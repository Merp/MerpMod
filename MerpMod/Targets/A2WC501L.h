#define MOD_DATE 13.5.29.1713

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A2WC501L
#define ECU_IDENTIFIER 3F12484206
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CBC50)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF7220)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x000126DC)
#define sRevLimStart (0x0002F91C)
#define sRevLimEnd (0x0002F952)
#define pFlagsRevLim ((char*)0xFFFF5944)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00007A04)
#define sMafCalc (0x000079A8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C5AF4)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x00075564)
#define hCelSignal (0x0007567C)
#define pCelSignalOem ((char*)0xFFFF6E76)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000121AC)
#define sWgdc (0x00014794)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF5788)
#define pPolfEnrich (0xFFFF5788)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF5AF4)
#define pKcaIam (0xFFFF5C74)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF4CDC)
#define ResumeBitMask ((char)0x04)
#define pCoastFlags ((char*)0xFFFF4CDC)
#define CoastBitMask ((char)0x02)
#define pBrakeFlags ((char*)0xFFFF4CDC)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFF513D)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF52B8)
#define pFbkc4 ((float*)0xFFFF5C30)
#define pIam1 ((char*)0xFFFF52BD)
#define pIam4 ((float*)0xFFFF2664)
#define pEngineSpeed ((float*)0xFFFF516C)
#define pVehicleSpeed ((float*)0xFFFF515C)
#define pAtmoPress ((float*)0xFFFF2E34)
#define pManifoldAbsolutePressure ((float*)0xFFFF4EB4)
#define pIntakeAirTemp ((float*)0xFFFF2DB8)
#define pMassAirFlow ((float*)0xFFFF2DF4)
#define pMafSensorVoltage ((short*)0xFFFF2D22)
#define pEngineLoad ((float*)0xFFFF5034)
#define pReqTorque ((float*)0xFFFF5D80)
#define pThrottlePlate ((float*)0xFFFF4F44)
#define pCurrentGear ((char*)0xFFFF526D)
#define pAf1Res ((float*)0xFFFF4A54)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1A90)
#define dLoadSmoothingB (0x000C1A94)
#define dLoadSmoothingFinal (0x000C1A98)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000F928)
#define hMemoryReset (0x0000D324)
#define pMemoryResetLimit (0xFFFFBFFB)
#define hMemoryResetLimit (0x0000FFF8)

