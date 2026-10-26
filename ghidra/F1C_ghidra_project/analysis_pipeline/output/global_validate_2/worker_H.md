=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be678 | StringPitlanes | game/text | string | offset | 1 | "pitlanes" string constant |
| DAT_005be59c | StringLapLength | game/text | string | offset | 1 | "lapLength" string constant |
| DAT_008aff94 | Flt_Unknown_Physics | physics | float | write | 1 | physics constant written by setup function |
| DAT_007d07a4 | DifficultyFloatThreshold | game | float | read | 1 | difficulty threshold compared against DAT_0059e448 |
| DAT_0059e6a0 | CollisionProximityScale | physics/collision | float | read | 1 | scaling factor for collision proximity checks (FUN_0040adb0) |
| DAT_005bea7c | StringCommentaryStop | audio/text | string | offset | 1 | "CommentaryStop" string constant |
| DAT_005beb30 | StringOriginal | setup/text | string | offset | 1 | "original" string constant |
| DAT_0059e744 | Ptr_FunctionTable | renderer | ptr | offset | 1 | function pointer table for renderer (referenced by FUN_0040fe50) |
| DAT_005c239c | StringSe | UI/text | string | offset | 1 | "se" string constant (FUN_00414600) |
| DAT_005c2564 | StringJarnoT | driver/text | string | offset | 1 | "Jarno T" driver name string (FUN_00415d90) |

| DAT_005c2498 | StringMikaS | driver/text | string | offset | 1 | "Mika S" driver name string (FUN_00415d90) |
| DAT_005c29a0 | String1999Arrows | vehicle/text | string | offset | 1 | "1999Arrows" vehicle filename string (FUN_0041b980) |
| DAT_005c2888 | String2000Sauber | vehicle/text | string | offset | 1 | "2000Sauber" vehicle filename string (FUN_0041b980) |
| DAT_005c2770 | String2002Renault | vehicle/text | string | offset | 1 | "2002Renault" vehicle filename string (FUN_0041b980) |
| DAT_005c29e8 | StringAudioMusic | audio/text | string | offset | 1 | "AudioMusic" string constant (FUN_004216f0) |
| DAT_005c2c34 | StringDriversDir | setup/text | string | offset | 1 | "driversdir" config key string (FUN_00421cd0) |
| DAT_005c2b38 | StringVBStrategy | setup/text | string | offset | 1 | "vbstrategy" config key string (FUN_00421cd0) |
| DAT_005c2f90 | StringReplayDirS | replay/text | string | offset | 1 | "replaydir" directory path string (FUN_00422be0) |
| DAT_005c2e40 | StringRunBenchmarksD | benchmark/text | string | offset | 1 | "runbenchmarks" config key string (FUN_00422be0) |
| DAT_005c30d0 | StringGameDic | game/text | string | offset | 1 | "Game.dic" filename string (FUN_00423890) |

| DAT_005c318c | StringStallDns | network/text | string | offset | 1 | "stall dns" string constant (FUN_00424080) |
| DAT_0059e94c | Flt_Unknown_Dynamics | physics/dynamics | float | read | 1 | dynamics interpolation/scaling constant (FUN_004270a0) |
| DAT_005c32f0 | StringD063f | setup/text | string | offset | 1 | format string "%d%03f" or similar (FUN_0042bdd0) |
| DAT_007cc394 | TrackSelectedIndex | setup/track | int | read | 1 | track selection index (FUN_0042c440) |
| DAT_005c3498 | StringEnteredDynManP | debug/text | string | offset | 1 | "Entered DynManP..." debug string (FUN_0042c9f0) |
| DAT_007d0438 | GameConfigFlag | game | int | read | 1 | game configuration flag (FUN_0042d370) |
| DAT_005c376c | Byte_Unknown | setup | byte | offset | 1 | byte constant (FUN_0042ed70) |
| DAT_005c3e60 | StringTireCompounds | vehicle/text | string | offset | 1 | "TireCompounds" config key string (FUN_0042fd00) |
| DAT_005c3cdc | StringRearToeInSetting | vehicle/text | string | offset | 1 | "RearToeInSetting" setup string (FUN_0042fd00) |
| DAT_005c3ac0 | StringBrakePressures | vehicle/text | string | offset | 1 | "BrakePressures" setup string (FUN_0042fd00) |

