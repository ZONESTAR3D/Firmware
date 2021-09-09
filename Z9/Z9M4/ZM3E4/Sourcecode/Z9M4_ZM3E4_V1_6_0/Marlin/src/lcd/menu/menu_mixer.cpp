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

//
// Mixer Menu
//

#include "../../inc/MarlinConfigPre.h"

#if BOTH(HAS_LCD_MENU, MIXING_EXTRUDER)

#include "menu_item.h"
#include "menu_addon.h"

#include "../../feature/mixing.h"

static uint8_t v_index;
static uint8_t cycle_index = 0;

#if ENABLED(GRADIENT_MIX)

void _lcd_mixer_gradient_z_edit(const bool isend) {
    ui.defer_status_screen();
    ENCODER_RATE_MULTIPLY(true);

    float &zvar = isend ? mixer.gradient.end_z : mixer.gradient.start_z;

    if (ui.encoderPosition) {
      zvar += float(int32_t(ui.encoderPosition)) * 0.1;
      ui.encoderPosition = 0;
      NOLESS(zvar, 0);
      NOMORE(zvar, Z_MAX_POS);
    }

    if (ui.should_draw()) {
      char tmp[16];
      SETCURSOR(1, (LCD_HEIGHT - 1) / 2);
      lcd_put_u8str_P(isend ? GET_TEXT(MSG_END_Z) : GET_TEXT(MSG_START_Z));
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(zvar), int(zvar * 10) % 10);
      SETCURSOR_RJ(9, (LCD_HEIGHT - 1) / 2);
      lcd_put_u8str(tmp);
    }

    if (ui.lcd_clicked) {
      if (isend && zvar < mixer.gradient.start_z)
        mixer.gradient.start_z = zvar;
      else if (!isend && zvar > mixer.gradient.end_z)
        mixer.gradient.end_z = zvar;
      mixer.refresh_gradient();
      ui.goto_previous_screen();
    }
}

//
// Reverse Gradient
//
inline void _lcd_mixer_reverse_gradient() {
    const uint8_t sv = mixer.gradient.start_vtool;
    mixer.gradient.start_vtool = mixer.gradient.end_vtool;
    mixer.gradient.end_vtool = sv;
    mixer.refresh_gradient();
    ui.refresh(LCDVIEW_CALL_REDRAW_NEXT);
}

void lcd_mixer_edit_gradient_menu() {
    START_MENU();
    BACK_ITEM(MSG_MIXER);

    EDIT_ITEM(int8, MSG_START_VTOOL, &mixer.gradient.start_vtool, 0, MIXING_VIRTUAL_TOOLS - 1, mixer.refresh_gradient);
    EDIT_ITEM(int8, MSG_END_VTOOL, &mixer.gradient.end_vtool, 0, MIXING_VIRTUAL_TOOLS - 1, mixer.refresh_gradient);
    
    #if ENABLED(GRADIENT_VTOOL)
      EDIT_ITEM(int8, MSG_GRADIENT_ALIAS, &mixer.gradient.vtool_index, -1, MIXING_VIRTUAL_TOOLS - 1, mixer.refresh_gradient);
    #endif

	ACTION_ITEM(MSG_REVERSE_GRADIENT, _lcd_mixer_reverse_gradient);

    char tmp[18];

    PGM_P const slabel = GET_TEXT(MSG_START_Z);
    SUBMENU_P(slabel, []{ _lcd_mixer_gradient_z_edit(false); });
    MENU_ITEM_ADDON_START_RJ(11);
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(mixer.gradient.start_z), int(mixer.gradient.start_z * 10) % 10);
      lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();

    PGM_P const elabel = GET_TEXT(MSG_END_Z);
    SUBMENU_P(elabel, []{ _lcd_mixer_gradient_z_edit(true); });
    MENU_ITEM_ADDON_START_RJ(11);
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(mixer.gradient.end_z), int(mixer.gradient.end_z * 10) % 10);
      lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();

    END_MENU();
}
  



#endif // GRADIENT_MIX

#if ENABLED(RANDOM_MIX)

void _lcd_mixer_random_z_edit(const bool isend) {
    ui.defer_status_screen();
    ENCODER_RATE_MULTIPLY(true);

    float &zvar = isend ? mixer.random_mix.end_z : mixer.random_mix.start_z;

    if (ui.encoderPosition) {
      zvar += float(int32_t(ui.encoderPosition)) * 0.1;
      ui.encoderPosition = 0;
      NOLESS(zvar, 0);
      NOMORE(zvar, Z_MAX_POS);
    }

    if (ui.should_draw()) {
      char tmp[16];
      SETCURSOR(1, (LCD_HEIGHT - 1) / 2);
      lcd_put_u8str_P(isend ? GET_TEXT(MSG_END_Z) : GET_TEXT(MSG_START_Z));
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(zvar), int(zvar * 10) % 10);
      SETCURSOR_RJ(9, (LCD_HEIGHT - 1) / 2);
      lcd_put_u8str(tmp);
    }

    if (ui.lcd_clicked) {
      if (isend && zvar < mixer.random_mix.start_z)
        mixer.random_mix.start_z = zvar;
      else if (!isend && zvar > mixer.random_mix.end_z)
        mixer.random_mix.end_z = zvar;
      mixer.refresh_random_mix();
      ui.goto_previous_screen();
    }
}

