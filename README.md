# Firmware file for ZONESTAR 3D printer
***NOTE:If you find any question, please feel free to contact us by email: [support@zonestar3d.com](support@zonestar3d.com)***

---------
## ZONESTAR 3D Printer Firmware download link:
- :file_folder: [**Z5 Serial: Z5/Z5S/Z5SM2/Z5SR2**](./Z5/)
- :file_folder: [**Z5X Serial: Z5X/Z5XM2**](./Z5X/)
- :file_folder: [**Z6 Serial: Z6/Z6B/Z6F/Z6FB**](./Z6/)
- :file_folder: [**Z8 Serial: Z8/Z8X/Z8S/Z8T/Z8P**](./Z8/)
- :file_folder: [**Z9 series: Z9M2/Z9M3/Z9M4/Z9V5**](./Z9/)
- :file_folder: [**Z10 series: Z10S/Z10M2**](./Z10/)

---------
## How to Upload Firmware
***ATTETION:Please distinguish the control board model before upload firmware***

### For ZM3E2/ZM3E4 control board 
:movie_camera: [**How to download firmware bin(Hex) file and copy to SD card**](./Firmware_Download.gif)
1. Download the zip file and unzip it, you will got a firmware.bin file
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into card socket of the control board
4. Power on the printer, wait about 30 seconds
5. Reset the EEPROM after uploaded firmware:
	- For LCD12864: "MENU>>Configuration>>Advanced setting>>initialize  EEPROM"
	- For LCD_DWIN: "MENU>>Control>>Restore Defaults"    

### For ZRIB & ZMIB control board  
1. Download firmware upgrade tool: [:arrow_down:](./Firmware_Upload_tool_for_ZRIB_ZMIB/Arduloader.zip).
2. Download HEX file and copy the hex file to the same directory with the tool.   
3. Unzip "Arduloader.zip" , there is a user guide"Arduloader_user_guide.pdf" in this zip file, please read it. 
4. Connect the printer to your PC, please make sure the driver has been installed correctly. 
5. Follow "Arduloader_user_guide.pdf" to upload the firmware to your control board.

----
### :file_folder:[Discontinued 3D Printer product Firmware](./backup/)
- :file_folder: [**P802 Serial: P802C/P802M/P802N/P802Q/M8R2**](./backup/P802/)
- :file_folder: [**D805 Serial: D805/D805S/D805SR2**](./backup/D805S/)