| DAT_005c392c | StringPackerSetting | vehicle/text | string | offset | 1 | "PackerSetting" setup string (FUN_0042fd00) |
| DAT_008ae194 | Double_Unknown_Physics | physics | double | read | 1 | physics constant used in FUN_00430a50 (suspension/wheel rate calc) |
| DAT_005c4044 | Asc_Unknown | setup/text | string | offset | 1 | ASCII string constant (FUN_00432bf0) |
| DAT_005c40f0 | StringSliding | UI/text | string | offset | 1 | "sliding" string constant (FUN_00435410) |
| DAT_005ec3bc | Dword_Unknown_Setup | setup | int | write | 1 | setup variable written in FUN_00438130 |
| DAT_0059ebd0 | Double_Unknown_Physics | physics | double | read | 1 | physics threshold or constant (FUN_00439210) |
| DAT_005c4364 | StringCouldNotFindOn | debug/text | string | offset | 1 | "Could not find on..." error string (FUN_0043da10) |
| DAT_0059ed70 | Double_SteeringClampMax | physics/steering | double | read | 1 | steering angle clamp upper bound (FUN_00442060) |
| DAT_0059eea8 | Double_Unknown_Dynamics | physics/dynamics | double | read | 1 | dynamics solver constant (FUN_004441f0) |
| DAT_0059ee18 | Double_Unknown_Dynamics2 | physics/dynamics | double | read | 1 | dynamics solver constant (FUN_004441f0) |

| DAT_005c43a4 | StringBrakeBias | vehicle/text | string | offset | 1 | "BrakeBias" setup string (FUN_00447d00) |
| DAT_007cd1a4 | Flt_Unknown_Render | renderer | float | write | 1 | renderer float initialized to 1.0 (FUN_0044c7a0) |
| DAT_007ca588 | Flt_Unknown_Render | renderer | float | write | 1 | renderer float initialized to 0.0 (FUN_0044d280) |
| DAT_007ccd28 | Dword_Unknown_Render | renderer | int | write | 1 | renderer state int (FUN_0044d520) |
| DAT_007cd07c | Dword_Unknown_Render | renderer | int | write | 1 | renderer state variable (FUN_0044ff50) |
| DAT_005ad3c4 | Dword_Unknown_Physics | physics | int | read | 1 | physics constant read in FUN_0044ff50 |
| DAT_005ad3e4 | Dword_Unknown_Physics2 | physics | int | read | 1 | physics constant read in FUN_0044ff50 |
| DAT_007d23c8 | Flt_Unknown_Render | renderer | float | read | 1 | renderer view/visibility constant (FUN_00451720) |
| DAT_007cd080 | Dword_Unknown_Render2 | renderer | int | read | 1 | renderer state pointer comparison (FUN_00452b10) |
| DAT_007cd044 | Dword_Unknown_Render3 | renderer | int | write | 1 | renderer state variable (FUN_004537b0) |

| DAT_007ca544 | Dword_Unknown_Render4 | renderer | int | write | 1 | renderer state variable (FUN_004537b0) |
| DAT_005c5620 | StringFirstGear | vehicle/text | string | offset | 1 | "FirstGear" setup string (FUN_00455290) |
| DAT_005c5504 | StringInstantReplay | replay/text | string | offset | 1 | "InstantReplay" config string (FUN_00455290) |
| DAT_005c56cc | StringEnteredHWInput | input/text | string | offset | 1 | "Entered HWInput..." debug string (FUN_00455c60) |
| DAT_0059ef84 | Flt_CameraOffset | camera | float | read | 1 | camera offset/movement constant (FUN_004569b0) |
| DAT_0059f038 | Double_Unknown_Dynamics3 | physics/dynamics | double | read | 1 | dynamics solver constant (FUN_00459ae0) |
| DAT_005c5c08 | StringMaxPlayers | network/text | string | offset | 1 | "MaxPlayers" config key string (FUN_0045cf50) |
| DAT_0059f108 | Flt_Unknown_Physics3 | physics | float | read | 1 | physics threshold constant (FUN_0045d890) |
| DAT_005c5f2c | StringLoadingSlotInd | UI/text | string | offset | 1 | "Loading slot %d" format string (FUN_0045fc50) |
| DAT_005c6134 | StringApplyingFrameT | UI/text | string | offset | 1 | "Applying frame t..." debug string (FUN_004612e0) |

| DAT_007ce876 | Byte_WeatherFlag | weather | byte | read | 1 | weather/session byte flag (FUN_00461900) |
| DAT_007d0140 | Dword_GameOptions | game | int | read | 1 | game options/settings (FUN_00461900) |
| DAT_005c64e4 | StringNetCommCheckin | network/text | string | offset | 1 | "NetComm CheckIn" debug string (FUN_00463160) |
| DAT_005c6578 | StringAutoJoinFailure | network/text | string | offset | 1 | "AutoJoin failure" error string (FUN_004637a0) |
| DAT_0059f1f8 | Flt_DynamicsMultiplier | physics/dynamics | float | read | 1 | dynamics velocity multiplier (FUN_00466350) |
| DAT_007d2dd4 | Dword_SeasonScoring | scoring | int | read | 1 | season scoring context (FUN_0046a560) |
| DAT_005c6ab0 | StringSD063f | setup/text | string | offset | 1 | format string "%s %d%03f" (FUN_0046bc20) |
| DAT_007cd87f | Byte_ReplayFlag | replay | byte | write | 1 | replay state byte (FUN_00470490) |
| DAT_005c71c8 | Byte_FileExtension | file | byte | read | 1 | file extension byte used in path construction (FUN_004793ec) |
| DAT_005c72ec | StringDropBookmark | UI/text | string | offset | 1 | "DropBookmark" string constant (FUN_0047daf0) |

