#define MOD_DATE 13.5.11.1322

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DK100P
#define ECU_IDENTIFIER 4E42504007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CED94)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF9CA0)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000020AC)
#define sPull3DFloat (0x00002160)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000151E4)
#define sRevLimStart (0x00034824)
#define sRevLimEnd (0x0003485A)
#define pFlagsRevLim ((char*)0xFFFF7374)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008468)
#define sMafCalc (0x0000840C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C73C4)

/////////////////////
// Cel Hacks
/////////////////////


/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0008996C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00014DA0)
#define sWgdc (0x0001813C)
#define tWgdcInitial (0x000898C4)
#define tWgdcMax (0x000898FC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF71E0)
#define tPolf (0x0008B1C4)
#define pPolfEnrich (0xFFFF71E0)

/////////////////////
// Timing Hacks
/////////////////////

#define tBaseTiming (0x0008B990)
#define pBaseTiming (0xFFFF7534)
#define pKcaIam (0xFFFF76D0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF6565)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF6566)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF6567)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF6AE1)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6C64)
#define pFbkc4 ((float*)0xFFFF768C)
#define pIam1 ((char*)0xFFFF6C69)
#define pIam4 ((float*)0xFFFF2B0C)
#define pEngineSpeed ((float*)0xFFFF6B10)
#define pVehicleSpeed ((float*)0xFFFF6B00)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF8374)
#define pManifoldAbsolutePressure ((float*)0xFFFF6774)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF6924)
#define pReqTorque ((float*)0xFFFF7980)
#define pThrottlePlate ((float*)0xFFFF6818)
#define pCurrentGear ((char*)0xFFFF6C19)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C246C)
#define dLoadSmoothingB (0x000C2470)
#define dLoadSmoothingFinal (0x000C247C)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FA6C)
#define hMemoryReset (0x0000DD28)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012490)

