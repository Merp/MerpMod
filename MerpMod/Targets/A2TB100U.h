#define MOD_DATE 14.7.6.160

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2TB100U
#define ECU_IDENTIFIER 5104584007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CE9D0)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA200)
#define pRamHoleEnd (0xFFFFB3D0)
#define sPull2DFloat (0x000020AC)
#define sPull3DFloat (0x00002160)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00015E20)
#define sRevLimStart (0x00039DF4)
#define sRevLimEnd (0x00039E24)
#define pFlagsRevLim ((unsigned char*)0xFFFF7998)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008384)
#define sMafCalc (0x00008328)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C5A48)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007C3CC)
#define hCelSignal (0x0007C4E4)
#define pCelSignalOem ((unsigned char*)0xFFFF94A2)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00088700)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00015A30)
#define sWgdc (0x000180CC)
#define tWgdcInitial (0x000886C8)
#define tWgdcMax (0x00088690)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7778)
#define tPolf (0x0008A144)
#define pPolfEnrich (0xFFFF7778)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7B98)
#define tBaseTimingPCruise (0x0008A98C)
#define tBaseTimingPNonCruise (0x0008A9A8)
#define tBaseTimingRCruiseAvcs (0x0008A9C4)
#define tBaseTimingRNonCruiseAvcs (0x0008A9E0)
#define pKcaIam (0xFFFF7DB0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////


/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF70C6)
#define pFbkc4 ((float*)0xFFFF7D4C)
#define pIam1 ((unsigned char*)0xFFFF70CB)
#define pIam4 ((float*)0xFFFF2538)
#define pEngineSpeed ((float*)0xFFFF6EA4)
#define pVehicleSpeed ((float*)0xFFFF6E78)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF70E0)
#define pManifoldAbsolutePressure ((float*)0xFFFF6ADC)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF6C9C)
#define pReqTorque ((float*)0xFFFF8058)
#define pThrottlePlate ((float*)0xFFFF6B7C)
#define pCurrentGear ((unsigned char*)0xFFFF7079)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C3B68)
#define dLoadSmoothingB (0x000C3B64)
#define dLoadSmoothingAlt (0x000C3B60)
#define dLoadSmoothingFinal (0x000C3B74)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F988)
#define hMemoryReset (0x0000DC44)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012CAC)

