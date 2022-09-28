#### :warning: !ATTETION PLEASE! About 
#### About DWIN LCD MENU V3
- You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 3.0.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN). 

#### About DWIN LCD MENU V2
- You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware to 2.0 or last version, otherwise it will cause some display issue on LCD MENU. For more details, please refer to :point_right: [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN). 
- We will stop releasing firmware for "DWIN LCD MENU V1" after the end of April 2022, V1.4.x will be the last version for "DWIN LCD MENU V1", we recommend that you upgrade the firmware of the 4.3" DWIN LCD screen as soon as possible. 
- About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
- About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/)  

#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

## Release Note
----
### DWIN LCD MENU V3 [:point_up:](#about-dwin-lcd-menu-v3)
### Z9V5Pro V3.1.0 beta [:arrow_down:](./Z9V5Pro_V3_1_0_beta.zip)
- **Date:** 2022-09-26
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some bugs.

### Z9V5Pro V3.0.0 beta [:arrow_down:](Z9V5Pro_V3_0_0_beta.zip)
- **Date:** 2022-07-06
- [**NEW**] Add a "flow rate" tune menu when priinting from SD card  
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight
- [**BUG**] Fix issue on disply string.
- [**BUG**] Fix issue when adjust Z offset when auto bed leveling is actived
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

----
DWIN LCD MENU V2 [:point_up:](#about-dwin-lcd-menu-v2)
### Z9V5Pro V2.1.0 beta [:arrow_down:](./Z9V5Pro_V2_1_0_beta.zip)
- **Date:** 2022-09-26
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**NEW**] Add a menu to adjust the brightness of LOGO backlight
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**BUG**] Fixed some bugs.
- [**BUG**] Fix issue on disply string.
- [**BUG**] Fix issue when adjust Z offset when auto bed leveling is actived
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.

### Z9V5Pro V2.0.2 beta [:arrow_down:](Z9V5Pro_V2_0_2_beta.zip)
- **Date:** 2022-04-25
- [**BUG**] Fix bug on print time shows.

### Z9V5Pro V2.0.1 beta
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**BUG**] Fix bug on print time.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.

----
DWIN LCD MENU V1

### Z9V5Pro V1.4.2 beta [:arrow_down:](Z9V5Pro_V1_4_2_Beta.zip)
- **Date:** 2022-04-25
- [**BUG**] Fix bug on print time shows.

### Z9V5Pro V1.4.1 beta [:arrow_down:](./Z9V5Pro_V1_4_1_Beta.zip)
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.

### Z9V5Pro V1.4.0 beta [:arrow_down:](./Z9V5Pro_V1_4_0_Beta.zip)
- **Date:** 2022-04-15
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected (WiFi module is required).

### Z9V5Pro V1.3.9 beta [:arrow_down:](./Z9V5Pro_V1_3_9_Beta.zip)
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu for a while.
- [**NEW**] Add "View User Guide" on INFO menu.

### Z9V5Pro V1.3.8 beta [:arrow_down:](./Z9V5Pro_V1_3_8_Beta.zip)
- **Date:** 2022-04-01
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**BUG**] Extend the waiting time to confirm the connection of WiFi.

### Z9V5Pro V1.3.7 beta [:arrow_down:](./Z9V5Pro_V1_3_7_Beta.zip)
- **Date:** 2022-03-08
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".

### Z9V5Pro V1.3.6 beta [:arrow_down:](./Z9V5Pro_V1_3_6_Beta.zip)
- **Date:** 2022-02-23
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  
 
### Z9V5Pro V1.3.5 beta [:arrow_down:](./Z9V5Pro_V1_3_5_Beta.zip)
- **Date:** 2022-01-07
- [**New**] Add PID Tune menu 
- [**CHG**] Change a little menu display 

### Z9V5Pro V1.3.1 beta [:arrow_down:](./Z9V5Pro_V1_3_1_Beta.zip)
- **Date:** 2021-12-03
- [**New**] force to do once HOME while start bed leveling 

### Z9V5Pro V1.3.0 beta [:arrow_down:](./Z9V5Pro_V1_3_0_Beta.zip)
- **Date:** 2021-12-01
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION:Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature**.    
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.  **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**   
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display    

### Z9V5Pro V1.2.8 beta [:arrow_down:](./Z9V5Pro_V1_2_8_beta.zip)
- **Date:** 2021-11-22
- [**BUG**] Updata the hotend temperature measure table to correct bed temperature display  

### Z9V5Pro V1.2.7 beta [:arrow_down:](./Z9V5Pro_V1_2_7_beta.zip)
- **Date:** 2021-11-03  
- [**BUG**] fix the issue on auto testing  
***Auto testing feature: move the cursor to the "Info>>Data:xx-xx-xx" and click the knob 5 time to start an auto testing process***      

