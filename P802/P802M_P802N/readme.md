## Firmware
### P802M
- **:arrow_down: [P802M: Melzi board, Marlin Firmware with DDE](./P802M_Melzi_Marlin_DDE.zip)**
- **:arrow_down: [P802M: Melzi board](./P802M_Melzi_Marlin.zip)**
### P802N
- **:arrow_down: [P802N: Melzi board, Repetier Firmware](./P802N_MELZI.zip)**
- **:arrow_down: [P802N: Melzi board, Marlin Firmware](./P802N_Melzi_Marlin_V22.zip)**
- **:arrow_down: [P802N: ZRIB board, Repetier Firmware](./P802N_ZRIB.zip)**
- **:arrow_down: [P802NR2: ZRIB board, Dual Extruder](./P802NR2_ZRIB.zip)**
- **:arrow_down: [P802NM2: ZRIB board, Dual Extruder and Mix Color Hotend](./P802NM2_ZRIBV6_LCD2004_5KEY.zip)**

----
## How to Upload Firmware
***ATTETION:Please distinguish the control board model before upload firmware***
### For ZRIB & ZMIB 8-bit control board  
1. Download firmware upgrade tool: [:arrow_down:](https://github.com/ZONESTAR3D/Firmware/tree/master/Firmware_Upload_tool_for_ZRIB_ZMIB).
2. Download HEX file and copy the hex file to the same directory with the tool.   
3. Unzip "Arduloader.zip" , there is a user guide"Arduloader_user_guide.pdf" in this zip file, please read it. 
4. Connect the printer to your PC, please make sure the driver has been installed correctly. 
5. Follow "Arduloader_user_guide.pdf" to upload the firmware to your control board.

### For ZM3E2/ZM3E4 32-bit control board 
1. Download the zip file and unzip it, you will got a firmware.bin file
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into card socket of the control board
4. Power on the printer, wait about 30 seconds
5. Reset the EEPROM after uploaded firmware:
	- For LCD12864: "MENU>>Configuration>>Advanced setting>>initialize  EEPROM"
	- For LCD_DWIN: "MENU>>Control>>Restore Defaults"    

----
## :file_folder: [Firmware Source code](https://github.com/ZONESTAR3D/source-code-for-3d-printer)
Please refer to [**here**](https://github.com/ZONESTAR3D/source-code-for-3d-printer).