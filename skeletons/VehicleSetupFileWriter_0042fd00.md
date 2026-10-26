## VehicleSetupFileWriter_0042fd00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RefCountRelease (00433fc0), FileLoadWithFlagPreserve (00434000), SeasonDataFileSetupChain (0046d060)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x16CC | R | — | [LLM] |
| this | 0x1704 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1704: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004305e4 | jpt_4303CA | R | [LLM] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c3830 | aCustomD | R | CustomDField [DERIVED] |
| 005c383c | aGearingF | R | SetupParam_Gearing [DERIVED] |
| 005c3848 | aRideF | R | String_RideF [DERIVED] |
| 005c3854 | aBalanceF | R | BalanceFString [DERIVED] |
| 005c3860 | aDownforceF | R | DownforceFString [DERIVED] |
| 005c3870 | aBasic_0 | R | BasicString [DERIVED] |
| 005c387c | aBrakepadsettin_0 | R | String_BrakePadSetting [DERIVED] |
| 005c3890 | aBrakediscsetti_0 | R | s_BrakeDiscSetting [DERIVED] |
| 005c38a8 | aFastreboundset_0 | R | FastReboundSet [DERIVED] |
| 005c38c0 | aSlowreboundset_0 | R | SlowReboundSetField [DERIVED] |
| 005c38d8 | aFastbumpsettin_0 | R | FastBumpSettingString [DERIVED] |
| 005c38ec | aSlowbumpsettin_0 | R | SlowbumpsettingString [DERIVED] |
| 005c3900 | aRideheightsett_0 | R | RideHeightSetString [DERIVED] |
| 005c3918 | aSpringsettingD | R | Str_SpringSettingD [DERIVED] |
| 005c392c | aPackersettingD | R | StringPackerSetting [DERIVED] |
| 005c3940 | aPressuresettin_0 | R | PressureSettingString [DERIVED] |
| 005c3954 | aCambersettingD | R | CamberSettingString [DERIVED] |
| 005c3968 | aRearright_0 | R | RearRightString [DERIVED] |
| 005c3978 | aRearleft_0 | R | RearLeftCfgStr [DERIVED] |
| 005c3984 | aFrontright_0 | R | FrontRightString [DERIVED] |
| 005c3994 | aFrontleft_0 | R | FrontLeftField [DERIVED] |
| 005c39a4 | aDiffpreloadset | R | SetupParam_DiffPreload [DERIVED] |
| 005c39bc | aDiffcoastsetti | R | String_DiffCoastSetting [DERIVED] |
| 005c39d4 | aDiffpowersetti | R | DiffPowerSettingString [DERIVED] |
| 005c39ec | aDiffpumpsettin | R | DiffpumpsettingString [DERIVED] |
| 005c3a00 | aGearDsettingD | R | GearSettingFormatString [DERIVED] |
| 005c3a14 | aReversesetting | R | String_ReverseSetting [DERIVED] |
| 005c3a28 | aFinaldrivesett | R | s_FinalDriveSetting [DERIVED] |
| 005c3a40 | aDriveline_0 | R | Driveline [DERIVED] |
| 005c3a50 | aEnginebrakemap | R | EngineBrakeMapField [DERIVED] |
| 005c3a6c | aEnginemapsetti_0 | R | EngineMapSettingString [DERIVED] |
| 005c3a84 | aRevlimitsettin_0 | R | RevlimitsettingString [DERIVED] |
| 005c3a98 | aEngine_1 | R | EngineString [DERIVED] |
| 005c3aa4 | aHandbrakepress_1 | R | Str_HandbrakePressure [DERIVED] |
| 005c3ac0 | aBrakepressures_0 | R | StringBrakePressures [DERIVED] |
| 005c3adc | aRearbrakesetti_0 | R | RearBrakeSettingString [DERIVED] |
| 005c3af4 | aSteerlocksetti_0 | R | SteerLockSettingString [DERIVED] |
| 005c3b0c | aControls_1 | R | ControlsString [DERIVED] |
| 005c3b18 | aRear3rdfastreb_1 | R | Rear3rdFastRebCfgStr [DERIVED] |
| 005c3b38 | aRear3rdslowreb_1 | R | Rear3rdSlowReboundString [DERIVED] |
| 005c3b58 | aRear3rdfastbum_1 | R | Rear3rdFastBumpField [DERIVED] |
| 005c3b74 | aRear3rdslowbum_1 | R | SetupParam_RearThirdSlowBump [DERIVED] |
| 005c3b90 | aRear3rdsprings_0 | R | String_Rear3rdSprings_0 [DERIVED] |
| 005c3bac | aRear3rdpackers_0 | R | Rear3rdPackersString [DERIVED] |
| 005c3bc8 | aFront3rdfastre_1 | R | Front3rdFastreString [DERIVED] |
| 005c3be8 | aFront3rdslowre_1 | R | Front3rdSlowReboundString [DERIVED] |
| 005c3c08 | aFront3rdfastbu_1 | R | String_Front3rdFastBump [DERIVED] |
| 005c3c24 | aFront3rdslowbu_1 | R | s_Front3rdSlowBump [DERIVED] |
| 005c3c40 | aFront3rdspring_1 | R | Front3rdSpring [DERIVED] |
| 005c3c5c | aFront3rdpacker_1 | R | Front3rdPackerField [DERIVED] |
| 005c3c78 | aRighttrackbars_0 | R | RightTrackBarsString [DERIVED] |
| 005c3c94 | aLefttrackbarse_0 | R | LefttrackbarseString [DERIVED] |
| 005c3cac | aRightcasterset_0 | R | RightCasterSetString [DERIVED] |
| 005c3cc4 | aLeftcastersett_0 | R | Str_LeftCasterSetting [DERIVED] |
| 005c3cdc | aReartoeinsetti_0 | R | StringRearToeInSetting [DERIVED] |
| 005c3cf4 | aFronttoeinsett_0 | R | FrontToeInSettingString [DERIVED] |
| 005c3d0c | aRearantiswayse_0 | R | RearAntiSwaySettingString [DERIVED] |
| 005c3d24 | aFrontantisways_0 | R | FrontAntiSwayString [DERIVED] |
| 005c3d40 | aSuspension_2 | R | SuspensionCfgStr [DERIVED] |
| 005c3d50 | aBrakeductsetti_0 | R | BrakeDuctSettingString [DERIVED] |
| 005c3d68 | aRadiatorsettin_0 | R | RadiatorSettingField [DERIVED] |
| 005c3d7c | aBodyaero_0 | R | SetupParam_BodyAero [DERIVED] |
| 005c3d88 | aRwsettingD | R | String_RWSetting_D [DERIVED] |
| 005c3d98 | aRearwing_0 | R | RearWingString [DERIVED] |
| 005c3da4 | aFwsettingD | R | FwsettingDString [DERIVED] |
| 005c3db4 | aFrontwing_0 | R | FrontWingString [DERIVED] |
| 005c3dc4 | aRightfender_0 | R | String_RightFender [DERIVED] |
| 005c3dd4 | aFenderflareset_0 | R | s_FenderFlareSet [DERIVED] |
| 005c3dec | aLeftfender_0 | R | LeftFender [DERIVED] |
| 005c3dfc | aPitstop3settin_0 | R | Pitstop3SettingsField [DERIVED] |
| 005c3e10 | aPitstop2settin_0 | R | PitstopSettingString [DERIVED] |
| 005c3e24 | aPitstop1settin_0 | R | Pitstop1SettingString [DERIVED] |
| 005c3e38 | aNumpitstopsset_0 | R | NumPitStopsSetString [DERIVED] |
| 005c3e50 | aFuelsettingD | R | Str_FuelSettingD [DERIVED] |
| 005c3e60 | aTirecompoundse_0 | R | StringTireCompounds [DERIVED] |
| 005c3e78 | aWedgesettingD | R | WedgeSettingString [DERIVED] |
| 005c3e8c | aCgrearsettingD | R | CGRearSettingString [DERIVED] |
| 005c3ea0 | aCgrightsetting_0 | R | CgRightSettingString [DERIVED] |
| 005c3eb4 | aSymmetricD | R | SymmetricDConfigStr [DERIVED] |
| 005c3ec4 | aNotesS | R | NotesSString [DERIVED] |
| 005c3ed0 | aGeneral_0 | R | GeneralField [DERIVED] |
| 005c3edc | aFailedToOpenSF | R | SetupError_FailedToOpen [DERIVED] |
| 005c3efc | aDDevF119992002_18 | R | String_Debug_F119992002_18 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566940 | sub_566940 | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566c30 | BufferWriteWithStringLengthCheck | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
