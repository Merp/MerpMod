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

void (*MemoryResetHooked)() __attribute__ ((section ("RomHole_Functions"))) = (void(*)()) sMemoryReset;

void Initializer()
{
	MemoryResetHooked();
#if RAM_PERSIST
	InitRamVariables();
#else
	ResetRamVariables();
#endif

}

void ResetRamVariables()
{
	ClearRamVariables((long*)pRamVariables,(long*)&pRamVariables->RamHoleEndMarker);
	PopulateRamVariables();
}

void InitRamVariables()
{
	if(pRamVariables->ECUIdentifier != *(long*)dEcuId)
	{
		ResetRamVariables();
	}
}

void ClearRamVariables(long *start, long *end)
{
	long *pend = end;
	long *pointy = start;
	while(pointy < pend)
	{
		*pointy = 0x00000000;
		pointy++;
	}
}

void PopulateRamVariables()
{
	
#if CRUISE_CONTROL
pRamVariables->CruiseResumeLast = TestCruiseResumeSwitch();
pRamVariables->CruiseCoastLast = TestCruiseCoastSwitch();
#endif

pRamVariables->IdleLast = TestIdleSwitch();
pRamVariables->NeutralLast = TestNeutralSwitch();
pRamVariables->DefoggerLast = TestDefoggerSwitch();

#if INJECTOR_HACKS
	//Injector Scalar init to default
	pRamVariables->InjectorScaling = *InjectorScalingOem;
#endif

#if SWITCH_HACKS
	pRamVariables->MapSwitch = DefaultMapSwitch;
	pRamVariables->MapBlendRatio = DefaultMapBlendRatio;
#endif

#if PROG_MODE
	pRamVariables->ProgModeEnable = 0;
	pRamVariables->ProgModeWait = 0;
	pRamVariables->ProgModeEntry = 0;
	pRamVariables->ProgModeEnable = 0;
	pRamVariables->ProgModeCurrentMode = 0;
#endif

#if REVLIM_HACKS
	//Revlimit mode init
	if (pRamVariables->RevLimMode == RevLimModeUndefined)
	{
		pRamVariables->RevLimMode = DefaultRevLimMode;
	}
	//Init revlimit cuts
	pRamVariables->FlatFootShiftMode = DefaultFlatFootShiftMode;
	pRamVariables->RedLineCut = DefaultRedLineCut;
	pRamVariables->RedLineHyst = DefaultRedLineHyst;
	pRamVariables->FlatFootShiftHyst = DefaultFlatFootShiftHyst;
	pRamVariables->FlatFootShiftAutoDelta = DefaultFlatFootShiftAutoDelta;
	pRamVariables->FlatFootShiftStaticDelta = DefaultFlatFootShiftStaticDelta;
	pRamVariables->LaunchControlSpeedMax = DefaultLaunchControlSpeedMax;
	pRamVariables->LaunchControlCut = DefaultLaunchControlCut;
	pRamVariables->LaunchControlHyst = DefaultLaunchControlHyst;
	pRamVariables->FlatFootShiftSpeedThreshold = DefaultFlatFootShiftSpeedThreshold;
	pRamVariables->FlatFootShiftRpmThreshold = DefaultFlatFootShiftRpmThreshold;
#endif 

#if VIN_HACKS
	VinCheck();
#endif

#if SPARK_HACKS
	//Init spark cut
	*LCSparkEventsToCut = DefaultLCSparkEventsToCut;
	*LCSparkEventsCutFrom = DefaultLCSparkEventsCutFrom;
#endif

#if POLF_HACKS
	pRamVariables->PolfHackEnabled = DefaultPolfHackEnabled;
	if (pRamVariables->LCFuelMode == LCFuelModeUndefined)
	{
		pRamVariables->LCFuelMode = DefaultLCFuelMode;
	}
	pRamVariables->LCFuelLock = DefaultLCFuelLock;
	pRamVariables->LCFuelEnrichMultiplier = DefaultLCFuelEnrichMultiplier;
#endif

#if TIMING_HACKS
	pRamVariables->TimingHackEnabled = DefaultTimingHackEnabled;

	if (pRamVariables->LCTimingMode == LCTimingModeUndefined)
	{
		pRamVariables->LCTimingMode = DefaultLCTimingMode;
	}
	pRamVariables->LCTimingLock = DefaultLCTimingLock;
	pRamVariables->LCTimingRetardMultiplier = DefaultLCTimingRetardMultiplier;
#endif

#if SD_HACKS
	pRamVariables->MafMode = DefaultMafMode;
#endif

#if SHIFTLIGHT_HACKS
	pRamVariables->ShiftLightRPM = DefaultShiftLightRPM;
#endif

#if ALS_HACKS
	pRamVariables->TargetIdleSpeed = Pull2DHooked((void*)PrimaryOEMTargetIdleSpeedTableA, *pCoolantTemp);
	pRamVariables->ALSModeWait = 0x00;
	pRamVariables->ALSEnable = 0x00;
	pRamVariables->ALSActive = 0x00;
	pRamVariables->RequestedTorque = Pull3DHooked((void*)tRequestedTorqueA, *pAcceleratorPedal, *pEngineSpeed);
	pRamVariables->DriveMode = DefaultDriveMode;
	pRamVariables->KillMode = 0x00;
	pRamVariables->FuelCheck1 = 0.0;
	pRamVariables->FuelCheck2 = 0.0;
	pRamVariables->StartTimer = 0.0;
	pRamVariables->TimerUp = 0x01;
/*	pRamVariables->StartTimerA = 0.0;
	pRamVariables->TimerUpA = 0x01;
	pRamVariables->StartTimerB = 0.0;
	pRamVariables->TimerUpB = 0x01;
	pRamVariables->StartTimerC = 0.0;
	pRamVariables->TimerUpC = 0x01;
*/	pRamVariables->FuelUp = 0x00;
	pRamVariables->FlexCount = 0x00;
	pRamVariables->FlexWait = 0x00;
	pRamVariables->FuelCheckSwitch = 0x00;
	pRamVariables->FuelLevelSwitch = 0x00;
	pRamVariables->FlexLearnHasRun = 0x00;
	pRamVariables->FlexFuelRatio = 0.0;	
	pRamVariables->FuelLevel1 = 0.0;
	pRamVariables->FuelLevel2 = 0.0;
	pRamVariables->FuelLevel3 = 0.0;
#if ALS_RAMTUNING
	pRamVariables->ALSAVCSRamTuning = DefaultALSAVCSRamTuning;
	pRamVariables->ALSPOLFRamTuning = DefaultALSPOLFRamTuning;
	pRamVariables->ALSTimingRamTuning = DefaultALSTimingRamTuning;
#endif
#endif

pRamVariables->ECUIdentifier = *(long*)dEcuId;

}

#if VIN_HACKS

void VinCheck()
{
	//Init VIN	
}

#endif