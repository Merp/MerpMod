#define MOD_ECUID CC7F30A737
#define MOD_DATE 14.10.17.19.23
#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1E400U
#define ECU_IDENTIFIER 5142584007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D391C)
#define dRomHoleStart (0x000E2000)
#define pRamHoleStart (0xFFFFA610)
#define sPull2DFloat (0x000BE764)
#define sPull3DFloat (0x000BE818)

/////////////////////
// Switch Hacks
/////////////////////

#define tCrankingFuelA (0x00085284)
#define tCrankingFuelB (0x00085298)
#define tCrankingFuelC (0x000852AC)
#define tCrankingFuelD (0x000852C0)
#define tCrankingFuelE (0x000852D4)
#define tCrankingFuelF (0x000852E8)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0004210C)
#define sRevLimStart (0x00034E88)
#define sRevLimEnd (0x00034EC8)
#define pFlagsRevLim ((unsigned char*)0xFFFF7760)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004B10)
#define sMafCalc (0x00004AB4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C7130)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00079AF0)
#define hCelSignal (0x00079BC8)
#define pCelSignalOem ((unsigned char*)0xFFFF98EA)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00083C68)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00041C4C)
#define sWgdc (0x00013F64)
#define tWgdcInitial (0x00083C4C)
#define tWgdcMax (0x00083C30)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF745C)
#define tPolf (0x00085FE8)
#define pPolfEnrich (0xFFFF745C)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7980)
#define tBaseTimingPCruise (0x00086C74)
#define tBaseTimingPNonCruise (0x00086C90)
#define tBaseTimingRCruiseAvcs (0x00086CAC)
#define tBaseTimingRNonCruiseAvcs (0x00086CC8)
#define pKcaIam (0xFFFF7C7C)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF61DB)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF61DA)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF61DC)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF67C3)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6A51)
#define pFbkc4 ((float*)0xFFFF7C18)
#define pIam1 ((unsigned char*)0xFFFF6A53)
#define pIam4 ((float*)0xFFFF2D10)
#define pEngineSpeed ((float*)0xFFFF6814)
#define pVehicleSpeed ((float*)0xFFFF67F0)
#define pCoolantTemp ((float*)0xFFFF413C)
#define pAtmoPress ((float*)0xFFFF6A70)
#define pManifoldAbsolutePressure ((float*)0xFFFF6420)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF79E0)
#define pReqTorque ((float*)0xFFFF7F58)
#define pThrottlePlate ((float*)0xFFFF64E8)
#define pCurrentGear ((unsigned char*)0xFFFF6A01)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2834)
#define dLoadSmoothingB (0x000C2830)
#define dLoadSmoothingAlt (0x000C282C)
#define dLoadSmoothingFinal (0x000C2840)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000102A4)
#define hMemoryReset (0x0000FC04)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C58)

