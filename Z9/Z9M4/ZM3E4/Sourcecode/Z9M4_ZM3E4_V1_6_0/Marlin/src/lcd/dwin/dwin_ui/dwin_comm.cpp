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
 * DwinMenu_comm.c
 */

#include "../../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include <WString.h>
#include <stdio.h>
#include <string.h>
#include "dwin.h"
#include "../../../module/temperature.h"
#include "../../../module/printcounter.h"
#include "../../../module/motion.h"
#include "../../../module/planner.h"
#include "../../../module/tool_change.h"
#include "../../thermistornames.h"
#include "../../../module/settings.h"
#include "../../../libs/buzzer.h"

#include "../../fontutils.h"
#include "../../ultralcd.h"

#include "../../../sd/cardreader.h"

#include "../../../MarlinCore.h"
#include "../../../core/serial.h"
#include "../../../core/macros.h"
#include "../../../gcode/queue.h"


#if ENABLED(HOST_ACTION_COMMANDS)
  #include "../../../feature/host_actions.h"
#endif
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
#include "../../../feature/runout.h"
#endif
#include "../../../feature/pause.h"
#if HAS_BED_PROBE
  #include "../../../module/probe.h"
#endif
#if ENABLED(BABYSTEPPING)
  #include "../../../feature/babystep.h"
#endif
#if ENABLED(POWER_LOSS_RECOVERY)
  #include "../../../feature/powerloss.h"
#endif
#if HAS_LEVELING
  #include "../../../feature/bedlevel/bedlevel.h"
#endif
#if ENABLED(BLTOUCH)
  #include "../../../feature/bltouch.h"
#endif
#if ENABLED(FWRETRACT)
  #include "../../../feature/fwretract.h"
#endif
#if ENABLED(MIXING_EXTRUDER)
  #include "../../../feature/mixing.h"
#endif

bool Apply_Encoder_int16(const ENCODER_DiffState &encoder_diffState, int16_t *valref) {
  if (encoder_diffState == ENCODER_DIFF_CW)
    *valref += (int16_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_CCW)
    *valref -= (int16_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_ENTER)
    return true;
  return false;
}

bool Apply_Encoder_uint8(const ENCODER_DiffState &encoder_diffState, uint8_t *valref) {
  if (encoder_diffState == ENCODER_DIFF_CW)
    *valref += (uint8_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_CCW)
    *valref -= (uint8_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_ENTER)
    return true;
  return false;
}

bool Apply_Encoder_int8(const ENCODER_DiffState &encoder_diffState, int8_t *valref) {
  if (encoder_diffState == ENCODER_DIFF_CW)
    *valref += (int8_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_CCW)
    *valref -= (int8_t)EncoderRate.encoderMoveValue;
  else if (encoder_diffState == ENCODER_DIFF_ENTER)
    return true;
  return false;
}


void DWIN_Show_ICON(uint8_t picID, uint16_t x, uint16_t y){
	dwinLCD.ICON_Show(ICON_IMAGE_ID, picID, x, y);
}

void Draw_Menu_Icon(const uint8_t line, const uint8_t icon){
	DWIN_Show_ICON(icon, MENUICON_X, MBASE(line) - 3);
}

void Draw_Menu_Line(const uint8_t line, const uint8_t icon /*= 0 */, const char * const label/* = nullptr*/){
	if (label) DWIN_Draw_UnMaskString_Default(LBLX, MBASE(line) - 1, (char*)label);
	if (icon) Draw_Menu_Icon(line, icon);
	dwinLCD.Draw_Line(LINE_COLOR, 16, MBASE(line) + 33, 256, MBASE(line) + 34);
}

void Draw_More_Icon(const uint8_t line){
	DWIN_Show_ICON(ICON_MORE, MENUMORE_X, MBASE(line) - 3);
}

