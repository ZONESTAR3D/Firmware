
#### :warning: ATTENTION PLEASE :warning:
1. You must upgrade the LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. The firmware of LCD screen is downward compatible, please upgrade to the latest version.
3. About how to upgrade firmware of LCD screen, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
4. About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN/user_guide)  

----
# Release Note
### V3.5.0
- **Date:** 2024-01-06
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

### V3.4.1
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values

### V3.4.0
- **Date:** 2023-09-09
- [**CHG**] Build on new PlatformIO core 6.0.
- [**CHG**] Optimize Configure menu.
- [**CHG**] Optimize Mixer Menu.
- [**NEW**] Enable the function of separately adjusting parameters such as steps/mm for each extruder    
- [**CHG**] Improved processing logic for high and low temperature error alarms.
- [**CHG**] Increase the knob running speed for selecting menu options on the main menu.
- [**CHG**] Correct steps/mm of extruders.
- [**BUG**] Fix some known bugs on power loss recovery feature.
- [**BUG**] Fix the issue where the machine crashes when starting the gradient mixing during printing. 

### V3.3.1
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".

### V3.3.0
- **Date:** 2023-04-06
- [NEW]Add a laser menu, about the detail.
- [CHG]Change the initial mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing

### V3.2.4
- **Date:** 2022-12-14
- [**CHG**] Correct temperature when the temperature is less than 20 degree

### V3.2.3
- **Date:** 2022-12-03
- [**NEW**] Add to support M73 gcode command to obtain more accurate printing progress percent and printing remaining time.

### Z8PM4Pro V3.2.2
- **Date:** 2022-11-18
- [**CHG**] Don't turn off power if the hotend/hotbed can't heat to the setting temperature.

### V3.0.0
- [**NEW**] Upgrade the LCD MENU.
- [**NEW**] Add a FlowRate Menu in "Print>>Tune" menu
