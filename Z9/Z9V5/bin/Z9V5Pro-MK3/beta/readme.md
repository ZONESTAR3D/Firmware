#### Firmware Upload Steps 
1. Download the zip file and unzip it.
2. Copy firmware.bin to the root directory of micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the micro-SD card into socket on control board
4. Power on the printer, push and hold the DC power button 3 seconds, the ZONESTAR Logo backlight will flash, wait until it goes out.
5. Push and hold the DC power button 3 seconds , until the LCD screen shows ZONESTAR LOGO.
6. Do the below step on LCD screen to initialize EEPROM: ***MENU>>Control>>Restore Defaults***

### :warning: !ATTENTION PLEASE!
- You must upgrade the DWIN LCD screen menu files before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. 
- About how to upgrade the LCD MENU files of DWIN LCD, please refer to [:point_right: **here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN).
- About the newest MENU description, please refer to  [:point_right: **here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/readme.md).

## Firmware Download Link and Release Note
----
### [:arrow_down: Z9V5ProMK3 V3.6.0 beta ](./Z9V5ProMK3_V3_6_0.zip)
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

### [:arrow_down: Z9V5ProMK3 V3.5.1 beta ](./Z9V5ProMK3_V3_5_1_beta.zip)
- **Date:** 2023-08-23
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**CHG**] Correction temperature     
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**NEW**] Add a "probe offset" item in control menu, to set the offset from probe to nozzle.
About hot to set the Home offset and probe offset, please refer to [**here**](https://github.com/ZONESTAR3D/Document-and-User-Guide/tree/master/common/set_offset.md)
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing.    
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hot end.
#### :warning:Removed some previously released firmware (from V3.3.2 ~ V3.4.1 ) that may have this issue.


### [:arrow_down: Z9V5ProMK3 V3.3.1 beta](./Z9V5ProMK3_V3_3_1_beta.zip)
- **Date:** 2023-04-26
- [**BUG**]Fix a bug on doing "Prepare>>Move>>Extruder All".

### [:arrow_down: Z9V5ProMK3 V3.3.0 beta](./Z9V5ProMK3_V3_3_0_beta.zip)
- **Date:** 2023-04-06
- [**NEW**]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [**CHG**]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [**BUG**]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### [:arrow_down: Z9V5ProMK3 V3.2.4 beta](./Z9V5ProMK3_V3_2_4_beta.zip)
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree

### [Z9V5ProMK3 V3.2.3 beta :arrow_down:](./Z9V5ProMK3_V3_2_3_beta.zip)
- **Date:** 2022-11-28
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**

### [Z9V5ProMK3 V3.2.2 beta :arrow_down:](./Z9V5ProMK3_V3_2_2_beta.zip)
- **Date:** 2022-11-18
- [**CHG**] When the hotend/hotbed heating fail, only showed message but not turn off printer.
- [**CHG**] Dynamically adjust the hotend target temperature based on planned E moves.

### [Z9V5ProMK3 V3.2.1 beta :arrow_down:](./Z9V5ProMK3_V3_2_1_beta.zip)
- **Date:** 2022-11-15
- [**CHG**] Correct shows temperature of hotend and hotbed

### [Z9V5ProMK3 V3.2.0 beta :arrow_down:](./Z9V5ProMK3_V3_2_0_beta.zip)
- **Date:** 2022-11-11
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.

### [Z9V5ProMK3 V3.1.1 beta :arrow_down:](./Z9V5ProMK3_V3_1_1_beta.zip)
- **Date:** 2022-10-12
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "Max Hotend temp" menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some known bugs.

### [Z9V5ProMK3 V3.0.0 beta :arrow_down:](Z9V5ProMK3_V3_0_0_beta.zip)
- **Date:** 2022-07-06
- [**NEW**] Add a "flow rate" tune menu when printing from SD card  

-----
### [Z9V5ProMK3 V2.5.0 beta :arrow_down:](Z9V5ProMK3_V2_5_0_beta.zip)
- **Date:** 2022-07-01
- [**BUG**] Fix issue on disply string.
- [**BUG**] Fix issue when adjust Z offset when auto bed leveling is actived
- [**CHG**] Backlight shows as "Breathing lamp" when auto shutdown is on

### [Z9V5ProMK3 V2.4.9 beta :arrow_down:](Z9V5ProMK3_V2_4_9_beta.zip)
- **Date:** 2022-06-18
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

### [Z9V5ProMK3 V2.4.8 beta :arrow_down:](Z9V5ProMK3_V2_4_8_beta.zip)
- **Date:** 2022-05-13
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight

### [Z9V5ProMK3 V2.4.7 beta :arrow_down:](Z9V5ProMK3_V2_4_7_beta.zip)
- **Date:** 2022-04-25
- [**BUG**] Correct print time (printed time and remain time)

### [Z9V5ProMK3 V2.4.6 beta :arrow_down:](Z9V5ProMK3_V2_4_6_beta.zip)
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.

### [Z9V5ProMK3 V2.4.5 beta :arrow_down:](Z9V5ProMK3_V2_4_5_beta.zip)
- **Date:** 2022-04-20
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected(need to add WiFi module).

### [Z9V5ProMK3 V2.4.3 beta :arrow_down:](Z9V5ProMK3_V2_4_3_beta.zip)
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu.
- [**NEW**] Add "View User Guide" on INFO menu.

### [Z9V5ProMK3 V2.4.2 beta :arrow_down:](Z9V5ProMK3_V2_4_2_beta.zip)
- **Date:** 2022-04-02
- [**BUG**] Extend the waiting time to confirm the WiFi.

### [Z9V5ProMK3 V2.4.1 beta :arrow_down:](Z9V5ProMK3_V2_4_1_beta.zip)
- **Date:** 2022-03-29
- [**CHG**] Add nozzle temperature settings on Prepare>>Filament menu. 

### [Z9V5ProMK3 V2.4.0 beta :arrow_down:](Z9V5ProMK3_V2_4_0_beta.zip)
- **Date:** 2022-03-09
- [**NEW**] Add a "Mixing Feature" to switch on/off mixing feature.
- [**NEW**] Add a "Extr.Sequence" menu to exchange the extrders sequence (only work on Non-mixing hotend).  

------
### [Z9V5ProMK3 V2.3.9 beta :arrow_down:](Z9V5ProMK3_V2_3_9_beta.zip)
- **Date:** 2022-06-20
- [**BUG**] Correct print time (printed time and remain time)
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight

### [Z9V5ProMK3 V2.3.6 beta :arrow_down:](Z9V5ProMK3_V2_3_6_beta.zip)
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Updates News" on info Menu

### [Z9V5ProMK3 V2.3.5 beta :arrow_down:](Z9V5ProMK3_V2_3_5_beta.zip)
- **Date:** 2022-04-20
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected(need to add WiFi module).

### [Z9V5ProMK3 V2.3.4 beta :arrow_down:](Z9V5ProMK3_V2_3_4_beta.zip)
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu.
- [**NEW**] Add "View User Guide" on INFO menu.

### [Z9V5ProMK3 V2.3.3 beta :arrow_down:](Z9V5ProMK3_V2_3_3_beta.zip)
- **Date:** 2022-04-02
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**BUG**] Extend the waiting time to confirm the connection to prevent misjudgment (Connecting fail).