void Draw_Menu_Cursor(const uint8_t line){
	dwinLCD.Draw_Rectangle(1, RECTANGLE_COLOR, 0, MBASE(line) - 18, 14, MBASE(line + 1) - 20);
}

void DWIN_Show_MultiLanguage_String(uint8_t ItemID, uint16_t x, uint16_t y){
	uint16_t coordinate[4];
	coordinate[0] = pgm_read_word(&MULTILANGSTR_COORDINATE[HMI_flag.language][ItemID][0]);
	coordinate[1] = pgm_read_word(&MULTILANGSTR_COORDINATE[HMI_flag.language][ItemID][1]);
	coordinate[2] = pgm_read_word(&MULTILANGSTR_COORDINATE[HMI_flag.language][ItemID][2]);
	coordinate[3] = pgm_read_word(&MULTILANGSTR_COORDINATE[HMI_flag.language][ItemID][3]);
	dwinLCD.Frame_AreaCopy_Index(IMAGE_CACHE_ID1, HMI_flag.language, ItemID, coordinate, x, y);
}

void Draw_Back_First(const bool is_sel/*=true*/){
	Draw_Menu_Line(0, ICON_BACK);
	DWIN_Show_MultiLanguage_String(MTSTRING_MENU_BACK, LBLX, MBASE(0));
	if (is_sel) Draw_Menu_Cursor(0);
}

void Draw_Popup_Bkgd_60(){
 dwinLCD.Draw_Rectangle(1, COLOR_BG_WINDOW, 14, 60, 258, 330);
}

void Erase_Menu_Cursor(const uint8_t line){
	dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 0, MBASE(line) - 18, 14, MBASE(line + 1) - 20);
}

void Move_Highlight(const int16_t from, const uint16_t newline){
	Erase_Menu_Cursor(newline - from);
	Draw_Menu_Cursor(newline);
	DWIN_FEEDBACK_TICK();
}

void Scroll_Menu(const int8_t dir /*= DWIN_SCROLL_DOWN*/){
	dwinLCD.Frame_AreaMove(1, dir, MLINE, COLOR_BG_BLACK, 0, 31, DWIN_WIDTH, 349);
	switch (dir) {
		case DWIN_SCROLL_DOWN: Move_Highlight(-1, 0); break;
	  case DWIN_SCROLL_UP:  Add_Menu_Line(); break;
	}
}


void Clear_Dwin_Area(const uint8_t area){
	if((area & AREA_TITAL) == AREA_TITAL)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLUE, 0, TITAL_Y_START, DWIN_WIDTH, TITAL_Y_END);
	if((area & AREA_MENU) == AREA_MENU)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 0, MENU_Y_START, DWIN_WIDTH, MENU_Y_END);	
#if ENABLED(MIXING_EXTRUDER)	
	if((area & AREA_MIXVALUE) == AREA_MIXVALUE)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, MIXVALUE_X_START, MIXVALUE_Y_START, MIXVALUE_X_END, MIXVALUE_Y_END);
#endif
	if((area & AREA_STATUS) == AREA_STATUS)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 0, STATUS_Y_START, DWIN_WIDTH, STATUS_Y_END);
	if((area & AREA_BOTTOM) == AREA_BOTTOM)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 0, BOTTOM_Y_START, DWIN_WIDTH, BOTTOM_Y_END);	
	if((area & AREA_POPMENU) == AREA_POPMENU)
		dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, POP_X_START, POP_Y_START, POP_X_END, POP_Y_END);
}



void Draw_Title(PGM_P title){
	DWIN_Draw_UnMaskString_FONT10_TITLE(14, 4, title);
}
void Draw_Wifi_Title(PGM_P title){
	DWIN_Draw_UnMaskString_FONT10_TITLE(14, 65, title);
}

void Draw_Popup_Bkgd_105(){
	dwinLCD.Draw_Rectangle(1, COLOR_BG_WINDOW, 14, 105, 258, 374);
}

