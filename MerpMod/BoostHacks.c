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
	float cgear = (char)*pCurrentGear;

	#if PGWG_RAMTUNING
		if(pRamVariables->PGWGRamFlag = 0x01)
		{
			pRamVariables->PGWGComp = Pull3DHooked(&PGWGRamTable, cgear, *pEngineSpeed);
		}
		else
		{
	#endif
	pRamVariables->PGWGComp	= BlendAndSwitch(PGWGTableGroup, cgear, *pEngineSpeed);

	#if PGWG_RAMTUNING
		}
	#endif

	pRamVariables->WGDCMax = BlendAndSwitch(WGDCMaxTableGroup, *pReqTorque, *pEngineSpeed);
	pRamVariables->WGDCInitial = BlendAndSwitch(WGDCInitialTableGroup, *pReqTorque, *pEngineSpeed);
	
	#if WGDC_LOCK
	//Apply locks
	if(*pEngineSpeed < RPMLockWGDC && *pThrottlePlate > ThrottleLockWGDC)
	{
		pRamVariables->WGDCInitial = 100.0;
		pRamVariables->WGDCMax = 100.0;
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
	float cgear = (char)*pCurrentGear;

	#if PGWG_RAMTUNING
		if(pRamVariables->PGWGRamFlag = 0x01)
		{
			pRamVariables->PGTBComp = Pull3DHooked(&PGTBRamTable, cgear, *pEngineSpeed);
		}
		else
		{
	#endif
		
		pRamVariables->PGTBComp = BlendAndSwitch(PGTBTableGroup, cgear, *pEngineSpeed);
		
	#if PGTB_RAMTUNING
		}
	#endif

		pRamVariables->TargetBoost = BlendAndSwitch(TargetBoostTableGroup, *pReqTorque, *pEngineSpeed);
}
#endif
#endif