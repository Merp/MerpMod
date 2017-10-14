#define MOD_ECUID CBC321227F
#define MOD_DATE 14.10.17.19.07
#include "Flash.h"
#define MOD_CONFIG Flash
#define MOD_BUILD Debug
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AZ1G202G
#define ECU_IDENTIFIER 5A42784207
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D4C4C)
#define dRomHoleStart (0x000E1400)
#define pRamHoleStart (0xFFFFA840)
#define sPull2DFloat (0x000BE804)
#define sPull3DFloat (0x000BE8B8)

/////////////////////
// Switch Hacks
/////////////////////


/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00042684)
#define sRevLimStart (0x00034B28)
#define sRevLimEnd (0x00034B68)
#define pFlagsRevLim ((unsigned char*)0xFFFF7768)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00004B10)
#define sMafCalc (0x00004AB4)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C78A8)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007CA94)
#define hCelSignal (0x0007CB6C)
#define pCelSignalOem ((unsigned char*)0xFFFF9B3A)

/////////////////////
// Boost Hacks
/////////////////////

#define tTargetBoost (0x00086C50)

/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000421A4)
#define sWgdc (0x00013E80)
#define tWgdcInitial (0x00086C34)
#define tWgdcMax (0x00086C18)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7458)
#define pPolfEnrich (0xFFFF7458)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7988)
#define pKcaIam (0xFFFF7CB0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF61B7)
#define ResumeBitMask ((unsigned char)0x01)
#define pCoastFlags ((unsigned char*)0xFFFF61B6)
#define CoastBitMask ((unsigned char)0x01)
#define pBrakeFlags ((unsigned char*)0xFFFF61B8)
#define BrakeBitMask ((unsigned char)0x01)
#define pClutchFlags ((unsigned char*)0xFFFF67BF)
#define ClutchBitMask ((unsigned char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6A4D)
#define pFbkc4 ((float*)0xFFFF7C40)
#define pIam1 ((unsigned char*)0xFFFF6A4F)
#define pIam4 ((float*)0xFFFF2D34)
#define pEngineSpeed ((float*)0xFFFF6810)
#define pVehicleSpeed ((float*)0xFFFF67EC)
#define pCoolantTemp ((float*)0xFFFF413C)
#define pAtmoPress ((float*)0xFFFF6A70)
#define pManifoldAbsolutePressure ((float*)0xFFFF63FC)
#define pIntakeAirTemp ((float*)0xFFFF4124)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4046)
#define pEngineLoad ((float*)0xFFFF65D4)
#define pReqTorque ((float*)0xFFFF7FA4)
#define pThrottlePlate ((float*)0xFFFF64C4)
#define pCurrentGear ((unsigned char*)0xFFFF69FD)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C29C0)
#define dLoadSmoothingB (0x000C29BC)
#define dLoadSmoothingAlt (0x000C29B8)
#define dLoadSmoothingFinal (0x000C29CC)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x000102A4)
#define hMemoryReset (0x0000FC04)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011C58)

