/*
	Copyright (C) 2014 Scott T. Anderson & 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
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
#if ALS_HACKS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! ALS constants
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char DefaultDriveMode SPEEDDENSITYDATA = 0x02;

TableGroup ReqTorqTableGroup SPEEDDENSITYDATA = {
	{&ReqTorqTable1v,
	&ReqTorqTable1i,
	&ReqTorqTable1s,
	&ReqTorqTable1ss},
	{&ReqTorqTable1v,
	&ReqTorqTable1i,
	&ReqTorqTable1s,
	&ReqTorqTable1ss}
};

TableGroup AVCSTableGroup SPEEDDENSITYDATA = {
	{&AVCSTable1i,
	&AVCSTable1i,
	&AVCSTable1s,
	&AVCSTable1ss},
	{&AVCSTable2i,
	&AVCSTable2i,
	&AVCSTable2s,
	&AVCSTable2ss}
};

#if MPG_HACKS

unsigned char DODMode SPEEDDENSITYDATA = HackDisabled;
float LeanCruiseLoadThreshold SPEEDDENSITYDATA = 0.80f;

#endif

///////////////
//Requested Torque Table 1v
///////////////
ThreeDTable ReqTorqTable1v __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float ReqTorqCols1v[15] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{0,3,10,16.5,25,31,37,44,52,58,64.3,71.4,78.6,85.7,98.5};
float ReqTorqRows1v[17] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{1000,2000,2600,3000,3400,3800,4200,4600,5000,5400,5800,6200,6600,7000,7400,7800,8200};
short ReqTorqData1v[255] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable ReqTorqTable1v __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 15,
	.rowCount = 17,
	.columnHeaderArray = ReqTorqCols1v,
	.rowHeaderArray = ReqTorqRows1v,
	.tableCells = ReqTorqData1v,
	.tableType = UInt16Table3D,
	.multiplier = 0.0078125f,	
	.offset = 0 };	

///////////////
//Requested Torque Table 1i
///////////////
ThreeDTable ReqTorqTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));

short ReqTorqData1i[255] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable ReqTorqTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 15,
	.rowCount = 17,
	.columnHeaderArray = ReqTorqCols1v,
	.rowHeaderArray = ReqTorqRows1v,
	.tableCells = ReqTorqData1i,
	.tableType = UInt16Table3D,
	.multiplier = 0.0078125f,	
	.offset = 0 };	

///////////////
//Requested Torque Table 1s
///////////////
ThreeDTable ReqTorqTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));

short ReqTorqData1s[255] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable ReqTorqTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 15,
	.rowCount = 17,
	.columnHeaderArray = ReqTorqCols1v,
	.rowHeaderArray = ReqTorqRows1v,
	.tableCells = ReqTorqData1s,
	.tableType = UInt16Table3D,
	.multiplier = 0.0078125f,	
	.offset = 0 };	
	
///////////////
//Requested Torque Table 1ss
///////////////
ThreeDTable ReqTorqTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));

short ReqTorqData1ss[255] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable ReqTorqTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 15,
	.rowCount = 17,
	.columnHeaderArray = ReqTorqCols1v,
	.rowHeaderArray = ReqTorqRows1v,
	.tableCells = ReqTorqData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.0078125f,	
	.offset = 0 };	

///////////////
// AVCS Table 1i
///////////////
ThreeDTable AVCSTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
float AVCSCols1[20] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{0.2,0.35,0.5,0.65,.80,0.95,1.1,1.25,1.4,1.66,2.0,2.33,2.66,3.0,3.25,3.50,3.75,4.0,4.25, 4.5};
float AVCSRows1[20] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = 
{800,1200,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200,5600,6000,6400,6800,7200,7300,7400,8000};
short AVCSData1i[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3276.8,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable1i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData1i,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	

///////////////
// AVCS Table 1s
///////////////
ThreeDTable AVCSTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
short AVCSData1s[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable1s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData1s,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	

#if MPG_HACKS

///////////////
// AVCS Table 1ss
///////////////
ThreeDTable AVCSTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
short AVCSData1ss[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable1ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData1ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	
	
///////////////
// AVCS Table 2i
///////////////

ThreeDTable AVCSTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
short AVCSData2i[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable2i __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData2i,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	

///////////////
// AVCS Table 2s
///////////////

ThreeDTable AVCSTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
short AVCSData2s[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable2s __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData2s,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	
	
///////////////
// AVCS Table 2ss
///////////////

ThreeDTable AVCSTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4)));
short AVCSData2ss[400] __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

ThreeDTable AVCSTable2ss __attribute__ ((section ("RomHole_SpeedDensityTables"),aligned(4))) = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = AVCSCols1,
	.rowHeaderArray = AVCSRows1,
	.tableCells = AVCSData2ss,
	.tableType = UInt16Table3D,
	.multiplier = 0.0054931640625f,	
	.offset = 0 };	

float O2SensorScalingMPGRows[13] SPEEDDENSITYDATA =
{-1.53,-1.43,-1.3,-0.87,-0.47,-0.14,0.0,0.1,0.24,0.39,0.53,0.64,0.74};

float O2SensorScalingMPGDATA[13] SPEEDDENSITYDATA =
{0.73,0.742,0.759,0.828,0.897,0.965,1.0,1.035,1.103,1.172,1.241,1.31,1.38};

TwoDTable O2SensorScalingMPGTable SPEEDDENSITYDATA = {
.columnCount = 13,
.tableType = FloatTable2D,
.columnHeaderArray = O2SensorScalingMPGRows,
.tableCells = O2SensorScalingMPGDATA,
.multiplier = 0.0f,
.offset = 0.0 };


#endif
#endif