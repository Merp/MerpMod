#define MOD_DATE 14.4.9.1853

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID D2WD701C
#define ECU_IDENTIFIER 3c4a384106
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000C9AF4)
#define dRomHoleStart (0x000CC000)
#define pRamHoleStart (0xFFFF8120)
#define pRamHoleEnd (0xFFFFB400)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000128FC)
#define sRevLimStart (0x00026000)
#define sRevLimEnd (0x0001D734)
#define pFlagsRevLim ((unsigned char*)0xFFFF5F78)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00007CA4)
#define sMafCalc (0x00007C48)

/////////////////////
// Injector Hack
/////////////////////


/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x000542B8)
#define hCelSignal (0x000543D0)
#define pCelSignalOem ((unsigned char*)0xFFFF7D8E)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////


/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF5DFC)
#define hPolf (0x00012938)
#define sPolf (0x000237DC)
#define pPolfEnrich (0xFFFF5DFC)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF6178)
#define pKcaIam (0xFFFF6DB4)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF6B28)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF6B28)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF6B28)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF551F)
#define ClutchBitMask ((unsigned char)0x40)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFF6D94)
#define pIam4 ((float*)0xFFFF2528)
#define pEngineSpeed ((float*)0xFFFF5548)
#define pVehicleSpeed ((float*)0xFFFF5540)
#define pCoolantTemp ((float*)0xFFFF4BBC)
#define pAtmoPress ((float*)0xFFFF4BE8)
#define pManifoldAbsolutePressure ((float*)0xFFFF52A4)
#define pIntakeAirTemp ((float*)0xFFFF4BAC)
#define pMassAirFlow ((float*)0xFFFF4BE4)
#define pMafSensorVoltage ((short*)0xFFFF4B06)
#define pEngineLoad ((float*)0xFFFF543C)
#define pThrottlePlate ((float*)0xFFFF52C8)
#define pAf1Res ((float*)0xFFFF4E70)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1208)
#define dLoadSmoothingB (0x000C120C)
#define dLoadSmoothingAlt (0x000C1204)
#define dLoadSmoothingAlt2 (0x000C1200)
#define dLoadSmoothingFinal (0x000C1210)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FC90)
#define hMemoryReset (0x0000D1FC)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x00010360)

