#define MOD_DATE 13.5.29.1431

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DK100Y
#define ECU_IDENTIFIER 4D42584006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CD1EC)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF9000)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00014974)
#define sRevLimStart (0x0002D3C0)
#define sRevLimEnd (0x0002D3F6)
#define pFlagsRevLim ((char*)0xFFFF70C0)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008128)
#define sMafCalc (0x000080CC)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C5F30)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x000728AC)
#define hCelSignal (0x000729C4)
#define pCelSignalOem ((char*)0xFFFF8BAA)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0007D4A8)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000145C0)
#define sWgdc (0x00016D38)
#define tWgdcInitial (0x0007D400)
#define tWgdcMax (0x0007D438)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF6F2C)
#define tPolf (0x0007E94C)
#define pPolfEnrich (0xFFFF6F2C)

/////////////////////
// Timing Hacks
/////////////////////

#define tBaseTiming (0x0007F134)
#define pBaseTiming (0xFFFF7260)
#define pKcaIam (0xFFFF73E0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pClutchFlags ((char*)0xFFFF6835)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF69B0)
#define pFbkc4 ((float*)0xFFFF739C)
#define pIam1 ((char*)0xFFFF69B5)
#define pIam4 ((float*)0xFFFF2AD4)
#define pEngineSpeed ((float*)0xFFFF685C)
#define pVehicleSpeed ((float*)0xFFFF6854)
#define pCoolantTemp ((float*)0xFFFF5CB4)
#define pAtmoPress ((float*)0xFFFF8004)
#define pManifoldAbsolutePressure ((float*)0xFFFF64C8)
#define pIntakeAirTemp ((float*)0xFFFF5CA4)
#define pMassAirFlow ((float*)0xFFFF5CD8)
#define pMafSensorVoltage ((short*)0xFFFF5C02)
#define pEngineLoad ((float*)0xFFFF6678)
#define pReqTorque ((float*)0xFFFF7690)
#define pThrottlePlate ((float*)0xFFFF656C)
#define pCurrentGear ((char*)0xFFFF6965)
#define pAf1Res ((float*)0xFFFF5F10)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C0F6C)
#define dLoadSmoothingB (0x000C0F70)
#define dLoadSmoothingFinal (0x000C0F7C)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F72C)
#define hMemoryReset (0x0000D9E8)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012150)

