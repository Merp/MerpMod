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

/////////////////
//Constants
/////////////////
#if BOOST_HACKS
float RPMLockWGDC BOOSTDATA = 3000.0f;
float ThrottleLockWGDC BOOSTDATA = 85.0f;

#if SWITCH_HACKS
TableGroup PGWGTableGroup BOOSTDATA = {
	{&PGWGTable1i,
	&PGWGTable1s,
	&PGWGTable1ss},
	{&PGWGTable2i,
	&PGWGTable2s,
	&PGWGTable2ss}
};
TableGroup PGTBTableGroup BOOSTDATA = {
	{&PGTBTable1i,
	&PGTBTable1s,
	&PGTBTable1ss},
	{&PGTBTable2i,
	&PGTBTable2s,
	&PGTBTable2ss}
};
#else
TableGroup PGWGTableGroup BOOSTDATA = {
	{&PGWGTable1i,
	&PGWGTable1i,
	&PGWGTable1i},
	{&PGWGTable2i,
	&PGWGTable2i,
	&PGWGTable2i}
};
TableGroup PGTBTableGroup BOOSTDATA = {
	{&PGTBTable1i,
	&PGTBTable1i,
	&PGTBTable1i},
	{&PGTBTable2i,
	&PGTBTable2i,
	&PGTBTable2i}
};
#endif

TableGroup WGDCInitialTableGroup BOOSTDATA = {
	{&WGDCInitialTable1,
	&WGDCInitialTable1,
	&WGDCInitialTable1},
	{&WGDCInitialTable2,
	&WGDCInitialTable2,
	&WGDCInitialTable2}
};

TableGroup WGDCMaxTableGroup BOOSTDATA = {
	{&WGDCMaxTable1,
	&WGDCMaxTable1,
	&WGDCMaxTable1},
	{&WGDCMaxTable2,
	&WGDCMaxTable2,
	&WGDCMaxTable2}
};

TableGroup TargetBoostTableGroup BOOSTDATA = {
	{&TargetBoostTable1,
	&TargetBoostTable1,
	&TargetBoostTable1},
	{&TargetBoostTable2,
	&TargetBoostTable2,
	&TargetBoostTable2}
};

///////////////
//PGWG TABLE 1 i
///////////////
ThreeDTable PGWGTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4400,5000,5600,6200,6800};
short PGWGData1i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{20992,20992,20992,20992,0,0,
19968,19968,19968,19968,0,0,
19200,19200,19200,19200,0,0,
15488,15488,15488,15488,0,0,
11776,11776,11776,11776,0,0,
11213,11213,11213,11213,0,0,
10650,10650,10650,10650,0,0,
10086,10086,10086,10086,0,0,
9523,9523,9523,9523,0,0,
8960,8960,8960,8960,0,0,
9600,9600,9600,9600,0,0,
10240,10240,10240,10240,0,0,
11520,11520,11520,11520,0,0,
11520,11520,11520,11520,0,0,
10880,10880,10880,10880,0,0,
10240,10240,10240,10240,0,0};

ThreeDTable PGWGTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1i,
	.rowHeaderArray = PGWGRows1i,
	.tableCells = PGWGData1i,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 i
///////////////
ThreeDTable PGWGTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4400,5000,5600,6200,6800};
short PGWGData2i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0};

ThreeDTable PGWGTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2i,
	.rowHeaderArray = PGWGRows2i,
	.tableCells = PGWGData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };
	
#if SWITCH_HACKS
///////////////
//PGWG TABLE 1 s
///////////////
ThreeDTable PGWGTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGWGData1s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384};

ThreeDTable PGWGTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1s,
	.rowHeaderArray = PGWGRows1s,
	.tableCells = PGWGData1s,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 s
///////////////
ThreeDTable PGWGTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGWGData2s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384};

ThreeDTable PGWGTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2s,
	.rowHeaderArray = PGWGRows2s,
	.tableCells = PGWGData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };	
	
///////////////
//PGWG TABLE 1 ss
///////////////
ThreeDTable PGWGTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols1ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGWGData1ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384};

ThreeDTable PGWGTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols1ss,
	.rowHeaderArray = PGWGRows1ss,
	.tableCells = PGWGData1ss,
	.tableType = UInt16Table3D,
	.multiplier =  0.00390625f,//0x3B800000
	.offset = 0 };	
	
	
///////////////
//PGWG TABLE 2 ss
///////////////
ThreeDTable PGWGTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGWGCols2ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGWGRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGWGData2ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384};

ThreeDTable PGWGTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGWGCols2ss,
	.rowHeaderArray = PGWGRows2ss,
	.tableCells = PGWGData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };	
#endif

///////////////
//PGWG RAM LUT
///////////////
#if PGWG_RAMTUNING
ThreeDTable PGWGRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->PGWGRamCols),
	.rowHeaderArray = &(pRamVariables->PGWGRamRows),
	.tableCells = &(pRamVariables->PGWGRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.00390625f,//0x3B800000	
	.offset = 0 };
#endif

///////////////
//PGTB TABLE 1i
///////////////
ThreeDTable PGTBTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{800,1200,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200,5600,6000,6400,6450};
short PGTBData1i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0};

ThreeDTable PGTBTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1i,
	.rowHeaderArray = PGTBRows1i,
	.tableCells = PGTBData1i,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2i
