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
 * DwinMenu_Main.cpp
 */

 #include "../../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include "dwin.h"

inline void Draw_ICON_Print(const bool selected) {
	if(selected) {
		DWIN_Show_ICON(ICON_PRINT_SEL, 17, 130);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 17, 130, 126, 229);
		DWIN_Show_ICON(GET_PIC_ID(ICON_BIG_PRINT), GET_ICON_X(PRINT), 201);
	}
	else {
		DWIN_Show_ICON(ICON_PRINT, 17, 130);
		DWIN_Show_MultiLanguage_String(MTSTRING_MAIN_PRINT, GET_ICON_X(PRINT),201);
	}
}

inline void Draw_ICON_Prepare(const bool selected) {
	if (selected) {
		DWIN_Show_ICON(ICON_PREPARE_SEL, 145, 130);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 145, 130, 254, 229);
		DWIN_Show_ICON(GET_PIC_ID(ICON_BIG_PREPARE), GET_ICON_X(PREPARE), 201);
	}
	else {
		DWIN_Show_ICON(ICON_PREPARE, 145, 130);
		DWIN_Show_MultiLanguage_String(MTSTRING_MAIN_PREPARE, GET_ICON_X(PREPARE),201);
	}
}

inline void Draw_ICON_Control(const bool selected) {
	if (selected) {
		DWIN_Show_ICON(ICON_CONTROL_SEL, 17, 246);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 17, 246, 126, 345);
		DWIN_Show_ICON(GET_PIC_ID(ICON_BIG_CONTROL), GET_ICON_X(CONTROL), 318);
	}
	else {
		DWIN_Show_ICON(ICON_CONTROL, 17, 246);
		DWIN_Show_MultiLanguage_String(MTSTRING_MAIN_CONTROL,  GET_ICON_X(CONTROL),318);
	}
}

inline void Draw_ICON_Infor(const bool selected) {
	if (selected) {
		DWIN_Show_ICON(ICON_BIGINFO_SEL, 145, 246);
		dwinLCD.Draw_Rectangle(0, COLOR_WHITE, 145, 246, 254, 345);
		DWIN_Show_ICON(GET_PIC_ID(ICON_BIG_INFO), GET_ICON_X(INFO), 318);
	}
	else {
		DWIN_Show_ICON(ICON_BIGINFO, 145, 246);
		DWIN_Show_MultiLanguage_String(MTSTRING_MAIN_INFO, GET_ICON_X(INFO),318);
	}
}


#if ENABLED(OPTION_WIFI_MODULE)
inline void Draw_ICON_WIFI(){
	if(queue.wifi_Handshake_ok && WiFi_Enabled){
		DWIN_Show_ICON(ICON_WIFI, 0, 0);
	}
}
#endif

static void Draw_BigICON_MainMenu(){
	Draw_ICON_Print(DwinMenu_main.now == MAIN_CASE_PRINT);
	Draw_ICON_Prepare(DwinMenu_main.now == MAIN_CASE_PREPARE);
	Draw_ICON_Control(DwinMenu_main.now == MAIN_CASE_CONTROL);
	Draw_ICON_Infor(DwinMenu_main.now == MAIN_CASE_INFO);
	dwinLCD.UpdateLCD();
}

void Draw_File_Menu() {
	DwinMenuID = DWMENU_FILE;
	
	Clear_Dwin_Area(AREA_TITAL|AREA_MENU|AREA_STATUS);
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_SDPRINT, TITLE_X, TITLE_Y);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_FILE, 14+GET_ICON_X(FILE), 7);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	Redraw_SD_List();	
	Draw_Status_Area();
}

void Draw_Main_Menu(const bool with_update, const uint8_t MenuItem) {
	DwinMenuID = DWMENU_MAIN;
	DwinMenu_main.set(MenuItem);
	
	dwinLCD.Draw_Rectangle(1, COLOR_BG_BLACK, 0, 0, DWIN_WIDTH, DWIN_HEIGHT);
	DWIN_Show_ICON(ICON_LOGO, LOGO_OFFSET_X, LOGO_OFFSET_Y);	
	Draw_BigICON_MainMenu();
	TERN_(OPTION_WIFI_MODULE,Draw_ICON_WIFI());
	Draw_Status_Area();
	EncoderRate.enabled = false;
	EncoderRate.encoderPlusePerStep = (ENCODER_PULSES_PER_STEP*2);
	if(with_update) dwinLCD.UpdateLCD();
}

void HMI_MainMenu() {
	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;
	HMI_flag.free_close_timer_rg = POWERDOWN_MACHINE_TIMER;	
	if((encoder_diffState == ENCODER_DIFF_CW && DwinMenu_main.inc(MAIN_CASE_END))\
		|| (encoder_diffState == ENCODER_DIFF_CCW && DwinMenu_main.dec())) {
		Draw_BigICON_MainMenu();		
		DWIN_FEEDBACK_TICK();
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_main.now) {
			case MAIN_CASE_PRINT: // Print File
			EncoderRate.encoderPlusePerStep = ENCODER_PULSES_PER_STEP;
			if(card.isMounted()){				
				HMI_SDCardInit();
				Draw_File_Menu();
			}
			else{
				buzzer.tone(100, 3000);
				DWIN_Show_Status_Message(COLOR_RED, PSTR("No SD card? please check!"));
			}
		break;

		case MAIN_CASE_PREPARE: // Prepare
			EncoderRate.encoderPlusePerStep = ENCODER_PULSES_PER_STEP;
			Draw_Prepare_Menu();
		break;

		case MAIN_CASE_CONTROL: // Control
			EncoderRate.encoderPlusePerStep = ENCODER_PULSES_PER_STEP;
			Draw_Control_Menu();
		break;

		case MAIN_CASE_INFO: // Leveling or Info
			EncoderRate.encoderPlusePerStep = ENCODER_PULSES_PER_STEP;			
			Draw_Info_Menu();
		break;

		default: break;
		}
	}
	dwinLCD.UpdateLCD();
}
#endif

