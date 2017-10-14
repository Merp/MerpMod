#define MOD_ECUID 2A089E40F6
#define MOD_DATE 14.10.17.17.45
#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH200V
#define ECU_IDENTIFIER 4352594006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CDD54)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF8FE0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0001483C)
#define sRevLimStart (0x00030D10)
#define sRevLimEnd (0x00030D46)
#define pFlagsRevLim ((unsigned char*)0xFFFF71BC)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000081BC)
#define sMafCalc (0x00008160)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C6A0C)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007806C)
#define hCelSignal (0x00078184)
#define pCelSignalOem ((unsigned char*)0xFFFF8BA2)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x0007F78C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000143F4)
#define sWgdc (0x00016BD8)
#define tWgdcInitial (0x0007F6E4)
#define tWgdcMax (0x0007F71C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7028)
#define pPolfEnrich (0xFFFF7028)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7354)
#define pKcaIam (0xFFFF74D4)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF643C)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF643C)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF643C)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF6975)
#define ClutchBitMask ((unsigned char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6AF0)
#define pFbkc4 ((float*)0xFFFF7490)
#define pIam1 ((unsigned char*)0xFFFF6AF5)
#define pIam4 ((float*)0xFFFF2910)
#define pEngineSpeed ((float*)0xFFFF699C)
#define pVehicleSpeed ((float*)0xFFFF6994)
#define pCoolantTemp ((float*)0xFFFF5CAC)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6624)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF67CC)
#define pReqTorque ((float*)0xFFFF7784)
#define pThrottlePlate ((float*)0xFFFF66C8)
#define pCurrentGear ((unsigned char*)0xFFFF6AA5)
#define pAf1Res ((float*)0xFFFF5F08)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1AF4)
#define dLoadSmoothingB (0x000C1AF8)
#define dLoadSmoothingFinal (0x000C1B04)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FB54)
#define hMemoryReset (0x0000DA70)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00011EE0)

