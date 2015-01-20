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

float DefaultALSTimingLock SPEEDDENSITYDATA = 5.0f;
float DefaultALSFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultALSBoostLimit SPEEDDENSITYDATA = 1381.0f;
float DefaultALSTargetIdleSpeed SPEEDDENSITYDATA = 2000.0f;
float ALSWGDC SPEEDDENSITYDATA = 100.0f;
float ALSAVCS SPEEDDENSITYDATA = 0.0f;
float ALSAcceleratorTrigger SPEEDDENSITYDATA = 55.0f;
float ALSVehicleSpeedEnable SPEEDDENSITYDATA = 45.0f;//kph, 28mph = 45kph
float ALSRPMLimit SPEEDDENSITYDATA = 3500.0f;
float ALSRequestedTorque SPEEDDENSITYDATA = 100.0f;//20%tps = 300
//unsigned short ThrottleKickVoltsMin SPEEDDENSITYDATA = 0x4800;//4800 = 22% Pedal, 22C0 = 0%, A300 = 100%
//unsigned short ThrottleKickVoltsMax SPEEDDENSITYDATA = 0xA300;

#if ALS_RAMTUNING
float DefaultALSPOLFRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSTimingRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSAVCSRamTuning SPEEDDENSITYDATA = 0.0f;
float ALSPOLFRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSTimingRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSAVCSRamTuningAdder SPEEDDENSITYDATA = 0.0f;

#endif
#endif
