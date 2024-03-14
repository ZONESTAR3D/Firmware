#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

----
# Release Note
### [ :arrow_down: Z8PM4-MK2A V1.5.1 beta](./Z8PM4MK2A_V1_5_1.zip)
- **Date:** 2024-03-14
- [**CHG**] Optimize BabyStep functionality: 
1. It is prohibited to call out the "Babystep" menu before starting printing.
2. Improve the issue of accidentally exiting the BabyStep menu by repeatedly pressing the knob when starting BabyStep.

### [ :arrow_down: Z8PM4-MK2A V1.5.0 beta](./Z8PM4MK2A_V1_5_0.zip)
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.
