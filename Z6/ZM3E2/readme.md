## Hex
Included firmware bin file for Z6F and Z6FB.  

##### What's different between Z6F and Z6FB?  
- **Z6F**   Z6 without heated printing platform  
- **Z6FB**  Z6 with heated printing platform (with heat bed)  

## SourceCode
Included firmware suource code

## USB driver
ZM3E4 used STM32F103RCT6 MCU, which uses the built-in USB module to virtual "USB to UART", so you need to supply DC power to the 3d printer first before connect the USB cable, and then you can install the USB driver, to find a named "maplab" USB to UART brige.   

## Upload firmware
#### you can upload firmware to ZM3E2 control board from SD card, steps as below
1. Download the zip file and unzip it, you will got a firmware.bin file
2. Copy firmware.bin to the root directory of Micro-SD card
3. Power off the printer and plug the Micro-SD card into card socket of the control board
4. Power on the printer, wait about 30 seconds.
5. Power off the printer and remove the SD card, and then Power on the printer again  