| DAT_005c7480 | StringFirstGrandPrix | driver/text | string | offset | 1 | "FirstGrandPrix" string constant (FUN_0047e440) |
| DAT_005ac328 | Ptr_VTable | renderer | ptr | offset | 1 | vtable pointer for renderer object (FUN_0048d740) |
| DAT_005cc6a0 | StringEscTarget | UI/text | string | offset | 1 | "escTarget" string constant (FUN_00492710) |
| DAT_005cc7bc | StringOffsetPair | UI/text | string | offset | 1 | "OffsetPair" string constant (FUN_00493060) |
| DAT_005cc800 | StringLostFocus | UI/text | string | offset | 1 | "LostFocus" string constant (FUN_00493480) |
| DAT_007cde28 | Dword_SoundHandle | audio | int | read | 1 | audio/sound handle (FUN_00494900) |
| DAT_005ccaf4 | StringFTime28Blk | UI/text | string | offset | 1 | "%.2f %d:%d" format string maybe (FUN_004989e0) |
| DAT_005ccbe4 | Ptr_FunctionTable2 | renderer | ptr | read | 1 | function pointer table (FUN_0049bde0) |
| DAT_005ccb5c | Ptr_FunctionTable3 | renderer | ptr | read | 1 | function pointer table (FUN_0049ca00) |
| DAT_005cced0 | String4dS | UI/text | string | offset | 1 | "%4d s" format string (FUN_0049db00) |

| DAT_007cf7ac | Byte_InputFlag | input | byte | read | 1 | input device flag bitmask (FUN_0049f790) |
| DAT_005ccfe4 | Byte_Unknown_Setup | setup | byte | read | 1 | setup byte flag (FUN_004a0eb0) |
| DAT_007ce2d4 | Dword_PitState | pit | int | write | 1 | pit state variable (FUN_004a1200) |
| DAT_005cd2cc | StringFuelOut | pit/text | string | offset | 1 | "FuelOut" pit string constant (FUN_004a24d0) |
| DAT_005cd44c | StringLollipop | pit/text | string | offset | 1 | "Lollipop" pit animation string (FUN_004a2a90) |
| DAT_005cd4c0 | StringPitGuyCMts | pit/text | string | offset | 1 | "PitGuyC_Mts" pit crew string (FUN_004a3910) |
| DAT_005cd4f8 | StringMonsoonCompound | tire/text | string | offset | 1 | "MonsoonCompound" tire string (FUN_004a4830) |
| DAT_005c6e18 | Unk_StringConstant | setup | string | offset | 1 | unknown string constant (FUN_004a58b0) |
| DAT_005cd6ec | StringQuick | UI/text | string | offset | 1 | "Quick" string constant (FUN_004aa1e0) |
| DAT_005d1ea8 | StringInvulnerability | game/text | string | offset | 1 | "Invulnerability" option string (FUN_004aa270) |

| DAT_005d1bb8 | StringHalfRate | game/text | string | offset | 1 | "HalfRate" option string (FUN_004aa270) |
| DAT_005d1960 | StringRunPractice4 | game/text | string | offset | 1 | "RunPractice4" option string (FUN_004aa270) |
| DAT_005d16c8 | StringSoundOptions | audio/text | string | offset | 1 | "SoundOptions" menu string (FUN_004aa270) |
| DAT_005d14c8 | StringMusicVolume | audio/text | string | offset | 1 | "MusicVolume" option string (FUN_004aa270) |
| DAT_005d1314 | StringHelicopterRange | camera/text | string | offset | 1 | "HelicopterRange" option string (FUN_004aa270) |
| DAT_005d114c | StringPlayerDetail | renderer/text | string | offset | 1 | "PlayerDetail" option string (FUN_004aa270) |
| DAT_005d0eac | StringOffsetBelowVeh | camera/text | string | offset | 1 | "OffsetBelowVeh" option string (FUN_004aa270) |
| DAT_005d0bc0 | StringAngleToLookLeft | camera/text | string | offset | 1 | "AngleToLookLeft" option string (FUN_004aa270) |
| DAT_005d0994 | StringDustDetail | renderer/text | string | offset | 1 | "DustDetail" option string (FUN_004aa270) |
| DAT_005d0700 | StringChampionshipBa | game/text | string | offset | 1 | "Championship..." option string (FUN_004aa270) |

