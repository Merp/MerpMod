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

#ifdef pBrakeFlags
void SetBrake(int value)
{
	if (value == 0)
	{
		*pBrakeFlags &= ~(BrakeBitMask);
	}
	else
	{
		*pBrakeFlags |= BrakeBitMask;
	}
}
#endif

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


void RevLimUnitTest(unsigned char flag, int brake, int clutch, float throttle, float mph, float rpm) __attribute__ ((section ("Misc")));
void RevLimUnitTest(unsigned char flag, int brake, int clutch, float throttle, float mph, float rpm){
	
	ClearRam();
	//Run initializer
	PopulateRamVariables();
	
#if VIN_HACKS
	//Bypass VIN Cut
	pRamVariables.VinAuth = 0x01;
#endif

#ifdef pBrakeFlags
	SetBrake(brake);
#endif

	SetClutch(clutch);
	*pThrottlePlate = throttle;
	*pEngineSpeed = rpm;
	*pVehicleSpeed = mph;

	//Clear flag
	*pFlagsRevLim = flag;
	
	RevLimCode();
}

// Test the rev limiter hack.
void RevLimUnitTests() __attribute__ ((section ("Misc")));
void RevLimUnitTests()
{

	//Set just below REDLINE, should not cut
	//void RevLimUnitTest(unsigned char flag, int brake, int clutch, float throttle, float mph, float rpm) __attribute__ ((section ("Misc")));
	RevLimUnitTest(0x00,0,0,50,19,DefaultRedLineCut-1);
	Assert(!GetFuelCutFlag(), "RedLine: Allow fuel at RedLineCut - 1 RPM, moving, clutch not pressed !FuelCut");
	Assert(!pRamVariables.LCEngaged, "RedLine: Allow fuel at RedLineCut - 1 RPM, moving, clutch not pressed, !LCEngaged");
	
	//Set above REDLINE, should cut
	RevLimUnitTest(0x00,0,0,50,18,DefaultRedLineCut+1);
	Assert(GetFuelCutFlag() && !pRamVariables.LCEngaged, "RedLine: Cut fuel at RedLineCut + 1 RPM, moving, clutch not pressed");	

	//Set back below hysteresis, should RESUME
	*pEngineSpeed = DefaultRedLineCut - DefaultRedLineHyst - 1;
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "RedLine: Resume fuel at RedLineResume - 1 RPM, moving, clutch not pressed");
	
	////
	//LC Tests
	///////////
	
	//TEST 1: Stationary car
	//Clutch is out
	//RPM is between LC limit and Redline Limit
	//Should NOT CUT
	RevLimUnitTest(0x00,0,0,100,0,DefaultLaunchControlCut + 1000);
	//-----V this ! means it SHOULD NOT cut
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "Normal stopped: Allow fuel at LaunchControlCut + 1000 RPM, stopped, no clutch");
	

	//TEST 2: Repeat test 1 with vehicle speed
	//Should NOT CUT
	RevLimUnitTest(0x00,0,0,100,50,DefaultLaunchControlCut + 1000);
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "Normal moving: Allow fuel at LaunchControlCut + 1000 RPM, moving, no clutch");
	
	//TEST 3: Stationary car
	//Clutch in
	//RPM Below limits
	//Shoudl NOT CUT
	RevLimUnitTest(0x00,0,1,10,0,DefaultLaunchControlCut -1);
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "Launch Control Test 3 Failed: standstill, clutch pressed");
	
	//TEST 4: Stationary Car
	//Apply full throttle, still below limit. Should engage LC mode but not cut.
	RevLimUnitTest(0x00,0,1,100,0,DefaultLaunchControlCut -1);
	Assert(!GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control Test 4 Failed: 0 mph, 100 thr, rpm below limit");
	
	//TEST 5: Repeat test 3
	//Set above LC limit
	//SHOULD CUT FUEL HERE!!
	RevLimUnitTest(0x00,0,1,100,0,DefaultLaunchControlCut +1);
	Assert(GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control: Cut fuel at LaunchControlCut + 1 RPM, standstill, clutch pressed");
	
	//Test 5: Repeat test 4
	//Set RPM below limit, but above resume value
	//SHOULD NOT RESUME YET!
	*pEngineSpeed = DefaultLaunchControlCut - 1;
	RevLimCode();
	Assert(GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	
	//TODO: run test here for disable during hysteresis?
	
	//TEST 6: Repeat test 5
	//Set below LC hysteresis
	//SHOULD RESUME HERE, but LC still engaged (on LC limit)
	*pEngineSpeed = DefaultLaunchControlCut - DefaultLaunchControlHyst - 1;
	RevLimCode();
	Assert(!GetFuelCutFlag() && pRamVariables.LCEngaged , "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	
	//TEST7: low throttle
	//Set throttle 
	RevLimUnitTest(0x00,0,1,LCMinimumThrottle+1,0,DefaultRedLineCut -200);
	//should cut here
	Assert(GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	*pThrottlePlate -= 10;
	RevLimCode();
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	//should resume here
	
		
#if LC_ADJUST
	//Test LC adjust
	//Setup:
	RevLimUnitTest(0x00,0,1,LCMinimumThrottle+1,0,DefaultRedLineCut - 200);
	//should cut here
	Assert(GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	//Adjust
	*pEngineSpeed = DefaultLaunchControlCut - DefaultLaunchControlHyst + 5; //Still should cut
	Assert(GetFuelCutFlag() && pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed");
	*pResumeFlags |= ResumeBitMask;
	//increases limit
	WGDCHack();
	RevLimCode();
	//should resume as limit has increased
	Assert(pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed, !LCEngaged");
	Assert(!GetFuelCutFlag(), "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed !FuelCut");
	*pResumeFlags &= ~ResumeBitMask;
	*pCoastFlags |= CoastBitMask;
	WGDCHack();
	RevLimCode();
	//should cut again
	Assert(pRamVariables.LCEngaged, "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed, !LCEngaged");
	Assert(!GetFuelCutFlag(), "Launch Control: Resume fuel at LaunchControlResume - 1 RPM, standstill, clutch pressed !FuelCut");
#endif
	
	//////
	//FFS TESTS
	////////////////
	
	//TEST 1: Check that low throttle disables the cut
	//Set pre-shift conditions
	
	#ifdef pCurrentGear
	*pCurrentGear = 4;
	#endif
	
	*pThrottlePlate = 20;
	*pVehicleSpeed = 50.0f;
	*pEngineSpeed = pRamVariables.LaunchControlCut - 100;
	SetClutch(0);
	RevLimCode(); //This sets the current gear
	SetClutch(1);
	RevLimCode();
	//Should NOT cut due to throttle.
	Assert(!GetFuelCutFlag() && !pRamVariables.LCEngaged, "Flat Foot Shifting: Resume fuel at FlatFootShiftResume - 1 RPM, moving, clutch pressed");

	//TEST 2: Set throttle high
	//Should engage FFS and cut
	*pEngineSpeed = pRamVariables.FlatFootShiftRpmThreshold + 500;
	*pThrottlePlate = FFSMinimumThrottle + 1;
	SetClutch(0);
	RevLimCode(); //This sets the clutch depressed test
	SetClutch(1);
	RevLimCode(); //Sets FFSEngaged = 1 and sets the FFSRPM
	Assert(pRamVariables.FFSEngaged == 1,"FFS Intermediate step");
	RevLimCode(); //Sets FFSEngaged = 2
	Assert(GetFuelCutFlag() && (pRamVariables.FFSEngaged == 2), "Flat Foot Shifting: Cut fuel at FlatFootShiftCut + 1 RPM, moving, clutch pressed");	

	//TEST 3: Set rpm low
	//Should disable FFS and resume fuel
	*pEngineSpeed = pRamVariables.RevLimResume - 1;
	RevLimCode();
	Assert(!GetFuelCutFlag() && pRamVariables.FFSEngaged == 2, "FFS resume when rpm drops");
	
	//TEST 4: Engage ffs and cut again
	*pEngineSpeed = pRamVariables.FlatFootShiftRpmThreshold + 500;
	RevLimCode(); //This sets the FFS engaged, and sets the FFSRPM
	RevLimCode(); //This runs the FFS limiter, and SHOULD CUT
	Assert(GetFuelCutFlag() && pRamVariables.FFSEngaged, "Flat Foot Shifting: Cut fuel at FlatFootShiftCut + 1 RPM, moving, clutch pressed");	
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
	#ifdef pBrakeFlags
	SetBrake(0);
	#endif
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
	Assert(pRamVariables.RedLineCut > pRamVariables.RedLineCut - pRamVariables.RedLineHyst, "RedLine cut/resume sanity.");
	Assert(pRamVariables.LaunchControlCut > pRamVariables.LaunchControlCut - pRamVariables.LaunchControlHyst, "LaunchControl cut/resume sanity.");
}

#endif


