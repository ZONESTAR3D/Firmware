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
 * DwinMenu_Infor.cpp
 */

 #include "../../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include "dwin.h"




/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Info menu
//
static void Item_Info_Version(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Version:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Version:")+1)*MENU_CHR_W, MBASE(row),  PSTR(FIRMWARE_VERSION));
}

static void Item_Info_Firmware(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Firmware:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Firmware:")+1)*MENU_CHR_W, MBASE(row),  PSTR(SHORT_BUILD_VERSION));
}

static void Item_Info_Website(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Website:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Website:")+1)*MENU_CHR_W, MBASE(row), PSTR(WEBSITE_URL));
}

static void Item_Info_Model(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Model:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Model:")+1)*MENU_CHR_W, MBASE(row), PSTR(CUSTOM_MACHINE_NAME));
}

static void Item_Info_Board(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Board:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Board:")+1)*MENU_CHR_W, MBASE(row), PSTR(BOARD_INFO_NAME));
}

static void Item_Info_Extruder_Num(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Extruder Num:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Extruder Num:")+1)*MENU_CHR_W, MBASE(row),PSTR(STRINGIFY(E_STEPPERS)));

}

#if ENABLED(OPTION_BGM)
#define EXTRUDER_MODEL				"BGM"
#else
#define EXTRUDER_MODEL				"Titan"
#endif
static void Item_Info_Extruder_Model(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Extruder Model:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Extruder Model:")+1)*MENU_CHR_W, MBASE(row), PSTR(EXTRUDER_MODEL));
}


#if ENABLED(OPTION_DUALZ_DRIVE)
#define Z_Drive						"DUAL Z"
static void Item_Info_DualZ_Drive(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Z Drive:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Z Drive:")+1)*MENU_CHR_W, MBASE(row), PSTR(Z_Drive));
}
#endif

#if ENABLED(OPTION_Z2_ENDSTOP)
#define Z_Endstop					"DUAL Endstop"
static void Item_Info_DualZ_Endstop(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Z Endstop:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Z Endstop:")+1)*MENU_CHR_W, MBASE(row), PSTR(Z_Endstop));
}
#endif

static void Item_Info_Baudrate(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Baudrate:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Baudrate:")+1)*MENU_CHR_W, MBASE(row), PSTR(STRINGIFY(BAUDRATE)));
}

static void Item_Info_Protocol(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Protocol:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Protocol:")+1)*MENU_CHR_W, MBASE(row), PSTR(PROTOCOL_VERSION));
}

static void Item_Info_Psu(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("PSU:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("PSU:")+1)*MENU_CHR_W, MBASE(row), PSTR(PSU_NAME));
}

static void Item_Info_Date(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Date:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Date:")+1)*MENU_CHR_W, MBASE(row), PSTR(STRING_DISTRIBUTION_DATE));
}

static void Item_Info_Thermistor(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Thermistor:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Thermistor:")+1)*MENU_CHR_W, MBASE(row), PSTR("100k with 4.7k pull-up"));
 //DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Thermistor:")+1)*MENU_CHR_W, MBASE(row), (char*)STRINGIFY(THERMISTOR_HEATER_0));
}

static void Item_Info_Bed(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Hot bed:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Hot bed:"))*MENU_CHR_W, MBASE(row), PSTR("MINTEMP:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("MINTEMP:") + strlen("Hot bed:"))*MENU_CHR_W, MBASE(row), PSTR(STRINGIFY(BED_MINTEMP)));
 DWIN_Draw_UnMaskString_Default(175, MBASE(row), PSTR("MAXTEMP:"));
 DWIN_Draw_UnMaskString_Default(175 + (strlen("MAXTEMP:"))*MENU_CHR_W, MBASE(row), PSTR(STRINGIFY(BED_MAXTEMP)));
}

