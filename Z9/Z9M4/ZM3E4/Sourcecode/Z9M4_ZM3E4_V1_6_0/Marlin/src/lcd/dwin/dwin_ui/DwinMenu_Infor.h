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

#include "../../../inc/MarlinConfig.h"
#if HAS_DWIN_LCD
#include "../rotary_encoder.h"
#include "../dwin_lcd.h"
#include "dwin_comm.h"
#include "dwin.h"

typedef enum{
	INFO_CASE_BACK = 0,
	INFO_CASE_VERSION,
	INFO_CASE_FIRMWARE,
	INFO_CASE_WEBSITE,
	INFO_CASE_MODEL,
	INFO_CASE_BOARD,
	INFO_CASE_EXTRUDER_NUM,
	INFO_CASE_EXTRUDER_MODEL,
#if ENABLED(OPTION_DUALZ_DRIVE)
	INFO_CASE_DUALZ_DRIVE,
#endif
#if ENABLED(OPTION_Z2_ENDSTOP)
	INFO_CASE_DUALZ_ENDSTOP,
#endif
	INFO_CASE_BAUDRATE,
	INFO_CASE_PROTOCOL,
	INFO_CASE_PSU,
	INFO_CASE_DATE,
	INFO_CASE_THERMISTOR,
	INFO_CASE_BED,
	INFO_CASE_HOT,
	INFO_CASE_END
}_emMenuCaseInfor;
#define	INFO_CASE_TOTAL	(14+ENABLED(OPTION_DUALZ_DRIVE)+ENABLED(OPTION_Z2_ENDSTOP))

#ifndef MACHINE_SIZE
  #define MACHINE_SIZE "300x300x400"
#endif

#ifndef CORP_WEBSITE_C
  #define CORP_WEBSITE_C "www.zonestar3d.com"
#endif

#ifndef CORP_WEBSITE_E
  #define CORP_WEBSITE_E "www.zonestar3d.com"
#endif


void Draw_Info_Menu();
void HMI_Info();


#endif
