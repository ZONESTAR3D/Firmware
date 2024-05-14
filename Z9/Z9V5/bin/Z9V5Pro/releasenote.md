## Release Note
### V3.5.1
- **Date:** 2023-08-27
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**CHG**] Add debounce for measuring hotend and hotbed temperature.   
- [**CHG**] Correction temperature.     
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing.   
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hot end. **:warning:Removed V3.4.0 & V3.5.0 that may have this issue.**
### V3.3.1
- **Date:** 2023-04-26
- [**BUG**]Fix a bug on doing "Prepare>>Move>>Extruder All".
### V3.3.0
- **Date:** 2023-04-06
- [**NEW**]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [**CHG**]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [**BUG**]Fix a bug, it will cause the printer auto shutdown when doing auto mixing
### V3.2.5
- **Date:** 2023-03-31
- [**NEW**] Add a "laser" item in "confire" menu, Turn it on when you use the laser engraving function.      
- [**NEW**] Add a "troubleshooting" item in "infor" menu, click it to pop up a QRcord of troubleshooting link.     
**About laser item**    
For ZM3E4 control board, laser engraving PWM and the extruder fan PWM  of the 3D printer used the same pin of MCU. When it be used as a extruder fan PWM of the 3D printing function, at the instant the fan is turned on, the PWM pin should output a short time high level (it is 500ms in the firmware) to help the fan to rotate successfully. However, this is not good at the engraving resolution. After adding this menu, the user can turn the "laser" on on LCD MENU when using laser engraving, so the machine don't out put a short time high level while the PWM output.
### V3.2.4
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree
### V3.2.3
- **Date:** 2022-11-28
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**
    <!-- - **[:point_right: How to set in Cura]()** -->
### V3.2.2
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.
- [**CHG**] Dynamically adjust the hotend target temperature based on planned E moves.
### V3.2.1
- **Date:** 2022-11-15
- [**CHG**] Correct shows temperature of hotend and hotbed
### V3.2.0
- **Date:** 2022-11-11
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.
### V3.1.1
- **Date:** 2022-10-12
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some bugs.
### V3.0.0
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
### V2.1.0
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
### V2.0.2
- **Date:** 2022-04-25
- [**BUG**] Fix bug on print time shows.
### V2.0.1
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**BUG**] Fix bug on print time.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.

