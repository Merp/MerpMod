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
if (pRamVariables->FlexFuelEnabled == HackEnabled)
{
	if (TestClutchSwitch() && TestDefoggerSwitch() && TestCruiseResumeSwitch() && TestBrakeSwitch())
		{
			pRamVariables->FuelUp = 0x01;
			pRamVariables->FuelCheckSwitch = 0x14;
			FlexRatioUser();
			//Lock LTFTs;
			//Enable MapRatio CELFlash Check
		}
	else if (pRamVariables->FuelUp == 1)
		{
			//Iam = InitialIAM
			FlexLearn();
		}
	else if (pRamVariables->FuelCheckSwitch == 20 && *pEngineSpeed > 400)
		{
			pRamVariables->FuelCheckSwitch = 0x00;
		}
	else if (pRamVariables->FuelCheckSwitch == 0 && *pEngineSpeed > 400)
		{
		}
	else
		{
		}
	if (*pEngineSpeed < 400 && pRamVariables->FuelCheckSwitch < 20)
		{
			pRamVariables->FlexLearnHasRun = 0x00;

			if (pRamVariables->FuelCheckSwitch == 0)
				{
					Timer(0.0, 20.0);
					LoadFuelLevels();
				}
			else if (pRamVariables->FuelCheckSwitch >= 3)
				{
					pRamVariables->FuelCheckSwitch = 0x14;
					pRamVariables->FuelUp = 0x00;
				}
			else
				{
					Timer(0.0, FuelCheckWaitTime);
					LoadFuelLevels();
				}
		}
	else
		{
		}
}
}
void LoadFuelLevels()
{
			
	if (pRamVariables->TimerUp == 1 && pRamVariables->FuelLevelSwitch == 0)
		{
			pRamVariables->FuelLevel1 = *pFuelLevel;
			pRamVariables->FuelLevelSwitch += 1;
		}			
	else if (pRamVariables->FuelLevelSwitch == 1)
		{
			pRamVariables->FuelLevel2 = *pFuelLevel;
			pRamVariables->FuelLevelSwitch += 1;
		}
	else if (pRamVariables->FuelLevelSwitch == 2)
		{
			pRamVariables->FuelLevel3 = *pFuelLevel;
			pRamVariables->FuelLevelSwitch += 1;
		}
	else if (pRamVariables->FuelLevelSwitch == 3)
		{
			CheckFuelLevels();
		}
	else
		{
		}
}

void CheckFuelLevels()
{
	
	pRamVariables->FuelLevelSwitch = 0x00;
	pRamVariables->StartTimer = 0.0;
	
	if (pRamVariables->FuelCheckSwitch == 0)
		{
			pRamVariables->FuelCheck1 = ((pRamVariables->FuelLevel1 + pRamVariables->FuelLevel2 + pRamVariables->FuelLevel3) / 3);
			pRamVariables->FuelCheckSwitch += 1;
		}
	else if (pRamVariables->FuelCheckSwitch == 1)
		{	
			pRamVariables->FuelCheck2 = ((pRamVariables->FuelLevel1 + pRamVariables->FuelLevel2 + pRamVariables->FuelLevel3) / 3);
			if (pRamVariables->FuelCheck2 <= (pRamVariables->FuelCheck1 * FuelRatio1))
				{
					pRamVariables->FuelUp = 0x01;
					pRamVariables->FuelCheckSwitch = 0x14;
					//Lock LTFTs;
				}
			else
				{
					pRamVariables->FuelCheckSwitch += 1;
				}
		}
	else if (pRamVariables->FuelCheckSwitch == 2)
		{	
			pRamVariables->FuelCheck2 = ((pRamVariables->FuelLevel1 + pRamVariables->FuelLevel2 + pRamVariables->FuelLevel3) / 3);
			if (pRamVariables->FuelCheck2 <= (pRamVariables->FuelCheck1 * FuelRatio2))
				{
					pRamVariables->FuelUp = 0x01;
					pRamVariables->FuelCheckSwitch = 0x14;
					//Lock LTFTs;
				}
			else
				{
					pRamVariables->FuelCheckSwitch += 1;
				}
		}
	else
		{
		}
}
#endif