void Add_Menu_Line(){
	Move_Highlight(1, MROWS);
	dwinLCD.Draw_Line(LINE_COLOR, 16, MBASE(MROWS + 1) - 20, 256, MBASE(MROWS + 1) - 19);
}
void Erase_Menu_Text(const uint8_t line){
	dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, LBLX, MBASE(line) - 14, 271, MBASE(line) + 28);
}

//updata Z position
void DWIN_Show_Z_Position(bool bshowICON){	
	static float last_z_pos = -9999.99;	
	if(bshowICON) DWIN_Show_ICON(ICON_ZOFFSET, State_icon_Zoffset_X, State_icon_Zoffset_Y);
	if(all_axes_known()){
		if(last_z_pos != current_position.z || bshowICON){
			dwinLCD.Draw_SignedFloatValue(DWIN_FONT_STAT, COLOR_WHITE, COLOR_BG_BLACK, State_text_Zoffset_inum, State_text_Zoffset_fnum, State_text_Zoffset_X, State_text_Zoffset_Y, MAXUNITMULT*current_position.z);
			last_z_pos = current_position.z;
		}
	}
	else
		dwinLCD.Draw_String(false, true, DWIN_FONT_STAT, COLOR_WHITE, COLOR_BG_BLACK, State_text_Zoffset_X,State_text_Zoffset_Y, PSTR("---.-- "));
}

//////////////////////////////////////////////////////
// The status area is always on-screen, except during
// full-screen modal dialogs. (TODO: Keep alive during dialogs)
//
void Draw_Status_Area() {
	// Clear the bottom area of the screen
	Clear_Dwin_Area(AREA_STATUS);
	//
	// Status Area
	//
#if HAS_HOTEND
	DWIN_Show_ICON(ICON_HOTENDTEMP, State_icon_extruder_X, State_icon_extruder_Y);
	DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_extruder_num, State_text_extruder_X, State_text_extruder_Y, thermalManager.temp_hotend[0].celsius);
	DWIN_Draw_UnMaskString_FONT10(State_string_extruder_X, State_string_extruder_Y, PSTR("/"));
	DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_extruder_num, State_text_extruder_X + (State_text_extruder_num + 1) * STAT_CHR_W, State_text_extruder_Y, thermalManager.temp_hotend[0].target);
#endif
#if HOTENDS > 1
	// dwinLCD.ICON_Show(ICON_IMAGE_ID,ICON_HOTENDTEMP, 13, 381);
#endif

#if HAS_HEATED_BED
	DWIN_Show_ICON(ICON_BEDTEMP, State_icon_bed_X, State_icon_bed_Y);
	DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_bed_num, State_text_bed_X, State_text_bed_Y, thermalManager.temp_bed.celsius);
	DWIN_Draw_UnMaskString_FONT10(State_string_bed_X, State_string_bed_Y, PSTR("/"));
	DWIN_Draw_IntValue_FONT10(COLOR_WHITE, State_text_bed_num, State_text_bed_X + (State_text_extruder_num + 1) * STAT_CHR_W, State_text_bed_Y, thermalManager.temp_bed.target);
#endif

	DWIN_Show_ICON(ICON_SPEED, State_icon_speed_X, State_icon_speed_Y);
	DWIN_Draw_IntValue_FONT10(COLOR_WHITE, 3, State_text_speed_X, State_text_speed_Y, feedrate_percentage);
	DWIN_Draw_UnMaskString_FONT10(State_string_speed_X, State_string_speed_Y, PSTR("%"));

	//	
	DWIN_Show_Z_Position(true);
}

void HMI_AudioFeedback(const bool success/*=true*/){
	if (success) {
		buzzer.tone(200, 1000);
		buzzer.tone(10, 0);
		buzzer.tone(200, 3000);
	}
	else
		buzzer.tone(20, 1000);
}

