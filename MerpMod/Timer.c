/*    Copyright (C) 2014 Scott T Anderson & 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
   
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
//Fuelup Timer
void Timer(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimer < 1)
        {
            pRamVariables->StartTimer = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimer -= 1;
        }
	if (pRamVariables->StartTimer < 1)
        {
            pRamVariables->TimerUp = 0x01;
        }
    else
        {
            pRamVariables->TimerUp = 0x00;
        }
}

void Timers(float Minutes, float Seconds, unsigned char Number)
{
	if (Number == 1)
		Timer1(Minutes, Seconds);
	else if (Number == 2)
		Timer2(Minutes, Seconds);
	else if (Number == 3)
		Timer3(Minutes, Seconds);
}
//FlexFuel Timer
void Timer1(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimer1 < 1)
        {
            pRamVariables->StartTimer1 = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimer1 -= 1;
        }
	if (pRamVariables->StartTimer1 < 1)
        {
            pRamVariables->TimerUp1 = 0x01;
        }
    else
        {
            pRamVariables->TimerUp1 = 0x00;
        }
}
//Flex Fuel Timer
void Timer2(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimer2 < 1)
        {
            pRamVariables->StartTimer2 = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimer2 -= 1;
        }
	if (pRamVariables->StartTimer2 < 1)
        {
            pRamVariables->TimerUp2 = 0x01;
        }
    else
        {
            pRamVariables->TimerUp2 = 0x00;
        }
}
//ALS Timer
void Timer3(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimer3 < 1)
        {
            pRamVariables->StartTimer3 = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimer3 -= 1;
        }
	if (pRamVariables->StartTimer3 < 1)
        {
            pRamVariables->TimerUp3 = 0x01;
        }
    else
        {
            pRamVariables->TimerUp3 = 0x00;
        }
}
#endif
