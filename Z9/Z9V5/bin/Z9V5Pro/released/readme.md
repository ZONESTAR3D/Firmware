#### DWIN LCD MENU
:warning: !ATTETION PLEASE!    
1. You must upgrade the DWIN LCD screen firmware before upgrading the printer firmware V2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. About how to upgrade firmware of DWIN LCD screen ,please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
3. About the new LCD screen function description, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#user-guide)  

----
#### About how to upload firmware, please refer to [:point_right: here](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin#how-to-upload-firmware-to-z9v5pro)

## Release Note
----
## Firmware V3.x.x
:warning: **If you upgraded the control board firmware to V3.0.0 or last version, You need to upgrade the DWIN LCD screen firmware too, about details, please refer to [:point_up: here](#dwin-lcd-menu)**

### [Z9V5Pro V3.2.1 :arrow_down:](./Z9V5Pro_V3_2_1.zip)
- **Date:** 2022-11-15   
- [**NEW**] Upgrade to DWIN LCD MENU V3
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Add a "Viwe Update News" on info Menu.
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**NEW**] Add a "Flow rate" tune menu.
- [**NEW**] Add a "Backlight" menu to adjust the brightness of LOGO backlight.
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**CHG**] Modify print remain time on LCD screen
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fix bug on print time.
- [**BUG**] Fixed some other known bugs.

----
## Firmware V2.x.x
:warning: **If you upgraded the control board firmware to V2.0.0 or last version, You need to upgrade the DWIN LCD screen firmware too, about details, please refer to [:point_up: here](#dwin-lcd-menu)**

### [Z9V5Pro V2.0.0 :arrow_down:](./Z9V5Pro_V2_0_0.zip)
- **Date:** 2022-04-20
- [**NEW**] Upgrade to DWIN LCD MENU V2

----
## Firmware V1.x.x

### [Z9V5Pro V1.4.0 :arrow_down:](./Z9V5Pro_V1_4_0.zip)
- **Date:** 2022-04-20
- [**NEW**] Auto return to print menu if doesn't operature on tune menu for a while.
- [**NEW**] Add "View User Guide" on INFO menu.
- [**NEW**] Add "View Update News" on INFO menu.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected (WiFi module is required).
- [**CHG**] Change "Mixing Feature" to "Hotend Type" on "Control>>Configure" menu.
- [**NEW**] Add "Extr. Sequence" menu to exchange the extruders while hotend type is Non-mixing hotend.

### [Z9V5Pro V1.3.8 :arrow_down:](./Z9V5Pro_V1_3_8.zip)
- **Date:** 2022-04-01
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**BUG**] Extend the waiting time to confirm the connection of WiFi.
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.

