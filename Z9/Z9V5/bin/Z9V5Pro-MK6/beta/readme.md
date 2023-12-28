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
### [:arrow_down: Z9V5Pro-MK6 V1.1.1](./Z9V5ProMK6_V1_1_1.zip)
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.      
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.

### [:arrow_down: Z9V5Pro-MK6 V1.0.2](./Z9V5ProMK6_V1_0_2.zip)
- **Date:** 2023-11-29
- [**CHG**] Improved the issue of sudden jumps when adjusting values on LCD screen.
