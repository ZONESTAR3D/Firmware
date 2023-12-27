### About how to upload firmware of the 3d printer, please refer to [:point_right: here](https://github.com/ZONESTAR3D/Firmware/tree/master/Z9/Z9V5/bin#how-to-upload-firmware-to-z9v5pro)

----
## Release Note
### [:arrow_down: Z9V5Pro-MK5 V1.3.0](./Z9V5ProMK5_V1_3_0.zip)
- **Date:** 2023-12-25
- [**CHG**] Support to access the SD card files from USB.      
  :pushpin: Hint:      
  - Plug the SD card before power on.
  - Do not access the SD card during printing.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.
  - If the SD card cannot be found when inserting USB, please restart the 3D printer and unplug the USB cable to try again.

### [:arrow_down: Z9V5Pro-MK5 V1.2.4](./Z9V5ProMK5_V1_2_4.zip)
- **Date:** 2023-08-23
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**CHG**] Add debounce for measuring hotend and hotbed temperature.   
- [**CHG**] Correction temperature     
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing.     
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hot end.
#### :warning:Removed some previously released firmware that may have this issue.

### [:arrow_down: Z9V5Pro-MK5 V1.0.1](./Z9V5ProMK5_V1_0_1.zip)
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".
