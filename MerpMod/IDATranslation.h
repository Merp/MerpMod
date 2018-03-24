/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#define SUB_KCA_HOOK_OLDVAL pKcaIam

#if WGDC_HOOK_DEFINED
#define TableInitialWGDC	((ThreeDTable*)dWgdcInitial)
#define TableMaxWGDC		((ThreeDTable*)dWgdcMax)
#endif

//FBKC AND IAM DEFINES
#ifdef pFbkc4
#define pFBKC					((float*) pFbkc4)
#else
#define pFBKC 			(float)( ( (char*)pFbkc1 ) - 128 )
#endif

#ifdef pIam4
#define pIAM (pIam4)
#define IAM (*(float*)pIam4)					
#else
#define pIAM (pIam1)
#define IAM (float)( (*(char*)pIam1) / 16 )
#endif

#ifdef pCruiseFlags
#ifndef pResumeFlags
#define pResumeFlags	((char*)pCruiseFlags)
#endif
#ifndef	pCoastFlags
#define pCoastFlags	((char*)pCruiseFlags)
#endif
#ifndef	pBrakeFlags
#define pBrakeFlags	((char*)pCruiseFlags)
#endif
#endif

#ifdef pSiDrive
#define SI_DRIVE
#endif

#ifdef dInjectorScaling
#define InjectorScalingOem ((float*)dInjectorScaling)
#endif

#ifdef tPolf
#define PrimaryOEMPolfTable tPolf
#elif defined(tPolfKcaAlt) //TODO FIX THIS FOR NEWER CARS!!!!!
#define PrimaryOEMPolfTable tPolfKcaAlt
#endif

#ifdef tBaseTiming
#define PrimaryOEMTimingTable tBaseTiming
#elif defined(tBaseTimingPNonCruise) //TODO FIX THIS FOR NEWER CARS!!!!!
#define PrimaryOEMTimingTable tBaseTimingPNonCruise
#endif

#ifdef tTargetBoost
#define OEMTargetBoostTable tTargetBoost
#endif

#ifdef tWgdcInitial
#define OEMWGDCInitialTable tWgdcInitial
#endif

#ifdef tWgdcMax
#define OEMWGDCMaxTable tWgdcMax
#endif

/* OLD STUFF
#define pEngineSpeed                      ((float*)E_ENGINE_SPEED)
#define pVehicleSpeed                    ((float*)E_VEHICLE_SPEED)

#define pCoolantTemp				((float*)E_COOLANT_TEMP)

#define RevLimitBitMask				((char)REVLIM_FUELCUT_BITMASK)
#define pClutchFlags             	((char*)CLUTCH_FLAGS)

#ifdef BRAKE_FLAGS
#define pBrakeFlags					((char*)BRAKE_FLAGS)
#else 
#define pBrakeFlags					((char*)CRUISE_FLAGS)
#endif

#define BrakeBitMask				((char)BRAKE_BITMASK)

#define ClutchBitMask				((char)CLUTCH_BITMASK)//Clutch switch is SSM switch #63
#define pAtmoPress      ((float*)pAtmoPress)
#define pIntakeAirTemp     ((float*)E_IAT_DIRECT)
#define pMassAirFlow              ((float*)E_MAF_GS_DIRECT)
#define pMafSensorVoltage         ((short*)E_MAF_VOLTS_DIRECT)
#define pEngineLoad					((float*)E_ENGINE_LOAD_4BYTEEXT_E32)
#ifdef	E_AF_SENSOR_1_RESISTANCE
	#define pAf1Res			((float*)E_SSM_AF_SENSOR_1_RES)
#endif
#define pThrottlePlate				((float*)E_THROTTLE_PLATE_OPENING_ANGLE_4BYTEEXT_E38)
#define pReqTorque					((float*)E_REQUESTED_TORQUEEXT_E56)
#define pWgdc4					((float*)pWgdc4)
#define pCurrentGear				((char*)E_GEAR_CALCULATEDEXT_E59)
#define pPOLF4byte					((float*)pPolfEnrich)


#define pVIN 						((char*)E_OBD_VIN)
//add second defien to support "boost pressure" param
#ifdef E_MANIFOLD_RELATIVE_SEA_LEVEL_PRESSURE_4BYTEEXT_E52
#define pManifoldAbsolutePressure ((float*)E_MANIFOLD_RELATIVE_SEA_LEVEL_PRESSURE_4BYTEEXT_E52)
#else
#define pManifoldAbsolutePressure ((float*)E_BOOST_PRESSURE_ACTUAL)
#endif


#ifdef CRUISE_RESUME_FLAGS
#define pResumeFlags				((char*)CRUISE_RESUME_FLAGS)
#else
#ifdef CRUISE_FLAGS
#define pResumeFlags				((char*)CRUISE_FLAGS)
#endif
#endif

#define ResumeBitMask				((char)CRUISE_RESUME_BITMASK)// Resume button is SSM switch #66
#ifdef CRUISE_COAST_FLAGS
#define pCoastFlags					((char*)CRUISE_COAST_FLAGS)//0xFFFF64B0) //k
#else
#ifdef CRUISE_FLAGS
#define pCoastFlags					((char*)CRUISE_FLAGS)
#endif
#endif

#define CoastBitMask				((char)CRUISE_COAST_BITMASK)// Coast button is SSM switch #65

#define pCelSignalOem				((char*)CEL_TRIGGER_BYTE)
//#define pCruiseSignalOem			((char*)0x1234)//

#define pFlagsRevLimit				((char*)pFlagsRevLimit)
*/