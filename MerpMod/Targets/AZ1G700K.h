#define MOD_DATE 14.7.6.167

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G700K
#define ECU_IDENTIFIER 7472594007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D4CE4)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA600)
#define pRamHoleEnd (0xFFFFB3D0)
#define sPull2DFloat (0x000BE864)
#define sPull3DFloat (0x000BE918)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00041E2C)
#define sRevLimStart (0x00034390)
#define sRevLimEnd (0x000343D0)
#define pFlagsRevLim ((unsigned char*)0xFFFF7600)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C787C)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00079D88)
#define hCelSignal (0x00079E0C)
#define pCelSignalOem ((unsigned char*)0xFFFF99A6)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00084184)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00041958)
#define sWgdc (0x000132EC)
#define tWgdcInitial (0x00084168)
#define tWgdcMax (0x0008414C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF72F0)
#define pPolfEnrich (0xFFFF72F0)
#define tPolfKcaAlt (0x00086588)
#define tPolfKcaBLo (0x000865DC)
#define tPolfKcaBHi (0x000865F8)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7820)
#define tBaseTimingPCruise (0x00087104)
#define tBaseTimingPNonCruise (0x00087120)
#define tBaseTimingRCruiseAvcs (0x0008713C)
#define tBaseTimingRNonCruiseAvcs (0x00087158)
#define pKcaIam (0xFFFF7B48)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF6167)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF6166)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF6168)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF6773)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6A01)
#define pFbkc4 ((float*)0xFFFF7AD8)
#define pIam1 ((unsigned char*)0xFFFF6A03)
#define pIam4 ((float*)0xFFFF2D74)
#define pEngineSpeed ((float*)0xFFFF67C4)
#define pVehicleSpeed ((float*)0xFFFF67A0)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6A24)
#define pManifoldAbsolutePressure ((float*)0xFFFF63AC)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF6588)
#define pReqTorque ((float*)0xFFFF7E3C)
#define pThrottlePlate ((float*)0xFFFF647C)
#define pCurrentGear ((unsigned char*)0xFFFF69B1)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C29C0)
#define dLoadSmoothingB (0x000C29BC)
#define dLoadSmoothingAlt (0x000C29B8)
#define dLoadSmoothingFinal (0x000C29CC)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000100C0)
#define hMemoryReset (0x0000FB18)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011A64)

