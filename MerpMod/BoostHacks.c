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

#if WGDC_HOOK_DEFINED

//Defines the function pointer to the existing WGDC Pull routine
float (*WGDCHooked)() __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sWgdc;

void WGDCHack()
{

EcuHacksMain();

#if BOOST_HACKS	

	//Calculated gear is a BYTE!
	float cgear = (unsigned char)*pCurrentGear;
	float PGWGComp;
	float WGDCInitial;
	float WGDCMax;

	#if PGWG_RAMTUNING
		if(pRamVariables->PGWGRamFlag = 0x01)
		{
			PGWGComp = Pull3DHooked(&PGWGRamTable, cgear, *pEngineSpeed);
		}
		else
		{
	#endif
	
	#if SWITCH_HACKS
		PGWGComp = BlendAndSwitch(PGWGTableGroup, cgear, *pEngineSpeed);
	#else
		PGWGComp = Pull3DHooked(PGWGTable1i, cgear, *pEngineSpeed);
	#endif

	#if PGWG_RAMTUNING
		}
	#endif


	#if WGDC_RAMTUNING
		if(pRamVariables->WGDCInitialRamFlag = 0x01)
		{
			WGDCInitial = Pull3DHooked(&WGDCInitialRamTable, *pReqTorque, *pEngineSpeed);
			WGDCMax = Pull3DHooked(&WGDCMaxRamTable, *pReqTorque, *pEngineSpeed);
		}
		else
		{
	#endif
	
	#if SWITCH_HACKS
		WGDCInitial = BlendAndSwitch(WGDCInitialTableGroup, *pReqTorque, *pEngineSpeed);
		WGDCMax = BlendAndSwitch(WGDCMaxTableGroup, *pReqTorque, *pEngineSpeed);
	#else
		WGDCInitial = Pull3DHooked(WGDCInitialTable1i, *pReqTorque, *pEngineSpeed);
		WGDCMax = Pull3DHooked(WGDCMaxTable1i, *pReqTorque, *pEngineSpeed);
	#endif
	
	#if WGDC_RAMTUNING
		}
	#endif
	
	#if ALS_HACKS
		if (pRamVariables->ALSActive == 2 || pRamVariables->ALSActive == 4)
			{
				pRamVariables->WGDCInitial = ALSWGDC;
				pRamVariables->WGDCMax = ALSWGDC;
			}
		else
			{
	#endif
				pRamVariables->PGWGComp = PGWGComp;	
				pRamVariables->WGDCInitial = WGDCInitial * PGWGComp;
				pRamVariables->WGDCMax = WGDCMax * PGWGComp;
	#if ALS_HACKS
			}
	#endif
	
	#if WGDC_LOCK
	}
	#endif
	
#endif

	//Finish Pulling WGDC
	WGDCHooked();
	
#if BOOST_HACKS
	TargetBoostHack();
#endif
}

#if BOOST_HACKS
void TargetBoostHack()
{
		//Calculated gear is a BYTE!
	float cgear = (unsigned char)*pCurrentGear;
	float PGTBComp;
	float TargetBoost;

	#if PGWG_RAMTUNING
		if(pRamVariables->PGWGRamFlag = 0x01)
		{
			PGTBComp = Pull3DHooked(&PGTBRamTable, cgear, *pEngineSpeed);
		}
		else
		{
	#endif
		
	#if SWITCH_HACKS
		PGTBComp = BlendAndSwitch(PGTBTableGroup, cgear, *pEngineSpeed);
	#else
		PGTBComp = Pull3DHooked(PGTBTable1i, cgear, *pEngineSpeed);
	#endif
		
	#if PGTB_RAMTUNING
		}
	#endif
	
	
	#if TARGET_BOOST_RAMTUNING
		if(pRamVariables->TargetBoostRamFlag = 0x01)
		{
			TargetBoost = Pull3DHooked(&TargetBoostRamTable, *pReqTorque, *pEngineSpeed);
		}
		else
		{
	#endif

	#if SWITCH_HACKS
		TargetBoost = BlendAndSwitch(TargetBoostTableGroup, *pReqTorque, *pEngineSpeed);
	#else
		TargetBoost = Pull3DHooked(TargetBoostTable1i, *pReqTorque, *pEngineSpeed);
	#endif
	
	#if TARGET_BOOST_RAMTUNING
		}
	#endif
	
	pRamVariables->PGTBComp = PGTBComp;

	#if ALS_HACKS
		if (pRamVariables->ALSActive == 2 || pRamVariables->ALSActive == 4)
		{
			pRamVariables->TargetBoost = DefaultALSBoostLimit;
		}
		else
		{
	#endif
			pRamVariables->TargetBoost = TargetBoost * PGTBComp;
	#if ALS_HACKS
		}
	#endif
}
#endif
#endif
