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

#define STI_BASE_TIMING_CANDYS_ROWS 800,1200,1600,2000,2400,2800,3200,3600,4000,4400,4800,5200,5600,6000,6400,6800,7200,7600,8000,8400,
#define STI_BASE_TIMING_CANDYS_COLS 0.2000000029802322,	0.4000000059604645,	0.6000000238418579,	0.800000011920929,	1,	1.200000047683716,	1.399999976158142,	1.600000023841858,	1.799999952316284,	2,	2.200000047683716,	2.400000095367432,	2.599999904632568,	2.799999952316284,	3,	3.200000047683716,	3.400000095367432,	3.599999904632568,	3.799999952316284,	4,
#define STI_BASE_TIMING_CANDYS_DATA1 {105,141,151,120,103,91,90,87,85,73,69,63,59,55,50,48,46,43,41,39,119,138,159,144,122,102,94,90,89,75,70,65,61,57,51,49,47,44,42,40,134,145,157,155,140,121,107,99,94,90,85,80,77,73,64,62,60,57,55,53,151,166,179,166,154,137,120,112,101,94,84,80,77,74,67,65,63,60,58,56,159,179,186,180,167,152,134,120,114,107,101,94,93,90,86,84,82,79,77,75,165,179,186,187,176,163,149,131,120,110,105,98,95,93,90,88,86,83,81,79,
#define STI_BASE_TIMING_CANDYS_DATA2 171,179,185,185,182,171,162,144,128,115,109,103,98,95,93,91,89,86,84,82,171,179,185,185,184,177,173,156,138,120,110,104,100,96,93,91,89,86,84,82,171,179,183,183,183,178,171,159,142,120,111,105,101,97,93,91,89,86,84,82,171,179,183,183,182,176,169,159,140,124,112,106,102,98,94,92,90,87,85,83,171,179,179,182,183,174,163,158,142,127,115,110,103,98,95,93,91,88,86,84,171,179,179,182,183,175,164,157,139,129,120,113,110,104,101,99,97,94,92,90,171,179,179,182,183,175,164,157,141,134,125,119,114,112,106,104,102,99,97,95,171,179,179,179,183,172,160,154,139,137,129,124,120,115,111,109,107,104,102,100,
#define STI_BASE_TIMING_CANDYS_DATA3 171,179,179,179,178,169,160,151,137,139,130,125,122,117,112,110,108,105,103,101,167,179,179,181,176,168,159,153,141,139,132,126,123,118,113,111,109,106,104,102,165,179,179,180,174,166,158,152,140,140,132,127,124,119,113,111,109,106,104,102,165,178,178,175,171,164,156,151,140,140,134,128,124,120,114,112,110,107,105,103,
#define STI_BASE_TIMING_CANDYS_DATA4 165,178,178,175,171,164,156,151,140,140,134,128,124,120,114,112,110,107,105,103,165,178,178,175,171,164,156,151,140,140,134,128,124,120,114,112,110,107,105,103,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,56.9,}
#define STI_BASE_TIMING_CANDYS STI_BASE_TIMING_CANDYS_DATA1 STI_BASE_TIMING_CANDYS_DATA2 STI_BASE_TIMING_CANDYS_DATA3 STI_BASE_TIMING_CANDYS_DATA4

#if TIMING_HACKS

unsigned char DefaultLCTimingMode TIMINGDATA = LCTimingModeDisabled;
unsigned char DefaultTimingHackEnabled TIMINGDATA = HackDisabled;
float DefaultLCTimingLock TIMINGDATA = 20.0f;
float DefaultLCTimingRetardMultiplier TIMINGDATA = 1.0f;

//TODO IS THIS NECESSARY?
ThreeDTable TimingTable1i  TIMINGDATA;
ThreeDTable TimingTable1s  TIMINGDATA;
ThreeDTable TimingTable1ss  TIMINGDATA;
ThreeDTable TimingTable2i  TIMINGDATA;
ThreeDTable TimingTable2s  TIMINGDATA;
ThreeDTable TimingTable2ss  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable1i  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable1s  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable1ss  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable2i  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable2s  TIMINGDATA;
ThreeDTable KnockCorrectionRetardTable2ss  TIMINGDATA;

#if SWITCH_HACKS
TableGroup TimingTableGroup TIMINGDATA = {
	{&TimingTable1i,
	&TimingTable1s,
	&TimingTable1ss},
	{&TimingTable2i,
	&TimingTable2s,
	&TimingTable2ss}
};

TableGroup KnockCorrectionRetardTableGroup TIMINGDATA = {
	{&KnockCorrectionRetardTable1i,
	&KnockCorrectionRetardTable1s,
	&KnockCorrectionRetardTable1ss},
	{&KnockCorrectionRetardTable2i,
	&KnockCorrectionRetardTable2s,
	&KnockCorrectionRetardTable2ss}
};

#else
TableGroup TimingTableGroup TIMINGDATA = {
	{&TimingTable1i,
	&TimingTable1i,
	&TimingTable1i},
	{&TimingTable2i,
	&TimingTable2i,
	&TimingTable2i}
	};
