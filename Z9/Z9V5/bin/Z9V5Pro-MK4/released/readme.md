### About how to upload firmware of the 3d printer, please refer to [:point_right: here](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin#how-to-upload-firmware-to-z9v5pro)

-----
## Release Note


### [:arrow_down: Z9V5Pro-MK4 V1.5.1](./Z9V5ProMK4_V1_5_1.zip)
- **Date:** 2023-08-23
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**CHG**] Correct temperature table of nozzle to get more accurate temperature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing.     
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hot end.

### [:arrow_down: Z9V5Pro-MK4 V1.3.2](./Z9V5ProMK4_V1_3_2.zip)
- **Date:** 2023-05-19
- [**NEW**]Add a "probe offset" item in control menu, to set the offset from probe to nozzle.
About hot to set the Home offset and probe offset, please refer to [**here**](https://github.com/ZONESTAR3D/Document-and-User-Guide/tree/master/common/set_offset.md)
- [**NEW**]Add a laser menu, about the detail, please refer to [**here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature)
- [**CHG**]Change the initialize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [**BUG**]Fix a bug on doing "Prepare>>Move>>Extruder All".
- [**BUG**]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### [:arrow_down: Z9V5Pro-MK4 V1.2.4](./Z9V5ProMK4_V1_2_4.zip)
- **Date:** 2022-12-14
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time. **[:point_right: How to set in PrusaSlicer](../beta/M73_PrusaSlicer.jpg)**
- [**CHG**] Correct temperature when the temperature is less than 20 degree
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.
- [**CHG**] Dynamically adjust the hotend target temperature based on planned E moves.

### [:arrow_down: Z9V5Pro-MK4 V1.2](./Z9V5ProMK4_V1_2.zip)
- **Date:** 2022-11-11
- [**NEW**] Add a "HOME OFFSET" menu, support to adjust the X/Y/Z HOME offset on LCD screen.
- [**NEW**] Add a "Auto Unload" menu, turn on it, the printer will unload filament automatically if the printing is abort.    
  --**This feature only work on E4 (4-IN-1-OUT Non-Mix Color) Hotend**.   
- [**NEW**] Display the print elapsed time xxxHxxM after printing finished.
- [**CHG**] Set the home-offset default value to 0
- [**CHG**] Modify print remain time on LCD screen
- [**CHG**] Change "PID auto tune" feature.
- [**CHG**] Delete "HOT end Max temperature" setting menu, but you still need to take care when setting temperature of the mixing color hotend.
- [**BUG**] Fixed the system crashes on gradient and random mixing color printing.
- [**BUG**] Fixed temperature instability issue on over 230 degreeC.
- [**BUG**] Fixed some known bugs.

### [:arrow_down: Z9V5Pro-MK4 V1.0](./Z9V5ProMK4_V1_0.zip)
- **Date:** 2022-04-07
- ***First release***





