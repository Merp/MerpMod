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

#if PORT_LOGGER

	// I/O Ports
/*
PAIOR_W 0xFFFFF720
PACRH_W 0xFFFFF722
PACRL_W 0xFFFFF724
PADR_W 0xFFFFF726
*/
#define PAPR_W ((unsigned short*)0xFFFFF780)

/*PBIOR_W 0xFFFFF730
PBCRH_W 0xFFFFF732
PBCRL_W 0xFFFFF734
PBIR_W 0xFFFFF736
PBDR_W 0xFFFFF738
*/
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
#define PLPR_W ((unsigned short*)0xFFFFF788)


unsigned short* PortAddresses[11] PORTDATA = {
	PAPR_W,
	PBPR_W,
	PCDR_W,
	PDPR_W,
	PEDR_W,
	PFDR_W,
	PGDR_W,
	PHDR_W,
	PJPR_W,
	PKDR_W,
	PLPR_W
};

void PortLogger(){

	int i;
	int count = (sizeof(PortAddresses)/sizeof(PortAddresses[0]));
	pRamVariables->testchar1 = 0x01;
	pRamVariables->testchar2 = 0x02;
	pRamVariables->testchar3 = 0x04;
	pRamVariables->testchar4 = 0x08;
	for(i = 0;i<count;i++)
	{
		pRamVariables->PortParameters[i] = *(PortAddresses[i]);
	}
}

#endif