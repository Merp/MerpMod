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

#if SWITCH_HACKS && INJECTOR_HACKS

void InjectorHack(){

float OutputValue;

OutputValue = Pull2DHooked(&InjectorScalingTable,pRamVariables->MapBlendRatio);

pRamVariables->InjectorScaling = OutputValue;
}

#endif

#if POLF_HACKS
	void (*PolfHooked)() __attribute__ ((section ("RomHole_Functions"))) = (void(*)()) sPolf;

void POLFHack()
{		

#if POLF_MAIN_HOOK
EcuHacksMain();
#endif

#if POLF_HACKS
	float OutputValue;

	#if POLF_RAM_TUNING
		if(pRamVariables->POLFRamFlag = 0x01)
		{
			OutputValue = Pull3DHooked(&FuelRamTable, *pEngineLoad, *pEngineSpeed);
		}
		else
		{
	#endif
	
		OutputValue	= BlendAndSwitch(FuelTableGroup, *pEngineLoad, *pEngineSpeed);
		
	#if POLF_RAM_TUNING
		}
	#endif
		pRamVariables->LCFuelEnrich = Pull3DHooked(&LCFuelEnrichTable, *pVehicleSpeed, *pEngineSpeed) * pRamVariables->LCFuelEnrichMultiplier;

		if(pRamVariables->LCFuelMode == LCFuelModeCompensated)
		{
			OutputValue += pRamVariables->LCFuelEnrich;
		}
		//Now run existing code!
		
#if ALS_HACKS
	if (pRamVariables->ALSActive == 1)
		{
			OutputValue = DefaultALSFuelLock;
#if ALS_RAMTUNING
			OutputValue += pRamVariables->ALSPOLFRamTuning;
#endif
		}
	else
		{
#endif
			OutputValue *= PGFuelComp;
			
#if ALS_HACKS
		}
#endif
	
		if(pRamVariables->PolfHackEnabled == HackEnabled)
			{
				pRamVariables->PolfOutput = OutputValue;
			}
		else
			{
				pRamVariables->PolfOutput = Pull3DHooked((void*)PrimaryOEMPolfTable, *pEngineLoad, *pEngineSpeed);
			}	
#endif
		
	PolfHooked();
}
#endif