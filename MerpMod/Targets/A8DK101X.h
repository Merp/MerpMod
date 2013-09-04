#define MOD_DATE 13.5.7.1023

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DK101X
#define ECU_IDENTIFIER 4D12584106
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000D0020)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF9B60)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0001533C)
#define sRevLimStart (0x00034A80)
#define sRevLimEnd (0x00034AB6)
#define pFlagsRevLim ((char*)0xFFFF75A8)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008378)
#define sMafCalc (0x0000831C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C8600)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0008E9CC)
#define hCelSignal (0x0008EAE4)
#define pCelSignalOem ((char*)0xFFFF9712)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0009969C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00014DD0)
#define sWgdc (0x000176EC)
#define tWgdcInitial (0x000995F4)
#define tWgdcMax (0x0009962C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF73E0)
#define tPolf (0x0009B168)
#define pPolfEnrich (0xFFFF73E0)

/////////////////////
// Timing Hacks
/////////////////////

#define tBaseTiming (0x0009B8E0)
#define pBaseTiming (0xFFFF7768)
#define pKcaIam (0xFFFF7904)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF650E)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF650D)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF650F)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF6A89)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6C04)
#define pFbkc4 ((float*)0xFFFF78C0)
#define pIam1 ((char*)0xFFFF6C09)
#define pIam4 ((float*)0xFFFF2E38)
#define pEngineSpeed ((float*)0xFFFF6AB0)
#define pVehicleSpeed ((float*)0xFFFF6AA8)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF8630)
#define pManifoldAbsolutePressure ((float*)0xFFFF6710)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF68CC)
#define pReqTorque ((float*)0xFFFF7BB4)
#define pThrottlePlate ((float*)0xFFFF67B4)
#define pCurrentGear ((char*)0xFFFF6BB9)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C23C4)
#define dLoadSmoothingB (0x000C23C8)
#define dLoadSmoothingFinal (0x000C23D4)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F97C)
#define hMemoryReset (0x0000DC38)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x000123A0)

