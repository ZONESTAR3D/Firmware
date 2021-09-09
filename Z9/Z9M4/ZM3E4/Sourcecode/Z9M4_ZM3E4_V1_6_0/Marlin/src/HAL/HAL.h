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

#include "platforms.h"

#include HAL_PATH(.,HAL.h)

#ifndef HAS_MYSERIAL0
#define	HAS_MYSERIAL0	0
#endif

#ifndef HAS_MYSERIAL1
#define	HAS_MYSERIAL1	0
#endif

#ifndef HAS_WIFI_SERIAL
#define	HAS_WIFI_SERIAL	0
#endif

#define	NUM_SERIAL	(HAS_MYSERIAL0 + HAS_MYSERIAL1 + HAS_WIFI_SERIAL)

#define HAL_ADC_RANGE _BV(HAL_ADC_RESOLUTION)

#ifndef I2C_ADDRESS
  #define I2C_ADDRESS(A) uint8_t(A)
#endif

// Needed for AVR sprintf_P PROGMEM extension
#ifndef S_FMT
  #define S_FMT "%s"
#endif

// String helper
#ifndef PGMSTR
  #define PGMSTR(NAM,STR) const char NAM[] = STR
#endif

inline void watchdog_refresh() {
  TERN_(USE_WATCHDOG, HAL_watchdog_refresh());
}
