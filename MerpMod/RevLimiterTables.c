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

#if REVLIM_HACKS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Rev limiter tables start here
//!! Cut/resume thresholds
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char DefaultRevLimMode REVLIMDATA = RevLimModeFuelCut;
float DefaultRedLineCut REVLIMDATA = 7200.0f;
float DefaultRedLineHyst REVLIMDATA = 50.0f;
float DefaultFlatFootShiftHyst REVLIMDATA = 50.0f;
float DefaultFlatFootShiftStaticDelta REVLIMDATA = 4000.0f;
float DefaultFlatFootShiftSpeedThreshold REVLIMDATA = 40.0f;
float DefaultFlatFootShiftRpmThreshold REVLIMDATA = 3500.0f;
float DefaultLaunchControlSpeedMax REVLIMDATA = 5.0f;
float DefaultLaunchControlCut REVLIMDATA = 4000.0f;
float DefaultLaunchControlHyst REVLIMDATA = 50.0f;

#ifdef pCurrentGear
unsigned char DefaultFlatFootShiftMode	REVLIMDATA = 1;
float DefaultFlatFootShiftAutoDelta REVLIMDATA = 0.0f;
float GearRatios[6] REVLIMDATA = 
{3.636,2.375,1.761,1.346,0.971,0.756};
#endif

float LCMinimumThrottle REVLIMDATA =  60.0f;
float FFSMinimumThrottle REVLIMDATA = 60.0f;

#if PROG_MODE
float ValetModeRevLim REVLIMDATA = 5000.0f;
#endif

#if LC_ADJUST
float LCAdjustStep REVLIMDATA = 30.0f;
#endif

#endif