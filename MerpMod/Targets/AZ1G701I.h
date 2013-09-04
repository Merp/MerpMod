#define MOD_DATE 13.4.29.1654

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G701I
#define ECU_IDENTIFIER 7212786007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D69F4)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFAFF0)
#define sPull2DFloat (0x000BE804)
#define sPull3DFloat (0x000BE8B8)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00046C34)
#define sRevLimStart (0x00038CF8)
#define sRevLimEnd (0x00038D38)
#define pFlagsRevLim ((char*)0xFFFF7A58)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8FCC)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00090CA8)
#define hCelSignal (0x00090D2C)
#define pCelSignalOem ((char*)0xFFFFA412)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00046610)
#define sWgdc (0x000132EC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7748)
#define pPolfEnrich (0xFFFF7748)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7C78)
#define pKcaIam (0xFFFF7FA0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF6167)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF6166)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF6168)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF677F)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6A10)
#define pFbkc4 ((float*)0xFFFF7F30)
#define pIam1 ((char*)0xFFFF6A12)
#define pIam4 ((float*)0xFFFF30B8)
#define pEngineSpeed ((float*)0xFFFF67D0)
#define pVehicleSpeed ((float*)0xFFFF67AC)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6A34)
#define pManifoldAbsolutePressure ((float*)0xFFFF63AC)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF6594)
#define pReqTorque ((float*)0xFFFF8294)
#define pThrottlePlate ((float*)0xFFFF647C)
#define pCurrentGear ((char*)0xFFFF69BD)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C28BC)
#define dLoadSmoothingB (0x000C28B8)
#define dLoadSmoothingAlt (0x000C28B4)
#define dLoadSmoothingFinal (0x000C28C8)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000100C0)
#define hMemoryReset (0x0000FB18)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011A64)

