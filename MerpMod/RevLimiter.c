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

void TestFFSEntry() ROMCODE;
void TestFFSExit() ROMCODE;
void TestLCEntry() ROMCODE;
void TestLCExit() ROMCODE;

#if REVLIM_HACKS

#if CRUISE_CONTROL && LC_ADJUST //does this need #if for CC?

void LCAdjustCruiseToggled(unsigned char state)
{
	if(pRamVariables.LCEngaged == 1)
	{
		if(state == ToggleResume && (pRamVariables.LaunchControlCut < pRamVariables.RedLineCut))
			pRamVariables.LaunchControlCut += LCAdjustStep;
		else if (state == ToggleCoast && (pRamVariables.LaunchControlCut > 2000))
			pRamVariables.LaunchControlCut -= LCAdjustStep;
	}
}
#endif

#if AUTO_TRANS

void RevLimCode()
{
		if (TestBrakeSwitch() && *pVehicleSpeed < pRamVariables.LaunchControlSpeedMax && *pThrottlePlate > LCMinimumThrottle )
			pRamVariables.LCEngaged = 1;
		else
			pRamVariables.LCEngaged = 0;
}

#else

void RevLimReset()
{
	#if PROG_MODE
		if (pRamVariables.ValetMode != ValetModeDisabled)
		{
			pRamVariables.RevLimCut = ValetModeRevLim;
			pRamVariables.RevLimResume = pRamVariables.RedLineCut - HighPass(pRamVariables.RedLineHyst,0.0f);
		}
		else
		{
	#endif
	pRamVariables.RevLimCut = pRamVariables.RedLineCut;
	pRamVariables.RevLimResume = pRamVariables.RevLimCut - HighPass(pRamVariables.RedLineHyst,0.0f);
	#if PROG_MODE
	}
	#endif
	
	//Disable FFS if clutch is out or brake is pressed
	pRamVariables.FFSEngaged = 0;
	pRamVariables.LCEngaged = 0;
	#ifdef pCurrentGear
	if(*pCurrentGear > 0)
	{
		pRamVariables.FFSGear = *pCurrentGear;
	}
	#endif
}

void TestFFSEntry()
{
	//check for FFS speed threshold
	if (*pVehicleSpeed >= pRamVariables.FlatFootShiftSpeedThreshold
	&& pRamVariables.FlatFootShiftMode != FlatFootShiftModeDisabled 
	&& *pThrottlePlate >= FFSMinimumThrottle)
	{
		
		pRamVariables.LCEngaged = 0;
		
		//calculate target rpm
		if(pRamVariables.FFSEngaged == 0 && *pEngineSpeed > pRamVariables.FlatFootShiftRpmThreshold)
		{
			pRamVariables.FFSEngaged = 1;
			pRamVariables.FFSRPM = *pEngineSpeed;
		}
	}
	else
	{
		pRamVariables.FFSEngaged = 0;
	}
}

void TestLCEntry()
{
	if (pRamVariables.FFSEngaged == 0 && *pVehicleSpeed <= pRamVariables.LaunchControlSpeedMax && *pThrottlePlate >= LCMinimumThrottle 
	#if PROG_MODE
	&& pRamVariables.ValetMode == ValetModeDisabled
	#endif
	)
	{
		// Launch control rev limiter thresholds.
		pRamVariables.LCEngaged = 1;
		pRamVariables.RevLimCut = pRamVariables.LaunchControlCut;
		pRamVariables.RevLimResume = pRamVariables.LaunchControlCut - HighPass(pRamVariables.LaunchControlHyst,0.0f);
	}
}

unsigned char TestClutchSwitchDepressedEvent()
{
	unsigned char ret = 0x00;
	unsigned char result = *pClutchFlags & ClutchBitMask;
	if(result != pRamVariables.ClutchSwitchLast && TestClutchSwitch())
	{
		ret = 0x01;
	}
	pRamVariables.ClutchSwitchLast = result;
	return ret;
}

void TestLCExit()
{
	if(*pVehicleSpeed > pRamVariables.LaunchControlSpeedMax || *pThrottlePlate < LCMinimumThrottle)
	{
		RevLimReset();
	}
}

void TestFFSExit()
{
	if(*pVehicleSpeed < pRamVariables.FlatFootShiftSpeedThreshold || *pThrottlePlate < FFSMinimumThrottle)
	{
		RevLimReset();
	}
}

