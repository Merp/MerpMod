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

void ALSActivate()
	
{
	//DOUBLE CHECK FUEL LOCK FOR ALS BEFORE ACTIVATING FUELHACKS!
	//Conditions for AntiLag And Rotational Idle
	if (pRamVariables->DriveMode == 4)
		{
			pRamVariables->ALSEnable = 0x01;
		}
	else
		{
			pRamVariables->ALSEnable = 0x00;
		}
		
	if (pRamVariables->ALSEnable == 0x01 && *pAcceleratorPedal == 0 && TestIdleSwitch())
		{
			pRamVariables->ALSActive = 0x01;
		}
	else
		{
			pRamVariables->ALSActive = 0x00;
		}
/*		
	if (pRamVariables->ALSActive == 0)
		{
			//Rotational Idle/ALS Specifics
		}
	else
		{
		}
*/
}

#endif
