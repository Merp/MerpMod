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

#if ALS_HACKS

float DefaultALSTimingLock SPEEDDENSITYDATA = -17.0f;
float DefaultRIMTimingLock SPEEDDENSITYDATA = 10.0f;
float DefaultALSFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultRIMFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultALSBoostLimit SPEEDDENSITYDATA = 1380.0f;
float DefaultALSTargetIdleSpeed SPEEDDENSITYDATA = 3500.0f;
float DefaultALSTargetIdleSpeedFCRI SPEEDDENSITYDATA = 1500.0f;
float ALSWGDC SPEEDDENSITYDATA = 1.0f;// = 100%
float ALSAVCS SPEEDDENSITYDATA = 0.0f;
float ALSAcceleratorTrigger SPEEDDENSITYDATA = 20.0f;
float ALSVehicleSpeedEnable SPEEDDENSITYDATA = 45.0f;//kph, 28mph = 45kph
float ALSVehicleSpeedDisable SPEEDDENSITYDATA = 1.0f;//kph
float RIMVehicleSpeedDisable SPEEDDENSITYDATA = 24.0f;//kph
float ALSRPMLimit SPEEDDENSITYDATA = 2500.0f;
float ThrottleRPMDenom SPEEDDENSITYDATA = 130.0f;
float ThrottleBoostMult SPEEDDENSITYDATA = 5.0f;
unsigned char ALSCutMode SPEEDDENSITYDATA = 0x00;
unsigned char RIMCutMode SPEEDDENSITYDATA = 0x01;
unsigned char RollingAntiLagEnabled SPEEDDENSITYDATA = HackEnabled;// = 0x00
float FCRIPedalThresh SPEEDDENSITYDATA = 1.0f;
float ALSPedalThresh SPEEDDENSITYDATA = 20.0f;
float DefaultRimRPMDiff SPEEDDENSITYDATA = 15.0f;
float ECTALSThreshold SPEEDDENSITYDATA = 30.0f;//86 fahrenheit
//short PedalKick SPEEDDENSITYDATA = 0x4980;

///////////////////
//ALSTPS Table
///////////////////
ThreeDTable ALSTPSTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float ALSTPSCols[17] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1.2,1.5,2.0,3.0,4.0,5.0,6.0,7.0,8.0,10.0,12.0,14.0,18.0,22.0,26.0,30.0,35.0};
float ALSTPSRows[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{0.0,1.0,2.0,3.0,4.0,5.0};
short ALSTPSData[102] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808,
33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808,
33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808,
33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808,
33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808,
33,156,347,702,1028,1331,1622,1874,2126,2579,3022,3420,4168,4840,5637,6760,8808};

ThreeDTable ALSTPSTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 17,
	.rowCount = 6,
	.columnHeaderArray = ALSTPSCols,
	.rowHeaderArray = ALSTPSRows,
	.tableCells = ALSTPSData,
	.tableType = UInt16Table3D,
	.multiplier = 0.002270655357f,
	.offset = 0 };


#if ALS_RAMTUNING
float DefaultALSPOLFRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSTimingRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSAVCSRamTuning SPEEDDENSITYDATA = 0.0f;
float ALSPOLFRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSTimingRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSAVCSRamTuningAdder SPEEDDENSITYDATA = 0.0f;

#endif
#endif
