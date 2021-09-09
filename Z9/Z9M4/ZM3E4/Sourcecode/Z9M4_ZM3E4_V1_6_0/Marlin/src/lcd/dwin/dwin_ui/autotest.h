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

/**
 * DWIN LCD
 */
#include "../../../inc/MarlinConfig.h"
#include "dwin.h"

#if (HAS_DWIN_LCD && ENABLED(DWIN_AUTO_TEST))
#include "../dwin_lcd.h"
#include "../rotary_encoder.h"

enum {
  CHECK_START = 0,
	CHECK_SD,
	CHECK_HOTBED_TEMP,
	CHECK_HOTEND_TEMP,
	CHECK_FAN_SPEED,	
	CHECK_XY_MOTOR,
	CHECK_Z_MOTOR,
	CHECK_MOTOR_E1,
	#if (E_STEPPERS > 1)
	CHECK_MOTOR_E2,
	#endif
	#if (E_STEPPERS > 2)
	CHECK_MOTOR_E3,
	#endif
	#if (E_STEPPERS > 3)
	CHECK_MOTOR_E4,
	#endif
	CHECK_MOTORS_END,
	CHECK_ENDSTOPS,
	CHECK_KEY,
	CHECK_END
};

typedef struct { 
	uint8_t loops = 0;
	uint8_t rotary_counter_rg = 0;
	uint8_t rotary_click_rg = 0;
	uint8_t Endstops;	
	bool fan_fg:1;	
}_stAutotest_t;

class Autotest {
public:		
		void Check_Rotary();
		bool DWIN_AutoTesting();		
		void HMI_StartTest();
		static _stAutotest_t testflag;

private:		
		inline void AutoTest_ShowSWStatus(bool bfirst);
		inline void AutoTest_ShowTemperature();
		inline void Autotest_ShowKnob(uint8_t );
		inline void AutoTest_Watch_SW();	
};

extern Autotest autotest;

#endif

