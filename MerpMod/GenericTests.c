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

void BrickBuster() __attribute__ ((section ("Misc")));
void CallMemoryReset() __attribute__ ((section ("Misc")));
void GenericTests() __attribute__ ((section ("Misc")));


#ifdef sMemoryReset

void CallMemoryReset()
{
	void (*func)() = (void(*)()) sMemoryReset;
	(*func)();//(*pMafSensorVoltage);
	//return *pMassAirFlow;
}
#endif



void GenericTests() 
{
	ResetRamVariables();
	
#if VIN_HACKS
	Assert(pRamVariables.VinAuth != 0x00,"Check VIN auth!");
#endif

#if CEL_HACKS
	CelFlashUnitTests();
#endif

#if REVLIM_HACKS
	RevLimUnitTests();
#endif

#if SD_HACKS
	SpeedDensityUnitTests();
#endif

#if POLF_HACKS
	PolfHackUnitTests();
#endif

#if TIMING_HACKS
	TimingHackUnitTests();
#endif

#if PROG_MODE
	ProgModeUnitTests();
#endif

	BrickBuster();
}


void BrickBuster()
{
//declare and call all of the hook test points

#ifdef pRamHoleEnd
unsigned int test = pRamHoleEnd;
unsigned int end = &(pRamVariables.RamHoleEndMarker);
if(test < end)
Assert(0,"error in ram hole!");
#endif

#if SD_HACKS
	CallSpeedDensityHook();//This covers SD
#endif

#if REVLIM_HACKS
	RevLimHook();
#endif

#if WGDC_HOOK_DEFINED
	WGDCHack();	//This covers everything hooked into WGDC
					//Celflash and/or wgdc/boost hacks, progmode, pgwg
#endif

#if SWITCH_HACKS && INJECTOR_HACKS
	InjectorHack();
#endif

#if POLF_HACKS
	POLFHack();
#endif

#if TIMING_HACKS
	TimingHack();
#endif

#if MEMORY_HACKS
	CallMemoryReset();
#endif
}


#if ARCH_SH7055
#define ARCH_STACK_POINTER 0xFFFF7000
#elif ARCH_SH7058
#define ARCH_STACK_POINTER 0xFFFF1000
#else
#define ARCH_STACK_POINTER 0xFFFF1000
#endif
unsigned long ArchStackPointer __attribute__ ((section ("RomHole_Misc"),aligned(8))) = ARCH_STACK_POINTER;

void SetValues() __attribute__ ((section ("Misc")));
void SetValues() 
{
	// These are just here to clarify the boundary between the prologue and the
	// 'real' code when stepping through in a debugger.
	asm("nop");
	asm("nop");

	// If you change compiler settings, inspect the way the variables get set.
	// Ideally it should take three instructions per assignment, with no 
	// references to other memory.  If this does reference other memory, patches
	// will be difficult to apply.
	
#if VIN_HACKS
	//Init VIN
	int i;
	int j = 16;
	for(i=0; i<16; i++)
	{
		pRamVariables.VehicleIdent[j] = VinBlock.Vin[i];
		*(pObdVinDirect + j) = VinBlock.Vin[i];
		j -= 4;
		if(j<0)
		{
			j += 15;
		}
	}
	
#endif
	
#if REVLIM_HACKS
	// LC/FFS test settings
	*pEngineSpeed = 1000.0f;
	*pVehicleSpeed = 12.0f;
	*pClutchFlags |= ClutchBitMask;
	*pFlagsRevLim &= ~RevLimBitMask;				
#endif
	
	// Speed-density test settings
	*pManifoldAbsolutePressure = 268.917649; // Corresponds to -9.5psiG, which is normal for idle.
	*pAtmoPress = 700;
	*pMafSensorVoltage = 1.5 * MafVoltageToInternalUnits;
}
