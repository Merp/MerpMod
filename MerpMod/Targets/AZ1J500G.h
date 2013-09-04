#define MOD_DATE 13.5.6.224

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1J500G
#define ECU_IDENTIFIER 7442594007
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D5310)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA7E0)
#define sPull2DFloat (0x000BE774)
#define sPull3DFloat (0x000BE828)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000440F8)
#define sRevLimStart (0x000363E0)
#define sRevLimEnd (0x00036420)
#define pFlagsRevLim ((char*)0xFFFF76FC)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C7DDC)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007FA40)
#define hCelSignal (0x0007FAC4)
#define pCelSignalOem ((char*)0xFFFF9C12)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00043BF8)
#define sWgdc (0x00013C94)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF73EC)
#define pPolfEnrich (0xFFFF73EC)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF791C)
#define pKcaIam (0xFFFF7C44)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF622B)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF622A)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF622C)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF683B)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6ADD)
#define pFbkc4 ((float*)0xFFFF7BD4)
#define pIam1 ((char*)0xFFFF6ADF)
#define pIam4 ((float*)0xFFFF2DE4)
#define pEngineSpeed ((float*)0xFFFF688C)
#define pVehicleSpeed ((float*)0xFFFF6868)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF6B00)
#define pManifoldAbsolutePressure ((float*)0xFFFF6470)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF664C)
#define pReqTorque ((float*)0xFFFF7F38)
#define pThrottlePlate ((float*)0xFFFF6540)
#define pCurrentGear ((char*)0xFFFF6A79)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2A1C)
#define dLoadSmoothingB (0x000C2A18)
#define dLoadSmoothingAlt (0x000C2A14)
#define dLoadSmoothingFinal (0x000C2A28)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000100C0)
#define hMemoryReset (0x0000FB18)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011A64)