### [Z9V5ProMK3 V2.3.2 beta :arrow_down:](Z9V5ProMK3_V2_3_2_beta.zip)
- **Date:** 2022-03-08
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".

### [Z9V5ProMK3 V2.3.1 beta :arrow_down:](Z9V5ProMK3_V2_3_1_beta.zip)
- **Date:** 2022-02-25
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  

### [Z9V5ProMK3 V2.3.0 beta :arrow_down:](Z9V5ProMK3_V2_3_0_beta.zip)
- **Date:** 2022-01-07
- [**New**]Add "Hotend PID tune" menu.  
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### [Z9V5ProMK3 V2.2.2 beta :arrow_down:](Z9V5ProMK3_V2_2_2_beta.zip)
- **Date:** 2021-12-30
- [**BUG**] Add Base Heigth settings for repeat printing feature. 

### [Z9V5ProMK3 V2.2.1 beta :arrow_down:](Z9V5ProMK3_V2_2_1_beta.zip)
- **Date:** 2021-12-28
- [**New**] Add auto repeat printing feature. 

### [Z9V5ProMK3 V2.1.3 beta :arrow_down:](Z9V5ProMK3_V2_1_3_beta.zip)
- **Date:** 2021-12-15 
- [**CHG**] Auto HOME when do "Catch Z probe offset" and "Bed auto leveling" on LCD screen

### [Z9V5ProMK3 V2.1.2 beta :arrow_down:](Z9V5ProMK3_V2_1_2_beta.zip)
- **Date:** 2021-12-13 
- [**BUG**] Initlize the current Extruder to #1 while starting print from SD card.   

### [Z9V5ProMK3 V2.1.1 beta :arrow_down:](Z9V5ProMK3_V2_1_1_beta.zip)
- **Date:** 2021-12-11 
- [**New**] force to do once HOME while start bed leveling
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)  

### [Z9V5ProMK3 V2.1.0 beta :arrow_down:](Z9V5ProMK3_V2_1_0_beta.zip)
- **Date:** 2021-12-01 
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION: Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature.**  
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.   **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**  
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display.  
