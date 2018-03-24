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

#if PROG_MODE

void ProgModeMapSwitch(unsigned char toggleType)  ROMCODE;
void ProgModeBlendModeAdjust(unsigned char toggleType)	ROMCODE;
void ProgModeBlendAdjust(unsigned char toggleType)  ROMCODE;
void ProgModeLCAdjust(unsigned char toggleType)  ROMCODE;
void ProgModeIAMAdjust(unsigned char toggleType) ROMCODE;
void ProgModeValetMode(unsigned char toggleType) ROMCODE;
void ProgModeHardReset(unsigned char toggleType) ROMCODE;
void ProgModeAdjust(unsigned char toggleType) ROMCODE;

// Constants need to be declared as 'extern' with their values defined in the 
// function body or in an external asm file.  This is a convoluted way to 
// declare and define variables, but the standard approach causes the compiler
// to generate references to addresses in another segment, which makes it 
// harder to stitch this code into the ECU code.  
// 
// I suspect that turning on compiler optimizations might might cause the 
// compiler to generate the sort of code we want for constants and RAM 
// variables, however other optimizations also make the code harder to verify
// when stepping through it one instruction at a time.  For now I'd much 
// rather have code that's very easy to verify (and verify with the highest
// possible confidence), but at some point it might be worthwhile to turn on
// optimizations and see what happens.

// This is the function that will use speed-density math to compute the MAF
// value that will be returned to the rest of the ECU.  The function needs to
// be declared with the section attribute before it is actually defined, in 
// order to tell the compiler and linker which segment (address range) to put
// it in.

// ProgModeMain function
// This is hooked on a fixed timer that runs all the time immediately after powering up the car
//
/*

	Menu Items:
	//TODO IMPLEMENT VALET MODE FIRST!1: Valet Mode Select
	2: Map Switching
	3: Map Blending
	4: LC Adjust
	//TODO9: ECU Reset
	//TODO: Injector hack

	//LOW PRIORITY STUFF
	6: LC Timing Retard Adjust
	8: SD Mode Select

	*/


#define PROG_MODE_COUNT 7
#define PROG_THROTTLE_HI 80.0f
#define PROG_THROTTLE_LO 10.0f

#define VALUE_FLASH_SPEED 2
#define VALUE_FLASH_DELAY 32
#define MODE_FLASH_SPEED 6
#define MODE_FLASH_DELAY 16

#define BLEND_MAX 1.0f
#define BLEND_MIN 0.0f
#define BLEND_STEP 0.1f

#define LC_MIN 2000.0f
#define LC_STEP 500.0f

#define IAM_MIN 0
#ifdef pIAM4
#define IAM_MAX 1.0f
#define IAM_STEP 0.1
#else
#define IAM_MAX 1
#define IAM_STEP 0.1
#endif

void ProgModeListener()
{
	//Check for prog mode disable (entered OEM test mode)
	if(pRamVariables.ProgModeStatus != ProgModeDisabled)
	{
		if(pRamVariables.ProgModeStatus == ProgModeEnabled)
		{
			//Check for entry conditions, enter mode selection if met
			if(TestTestModeSwitch())
			{	
				pRamVariables.ProgModeStatus = ProgModeSelectMode;
			}
		}
		else
		{
			//Check for exit conditions, run main if met.
			if(!TestTestModeSwitch())
			{
				pRamVariables.ProgModeStatus = ProgModeEnabled;
			}
			else
			{
				ProgModeMain();
			}
		}
	}
}

