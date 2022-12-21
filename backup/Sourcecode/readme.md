### [:arrow_down: V3](./Sourcecode/V3.zip)
### [:arrow_down: V4](./Sourcecode/V4.zip)

-----
## How to build firmware source code
### 1. Download and install [Arduino IDE V1.18.x](https://www.arduino.cc/en/software). The last version should work too, but we don't test it.
### 2. Open the config.h file and modify the below line, about details of the MODEL_NUMBER, please open the "modelist.h" file to view the definition
>
    #define	MODEL_NUMBER		D805SR2
### 3. Open Marlin.ino in Arduino IDE and build it.

-----
#### modelist.h
>
    /*********************************************************************************************************/
    //							Model list
    /*********************************************************************************************************/
    #define	TESTMODEL			 0
    #define	ZA6_R2				 1
    //Prusa i3, Full Acrylic frame, acrylic hotend
    #define	P802C				10	//P802C, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board, without heatbed
    #define	P802CB				11	//P802C, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802CR2				12	//P802C, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    //Prusa i3, Acrylic frame, metal hotend
    #define	P802N_MELZI			20	//P802N 1st version, Single extruder,  LCD2004 and 5Key keypad, Melzi control board
    #define	P802N				21	//P802N 2nd version, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802NR2				22	//P802N 2nd version, dual extruder,  LCD2004 and 5Key keypad, ZRIB control board

    #define	A3_MELZI			23	//A3(Afinibot), Single extruder,  LCD2004 and 5Key keypad, Melzi control board
    #define	A3S_MELZI			24	//A3S(Afinibot), Single extruder,  LCD2004 and 5Key keypad, Melzi control board
    #define	A3S_ZRIB			25	//A3S(Afinibot), Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    //Prusa i3, Metal frame
    #define	P802Q_MELZI_5KEY	30	//P802Q 1st version, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802QS_5KEY			31	//P802Q 2nd version, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802QR2_5KEY		32	//P802Q 2nd version, dual extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802QM2_5KEY		33	//P802Q 2nd version, 2-IN-1-OUT Mixing extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	P802QS_KNOB			34	//P802Q 3nd version, Single extruder,  LCD2004 and knob keypad, ZRIB control board
    #define	M8S					34
    #define	P802QR2_KNOB		35	//P802Q 3nd version, dual extruder,  LCD2004 and knob keypad, ZRIB control board
    #define	P802QM2_KNOB		36	//P802Q 3nd version, 2-IN-1-OUT Mixing extruder,  LCD2004 and knob keypad, ZRIB control board
    #define	M8R2				36
    #define	M8R2S				320
    #define	P802QR2_LCD12864	37	//P802QR2, dual extruder,  LCD128x64 and knob keypad, ZRIB control board
    #define	P802QR2_MINI12864	38	//P802QR2, dual extruder,  MKS Mini LCD128x64 and knob keypad, ZRIB control board
    //ANET A8
    #define	ANET_A8				40	//
    #define	ANET_A8R2			41	//

    //D805 & Z5 Serial
    #define	D805				50	//D805 1st version, Single extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	D805R2				51	//D805 1st version, dual extruder,  LCD2004 and 5Key keypad, ZRIB control board
    #define	D805S				52	//D805S 2nd version, Single extruder,  LCD2004 and knob keypad, ZRIB control board
    #define	D805SR2				53	//D805S 2nd version, dual exetruder,  LCD2004 and knob keypad, ZRIB control board
    #define	D805SM2				54	//D805S 2nd version, 2-IN-1-OUT Mixing exetruder,  LCD2004 and knob keypad, ZRIB control board
    #define	D805SM2_E0TOE1		504	//D805S 2nd version, 2-IN-1-OUT Mixing exetruder,  LCD2004 and knob keypad, ZRIB control board
    #define	Z5N_ZMIB			55	//Z5 3rd version, Single exetruder,  LCD12864 and knob keypad, ZMIB control board
    #define	Z5NM2_ZMIB			56	//Z5 3rd version, 2-IN-1-OUT Mixing exetruder,  LCD12864 and knob keypad, ZMIB control board
    #define	Z5N_ZRIB			57	//Z5 3rd version, Single exetruder,  LCD12864 and knob keypad, ZMIB control board
    #define	Z5NM2_ZRIB			58	//Z5 3rd version, 2-IN-1-OUT Mixing exetruder,  LCD12864 and knob keypad, ZRIB control board  [for test only]
    //D806 & Z6 Serial
    #define	D806				60	//D806 1st version, Single extruder, LCD2004 and 5Key keypad, ZRIB control board, without heatbed
    #define	D806B				61	//D806 1st version, Single extruder, LCD2004 and 5Key keypad, ZRIB control board, 
    #define	Z6					62	//Z6 1st version, Single extruder, OLED128x64 and Knob keypad, ZMIB control board, without heatbed
    #define	Z6B					63	//Z6 1st version, Single extruder, OLED128x64 and Knob keypad, ZMIB control board,
    #define	Z6B_WiFi			64	//Z6 1st version, Single extruder, OLED128x64 and Knob keypad, ZMIB control board,Connect to WiFi
    //D808 & Z8 Serial
    #define	Z8					80	//Z8 1st version, Single extruder, LCD12864 and knob keypad, ZRIB control board,
    #define	Z8H					80
    #define	Z8R2				81  //Z8 1st version, dual extruder, LCD12864 and knob keypad, ZRIB control board,
    #define	Z8HR2				81
    #define	Z8M2				82	//Z8 1st version, 2-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board,
    #define	Z8HM2				82
    #define	Z8M3				821
    #define	Z8HM3				821
    #define	Z8X					83	//Z8X 1st version, Single extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z8XR2				84	//Z8X 1st version, dual extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z8XM2				85	//Z8X 1st version, 2-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z8XM3				86	//Z8X 1st version, 3-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z8XS				87  //Z8X 2nd version, Single extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board
    #define	Z8XS_M2				88	//Z8X 2nd version, 2-IN-1-OUT Mixing extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board
    #define	Z8XS_M3				89  //Z8X 2nd version, 3-IN-1-OUT Mixing extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board
    #define	Z8XS_R2				802 //Z8X 2nd version, dual extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board

    //Z9 Serial
    #define	Z9					91	//Z9  1st version, Single extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9M2				92	//Z9  1st version, 2-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9M3				93	//Z9  1st version, 3-IN-1-OUT Mixing  extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9R2				902	//Z9  1st version, 2-IN-2-OUT extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9S_S				911	//Z9  Second version, Single extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9S_M2				912	//Z9  Second version, 2-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9S_R2				920	//Z9  Second version, 2-IN-2-OUT extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9S_M3				913	//Z9  Second version, 3-IN-1-OUT Mixing  extruder, LCD12864 and knob keypad, ZRIB control board

    #define	Z9H					94	//Z9 HBOT, Single extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9HM2				95	//Z9 HBOT, 2-IN-1-OUT Mixing extruder, LCD12864 and knob keypad, ZRIB control board
    #define	Z9HM3				96	//Z9 HBOT, 3-IN-1-OUT Mixing  extruder, LCD12864 and knob keypad, ZRIB control board
    //Z10 Serial
    #define	Z10_REPRAPLCD		100	//Z10, Single extruder, Reprap LCD12864 and knob keypad, ZRIB control board
    #define	Z10M2_REPRAPLCD		101	//Z10, 2-IN-1-OUT Mixing extruder, Reprap LCD12864 and knob keypad, ZRIB control board
    #define	Z10_ZONESTARLCD	    102	//Z10, Single extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board
    #define	Z10M2_ZONESTARLCD	103	//Z10, 2nd version, 2-IN-1-OUT Mixing extruder, ZONESTAR LCD12864 and knob keypad, ZRIB control board
    #define	Z10S	    		104	//Z10 2nd Version, Single extruder, ZONESTAR LCD12864 and knob keypad, ZRIBV6 control board
    #define	Z10S_M2				105	//Z10 2nd Version, 2nd version, 2-IN-1-OUT Mixing extruder, ZONESTAR LCD12864 and knob keypad, ZRIBV6 control board
