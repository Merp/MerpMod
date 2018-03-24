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
#if CEL_HACKS

void TestCelFlash(int c) __attribute__ ((section ("Misc")));
void TestCelFlash(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
		CelFlash();
	}
}

void CelFlashUnitTests() __attribute__ ((section ("Misc")));
void CelFlashUnitTests()
{
	PopulateRamVariables();

	*pCelSignalOem = 1;
	pRamVariables.CelSignal = 0;
	*pFBKC = 0;
	*pClutchFlags = 0;
	*pAf1Res = EGTResistanceThreshold + 5;
	*pCoolantTemp = ECTFlashThreshold - 5;
#ifdef pResumeFlags
	*pResumeFlags = 0;
#endif

#ifdef pIam4
*pIam4 = 1.0f;
#else
*pIam1 = 16;
#endif

	pRamVariables.CelSignalLast = 0;
	pRamVariables.CelFlashCounter = 0;
	pRamVariables.CelFlashSpeedCounter = 0;
	CelFlash();
	Assert(pRamVariables.CelSignal == 1, "OEM cel popped, Cel Signal should have popped too");
	
	//Check it is still on
	TestCelFlash(20);
	Assert(pRamVariables.CelSignal == 1, "OEM cel popped, 20 cycles later, Cel Signal should stay on");
	//Check 1 more cycle
	CelFlash();
	Assert(pRamVariables.CelSignal == 1, "OEM cel popped, 21 cycles later, Cel Signal should stay on");
	
	//Turn OEM Cel off, check for response
	
	*pCelSignalOem = 0;
	CelFlash();
	Assert(pRamVariables.CelSignal == 0, "OEM cel is now gone, Cel signal should have dropped");
	
	//Trigger knock below load threshold
	*pEngineLoad = 1.0f;
	*pFBKC = -1.0f;
	CelFlash();
	Assert(pRamVariables.CelSignal == 0, "below fbkc load threshold for cel, no light!");
	
	//Trigger knock above load threshold
	*pEngineLoad = 3.0f;
	CelFlash();
	Assert(pRamVariables.CelFlashCounter > 0, "knocking! Flash counter should init");
	Assert(pRamVariables.CelFlashSpeedCounter > 0, "knocking! Flash speed counter should init");
	Assert(pRamVariables.CelFlashSpeed > 0, "knocking! Flash speed counter should init");
	Assert(pRamVariables.CelSignal == 1, "knocking! Flash should start");
	
	//remove knock conditions
	*pEngineLoad = 1.0f;
	*pFBKC = 0.0f;
	
	//run cel flash a few times to clear everything out
	TestCelFlash(200);
	
	Assert(pRamVariables.CelSignal == 0, "knocking gone! Flash should zero");
	Assert(pRamVariables.CelFlashCounter == 0, "knocking gone! Flash counter should zero");

//TODO: Test IAM CEL WARNING

/*	//Clear recall and Run cycles, should clear everything
	*pClutchFlags &= ~ClutchBitMask;
	*pResumeFlags &= ~ResumeBitMask;
	TestCelFlash(400);
	Assert(pRamVariables.CelSignal == 0, "knocking gone! Flash should zero");
	Assert(pRamVariables.CelFlashCounter == 0, "knocking gone! Flash counter should zero");
*/
}	
	
#endif
