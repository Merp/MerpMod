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

unsigned char DefaultMapSwitch SWITCHDATA = 0x01;
float DefaultMapBlendRatio SWITCHDATA = 0.0f;

float MapSwitchThresholdLo SWITCHDATA = 1.5f;
float MapSwitchThresholdHi SWITCHDATA = 3.5f;

unsigned char BlendRatioInput SWITCHDATA = 0x00;
unsigned char MapSwitchInput  SWITCHDATA = 0x00;



//TODO TEST pull2d function here!

float INPUT1_SCALING_ROWS[11] SWITCHDATA =
{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};

short INPUT1_SCALING_DATA[11] SWITCHDATA =
{0,3276,6552,9828,13104,16380,19656,22932,26208,29484,32760};

TwoDTable TGVLeftScaling  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,
	.columnHeaderArray = INPUT1_SCALING_ROWS,
	.tableCells = INPUT1_SCALING_DATA,
	.multiplier = 0.000030517589f,	//todo unit test these
	.offset = 0.0 };
//! 1/32767  (0-1.00 range, 16bit precision)

float INPUT2_SCALING_ROWS[11] SWITCHDATA =
{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};

short INPUT2_SCALING_DATA[11] SWITCHDATA =
{0,3276,6552,9828,13104,16380,19656,22932,26208,29484,32760};

TwoDTable TGVRightScaling  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = INPUT2_SCALING_ROWS,
	.tableCells = INPUT2_SCALING_DATA,
	.multiplier = 0.00003051758f,	
	.offset = 0.0 };
//! 1/32767  (0-1.00 range, 16bit precision)

#endif