void ProgModeCruiseToggled(unsigned char toggleType)
{
	switch(toggleType)
	{
		case(ToggleResume):
			if(pRamVariables.ProgModeStatus == ProgModeSelectMode)
			{
				if(pRamVariables.ProgModeCurrentMode >= PROG_MODE_COUNT)
					pRamVariables.ProgModeCurrentMode = 1;
				else
					pRamVariables.ProgModeCurrentMode++;
			}
			else if(pRamVariables.ProgModeStatus == ProgModeAdjustValue)
			{
				ProgModeAdjust(toggleType);
			}
			break;
		
		case(ToggleCoast):		
			if(pRamVariables.ProgModeStatus == ProgModeSelectMode)
			{
				if(pRamVariables.ProgModeCurrentMode <= 1)
					pRamVariables.ProgModeCurrentMode = PROG_MODE_COUNT;
				else
					pRamVariables.ProgModeCurrentMode--;
			}
			else if(pRamVariables.ProgModeStatus == ProgModeAdjustValue)
			{
				ProgModeAdjust(toggleType);
			}
			break;
		
		default:
		break;
	}
}

void ProgModeMain()
{
	ProgModeAdjust(ToggleInit);
	if(TestDefogSwitch())
	{
		pRamVariables.ProgModeStatus = ProgModeAdjustValue;
	}
	else
	{
		pRamVariables.ProgModeStatus = ProgModeSelectMode;
	}
	
	if(pRamVariables.ProgModeStatus == ProgModeSelectMode)
	{
		CelFlashStart(pRamVariables.ProgModeCurrentMode, MODE_FLASH_SPEED, MODE_FLASH_DELAY,0);
	}
	if(pRamVariables.ProgModeStatus == ProgModeAdjustValue)
	{
		CelFlashStart(pRamVariables.ProgModeValueFlashes, VALUE_FLASH_SPEED, VALUE_FLASH_DELAY,0);
	}
}
		
void ProgModeAdjust(unsigned char toggleType)
{
	switch(pRamVariables.ProgModeCurrentMode)
	{
		case 1:
		ProgModeMapSwitch(toggleType);
		break;
		
		case 2:
		ProgModeBlendModeAdjust(toggleType);
		break;
		
		case 3:
		ProgModeBlendAdjust(toggleType);
		break;
		
		case 4:
		ProgModeLCAdjust(toggleType);
		break;
		
		case 5:
		ProgModeIAMAdjust(toggleType);
		break;
		
		case 6://Put this in ENUM if you want to reorder them easily
		ProgModeValetMode(toggleType);
		break;
		
		case 7:
		ProgModeHardReset(toggleType);
		break;
		
		default:
		pRamVariables.ProgModeCurrentMode = 1;
		break;
	}	
}

void ProgModeMapSwitch(unsigned char toggleType)
{
	if(pRamVariables.MapSwitchingInputMode == MapSwitchingInputModeUndefined)
	{	
		if(toggleType == ToggleResume)
		{	
			if(pRamVariables.MapSwitch >= 3)
				asm("nop");//pRamVariables.MapSwitch = 1;
			else
				pRamVariables.MapSwitch++;
		}
		else if(toggleType == ToggleCoast)
		{
			if(pRamVariables.MapSwitch == 1 )
				asm("nop");//pRamVariables.MapSwitch = 3;
			else
				pRamVariables.MapSwitch--;
		}
	}
	pRamVariables.ProgModeValue = pRamVariables.MapSwitch;
	pRamVariables.ProgModeValueFlashes = pRamVariables.MapSwitch;
}

void ProgModeBlendModeAdjust(unsigned char toggleType)
{
	if(toggleType == ToggleResume)
	{
		if(pRamVariables.MapBlendingInputMode < 2)
			pRamVariables.MapBlendingInputMode++;
	}
	else if(toggleType == ToggleCoast)
	{
		if(pRamVariables.MapBlendingInputMode > 0)
			pRamVariables.MapBlendingInputMode--;
	}
	
	pRamVariables.ProgModeValue = pRamVariables.MapBlendingInputMode;
	pRamVariables.ProgModeValueFlashes = pRamVariables.MapBlendingInputMode;
}

