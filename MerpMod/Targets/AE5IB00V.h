#define MOD_DATE 13.5.21.037

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID AE5IB00V
#define ECU_IDENTIFIER 7412597207
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002004)
#define dEcuId (0x000D9D2C)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFFB1C0)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x000BE7F4)
#define sPull3DFloat (0x000BE8A8)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00049210)
#define sRevLimStart (0x0003A924)
#define sRevLimEnd (0x0003A964)
#define pFlagsRevLim ((char*)0xFFFF7904)
#define RevLimBitMask (0x01)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000049E8)
#define sMafCalc (0x0000498C)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000CBEF0)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0009B3EC)
#define hCelSignal (0x0009B470)
#define pCelSignalOem ((char*)0xFFFFA7AA)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x00048AB0)
#define sWgdc (0x000134CC)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF75DC)
#define pPolfEnrich (0xFFFF75DC)
#define tPolfKcaAlt (0x000AA000)
#define tPolfKcaBLo (0x000AA054)
#define tPolfKcaBHi (0x000AA070)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7B38)
#define dBaseTimingPCruise (0x000AAC10)
#define tBaseTimingPNonCruise (0x000AAC2C)
#define tBaseTimingRCruiseAvcs (0x000AAC48)
#define tBaseTimingRNonCruiseAvcs (0x000AAC64)
#define pKcaIam (0xFFFF7E68)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF5FBF)
#define ResumeBitMask ((char)0x01)
#define pCoastFlags ((char*)0xFFFF5FBE)
#define CoastBitMask ((char)0x01)
#define pBrakeFlags ((char*)0xFFFF5FC0)
#define BrakeBitMask ((char)0x01)
#define pClutchFlags ((char*)0xFFFF65E8)
#define ClutchBitMask ((char)0x01)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6894)
#define pFbkc4 ((float*)0xFFFF7DF8)
#define pIam1 ((char*)0xFFFF6896)
#define pIam4 ((float*)0xFFFF3200)
#define pEngineSpeed ((float*)0xFFFF663C)
#define pVehicleSpeed ((float*)0xFFFF6618)
#define pCoolantTemp ((float*)0xFFFF4140)
#define pAtmoPress ((float*)0xFFFF68B8)
#define pManifoldAbsolutePressure ((float*)0xFFFF6208)
#define pIntakeAirTemp ((float*)0xFFFF4128)
#define pMassAirFlow ((float*)0xFFFF40B4)
#define pMafSensorVoltage ((short*)0xFFFF4042)
#define pEngineLoad ((float*)0xFFFF63F4)
#define pReqTorque ((float*)0xFFFF8160)
#define pThrottlePlate ((float*)0xFFFF62D8)
#define pCurrentGear ((char*)0xFFFF6829)
#define pAf1Res ((float*)0xFFFF40C8)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2D1C)
#define dLoadSmoothingB (0x000C2D18)
#define dLoadSmoothingAlt (0x000C2D14)
#define dLoadSmoothingFinal (0x000C2D28)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FFE4)
#define hMemoryReset (0x0000FA3C)
#define pMemoryResetLimit (0xFFFFBF9F)
#define hMemoryResetLimit (0x00011988)

