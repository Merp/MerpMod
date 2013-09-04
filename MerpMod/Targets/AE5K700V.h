#define MOD_DATE 13.5.30.2223

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AE5K700V
#define ECU_IDENTIFIER 8112597107
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000DA924)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFB984)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000BE7F4)
#define sPull3DFloat (0x000BE8A8)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0004AE24)
#define sRevLimStart (0x0003BCC4)
#define sRevLimEnd (0x0003BD04)
#define pFlagsRevLim ((char*)0xFFFF7CD0)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000CCA68)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x000A0418)
#define hCelSignal (0x000A049C)
#define pCelSignalOem ((char*)0xFFFFAEEE)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00013A28)
#define hTableTargetBoost (0x00013A24)
#define tTargetBoost (0x000ACAF4)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00013F0C)
#define hWgdc (0x0004A6E4)
#define sWgdc (0x00013774)
#define hTableWgdcInitial (0x00013F08)
#define tWgdcInitial (0x000ACAD8)
#define hTableWgdcMax (0x00013F28)
#define tWgdcMax (0x000ACABC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF79A0)
#define hPull3DPolf (0x00036738)
#define hPolf (0x0004AE48)
#define sPolf (0x000364E4)
#define pPolfEnrich (0xFFFF79A0)
#define tPolfKcaAlt (0x000AF7A4)
#define hTablePolfKcaAlt (0x00036750)
#define tPolfKcaBLo (0x000AF788)
#define hTablePolfKcaBLo (0x0003674C)
#define tPolfKcaBHi (0x000AF734)
#define hTablePolfKcaBHi (0x00036734)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x0004AF08)
#define pBaseTiming (0xFFFF7F20)
#define sBaseTiming (0x0004069C)
#define hPull3DTiming (0x0004093C)
#define tBaseTimingPCruise (0x000B0344)
#define hTableBaseTimingPCruise (0x00040938)
#define tBaseTimingPNonCruise (0x000B0360)
#define hTableBaseTimingPNonCruise (0x00040944)
#define tBaseTimingRCruiseAvcs (0x000B037C)
#define hTableBaseTimingRCruiseAvcs (0x00040940)
#define tBaseTimingRNonCruiseAvcs (0x000B0398)
#define hTableBaseTimingRNonCruiseAvcs (0x00040948)
#define pKcaIam (0xFFFF8250)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF5FCB)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF5FCA)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF5FCC)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF65F4)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF689F)
#define pFbkc4 ((float*)0xFFFF81E0)
#define pIam1 ((char*)0xFFFF68A1)
#define pIam4 ((float*)0xFFFF32D8)
#define pEngineSpeed ((float*)0xFFFF6648)
#define pVehicleSpeed ((float*)0xFFFF6624)
#define pCoolantTemp ((float*)0xFFFF4144)
#define pAtmoPress ((float*)0xFFFF68C4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6214)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF63FC)
#define pReqTorque ((float*)0xFFFF854C)
#define pThrottlePlate ((float*)0xFFFF62E4)
#define pCurrentGear ((char*)0xFFFF6835)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2D40)
#define dLoadSmoothingB (0x000C2D3C)
#define dLoadSmoothingAlt (0x000C2D38)
#define dLoadSmoothingFinal (0x000C2D4C)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000101C8)
#define hMemoryReset (0x0000FC20)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C20)

