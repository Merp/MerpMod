#define MOD_DATE 13.6.28.026

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G301F
#define ECU_IDENTIFIER 5A04784207
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D569C)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA570)
#define sPull2DFloat (0x000BE714)
#define sPull3DFloat (0x000BE7C8)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0003CFEC)
#define sRevLimStart (0x0002F554)
#define sRevLimEnd (0x0002F594)
#define pFlagsRevLim ((char*)0xFFFF74AC)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004928)
#define sMafCalc (0x000048CC)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C7B94)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00076EE0)
#define hCelSignal (0x00076FB8)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0008105C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x0003CB08)
#define sWgdc (0x00013C98)
#define tWgdcInitial (0x00081040)
#define tWgdcMax (0x00081024)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF719C)
#define tPolf (0x00083400)
#define pPolfEnrich (0xFFFF719C)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF76CC)
#define tBaseTimingPCruise (0x00083F88)
#define tBaseTimingPNonCruise (0x00083FA4)
#define tBaseTimingRCruiseAvcs (0x00083FC0)
#define tBaseTimingRNonCruiseAvcs (0x00083FDC)
#define pKcaIam (0xFFFF7A00)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pClutchFlags ((char*)0xFFFF659F)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF682D)
#define pFbkc4 ((float*)0xFFFF7990)
#define pIam1 ((char*)0xFFFF682F)
#define pIam4 ((float*)0xFFFF2D10)
#define pEngineSpeed ((float*)0xFFFF65F0)
#define pVehicleSpeed ((float*)0xFFFF65CC)
#define pAtmoPress ((float*)0xFFFF6850)
#define pManifoldAbsolutePressure ((float*)0xFFFF61DC)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF63B4)
#define pReqTorque ((float*)0xFFFF7D00)
#define pThrottlePlate ((float*)0xFFFF62A4)
#define pCurrentGear ((char*)0xFFFF67DD)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2E50)
#define dLoadSmoothingB (0x000C2E4C)
#define dLoadSmoothingAlt (0x000C2E48)
#define dLoadSmoothingFinal (0x000C2E5C)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000100BC)
#define hMemoryReset (0x0000FA1C)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011A70)

