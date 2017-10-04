/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

//Tests for CEL Flashing Code
//TODO test for normal/severe knock behavior, implement interrupt when lowknock -> hi
#include "EcuHacks.h"
// Test the rev limiter hack.
#if CAN_HACKS

void TestCustomCan(int c) __attribute__ ((section ("Misc")));
void TestCustomCan(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
	//	CustomCan();
	}
}

unsigned long getMailBoxId(unsigned short mailbox, unsigned short bus) __attribute__ ((section ("Misc")));
unsigned long getMailBoxId(unsigned short mailbox, unsigned short bus)
{
	unsigned short* ptr;	
	ptr = (unsigned short*)(0xFFFFD100+ 0x800*bus + 0x20*(unsigned short)mailbox);
/*	if(cs->ext == 0) //11-bit, not extended
		{
		ptr[0] = ((unsigned short)cs->id<<4)&0x7FF0;
		ptr[1] = 0;
		}
	else if(cs->ext == 1)
		{
		ptr[0]  = (unsigned short)(((unsigned long)cs->id>>16)&0x0003);
		ptr[0] += (unsigned short)(0x0004);
		ptr[0] += (unsigned short)(((unsigned long)cs->id>>14)&0x7FF0);
		ptr[1] = ((unsigned short)cs->id)&0xFFFF;
		}		
	//ptr[2] = (((unsigned short)cs->mcs<<8)&0x700) + ((unsigned short)cs->dlc&0x0F);	*/
	unsigned short ddd = ptr[0]&0x04;
	unsigned long id = 0xffffffff;
	if(ddd == 0x04)
	{
		id = (unsigned long)ptr[1];
		id += (unsigned long)(ptr[0]&0x02)<<16;
		id += (unsigned long)(ptr[0]&0x7FF0)<<14;		
	}
	else
	{
		id = (ptr[0]>>4)&0x7FF;		
	}
	return id;
}

#if RACEGRADE_KEYPAD_HACKS
unsigned char dt1[8]  = {0,0,0,0,0,0,0,0};
unsigned char dt2[8]  = {0,0,0,0,0,0,0,0};
unsigned char dt3[8]  = {4,0,0,0,0,0,0,0};
unsigned char dtAEM[8] ROMCODE = {4,2,5,2,0,0,0,0};
#endif

