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

void FlexLearn()
{
//AFTER TESTING ALL OUT ADD IN A IF FLEXfUELENABLED SWITCH INTO ECUHACKS.C
	if (pRamVariables->FlexCount >= 6)
		{
			FlexLearnStop();
		}
	else
		{
			Timers(0.0, 10.0, 1);
			if (pRamVariables->TimerUp1 == 1)
				{
					if (*pCPCDutyRatio == 0)//&& LTFTs == 0 && pAirPump == pointless?)
						{
							pRamVariables->FlexFuelRatio = pRamVariables->MapBlendRatio;
							if (pRamVariables->FlexCount < 3)
        						{
        						   FlexRoughCorrect();
        						}
    						else
    						    {
    		    				    FlexFineCorrect();
        						}
						}
					else
						{
						}
				}
			else
				{
				}
				
   			if (pRamVariables->FlexWait == 1)
				{
				    Timers(0.0, 30.0, 2);
					if (pRamVariables->TimerUp2 == 1)
        				{
        		    		pRamVariables->FlexWait = 0x00;
       					}
    				else
        				{
       					}
				}
				
			else
				{
				}
		}
}

void FlexRoughCorrect()
{
    if (pRamVariables->FlexWait == 0)
    {
		
        if (*pSTFTs1 > FlexRoughFTs)
            {
                pRamVariables->FlexFuelRatio += FlexRoughRatio;
                pRamVariables->FlexWait = 0x01;
                pRamVariables->FlexCount += 1;
            }
        else if (*pSTFTs1 < (0.0 - FlexRoughFTs))
            {
                pRamVariables->FlexFuelRatio -= FlexRoughRatio;
                pRamVariables->FlexWait = 0x01;
                pRamVariables->FlexCount += 1;
            }
        else
            {
                pRamVariables->FlexCount += 1;
                pRamVariables->FlexWait = 0x01;
            }
		BandPass(pRamVariables->FlexFuelRatio, 0.0, 1.0);
    }
	else
	{
	}
}

void FlexFineCorrect()
{
    if (pRamVariables->FlexWait == 0)
    {
		
        if (*pSTFTs1 > FlexFineFTs)
            {
                pRamVariables->FlexFuelRatio += FlexFineRatio;
                pRamVariables->FlexWait = 0x01;
                pRamVariables->FlexCount += 1;
            }
        else if (*pSTFTs1 < (0.0 - FlexFineFTs))
            {
                pRamVariables->FlexFuelRatio -= FlexFineRatio;
                pRamVariables->FlexWait = 0x01;
                pRamVariables->FlexCount += 1;
            }
        else
            {
                pRamVariables->FlexCount += 1;
                pRamVariables->FlexWait = 0x01;
            }
		BandPass(pRamVariables->FlexFuelRatio, 0.0, 1.0);
    }

    else
    {
    }
}

void FlexLearnStop()
{
	pRamVariables->FuelUp = 0x00;
	pRamVariables->FlexLearnHasRun = 0x01;//Delete when tested??  Or leave?
	pRamVariables->FlexCount = 0x00;
	//unlock LTFTs pRamVariables->LTFTs = OEM;
}

void FlexRatioUser()
{	
		if (pRamVariables->KillWait == 0)
		{
			if (pRamVariables->FlexFuelRatio < 0.5)
				{
					pRamVariables->FlexFuelRatio += FlexRatioUserJump;
				}
			else if (pRamVariables->FlexFuelRatio > 0.5)
				{
					pRamVariables->FlexFuelRatio -= FlexRatioUserJump;
				}
			else
				{
				}
		}
		else
		{
		}
		
	pRamVariables->KillWait = 0x01;
	BandPass(pRamVariables->FlexFuelRatio, 0.0, 1.0);
}


#endif