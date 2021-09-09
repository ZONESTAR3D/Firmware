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

/**
 * repeat_printing.cpp - repeat printing control
 */

#include "../inc/MarlinConfig.h"

#if ENABLED(OPTION_REPEAT_PRINTING)

#include "repeat_printing.h"
#include "../module/temperature.h"
#include "../module/stepper/indirection.h"
#include "../MarlinCore.h"


#if HAS_DWIN_LCD
#include "../lcd/dwin/dwin_lcd.h"
#include "../lcd/dwin/dwin_ui/dwin.h"
#include "../lcd/dwin/dwin_ui/dwinmenu_repeatprint.h"
#endif

RePrint ReprintManager;

bool RePrint::enabled = false;
bool RePrint::Reprint_over = false;
bool RePrint::Is_Reprint_Reset = false;
bool RePrint::Is_Reprint_Print = false;
bool RePrint::Reprint_Reset_Enabled = false;
bool RePrint::Reprint_Wait_Enabled = false;
		 
int16_t RePrint::Reprint_times = REPEAT_PRINTING_TIMES;
int16_t RePrint::Forward_lenght = FORWARD_PRINTING_LENGHT;
int16_t RePrint::tempbed_counter = 0;
millis_t RePrint::reprt_timer = 0;
RePrint_state_t RePrint::reprt_state = REPRINT_INIT;

int16_t RePrint::raw_bedtemp_old;
uint8_t RePrint::tempbed_var;


void RePrint::Init() {
  OUT_WRITE(FPRWARD_PIN,LOW);
  delayMicroseconds(10);
  OUT_WRITE(BACK_PIN,LOW);
  delayMicroseconds(10);
  SET_INPUT_PULLUP(REPRINT_STOP_PIN);
  
  TERN_(HAS_DWIN_LCD, Is_Reprint_Reset = true);
  Back_Move_Start();
	reprt_timer = millis();
}

bool RePrint::Forward_Move_Process(uint16_t Fmove_Timer) {
  if(reprt_timer - millis() > (millis_t)(Fmove_Timer*1000)){
  	reprt_timer = millis();
		 return true;
  }
  return false;
}

bool RePrint::Check_ENDSTOP() {
  if(!READ(REPRINT_STOP_PIN))
	{
		delay(2);
		if(!READ(REPRINT_STOP_PIN))	
			return true;
	}
	return false;
}

void RePrint::Check_Reprint_HOME(){ 
	if(ReprintManager.Is_Reprint_Reset){
		if(ReprintManager.Check_ENDSTOP()){
				ReprintManager.Back_Move_Start();
		  ReprintManager.Is_Reprint_Reset = 0;
				ReprintManager.Reprint_Reset_Enabled = 1;
	 		ReprintManager.Reprint_Wait_Enabled = 0;
	 		ReprintManager.tempbed_counter = 0;
		}
	}
}

bool RePrint::Reprint_BTemp_Check() {
  if((reprt_timer - millis())/100 > CHECK_TEMP_PER_TIMER){
  	reprt_timer = millis();
		if(thermalManager.temp_bed.celsius <= 25) 
			return true;
		else if((ABS(raw_bedtemp_old - thermalManager.temp_bed.raw) < TEMP_DIFFER) && (thermalManager.temp_bed.celsius < 30)) {
			if(tempbed_var++ > 10){
				tempbed_var = 0;
				raw_bedtemp_old = thermalManager.temp_bed.raw;
				return true;
			}
		}
		else 
			raw_bedtemp_old = thermalManager.temp_bed.raw;
  }
  return false;
}

void RePrint::Forward_Move_Start() {
  OUT_WRITE(FPRWARD_PIN,LOW);
  delayMicroseconds(1);
  OUT_WRITE(BACK_PIN,HIGH);
}

void RePrint::Back_Move_Start() {
  OUT_WRITE(FPRWARD_PIN,HIGH);
  delayMicroseconds(1);
  OUT_WRITE(BACK_PIN,LOW);
}

void RePrint::Back_Move_Stop() {
  OUT_WRITE(FPRWARD_PIN,LOW);
  delayMicroseconds(1);
  OUT_WRITE(BACK_PIN,LOW);
}



bool RePrint::Repeat_Print_Process(RePrint_state_t state) {
  uint8_t RPrint_Fg = 0;
  switch(reprt_state){
  	case REPRINT_INIT:
			raw_bedtemp_old = thermalManager.temp_bed.raw;
	    reprt_timer = millis();
			tempbed_var = 0;
			reprt_state = REPRINT_WAIT;
		break;
		
	case REPRINT_WAIT:
		if(Reprint_BTemp_Check()) 
			reprt_state = FORWARD_START;
		break;
		
	case FORWARD_START:
		Forward_Move_Start();
		reprt_state = FORWARD_MOVE;
    reprt_timer = millis(); 
		TERN_(HAS_DWIN_LCD,Popup_Window_FMoveStart());
		break;

	case FORWARD_MOVE:
		if(Forward_Move_Process((Forward_lenght*60)/(8*DCMOTOR_SPEED_RMP)))
			reprt_state = BACK_START;
		#if HAS_DWIN_LCD
		else {			
			DWIN_Draw_RepeatPrint_Time_lapse();			
		}
		#endif
		break;

	case BACK_START:
		Back_Move_Start();
	  TERN_(HAS_DWIN_LCD,Is_Reprint_Reset = true);
		TERN_(HAS_DWIN_LCD,Popup_Window_BMoveStart());
		Reprint_over = 0;
		reprt_state = BACK_MOVE;
		break;

	case BACK_MOVE:
		if(Reprint_over) {
			Reprint_over = 0;
			TERN_(HAS_DWIN_LCD,Popup_Window_BMoveStop());
			reprt_state = BACK_STOP;
		}
		break;

	case BACK_STOP:
			RPrint_Fg = 1;
		break;
		
	default: RPrint_Fg = 0;
		break;
  } 
  return RPrint_Fg;
}


_emReprint_state RePrint::Reprint_check_state(){
 if(Reprint_Reset_Enabled){
	 if(Forward_Move_Process(2)){
			 Reprint_Reset_Enabled = false;
			 Reprint_Wait_Enabled = true;
			 tempbed_counter = 0;
			 Forward_Move_Start();  
	 }
	 else Back_Move_Start();
 }

 if(Reprint_Wait_Enabled){
	 if(Forward_Move_Process(4)){
			 Reprint_Wait_Enabled = false;  
			 tempbed_counter = 0;
			 Reprint_over = true;
			 Back_Move_Stop();
	 }
	 else Forward_Move_Start();
 }
 
 if(Is_Reprint_Print && enabled){
	 if(Repeat_Print_Process(reprt_state)){
		 Is_Reprint_Print = false;
		 reprt_state = REPRINT_INIT;
		 if(Reprint_times <= 0) {
			 enabled = false;			 
			 return REPRINT_FINISHED;			 
		 }		 
		 return REPRINT_NEXT;		 
	 }
 }
 return REPRINT_GOON;
} 

void RePrint::Reprint_Stop(){
	Is_Reprint_Print = false;
	reprt_state = REPRINT_INIT;
}

void RePrint::Reprint_goon(){
	Reprint_times--;						
	Is_Reprint_Print = true;
	reprt_state = REPRINT_INIT;	
}
#endif // REPEAT_PRINTING_CONTROL
