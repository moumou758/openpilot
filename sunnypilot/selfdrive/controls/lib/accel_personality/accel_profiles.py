"""
Copyright (c) 2021-, rav4kumar, Haibin Wen, sunnypilot, and a number of other contributors.

This file is part of sunnypilot and is licensed under the MIT License.
See the LICENSE.md file in the root directory for more details.
"""

# Acceleration profile for maximum allowed acceleration
MAX_ACCEL_ECO     = [2.00, 1.90, 1.75, 1.45, 0.83, .54,  .45, .34, .30, .09]
MAX_ACCEL_NORMAL  = [2.00, 1.95, 1.85, 1.65, 1.00, .75,  .61, .50, .38, .2]
MAX_ACCEL_SPORT   = [2.00, 2.00, 1.98, 1.90, 1.30, 1.00, .72, .60, .48, .3]

# Acceleration profile for minimum (braking) acceleration
MIN_ACCEL_ECO     = [-1.1, -1.1, -1.1, -1.1, -1.1]
MIN_ACCEL_NORMAL  = [-1.2, -1.2, -1.2, -1.2, -1.2]
MIN_ACCEL_SPORT   = [-1.3, -1.3, -1.3, -1.3, -1.3]
MIN_ACCEL_STOCK   = [-1.2, -1.2, -1.2, -1.2, -1.2]

# Speed breakpoints for interpolation
MAX_ACCEL_BREAKPOINTS = [0., 1., 6., 8., 11., 16, 20., 25., 30., 55.]
MIN_ACCEL_BREAKPOINTS = [0., 0.3, 1., 27, 40]
