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
	if(pRamVariables->CelFlashStatus == 0)
	{
		if(pRamVariables->CelRepeatSwitch != 0)
			CelFlashStart(*CelFlashes1,Speed1,Delay1,0);
		else
			CelFlashStart(*CelFlashes2,Speed2,Delay2,0);
		pRamVariables->CelRepeatSwitch ^= 1;
	}
}

void CelFlashStart(unsigned char CelFlashes, unsigned char Speed, unsigned char Delay, unsigned char Interrupt)
{	
	// If no flashes exist OR interrupt is sent
	if(pRamVariables->CelFlashStatus == 0 || Interrupt == 1)
	{
		// No current flashes or interrupt is running, go ahead and set parameters
		pRamVariables->CelFlashDelay = Delay;
		pRamVariables->CelFlashSpeed = Speed;
		pRamVariables->CelFlashSpeedCounter = Speed;
		if(CelFlashes != 0)
		{
			pRamVariables->CelFlashCount = ((CelFlashes * 2)-1);
			pRamVariables->CelFlashCounter = ((CelFlashes * 2)-1);
			pRamVariables->CelSignal = *pCelSignalOem ^ 1;
			pRamVariables->CelFlashStatus = 1;
		}
	}
}
	
void CelFlash()
{	
	// Check for existing flash call
	if(pRamVariables->CelFlashCounter > 0)
	{
		if(pRamVariables->CelFlashSpeedCounter == 0)
		{			
			// If cel flashes remain and speed counter hits zero
			// Reset speed counter, decrement flash counter, Invert Signal
			pRamVariables->CelFlashSpeedCounter = pRamVariables->CelFlashSpeed;						
			pRamVariables->CelSignal ^= 1;
			(pRamVariables->CelFlashCounter)--;
		}
		else
		{
			(pRamVariables->CelFlashSpeedCounter)--;
		}
	}
	else if(pRamVariables->CelFlashDelay > 0)
	{
		(pRamVariables->CelFlashDelay)--;
		//TODO UPDATE UNIT TEST THIS SHIT!!
	}
	else
	{
		//Copy existing signal if not flashing!
		pRamVariables->CelSignal = *pCelSignalOem;
		pRamVariables->CelFlashStatus = 0;
	}
	
	//TODO HACK CRUISE LIGHT!!!!!
	// Check for existing flash call
	//if(*pCruiseFlashCounter > 0)
	//{
	//	if(*pCruiseSpeedCounter == 0)
	//	{			
	//		// If ccruise flashes remain and speed counter hits zero
	//		// Reset speed counter, decrement flash counter, Invert Signal and call Trigger
	//		pRamVariables->CelSpeedCounter == pRamVariables->FlashSpeed;						
	//		pRamVariables->CelSignal = pRamVariables->CelSignal ^ 1;
	//		(pRamVariables->CelFlashCounter)--;
	//	}
	//	else
	//	{
	//		(*pCruiseSpeedCounter)--;
	//	}
	//}
	
#if ALS_HACKS

	unsigned char ShiftMode = pRamVariables->DriveMode;
	unsigned char ALSModeFlashes = pRamVariables->DriveMode;
	unsigned char MapRatioFlashes = (pRamVariables->FlexFuelRatio * 10);
	
		if(*pCurrentGear >= 1)
		{
		pRamVariables->ShiftLightRPM = Pull3DHooked(&ShiftLightRPMs,*pCurrentGear, ShiftMode);
		}
		else
		{
		pRamVariables->ShiftLightRPM = DefaultShiftLightRPM;
		}
#endif

/*
#if DASHBOARD_CEL

	unsigned char FirstFlash;
	unsigned char SecondFlash;
	unsigned char ThirdFlash;
	unsigned char FourthFlash;

	if (entry conditions)
	{
		CelFlashStart(FirstFlash,FirstFlashSpeed,0,0); DELAY!!!!
		CelFlashStart(SecondFlash,SecondFlashSpeed,0,0); DELAY!!!!
		CelFlashStart(ThirdFlash,ThirdFlashSpeed,0,0); DELAY!!!!
		CelFlashStart(FourthFlash,FourthFlashSpeed,0,0); LONG DELAY!!!!
	}
*/

////////////////////////////////
//KNOCK LIGHT CODE w/ IAM RECALL
////////////////////////////////

	if(*pFBKC <= FBKCHiThreshold && *pEngineLoad > FBKCLoadThreshold)
	{
		CelFlashStart(FBKCHiFlashes,FBKCHiFlashSpeed,0,0);
	}
	else if(*pFBKC <= FBKCLoThreshold && *pEngineLoad > FBKCLoadThreshold)
	{
		CelFlashStart(FBKCLoFlashes,FBKCLoFlashSpeed,0,0);
	}

#if SHIFTLIGHT_HACKS
	else if(*pEngineSpeed >= pRamVariables->ShiftLightRPM && ShiftLightEnabled == HackEnabled)
	{
		CelFlashStart(ShiftLightFlashes,ShiftLightFlashSpeed,0,0);
	}
#endif

#if ALS_HACKS
	else if(pRamVariables->ALSModeWait == 1)
	{
		CelFlashStart(ALSModeFlashes,ALSModeFlashSpeed,0,0);
	}
	else if(pRamVariables->KillMode >= 2)
	{
		CelFlashStart(KillModeFlashes,KillModeFlashSpeed,0,0);
	}
/*	else if(pRamVariables->FuelUp == 1)
	{
		CelFlashStart(FlexLearnFlashes,FlexLearnFlashSpeed,8,0);
	}
	else if(pRamVariables->FlexLearnHasRun == 1)
	{
		CelFlashStart(MapRatioFlashes,ALSModeFlashSpeed,0,0);
		pRamVariables->FlexLearnHasRun = 0x00;
	}
*/
#endif


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
	// Call triggers if signal changes!
	if(pRamVariables->CelSignal != pRamVariables->CelSignalLast)
	{
		CelTrigger();
	}
	if(IAM < IAMFlashThreshold)
	{
		CelFlashStart(IAMFlashes,IAMFlashSpeed,64,0);
	}
	
	//if(*pCruiseSignal != *pCruiseSignalLast)
	//{
	//	CruiseTrigger();
	//}
	
	// Copy OEM cel trigger & cruise trigger
	pRamVariables->CelSignalLast = pRamVariables->CelSignal;
	//*pCruiseSignalLast = *pCruiseSignal;

}

//TODO put this somewhere else and PROTOTYPE
/*
void WideBandLambdaInput(float * Input)
{
	//scale
	pRamVariables->WideBandLambda = Pull2DFloat(&WideBandScaling//createthis,Input);
	
	if(pRamVariables->WideBandLambda < pRamVariables->LeanBoostThreshold)
	{
		if(pRamVariables->LeanBoostDelay == 0)
			pRamVariables->LeanBoostSwitch = 1;
		else
			pRamVariables->LeanBoostDelay--;
	}
	else
	{
		pRamVariables->LeanBoostSwitch = 0;
		pRamVariables->LeanBoostDelay = LeanBoostFlashDelay;
	}
}
*/

#endif