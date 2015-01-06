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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! CelFlash constants
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char FBKCLoFlashSpeed CELFLASHDATA = 0x02;
unsigned char FBKCLoFlashes CELFLASHDATA = 0x04;
unsigned char FBKCHiFlashSpeed CELFLASHDATA = 0x01;
unsigned char FBKCHiFlashes CELFLASHDATA = 0x08;
unsigned char EGTFlashSpeed CELFLASHDATA = 0x04;
unsigned char EGTFlashes CELFLASHDATA = 0x02;
unsigned char ECTFlashSpeed CELFLASHDATA = 0x10;
unsigned char ECTFlashes CELFLASHDATA = 0x10;
float ECTFlashThreshold CELFLASHDATA = 120.0f;
float IAMFlashThreshold CELFLASHDATA = 0.5f;
unsigned char IAMFlashes CELFLASHDATA = 0x20;
unsigned char IAMFlashSpeed CELFLASHDATA = 0x02;
float FBKCLoThreshold CELFLASHDATA = -0.1f;
float FBKCHiThreshold CELFLASHDATA = -2.1f;
float FBKCLoadThreshold CELFLASHDATA = 1.5f;
float EGTCelLoadThreshold CELFLASHDATA = 1.5f;
float EGTResistanceThreshold CELFLASHDATA = 25.0f;
unsigned char ShiftLightFlashes CELFLASHDATA = 0x01;
unsigned char ShiftLightFlashSpeed CELFLASHDATA = 0x10;
unsigned char FlexLearnFlashes CELFLASHDATA = 0x01;
unsigned char FlexLearnFlashSpeed CELFLASHDATA = 0x08;
unsigned char KillModeFlashes CELFLASHDATA = 0x20;
unsigned char KillModeFlashSpeed CELFLASHDATA = 0x01;
unsigned char ALSModeFlashSpeed CELFLASHDATA = 0x04;
float DefaultShiftLightRPM CELFLASHDATA = 10000.0f;
unsigned char ShiftLightEnabled CELFLASHDATA = HackDisabled;

ThreeDTable ShiftLightRPMs __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float SHIFTLIGHTRPM_COLS[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float SHIFTLIGHTRPM_ROWS[4] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4};
short SHIFTLIGHTRPM_DATA[24] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{1300,2500,3000,3500,6400,6400,
1300,2500,3000,3500,6400,6400,
1300,2500,3000,3500,6400,6400,
1300,2500,3000,3500,6400,6400};

ThreeDTable ShiftLightRPMs __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 4,
	.columnHeaderArray = SHIFTLIGHTRPM_COLS,
	.rowHeaderArray = SHIFTLIGHTRPM_ROWS,
	.tableCells = SHIFTLIGHTRPM_DATA,
	.tableType = UInt16Table3D,
	.multiplier =  0.25f,
	.offset = 0 };	
	

//TwoDTable LeanBoostThreshold CELFLASHDATA = //MAP axis, LAMBDA data
//unsigned char LeanBoostInputMode CELFLASHDATA = LeanBoostInputModeOEM; //TODO EXTERN
//TODO: TwoDTable with axes to use rearo2 or TGV input as wideband for LEAN BOOST flash