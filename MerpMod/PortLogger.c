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
#include "SH7058.h"

#if PORT_LOGGER

	// I/O Ports
/*
PAIOR_W 0xFFFFF720
PACRH_W 0xFFFFF722
PACRL_W 0xFFFFF724
PADR_W 0xFFFFF726
*/
#define PADR_W ((unsigned short*)0xFFFFF726)
#define PAPR_W ((unsigned short*)0xFFFFF780)

/*PBIOR_W 0xFFFFF730
PBCRH_W 0xFFFFF732
PBCRL_W 0xFFFFF734
PBIR_W 0xFFFFF736
PBDR_W 0xFFFFF738
*/
#define PBDR_W ((unsigned short*)0xFFFFF738)
#define PBPR_W ((unsigned short*)0xFFFFF782)

/*
PCIOR_W 0xFFFFF73A
PCCR_W 0xFFFFF73C
*/
#define PCDR_W ((unsigned short*)0xFFFFF73E)

/*
PDIOR_W 0xFFFFF740
PDCRH_W 0xFFFFF742
PDCRL_W 0xFFFFF744
PDDR_W 0xFFFFF746
*/
#define PDDR_W ((unsigned short*)0xFFFFF746)
#define PDPR_W ((unsigned short*)0xFFFFF784)

/*
PEIOR_W 0xFFFFF750
PECR_W 0xFFFFF752
*/
#define PEDR_W ((unsigned short*)0xFFFFF754)

/*
PFIOR_W 0xFFFFF748
PFCRH_W 0xFFFFF74A
PFCRL_W 0xFFFFF74C
*/
#define PFDR_W ((unsigned short*)0xFFFFF74E)

/*
PGIOR_W 0xFFFFF760
PGCR_W 0xFFFFF762
*/
#define PGDR_W ((unsigned short*)0xFFFFF764)

/*
PHIOR_W 0xFFFFF728
PHCR_W 0xFFFFF72A
*/
#define PHDR_W ((unsigned short*)0xFFFFF72C)

/*
PJIOR_W 0xFFFFF766
PJCRH_W 0xFFFFF768
PJCRL_W 0xFFFFF76A
PJDR_W 0xFFFFF76C
*/
#define PJDR_W ((unsigned short*)0xFFFFF76C)
#define PJPR_W ((unsigned short*)0xFFFFF786)

/*
PKIOR_W 0xFFFFF770
PKCRH_W 0xFFFFF772
PKCRL_W 0xFFFFF774
PKIR_W 0xFFFFF776
*/
#define PKDR_W ((unsigned short*)0xFFFFF778)
	
/*
PLIOR_W 0xFFFFF756
PLCRH_W 0xFFFFF758
PLCRL_W 0xFFFFF75A
PLIR_W 0xFFFFF75C
PLDR_W 0xFFFFF75E
*/
#define PLDR_W ((unsigned short*)0xFFFFF75E)
#define PLPR_W ((unsigned short*)0xFFFFF788)


unsigned short* PortAddresses[11] PORTDATA = {
	PADR_W,
	PBDR_W,
	PCDR_W,
	PDDR_W,
	PEDR_W,
	PFDR_W,
	PGDR_W,
	PHDR_W,
	PJDR_W,
	PKDR_W,
	PLDR_W
};

void PortLogger(){

	int i;
	int count = (sizeof(PortAddresses)/sizeof(PortAddresses[0]));
	pRamVariables.testchar1 = 0x01;
	pRamVariables.testchar2 = 0x02;
	pRamVariables.testchar3 = 0x04;
	pRamVariables.testchar4 = 0x08;
	for(i = 0;i<count;i++)
	{
		pRamVariables.PortParameters[i] = *(PortAddresses[i]);
	}
}

unsigned short* ADCAddresses[32] PORTDATA = {
(unsigned short*)ADDR0H_B,
(unsigned short*)ADDR1H_B,
(unsigned short*)ADDR2H_B,
(unsigned short*)ADDR3H_B,
(unsigned short*)ADDR4H_B,
(unsigned short*)ADDR5H_B,
(unsigned short*)ADDR6H_B,
(unsigned short*)ADDR7H_B,
(unsigned short*)ADDR8H_B,
(unsigned short*)ADDR9H_B,
(unsigned short*)ADDR10H_B,
(unsigned short*)ADDR11H_B,
(unsigned short*)ADDR12H_B,
(unsigned short*)ADDR13H_B,
(unsigned short*)ADDR14H_B,
(unsigned short*)ADDR15H_B,
(unsigned short*)ADDR16H_B,
(unsigned short*)ADDR17H_B,
(unsigned short*)ADDR18H_B,
(unsigned short*)ADDR19H_B,
(unsigned short*)ADDR20H_B,
(unsigned short*)ADDR21H_B,
(unsigned short*)ADDR22H_B,
(unsigned short*)ADDR23H_B,
(unsigned short*)ADDR24H_B,
(unsigned short*)ADDR25H_B,
(unsigned short*)ADDR26H_B,
(unsigned short*)ADDR27H_B,
(unsigned short*)ADDR28H_B,
(unsigned short*)ADDR29H_B,
(unsigned short*)ADDR30H_B,
(unsigned short*)ADDR31H_B
};

void ADCLogger(){
	int i;
	int count = (sizeof(ADCAddresses)/sizeof(ADCAddresses[0]));
	for(i=0;i<count;i++)
	{
		pRamVariables.ADCParameters[i] = *ADCAddresses[i];
	}
}

#endif