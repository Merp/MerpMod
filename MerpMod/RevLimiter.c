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

#if CRUISE_CONTROL && LC_ADJUST //does this need #if for CC?

void LCAdjustCruiseToggled(unsigned char state)
{
	if(pRamVariables->LCEngaged == 1)
	{
		if(state == ToggleResume && (pRamVariables->LaunchControlCut < pRamVariables->RedLineCut))
			pRamVariables->LaunchControlCut += LCAdjustStep;
		else if (state == ToggleCoast && (pRamVariables->LaunchControlCut > 2000))
			pRamVariables->LaunchControlCut -= LCAdjustStep;
	}
}
#endif

#if AUTO_TRANS

void RevLimCode()
{
		if (TestBrakeSwitch() && *pVehicleSpeed < pRamVariables->LaunchControlSpeedMax && *pThrottlePlate > LCMinimumThrottle )
			pRamVariables->LCEngaged = 1;
		else
			pRamVariables->LCEngaged = 0;
}

#else

void RevLimReset()
{
	pRamVariables->RevLimCut = pRamVariables->RedLineCut;
				pRamVariables->RevLimResume = pRamVariables->RedLineCut - Abs(pRamVariables->RedLineHyst);
				//Disable FFS if clutch is out or brake is pressed
				pRamVariables->FFSEngaged = 0;
				pRamVariables->LCEngaged = 0;
				#ifdef pCurrentGear
				if(*pCurrentGear > 0)
				{
					pRamVariables->FFSGear = *pCurrentGear;
				}
				#endif
}

void RevLimCode()
{	

#if VIN_HACKS
	if (pRamVariables->VinAuth != 0x01)
	{
		// Set the rev-limit fuel cut flag.
		*pFlagsRevLim |= RevLimBitMask;
		VinCheck();
	} 
	else
	{
#endif

	#ifdef pBrakeFlags
		if (!TestClutchSwitch() || TestBrakeSwitch())
	#else
		if (!TestClutchSwitch())//TODO: if this works, change the rest!!
	#endif
		{
				RevLimReset();
		}
		else
		{
			//check for FFS speed threshold
			if (*pVehicleSpeed > pRamVariables->FlatFootShiftSpeedThreshold 
			&& *pEngineSpeed > pRamVariables->FlatFootShiftRpmThreshold 
			&& pRamVariables->FlatFootShiftMode != 0 
			&& *pThrottlePlate > FFSMinimumThrottle)
			{
				pRamVariables->LCEngaged = 0;
				
				//calculate target rpm
				if(pRamVariables->FFSEngaged == 0)
				{
					pRamVariables->FFSEngaged = 1;
					pRamVariables->FFSRPM = *pEngineSpeed;
				}
			}
			else if (*pVehicleSpeed < pRamVariables->LaunchControlSpeedMax && *pThrottlePlate > LCMinimumThrottle)
			{
				// Launch control rev limiter thresholds.
				pRamVariables->FFSEngaged = 0;
				pRamVariables->LCEngaged = 1;
				pRamVariables->RevLimCut = pRamVariables->LaunchControlCut;
				pRamVariables->RevLimResume = pRamVariables->LaunchControlCut - Abs(pRamVariables->LaunchControlHyst);
			}
			else
				RevLimReset();

			}
	
		if (pRamVariables->FFSEngaged == 1)
		{
			#ifdef pCurrentGear
			if (pRamVariables->FlatFootShiftMode == 2)
			{
				float cut =  pRamVariables->FFSRPM;
				cut *=  GearRatios[(int)pRamVariables->FFSGear + 1]; 
				cut *= 1 / GearRatios[(int)pRamVariables->FFSGear];
				cut += pRamVariables->FlatFootShiftAutoDelta;
				pRamVariables->RevLimCut = cut;
				pRamVariables->RevLimResume = pRamVariables->RevLimCut - Abs(pRamVariables->FlatFootShiftHyst);
			}
			else
			{
			#endif
			
				float cut = pRamVariables->RedLineCut - Abs(pRamVariables->FlatFootShiftStaticDelta);
				pRamVariables->RevLimCut = cut;
				pRamVariables->RevLimResume = cut - Abs(pRamVariables->FlatFootShiftHyst);
			
			#ifdef pCurrentGear
			}
			#endif
			pRamVariables->FFSEngaged = 2;
		}
		
	#if PROG_MODE
		if (pRamVariables->ValetMode != ValetModeDisabled)
		{
			pRamVariables->RedLineCut = ValetModeRevLim;
		}
	#endif

	#if SPARK_HACKS
		if (pRamVariables->RevLimMode == RevLimModeSparkCut)
		{
			if (*pEngineSpeed > pRamVariables->RevLimCut)
			{
				// Set the rev-limit fuel cut flag.
				*LCSparkCutFlag |= 0x01;
			} 
			else if (*pEngineSpeed < pRamVariables->RevLimResume)
			{
				// Clear the rev-limit fuel cut flag.
				*LCSparkCutFlag &= 0xFE;
			}
		}
		else if (pRamVariables->RevLimMode == RevLimModeComboCut)
		{
			if (*pEngineSpeed > pRamVariables->RevLimResume)
			{
				// Set the rev-limit fuel cut flag.
				*LCSparkCutFlag |= 0x01;
			} 
			else if (*pEngineSpeed < (pRamVariables->RevLimResume - 50))	///TODO: Add this as an adjustable value??
			{
				// Clear the rev-limit fuel cut flag.
				*LCSparkCutFlag &= 0xFE;
			}
			if (*pEngineSpeed > pRamVariables->RevLimCut)
			{
				// Set the rev-limit fuel cut flag.
				//*((char*)pFlagsRevLim) |= RevLimBitMask; 
				*pFlagsRevLim |= RevLimBitMask;
			} 
			else if (*pEngineSpeed < pRamVariables->RevLimResume)
			{
				// Clear the rev-limit fuel cut flag.
				//*((char*)pFlagsRevLim) &= !RevLimBitMask;
				*pFlagsRevLim &= ~RevLimBitMask;
			}
		}
		else
		{
	#endif
		if (*pEngineSpeed > pRamVariables->RevLimCut || *pEngineSpeed > pRamVariables->RedLineCut)
		{
			*pFlagsRevLim |= RevLimBitMask;
		} 
		else if (*pEngineSpeed < pRamVariables->RevLimResume)
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
