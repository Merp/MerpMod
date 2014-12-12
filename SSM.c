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

#if SSM_HACKS

float (*FloatToShortHooked)(float input, float grad, float offs) __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sFloatToShort;

void SSMHack1()

{
	FloatToShortHooked(*pEngineSpeed, 0.25, 0.0);
}

#endif