| DAT_005d04d0 | StringAdjustmentsWith | game/text | string | offset | 1 | "AdjustmentsWith..." option string (FUN_004aa270) |
| DAT_005d020c | StringRaceStintOffset | game/text | string | offset | 1 | "RaceStintOffset" option string (FUN_004aa270) |
| DAT_005cffac | StringRaceLaps | game/text | string | offset | 1 | "RaceLaps" option string (FUN_004aa270) |
| DAT_005cfce8 | StringTireWearMultip | tire/text | string | offset | 1 | "TireWearMultiplier" option string (FUN_004aa270) |
| DAT_005cf878 | StringAddTheFollowing | game/text | string | offset | 1 | "AddTheFollowing..." option string (FUN_004aa270) |
| DAT_005cf55c | StringTargetRateForD | renderer/text | string | offset | 1 | "TargetRateForDetail" option string (FUN_004aa270) |
| DAT_005cf108 | StringUsedToRestoreT | game/text | string | offset | 1 | "UsedToRestoreThe..." option string (FUN_004aa270) |
| DAT_005cedc8 | StringExponentToAppl | tire/text | string | offset | 1 | "ExponentToApply" option string (FUN_004aa270) |
| DAT_005ceb6c | StringController1S0 | input/text | string | offset | 1 | "Controller1S0" option string (FUN_004aa270) |
| DAT_005ce968 | StringControlFifthGe | input/text | string | offset | 1 | "ControlFifthGear" option string (FUN_004aa270) |

| DAT_005ce794 | StringControlRestart | input/text | string | offset | 1 | "ControlRestart" option string (FUN_004aa270) |
| DAT_005ce4d8 | String0BrakeEffectsO | input/text | string | offset | 1 | "0BrakeEffectsOff" option string (FUN_004aa270) |
| DAT_005cdf98 | StringAmountOfChange | input/text | string | offset | 1 | "AmountOfChange" option string (FUN_004aa270) |
| DAT_005cdbb8 | StringFfbBrakeVibeFr | input/text | string | offset | 1 | "FFBBrakeVibeFreq" option string (FUN_004aa270) |
| DAT_005cd7cc | StringDirectInputSat | input/text | string | offset | 1 | "DirectInputSat" option string (FUN_004aa270) |
| DAT_005acc38 | Ptr_VTable_Input | input | ptr | offset | 1 | vtable pointer for input object (FUN_004b19f0) |
| DAT_008acfe4 | Byte_GameStateFlag | game | byte | write | 1 | game state/session flag (FUN_004b3400) |
| DAT_005acd5c | Flt_SteeringDeadzone | input/steering | float | read | 1 | steering deadzone values for different sensitivity levels (FUN_004b67d0) |
| DAT_007d0080 | Dword_GameState2 | game | int | read | 1 | game state value used in menu flow (FUN_004ba6c0) |
| DAT_005acd90 | Flt_Unknown_Display | renderer | float | read | 1 | display/UI scaling constant (FUN_004bccc0) |

| DAT_007d2e54 | Unk_ScoringRingBuffer | scoring | struct | offset | 1 | scoring ring buffer base pointer (stride for season points) (FUN_004bf4f0) |
| DAT_005d2684 | StringControlType | input/text | string | offset | 1 | "ControlType" config key (FUN_004c03f0) |
| DAT_005d2870 | StringCurrentRaceD | game/text | string | offset | 1 | "CurrentRace" debug string (FUN_004c0cc0) |
| DAT_005d2d7c | StringAvgOpponentsStr | game/text | string | offset | 1 | "AvgOpponentsStrength" option string (FUN_004c2420) |
| DAT_005d2e88 | StringCareer | game/text | string | offset | 1 | "Career" mode string (FUN_004c2700) |
| DAT_005d2f50 | StringTeamPoles | game/text | string | offset | 1 | "TeamPoles" scoring string (FUN_004c3200) |
| DAT_005d30fc | String2WeDoNotHaveRe | UI/text | string | offset | 1 | "We do not have replay data" error string (FUN_004c52c0) |
| DAT_005d33c0 | StringEnteredSoundSet | audio/text | string | offset | 1 | "Entered SoundSet..." debug string (FUN_004c8ab0) |
| DAT_005ace3c | Ptr_VTable_Sound | audio | ptr | offset | 1 | vtable pointer for sound objects (FUN_004c9a50) |
| DAT_005d3608 | StringUnrecognizedRe | renderer/text | string | offset | 1 | "Unrecognized render..." error string (FUN_004ca480) |

| DAT_005d3528 | StringPixel | renderer/text | string | offset | 1 | "Pixel" render format string (FUN_004ca480) |
| DAT_005d373c | StringInvSrcAlpha | renderer/text | string | offset | 1 | "inv_src_alpha" render state string (FUN_004cada0) |
| DAT_005acec0 | Flt_AlphaBlendFactor | renderer | float | read | 1 | alpha blending factor for particle effects (FUN_004cd6c0) |
| DAT_005d3850 | StringSolidWall | track/text | string | offset | 1 | "solidwall" track surface string (FUN_004cdd80) |
| DAT_005d39d0 | StringEnteredSpecial | debug/text | string | offset | 1 | "Entered Special..." debug string (FUN_004cfc90) |
| DAT_005d3a84 | StringWcFlagBmp | UI/text | string | offset | 1 | "wcflag.bmp" bitmap filename (FUN_004d0110) |
| DAT_005d3c48 | StringPTent02d | UI/text | string | offset | 1 | "ptent%02d" format string (FUN_004d15f0) |
| DAT_005d4038 | StringDriveAidsSteer | game/text | string | offset | 1 | "DriveAidsSteering" option string (FUN_004d24d0) |
| DAT_005d3de8 | StringGameOptDamageM | game/text | string | offset | 1 | "GameOptDamageModel" option string (FUN_004d24d0) |
| DAT_005d3c90 | StringRaceTimeDNF | game/text | string | offset | 1 | "RaceTimeDNF" option string (FUN_004d24d0) |

