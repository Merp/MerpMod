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
#if SWITCH_HACKS

float BlendAndSwitch(TableGroup tg, float xLookup, float yLookup)
{
	float OutputValue;
	if(pRamVariables->MapBlendRatio < 0.01)
	{
		OutputValue = SwitchSelect(tg.Map1, xLookup, yLookup);
		
	}
	else if(pRamVariables->MapBlendRatio > 0.99)
	{
		OutputValue = SwitchSelect(tg.Map2, xLookup, yLookup);
	}
	else
	{
		float Value1;
		
		Value1 = SwitchSelect(tg.Map1, xLookup, yLookup);

		Value1 *= (1 - pRamVariables->MapBlendRatio);

		//Pull3d for Timing Map 2

		float Value2;
		//Pull3d for Timing Map 1
		Value2 = SwitchSelect(tg.Map2, xLookup, yLookup);
		
		Value2 *= pRamVariables->MapBlendRatio;

		//Blend

		OutputValue = (Value1 + Value2);
	}
	return OutputValue;
}

float SwitchSelect(TableSubSet tss, float xLookup, float yLookup)
{
	float OutputValue;
		switch(pRamVariables->MapSwitch)
		{
			case MapSwitch3:
			OutputValue = Pull3DHooked(tss.TableSS, xLookup, yLookup);
			break;
			
			case MapSwitch2:
			OutputValue = Pull3DHooked(tss.TableS, xLookup, yLookup);
			break;
			
			default:
			OutputValue = Pull3DHooked(tss.TableI, xLookup, yLookup);
			break;
		}
	return OutputValue;
}

void InputUpdate()
{
	float grad = 0.0000762939453125;
	float offs = 0.0f;
	pRamVariables->TGVLeftVolts = ShortToFloatHooked(*pTGVLeftVoltage,grad,offs);
	pRamVariables->TGVRightVolts = ShortToFloatHooked(*pTGVRightVoltage,grad,offs);
	pRamVariables->TGVLeftScaled = Pull2DHooked(&TGVLeftScaling,pRamVariables->TGVLeftVolts);
	pRamVariables->TGVRightScaled = Pull2DHooked(&TGVRightScaling,pRamVariables->TGVRightVolts);
	
	switch(BlendRatioInput)
	{
		case InputModeUndefined:
		break;
		
		case InputModeTGVLeft:
			pRamVariables->MapBlendRatio = pRamVariables->TGVLeftScaled;
			break;
		
		case InputModeTGVRight:
			pRamVariables->MapBlendRatio = pRamVariables->TGVRightScaled;
			break;
		
		default:
			pRamVariables->MapBlendRatio = DefaultMapBlendRatio;
			break;
	}
	
	switch(MapSwitchInput)
	{
		case InputModeUndefined:
		break;
		
		#ifdef pSiDrive
		case InputModeSiDrive:
		{
			switch(*pSiDrive)
		
			case SiDriveSS:
			pRamVariables->MapSwitch = MapSwitch3;
			break;
			
			case SiDriveSSAlt:
			pRamVariables->MapSwitch = MapSwitch3;
			break;
			
			case SiDriveS:
			pRamVariables->MapSwitch = MapSwitch2;
			break;
		
			default:
			pRamVariables->MapSwitch = MapSwitch1;
			break;
			}
		}
		#endif
		
		case InputModeTGVLeft:
			MapSwitchThresholdCheck(pRamVariables->TGVLeftVolts);
			break;
		
		case InputModeTGVRight:
			MapSwitchThresholdCheck(pRamVariables->TGVRightVolts);
			break;
		
		default:
		pRamVariables->MapSwitch = DefaultMapSwitch;
		break;
	}
}

void MapSwitchThresholdCheck(float input)
{
	if(input < MapSwitchThresholdLo)
	{
		//Low, map 1
		pRamVariables->MapSwitch = MapSwitch1;
	}
	else if (input < MapSwitchThresholdHi)
	{
		//Mid, map 2
		pRamVariables->MapSwitch = MapSwitch2;
	}
	else
	{
		//High, map 3
		pRamVariables->MapSwitch = MapSwitch3;
	}
}

#endif