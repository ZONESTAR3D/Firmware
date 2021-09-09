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
 * DwinMenu_RepeatPrint.cpp
 */

 #include "../../../inc/MarlinConfig.h"

#if (HAS_DWIN_LCD && ENABLED(OPTION_REPEAT_PRINTING))
#include "dwin.h"

bool _check_repeatPrint(){
	switch(ReprintManager.Reprint_check_state()){
		case REPRINT_FINISHED:
			DwinMenu_main.reset();
			DWIN_status = ID_SM_STOPED;
			return true;
			
		case REPRINT_NEXT:
			HMI_flag.show_mode = SHOWED_TUNE;
			card.openAndPrintFile(card.filename);
			DWIN_status = ID_SM_PRINTING;
			DwinMenu_print.reset();
			Draw_Printing_Menu(true);
			return true; 		
			
		default:
			break;
	}  
	return false;
}

void HMI_Reprint_Times() {
	char Reprint_Buf[50] = {0}; 
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &ReprintManager.Reprint_times)) {
			DwinMenuID = DWMENU_SET_REPRINT;
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(4, MENUVALUE_X, MBASE(MROWS -select_reprint.index + REPRINT_CASE_TIMES), ReprintManager.Reprint_times);
			ZERO(Reprint_Buf);
			sprintf_P(Reprint_Buf,PSTR("M180 T%4d"),ReprintManager.Reprint_times);
			queue.inject(Reprint_Buf);
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(ReprintManager.Reprint_times, 0);
		NOMORE(ReprintManager.Reprint_times, REPEAT_PRINTING_MAX_TIMES);
		DWIN_Draw_Select_IntValue_Default(4, MENUVALUE_X, MBASE(MROWS -select_reprint.index + REPRINT_CASE_TIMES), ReprintManager.Reprint_times);
		dwinLCD.UpdateLCD();
	}
}

void HMI_Forward_Lenght() {
	char Reprint_Buf[50] = {0}; 
	ENCODER_DiffState encoder_diffState = Encoder_ReceiveAnalyze();
	if (encoder_diffState != ENCODER_DIFF_NO) {
		if (Apply_Encoder_int16(encoder_diffState, &ReprintManager.Forward_lenght)) {
			DwinMenuID = DWMENU_SET_REPRINT;
			EncoderRate.enabled = false;
			DWIN_Draw_IntValue_Default(4, MENUVALUE_X, MBASE(MROWS -select_reprint.index + REPRINT_CASE_LENGHT), ReprintManager.Forward_lenght);
			ZERO(Reprint_Buf);
			sprintf_P(Reprint_Buf,PSTR("M180 L%4d"),ReprintManager.Forward_lenght);
			queue.inject(Reprint_Buf);
			dwinLCD.UpdateLCD();
			return;
		}
		NOLESS(ReprintManager.Forward_lenght, 0);
		NOMORE(ReprintManager.Forward_lenght, FORWARD_PRINTING_MAX_LENGHT);
		DWIN_Draw_Select_IntValue_Default(4, MENUVALUE_X, MBASE(MROWS -select_reprint.index + REPRINT_CASE_LENGHT), ReprintManager.Forward_lenght);
		dwinLCD.UpdateLCD();
	}
}


#endif