### Z9V5Pro V1.2.5 beta [:arrow_down:](./Z9V5Pro_V1_2_5_beta.zip)
- **Date:** 2021-07-15   
- [**BUG**] fix the issue on power loss recovery  
- [**NEW**]Add feedback on menu scroll
- [**CHG**]Improbe menu operature (auto return to the last item)
- [**CHG**]Change leveling table to 5x5 grid and improve the accuracy of automatic leveling
- [**BUG**]fix the display issue when G29 command in the gcode file
- [**BUG**]fix the issue on filament run out when mixing printing 
- [**BUG**]fix several known bugs

### Z9V5Pro V1.2.4 beta 
- **Date:** 2021-07-14
- [**NEW**]Add feedback on menu scroll  
- [**BUG**]fix the disply issue when G29 command in the gcode file  
- [**BUG**]fix the issue on filament run out when mixing printing   
- [**CHG**]Improbe menu operature (auto return to the last item)  

### Z9V5Pro V1.2.0 beta
- **Date:** 2021-07-07
- [**NEW**] Add filament Load/Unload menu, please refer to "user guide\LCD-DWIN MENU Description V1_2.pdf"
- [**NEW**] Add WiFi BaudRate setting menu, please refer to "user guide\How to Change WiFi BaudRate.pdf"  

### Z9V5Pro V1.1.2 beta
- **Date:** 2021-6-26 
- [**BUG**] fix the bug on powerloss recovery and pause print

### Z9V5Pro V1.1.1 beta
- **Date:** 2021-6-24  
- [**CHG**] Set the highest temperature of hotend to 260 degree

### Z9V5Pro V1.1.0 beta
- **Date:** 2021-6-19
- [**CHG**] Optimize the menu arrangement and display effect.
- [**CHG**] Fix the confirmation logic of WiFi module.
- [**CHG**] Optimize automatic leveling function:
  - Add probe offset setting (usually, if the catch offset effect is not good and the height of the nozzle is not suitable when printing the first layer after auto leveling, you need to adjust babystepz. You can add babystep value to probezofaffset and do auto leveling again).
  - Add Probing heigh table display for automatic leveling.
  - For more description of the auto leveling function, please refer to the directory "bed auto leveling"
- [**CHG**]Change the text of the menu item "bed coasting" to "home Z offset"
- [**BUG**] Fixed several known bugs  

### Z9V5Pro V1.0.8 beta
- **Date:** 2021-5-15   
- [**CHG**] Save WiFi On Off  
- [**CHG**] Remove unactived menu option of config when printing from SD card  

### Z9V5Pro V1.0.7 beta
- **Date:** 2021-4-18   
- [**CHG**] Improve the auto leveling feature for glass bed
Following the below steps to do:  
  - Adjust the Z axis adjust screws (left and right) to the bottom as far as possible
  - Do Level corners(Menu>>Prepare>>Bed Levling), let the 4 corners on the same heigth as far as possible
  - Copy level_test_310.gcode file to SD card and print it, if the bed is enough leveling, do need to enable bed auto leveling feature.
  - Turn on the auto leveling feature(MENU>>Config>>configure>>Auto Leveling: ON)
  - Remove the glass
  - Do Menu>>Prepare>>Bed Levling>>Catch Z-offset
  - Do Menu>>Prepare>>Bed Levling>>AutoLevling
  - Print "level_test_310.gcode" file again to check.  
***NOTE: if you find the nozzle is too Heigth/Low when printing the first layer, Redunce/Add the coating thickness value on menu (Config>>configure>>Coating Thickness)***   

### Z9V5Pro V1.0.6 beta
- **Date:** 2021-3-18   
- [**NEW**] Add WIFI function

### Z9V5Pro V1.0.5 beta
- **Date:** 2021-3-9   
- [**CHG**] Modifying bed leveling display；
- [**BUG**] Fix several known bugs

### Z9V5Pro V1.0.4 beta
- **Date:** 2021-2-25   
- [**CHG**] Modify the bug of manual extrusion of extruder in the move menu;
- [**CHG**] Modify the display of several menu names;

### Z9V5Pro V1.0.3 beta
- **Date:** 2021-2-4   
- [**NEW**] Add the function of all extruders moving at the same time in the move menu;
- [**BUG**] fixed some other known bugs;

### Z9V5Pro V1.0.1 beta
- **Date:** 2021-1-26
- [**CHG**] Dwin screen refreshes the display after receiving m166 m167 instruction;
- [**CHG**] Automatic retraction speed modification;
- [**BUG**] fixed some other known bugs;