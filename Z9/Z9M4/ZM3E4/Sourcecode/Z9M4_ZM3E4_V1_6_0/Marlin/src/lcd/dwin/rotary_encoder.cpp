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

/*****************************************************************************
 * @file     rotary_encoder.cpp
 * @author   LEO / Creality3D
 * @date     2019/07/06
 * @version  2.0.1
 * @brief    Rotary encoder functions
 *****************************************************************************/

#include "../../inc/MarlinConfig.h"

#if HAS_DWIN_LCD
#include <WString.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rotary_encoder.h"
#include "../../MarlinCore.h"
#include "../../HAL/shared/Delay.h"
#include "dwin_ui/dwin.h"
#if HAS_BUZZER
#include "../../libs/buzzer.h"
#endif

_stENCODER_Rate_ EncoderRate;

// Buzzer
void Encoder_tick(void) {
  WRITE(BEEPER_PIN, 1);
  delay(10);
  WRITE(BEEPER_PIN, 0);
}

// Encoder initialization
void Encoder_Configuration(void) {
  #if BUTTON_EXISTS(EN1)
    SET_INPUT_PULLUP(BTN_EN1);
  #endif
  #if BUTTON_EXISTS(EN2)
    SET_INPUT_PULLUP(BTN_EN2);
  #endif
  #if BUTTON_EXISTS(ENC)
    SET_INPUT_PULLUP(BTN_ENC);
  #endif
  #ifdef BEEPER_PIN
    SET_OUTPUT(BEEPER_PIN);
  #endif
}

// Analyze encoder value and return state
ENCODER_DiffState Encoder_ReceiveAnalyze(void) {
  const millis_t now = millis();
  static unsigned char lastEncoderBits;
  unsigned char newbutton = 0;
  static signed char temp_diff = 0;

  ENCODER_DiffState temp_diffState = ENCODER_DIFF_NO;
  if (BUTTON_PRESSED(EN1)) newbutton |= 0x01;
  if (BUTTON_PRESSED(EN2)) newbutton |= 0x02;
  if (BUTTON_PRESSED(ENC)) {
    static millis_t next_click_update_ms;
    if (ELAPSED(now, next_click_update_ms)) {
      next_click_update_ms = millis() + 300;
      //Encoder_tick();
      buzzer.tone(20, 1000);
	  
      const bool was_waiting = wait_for_user;
      wait_for_user = false;
      return was_waiting ? ENCODER_DIFF_NO : ENCODER_DIFF_ENTER;
    }
    else return ENCODER_DIFF_NO;
  }
  
  if (newbutton != lastEncoderBits) {
    switch (newbutton) {
      case ENCODER_PHASE_0: {
        if (lastEncoderBits == ENCODER_PHASE_3) temp_diff++;
        else if (lastEncoderBits == ENCODER_PHASE_1) temp_diff--;
      }break;
      case ENCODER_PHASE_1: {
        if (lastEncoderBits == ENCODER_PHASE_0) temp_diff++;
        else if (lastEncoderBits == ENCODER_PHASE_2) temp_diff--;
      }break;
      case ENCODER_PHASE_2: {
        if (lastEncoderBits == ENCODER_PHASE_1) temp_diff++;
        else if (lastEncoderBits == ENCODER_PHASE_3) temp_diff--;
      }break;
      case ENCODER_PHASE_3: {
        if (lastEncoderBits == ENCODER_PHASE_2) temp_diff++;
        else if (lastEncoderBits == ENCODER_PHASE_0) temp_diff--;
      }break;
    }
    lastEncoderBits = newbutton;
  }

  if (abs(temp_diff) >= EncoderRate.encoderPlusePerStep) {
    if (temp_diff > 0) temp_diffState = ENCODER_DIFF_CW;
    else temp_diffState = ENCODER_DIFF_CCW;

    #if ENABLED(ENCODER_RATE_MULTIPLIER)

      millis_t ms = millis();
      int32_t encoderMultiplier = 1;

      // if must encoder rati multiplier
      if (EncoderRate.enabled) {
        const float abs_diff = ABS(temp_diff),
                    encoderMovementSteps = abs_diff / (EncoderRate.encoderPlusePerStep);
        if (EncoderRate.lastEncoderTime) {
          // Note that the rate is always calculated between two passes through the
          // loop and that the abs of the temp_diff value is tracked.
          const float encoderStepRate = encoderMovementSteps / float(ms - EncoderRate.lastEncoderTime) * 1000;
               if (encoderStepRate >= ENCODER_100X_STEPS_PER_SEC) encoderMultiplier = 100;
          else if (encoderStepRate >= ENCODER_10X_STEPS_PER_SEC)  encoderMultiplier = 10;
          else if (encoderStepRate >= ENCODER_5X_STEPS_PER_SEC)   encoderMultiplier = 5;
        }
        EncoderRate.lastEncoderTime = ms;
      }
    #else
      constexpr int32_t encoderMultiplier = 1;
    #endif // ENCODER_RATE_MULTIPLIER

    // EncoderRate.encoderMoveValue += (temp_diff * encoderMultiplier) / (EncoderRate.encoderPlusePerStep);
    EncoderRate.encoderMoveValue = (temp_diff * encoderMultiplier) / (EncoderRate.encoderPlusePerStep);
    if (EncoderRate.encoderMoveValue < 0) EncoderRate.encoderMoveValue = -EncoderRate.encoderMoveValue;

    temp_diff = 0;
  }
  return temp_diffState;
}

ENCODER_DiffState get_encoder_state() {
  static millis_t Encoder_ms = 0;
  const millis_t ms = millis();
  if (PENDING(ms, Encoder_ms)) return ENCODER_DIFF_NO;
  const ENCODER_DiffState state = Encoder_ReceiveAnalyze();
  if (state != ENCODER_DIFF_NO){
		Encoder_ms = ms + ENCODER_WAIT;
		TERN_(OPTION_AUTOPOWEROFF, _reset_shutdown_timer());
  }
  return state;
}

#endif // HAS_DWIN_LCD