# Release Note
### V1.5.0 
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

### V1.4.3 
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values on LCD screen.

### V1.4.2
- **Date:** 2023-08-23
- [**CHG**] Remove the independent E-step setting since it is not very compatible with the color mixing feature. 

### V1.4.1 
- **Date:** 2023-08-22
- [**BUG**] Solve the problem of some machines mistakenly displaying the maximum temperature or even crashing / auto shutting down during printing due to temperature flipping of the hotbed and hotend.

### V1.2.1 
- **Date:** 2023-04-26
- [BUG]Fix a bug on doing "Prepare>>Move>>Extruder All".

### V1.2.0 
- **Date:** 2023-04-06
- [NEW]Add a laser menu, about the detail, please refer to [**:point_right:here**](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/Laser_Engraving#two-turn-on-the-laser-engine-feature).
- [CHG]Change the initlize mix rate table (suit for Whit+Cyan+Magenta+Yellow)
- [BUG]Fix a bug, it will cause the printer auto shutdown when doing auto mixing
