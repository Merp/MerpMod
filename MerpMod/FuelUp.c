/*    Copyright (C) 2014 Scott T Anderson & 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
   
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

void FuelUp()
{
//float	unsigned char ClosedLoop = *pClosedLoopFlags

//	if (&& ClosedLoop == 1)
if (pRamVariables->FuelUp == 1 && *pEngineSpeed > 300)
		{
			pRamVariables->FlexFuelLearning = 0x01;
			pRamVariables->FlexCount += 1;
			FlexLearn();
		}
else
{
	float FuelLevel1;
	float FuelLevel2;
	float FuelLevel3;
	if (*pEngineSpeed <= 400)
		{
			pRamVariables->FuelCheckSwitch = 0x00;
		}
	else
		{
		}
		
	if (pRamVariables->FuelCheckSwitch == 0)
		{
			Timer(0.0, 15.0);
			if (pRamVariables->TimerUp == 1)
				{
				FuelLevel1 = *pFuelLevel;
				//make sure FuelLevel1 doesn't change and stays static value!
				pRamVariables->FuelCheckSwitch = 0x01;
				}
			else
			{
			}
		}
	else
		{
		}

	if (*pEngineSpeed > 400 && pRamVariables->FuelCheckSwitch == 1)
		{
			Timer(0.0, 15.0);
			if (pRamVariables->TimerUp == 1 && pRamVariables->FuelCheckSwitch == 1)
				{
					FuelLevel2 = *pFuelLevel;
					pRamVariables->FuelCheckSwitch = 0x02;
				}
			else
			{
			}
		}
	else
		{
		}
	
	if (pRamVariables->FuelCheckSwitch == 2 && (FuelLevel2 > (FuelLevel1 * 1.1)))
		{
			pRamVariables->FuelUp = 0x01;
			pRamVariables->FuelCheckSwitch = 0x04;
		}
	else if (pRamVariables->FuelCheckSwitch == 2)
		{
			Timer(0.0, 30.0);
			if (pRamVariables->TimerUp == 1 && pRamVariables->FuelCheckSwitch == 2)
				{
					FuelLevel3 = *pFuelLevel;
					pRamVariables->FuelCheckSwitch = 0x03;
				}
			else
			{
			}
		}
	else
		{
		}
		
	if (pRamVariables->FuelCheckSwitch == 3 && (FuelLevel3 > (FuelLevel1 * 1.15)))
		{
			pRamVariables->FuelUp = 0x01;
			pRamVariables->FuelCheckSwitch = 0x04;
		}
	else if (TestClutchSwitch() && TestDefoggerSwitch() && TestCruiseResumeSwitch() && TestBrakeSwitch())
		{
			pRamVariables->FuelUp = 0x01;
			pRamVariables->FuelCheckSwitch = 0x04;
		}
	else if (pRamVariables->FuelCheckSwitch <= 3)
		{
			pRamVariables->FuelUp = 0x00;
		}
	else
		{
		}
}
}

#endif
