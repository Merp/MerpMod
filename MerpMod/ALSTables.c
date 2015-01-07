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

float DefaultALSTimingLock SPEEDDENSITYDATA = 20.0f;
float DefaultALSFuelLock SPEEDDENSITYDATA = 0.35f;
float DefaultALSBoostLimit SPEEDDENSITYDATA = 1381.0f;
float DefaultALSTargetIdleSpeed SPEEDDENSITYDATA = 2000.0f;
float ALSWGDC SPEEDDENSITYDATA = 100.0f;
float ALSAVCS SPEEDDENSITYDATA = 0.0f;

#if ALS_RAMTUNING
float DefaultALSPOLFRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSTimingRamTuning SPEEDDENSITYDATA = 0.0f;
float DefaultALSAVCSRamTuning SPEEDDENSITYDATA = 0.0f;
float ALSPOLFRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSTimingRamTuningAdder SPEEDDENSITYDATA = 0.0f;
float ALSAVCSRamTuningAdder SPEEDDENSITYDATA = 0.0f;

#endif

// float? ALSRevLimit SPEEDDENSITYDATA = 3000.0f;
// float ALSThrottleKick SPEEDDENSITYDATA = 100.0f; ReqTorq? Or unneeded?

#endif
