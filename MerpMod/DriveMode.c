/*	Copyright (C) 2014 Scott T Anderson & 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
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

float (*SSMResetWrite)(short ByteData) __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sMemorySoftReset;

#if ALS_HACKS

void DriveModeHack()
{
	{
		unsigned char NewDriveMode;
		unsigned char KillWait = pRamVariables->KillWait;
		unsigned char ModeWait = pRamVariables->ALSModeWait;

		if (TestClutchSwitch() && TestDefoggerSwitch() && TestCruiseCoastSwitch() && TestBrakeSwitch())
		{
			if (KillWait == 0)
			{
				pRamVariables->KillMode += 1;
				pRamVariables->KillWait = 0x01;
				pRamVariables->DriveMode = 0x01;
				pRamVariables->ALSModeWait = 0x01;
			}
			else
			{
			}
		}	
		else if (TestCruiseMasterSwitch() && TestCruiseResumeSwitch())
		{	
			if (ModeWait == 0)
			{
				NewDriveMode = DriveModeSwitch();
				pRamVariables->DriveMode = NewDriveMode;
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->KillMode = 0x00;
			}
			else
			{
			}
		}
		else if (TestCruiseMasterSwitch() && TestCruiseCoastSwitch())
		{	
			if (ModeWait == 0)
			{
				NewDriveMode = DriveModeSwitchAlt();
				pRamVariables->DriveMode = NewDriveMode;
				pRamVariables->ALSModeWait = 0x01;
			}
			else
			{
			}
		}
		else if (!TestCruiseResumeSwitch() && !TestCruiseCoastSwitch())
		{
			pRamVariables->ALSModeWait = 0x00;
		}
		else if (!TestBrakeSwitch())
		{
			pRamVariables->KillWait = 0x00;
		}
		else
		{
		}

		float TargetIdleSpeed;
		float RequestedTorque;
		
		RequestedTorque = BlendAndSwitch(ReqTorqTableGroup, *pAcceleratorPedal, *pEngineSpeed);

		if (pRamVariables->KillMode >= 2)
		//Kill Mode
			{
//				*pFlagsRevLim |= RevLimBitMask;//FuelCut
				TargetIdleSpeed = 0.0;
				RequestedTorque = 0.0;
			}
		else if (pRamVariables->DriveMode == 1 && pRamVariables->KillMode <= 1)
		//Valet Mode
			{
				TargetIdleSpeed = Pull2DHooked((void*)tTargetIdleSpeedA, *pCoolantTemp);
			}
		else if (pRamVariables->DriveMode == 2)
		//Normal Mode
			{
				TargetIdleSpeed = Pull2DHooked((void*)tTargetIdleSpeedA, *pCoolantTemp);
			}
		else if (pRamVariables->DriveMode == 3)
		//Performance Mode
			{
				TargetIdleSpeed = Pull2DHooked((void*)tTargetIdleSpeedB, *pCoolantTemp);
			}
		else if (pRamVariables->DriveMode >= 4)
		//ALS Mode
			{

				TargetIdleSpeed = DefaultALSTargetIdleSpeed;
			}
		else
			{
			}

		//add if A/C check here?
		pRamVariables->TargetIdleSpeed = TargetIdleSpeed;
		pRamVariables->RequestedTorque = RequestedTorque;

	}
	ALSActivate();
	MemoryHardReset();
}

void MemoryHardReset()	
{
	//Conditions for Memory Reset
	if (pRamVariables->KillMode >= 5 && *pEngineSpeed == 0)
		{
			ResetRamVariables();
			SSMResetWrite(0x40);
		}
	else
		{
		}
}

#endif

#if ALS_HACKS
	unsigned char DriveModeSwitch()
	{
		unsigned char result = pRamVariables->DriveMode;
		if(result == 1)
			return 0x02;
		else if(result == 2)
			return 0x03;
		else if(result == 3)
			return 0x04;
		else
			return DefaultDriveMode;
	}
	unsigned char DriveModeSwitchAlt()
	{
		unsigned char result = pRamVariables->DriveMode;
		if(result <= 1)
			return 0x01;
		else if(result == 2)
			return 0x01;
		else if(result == 3)
			return 0x02;
		else
			return 0x03;
	} 	
#endif
