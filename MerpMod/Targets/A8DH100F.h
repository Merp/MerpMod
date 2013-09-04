#define MOD_DATE 13.5.21.031

#include "Gratis.h"
#define MOD_CONFIG Gratis
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH100F
#define ECU_IDENTIFIER 4242584106
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CEBB4)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF9100)
#define pRamHoleEnd (0xFFFFBF70)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002150)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x00014C14)
#define sRevLimStart (0x00033898)
#define sRevLimEnd (0x000338CE)
#define pFlagsRevLim ((char*)0xFFFF72A0)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x00008314)
#define sMafCalc (0x000082B8)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C73B0)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007CC4C)
#define hCelSignal (0x0007CD64)
#define pCelSignalOem ((char*)0xFFFF8D3E)

/////////////////////
// Boost Hacks
/////////////////////


/////////////////////
// WGDC Hacks
/////////////////////

#define hWgdc (0x000147E8)
#define sWgdc (0x00017A9C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF710C)
#define pPolfEnrich (0xFFFF710C)

/////////////////////
// Timing Hacks
/////////////////////

#define pBaseTiming (0xFFFF7454)
#define pKcaIam (0xFFFF75E4)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals
/////////////////////

#define pResumeFlags ((char*)0xFFFF6508)
#define ResumeBitMask ((char)0x02)
#define pCoastFlags ((char*)0xFFFF6508)
#define CoastBitMask ((char)0x04)
#define pBrakeFlags ((char*)0xFFFF6508)
#define BrakeBitMask ((char)0x08)
#define pClutchFlags ((char*)0xFFFF6A45)
#define ClutchBitMask ((char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((char*)0xFFFF6BC8)
#define pFbkc4 ((float*)0xFFFF75A0)
#define pIam1 ((char*)0xFFFF6BCD)
#define pIam4 ((float*)0xFFFF2914)
#define pEngineSpeed ((float*)0xFFFF6A74)
#define pVehicleSpeed ((float*)0xFFFF6A64)
#define pCoolantTemp ((float*)0xFFFF5CAC)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF66F4)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF689C)
#define pReqTorque ((float*)0xFFFF7894)
#define pThrottlePlate ((float*)0xFFFF6798)
#define pCurrentGear ((char*)0xFFFF6B7D)
#define pAf1Res ((float*)0xFFFF5F08)

/////////////////////
// OBD Experimental stuff
/////////////////////


/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C2460)
#define dLoadSmoothingB (0x000C2464)
#define dLoadSmoothingFinal (0x000C2470)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FCAC)
#define hMemoryReset (0x0000DBC8)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00012038)

