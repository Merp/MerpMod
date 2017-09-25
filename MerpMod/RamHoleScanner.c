
#include "EcuHacks.h"

#if RAM_HOLE_SCANNER

void RamHoleScanner(){

unsigned int addr = 0xFFFF0000;
addr |= (unsigned int)pRamVariables->ScannedAddress;
pRamVariables->ScannedValue = *(unsigned short*)addr;
pRamVariables->ScannedAddress +=2;
if(pRamVariables->ScannedAddress > 0xBFFF)
	pRamVariables->ScannedAddress = 0x0000; //TODO: set on a per CPU basis!
	// store full address and perform CRC32 on ram?

//pRamVariables->ScannedAddress USHORT
//pRamVariables->ScannedValue USHORT
//pRamVariables->ScannedtackPointer ULONG
}

#endif