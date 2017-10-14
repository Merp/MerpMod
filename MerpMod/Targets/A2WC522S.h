#define MOD_ECUID 951B666E2D
#define MOD_DATE 14.10.17.17.21
#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2WC522S
#define ECU_IDENTIFIER 2F12795606
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CD87C)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF73B0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Switch Hacks
/////////////////////

#define tTipInEnrich (0x000840C0)
#define tCrankingFuelA (0x00083DC0)
#define tCrankingFuelB (0x00083DD4)
#define tCrankingFuelC (0x00083DE8)
#define tCrankingFuelD (0x00083DFC)
#define tStartupEnrich2_1A (0x00083E60)
#define tStartupEnrich2_1B (0x00083E88)
#define tStartupEnrich2_2A (0x00083E74)
#define tStartupEnrich2_2B (0x00083E9C)
#define tStartupEnrich3_1A (0x00083E10)
#define tStartupEnrich3_1B (0x00083E24)
#define tStartupEnrich3_2A (0x00083E38)
#define tStartupEnrich3_2B (0x00083E4C)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000127E8)
#define sRevLimStart (0x000318DC)
#define sRevLimEnd (0x00031912)
#define pFlagsRevLim ((unsigned char*)0xFFFF5A40)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00007A04)
#define sMafCalc (0x000079A8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C6E48)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007AFD0)
#define hCelSignal (0x0007B0E8)
#define pCelSignalOem ((unsigned char*)0xFFFF7002)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000122B4)
#define sWgdc (0x00014B20)
#define tWgdcMax (0x00082D5C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF5884)
#define tPolf (0x000843E8)
#define pPolfEnrich (0xFFFF5884)

/////////////////////
// Timing Hacks
/////////////////////

#define tBaseTiming (0x000849F8)
#define pBaseTiming (0xFFFF5BF4)
#define pKcaIam (0xFFFF5D68)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF4D64)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF4D64)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF4D64)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF51C9)
#define ClutchBitMask ((unsigned char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF5344)
#define pFbkc4 ((float*)0xFFFF5D24)
#define pIam1 ((unsigned char*)0xFFFF5349)
#define pIam4 ((float*)0xFFFF267C)
#define pEngineSpeed ((float*)0xFFFF51F8)
#define pVehicleSpeed ((float*)0xFFFF51E8)
#define pCoolantTemp ((float*)0xFFFF2DC8)
#define pAtmoPress ((float*)0xFFFF2E34)
#define pManifoldAbsolutePressure ((float*)0xFFFF4F40)
#define pIntakeAirTemp ((float*)0xFFFF2DB8)
#define pMassAirFlow ((float*)0xFFFF2DF4)
#define pMafSensorVoltage ((short*)0xFFFF2D22)
#define pEngineLoad ((float*)0xFFFF50C0)
#define pReqTorque ((float*)0xFFFF5F08)
#define pThrottlePlate ((float*)0xFFFF4FD0)
#define pCurrentGear ((unsigned char*)0xFFFF52F9)
#define pAf1Res ((float*)0xFFFF4A54)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C23A4)
#define dLoadSmoothingB (0x000C23A8)
#define dLoadSmoothingFinal (0x000C23AC)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F928)
#define hMemoryReset (0x0000D324)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x0000FFF8)

