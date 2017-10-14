#define MOD_ECUID 429ED6E3BD
#define MOD_DATE 14.10.17.18.57
#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G101N
#define ECU_IDENTIFIER 5C42504007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D4328)
#define dRomHoleStart (0x000E1D40)
#define pRamHoleStart (0xFFFFA690)
#define sPull2DFloat (0x000BE844)
#define sPull3DFloat (0x000BE8F8)

/////////////////////
// Switch Hacks
/////////////////////

#define tCrankingFuelA (0x000862FC)
#define tCrankingFuelB (0x00086310)
#define tCrankingFuelC (0x00086324)
#define tCrankingFuelD (0x00086338)
#define tCrankingFuelE (0x0008634C)
#define tCrankingFuelF (0x00086360)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00042D1C)
#define sRevLimStart (0x000351C0)
#define sRevLimEnd (0x00035200)
#define pFlagsRevLim ((unsigned char*)0xFFFF7788)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004B10)
#define sMafCalc (0x00004AB4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C74F0)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007AAB4)
#define hCelSignal (0x0007AB8C)
#define pCelSignalOem ((unsigned char*)0xFFFF997E)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00084C70)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00042848)
#define sWgdc (0x00013F64)
#define tWgdcInitial (0x00084C54)
#define tWgdcMax (0x00084C38)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7478)
#define tPolf (0x00087074)
#define pPolfEnrich (0xFFFF7478)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF79A8)
#define tBaseTimingPCruise (0x00087D1C)
#define tBaseTimingPNonCruise (0x00087D38)
#define tBaseTimingRCruiseAvcs (0x00087D54)
#define tBaseTimingRNonCruiseAvcs (0x00087D70)
#define pKcaIam (0xFFFF7CD0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF61F3)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF61F2)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF61F4)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF67DB)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6A69)
#define pFbkc4 ((float*)0xFFFF7C60)
#define pIam1 ((unsigned char*)0xFFFF6A6B)
#define pIam4 ((float*)0xFFFF2D1C)
#define pEngineSpeed ((float*)0xFFFF682C)
#define pVehicleSpeed ((float*)0xFFFF6808)
#define pCoolantTemp ((float*)0xFFFF413C)
#define pAtmoPress ((float*)0xFFFF6A88)
#define pManifoldAbsolutePressure ((float*)0xFFFF6438)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF6610)
#define pReqTorque ((float*)0xFFFF7FC4)
#define pThrottlePlate ((float*)0xFFFF6508)
#define pCurrentGear ((unsigned char*)0xFFFF6A19)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2D7C)
#define dLoadSmoothingB (0x000C2D78)
#define dLoadSmoothingAlt (0x000C2D74)
#define dLoadSmoothingFinal (0x000C2D88)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000102A4)
#define hMemoryReset (0x0000FC04)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C58)

