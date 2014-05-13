#define MOD_DATE 14.5.10.044

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2ZJ500F
#define ECU_IDENTIFIER 3144504006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x00058934)
#define dRomHoleStart (0x0006D000)
#define pRamHoleStart (0xFFFFBE40)
#define pRamHoleEnd (0xFFFFC500)
#define sPull2DFloat (0x0000208C)
#define sPull3DFloat (0x0000211C)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000100C4)
#define sRevLimStart (0x00021668)
#define sRevLimEnd (0x0002169E)
#define pFlagsRevLim ((unsigned char*)0xFFFFAAD0)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000076B8)
#define sMafCalc (0x00007658)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x00052FA8)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x000436C0)
#define hCelSignal (0x000437D8)
#define pCelSignalOem ((unsigned char*)0xFFFFBACA)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x0000FCB4)
#define sWgdc (0x00012510)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFFA994)
#define pPolfEnrich (0xFFFFA994)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFFAC68)
#define pKcaIam (0xFFFFAD9C)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pClutchFlags ((unsigned char*)0xFFFFA4A1)
#define ClutchBitMask ((unsigned char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFFAD58)
#define pIam4 ((float*)0xFFFF83CC)
#define pEngineSpeed ((float*)0xFFFFA4D0)
#define pVehicleSpeed ((float*)0xFFFFA4C0)
#define pCoolantTemp ((float*)0xFFFF90D0)
#define pAtmoPress ((float*)0xFFFF9128)
#define pManifoldAbsolutePressure ((float*)0xFFFFA2F4)
#define pIntakeAirTemp ((float*)0xFFFF90C0)
#define pMassAirFlow ((float*)0xFFFF90FC)
#define pMafSensorVoltage ((short*)0xFFFF9026)
#define pEngineLoad ((float*)0xFFFFA41C)
#define pThrottlePlate ((float*)0xFFFFA314)
#define pCurrentGear ((unsigned char*)0xFFFFA5C5)
#define pAf1Res ((float*)0xFFFFA01C)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x0004F808)
#define dLoadSmoothingB (0x0004F80C)
#define dLoadSmoothingFinal (0x0004F810)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000E19C)
#define hMemoryReset (0x0000BB00)
#define pMemoryResetLimit (0xFFFFDFFB)
#define hMemoryResetLimit (0x0000E380)

