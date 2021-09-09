/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#ifndef __MARLIN_FIRMWARE__
#define __MARLIN_FIRMWARE__
#endif

//
// Prefix header to acquire configurations
//
#include <stdint.h>

#ifndef __MARLIN_DEPS__
  #include "../HAL/platforms.h"
#endif

#include "../core/boards.h"
#include "../core/macros.h"

#ifdef	__Z9V5_ZM3E4__
#include "../../../Z9V5/config/Configuration.h"
#elif defined(__Z9M4_ZM3E4__)
#include "../../../Z9M4_ZM3E4/config/Configuration.h"
#elif defined(__Z9M3_ZM3E4__)
#include "../../../Z9M3_ZM3E4/config/Configuration.h"
#elif defined(__Z9M3_ZRIB__)
#include "../../../Z9M3_ZM3E4/config/Configuration.h"
#elif defined(__Z8T_ZM3E4__)
#include "../../../Z8T_ZM3E4/config/Configuration.h"
#elif defined(__Z8T_ZRIB__)
#include "../../../Z8T_ZRIB/config/Configuration.h"
#elif defined(__Z8P_ZM3E4__)
#include "../../../Z8P_ZM3E4/config/Configuration.h"
#else
#include "../../Configuration.h"
#endif

#ifdef CUSTOM_VERSION_FILE
  #if __has_include(STRINGIFY(../../CUSTOM_VERSION_FILE))
    #include STRINGIFY(../../CUSTOM_VERSION_FILE)
  #endif
#endif

#include "Version.h"

#include "Conditionals_LCD.h"

#ifndef __MARLIN_DEPS__
  #include HAL_PATH(../HAL, inc/Conditionals_LCD.h)
#endif

#include "../core/drivers.h"

#ifdef	__Z9V5_ZM3E4__
#include "../../../Z9V5/config/Configuration_adv.h"
#elif defined(__Z9M4_ZM3E4__)
#include "../../../Z9M4_ZM3E4/config/Configuration_adv.h"
#elif defined(__Z9M3_ZM3E4__)
#include "../../../Z9M3_ZM3E4/config/Configuration_adv.h"
#elif defined(__Z9M3_ZRIB__)
#include "../../../Z9M3_ZM3E4/config/Configuration_adv.h"
#elif defined(__Z8T_ZM3E4__)
#include "../../../Z8T_ZM3E4/config/Configuration_adv.h"
#elif defined(__Z8T_ZRIB__)
#include "../../../Z8T_ZRIB/config/Configuration_adv.h"
#elif defined(__Z8P_ZM3E4__)
#include "../../../Z8P_ZM3E4/config/Configuration_adv.h"
#else
#include "../../Configuration_adv.h"
#endif

#include "Conditionals_adv.h"


#ifndef __MARLIN_DEPS__
  #include HAL_PATH(../HAL, inc/Conditionals_adv.h)
#endif