TableGroup KnockCorrectionRetardTableGroup TIMINGDATA = {
	{&KnockCorrectionRetardTable1i,
	&KnockCorrectionRetardTable1i,
	&KnockCorrectionRetardTable1i},
	{&KnockCorrectionRetardTable2i,
	&KnockCorrectionRetardTable2i,
	&KnockCorrectionRetardTable2i}
	};
#endif

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 1 i
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float T1i_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T1i_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T1i_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;

ThreeDTable TimingTable1i  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T1i_COLS,
	.rowHeaderArray = T1i_ROWS,
	.tableCells = T1i_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 2 i
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
float T2i_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T2i_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T2i_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;
	
ThreeDTable TimingTable2i  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T2i_COLS,
	.rowHeaderArray = T2i_ROWS,
	.tableCells = T2i_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! KCR Table 1 i
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR1i_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR1i_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR1i_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable1i  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR1i_COLS,
	.rowHeaderArray = KCR1i_ROWS,
	.tableCells = KCR1i_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! KCR Table 2 i
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR2i_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR2i_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR2i_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable2i  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR2i_COLS,
	.rowHeaderArray = KCR2i_ROWS,
	.tableCells = KCR2i_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset

#if SWITCH_HACKS
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 1 s
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float T1s_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T1s_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T1s_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;

ThreeDTable TimingTable1s  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T1s_COLS,
	.rowHeaderArray = T1s_ROWS,
	.tableCells = T1s_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 2 s
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
float T2s_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T2s_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T2s_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;
	
ThreeDTable TimingTable2s  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T2s_COLS,
	.rowHeaderArray = T2s_ROWS,
	.tableCells = T2s_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
//!! KCR Table 1 s
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR1s_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR1s_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR1s_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable1s  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR1s_COLS,
	.rowHeaderArray = KCR1s_ROWS,
	.tableCells = KCR1s_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! KCR Table 2 s
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR2s_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR2s_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR2s_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable2s  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR2s_COLS,
	.rowHeaderArray = KCR2s_ROWS,
	.tableCells = KCR2s_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 1 ss
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float T1ss_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T1ss_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T1ss_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;

ThreeDTable TimingTable1ss  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T1ss_COLS,
	.rowHeaderArray = T1ss_ROWS,
	.tableCells = T1ss_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Timing Table 2 ss
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
float T2ss_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float T2ss_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char T2ss_DATA[]  TIMINGDATA = 
STI_BASE_TIMING_CANDYS;
	
ThreeDTable TimingTable2ss  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = T2ss_COLS,
	.rowHeaderArray = T2ss_ROWS,
	.tableCells = T2ss_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
//!! KCR Table 1 ss
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR1ss_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR1ss_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR1ss_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable1ss  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR1ss_COLS,
	.rowHeaderArray = KCR1ss_ROWS,
	.tableCells = KCR1ss_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! KCR Table 2 ss
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
float KCR2ss_COLS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_COLS};

float KCR2ss_ROWS[]  TIMINGDATA = 
{STI_BASE_TIMING_CANDYS_ROWS};

unsigned char KCR2ss_DATA[]  TIMINGDATA = 
{85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,
85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85,85};

ThreeDTable KnockCorrectionRetardTable2ss  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = KCR2ss_COLS,
	.rowHeaderArray = KCR2ss_ROWS,
	.tableCells = KCR2ss_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
#endif

#if TIMING_RAMTUNING
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!Timing Ram table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!	
ThreeDTable TimingRamTable  TIMINGDATA = {
	.columnCount = 20,
	.rowCount = 20,
	.columnHeaderArray = &(pRamVariables->TimingRamCols),
	.rowHeaderArray = &(pRamVariables->TimingRamRows),
	.tableCells = &(pRamVariables->TimingRamData),
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset
#endif

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Launch Control Timing Retard Table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float LCTR_COLS[]  TIMINGDATA = 
{0,4,6,8,12};

float LCTR_ROWS[]  TIMINGDATA = 
{2800,3000,3600,4000,4400,4800,5200,5600,6000,6400,6800,7200};

unsigned char LCTR_DATA[]  TIMINGDATA = 
{57, 57, 57, 57, 57,
57,	57,	57,	57,	57,
57,	57,	57,	57,	57,
59,	59,	58,	58,	57,
60,	59,	59,	58,	57,
62,	61,	60,	58,	57,
63,	62,	60,	59,	57,
65,	63,	61,	59,	57,
66,	64,	62,	59,	57,
68,	65,	63,	60,	57,
69,	66,	63,	60,	57,
71,	68,	64,	61,	57,
};
	
ThreeDTable LCTimingRetardTable  TIMINGDATA = {
	.columnCount = 5,
	.rowCount = 12,
	.columnHeaderArray = LCTR_COLS,
	.rowHeaderArray = LCTR_ROWS,
	.tableCells = LCTR_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.3515625f,	//
	.offset = -20.0f }; 	//-20 offset

#endif