### [Z9V5Pro V1.3.5 :arrow_down:](./Z9V5Pro_V1_3_5.zip)
- **Date:** 2022-01-07
- [**New**]Add "Hotend PID tune" menu. Details of PID, please refer to [**here**](https://marlinfw.org/docs/configuration/configuration.html#pid).
- [**CHG**]Optimize the setting of motion to improve the printing quality.  
- [**CHG**]Optimize menu display characters.
- [**CHG**]Optimize automatic test display and process.

### [Z9V5Pro V1.3.2 :arrow_down:](./Z9V5Pro_V1_3_2.zip)
- **Date:** 2021-12-11
- [**New**] force to do once HOME while start bed leveling 
- [**CHG**] Change MAX_AUTORETRACT to 20 (from 10 ). to solve the issue that the automatic extraction does not work while slicing set the "retraction length is bigger than 10 mm". About the setting of MAX_AUTORETRACT, please refer to  [**here**](https://marlinfw.org/docs/configuration/configuration.html#firmware-retraction)      

### [Z9V5Pro V1.3.0 :arrow_down:](./Z9V5Pro_V1_3_0.zip)
- **Date:** 2021-12-01
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION:Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature**.    
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.  **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**   
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display.

### [Z9V5Pro V1.2.7 :arrow_down:](./Z9V5Pro_V1_2_7.zip)
- **Date:** 2021-11-19 
- [**BUG**] fix the issue on auto testing  
***Auto testing feature: move the cursor to the "Info>>Data:xx-xx-xx" and click the knob 5 time to start an auto testing process***      

### [Z9V5Pro V1.2.6 :arrow_down:](./Z9V5Pro_V1_2_6.zip)
- **Date:** 2021-07-15  
- [**BUG**] fix the issue on filament run out

### [Z9V5Pro V1.2.5 :arrow_down:](./Z9V5Pro_V1_2_5.zip)
- **Date:** 2021-07-15   
- [**BUG**] fix the issue on power loss recovery  
- [**NEW**]Add feedback on menu scroll
- [**CHG**]Improbe menu operature (auto return to the last item)
- [**CHG**]Change leveling table to 5x5 grid and improve the accuracy of automatic leveling
- [**BUG**]fix the display issue when G29 command in the gcode file
- [**BUG**]fix the issue on filament run out when mixing printing 
- [**BUG**]fix several known bugs

### [Z9V5Pro V1.2.4 :arrow_down:](./Z9V5Pro_V1_2_4.zip)
- **Date:** 2021-07-14
- [**NEW**]Add feedback on menu scroll  
- [**BUG**]fix the disply issue when G29 command in the gcode file  
- [**BUG**]fix the issue on filament run out when mixing printing   
- [**CHG**]Improbe menu operature (auto return to the last item)  

### [Z9V5Pro V1.2.0 :arrow_down:](./Z9V5Pro_V1_2_0.zip)
- **Date:** 2021-07-07
- [**NEW**] Add filament Load/Unload menu, please refer to "user guide\LCD-DWIN MENU Description V1_2.pdf"
- [**NEW**] Add WiFi BaudRate setting menu, please refer to "user guide\How to Change WiFi BaudRate.pdf"  

### [Z9V5Pro V1.1.2 :arrow_down:](./Z9V5Pro_V1_1_2.zip)
- **Date:** 2021-6-26 
- [**BUG**] fix the bug on powerloss recovery and pause print

### [Z9V5Pro V1.1.1 :arrow_down:](./Z9V5Pro_V1_1_1.zip)
- **Date:** 2021-6-24  
- [**CHG**] Set the highest temperature of hotend to 260 degree

### [Z9V5Pro V1.1.0 :arrow_down:](./Z9V5Pro_V1_1_0.zip)
- **Date:** 2021-6-19
- [**CHG**] Optimize the menu arrangement and display effect.
- [**CHG**] Fix the confirmation logic of WiFi module.
- [**CHG**] Optimize automatic leveling function:
  - Add probe offset setting (usually, if the catch offset effect is not good and the height of the nozzle is not suitable when printing the first layer after auto leveling, you need to adjust babystepz. You can add babystep value to probezofaffset and do auto leveling again).
  - Add Probing heigh table display for automatic leveling.
  - For more description of the auto leveling function, please refer to the directory "bed auto leveling"
- [**CHG**]Change the text of the menu item "bed coasting" to "home Z offset"
- [**BUG**] Fixed several known bugs  

### [Z9V5Pro V1.0.8 :arrow_down:](./Z9V5Pro_V1_0_8.zip)
- **Date:** 2021-5-15   
- [**CHG**] Save WiFi On Off  
- [**CHG**] Remove unactived menu option of config when printing from SD card  

### [Z9V5Pro V1.0.7 :arrow_down:](./Z9V5Pro_V1_0_7.zip)
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


### [Z9V5Pro V1.0.6 :arrow_down:](./Z9V5Pro_V1_0_6.zip)
- **Date:** 2021-3-18   
- [**NEW**] Add WIFI function

### [Z9V5Pro V1.0.5 :arrow_down:](./Z9V5Pro_V1_0_5.zip)
- **Date:** 2021-3-9   
- [**CHG**] Modifying bed leveling display；
- [**BUG**] Fix several known bugs

### [Z9V5Pro V1.0.4 :arrow_down:](./Z9V5Pro_V1_0_4.zip)
- **Date:** 2021-2-25   
- [**CHG**] Modify the bug of manual extrusion of extruder in the move menu;
- [**CHG**] Modify the display of several menu names;

### [Z9V5Pro V1.0.3 :arrow_down:](./Z9V5Pro_V1_0_3.zip)
- **Date:** 2021-2-4   
- [**NEW**] Add the function of all extruders moving at the same time in the move menu;
- [**BUG**] fixed some other known bugs;

### [Z9V5Pro V1.0.1 :arrow_down:](./Z9V5Pro_V1_0_1.zip)
- **Date:** 2021-1-26
- [**CHG**] Dwin screen refreshes the display after receiving m166 m167 instruction;
- [**CHG**] Automatic retraction speed modification;
- [**BUG**] fixed some other known bugs;

### [Z9V5Pro V1.0.0 :arrow_down:](./Z9V5Pro_V1_0_0.zip)
- **Date:** 2021-1-15
- ***First release***
