#### About how to upload firmware, please refer to [:point_right: here](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin#how-to-upload-firmware-to-z9v5pro)

----
## Release Note
### [Z9V5Pro-MK4 V1.2.3 beta :arrow_down:](./Z9V5Pro-MK4_V1_2_3_beta.zip)
- **Date:** 2022-11-28
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](M73_PrusaSlicer.jpg)**

### [Z9V5Pro-MK4 V1.2.2 beta :arrow_down:](./Z9V5ProMK4_V1_2_2.zip)
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.
- [**CHG**] Dynamically adjust the hotend target temperature based on planned E moves.

### [Z9V5Pro-MK4 V1.2.1 beta :arrow_down:](./Z9V5ProMK4_V1_2_1.zip)
- **Date:** 2022-11-15
- [**CHG**] Correct shows temperature of hotend and hotbed

### [Z9V5Pro-MK4 V1.2.0 beta :arrow_down:](./Z9V5ProMK4_V1_2_0.zip)
- **Date:** 2022-11-11
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.

### [Z9V5Pro-MK4 V1.1.1 beta :arrow_down:](./Z9V5ProMK4_V1_1_1.zip)
- **Date:** 2022-10-12
- [**BUG**] Fixed "Home Z Offset" saved issue.

### [Z9V5Pro-MK4 V1.1.0 beta :arrow_down:](./Z9V5ProMK4_V1_1_0.zip)
- **Date:** 2022-09-26
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed some bugs.

### [Z9V5Pro-MK4 V1.0.6 beta :arrow_down:](./Z9V5ProMK4_V1_0_6.zip)
- **Date:** 2022-06-18
- [**BUG**] To solve the misjudgment issue on checking the hot bed when the ambient temperature is low in the automatic test program.
- [**CHG**] Optimize automatic test display.
- [**CHG**] Allow to move extruder motors without heating the nozzle.
- [**CHG**] Allow to move extruder motors while printing is paused.

### [Z9V5Pro-MK4 V1.0.5 beta :arrow_down:](./Z9V5ProMK4_V1_0_5.zip)
- **Date:** 2022-06-11
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.

### [Z9V5Pro-MK4 V1.0.1 beta :arrow_down:](./Z9V5ProMK4_V1_0_1.zip)
- **Date:** 2022-04-09
- [BUG] fix text display issue on printing pause
- [NEW] Auto return printing menu from tune menu without operation within 8 seconds.





