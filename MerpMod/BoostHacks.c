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

#if WGDC_MAIN_HOOK
EcuHacksMain();
#endif

#if BOOST_HACKS	

	//Calculated gear is a BYTE!
	float cgear = (char)*pCurrentGear;
	float PGWGInitial;
	float PGWGMax;
	float WGDCInitialComp;
	float WGDCMaxComp;

	#if PGWG_RAMTUNING
		if(pRamVariables.PGWGRamFlag = 0x01)
		{
			PGWGInitial = Pull3DHooked(&PGWGRamTable, cgear, *pEngineSpeed);
			PGWGMax = PGWGInitial;
		}
		else
		{
	#endif
	
	#if SWITCH_HACKS
		PGWGInitial = BlendAndSwitch(PGWGTableGroup, cgear, *pEngineSpeed);
		PGWGMax = PGWGInitial;
	#else
		PGWGInitial = Pull3DHooked(PGWGTable1i, cgear, *pEngineSpeed);
		PGWGMax = PGWGInitial;
	#endif

	#if PGWG_RAMTUNING
		}
	#endif


	#if WGDC_RAMTUNING
		if(pRamVariables.WGDCInitialRamFlag = 0x01)
		{
			WGDCInitialComp = Pull3DHooked(&WGDCInitialRamTable, *pReqTorque, *pEngineSpeed);
			WGDCMaxComp = Pull3DHooked(&WGDCMaxRamTable, *pReqTorque, *pEngineSpeed);
		}
		else
		{
	#endif
	
	#if SWITCH_HACKS
		WGDCInitialComp = BlendAndSwitch(WGDCInitialTableGroup, *pReqTorque, *pEngineSpeed);
		WGDCMaxComp = BlendAndSwitch(WGDCMaxTableGroup, *pReqTorque, *pEngineSpeed);
	#else
		WGDCInitialComp = Pull3DHooked(WGDCInitialTable1i, *pReqTorque, *pEngineSpeed);
		WGDCMaxComp = Pull3DHooked(WGDCMaxTable1i, *pReqTorque, *pEngineSpeed);
	#endif
	
	#if WGDC_RAMTUNING
		}
	#endif
	
	pRamVariables.PGWGMaxComp = WGDCMaxComp;
	pRamVariables.PGWGInitialComp = WGDCInitialComp;
	PGWGInitial *= WGDCInitialComp;
	PGWGMax *= WGDCMaxComp;
	pRamVariables.WGDCInitialTarget = PGWGInitial;
	pRamVariables.WGDCMaxTarget = PGWGMax;
	
	if(pRamVariables.BoostHackEnable == HackEnabled)
	{
		#if PROG_MODE
		if(pRamVariables.ValetMode == ValetModeEnabled)
		{
			pRamVariables.WGDCInitialOutput = WGDCInitialComp * Pull3DHooked(&PGWGTableValetMode, *pReqTorque, *pEngineSpeed);
			pRamVariables.WGDCMaxOutput = WGDCMaxComp * Pull3DHooked(&PGWGTableValetMode, *pReqTorque, *pEngineSpeed);
		}
		#endif
		#if WGDC_LOCK
		#if PROG_MODE
		else
		#else
		else if
		#endif
		//Apply locks
		(*pEngineSpeed < RPMLockWGDC && *pThrottlePlate > ThrottleLockWGDC)
		{
			pRamVariables.WGDCInitialOutput = 100.0;
			pRamVariables.WGDCMaxOutput = 100.0;
		}
		#endif
		#if WGDC_LOCK || PROG_MODE
		else
		#endif
		{
			pRamVariables.WGDCInitialOutput = PGWGInitial;
			pRamVariables.WGDCMaxOutput = PGWGMax;	
		}
	}
	else
	{
		//TODO: Might need to use conditionals here! Do some roms use Requested Torque lookups??
		pRamVariables.WGDCInitialOutput = Pull3DHooked((void*)OEMWGDCInitialTable, *pThrottlePlate, *pEngineSpeed);
		pRamVariables.WGDCMaxOutput = Pull3DHooked((void*)OEMWGDCMaxTable, *pThrottlePlate, *pEngineSpeed);	
	}
		
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
	float PGTB;
	float TargetBoostComp;

	#if PGWG_RAMTUNING
		if(pRamVariables.PGWGRamFlag = 0x01)
		{
			PGTB = Pull3DHooked(&PGTBRamTable, cgear, *pEngineSpeed);
		}
		else
		{
	#endif
		
	#if SWITCH_HACKS
		PGTB = BlendAndSwitch(PGTBTableGroup, cgear, *pEngineSpeed);
	#else
		PGTB = Pull3DHooked(PGTBTable1i, cgear, *pEngineSpeed);
	#endif
		
	#if PGTB_RAMTUNING
		}
	#endif
	
	
	#if TARGET_BOOST_RAMTUNING
		if(pRamVariables.TargetBoostRamFlag = 0x01)
		{
			TargetBoostComp = Pull3DHooked(&TargetBoostRamTable, *pReqTorque, *pEngineSpeed);
		}
		else
		{
	#endif

	#if SWITCH_HACKS
		TargetBoostComp = BlendAndSwitch(TargetBoostTableGroup, *pReqTorque, *pEngineSpeed);
	#else
		TargetBoostComp = Pull3DHooked(TargetBoostTable1i, *pReqTorque, *pEngineSpeed);
	#endif
	
	#if TARGET_BOOST_RAMTUNING
		}
	#endif
	
	pRamVariables.PGTBComp = TargetBoostComp;
	
	PGTB = ( ( PGTB - 760) * TargetBoostComp) + 760; //COMP IS APPLIED TO RELATIVE UNITS NOT ABSOLUTE!!
	
	pRamVariables.TargetBoostTarget = PGTB;
	
	if(pRamVariables.BoostHackEnable == HackEnabled)
	{
		if(pRamVariables.ValetMode == ValetModeEnabled)
		{
			pRamVariables.TargetBoostOutput = Pull3DHooked(&PGTBTableValetMode, *pReqTorque, *pEngineSpeed);
		}
		else
		{
			pRamVariables.TargetBoostOutput = PGTB;
		}
	}
	else
	{		
		//TODO: Need to use conditionals here! Some roms use Requested Torque lookups!
		pRamVariables.TargetBoostOutput = Pull3DHooked((void*)OEMTargetBoostTable, *pThrottlePlate, *pEngineSpeed);			
	}
}
#endif
#endif