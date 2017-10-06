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

#if SD_HACKS

float ComputeMassAirFlow(TwoDTable* MafScalingTable, float MafVoltage)
{	
#if CAN_HACKS
	CustomCanService();
#endif	
	pRamVariables.MafFromSensor = Pull2DHooked(MafScalingTable,MafVoltage);	

#if VE_RAMTUNING
	if(pRamVariables.VERamFlag == 0x01)
	{
		pRamVariables.VolumetricEfficiency = Pull3DHooked(&VolumetricEfficiencyRamTable, *pManifoldAbsolutePressure, *pEngineSpeed);
	}
	else
	{
#endif

#if SWITCH_HACKS
	pRamVariables.VolumetricEfficiency = BlendAndSwitch(VETableGroup, *pManifoldAbsolutePressure, *pEngineSpeed);
#else
	pRamVariables.VolumetricEfficiency = Pull3DHooked(&VolumetricEfficiencyTable1, *pManifoldAbsolutePressure, *pEngineSpeed);
#endif
		
#if VE_RAMTUNING
	}
#endif
	
	float intakeAirTempInKelvin = (*pIntakeAirTemp) + CelsiusToKelvin;
		
	pRamVariables.AtmosphericCompensation = Pull3DHooked(&AtmosphericCompensationTable, *pManifoldAbsolutePressure, *pAtmoPress);
#if SD_DMAP
	pRamVariables.DeltaMapCompensation = Pull3DHooked(&SDDeltaMapTable, *pDeltaMap, *pEngineSpeed);
#endif

	pRamVariables.MafFromSpeedDensity = 
		Displacement * 
		(*pEngineSpeed) * 
		(*pManifoldAbsolutePressure) * 
		pRamVariables.VolumetricEfficiency * 
		pRamVariables.AtmosphericCompensation *
#if SD_DMAP
		pRamVariables.DeltaMapCompensation *
#endif
		SpeedDensityConstant / intakeAirTempInKelvin;

#if VE_RAMTUNING
	if (pRamVariables.MafMode == MafModeSpeedDensity || pRamVariables.VERamFlag == 0x01)
#else
	if (pRamVariables.MafMode == MafModeSpeedDensity)
#endif
	{
		return pRamVariables.MafFromSpeedDensity;
	}
	else if (pRamVariables.MafMode == MafModeBlending)
	{
		pRamVariables.SDMafBlendRatio = Pull3DHooked(&SDBlendingTable, *pManifoldAbsolutePressure, *pEngineSpeed);
		
		pRamVariables.SDMafFromBlend = 
		((pRamVariables.MafFromSpeedDensity * pRamVariables.SDMafBlendRatio) +
		(pRamVariables.MafFromSensor * 
		(1 - pRamVariables.SDMafBlendRatio)));
		
		return pRamVariables.SDMafFromBlend;
	}
	else
	{
		return pRamVariables.MafFromSensor;
	}
}
#endif