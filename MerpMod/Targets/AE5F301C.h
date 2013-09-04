#define MOD_DATE 13.6.27.2237

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AE5F301C
#define ECU_IDENTIFIER 5B42564107
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D6688)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFA620)
#define sPull2DFloat (0x000BE990)
#define sPull3DFloat (0x000BEA44)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////


/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004800)
#define sMafCalc (0x000047A4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8A70)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007EDD0)
#define hCelSignal (0x0007EE54)
#define pCelSignalOem ((char*)0xFFFF9C5A)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00089050)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00045FE0)
#define sWgdc (0x000130FC)
#define tWgdcInitial (0x00089034)
#define tWgdcMax (0x00089018)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7568)
#define pPolfEnrich (0xFFFF7568)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7B58)
#define tBaseTimingPCruise (0x0008C408)
#define tBaseTimingRCruiseAvcs (0x0008C440)
#define pKcaIam (0xFFFF7E74)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF6317)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF6316)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF6318)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF6974)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6C23)
#define pFbkc4 ((float*)0xFFFF7E04)
#define pIam1 ((char*)0xFFFF6C25)
#define pIam4 ((float*)0xFFFF2CBC)
#define pEngineSpeed ((float*)0xFFFF69C8)
#define pVehicleSpeed ((float*)0xFFFF69A4)
#define pAtmoPress ((float*)0xFFFF6C48)
#define pManifoldAbsolutePressure ((float*)0xFFFF65CC)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF67AC)
#define pReqTorque ((float*)0xFFFF8228)
#define pThrottlePlate ((float*)0xFFFF6694)
#define pCurrentGear ((char*)0xFFFF6BB6)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C47F0)
#define dLoadSmoothingB (0x000C47EC)
#define dLoadSmoothingFinal (0x000C4800)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FDFC)
#define hMemoryReset (0x0000F854)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x000117A0)

