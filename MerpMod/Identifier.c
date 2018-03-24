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

#if CEL_HACKS
	char* CelSignalMod __attribute__ ((section ("Test_Section"),aligned(4))) = &(pRamVariables.CelSignal);
#endif

#define DATE_AS_INT (((COMPILE_YEAR - 2000) * 12 + COMPILE_MONTH) * 31 + COMPILE_DAY)



unsigned char ModIdentifier[] __attribute__ ((section ("RomHole_Identifier"),aligned(4))) = MOD_IDENTIFIER;


#ifdef SMALLROM
unsigned char ModDisclaimer[] __attribute__ ((section ("RomHole_Misc"),aligned(4))) = "COPYRIGHT 2012,2013 MERRILL A MYERS III DISTRIBUTION PROHIBITED OFFROAD USE ONLY NO WARRANTY";

#else
unsigned char ModDisclaimer[] __attribute__ ((section ("RomHole_Misc"),aligned(4))) = "COPYRIGHT 2012,2013 Merrill A. Myers III, merrillamyersiii@gmail.com merrillamyersiii@gmail.com. UNAUTHORIZED DISTRIBUTION STRICTLY PROHIBITED. OFFROAD USE ONLY. NO WARRANTY. THIS SOFTWARE IS LICENSED TO YOU “AS IS,” AND WITHOUT ANY WARRANTY OF ANY KIND, WHETHER ORAL, WRITTEN, EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT.";
#endif

#if VIN_HACKS


const VinBlockStruct VinBlock __attribute__ ((section ("RomHole_Vin"),aligned(8))) = 
{
	s1: 0x54320001,
	s2: 0x65430001,
	Vin: {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	e1: 0x54320001,
	e2: 0x65430002
};

unsigned char Licensee[136] __attribute__ ((section ("RomHole_Misc"),aligned(8))) = {0x54,0x32,0x00,0x01,0x65,0x43,0x00,0x03,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0x54,0x32,0x00,0x01,0x65,0x43,0x00,0x04};
#endif

long RomHoleEndMarker __attribute__ ((section ("RomHole_RomHoleEndMarker"),aligned(4))) = (long)"0xA5A5A5A5";