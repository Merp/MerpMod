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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Flex Fuel constants
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float CyclesPerSec SPEEDDENSITYDATA = 15.5f;
unsigned char FlexFuelEnabled SPEEDDENSITYDATA = HackDisabled;
float FlexRoughFTs SPEEDDENSITYDATA = 12.0f;
float FlexFineFTs SPEEDDENSITYDATA = 5.0f;
float FlexRoughRatio SPEEDDENSITYDATA = 0.3f;
float FlexFineRatio SPEEDDENSITYDATA = 0.1f;
float FuelRatio1 SPEEDDENSITYDATA = 0.90f;
float FuelRatio2 SPEEDDENSITYDATA = 0.85f;
float FuelCheckWaitTime SPEEDDENSITYDATA = 30.0f;
float FlexRatioUserJump SPEEDDENSITYDATA = 0.5f;

//unsigned char FuelUpWaitMinutes = 0;
//unsigned char FuelUpWaitSeconds = 30.0;
//unsigned char O2WaitMinutes = 0;
//unsigned char O2WaitSeconds = 30.0;


#endif