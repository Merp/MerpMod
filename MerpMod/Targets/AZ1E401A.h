#define MOD_DATE 13.5.7.1038

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1E401A
#define ECU_IDENTIFIER 5112584107
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D4BD0)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFAD50)
#define sPull2DFloat (0x000BE764)
#define sPull3DFloat (0x000BE818)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000438A8)
#define sRevLimStart (0x0003633C)
#define sRevLimEnd (0x0003637C)
#define pFlagsRevLim ((char*)0xFFFF7A2C)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004B10)
#define sMafCalc (0x00004AB4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C837C)

/////////////////////
// Cel Hacks
/////////////////////


/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000432DC)
#define sWgdc (0x000135C4)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7728)
#define tPolf (0x000960DC)
#define pPolfEnrich (0xFFFF7728)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7C4C)
#define dBaseTimingPCruise (0x00096D68)
#define tBaseTimingPNonCruise (0x00096D84)
#define tBaseTimingRCruiseAvcs (0x00096DA0)
#define tBaseTimingRNonCruiseAvcs (0x00096DBC)
#define pKcaIam (0xFFFF7F48)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF6173)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF6172)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF6174)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF6767)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF69F8)
#define pFbkc4 ((float*)0xFFFF7EE4)
#define pIam1 ((char*)0xFFFF69FA)
#define pIam4 ((float*)0xFFFF2FDC)
#define pEngineSpeed ((float*)0xFFFF67B8)
#define pVehicleSpeed ((float*)0xFFFF6794)
#define pCoolantTemp ((float*)0xFFFF413C)
#define pAtmoPress ((float*)0xFFFF6A18)
#define pManifoldAbsolutePressure ((float*)0xFFFF63B8)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF659C)
#define pReqTorque ((float*)0xFFFF8224)
#define pThrottlePlate ((float*)0xFFFF6488)
#define pCurrentGear ((char*)0xFFFF69A5)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2674)
#define dLoadSmoothingB (0x000C2670)
#define dLoadSmoothingAlt (0x000C266C)
#define dLoadSmoothingFinal (0x000C2680)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000102A4)
#define hMemoryReset (0x0000FC04)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C58)