void RevLimCode()
{	

#if VIN_HACKS
	if (pRamVariables.VinAuth != 0x01)
	{
		// Set the rev-limit fuel cut flag.
		*pFlagsRevLim |= RevLimBitMask;
		VinCheck();
	} 
	else
	{
#endif
		unsigned char testClutchDepressed = TestClutchSwitchDepressedEvent();
		#ifdef pBrakeFlags
		if(!TestClutchSwitch() || TestBrakeSwitch())
		#else
		if(!TestClutchSwitch())
		#endif
		{
			RevLimReset();
		}
		else if(pRamVariables.LCEngaged == 1)
		{
			TestLCExit();
		}
		else if(pRamVariables.FFSEngaged == 2)
		{
			TestFFSExit();
		}
		//no need to test FFS exit, only depends on clutch!
		else if(testClutchDepressed)
		{
			TestFFSEntry();
		}
		else if (pRamVariables.FFSEngaged == 1)
		{
			#ifdef pCurrentGear
			if (pRamVariables.FlatFootShiftMode == FlatFootShiftModeAuto)
			{
				float cut =  pRamVariables.FFSRPM;
				//int gear1 = (int)pRamVariables.FFSGear-1;
				int gear1 = BandPassInt((int)pRamVariables.FFSGear-1, 0, 5);//(sizeof(GearRatios)/sizeof(GearRatios[0]))-1);
				//int gear2 = (int)pRamVariables.FFSGear;
				int gear2 = BandPassInt((int)pRamVariables.FFSGear, 0, 5);// (sizeof(GearRatios)/sizeof(GearRatios[0]))-1);//TODO: SANITIZE THE LOOKUP!!! 
				float ratio1 = GearRatios[gear1];
				float ratio2 = GearRatios[gear2];
				cut *= ratio2;
				cut *= 1/ratio1;
				//cut *=  GearRatios[(int)pRamVariables.FFSGear + 1]; 
				//cut *= 1 / GearRatios[(int)pRamVariables.FFSGear];
				cut += pRamVariables.FlatFootShiftAutoDelta;
				pRamVariables.RevLimCut = LowPass(cut, pRamVariables.RedLineCut);
				pRamVariables.RevLimResume = pRamVariables.RevLimCut - HighPass(pRamVariables.FlatFootShiftHyst,0.0f);
			}
			else
			{
			#endif
			
				float cut = pRamVariables.RedLineCut - HighPass(pRamVariables.FlatFootShiftStaticDelta,0.0f);
				pRamVariables.RevLimCut = LowPass(cut, pRamVariables.RedLineCut);
				pRamVariables.RevLimResume = cut - HighPass(pRamVariables.FlatFootShiftHyst,0.0f);
			
			#ifdef pCurrentGear
			}
			#endif
			pRamVariables.FFSEngaged = 2;
		}
		else
		{
			TestLCEntry();
		}
		
	#if PROG_MODE
		if (pRamVariables.ValetMode != ValetModeDisabled)
		{
			pRamVariables.RevLimCut = ValetModeRevLim;
			pRamVariables.RevLimResume = pRamVariables.RevLimCut - HighPass(pRamVariables.RedLineHyst,0.0f);
		}
	#endif

	#if SPARK_HACKS
		if (pRamVariables.RevLimMode == RevLimModeSparkCut)
		{
			if (*pEngineSpeed > pRamVariables.RevLimCut)
			{
				// Set the rev-limit fuel cut flag.
				*LCSparkCutFlag |= 0x01;
			} 
			else if (*pEngineSpeed < pRamVariables.RevLimResume)
			{
				// Clear the rev-limit fuel cut flag.
				*LCSparkCutFlag &= 0xFE;
			}
		}
		else if (pRamVariables.RevLimMode == RevLimModeComboCut)
		{
			if (*pEngineSpeed > pRamVariables.RevLimResume)
			{
				// Set the rev-limit fuel cut flag.
				*LCSparkCutFlag |= 0x01;
			} 
			else if (*pEngineSpeed < (pRamVariables.RevLimResume - 50))	///TODO: Add this as an adjustable value??
			{
				// Clear the rev-limit fuel cut flag.
				*LCSparkCutFlag &= 0xFE;
			}
			if (*pEngineSpeed > pRamVariables.RevLimCut)
			{
				// Set the rev-limit fuel cut flag.
				//*((char*)pFlagsRevLim) |= RevLimBitMask; 
				*pFlagsRevLim |= RevLimBitMask;
			} 
			else if (*pEngineSpeed < pRamVariables.RevLimResume)
			{
				// Clear the rev-limit fuel cut flag.
				//*((char*)pFlagsRevLim) &= !RevLimBitMask;
				*pFlagsRevLim &= ~RevLimBitMask;
			}
		}
		else
		{
	#endif
		if (*pEngineSpeed > pRamVariables.RevLimCut || *pEngineSpeed > pRamVariables.RedLineCut)
		{
			*pFlagsRevLim |= RevLimBitMask;
		} 
		else if (*pEngineSpeed < pRamVariables.RevLimResume)
		{
			*pFlagsRevLim &= ~RevLimBitMask;
		}	
#if SPARK_HACKS
	}
#endif

#if VIN_HACKS
	}
#endif
}

#endif

#endif
