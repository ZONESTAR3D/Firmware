### :globe_with_meridians: Choose Language (Translated by google)
[![](./lanpic/ES.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=es)
[![](./lanpic/PT.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=pt)
[![](./lanpic/FR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=fr)
[![](./lanpic/DE.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=de)
[![](./lanpic/IT.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=it)
[![](./lanpic/SW.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=sv)
[![](./lanpic/PL.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=pl)
[![](./lanpic/DK.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=da)
[![](./lanpic/CZ.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=cs)
[![](./lanpic/HR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=hr)
[![](./lanpic/RO.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=ro)
[![](./lanpic/SK.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=sk)

[![](./lanpic/RU.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=ru)
[![](./lanpic/JP.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=ja)
[![](./lanpic/KR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=ko)
[![](./lanpic/ID.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=id)
[![](./lanpic/TH.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=th)
[![](./lanpic/VN.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=vi)
[![](./lanpic/IL.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=iw)
[![](./lanpic/SA.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=ar)
[![](./lanpic/TR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=tr)
[![](./lanpic/GR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=el)
[![](./lanpic/BR.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=pt)
[![](./lanpic/CN.png)](https://github-com.translate.goog/ZONESTAR3D/Firmware?_x_tr_sl=en&_x_tr_tl=zh-CN)

-----
# Firmware file for ZONESTAR 3D printer
***NOTE:If you find any question, please feel free to contact us by email: [support@zonestar3d.com](support@zonestar3d.com)***

-----
## ZONESTAR 3D Printer Firmware download link:
- :file_folder: [**P802 Series: P802M/P802N/P802Q/P802C**](./P802/)
- :file_folder: [**Z5 Series: Z5/Z5S/Z5SM2/Z5SR2**](./Z5/)
- :file_folder: [**Z5X Series: Z5X/Z5XM2**](./Z5X/)
- :file_folder: [**Z6 Series: Z6/Z6B/Z6F/Z6FB**](./Z6/)
- :file_folder: [**Z8 Series: Z8/Z8X/Z8S/Z8T/Z8P**](./Z8/)
- :file_folder: [**Z9 Series: Z9M2/Z9M3/Z9M4/Z9V5**](./Z9/)
- :file_folder: [**Z10 Series: Z10S/Z10M2**](./Z10/)

-----
## How to Upload Firmware
***ATTETION:Please distinguish the control board model before upload firmware***

### For ZM3E2/ZM3E4 32-bit control board 
:movie_camera: [**How to download firmware bin(Hex) file and copy to SD card**](./Firmware_Download.gif)
1. Download the zip file and unzip it, you will got a firmware.bin file
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into card socket of the control board
4. Power on the printer, wait about 30 seconds
5. Reset the EEPROM after uploaded firmware:
	- For LCD12864: "MENU>>Configuration>>Advanced setting>>initialize  EEPROM"
	- For LCD_DWIN: "MENU>>Control>>Restore Defaults"    

### For ZRIB & ZMIB 8-bit control board  
1. Download firmware upgrade tool: [:arrow_down:](./Firmware_Upload_tool_for_ZRIB_ZMIB/Arduloader.zip).
2. Download HEX file and copy the hex file to the same directory with the tool.   
3. Unzip "Arduloader.zip" , there is a user guide"Arduloader_user_guide.pdf" in this zip file, please read it. 
4. Connect the printer to your PC, please make sure the driver has been installed correctly. 
5. Follow "Arduloader_user_guide.pdf" to upload the firmware to your control board.

----
### :file_folder:[Discontinued 3D Printer product Firmware](./backup/)
If your printer model is Z9M2, Z9M3, D805S, D806, please find the firmware from the below link:
- [**Firmware**](./backup/Firmware/)
- [**Sourcecode**](./backup/Sourcecode/)
