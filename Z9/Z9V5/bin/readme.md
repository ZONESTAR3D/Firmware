## How do I know if my machine is MK1, MK2, MK3 or MK4?
### Method 1. Check serial number of your printer:
You can distinguish by serial number, there is a white lable on the power supply wrote down the serial number.  
- **Z9V5-MK1:** Serial Number is **xxxxxxxxxx**   
- **Z9V5-MK2:** Serial Number is **V1-xxxxxxxxxx** and **V2-xxxxxxxxxx**    
- **Z9V5-MK3:** Serial Number is **MK3-xxxxxxxxxx**  
- **Z9V5-MK4:** Serial Number is **MK4-xxxxxxxxxx**  
![Z9V5_SN](Z9V5_SN.jpg)
### Method 2. Check the original firmware version:
You can check the printer name from the LCD screen, refer to the below picture:

    Menu>>Info>>Model:
- **Z9V5-MK1** and **Z9V5-MK2**: model is **Z9V5Pro** or **Z9V5Pro-MK1(2)**  
- **Z9V5-MK3**: model is **Z9V5Pro-MK3**    
- **Z9V5-MK4**: model is **Z9V5Pro-MK4**    
![Z9V5_Info](info.jpg)   

## What's different on Z9V5Pro-MK1, MK2, MK3 and MK4 
**Please refer to :point_right: [here](https://github.com/ZONESTAR3D/Z9/tree/main/Z9V5)**

## What's different between Z9V5 with Z9V5Pro
**Z9V5 equiped with LCD12864 LCD screen and hotbed sticker**    
**Z9V5Pro equiped with a 4.3" TFT-LCD screen and a glass print platform**    
**NOTE: We stop to produce Z9V5 since Z9V5-MK2.**  

-------------
## Firmware Upload Steps:
1. Download the zip file and unzip it
2. Copy firmware.bin to the root directory of Micro-SD card, 
**NOTE: !!if there is a "old_fw.bin" in the SD card, delete it first!!**    
3. Power off the printer and plug the Micro-SD card into socket on control board
4. Power on the printer, push the power button and wait about 30 seconds
5. Do the below step on LCD screen to initialize EEPROM after upload firmware:  ***MENU>>Control>>Restore Defaults***
