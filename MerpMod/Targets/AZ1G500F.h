#define MOD_DATE 13.7.16.1227

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G500F
#define ECU_IDENTIFIER 6904784007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D56A0)
#define dRomHoleStart (0x000E2000)
#define pRamHoleStart (0xFFFFA590)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000BE714)
#define sPull3DFloat (0x000BE7C8)

/////////////////////
// Switch Hacks
/////////////////////

#define pSiDrive (0xFFFF6136)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0003CDE4)
#define sRevLimStart (0x0002F340)
#define sRevLimEnd (0x0002F380)
#define pFlagsRevLim ((char*)0xFFFF74C4)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004800)
#define sMafCalc (0x000047A4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C7B98)

/////////////////////
// Cel Hacks
/////////////////////


/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00080FC8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x0003C900)
#define sWgdc (0x00013AA4)
#define tWgdcInitial (0x00080FAC)
#define tWgdcMax (0x00080F90)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF71B4)
#define tPolf (0x0008336C)
#define pPolfEnrich (0xFFFF71B4)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF76E4)
#define tBaseTimingPCruise (0x00083FF0)
#define tBaseTimingPNonCruise (0x0008400C)
#define tBaseTimingRCruiseAvcs (0x00084028)
#define tBaseTimingRNonCruiseAvcs (0x00084044)
#define pKcaIam (0xFFFF7A18)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pClutchFlags ((char*)0xFFFF65B7)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6845)
#define pFbkc4 ((float*)0xFFFF79A8)
#define pIam1 ((char*)0xFFFF6847)
#define pIam4 ((float*)0xFFFF2D10)
#define pEngineSpeed ((float*)0xFFFF6608)
#define pVehicleSpeed ((float*)0xFFFF65E4)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6868)
#define pManifoldAbsolutePressure ((float*)0xFFFF61F4)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF63CC)
#define pReqTorque ((float*)0xFFFF7D18)
#define pThrottlePlate ((float*)0xFFFF62BC)
#define pCurrentGear ((char*)0xFFFF67F5)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2E54)
#define dLoadSmoothingB (0x000C2E50)
#define dLoadSmoothingAlt (0x000C2E4C)
#define dLoadSmoothingFinal (0x000C2E60)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FED8)
#define hMemoryReset (0x0000F930)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x0001187C)

