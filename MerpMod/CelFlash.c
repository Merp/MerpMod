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

#if CEL_HACKS
//void CelFlashStart(unsigned char CelFlashes, unsigned char CruiseFlashes, unsigned char Speed, unsigned char Interrupt)  __attribute__ ((section ("RomHole_Code")));

float (*CelTrigger)() __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sCelTrigger;

void CelDoubleRepeat(unsigned char * CelFlashes1, unsigned char Speed1, unsigned char * CelFlashes2, unsigned char Speed2, unsigned char Delay1, unsigned char Delay2)
{
	if(pRamVariables.CelFlashStatus == 0)
	{
		if(pRamVariables.CelRepeatSwitch != 0)
			CelFlashStart(*CelFlashes1,Speed1,Delay1,0);
		else
			CelFlashStart(*CelFlashes2,Speed2,Delay2,0);
		pRamVariables.CelRepeatSwitch ^= 1;
	}
}

void CelFlashStart(unsigned char CelFlashes, unsigned char Speed, unsigned char Delay, unsigned char Interrupt)
{	
	// If no flashes exist OR interrupt is sent
	if(pRamVariables.CelFlashStatus == 0 || Interrupt == 1)
	{
		// No current flashes or interrupt is running, go ahead and set parameters
		pRamVariables.CelFlashDelay = Delay;
		pRamVariables.CelFlashSpeed = Speed;
		pRamVariables.CelFlashSpeedCounter = Speed;
		if(CelFlashes != 0)
		{
			pRamVariables.CelFlashCount = ((CelFlashes * 2)-1);
			pRamVariables.CelFlashCounter = ((CelFlashes * 2)-1);
			pRamVariables.CelSignal = *pCelSignalOem ^ 1;
			pRamVariables.CelFlashStatus = 1;
		}
	}
}
	
void CelFlash()
{	
	// Check for existing flash call
	if(pRamVariables.CelFlashCounter > 0)
	{
		if(pRamVariables.CelFlashSpeedCounter == 0)
		{			
			// If cel flashes remain and speed counter hits zero
			// Reset speed counter, decrement flash counter, Invert Signal
			pRamVariables.CelFlashSpeedCounter = pRamVariables.CelFlashSpeed;						
			pRamVariables.CelSignal ^= 1;
			(pRamVariables.CelFlashCounter)--;
		}
		else
		{
			(pRamVariables.CelFlashSpeedCounter)--;
		}
	}
	else if(pRamVariables.CelFlashDelay > 0)
	{
		(pRamVariables.CelFlashDelay)--;
		//TODO UPDATE UNIT TEST THIS SHIT!!
	}
	else
	{
		//Copy existing signal if not flashing!
		pRamVariables.CelSignal = *pCelSignalOem;
		pRamVariables.CelFlashStatus = 0;
	}
	
	//TODO HACK CRUISE LIGHT!!!!!
	// Check for existing flash call
	//if(*pCreuiseFlashCounter > 0)
	//{
	//	if(*pCruiseSpeedCounter == 0)
	//	{			
	//		// If ccruise flashes remain and speed counter hits zero
	//		// Reset speed counter, decrement flash counter, Invert Signal and call Trigger
	//		pRamVariables.CelSpeedCounter == pRamVariables.FlashSpeed;						
	//		pRamVariables.CelSignal = pRamVariables.CelSignal ^ 1;
	//		(pRamVariables.CelFlashCounter)--;
	//	}
	//	else
	//	{
	//		(*pCruiseSpeedCounter)--;
	//	}
	//}
	

////////////////////////////////
//KNOCK LIGHT CODE w/ IAM RECALL
////////////////////////////////
#if PROG_MODE
//Disable flashes during programming mode
if(pRamVariables.ProgModeStatus == ProgModeEnabled)
{
#endif
	if(*pFBKC <= FBKCHiThreshold && *pEngineLoad > FBKCLoadThreshold)
	{
		CelFlashStart(FBKCHiFlashes,FBKCHiFlashSpeed,0,0);
	}
	else if(*pFBKC <= FBKCLoThreshold && *pEngineLoad > FBKCLoadThreshold)
	{
		CelFlashStart(FBKCLoFlashes,FBKCLoFlashSpeed,0,0);
	}
#if !defined(NOAF1RES)
	else if(*pAf1Res < EGTResistanceThreshold && *pEngineLoad > EGTCelLoadThreshold)
	{
		CelFlashStart(EGTFlashes,EGTFlashSpeed,0,0);
	}
#endif
	else if (*pCoolantTemp > ECTFlashThreshold)
	{
		CelFlashStart(ECTFlashes,ECTFlashSpeed,64,0);
	}
	else if(IAM < IAMFlashThreshold)
	{
		CelFlashStart(IAMFlashes,IAMFlashSpeed,64,0);
	}
#if PROG_MODE
}
#endif
	
	// Call triggers if signal changes!
	if(pRamVariables.CelSignal != pRamVariables.CelSignalLast)
	{
		CelTrigger();
	}
	
	
	//if(*pCruiseSignal != *pCruiseSignalLast)
	//{
	//	CruiseTrigger();
	//}
	
	// Copy OEM cel trigger & cruise trigger
	pRamVariables.CelSignalLast = pRamVariables.CelSignal;
	//*pCruiseSignalLast = *pCruiseSignal;

}

//TODO put this somewhere else and PROTOTYPE
/*
void WideBandLambdaInput(float * Input)
{
	//scale
	pRamVariables.WideBandLambda = Pull2DFloat(&WideBandScaling//createthis,Input);
	
	if(pRamVariables.WideBandLambda < pRamVariables.LeanBoostThreshold)
	{
		if(pRamVariables.LeanBoostDelay == 0)
			pRamVariables.LeanBoostSwitch = 1;
		else
			pRamVariables.LeanBoostDelay--;
	}
	else
	{
		pRamVariables.LeanBoostSwitch = 0;
		pRamVariables.LeanBoostDelay = LeanBoostFlashDelay;
	}
}
*/

#endif