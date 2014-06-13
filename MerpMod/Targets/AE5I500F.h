#define MOD_DATE 14.6.12.1252

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AE5I500F
#define ECU_IDENTIFIER 75525A4007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D6850)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA660)
#define pRamHoleEnd (0xFFFFB4C0)
#define sPull2DFloat (0x000BE990)
#define sPull3DFloat (0x000BEA44)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000464E4)
#define sRevLimStart (0x00038414)
#define sRevLimEnd (0x00039E8C)
#define pFlagsRevLim ((unsigned char*)0xFFFF7938)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004800)
#define sMafCalc (0x000047A4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8760)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007EFC4)
#define hCelSignal (0x0007F048)
#define pCelSignalOem ((unsigned char*)0xFFFF9C5A)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0008924C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00045FE0)
#define sWgdc (0x000130FC)
#define tWgdcInitial (0x00089230)
#define tWgdcMax (0x00089214)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define tPolf (0x0008B884)

/////////////////////
// Timing Hacks
/////////////////////

#define tBaseTimingPCruise (0x0008C5A4)
#define tBaseTimingPNonCruise (0x0008C5C0)
#define tBaseTimingRCruiseAvcs (0x0008C5DC)
#define tBaseTimingRNonCruiseAvcs (0x0008C5F8)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define ResumeBitMask ((unsigned char)0x01)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF6318)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF6974)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6C23)
#define pFbkc4 ((float*)0xFFFF7E04)
#define pIam1 ((unsigned char*)0xFFFF6C25)
#define pIam4 ((float*)0xFFFF2CC8)
#define pEngineSpeed ((float*)0xFFFF69C8)
#define pVehicleSpeed ((float*)0xFFFF69A4)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6C48)
#define pManifoldAbsolutePressure ((float*)0xFFFF65CC)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF67AC)
#define pReqTorque ((float*)0xFFFF8228)
#define pThrottlePlate ((float*)0xFFFF6694)
#define pCurrentGear ((unsigned char*)0xFFFF6BB6)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C43D4)
#define dLoadSmoothingB (0x000C43D0)
#define dLoadSmoothingAlt (0x000C43CC)
#define dLoadSmoothingFinal (0x000C43E4)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FDFC)
#define hMemoryReset (0x0000F854)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x000117A0)