void CustomCanUnitTests() __attribute__ ((section ("Misc")));
void CustomCanUnitTests()
{
	PopulateRamVariables();
	
	CanSetup();	
	//Test to make sure CanSetup puts the right info into the Mailboxes
	Assert(getMailBoxId(ccm00.mailBox, ccm00.bus) == ccm00.id, "CAN ID 0 is not set Correctly");
	Assert(getMailBoxId(ccm01.mailBox, ccm01.bus) == ccm01.id, "CAN ID 1 is not set Correctly");
	Assert(getMailBoxId(ccm02.mailBox, ccm02.bus) == ccm02.id, "CAN ID 2 is not set Correctly");
	Assert(getMailBoxId(ccm03.mailBox, ccm03.bus) == ccm03.id, "CAN ID 3 is not set Correctly");
	Assert(getMailBoxId(ccm04.mailBox, ccm04.bus) == ccm04.id, "CAN ID 4 is not set Correctly");
	Assert(getMailBoxId(ccm05.mailBox, ccm05.bus) == ccm05.id, "CAN ID 5 is not set Correctly");
	Assert(getMailBoxId(ccm06.mailBox, ccm06.bus) == ccm06.id, "CAN ID 6 is not set Correctly");
	Assert(getMailBoxId(ccm07.mailBox, ccm07.bus) == ccm07.id, "CAN ID 7 is not set Correctly");
	Assert(getMailBoxId(ccm08.mailBox, ccm08.bus) == ccm08.id, "CAN ID 8 is not set Correctly");
	Assert(getMailBoxId(ccm09.mailBox, ccm09.bus) == ccm09.id, "CAN ID 9 is not set Correctly");
	
	
//	dtAEM[8]  = {4,1,5,2,0,0,0,0};
	canCallbackAEMwideband(&dtAEM[0]);
	Assert(Abs(pRamVariables->aemLambda - 0.1026f) < 0.0001, "aem lambda Fault Failed");
	Assert(Abs(pRamVariables->aemOxygen - 1.282f) < 0.0001, "aem oxygen Fault Failed");
	
	dtAEM[6]  = 0x80;
	canCallbackAEMwideband(&dtAEM[0]);
	Assert(pRamVariables->aemDataValid == 1, "aem Data Valid Failed");
	
	
	dtAEM[7]  = 0x40;
	canCallbackAEMwideband(&dtAEM[0]);
	Assert(pRamVariables->aemSensorFault == 1, "aem Sensor Fault Failed");	
	
	//Try all DT types, 1,2,3 U8,U16,U32
	cmDTccm[0] = 0;	
	cmDTaddr[0] = 0xFFFF0000;	
	ccm00.mailBox = 19; //Force to Mailbox 19 for now
	cmDTtypeIn[0] = 1;
	cmDTtypeOut[0] = 1;
	*((unsigned char*)cmDTaddr[0]) = 0x55;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 0x55, "DT U8 Check Failed");
	
	cmDTtypeIn[0] = 2;
	cmDTtypeOut[0] = 2;
	*((unsigned short*)cmDTaddr[0]) = 0x1234;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 0x1234, "DT U16 Check Failed");
	
	cmDTtypeIn[0] = 3;
	cmDTtypeOut[0] = 3;
	*((unsigned long*)cmDTaddr[0]) = 0x87654321;
	updateCanDT(0);
	Assert(*(unsigned long*)(0xFFFFD100+0x08+19*0x20) == 0x87654321, "DT U32 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 4;
	*((float*)cmDTaddr[0]) = 3.1415f;
	updateCanDT(0);
	Assert(*(float*)(0xFFFFD100+0x08+19*0x20) == 3.1415f, "DT float Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 4;
	cmDTscale[0] = 3;
	cmDToffset[0] = 0;
	*((float*)cmDTaddr[0]) = 3.1415f;
	updateCanDT(0);
	Assert(*(float*)(0xFFFFD100+0x08+19*0x20) == 3.1415f*3, "DT float scale Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 4;
	cmDTscale[0] = 3;
	cmDToffset[0] = 2.25f;
	*((float*)cmDTaddr[0]) = 3.1415f;
	updateCanDT(0);
	Assert(*(float*)(0xFFFFD100+0x08+19*0x20) == ((2.25f + 3.1415f)*3), "DT float scale offset Check Failed");
	
	
	//Float to U8
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	*((float*)cmDTaddr[0]) = 3.1415f;
	cmDTscale[0] = 1;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 3, "DT float u8 Check Failed");
	
	//this should round up
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	*((float*)cmDTaddr[0]) = 3.50001f;
	cmDTscale[0] = 1;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 4, "DT float u8 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	cmDTscale[0] = 3;
	cmDToffset[0] = 0;
	*((float*)cmDTaddr[0]) = 3.1415f;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 9, "DT float u8 scale Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	cmDTscale[0] = 4;
	cmDToffset[0] = 2;
	*((float*)cmDTaddr[0]) = 3;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 20, "DT float u8 scale offset Check Failed");
	
		//Float to U16
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	*((float*)cmDTaddr[0]) = 257.49;
	cmDTscale[0] = 1;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 257, "DT float u16 Check Failed");
	
	//this should round up
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	*((float*)cmDTaddr[0]) = 257.501;
	cmDTscale[0] = 1;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 258, "DT float u16 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	cmDTscale[0] = 3;
	cmDToffset[0] = 0;
	*((float*)cmDTaddr[0]) = 100;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 300, "DT float u16 scale Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	cmDTscale[0] = 4;
	cmDToffset[0] = 2;
	*((float*)cmDTaddr[0]) = 100;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 408, "DT float u16 scale offset Check Failed");
	
	//Float to U8 OVERFLOWS
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	*((float*)cmDTaddr[0]) = -3;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 0, "DT float u8 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 1;
	*((float*)cmDTaddr[0]) = 300;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned char*)(0xFFFFD100+0x08+19*0x20) == 255, "DT float u8 Check Failed");
	
	//Float to U16 OVERFLOWS
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	*((float*)cmDTaddr[0]) = -3;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 0, "DT float u8 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 2;
	*((float*)cmDTaddr[0]) = 65536;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned short*)(0xFFFFD100+0x08+19*0x20) == 65535, "DT float u8 Check Failed");
	
	//Float to U32 OVERFLOWS
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 3;
	*((float*)cmDTaddr[0]) = -3;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned long*)(0xFFFFD100+0x08+19*0x20) == 0, "DT float u8 Check Failed");
	
	cmDTtypeIn[0] = 4;
	cmDTtypeOut[0] = 3;
	*((float*)cmDTaddr[0]) = 4294967296;
	cmDTscale[0] = 0;
	cmDToffset[0] = 0;
	updateCanDT(0);
	Assert(*(unsigned long*)(0xFFFFD100+0x08+19*0x20) == 4294967295, "DT float u8 Check Failed");
	
	CustomCanService();
	
	#if RACEGRADE_KEYPAD_HACKS
		raceGradeKeyPadCallback(&dt1[0]);
		raceGradeKeyPadCallback(&dt2[0]);
		raceGradeKeyPadCallback(&dt3[0]);
		ProgModeMain();
		raceGradeKeyPadCallback(&dt3[0]);
	#endif

	pRamVariables->initFunctionRun = 0;	
	CustomCanService();



	
	
	//Check it is still on
//	TestCustomCan(20);
//	Assert(pRamVariables->CelSignal == 1, "OEM cel popped, 20 cycles later, Cel Signal should stay on");

}	
	
#endif
