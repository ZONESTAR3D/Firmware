## Release Note
### V1.5.3
- **Date:** 2024-04-27
- [**BUG**] Fix M190 Rx issue
- [**BUG**] Fix the bug the LCD screen doesn't show print menu when use M24 command on SD card
- 
### V1.5.2
- **Date:** 2024-03-18
- [**CHG**] Optimize startup speed

### V1.5.1
- **Date:** 2024-03-14
- [**CHG**] Optimize BabyStep functionality: 
1. It is prohibited to call out the "Babystep" menu before starting printing.
2. Improve the issue of accidentally exiting the BabyStep menu by repeatedly pressing the knob when starting BabyStep.

### V1.5.0
- **Date:** 2023-12-25
- [**NEW**] Support to access the SD card files from USB Port.    
  :pushpin: Hint:      
  - Do not access the SD card during printing.
  - Must plug the SD card before power on the machine if you need to access it from USB port.
  - If released the SD card from machine, you need to disconnect the USB cable and restart the machine, otherwise you can't find the SD card from PC.
  - The speed of accessing the SD card through USB is about 300KB/S. If the file is large, please be patient to wait for the access to be completed.
