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
/*
void Timers(float Minutes, float Seconds, unsigned char Number)
{
	if (Number == 1)
		TimerA(Minutes, Seconds);
	else if Number == 2)
		TimerB(Minutes, Seconds);
	else if Number == 3)
		TimerC(Minutes, Seconds);
}

void TimerA(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimerA < 1)
        {
            pRamVariables->StartTimerA = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimerA -= 1;
        }
	if (pRamVariables->StartTimerA < 1)
        {
            pRamVariables->TimerUpA = 0x01;
        }
    else
        {
            pRamVariables->TimerUpA = 0x00;
        }
}

void TimerB(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimerB < 1)
        {
            pRamVariables->StartTimerB = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimerB -= 1;
        }
	if (pRamVariables->StartTimerB < 1)
        {
            pRamVariables->TimerUpB = 0x01;
        }
    else
        {
            pRamVariables->TimerUpB = 0x00;
        }
}

void TimerC(float Minutes, float Seconds)
{
    if (pRamVariables->StartTimerC < 1)
        {
            pRamVariables->StartTimerC = (((Minutes * 60) + Seconds) * CyclesPerSec);
        }
    else
        {
            pRamVariables->StartTimerC -= 1;
        }
	if (pRamVariables->StartTimerC < 1)
        {
            pRamVariables->TimerUpC = 0x01;
        }
    else
        {
            pRamVariables->TimerUpC = 0x00;
        }
}*/
#endif
