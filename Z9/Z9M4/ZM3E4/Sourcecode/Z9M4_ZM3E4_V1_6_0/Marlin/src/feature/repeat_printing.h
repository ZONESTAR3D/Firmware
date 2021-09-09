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
 * repeat_printing.h - repeat printing control
 */

#include "../core/millis_t.h"

// @repeat printing control
#define REPEAT_PRINTING_TIMES				10			//
#define FORWARD_PRINTING_LENGHT			360			//
#define DCMOTOR_SPEED_RMP						26  		//tune/min
#define REPEAT_PRINTING_MAX_TIMES		9999		//
#define FORWARD_PRINTING_MAX_LENGHT	500
#define CHECK_TEMP_PER_TIMER				10			//Time interval for temperature detection(s)
#define TEMP_DIFFER									5				//Temperature difference

typedef enum {
	REPRINT_GOON = 0,
	REPRINT_NEXT,
	REPRINT_FINISHED,
}_emReprint_state;

typedef enum {
	REPRINT_INIT = 0,
	REPRINT_WAIT,
	FORWARD_START,
	FORWARD_MOVE,
	BACK_START,
	BACK_MOVE,
	BACK_STOP
}RePrint_state_t;


class RePrint {
  public:
		static bool enabled ;
		static bool Reprint_over;
		static bool Is_Reprint_Reset;
		static bool Is_Reprint_Print;
		static bool Reprint_Reset_Enabled;
		static bool Reprint_Wait_Enabled;
		 
		static int16_t Reprint_times;
		static int16_t Forward_lenght;
		static int16_t tempbed_counter;
		static millis_t reprt_timer;		
		
		
		static void Init();
		static bool Repeat_Print_Process(RePrint_state_t state);
		//static bool Back_Move_Process();
		static void Back_Move_Stop();
		static void Back_Move_Start();
		static void Forward_Move_Start();
		static bool Forward_Move_Process(uint16_t Fmove_Timer);
		static bool Check_ENDSTOP(); 
		static void Check_Reprint_HOME();
		_emReprint_state Reprint_check_state();
		static void Reprint_Stop();
		static void Reprint_goon();
		
  private:
  
		static int16_t raw_bedtemp_old;
		static uint8_t tempbed_var;
		static RePrint_state_t reprt_state;
		
		static bool Reprint_BTemp_Check();
	
};

extern RePrint ReprintManager;

