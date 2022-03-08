# Firmware file for ZONESTAR 3D printer
***NOTE:If you find any question, please feel free to contact us by email: [support@zonestar3d.com](support@zonestar3d.com)***

## Firmware Upload steps
***ATTETION:Please distinguish the type of control panel and control board model before upload firmware***

### Upload firmware to ZM3E2/ZM3E4 control board 
1. Download the zip file and unzip it, you will got a firmware.bin file
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into card socket of the control board
4. Power on the printer, wait about 30 seconds
5. Reset the EEPROM after uploaded firmware:
	- For LCD12864: "MENU>>Configuration>>Advanced setting>>initialize  EEPROM"
	- For LCD_DWIN: "MENU>>Control>>Restore Defaults" 

### Upload firmware to ZRIB & ZMIB control board  
1. Download firmware upgrade tool: **./Firmware\_Upload\_tool\_for\_ZRIB\_ZMIB/Arduloader.zip**.
2. Download HEX file and copy the hex file to the same directory with the tool.   
3. Unzip "Arduloader.zip" , there is a user guide"Arduloader_user_guide.pdf" in this zip file, please read it. 
4. Connect the printer to your PC, please make sure the driver has been installed correctly. 
5. Follow "Arduloader_user_guide.pdf" to upload the firmware to your control board.

## How to downlod files from Github page
#### Step 1: Click this link [**https://downgit.github.io/**](https://downgit.github.io/) 
#### Step 2: Copy the Github file or direcotry link which you want to download.
#### Step 3: Click download button and wait a few seconds, it will start to download automatically. 
![](https://github.com/ZONESTAR3D/Document-and-User-Guide/blob/master/download.gif)   