| DAT_005d42bc | StringPtLit01 | UI/text | string | offset | 1 | "ptlit01" texture/bitmap name (FUN_004d38f0) |
| DAT_005acf00 | Double_Unknown_Render | renderer | double | read | 1 | renderer double constant (FUN_004d3cf0) |
| DAT_005d4580 | StringPosZM | vehicle/text | string | offset | 1 | "Pos ZM" telemetry string (FUN_004d4a80) |
| DAT_005d4464 | StringTyreLeftTempK | tire/text | string | offset | 1 | "Tyre Left Temp K" telemetry string (FUN_004d4a80) |
| DAT_005d4684 | StringTireSlipCurveS | tire/text | string | offset | 1 | "Tire Slip Curve..." string (FUN_004d5f70) |
| DAT_005d47b8 | StringTransfer | vehicle/text | string | offset | 1 | "Transfer" setup string (FUN_004d6b00) |
| DAT_005d4950 | StringTireBrandDoesn | tire/text | string | offset | 1 | "Tire brand doesn't..." error string (FUN_004d7570) |
| DAT_005d4a48 | Ptr_Unknown_Table | unknown | ptr | read | 1 | pointer table (FUN_004d8ab0) |
| DAT_005acffc | Ptr_VTable2 | unknown | ptr | offset | 1 | vtable pointer (FUN_004daea0) |
| DAT_005d4c8c | StringWcWing | vehicle/text | string | offset | 1 | "WCWing" setup string (FUN_004ddad0) |

| DAT_005c67cc | StringTeamDir | setup/text | string | offset | 1 | "teamdir" config key (FUN_004ddf90) |
| DAT_005d4d8c | StringRWing | vehicle/text | string | offset | 1 | "RWing" setup string (FUN_004dfce0) |
| DAT_005ad154 | Flt_Unknown_Render5 | renderer | float | read | 1 | renderer/scene constant (FUN_004e19d0) |
| DAT_005ad1a8 | Double_Unknown_Dynamics4 | physics/dynamics | double | read | 1 | dynamics solver constant (FUN_004e5f60) |
| DAT_005ad1f0 | Flt_Unknown_Damage | physics/damage | float | read | 1 | damage/torque scaling constant (FUN_004ec1a0) |
| DAT_007d0af8 | Byte_DriverFlag | driver | byte | read | 1 | driver AI state byte flag (FUN_004f1c40) |
| DAT_005d4f24 | StringWheelBend | vehicle/text | string | offset | 1 | "WheelBend" setup string (FUN_004f24f0) |
| DAT_005d5248 | StringBrakeWearRate | vehicle/text | string | offset | 1 | "BrakeWearRate" setup string (FUN_004f2c60) |
| DAT_005d510c | StringSpringSetting | vehicle/text | string | offset | 1 | "SpringSetting" setup string (FUN_004f2c60) |
| DAT_005d545c | StringXForceAppliedW | vehicle/text | string | offset | 1 | "XForce Applied W" debug string (FUN_004f3240) |

| DAT_005d5698 | StringBadEngineLaunc | engine/text | string | offset | 1 | "Bad engine launch" error string (FUN_004f3c80) |
| DAT_005d6764 | StringSetting | vehicle/text | string | offset | 1 | "Setting" setup string (FUN_004f4270) |
| DAT_005d667c | StringRRUndertray | vehicle/text | string | offset | 1 | "RRUndertray" setup string (FUN_004f4270) |
| DAT_005d6540 | StringCGRearRange | vehicle/text | string | offset | 1 | "CGRearRange" setup string (FUN_004f4270) |
| DAT_005d6410 | StringFWLeft | vehicle/text | string | offset | 1 | "FWLeft" setup string (FUN_004f4270) |
| DAT_005d633c | StringRWAft | vehicle/text | string | offset | 1 | "RWAft" setup string (FUN_004f4270) |
| DAT_005d6244 | StringRadiatorLift | vehicle/text | string | offset | 1 | "RadiatorLift" setup string (FUN_004f4270) |
| DAT_005d6100 | StringLeftWheelBase | vehicle/text | string | offset | 1 | "LeftWheelBase" setup string (FUN_004f4270) |
| DAT_005d5f30 | StringRear3rdBumpstop | vehicle/text | string | offset | 1 | "Rear3rdBumpstop" setup string (FUN_004f4270) |
| DAT_005d5d94 | StringLeftTrackBarRa | vehicle/text | string | offset | 1 | "LeftTrackBarRa" setup string (FUN_004f4270) |

