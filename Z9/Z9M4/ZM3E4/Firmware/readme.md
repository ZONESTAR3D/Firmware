## :book: Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:
- **for LCD12864** ***MENU>>Configuration>>Advanced setting>>initialize  EEPROM***
- **for LCD_DWIN** ***MENU>>Control>>Restore Default***

----
## Wiring
About wiring, please refer to "Z9M4 Firmware and Wiring Diagram.pdf"
### Motor Working Direction
**If the motor working direction is reserved, please refer to the below photo to modify it:**
![how to change motor woking direction](./how_to_change_motor_woking_direction.jpg)

----

## Release Note
#### About DWIN LCD MENU V3
You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN)

### Version: V3.0.0_beta 
+ Date: 	 2022-10-18
+ NOTE:
- [**NEW**] Upgrade to DWIN LCD MENU V3 [:point_down: About detail](#about-dwin-lcd-menu-v3)
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**NEW**] Add a "flow rate" tune menu when printing from SD card.
- [**NEW**] Add WiFi Feature. You need to add a WiFi module to the control board before active this feature, For details, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/WiFi)
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "Max Hotend temp" menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**BUG**] Correct print time (printed time and remain time).
- [**BUG**] Fixed some known bugs.

#### :black_circle: Z9M4 + LCDDWIN [:arrow_down:](./V3_0_0_beta/Z9M4_LCDDWIN_V3_0_0.zip)
#### :black_circle: Z9M4 + LCDDWIN + TMC220x@XYZ [:arrow_down:](./V3_0_0_beta/Z9M4_LCDDWIN_TMC220x@XYZ_V3_0_0.zip)
#### :black_circle: Z9M4 + LCDDWIN + TMC220x@All [:arrow_down:](./V3_0_0_beta/Z9M4_LCDDWIN_TMC220x@All_V3_0_0.zip)

--------
### Version: V2.0.0_beta
+ Date: 	 2022-05-19
+ NOTE:
- [**NEW**] Upgrade to DWIN LCD MENU V2 [:point_down:](#about-dwin-lcd-menu-v2)
#### About DWIN LCD MENU V2
1. You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
3. About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V2.pdf)  

### Version: V1.7.0_beta  
+ Date: 	 2022-01-14
+ NOTE:
>
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters (for LCD_DWIN).
- [**CHG**]Optimize automatic test display and process (for LCD_DWIN).
- [**CHG**]Add "Hotend PID Tune" menu (for LCD_DWIN).
- [**BUG**]fix some bugs.
 
### Version: V1.6.0
+ Date:    2021-07-15
+ NOTE:
> 
+ [NEW] (for LCD_DWIN) Add filament load/unload menu
+ [NEW] (for LCD_DWIN) Add bed leveling data table shows on LCD screen
+ [BUG] (for LCD_DWIN) fix some known bugs
+ [CHG] add "bed automatic leveling" to 5x5 Grid
+ [CHG] Automatically correct Z offset after "bed automatic leveling"(G29 command)

### Version: V1.5.0
+ Date:    2021-04-25
+ NOTE:
>
+ [NEW] Add Bedcoating setting
+ [NEW] Add Auto Leveling featurn switch on configure Menu(DWIN_LCD)

### Version: V1.4.0
+ Date:    2021-04-25
+ NOTE:
>
+ [NEW] Add WiFi feature
+ [CHG] Remaping the BLTouch wiring if 3DTouch feature is enabled
for LCD12864[+TFT-LCD35]: LCD12864>>EXP1 3DTouch>>EXP2 TFT-LCD35>>AUX1  
for LCD_DWIN            : LCD_DWIN>>EXP2 3DTouch>>EXP1

### Version: V1.3.0
+ Date:    2020-12-23
+ NOTE:
>
+ [CHG] Correct the display data transmit speed of LCD12864
+ [NEW] Modify the Random mixing feature
	1-1. add a "Height" parameter, When the z-axis height change is greater than or equal to this value, the color mixing ratio change is performed once
	1-2. add a "Extruders" parameter, it means how many extruders involved in random mixing;  
	+ when Extruders = 1,switch between the all of extruders randomlly.  
	+ when Extruders = 2, extruder 1,2 will be mixed on a random mixing ratio.  
	+ when Extruders = 3, extruder 1,2,3 will be mixed on a random mixing ratio.  
	+ when Extruders = 4, extruder 1,2,3,4 will be mixed on a random mixing ratio.  
+ [NEW] Auto reset the VTOOL setting to default if printed complete from SD card.

### Version: V1.2.5
+ Date:    2020-12-04
+ NOTE:
> 
+ [BUG] Correct the display temperature when the ambient temperature is low


### Version: V1.2.4
+ Date:    2020-11-09
+ NOTE:
>
+ [BUG] fix an issue of power loss resume:
when auto leveling feature is enable, it doesn't work well when resume from power loss

### Version: V1.2.3
+ Date:    2020-11-05
+ NOTE:
>
+ [BUG] fix an issue: when the file in the root directory on SD card, 
"power loss fail resume" can't start to work.



