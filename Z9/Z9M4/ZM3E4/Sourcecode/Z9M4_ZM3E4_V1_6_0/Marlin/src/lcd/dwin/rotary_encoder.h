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

/*****************************************************************************
  * @file     rotary_encoder.h
  * @author   LEO / Creality3D
  * @date     2019/07/06
  * @version  2.0.1
  * @brief    Rotary encoder functions
  ****************************************************************************/
#if HAS_DWIN_LCD
/*********************** Encoder Set ***********************/

#define ENCODER_PHASE_0  0
#define ENCODER_PHASE_1  2
#define ENCODER_PHASE_2  3
#define ENCODER_PHASE_3  1

#define ENCODER_WAIT    20

#define BUTTON_PRESSED(BN) !READ(BTN_## BN)


typedef struct {
	bool enabled = false;
	uint8_t encoderPlusePerStep = ENCODER_PULSES_PER_STEP;
	int16_t encoderMoveValue = 0;
	millis_t lastEncoderTime = 0;
}_stENCODER_Rate_;

typedef enum {
  ENCODER_DIFF_NO    = 0,  // no state
  ENCODER_DIFF_CW    = 1,  // clockwise rotation
  ENCODER_DIFF_CCW   = 2,  // counterclockwise rotation
  ENCODER_DIFF_ENTER = 3   // click
} ENCODER_DiffState;


extern _stENCODER_Rate_ EncoderRate;

// Encoder initialization
void Encoder_Configuration(void);
// Analyze encoder value and return state
ENCODER_DiffState Encoder_ReceiveAnalyze(void);
ENCODER_DiffState get_encoder_state();

#endif//HAS_DWIN_LCD