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
/*
void SSMHack1()

{
	FloatToShortHooked(SSMMapSwitch);
}
//Move To Enums!
enum SSMAddressValues
{
	SSMAddressUndefined = Address,
	SSMAddressMapSwitch = Address,
	SSMAddressMapBlend = Address,
	SSMAddressEmpty1 = Address,
	SSMAddressEmpty2 = Address,
};
enum SSMgradValues
{
	SSMgradUndefined = 0.00,
	SSMgradMapSwitch = 0.00,
	SSMgradMapBlend = 0.00,
	SSMgradEmpty1 = 0.00,
	SSMgradEmpty2 = 0.00,
};
enum SSMoffsValues
{
	SSMoffsUndefined = 0.00,
	SSMoffsMapSwitch = 0.00,
	SSMoffsMapBlend = 0.00,
	SSMoffsEmpty1 = 0.00,
	SSMoffsEmpty2 = 0.00,
};
enum SSMVariableValues
{
	SSMUndefined = (SSMAddressUndefined, SSMgradUndefined, SSMoffsUndefined),
	SSMMapSwitch = (SSMAddressMapSwitch, SSMgradMapSwitch, SSMoffsMapSwitch),
	SSMMapBlend = (SSMAddressMapBlend, SSMgradMapBlend, SSMoffsMapBlend),
	SSMEmpty1 = (SSMAddressEmpty1, SSMgradMapEmpty1, SSMoffsMapEmpty1),
	SSMEmpty2 = (SSMAddressEmpty2, SSMgradMapEmpty2, SSMoffsMapEmpty2),
};
*/