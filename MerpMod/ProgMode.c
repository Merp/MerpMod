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


#define PROG_MODE_COUNT 4
#define PROG_THROTTLE_HI 80.0f
#define PROG_THROTTLE_LO 10.0f

#define VALUE_FLASH_SPEED 2
#define VALUE_FLASH_DELAY 32
#define MODE_FLASH_SPEED 4
#define MODE_FLASH_DELAY 16

#define BLEND_MAX 1.0f
#define BLEND_MIN 0.0f
#define BLEND_STEP 0.1f
#define BLEND_WAIT 32

#define LC_MIN 2000.0f
#define LC_STEP 500.0f
#define LC_WAIT 32

#define IAM_MIN 0
#ifdef pIAM4
#define IAM_MAX 1.0f
#define IAM_STEP 0.1
#else
#define IAM_MAX 16
#define IAM_STEP 1
#endif
#define IAM_WAIT 32

void ProgModeListener()
{
	if(pRamVariables->ProgModeEnable == 1)
	{
		//CHECK FOR EXIT CONDITIONS THEN RUN
		if(TestClutchSwitch() || *pEngineSpeed > 10)
		{
			ExitProgMode();
		}
		else
		{
			ProgModeMain();
		}
	}
	else
	{
		//CHECK FOR ENTRY CONDITIONS
		if(*pEngineSpeed < 10 && !TestClutchSwitch())
		{
			if (pRamVariables->ProgModeTimer > 0)
				pRamVariables->ProgModeTimer--;

			if (pRamVariables->ProgModeEntry < 1)
			{
				if(TestBrakeSwitch())
				{
					pRamVariables->ProgModeEntry = 1;
					pRamVariables->ProgModeTimer = 0xFF;
				}
			}
		
			if (pRamVariables->ProgModeEntry == 1)
			{
				if(!TestBrakeSwitch())
				{
					pRamVariables->ProgModeEntry = 2;
				}
			}
		
			if (pRamVariables->ProgModeEntry > 1)
			{
				if((pRamVariables->ProgModeEntry/2)*2 == pRamVariables->ProgModeEntry)
				{
					if(*pThrottlePlate > PROG_THROTTLE_HI)
					{
						pRamVariables->ProgModeEntry++;
					}
				}
				else if(*pThrottlePlate < PROG_THROTTLE_LO)
				{
					pRamVariables->ProgModeEntry++;
				}
			}
		
			if(pRamVariables->ProgModeEntry > 7)
			{
				EnterProgMode();
				return;
			}
		}
	}
}

void EnterProgMode()
{
	pRamVariables->ProgModeEnable = 1;
	pRamVariables->ProgModeWait = 248;
	pRamVariables->ProgModeEntry = 0;
}

void ExitProgMode()
{
	pRamVariables->ProgModeEnable = 0;
}

void ProgModeCruiseToggled(unsigned char toggleType)
{
	switch(toggleType)
	{
		case(ToggleResume):
			if(pRamVariables->ProgModeEnable)
			{
				if(pRamVariables->ProgModeCurrentMode >= PROG_MODE_COUNT)
					pRamVariables->ProgModeCurrentMode = 1;
				else
					pRamVariables->ProgModeCurrentMode++;
			}
			break;
		
		case(ToggleCoast):		
			if(pRamVariables->ProgModeEnable)
			{
				if(pRamVariables->ProgModeCurrentMode <= 1)
					pRamVariables->ProgModeCurrentMode = PROG_MODE_COUNT;
				else
					pRamVariables->ProgModeCurrentMode--;
			}
			break;
		
		default:
		break;
	}
}

void ProgModeMain()
{
	switch(pRamVariables->ProgModeCurrentMode)
	{
		case 1:
		ProgModeMapSwitch();
		break;
		
		case 2:
		ProgModeBlendAdjust();
		break;
		
		case 3:
		ProgModeLCAdjust();
		break;
		
		case 4:
		ProgModeIAMAdjust();
		break;
		
		case 5://Put this in ENUM if you want to reorder them easily
		ProgModeValetMode();
		break;
		
		default:
		pRamVariables->ProgModeCurrentMode = 1;
		break;
	}	
	CelDoubleRepeat(&pRamVariables->ProgModeCurrentMode,MODE_FLASH_SPEED,&pRamVariables->ProgModeValueFlashes,VALUE_FLASH_SPEED,MODE_FLASH_DELAY,VALUE_FLASH_DELAY);//TODO abstract
}

void ProgModeMapSwitch()
{
	if(MapSwitchInput == InputModeUndefined)
	{	
		if((*pThrottlePlate > PROG_THROTTLE_HI) && pRamVariables->ProgModeWait == 0)
		{	
			if(pRamVariables->MapSwitch >= 3)
				asm("nop");//pRamVariables->MapSwitch = 1;
			else
				pRamVariables->MapSwitch++;
		
			pRamVariables->ProgModeWait = 1;
		}
		else if(TestBrakeSwitch() && pRamVariables->ProgModeWait ==0)
		{
			if(pRamVariables->MapSwitch == 1 )
				asm("nop");//pRamVariables->MapSwitch = 3;
			else
				pRamVariables->MapSwitch--;
				
			pRamVariables->ProgModeWait = 1;
		}
		else
		{
			if(pRamVariables->ProgModeWait != 0 && (*pThrottlePlate < PROG_THROTTLE_LO) && (*pBrakeFlags & BrakeBitMask) == 0)
				pRamVariables->ProgModeWait--;
		}
	}
	pRamVariables->ProgModeValue = pRamVariables->MapSwitch;
	pRamVariables->ProgModeValueFlashes = pRamVariables->MapSwitch;
}

