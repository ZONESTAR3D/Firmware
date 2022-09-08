#### :warning: !ATTETION PLEASE! 
#### About DWIN LCD MENU V3
You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN)

#### About DWIN LCD MENU V2
You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 2.4 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN)

#### :book: Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware: ***MENU>>Control>>Restore Defaults***

## Release Note
-----------------------------------------
### DWIN LCD MENU V3 [:point_up:](#about-dwin-lcd-menu-v3)
### Z9V5Pro-MK3 V3.0.0 beta [:arrow_down:](Z9V5Pro-MK3_V3_0_0_beta.zip)
- **Date:** 2022-07-06
- [**NEW**] Add a "flow rate" tune menu when priinting from SD card  
**NOTE** it need upgrade to DWIN LCD MENU V3

-----------------------------------------
### DWIN LCD MENU V2 [:point_up:](#about-dwin-lcd-menu-v2)
### Z9V5Pro-MK3 V2.5.0 beta [:arrow_down:](Z9V5Pro-MK3_V2_5_0_beta.zip)
- **Date:** 2022-07-01
- [**BUG**] Fix issue on disply string.
- [**BUG**] Fix issue when adjust Z offset when auto bed leveling is actived
- [**CHG**] Backlight shows as "Breathing lamp" when auto shutdown is on

### Z9V5Pro-MK3 V2.4.9 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_9_beta.zip)
- **Date:** 2022-06-18
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

### Z9V5Pro-MK3 V2.4.8 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_8_beta.zip)
- **Date:** 2022-05-13
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight

### Z9V5Pro-MK3 V2.4.7 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_7_beta.zip)
- **Date:** 2022-04-25
- [**BUG**] Correct print time (printed time and remain time)

### Z9V5Pro-MK3 V2.4.6 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_6_beta.zip)
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.

### Z9V5Pro-MK3 V2.4.5 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_5_beta.zip)
- **Date:** 2022-04-20
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected(need to add WiFi module).

### Z9V5Pro-MK3 V2.4.3 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_3_beta.zip)
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu.
- [**NEW**] Add "View User Guide" on INFO menu.

### Z9V5Pro-MK3 V2.4.2 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_2_beta.zip)
- **Date:** 2022-04-02
- [**BUG**] Extend the waiting time to confirm the WiFi.

### Z9V5Pro-MK3 V2.4.1 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_1_beta.zip)
- **Date:** 2022-03-29
- [**CHG**] Add nozzle temperature settings on Prepare>>Filament menu. 

### Z9V5Pro-MK3 V2.4.0 beta [:arrow_down:](Z9V5Pro_MK3_V2_4_0_beta.zip)
- **Date:** 2022-03-09
- [**NEW**] Upgrade to DWIN LCD MENU V2. For details, please refer to :point_up: [**here**](#about-dwin-lcd-menu-v2)
- [**NEW**] Add a "Mixing Feature" to switch on/off mixing feature.
- [**NEW**] Add a "Extr.Sequence" menu to exchange the extrders sequence (only work on Non-mixing hotend).  

-----------------------------------------
### DWIN LCD MENU V1

### Z9V5Pro-MK3 V2.3.9 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_9_beta.zip)
- **Date:** 2022-06-20
- [**BUG**] Correct print time (printed time and remain time)
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight

### Z9V5Pro-MK3 V2.3.6 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_6_beta.zip)
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Updates News" on info Menu

### Z9V5Pro-MK3 V2.3.5 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_5_beta.zip)
- **Date:** 2022-04-20
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected(need to add WiFi module).

### Z9V5Pro-MK3 V2.3.4 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_4_beta.zip)
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu.
- [**NEW**] Add "View User Guide" on INFO menu.

### Z9V5Pro-MK3 V2.3.3 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_3_beta.zip)
- **Date:** 2022-04-02
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**BUG**] Extend the waiting time to confirm the connection to prevent misjudgment (Connecting fail).

### Z9V5Pro-MK3 V2.3.2 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_2_beta.zip)
- **Date:** 2022-03-08
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".

### Z9V5Pro-MK3 V2.3.1 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_1_beta.zip)
- **Date:** 2022-02-25
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  

### Z9V5Pro-MK3 V2.3.0 beta [:arrow_down:](Z9V5Pro_MK3_V2_3_0_beta.zip)
- **Date:** 2022-01-07
- [**New**]Add "Hotend PID tune" menu.  
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### Z9V5Pro-MK3 V2.2.2 beta [:arrow_down:](Z9V5Pro_MK3_V2_2_2_beta.zip)
- **Date:** 2021-12-30
- [**BUG**] Add Base Heigth settings for repeat printing feature. 

### Z9V5Pro-MK3 V2.2.1 beta [:arrow_down:](Z9V5Pro_MK3_V2_2_1_beta.zip)
- **Date:** 2021-12-28
- [**New**] Add auto repeat printing feature. 

### Z9V5Pro-MK3 V2.1.3 beta [:arrow_down:](Z9V5Pro_MK3_V2_1_3_beta.zip)
- **Date:** 2021-12-15 
- [**CHG**] Auto HOME when do "Catch Z probe offset" and "Bed auto leveling" on LCD screen

### Z9V5Pro-MK3 V2.1.2 beta [:arrow_down:](Z9V5Pro_MK3_V2_1_2_beta.zip)
- **Date:** 2021-12-13 
- [**BUG**] Initlize the current Extruder to #1 while starting print from SD card.   

### Z9V5Pro-MK3 V2.1.1 beta [:arrow_down:](Z9V5Pro_MK3_V2_1_1_beta.zip)
- **Date:** 2021-12-11 
- [**New**] force to do once HOME while start bed leveling
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)  

### Z9V5Pro-MK3 V2.1.0 beta [:arrow_down:](Z9V5Pro_MK3_V2_1_0_beta.zip)
- **Date:** 2021-12-01 
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION: Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature.**  
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.   **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**  
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display.  
