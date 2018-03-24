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
// All test functions must be explicitly put into the Misc section, otherwise
// the compiler/linker will put them in an address range that conflicts with
// ECU code.
extern long SpeedDensityIntegration;

float CallSpeedDensityHook()
{
	void (*func)() = (void(*)()) sMafCalc;
	(*func)(*pMafSensorVoltage);
	
	return *pMassAirFlow;
}



// Unit tests for the speed density hack.
void SpeedDensityUnitTests() __attribute__ ((section ("Misc")));
void SpeedDensityUnitTests()
{
	pRamVariables.MafMode = MafModeUndefined;
	ClearRam();
#if VE_RAMTUNING	
	pRamVariables.VERamFlag = 0;
#endif
	//Run initializer 
	PopulateRamVariables();
	
	float expectedMafFromSensor;
	float expectedMafFromSpeedDensity;
	expectedMafFromSensor = EXPECTED_MAF_SENSOR;
	expectedMafFromSpeedDensity = EXPECTED_MAF_SD;

	// Pretend the ECU has just booted and initialized, so MafMode should be set to default (sensor)
	Assert(pRamVariables.MafMode == MafModeSensor, "First execution should set MafMode to MafModeSensor.");
	
	*pEngineSpeed = 1000.0f;
	*pManifoldAbsolutePressure = 268.917649; // Corresponds to -9.5psiG, which is normal for idle.	
	*pAtmoPress = 700;
	*pIntakeAirTemp = 15;
	*pMafSensorVoltage = (short) (1.25f * MafVoltageToInternalUnits);
	
	float result = CallSpeedDensityHook();
	Assert(AreCloseEnough(result, expectedMafFromSensor), "First execution should return MAF from sensor.");
	
	// Verify that we get the same result again.
	result = CallSpeedDensityHook();	
	Assert(AreCloseEnough(result, expectedMafFromSensor), "Second execution should return MAF from sensor.");
	Assert(pRamVariables.MafMode == MafModeSensor, "MafMode should remain set to MafModeSensor.");

	//Switch to SD mode
	pRamVariables.MafMode = MafModeSpeedDensity;
	result = CallSpeedDensityHook();	
	Assert(AreCloseEnough(result, expectedMafFromSpeedDensity), "Second execution should return MAF from speed-density.");
	Assert(pRamVariables.MafMode == MafModeSpeedDensity, "MafMode should remain set to MafModeSpeedDensity.");

#if SWITCH_HACKS
	//Check Blend = 1
	pRamVariables.MapBlendRatio = 1.0;
	result = CallSpeedDensityHook();	
	Assert(AreCloseEnough(result, 3.73053f), "Second execution should return MAF from speed-density.");
	Assert(pRamVariables.MafMode == MafModeSpeedDensity, "MafMode should remain set to MafModeSpeedDensity.");
	
	//Check Blend = 0.5
	pRamVariables.MapBlendRatio = 0.5;
	result = CallSpeedDensityHook();	
	Assert(AreCloseEnough(result, ((3.73053f + 3.73053f)/ 2.0f)), "Second execution should return MAF from speed-density.");
	Assert(pRamVariables.MafMode == MafModeSpeedDensity, "MafMode should remain set to MafModeSpeedDensity.");
#endif

	//Test MAF Blending
	pRamVariables.MafMode = MafModeBlending;
	result = CallSpeedDensityHook();
	Assert(AreCloseEnough(result, expectedMafFromSensor), "Checking blend mode code, cell should be zero and return maf sensor value.");
	Assert(pRamVariables.MafMode == MafModeBlending, "MafMode should remain set.");
	//add another test at mixed load cell (50% blend)
	*pManifoldAbsolutePressure = 700.0f; // Corresponds to -9.5psiG, which is normal for idle.
	result = CallSpeedDensityHook();
	Assert(AreCloseEnough(pRamVariables.SDMafBlendRatio, 0.5555555f),"Checking Blend ratio");
	Assert(AreCloseEnough(pRamVariables.MafFromSpeedDensity, 11.52687f),"Checking SD value"); 
	Assert(AreCloseEnough(result, (expectedMafFromSensor*(1-0.5555555f)+(11.52687f*0.5555555f))), "Checking blend mode code, cell should be zero and return maf sensor value.");
	Assert(pRamVariables.MafMode == MafModeBlending, "MafMode should remain set.");
	//Clear manifold pressure
	*pManifoldAbsolutePressure = 268.917649;;

#if VE_RAMTUNING	
	//Test RAM table 
	*pEngineSpeed = 1000.0f;
	*pManifoldAbsolutePressure = 268.917649; // Corresponds to -9.5psiG, which is normal for idle.	
	*pAtmoPress = 700;
	*pIntakeAirTemp = 15;
	pRamVariables.VERamFlag = 1;
	result = CallSpeedDensityHook();
	Assert(AreCloseEnough(result, 0), "Checking blend mode code, cell should be zero and return maf sensor value.");
	//populate table
	extern float VE_COLS1[];
	extern float VE_ROWS1[];
	extern short VE_DATA1[];
	
	int i;
	float* fpoint = pRamVariables.VERamCols;
	for (i=0; i < 24; i++)
	{
	*fpoint = VE_COLS1[i];
	fpoint += 0x1;
	}
	fpoint = pRamVariables.VERamRows;
	for (i=0; i < 24; i++)
	{
	*fpoint = VE_ROWS1[i];
	fpoint += 0x1;
	}
	short* spoint = pRamVariables.VERamData;
	for (i=0; i < 576; i++)
	{
	*spoint = VE_DATA1[i];
	spoint += 0x1;
	}
	result = CallSpeedDensityHook();
	Assert(AreCloseEnough(result, expectedMafFromSpeedDensity), "Checking blend mode code, cell should be zero and return maf sensor value.");


#endif	
	
	pRamVariables.MafMode = MafModeSensor;
	
}
#endif

