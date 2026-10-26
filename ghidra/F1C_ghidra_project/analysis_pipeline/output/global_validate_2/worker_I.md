=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be668 | Str_StartingGrid | setup | char[] | offset | 1 | String literal "StartingGrid" — INI/format field name for starting grid position. Used in FUN_00402690. |
| DAT_005be58c | Str_Sector1Length | track | char[] | offset | 1 | String literal "Sector1Length" — track sector length field name. Used in FUN_00402690. |
| DAT_005be4e4 | Str_FogDensity | renderer | char[] | offset | 1 | String literal "FogDensity" — fog density parameter for track rendering. Used in FUN_00402690. |
| DAT_007cb25c | Unknown_7CB25C | game_logic | int | read | 1 | Unknown global read by FUN_00404b60. No source excerpts available. |
| DAT_005be928 | Str_StaticCam | renderer | char[] | offset | 1 | String literal "StaticCam" — static camera name/ID string. Used in FUN_0040b030 camera setup function: loaded from game resource via sub_566B20/sub_565520, stored into 160-byte struct array. |
| DAT_005bea70 | Str_FlyOver | camera | char[] | offset | 1 | String literal "FlyOver" — fly-over camera name string. Used in FUN_0040d4c0. |
| DAT_005beb28 | Str_Last | game_logic | char[] | offset | 1 | String literal "Last" — game/race state name or field. Used in FUN_0040db00. |
| DAT_0059e738 | off_59E738 | system | ptr | offset | 1 | Data pointer referenced by FUN_0040fe50. Likely a vtable or function pointer table. |
| DAT_005c2394 | Str_StvS | system | char[] | offset | 1 | String literal "StvS" — likely a driver/team name or abbreviation (Stewart?). Used in FUN_00414600. |
| DAT_005c2558 | Str_RicardoZ | driver_data | char[] | offset | 1 | String literal "Ricardo Z..." — driver name (Ricardo Zonta). Used in FUN_00415d90 driver data setup. |
| DAT_005c248c | Str_ThomasE | driver_data | char[] | offset | 1 | String literal "Thomas E..." — driver name (likely Thomas Enge or similar). Used in FUN_00415d90 driver data setup. |
| DAT_005c2994 | Str_1999Bar | car_data | char[] | offset | 1 | String literal "1999Bar" — car/team identifier for 1999 BAR team. Used in FUN_0041b980. |
| DAT_005c2878 | Str_2000Williams | car_data | char[] | offset | 1 | String literal "2000Williams" — car/team identifier for 2000 Williams team. Used in FUN_0041b980. |
| DAT_005c2764 | Str_2002Sauber | car_data | char[] | offset | 1 | String literal "2002Sauber" — car/team identifier for 2002 Sauber team. Used in FUN_0041b980. |
| DAT_005c29d8 | Str_DevFilesCamEd | setup | char[] | offset | 1 | String literal "DevFilesCamEd" — developer/setup path string. Used in FUN_004216f0. |
| DAT_005c2c28 | Str_MusicDir | audio | char[] | offset | 1 | String literal "MusicDir" — music directory path name. Used in FUN_00421cd0 setup. |
| DAT_005c2b2c | Str_Install | setup | char[] | offset | 1 | String literal "Install" — installation directory or INI section name. Used in FUN_00421cd0. |
| DAT_005c2f80 | Str_MovieDirS | setup | char[] | offset | 1 | String literal "MovieDirS" — movie directory path string. Used in FUN_00422be0. |
| DAT_005c2e34 | Str_FsaaD | renderer | char[] | offset | 1 | String literal "FsaaD" — FSAA (Full Scene Anti-Aliasing) setting name. Used in FUN_00422be0. |
| DAT_005c30bc | Str_OscLocaleString | UI | char[] | offset | 1 | String literal "OSC_Locale_Str" — OSC locale string for UI. Used in FUN_00423890. |
| DAT_005c3188 | off_5C3188 | system | ptr | offset | 1 | Data pointer/reference table. Used in FUN_00424080. |
| DAT_0059e948 | Unknown_Float_59E948 | physics | float | read | 1 | Float constant read in FUN_004270a0 (9165-byte physics/AI function). Used in vehicle physics/position calculations involving wheel position comparison. |
| DAT_005c32dc | Str_D022D063F | game_logic | char[] | offset | 1 | String literal (GUID or hash string). Used in FUN_0042bdd0. |
| DAT_007cc3c0 | Unknown_7CC3C0 | collision | int | read | 1 | Unknown global read by FUN_0042c440. Located in collision data region (0x7CCxxx range). |
| DAT_005c34b0 | Str_EnteredDynmanE | dynamics | char[] | offset | 1 | Debug string "Entered DynmanE..." for dynamics engine. Used in FUN_0042ca70. |
| DAT_005c3608 | Str_Rcd | file_formats | char[] | offset | 1 | String literal ".RCD" or "Rcd" — RCD file format extension. Used in FUN_0042d370. |
| DAT_005c3768 | Str_Mm | file_formats | char[] | offset | 1 | String literal "MM" or ".mm" — file format string. Used in FUN_0042ed70. |
| DAT_005c3e50 | Str_FuelSettingD | setup | char[] | offset | 1 | String literal "FuelSettingD" — fuel setting field name. Used in FUN_0042fd00. |
| DAT_005c3cc4 | Str_LeftCasterSetting | setup | char[] | offset | 1 | String literal "LeftCasterSetting" — suspension caster setting field name. Used in FUN_0042fd00. |
| DAT_005c3aa4 | Str_HandbrakePressure | setup | char[] | offset | 1 | String literal "HandbrakePressure" — handbrake pressure field name. Used in FUN_0042fd00. |
| DAT_005c3918 | Str_SpringSettingD | setup | char[] | offset | 1 | String literal "SpringSettingD" — spring setting field name. Used in FUN_0042fd00. |
| DAT_005c3f68 | off_5C3F68 | system | ptr | offset | 1 | Data pointer/reference table. Used in FUN_00430f00. |
| DAT_005c3f9c | off_5C3F9C | system | ptr | offset | 1 | Data pointer/reference table. Used in FUN_00432df0. |
| DAT_005c40dc | Str_FreeDamping | setup | char[] | offset | 1 | String literal "FreeDamping" — suspension free damping field name. Used in FUN_00435410. |
| DAT_005c41d4 | Str_Body | file_formats | char[] | offset | 1 | String literal "Body" — body/chassis section name. Used in FUN_00438da0. |
| DAT_0059ebc8 | Unknown_Double_59EBC8 | physics | double | read | 1 | Double constant read in FUN_00439210 (vehicle physics function). Located in physics constant pool. |
| DAT_0059ec58 | Unknown_Double_59EC58 | physics | double | read | 1 | Double constant read in FUN_0043da10 (vehicle physics function). Located in physics constant pool. |
| DAT_0059ed68 | LifetimeClampUpperBound | dynamics | double | read | 1 | Double threshold constant used as upper bound in FUN_00442060 (930-byte vehicle lifetime/damage model). Compared against double at param_1+0x1d0; when exceeded, resets with 0x3fc65718 sentinel. Paired with DAT_0059ed70 (lower bound). |
| DAT_0059eea0 | Unknown_Double_59EEA0 | dynamics | double | read | 1 | Double constant read in FUN_004441f0 (9101-byte vehicle dynamics integration function). Part of vehicle physics constant pool. |
| DAT_0059ee10 | Unknown_Double_59EE10 | dynamics | double | read | 1 | Double constant read in FUN_004441f0 (9101-byte vehicle dynamics integration). |
| DAT_005c4394 | Str_S41F41F | file_formats | char[] | offset | 1 | String literal "^S41^F41^F" or similar format string. Used in FUN_00447d00. |
| DAT_007ccfb8 | CollisionInitFloat1 | collision | float | write | 1 | Initialized to 0xbf800000 (-1.0f) in FUN_0044c8c0 alongside 3 companion globals (0x7ccfb0=8, 0x7ccfb4=0, 0x7ccfbc=0). Part of collision system struct init. |
| DAT_007ca4d4 | CameraInitFloat1 | renderer | float | write | 1 | Initialized to 0xbf800000 (-1.0f) in FUN_0044d340 alongside 3 companions (0x7ca4d0=0x3f, 0x7ca4d8=-1.0f, 0x7ca4dc=0). Part of camera/renderer struct init. |
| DAT_007ccd2c | CollisionGridInitZero | collision | int | write | 1 | Initialized to 0 in FUN_0044d520 alongside 5 companions (0x7ccd20=0x11, 0x7ccd24=0, 0x7ccd28=0, 0x7ccd30=0, 0x7ccd34=0). Part of collision grid param struct. |
| DAT_007d2020 | Collision_RayHitThreshold | collision | float | read | 1 | Float threshold compared in FUN_0044ff50 (5968-byte collision/contact physics function). Used in contact point processing for collision raycast hit detection. |
| DAT_005ad3c8 | Unknown_5AD3C8 | collision | int | read | 1 | Integer constant read in FUN_0044ff50 (collision/contact physics). Located in collision constant region (0x5ADxxx range). |
| DAT_005ad3e8 | Unknown_5AD3E8 | collision | int | read | 1 | Integer constant read in FUN_0044ff50 (collision/contact physics). Located in collision constant region. |
| DAT_0059ef60 | HeadlightRangeScale | renderer | float | read | 1 | Float threshold read in FUN_00451720 (3910-byte vehicle headlight/effect function). Controls headlight illumination range/gating based on DAT_007c56ac (EnableFlag). |
| DAT_007ca534 | AudioSourceDepth | audio | float | read | 1 | Float value read in FUN_00452b10 (audio source depth/comparison function). Used alongside many DAT_007CCxxx audio source constants as comparison targets for audio source type matching. |
| DAT_007cd0d8 | VehicleSetupFloat_7CD0D8 | vehicle_physics | float | write | 1 | Initialized from vehicle struct +0xN in FUN_004537b0 vehicle setup copy function. Part of vehicle parameter block copied with min-clamp to DAT_0059e440. |
| DAT_007ca574 | VehicleSetupFloat_7CA574 | vehicle_physics | float | write | 1 | Part of vehicle setup parameter copy in FUN_004537b0. Copied from vehicle struct field and clamped. |
| DAT_005c5614 | Str_SecondGear | setup | char[] | offset | 1 | String literal "SecondGear" — gear ratio setting field name. Used in FUN_00455290. |
| DAT_005c54fc | Str_Pause | UI | char[] | offset | 1 | String literal "Pause" — pause menu UI string. Used in FUN_00455290. |
| DAT_005ad4a0 | riidltf | system | byte | offset | 1 | COM interface IID (GUID) for DirectInput/COM interface. Used in FUN_00455c60. |
| DAT_0059ef88 | Unknown_Float_59EF88 | physics | float | read | 1 | Float constant used in FUN_004569b0 (130-byte steering/force function). Referenced but not directly used in excerpt — part of physics constant pool. |
| DAT_007d0ab0 | BrakeBalanceOffset | dynamics | float | read | 1 | Float offset added to brake balance/comparison in FUN_0045a8e0 (1297-byte brake/control function). Added to param_1[8] when param_2 exceeds threshold. |
| DAT_005c5bfc | Str_GameMode | game_logic | char[] | offset | 1 | String literal "GameMode" — game mode field name. Used in FUN_0045cf50. |
| DAT_007d1158 | WheelVelocityThreshold | dynamics | float | read | 1 | Float threshold read in FUN_0045e620 (1243-byte wheel velocity/comparison function). Used with DAT_007d108c in wheel velocity differential calculation for tire force. |
| DAT_005c5f08 | Str_SlotIsTaggedAs | network | char[] | offset | 1 | Debug string "Slot is tagged as..." for network slot management. Used in FUN_0045fc50. |
| DAT_007d0f70 | SessionConfigByte | session | ushort | read | 1 | 16-bit ushort masked to 6 bits in FUN_00461610 (674-byte config parser). Used with DAT_007ce874, DAT_007ce88c to build session config word at param_1+0x76. Bitfield for game options. |
| DAT_007ce877 | SessionConfigFlagByte | session | byte | read | 1 | Byte flag referenced by FUN_00461900 (878-byte config reader). Written to via FUN_00464720 with `(byte)(*(ushort *)(param_1+0x76)>>6)&1`. Part of session option flag cascade. |
| DAT_007d013c | SessionConfigValue_7D013C | session | int | read | 1 | Integer value in session config block. Written/read by FUN_00461900 config parser. Part of session option struct. |
| DAT_005c64d8 | Str_Password | network | char[] | offset | 1 | String literal "Password" — network password field name. Used in FUN_00463160. |
| DAT_005c6530 | Str_CouldNotSwitch | game_logic | char[] | offset | 1 | String literal "Could not switch..." — session state error message. Used in FUN_004637a0. |
| DAT_0059f1f0 | CameraControlAccel | camera | float | read | 1 | Float acceleration/scaling constant read in FUN_00466350 (768-byte camera/control function). Used in camera position/velocity calculations with grid position input. |
| DAT_005c6858 | Str_SSI | file_formats | char[] | offset | 1 | String literal ".SSI" or "SSI" — file format extension. Used in FUN_0046a560. |
| DAT_007cd818 | TrackDB_Byte_7CD818 | track | byte | offset | 1 | String/byte at track database location. Used in FUN_0046cb50. |
| DAT_007cd834 | TrackDB_Buffer_7CD834 | track | byte[] | offset | 1 | String buffer at track database location. Used in FUN_00470490 (418-byte track/scene function) for string copy via sub_587DD0 with length 25. |
| DAT_005c7190 | FileExtensionMagic | file_formats | dword | read | 1 | Four-byte magic value used in FUN_004793ec (495-byte file path/extension function). Compared against file path suffix to determine file type. Paired with DAT_005c71c0/c4/c8 as extension magic block. |
| DAT_005c72dc | Str_RemoveBookmark | UI | char[] | offset | 1 | String literal "RemoveBookmark" — UI bookmark management string. Used in FUN_0047daf0. |
| DAT_005c7470 | Str_CircuitLength | track | char[] | offset | 1 | String literal "CircuitLength" — track circuit length field name. Used in FUN_0047e440. |
| DAT_005cc248 | Str_DevF119992002_27 | setup | char[] | offset | 1 | Debug path string "D:\\dev\\F1_1999_2002\\..." variant. Used in FUN_0048e8d0. |
| DAT_005cc680 | Str_Location2 | track | char[] | offset | 1 | String literal "Location2" — track location field name. Used in FUN_00492710. |
| DAT_005cc7b4 | Str_Font | UI | char[] | offset | 1 | String literal "Font" — font resource name. Used in FUN_00493060. |
| DAT_005cc92c | Str_AnimDelta | renderer | char[] | offset | 1 | String literal "AnimDelta" — animation delta parameter name. Used in FUN_00493990. |
| DAT_005ac9c8 | Unknown_Double_5AC9C8 | math_util | double | read | 1 | Double constant read in FUN_00496280 (56-byte random init function). Not referenced directly in code — function uses FUN_005881f0 to fill 16 floats at param_1+0x162c. |
| DAT_005ac9e0 | Unknown_Float_5AC9E0 | math_util | float | read | 1 | Float constant read in FUN_004989e0. Located in math constant pool. |
| DAT_005ccbf0 | Ptr_VTable_5CCBF0 | system | ptr | read | 1 | Vtable/function pointer table. Used in FUN_0049c140. |
| DAT_005ccb68 | Ptr_VTable_5CCB68 | system | ptr | read | 1 | Vtable/function pointer table. Used in FUN_0049ca00. |
| DAT_005ccee8 | Str_Water | weather | char[] | offset | 1 | String literal "Water" — water/wet condition parameter name. Used in FUN_0049db80. |
| DAT_007cc28c | ScoringGateFlag | steward | int | read | 1 | Scoring gate flag read in FUN_0049f790 (213-byte steward scoring function). When non-zero, triggers FUN_0049f170(1) scoring path. Part of scoring gate chain with 0x7cc2b8, 0x7cc2e4, 0x7cc310. |
| DAT_007ce270 | RaceStateStruct | race | struct | write | 1 | Race state struct initialized in FUN_004a1200. Part of session initialization sequence. |
| DAT_007ce2c4 | RaceStateValue_7CE2C4 | race | int | write | 1 | Race state value written by FUN_004a1200 during session init. |
| DAT_005cd2b8 | Str_FrontLeftWheel | setup | char[] | offset | 1 | String literal "FrontLeftWheel" — wheel setup field name. Used in FUN_004a24d0. |
| DAT_005cd444 | Str_Detail | renderer | char[] | offset | 1 | String literal "Detail" — rendering detail level parameter. Used in FUN_004a2a90. |
| DAT_005cd4b8 | Str_Pits_0 | track | char[] | offset | 1 | String literal "Pits" variant — pit lane section name. Used in FUN_004a3910. |
| DAT_005cd5e4 | Str_Pits | track | char[] | offset | 1 | String literal "Pits" — pit lane section name. Used in FUN_004a4900. |
| DAT_005cd62c | Str_SD | game_logic | char[] | offset | 1 | String literal "SD" — session/state field. Used in FUN_004a58b0. |
| DAT_005cd6e4 | Str_GPrix | UI | char[] | offset | 1 | String literal "GPrix" — Grand Prix UI menu string. Used in FUN_004aa1e0. |
| DAT_005d1ea0 | Str_AutoPit | UI | char[] | offset | 1 | String literal "AutoPit" — auto pit option field name. Used in FUN_004aa270. |
| DAT_005d1b90 | Str_0SuperHighPhys | UI | char[] | offset | 1 | String literal "0_SuperHighPhys" — graphics/physics detail level. Used in FUN_004aa270. |
| DAT_005d1954 | Str_RunQualify | UI | char[] | offset | 1 | String literal "RunQualify" — run qualify option. Used in FUN_004aa270. |
| DAT_005d16b8 | Str_MaximumEffects | UI | char[] | offset | 1 | String literal "MaximumEffects" — effects quality level. Used in FUN_004aa270. |
| DAT_005d14bc | Str_PitVolume | audio | char[] | offset | 1 | String literal "PitVolume" — pit audio volume setting. Used in FUN_004aa270. |
| DAT_005d1300 | Str_HelicopterShape | renderer | char[] | offset | 1 | String literal "HelicopterShape" — helicopter shape/model name. Used in FUN_004aa270. |
| DAT_005d113c | Str_OpponentDetail | UI | char[] | offset | 1 | String literal "OpponentDetail" — opponent detail quality setting. Used in FUN_004aa270. |
| DAT_005d0e98 | Str_EngineEmitterF | audio | char[] | offset | 1 | String literal "EngineEmitterF" — engine audio emitter parameter. Used in FUN_004aa270. |
| DAT_005d0bac | Str_LookaheadAngle | ai | char[] | offset | 1 | String literal "LookaheadAngle" — AI lookahead angle setting. Used in FUN_004aa270. |
| DAT_005d0984 | Str_SmokeDetail | renderer | char[] | offset | 1 | String literal "SmokeDetail" — smoke particle detail level. Used in FUN_004aa270. |
| DAT_005d06f4 | Str_BasicRules | game_logic | char[] | offset | 1 | String literal "BasicRules" — basic rules/scoring mode. Used in FUN_004aa270. |
| DAT_005d04b4 | Str_AiPowerCalibra | ai | char[] | offset | 1 | String literal "AiPowerCalibra" — AI power calibration setting. Used in FUN_004aa270. |
| DAT_005d01ec | Str_FidelityUnilat | renderer | char[] | offset | 1 | String literal "FidelityUnilat" — rendering fidelity setting. Used in FUN_004aa270. |
| DAT_005cffa0 | Str_RaceTime | race | char[] | offset | 1 | String literal "RaceTime" — race time setting. Used in FUN_004aa270. |
| DAT_005cfcd4 | Str_AllowedVehicle | game_logic | char[] | offset | 1 | String literal "AllowedVehicle" — vehicle restriction setting. Used in FUN_004aa270. |
| DAT_005cf868 | Str_ForcePhysics | physics | char[] | offset | 1 | String literal "ForcePhysics" — force physics level setting. Used in FUN_004aa270. |
| DAT_005cf544 | Str_DedicatedTarget | ai | char[] | offset | 1 | String literal "DedicatedTarget" — AI dedicated target mode. Used in FUN_004aa270. |
| DAT_005cf0f0 | Str_PreviousVehicle | game_logic | char[] | offset | 1 | String literal "PreviousVehicle" — previous vehicle switch key. Used in FUN_004aa270. |
| DAT_005cedb4 | Str_HmdPitchExpone | UI | char[] | offset | 1 | String literal "HmdPitchExpone" — HMD pitch exponent setting. Used in FUN_004aa270. |
| DAT_005ceb5c | Str_Controller2S0 | controller | char[] | offset | 1 | String literal "Controller2S0" — controller binding setting. Used in FUN_004aa270. |
| DAT_005ce950 | Str_ControlSixthGe | controller | char[] | offset | 1 | String literal "ControlSixthGe" — sixth gear control mapping. Used in FUN_004aa270. |
| DAT_005ce780 | Str_ControlZeroHmd | controller | char[] | offset | 1 | String literal "ControlZeroHmd" — HMD zero/center control mapping. Used in FUN_004aa270. |
| DAT_005ce4bc | Str_FfbBrakeFxOnSt | controller | char[] | offset | 1 | String literal "FfbBrakeFxOnSt" — force feedback brake effect setting. Used in FUN_004aa270. |
| DAT_005cdf80 | Str_FfbSteerUpdate | controller | char[] | offset | 1 | String literal "FfbSteerUpdate" — force feedback steering update setting. Used in FUN_004aa270. |
| DAT_005cdb80 | Str_MagnitudeOfBra | controller | char[] | offset | 1 | String literal "MagnitudeOfBra" — FFB brake magnitude setting. Used in FUN_004aa270. |
| DAT_005cd798 | Str_FfbJoy22dAxis2 | controller | char[] | offset | 1 | String literal "FfbJoy22dAxis2" — FFB joystick axis mapping. Used in FUN_004aa270. |
| DAT_005acc44 | PTR_VTABLE_5ACC44 | system | ptr | offset | 1 | Vtable pointer table used as class vtable in FUN_004b1a10 (26-byte constructor). Assigned to param_1[0]. |
| DAT_005accf0 | RandomRangeScale | math_util | float | read | 1 | Float scale factor for random number generation in FUN_004b3bd0 (141-byte noise init). Used as multiplier for rand() to produce [-0.5,0.5] range. Part of 256-entry noise buffer init. |
| DAT_005acd58 | SteeringProgressiveScale | dynamics | float | read | 1 | Float scale factor read in FUN_004b67d0 (201-byte steering progressive/logic function). Part of switch-case lookup table with DAT_005acd44/5c/60 to scale steering input based on steering wheel type. |
| DAT_005d253c | Str_Accident | UI | char[] | offset | 1 | String literal "Accident" — UI accident report string. Used in FUN_004bb730. |
| DAT_005d25bc | Str_LapWillNotCount | race | char[] | offset | 1 | String literal "Lap will not count..." — lap disallowed message. Used in FUN_004bccc0. |
| DAT_0083ee5c | SeasonScoringQueuePtr | scoring | ptr | write | 1 | Queue/ring buffer pointer for season scoring. Set to &DAT_007d2e54 in FUN_004bf4f0 (316-byte scoring init). Part of season scoring double-buffer (DAT_0083ee54-5c, DAT_008aae64-6c). |
| DAT_005d27f8 | Str_NameS | file_formats | char[] | offset | 1 | Format string "Name: %s" for serialization output. Used in FUN_004c0690 (342-byte season data serialize function). |
| DAT_005d2864 | Str_S22D | file_formats | char[] | offset | 1 | Format string "S%2d" for serialization output. Used in FUN_004c0cc0. |
| DAT_005d2cf8 | Str_ChampionshipSe | UI | char[] | offset | 1 | String literal "ChampionshipSe" — championship season UI string. Used in FUN_004c2420. |
| DAT_005d3038 | Str_Hdvehicle | setup | char[] | offset | 1 | String literal "HDV" or "Hdvehicle" — HDV (handling data vehicle) file identifier. Used in FUN_004c3200. |
| DAT_005d2f44 | Str_TeamWins | scoring | char[] | offset | 1 | String literal "TeamWins" — team wins counter field name. Used in FUN_004c3200. |
| DAT_005d30dc | Str_3ThereAreNoSce | UI | char[] | offset | 1 | Message string "There are no scenes..." — scene load error. Used in FUN_004c52c0. |
| DAT_005d33d8 | Str_EnteredSoundIn | audio | char[] | offset | 1 | Debug string "Entered Sound In..." for audio init. Used in FUN_004c8ae0. |
| DAT_005ace4c | PTR_VTABLE_5ACE4C | system | ptr | offset | 1 | Vtable pointer for audio subsystem class (case 2 in FUN_004c9a50 switch). Audio object factory creates objects of type 1-7 with different vtable ptrs. |
| DAT_005d3600 | Str_Scale | renderer | char[] | offset | 1 | String literal "Scale" — renderer scale parameter name. Used in FUN_004ca480. |
| DAT_005d3518 | Str_NoReduceDetail | renderer | char[] | offset | 1 | String literal "NoReduceDetail" — detail reduction toggle. Used in FUN_004ca480. |
| DAT_005d3730 | Str_DstColor | renderer | char[] | offset | 1 | String literal "DstColor" — destination color blending parameter. Used in FUN_004cada0. |
| DAT_005d37e8 | Str_CouldNotFindTr | track | char[] | offset | 1 | String literal "Could not find track..." — track file load error. Used in FUN_004cdc70. |
| DAT_005d3844 | Str_Guardrail | track | char[] | offset | 1 | String literal "Guardrail" — guardrail geometry name. Used in FUN_004cdd80. |
| DAT_005d39f0 | Str_EnteredSpecial_3 | game_logic | char[] | offset | 1 | Debug string "Entered Special 3..." — game mode entry. Used in FUN_004cfed0. |
| DAT_005d3a7c | Str_Wcflag | game_logic | char[] | offset | 1 | String literal "WCFlag" — weather/condition flag parameter name. Used in FUN_004d0110. |
| DAT_005d4188 | Str_Results | UI | char[] | offset | 1 | String literal "Results" — results screen string. Used in FUN_004d24d0. |
| DAT_005d4014 | Str_DriveAidsSteer | controller | char[] | offset | 1 | String literal "DriveAidsSteer" — driving aid steering setting. Used in FUN_004d24d0. |
| DAT_005d3dd8 | Str_FuelMultD | race | char[] | offset | 1 | String literal "FuelMultD" — fuel multiplier display field. Used in FUN_004d24d0. |
| DAT_005d3c84 | Str_ReasonD | race | char[] | offset | 1 | String literal "ReasonD" — DNF/DSQ reason field. Used in FUN_004d24d0. |
| DAT_005d42b4 | Str_Xpitin | track | char[] | offset | 1 | String literal "Xpitin" — pit lane entry coordinate. Used in FUN_004d38f0. |
| DAT_005d4340 | Str_DDF | file_formats | char[] | offset | 1 | String literal ".DDF" — DDF file format extension. Used in FUN_004d3cf0. |
| DAT_005d4574 | Str_YawRads | vehicle | char[] | offset | 1 | String literal "YawRads" — yaw rate display/field name. Used in FUN_004d4a80. |
| DAT_005d444c | Str_TyreCenterTemp | vehicle | char[] | offset | 1 | String literal "TyreCenterTemp" — tire center temperature field. Used in FUN_004d4a80. |
| DAT_005d4648 | Str_NeedAtLeastDDa | UI | char[] | offset | 1 | Error string "Need at least DDA..." — driver/controller warning. Used in FUN_004d5f70. |
| DAT_005d47ac | Str_Wearrate | vehicle | char[] | offset | 1 | String literal "WearRate" — tire wear rate field. Used in FUN_004d6b00. |
| DAT_005d497c | Str_TireBrandDoesn_0 | vehicle | char[] | offset | 1 | String literal "Tire brand doesn't match..." — tire brand mismatch warning. Used in FUN_004d75d0. |
| DAT_005d4a4c | Ptr_VTable_5D4A4C | system | ptr | read | 1 | Vtable/function pointer table. Used in FUN_004d8ab0. |
| DAT_005acfe0 | PTR_VTABLE_5ACFE0 | system | ptr | offset | 1 | Vtable pointer for graphics/particle class (case 7 in FUN_004daea0 object factory switch). |
| DAT_005d4c84 | Str_Wing | vehicle | char[] | offset | 1 | String literal "Wing" — wing setup/display field. Used in FUN_004ddad0. |
| DAT_005c67c4 | Str_Notspin | ai | char[] | offset | 1 | String literal "NotSpin" — AI spin prevention setting. Used in FUN_004ddf90. |
| DAT_005d4d80 | Str_DebrisD | vehicle | char[] | offset | 1 | String literal "DebrisD" — debris damage field. Used in FUN_004dfce0. |
| DAT_005ad15c | WheelOffsetThreshold | dynamics | float | read | 1 | Float threshold used in FUN_004e2d00 (838-byte wheel/contact setup). Compared against DAT_0059e440 in wheel position initialization for contact point selection. |
| DAT_005ad1a0 | Unknown_Float_5AD1A0 | dynamics | float | read | 1 | Float constant read in FUN_004e5f60 (3593-byte vehicle dynamics integration function). Located in physics constant region. |
| DAT_005ad1ec | SuspensionForceLimit | dynamics | float | read | 1 | Float threshold read in FUN_004ec1a0 (3722-byte suspension/force dynamics function). Compared in ABS(param_4) path with DAT_0059e43c, DAT_0059e670 for suspension force calculation. |
| DAT_007c74a3 | VehicleFlagByte_7C74A3 | vehicle | byte | read | 1 | Byte flag read in FUN_004f1c40 (921-byte vehicle control function). Checked alongside DAT_007c749f in player vehicle control path. |
| DAT_005d4f18 | Str_Wheeldetach | vehicle | char[] | offset | 1 | String literal "WheelDetach" — wheel detachment setting. Used in FUN_004f24f0. |
| DAT_005d5238 | Str_Brakefailure | vehicle | char[] | offset | 1 | String literal "BrakeFailure" — brake failure setting. Used in FUN_004f2c60. |
| DAT_005d5100 | Str_Springrange | vehicle | char[] | offset | 1 | String literal "SpringRange" — spring range setting. Used in FUN_004f2c60. |
| DAT_005d542c | Str_XForceAppliedW | vehicle | char[] | offset | 1 | String literal "XForceAppliedW" — force applied to wheel field. Used in FUN_004f3240. |
| DAT_005d5688 | Str_Revlimitlogic | vehicle | char[] | offset | 1 | String literal "RevLimitLogic" — rev limit logic setting. Used in FUN_004f3c80. |
| DAT_005d675c | Str_Notes | setup | char[] | offset | 1 | String literal "Notes" — notes/description field. Used in FUN_004f4270. |
| DAT_005d6670 | Str_TireBrand | vehicle | char[] | offset | 1 | String literal "TireBrand" — tire brand setting. Used in FUN_004f4270. |
| DAT_005d6530 | Str_Wedgesetting | vehicle | char[] | offset | 1 | String literal "WedgeSetting" — wedge (cross-weight) setting. Used in FUN_004f4270. |
| DAT_005d6408 | Str_Fwright | vehicle | char[] | offset | 1 | String literal "FWRight" — front right wheel setting. Used in FUN_004f4270. |
| DAT_005d6334 | Str_Rwfore | vehicle | char[] | offset | 1 | String literal "RWFore" — rear wing fore setting. Used in FUN_004f4270. |
| DAT_005d6234 | Str_Radiatorsetting | vehicle | char[] | offset | 1 | String literal "RadiatorSetting" — radiator opening setting. Used in FUN_004f4270. |
| DAT_005d60f0 | Str_Rightwheelbase | vehicle | char[] | offset | 1 | String literal "RightWheelBase" — right wheelbase adjustment. Used in FUN_004f4270. |
| DAT_005d5f1c | Str_Rear3rdbumpsta | vehicle | char[] | offset | 1 | String literal "Rear3rdBumpSta" — rear 3rd spring bump stop setting. Used in FUN_004f4270. |
| DAT_005d5d7c | Str_Righttrackbars | vehicle | char[] | offset | 1 | String literal "RightTrackBars" — right track bar setting. Used in FUN_004f4270. |
| DAT_005d5ba0 | Str_Rear3rdfastbum | vehicle | char[] | offset | 1 | String literal "Rear3rdFastBum" — rear 3rd fast bump setting. Used in FUN_004f4270. |
| DAT_005d5a0c | Str_Handbrakepress | vehicle | char[] | offset | 1 | String literal "HandbrakePress" — handbrake pressure setting. Used in FUN_004f4270. |
| DAT_005d58ef | Str_Rear | vehicle | char[] | offset | 1 | String literal "Rear" — rear axle/setting prefix. Used in FUN_004f4270. |
| DAT_005d579c | Str_Diffpreloadran | vehicle | char[] | offset | 1 | String literal "DiffPreloadRan" — differential preload range setting. Used in FUN_004f4270. |
| DAT_008af8f0 | Unknown_8AF8F0 | dynamics | int | offset | 1 | Data offset in dynamics/physics region. Used in FUN_004f70c0. |
| DAT_005d6bcc | Str_EngineAmbient | vehicle | char[] | offset | 1 | String literal "EngineAmbient" — engine ambient temperature setting. Used in FUN_004f7460. |
| DAT_005d6a63 | Str_EngineTempRange | vehicle | char[] | offset | 1 | String literal (truncated) — engine temperature range setting. Used in FUN_004f7460. |
| DAT_005d68d7 | Str_EngineWearMode | vehicle | char[] | offset | 1 | String literal (truncated) — engine wear mode field. Used in FUN_004f7460. |
| DAT_005ad26c | Unknown_Float_5AD26C | dynamics | float | read | 1 | Float constant read in FUN_004f8d70. Located in physics constant region. |
| DAT_005d6e10 | Str_LogoLodBmp | renderer | char[] | offset | 1 | String literal "LogoLodBmp" — logo LOD bitmap name. Used in FUN_004f9480. |
| DAT_008afeac | Unknown_8AFEAC | physics | int | write | 1 | Written by FUN_004fa640. Located in physics state region (0x8AFExx). |
| DAT_005d6f38 | Str_SC | game_logic | char[] | offset | 1 | String literal "SC" — safety car or similar. Used in FUN_004fc400. |
| DAT_005ad2d0 | SpeedComparisonThreshold | dynamics | float | read | 1 | Float threshold compared against param_2 in FUN_004fd7e0 (93-byte speed/lookup function). When param_2 >= threshold, returns float from param_1+0xa0; otherwise interpolates from lookup table at param_1+0x64/68. |
| DAT_005d6f8c | Str_Drizzle | weather | char[] | offset | 1 | String literal "Drizzle" — light rain weather type. Used in FUN_004fe0d0. |
| DAT_005d6fec | Str_AmbientTemp | weather | char[] | offset | 1 | String literal "AmbientTemp" — ambient temperature field. Used in FUN_004fe350. |
| DAT_005ad334 | WeatherTypeThreshold | weather | float | read | 1 | Float threshold in FUN_004feaa0 (80-byte weather type selector). Used in cascade: param_1 < threshold → type 2, param_1 < DAT_0059e6e8 → type 3, else type 4/5. |
| DAT_005adb70 | AudioDSPConstant | audio | double | read | 1 | Double constant read in FUN_0050210e (1430-byte audio/COM function). Used in DirectX/audio DSP initialization with COM interface setup (FUN_00513c38, FUN_005118e6). |
| DAT_005adba8 | PTR_VTABLE_5ADBA8 | renderer | ptr | offset | 1 | Vtable pointer for renderer mesh/object class (size 0x18). Assigned in FUN_0050a7c5 constructor. |
| DAT_005adc6c | PTR_VTABLE_5ADC6C | renderer | ptr | offset | 1 | Vtable pointer for renderer object (size 8). Assigned in FUN_0050ae5a constructor. |
| DAT_005add9c | PTR_VTABLE_5ADD9C | renderer | ptr | offset | 1 | Vtable pointer for renderer object (size 0x20). Assigned in FUN_0050b727 constructor. |
| DAT_005d7804 | PTR_FUN_5D7804 | system | ptr | read | 1 | Function pointer table used in FUN_0050c647. Indirect call via `(*(code *)PTR_FUN_005d7804)()` — jumptable dispatch target. |
| DAT_005ade48 | Unknown_Float_5ADE48 | renderer | float | read | 1 | Float constant read in FUN_0050f258 (986-byte renderer math function — quaternion/transform operations). |
| DAT_005af274 | Str_IEnd | file_formats | char[] | offset | 1 | String literal "IEnd" — I/O stream end marker. Used in FUN_005119e9. |
| DAT_005af520 | Str_ItSAnErrorToSe | system | char[] | offset | 1 | Error string "It's an error to set..." — MSVC CRT error message. Used in FUN_00513bf9. |
| DAT_005af640 | AudioResampleBuffer | audio | byte[] | offset | 1 | Audio resampling buffer/coefficient table referenced in FUN_00515417 (1106-byte audio resampling filter). Also referenced via DAT_005af63c/638/634 — coefficients for 16-tap interpolation filter. |
| DAT_005afba0 | Str_UnknownInterla | renderer | char[] | offset | 1 | String literal "Unknown interlaced format" — D3D surface format error. Used in FUN_005188b4. |
| DAT_005afdfc | Str_UnknownSrgbInt | renderer | char[] | offset | 1 | String literal "Unknown sRGB interlaced format" — D3D surface format error. Used in FUN_00518d29. |
| DAT_005d89e8 | PTR_MMXConstant | math_util | qword | read | 1 | MMX packed constant (qword) used in FUN_0051c813 (316-byte SIMD pixel processing). Used as target for psubsw (packed subtract signed with saturation) in pixel format conversion pipeline. |
| DAT_008d60c0 | NewtonRaphsonConstant | math_util | dword | read | 1 | DWORD constant used in FUN_0051f98e (380-byte Newton-Raphson reciprocal sqrt approximation via SIMD). Cached in xmmword_8D4690 as initial guess for 1/sqrt(x) computation. |
| DAT_008d611c | SqrtApproxConstants | math_util | float[4] | read | 1 | Array of 4 floats used in FUN_0051fd90 (276-byte 3D vector normalization/sqrt approximation). Contains sqrt precision constants (flt_8D611c=threshold, flt_8D6120, flt_8D6124, flt_8D6128, flt_8D6130/34/38). Part of SIMD/3DNow math library. |
| DAT_008d61c0 | XMMWORD_8D61C0 | math_util | xmmword | read | 1 | SSE XMM constant used in FUN_0052087e (109-byte SIMD matrix/transform setup). Loaded as 128-bit constant for vertex transform operations. |
| DAT_005d8cb0 | XMMWORD_5D8CB0 | math_util | xmmword | read | 1 | SSE XMM constant used in FUN_00520c0e (198-byte SIMD quaternion/matrix rotation). Used as additive constant in quaternion multiplication polynomial evaluation. |
| DAT_005b06e8 | Unknown_5B06E8 | file_formats | int | read | 1 | Integer constant read in FUN_00527752. Located in JPEG/file format decoding region. |
| DAT_005d9140 | XMMWORD_5D9140 | math_util | xmmword | read | 1 | SSE XMM constant referenced but not directly used in FUN_00528bd0 (empty stub function). Part of SIMD math constant pool. |
| DAT_005d9170 | XMMWORD_5D9170 | math_util | xmmword | read | 1 | SSE XMM constant used in FUN_00528cc0 (329-byte SIMD pixel format conversion). Part of color channel extraction pipeline with bitmask and scaling constants. |
| DAT_005d93cc | Unknown_5D93CC | math_util | int | read | 1 | Integer constant. Referenced in FUN_00529200 (empty stub). Part of SIMD math constant pool. |
| DAT_005da420 | PTR_Buffer_5DA420 | math_util | ptr | offset | 1 | Buffer pointer returned via param_4 in FUN_0052a5a8 (47-byte math constant query function). Returns DAT_005d9418/1c/20/as420 as const pointers. |
| DAT_005b0c58 | JPEG_HuffmanTable_5B0C58 | file_formats | qword | read | 1 | 64-bit constant (qword) used in FUN_0052ab4e (1720-byte JPEG Huffman decoding function). Part of JPEG decoder lookup tables for Huffman symbol decoding with packed short arithmetic. |
| DAT_005da6c4 | Str_CMPEGFilePlaye | audio | char[] | offset | 1 | String literal "CMPEGFilePlayer" — MPEG audio file player class name. Used in FUN_0052e1d0. |
| DAT_008b0424 | GIF_DecompTable | file_formats | byte[] | offset | 1 | Decompression/decoding lookup table used in FUN_00531250 (1385-byte GIF/LZW-style decompression). Indexed by byte array with 2-byte stride. |
| DAT_005b7740 | DCT_TransformCoeff | renderer | float | read | 1 | Float DCT/transform coefficient in FUN_00531b50 (3910-byte DCT/color transform function). Part of 32-entry coefficient array (DAT_005b772c to 5b7768) used for discrete cosine transform or color space conversion. |
| DAT_008b5954 | DCT_OutputBuffer | renderer | float | write | 1 | Float output written by FUN_00531b50 DCT transform. One of 32 output coefficients in the color space transform. |
| DAT_008b59b0 | DCT_OutputBuffer2 | renderer | float | write | 1 | Float output written by FUN_00531b50 DCT transform. Part of 32-entry coefficient output. |
| DAT_008b5a14 | DCT_OutputBuffer3 | renderer | float | write | 1 | Float output written by FUN_00531b50 DCT transform. Part of 32-entry coefficient output. |
| DAT_008d7200 | VertexTransformConstants | renderer | byte[] | offset | 1 | Constant data block (8 bytes) referenced in FUN_00534120 (2444-byte vertex transform with packed short arithmetic). Used in SIMD vertex skinning pipeline alongside DAT_008d7228 and DAT_008d7220. |
| DAT_005da8f4 | Str_InvalidStoredB_0 | renderer | char[] | offset | 1 | Error string "Invalid stored buffer..." for D3D vertex/index buffer operations. Used in FUN_00537110. |
| DAT_005dbb30 | Str_EmptyDistanceT_0 | renderer | char[] | offset | 1 | Debug/error string "Empty distance T..." for rendering. Used in FUN_0053a4d0. |
| DAT_005dbd0c | Str_S0xX | file_formats | char[] | offset | 1 | Format string "S0x%X" for hex formatting. Used in FUN_0053f720. |
| DAT_005dbf3c | Str_WrongMtsVersio | file_formats | char[] | offset | 1 | Error string "Wrong MTS version..." — model/scene file version mismatch. Used in FUN_0054ac70. |
| DAT_005dc108 | Str_IllegalFontFil | UI | char[] | offset | 1 | Error string "Illegal font file..." — font loading error. Used in FUN_00552470. |
| DAT_005dc284 | Str_Adjacent | track | char[] | offset | 1 | String literal "Adjacent" — track adjacent sector/segment name. Used in FUN_0055a790. |
| DAT_005dc2c0 | Str_Special2 | track | char[] | offset | 1 | String literal "Special2" — track special feature/section. Used in FUN_0055a910. |
| DAT_008b8dec | AudioStreamLoopFlag | audio | int | write | 1 | Loop/flag bit written in FUN_0055bd20 (160-byte audio streaming function). Set as `param_5 & 1`. Controls audio stream looping behavior. |
| DAT_005dc574 | GIF_CodeSize | file_formats | int | read | 1 | Integer code size constant for GIF/LZW decompression. Used in FUN_0055f0d0 alongside DAT_005dc524/4cc/480. |
| DAT_005dc524 | GIF_CodeMask | file_formats | word | read | 1 | Word mask value for GIF/LZW bit packing. Used in FUN_0055f0d0. |
| DAT_005dc4cc | GIF_CodeClear | file_formats | int | read | 1 | Clear code constant for GIF/LZW decompression. Used in FUN_0055f0d0. |
| DAT_005dc480 | GIF_CodeEOF | file_formats | int | read | 1 | EOF code constant for GIF/LZW decompression. Used in FUN_0055f0d0. |
| DAT_005e4ec4 | Str_StateChangedD | audio | char[] | offset | 1 | Debug string "StateChanged %d" for audio state changes. Used in FUN_00562ac0. |
| DAT_008cfae4 | StringParseCursor | file_formats | ptr | write | 1 | Mutable string parse cursor pointer. Used in FUN_00564220 (75-byte string tokenizer). Advances through string, replacing delimiters with null. Similar to strtok. |
| DAT_005e516c | FileAccessModeByte | file_formats | byte | read | 1 | Byte string constant for file access mode (mode "rb" variant). Used in FUN_00566940 (293-byte file open function). Copied to local stack for fopen call. |
| DAT_005e51c4 | Str_Lpt3 | system | char[] | offset | 1 | String literal "LPT3" — parallel port device name. Used in FUN_005687f0. |
| DAT_005e5314 | Ptr_VTable_5E5314 | system | ptr | offset | 1 | Vtable/data pointer. Used in FUN_0056d930. |
| DAT_008cfc20 | DynSolver_WS_8CFC20 | dynamics | double | write | 1 | Double-precision variable in dynamics constraint solver workspace (0x8CFC20). Written by FUN_0056fa96 (17786-byte LDL^T factorization). Part of block sparse Cholesky matrix workspace. |
| DAT_008cfcf0 | DynSolver_WS_8CFCF0 | dynamics | double | write | 1 | Double-precision variable in dynamics constraint solver workspace. Written by FUN_0056fa96 LDL^T factorization. |
| DAT_008cfff8 | DynSolver_WS_8CFFF8 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96 LDL^T factorization. |
| DAT_008d1710 | DynSolver_WS_8D1710 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace (0x8D0000 block). Read by FUN_0056fa96. |
| DAT_008d0100 | DynSolver_WS_8D0100 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d0360 | DynSolver_WS_8D0360 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d04d8 | DynSolver_WS_8D04D8 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1b08 | DynSolver_WS_8D1B08 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d05d8 | DynSolver_WS_8D05D8 | dynamics | double | write | 1 | Double-precision variable in dynamics constraint solver workspace. Written by FUN_0056fa96 LDL^T factorization. |
| DAT_008d1dc0 | DynSolver_WS_8D1DC0 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1f80 | DynSolver_WS_8D1F80 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1b40 | DynSolver_WS_8D1B40 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d2078 | DynSolver_WS_8D2078 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1548 | DynSolver_WS_8D1548 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1df8 | DynSolver_WS_8D1DF8 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1b68 | DynSolver_WS_8D1B68 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1b70 | DynSolver_WS_8D1B70 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1a88 | DynSolver_WS_8D1A88 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1d48 | DynSolver_WS_8D1D48 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1fd8 | DynSolver_WS_8D1FD8 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d3b00 | DynSolver_WS_8D3B00 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d19c0 | DynSolver_WS_8D19C0 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1ff8 | DynSolver_WS_8D1FF8 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d1d80 | DynSolver_WS_8D1D80 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d09b0 | DynSolver_WS_8D09B0 | dynamics | double | read | 1 | Double-precision variable in dynamics constraint solver workspace. Read by FUN_0056fa96. |
| DAT_008d3a1c | DynSolver_Ptr_8D3A1C | dynamics | int | offset | 1 | Integer/index in dynamics constraint solver workspace (0x8D3A1C). Used by FUN_0056fa96 LDL^T factorization. |
| DAT_008d2198 | DynSolver_WS_8D2198 | dynamics | byte | offset | 1 | Workspace byte in dynamics constraint solver (0x8D2198). Used by FUN_00575bbd (13241-byte LDL^T factorization solver). |
| DAT_008d2488 | DynSolver_WS_8D2488 | dynamics | double | write | 1 | Double-precision variable in dynamics constraint solver. Written by FUN_00575bbd LDL^T factorization. |
| DAT_008d2808 | DynSolver_WS_8D2808 | dynamics | double | offset | 1 | Double-precision variable in dynamics constraint solver workspace. Used by FUN_00575bbd. |
| DAT_008d2cc8 | DynSolver_WS_8D2CC8 | dynamics | byte | offset | 1 | Workspace byte in dynamics constraint solver (0x8D2CC8). Used by FUN_00575bbd. |
| DAT_008d3bbc | DynSolver_WS_8D3BBC | dynamics | int | offset | 1 | Workspace integer in dynamics constraint solver. Used by FUN_00575bbd. |
| DAT_0057bc90 | DynSolver_WS_57BC90 | dynamics | byte | offset | 1 | Workspace in dynamics constraint solver. Offset pattern access by FUN_0057b9e0 solver functions. |
| DAT_008d3690 | DynSolver_WS_8D3690 | dynamics | byte | offset | 1 | Workspace byte in dynamics constraint solver (0x8D3690). Used by FUN_00575bbd LDL^T factorization. |
| DAT_005b8a40 | PTR_VTABLE_5B8A40 | system | ptr | offset | 1 | Vtable pointer for linked-list/collection class. Assigned as second vtable in FUN_0057aef0 (133-byte destructor freeing linked list items). |
| DAT_005e5498 | Str_NetworkDown | network | char[] | offset | 1 | String literal "Network down" — network connection failure message. Used in FUN_0057cb50. |
| DAT_005e5dc0 | Str_TheAttemptToCo | network | char[] | offset | 1 | Error string "The attempt to connect..." — network connect failure message. Used in FUN_0057d400. |
| DAT_005e5518 | Str_TheConnectionH_0 | network | char[] | offset | 1 | Error string "The connection has..." — network disconnect message. Used in FUN_0057d400. |
| DAT_005bac58 | PTR_VTABLE_5BAC58 | system | ptr | offset | 1 | Vtable/struct pointer for file handle/thread class. Used in FUN_00581b30 (231-byte destructor with CloseHandle call). |
| DAT_005bafc8 | PTR_VTABLE_5BAFC8 | system | ptr | offset | 1 | Vtable/struct pointer. Used in FUN_005835f0 (85-byte constructor calling FUN_00568ba0/be0). |
| DAT_005bb2c0 | PTR_VTABLE_5BB2C0 | system | ptr | offset | 1 | Vtable/struct pointer. Used in FUN_005867b0 (77-byte destructor calling FUN_0059b390 and FUN_00499ae0). |
| DAT_005e6468 | LocaleCompareString | system | char[] | offset | 1 | Locale string constant "C" (used in setlocale/locale comparison). Used in FUN_00588e4e (280-byte locale setup function). Compared with strcmp against param_1 to check for "C" locale. |
| DAT_008d3eb0 | TerminateOnExitFlag | system | int | read | 1 | Flag read in FUN_00589cc6 (156-byte terminate/atexit handler). When == 1, calls TerminateProcess on current process. Controls exit behavior. |
| DAT_005e6728 | VKeyToAsciiTable | system | byte | offset | 1 | Virtual key to ASCII conversion table boundary (end of 0x5e65c0 table). Used in FUN_0058af5c (115-byte vkey lookup). Iterates 2-entry structs {vkey, ascii} until hitting this address. |
| DAT_005e7720 | CRP_MathConst | math_util | double | read | 1 | Double constant read in FUN_0058de2c (304-byte CRT math classification function). Written to param_4 output. Part of MSVC math classification/signaling NaN handling. |
| DAT_008d3f64 | LocaleBufferHandle | system | dword | offset | 1 | Locale string buffer handle. Used in FUN_0058f4f2 (469-byte locale init function). Gets value from sub_5968F6 locale query and stored via off_5E9AC0 buffer array (3 entries). |
| DAT_005e6d74 | Ptr_VTable_5E6D74 | system | ptr | read | 1 | Vtable/function pointer table. Used in FUN_005904f7. |
| DAT_005e774c | MathConst_5E774C | math_util | tbyte | read | 1 | Extended-precision (10-byte) math constant referenced in FUN_00591e89 (86-byte stub). |
| DAT_008d400c | LocaleMonthFormat | system | word | read | 1 | Word-sized locale formatting flag read in FUN_0059249b (428-byte date/time formatting function). Controls date/month display format cascade. |
| DAT_005b990c | Str_RuntimeErrorPr | system | char[] | offset | 1 | String literal "Runtime error: ..." — MSVC runtime error message. Used in FUN_005932f3. |
| DAT_005e9b58 | CodePageTable | system | byte[] | offset | 1 | Code page translation table (8-byte stride entries for character range mapping). Used in FUN_00596e40 (429-byte codepage init). Indexed for character class table setup (DAT_008d47e0). |
| DAT_008d4200 | LocaleSystemType | system | int | read | 1 | Locale system type flag read in FUN_00597d3c (264-byte GetLocaleInfo wrapper). Values: 0=uninitialized, 1=Unicode (GetLocaleInfoW), 2=ANSI (GetLocaleInfoA). Determines WideChar/MultiByte path. |
| DAT_005bb590 | PTR_VTABLE_5BB590 | system | ptr | offset | 1 | Vtable pointer for MSVC iostream/fstream class. Used in FUN_00599cb7 (96-byte constructor). Assigned `&PTR_FUN_005b9ca0` then `&PTR_FUN_005b9c68` via exception-safe init. |
| DAT_005b9d68 | Str_StringTooLong | system | char[] | offset | 1 | String literal "string too long" — MSVC STL string error message. Used in FUN_0059ad49. |
| DAT_005bd0d0 | Str_Start | system | char[] | offset | 1 | String literal "Start" — startup/init string constant. Used in FUN_008d8000. |
| DAT_0059ed70 | LifetimeClampLowerBound | dynamics | double | read | 1 | Double threshold constant used as lower bound in FUN_00442060. Paired with DAT_0059ed68 (upper bound). Controls lifetime averaging clamp range. |
| DAT_0059ed78 | Unknown_Double_59ED78 | dynamics | double | read | 1 | Double constant read in FUN_00442060 as multiplier for param_3. Part of lifetime/damage calculation. |
| DAT_0059e890 | Unknown_Double_59E890 | dynamics | double | read | 1 | Double constant read in FUN_00442060 and FUN_004441f0. Used as frequency multiplier with fsin/fcos for oscillatory lifetime/damage calculations. |
| DAT_007ca3b8 | AudioSourcePtr_7CA3B8 | audio | ptr | read | 1 | Audio source object pointer compared in FUN_0044ff50. Checked against audio source pointers for channel routing selection. |
| DAT_0059e600 | Unknown_Float_59E600 | physics | float | read | 1 | Float constant read in FUN_00461900 as scale factor: `(float)*(ushort *)(param_1+0x7c) * _DAT_0059e600`. Used in session config parsing for float conversion. |
| DAT_0059f200 | Unknown_Float_59F200 | camera | float | read | 1 | Float constant read in FUN_00466350 as grid position scaling factor: `(float)local_4 * _DAT_0059f200`. Also used with DAT_0059e87c for camera/control adjustment. |
