## Firmware upload steps:
:warning: Arduloader only can work on a PC with windows system (Win7/Win10/Win11) 
#### 1. Download [**Arduloader.zip**](./Arduloader.zip) and unzip it to your PC.   
#### 2. Connect the 3d printer to PC by USB cable.  
#### 3. Refer to the guide "Arduloader user guide.pdf" to upload firmware to the control board.   
##### :warning: **NOTE 1** Rename the directory to a simply for example "tool" and copy the HEX file to the same directory with "Arduloader.exe".     

## FAQ
### Show "stk500v2_ReceiveMessage(): timeout" error 
![](./1.jpg)   
1. Please connect the USB cable to control board and check if the com port showed on the arduloader message window,? If not, please check if the USB driver is installed well.
2. Choose the com port and upload firmware again. if the question is the same, try to change the com port number and reset your PC and try again.
[:movie_camera: How to change com port](./ChangeCOMPort.gif)