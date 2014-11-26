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

#include "EcuHacks.h"

unsigned char TestBrakeSwitch()
{
	unsigned char result = *pBrakeFlags & BrakeBitMask;
	if(result == BrakeBitMask)
		return 0x01;
	else
		return 0x00;
}

unsigned char TestCruiseMasterSwitch()
{
	unsigned char result = *pCruiseMasterFlags & CruiseMasterBitMask;
	if(result == CruiseMasterBitMask)
		return 0x01;
	else
		return 0x00;
}

#ifdef pClutchFlags
unsigned char TestClutchSwitch()
{
	unsigned char result = *pClutchFlags & ClutchBitMask;
	if(result == ClutchBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pResumeFlags
unsigned char TestCruiseResumeSwitch()
{
	unsigned char result = *pResumeFlags & ResumeBitMask;
	if(result == ResumeBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pCoastFlags
unsigned char TestCruiseCoastSwitch()
{
	unsigned char result = *pCoastFlags & CoastBitMask;
	if(result == CoastBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pDefoggerFlags
unsigned char TestDefoggerSwitch()
{
	unsigned char result = *pDefoggerFlags & DefoggerBitMask;
	if(result == DefoggerBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pNeutralFlags
unsigned char TestNeutralSwitch()
{
	unsigned char result = *pNeutralFlags & NeutralBitMask;
	if(result == NeutralBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pIdleFlags
unsigned char TestIdleSwitch()
{
	unsigned char result = *pIdleFlags & IdleBitMask;
	if(result == IdleBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif



void TestCruiseControlToggles()
{
	unsigned char resume = TestCruiseResumeSwitch();
	unsigned char coast = TestCruiseCoastSwitch();
	
	unsigned char Idle = TestIdleSwitch();
	unsigned char Neutral = TestNeutralSwitch();
	unsigned char Defogger = TestDefoggerSwitch();
	
	if(pRamVariables->CruiseResumeLast != resume
	&& pRamVariables->CruiseCoastLast != coast)
	{
		if(resume != 0 && coast != 0)
		{
			//Cruise lever was pulled backwards
			int i = 0;
		} 
	}
	else if(pRamVariables->CruiseResumeLast != resume)
	{
		if(resume != 0)
		{
			#if PROG_MODE
			ProgModeCruiseToggled(ToggleResume);
			#endif
			#if LC_ADJUST
			LCAdjustCruiseToggled(ToggleResume);
			#endif
		}
	}
	else if(pRamVariables->CruiseCoastLast != coast)
	{
		if(coast != 0)
		{
			#if PROG_MODE
			ProgModeCruiseToggled(ToggleCoast);
			#endif
			#if LC_ADJUST
			LCAdjustCruiseToggled(ToggleCoast);
			#endif
		}
	}
	pRamVariables->CruiseCoastLast = coast;
	pRamVariables->CruiseResumeLast = resume;
	pRamVariables->IdleLast = Idle;
	pRamVariables->NeutralLast = Neutral;
	pRamVariables->DefoggerLast = Defogger;
}