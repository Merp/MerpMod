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

//Tests for Programming mode
#include "EcuHacks.h"
#if PROG_MODE
void ProgModeEntryTest() __attribute__ ((section ("Misc")));
void ProgModeUnitTests() __attribute__ ((section ("Misc")));
void TestProgModeListener(int c) __attribute__ ((section ("Misc")));
void TestProgModeMain(int c) __attribute__ ((section ("Misc")));
void TestProgModeMain(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
		ProgModeMain();
	}
}

void TestProgModeListener(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
		ProgModeListener();
	}
}

void ProgModeUnitTests()
{
	ProgModeEntryTest();

	//verify progmode exit
	SetClutch(1);
	ProgModeListener();
	Assert(pRamVariables->ProgModeEnable == 0,"Check progmode exit for clutch");
	
	ProgModeEntryTest();
	*pEngineSpeed = 1000.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEnable == 0,"Check progmode exit for RPM");
	
}

void ProgModeEntryTest()
{
	PopulateRamVariables();
	*pEngineSpeed = 0;
	SetBrake(0);
	SetClutch(0);
	pRamVariables->ProgModeEntry=0;
	pRamVariables->ProgModeTimer=0;
	
	if(pRamVariables->ProgModeEnable != 0)
		ExitProgMode();
	
	SetBrake(1);
	TestProgModeListener(2);
	Assert(pRamVariables->ProgModeEntry==1,"Programming mode entry listener step 1");
	SetBrake(0);
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==2,"Programming mode entry listener step 2");
	*pThrottlePlate = 90.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==3,"Programming mode entry listener step 3");
	*pThrottlePlate = 0.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==4,"Programming mode entry listener step 4");
	*pThrottlePlate = 90.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==5,"Programming mode entry listener step 5");
	*pThrottlePlate = 0.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==6,"Programming mode entry listener step 6");
	*pThrottlePlate = 90.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==7,"Programming mode entry listener step 7");
	*pThrottlePlate = 0.0f;
	ProgModeListener();
	Assert(pRamVariables->ProgModeEntry==0,"Programming mode entry listener step 8");	
	
	//test progmode is now entered
	Assert(pRamVariables->ProgModeEnable == 1, "rogramming mode entry check");
	Assert(pRamVariables->ProgModeWait == 248, "rogramming mode entry check");
	Assert(pRamVariables->ProgModeEntry == 0, "rogramming mode entry check");
	
}

#endif