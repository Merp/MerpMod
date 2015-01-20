/* Copyright (C) 2014 Scott T Anderson & 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
*/

#include "EcuHacks.h"

#if ALS_HACKS && ALS_RAMTUNING

//Replaces Drivemode!
void ALSRamTuning()
{
	{
		unsigned char NewDriveMode;
		unsigned char KillWait = pRamVariables->KillWait;
		unsigned char ModeWait = pRamVariables->ALSModeWait;

  		if (TestBrakeSwitch() && TestCruiseResumeSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSTimingRamTuning += ALSTimingRamTuningAdder;
			}
			else
			{
			}
		}
  		else if (TestBrakeSwitch() && TestCruiseCoastSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSTimingRamTuning -= ALSTimingRamTuningAdder;
			}
			else
			{
			}
		}
  		if (TestClutchSwitch() && TestCruiseResumeSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSPOLFRamTuning += ALSPOLFRamTuningAdder;
			}
			else
			{
			}
		}
  		else if (TestClutchSwitch() && TestCruiseCoastSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSPOLFRamTuning -= ALSPOLFRamTuningAdder;
			}
			else
			{
			}
		}
  		if (TestDefoggerSwitch() && TestCruiseResumeSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSAVCSRamTuning += ALSAVCSRamTuningAdder;
			}
			else
			{
			}
		}
  		else if (TestDefoggerSwitch() && TestCruiseCoastSwitch())
		{	
			if (ModeWait == 0)
			{
				pRamVariables->ALSModeWait = 0x01;
				pRamVariables->ALSAVCSRamTuning -= ALSAVCSRamTuningAdder;
			}
			else
			{
			}
		}
  		if (TestCruiseMasterSwitch() && TestCruiseResumeSwitch())
		{	
			if (ModeWait == 0)
			{
				NewDriveMode = DriveModeSwitch();
				pRamVariables->DriveMode = NewDriveMode;
				pRamVariables->ALSModeWait = 0x01;
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
		else
		{
		}

		float TargetIdleSpeed;
		float RequestedTorque;
		float AVCS;

  	AVCS = BlendAndSwitch(AVCSTableGroup, *pEngineLoad, *pEngineSpeed);

		if (pRamVariables->DriveMode <= 3)
		//Performance Mode
			{
				RequestedTorque = BlendAndSwitch(ReqTorqTableGroup, *pAcceleratorPedal, *pEngineSpeed);
				TargetIdleSpeed = Pull2DHooked((void*)tTargetIdleSpeedA, *pCoolantTemp);
			}
		else if (pRamVariables->DriveMode >= 4)
		//ALS Mode
			{
				RequestedTorque = BlendAndSwitch(ReqTorqTableGroup, *pAcceleratorPedal, *pEngineSpeed);
				TargetIdleSpeed = DefaultALSTargetIdleSpeed;
			}
		else
			{
			}

		if (pRamVariables->ALSActive == 2)
			{
				ALSAVCS += pRamVariables->ALSAVCSRamTuning;//Test, need to fix neutral/ingear swithes
				pRamVariables->AVCS = ALSAVCS;//Test, need to fix neutral/ingear swithes
			}
		else
			{
				pRamVariables->AVCS = AVCS;
			}

		pRamVariables->TargetIdleSpeed = TargetIdleSpeed;
		pRamVariables->RequestedTorque = RequestedTorque;

	}
}

#endif
