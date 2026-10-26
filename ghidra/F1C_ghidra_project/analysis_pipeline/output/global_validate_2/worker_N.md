=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be638 | IntermediateFolderNamePtr | setup | ptr | offset | 1 | pointer to intermediate folder name string, used by FUN_00402690 |
| DAT_005be540 | IntermediateFolderName | setup | string | offset | 1 | "IntermediateFolderName" string literal for config parsing |
| DAT_005be4c0 | WpPath | setup | string | offset | 1 | "WpPath" string literal for waypoint path config |
| DAT_0059e4b4 | VTable_0059e490_Swap | setup | ptr | offset | 1 | vtable pointer table entry swapped during FUN_004058a0 lifecycle |
| DAT_005be980 | EnteredCamManReset | UI | string | offset | 1 | "EnteredCamManReset" format string for camera manager debug |
| DAT_005bea3c | Time | UI | string | offset | 1 | "Time" string literal for UI time display |
| DAT_0059e704 | RaceGrid_TeamID | game_logic | int | read | 1 | TeamID selector for race grid display, read via VehiclePtrArray +0x4894 |
| DAT_005bf8e0 | Ptr_s_Audio_Commentary_Pws | audio | ptr | offset | 1 | pointer to "Audio_Commentary_Pws" string for audio commentary system, param_1==0 path |
| DAT_005c23d0 | UnknownSetup_5C23D0 | setup | ptr | offset | 1 | unknown offset pointer used by FUN_00414a90 |
| DAT_005c2524 | NickH | setup | string | offset | 1 | "NickH" driver name string (Nick Heidfeld) |
| DAT_005c2450 | DamonH | setup | string | offset | 1 | "DamonH" driver name string (Damon Hill) |
| DAT_005c2948 | Year1999_Minardi | setup | string | offset | 1 | "1999Minardi" year-team folder name string |
| DAT_005c2834 | Year2001_Jaguar | setup | string | offset | 1 | "2001Jaguar" year-team folder name string |
| DAT_005c2a94 | SeasonData | setup | string | offset | 1 | "seasondata" INI section key string |
| DAT_005c2d34 | DevPath_F119992002 | setup | string | offset | 1 | "D:\dev\F1_1999_2002\Source" development path string |
| DAT_005c2be4 | GridSize | setup | string | offset | 1 | "GridSize" INI key string |
| DAT_005c2af0 | LaunchTime | setup | string | offset | 1 | "LaunchTime" INI key string |
| DAT_005c2f38 | SaveDirS | setup | string | offset | 1 | "SaveDir=%s" format string for save directory |
| DAT_005c2dec | InstallToS | setup | string | offset | 1 | "InstallTo=%s" format string for install path |
| DAT_005c321c | QualifyingAbility | setup | string | offset | 1 | "QualifyingAbility" INI key string for AI driver data |
| DAT_005ea3e4 | RaceAbility_HighRange | ai_db | float | read | 1 | AI race ability scale factor for difficulty>100 (high range slope) |
| DAT_005c3284 | PitStopStrategy | setup | string | offset | 1 | "PitStopStrategy" INI key string |
| DAT_0059e9d0 | Flt_59E9D0_Race | race | float | read | 1 | race-related float constant, read by FUN_0042c1a0 |
| DAT_007c932c | RaceScoring_ClearFlags_0 | steward | int | write | 1 | zeroed race scoring flag array entry 0, part of 12-entry block cleared at tick intervals |
| DAT_005c3518 | Practice4 | setup | string | offset | 1 | "Practice4" session name string |
| DAT_005c3670 | NextStateDWasN | game | string | offset | 1 | "Next state %d was %d" debug format string |
| DAT_005c3744 | Off_5C3744_VTable | game | ptr | offset | 1 | vtable pointer, used by FUN_0042ed70 |
| DAT_005c3dec | LeftFender | setup | string | offset | 1 | "LeftFender" INI key for vehicle setup |
| DAT_005c3c40 | Front3rdSpring | setup | string | offset | 1 | "Front3rdSpring" INI key for vehicle setup |
| DAT_005c3a40 | Driveline | setup | string | offset | 1 | "Driveline" INI key for vehicle setup |
| DAT_005c38a8 | FastReboundSet | setup | string | offset | 1 | "FastReboundSet" INI key for vehicle setup |
| DAT_005c3f38 | EstTopSpeed | setup | string | offset | 1 | "EstTopSpeed" INI key for estimated top speed |
| DAT_005c3fb0 | Off_5C3FB0_Sound | audio | ptr | read | 1 | sound-related pointer table, read by FUN_00433890 |
| DAT_005c4098 | SpringParams | setup | string | offset | 1 | "SpringParams" INI key for suspension |
| DAT_005c4180 | RLWheel | setup | string | offset | 1 | "RLWheel" INI key for rear-left wheel setup |
| DAT_0059eba8 | Dbl_59EBA8_Physics | physics | double | read | 1 | physics double constant, read by FUN_00439210 |
| DAT_0059ed00 | DampingFactor | dynamics | double | read | 1 | damping multiplier in vehicle dynamics, multiplied by ABS(suspension travel) |
| DAT_0059ed88 | TireBrush_Threshold | dynamics | double | read | 1 | tire brush model threshold constant, compared to friction values in tire model |
| DAT_0059ee84 | TireBrush_RollingResist | dynamics | float | read | 1 | tire rolling resistance coefficient, used in tire brush model |
| DAT_0059ede8 | TireBrush_LatForce | dynamics | double | read | 1 | lateral force multiplier in tire brush model |
| DAT_005c43b0 | Heli | audio | string | offset | 1 | "Heli" helicopter audio string |
| DAT_007cd114 | D3D_InitValue_1 | renderer | int | write | 1 | Direct3D initialization value 1065353216 (1.0f), paired with flt_7CD110 |
| DAT_007ccd3c | VideoMode_Index | renderer | int | write | 1 | video mode index counter, zeroed in init FUN_0044d400 |
| DAT_007ccd18 | VideoMode_Index_2 | renderer | int | write | 1 | second video mode index, zeroed in init FUN_0044d580 |
| DAT_005ad36c | Dword_5AD36C_Session | game | int | read | 1 | session state index used in game session logic |
| DAT_005ad3dc | Dword_5AD3DC_Session | game | int | read | 1 | second session state index used in game session logic |
| DAT_0059ef74 | PitCrew_FlagState | pit | float | read | 1 | pit crew flag state threshold, used in FUN_00451720 |
| DAT_007ccfdc | SoundBank_CCFDC | audio | ptr | read | 1 | sound bank entry pointer, matched in sound resource selector |
| DAT_007ca458 | SoundBank_CA458 | audio | ptr | read | 1 | sound bank entry pointer, matched in sound resource selector (type 1) |
| DAT_007cd074 | SoundBank_VolumeFL | audio | float | write | 1 | front-left speaker volume, written in FUN_004537b0 sound update |
| DAT_007ca55c | SoundBank_VolumeFL_Alt | audio | float | write | 1 | alternate front-left volume, written in FUN_004537b0 |
| DAT_005c55d4 | SeventhGear | setup | string | offset | 1 | "SeventhGear" INI key for gear ratios |
| DAT_005c54b4 | Starter | setup | string | offset | 1 | "Starter" INI key for engine starter |
| DAT_007cd1fc | RandomInit_Flag | game | byte | read | 1 | flag tracking if rand() has been initialized (0=needs init, 1=done) |
| DAT_005c5a70 | ControlPoint | setup | string | offset | 1 | "ControlPoint" string for track control points |
| DAT_007c56b4 | Session_SubState | game | int | offset | 1 | session sub-state variable near SessionType/RacePhase |
| DAT_005c5c54 | ScoreD | network | string | offset | 1 | "score_%d" format string for multiplayer scoring |
| DAT_005c5e54 | AutoChat01 | network | string | offset | 1 | "AutoChat01" string for auto chat messages |
| DAT_005c5f5c | MpClientGrid | network | string | offset | 1 | "MpClientGrid" string for multiplayer client grid |
| DAT_007d0d20 | Setup_MaxVehicles | setup | int | read | 1 | maximum vehicles config value, read via FUN_0047f1f0 |
| DAT_007ce97e | Setup_ExtraFlag2 | setup | byte | read | 1 | extra config flag byte near tire model and session settings |
| DAT_007cd270 | HudLayout_Default | UI | ptr | offset | 1 | default HUD layout data block, copied during 0x30-byte transfer |
| DAT_005c6474 | GameName | game | string | offset | 1 | "GameName" INI key string |
| DAT_007d0998 | RaceSession_MaxScore | steward | int | read | 1 | max score value used in session scoring logic |
| DAT_0059f4f8 | VTable_WindowManager | UI | ptr | offset | 1 | vtable pointer for window manager object |
| DAT_007d2dec | Dword_7D2DEC_Season | game | int | read | 1 | season-related counter/flag used in FUN_0046a560 |
| DAT_005c6c58 | ClientPassword | network | string | offset | 1 | "Client Password Entry" string literal for network UI |
| DAT_005c70f4 | Searching | network | string | offset | 1 | "Searching" string for network lobby |
| DAT_007cd717 | FileCopied_Flag | file | byte | write | 1 | flag byte set to 0 after file copy succeeds in sub_4793EC |
| DAT_005c73dc | DateOfBirth | setup | string | offset | 1 | "DateOfBirth" driver data field string |
| DAT_005a6d20 | VTable_47EFF0 | game | ptr | offset | 1 | vtable pointer set in FUN_0047eff0 init |
| DAT_005cc5e8 | InvalidOptions | UI | string | offset | 1 | "InvalidOptions" error string for options UI |
| DAT_005cc718 | VariableValue | UI | string | offset | 1 | "VariableValue" string for UI variable display |
| DAT_005cc908 | DoPage | UI | string | offset | 1 | "DoPage" string for UI paging logic |
| DAT_005cc960 | CriticalError | setup | string | offset | 1 | "CriticalError" error string literal |
| DAT_00888888 | D3D_StructInit | renderer | ptr | offset | 1 | Direct3D struct initialization with 0xBF800000 (-1.0f), 0x3F000000 (0.5f), 0x3E800000 (0.25f) |
| DAT_007ce104 | FuncCall_Afe0 | game | ptr | offset | 1 | pointer to 5 repeated FUN_0049e8f0 calls |
| DAT_005ccbd0 | MessageBuffer_Ptr | UI | ptr | read | 1 | pointer to message buffer (DAT_005ec4cc), used for string copy |
| DAT_005ccb98 | Off_5CCB98_UI | UI | ptr | read | 1 | pointer table entry used by FUN_0049ca00 |
| DAT_007c8380 | Dbl_7C8380_Render | renderer | double | read | 1 | renderer double constant |
| DAT_005ccfd8 | DSD_Render | renderer | string | offset | 1 | "DSD" renderer string |
| DAT_007ce288 | UnknownFlag_7CE288 | game | int | write | 1 | flag written by FUN_004a1200 |
| DAT_005cd0d4 | EnteredOsmanEn | UI | string | offset | 1 | "EnteredOsmanEn" format string |
| DAT_005cd258 | TenSecLollipopD | pit | string | offset | 1 | "10secLollipopD" pit crew string |
| DAT_005cd408 | LfWheelOnMts | setup | string | offset | 1 | "LFWheelOnMTS" tire setup string |
| DAT_005acb48 | Pit_TimerThreshold | pit | float | read | 1 | pit timer threshold, compared against elapsed time in pit logic |
| DAT_005cd568 | PitsNormalPitC | pit | string | offset | 1 | "PitsNormalPitC" pit mode string |
| DAT_005acb64 | BrakeBias_Rate | physics | float | read | 1 | brake bias adjustment rate multiplier, used in brake-by-wire logic |
| DAT_005d1fd4 | SceneFile | setup | string | offset | 1 | "SceneFile" INI key string |
| DAT_005d1e2c | PitcrewPush | setup | string | offset | 1 | "PitCrewPush" INI key string |
| DAT_005d1a90 | VersionOfTelem | setup | string | offset | 1 | "VersionOfTelem" telemetry INI key |
| DAT_005d18a8 | AiFollowsCenter | setup | string | offset | 1 | "AIFollowsCenter" AI config key |
| DAT_005d1650 | InSeconds | setup | string | offset | 1 | "InSeconds" timing config key |
| DAT_005d1430 | VolumeRangePar | setup | string | offset | 1 | "VolumeRangePar" audio config key |
| DAT_005d12ac | Rearview | setup | string | offset | 1 | "RearView" config key |
| DAT_005d10d4 | SpecialFx | setup | string | offset | 1 | "SpecialFX" config key |
| DAT_005d0dcc | WhetherAllSmok | setup | string | offset | 1 | "WhetherAllSmok" smoke config key |
| DAT_005d0ab0 | AdditionalHead | setup | string | offset | 1 | "AdditionalHead" head movement config key |
| DAT_005d0920 | OverridesDefau | setup | string | offset | 1 | "OverridesDefau" config override key |
| DAT_005d065c | TimesCompariso | setup | string | offset | 1 | "TimesCompariso" lap time comparison config key |
| DAT_005d03c4 | FractionOfTheo | setup | string | offset | 1 | "FractionOfTheo" theoretical lap fraction key |
| DAT_005d00dc | DefaultPlayerS | setup | string | offset | 1 | "DefaultPlayerS" default setup key |
| DAT_005cff20 | VehicleRemoval | setup | string | offset | 1 | "VehicleRemoval" config key |
| DAT_005cfbac | Network_028k156k2 | network | string | offset | 1 | "0.28k/1.56k/2.5k ISDN" network speed string |
| DAT_005cf780 | MaxMpPlayers | network | string | offset | 1 | "MaxMpPlayers" multiplayer config key |
| DAT_005cf3c8 | SessionIsAdvan | setup | string | offset | 1 | "SessionIsAdvan" session config key |
| DAT_005cf0a8 | Controls | setup | string | offset | 1 | "Controls" config key |
| DAT_005cec54 | NumberOfConfig | setup | string | offset | 1 | "NumberOfConfig" config key |
| DAT_005ceae0 | Axis22d22dCent | setup | string | offset | 1 | "Axis%2.2d%2.2dCent" axis calibration format |
| DAT_005ce8dc | ControlPitMenu | setup | string | offset | 1 | "ControlPitMenu" controller config key |
| DAT_005ce70c | ControlHeadlig | setup | string | offset | 1 | "ControlHeadlig" headlight control key |
| DAT_005ce378 | SlopeOfLineDef | setup | string | offset | 1 | "SlopeOfLineDef" config key |
| DAT_005cde84 | CoefficientToU | setup | string | offset | 1 | "CoefficientToU" config key |
| DAT_005cda88 | AmountOfChange | setup | string | offset | 1 | "AmountOfChange" config key |
| DAT_005d1fe8 | FilePath_MaxLen | file | int | read | 1 | path buffer length limit used in string concatenation |
| DAT_005acc8c | ColorQuantize_Max | renderer | float | read | 1 | max threshold for color quantization, used in pixel format conversion |
| DAT_005ec478 | Dword_5EC478_Season | game | int | read | 1 | season-related global read by FUN_004b40a0 |
| DAT_005d246c | FloatCmp_Value | math_util | int | read | 1 | 4-byte value used in floating point comparison utility |
| DAT_005d255c | FinedUs | UI | string | offset | 1 | "FinedUs" UI error string |
| DAT_005acd7c | Flt_5ACD7C_Race | race | float | read | 1 | race-related float constant |
| DAT_005d263c | Off_5D263C_Season | game | ptr | read | 1 | season DB pointer table entry |
| DAT_005d2794 | SeasonPointsD | setup | string | offset | 1 | "SeasonPoints=%d" season scoring format |
| DAT_005d28cc | TrackFile | setup | string | offset | 1 | "TrackFile" INI key string |
| DAT_005d2c60 | RaceCondWeather | setup | string | offset | 1 | "RaceCondWeather" config key |
| DAT_005d3000 | Eyepoint | setup | string | offset | 1 | "EyePoint" camera config key |
| DAT_005d2ec0 | FormatIsTrackL | setup | string | offset | 1 | "FormatIsTrackL" track format string |
| DAT_005ace10 | RaceFuel_Consumption_Mult | race | float | read | 1 | race fuel consumption multiplier, varies by session type |
| DAT_005d3234 | Audio_WelcomePtrTable | audio | ptr | read | 1 | pointer table to welcome WAV filenames (8 entries for options/setup) |
| DAT_005d36d0 | Dust | setup | string | offset | 1 | "Dust" track surface config key |
| DAT_005d35cc | Power | setup | string | offset | 1 | "Power" engine config key |
| DAT_005d34f0 | Cross | setup | string | offset | 1 | "Cross" config key |
| DAT_007cf974 | Flt_7CF974_Render | renderer | float | read | 1 | renderer float constant |
| DAT_005d38d4 | BumpAmp | setup | string | offset | 1 | "BumpAmp" track bump config key |
| DAT_005aced0 | Rain_ParticleScale | weather | float | read | 1 | rain particle scale factor used in weather effects |
| DAT_005d3b54 | Off_5D3B54_D3D | renderer | ptr | read | 1 | Direct3D pointer table read by FUN_004d0110 |
| DAT_007c9d80 | SeasonEnd_Boundary | game | ptr | offset | 1 | season data block boundary marker used in season scoring iteration |
| DAT_005d4120 | Header | setup | string | offset | 1 | "Header" INI section key |
| DAT_005d3f80 | DriveAidsInvul | setup | string | offset | 1 | "DriveAidsInvul" config key |
| DAT_005d3d90 | Controls | setup | string | offset | 1 | "Controls" INI section key |
| DAT_005acef8 | Flt_5ACEF8_Render | renderer | float | read | 1 | renderer float constant |
| DAT_005d425c | NoFinishPolyFo | renderer | string | offset | 1 | "NoFinishPolyFo" renderer error string |
| DAT_005c3300 | VehicleFile_Count | setup | int | read | 1 | vehicle file count parameter read by FUN_004d3cf0 |
| DAT_005d4524 | ClutchRpm | setup | string | offset | 1 | "ClutchRPM" config key |
| DAT_005d4400 | Gear | setup | string | offset | 1 | "Gear" config key |
| DAT_005d4858 | DryLatLong | setup | string | offset | 1 | "DryLatLong" tire config key |
| DAT_005d4778 | AiWear | setup | string | offset | 1 | "AiWear" AI tire wear config key |
| DAT_005d4a04 | TraceLevelD | setup | string | offset | 1 | "TRACE LEVEL = %d" debug format string |
| DAT_005acf44 | Render_QuadScale | renderer | float | read | 1 | render quad scale factor for corner vertices |
| DAT_005ad0c0 | Off_5AD0C0_VTable | game | ptr | offset | 1 | vtable pointer referenced by FUN_004db420 |
| DAT_005d4c50 | WcPitHelmet | UI | string | offset | 1 | "WcPitHelmet" WC pit helmet UI string |
| DAT_005d4cd0 | DashLow | UI | string | offset | 1 | "DashLow" UI dashboard string |
| DAT_005d4d58 | RainLight | weather | string | offset | 1 | "RainLight" weather config string |
| DAT_007c7918 | VehicleDynamics_State | dynamics | ptr | offset | 1 | vehicle dynamics state block accessed in FUN_004e49b0 |
| DAT_005ad1d0 | Vehicle_SqDistThreshold | dynamics | double | read | 1 | squared distance threshold for position update filtering |
| DAT_007c7598 | Physics_Damping | dynamics | double | read | 1 | physics damping coefficient used in tire/body dynamics |
| DAT_005d4ffc | RadiusMax | setup | string | offset | 1 | "RadiusMax" track config key |
| DAT_005d4ec4 | PartDRandom | setup | string | offset | 1 | "PartDRandom" config key |
| DAT_005d51e0 | BrakeCooling | setup | string | offset | 1 | "BrakeCooling" vehicle setup key |
| DAT_005d50ac | SlowReboundSet | setup | string | offset | 1 | "SlowReboundSet" suspension setup key |
| DAT_005d5518 | RevLimitSetting | setup | string | offset | 1 | "RevLimitSetting" engine setup key |
| DAT_005d5600 | LifetimeEngine | setup | string | offset | 1 | "LifetimeEngine" engine wear setup key |
| DAT_005d6728 | Custom | setup | string | offset | 1 | "Custom" setup mode string |
| DAT_005d6610 | AiRotationThre | setup | string | offset | 1 | "AiRotationThre" AI rotation threshold key |
| DAT_005d64e4 | NumPitStopsSet | setup | string | offset | 1 | "NumPitStopsSet" pit strategy key |
| DAT_005d63e0 | FwRot | setup | string | offset | 1 | "FWRot" front wing rotation key |
| DAT_005d6300 | BodyAero | setup | string | offset | 1 | "BodyAero" body aero setup key |
| DAT_005d61e0 | BrakeDuctRange | setup | string | offset | 1 | "BrakeDuctRange" brake duct setup key |
| DAT_005d608c | RearAntiSwayRa | setup | string | offset | 1 | "RearAntiSwayRa" rear anti-roll bar key |
| DAT_005d5eb0 | RearAntiSwayRa2 | setup | string | offset | 1 | "RearAntiSwayRa" rear anti-roll bar key 2 |
| DAT_005d5d10 | Front3rdSpring2 | setup | string | offset | 1 | "Front3rdSpring" front 3rd spring key |
| DAT_005d5b20 | Rear3rdFastReb | setup | string | offset | 1 | "Rear3rdFastReb" rear fast rebound key |
| DAT_005d59d0 | Off_5D59D0_Vehicle | setup | ptr | offset | 1 | vehicle setup pointer table |
| DAT_005d589c | Gear1Setting | setup | string | offset | 1 | "Gear1Setting" gear ratio key |
| DAT_005d5760 | Basic | setup | string | offset | 1 | "Basic" setup category string |
| DAT_005ec3e8 | Season_CurrentEntry | game | int | read | 1 | current season entry index |
| DAT_005d6b8c | OtherShape | setup | string | offset | 1 | "OtherShape" config key |
| DAT_005d69ff | Shape_Other | setup | string | offset | 1 | "Other" shape string (partial) |
| DAT_005d6867 | Shape_Main | setup | string | offset | 1 | "Main" shape string (partial) |
| DAT_005ec4b0 | Season_DisplayFlags | game | int | read | 1 | season display flags read by FUN_004f9310 |
| DAT_005d6dec | FTire18WHT | setup | string | offset | 1 | "FTire18WHT" front tire string |
| DAT_005ad274 | Suspension_BumpTravel | physics | float | read | 1 | suspension bump travel scaling factor |
| DAT_007cfec4 | Flt_7CFEC4_Render | renderer | float | read | 1 | renderer float constant |
| DAT_005ad2e0 | Steering_NoiseScale | physics | float | read | 1 | steering noise scale factor for FFB/input randomization |
| DAT_005d6fb4 | Damp | setup | string | offset | 1 | "Damp" suspension damping key |
| DAT_005d7100 | Weather | setup | string | offset | 1 | "Weather" config key |
| DAT_005ad338 | UI_ScrollRange | UI | float | read | 1 | scroll range threshold, varies by session (race/practice) |
| DAT_005ba4c0 | D3D_TextureAlloc | renderer | ptr | offset | 1 | Direct3D texture allocation struct |
| DAT_005adc14 | ColorMatrix_CbCr | renderer | float | read | 1 | color space conversion matrix coefficient (CbCr channel) |
| DAT_005adcbc | VTable_D3DTex | renderer | ptr | offset | 1 | Direct3D texture vtable pointer |
| DAT_005addec | VTable_D3DTex2 | renderer | ptr | offset | 1 | second Direct3D texture vtable pointer |
| DAT_005d7830 | FunPtr_D3D_Proc | renderer | ptr | read | 1 | function pointer called in D3D proc dispatch |
| DAT_005d78b0 | Off_5D78B0_D3D | renderer | ptr | offset | 1 | Direct3D pointer table |
| DAT_005af318 | MissingPlteBef | renderer | string | offset | 1 | "MissingPlteBef" PNG error string |
| DAT_005af58c | ColorQuantize_Table6 | renderer | ptr | offset | 1 | color quantization table for 6-entry palette |
| DAT_005afa74 | UnknownCompres | renderer | string | offset | 1 | "UnknownCompres" PNG error string |
| DAT_005afcb4 | DuplicatePlteC | renderer | string | offset | 1 | "DuplicatePlteC" PNG error string |
| DAT_005afef0 | InvalidTrnsAft | renderer | string | offset | 1 | "InvalidTrnsAft" PNG error string |
| DAT_005d8a08 | SSE_ShuffleConst | math_util | qword | read | 1 | SSE shuffle constant used in SIMD pixel processing |
| DAT_005d8b30 | SSE_NormalizeMask | math_util | xmm | read | 1 | SSE mask for vector normalization in SIMD math |
| DAT_008d6120 | SSE_Vec3_Normalize | math_util | float | read | 1 | SSE normalized vector length constant in 3D math |
| DAT_005d8c40 | SSE_CrossProduct | math_util | xmm | read | 1 | SSE cross product constant in SIMD math |
| DAT_008d6270 | SSE_Triangle_IndexLUT | math_util | int | read | 1 | SSE triangle index lookup table for SIMD math |
| DAT_005b081c | Vertex_SkewMatrix | math_util | float | read | 1 | vertex skew transformation matrix coefficient |
| DAT_005d90f0 | XMM_CropConst | math_util | xmm | read | 1 | SSE crop/truncation constant |
| DAT_005d9394 | SSE_ATan_Coef | math_util | int | read | 1 | SSE arctan approximation polynomial coefficient |
| DAT_005d93ec | Dword_5D93EC_Math | math_util | int | read | 1 | math utility integer constant |
| DAT_005b0c00 | SSE_Matrix_MultConst | math_util | qword | read | 1 | SSE matrix multiplication constant |
| DAT_005b0c20 | SSE_Matrix_AddConst | math_util | qword | read | 1 | SSE matrix addition constant |
| DAT_008b0110 | D3D_Buffer_0110 | renderer | ptr | offset | 1 | Direct3D buffer pointer used by FUN_0052e5a0 |
| DAT_005b772c | DCT_CosineTable_00 | renderer | float | read | 1 | DCT cosine table entry 0, used in JPEG/DCT texture decompression |
| DAT_008b5940 | DCT_Output_00 | renderer | float | write | 1 | DCT output coefficient 0 in texture decompression |
| DAT_008b596c | DCT_Output_01 | renderer | float | write | 1 | DCT output coefficient 1 in texture decompression |
| DAT_008b59d0 | DCT_Output_02 | renderer | float | write | 1 | DCT output coefficient 2 in texture decompression |
| DAT_008b5a08 | DCT_Output_03 | renderer | float | write | 1 | DCT output coefficient 3 in texture decompression |
| DAT_005da7d0 | IncorrectHeader | renderer | string | offset | 1 | "IncorrectHeade" PNG error string |
| DAT_005da950 | D3D_Shader_StatePtr | renderer | ptr | offset | 1 | Direct3D shader state initialization pointer |
| DAT_005da9a0 | D3D_Shader_StateFuncs | renderer | ptr | offset | 1 | Direct3D shader function pointer table |
| DAT_00804000 | D3D_VertexBuffer_State | renderer | ptr | offset | 1 | Direct3D vertex buffer state block |
| DAT_005dbfec | TextureSizeNo | renderer | string | offset | 1 | "TextureSizeNo" D3D texture error string |
| DAT_00600000 | D3D_RenderState_Block | renderer | ptr | offset | 1 | Direct3D render state block at 0x600000 |
| DAT_005dc370 | HatTarget | renderer | string | offset | 1 | "HatTarget" D3D input config string |
| DAT_005dc41c | GroupMethod | renderer | string | offset | 1 | "GroupMethod" render group method string |
| DAT_005dc5a8 | CPUID_Feature_3DNow | cpu | int | read | 1 | CPUID feature flag for 3DNow! support (AMD) |
| DAT_005dc564 | CPUID_Feature_SSE | cpu | int | read | 1 | CPUID feature flag for SSE support |
| DAT_005dc500 | CPUID_Feature_MMX | cpu | int | read | 1 | CPUID feature flag for MMX support |
| DAT_005dc4bc | CyrixInstead | cpu | string | offset | 1 | "CyrixInstead" CPU vendor string |
| DAT_005dd844 | Blit_CopyAllFlag | renderer | int | write | 1 | flag for texture blit copy mode (0=solid color skip, 1=copy all) |
| DAT_005e4fe0 | Groups | renderer | string | offset | 1 | "Groups" render group string |
| DAT_005e50f4 | FFFFFF | renderer | string | offset | 1 | "%f %f %f %f %f" format string |
| DAT_005e5184 | CCXX | renderer | string | offset | 1 | "CCXX" renderer string |
| DAT_005e519c | Lpt8 | renderer | string | offset | 1 | "LPT8" string |
| DAT_005e52f8 | NegBody | renderer | string | offset | 1 | "NegBody" renderer string |
| DAT_008cfd88 | LDLT_Work_0 | dynamics | double | read | 1 | LDL^T factorization workspace double 0 (physics solver) |
| DAT_008d01a8 | LDLT_Work_1 | dynamics | double | read | 1 | LDL^T factorization workspace double 1 (physics solver) |
| DAT_008cfe78 | LDLT_Work_2 | dynamics | double | write | 1 | LDL^T factorization workspace double 2 (physics solver) |
| DAT_008d3994 | LDLT_Work_Idx0 | dynamics | int | offset | 1 | LDL^T factorization workspace index 0 (physics solver) |
| DAT_008d1020 | LDLT_Work_3 | dynamics | double | read | 1 | LDL^T factorization workspace double 3 (physics solver) |
| DAT_008d1738 | LDLT_Work_4 | dynamics | double | read | 1 | LDL^T factorization workspace double 4 (physics solver) |
| DAT_008d0440 | LDLT_Work_5 | dynamics | double | write | 1 | LDL^T factorization workspace double 5 (physics solver) |
| DAT_008d0508 | LDLT_Work_6 | dynamics | double | write | 1 | LDL^T factorization workspace double 6 (physics solver) |
| DAT_008d0670 | LDLT_Work_7 | dynamics | double | write | 1 | LDL^T factorization workspace double 7 (physics solver) |
| DAT_008d1f78 | LDLT_Work_8 | dynamics | double | read | 1 | LDL^T factorization workspace double 8 (physics solver) |
| DAT_008d3aa0 | LDLT_Work_9 | dynamics | double | read | 1 | LDL^T factorization workspace double 9 (physics solver) |
| DAT_008d0aa8 | LDLT_Work_10 | dynamics | double | read | 1 | LDL^T factorization workspace double 10 (physics solver) |
| DAT_008d0f50 | LDLT_Work_11 | dynamics | double | read | 1 | LDL^T factorization workspace double 11 (physics solver) |
| DAT_008d17a0 | LDLT_Work_12 | dynamics | double | read | 1 | LDL^T factorization workspace double 12 (physics solver) |
| DAT_008d1fb0 | LDLT_Work_13 | dynamics | double | read | 1 | LDL^T factorization workspace double 13 (physics solver) |
| DAT_008d1fb8 | LDLT_Work_14 | dynamics | double | read | 1 | LDL^T factorization workspace double 14 (physics solver) |
| DAT_008d1fc0 | LDLT_Work_15 | dynamics | double | read | 1 | LDL^T factorization workspace double 15 (physics solver) |
| DAT_008d1ef0 | LDLT_Work_16 | dynamics | double | read | 1 | LDL^T factorization workspace double 16 (physics solver) |
| DAT_008d39f0 | LDLT_Work_Idx1 | dynamics | int | offset | 1 | LDL^T factorization workspace index 1 (physics solver) |
| DAT_008d1580 | LDLT_Work_17 | dynamics | double | read | 1 | LDL^T factorization workspace double 17 (physics solver) |
| DAT_008d1aa8 | LDLT_Work_18 | dynamics | double | read | 1 | LDL^T factorization workspace double 18 (physics solver) |
| DAT_008d1e40 | LDLT_Work_19 | dynamics | double | read | 1 | LDL^T factorization workspace double 19 (physics solver) |
| DAT_008d19d0 | LDLT_Work_20 | dynamics | double | read | 1 | LDL^T factorization workspace double 20 (physics solver) |
| DAT_008d3a0c | LDLT_Work_Idx2 | dynamics | int | offset | 1 | LDL^T factorization workspace index 2 (physics solver) |
| DAT_008d20f0 | LDLT_Work_21 | dynamics | double | read | 1 | LDL^T factorization workspace double 21 (physics solver) |
| DAT_008d2108 | LDLT_Work_22 | dynamics | double | read | 1 | LDL^T factorization workspace double 22 (physics solver) |
| DAT_008d21e0 | Dbl_8D21E0_Solver | dynamics | double | offset | 1 | constraint solver double offset in LDL^T workspace |
| DAT_008d3b84 | LDLT_Work_Idx3 | dynamics | int | offset | 1 | LDL^T factorization workspace index 3 (physics solver) |
| DAT_008d3b98 | LDLT_Work_Idx4 | dynamics | int | offset | 1 | LDL^T factorization workspace index 4 (physics solver) |
| DAT_008d2dc0 | LDLT_Work_23 | dynamics | double | write | 1 | LDL^T factorization workspace double 23 (physics solver) |
| DAT_008d3bcc | LDLT_Work_Idx5 | dynamics | int | offset | 1 | LDL^T factorization workspace index 5 (physics solver) |
| DAT_008d3bec | LDLT_Work_Idx6 | dynamics | int | offset | 1 | LDL^T factorization workspace index 6 (physics solver) |
| DAT_008d3c10 | LDLT_Solver_Flag | dynamics | byte | read | 1 | LDL^T solver flag byte |
| DAT_005e5454 | NotSupported | network | string | offset | 1 | "NotSupported" WinSock error string |
| DAT_005e5c10 | ForWindowsCeAf | network | string | offset | 1 | "ForWindowsCeAf" WinSock error string |
| DAT_005e6290 | WSAEConnAborte | network | string | offset | 1 | "WSAECONNABORTE" WinSock error string |
| DAT_005bad4c | Thread_MutexState | thread | ptr | offset | 1 | thread mutex initialization state struct (CreateMutexA wrapper) |
| DAT_005bb15c | Audio_StreamState | audio | ptr | offset | 1 | audio stream state struct with playback loop |
| DAT_008d3e3d | Unk_8D3E3D_Jump | thread | ptr | offset | 1 | trampoline target address used by FUN_00587a50 |
| DAT_005b8c7c | StringParse_Delim | file | string | offset | 1 | delimiter string used in path/token parsing (".", "_", ",") |
| DAT_005be3f0 | AtExit_Handlers_End | file | ptr | offset | 1 | end of atexit handler chain, used in FUN_00589cc6 shutdown |
| DAT_005b8d48 | Random_Modulus | math_util | double | read | 1 | random number modulus used in modulo comparison (rand % M) |
| DAT_005e6c84 | CriticalSection_Ptr4 | thread | ptr | read | 1 | critical section pointer 4, initialized in FUN_0058dfc1 |
| DAT_005e9a90 | LinkedList_Sentinel | file | ptr | write | 1 | linked list sentinel node for memory tracking |
| DAT_005e6d64 | Format040a | setup | string | offset | 1 | "%04d-%02d" date format string |
| DAT_008d401c | TimeZone_Bias | setup | int | read | 1 | time zone bias in minutes, from GetTimeZoneInformation |
| DAT_008d4012 | TimeZone_ExtraBias | setup | short | read | 1 | time zone extra bias component for daylight saving |
| DAT_005b9950 | ExceptionHandler_State | thread | ptr | offset | 1 | exception handler state block with EH registration |
| DAT_005b9b2c | MessageBoxA | UI | string | offset | 1 | "MessageBoxA" string import |
| DAT_008d3e94 | IniParse_BucketEnd | file | int | read | 1 | INI parser hash bucket end marker, compared to bucket pointer |
| DAT_005bb678 | Stru_5BB678_VTable | game | ptr | offset | 1 | vtable struct for FUN_0059a5fe |
| DAT_005bb938 | Stru_5BB938_VTable | game | ptr | offset | 1 | vtable struct for FUN_0059ae7d |
| DAT_005c752c | Dword_5C752C_Session | game | int | write | 1 | session write target at address 0x008d8000 |