///////////////
ThreeDTable PGTBTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2i[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2i[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{800,1200,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200,5600,6000,6400,6450};
short PGTBData2i[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0};

ThreeDTable PGTBTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2i,
	.rowHeaderArray = PGTBRows2i,
	.tableCells = PGTBData2i,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };

#if SWITCH_HACKS
///////////////
//PGTB TABLE 1s
///////////////
ThreeDTable PGTBTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGTBData1s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000};

ThreeDTable PGTBTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1s,
	.rowHeaderArray = PGTBRows1s,
	.tableCells = PGTBData1s,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2s
///////////////
ThreeDTable PGTBTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2s[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2s[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,3600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGTBData2s[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000};

ThreeDTable PGTBTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2s,
	.rowHeaderArray = PGTBRows2s,
	.tableCells = PGTBData2s,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };


///////////////
//PGTB TABLE 1ss
///////////////
ThreeDTable PGTBTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols1ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows1ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2800,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGTBData1ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000};

ThreeDTable PGTBTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols1ss,
	.rowHeaderArray = PGTBRows1ss,
	.tableCells = PGTBData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };	
	
	
///////////////
//PGTB TABLE 2ss
///////////////
ThreeDTable PGTBTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float PGTBCols2ss[6] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1,2,3,4,5,6};
float PGTBRows2ss[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2800,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short PGTBData2ss[96] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000};

ThreeDTable PGTBTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = PGTBCols2ss,
	.rowHeaderArray = PGTBRows2ss,
	.tableCells = PGTBData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,//0x3F800000	
	.offset = 0 };
#endif

///////////////
//PGTB RAM LUT
///////////////
#if PGWG_RAMTUNING
ThreeDTable PGTBRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 6,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->PGTBRamCols),
	.rowHeaderArray = &(pRamVariables->PGTBRamRows),
	.tableCells = &(pRamVariables->PGTBRamData),
	.tableType = UInt16Table3D,
	.multiplier = 1.0,//0x3B800000
	.offset = 0 };	
#endif

///////////////////
//WGDC Initial Table 1 LUT
///////////////////
ThreeDTable WGDCInitialTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float WGDCInitialRows1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4400,5000,5600,6200,6800};
short WGDCInitialData1[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384};

ThreeDTable WGDCInitialTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols1,
	.rowHeaderArray = WGDCInitialRows1,
	.tableCells = WGDCInitialData1,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Initial Table 2 LUT
///////////////////
ThreeDTable WGDCInitialTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCInitialCols2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float WGDCInitialRows2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2800,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short WGDCInitialData2[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384};

ThreeDTable WGDCInitialTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCInitialCols2,
	.rowHeaderArray = WGDCInitialRows2,
	.tableCells = WGDCInitialData2,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////
//WGDC Initial RAM LUT
///////////////
#if WGDC_RAMTUNING
ThreeDTable WGDCInitialRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->WGDCInitialRamCols),
	.rowHeaderArray = &(pRamVariables->WGDCInitialRamRows),
	.tableCells = &(pRamVariables->WGDCInitialRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0- range, 16bit precision)
#endif

///////////////////
//WGDC Max Table 1 LUT
///////////////////
ThreeDTable WGDCMaxTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float WGDCMaxRows1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4400,5000,5600,6200,6800};
short WGDCMaxData1[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120};

ThreeDTable WGDCMaxTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols1,
	.rowHeaderArray = WGDCMaxRows1,
	.tableCells = WGDCMaxData1,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//WGDC Max Table 2 LUT
///////////////////
ThreeDTable WGDCMaxTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float WGDCMaxCols2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float WGDCMaxRows2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2800,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short WGDCMaxData2[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120,
0,0,0,0,50,50,100,100,100,100,100,120,120,120,120,120};

ThreeDTable WGDCMaxTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = WGDCMaxCols2,
	.rowHeaderArray = WGDCMaxRows2,
	.tableCells = WGDCMaxData2,
	.tableType = UInt16Table3D,
	.multiplier = 1.0f,
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////
//WGDC Max RAM LUT
///////////////
#if WGDC_RAMTUNING
ThreeDTable WGDCMaxRamTable __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = &(pRamVariables->WGDCMaxRamCols),
	.rowHeaderArray = &(pRamVariables->WGDCMaxRamRows),
	.tableCells = &(pRamVariables->WGDCMaxRamData),
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,
	.offset = 0 };				//! /32767  (0- range, 16bit precision)
#endif
	
///////////////////
//Target Boost Table 1
///////////////////
ThreeDTable TargetBoostTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float TBRows1[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2200,2400,2600,2800,3000,3200,3400,3600,3800,4000,4400,5000,5600,6200,6800};
short TBData1[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384};

ThreeDTable TargetBoostTable1 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols1,
	.rowHeaderArray = TBRows1,
	.tableCells = TBData1,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
///////////////////
//Target Boost Table 2
///////////////////
ThreeDTable TargetBoostTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float TBCols2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{100,120,130,140,160,170,190,210,230,240,260,280,300,320,340,350};
float TBRows2[16] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{2000,2800,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short TBData2[256] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,
16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384,16384};

ThreeDTable TargetBoostTable2 __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 16,
	.rowCount = 16,
	.columnHeaderArray = TBCols2,
	.rowHeaderArray = TBRows2,
	.tableCells = TBData2,
	.tableType = UInt16Table3D,
	.multiplier = 0.000061037f,	
	.offset = 0 };				//! /32767  (0-? range, 16bit precision)
	
#endif