static void Item_Info_Hot(const uint8_t row) {
 DWIN_Draw_UnMaskString_Default(LBLX_INFO, MBASE(row), PSTR("Hot end:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Hot end:"))*MENU_CHR_W, MBASE(row), PSTR("MINTEMP:"));
 DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("MINTEMP:")+strlen("Hot end:"))*MENU_CHR_W, MBASE(row), PSTR(STRINGIFY(HEATER_0_MINTEMP)));
 DWIN_Draw_UnMaskString_Default(175, MBASE(row), PSTR("MAXTEMP:"));
 DWIN_Draw_UnMaskString_Default(175 + (strlen("MAXTEMP:"))*MENU_CHR_W, MBASE(row), PSTR(STRINGIFY(HEATER_0_MAXTEMP)));
}

void Draw_Info_Menu() {
	DwinMenuID = DWMENU_INFO;
	DwinMenu_infor.reset();
	//DwinMenu_infor.index = _MAX(DwinMenu_infor.now, MROWS);
	
#if(INFO_CASE_TOTAL > MROWS)
	const int16_t iscroll = MROWS - DwinMenu_infor.index; // Scrolled-up lines
	#define ICSCROL(L) (iscroll + (L))
#else
	#define ICSCROL(L) (L)
#endif
	#define ICLINE(L) MBASE(ICSCROL(L))
	#define ICVISI(L) WITHIN(ICSCROL(L), 0, MROWS)

	Clear_Dwin_Area(AREA_TITAL|AREA_MENU|AREA_STATUS);
	
	dwinLCD.JPG_CacheTo1(HMI_flag.Title_Menu_Backup);
	DWIN_Show_MultiLanguage_String(MTSTRING_TITLE_INFO, TITLE_X, TITLE_Y);
	dwinLCD.JPG_CacheTo1(HMI_flag.language+1);
	if (ICVISI(0)) Draw_Back_First(DwinMenu_infor.now == 0);             						// < Back

	DWIN_Draw_UnMaskString_Default(LBLX_INFO, ICLINE(INFO_CASE_VERSION), PSTR("Version:"));
	DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Version:")+1)*MENU_CHR_W, ICLINE(INFO_CASE_VERSION), PSTR(FIRMWARE_VERSION));  	
	dwinLCD.Draw_Line(LINE_COLOR, 16, ICLINE(INFO_CASE_VERSION) + 33, 256, ICLINE(INFO_CASE_VERSION) + 34);
	DWIN_Draw_UnMaskString_Default(LBLX_INFO, ICLINE(INFO_CASE_FIRMWARE), PSTR("Firmware:"));
	DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Firmware:")+1)*MENU_CHR_W, ICLINE(INFO_CASE_FIRMWARE), PSTR(SHORT_BUILD_VERSION)); 
	dwinLCD.Draw_Line(LINE_COLOR, 16, ICLINE(INFO_CASE_FIRMWARE) + 33, 256, ICLINE(INFO_CASE_FIRMWARE) + 34);
	DWIN_Draw_UnMaskString_Default(LBLX_INFO, ICLINE(INFO_CASE_WEBSITE), PSTR("Website:"));
	DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Website:")+1)*MENU_CHR_W, ICLINE(INFO_CASE_WEBSITE), PSTR(WEBSITE_URL)); 
	dwinLCD.Draw_Line(LINE_COLOR, 16, ICLINE(INFO_CASE_WEBSITE) + 33, 256, ICLINE(INFO_CASE_WEBSITE) + 34);
	DWIN_Draw_UnMaskString_Default(LBLX_INFO, ICLINE(INFO_CASE_MODEL), PSTR("Model:"));
	DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Model:")+1)*MENU_CHR_W, ICLINE(INFO_CASE_MODEL), PSTR(CUSTOM_MACHINE_NAME)); 
	dwinLCD.Draw_Line(LINE_COLOR, 16, ICLINE(INFO_CASE_MODEL) + 33, 256, ICLINE(INFO_CASE_MODEL) + 34);
	DWIN_Draw_UnMaskString_Default(LBLX_INFO, ICLINE(INFO_CASE_BOARD), PSTR("Board:"));
	DWIN_Draw_UnMaskString_Default(LBLX_INFO + (strlen("Board:")+1)*MENU_CHR_W, ICLINE(INFO_CASE_BOARD), PSTR(BOARD_INFO_NAME)); 
	dwinLCD.Draw_Line(LINE_COLOR, 16, ICLINE(INFO_CASE_BOARD) + 33, 256, ICLINE(INFO_CASE_BOARD) + 34);
	if (DwinMenu_infor.now)	Draw_Menu_Cursor(ICSCROL(DwinMenu_infor.now));  
	
	Draw_Status_Area();
}


