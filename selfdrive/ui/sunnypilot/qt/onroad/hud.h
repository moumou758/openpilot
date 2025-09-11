/**
 * Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.
 *
 * This file is part of sunnypilot and is licensed under the MIT License.
 * See the LICENSE.md file in the root directory for more details.
 */

#pragma once

#include <QPainter>

#include "selfdrive/ui/qt/onroad/hud.h"
#include "selfdrive/ui/sunnypilot/qt/onroad/developer_ui/developer_ui.h"

class HudRendererSP : public HudRenderer {
  Q_OBJECT

private:
  Params params;
  void drawText(QPainter &p, int x, int y, const QString &text, QColor color = Qt::white);
  void drawRightDevUI(QPainter &p, int x, int y);
  int drawRightDevUIElement(QPainter &p, int x, int y, const QString &value, const QString &label, const QString &units, QColor &color);
  int drawBottomDevUIElement(QPainter &p, int x, int y, const QString &value, const QString &label, const QString &units, QColor &color);
  void drawBottomDevUI(QPainter &p, int x, int y);

  bool lead_status;
  float lead_d_rel;
  float lead_v_rel;
  bool torqueLateral;
  float angleSteers;
  float steerAngleDesired;
  float curvature;
  float roll;
  int memoryUsagePercent;
  int devUiInfo;
  float gpsAccuracy;
  float altitude;
  float vEgo;
  float aEgo;
  float steeringTorqueEps;
  float bearingAccuracyDeg;
  float bearingDeg;
  bool torquedUseParams;
  float latAccelFactorFiltered;
  float frictionCoefficientFiltered;
  bool liveValid;
  QString speedUnit;
  bool latActive;
  bool madsEnabled;
  bool reversing;

public:
  HudRendererSP();
  void updateState(const UIState &s) override;
  void draw(QPainter &p, const QRect &surface_rect) override;

private:
  // Vision Turn Speed Control
  int vtsc_state = 0;
  float vtsc_velocity = 0.0;
  float vtsc_current_lateral_accel = 0.0;
  float vtsc_max_predicted_lateral_accel = 0.0;
  bool show_vtsc = false;

  // SLC-related member
  float slc_speed_limit = 0.0;
  float slc_speed_offset = 0.0;
  cereal::LongitudinalPlanSP::SpeedLimitControlState slc_state = cereal::LongitudinalPlanSP::SpeedLimitControlState::INACTIVE;
  bool show_slc = false;
  float dist_to_speed_limit = 0.0;

  // Speed limit ahead
  bool speed_limit_ahead_valid = false;
  float speed_limit_ahead = 0.0;
  float speed_limit_ahead_distance = 0.0;

  // Road name
  QString road_name;

  // Speed violation
  int speed_violation_level = 0;
  bool over_speed_limit = false;

  void drawSetSpeedSP(QPainter &p, const QRect &surface_rect);
  void drawSpeedLimitSigns(QPainter &p, const QRect &surface_rect);
  void drawUpcomingSpeedLimit(QPainter &p, const QRect &surface_rect);
  void drawSLCStateIndicator(QPainter &p, const QRect &surface_rect);
  void drawRoadName(QPainter &p, const QRect &surface_rect);
  void drawVisionTurnControl(QPainter &p, const QRect &surface_rect);

  QColor interpColor(float x, const std::vector<float> &x_vals, const std::vector<QColor> &colors);
};
