#define MOD_DATE 13.5.7.1922

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G401V
#define ECU_IDENTIFIER 6612784007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D5B78)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFAE28)
#define sPull2DFloat (0x000BE844)
#define sPull3DFloat (0x000BE8F8)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00044544)
#define sRevLimStart (0x000366A4)
#define sRevLimEnd (0x000366E4)
#define pFlagsRevLim ((char*)0xFFFF7A54)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004B10)
#define sMafCalc (0x00004AB4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C893C)

/////////////////////
// Cel Hacks
/////////////////////


/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00043F4C)
#define sWgdc (0x000135D0)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7744)
#define pPolfEnrich (0xFFFF7744)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7C74)
#define pKcaIam (0xFFFF7F9C)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF618B)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF618A)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF618C)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF677F)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6A10)
#define pFbkc4 ((float*)0xFFFF7F2C)
#define pIam1 ((char*)0xFFFF6A12)
#define pIam4 ((float*)0xFFFF3008)
#define pEngineSpeed ((float*)0xFFFF67D0)
#define pVehicleSpeed ((float*)0xFFFF67AC)
#define pCoolantTemp ((float*)0xFFFF413C)
#define pAtmoPress ((float*)0xFFFF6A30)
#define pManifoldAbsolutePressure ((float*)0xFFFF63D0)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF65B4)
#define pReqTorque ((float*)0xFFFF8290)
#define pThrottlePlate ((float*)0xFFFF64A0)
#define pCurrentGear ((char*)0xFFFF69BD)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2BBC)
#define dLoadSmoothingB (0x000C2BB8)
#define dLoadSmoothingAlt (0x000C2BB4)
#define dLoadSmoothingFinal (0x000C2BC8)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000102A4)
#define hMemoryReset (0x0000FC04)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C58)