#if HAS_HOTEND
void HMI_ETemp() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		uint8_t temp_line;
		switch (HMI_flag.show_mode) {
			case SHOWED_TEMPERATURE: temp_line = TEMP_CASE_ETEMP + MROWS - DwinMenu_temp.index; break;
			case SHOWED_PEHEAT_PLA: temp_line = PREHEAT_CASE_TEMP; break;
			case SHOWED_PEHEAT_ABS: temp_line = PREHEAT_CASE_TEMP; break;
			default: temp_line = TUNE_CASE_ETEMP + MROWS - DwinMenu_tune.index;
		}
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.E_Temp)) {
			EncoderRate.enabled = false;
			switch (HMI_flag.show_mode){
				case SHOWED_TEMPERATURE:
					DwinMenuID = DWMENU_TEMPERATURE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
					thermalManager.setTargetHotend(HMI_Value.E_Temp, 0);
				break;
				
				case SHOWED_PEHEAT_PLA:
					DwinMenuID = DWMENU_PREHEAT_PLA;					
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
					ui.material_preset[0].hotend_temp = HMI_Value.E_Temp;
				break;
				
				case SHOWED_PEHEAT_ABS:
					DwinMenuID = DWMENU_PREHEAT_ABS;				
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
					ui.material_preset[1].hotend_temp = HMI_Value.E_Temp;
				break;
				
				default:
					DwinMenuID = DWMENU_TUNE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
					thermalManager.setTargetHotend(HMI_Value.E_Temp, 0);
				break;
			}			
			if(HMI_Value.E_Temp > 230){								
				Clear_Dwin_Area(AREA_BOTTOM);
				DWIN_Show_Status_Message(COLOR_RED, PSTR("Warnning! High temperature"));
				buzzer.tone(100, 1000);
				buzzer.tone(100, 3000);
				buzzer.tone(100, 1000);
				buzzer.tone(100, 3000);
				set_status_bar_showtime(3);
			}
			return;
		}
		// E_Temp limit
		NOMORE(HMI_Value.E_Temp, (HEATER_0_MAXTEMP - (HOTEND_OVERSHOOT)));
		NOLESS(HMI_Value.E_Temp, HEATER_0_MINTEMP);
		// E_Temp value
		if(HMI_Value.E_Temp > 230)
			DWIN_Draw_Warn_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
		else
			DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(temp_line), HMI_Value.E_Temp);
	}
}
#endif // HAS_HOTEND

#if HAS_HEATED_BED
void HMI_BedTemp() {
  ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
  if (encoder_diffState != ENCODER_DIFF_NO) {
		uint8_t bed_line;
		switch (HMI_flag.show_mode) {
			case SHOWED_TEMPERATURE: bed_line = TEMP_CASE_BTEMP + MROWS - DwinMenu_temp.index; break;
			case SHOWED_PEHEAT_PLA: bed_line = PREHEAT_CASE_BED; break;
			case SHOWED_PEHEAT_ABS: bed_line = PREHEAT_CASE_BED; break;
			default: bed_line = TUNE_CASE_BTEMP + MROWS - DwinMenu_tune.index; break;
		}
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Bed_Temp)) {
			EncoderRate.enabled = false;
			switch (HMI_flag.show_mode) {
				case SHOWED_TEMPERATURE:
					DwinMenuID = DWMENU_TEMPERATURE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(bed_line), HMI_Value.Bed_Temp);
					thermalManager.setTargetBed(HMI_Value.Bed_Temp);
				break;
				
				case SHOWED_PEHEAT_PLA: 
					DwinMenuID = DWMENU_PREHEAT_PLA;					
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(bed_line), HMI_Value.Bed_Temp);
					ui.material_preset[0].bed_temp = HMI_Value.Bed_Temp;
				break;
				
				case SHOWED_PEHEAT_ABS: 
					DwinMenuID = DWMENU_PREHEAT_ABS;					
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(bed_line), HMI_Value.Bed_Temp);
					ui.material_preset[1].bed_temp = HMI_Value.Bed_Temp;
				break;
				
				default: 
					DwinMenuID = DWMENU_TUNE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(bed_line), HMI_Value.Bed_Temp);
					thermalManager.setTargetBed(HMI_Value.Bed_Temp);
    		break;
			}   
	   	return;
		}
		// Bed_Temp limit
		NOMORE(HMI_Value.Bed_Temp, BED_MAX_TARGET);
		NOLESS(HMI_Value.Bed_Temp, BED_MINTEMP);
		// Bed_Temp value
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(bed_line), HMI_Value.Bed_Temp);
	}
}
#endif // HAS_HEATED_BED

