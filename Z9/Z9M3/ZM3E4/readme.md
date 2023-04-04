## [:file_folder: Firmware](./firmware/)
Included firmware bin files of Z9M3 upgraded to ZM3E4 control board 
### [![](../../LCD12864.jpg)](./firmware/LCD12864/)
### [![](../../LCDDWIN.jpg)](./firmware/LCD_DWIN/)

## Source code
Please download firmware source code from [**Here**](https://github.com/ZONESTAR3D/source-code-for-3d-printer).  

## Wiring Diagram
![](Z9M3_ZM3E4_Wiring_Diagram.jpg)

-----
### Firmware Upload Steps
1. Download and unzip the firmware zip file
2. Copy firmware.bin to the root directoy of Micro-SD card
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, wait about 30 seconds (need to push the DC power switch if you have installed it)
5. Reset the EEPROM after uploaded frimware:    
For LCD12864, `MENU>>Configuration>>Advanced setting>>Initialize EEPROM`   
For LCD_DWIN, `MENU>>Contol>>Restore defaults`