| DAT_005d5bb8 | StringRear3rdSlowBump | vehicle/text | string | offset | 1 | "Rear3rdSlowBump" setup string (FUN_004f4270) |
| DAT_005d5a24 | StringBrakePressureR | vehicle/text | string | offset | 1 | "BrakePressureRear" setup string (FUN_004f4270) |
| DAT_005d58f4 | StringWheelDrive | vehicle/text | string | offset | 1 | "WheelDrive" setup string (FUN_004f4270) |
| DAT_005d57b0 | StringDiffPreloadSet | vehicle/text | string | offset | 1 | "DiffPreloadSetting" setup string (FUN_004f4270) |
| DAT_008af568 | Dword_Unknown_Setup2 | setup | int | offset | 1 | setup/track variable (FUN_004f70c0) |
| DAT_005d6bdc | StringEngineShape | engine/text | string | offset | 1 | "EngineShape" setup string (FUN_004f7460) |
| DAT_005d6a77 | String_Unknown_Setup | setup/text | string | offset | 1 | unknown setup string (FUN_004f7460) |
| DAT_005d68ef | String_Unknown_Setup2 | setup/text | string | offset | 1 | unknown setup string (FUN_004f7460) |
| DAT_005d6d10 | StringVfxGetTracking | renderer/text | string | offset | 1 | "VfxGetTracking" debug string (FUN_004f8b50) |
| DAT_005d6e20 | StringDfLod2Bmp | renderer/text | string | offset | 1 | "df_lod2.bmp" texture filename (FUN_004f9480) |

| DAT_005d6eb4 | StringEnteredVidManR | renderer/text | string | offset | 1 | "Entered VidMan..." debug string (FUN_004fa640) |
| DAT_005d6f40 | StringSCS | renderer/text | string | offset | 1 | "SCS" string constant (FUN_004fc400) |
| DAT_005ad2c4 | Flt_InterpolationCoeff | physics/interp | float | read | 1 | interpolation coefficient for physics interpolation table (FUN_004fd6f0) |
| DAT_005c6e8c | StringOvercast | weather/text | string | offset | 1 | "Overcast" weather string (FUN_004fe0d0) |
| DAT_005d6ff8 | StringOffPathWetness | track/text | string | offset | 1 | "OffPathWetness" track string (FUN_004fe350) |
| DAT_005d7034 | Asc_Unknown_Weather | weather/text | string | offset | 1 | ASCII weather constant (FUN_004fe820) |
| DAT_005adb78 | String105 | serial/text | string | offset | 1 | "1.0.5" version string (FUN_0050210e) |
| DAT_005ba64c | Stru_Serialization | serial | struct | offset | 1 | serialization structure vtable (FUN_005076fe) |
| DAT_005adc5c | Ptr_VTable_Serial | serial | ptr | offset | 1 | serialization vtable pointer (FUN_0050ae3e) |
| DAT_005ba69c | Stru_Serialization2 | serial | struct | offset | 1 | serialization structure (FUN_0050b47e) |

| DAT_005d7800 | Ptr_FunctionDispatch | system | ptr | read | 1 | function dispatch table (FUN_0050c636) |
| DAT_005d7858 | Ptr_FunctionDispatch2 | system | ptr | read | 1 | function dispatch table (FUN_0050e313) |
| DAT_005af27c | StringPlte | renderer/text | string | offset | 1 | ".plte" file extension string (FUN_005119e9) |
| DAT_005af4d0 | StringCallToNullRead | serial/text | string | offset | 1 | "Call to NULL read function" error string (FUN_00513bd1) |
| DAT_005af660 | Unk_ImageDecoder | renderer | struct | offset | 1 | image decoder state structure (FUN_00515417) |
| DAT_005afbc4 | StringInvalidColorType | renderer/text | string | offset | 1 | "Invalid color type" error string (FUN_005188b4) |
| DAT_005afe10 | StringDuplicateSrgbC | renderer/text | string | offset | 1 | "Duplicate sRGB chunk" error string (FUN_00518d29) |
| DAT_005b0508 | Unk_ImageCodec | renderer | struct | offset | 1 | image codec state (FUN_0051bad1) |
| DAT_005d8b40 | Xmm_SSE_AndMask | math/SSE | xmm | read | 1 | SSE bitwise AND mask for vector normalization (FUN_0051f98e) |
| DAT_005d8c00 | Xmm_SSE_SignMask_NegZ | math/SSE | xmm | read | 1 | SSE sign mask for negating Z component in cross product (FUN_0051fd2e) |

