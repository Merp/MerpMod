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

#if MPG_HACKS

void Mileage()
{
	float TargetCLAFR;
	//Lean 5th Gear Cruise and idle
	if (*pCurrentGear == 5 && *pEngineLoad <= LeanCruiseLoadThreshold || TestIdleSwitch())
		{
			TargetCLAFR = Pull2DHooked(&O2SensorScalingMPGTable, *pAFSensor1Current);
		}
	else
		{
			TargetCLAFR = Pull2DHooked((void*)tO2SensorScaling, *pAFSensor1Current);
		}
		
	pRamVariables->TargetCLAFR = TargetCLAFR;
}

void DisplacementOnDemand()
{
	if (*pAcceleratorPedal < 15.0 && *pEngineLoad < 0.5 && *pVehicleSpeed > 72.0 && *pFuelCut < 13)
		{
			RotationalFuelCut();
		}
	else
		{
		}
}
#endif
