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

float DefaultALSTimingLock SPEEDDENSITYDATA = -10.0f;
float DefaultRIMTimingLock SPEEDDENSITYDATA = 10.0f;
float DefaultALSFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultRIMFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultALSBoostLimit SPEEDDENSITYDATA = 1380.0f;
float DefaultALSTargetIdleSpeed SPEEDDENSITYDATA = 4000.0f;
float DefaultALSTargetIdleSpeedFCRI SPEEDDENSITYDATA = 2000.0f;
float ALSWGDC SPEEDDENSITYDATA = 1.0f;// = 100%
float ALSAVCS SPEEDDENSITYDATA = 0.0f;
float ALSAcceleratorTrigger SPEEDDENSITYDATA = 55.0f;
float ALSVehicleSpeedEnable SPEEDDENSITYDATA = 45.0f;//kph, 28mph = 45kph
float ALSVehicleSpeedDisable SPEEDDENSITYDATA = 1.0f;//kph
float RIMVehicleSpeedDisable SPEEDDENSITYDATA = 12.0f;//kph
float ALSRPMLimit SPEEDDENSITYDATA = 3500.0f;
float ALSRequestedTorque SPEEDDENSITYDATA = 0.0f;//20%tps = 300 KEEP THIS LOW TO PREVENT CLUTCH SLIP!
float ALSTPS SPEEDDENSITYDATA = 40.0f;
unsigned char ALSCutMode SPEEDDENSITYDATA = 0x01;
unsigned char RIMCutMode SPEEDDENSITYDATA = 0x01;
unsigned char RollingAntiLagEnabled SPEEDDENSITYDATA = HackDisabled;// = 0x00
float FCRIPedalThresh SPEEDDENSITYDATA = 1.0f;
float ALSPedalThresh SPEEDDENSITYDATA = 20.0f;
float DefaultRimRPMDiff SPEEDDENSITYDATA = 15.0f;
float ECTALSThreshold SPEEDDENSITYDATA = 30.0f;//86 fahrenheit
float ALSRPMDeltaLimit SPEEDDENSITYDATA = 1500.0f;

#if ALS_RAMTUNING
float DefaultALSPOLFRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSTimingRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSAVCSRamTuning SPEEDDENSITYDATA = 0.0f;
float ALSPOLFRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSTimingRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSAVCSRamTuningAdder SPEEDDENSITYDATA = 0.0f;

#endif
#endif