| DAT_008d61b0 | Xmm_SSE_MatrixConst0 | math/SSE | xmm | read | 1 | SSE matrix construction constant (FUN_0052087e) |
| DAT_005d8ce0 | Xmm_SSE_MatrixConst1 | math/SSE | xmm | read | 1 | SSE matrix rotation constant (FUN_00520c0e) |
| DAT_005b0794 | StringInvalidBlockType | renderer/text | string | offset | 1 | "Invalid block type" error string (FUN_00527752) |
| DAT_005d8f30 | Xmm_SSE_ColorXform | math/SSE | xmm | read | 1 | SSE color space transformation constants (FUN_005289e0) |
| DAT_005d9190 | Xmm_SSE_ColorXform2 | math/SSE | xmm | read | 1 | SSE color space transformation constants (FUN_00528cc0) |
| DAT_005d93d8 | Dword_EmptyFunction | system | int | read | 1 | referenced by empty stub function (FUN_00529200) |
| DAT_005d9420 | Unk_TextureAtlas | renderer | struct | offset | 1 | texture atlas/page structure (FUN_0052a5a8) |
| DAT_005b0c38 | Qword_SSE_Const | math/SSE | qword | read | 1 | SSE packed 16-bit multiply constant (FUN_0052ab4e) |
| DAT_005b4810 | Ptr_VTable_SSE | math/SSE | ptr | offset | 1 | vtable for SSE math object (FUN_0052e170) |
| DAT_008b1824 | Unk_BitReader | codec | struct | offset | 1 | bit reader/decoder state (FUN_00531250) |

| DAT_008b5938 | Flt_DCT_Coeff | codec/dct | float | write | 1 | DCT coefficient table (FUN_00531b50) |
| DAT_008b5974 | Flt_DCT_Coeff2 | codec/dct | float | write | 1 | DCT coefficient table (FUN_00531b50) |
| DAT_008b59d8 | Flt_DCT_Coeff3 | codec/dct | float | write | 1 | DCT coefficient table (FUN_00531b50) |
| DAT_008b59f0 | Flt_DCT_Coeff4 | codec/dct | float | write | 1 | DCT coefficient table (FUN_00531b50) |
| DAT_008b3724 | Unk_MMX_Const | codec/MMX | struct | offset | 1 | MMX/SSE packed multiply-add constants (FUN_00532aa0) |
| DAT_005da914 | StringInvalidBlockTy0 | codec/text | string | offset | 1 | "Invalid block type" error string (FUN_00537110) |
| DAT_005dbb54 | StringIncompleteDist | codec/text | string | offset | 1 | "Incomplete distance" error string (FUN_0053a4d0) |
| DAT_005dbd18 | StringCouldNotAlloca | codec/text | string | offset | 1 | "Could not allocate" error string (FUN_0053f720) |
| DAT_005dbf60 | StringErrorReadingMe | codec/text | string | offset | 1 | "Error reading memory" error string (FUN_0054ac70) |
| DAT_005dc124 | StringFontTex | renderer/text | string | offset | 1 | "fonttex" texture name (FUN_00552470) |

| DAT_005dc290 | StringLink | UI/text | string | offset | 1 | "Link" string constant (FUN_0055a790) |
| DAT_005dc2cc | StringSpecial1 | UI/text | string | offset | 1 | "Special1" string constant (FUN_0055a910) |
| DAT_005dc434 | StringCouldNotLocate | UI/text | string | offset | 1 | "Could not locate..." error string (FUN_0055b6b0) |
| DAT_005dc570 | Dword_Unknown_UI | UI | int | read | 1 | UI display constant (FUN_0055f0d0) |
| DAT_005dc520 | Dword_Unknown_UI2 | UI | int | read | 1 | UI display constant (FUN_0055f0d0) |
| DAT_005dc4e8 | Byte_Unknown_UI | UI | byte | read | 1 | UI display flag (FUN_0055f0d0) |
| DAT_005dc47c | Dword_Unknown_UI3 | UI | int | read | 1 | UI display constant (FUN_0055f0d0) |
| DAT_005e4ed8 | StringHeartbeatDGame | network/text | string | offset | 1 | "Heartbeat_DGame" network string (FUN_00562ac0) |
| DAT_005e5048 | StringOther | network/text | string | offset | 1 | "Other" network/chat string (FUN_00564110) |
| DAT_005e5170 | Dword_SerialPort | serial/io | int | read | 1 | serial port identifier (FUN_00566940) |

| DAT_005e51cc | StringLpt2 | io/text | string | offset | 1 | "LPT2" port name string (FUN_005687f0) |
| DAT_005e5318 | StringInertia | vehicle/text | string | offset | 1 | "Inertia" vehicle physics string (FUN_0056d930) |
| DAT_008d00d0 | Dbl_DynamicsSolver | physics/dynamics | double | read | 1 | dynamics constraint solver matrix workspace (FUN_0056fa96) |
| DAT_008cfce8 | Dbl_DynamicsSolverWk | physics/dynamics | double | write | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008cfe50 | Dbl_DynamicsSolverWk2 | physics/dynamics | double | write | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d15f0 | Dbl_DynamicsSolverWk3 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d3a50 | Dbl_DynamicsSolverWk4 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d0288 | Dbl_DynamicsSolverWk5 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d0410 | Dbl_DynamicsSolverWk6 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1a20 | Dbl_DynamicsSolverWk7 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |

