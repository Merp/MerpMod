#define MOD_DATE 13.4.29.1327

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2ZJE11J
#define ECU_IDENTIFIER 4312594006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CC7E8)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF6F90)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00013470)
#define sRevLimStart (0x0002C7AC)
#define sRevLimEnd (0x0002C7E2)
#define pFlagsRevLim ((char*)0xFFFF5660)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00007F98)
#define sMafCalc (0x00007F3C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C5BBC)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00071F34)
#define hCelSignal (0x0007204C)
#define pCelSignalOem ((char*)0xFFFF6BEE)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00079D84)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00012FD8)
#define sWgdc (0x00014D38)
#define tWgdcMax (0x00079DA0)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF54F4)
#define pPolfEnrich (0xFFFF54F4)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF57F0)
#define pKcaIam (0xFFFF5920)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF4C18)
#define ResumeBitMask ((char)0x04)
#define pCoastFlags ((char*)0xFFFF4C18)
#define CoastBitMask ((char)0x02)
#define pBrakeFlags ((char*)0xFFFF4C18)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFF5049)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc4 ((float*)0xFFFF58CC)
#define pIam4 ((float*)0xFFFF2570)
#define pEngineSpeed ((float*)0xFFFF5078)
#define pVehicleSpeed ((float*)0xFFFF5068)
#define pAtmoPress ((float*)0xFFFF2E34)
#define pManifoldAbsolutePressure ((float*)0xFFFF4DCC)
#define pIntakeAirTemp ((float*)0xFFFF2DB8)
#define pMassAirFlow ((float*)0xFFFF2DF4)
#define pMafSensorVoltage ((short*)0xFFFF2D22)
#define pEngineLoad ((float*)0xFFFF4F58)
#define pReqTorque ((float*)0xFFFF5AC4)
#define pThrottlePlate ((float*)0xFFFF4E5C)
#define pCurrentGear ((char*)0xFFFF516D)
#define pAf1Res ((float*)0xFFFF4A50)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1BF4)
#define dLoadSmoothingB (0x000C1BF8)
#define dLoadSmoothingFinal (0x000C1BFC)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x00010950)
#define hMemoryReset (0x0000DFE0)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x000110D8)

