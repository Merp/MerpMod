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

	//Conditions for AntiLag And Rotational Idle
	if (pRamVariables->DriveMode == 4)// && *pAf1Res > EGTResistanceThreshold && *pManifoldAbsolutePressure <= DefaultALSBoostLimit)
		{
			if (pRamVariables->ALSActive == 0)
				{
					pRamVariables->ALSActive = 0x01;
				}
			else if (pRamVariables->ALSActive == 1)
				{
					//Rotational Idle Specific
					if (TestIdleSwitch())
						{
							pRamVariables->ALSActive = 0x02;
						}

					else if (*pAcceleratorPedal >= ALSAcceleratorTrigger)
						{
							pRamVariables->ALSActive = 0x03;
						}
					else
						{
							pRamVariables->ALSActive = 0x01;
						}
				}
			else if (pRamVariables->ALSActive == 2 && !TestIdleSwitch())
				{
					pRamVariables->ALSActive = 0x01;
				}

			//ALS Specific
			else if (pRamVariables->ALSActive >= 3 && *pVehicleSpeed >= ALSVehicleSpeedEnable && TestClutchSwitch())
				{
					AntiLag();
				}
			else if (pRamVariables->ALSActive >= 3 && *pVehicleSpeed >= ALSVehicleSpeedEnable)
				{
					pRamVariables->ALSRequestedTorque = 0.0;
					pRamVariables->ALSActive = 0x03;
				}
			else if (pRamVariables->ALSActive >= 3)
				{
					pRamVariables->ALSActive = 0x01;
					pRamVariables->ALSRequestedTorque = 0.0;
				}
			else
				{
					pRamVariables->ALSRequestedTorque = 0.0;
				}
		}
	else
		{
			pRamVariables->ALSActive = 0x00;
		}
}

void AntiLag()
{
	if (*pEngineSpeed <= ALSRPMLimit)
		{
			pRamVariables->ALSActive = 0x04;
			pRamVariables->ALSRequestedTorque = ALSRequestedTorque;
		}
	else
		{
			pRamVariables->ALSActive = 0x03;
		}
}

#endif


