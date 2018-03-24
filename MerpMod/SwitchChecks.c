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

#ifdef pTestModeFlags
unsigned char TestTestModeSwitch()
{
	unsigned char result = *pTestModeFlags & TestModeBitMask;
	if(result == TestModeBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pDefogFlags
unsigned char TestDefogSwitch()
{
	unsigned char result = *pDefogFlags & DefogBitMask;
	if(result == DefogBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

#ifdef pBrakeFlags
unsigned char TestBrakeSwitch()
{
	unsigned char result = *pBrakeFlags & BrakeBitMask;
	if(result == BrakeBitMask)
		return 0x01;
	else
		return 0x00;
}
#endif

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

#if defined(pCoastFlags) && defined(pResumeFlags)
void TestCruiseControlToggles()
{
	unsigned char resume = TestCruiseResumeSwitch();
	unsigned char coast = TestCruiseCoastSwitch();
	
	if(pRamVariables.CruiseResumeLast != resume
	&& pRamVariables.CruiseCoastLast != coast)
	{
		if(resume != 0 && coast != 0)
		{
			//Cruise lever was pulled backwards
			int i = 0;
		} 
	}
	else if(pRamVariables.CruiseResumeLast != resume)
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
	else if(pRamVariables.CruiseCoastLast != coast)
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
	pRamVariables.CruiseCoastLast = coast;
	pRamVariables.CruiseResumeLast = resume;
}

#endif