| DAT_008d05d0 | Dbl_DynamicsSolverWk8 | physics/dynamics | double | write | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1cf0 | Dbl_DynamicsSolverWk9 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1ea8 | Dbl_DynamicsSolverWk10 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1a50 | Dbl_DynamicsSolverWk11 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1fa0 | Dbl_DynamicsSolverWk12 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1428 | Dbl_DynamicsSolverWk13 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1d28 | Dbl_DynamicsSolverWk14 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1a78 | Dbl_DynamicsSolverWk15 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1a80 | Dbl_DynamicsSolverWk16 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1998 | Dbl_DynamicsSolverWk17 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1c70 | Dbl_DynamicsSolverWk18 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1f00 | Dbl_DynamicsSolverWk19 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1588 | Unk_DynamicsSolver | physics/dynamics | struct | offset | 1 | dynamics solver index/offset table (FUN_0056fa96) |
| DAT_008d18d0 | Dbl_DynamicsSolverWk20 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1f20 | Dbl_DynamicsSolverWk21 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d1ca8 | Dbl_DynamicsSolverWk22 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d0a78 | Dbl_DynamicsSolverWk23 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d2100 | Dbl_DynamicsSolverWk24 | physics/dynamics | double | read | 1 | dynamics solver workspace area (FUN_0056fa96) |
| DAT_008d3b90 | Dword_DynamicsSolver | physics/dynamics | int | offset | 1 | dynamics LDL^T solver index array (FUN_00575bbd) |
| DAT_008d2458 | Unk_DynamicsSolver2 | physics/dynamics | struct | offset | 1 | dynamics LDL^T solver workspace (FUN_00575bbd) |
| DAT_008d27f8 | Dbl_DynamicsSolverWk25 | physics/dynamics | double | write | 1 | dynamics LDL^T solver workspace (FUN_00575bbd) |
| DAT_008d2ba0 | Dbl_DynamicsSolverWk26 | physics/dynamics | double | write | 1 | dynamics LDL^T solver workspace (FUN_00575bbd) |
| DAT_008d3068 | Dbl_DynamicsSolverWk27 | physics/dynamics | double | offset | 1 | dynamics LDL^T solver workspace (FUN_00575bbd) |
| DAT_008d3be4 | Dword_DynamicsSolver2 | physics/dynamics | int | offset | 1 | dynamics LDL^T solver index (FUN_00575bbd) |
| DAT_008d3c18 | Unk_EmptyStub | system | struct | offset | 1 | referenced by empty stub function FUN_0057ae70 |
| DAT_005e54a8 | StringNotInitialised | network/text | string | offset | 1 | "Not Initialised" error string (FUN_0057cb50) |
| DAT_005e5df0 | StringTheSpecifiedPr | network/text | string | offset | 1 | "The specified protocol..." error string (FUN_0057d400) |
| DAT_005e5598 | StringTheNetworkCann | network/text | string | offset | 1 | "The network cannot..." error string (FUN_0057d400) |
| DAT_005bac00 | Stru_NetworkQueue | network | struct | offset | 1 | network message queue structure (FUN_00581070) |
| DAT_005bafa4 | Stru_NetworkBuffer | network | struct | offset | 1 | network buffer allocation structure (FUN_005830c0) |
| DAT_005bb29c | Stru_MemoryManager | memory | struct | offset | 1 | memory manager structure (FUN_00586700) |
| DAT_005e650c | Ptr_FunctionTable | system | ptr | read | 1 | function pointer table (FUN_00588d95) |
| DAT_005be000 | Unk_LocaleData | locale | struct | offset | 1 | locale/codepage data structure (FUN_00589c77) |
| DAT_005e65c0 | Unk_KeyCodeTable | input | struct | offset | 1 | keyboard scancode-to-vkey lookup table (FUN_0058af5c) |
| DAT_005b8e34 | Double_FPU_Constant | math/FPU | double | read | 1 | FPU scaling constant for math helper (FUN_0058dd89) |
| DAT_008d3f60 | Dword_LocaleBuffer | locale | int | offset | 1 | locale string buffer handle/pointer (FUN_0058f4f2) |
| DAT_005e6d84 | String1252 | locale/text | string | offset | 1 | "1252" codepage string (FUN_005904f7) |
| DAT_005e7740 | Tbyte_CRT_Constant | math/CRT | tbyte | read | 1 | MSVC CRT tbyte constant (FUN_00591e89) |
| DAT_008d401a | Byte_LocaleCompare | locale | byte | read | 1 | locale comparison flags for date/time format (FUN_0059249b) |
| DAT_005c5c8c | Asc_Unknown | UI/text | string | offset | 1 | ASCII constant (FUN_005932f3) |
| DAT_005e9b48 | Unk_CodePageTable | locale | struct | offset | 1 | codepage translation table array (FUN_00596e40) |
| DAT_005b9b68 | Stru_LocaleInfo | locale | struct | offset | 1 | locale info structure with exception handler (FUN_00597d3c) |
| DAT_005bb568 | Stru_MemoryPool | memory | struct | offset | 1 | memory pool structure (FUN_00599c58) |
| DAT_005bb808 | Stru_ObjectManager | memory | struct | offset | 1 | object manager/allocator structure (FUN_0059ac7f) |
| DAT_005c7520 | HModule_Instance | system | handle | write | 1 | DLL/EXE module instance handle |