void ProgModeBlendAdjust(unsigned char toggleType)
{
	if(pRamVariables.MapBlendingInputMode == MapBlendingInputModeUndefined)
	{
		if(toggleType == ToggleResume)
		{	
			if(pRamVariables.MapBlendRatio > (BLEND_MAX - BLEND_STEP - BLEND_STEP))
				pRamVariables.MapBlendRatio = BLEND_MAX;
			else
				pRamVariables.MapBlendRatio += BLEND_STEP;
		}
		else if(toggleType == ToggleCoast)
		{
			if(pRamVariables.MapBlendRatio < (BLEND_MIN + BLEND_STEP + BLEND_STEP))
				pRamVariables.MapBlendRatio = BLEND_MIN;//Hard limit, does not cycle to top again.
			else
				pRamVariables.MapBlendRatio -= BLEND_STEP;
		}
	}
	pRamVariables.ProgModeValue = pRamVariables.MapBlendRatio + 1;
	pRamVariables.ProgModeValueFlashes = (unsigned char)(pRamVariables.MapBlendRatio*10);
}

void ProgModeLCAdjust(unsigned char toggleType)
{
	#if !AUTO_TRANS
	if(toggleType == ToggleResume)
	{	
		pRamVariables.LaunchControlCut++;
		if(pRamVariables.LaunchControlCut < pRamVariables.RedLineCut)
			pRamVariables.LaunchControlCut+= LC_STEP;
	}
	else if(toggleType == ToggleCoast)
	{
		if(pRamVariables.LaunchControlCut > LC_MIN)
			pRamVariables.LaunchControlCut-= LC_STEP;//Hard limit, does not cycle to top again.
		else
			pRamVariables.LaunchControlCut = LC_MIN;
	}
	
	pRamVariables.ProgModeValue = pRamVariables.LaunchControlCut;
	pRamVariables.ProgModeValueFlashes = (unsigned char)(pRamVariables.LaunchControlCut / 1000);
	#else
	pRamVariables.ProgModeValue = 0.0f;
	pRamVariables.ProgModeValueFlashes = 0;
	#endif
}

void ProgModeIAMAdjust(unsigned char toggleType)
{
	if(toggleType == ToggleResume)
	{	
		if(*pIAM < IAM_MAX - IAM_STEP)
			*pIAM += IAM_STEP;
		else
			*pIAM = IAM_MAX;
	}
	else if(toggleType == ToggleCoast)
	{
		if(IAM > IAM_MIN + IAM_STEP)
			*pIAM -= IAM_STEP;
		else
			*pIAM = IAM_MIN;
	}
	pRamVariables.ProgModeValue = *pIAM;
	pRamVariables.ProgModeValueFlashes = (10*(IAM))+1;
}

void ProgModeValetMode(unsigned char toggleType)
{
	if(toggleType == ToggleResume)
	{	
		if(pRamVariables.ValetMode <=0)
			pRamVariables.ValetMode = ValetModeEnabled;
	}
	else if(toggleType == ToggleCoast)
	{
		if(pRamVariables.ValetMode >= 1 )
			pRamVariables.ValetMode = ValetModeDisabled;
	}
	pRamVariables.ProgModeValue = pRamVariables.ValetMode;
	pRamVariables.ProgModeValueFlashes = pRamVariables.ValetMode;
	
}

void ProgModeHardReset(unsigned char toggleType)
{
	if(toggleType == ToggleResume)
	{	
		if(pRamVariables.HardResetFlag <=0)
		{
			pRamVariables.HardResetFlag = HardResetFlagEnabled;
			*pSSMResetByte = 0x40;
		}
		
	}
	else if(toggleType == ToggleCoast)
	{
		if(pRamVariables.HardResetFlag >= 1 )
		{
			pRamVariables.HardResetFlag = HardResetFlagDisabled;
			*pSSMResetByte = 0x40;
		}
	}
	pRamVariables.ProgModeValue = pRamVariables.HardResetFlag;
	pRamVariables.ProgModeValueFlashes = pRamVariables.HardResetFlag;
}

#endif