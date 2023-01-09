#### About how to upload firmware, please refer to [:point_right: here](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin#how-to-upload-firmware-to-z9v5pro)

#### About DWIN LCD MENU V3
You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN)

## Release Note
-----
### Z9V5Pro-MK3 V3.2.4 [:arrow_down:](./Z9V5Pro-MK3_V3_2_4.zip)
- **Date:** 2022-12-14
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](../beta/M73_PrusaSlicer.jpg)**
- [**CHG**] Correct temperature when the temperature is less than 20 degree.
- [**CHG**] When the hotend/hotbed heating fail, only showed message but not turn off printer.

### Z9V5Pro-MK3 V3.2.1 [:arrow_down:](./Z9V5Pro-MK3_V3_2_1.zip)
- **Date:** 2022-11-15
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "Max Hotend temp" menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.[:bulb:Tips](#1)
- [**BUG**] Fixed some known bugs.


### Z9V5Pro-MK3 V3.0.0 [:arrow_down:](Z9V5Pro-MK3_V3_0_0.zip)
- **Date:** 2022-07-06    
:warning: **NOTE** it need upgrade to [:point_up: **DWIN LCD MENU V3**](#about-dwin-lcd-menu-v3)
- [**NEW**] Add a "flow rate" tune menu when priinting from SD card  
- [**NEW**] Add a "Viwe Update News" on info Menu.
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight
:warning: **NOTE** WiFi is an optional feature [About WiFi Module](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/WiFi)
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected(need to add WiFi module).
- [**NEW**] Auto return to print menu if doesn't operature on tune menu.
- [**NEW**] Add "View User Guide" on INFO menu.
- [**CHG**] Backlight shows as "Breathing lamp" when auto shutdown is on
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**BUG**] Fix issue when adjust Z offset when auto bed leveling is actived
- [**BUG**] Fix issue on disply string.
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**BUG**] Fix the issue can't find the SD card.
- [**BUG**] Correct print time (printed time and remain time)
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.

-----
### Z9V5Pro-MK3 V2.7.0 [:arrow_down:](Z9V5Pro-MK3_V2_7_0.zip)
- **Date:** 2022-12-14
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](../beta/M73_PrusaSlicer.jpg)**
- [**CHG**] Correct temperature when the temperature is less than 20 degree.
- [**CHG**] When the hotend/hotbed heating fail, only showed message but not turn off printer.
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "Max Hotend temp" menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.
- [**BUG**] Fixed some known bugs.


### Z9V5Pro-MK3 V2.6.0 [:arrow_down:](Z9V5Pro-MK3_V2_6_0.zip)
- **Date:** 2022-10-17
- [**NEW**] Add a "Viwe Update News" on info Menu.
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Delete "Max Hotend temp" menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**CHG**] Backlight shows as "Breathing lamp" when auto shutdown is on.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**BUG**] Fixed some known bugs.

### Z9V5Pro-MK3 V2.3.3 [:arrow_down:](Z9V5Pro_MK3_V2_3_3.zip)
- **Date:** 2022-04-02
- [**BUG**] fix the bug of setting max hotend temperature.
- [**BUG**] Extend the waiting time to confirm the connection to prevent misjudgment (Connecting fail).
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].
- [**CHG**] Change LCD message while temperature error occured.   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".

### Z9V5Pro-MK3 V2.3 [:arrow_down:](Z9V5Pro_MK3_V2_3.zip)
- **Date:** 2022-01-07
- [**New**]Add "Hotend PID tune" menu.  
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### Z9V5Pro-MK3 V2.2 [:arrow_down:](Z9V5Pro_MK3_V2_2.zip)
- **Date:** 2021-12-15 
- [**CHG**] Auto HOME first while do "Catch Z probe offset" and "Bed auto leveling" on LCD screen
- [**BUG**] Initlize the current Extruder to #1 while starting print from SD card.   
- [**New**] force to do once HOME while start bed leveling
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)  

### Z9V5Pro-MK3 V2.1 [:arrow_down:](Z9V5Pro_MK3_V2_1.zip)
- **Date:** 2021-12-01 
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION: Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature.**  
- [**NEW**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.   **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**  
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display  

### Z9V5Pro-MK3 V2.0 [:arrow_down:](Z9V5Pro_MK3_V2_0.zip)
- **Date:** 2021-10-26 
- ***First release***