void lcd_mixer_edit_random_menu() {
    START_MENU();
    BACK_ITEM(MSG_MIXER);
    char tmp[18];

    PGM_P const slabel = GET_TEXT(MSG_START_Z);
    SUBMENU_P(slabel, []{ _lcd_mixer_random_z_edit(false); });
    MENU_ITEM_ADDON_START_RJ(11);
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(mixer.random_mix.start_z), int(mixer.random_mix.start_z * 10) % 10);
      lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();

    PGM_P const elabel = GET_TEXT(MSG_END_Z);
    SUBMENU_P(elabel, []{ _lcd_mixer_random_z_edit(true); });
    MENU_ITEM_ADDON_START_RJ(11);
      sprintf_P(tmp, PSTR("%4d.%d mm"), int(mixer.random_mix.end_z), int(mixer.random_mix.end_z * 10) % 10);
      lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();

	EDIT_ITEM(float51, MSG_HEIGHT, &mixer.random_mix.height, 0.1, 100.0);
	EDIT_ITEM(uint8, MSG_INFO_EXTRUDERS, &mixer.random_mix.extruders, 1, MIXING_STEPPERS);

    END_MENU();
}

#endif // RANDOM_MIX



void _lcd_mixer_DwinMenu_leveling() {
  mixer.T(v_index);  
}


#if ENABLED(USE_PRECENT_MIXVALUE)	
void _lcd_mixer_cycle_mix() {
	  mixer.init_collector(cycle_index);
	  cycle_index++;
	  if(cycle_index > MIXING_VIRTUAL_TOOLS)
		  cycle_index = 0;
	  mixer.normalize();
		TERN_(USE_PRECENT_MIXVALUE,mixer.copy_collector_to_percentmix());
	  ui.refresh();
}
#else
void _lcd_mixer_cycle_mix() {  	
    uint16_t bits = 0;
    MIXER_STEPPER_LOOP(i) if (mixer.collector[i]) SBI(bits, i);
    bits = (bits + 1) & (_BV(MIXING_STEPPERS) - 1);
    if (!bits) ++bits;
    MIXER_STEPPER_LOOP(i) mixer.collector[i] = TEST(bits, i) ? 10.0f : 0.0f;
    ui.refresh();
}
#endif
void _lcd_mixer_commit_vtool() {
#if ENABLED(USE_PRECENT_MIXVALUE)	
		mixer.copy_percentmix_to_collector();
#endif  	
    mixer.normalize();
    //ui.goto_previous_screen();
    ui.refresh();
}

void lcd_mixer_mix_edit() {
    START_MENU();
    BACK_ITEM(MSG_MIXER);
#if ENABLED(USE_PRECENT_MIXVALUE)
    LOOP_S_LE_N(n, 1, MIXING_STEPPERS)
      EDIT_ITEM_FAST_N(int8, n, MSG_MIX_COMPONENT_N, &mixer.percentmix[n-1], 0, 100);
#else
    LOOP_S_LE_N(n, 1, MIXING_STEPPERS)
      EDIT_ITEM_FAST_N(float42_52, n, MSG_MIX_COMPONENT_N, &mixer.collector[n-1], 0, 10);
#endif
    ACTION_ITEM(MSG_COMMIT_VTOOL, _lcd_mixer_commit_vtool);
		ACTION_ITEM(MSG_CYCLE_MIX, _lcd_mixer_cycle_mix);
    END_MENU();
}


//
// Prepare and Edit Mix
//
inline void _lcd_goto_mix_edit() {
	mixer.refresh_collector(10, v_index);
#if ENABLED(USE_PRECENT_MIXVALUE)	
	mixer.copy_collector_to_percentmix();
#endif
	ui.goto_screen(lcd_mixer_mix_edit);
	lcd_mixer_mix_edit();
}


void menu_mixer() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);

  v_index = mixer.get_current_vtool();
  EDIT_ITEM(uint8, MSG_ACTIVE_VTOOL, &v_index, 0, MIXING_VIRTUAL_TOOLS - 1, _lcd_mixer_DwinMenu_leveling, ENABLED(HAS_DUAL_MIXING));
  
  SUBMENU(MSG_MIX, _lcd_goto_mix_edit);
  
  //
  // Reset All V-Tools
  //
  CONFIRM_ITEM(MSG_RESET_VTOOLS,
    MSG_BUTTON_RESET, MSG_BUTTON_CANCEL,
    []{
      mixer.reset_vtools();
      LCD_MESSAGEPGM(MSG_VTOOLS_RESET);
      ui.return_to_status();
    },
    nullptr,
    GET_TEXT(MSG_RESET_VTOOLS), (const char *)nullptr, PSTR("?")
  );

  #if ENABLED(GRADIENT_MIX)
  {
    char tmp[13];
    SUBMENU(MSG_GRADIENT, lcd_mixer_edit_gradient_menu);
    MENU_ITEM_ADDON_START_RJ(9);
	  if(mixer.gradient.enabled)
	    strcpy_P(tmp, PSTR(": enable"));
	  else
	    strcpy_P(tmp, PSTR(":disable"));
	 lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();    
  }
  #endif

  #if ENABLED(RANDOM_MIX)
  {
    char tmp[13];
    SUBMENU(MSG_RANDOMMIX, lcd_mixer_edit_random_menu);
    MENU_ITEM_ADDON_START_RJ(9);
      if(mixer.random_mix.enabled)
	    strcpy_P(tmp, PSTR(": enable"));
	  else
	  	strcpy_P(tmp, PSTR(":disable"));
      lcd_put_u8str(tmp);
    MENU_ITEM_ADDON_END();
  }
  #endif
  
  END_MENU();
}

#endif // HAS_LCD_MENU && MIXING_EXTRUDER
