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

pRamVariables->InjectorScalingMultiplier = Pull2DHooked(&InjectorScalingMultiplierTable,pRamVariables->MapBlendRatio);

pRamVariables->InjectorScaling = pRamVariables->InjectorScalingMultiplier * *dInjectorScaling;

}

#endif

#if POLF_HOOK_DEFINED
	void (*PolfHooked)() __attribute__ ((section ("RomHole_Functions"))) = (void(*)()) sPolf;

void POLFHack()
{		

	//Calculate new Injector Flow based off Ethanol Content	

	if(pRamVariables.fuelPressureFlowEnabled == 1)
		{		
		pRamVariables.kFuelPressure = sqrt(pRamVariables.pFuelCanRel/BaseInjectorFlowPressureRelative);
		
		}
	else
		pRamVariables.kFuelPressure = 1;
		
	if(pRamVariables.flexFuelSensorEnabaled == 1)	
	{
		pRamVariables.TargetedStoich = Pull2DHooked(&FlexFuelStoichTable, pRamVariables.MapBlendRatio);	 
		pRamVariables.InjectorScaling =  pRamVariables.kFuelPressure *(pRamVariables.TargetedStoich / BaseGasolineAFR) *  (*dInjectorScaling);
	}
	else
		pRamVariables.InjectorScaling = pRamVariables.kFuelPressure * (*dInjectorScaling);
		
	
#if POLF_MAIN_HOOK
EcuHacksMain();
#endif

#if POLF_HACKS
	float OutputValue;

	#if POLF_RAM_TUNING
		if(pRamVariables.POLFRamFlag = 0x01)
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
		pRamVariables.LCFuelEnrich = Pull3DHooked(&LCFuelEnrichTable, *pVehicleSpeed, *pEngineSpeed) * pRamVariables.LCFuelEnrichMultiplier;
	
		if(pRamVariables.LCFuelMode == LCFuelModeCompensated)
		{
			OutputValue += pRamVariables.LCFuelEnrich;
		}
		//Now run existing code!
	
		pRamVariables.PolfTarget = OutputValue;
	
		if(pRamVariables.PolfHackEnabled == HackEnabled)
			pRamVariables.PolfOutput = OutputValue;
		else
			pRamVariables.PolfOutput = Pull3DHooked((void*)PrimaryOEMPolfTable, *pEngineLoad, *pEngineSpeed);	
			
		pRamVariables.PolfOutputFP = (unsigned char)((pRamVariables.PolfOutput-9)*44.7); //9=0x00, 14.7 = 0xFF
#endif
		
	PolfHooked();
}
#endif
