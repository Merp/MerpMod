
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

//SCANNER:
//Initialize: set scan range 0xFFFF0000 - 0xFFFFBFFF (SH7058)
//Set minimum byte size for ramhole.
//Pop range from array.
//Call range reader.

//RANGE READER:
//init vars.
//Read @ address
//If same as previous value, increment counter
//Keep going.
//
//If minimum size is met, store the start address in array.
//Keep going
//When end is found (different value or range bound) store end address (and count? somewhat redundant.) in array. 
//
//If not at end of range, repeat range scan with new start bound!.
//Else return
}

#endif