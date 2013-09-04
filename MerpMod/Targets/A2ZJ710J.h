#define MOD_DATE 13.4.29.1244

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2ZJ710J
#define ECU_IDENTIFIER 2E12495306
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x0006229C)
#define dRomHoleStart (0x0007E67C)
#define pRamHoleStart (0xFFFFC430)
#define sPull2DFloat (0x0000208C)
#define sPull3DFloat (0x00002100)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0001122C)
#define sRevLimStart (0x00029B54)
#define sRevLimEnd (0x00029B8A)
#define pFlagsRevLim ((char*)0xFFFFAD58)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000076EC)
#define sMafCalc (0x0000768C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x0005B8E0)
#define hInjectorScaling (0x00023BCC)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0004BC7C)
#define hCelSignal (0x0004BD94)
#define pCelSignalOem ((char*)0xFFFFC08A)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00010DA4)
#define sWgdc (0x0001322C)
#define tWgdcMax (0x000538DC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFFABEC)
#define pPolfEnrich (0xFFFFABEC)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFFAEE4)
#define pKcaIam (0xFFFFB014)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFFA32C)
#define ResumeBitMask ((char)0x04)
#define pCoastFlags ((char*)0xFFFFA32C)
#define CoastBitMask ((char)0x02)
#define pBrakeFlags ((char*)0xFFFFA32C)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFFA75D)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFFAFC0)
#define pIam4 ((float*)0xFFFF854C)
#define pEngineSpeed ((float*)0xFFFFA78C)
#define pVehicleSpeed ((float*)0xFFFFA77C)
#define pCoolantTemp ((float*)0xFFFF90C8)
#define pAtmoPress ((float*)0xFFFF913C)
#define pManifoldAbsolutePressure ((float*)0xFFFFA4E0)
#define pIntakeAirTemp ((float*)0xFFFF90B8)
#define pMassAirFlow ((float*)0xFFFF90F4)
#define pMafSensorVoltage ((short*)0xFFFF9022)
#define pEngineLoad ((float*)0xFFFFA664)
#define pReqTorque ((float*)0xFFFFB114)
#define pThrottlePlate ((float*)0xFFFFA570)
#define pCurrentGear ((char*)0xFFFFA881)
#define pAf1Res ((float*)0xFFFFA120)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x00057C7C)
#define dLoadSmoothingB (0x00057C80)
#define dLoadSmoothingFinal (0x00057C84)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000EDE4)
#define hMemoryReset (0x0000C968)
#define pMemoryResetLimit (0xFFFFDFFB)
#define hMemoryResetLimit (0x0000EFCC)

