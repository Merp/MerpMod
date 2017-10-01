
#include "EcuHacks.h"

/////////////////
//Constants
/////////////////
#if CAN_HACKS


CanMessageSetupStruct ccm00 CANDATA = {.id = 0x240,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 20,	.mcs = mcsTrans, 	.nmc = 0, .rate = 22, .callback = 0};
CanMessageSetupStruct ccm01 CANDATA = {.id = 0x506, .ext = 0,	.dlc = 3,	.bus = 0,	.mailBox = 21,	.mcs = mcsReceive, 	.nmc = 1, .rate =  0, .callback = (unsigned long)&raceGradeKeyPadCallback};
CanMessageSetupStruct ccm02 CANDATA = {.id = 0x507,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 22,	.mcs = mcsTrans, 	.nmc = 0, .rate =  0, .callback = 0}; //RaceGrade Keypad LEDS
CanMessageSetupStruct ccm03 CANDATA = {.id = 0x000,	.ext = 0,	.dlc = 2,	.bus = 0,	.mailBox = 23,	.mcs = mcsTrans,    .nmc = 0, .rate =1000, .callback = 0}; //RaceGrade Keypad INIT CANOPEN
CanMessageSetupStruct ccm04 CANDATA = {.id = 0x241,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 24,	.mcs = mcsTrans, 	.nmc = 0, .rate = 22, .callback = 0};
CanMessageSetupStruct ccm05 CANDATA = {.id = 0x246,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 25,	.mcs = mcsInactive, .nmc = 0, .rate =  0, .callback = 0};
CanMessageSetupStruct ccm06 CANDATA = {.id = 0x720,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 26,	.mcs = mcsReceive, 	.nmc = 1, .rate =  0, .callback = (unsigned long)&canCallbackRamTune};
CanMessageSetupStruct ccm07 CANDATA = {.id = 0x728,	.ext = 0,	.dlc = 8,	.bus = 0,	.mailBox = 27,	.mcs = mcsTrans, 	.nmc = 0, .rate =  0, .callback = 0};
//CanMessageSetupStruct *ccmGroup[8] CANDATA;// = {&ccm00,&ccm01,&ccm02,&ccm03,&ccm04,&ccm05,&ccm06,&ccm07};


CanDataSendStuct cmDT00 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[0].state, .type=dtChar, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT01 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[1].state, .type=dtChar, .ccm=0, .bytePos=1};
CanDataSendStuct cmDT02 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[2].state, .type=dtChar, .ccm=0, .bytePos=2};
CanDataSendStuct cmDT03 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[3].state, .type=dtChar, .ccm=0, .bytePos=3};
CanDataSendStuct cmDT04 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[4].state, .type=dtChar, .ccm=0, .bytePos=4};
CanDataSendStuct cmDT05 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[5].state, .type=dtChar, .ccm=0, .bytePos=5};
CanDataSendStuct cmDT06 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[6].state, .type=dtChar, .ccm=0, .bytePos=6};
CanDataSendStuct cmDT07 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[7].state, .type=dtChar, .ccm=0, .bytePos=7};
CanDataSendStuct cmDT08 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[0].led, .type=dtChar, .ccm=4, .bytePos=0};
CanDataSendStuct cmDT09 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[1].led, .type=dtChar, .ccm=4, .bytePos=1};
CanDataSendStuct cmDT10 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[2].led, .type=dtChar, .ccm=4, .bytePos=2};
CanDataSendStuct cmDT11 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[3].led, .type=dtChar, .ccm=4, .bytePos=3};
CanDataSendStuct cmDT12 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[4].led, .type=dtChar, .ccm=4, .bytePos=4};
CanDataSendStuct cmDT13 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[5].led, .type=dtChar, .ccm=4, .bytePos=5};
CanDataSendStuct cmDT14 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[6].led, .type=dtChar, .ccm=4, .bytePos=6};
CanDataSendStuct cmDT15 CANDATA = {.addr=(unsigned long)&pRamVariables->buttons[7].led, .type=dtChar, .ccm=4, .bytePos=7};
CanDataSendStuct cmDT16 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT17 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT18 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT19 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT20 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT21 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT22 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT23 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT24 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT25 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT26 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT27 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT28 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT29 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT30 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};
CanDataSendStuct cmDT31 CANDATA = {.addr=0x00000000, .type=0, .ccm=0, .bytePos=0};

CanDataSendStuct *cmDTGroup[32] CANDATA = {
	&cmDT00,&cmDT01,&cmDT02,&cmDT03,&cmDT04,&cmDT05,&cmDT06,&cmDT07,
	&cmDT08,&cmDT09,&cmDT10,&cmDT11,&cmDT12,&cmDT13,&cmDT14,&cmDT15,
	&cmDT16,&cmDT17,&cmDT18,&cmDT19,&cmDT20,&cmDT21,&cmDT22,&cmDT23,
	&cmDT24,&cmDT25,&cmDT26,&cmDT27,&cmDT28,&cmDT29,&cmDT30,&cmDT31
	};

#endif