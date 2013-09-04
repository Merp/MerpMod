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

#if PROG_MODE
///////////////
//PROGRAMMING MODE TABLES
////////////////////////////////

//TODO: use this stuff??		
float BlendIncrement PROGMODEDATA = 0.01f;
float RevLimitIncrement PROGMODEDATA = 250.0f;
float RevLimitMax PROGMODEDATA = 9500.0f;
float RevLimitMin PROGMODEDATA = 4000.0f;			
float FFSIncrement PROGMODEDATA = 250.0f;
float FFSMax PROGMODEDATA = 9000.0f;
float FFSMin PROGMODEDATA = 3000.0f;					
float LCIncrement PROGMODEDATA =100.0f;
float LCMax PROGMODEDATA = 8000.0f;
float LCMin PROGMODEDATA = 2000.0f;

#endif