=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005BE634 | StringTablePtr | data | const char** | offset | 1 | string table pointer at off_5BE634, used in FUN_00402690 |
| DAT_005BE528 | s_IntermediateFormat | string | char* | offset | 1 | "Intermed" string at aIntermediatefo_0, used in FUN_00402690 |
| DAT_005BE4B4 | s_WpEvent | string | char* | offset | 1 | "wpEvent" string at aWpEvent, used in FUN_00402690 |
| DAT_005BE84C | s_FormatPercentS | string | char* | offset | 1 | "%s" format string at aSD_1, used in FUN_00406790 |
| DAT_007CFE54 | Unknown_VehicleState | game_logic | uint | read | 1 | dword_7CFE54, vehicle physics state counter read in FUN_0040ca30 with VehicleCount loop, accessed via DAT_007c54e0+0x58/0x5c offsets |
| DAT_005BEA30 | s_Iterations | string | char* | offset | 1 | "Iterations" string at aIterations, used in FUN_0040d4c0 |
| DAT_0059E700 | UIRingBufferTimeConst | renderer | float | read | 1 | flt_59E700, float time constant used in UI/display code with DAT_008aae64 ring buffer |
| DAT_005EA5E0 | InitGateFlag | game_logic | byte | read | 1 | byte_5EA5E0, bitfield gate flag tested with & 1 for one-time init gating in FUN_00411840 |
| DAT_005C23CC | UnknownDataPtr_5C23CC | unknown | void* | offset | 1 | off_5C23CC, data pointer used in FUN_00414a90, purpose unclear |
| DAT_005C251C | s_DriverNameKimiR | string | char* | offset | 1 | "Kimi R" driver name string at aKimiR, used in FUN_00415d90 driver name table |
| DAT_005C2444 | s_DriverNameJohnnyH | string | char* | offset | 1 | "Johnny H" driver name string at aJohnnyH, used in FUN_00415d90 driver name table |
| DAT_005C293C | s_TeamName1999Prost | string | char* | offset | 1 | "1999 Prost" team name string at a1999Prost, used in FUN_0041b980 |
| DAT_005C2828 | s_TeamName2001Jordan | string | char* | offset | 1 | "2001 Jordan" team name string at a2001Jordan, used in FUN_0041b980 |
| DAT_005C2A8C | s_Audio | string | char* | offset | 1 | "Audio" config section string at aAudio, used in FUN_004216f0 |
| DAT_005C2D10 | s_ErrorCouldNotCreate | string | char* | offset | 1 | "Could not create" error string at aCouldNotCreate_0, used in FUN_00421cd0 |
| DAT_005C2BD8 | s_CpuRating | string | char* | offset | 1 | "cpurating" config key string at aCpurating, used in FUN_00421cd0 |
| DAT_005C2AE4 | s_VcrCycle | string | char* | offset | 1 | "vcrcycle" config key string at aVcrcycle, used in FUN_00421cd0 |
| DAT_005C2F28 | s_MusicDir | string | char* | offset | 1 | "musicdir" config key string at aMusicdirS, used in FUN_00422be0 |
| DAT_005C2DDC | s_AutoLaunch | string | char* | offset | 1 | "autolaunch" config key string at aAutolaunch_0, used in FUN_00422be0 |
| DAT_0059E858 | Unknown_FloatConst_59E858 | unknown | float | read | 1 | flt_59E858, float constant read in FUN_00424080, purpose unclear |
| DAT_0059E878 | AISpeedThreshold | physics_math | float | read | 1 | flt_59E878, AI vehicle speed comparison threshold used with DAT_008afea0 in FUN_00424e70 |
| DAT_005C3278 | s_FormatD | string | char* | offset | 1 | "%d" format string at aDD, used in FUN_00429960 |
| DAT_005C338C | s_DebugEnteredDynmanR | string | char* | offset | 1 | "Entered Dynman R" debug string at aEnteredDynmanR, used in FUN_0042c3b0 |
| DAT_007C9330 | UpdateLoopZeroState | game_logic | int | write | 1 | dword_7C9330, part of block 0x7C932C-0x7C9358 zeroed during game update loop in FUN_0042c690 |
| DAT_005C3510 | s_TestDay | string | char* | offset | 1 | "testday" config key string at aTestday, used in FUN_0042ce30 |
| DAT_005C3690 | s_DebugEnteredGamePos | string | char* | offset | 1 | "Entered Game Pos" debug string at aEnteredGamePos, used in FUN_0042da30 |
| DAT_005C3740 | UnknownDataByte_5C3740 | unknown | byte | offset | 1 | byte_5C3740, single data byte used in FUN_0042ed70, purpose unclear |
| DAT_005C3DD4 | s_FenderFlareSet | string | char* | offset | 1 | "FenderFlareSet" setup string at aFenderflareset_0, used in FUN_0042fd00 |
| DAT_005C3C24 | s_Front3rdSlowBump | string | char* | offset | 1 | "Front3rdSlowBu" setup string at aFront3rdslowbu_1, used in FUN_0042fd00 |
| DAT_005C3A28 | s_FinalDriveSetting | string | char* | offset | 1 | "FinalDriveSet" setup string at aFinaldrivesett, used in FUN_0042fd00 |
| DAT_005C3890 | s_BrakeDiscSetting | string | char* | offset | 1 | "BrakeDiscSetting" setup string at aBrakediscsetti_0, used in FUN_0042fd00 |
| DAT_0059EAA0 | Unknown_DoubleConst_59EAA0 | unknown | double | read | 1 | dbl_59EAA0, double constant read in FUN_00430f00, purpose unclear |
| DAT_005C3FAC | UnknownDataPtr_5C3FAC | unknown | void* | read | 1 | off_5C3FAC, data pointer read in FUN_00433890, purpose unclear |
| DAT_007CFB48 | CollisionForceClampFactor | collision | float | read | 1 | flt_7CFB48, multiplied against position diffs then clamped between min/max in collision/force code in FUN_00435e60 |
| DAT_005C4174 | s_SuspensionRLSpindle | string | char* | offset | 1 | "RL Spindle" suspension part string at aRlSpindle, used in FUN_00438da0 |
| DAT_005C4248 | s_ErrorCouldNotFindSub | string | char* | offset | 1 | "Could not find su" error string at aCouldNotFindSu, used in FUN_0043af50 |
| DAT_0059ECF8 | EngineThermalEnergyConst | physics_math | double | read | 1 | dbl_59ECF8, energy dissipation constant in engine thermal/damage model, compared against temperature values in FUN_0043ef20 |
| DAT_0059ED80 | TirePhysicsDoubleConst | physics_math | double | read | 1 | dbl_59ED80, double constant used in dynamics/tire physics in FUN_004423b0 |
| DAT_0059EE80 | TirePhysicsFloatConst | physics_math | float | read | 1 | flt_59EE80, float constant in large tire physics function FUN_004441f0 |
| DAT_0059EDE0 | TirePhysicsDoubleConst2 | physics_math | double | read | 1 | dbl_59EDE0, double constant in tire physics function FUN_004441f0 |
| DAT_0059EF28 | VehicleDynamicsDoubleConst | dynamics | double | read | 1 | dbl_59EF28, double constant in vehicle dynamics function FUN_00448730 |
| DAT_007CA3C4 | CollisionInitOne | collision | float | write | 1 | dword_7CA3C4, init to 1.0f (1065353216), part of collision system in FUN_0044cc34 |
| DAT_007CCD40 | CollisionZeroState | collision | int | write | 1 | dword_7CCD40, collision init state zeroed with block in FUN_0044d400 |
| DAT_005AD3F0 | RenderSetupDataPtr | renderer | void* | offset | 1 | unk_5AD3F0, data pointer used in render/setup function FUN_0044ee10 |
| DAT_007D223C | AudioFloatConstant | audio | float | read | 1 | flt_7D223C, float constant used in audio processing in FUN_0044ff50 |
| DAT_005AD3B0 | AudioRenderData | renderer | uint | read | 1 | dword_5AD3B0, data value used in audio/render function FUN_0044ff50 |
| DAT_0059EF70 | VehicleEffectFloatConst | physics_math | float | read | 1 | flt_59EF70, float constant in vehicle effect processing function FUN_00451720 |
| DAT_007CD108 | AudioSystemSingleton | audio | void* | read | 1 | dword_7CD108, audio system singleton pointer compared in object-type dispatch in FUN_00452810 |
| DAT_007CCCB4 | CollisionAngularVelX | collision | float | write | 1 | flt_7CCCB4, collision angular velocity X component written from param_1+0x1154 in FUN_004537b0 |
| DAT_007CA3BC | CollisionAngularVelY | collision | float | write | 1 | flt_7CA3BC, collision angular velocity Y component written in FUN_004537b0 |
| DAT_007CA430 | CollisionStateField | collision | uint | write | 1 | dword_7CA430, collision state field written in FUN_004537b0 |
| DAT_005C55C0 | s_TCOverride | string | char* | offset | 1 | "TC Override" control string at aTcOverride, used in FUN_00455290 |
| DAT_005C54AC | s_Horn | string | char* | offset | 1 | "Horn" control string at aHorn, used in FUN_00455290 |
| DAT_0059EFAC | ObjectConstructorVtable | unknown | void** | offset | 1 | off_59EFAC, vtable/function pointer table for object constructor in FUN_00456170 |
| DAT_005C5AA8 | s_MovementPath | string | char* | offset | 1 | "MovementPath" string at aMovementpath, used in FUN_00458190 |
| DAT_007C56AD | SessionFlagByte | game_logic | byte | write | 1 | byte_7C56AD, flag byte written in FUN_0045b200, located adjacent to SessionType at 0x007C56A4 |
| DAT_005C5C4C | s_FormatPingD | string | char* | offset | 1 | "ping_%d" format string at aPingD, used in FUN_0045d130 |
| DAT_005C5E48 | s_AutoChat02 | string | char* | offset | 1 | "AutoChat02" string at aAutochat02, used in FUN_0045ecd0 |
| DAT_005C5F94 | s_OK | string | char* | offset | 1 | "OK" button string at aOk, used in FUN_00460470 |
| DAT_007D0D1C | GameOptionConfigValue | game_logic | char | read | 1 | dword_7D0D1C, game option value read from config, stored as char with companion pointer in FUN_00461900 |
| DAT_007CE97F | TireModelOptionByte | game_logic | byte | read | 1 | byte_7CE97F, companion byte for tire model mode option, read alongside DAT_007d0d1c in FUN_00461900 |
| DAT_007C9530 | DriverTeamIndexTableEnd | data | void* | offset | 1 | unk_7C9530, end sentinel for DriverTeamIndexTable array in FUN_00462a10 |
| DAT_005C6458 | s_DebugSettingGameName | string | char* | offset | 1 | "Setting Game Nam" debug string at aSettingGameNam, used in FUN_00463160 |
| DAT_007D099C | FFBForceNegativeMin | game_logic | int | read | 1 | dword_7D099C, negative minimum limit for force feedback/steering option in FUN_00463ef0 |
| DAT_005C6734 | s_CreditsTxt | string | char* | offset | 1 | "credits.txt" filename at aCreditsTxt, used in FUN_00467e40 |
| DAT_007D2DE0 | UIStateVar | game_logic | int | read | 1 | dword_7D2DE0, game state/UI state variable read in FUN_0046a560 |
| DAT_005C6D48 | s_DebugJoinFailurePage | string | char* | offset | 1 | "Join Failure Pag" debug string at aJoinFailurePag, used in FUN_0046de10 |
| DAT_005A4428 | VtablePtr_5A4428 | unknown | void** | offset | 1 | off_5A4428, vtable pointer for object constructor in FUN_00476030 |
| DAT_007D17A8 | SuspensionFloatArrayEnd | dynamics | void* | offset | 1 | unk_7D17A8, end sentinel for suspension float array used as loop bound in FUN_0047a080 |
| DAT_005C73C4 | s_DriversChampion | string | char* | offset | 1 | "Drivers Champion" menu string at aDriversChampio, used in FUN_0047dd10 |
| DAT_005A6DC8 | VtablePtr_5A6DC8 | unknown | void** | offset | 1 | off_5A6DC8, vtable pointer used in FUN_0047f080 |
| DAT_005CC5CC | s_OptionsScreens | string | char* | offset | 1 | "Options Screens" string at aOptionsScreens, used in FUN_00492160 |
| DAT_005CC708 | s_WidthHeight | string | char* | offset | 1 | "WidthHeight" string at aWidthHeight, used in FUN_00492a40 |
| DAT_005CC8EC | s_DoPageTransition | string | char* | offset | 1 | "DoPageTransiti" string at aDoPageTransiti, used in FUN_00493480 |
| DAT_005CC948 | s_FormatOSCSOnLineD | string | char* | offset | 1 | "OSC %%s on line %%d" format string at aOscSOnLineD, used in FUN_00493c80 |
| DAT_005CCA20 | s_CurrentPage | string | char* | offset | 1 | "CurrentPage" string at aCurrentPage, used in FUN_00496880 |
| DAT_007CE150 | ScoringDataStruct | game_logic | void* | offset | 1 | unk_7CE150, scoring/points data structure referenced in FUN_0049afe0 |
| DAT_005CCE88 | s_FormatD_5CCE88 | string | char* | offset | 1 | "%d" format string at aD_2, used in FUN_0049c670 |
| DAT_005CCB9C | FileDataPtr_5CCB9C | unknown | void* | read | 1 | off_5CCB9C, file/data pointer read in FUN_0049ca00 |
| DAT_007C87E4 | VehiclePhysicsDoubleConst | physics_math | double | read | 1 | dbl_7C87E4, double constant used in vehicle physics in FUN_0049db80 |
| DAT_005CCFCC | s_FormatDMs | string | char* | offset | 1 | "d %%dms" format string at aDMs, used in FUN_0049f870 |
| DAT_007CE29C | SessionInitState | game_logic | int | write | 1 | dword_7CE29C, session init state written in FUN_004a1200 |
| DAT_005CD0B4 | s_Name | string | char* | offset | 1 | "Name" string at aName, used in FUN_004a18d0 |
| DAT_005CD244 | s_Pit10secLollipop | string | char* | offset | 1 | "10sec Lollipop U" pit animation string at a10secLollipopU, used in FUN_004a24d0 |
| DAT_005CD3F8 | s_RFWheelOffMTS | string | char* | offset | 1 | "RFWheelOff MTS" pit animation string at aRfwheeloffMts, used in FUN_004a2a90 |
| DAT_005ACB40 | PitStopTimeoutMultiplier | game_logic | float | read | 1 | flt_5ACB40, multiplier for pit stop timeout calculation (SessionType-dependent) in FUN_004a4110 |
| DAT_005CD554 | s_PitCrewNormal0 | string | char* | offset | 1 | "PitCrewNormal0" pit crew string at aPitcrewnormal0, used in FUN_004a4900 |
| DAT_005ACB60 | PitRepairThreshold | game_logic | float | read | 1 | flt_5ACB60, float threshold used in pit/repair logic in FUN_004a68b0 |
| DAT_005D1FC0 | s_SceneDescription | string | char* | offset | 1 | "Scene Description" config key at aSceneDescripti, used in FUN_004aa270 |
| DAT_005D1DC8 | s_WhenOutOfFuel | string | char* | offset | 1 | "When Out Of Fuel" config key at aWhenOutOfFuelI, used in FUN_004aa270 |
| DAT_005D1A80 | s_TelemetryRate | string | char* | offset | 1 | "TelemetryRate" config key at aTelemetryRate, used in FUN_004aa270 |
| DAT_005D1850 | s_TimeThatPitsRemain | string | char* | offset | 1 | "Time That Pits" config key at aTimeThatPitsRe, used in FUN_004aa270 |
| DAT_005D1638 | s_TrackLoad | string | char* | offset | 1 | "Track Load" config key at aTrackLoadComme, used in FUN_004aa270 |
| DAT_005D1424 | s_CrowdShape | string | char* | offset | 1 | "CrowdShape" config key at aCrowdShape, used in FUN_004aa270 |
| DAT_005D129C | s_RearviewWidth | string | char* | offset | 1 | "RearviewWidth" config key at aRearviewWidth, used in FUN_004aa270 |
| DAT_005D10BC | LightningProbability | setup/UI | char* | read | 1 | "LightningProbability" config key string |
| DAT_005D0DBC | RaindropFlow | setup/UI | char* | read | 1 | "RaindropFlow" config key string |
| DAT_005D0AA0 | TrackDetail | setup/UI | char* | read | 1 | "TrackDetail" config key string |
| DAT_005D0910 | PlayerLivery | setup/UI | char* | read | 1 | "PlayerLivery" config key string |
| DAT_005D0648 | DamageMultiplier | setup/UI | char* | read | 1 | "DamageMultiplier" config key string |
| DAT_005D03B0 | AiBrakeGripUsage | setup/UI | char* | read | 1 | "AiBrakeGripUsage" config key string |
| DAT_005D00D0 | AiRealism | setup/UI | char* | read | 1 | "AiRealism" config key string |
| DAT_005CFEE0 | SecondsUntilStart | setup/UI | char* | read | 1 | "SecondsUntilStart" config key string |
| DAT_005CFB80 | LanInternetOption | setup/UI | char* | read | 1 | "0LAN1Internet" config key string |
| DAT_005CF768 | RangeIs1025655 | setup/UI | char* | read | 1 | "RangeIs1025655" config key string |
| DAT_005CF3A8 | ServerSessionEnabled | setup/UI | char* | read | 1 | "ServerSessionEnabled" config key string |
| DAT_005CF094 | KeyboardSteering | setup/UI | char* | read | 1 | "KeyboardSteering" config key string |
| DAT_005CEC3C | OptionsNumControllers | setup/UI | char* | read | 1 | "OptionsNumControllers" config key string |
| DAT_005CEA90 | SteeringDeadzone | setup/UI | char* | read | 1 | "00Min05Center1" config key string (steering deadzone range) |
| DAT_005CE8C4 | ControlPitMenu | setup/UI | char* | read | 1 | "ControlPitMenu" config key string |
| DAT_005CE6F8 | ControlHandbrake | setup/UI | char* | read | 1 | "ControlHandbrake" config key string |
| DAT_005CE35C | FFBSteerVibeSlope | setup/UI | char* | read | 1 | "FFBSteerVibeSlope" config key string |
| DAT_005CDE64 | FFBSteerDamper | setup/UI | char* | read | 1 | "FFBSteerDamper" config key string |
| DAT_005CDA68 | FFBBrakeVibeUp | setup/UI | char* | read | 1 | "FFBBrakeVibeUp" config key string |
| DAT_005D1FEC | PathConcatBuffer | string | char | read | 1 | byte buffer for string path concatenation in FUN_004b02b0 |
| DAT_005ACC88 | ColorConvClampLower | renderer | float | read | 1 | float-to-int color conversion clamp range lower bound in FUN_004b21f0 |
| DAT_005D240C | ScreenSavedString | setup/UI | char* | read | 1 | "ScreenSaved" string constant |
| DAT_005ACD68 | UIScrollRange | renderer | float | read | 1 | UI scroll/range offset value in FUN_004b9510 |
| DAT_005D2554 | FormatPctS | data | char* | read | 1 | "%s" format string constant |
| DAT_005D2604 | DebugSourcePath_F1C | unknown | char* | read | 1 | debug source path string "D:\dev\F1_1999_2002\Source\..." |
| DAT_005ACDBC | UnknownRenderFloat_5ACDBC | unknown | float | read | 1 | float constant in FUN_004bf6a0 |
| DAT_005D2780 | PointsPositionFormat | game | char* | read | 1 | "PointsPosition_%d" format string for UI points display |
| DAT_007D0A24 | UIOptionRestoreValue | game | int | both | 1 | game option value restored on UI cleanup/destruct in FUN_004c2300 |
| DAT_005D2C40 | RaceCondTimeScaleString | setup/UI | char* | read | 1 | "RaceCondTimeScale" config key string |
| DAT_005D2FF0 | CameraTargetString | renderer | char* | read | 1 | "CameraTarget" string constant |
| DAT_005D2EB4 | TimeFormat4s50s | data | char* | read | 1 | "4s,50s" time format display string |
| DAT_005ACE0C | SessionDynamicsConst | physics_math | float | read | 1 | session-type-dependent physics dynamics constant in FUN_004c7f30 |
| DAT_008AC4DC | RandSeedInitGate | game | byte | both | 1 | one-time init gate and counter for rand seeding in FUN_004c8ee0 |
| DAT_005D36C4 | WhiteSmokeString | data | char* | read | 1 | "WhiteSmoke" color string constant |
| DAT_005D35C0 | RampSpeedString | setup/UI | char* | read | 1 | "RampSpeed" config key string |
| DAT_005D34E8 | MTSFileString | setup/UI | char* | read | 1 | "MTSFile" config/file key string |
| DAT_007CF998 | Unknown_7CF998 | unknown | int | read | 1 | unknown global referenced in FUN_004cb120 |
| DAT_005D38C8 | BumpWaveLenString | setup/UI | char* | read | 1 | "BumpWaveLen" config key string |
| DAT_005ACECC | ParticleEffectConst | renderer | float | read | 1 | float constant in FUN_004ce930 (particle/weather effects) |
| DAT_005D3B38 | CouldNotLoadCD | game | char* | read | 1 | "Could not load CD" error message string |
| DAT_005D3BCC | TimeFormat02d02d | data | char* | read | 1 | "%02d:%02d" time format string constant |
| DAT_005D4114 | GameFormatString | setup/UI | char* | read | 1 | "Game.%" window class/format string |
| DAT_005D3F68 | DriveAidsAutopString | setup/UI | char* | read | 1 | "DriveAids Autop" UI string constant |
| DAT_005D3D84 | FormatDDD | data | char* | read | 1 | "%d%d%d" format string constant |
| DAT_007CEBF4 | SessionRaceState | game | int | read | 1 | session/race state flag in FUN_004d2e50 |
| DAT_005D4250 | XSector1String | physics_math | char* | read | 1 | "XSector1" sector string constant |
| DAT_005D430C | PreRacePresentationString | game | char* | read | 1 | "PreRacePresentation" string constant |
| DAT_005D4510 | UnfilteredThrottle | game | char* | read | 1 | "UnfilteredThrottle" telemetry/log key string |
| DAT_005D43EC | WaterTemperature | game | char* | read | 1 | "WaterTemperature" telemetry/log key string |
| DAT_005D484C | TireWetLatLong | physics_math | char* | read | 1 | "WetLatLong" tire string constant |
| DAT_005D476C | TireOptimumTemp | physics_math | char* | read | 1 | "OptimumTemp" tire string constant |
| DAT_005D4A30 | NoTraceDebug | game | char* | read | 1 | "NoTrace" debug string constant |
| DAT_005ACF40 | UIQuadDrawMultiplier | renderer | float | read | 1 | float multiplier for UI quad drawing in FUN_004d90d0 |
| DAT_005AD0A4 | Vtable_5AD0A4 | renderer | void* | read | 1 | vtable pointer |
| DAT_005D4C44 | PitHelmetString | renderer | char* | read | 1 | "PitHelmet" string constant for pit helmet rendering |
| DAT_005D4CC4 | DashHighString | renderer | char* | read | 1 | "DashHigh" string constant for dashboard high element |
| DAT_005D4D4C | BrakeLightString | renderer | char* | read | 1 | "BrakeLight" string constant for brake light rendering |
| DAT_007C9318 | VehicleOrientationBlock | dynamics | float | write | 1 | part of zeroed block 0x7C9318-0x7C9358 in vehicle orientation init FUN_004e49b0 |
| DAT_005AD1C8 | VehiclePosCompareThreshold | dynamics | double | read | 1 | double threshold for vehicle position comparison in FUN_004e96c0 |
| DAT_007CC75C | TireDynamicsState | dynamics | int | read | 1 | collision/vehicle state for tire dynamics in FUN_004f0430 |
| DAT_005D4FF4 | AeroDivString | physics_math | char* | read | 1 | "AeroDiv" aero setup string constant |
| DAT_005D4EB8 | PartDPosString | physics_math | char* | read | 1 | "PartDPos" part position string constant |
| DAT_005D51CC | BrakeDuctCoolingString | physics_math | char* | read | 1 | "BrakeDuctCooling" setup string constant |
| DAT_005D5098 | SlowReboundRangeString | physics_math | char* | read | 1 | "SlowReboundRange" suspension setup string |
| DAT_005D5508 | RevLimitRangeString | physics_math | char* | read | 1 | "RevLimitRange" engine setup string |
| DAT_005D55F0 | LifetimeOilTempRangeString | physics_math | char* | read | 1 | "LifetimeOilTempRange" engine setup string |
| DAT_005D671C | SymmetricString | physics_math | char* | read | 1 | "Symmetric" differential setup string |
| DAT_005D65FC | AIEvenSuspensionString | physics_math | char* | read | 1 | "AIEvenSuspension" AI setup string |
| DAT_005D64D0 | NumPitStopsRangeString | physics_math | char* | read | 1 | "NumPitStopsRange" strategy setup string |
| DAT_005D63D4 | FWCenterString | physics_math | char* | read | 1 | "FWCenter" front wing setup string |
| DAT_005D62F0 | BodyDragBaseString | physics_math | char* | read | 1 | "BodyDragBase" aero setup string |
| DAT_005D61D4 | DiffuserString | physics_math | char* | read | 1 | "Diffuser" aero setup string |
| DAT_005D6078 | Front3rdBumpTravelString | physics_math | char* | read | 1 | "Front3rdBumpTravel" suspension setup string |
| DAT_005D5E9C | FrontToeInSettingString | physics_math | char* | read | 1 | "FrontToeInSetting" steering geometry setup string |
| DAT_005D5CF8 | Front3rdSlowBumpString | physics_math | char* | read | 1 | "Front3rdSlowBump" suspension setup string |
| DAT_005D5B14 | ControlsString | physics_math | char* | read | 1 | "Controls" setup section string |
| DAT_005D59C4 | DrivelineString | physics_math | char* | read | 1 | "Driveline" setup section string |
| DAT_005D588F | Gear2SettingString | physics_math | char* | read | 1 | "Gear2Setting" gear ratio setup string |
| DAT_005D5754 | DownforceString | physics_math | char* | read | 1 | "Downforce" setup section string |
| DAT_005D6770 | VsInsideString | physics_math | char* | read | 1 | "VsInside" differential setup string |
| DAT_005D6B7C | OtherAmbientString | renderer | char* | read | 1 | "OtherAmbient" renderer/lighting string |
| DAT_005D69EB | UnknownString_5D69EB | unknown | char* | read | 1 | unknown string constant (no IDA name) |
| DAT_005D684B | UnknownString_5D684B | unknown | char* | read | 1 | unknown string constant (no IDA name) |
| DAT_005EC4A6 | PlayerFileSuffixChar | game | char | read | 1 | player file path suffix character in FUN_004f9480 |
| DAT_005AD270 | UnknownFloat_5AD270 | unknown | float | read | 1 | float constant in FUN_004f9480 |
| DAT_005AD280 | LineIntersectionThreshold | collision | double | read | 1 | double threshold for 2D line intersection test in FUN_004fb2e0 |
| DAT_008ACFB0 | RaceTimingConstant | game | float | read | 1 | race timing constant in FUN_004fcee0 |
| DAT_005AD2DC | SteeringPerturbThreshold | dynamics | float | read | 1 | random steering perturbation threshold in FUN_004fd8b0 |
| DAT_005C7234 | DataPtr_5C7234 | unknown | void* | read | 1 | data pointer |
| DAT_005D70F8 | FormatPctS_2 | data | char* | read | 1 | "%s" format string constant |
| DAT_005AD350 | ThrottleBrakeInputClamp | game | float | read | 1 | throttle/brake input filter clamp value in FUN_004ff680 |
| DAT_005BA4EC | ZlibInflateState | unknown | struct | both | 1 | data structure (likely zlib inflate state for network/compression) |
| DAT_005ADC10 | VertexColorMatrixCoeff | renderer | float | read | 1 | vertex color transform matrix coefficient in FUN_0050a92d |
| DAT_005ADCCC | Vtable_5ADCCC | renderer | void* | read | 1 | vtable pointer |
| DAT_005ADDFC | Vtable_5ADDFC | renderer | void* | read | 1 | vtable pointer |
| DAT_005d7840 | FuncPtrTable_5D7840 | render | void*[] | read | 1 | Function pointer table called through in FUN_0050d563 |
| DAT_005d7998 | RenderStateValue_5D7998 | render | int | both | 1 | State value written in FUN_0050fea7 |
| DAT_005af3cc | aInvalidAttempt | string | char* | read | 1 | "Invalid attempt" error string |
| DAT_005af56c | SplineCoeffTable_5AF56C | math | float[] | read | 1 | Spline/curve coefficient data table in FUN_00513f7a (math interpolation) |
| DAT_005afa60 | aInvalidWindowS | string | char* | read | 1 | "Invalid window size" error string |
| DAT_005afc9c | aInvalidPalette | string | char* | read | 1 | "Invalid palette" error string |
| DAT_005afed8 | aDuplicateTrnsC | string | char* | read | 1 | "Duplicate trans col" error string |
| DAT_008d6000 | SIMD_NormalizeConstants | math | float[3] | read | 1 | SIMD vector normalization constant block (threshold, scale, coeff) in FUN_0051edae |
| DAT_005d8bc0 | SSE_Bitmask_5D8BC0 | math | int[4] | read | 1 | SSE bitmask in FUN_0051fb1e (SIMD math) |
| DAT_008d6128 | SIMD_EigenvectorConst | math | float | read | 1 | SIMD 3x3 eigenvector computation constant in FUN_0051fd90 |
| DAT_005d8c50 | SSE_CrossProductConst | math | int[4] | read | 1 | SSE constant in FUN_0052098e (SIMD cross product / normal computation) |
| DAT_008d6298 | SIMD_EigenvalueConst | math | float | read | 1 | SIMD 3x3 eigenvalue computation constant in FUN_00520ce0 |
| DAT_005b0818 | TexColorTransformConst | render | float | read | 1 | Float in FUN_005285f2 (renderer/texture color transform) |
| DAT_005d90e0 | SSE_Const_5D90E0 | math | int[4] | read | 1 | SSE constant (referenced but empty function) |
| DAT_005d9388 | MMX_RecipApproxCoeff | math | int | read | 1 | MMX/3DNow! polynomial coefficient for reciprocal/square root approximation in FUN_00528f00 |
| DAT_005b0a8c | aOversubscribed | string | char* | read | 1 | "Over-subscribed" error string (memory allocation) |
| DAT_005b0c08 | MMX_PackedConst_5B0C08 | math | int[2] | read | 1 | 64-bit packed math constant in FUN_0052ab4e (MMX/3DNow! matrix multiply) |
| DAT_005b0c70 | MMX_PackedConst_5B0C70 | math | int[2] | read | 1 | 64-bit packed math constant in FUN_0052b561 (MMX/3DNow! matrix multiply) |
| DAT_005b47a8 | TexDecodeConstant | render | int | read | 1 | Integer constant in FUN_0052e6f0 (renderer/texture decode) |
| DAT_008b59a0 | DCT_Coefficient_8B59A0 | math | float | read | 1 | DCT/IDCT coefficient in FUN_00531b50 (image transform: JPEG-like DCT) |
| DAT_005b7748 | DCT_Coefficient_5B7748 | math | float | read | 1 | DCT coefficient in FUN_00531b50 |
| DAT_008b595c | DCT_Output_8B595C | math | float | write | 1 | DCT coefficient write target in FUN_00531b50 |
| DAT_008b59b8 | DCT_Output_8B59B8 | math | float | write | 1 | DCT coefficient write target in FUN_00531b50 |
| DAT_008b5a04 | DCT_Output_8B5A04 | math | float | write | 1 | DCT coefficient write target in FUN_00531b50 |
| DAT_005da7b8 | aIncorrectDataC_0 | string | char* | read | 1 | "Incorrect data check" error string (zlib) |
| DAT_005b8280 | InflateState_5B8280 | data | void* | both | 1 | Huffman/data structure in FUN_005381f0 (zlib inflate state) |
| DAT_005db9a0 | RenderLightingTable | render | void*[] | read | 1 | Data table returned as pointer array in FUN_0053a630 (renderer/lighting) |
| DAT_005dbe0c | aShadowtex3d | string | char* | read | 1 | "ShadowTex3D" string |
| DAT_005dc050 | FuncPtrTable_5DC050 | render | void*[] | read | 1 | Function pointer table |
| DAT_008cef70 | RenderFrameEndFlag | render | int | write | 1 | Renderer state flag, zeroed in FUN_00557120 (renderer frame end) |
| DAT_005dc364 | aColltarget | string | char* | read | 1 | "CollTarget" string |
| DAT_005dc414 | aDynamic | string | char* | read | 1 | "Dynamic" string |
| DAT_005dc5ac | RenderState_5DC5AC | render | int | both | 1 | Renderer state value in FUN_0055f0d0 |
| DAT_005dc568 | RenderState_5DC568 | render | int | both | 1 | Renderer state value in FUN_0055f0d0 |
| DAT_005dc504 | RenderState_5DC504 | render | int | both | 1 | Renderer state value in FUN_0055f0d0 |
| DAT_005dc4ac | RenderState_5DC4AC | render | int | both | 1 | Renderer state value in FUN_0055f0d0 |
| DAT_005dd84c | aShadowview3d | string | char* | read | 1 | "ShadowView3D" format string |
| DAT_005e4fd8 | aInfo2 | string | char* | read | 1 | "Info2" string |
| DAT_005e50e0 | aFFFFFF | string | char* | read | 1 | "FFFFFF" string |
| DAT_005e5230 | FuncPtrTable_5E5230 | unknown | void*[] | read | 1 | Function pointer table |
| DAT_005e5194 | aLpt9 | string | char* | read | 1 | "LPT9" string |
| DAT_005e52f0 | aAxis | string | char* | read | 1 | "Axis" string |
| DAT_008d00d8 | LDLT_Workspace_8D00D8 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 (block sparse LDL^T factorization) |
| DAT_008d0c40 | LDLT_Workspace_8D0C40 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d3a40 | LDLT_Workspace_8D3A40 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d399c | LDLT_IndexArray_8D399C | dynamics | int[] | both | 1 | Dynamics solver index array in FUN_0056fa96 |
| DAT_008d1160 | LDLT_Workspace_8D1160 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d0310 | LDLT_Workspace_8D0310 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d09b8 | LDLT_Workspace_8D09B8 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d0510 | LDLT_Workspace_8D0510 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d0818 | LDLT_Workspace_8D0818 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d2048 | LDLT_Workspace_8D2048 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d0920 | LDLT_Workspace_8D0920 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d0b80 | LDLT_Workspace_8D0B80 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1090 | LDLT_Workspace_8D1090 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1888 | LDLT_Workspace_8D1888 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d2080 | LDLT_Workspace_8D2080 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d2090 | LDLT_Workspace_8D2090 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d2098 | LDLT_Workspace_8D2098 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1fc8 | LDLT_Workspace_8D1FC8 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1328 | LDLT_Workspace_8D1328 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d16a8 | LDLT_Workspace_8D16A8 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1b98 | LDLT_Workspace_8D1B98 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1f18 | LDLT_Workspace_8D1F18 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1ac0 | LDLT_Workspace_8D1AC0 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1ad0 | LDLT_Workspace_8D1AD0 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1cc0 | LDLT_Workspace_8D1CC0 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d1f60 | LDLT_Workspace_8D1F60 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_0056fa96 |
| DAT_008d2248 | LDLT_FactorWorkspace_8D2248 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_00575bbd (13KB LDL^T factorization) |
| DAT_008d2578 | LDLT_FactorWorkspace_8D2578 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_00575bbd |
| DAT_008d28a8 | LDLT_FactorWorkspace_8D28A8 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_00575bbd |
| DAT_008d2e80 | LDLT_FactorWorkspace_8D2E80 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_00575bbd |
| DAT_008d3070 | LDLT_FactorWorkspace_8D3070 | dynamics | double[] | both | 1 | Dynamics solver matrix workspace in FUN_00575bbd |
| DAT_008d3980 | DynConstraintBlockSelector | dynamics | void* | read | 1 | Dynamics constraint block base pointer selector in FUN_00579f89 |
| DAT_005e537c | FuncPtrTable_5E537C | unknown | void*[] | read | 1 | Function pointer table |
| DAT_005e5448 | aShutdown | string | char* | read | 1 | "Shutdown" string |
| DAT_005e5b60 | aTheRequestedAd | network | char* | read | 1 | "The requested address" error string (Winsock) |
| DAT_005e6280 | aWsaeconnreset | network | char* | read | 1 | "WSAECONNRESET" error string (Winsock) |
| DAT_005bad70 | FileThreadCleanupData | runtime | void* | both | 1 | Data structure in FUN_00582190 (file/thread cleanup) |
| DAT_005e638c | aUnknownNode | string | char* | read | 1 | "Unknown node" error string |
| DAT_008d3e3c | ExceptionHandlerData | runtime | void* | both | 1 | Data structure in FUN_00587a90 (exception handling) |
| DAT_005e6540 | aAcos | string | char* | read | 1 | "acos" math error string |
| DAT_005be3e8 | TerminateHandlerData | runtime | void* | both | 1 | Exception/terminate handler data in FUN_00589cc6 |
| DAT_005b8d58 | aIsprocessorfea | string | char* | read | 1 | "IsProcessorFeaturePresent" string (CPUID) |
| DAT_005e7810 | VtablePtr_5E7810 | runtime | void* | write | 1 | Vtable/function table pointer assigned in FUN_0058e0b4 |
| DAT_005e9a94 | AllocLinkedListPtr | runtime | void* | both | 1 | Linked list pointer in FUN_0058f6fe (memory allocator) |
| DAT_005b94f8 | CRT_MathExceptionConst | runtime | double | read | 1 | Double constant in FUN_0059070a (MSVC CRT math exception handler) |
| DAT_008d4070 | TimezoneDSTBias | runtime | int | both | 1 | Timezone DST bias in FUN_005921f3 (CRT timezone init) |
| DAT_008d4080 | DateTimeStructBase | runtime | void* | both | 1 | Date/time struct base in FUN_00592787 (CRT date computation) |
| DAT_005b9968 | CRT_ExceptionStruct_5B9968 | runtime | void* | both | 1 | Exception handling structure in FUN_005939f9 (CRT) |
| DAT_005b9b1c | aGetactivewindo | string | char* | read | 1 | "GetActiveWindow" string (CRT/assert) |
| DAT_005bb338 | CXX_ExceptionStruct_5BB338 | runtime | void* | both | 1 | C++ exception handling structure in FUN_005989d7 |
| DAT_005bb6a0 | CXX_ExceptionStruct_5BB6A0 | runtime | void* | both | 1 | C++ exception handling structure in FUN_0059a69a |
| DAT_005bb960 | CXX_ExceptionStruct_5BB960 | runtime | void* | both | 1 | C++ exception handling structure in FUN_0059aeda |
| DAT_005bd100 | aSteeringwheelD | string | char* | read | 1 | "SteeringWheelDescription" string |