----
### V1.4.2
- **Date:** 2022-04-25
- [**BUG**] Fix bug on print time shows.
### V1.4.1
- **Date:** 2022-04-22
- [**BUG**] Fix bug on hotend max temp setting.
- [**BUG**] Fix bug on display on hotend high temperature.
- [**NEW**] Turn off WiFi settings if WiFi connection is fail.
- [**NEW**] Add a "Viwe Update News" on info Menu.
### V1.4.0
- **Date:** 2022-04-15
- [**BUG**] Fix the issue can't find the SD card.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected (WiFi module is required).
### V1.3.9
- **Date:** 2022-04-14
- [**NEW**] Auto return to print menu if doesn't operature on tune menu for a while.
- [**NEW**] Add "View User Guide" on INFO menu.
### V1.3.8
- **Date:** 2022-04-01
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**BUG**] Extend the waiting time to confirm the connection of WiFi.
### V1.3.7
- **Date:** 2022-03-08
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Auto disable motors after did "Stop printing".
### V1.3.6
- **Date:** 2022-02-23
- [**BUG**] fix the bug of setting max hotend temperature.  
- [**CHG**] Change LCD message while temperature error occured.  
### V1.3.5
- **Date:** 2022-01-07
- [**New**] Add PID Tune menu 
- [**CHG**] Change a little menu display 
### V1.3.1
- **Date:** 2021-12-03
- [**New**] force to do once HOME while start bed leveling 
### V1.3.0
- **Date:** 2021-12-01
- [**New**] Add a "***Control>>configre>>Max HOTEND Temp***" menu, so that you can upgrade to high temperature hotend. **ATTETION:Overheating may damaged the hotend, ensure your hotend can work in that temperature before set the temperature**.    
- [**New**] Add a "***Control>>configre>>PID AutoTune***" menu to auto tune the PID parameter.  **NOTE: While do PID autotune, please wait until the LCD show PID Auto tune finished!**   
- [**CHG**] Correct the temperature table of hotend and hotbed to get more accurate temperature display    
### V1.2.8
- **Date:** 2021-11-22
- [**BUG**] Updata the hotend temperature measure table to correct bed temperature display  
### V1.2.7
- **Date:** 2021-11-03  
- [**BUG**] fix the issue on auto testing  
***Auto testing feature: move the cursor to the "Info>>Data:xx-xx-xx" and click the knob 5 time to start an auto testing process***      
### V1.2.5
- **Date:** 2021-07-15   
- [**BUG**] fix the issue on power loss recovery  
- [**NEW**]Add feedback on menu scroll
- [**CHG**]Improbe menu operature (auto return to the last item)
- [**CHG**]Change leveling table to 5x5 grid and improve the accuracy of automatic leveling
- [**BUG**]fix the display issue when G29 command in the gcode file
- [**BUG**]fix the issue on filament run out when mixing printing 
- [**BUG**]fix several known bugs
### V1.2.4
- **Date:** 2021-07-14
- [**NEW**]Add feedback on menu scroll  
- [**BUG**]fix the disply issue when G29 command in the gcode file  
- [**BUG**]fix the issue on filament run out when mixing printing   
- [**CHG**]Improbe menu operature (auto return to the last item)  
### V1.2.0
- **Date:** 2021-07-07
- [**NEW**] Add filament Load/Unload menu, please refer to "user guide\LCD-DWIN MENU Description V1_2.pdf"
- [**NEW**] Add WiFi BaudRate setting menu, please refer to "user guide\How to Change WiFi BaudRate.pdf"  
### V1.1.2
- **Date:** 2021-6-26 
- [**BUG**] fix the bug on powerloss recovery and pause print
### V1.1.1
- **Date:** 2021-6-24  
- [**CHG**] Set the highest temperature of hotend to 260 degree
### V1.1.0
- **Date:** 2021-6-19
- [**CHG**] Optimize the menu arrangement and display effect.
- [**CHG**] Fix the confirmation logic of WiFi module.
- [**CHG**] Optimize automatic leveling function:
  - Add probe offset setting (usually, if the catch offset effect is not good and the height of the nozzle is not suitable when printing the first layer after auto leveling, you need to adjust babystepz. You can add babystep value to probezofaffset and do auto leveling again).
  - Add Probing heigh table display for automatic leveling.
  - For more description of the auto leveling function, please refer to the directory "bed auto leveling"
- [**CHG**]Change the text of the menu item "bed coasting" to "home Z offset"
- [**BUG**] Fixed several known bugs  
### V1.0.8
- **Date:** 2021-5-15   
- [**CHG**] Save WiFi On Off  
- [**CHG**] Remove unactived menu option of config when printing from SD card  
### V1.0.7
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
### V1.0.6
- **Date:** 2021-3-18   
- [**NEW**] Add WIFI function
### V1.0.5
- **Date:** 2021-3-9   
- [**CHG**] Modifying bed leveling display；
- [**BUG**] Fix several known bugs
### V1.0.4
- **Date:** 2021-2-25   
- [**CHG**] Modify the bug of manual extrusion of extruder in the move menu;
- [**CHG**] Modify the display of several menu names;
### V1.0.3
- **Date:** 2021-2-4   
- [**NEW**] Add the function of all extruders moving at the same time in the move menu;
- [**BUG**] fixed some other known bugs;
### V1.0.1
- **Date:** 2021-1-26
- [**CHG**] Dwin screen refreshes the display after receiving m166 m167 instruction;
- [**CHG**] Automatic retraction speed modification;
- [**BUG**] fixed some other known bugs;