=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be618 | PitPosString | setup | string offset | offset | 1 | "PitPos" string offset — used in FUN_00402690 for INI/config key lookup |
| DAT_005be518 | RainyFogPlanesString | renderer | string offset | offset | 1 | "RainyFogPlanes" string offset — used in FUN_00402690 for renderer config |
| DAT_005be498 | WpGalphaString | renderer | string offset | offset | 1 | "WpGalpha" string offset — used in FUN_00402690 for renderer config |
| DAT_005be870 | byte_5BE870 | renderer | byte | read | 1 | Used in FUN_004085f0 as handle/object selector — passed to FUN_00456f70 based on param_2/param_3 case (-1 vs 1) to select secondary render target |
| DAT_0059e6d8 | dbl_59E6D8 | math_util | double | read | 1 | Double constant used in FUN_0040ca30 — part of vehicle position/rotation calculation |
| DAT_005bea1c | CameraString | camera | string offset | offset | 1 | "Camera" string offset — used in FUN_0040d4c0 for camera config |
| DAT_005beb90 | DsconeString | audio | string offset | offset | 1 | "dscone" string offset — used in FUN_0040fe50 for audio DSP cone config |
| DAT_005ea5d8 | FileEnumSentinel | filesys | int | write | 1 | Sentinel value (-1) set to 0xFFFFFFFF during file enumeration init in FUN_00411840. Part of file enumeration state block with DAT_005ea5d0/5d4/5dc/5e0 |
| DAT_005c2400 | CountryeString | game | string offset | offset | 1 | "Countrye" string — likely "Country" INI key for nationality config |
| DAT_005c24fc | GastonMString | driver | string offset | offset | 1 | "Gaston M" string — driver name for Gaston Mazzacane, used in FUN_00415d90 |
| DAT_005c2428 | PedroDiString | driver | string offset | offset | 1 | "Pedro Diniz" string — driver name, used in FUN_00415d90 |
| DAT_005c2910 | Team1999Williams | setup | string offset | offset | 1 | "1999 Williams" string — team name, used in FUN_0041b980 |
| DAT_005c27fc | Team2001Prost | setup | string offset | offset | 1 | "2001 Prost" string — team name, used in FUN_0041b980 |
| DAT_005c2a5c | OptionsFlagsString | game | string offset | offset | 1 | "Options Flags" string — INI key for options, used in FUN_004216f0 |
| DAT_005c2cb8 | SeasonDirString | setup | string offset | offset | 1 | "SeasonDir" string — INI key, used in FUN_00421cd0 |
| DAT_005c2bb4 | ObjDetailString | renderer | string offset | offset | 1 | "ObjDetail" string — renderer detail level key, used in FUN_00421cd0 |
| DAT_005c2ac4 | VersionString | setup | string offset | offset | 1 | "Version" string — version key, used in FUN_00421cd0 |
| DAT_005c2eec | CpuRatingDString | setup | string offset | offset | 1 | "Cpurating" string — CPU rating format string, used in FUN_00422be0 |
| DAT_005c2db4 | VersionString2 | setup | string offset | offset | 1 | "Version" string — version display, used in FUN_00422be0 |
| DAT_005c31f4 | AIConfigRaceAbilityString | setup | string offset | offset | 1 | "Raceability" string — AI config key, used in FUN_00424080 |
| DAT_005c3144 | VehicleField_3144 | vehicle | int | offset | 1 | Stride-4 field array at offset 0xcb2 of vehicle struct — accessed as param_1[0xcb2] in FUN_00424e70 (AI state machine). Checked for values 0/1 |
| DAT_0059e988 | AISpatialProximityThreshold | ai | float | read | 1 | Float threshold ~large for AI opponent proximity check in FUN_0042a7d0. Compared against squared distance to target vehicle to determine if opponent is "nearby" for battle/overtake logic |
| DAT_005c3448 | BrakingPointAsString | setup | string offset | offset | 1 | "Braking Point As" string — AI braking config key, used in FUN_0042c440 |
| DAT_007c933c | CollisionAccumulator | collision | int[11] | write | 1 | Zeroed block of 11 ints (DAT_007c932c-9358) in FUN_0042c690 — collision/contact accumulators reset every 10th tick |
| DAT_005c34ec | Practice3String | setup | string offset | offset | 1 | "Practice3" string — session config key, used in FUN_0042ce30 |
| DAT_005c36e0 | GearRatiosString | setup/vehicle | string offset | offset | 1 | "Gear Ratios" string — setup INI key, used in FUN_0042de10 |
| DAT_0059ea00 | DynSolverConvergenceThreshold | dynamics | double | read | 1 | Double threshold for convergence test in FUN_0042f180 (dynamics solver). Compared against solver residual |
| DAT_005c3da4 | FwsettingDString | setup | string offset | offset | 1 | "Fwsetting" string — front wing setting INI key, used in FUN_0042fd00 |
| DAT_005c3bc8 | Front3rdFastreString | setup | string offset | offset | 1 | "Front 3rd fastre" string — suspension setup key, used in FUN_0042fd00 |
| DAT_005c39ec | DiffpumpsettingString | setup | string offset | offset | 1 | "Diffpumpsetting" string — diff pump INI key, used in FUN_0042fd00 |
| DAT_005c3860 | DownforceFString | setup | string offset | offset | 1 | "Downforce F" string — front downforce key, used in FUN_0042fd00 |
| DAT_005c3f28 | EstCorneringString | setup | string offset | offset | 1 | "Est Cornering" string — AI est cornering key, used in FUN_00430f00 |
| DAT_005ea535 | byte_5EA535 | game | byte | write | 1 | State byte in param_1 struct — part of object state machine in FUN_00434460. Tracks initialization state (0=uninit, 1=initing, 2=running) |
| DAT_0059eb10 | ThermalModelConst | physics/thermal | double | read | 1 | Double constant in FUN_00436870 (6198-byte thermal/damage model). Used in engine temperature computations with multiple double-precision arithmetic operations |
| DAT_005c4150 | RearAxleString | setup | string offset | offset | 1 | "Rear Axle" string — suspension setup key, used in FUN_00438da0 |
| DAT_005c42d4 | FlForeLowerString | setup | string offset | offset | 1 | "Fl Fore Lower" string — suspension geometry key, used in FUN_0043b590 |
| DAT_0059ecd0 | EngineTorqueDecayFactor | physics/engine | double | read | 1 | Double used in FUN_0043ef20 as damping/decay factor. Applied in engine torque model with ABS(angular velocity) scaling. Part of engine speed limiter torque reduction path |
| DAT_007cc6e4 | ContactForceThreshold | physics | double | read | 1 | Double threshold in FUN_00443b70 compared against contact relative velocity. Gates secondary damping force in vehicle dynamics contact model |
| DAT_008acfd8 | RaceTimeAccumulator | race | double | read | 1 | Double value used in FUN_004441f0 (9101-byte race dynamics function). Part of race timing/accumulator calculations |
| DAT_007cc1bc | VehicleDynamicsParam | dynamics | double | read | 1 | Double reference in FUN_004441f0 — part of vehicle dynamics solver workspace |
| DAT_005c4434 | DDevF119992002String | debug | string offset | offset | 1 | "D:\\dev\\F1_1999_2002" string — source path assert prefix, used in FUN_00449a80 |
| DAT_007ca3b4 | AudioVolumeFloat | audio | float | write | 1 | Float initialized to 1.0f (1065353216) in sub_44CF34. Audio volume/amplitude setting paired with DAT_007ca3b0=0.0f |
| DAT_007ccd4c | CollisionInit6 | collision | int[6] | write | 1 | Sixth of 6 zeroed collision init fields (DAT_007ccd38-4c) in FUN_0044d400. Part of collision state init block |
| DAT_005c5440 | Cursor01CurString | UI | string offset | offset | 1 | "Cursor01.cur" string — cursor resource, used in FUN_0044f4e0 |
| DAT_005ad374 | AudioEffectTableOffset | audio | dword | read | 1 | Offset/constant in FUN_0044ff50 (5968-byte audio mixer). Used in audio channel routing logic comparing audio source pointers |
| DAT_005ad3bc | AudioChannelConfig | audio | dword | read | 1 | Audio channel configuration pointer table reference in FUN_0044ff50. Compared against multiple audio source objects for channel routing |
| DAT_007c7c5c | DoublePhysicsConst | physics | double | read | 1 | Double constant used in FUN_00451720 — part of vehicle effect/suspension animation physics |
| DAT_007cd1a8 | CollisionDispatchStruct | collision | int | read | 1 | Used in FUN_00452b10 for collision object dispatch — compared against collision shape ID constants for type routing |
| DAT_007cd10c | AudioMixTargetVolume | audio | float | write | 1 | Float written in FUN_004537b0 as target volume for audio mixer from vehicle struct +0x1140 |
| DAT_007cd0fc | AudioMixVolume2 | audio | float | write | 1 | Float written in FUN_004537b0 as secondary audio volume from vehicle struct +0x1140 |
| DAT_005c5590 | LcdDownString | UI | string offset | offset | 1 | "LCD Down" string — UI control key, used in FUN_00455290 |
| DAT_005c548c | LookUpString | UI | string offset | offset | 1 | "Look Up" string — UI control key, used in FUN_00455290 |
| DAT_005c5778 | OrientationratString | input | string offset | offset | 1 | "Orientationrat" string — input config key, used in FUN_004562f0 |
| DAT_005c5ad8 | TrackingrateString | input | string offset | offset | 1 | "Trackingrate" string — input config key, used in FUN_004585e0 |
| DAT_005c5b50 | off_5C5B50 | network | ptr | read | 1 | Pointer constant used in FUN_0045b950 — network config/setup reference |
| DAT_0059f0a4 | NetCommInitParam | network | int | read | 1 | Init parameter value written to NetComm object field [9] in FUN_0045d530. Part of network session initialization |
| DAT_005c5e24 | Autochat05String | network | string offset | offset | 1 | "Autochat05" string — network chat key, used in FUN_0045ecd0 |
| DAT_005c6060 | NetcommSetselfString | network | string offset | offset | 1 | "NetComm::SetSelf" string — debug assert, used in FUN_00460520 |
| DAT_007ceb1c | ReconSettings_e1c | setup | int | read | 1 | Read from param_1+0x6a in FUN_00461900 (session setup). Part of recon/ghost settings block. DAT_007ceb10 is source, DAT_007ceb1c is passed to FUN_0047f1f0 |
| DAT_007ced50 | SessionInitFlags | session | int | read | 1 | Read from param_1+0x76 bit flags in FUN_00461900. Part of session init block — controls TireModelMode, WeatherMode, recon settings etc. |
| DAT_005c6274 | IncompatibleGaString | network | string offset | offset | 1 | "Incompatible" string — version mismatch error, used in FUN_00462da0 |
| DAT_005c63e8 | AutojoinAddresString | network | string offset | offset | 1 | "Autojoin Addres" string — autojoin config key, used in FUN_00463160 |
| DAT_007d0e88 | NetCommContextPtr | network | ptr | read | 1 | Network context/state pointer in FUN_00463f70. Checked for null, with fallback to DAT_005ea438 |
| DAT_005c6798 | TmpvehicleScnString | setup | string offset | offset | 1 | "tmpvehicle.scn" string — temp scene filename, used in FUN_004681b0 |
| DAT_005c69f4 | ReservedKeyString | input | string offset | offset | 1 | "Reserved Key" string — input config key, used in FUN_0046b0c0 |
| DAT_005c6cec | SessionNameSString | network | string offset | offset | 1 | "Session Name: %s" string — network debug, used in FUN_0046de10 |
| DAT_005c7158 | word_5C7158 | setup | short | read | 1 | Short constant in FUN_00477830 — part of game filter/scene setup string processing |
| DAT_005a6b20 | off_5A6B20 | game | ptr | offset | 1 | Pointer/vtable constant used in FUN_0047daf0 |
| DAT_005c739c | PolesString | setup | string offset | offset | 1 | "Poles" string — INI key, used in FUN_0047dd10 |
| DAT_007d2e40 | byte_7D2E40 | scoring | byte | read | 1 | Single byte near SeasonScoringDB (DAT_007d2e48). Read in FUN_00485b90 for scoring config |
| DAT_005cc590 | LoadingscreenpString | UI | string offset | offset | 1 | "Loadingscreenp" string — UI resource path, used in FUN_00492160 |
| DAT_005cc6e8 | Caption1String | UI | string offset | offset | 1 | "Caption1" string — UI dialog caption, used in FUN_00492a40 |
| DAT_005cc890 | DoPageTransitiString | UI | string offset | offset | 1 | "DoPageTransiti" string — UI debug/method name, used in FUN_00493480 |
| DAT_005ac820 | LogOscErrString | audio | string offset | offset | 1 | "LogOscErr" string — audio OSC error log, used in FUN_00493f50 |
| DAT_007ce03c | SessionTimeCounter | session | int | read | 1 | Read in FUN_00496e90 — session time counter/state variable |
| DAT_005cce04 | VehicledisplayString | UI | string offset | offset | 1 | "Vehicledisplay" string — UI config key, used in FUN_0049b0a0 |
| DAT_005acaf8 | ScoringFloatConst | scoring | float | read | 1 | Float constant used in FUN_0049c770 — scoring computation |
| DAT_005ccba8 | off_5CCBA8 | UI | ptr | read | 1 | Pointer/function table used in FUN_0049ca00 — UI widget dispatch |
| DAT_005ccf38 | EnteredOnscreeString | UI | string offset | offset | 1 | "Entered Onscree" string — UI text, used in FUN_0049ef70 |
| DAT_005ccfe8 | PostRaceMonitoString | UI | string offset | offset | 1 | "Post Race Monito" string — UI text, used in FUN_004a0250 |
| DAT_007ce27c | SessionResetFlag | session | int | write | 1 | Written in FUN_004a1200 — session reset/cleanup flag. Part of session state machine |
| DAT_005cd144 | asc_5CD144 | setup | string | offset | 1 | String constant passed to FUN_005665b0 in FUN_004a1ec0 for path/file cleanup |
| DAT_005cd218 | String10secRman | session | string offset | offset | 1 | "10sec Rman" string — penalty/rejoin message, used in FUN_004a24d0 |
| DAT_005cd3c8 | LrwheelonMtsString | setup | string offset | offset | 1 | "Lrwheelon Mts" string — setup key, used in FUN_004a2a90 |
| DAT_005ccc78 | FuelString | setup | string offset | offset | 1 | "Fuel" string — INI key, used in FUN_004a47e0 |
| DAT_008afed4 | OutOfSessionGateFlag | session | int | read | 1 | Gate flag in FUN_004a5820 — when non-zero, allows driver selection in non-race sessions (SessionType <1 or >5). Controls fallback driver assignment path |
| DAT_005acbb4 | WidgetVTableRef | UI | ptr | offset | 1 | Vtable reference pointer at PTR_FUN_005acbfc — used in FUN_004a70e0 (6669-byte UI widget construction) |
| DAT_005d1f90 | VehicleFileString | setup | string offset | offset | 1 | "Vehicle File" string — INI key, used in FUN_004aa270 |
| DAT_005d1d48 | WhetherToAutomString | setup | string offset | offset | 1 | "Whether To Autom" string — auto-transmission config key, used in FUN_004aa270 |
| DAT_005d1a40 | TelemetryExeString | setup | string offset | offset | 1 | "Telemetry Exe" string — INI key, used in FUN_004aa270 |
| DAT_005d17b4 | WhetherTimerIsString | setup | string offset | offset | 1 | "Whether Timer Is" string — timer config key, used in FUN_004aa270 |
| DAT_005d15b8 | WhetherToPlayRString | setup | string offset | offset | 1 | "Whether To Play R" string — replay config key, used in FUN_004aa270 |
| DAT_005d13d0 | AmbientRangeWhString | setup | string offset | offset | 1 | "Ambient Range Wh" string — audio config key, used in FUN_004aa270 |
| DAT_005d1264 | SelfInRearviewString | setup | string offset | offset | 1 | "Self In Rearview" string — camera config key, used in FUN_004aa270 |
| DAT_005d1050 | ProbabilityOfHString | setup | string offset | offset | 1 | "Probability Of H" string — AI config key, used in FUN_004aa270 |
| DAT_005d0d60 | SparkFlowString | setup | string offset | offset | 1 | "Spark Flow" string — spark/effect config key, used in FUN_004aa270 |
| DAT_005d0a7c | MipMappingString | setup | string offset | offset | 1 | "Mip Mapping" string — renderer config key, used in FUN_004aa270 |
| DAT_005d08b8 | MipmapLodBiasString | setup | string offset | offset | 1 | "Mipmap Lod Bias" string — renderer config key, used in FUN_004aa270 |
| DAT_005d05d0 | WhetherToRecorString | setup | string offset | offset | 1 | "Whether To Recor" string — telemetry config key, used in FUN_004aa270 |
| DAT_005d031c | MaximumTotalLoString | setup | string offset | offset | 1 | "Maximum Total Lo" string — load config key, used in FUN_004aa270 |
| DAT_005d0094 | SettingsTypeString | setup | string offset | offset | 1 | "Settings Type" string — INI key, used in FUN_004aa270 |
| DAT_005cfe44 | PartsDurationString | setup | string offset | offset | 1 | "Parts Duration" string — wear config key, used in FUN_004aa270 |
| DAT_005cfb48 | NetDataRateString | setup | string offset | offset | 1 | "Net Data Rate" string — network config key, used in FUN_004aa270 |
| DAT_005cf6f8 | SortByNameString | setup | string offset | offset | 1 | "Sort By Name" string — sorting config key, used in FUN_004aa270 |
| DAT_005cf300 | IfLatencyIsBelString | setup | string offset | offset | 1 | "If Latency Is Bel" string — network config key, used in FUN_004aa270 |
| DAT_005cf060 | KeyboardClutchString | setup | string offset | offset | 1 | "Keyboard Clutch" string — input config key, used in FUN_004aa270 |
| DAT_005cec0c | Controller1YString | setup | string offset | offset | 1 | "Controller 1 Y" string — input config key, used in FUN_004aa270 |
| DAT_005cea50 | ControlSteerLeString | setup | string offset | offset | 1 | "Control Steer Le" string — input config key, used in FUN_004aa270 |
| DAT_005ce87c | ControlTcoverrString | setup | string offset | offset | 1 | "Control Tcoverr" string — TC override key, used in FUN_004aa270 |
| DAT_005ce6b4 | ControlLookRolString | setup | string offset | offset | 1 | "Control Look Rol" string — look control key, used in FUN_004aa270 |
| DAT_005ce240 | HowMuchWeightIString | setup | string offset | offset | 1 | "How Much Weight I" string — weight config key, used in FUN_004aa270 |
| DAT_005cdda8 | ScalesActualEnString | setup | string offset | offset | 1 | "Scales Actual En" string — engine config key, used in FUN_004aa270 |
| DAT_005cd9b8 | RumbleStipFreqString | setup | string offset | offset | 1 | "Rumble Stip Freq" string — FFB config key, used in FUN_004aa270 |
| DAT_005d22c4 | AttemptingToSaString | setup | string offset | offset | 1 | "Attempting To Sa" string — debug/file message, used in FUN_004b0770 |
| DAT_005accbc | FloatQuantizeUpperBound | renderer | float | read | 1 | Upper clamp bound for float-to-16-bit quantization in FUN_004b2750. When *param_2 > this value, outputs 0x7FFF |
| DAT_008ab6f8 | FreeListTailPtr | memory | ptr | write | 1 | Tail pointer of free memory block list in FUN_004b44e0 (memory allocator). Part of linked-list allocator with DAT_008ab6f0/6f4/6fc/700/704/708/70c |
| DAT_005acd18 | CameraZoomMult | camera | float | read | 1 | Camera zoom/scale multiplier used in FUN_004b9e40. Multiplied with DAT_008afe90 (world distance) for zoom computation |
| DAT_005d2574 | StopGoPenaltyString | steward | string offset | offset | 1 | "Stop Go Penalty" string — steward message, used in FUN_004bbd60 |
| DAT_005acdc8 | InitAudioVolume | audio | float | read | 1 | Audio init volume float used in FUN_004be760 — initial volume setting |
| DAT_005d2718 | VehfileString | setup | string offset | offset | 1 | "Vehfile" string — INI key, used in FUN_004c03f0 |
| DAT_005d273c | CurrentGridposString | steward | string offset | offset | 1 | "Current Grid Position" string — output format for session data, used in FUN_004c0690 |
| DAT_005d2e54 | TotalracesDString | setup | string offset | offset | 1 | "Totalraces" format string, used in FUN_004c2420 |
| DAT_005d2bf4 | GameoptRaceTimString | setup | string offset | offset | 1 | "Gameopt Race Tim" string — game option key, used in FUN_004c2420 |
| DAT_005d2fc4 | SteeringwheelaString | setup | string offset | offset | 1 | "Steeringwheela" string — input config key, used in FUN_004c3200 |
| DAT_005d2e94 | SfxString | setup | string offset | offset | 1 | "Sfx" string — audio config key, used in FUN_004c3200 |
| DAT_005acdfc | AudioMixScaler | audio | float | read | 1 | Session-type dependent audio mixer scale factor in FUN_004c7f30. Default = DAT_0059e7f8, overridden per SessionType (3→_DAT_005ace10, 4→_DAT_005ace0c, etc.) |
| DAT_005d347c | PithornWavString | audio | string offset | offset | 1 | "pithorn.wav" string — audio filename, used in FUN_004c9840 |
| DAT_005d36a4 | FlamesString | renderer | string offset | offset | 1 | "Flames" string — particle effect key, used in FUN_004ca480 |
| DAT_005d35a0 | off_5D35A0 | renderer | ptr | offset | 1 | Pointer constant used in FUN_004ca480 — particle/renderer config |
| DAT_005d34c8 | DeformableString | renderer | string offset | offset | 1 | "Deformable" string — mesh config key, used in FUN_004ca480 |
| DAT_005d3778 | CubeErrorSString | renderer | string offset | offset | 1 | "Cube Error" string — renderer error format, used in FUN_004cb120 |
| DAT_005d38ac | CollfrictString | collision | string offset | offset | 1 | "Collfrict" string — collision friction key, used in FUN_004cdd80 |
| DAT_005d3930 | STerrainIniString | setup | string offset | offset | 1 | "%s terrain.ini" string — terrain config path, used in FUN_004ceef0 |
| DAT_005d3afc | GridgirlaMtsString | track | string offset | offset | 1 | "Gridgirla Mts" string — track grid config key, used in FUN_004d0110 |
| DAT_005d3be0 | ReversepitordeString | setup | string offset | offset | 1 | "Reversepitorde" string — pit config key, used in FUN_004d12c0 |
| DAT_005d40ec | RaceString | setup | string offset | offset | 1 | "Race" string — session config key, used in FUN_004d24d0 |
| DAT_005d3f10 | DriveaidsNoAiCString | setup | string offset | offset | 1 | "Driveaids No Ai C" string — driver aids key, used in FUN_004d24d0 |
| DAT_005d3d60 | VehicleSString | setup | string offset | offset | 1 | "Vehicle" string — config key, used in FUN_004d24d0 |
| DAT_005d41ec | EnteredStewardString | steward | string offset | offset | 1 | "Entered Steward" string — debug/assert, used in FUN_004d36d0 |
| DAT_005d4214 | NoSector2PolyFString | track | string offset | offset | 1 | "No Sector2 PolyF" string — track data error, used in FUN_004d38f0 |
| DAT_007cc520 | CollisionContactTimer | collision | int | read | 1 | Collision contact timer/state used in FUN_004d4580 — gates collision response based on session type and race phase |
| DAT_005d44e8 | UnfilteredSteeString | input | string offset | offset | 1 | "Unfiltered Stee" string — steering config key, used in FUN_004d4a80 |
| DAT_007cea18 | ProcessExecPath | system | ptr | read | 1 | Path pointer to external executable for CreateProcessA in sub_4D5885. Falls back to DAT_005ea438 if null |
| DAT_005d4830 | WidthString | track | string offset | offset | 1 | "Width" string — track geometry key, used in FUN_004d6b00 |
| DAT_005d4738 | LatcurveString | track | string offset | offset | 1 | "Latcurve" string — track lateral curve key, used in FUN_004d6b00 |
| DAT_005d4a61 | ByteSteeringDisplay | UI | byte | read | 1 | Byte steering display type selector in FUN_004d8130. When param_2==0 uses DAT_005d4a60, else uses this. Controls steering wheel animation display mode |
| DAT_005d4aef | ByteGearPosDisplay | UI | byte | read | 1 | Byte gear position display value in FUN_004d9420. Used to print current gear character on HUD |
| DAT_005ad0f8 | ObjectVTableRef | game | ptr | offset | 1 | Vtable pointer reference at PTR_LAB_005ad0f8 — used in FUN_004dc220 for object construction |
| DAT_005d4c20 | WcrefuelerString | pit | string offset | offset | 1 | "Wcrefueler" string — pit crew config key, used in FUN_004ddad0 |
| DAT_005d4e2c | UnableToReadSSString | setup | string offset | offset | 1 | "Unable To Read" string — error message, used in FUN_004dfce0 |
| DAT_005c6740 | CatsteerString | input | string offset | offset | 1 | "Catsteer" string — steering config key, used in FUN_004dfce0 |
| DAT_007c7430 | PoseInterpDuration | physics | double | read | 1 | Double interpolation duration used in FUN_004e49b0 — controls vehicle pose interpolation rate for wheel/body animation |
| DAT_005ea570 | InitStateFlag2 | setup | int | read | 1 | Init state flag checked in FUN_004ea970 — gates initialization path in vehicle dynamics setup |
| DAT_005ad164 | ParticleGravityScale | particles | float | read | 1 | Particle gravity scale applied in FUN_004f0430 (2270-byte particle effect function). Multiplied with DAT_008afe98 for vertical particle acceleration |
| DAT_005d4fd0 | FrontwingdetacString | setup | string offset | offset | 1 | "Frontwingdetac" string — front wing config key, used in FUN_004f24f0 |
| DAT_005d52f0 | BumptravelString | setup | string offset | offset | 1 | "Bumptravel" string — suspension config key, used in FUN_004f2c60 |
| DAT_005d51a4 | PushrodspindleString | setup | string offset | offset | 1 | "Pushrodspindle" string — suspension config key, used in FUN_004f2c60 |
| DAT_005d505c | BrakediscsettiString | setup | string offset | offset | 1 | "Brakediscsetti" string — brake disc key, used in FUN_004f2c60 |
| DAT_005d54cc | EnginebrakingmString | setup | string offset | offset | 1 | "Enginebrakingm" string — engine braking key, used in FUN_004f3c10 |
| DAT_005d55c8 | EngineemissionString | setup | string offset | offset | 1 | "Engineemission" string — engine emission key, used in FUN_004f3c80 |
| DAT_005d66f4 | GaragedisplayfString | setup | string offset | offset | 1 | "Garagedisplayf" string — garage display key, used in FUN_004f4270 |
| DAT_005d65cc | AidamperfastString | setup | string offset | offset | 1 | "Aidamperfast" string — damper config key, used in FUN_004f4270 |
| DAT_005d64a0 | Pitstop2settinString | setup | string offset | offset | 1 | "Pitstop2settin" string — pit stop key, used in FUN_004f4270 |
| DAT_005d63b0 | LeftfenderString | setup | string offset | offset | 1 | "Leftfender" string — body config key, used in FUN_004f4270 |
| DAT_005d62b8 | BodymaxheightString | setup | string offset | offset | 1 | "Bodymaxheight" string — ride height key, used in FUN_004f4270 |
| DAT_005d619c | DiffusersidewaString | setup | string offset | offset | 1 | "Diffusersidewa" string — diffuser key, used in FUN_004f4270 |
| DAT_005d6028 | Front3rdbumpstString | setup | string offset | offset | 1 | "Front 3rd Bumpst" string — bumpstop key, used in FUN_004f4270 |
| DAT_005d5e68 | ReartoeinrangeString | setup | string offset | offset | 1 | "Reartoeinrange" string — toe-in key, used in FUN_004f4270 |
| DAT_005d5cb0 | Front3rdfastbuString | setup | string offset | offset | 1 | "Front 3rd Fast Bu" string — bumpstop fast key, used in FUN_004f4270 |
| DAT_005d5ad0 | TractioncontroString | setup | string offset | offset | 1 | "Tractioncontro" string — TC config key, used in FUN_004f4270 |
| DAT_005d5998 | ClutchwearString | setup | string offset | offset | 1 | "Clutchwear" string — wear config key, used in FUN_004f4270 |
| DAT_005d5868 | Gear5settingString | setup | string offset | offset | 1 | "Gear5setting" string — gear config key, used in FUN_004f4270 |
| DAT_005d573c | GearingString | setup | string offset | offset | 1 | "Gearing" string — gear config key, used in FUN_004f4270 |
| DAT_005d6cf0 | EnginerpmsoundString | audio | string offset | offset | 1 | "Enginerpmsound" string — audio config key, used in FUN_004f7460 |
| DAT_005d6b4f | EngineSoundString | audio | string offset | offset | 1 | Engine sound key string, used in FUN_004f7460 |
| DAT_005d69b7 | SoundString3_69b7 | audio | string offset | offset | 1 | Audio sample/curve string, used in FUN_004f7460 |
| DAT_005d6813 | SoundString4_6813 | audio | string offset | offset | 1 | Audio sample/curve string, used in FUN_004f7460 |
| DAT_005d6e4c | byte_5D6E4C | renderer | byte | read | 1 | Byte constant used in FUN_004f9480 |
| DAT_005d6e6c | EnteredVidmanEString | renderer | string offset | offset | 1 | "Entered Vidman E" string — debug assert, used in FUN_004fa000 |
| DAT_005ad28c | DownshiftTolerance | transmission | float | read | 1 | Float tolerance for downshift detection used in FUN_004fb910 — gates auto-downshift logic |
| DAT_005ad2ac | TireSpinThreshold | physics/tire | float | read | 1 | Tire spin detection threshold used in FUN_004fcee0 — compares wheel speed vs vehicle speed to detect spin |
| DAT_005ad308 | BrakeRampSlope | physics/brake | float | read | 1 | Brake force ramp slope in FUN_004fde00. Multiplied with input param_2 in linear ramp region (between DAT_0059e4e8 and DAT_0059e8f8) |
| DAT_005ad330 | ClutchEngagementRate | transmission | float | read | 1 | Clutch engagement rate in FUN_004fe2b0 — controls clutch slip speed |
| DAT_005d70c8 | Onpathwetness2String | track | string offset | offset | 1 | "Onpathwetness2" string — track wetness key, used in FUN_004fe820 |
| DAT_005ad358 | VertexCacheTolerance | renderer | float | read | 1 | Vertex cache comparison tolerance in FUN_00500010. Compared against position difference to determine if vertex is already in cache |
| DAT_008b0098 | SineLookupWorkspace | math | dword | write | 1 | Workspace value stored during sine/cosine lookup table generation in FUN_005053ec. Stores FPU control word for precision management |
| DAT_005adc04 | ColorMatrixCoeff_04 | renderer | float | read | 1 | Color transform matrix coefficient for vertex color processing in FUN_0050a92d. Used in 3x4 matrix multiply for RGB565-to-float conversion with bias |
| DAT_005adcfc | VertexShaderVTable | renderer | ptr | offset | 1 | VTable pointer for vertex shader object in FUN_0050b260. PTR_FUN_005adcfc assigned to *param_1 |
| DAT_005ade1c | PixelShaderVTable | renderer | ptr | offset | 1 | VTable pointer for pixel shader object in FUN_0050b879. PTR_FUN_005ade1c assigned to *param_1 |
| DAT_005d7870 | RenderFuncPtr | renderer | ptr | read | 1 | Renderer function pointer in FUN_0050d728. Called indirectly: `(*(code *)PTR_FUN_005d7870)(param_1,param_2,param_3)` |
| DAT_005ade98 | ErrorStringTable | runtime | ptr | offset | 1 | Pointer to "Bogus message code" string table in FUN_0051177c. Part of debug error message handling |
| DAT_005af22c | SimdConstant22c | math | dword | read | 1 | SIMD constant read in FUN_00511b7c — part of SIMD math operations |
| DAT_005af5f0 | RendererMatrixConst | renderer | float[16] | offset | 1 | 4x4 matrix constants used in FUN_0051427f (1387-byte renderer transform function). Serves as default/projection matrix coefficients |
| DAT_005afa20 | NeedDictionaryString | zlib | string offset | offset | 1 | "need dictionary" string — zlib decompression error message, used in FUN_00517adc |
| DAT_005afd00 | IncorrectIendCString | zlib | string offset | offset | 1 | "Incorrect IEND C" string — PNG/zlib error, used in FUN_00518bd4 |
| DAT_005aff58 | UnknownCriticaString | zlib | string offset | offset | 1 | "Unknown Critical" string — PNG error, used in FUN_00518fcf |
| DAT_008d600c | SIMDVectorNormThreshold | math | float | read | 1 | Threshold for SIMD vector normalization in sub_51EE7E. If squared length <= this, output is zeroed. Controls fsqrt branch for near-zero vectors |
| DAT_005d8b90 | QuaternionTransformCoeff | math | float[4] | read | 1 | SIMD quaternion transformation coefficients used in sub_51FB1E (198-byte SSE quaternion math). Multiplied in quaternion-vector transform via _mm_mul_ps |
| DAT_008d6150 | ColorChannelMaskSIMD | renderer | float[4] | read | 1 | SIMD mask for color channel extraction in sub_51FEBE (179-byte). Part of pixel/color processing with _mm_mul_ps and _mm_shuffle_ps |
| DAT_008d6220 | SIMDRSQConstants | math | float[4] | read | 1 | SIMD reciprocal square root approximation constants in sub_520A7E (380-byte). Used with _mm_mul_ps and fsqrt for normalized vector ops |
| DAT_008d6288 | EigenDecompConst | math | float[5] | read | 1 | Float constants for eigenvalue/eigenvector computation in sub_520CE0 (276-byte). Includes sqrt factor, normalization divisor, and matrix comparison threshold |
| DAT_005d9010 | DCTTransformCoeff | codec | float[16] | read | 1 | DCT/transform coefficients used in FUN_005289e0 (492-byte codec transform). Part of 30+ coefficient array for discrete cosine-like signal transform |
| DAT_005d90b0 | CodecDummyGlobal | codec | float | read | 1 | Stub reference in empty function FUN_00528bd0 — likely unused codec constant |
| DAT_005d93b0 | SIMDSqrtApproxConst | math | dword | read | 1 | SIMD sqrt approximation constant used in FUN_00529000 (247-byte MMX/3DNow! math). Part of Newton-Raphson reciprocal sqrt iteration |
| DAT_005b0878 | AudioCodecBuffer | audio | byte[] | offset | 1 | Audio codec data buffer in FUN_0052a4a5 — audio/Speech compression workspace |
| DAT_005b0be8 | AudioMixCoeffs | audio | dword | read | 1 | Audio mixing coefficients used in FUN_0052ab4e (1720-byte audio mixer). 16-bit signed multiply-accumulate with packed 8-element operations |
| DAT_005b0c80 | AudioMixCoeffs2 | audio | qword | read | 1 | Audio mixing coefficients used in FUN_0052b561 (3539-byte). Extended coefficient set for multi-channel mixing |
| DAT_005b2ca4 | AudioCodecState | audio | int | read | 1 | Audio codec state/flag read in FUN_0052e6f0 (6487-byte audio decode). Part of audio codec (Miles Sound System) decompression pipeline |
| DAT_008b599c | DCTWorkspaceFloat | codec | float | write | 1 | Float workspace written in FUN_00531b50 (3910-byte DCT/codec transform). Part of 32x32 block transform coefficient write area |
| DAT_005b774c | DCTTransformCoeff_774c | codec | float | read | 1 | DCT transform coefficient in FUN_00531b50. Multiplied with (param_3[8] - param_3[0x17]) for signal difference encoding |
| DAT_008b5960 | DCTOutputCoeff | codec | float | write | 1 | DCT output coefficient written in FUN_00531b50. Part of 32x32 block transform result storage |
| DAT_008b59bc | DCTOutputScaler | codec | float | write | 1 | DCT output scale coefficient written in FUN_00531b50. Part of 32x32 DCT transform output |
| DAT_005b7794 | DCTConst_7794 | codec | float | read | 1 | DCT constant coefficient in FUN_00531b50. Used in block transform math |
| DAT_005da834 | off_5DA834 | codec | ptr | read | 1 | Pointer constant used in FUN_00535c10 |
| DAT_005b85f8 | ImageDecompressConst | codec | int | read | 1 | Image decompression constant used in sub_539200 (1011-byte). Part of image/codec decompression state machine |
| DAT_008b8ed8 | AudioPlaybackRate | audio | qword | write | 1 | Audio playback rate constant (0x100000000000000) written in FUN_0053c2c0. Sets sample rate conversion factor |
| DAT_005dbe48 | S4sSString | audio | string offset | offset | 1 | "%4s %s" format string, used in FUN_00546450 |
| DAT_005dc0b8 | BikString | audio | string offset | offset | 1 | "Bik" string — Bink video format, used in FUN_00551a50 |
| DAT_005dc16c | ParticleMustBeString | particles | string offset | offset | 1 | "Particle Must Be" string — debug error, used in FUN_00557670 |
| DAT_005dc33c | ShadowcasterString | renderer | string offset | offset | 1 | "Shadowcaster" string — scene config key, used in FUN_0055a910 |
| DAT_005dc3ec | AmbientcolorString | renderer | string offset | offset | 1 | "Ambientcolor" string — scene config key, used in FUN_0055b200 |
| DAT_005dc594 | RenderTargetConst0 | renderer | int | read | 1 | Render target config constant in FUN_0055f0d0 |
| DAT_005dc54c | RenderTargetConst1 | renderer | int | read | 1 | Render target config constant in FUN_0055f0d0 |
| DAT_005dc4f8 | RenderTargetConst2 | renderer | int | read | 1 | Render target config constant in FUN_0055f0d0 |
| DAT_005dc4b8 | RenderTargetByte | renderer | byte | read | 1 | Render target byte config in FUN_0055f0d0 |
| DAT_005dd8cc | SoundMixClipTable | audio | byte[1024] | write | 1 | 32x32 = 1024-byte clip/limit table written in sub_561B2A. Used for audio mixing saturation: byte_5DD8CC[n*32+ii] = min(n+ii, 31) for n,ii in [0,32) |
| DAT_005e4f90 | ListSGamenameSString | network | string offset | offset | 1 | "%s %s" games list format string, used in FUN_00562e30 |
| DAT_005e50b0 | FFFString | audio | string offset | offset | 1 | "FFF" string — triple-F format specifier, used in FUN_00565870 |
| DAT_005e521c | Com1String | input | string offset | offset | 1 | "Com1" string — serial port name, used in FUN_005687f0 |
| DAT_005b89b8 | SuspensionRateCoeff | physics/suspension | double | read | 1 | Double coefficient in FUN_00569de0 (878-byte suspension). Used in damping ratio: `SQRT(distSq) / (speed * coeff + SQRT(refSpeedSq))`. Controls suspension oscillation damping |
| DAT_005e52bc | TwoBodiesNamedString | physics | string offset | offset | 1 | "Two Bodies Named" string — physics error, used in FUN_0056d930 |
| DAT_008d0c38 | DynSolverMatrixBlock | dynamics | double[1K+] | read | 1 | Part of dynamics constraint solver workspace (0x8D0000-0x8D9000). Double matrix workspace for LDL^T/Cholesky factorization in sub_56FA96 (17786-byte solver) |
| DAT_008d1000 | DynSolverScratch | dynamics | double[] | read | 1 | Dynamics solver scratch/workspace array in sub_56FA96. Part of 0x8D0000-0x8D9000 physics solver block |
| DAT_008d0000 | DynSolverBase | dynamics | double[] | read | 1 | Base of dynamics solver workspace block (0x8D0000). Zeroed by FUN_00579ccf (memset), factorized by sub_575BBD (LDL^T), used by sub_56FA96 |
| DAT_008d0270 | DynSolverBlock_0270 | dynamics | double[] | read | 1 | Dynamics solver workspace region at 0x8D0270. Part of constraint matrix in LDL^T solver |
| DAT_008d3a58 | DynSolverConst_3a58 | dynamics | double | read | 1 | Double constant in dynamics solver workspace (sub_56FA96). Part of force/constraint computation |
| DAT_008d0368 | DynSolverBlock_0368 | dynamics | double[] | read | 1 | Dynamics solver workspace region at 0x8D0368. Part of constraint matrix factorization |
| DAT_008d0578 | DynSolverBlock_0578 | dynamics | double[] | offset | 1 | Dynamics solver workspace region at 0x8D0578. Part of constraint matrix factorization |
| DAT_008d3a80 | DynSolverConst_3a80 | dynamics | double | read | 1 | Double constant in dynamics constraint solver workspace |
| DAT_008d0690 | DynSolverOutput_0690 | dynamics | double | write | 1 | Dynamics solver output write location at 0x8D0690 |
| DAT_008d0768 | DynSolverOutput_0768 | dynamics | double | write | 1 | Dynamics solver output write location at 0x8D0768 |
| DAT_008d1958 | DynSolverBlock_1958 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1958. Part of constraint matrix in LDL^T solver |
| DAT_008d1ec0 | DynSolverBlock_1ec0 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1EC0. Part of solver matrix |
| DAT_008d0cd8 | DynSolverBlock_0cd8 | dynamics | double[] | offset | 1 | Dynamics solver workspace at 0x8D0CD8. Referenced by structured offset from solver code |
| DAT_008d1980 | DynSolverBlock_1980 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1980. Part of constraint solver matrix |
| DAT_008d0f60 | DynSolverBlock_0f60 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D0F60. Part of solver matrix |
| DAT_008d3ad8 | DynSolverConst_3ad8 | dynamics | double | read | 1 | Double constant in dynamics constraint solver |
| DAT_008d3ae0 | DynSolverConst_3ae0 | dynamics | double | read | 1 | Double constant in dynamics constraint solver |
| DAT_008d3ae8 | DynSolverConst_3ae8 | dynamics | double | read | 1 | Double constant in dynamics constraint solver |
| DAT_008d1578 | DynSolverBlock_1578 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1578 |
| DAT_008d19b0 | DynSolverBlock_19b0 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D19B0 |
| DAT_008d1e38 | DynSolverBlock_1e38 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1E38 |
| DAT_008d17e8 | DynSolverBlock_17e8 | dynamics | double[] | offset | 1 | Dynamics solver workspace at 0x8D17E8 |
| DAT_008d1d78 | DynSolverBlock_1d78 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1D78 |
| DAT_008d1cb0 | DynSolverBlock_1cb0 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1CB0 |
| DAT_008d1e70 | DynSolverBlock_1e70 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D1E70 |
| DAT_008d2038 | DynSolverBlock_2038 | dynamics | double[] | read | 1 | Dynamics solver workspace at 0x8D2038 |
| DAT_008d2298 | DynSolverBlock_2298 | dynamics | double[] | offset | 1 | Dynamics solver workspace at 0x8D2298 in sub_575BBD (13241-byte LDL^T factorization). Part of block-sparse Cholesky factor workspace |
| DAT_008d2668 | DynSolverBlock_2668 | dynamics | double[] | offset | 1 | Dynamics solver workspace at 0x8D2668 in sub_575BBD (LDL^T factor). Part of sparse matrix factor storage |
| DAT_008d2948 | DynSolverFactorOut | dynamics | double | write | 1 | Factorization output written in sub_575BBD. Stores computed LDL^T factor element |
| DAT_008d2e48 | DynSolverFactorOut2 | dynamics | double | write | 1 | Factorization output written in sub_575BBD |
| DAT_008d3078 | DynSolverFactorConst | dynamics | double | read | 1 | Factorization constant read in sub_575BBD |
| DAT_005bb2e0 | RuntimeEHData | runtime | struct | offset | 1 | Exception handling data structure used in FUN_00579fb0. Part of MSVC runtime EH table |
| DAT_005e538c | off_5E538C | network | ptr | read | 1 | Network function pointer table reference in FUN_0057bf00 |
| DAT_005e542c | TimedOutString | network | string offset | offset | 1 | "Timed Out" string — network timeout, used in FUN_0057cb50 |
| DAT_005e5a58 | TheSocketIsNotString | network | string offset | offset | 1 | "The Socket Is Not" string — socket error, used in FUN_0057d400 |
| DAT_005e624c | WsaetimedoutString | network | string offset | offset | 1 | "WSAETIMEDOUT" string — Winsock error, used in FUN_0057d6c0 |
| DAT_005bae04 | MemoryPoolCleanup | memory | struct | offset | 1 | Memory pool data structure in FUN_00582650 — linked list cleanup with destructor dispatch |
| DAT_005e6388 | CRTInitByte | crt | byte | read | 1 | CRT initialization byte read in FUN_00584230 |
| DAT_005e63b8 | FPUExceptionHandler | crt | ptr | offset | 1 | FPU exception handler dispatch table in FUN_00588212 (467-byte MSVC FPU helper). Handles FPU status word and exception routing |
| DAT_008d3e6a | SystemTimeStore | runtime | short[6] | read | 1 | Six shorts storing current system time: year, month, dayOfWeek, day, hour, minute in FUN_005896ee. Updated by GetLocalTime/GetSystemTime calls |
| DAT_008d3e7c | OSVersion_Major | runtime | int | write | 1 | Windows OS version major number extracted from GetVersion() in FUN_0058a19e. Paired with DAT_008d3e80 (minor), DAT_008d3e78 (combined), DAT_008d3e74 (build) |
| DAT_005e6be4 | CRTFPUHelper | crt | ptr | read | 1 | CRT FPU helper function pointer used in FUN_0058d04d |
| DAT_005e6d50 | FormatStrWide | crt | string offset | offset | 1 | Wide format specifier string used in FUN_0058e4d2 (2597-byte MSVC printf-family implementation) |
| DAT_008d3f80 | CodePageInfo | runtime | short | read | 1 | Code page info parameter for GetCPInfo in FUN_0058f939 (581-byte CRT locale init). Used to determine lead byte ranges for multi-byte character sets |
| DAT_005b94f0 | FPUFscaleConstNeg | crt | double | read | 1 | FPU fscale negative scaling constant in FUN_0059070a (305-byte MSVC math helper). When FPU status word has 0x7ff0 exponent, scales by this value |
| DAT_005e77e8 | TimeZoneName2 | runtime | ptr | read | 1 | Pointer to time zone display name string (DST name). Written by WideCharToMultiByte in FUN_005921f3 (647-byte CRT timezone init). Holds daylight time zone name |
| DAT_008d3e88 | CmdLineArgv | runtime | ptr | write | 1 | Command-line argument argv array pointer written in FUN_00592bad. Allocated via _malloc with size from FUN_00592c46 |
| DAT_005b99a0 | CRTEHFrame | crt | struct | offset | 1 | CRT exception handling frame data used in FUN_00593cfd. Part of MSVC EH chain |
| DAT_008d41e0 | LocaleModulePtr | runtime | ptr | write | 1 | Locale module handle pointer written in FUN_00597234. CRT locale initialization |
| DAT_005bb3b0 | CRTTerminateHandler | crt | struct | offset | 1 | CRT terminate handler data structure in FUN_00598b5d. Part of terminate/exception handling vtable |
| DAT_005bb710 | CRTExceptionVTable | crt | struct | offset | 1 | CRT exception class vtable reference in FUN_0059a781. Part of C++ exception type hierarchy |
| DAT_005bb9f0 | CRTExceptionVTable2 | crt | struct | offset | 1 | CRT exception vtable for FUN_0059afc2 (61-byte exception destructor). Part of C++ EH type info |
| DAT_005bd120 | IsdebuggerpresString | anti-debug | string offset | offset | 1 | "IsDebuggerPresent" string — anti-debug API name, used at 0x008d8000 |