/* Info */
void HMI_Info() {

	ENCODER_DiffState encoder_diffState = get_encoder_state();
	if (encoder_diffState == ENCODER_DIFF_NO) return;
	
	#if ENABLED(DWIN_AUTO_TEST)
	static uint8_t testmode_click_times = 0;
	#endif

	if (encoder_diffState == ENCODER_DIFF_CW) {
		if (DwinMenu_infor.inc(INFO_CASE_END)) {
			if (DwinMenu_infor.now > MROWS && DwinMenu_infor.now > DwinMenu_infor.index) {
				DwinMenu_infor.index = DwinMenu_infor.now;

				// Scroll up and draw a blank bottom line
				Scroll_Menu(DWIN_SCROLL_UP);		
				if(DwinMenu_infor.index == INFO_CASE_EXTRUDER_NUM) Item_Info_Extruder_Num(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_EXTRUDER_MODEL) Item_Info_Extruder_Model(MROWS);		
			#if ENABLED(OPTION_DUALZ_DRIVE)
				else if(DwinMenu_infor.index == INFO_CASE_DUALZ_DRIVE) Item_Info_DualZ_Drive(MROWS);
			#endif
			#if ENABLED(OPTION_Z2_ENDSTOP)
				else if(DwinMenu_infor.index == INFO_CASE_DUALZ_ENDSTOP) Item_Info_DualZ_Endstop(MROWS);
			#endif
				else if(DwinMenu_infor.index == INFO_CASE_BAUDRATE) Item_Info_Baudrate(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_PROTOCOL) Item_Info_Protocol(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_PSU) Item_Info_Psu(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_DATE) Item_Info_Date(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_THERMISTOR) Item_Info_Thermistor(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_BED) Item_Info_Bed(MROWS);
				else if(DwinMenu_infor.index == INFO_CASE_HOT) Item_Info_Hot(MROWS);
			}
			else 
				Move_Highlight(1, DwinMenu_infor.now + MROWS - DwinMenu_infor.index);
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_CCW) {
		if (DwinMenu_infor.dec()) {
			if (DwinMenu_infor.now < DwinMenu_infor.index - MROWS) {
				DwinMenu_infor.index--;
				Scroll_Menu(DWIN_SCROLL_DOWN);		
				if(DwinMenu_infor.index - MROWS == INFO_CASE_BACK) Draw_Back_First();				
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_BAUDRATE) Item_Info_Baudrate(0);
			#if ENABLED(OPTION_Z2_ENDSTOP)
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_DUALZ_ENDSTOP) Item_Info_DualZ_Endstop(0);
			#endif
			#if ENABLED(OPTION_DUALZ_DRIVE)
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_DUALZ_DRIVE) Item_Info_DualZ_Drive(0);
			#endif
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_EXTRUDER_MODEL) Item_Info_Extruder_Model(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_EXTRUDER_NUM) Item_Info_Extruder_Num(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_BOARD) Item_Info_Board(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_MODEL) Item_Info_Model(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_WEBSITE) Item_Info_Website(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_FIRMWARE) Item_Info_Firmware(0);
				else if(DwinMenu_infor.index - MROWS == INFO_CASE_VERSION) Item_Info_Version(0);
			}
			else {
				Move_Highlight(-1, DwinMenu_infor.now + MROWS - DwinMenu_infor.index);
			}
		}
	}
	else if (encoder_diffState == ENCODER_DIFF_ENTER) {
		switch (DwinMenu_infor.now) {
			case 0: // Back
				Draw_Main_Menu(false, MAIN_CASE_INFO);
			break;
			
		#if ENABLED(DWIN_AUTO_TEST)
			case INFO_CASE_DATE:				
				if(++testmode_click_times >= 5){	
					HMI_flag.auto_test_flag = 0xaa;
					autotest.HMI_StartTest();
				}
			break;
		#endif
			
			default:	break;
		}
	}
	dwinLCD.UpdateLCD();
}
#endif

