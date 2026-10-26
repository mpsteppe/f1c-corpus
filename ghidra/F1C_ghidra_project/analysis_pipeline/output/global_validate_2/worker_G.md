=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be684 | FeaturesString | setup | char* | offset | 1 | String constant "Features" — INI section name for feature flags in game config |
| DAT_005be5a8 | RaceQualRatioString | setup | char* | offset | 1 | String constant "RaceQualRatio" — INI key for race/qualifying ratio setting |
| DAT_008aff90 | Unknown_Float_8AFF90 | physics | float | write | 1 | Float constant written by FUN_00402690 — likely physics initialization parameter |
| DAT_007d07a0 | UISliderMax | UI | float | read | 1 | UI slider maximum threshold. Compared against _DAT_0059e448 (0.05f) in FUN_00404890. Controls UI slider range clamping |
| DAT_005be8fc | Unknown_Float_5BE8FC | renderer | float | read | 1 | Float constant read by FUN_00409a00 — likely renderer or game parameter |
| DAT_005bea8c | CommentaryStarString | audio/game | char* | offset | 1 | String constant "CommentaryStar" — INI key for commentary star driver setting |
| DAT_005beb3c | PlayerString | game | char* | offset | 1 | String constant "Player" — used for player name/key lookup in config/INI files |
| DAT_0059e750 | VtablePtr_59E750 | game | ptr | offset | 1 | Vtable/function pointer table reference — used in object construction at FUN_0040fe50 |
| DAT_005c23a0 | SbString | setup/driver | char* | offset | 1 | String constant "Sb" — driver abbreviation or team short name |
| DAT_005c256c | HeinzHaraldFrentzenName | setup/driver | char* | offset | 1 | String constant "Heinz-Harald Frentzen" — driver name string |
| DAT_005c24a0 | FelipeMassaName | setup/driver | char* | offset | 1 | String constant "Felipe Massa" — driver name string |
| DAT_0059e810 | LapTimeThreshold1 | session/physics | float | read | 1 | Lap time threshold compared against param_1 in FUN_0041a500. Part of cascading time threshold checks for session timing events (0x22/0x23/0x114-0x117 event IDs) |
| DAT_005c2894 | Team2000ProstString | setup | char* | offset | 1 | String constant "2000 Prost" — team/year designation string |
| DAT_005c2780 | Team2002MinardiString | setup | char* | offset | 1 | String constant "2002 Minardi" — team/year designation string |
| DAT_005c29f8 | SaveString | game | char* | offset | 1 | String constant "Save" — file/save operation name |
| DAT_005c2c40 | VehiclesDirString | setup | char* | offset | 1 | String constant "VehiclesDir" — INI key for vehicles directory path |
| DAT_005c2b44 | VsyncString | setup | char* | offset | 1 | String constant "Vsync" — INI key for vertical sync setting |
| DAT_005c2fa0 | OptionsDirFormat | setup | char* | offset | 1 | String constant "OptionsDir %s" — format string for options directory path |
| DAT_005c2e54 | WindowedModeString | setup | char* | offset | 1 | String constant "WindowedMode" — INI key for windowed mode setting |
| DAT_005c3084 | AccessCheckFailed | security | char* | offset | 1 | String constant "access check failed" — Windows security/ACL error message used in FUN_00423250 |
| DAT_005c3198 | StallString | physics | char* | offset | 1 | String constant "Stall" — INI key for engine stall configuration |
| DAT_0059e950 | EngineRPMThreshold | physics | double | read | 1 | Double-precision RPM threshold in FUN_004270a0 (9165-byte engine/vehicle physics). Used in scaling computations with _DAT_0059e450 |
| DAT_005c3304 | DS5Format | setup | char* | offset | 1 | String constant "%dS %d" — format string for display seconds/minutes |
| DAT_007cc260 | Unknown_Int_7CC260 | collision | int | read | 1 | Integer constant read by FUN_0042c440 — collision system parameter |
| DAT_007cbf24 | Unknown_Int_7CBF24 | game | int | read | 1 | Integer read by FUN_0042c690 — game loop timer counter. Compared against DAT_007c5694 in time-sliced update loop (every 10th frame triggers vehicle update) |
| DAT_005c3610 | EnteredGameEnterString | game | char* | offset | 1 | String constant "Entered GameEnter" — debug/log string for game state entry |
| DAT_005c3770 | VtablePtr_5C3770 | game | ptr | offset | 1 | Vtable/function pointer reference — used in object construction at FUN_0042ed70 |
| DAT_005c3e78 | WedgeSettingString | setup | char* | offset | 1 | String constant "WedgeSetting" — INI key for vehicle wedge/cross-weight setting |
| DAT_005c3cf4 | FrontToeInSettingString | setup | char* | offset | 1 | String constant "FrontToeInSetting" — INI key for front toe-in adjustment |
| DAT_005c3adc | RearBrakeSettingString | setup | char* | offset | 1 | String constant "RearBrakeSetting" — INI key for rear brake bias setting |
| DAT_005c3940 | PressureSettingString | setup | char* | offset | 1 | String constant "PressureSetting" — INI key for tire pressure setting |
| DAT_0059ea78 | DamperMultiplier | physics | double | read | 1 | Double multiplier in FUN_00430a50 (tire/damper physics). Multiplied against load value at param_1+0xc38. Used in both normal (DAT_008aeec0==0) and alternate (==1) damper branches |
| DAT_005c4048 | SDFormat | setup | char* | offset | 1 | String constant "%s%d" — format string for name+number concatenation |
| DAT_005c40f8 | SpringString | setup | char* | offset | 1 | String constant "Spring" — INI key for spring rate setting |
| DAT_0059eb60 | AntiRollScale | physics | double | read | 1 | Double multiplier in FUN_00438130 (anti-roll bar / suspension physics). Multiplied against motion ratio at param_1+0x314. Clamped between _DAT_0059e428 and _DAT_0059e420 |
| DAT_0059ebd8 | Unknown_Double_59EBD8 | physics | double | read | 1 | Double constant read by FUN_00439210 — physics suspension/thermal parameter |
| DAT_0059ec68 | Unknown_Double_59EC68 | physics | double | read | 1 | Double constant read by FUN_0043da10 — engine/thermal parameter |
| DAT_0059ed78 | RandomOffsetScale | physics/ai | float | read | 1 | Float multiplier in FUN_00442060 (AI steering noise). Multiplied against param_3 (steering magnitude), then used with ring-buffer random value to introduce steering oscillation via sin/cos. Part of AI steering jitter/error model |
| DAT_0059eeb0 | TireSlipParam | physics/tire | double | read | 1 | Double constant in FUN_004441f0 (9101-byte tire physics). Used in tire slip/grip computations |
| DAT_0059ee20 | TireSlipThreshold | physics/tire | double | read | 1 | Double threshold in FUN_004441f0 (9101-byte tire physics). Used in tire slip angle or force calculations |
| DAT_0059eef8 | OilTempBlendFactor | physics/engine | double | read | 1 | Double constant in FUN_00447b10 (engine thermal model). Added to param_1+0x19c (oil temperature) for interpolation. Used with _DAT_0059eba0 in temperature blending calculation via FUN_00447ab0 |
| DAT_007ca3f4 | CollisionScaleZ | collision | float | write | 1 | Initialized to 1.0f (0x3f800000) in FUN_0044c6e0. Z-axis scale component in collision grid struct (alongside DAT_007ca3e8=3, _7ca3ec=0, _7ca3f0=0) |
| DAT_007ca584 | CollisionBoundMax | collision | float | write | 1 | Initialized to -1.0f (0xbf800000) in FUN_0044d280. Maximum bound value for collision boundary struct (alongside _7ca57c=0x3d, _7ca580=0, _7ca588=0) |
| DAT_007ccd24 | CollisionCellOffsetY | collision | int | write | 1 | Initialized to 0 in FUN_0044d520. Y-offset component in collision grid cell struct (alongside _7ccd20=0x11, _7ccd28=0, _7ccd2c=0, _7ccd30=0, _7ccd34=0) |
| DAT_007cc9cc | CollisionAudioSource | audio/collision | ptr | offset | 1 | Audio source pointer used in FUN_0044ff50 (5968-byte audio/collision function). Compared against known audio buffer pointers (DAT_007ca3b8, DAT_007cc9bc) for audio channel routing |
| DAT_005ad3c0 | CollisionTableEntry0 | collision | int | read | 1 | Collision behavior table entry read by FUN_0044ff50. Part of collision response parameter table |
| DAT_005ad3e0 | CollisionTableEntry1 | collision | int | read | 1 | Collision behavior table entry read by FUN_0044ff50. Part of collision response parameter table |
| DAT_007d2314 | VehicleEffectRadius | renderer/vehicle | float | read | 1 | Float constant in FUN_00451720 (3910-byte vehicle effect renderer). Used in vehicle part visibility/effect culling based on DAT_007c56ac (enable flag) |
| DAT_007ccfec | CollisionGridDataPtr | collision | ptr | read | 1 | Collision grid data pointer read by FUN_00452b10. Stored as param_1[7] reference to collision grid structures (DAT_007ccd50, DAT_007ccd38, etc.) |
| DAT_007cd014 | DamperBoundA | physics/suspension | float | write | 1 | Float written in FUN_004537b0 (2590-byte suspension init). Copied from param_1+0x1140. Clamped against companion threshold. Part of suspension damper boundary parameters |
| DAT_005ad1e0 | Unknown_Float_5AD1E0 | physics | float | read | 1 | Float constant read by FUN_004eb430 — brake/tire physics parameter |
| DAT_005c562c | ReverseGearString | input/controls | char* | offset | 1 | String constant "ReverseGear" — INI/control key for reverse gear input binding |
| DAT_005c5514 | LookBehindString | input/controls | char* | offset | 1 | String constant "LookBehind" — INI/control key for look-behind input binding |
| DAT_005c5688 | EnteredHwinputString | input | char* | offset | 1 | Debug string "Entered Hwinput" — hardware input initialization log |
| DAT_005c5808 | SRadiusFormat | setup | char* | offset | 1 | String constant "sRadius %f" — format string for spring radius display |
| DAT_0059f040 | Unknown_Double_59F040 | physics | double | read | 1 | Double constant read by FUN_00459ae0 (3411-byte function) — physics transmission/clutch parameter |
| DAT_005c5bc4 | GameverString | game | char* | offset | 1 | String format "1.3f" — game version string format, used in FUN_0045cde0 with _DAT_0059f090 |
| DAT_007d10d4 | SessionFlagByte | session | byte | read | 1 | Session state byte read by FUN_0045d890 — session state machine flag |
| DAT_005c5e74 | SDMsFormat | setup | char* | offset | 1 | String constant "%d %s" — format string for session data display |
| DAT_005c610c | TheServerFormat | network | char* | offset | 1 | String constant "The server %s %s" — network server message format |
| DAT_007d0f54 | NetQualifyingTime | network/race | float | read | 1 | Float read/written in FUN_00461900 (878-byte session config parser). Extracted from param_1+0x74 as short, cast to float. Part of network session parameter sync |
| DAT_007cec5c | NetSessionTimeout | network/race | float | read | 1 | Session timeout value read in FUN_00461900. Part of network session configuration sync |
| DAT_005c6290 | CouldNotFindSessionString | network | char* | offset | 1 | Error string "Could not find session" — network session not found message |
| DAT_005c65a4 | AutojoinAttemptString | network | char* | offset | 1 | String constant "Autojoin attempt" — network autojoin debug/log string |
| DAT_0059f1fc | SteeringSensitivity | input | float | read | 1 | Float multiplier in FUN_00466350 (768-byte input handling). Scaled with _DAT_0059f200 for steering/controller input. Used with param_1 offsets 0x3e-0x42 for controller input processing |
| DAT_005c6990 | DriversChampionshipString | UI | char* | offset | 1 | String constant "Drivers Championship" — UI standings/screen title string |
| DAT_005c6abc | FillerString | UI/game | char* | offset | 1 | String constant / ASCII separator — UI formatting or file I/O separator |
| DAT_007cd860 | TrackDataBuffer | track | char[] | offset | 1 | Track data string buffer (31 bytes) — used in FUN_00470490 for track file path construction. Copied via string copy function when track ID matches specific values |
| DAT_005c71c4 | TrackNameSuffix | track/setup | dword | read | 1 | Track name suffix data read by FUN_004793ec (495-byte track path builder). Used with DAT_005c71c0, _5c71c8 to construct track directory and file paths from path components |
| DAT_005c72fc | ForwardScanFastString | renderer | char* | offset | 1 | String constant "ForwardScanFast" — renderer or display setting INI key |
| DAT_005c7494 | LocationString | UI | char* | offset | 1 | String constant "Location" — UI/track location display string or INI key |
| DAT_005ac118 | VtablePtr_5AC118 | renderer | ptr | offset | 1 | Vtable pointer assigned to param_1 in FUN_0048d3a0 (renderer/scene object constructor) |
| DAT_005cc6ac | EnterTargetString | renderer | char* | offset | 1 | String constant "EnterTarget" — render target or effect entry string |
| DAT_005cc7c8 | SecondaryOffsetString | renderer | char* | offset | 1 | String constant "SecondaryOffset" — renderer offset/shader parameter string |
| DAT_005cc80c | FocusString | UI/renderer | char* | offset | 1 | String constant "Focus" — camera focus or UI focus setting string |
| DAT_005cc9a8 | EaIntroBikString | game | char* | offset | 1 | String constant "EaIntro.bik" — EA intro video filename string |
| DAT_005ccb00 | SavingReplayString | game | char* | offset | 1 | String constant "SavingReplay00" — replay save filename format string |
| DAT_005ccc0c | Unknown_Float_5CCC0C | game/UI | float | read | 1 | Float constant in menu/UI function FUN_0049bbb0 — UI layout parameter |
| DAT_005ccb80 | VtablePtr_5CCB80 | game | ptr | read | 1 | Vtable/function pointer reference read by FUN_0049ca00 |
| DAT_005ccb84 | VtablePtr_5CCB84 | game | ptr | read | 1 | Vtable/function pointer reference read by FUN_0049cd80 |
| DAT_007cc234 | GameUIFeatureFlag | game/UI | int | read | 1 | Flag checked in FUN_0049f790 (213-byte UI/menu routing). When non-zero, enables UI feature selection based on DAT_005ea518/528 state and bit flags at DAT_007cf7ac |
| DAT_005cd048 | EnteredOptionsString | UI | char* | offset | 1 | Debug string "Entered Options" — UI options screen entry log |
| DAT_007ce2c0 | SessionInitFlag | session | int | write | 1 | Session initialization flag written by FUN_004a1200 — part of session state initialization |
| DAT_005cd2d8 | FuelInString | UI/setup | char* | offset | 1 | String constant "Fuel In" — UI label for fuel amount setting |
| DAT_005cd458 | LManString | UI | char* | offset | 1 | String constant "LMan" — UI text (likely "Lap Man" or leaderboard abbreviation) |
| DAT_005cd33c | UnableToSetupAIString | UI/ai | char* | offset | 1 | String "Unable to setup AI" — AI setup error message |
| DAT_005c7224 | WetCompoundString | setup/tire | char* | offset | 1 | String constant "WetCompound" — INI key for wet tire compound setting |
| DAT_005c6e14 | VtablePtr_5C6E14 | game | ptr | offset | 1 | Vtable/function pointer reference at FUN_004a58b0 |
| DAT_005cd6f4 | PractString | UI/radio | char* | offset | 1 | String constant "Pract" — UI abbreviation for Practice session |
| DAT_005d1eb8 | SpinRecoveryString | setup | char* | offset | 1 | String constant "SpinRecovery" — INI key for spin recovery assist setting |
| DAT_005d1bc4 | SpeedSensitiveString | setup | char* | offset | 1 | String constant "SpeedSensitive" — INI key for speed-sensitive steering setting |
| DAT_005d1970 | RunPractice3String | setup | char* | offset | 1 | String constant "RunPractice3" — INI key for practice session count setting |
| DAT_005d16d8 | WhetherWeatherString | setup | char* | offset | 1 | String constant "WhetherWeather" — INI key for weather selection setting |
| DAT_005d14d8 | AdditionalVolumeString | setup/audio | char* | offset | 1 | String constant "AdditionalVolume" — INI key for additional audio volume setting |
| DAT_005d1328 | PitHornAmbientString | setup/audio | char* | offset | 1 | String constant "PitHornAmbient" — INI key for pit horn/ambient sound setting |
| DAT_005d115c | AutomapString | setup/UI | char* | offset | 1 | String constant "AutoMap" — INI key for auto-map display setting |
| DAT_005d0ee0 | VehicleFlowOffString | setup | char* | offset | 1 | String constant "VehicleFlowOff" — INI key for vehicle flow visualization toggle |
| DAT_005d0c0c | GlanceAngleString | setup/input | char* | offset | 1 | String constant "GlanceAngle" — INI key for glance/LOOK angle setting |
| DAT_005d09a0 | InCarDashString | setup/UI | char* | offset | 1 | String constant "InCarDash" — INI key for in-car dashboard display setting |
| DAT_005d071c | GameOptionsString | setup/UI | char* | offset | 1 | String constant "GameOptions" — INI section key for game options |
| DAT_005d0528 | AiDriverStrengthString | setup/ai | char* | offset | 1 | String constant "AIDriverStrength" — INI key for AI driver strength multiplier |
| DAT_005d0220 | OffsetEachScheduleString | setup | char* | offset | 1 | String constant "OffsetEachSchedule" — INI key for session schedule offset |
| DAT_005cffb8 | QualifyLapsString | setup | char* | offset | 1 | String constant "QualifyLaps" — INI key for qualifying laps count |
| DAT_005cfd00 | FuelConsumptionString | setup | char* | offset | 1 | String constant "FuelConsumption" — INI key for fuel consumption rate |
| DAT_005cf924 | MultiAllowedAiString | setup/network | char* | offset | 1 | String constant "MultiAllowedAi" — INI key for multiplayer AI allowance |
| DAT_005cf580 | CollisionThresholdString | setup | char* | offset | 1 | String constant "CollisionThreshold" — INI key for collision threshold setting |
| DAT_005cf150 | PreviousGameDataString | setup | char* | offset | 1 | String constant "PreviousGameData" — INI key for previous game data import |
| DAT_005cee48 | Vfx3dHeadTrackString | setup/renderer | char* | offset | 1 | String constant "VFX3DHeadTrack" — INI key for 3D head tracking effect setting |
| DAT_005ceb7c | Controller2RzString | setup/input | char* | offset | 1 | String constant "Controller2Rz" — INI key for controller 2 rotation-Z axis binding |
| DAT_005ce980 | ControlFourthGearString | setup/input | char* | offset | 1 | String constant "ControlFourthGear" — INI key for 4th gear control binding |
| DAT_005ce7ac | ControlPauseString | setup/input | char* | offset | 1 | String constant "ControlPause" — INI key for pause control binding |
| DAT_005ce520 | FfbThrottleFxOnString | setup/input | char* | offset | 1 | String constant "FFBThrottleFxOn" — INI key for FFB throttle effect toggle |
| DAT_005ce024 | FfbSteerForceGString | setup/input | char* | offset | 1 | String constant "FFBSteerForceG" — INI key for FFB steering force gain |
| DAT_005cdbd8 | ScalesActualBrakString | setup/input | char* | offset | 1 | String constant "ScalesActualBrake" — INI key for brake pedal scaling |
| DAT_005cd7f8 | FfbJoy22dAxis2String | setup/input | char* | offset | 1 | String constant "FFBJoy22dAxis2" — INI key for FFB joystick axis mapping |
| DAT_005acc2c | VtablePtr_5ACC2C | data/renderer | ptr | offset | 1 | Vtable pointer assigned in FUN_004b19d0 (26-byte constructor). Object stores 0, -1, 0, -1 as initial field values |
| DAT_008ad008 | NetworkPacketFlag | network | byte | write | 1 | Byte written in FUN_004b3400 (1512-byte network packet handler). Part of packet processing for vehicle grid array at DAT_005ef9a0 |
| DAT_005acd60 | SteeringWheelAngleCoeff | input/physics | float | read | 1 | Steering wheel angle coefficient in FUN_004b67d0 (201-byte steering helper). Selected by case index (0-3) from param_1+0x9ac-1. Defines steering angle multiplication for different sensitivity modes |
| DAT_005d2504 | ReplayRecordingString | UI/game | char* | offset | 1 | String constant "ReplayRecording" — UI/info string for replay recording status |
| DAT_005acd98 | Unknown_Float_5ACD98 | renderer | float | read | 1 | Float constant read by FUN_004bccc0 — renderer/D3D parameter |
| DAT_005acdb0 | SessionScoringParameter | scoring | int | read | 1 | Integer constant passed to FUN_004be9e0 in FUN_004bf0a0 (736-byte session scoring). Used with DAT_007cea5c (engine wear mode) and DAT_007c56a4 (session type) for scoring initialization |
| DAT_005d2690 | CurrentGridPosString | UI | char* | offset | 1 | String constant "CurrentGridPos" — UI/display string for grid position |
| DAT_005d2880 | RaceoverDFormat | UI | char* | offset | 1 | String constant "Raceover %d" — format string for race-over display |
| DAT_005d2d94 | AvgRaceDistanceString | UI | char* | offset | 1 | String constant "AvgRaceDistance" — UI/statistics string for average race distance |
| DAT_005d2b38 | BestLapTimeFormat | UI | char* | offset | 1 | String constant "BestLapTime %f" — format string for best lap time display |
| DAT_005d2f5c | TeamStartsString | UI | char* | offset | 1 | String constant "TeamStarts" — UI/statistics string for team starts count |
| DAT_005d3138 | IncorrectSeasonString | UI/game | char* | offset | 1 | String "1 Incorrect Season" — error message for incorrect season format |
| DAT_005d3380 | EnteredSoundEnvString | audio | char* | offset | 1 | Debug string "Entered SoundEnv" — audio environment initialization log |
| DAT_005ace6c | VtablePtr_5ACE6C | audio | ptr | offset | 1 | Vtable pointer assigned in FUN_004c9a50 (265-byte audio object factory). Case 7 creates 0x20-byte audio object with this vtable |
| DAT_005d3650 | RainString | renderer | char* | offset | 1 | String constant "Rain" — rain/weather render effect string |
| DAT_005d3530 | GlobalshadowString | renderer | char* | offset | 1 | String constant "GlobalShadow" — global shadow render effect string |
| DAT_005d3748 | SrcalphaString | renderer | char* | offset | 1 | String constant "SrcAlpha" — D3D alpha blend source factor string |
| DAT_007cfa04 | ParticleFlags | renderer/particle | int | read | 1 | Particle system flags read by FUN_004ccb30 (653-byte particle update). Bit 0-1 checked for particle behavior. Value 1 enables vehicle-relative particle positioning using DAT_007c54e0 vehicle data |
| DAT_005d385c | TirewallString | renderer | char* | offset | 1 | String constant "Tirewall" — tire wall render object string |
| DAT_005d3940 | LptreeString | renderer | char* | offset | 1 | String constant "LPTree" — low-poly tree render object string |
| DAT_005d3a90 | WcnumberString | renderer | char* | offset | 1 | String constant "WC Number" — waypoint/checkpoint number label string |
| DAT_005d3c54 | Pdoor02dString | renderer | char* | offset | 1 | String constant "PDoor02d" — pit door / garage door render object string |
| DAT_005d4054 | LocalSettingsString | setup | char* | offset | 1 | String constant "LocalSettings" — INI section for local/player settings |
| DAT_005d3e08 | DriveaidsExtraString | setup | char* | offset | 1 | String constant "DriveAidsExtra" — INI section for extra driving aids settings |
| DAT_005d3ca0 | RacetimeDFormat | setup/UI | char* | offset | 1 | String constant "RaceTime %02d:%06.3f" — format string for race time display |
| DAT_005d42c4 | Ptglow01String | renderer | char* | offset | 1 | String constant "PTGlow01" — particle glow texture name string |
| DAT_005d434c | DefaultScoringString | setup | char* | offset | 1 | String constant "DefaultScoring" — INI key for default scoring system |
| DAT_005d458c | PosYMFormat | UI | char* | offset | 1 | String constant "Pos Y: %f" — format string for Y position display in UI |
| DAT_005d4478 | UndertrayRideHeightString | setup | char* | offset | 1 | String constant "UndertrayRideHeight" — INI key for undertray ride height setting |
| DAT_005d46bc | SkippingUnexpectedString | setup | char* | offset | 1 | String constant "Skipping unexpected" — parser error/warning string |
| DAT_005d47c4 | HeatingString | physics/thermal | char* | offset | 1 | String constant "Heating" — INI key or debug string for tire/brake heating |
| DAT_005d4880 | BadSyntaxInFileString | setup | char* | offset | 1 | String constant "Bad syntax in file" — file parser error string |
| DAT_005d4a58 | VtablePtr_5D4A58 | renderer | ptr | read | 1 | Vtable/function pointer reference read by FUN_004d8ab0 |
| DAT_005ad018 | VtablePtr_5AD018 | renderer | ptr | offset | 1 | Vtable pointer assigned in FUN_004daea0 (396-byte factory). Case 2 creates object with this vtable |
| DAT_005d4c94 | ArmsString | setup | char* | offset | 1 | String constant "Arms" — INI key for suspension arms geometry |
| DAT_005d4cd8 | VehdirString | setup | char* | offset | 1 | String constant "VehDir" — INI key for vehicle directory path |
| DAT_005d4d94 | FwingString | setup | char* | offset | 1 | String constant "FWing" — INI key for front wing geometry |
| DAT_005ad158 | Unknown_Float_5AD158 | physics | float | read | 1 | Float constant read by FUN_004e19d0 (1536-byte function) — vehicle physics node parameter |
| DAT_007d01e8 | AIDifficultyScale | ai | float | read | 1 | Float constant in FUN_004e5f60 (3593-byte AI driving function). Used in AI throttle/brake difficulty scaling |
| DAT_005ad1e0 | WheelBrakeTorqueMult | physics/brake | float | read | 1 | Float multiplier in FUN_004eb430 (2029-byte brake physics). Used in brake torque computation during wheel brake force distribution |
| DAT_007c8884 | VehicleDamageFlag | physics/damage | int | write | 1 | Flag written by FUN_004f18c0 (403-byte vehicle damage/repair). Set when vehicle damage parameters computed — gates damage state updates |
| DAT_005d4f30 | RearWingCollPanelString | setup | char* | offset | 1 | String constant "RearWingCollPanel" — INI key for rear wing collision panel setting |
| DAT_005d5258 | BrakeTorqueString | setup | char* | offset | 1 | String constant "BrakeTorque" — INI key for brake torque setting |
| DAT_005d511c | PackerRangeString | setup | char* | offset | 1 | String constant "PackerRange" — INI key for suspension packer range setting |
| DAT_005d52fc | FenderFlareRangeString | setup | char* | offset | 1 | String constant "FenderFlareRange" — INI key for fender flare range setting |
| DAT_005d56b0 | LaunchRPMLogicString | setup | char* | offset | 1 | String constant "LaunchRPMLogic" — INI key for launch RPM logic setting |
| DAT_005d5528 | RadiatorCoolingString | setup | char* | offset | 1 | String constant "RadiatorCooling" — INI key for radiator cooling efficiency setting |
| DAT_005d6688 | RLUndertrayString | setup | char* | offset | 1 | String constant "RLUndertray" — INI key for rear-left undertray geometry |
| DAT_005d654c | CgRearSettingString | setup | char* | offset | 1 | String constant "CGRearSetting" — INI key for rear CG height setting |
| DAT_005d6418 | FWLiftSidewaysString | setup | char* | offset | 1 | String constant "FWLiftSideways" — INI key for front wing sideways lift |
| DAT_005d6344 | RWDownString | setup | char* | offset | 1 | String constant "RWDown" — INI key for rear wing downforce |
| DAT_005d6254 | RadiatorDragString | setup | char* | offset | 1 | String constant "RadiatorDrag" — INI key for radiator drag coefficient |
| DAT_005d6110 | RearWheelTrackString | setup | char* | offset | 1 | String constant "RearWheelTrack" — INI key for rear wheel track width |
| DAT_005d5f4c | Rear3rdBumpstopString | setup | char* | offset | 1 | String constant "Rear3rdBumpStop" — INI key for rear 3rd element bump stop |
| DAT_005d5da8 | LeftTrackbarSettingString | setup | char* | offset | 1 | String constant "LeftTrackbarSetting" — INI key for left track bar setting |
| DAT_005d5bd0 | Rear3rdSlowBumpString | setup | char* | offset | 1 | String constant "Rear3rdSlowBump" — INI key for rear 3rd element slow bump |
| DAT_005d5a38 | BrakePressureSettingString | setup | char* | offset | 1 | String constant "BrakePressureSetting" — INI key for brake pressure setting |
| DAT_005d5900 | DiffPumpTorqueString | setup | char* | offset | 1 | String constant "DiffPumpTorque" — INI key for differential pump torque |
| DAT_005d57c4 | DiffCoastRangeString | setup | char* | offset | 1 | String constant "DiffCoastRange" — INI key for differential coast range |
| DAT_005d6788 | F1SoundsSfxString | audio | char* | offset | 1 | String constant "F1Sounds.sfx" — sound effects filename for F1 car audio |
| DAT_005d6be8 | EngineRangeString | audio | char* | offset | 1 | String constant "EngineRange" — INI key for engine sound range mapping |
| DAT_005d6a8b | UnknownByte_5D6A8B | audio | byte | offset | 1 | Unnamed byte — part of engine range configuration data |
| DAT_005d6907 | UnknownByte_5D6907 | audio | byte | offset | 1 | Unnamed byte — part of engine range configuration data |
| DAT_005d6d20 | VfxSetVideoModeString | setup/renderer | char* | offset | 1 | String constant "VFXSetVideoMode" — INI key for video mode setting |
| DAT_008afeb4 | Unknown_Ptr_8AFEB4 | renderer | ptr | offset | 1 | Pointer/reference at FUN_004f9480 — renderer or particle system parameter |
| DAT_007cfc20 | ParticleSystemPtr | renderer/particle | ptr | read | 1 | Pointer read by FUN_004fa320 — particle system allocation/pool reference |
| DAT_005d6f48 | Unknown_Byte_5D6F48 | game | byte | read | 1 | Byte read by FUN_004fc400 — game state / menu routing flag |
| DAT_005ad2c8 | CameraFOVCoeff | renderer/camera | float | read | 1 | Float coefficient in FUN_004fd6f0 (229-byte camera/LOD). Used as multiplier for range delta: `param_1+0x8c = _DAT_005ad2c8 * fVar3 + fVar1`. Part of cascading camera distance/LOD blend computation |
| DAT_005d6f94 | ClearString | renderer | char* | offset | 1 | String constant "Clear" — renderer clear/screen option string |
| DAT_005d7008 | OnPathWetnessString | setup/track | char* | offset | 1 | String constant "OnPathWetness" — INI key for track surface wetness level |
| DAT_005d7038 | ASCIISeparator_5D7038 | setup | char* | offset | 1 | ASCII separator/constant string used in file parsing |
| DAT_005adb4c | ReadErrorString | data | char* | offset | 1 | String constant "read error" — file I/O error message, used in FUN_005020bf (67-byte read wrapper) |
| DAT_005d7748 | TextureRenderTargetData | renderer | ptr | offset | 1 | Render target data pointer in FUN_00507496 (588-byte texture/render target init). Points to 32-entry render state block; alternate _5d76c8 used when param_2[0x10]==0. Used with DAT_0059e460 (AlphaScaleFactor) for color channel scaling |
| DAT_005adc4c | VtablePtr_5ADC4C | renderer | ptr | offset | 1 | Vtable pointer assigned in FUN_0050ae22 (28-byte texture subclass constructor). Calls FUN_00507496 with param_2 and 0x10, 1 |
| DAT_005add8c | VtablePtr_5ADD8C | renderer | ptr | offset | 1 | Vtable pointer assigned in FUN_0050b462 (28-byte texture subclass constructor). Calls FUN_00507496 with param_2 and 0x10, 1 |
| DAT_005d7894 | FnPtr_5D7894 | renderer | ptr | read | 1 | Function pointer called indirectly in FUN_0050c48c. Dispatches to render function after calling FUN_0050fea7(1) |
| DAT_005d787c | FnPtr_5D787C | renderer | ptr | read | 1 | Function pointer called indirectly in FUN_0050e302. Indirection after FUN_0050fea7(1) enable call |
| DAT_005af264 | IhdrString | data/image | char* | offset | 1 | String constant "IHDR" — PNG image header chunk identifier, used in image loader |
| DAT_005af4c8 | PNGGammaValue | data/image | double | read | 1 | Double gamma value in FUN_00513b51 (57-byte PNG gamma correction). Passed to FUN_00513a56 for image gamma processing |
| DAT_005af618 | ImagePaletteData | data/image | ptr | offset | 1 | Image palette/color data in FUN_005147ea (2052-byte image decoder). Used in indexed color image processing |
| DAT_005afbf8 | InvalidColorTypeString | data/image | char* | offset | 1 | String constant "Invalid color type" — PNG decoder error message |
| DAT_005afe28 | OutOfPlaceSRGBString | data/image | char* | offset | 1 | String constant "out of place sRGB" — PNG decoder warning for misplaced sRGB chunk |
| DAT_005b0588 | ImageDataBlock | data/image | ptr | offset | 1 | Image processing data block in FUN_0051bad1 (439-byte pixel format dispatch). Selects pixel processing function based on format type (1=RGB, 2=BGR, 4=RGBA, 8=paletted) |
| DAT_005d8ad0 | SIMDQuaternionConst | math/SIMD | xmmword | read | 1 | SIMD constant in FUN_0051f89e (quaternion math). Used as XOR mask for sign bit flipping in quaternion cross-product computation |
| DAT_005d8be0 | SIMDVectorNormalizeCoeff | math/SIMD | dword | read | 1 | SIMD coefficient in FUN_0051fc80 (156-byte vector normalize). Used in Newton-Raphson refinement: `(3.0 - lenSq * invSqrt^2) * invSqrt * 0.5`. Part of fast 4-component vector normalization |
| DAT_005d8cf0 | SIMDMatrixRowMul | math/SIMD | xmmword | read | 1 | SIMD constant in FUN_00520c0e (198-byte matrix construction). Multiplied against vector components to build 4x4 rotation/transform matrix rows |
| DAT_005d8f40 | SIMDColorConvMask | math/SIMD | xmmword | read | 1 | SIMD color conversion bit masks in FUN_005289e0 (492-byte pixel format conversion). Part of a large mask table (DAT_005d8fc0 through _5d906c) used for ARGB channel extraction and float conversion |
| DAT_005d91b0 | SIMDColorConvCoeff | math/SIMD | xmmword | read | 1 | SIMD color conversion coefficients in FUN_00528cc0 (329-byte pixel processing). Companion to _5d8f40. Used with mask table (DAT_005d91e0-_5d928c) for color space transformation |
| DAT_005d93d4 | EmptyVtablePtr | CRT | ptr | read | 1 | Function pointer/vtable read by FUN_00529200 (empty function, just returns). Likely placeholder/noop handler |
| DAT_005d941c | TextureHeapBase | renderer | ptr | read | 1 | Texture memory heap base pointer returned by FUN_0052a5a8. Paired with DAT_005d9418 to define texture memory pool (heap range from _5d9418 through _5d9420 to _5da420) |
| DAT_005b0c30 | SIMD64MatrixCoeff | math/SIMD | qword | read | 1 | 3DNow! SIMD constant in FUN_0052ab4e (1720-byte 3DNow matrix transform). Used with 3DNow! 64-bit MMX register operations for matrix multiply/add |
| DAT_005da674 | CmpegBaseOpenGLString | renderer | char* | offset | 1 | String constant "CMpegBase OpenGL" — video/mpeg rendering debug string |
| DAT_008b1724 | AudioDecoderWorkspace | audio | ptr | offset | 1 | Audio decoder workspace in FUN_00531250 (1385-byte audio codec). Used with huffman/decoding tables (DAT_005b65e0, _5b6620) for compressed audio format parsing |
| DAT_008b5990 | DCTOutputBlock | audio/codec | float | write | 1 | DCT transform output storage in FUN_00531b50 (3910-byte audio codec). Stores MDCT/DCT frequency coefficients for audio codec reconstruction |
| DAT_005b7758 | DCTCoefficient_05B7758 | audio/codec | float | read | 1 | DCT coefficient in FUN_00531b50. Part of 32-element coefficient table (_5b772c through _5b77a4) used for MDCT frequency transform in audio codec |
| DAT_005b7774 | DCTCoefficient_05B7774 | audio/codec | float | read | 1 | DCT coefficient in FUN_00531b50. Part of audio codec MDCT coefficient block |
| DAT_008b5a18 | DCTWorkspace | audio/codec | float | write | 1 | DCT workspace/temporary storage in FUN_00531b50. Written during MDCT coefficient accumulation |
| DAT_005b77a4 | DCTCoefficient_05B77A4 | audio/codec | float | read | 1 | DCT coefficient in FUN_00531b50. Part of audio codec MDCT coefficient block |
| DAT_005b7c60 | AudioBitstreamPtr | audio/codec | int | read | 1 | Audio bitstream pointer read by FUN_00537110 — audio codec bitbuffer position |
| DAT_005dbb70 | OversubscribedString | audio | char* | offset | 1 | String constant "Oversubscribed" — audio/DirectSound error string (buffer oversubscription) |
| DAT_005dbc90 | ErrorEnumDisplayString | renderer | char* | offset | 1 | String constant "Error EnumDisplay" — D3D display enumeration error string |
| DAT_005dbf78 | ErrorReadingScnString | setup | char* | offset | 1 | String constant "Error reading .scn" — scene file read error string |
| DAT_005dc0c0 | ErrorAllocatingString | memory | char* | offset | 1 | String constant "Error allocating" — memory allocation error string |
| DAT_005dc23c | MovingOmniString | audio | char* | offset | 1 | String constant "MovingOmni" — audio 3D sound source/moving emitter string |
| DAT_005dc2d8 | ChangeString | renderer | char* | offset | 1 | String constant "Change" — renderer/material state change key |
| DAT_005dc3a0 | GroupString | renderer | char* | offset | 1 | String constant "Group" — renderer group/node name string |
| DAT_005dc590 | UNK_Byte_5DC590 | renderer | byte | read | 1 | Unknown byte read by FUN_0055f0d0 — renderer/D3D parameter |
| DAT_005dc51c | UNK_Dword_5DC51C | renderer | dword | read | 1 | Unknown dword read by FUN_0055f0d0 — renderer/D3D parameter |
| DAT_005dc4e4 | UNK_Dword_5DC4E4 | renderer | dword | read | 1 | Unknown dword read by FUN_0055f0d0 — renderer/D3D parameter |
| DAT_005dc496 | UNK_Byte_5DC496 | renderer | byte | read | 1 | Unknown byte read by FUN_0055f0d0 — renderer/D3D parameter |
| DAT_005e4eb4 | ValidateFormat | network | char* | offset | 1 | String constant "Validate: %s" — network validation message format |
| DAT_005e5050 | IpString | network | char* | offset | 1 | String constant "IP" — network IP address string |
| DAT_005e5174 | SerialPortName | serial/network | char* | offset | 1 | Serial port name string in FUN_00566940 (293-byte serial init). Used with _5e5178 for COM port filename construction ("COM1", "COM2", etc.) |
| DAT_005e51d4 | Lpt1String | serial | char* | offset | 1 | String constant "LPT1" — parallel port name for serial/parallel I/O |
| DAT_005e5320 | MassString | dynamics | char* | offset | 1 | String constant "Mass" — INI key for vehicle mass parameter |
| DAT_008cfc00 | LDLTWorkspaceBlock | dynamics | double | write | 1 | LDL^T factorization workspace block in sub_56FA96 (17786-byte dynamics solver). Part of constraint matrix workspace (0x8CFC00-0x8D9000) used by the sparse LDL^T decomposition solver |
| DAT_008cfcc8 | LDLTWorkspaceBlock2 | dynamics | double | write | 1 | LDL^T factorization workspace — second block in dynamics constraint solver matrix workspace |
| DAT_008cff20 | LDLTFactor_In | dynamics | double | read | 1 | LDL^T factorization input — matrix/vector read during decomposition step |
| DAT_008d15e8 | LDLTScratchVector | dynamics | double | read | 1 | LDL^T scratch/temporary vector read during constraint matrix factorization |
| DAT_008d0028 | LDLTWorkspaceResult | dynamics | double | write | 1 | LDL^T factorization output — result written during decomposition in dynamics constraint solver |
| DAT_008d39a0 | LDLTIndexBlockA | dynamics | dword | offset | 1 | LDL^T index array in constraint solver — index offsets/variable assignments for sparse matrix structure |
| DAT_008d3a14 | LDLTIndexBlockB | dynamics | dword | offset | 1 | LDL^T index array in constraint solver — secondary index/block starts for matrix blocks |
| DAT_008d1a18 | LDLTDiagBlock | dynamics | double | read | 1 | LDL^T diagonal block matrix elements read during factorization |
| DAT_008d0640 | LDLTUnknownBlock | dynamics | ptr | offset | 1 | LDL^T data block — untyped pointer to constraint matrix data region |
| DAT_008d1ce8 | LDLTSubmatrixBlock | dynamics | double | read | 1 | LDL^T submatrix block elements read during sparse factorization |
| DAT_008d1dd0 | LDLTAccumBlock | dynamics | double | read | 1 | LDL^T accumulation block — temporary/scratch values during block factorization |
| DAT_008d1960 | LDLTFactorBlock | dynamics | double | read | 1 | LDL^T factor block elements read during decomposition |
| DAT_008d1ec8 | LDLTWorkBlockA | dynamics | double | read | 1 | LDL^T work block — intermediate values in constraint solver workspace |
| DAT_008d1420 | LDLTWorkBlockB | dynamics | double | read | 1 | LDL^T work block — auxiliary storage in dynamics solver |
| DAT_008d1d20 | LDLTWorkBlockC | dynamics | double | read | 1 | LDL^T work block — coefficient storage during factorization |
| DAT_008d1988 | LDLTWorkBlockD | dynamics | double | read | 1 | LDL^T work block — intermediate values in dynamics constraint solver |
| DAT_008d1990 | LDLTWorkBlockE | dynamics | double | read | 1 | LDL^T work block — intermediate values in dynamics constraint solver |
| DAT_008d18a8 | LDLTWorkBlockF | dynamics | double | read | 1 | LDL^T work block — scalar/vector workspace in LDL^T decomposition |
| DAT_008d1b80 | LDLTWorkBlockG | dynamics | double | read | 1 | LDL^T work block — additional workspace in constraint solver |
| DAT_008d1e28 | LDLTWorkBlockH | dynamics | double | read | 1 | LDL^T work block — scratch values for constraint matrix processing |
| DAT_008d39f8 | LDLTIndexBlockC | dynamics | dword | offset | 1 | LDL^T index array — index into constraint matrix data for sparse block access |
| DAT_008d0330 | LDLTMatrixElement | dynamics | double | read | 1 | LDL^T matrix element — individual matrix value read during sparse factorization |
| DAT_008d1e48 | LDLTWorkBlockI | dynamics | double | read | 1 | LDL^T work block — temporary storage in dynamics solver workspace |
| DAT_008d1bb8 | LDLTWorkBlockJ | dynamics | double | read | 1 | LDL^T work block — additional scratch region for factorization |
| DAT_008d1cb8 | LDLTWorkBlockK | dynamics | double | read | 1 | LDL^T work block — matrix element workspace |
| DAT_008d2028 | LDLTWorkBlockL | dynamics | double | read | 1 | LDL^T work block — scalar/vector storage in dynamics solver |
| DAT_008d3b6c | LDLTSolverIndexBlock | dynamics | dword | offset | 1 | LDL^T solver index block in sub_575BBD (13241-byte LDL^T Cholesky factor solver). Index array for sparse matrix block operations |
| DAT_008d2408 | LDLTSolverDataBlock | dynamics | ptr | offset | 1 | LDL^T solver data block — untyped data region for constraint solver workspace |
| DAT_008d27c8 | LDLTSolverScratch | dynamics | ptr | offset | 1 | LDL^T solver scratch region — temporary workspace for Cholesky solve step |
| DAT_008d2b80 | LDLTSolverResultBlock | dynamics | double | write | 1 | LDL^T solver result storage — solution vector written during back-substitution |
| DAT_008d2f50 | LDLTSolverWorkBlock | dynamics | double | write | 1 | LDL^T solver workspace — intermediate values during forward/back substitution |
| DAT_008d35f0 | LDLTSolverIndexBlock2 | dynamics | ptr | offset | 1 | LDL^T solver index block — secondary index array for matrix structure |
| DAT_008d3c19 | LDLTSolverSentinel | dynamics | ptr | offset | 1 | LDL^T solver sentinel/tiny function marker at FUN_0057ae30 (10-byte thunk to FUN_00598815) |
| DAT_005e54b8 | TcpConnectionRefusedString | network | char* | offset | 1 | String constant "TCP connection refused" — network error message |
| DAT_005e5e1c | NoBufferSpaceString | network | char* | offset | 1 | String constant "No buffer space" — network buffer allocation error |
| DAT_005e55d4 | DestinationAddrRequiredString | network | char* | offset | 1 | String constant "A destination address is required" — network socket error message |
| DAT_005babdc | CRTDynamicExceptionBlock | CRT | struct | offset | 1 | CRT exception/cleanup data structure in FUN_00580de0 (642 bytes). Used with SEH exception handling and thread synchronization via WaitForSingleObject |
| DAT_005baf80 | CRTLinkedListNode | CRT/memory | struct | offset | 1 | CRTL linked list node structure in FUN_00583050 (112-byte destructor). Walks linked list and calls destructor on each node via vtable dispatch |
| DAT_005bb270 | CRTObjConstructorBlock | CRT/memory | struct | offset | 1 | CRT object construction workspace in FUN_00586320 (305-byte alloc+init). Allocates 0x834-byte block with FUN_0058a6eb for linked list management |
| DAT_005e6500 | FnPtrTable_5E6500 | CRT | ptr | read | 1 | Function pointer table/vtable read by FUN_00588d95 — CRT/exception handler dispatch table |
| DAT_005be3bc | CRTStaticInitBlock | CRT | ptr | offset | 1 | CRT static initialization data block in FUN_00589c77. Used with _5be3c0, _5be3d8, _5be000 for C++ static destructor registration |
| DAT_005b8d00 | CRTMemoryAllocStack | CRT/memory | struct | offset | 1 | CRT memory allocation data in FUN_0058ab58 (289-byte allocator). Used with exception handling and HeapAlloc fallback chain. Checks DAT_008d4908 allocator mode (2=bucket, 3=pool) |
| DAT_005b8e14 | FPUConstantDouble | CRT/math | double | read | 1 | FPU double constant in FUN_0058dd89 (163-byte FPU error handler). Used in fscale operation for extended-precision math error recovery |
| DAT_008d3f5c | CRTLocaleAllocBlock | CRT/locale | dword | offset | 1 | CRT locale/string type allocation block in sub_58F4F2 (469 bytes). Used with GetStringTypeW/A for Unicode/ANSI string type detection. Allocated via sub_58A935 memory pool |
| DAT_005e6d60 | UNK_Dword_5E6D60 | CRT | dword | read | 1 | Unknown dword read by FUN_005904f7 — CRT/internal function parameter |
| DAT_005e7644 | CRTExceptionTypeTable | CRT | ptr | read | 1 | CRT exception type dispatch table in FUN_00591ca1 (37-byte lookup). Parallel array with DAT_005e7640 mapping type IDs to function pointers (stride 8 bytes) |
| DAT_008d4066 | CRTTimeDateByte | CRT/time | byte | read | 1 | CRT date/time field byte in FUN_0059249b (428-byte date validation). Part of locale-specific date format fields compared for session scheduling validation |
| DAT_005b9928 | ProgramNameUnknown | CRT | char* | offset | 1 | String constant "Program name unknown" — CRT/default program name string |
| DAT_008d41d0 | CRTUnicodeMode | CRT/locale | int | read | 1 | CRT Unicode/ANSI mode flag in FUN_00596a2e (423-byte string type detection). Value 1=Unicode, 2=ANSI. Cached result of GetStringTypeW/A calls for string classification |
| DAT_005e9d98 | CRTDecimalLookup | CRT/data | ptr | offset | 1 | CRT decimal conversion lookup table in FUN_00597cc0 (124-byte conversion helper). Stride 0x54 per entry; indexed by power-of-two digit blocks for binary-to-decimal string conversion |
| DAT_005bb540 | CRTExceptionBlock | CRT | struct | offset | 1 | CRT exception handling block in FUN_00599bf0 (104-byte constructor). Initializes exception info with vtable reference and cleanup handler |
| DAT_005bb7e0 | CRTStringConstructor | CRT | struct | offset | 1 | CRT string constructor workspace in FUN_0059abcd (114 bytes). Constructs string object with vtable, length tracking, and character data from DAT_005c406c |
| DAT_005bd0c0 | OphDllString | CRT | char* | offset | 1 | String constant "Oph.dll" — CRT/OS helper DLL name for finalization |
