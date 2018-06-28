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

float (*Pull3DHooked)(ThreeDTable* table, float xLookup, float yLookup) __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sPull3DFloat;
float (*Pull2DHooked)(TwoDTable* table, float xLookup) __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sPull2DFloat;

#if SWITCH_HACKS
float (*ShortToFloatHooked)(unsigned short input, float grad, float offs) __attribute__ ((section ("RomHole_Functions"))) = (float(*)()) sShortToFloat;
#endif

float Pull3DRamHook(float* table, float xLookup, float yLookup)
{
	//Check if r4 is ram or not??
	//WARNING: cannot use LOOKUP TABLES in this region (pRamVariables)!!!
	//Lookup tables must be static or this needs to change.
	if(((void*)table > (void*)&(pRamVariables.RamVariableStart)) && ((void*)table < (void*)&(pRamVariables.RamHoleEndMarker)))
	{
		return *table;
	}
	else
	{
		return Pull3DHooked((ThreeDTable*)table, xLookup, yLookup);
	}
}

#if REQTORQUE_HACKS && PROG_MODE
float Pull3DHookReqTorque(ThreeDTable* table, float xLookup, float yLookup)
{
	float oemValue = Pull3DHooked(table, xLookup, yLookup);
	
	#if PROG_MODE
	if(pRamVariables.ValetMode == 1 && oemValue > ValetModeReqTorqueLimit)
		return ValetModeReqTorqueLimit;
	else
	#endif
		return oemValue;
}
#endif

float Pull2DRamHook(float* table, float xLookup)
{
	//Check if r4 is ram or not??
	if(table > (float*)&(pRamVariables.RamVariableStart))
	{
		return *table;
	}
	else
	{
		 return Pull2DHooked((TwoDTable*)table, xLookup);
	}
}

#if SWITCH_HACKS
float Pull2DRamHookTipIn(float* table, float xLookup)
{
	if(table == tTipInEnrich)//This hook is used by other tables!!
		return Pull2DHooked((TwoDTable*)table, xLookup) 
		* Pull2DHooked((TwoDTable*)&TipInEnrichMultiplier, xLookup)
		* pRamVariables.InjectorScalingMultiplier;		
	return Pull2DHooked((TwoDTable*)table, xLookup);
}

float Pull2DRamHookCrankingFuel(float* table, float xLookup)
{
	if(table == tCrankingFuelA ||
	table == tCrankingFuelB ||
	table == tCrankingFuelC ||
	table == tCrankingFuelD ||
	table == tCrankingFuelE ||
	table == tCrankingFuelF)//This hook is used by other tables!!
		return Pull2DHooked((TwoDTable*)table, xLookup) 
		* Pull2DHooked((TwoDTable*)&CrankingFuelMultiplier, xLookup)
		* pRamVariables.InjectorScalingMultiplier;
	return Pull2DHooked((TwoDTable*)table, xLookup);
}

float Pull2DRamHookStartupEnrich2(float* table, float xLookup)
{
	if(table == tStartupEnrich2_1A ||
	table == tStartupEnrich2_1B ||
	table == tStartupEnrich2_2A ||
	table == tStartupEnrich2_2B)//This hook is used by other tables!!
		return Pull2DHooked((TwoDTable*)table, xLookup) * Pull2DHooked((TwoDTable*)&StartupEnrichMultiplier, xLookup);
	return Pull2DHooked((TwoDTable*)table, xLookup);
}

float Pull2DRamHookStartupEnrich3(float* table, float xLookup)
{
	if(table == tStartupEnrich3_1A ||
	table == tStartupEnrich3_1B ||
	table == tStartupEnrich3_2A ||
	table == tStartupEnrich3_2B)//This hook is used by other tables!!
		return Pull2DHooked((TwoDTable*)table, xLookup) * Pull2DHooked((TwoDTable*)&StartupEnrichMultiplier, xLookup);
	return Pull2DHooked((TwoDTable*)table, xLookup);
}
#endif