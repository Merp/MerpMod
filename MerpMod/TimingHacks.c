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

#if TIMING_HACKS


extern void** TimingBlendGroup;
extern void** KnockCorrectionRetardBlendGroup;

void (*BaseTimingHooked)() __attribute__ ((section ("RomHole_Functions"))) = (void(*)()) sBaseTiming;

float TimingHack()
{
	float OutputValue;
	
	float subIam;
	float iam;

	subIam = HighPass(1 - IAM, 0.0f);
	
	pRamVariables.MaxSubtractiveKCA = HighPass(BlendAndSwitch(KnockCorrectionRetardTableGroup, *pEngineLoad, *pEngineSpeed),0.0f);
	
	pRamVariables.SubtractiveKCA = subIam *  pRamVariables.MaxSubtractiveKCA;
	
#if TIMING_RAM_TUNING
	if(pRamVariables.WGDCMaxRamFlag = 0x01)
	{
		OutputValue = Pull3DHooked(&TimingRamTable, *pEngineLoad, *pEngineSpeed);
	}
	else
	{
#endif

	OutputValue = BlendAndSwitch(TimingTableGroup, *pEngineLoad, *pEngineSpeed);
	pRamVariables.BaseTiming = OutputValue;
		
#if TIMING_RAM_TUNING
	}
#endif

	if(pRamVariables.LCTimingMode == LCTimingModeLocked && pRamVariables.LCEngaged == 1)
	{
		OutputValue = pRamVariables.LCTimingLock;
	}
	else if(pRamVariables.LCTimingMode == LCTimingModeCompensated)
	{
		pRamVariables.LCTimingRetard = HighPass(Pull3DHooked(&LCTimingRetardTable, *pVehicleSpeed, *pEngineSpeed),0.0f);
	
		pRamVariables.LCTimingRetard *= pRamVariables.LCTimingRetardMultiplier;
		
		OutputValue -= HighPass(pRamVariables.LCTimingRetard,0.0f);
	}

	OutputValue -= Abs(pRamVariables.SubtractiveKCA);
	
	pRamVariables.FinalTiming = OutputValue;
	
	if(pRamVariables.TimingHackEnabled == HackEnabled)
		pRamVariables.TimingOutput = OutputValue;
	else
		pRamVariables.TimingOutput = Pull3DHooked((void*)PrimaryOEMTimingTable, *pEngineLoad, *pEngineSpeed);	
		
	//Call existing!
	BaseTimingHooked();

}

#endif