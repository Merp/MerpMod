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

//////////////////////////
//Enumerations
//////////////////////////
enum TableType3D
{
	UInt8Table3D = (unsigned long)0x04000000,
	UInt16Table3D = (unsigned long)0x08000000
};

enum TableType2D
{
	UInt8Table2D = (unsigned short)0x0400,
	UInt16Table2D = (unsigned short)0x0800,
	FloatTable2D = (unsigned short)0x0000
};

enum CruiseToggles
{
	ToggleCoast = (unsigned char)0,
	ToggleResume = (unsigned char)1,
	ToggleCancel = (unsigned char)2,
	ToggleCruise = (unsigned char)3,
};

enum ValetModes
{
	ValetModeDisabled = 0,
	ValetModeEnabled = 1
};

enum MafModeValues
{
	MafModeUndefined = 0,
	MafModeSensor = 1,
	MafModeSpeedDensity = 2,
	MafModeBlending = 3,
};
enum RevLimModeValues
{
	RevLimModeUndefined = 0,
	RevLimModeFuelCut = 1,
	RevLimModeSparkCut = 2,
	RevLimModeComboCut = 3,
};
enum LCTimingModeValues
{
	LCTimingModeUndefined = 0,
	LCTimingModeDisabled = 1,
	LCTimingModeCompensated = 2,
	LCTimingModeLocked = 3,
};
enum LCFuelModeValues
{
	LCFuelModeUndefined = 0,
	LCFuelModeDisabled = 1,
	LCFuelModeCompensated = 2,
	LCFuelModeLocked = 3,
};
enum InputModeValues
{
	InputModeUndefined = 0,
	InputModeTGVLeft = 1,
	InputModeTGVRight = 2,
	InputModeSiDrive = 3
};
enum MapSwitchValues
{
	MapSwitchUndefined = 0,
	MapSwitch1 = 1,
	MapSwitch2 = 2,
	MapSwitch3 = 3,
};

//,1=S,2=S#,3=I,8=S#,16=I"
enum SiDriveModes
{
	SiDriveSS = 2,
	SiDriveSSAlt = 8,
	SiDriveS = 1,
};

//////////////////////////////
//Type Definitions for Tables
//////////////////////////////
typedef struct 
{
	short columnCount;
	short rowCount;
	float* columnHeaderArray;
	float* rowHeaderArray;
	void* tableCells;
	int tableType;
	float multiplier;
	float offset;
} ThreeDTable;

typedef struct 
{
	short columnCount;
	short tableType;
	float* columnHeaderArray;
	short* tableCells;
	float multiplier;
	float offset;
} TwoDTable;

typedef struct
{
	ThreeDTable* TableI;
	ThreeDTable* TableS;
	ThreeDTable* TableSS;
} TableSubSet;

typedef struct{
	TableSubSet Map1;
	TableSubSet Map2;
} TableGroup;

typedef struct
{
	long s1;
	long s2;
	char Vin[20];
	long e1;
	long e2;
} VinBlockStruct;