#if HAS_FAN
void HMI_FanSpeed() {
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		uint8_t fan_line;
		switch (HMI_flag.show_mode) {
			case SHOWED_TEMPERATURE: fan_line = TEMP_CASE_FAN + MROWS - DwinMenu_temp.index; break;
			case SHOWED_PEHEAT_PLA: fan_line = PREHEAT_CASE_FAN; break;
			case SHOWED_PEHEAT_ABS: fan_line = PREHEAT_CASE_FAN; break;
			default: fan_line = TUNE_CASE_FAN + MROWS - DwinMenu_tune.index;
		}
		if (Apply_Encoder_int16(encoder_diffState, &HMI_Value.Fan_speed)) {
			EncoderRate.enabled = false;
			switch (HMI_flag.show_mode){
				case SHOWED_TEMPERATURE: 
					DwinMenuID = DWMENU_TEMPERATURE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(fan_line), HMI_Value.Fan_speed);
					thermalManager.set_fan_speed(0, HMI_Value.Fan_speed);
				break;
				case SHOWED_PEHEAT_PLA: 
					DwinMenuID = DWMENU_PREHEAT_PLA;				
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(fan_line), HMI_Value.Fan_speed);
					ui.material_preset[0].fan_speed = HMI_Value.Fan_speed;
				break;

				case SHOWED_PEHEAT_ABS:
					DwinMenuID = DWMENU_PREHEAT_ABS;					
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(fan_line), HMI_Value.Fan_speed);
					ui.material_preset[1].fan_speed = HMI_Value.Fan_speed;
				break;
				
				default:
					DwinMenuID = DWMENU_TUNE;
					DWIN_Draw_IntValue_Default(3, MENUVALUE_X+8, MBASE(fan_line), HMI_Value.Fan_speed);
					thermalManager.set_fan_speed(0, HMI_Value.Fan_speed);
				break;
			}
			return;	
		}
		// Fan_speed limit
		NOMORE(HMI_Value.Fan_speed, 255);
		NOLESS(HMI_Value.Fan_speed, 0);
		// Fan_speed value
		DWIN_Draw_Select_IntValue_Default(3, MENUVALUE_X+8, MBASE(fan_line), HMI_Value.Fan_speed);
	}
}
#endif // HAS_PREHEAT

void ICON_YESorNO(uint8_t Option){
	if (Option == 0) {
  	DWIN_Show_ICON(ICON_YES_SEL, 26, 228);
		DWIN_Show_ICON(ICON_NO_UNSEL, 146, 228);
  	dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 26, 228, 126, 266);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 27, 229, 125, 265);
 	}
	else{
		DWIN_Show_ICON(ICON_YES_UNSEL, 26, 228);
		DWIN_Show_ICON(ICON_NO_SEL, 146, 228);
  	dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 146, 228, 246, 266);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 147, 229, 245, 265);
	}
	DWIN_FEEDBACK_TICK();
}

void DWIN_Show_Status_Message(const uint16_t color, PGM_P string, const uint8_t t ){
	Clear_Dwin_Area(AREA_BOTTOM);
	dwinLCD.Draw_String(true, true, font8x16, color, COLOR_BG_BLACK, 10, 455, string);
	if(t > 0) HMI_flag.clean_status_delay = t;
}

#endif // HAS_DWIN_LCD