void ProgModeBlendAdjust()
{
	if(BlendRatioInput == InputModeUndefined)
	{
		if((*pThrottlePlate > PROG_THROTTLE_HI) && pRamVariables->ProgModeWait == 0)
		{	
			if(pRamVariables->MapBlendRatio > (BLEND_MAX - BLEND_STEP - 0.01f))
				pRamVariables->MapBlendRatio = BLEND_MAX;
			else
				pRamVariables->MapBlendRatio+= BLEND_STEP;
		
			pRamVariables->ProgModeWait = BLEND_WAIT;
		}
		else if(TestBrakeSwitch() && pRamVariables->ProgModeWait ==0)
		{
			if(pRamVariables->MapBlendRatio < (BLEND_MIN + BLEND_STEP + 0.01f))
				pRamVariables->MapBlendRatio = BLEND_MIN;//Hard limit, does not cycle to top again.
			else
				pRamVariables->MapBlendRatio-= BLEND_STEP;
			pRamVariables->ProgModeWait = BLEND_WAIT;
		}
		else
		{
			if(pRamVariables->ProgModeWait != 0)
				pRamVariables->ProgModeWait--;
		}
	}
	pRamVariables->ProgModeValue = pRamVariables->MapBlendRatio + 1;
	pRamVariables->ProgModeValueFlashes = (unsigned char)(pRamVariables->MapBlendRatio*10);
}

void ProgModeLCAdjust()
{
	#if !AUTO_TRANS
	if((*pThrottlePlate > 50) && pRamVariables->ProgModeWait == 0)
	{	
		pRamVariables->LaunchControlCut++;
		if(pRamVariables->LaunchControlCut < pRamVariables->RedLineCut)
			pRamVariables->LaunchControlCut+= LC_STEP;
		pRamVariables->ProgModeWait = LC_WAIT;
	}
	else if(TestBrakeSwitch() && pRamVariables->ProgModeWait ==0)
	{
		if(pRamVariables->LaunchControlCut > LC_MIN)
			pRamVariables->LaunchControlCut-= LC_STEP;//Hard limit, does not cycle to top again.
		else
			pRamVariables->LaunchControlCut = LC_MIN;
		pRamVariables->ProgModeWait = LC_WAIT;
	}
	else
	{
		if(pRamVariables->ProgModeWait != 0)
		pRamVariables->ProgModeWait--;
	}
	
	pRamVariables->ProgModeValue = pRamVariables->LaunchControlCut;
	pRamVariables->ProgModeValueFlashes = (unsigned char)(pRamVariables->LaunchControlCut / 1000);
	#else
	pRamVariables->ProgModeValue = 0.0f;
	pRamVariables->ProgModeValueFlashes = 0;
	#endif
}

void ProgModeIAMAdjust()
{
	if((*pThrottlePlate > PROG_THROTTLE_HI) && pRamVariables->ProgModeWait == 0)
	{	
		if(*pIAM < IAM_MAX - IAM_STEP)
			*pIAM += IAM_STEP;
		else
			*pIAM = IAM_MAX;
		pRamVariables->ProgModeWait = IAM_WAIT;
	}
	else if(TestBrakeSwitch() && pRamVariables->ProgModeWait ==0)
	{
		if(IAM > IAM_MIN + IAM_STEP)
			*pIAM -= IAM_STEP;
		else
			*pIAM = IAM_MIN;
		pRamVariables->ProgModeWait = IAM_WAIT;
	}
	else
	{
		if(pRamVariables->ProgModeWait != 0)
			pRamVariables->ProgModeWait--;
	}
	pRamVariables->ProgModeValue = *pIAM;
	pRamVariables->ProgModeValueFlashes = (10*(1-IAM))+1;
}

void ProgModeValetMode()
{
	if((*pThrottlePlate > PROG_THROTTLE_HI) && pRamVariables->ProgModeWait == 0)
	{	
		if(pRamVariables->ValetMode <=0)
			pRamVariables->ValetMode = 1;
	
		pRamVariables->ProgModeWait = 1;
	}
	else if(TestBrakeSwitch() && pRamVariables->ProgModeWait ==0)
	{
		if(pRamVariables->ValetMode >= 1 )
			pRamVariables->ValetMode = 0;
			
		pRamVariables->ProgModeWait = 1;
	}
	else
	{
		if(pRamVariables->ProgModeWait != 0 && (*pThrottlePlate < PROG_THROTTLE_LO) && (*pBrakeFlags & BrakeBitMask) == 0)
			pRamVariables->ProgModeWait--;
	}
	pRamVariables->ProgModeValue = pRamVariables->ValetMode;
	pRamVariables->ProgModeValueFlashes = pRamVariables->ValetMode;
}

#endif