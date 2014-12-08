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

unsigned char DefaultMapSwitch SWITCHDATA = MapSwitch1;
float DefaultMapBlendRatio SWITCHDATA = 0.0f;

float LeftTGVInputSmoothingFactor SWITCHDATA = 1.0f;
float RightTGVInputSmoothingFactor SWITCHDATA = 1.0f;

float LeftTGVInputMultiplier SWITCHDATA = 1.0f;
float RightTGVInputMultiplier SWITCHDATA = 1.0f;

float LeftTGVInputOffset SWITCHDATA = 0.0f;
float RightTGVInputOffset SWITCHDATA = 0.0f;

float MapSwitchThresholdLo SWITCHDATA = 1.5f;
float MapSwitchThresholdHi SWITCHDATA = 3.5f;

unsigned char DefaultMapBlendingInputMode SWITCHDATA = MapBlendingInputModeUndefined;
unsigned char DefaultMapSwitchingInputMode  SWITCHDATA = MapSwitchingInputModeUndefined;

//TODO TEST pull2d function here!

float INPUT1_SCALING_ROWS[11] SWITCHDATA =
{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};

short INPUT1_SCALING_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable TGVLeftScaling  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,
	.columnHeaderArray = INPUT1_SCALING_ROWS,
	.tableCells = INPUT1_SCALING_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float INPUT2_SCALING_ROWS[11] SWITCHDATA =
{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};

short INPUT2_SCALING_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable TGVRightScaling  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = INPUT2_SCALING_ROWS,
	.tableCells = INPUT2_SCALING_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float TipInEnrichMultiplierAxis[18] SWITCHDATA =
{0,0.9799999594688416,1.949999928474426,3.909999847412109,5.859999656677246,
7.809999942779541,9.769999504089355,11.69999980926514,13.69999980926514,
15.59999942779541,17.59999847412109,19.5,21.5,23.39999961853027,
25.39999961853027,27.29999923706055,29.29999923706055,31.29999923706055};

short TipInEnrichMultiplierData[18] SWITCHDATA =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

TwoDTable TipInEnrichMultiplier SWITCHDATA = {
	.columnCount = 18,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = TipInEnrichMultiplierAxis,
	.tableCells = TipInEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

float CrankingFuelMultiplierAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

short CrankingFuelMultiplierData[16] SWITCHDATA = 
{16360,16252,15010,14020,12689,11639,6632,6554,6554,6554,6554,6554,6554,6554,6554,6554,};

TwoDTable CrankingFuelMultiplier SWITCHDATA = {
	.columnCount = 16,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = CrankingFuelMultiplierAxis,
	.tableCells = CrankingFuelMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

float StartupEnrichMultiplierECTAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

short StartupEnrichMultiplierData[16] SWITCHDATA = 
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

TwoDTable StartupEnrichMultiplier SWITCHDATA = {
	.columnCount = 16,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = StartupEnrichMultiplierECTAxis,
	.tableCells = StartupEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

#endif