#define MOD_DATE 13.6.20.25

#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2UJ000J
#define ECU_IDENTIFIER 4D12784206
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000D2480)
#define dRomHoleStart (0x000E2000)
#define pRamHoleStart (0xFFFFA0E0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00014FA8)
#define sRevLimStart (0x000321F4)
#define sRevLimEnd (0x00032224)
#define pFlagsRevLim ((char*)0xFFFF7804)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000081E4)
#define sMafCalc (0x00008188)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C87FC)
#define hInjectorScaling (0x0002949C)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x000883B0)
#define hCelSignal (0x000884C8)
#define pCelSignalOem ((char*)0xFFFF9BB2)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x00016BB0)
#define tTargetBoostKcaAlt (0x00092C9C)
#define hTableTargetBoostKcaAlt (0x00016BC4)
#define tTargetBoostKcaBLo (0x00092CD4)
#define hTableTargetBoostKcaBLo (0x00016BC8)
#define tTargetBoostKcaBHi (0x00092D28)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x00016F14)
#define hWgdc (0x00014A38)
#define sWgdc (0x000166E8)
#define tWgdcMax (0x00092BD8)
#define tWgdcInitialKcaAlt (0x00092C10)
#define tWgdcInitialKcaBLo (0x00092C48)
#define tWgdcInitialKcaBHi (0x00092C80)
#define hTableWgdcInitialKcaBHi (0x00016F20)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF75CC)
#define hPull3DPolf (0x0002E314)
#define hPolf (0x00014FC4)
#define sPolf (0x0002E0C4)
#define pPolfEnrich (0xFFFF75CC)
#define tPolfKcaAlt (0x00094AA8)
#define hTablePolfKcaAlt (0x0002E320)
#define tPolfKcaBLo (0x00094A38)
#define hTablePolfKcaBLo (0x0002E328)
#define tPolfKcaBHi (0x00094A54)
#define hTablePolfKcaBHi (0x0002E32C)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF79CC)
#define sBaseTiming (0x00035BE6)
#define hPull3DTiming (0x00035DD8)
#define tBaseTimingPCruise (0x000952AC)
#define tBaseTimingPNonCruise (0x000952C8)
#define tBaseTimingRCruiseAvcs (0x000952E4)
#define tBaseTimingRNonCruiseAvcs (0x00095300)
#define pKcaIam (0xFFFF7BDC)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF645B)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF645A)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF645C)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF6A31)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6C9A)
#define pFbkc4 ((float*)0xFFFF7B78)
#define pIam1 ((char*)0xFFFF6C9F)
#define pIam4 ((float*)0xFFFF2E30)
#define pEngineSpeed ((float*)0xFFFF6A78)
#define pVehicleSpeed ((float*)0xFFFF6A54)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF6CB4)
#define pManifoldAbsolutePressure ((float*)0xFFFF66B0)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF687C)
#define pReqTorque ((float*)0xFFFF7E94)
#define pThrottlePlate ((float*)0xFFFF6758)
#define pWgdc4 ((float*)0xFFFF63B8)
#define pCurrentGear ((char*)0xFFFF6C4D)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C29B8)
#define dLoadSmoothingB (0x000C29B4)
#define dLoadSmoothingAlt (0x000C29B0)
#define dLoadSmoothingFinal (0x000C29C4)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F7E8)
#define hMemoryReset (0x0000DAA4)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x0001220C)

