#### Firmware Upload Steps 
1. Download the zip file and unzip it.
2. Copy firmware.bin to the root directory of micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the micro-SD card into socket on control board
4. Power on the printer, push and hold the DC power button 3 seconds, the ZONESTAR Logo backlight will flash, wait until it goes out.
5. Push and hold the DC power button 3 seconds , until the LCD screen shows ZONESTAR LOGO.
6. Do the below step on LCD screen to initialize EEPROM: ***MENU>>Control>>Restore Defaults***

----
## Firmware Download Link and Release Note
### [:arrow_down: Z9V5Pro-MK5 V1.3.0](./Z9V5ProMK5_V1_3_0.zip)
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.      
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

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
