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

//////////////////////////
//RAM VARIABLES STRUCTURE
//////////////////////////
typedef struct
{
	unsigned char MasterInitFlag;
	unsigned char VinAuth;
	unsigned char CruiseCoastLast;
	unsigned char CruiseResumeLast;
	
#if VIN_HACKS
	unsigned char VehicleIdent[20];
#endif

	float InjectorScaling;
	float Mfempty;
	float Mfempty1;
	float Mfempty2;
//	float Mfempty3;
//	float Mfempty4;
//	float Mfempty5;
//	float Mfempty6;
	
#if SPARK_CUT
	unsigned char SparkEventsX;
	unsigned char se;
	unsigned char se1;
	unsigned char se2;
	unsigned char SparkEventsY;
	unsigned char se3;
	unsigned char se4;
	unsigned char se5;
#endif

#if SWITCH_HACKS
	unsigned char MapSwitch;
	float MapBlendRatio;
	float TGVLeftVolts;
	float TGVRightVolts;
	float TGVLeftScaled;
	float TGVRightScaled;
#endif

#if SD_HACKS
	//MAF/SD params
	unsigned char SDInitFlag;		//96d
	unsigned char MafMode;
	unsigned char SDempty;
	unsigned char sdempty1;	
	float VolumetricEfficiency;	//	96d
	float MafFromSpeedDensity;
	float MafFromSensor;
	float AtmosphericCompensation; //96
	float DeltaMapCompensation;	
	float SDMafBlendRatio;
	float SDMafFromBlend;

#endif
	
#if REVLIM_HACKS
	//Rev Limiter params
	unsigned char  	RevLimInitFlag;  //96
	unsigned char  	RevLimMode;
	char	FlatFootShiftMode;
	char	LCEngaged;
	char	FFSEngaged;
	char	elemptteey;
	char	elempty1;
	char	eleemee2;
	float	FFSGear;
	float 	RevLimCut;	//96
	float 	RevLimResume;
  	float  	RedLineCut;
	float	RedLineHyst;	//9
	float	LaunchControlSpeedMax;
  	float  	LaunchControlCut;	
	float  	LaunchControlHyst;
 	float  	FFSRPM;
	float 	FlatFootShiftRpmThreshold;
	float	FlatFootShiftAutoDelta;
	float	FlatFootShiftStaticDelta;
	float  	FlatFootShiftHyst;	//9
  	float  	FlatFootShiftSpeedThreshold; //97
#endif
	
#if CEL_HACKS
	// New variables needed for the CEL Flash Hack
	unsigned char CelSignal;				
	unsigned char CelSignalLast;				
	unsigned char CruiseSignal;			
	unsigned char CruiseSignalLast;	
		
	unsigned char CelFlashSpeed;				
	unsigned char CelFlashSpeedCounter;
	unsigned char CelFlashCount;			
	unsigned char CelFlashCounter;
			
	unsigned char CelRepeatSwitch;
	unsigned char CelFlashStatus;
	unsigned char CelFlashDelay;
	unsigned char celunused;
	
	//unsigned char CruiseSpeedCounter;			
	//unsigned char CruiseFlashCounter;

#endif

#if PROG_MODE
	unsigned char ProgModeEnable;
	unsigned char ProgModeTimer;
	unsigned char ProgModeEntry;
	unsigned char ProgModeWait;
	unsigned char ProgModeCurrentMode;
	unsigned char ProgModeValueFlashes;
	unsigned char ValetMode;
	unsigned char asdf3;
	float ProgModeValue;
#endif			

#if TIMING_HACKS
	//Timing Hack params
	unsigned char 	TimingHackInitFlag;		//97
	unsigned char 	LCTimingMode;
	unsigned char	TimingHackEnabled;
	char	Tempty1;	
	float	BaseTiming;
	float 	TimingHackOutput;	//97
	float 	LCTimingRetard;		//97
	float 	LCTimingLock;		//97
	float	LCTimingLockRPM;
	float	LCTimingRetardMultiplier;
	float	SubtractiveKCA;
	float	MaxSubtractiveKCA;
#endif

#if POLF_HACKS
	//Fuel Hack params
	unsigned char 	POLFuelHackInitFlag;	//97
	unsigned char 	LCFuelMode;
	unsigned char	PolfHackEnabled;
	char	Fempty1;	
	float PolfTarget;
	float PolfOutput;		//97
	float LCFuelEnrich;			//97
	float LCFuelLock;			//97
	float LCFuelEnrichMultiplier;
#endif

#if BOOST_HACKS	
	//Target Boost Params
	float TargetBoost;
		
	//PGWG Params
	float PGWGComp;
	float PGTBComp;
	
	//WGDC Params
	float WGDCInitial;
	float WGDCMax;
#endif
	
	
#if VE_RAMTUNING
//VE RAMTUNING
	unsigned char VERamFlag;
	unsigned char emptypaafr;
	unsigned char emptypdfr1;
	unsigned char emptyprdafd2;
	float VERamCols[24];
	float VERamRows[24];
	short VERamData[576];
#endif

#if TIMING_RAMTUNING
//VE RAMTUNING
	unsigned char TimingRamFlag;
	unsigned char emptypadr;
	unsigned char emptyprdadf1;
	unsigned char emptypfadfr2;
	float TimingRamCols[20];
	float TimingRamRows[20];
	unsigned char TimingRamData[400];
#endif

#if POLF_RAMTUNING
//VE RAMTUNING
	unsigned char POLFRamFlag;
	unsigned char emptypr;
	unsigned char emptypr1;
	unsigned char emptypr2;
	float POLFRamCols[20];
	float POLFRamRows[20];
	unsigned char POLFRamData[400];
	unsigned char LCFuelEnrichRamFlag;
	unsigned char emptylcfe;
	unsigned char emptylcfe1;
	unsigned char emptylcfe2;
	float LCFuelEnrichCols[20];
	float LCFuelEnrichRows[20];
	unsigned char LCFFuelEnrichData[400];
#endif

	
#if PGWG_RAMTUNING
	//PGWG RAMTUNING
	unsigned char PGWGRamFlag;
	unsigned char emptypadfdr;
	unsigned char emptyprada1;
	unsigned char emptypddfrfaf2;
	float PGWGRamCols[6];
	float PGWGRamRows[10];
	short PGWGRamData[60];
#endif

	
#if WGDC_RAMTUNING
	//WGDC RAMTUNIN
	unsigned char WGDCInitialRamFlag;
	unsigned char emptywi1;
	unsigned char emptywi2;
	unsigned char emptywi3;
	float WGDCInitialRamCols[6];
	float WGDCInitialRamRows[10];
	short WGDCInitialRamData[60];
	unsigned char WGDCMaxRamFlag;
	unsigned char emptywm1;
	unsigned char emptywm2;
	unsigned char emptywm3;
	float WGDCMaxRamCols[6];
	float WGDCMaxRamRows[10];
	short WGDCMaxRamData[60];
#endif

long	RamHoleSpace;
char	RamHoleEndMarker;
	
	//IF ADDING PARAMS, MUST UPDATE SPARK CUT ASM!!!!
	
} RamVariables;