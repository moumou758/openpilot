"""
Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.

This file is part of sunnypilot and is licensed under the MIT License.
See the LICENSE.md file in the root directory for more details.
"""
import math

from cereal import messaging, custom
from opendbc.car import structs
from openpilot.selfdrive.car.cruise import V_CRUISE_UNSET
from openpilot.common.params import Params
from openpilot.common.realtime import DT_MDL
from opendbc.car.interfaces import ACCEL_MIN
from openpilot.sunnypilot.selfdrive.controls.lib.dec.dec import DynamicExperimentalController
from openpilot.sunnypilot.selfdrive.controls.lib.speed_limit_controller.speed_limit_controller import SpeedLimitController
from openpilot.sunnypilot.selfdrive.controls.lib.speed_limit_controller.speed_limit_resolver import SpeedLimitResolver
from openpilot.sunnypilot.selfdrive.selfdrived.events import EventsSP
from openpilot.sunnypilot.selfdrive.controls.lib.smart_cruise_control.vision_controller import SmartCruiseControlVision
from openpilot.sunnypilot.models.helpers import get_active_bundle

from openpilot.sunnypilot.selfdrive.controls.lib.vibe_personality.vibe_personality import VibePersonalityController
DecState = custom.LongitudinalPlanSP.DynamicExperimentalControl.DynamicExperimentalControlState


class LongitudinalPlannerSP:
  def __init__(self, CP: structs.CarParams, mpc):
    self.events_sp = EventsSP()

    self.resolver = SpeedLimitResolver()

    self.dec = DynamicExperimentalController(CP, mpc)
    self.vibe_controller = VibePersonalityController()
    self.scc_v = SmartCruiseControlVision(CP)
    self.generation = int(model_bundle.generation) if (model_bundle := get_active_bundle()) else None
    self.slc = SpeedLimitController(CP)
    self.transition_init()

  @property
  def mlsim(self) -> bool:
    # If we don't have a generation set, we assume it's default model. Which as of today are mlsim.
    return bool(self.generation is None or self.generation >= 11)

  def get_mpc_mode(self) -> str | None:
    if not self.dec.active():
      return None

    return self.dec.mode()

  def update_targets(self, sm: messaging.SubMaster, v_ego: float, a_ego: float, v_cruise: float) -> tuple[float, float, str]:
    # Update SCC
    self.scc_v.update(sm, sm['carControl'].longActive, v_ego, a_ego, v_cruise)

    # update SLA
    self.events_sp.clear()
    self.resolver.update(v_ego, sm)
    v_cruise_slc = self.slc.update(sm['carControl'].longActive, v_ego, a_ego, sm['carState'].vCruiseCluster,
                                   self.resolver.speed_limit, self.resolver.distance, self.resolver.source, self.events_sp)

    v_cruise_final = min(v_cruise, v_cruise_slc)

    targets = {
      'cruise': (v_cruise_final, a_ego),
      'scc_v': (self.scc_v.output_v_target, self.scc_v.output_a_target),
    }

    src = min(targets, key=lambda k: targets[k][0])
    v_target, a_target = targets[src]

    return v_target, a_target, src

  def transition_init(self) -> None:
    self._transition_counter = 0
    self._transition_steps = 20
    self._last_mode = 'acc'

  def handle_mode_transition(self, mode: str) -> None:
    if self._last_mode != mode:
      if mode == 'blended':
        self._transition_counter = 0
      self._last_mode = mode

  def blend_accel_transition(self, mpc_accel: float, e2e_accel: float, v_ego: float) -> float:
    if self.dec.enabled():
      if self._transition_counter < self._transition_steps:
        self._transition_counter += 1
        progress = self._transition_counter / self._transition_steps
        if v_ego > 5.0 and e2e_accel < 0.0:
          if mpc_accel < 0.0 and e2e_accel > mpc_accel:
            return mpc_accel
          # use k3.0 and normalize midpoint at 0.5
          sigmoid = 1.0 / (1.0 + math.exp(-3.0 * (abs(e2e_accel / ACCEL_MIN) - 0.5)))
          blend_factor = 1.0 - (1.0 - progress) * (1.0 - sigmoid)
          blended = mpc_accel + (e2e_accel - mpc_accel) * blend_factor
          return blended
    return min(mpc_accel, e2e_accel)

  def update(self, sm: messaging.SubMaster) -> None:
    self.dec.update(sm)
    self.vibe_controller.update()

  def publish_longitudinal_plan_sp(self, sm: messaging.SubMaster, pm: messaging.PubMaster) -> None:
    plan_sp_send = messaging.new_message('longitudinalPlanSP')

    plan_sp_send.valid = sm.all_checks(service_list=['carState', 'controlsState'])

    longitudinalPlanSP = plan_sp_send.longitudinalPlanSP
    longitudinalPlanSP.events = self.events_sp.to_msg()

    # Dynamic Experimental Control
    dec = longitudinalPlanSP.dec
    dec.state = DecState.blended if self.dec.mode() == 'blended' else DecState.acc
    dec.enabled = self.dec.enabled()
    dec.active = self.dec.active()

    # Speed Limit Control
    slc = longitudinalPlanSP.slc
    slc.state = self.slc.state
    slc.enabled = self.slc.is_enabled
    slc.active = self.slc.is_active
    slc.speedLimit = float(self.resolver.speed_limit)
    slc.speedLimitOffset = float(self.slc.speed_limit_offset)
    slc.distToSpeedLimit = float(self.resolver.distance)
    slc.source = self.resolver.source
    # Smart Cruise Control
    smartCruiseControl = longitudinalPlanSP.smartCruiseControl
    # Vision Turn Speed Control
    sccVision = smartCruiseControl.vision
    sccVision.state = self.scc_v.state
    sccVision.vTarget = float(self.scc_v.output_v_target)
    sccVision.aTarget = float(self.scc_v.output_a_target)
    sccVision.currentLateralAccel = float(self.scc_v.current_lat_acc)
    sccVision.maxPredictedLateralAccel = float(self.scc_v.max_pred_lat_acc)

    pm.send('longitudinalPlanSP', plan_sp_send)
