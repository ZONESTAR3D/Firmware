## Firmware Release Note
### V1.6.2
- **Date:** 2024-03-14
- [**CHG**] Optimize BabyStep functionality: 
1. It is prohibited to call out the "Babystep" menu before starting printing.
2. Improve the issue of accidentally exiting the BabyStep menu by repeatedly pressing the knob when starting BabyStep.

### V1.6.0 
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

### V1.5.4
- **Date:** 2023-11-30
- [**CHG**] Improved the issue of sudden jumps when adjusting values on LCD screen.

### V1.5.1
- **Date:** 2023-08-23
- [**NEW**]Add a "probe offset" item in control menu, to set the offset from probe to nozzle.
About hot to set the Home offset and probe offset, please refer to [**:point_right:here**](https://github.com/ZONESTAR3D/Document-and-User-Guide/tree/master/common/set_offset.md).    
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**CHG**] Correct temperature table of nozzle to get more accurate temperature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing.     
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hot end.
#### :warning:Removed some previously released firmware that may have this issue.

###  V1.3.1
- **Date:** 2023-04-26
- [**BUG**]Fix a bug on doing "Prepare>>Move>>Extruder All".

### V1.3.0
- **Date:** 2023-04-06
- [**NEW**]Add a laser menu, about the detail, please refer to [**:point_right:here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature).
- [**CHG**]Change the initialize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [**BUG**]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### V1.2.4
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree

### V1.2.3
- **Date:** 2022-11-28
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**

### V1.2.2
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.
- [**CHG**] Dynamically adjust the hotend target temperature based on planned E moves.

### V1.2.1
- **Date:** 2022-11-15
- [**CHG**] Correct shows temperature of hotend and hotbed

### V1.2.0
- **Date:** 2022-11-11
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.

### V1.1.1
- **Date:** 2022-10-12
- [**BUG**] Fixed "Home Z Offset" saved issue.

### V1.1.0
- **Date:** 2022-09-26
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some bugs.

### V1.0.6
- **Date:** 2022-06-18
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

### V1.0.5
- **Date:** 2022-06-11
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.

### V1.0.1
- **Date:** 2022-04-09
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.
