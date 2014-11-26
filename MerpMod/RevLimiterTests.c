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


// All test functions must be explicitly put into the Misc section, otherwise
// the compiler/linker will put them in an address range that conflicts with
// ECU code.

// Sets or clears the 0x80 bit of the 'cruise flags A' ECU variable.

#if !AUTO_TRANS
void SetClutch(int value)
{
	if (value == 0)
	{
		*pClutchFlags &= ~(ClutchBitMask);
	}
	else
	{
		*pClutchFlags |= ClutchBitMask;
	}
}
#endif

void SetBrake(int value)
{
	#ifdef pBrakeFlags
		if (value == 0)
		{
			*pBrakeFlags &= ~(BrakeBitMask);
		}
		else
		{
			*pBrakeFlags |= BrakeBitMask;
		}
	#endif
}

#if REVLIM_HACKS

// Gets the bit of the 'rev limit flags' ECU variable.
// Or returns value when using value flags.
unsigned char GetFuelCutFlag() __attribute__ ((section ("Misc")));
unsigned char GetFuelCutFlag()
{
	// The SH2E compiler implements this correctly.
	unsigned char result = *pFlagsRevLim & RevLimBitMask;  // use this for bit flags
	if (result == 0)
	return result;
	return 1;
}

// Test the rev limiter hack.
void RevLimUnitTests() __attribute__ ((section ("Misc")));
void RevLimUnitTests()
{
	ClearRam();
	//Run initializer
	PopulateRamVariables();
	
#if VIN_HACKS
	//Bypass VIN Cut
	pRamVariables->VinAuth = 0x01;
#endif

	SetBrake(0);
	SetClutch(0);

	////
	//Redline Test
	///////////////
	//Clear flag
	*pFlagsRevLim = 0x00;
	//Set just below REDLINE, should not cut
	*pEngineSpeed = pRamVariables->RedLineCut - 1;
	*pVehicleSpeed = 19.0f;
	SetClutch(0);
	RevLimCode();
	Assert(!GetFuelCutFlag(), "RedLine: Allow fuel at RedLineCut - 1 RPM, moving, clutch not pressed !FuelCut");
	Assert(!pRamVariables->LCEngaged, "RedLine: Allow fuel at RedLineCut - 1 RPM, moving, clutch not pressed, !LCEngaged");
	
	//Set above REDLINE, should cut
	*pEngineSpeed = pRamVariables->RedLineCut + 1;
	*pVehicleSpeed = 19.0f;
	SetClutch(0);
	RevLimCode();
	Assert(GetFuelCutFlag() && !pRamVariables->LCEngaged, "RedLine: Cut fuel at RedLineCut + 1 RPM, moving, clutch not pressed");	

	//Set back below hysteresis, should RESUME
	*pEngineSpeed = pRamVariables->RedLineCut - pRamVariables->RedLineHyst - 1;
	*pVehicleSpeed = 19.0f;
	SetClutch(0);
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "RedLine: Resume fuel at RedLineResume - 1 RPM, moving, clutch not pressed");
	
	////
	//LC Tests
	///////////
	
	//TEST 1: Stationary car
	//Clutch is out
	//RPM is between LC limit and Redline Limit
	//Should NOT CUT
	*pThrottlePlate = 100;
	*pEngineSpeed = pRamVariables->LaunchControlCut + 1000;
	*pVehicleSpeed = 0.0f;
	RevLimCode();
	//-----V this ! means it SHOULD NOT cut
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "Normal stopped: Allow fuel at LaunchControlCut + 1000 RPM, stopped, no clutch");
	

	//TEST 2: Repeat test 1 with vehicle speed
	//Should NOT CUT
	*pEngineSpeed = pRamVariables->LaunchControlCut + 1000;
	*pVehicleSpeed = 19.0f;
	SetClutch(0);
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "Normal moving: Allow fuel at LaunchControlCut + 1000 RPM, moving, no clutch");
	
	//TEST 3: Stationary car
	//Clutch in
	//RPM Below limits
	//Shoudl NOT CUT
	*pEngineSpeed = pRamVariables->LaunchControlCut - 1;
	*pVehicleSpeed = 0.0f;
	*pThrottlePlate = 10.0f;
	SetClutch(1);
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "Launch Control: Allow fuel at LaunchControlCut - 1 RPM, standstill, clutch pressed");
	
	//TEST 4: Repeat test 3
	//Set above LC limit
	//SHOULD CUT FUEL HERE!!
	*pThrottlePlate = 100.0f;
	*pEngineSpeed = pRamVariables->LaunchControlCut + 1;
	*pVehicleSpeed = 0.0f;
	SetClutch(1);
	RevLimCode();
	Assert(GetFuelCutFlag() && pRamVariables->LCEngaged, "Launch Control: Cut fuel at LaunchControlCut + 1 RPM, standstill, clutch pressed");
	
	//Test 5: Repeat test 4
	//Set RPM below limit, but above resume value
	//SHOULD NOT RESUME YET!
	*pEngineSpeed = pRamVariables->LaunchControlCut - 1;
	*pVehicleSpeed = 0.0f;
	SetClutch(1);
	RevLimCode();
	Assert(GetFuelCutFlag() && pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	
	//TEST 6: Repeat test 5
	//Set below LC hysteresis
	//SHOULD RESUME HERE, but LC still engaged (on LC limit)
	*pEngineSpeed = pRamVariables->LaunchControlCut - pRamVariables->LaunchControlHyst - 1;
	*pVehicleSpeed = 0.0f;
	SetClutch(1);
	RevLimCode();
	int shit = !GetFuelCutFlag();
	shit &= pRamVariables->LCEngaged;
	Assert(shit , "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	
	//TEST7: low throttle
	//Set throttle 
	*pEngineSpeed = pRamVariables->RedLineCut - 200;
	*pVehicleSpeed = 0.0f;
	*pThrottlePlate = LCMinimumThrottle + 1;
	SetClutch(1);
	RevLimCode();
	//should cut here
	Assert(GetFuelCutFlag() && pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	*pThrottlePlate -= 10;
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	//should resume here
	
		
#if LC_ADJUST
	//Test LC adjust
	//Setup:
	*pEngineSpeed = pRamVariables->RedLineCut - 200;
	*pVehicleSpeed = 0.0f;
	*pThrottlePlate = LCMinimumThrottle + 1;
	SetClutch(1);
	RevLimCode();
	//should cut here
	Assert(GetFuelCutFlag() && pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	//Adjust
	*pEngineSpeed = pRamVariables->LaunchControlCut - pRamVariables->LaunchControlHyst + 5; //Still should cut
	Assert(GetFuelCutFlag() && pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	*pResumeFlags |= ResumeBitMask;
	//increases limit
	WGDCHack();
	RevLimCode();
	//should resume as limit has increased
	Assert(pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed, !LCEngaged");
	Assert(!GetFuelCutFlag(), "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed !FuelCut");
	*pResumeFlags = 0x00;
	*pCoastFlags |= CoastBitMask;
	WGDCHack();
	RevLimCode();
	//should cut again
	Assert(pRamVariables->LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed, !LCEngaged");
	Assert(!GetFuelCutFlag(), "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed !FuelCut");
#endif
	
	//////
	//FFS TESTS
	////////////////
	
	//TEST 1: Check that low throttle disables the cut
	//Set pre-shift conditions
	*pCurrentGear = 4;
	*pThrottlePlate = 20;
	*pVehicleSpeed = 50.0f;
	*pEngineSpeed = pRamVariables->LaunchControlCut - 100;
	SetClutch(0);
	RevLimCode(); //This sets the current gear
	SetClutch(1);
	RevLimCode();
	//Should NOT cut due to throttle.
	Assert(!GetFuelCutFlag() && !pRamVariables->LCEngaged, "Flat Foot Shifting: Resume fuel at FlatFootShiftResume - 1 RPM, moving, clutch pressed");

	//TEST 2: Set throttle high
	//Should engage FFS and cut
	*pEngineSpeed = pRamVariables->FlatFootShiftRpmThreshold + 500;
	*pThrottlePlate = FFSMinimumThrottle + 1;
	RevLimCode(); //This sets the FFS engaged, and sets the FFSRPM
	Assert(GetFuelCutFlag() && (pRamVariables->FFSEngaged == 2), "Flat Foot Shifting: Cut fuel at FlatFootShiftCut + 1 RPM, moving, clutch pressed");	

	//TEST 3: Set rpm low
	//Should disable FFS and resume fuel
	*pEngineSpeed = pRamVariables->RevLimResume - 1;
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables->FFSEngaged, "FFS resume when rpm drops");
	
	//TEST 4: Engage ffs and cut again
	*pEngineSpeed = pRamVariables->FlatFootShiftRpmThreshold + 500;
	RevLimCode(); //This sets the FFS engaged, and sets the FFSRPM
	RevLimCode(); //This runs the FFS limiter, and SHOULD CUT
	Assert(GetFuelCutFlag() && pRamVariables->FFSEngaged, "Flat Foot Shifting: Cut fuel at FlatFootShiftCut + 1 RPM, moving, clutch pressed");	
	//Set throttle below  FFS threshold, should resume
	*pThrottlePlate = FFSMinimumThrottle - 1;
	*pVehicleSpeed = 19.0f;
	SetClutch(1);
	RevLimCode();
	RevLimCode();
	Assert(!GetFuelCutFlag(), "Flat Foot Shifting: Resume fuel at FlatFootShiftResume - 1 RPM, moving, clutch pressed");
	*pThrottlePlate = 100;
	

	
	// Verify the other bits in the rev limiter flag are not modified.
	// ONLY NECESSARY FOR BITMASKING
	
	*pEngineSpeed = 6000.0f;
	*pVehicleSpeed = 0.0f;
	SetClutch(1);
	SetBrake(0);
	*pFlagsRevLim = 0x00;					
	RevLimCode();
	unsigned char flags = *pFlagsRevLim;
	Assert(flags == (unsigned char) RevLimBitMask, "When rev limit flag is set, no other bits are set.");

	// Verify the other bits in the rev limiter flag are not modified.
	*pEngineSpeed = 1000.0f;
	*pVehicleSpeed = 0.0f;
	SetClutch(0);
	*pFlagsRevLim = 0xFF;
	RevLimCode();
	flags = ~*pFlagsRevLim;
	Assert( flags == (unsigned char) RevLimBitMask, "When rev limit flag is cleared, no other bits are cleared.");
		
	// Sanity check the defaults
	Assert(pRamVariables->RedLineCut > pRamVariables->RedLineCut - pRamVariables->RedLineHyst, "RedLine cut/resume sanity.");
	Assert(pRamVariables->LaunchControlCut > pRamVariables->LaunchControlCut - pRamVariables->LaunchControlHyst, "LaunchControl cut/resume sanity.");
}

#endif


