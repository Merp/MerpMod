#define MOD_DATE 13.5.6.212

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2WC012E
#define ECU_IDENTIFIER 3B02594316
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x0005F004)
#define dRomHoleStart (0x00069C10)
#define pRamHoleStart (0xFFFFCA00)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00011310)
#define sRevLimStart (0x00025758)
#define sRevLimEnd (0x0002578E)
#define pFlagsRevLim ((char*)0xFFFFB868)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000077B4)
#define sMafCalc (0x00007758)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000589B0)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0004C4FC)
#define hCelSignal (0x0004C614)
#define pCelSignalOem ((char*)0xFFFFC692)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00010FF8)
#define sWgdc (0x00013350)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFFB6E8)
#define tPolf (0x00054A90)
#define pPolfEnrich (0xFFFFB6E8)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFFB9F8)
#define pKcaIam (0xFFFFBB60)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pClutchFlags ((char*)0xFFFFB1E9)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFFB364)
#define pFbkc4 ((float*)0xFFFFBB1C)
#define pIam1 ((char*)0xFFFFB369)
#define pIam4 ((float*)0xFFFF822C)
#define pEngineSpeed ((float*)0xFFFFB218)
#define pVehicleSpeed ((float*)0xFFFFB208)
#define pCoolantTemp ((float*)0xFFFF90C8)
#define pAtmoPress ((float*)0xFFFF9134)
#define pManifoldAbsolutePressure ((float*)0xFFFFAF94)
#define pIntakeAirTemp ((float*)0xFFFF90B8)
#define pMassAirFlow ((float*)0xFFFF90F4)
#define pMafSensorVoltage ((short*)0xFFFF9022)
#define pEngineLoad ((float*)0xFFFFB0E0)
#define pThrottlePlate ((float*)0xFFFFB024)
#define pCurrentGear ((char*)0xFFFFB319)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x0005774C)
#define dLoadSmoothingB (0x00057750)
#define dLoadSmoothingFinal (0x00057754)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F280)
#define hMemoryReset (0x0000CC84)
#define pMemoryResetLimit (0xFFFFDFFB)
#define hMemoryResetLimit (0x0000F468)

