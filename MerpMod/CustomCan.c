/*
	Copyright (C) 2017-2017 Johnny Lloyd Wall jlwall@gmail.com
	
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
#if CAN_HACKS

void setupMailBoxStruct(CanMessageSetupStruct* cs)
{
	unsigned short* ptr;	
	ptr = (unsigned short*)(0xFFFFD100+ 0x800*cs->bus + 0x20*(unsigned short)cs->mailBox);
	if(cs->ext == 0) //11-bit, not extended
		{
		ptr[0] = ((unsigned short)cs->id<<4)&0x7FF0;
		ptr[1] = 0;
		}
	else if(cs->ext == 1)
		{
		ptr[0]  = (unsigned short)(((unsigned long)cs->id>>16)&0x0003);
		ptr[0] += (unsigned short)(0x0004);
		ptr[0] += (unsigned short)(((unsigned long)cs->id>>14)&0x7FF0);
		ptr[1] = ((unsigned short)cs->id)&0xFFFF;
		}		
	ptr[2] = (((unsigned short)cs->mcs<<8)&0x700) + ((unsigned short)cs->dlc&0x0F);	
}

void updateCanDT(CanDataSendStuct* dt)
{
	unsigned long addrtemp;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	if(dt->addr >= 0xFFFF0000)
	{		
		addrtemp = 0xFFFFD100;
		addrtemp += 0x800*(unsigned long)(ccmGroup[dt->ccm].bus&0x01);		
		addrtemp += 0x020*(unsigned long)(ccmGroup[dt->ccm].mailBox&0x1F);
		addrtemp += 0x08;
		addrtemp += (unsigned long)dt->bytePos&0x07;	
		switch(dt->type)
		{
		case 1: 
			{
			unsigned char* ptrSource = (unsigned char*)dt->addr;
			unsigned char* ptrSink = (unsigned char*)addrtemp;		
			ptrSink[0] = ptrSource[0];			
			}
			break;
		case 2: 
			{			
			if(((addrtemp%2) ==0) && ((dt->addr%2) ==0))
				{
				unsigned short* ptrSource = (unsigned short*)dt->addr;
				unsigned short* ptrSink = (unsigned short*)addrtemp;	
				ptrSink[0] = ptrSource[0];
				}
			}
			break;		
		case 3: 
			{				
			if(((addrtemp%4) ==0) && ((dt->addr%4) ==0))
				{
				unsigned long* ptrSource = (unsigned long*)dt->addr;
				unsigned long* ptrSink = (unsigned long*)addrtemp;
				ptrSink[0] = ptrSource[0];
				}
			}
			break;		
		case 4: 
			{			
			if(((addrtemp%4) ==0) && ((dt->addr%4) ==0))
				{
				float* ptrSource = (float*)dt->addr;
				float* ptrSink = (float*)addrtemp;	
				ptrSink[0] = ptrSource[0];
				}
			}
			break;
		
		default: 
			break;	
		}		
	}
}

void updateCanRaw(unsigned long addr, unsigned char type, unsigned char ccm, unsigned char bytePos)
{
	unsigned long addrtemp;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	if(addr >= 0xFFFF0000)
	{		
		addrtemp = 0xFFFFD100;
		addrtemp += 0x800*(unsigned long)ccmGroup[ccm].bus;
		addrtemp += 0x020*(unsigned long)ccmGroup[ccm].mailBox;
		addrtemp += 0x08;
		addrtemp += (unsigned long)bytePos&0x07;	
		switch(type)
		{
		case 1: 
			if(((addrtemp%1) ==0) && ((addr%1) ==0))
			{
				unsigned char* ptrSource = (unsigned char*)addr;
				unsigned char* ptrSink = (unsigned char*)addrtemp;		
				ptrSink[0] = ptrSource[0];			
			}
			break;
		case 2: 
			{				
			if(((addrtemp%2) ==0) && ((addr%2) ==0))
				{
				unsigned short* ptrSource = (unsigned short*)addr;
				unsigned short* ptrSink = (unsigned short*)addrtemp;
				ptrSink[0] = ptrSource[0];
				}
			}
			break;		
		case 3: 
			{			
			if(((addrtemp%4) ==0) && ((addr%4) ==0))
				{
				unsigned long* ptrSource = (unsigned long*)addr;
				unsigned long* ptrSink = (unsigned long*)addrtemp;	
				ptrSink[0] = ptrSource[0];
				}
			}
			break;				
		default: 
			break;	
		}		
	}
}

void sendCanMessage(unsigned char ccm)
{
	unsigned short* ptr;
	unsigned char* ptrMB;	
	unsigned short tmp;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	ptrMB = (unsigned char*)(0xFFFFD100 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x20*(ccmGroup[ccm].mailBox&0x1f) + 0x04);			
	if((ptrMB[0]&0x07) == 0x00) //Check if Mailbox is a TX
	{		
		if(ccmGroup[ccm].mailBox>=16)
			{
			tmp = (unsigned short)ccmGroup[ccm].mailBox-16;
			ptr = (unsigned short*)(0xFFFFD000 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x20);	//This is 	TXPR1
			}
		else
			{
			tmp = (unsigned short)ccmGroup[ccm].mailBox;
			ptr = (unsigned short*)(0xFFFFD000 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x22);	//This is 	TXPR0	
			}
		switch(tmp)
		{
			case  0: ptr[0] = 0x001; break;
			case  1: ptr[0] = 0x002; break;
			case  2: ptr[0] = 0x004; break;
			case  3: ptr[0] = 0x008; break;
			case  4: ptr[0] = 0x010; break;
			case  5: ptr[0] = 0x020; break;
			case  6: ptr[0] = 0x040; break;
			case  7: ptr[0] = 0x080; break;
			case  8: ptr[0] = 0x100; break;
			case  9: ptr[0] = 0x200; break;
			case 10: ptr[0] = 0x400; break;
			case 11: ptr[0] = 0x800; break;
			case 12: ptr[0] = 0x1000; break;
			case 13: ptr[0] = 0x2000; break;
			case 14: ptr[0] = 0x4000; break;
			case 15: ptr[0] = 0x8000; break;
			default: break;
		}
	}
}

unsigned short returnShifter(unsigned char c)
{	
	switch(c)
		{
		case  0: return 0x001; break;
		case  1: return 0x002; break;
		case  2: return 0x004; break;
		case  3: return 0x008; break;
		case  4: return 0x010; break;
		case  5: return 0x020; break;
		case  6: return 0x040; break;
		case  7: return 0x080; break;
		case  8: return 0x100; break;
		case  9: return 0x200; break;
		case 10: return 0x400; break;
		case 11: return 0x800; break;
		case 12: return 0x1000; break;
		case 13: return 0x2000; break;
		case 14: return 0x4000; break;
		case 15: return 0x8000; break;
		default: return 0;break;
		}
}

void recieveCanMessage(unsigned char ccm)
{
	unsigned short* ptr;
	unsigned char* ptrMB;	
	unsigned short tmp;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	ptrMB = (unsigned char*)(0xFFFFD100 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x20*(ccmGroup[ccm].mailBox&0x1f) + 0x04);			
	if((ptrMB[0]&0x07) == 0x03) //Check if Mailbox is a TX
	{		
		if(ccmGroup[ccm].mailBox>=16)
		{
			tmp = (unsigned short)ccmGroup[ccm].mailBox-16;
			ptr = (unsigned short*)(0xFFFFD000 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x40);	//This is 	RXPR1
		}
		else
		{
			tmp = (unsigned short)ccmGroup[ccm].mailBox;
			ptr = (unsigned short*)(0xFFFFD000 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x42);	//This is 	RXPR0	
		}	
		if((ptr[0] & returnShifter(tmp)) >0)
		{		
			switch(tmp)
			{
				case  0: ptr[0] = 0x001; break;
				case  1: ptr[0] = 0x002; break;
				case  2: ptr[0] = 0x004; break;
				case  3: ptr[0] = 0x008; break;
				case  4: ptr[0] = 0x010; break;
				case  5: ptr[0] = 0x020; break;
				case  6: ptr[0] = 0x040; break;
				case  7: ptr[0] = 0x080; break;
				case  8: ptr[0] = 0x100; break;
				case  9: ptr[0] = 0x200; break;
				case 10: ptr[0] = 0x400; break;
				case 11: ptr[0] = 0x800; break;
				case 12: ptr[0] = 0x1000; break;
				case 13: ptr[0] = 0x2000; break;
				case 14: ptr[0] = 0x4000; break;
				case 15: ptr[0] = 0x8000; break;
				default: return; break;
			}
				
			if(ccmGroup[ccm].callback >0)
			{
				ptrMB = (unsigned char*)(0xFFFFD100 + 0x800*(ccmGroup[ccm].bus&0x01) + 0x20*(ccmGroup[ccm].mailBox&0x1f) + 0x08);		
				if(ccmGroup[ccm].callback%4 == 0) //Only call it if its U32 alligned
				{
					void (*callbackPtr)(unsigned char*) = (void*)ccmGroup[ccm].callback;
					(*callbackPtr)(ptrMB);					
				}
			}			
		}		
	}
}

void sampleCallback(unsigned char* data)
{
	data[0] += 1;	
	data[1] += 2;
	data[2] += 3;
}

void canCallbackRamTune(unsigned char* data)
{
	if(data[2] == 0x55) // Write to RAM
	{
		unsigned long addr = (unsigned long)(0xFFFF0000 + (unsigned long)data[0]*256 + (unsigned long)data[1]);
		switch(data[3])
		{
			case 1:		// Write to 1 byte
				if((addr%1)==0)
				{
					unsigned char* ptr = (unsigned char*)addr;
					ptr[0] = data[4];			
				}
				break;
			case 2:		// Write to 2 byte
				if((addr%2)==0)
				{
					unsigned short* ptr = (unsigned short*)addr;
					ptr[0] = (unsigned short)(data[4]*256+data[5]);			
				}
				break;
			case 3:		// Write to 4 byte
				if((addr%4)==0)
				{
					unsigned long* ptr = (unsigned long*)addr;
					ptr[0] = (unsigned long)(data[4]*256*256*256+data[5]*256*256+data[6]*256+data[7]);			
				}
				break;
			default: break;
		}
	}
	else if(data[2] == 0x66)
	{
		unsigned long addr = (unsigned long)(0xFFFF0000 + (unsigned long)data[0]*256 + (unsigned long)data[1]);
		switch(data[3])
		{
			case 1:		// Write to 1 byte
				if((addr%1)==0)
				{					
					updateCanRaw(addr, 1, 7, 4);
					sendCanMessage(7);													
				}
				break;
			case 2:		// Write to 2 byte
				if((addr%2)==0)
				{
					updateCanRaw(addr, 2, 7, 4);
					sendCanMessage(7);													
				}
				break;
			case 3:		// Write to 4 byte
				if((addr%4)==0)
				{
					updateCanRaw(addr, 3, 7, 4);
					sendCanMessage(7);													
				}
			break;
			default: break;
		}
	}
}
  
void CanSetup()
{
	unsigned char i = 0;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	while(i< 8)
	{
		if(ccmGroup[i].mcs < 7)
		{
			setupMailBoxStruct(&ccmGroup[i]);
		}	
		i++;
	}
	pRamVariables->initFunctionRun = 1;
}



void CustomCanService()
{
	unsigned char i = 0;
	CanMessageSetupStruct *ccmGroup = (CanMessageSetupStruct *)(&ccm00);
	
	pRamVariables->randomTimer++;
	if(pRamVariables->initFunctionRun != 1)
	{
		CanSetup();
	}
	
	//Update all possible DataTransfers, stop when list is seen to be not configured	
	while(i<32)
	{
		if(cmDTGroup[i]->type > 0) //update if a Type is defined
		{
			updateCanDT(cmDTGroup[i]);
		}
		else
		{
			break;	//Finished with this list, break out
		}
		i++;
	}
	
	//Send all Possible Messages
	i=0;
	while(i<8)
	{
		if((ccmGroup[i].mcs == mcsTrans) && (ccmGroup[i].rate>0)) //Send if MCS is set to 0, and has a periodic rate greater than 0
		{
			if(++pRamVariables->ccmSendTimers[i] >= ccmGroup[i].rate) //Send message once 1mSec timer has rolled up
			{
				sendCanMessage(i);
				pRamVariables->ccmSendTimers[i] = 0; //rest timer
			}
		}			
		else if(ccmGroup[i].mcs == mcsReceive) //recieve
		{
			recieveCanMessage(i);	
		}
		i++;
	}
}
#endif