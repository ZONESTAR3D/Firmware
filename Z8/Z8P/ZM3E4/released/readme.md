#### :green_book: Firmware Upload Steps
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***

#### :warning: !ATTETION PLEASE! 
#### About DWIN LCD MENU V2
1. You must to upgrade the DWIN LCD screen firmware before upgrading the printer firmware 2.0 or last version, otherwise it will cause some display issue on LCD MENU. 
2. We will stop to release firmware for "DWIN LCD MENU V1" from 2022-04-20, V1.4.0 will be the last version for "DWIN LCD MENU V1".
3. About how to upgrade firmware of DWIN LCD screen ,please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/tree/main/TFT-LCD/LCD-DWIN#upload-firmware)  
4. About the new LCD screen function description, please refer to [here](https://github.com/ZONESTAR3D/Upgrade-kit-guide/blob/main/TFT-LCD/LCD-DWIN/user_guide/LCD-DWIN%20MENU%20Description%20V2.pdf)  

## Release Note
### Z8PM4Pro V2.1.0 [:arrow_down:Download](./Z8PM4Pro_V2_1_0.zip)
- **Date:** 2022-04-25
- [**BUG**] Correct print and remine time

### Z8PM4Pro V2.0.0 [:arrow_down:Download](./Z8PM4Pro_V2_0_0.zip)
- **Date:** 2022-04-25
- [**NEW**] Upgrade to DWIN LCD MENU V2 [:point_up:](#about-dwin-lcd-menu-v2)
- [**NEW**] Auto return to print menu if doesn't operature on tune menu for a while.
- [**NEW**] Add "View User Guide" on INFO menu.
- [**NEW**] Add "View Update News" on INFO menu.
- [**NEW**] Show a QRcode for visiting the ESP3D website page while WiFi is connected (WiFi module is required).
- [**NEW**] Auto save "baby Z offset adjustment" on the previous printing. 
- [**NEW**] Add "Extr. Sequence" menu to exchange the extruders while hotend type is Non-mixing hotend.
- [**NEW**] Auto disable motors after did "Stop printing".

- [**BUG**] Extend the waiting time to confirm the connection of WiFi.
- [**BUG**] fix the bug of setting max hotend temperature.    

- [**CHG**] Change "Mixing Feature" to "Hotend Type" on "Control>>Configure" menu.
- [**CHG**] Add Nozzle temperature setting on filament menu.
- [**CHG**] Correct HOTEND temperature.
- [**CHG**] Change the menu [HOTEND Temp] to [Nozzle Temp].   
- [**CHG**] Change LCD message while temperature error occured.

### Z8PM4Pro V1.3.0 [:arrow_down:Download](./Z8PM4Pro_V1_3_0.zip)
- **Date:** 2022-03-2
- ***First release***