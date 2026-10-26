## TheSvmHdvVehicleFileParser_004f4270 — ParseSVM_HDV_VehicleConfigFile

**Summary:** Parses .SVM and .HDV vehicle configuration files line-by-line, dispatching to section-specific parsers for general vehicle data, aero surfaces, suspension, engine, driveline, and per-wheel brake settings. Writes parsed values into both the internal vehicle setup struct and the output vehicle state struct.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ValidateVehicleConfigurationFile (00433ed0), TireModelInit (0043e050), sub_45C400 (0045c400), TelemetryDataDump (004d4a80), sub_4E3360 (004e3360), LargeConfigFunctionWithPhysicsConstants (004e45b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Tire compound RPM multiplier computed from TireBrandLookup |
| this | 0x34 | RW | — | Suspension physical model file path pointer from FileFinder |
| this | 0x38 | R | — | Adjacent suspension file-path data |
| this | 0x68 | R | — | Vehicle mass/inertia data area |
| this | 0x1EC | RW | 1 | Front-wing drag-params-loaded flag |
| this | 0x2F8 | RW | 1 | Rear-wing drag-params-loaded flag |
| this | 0x4D4 | RW | 1 | Diffuser-base-loaded flag |
| this | 0x548 | R | — | Front wing lift-params data area |
| this | 0x56C | R | — | Front wing direction/damping data |
| this | 0x674 | R | — | Body aero drag/direction data |
| this | 0x67C | R | — | Body aero rotation data |
| this | 0x13C0 | RW | 0 | Forward-gears count parsed from file |
| this | 0x13C4 | R | — | Adjacent gear-count validation data |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x1EC: recalc every frame — external poke does NOT persist
- this 0x2F8: recalc every frame — external poke does NOT persist
- this 0x4D4: recalc every frame — external poke does NOT persist
- this 0x13C0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005c42f4 | aHdvFileReferen | R | aHdvFileReference [DERIVED] |
| 005c670c | aCustom_0 | R | StringCustom [DERIVED] |
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] |
| 005d2ea4 | aIni | R | StringDotIni [DERIVED] |
| 005d548c | aDDevF119992002_7 | R | DefaultScenePath7 [DERIVED] |
| 005d573c | aGearing_0 | R | GearingString [DERIVED] |
| 005d5744 | aRide_0 | R | RideString [DERIVED] |
| 005d574c | aBalance_0 | R | String_Balance [DERIVED] |
| 005d5754 | aDownforce_0 | R | DownforceString [DERIVED] |
| 005d5760 | aBasic | R | Basic [DERIVED] |
| 005d5768 | aRearright | R | RearRightField [DERIVED] |
| 005d5774 | aRearleft | R | RearLeftString [DERIVED] |
| 005d5780 | aFrontright | R | FrontrightString [DERIVED] |
| 005d5790 | aFrontleft | R | FrontleftString [DERIVED] |
| 005d579c | aDiffpreloadran | R | Str_Diffpreloadran [DERIVED] |
| 005d57b0 | aDiffpreloadset_0 | R | StringDiffPreloadSet [DERIVED] |
| 005d57c4 | aDiffcoastrange | R | DiffCoastRangeString [DERIVED] |
| 005d57d4 | aDiffcoastsetti_0 | R | DiffCoastSettingString [DERIVED] |
| 005d57e8 | aDiffpowerrange | R | DiffpowerrangeString [DERIVED] |
| 005d57f8 | aDiffpowersetti_0 | R | DiffPowerSetStr [DERIVED] |
| 005d580c | aDiffpumprange | R | DiffPumpRangeString [DERIVED] |
| 005d581c | aDiffpumpsettin_0 | R | DiffPumpSettingField [DERIVED] |
| 005d582c | aReversesetting_0 | R | aReverseSetting [DERIVED] |
| 005d583c | aFinaldrivesett_0 | R | String_FinalDriveSetting_0 [DERIVED] |
| 005d585b | aGear6setting | R | Gear6SettingString [DERIVED] |
| 005d5868 | aGear5setting | R | Gear5settingString [DERIVED] |
| 005d5875 | aGear4setting | R | Gear4SettingString [DERIVED] |
| 005d5882 | aGear3setting | R | String_Gear3Setting [DERIVED] |
| 005d588f | aGear2setting | R | Gear2SettingString [DERIVED] |
| 005d589c | aGear1setting | R | Gear1Setting [DERIVED] |
| 005d58a9 | aForwardgears | R | ForwardGearsField [DERIVED] |
| 005d58b6 | aGearfile | R | GearFileString [DERIVED] |
| 005d58e4 | aFront | R | FrontString [DERIVED] |
| 005d58ea | aFour | R | FourString [DERIVED] |
| 005d58ef | aRear | R | Str_Rear [DERIVED] |
| 005d58f4 | aWheeldrive | R | StringWheelDrive [DERIVED] |
| 005d5900 | aDiffpumptorque | R | DiffPumpTorqueString [DERIVED] |
| 005d5910 | aDownshiftclutc | R | DownshiftClutchString [DERIVED] |
| 005d5924 | aDownshiftdelay | R | DownshiftdelayString [DERIVED] |
| 005d5934 | aUpshiftclutcht | R | UpshiftClutchTimeStr [DERIVED] |
| 005d5948 | aUpshiftdelay | R | UpshiftDelayString [DERIVED] |
| 005d5958 | aSemiautomatic | R | SemiAutomaticField [DERIVED] |
| 005d5968 | aAllowmanualove | R | aAllowManualOverride [DERIVED] |
| 005d597c | aBaulktorque | R | String_BaulkTorque [DERIVED] |
| 005d5988 | aClutchfriction | R | ClutchFrictionString [DERIVED] |
| 005d5998 | aClutchwear | R | ClutchwearString [DERIVED] |
| 005d59a4 | aClutchtorque | R | ClutchTorqueString [DERIVED] |
| 005d59b4 | aClutchinertia | R | String_ClutchInertia [DERIVED] |
| 005d59c4 | aDriveline | R | DrivelineString [DERIVED] |
| 005d59d0 | off_5D59D0 | R | Off_5D59D0_Vehicle [DERIVED] |
| 005d59d4 | aTrue_0 | R | TrueField [DERIVED] |
| 005d59dc | aRestrictorplat | R | RestrictorPlateString [DERIVED] |
| 005d59ec | aEngine_0 | R | EngineString [DERIVED] |
| 005d59f8 | aHandbrakepress_0 | R | HandbrakepressString [DERIVED] |
| 005d5a0c | aHandbrakepress | R | Str_Handbrakepress [DERIVED] |
| 005d5a24 | aBrakepressurer | R | StringBrakePressureR [DERIVED] |
| 005d5a38 | aBrakepressures | R | BrakePressureSettingString [DERIVED] |
| 005d5a50 | aRearbrakerange | R | RearBrakeRangeString [DERIVED] |
| 005d5a60 | aRearbrakesetti | R | RearbrakesettingString [DERIVED] |
| 005d5a74 | aSteerlockrange | R | SteerLockRangeStr [DERIVED] |
| 005d5a84 | aSteerlocksetti | R | SteerLockSettingString [DERIVED] |
| 005d5a98 | aAbslevel | R | ABSLevelField [DERIVED] |
| 005d5aa4 | aAbsgrip | R | aAbsGrip [DERIVED] |
| 005d5aac | aAbs4wheel | R | String_Abs4Wheel [DERIVED] |
| 005d5ab8 | aTractioncontro_0 | R | TractionControlString [DERIVED] |
| 005d5ad0 | aTractioncontro | R | TractioncontroString [DERIVED] |
| 005d5ae4 | aAutodownshiftg | R | AutoDownshiftGearString [DERIVED] |
| 005d5afc | aAutoupshiftgri | R | String_AutoUpshiftGrip [DERIVED] |
| 005d5b14 | aControls_0 | R | ControlsString [DERIVED] |
| 005d5b20 | aRear3rdfastreb_0 | R | Rear3rdFastReb [DERIVED] |
| 005d5b38 | aRear3rdfastreb | R | Rear3rdFastRebField [DERIVED] |
| 005d5b54 | aRear3rdslowreb_0 | R | RearSlowReboundString [DERIVED] |
| 005d5b6c | aRear3rdslowreb | R | Rear3rdslowrebString [DERIVED] |
| 005d5b88 | aRear3rdfastbum_0 | R | Rear3rdfastbumString [DERIVED] |
| 005d5ba0 | aRear3rdfastbum | R | Str_Rear3rdfastbum [DERIVED] |
| 005d5bb8 | aRear3rdslowbum_0 | R | StringRear3rdSlowBump [DERIVED] |
| 005d5bd0 | aRear3rdslowbum | R | Rear3rdSlowBumpString [DERIVED] |
| 005d5be8 | aRear3rdspringr | R | Rear3rdSpringRangeString [DERIVED] |
| 005d5bfc | aRear3rdsprings | R | Rear3rdspringsString [DERIVED] |
| 005d5c14 | aRear3rdpackerr | R | Rear3rdPackerRngStr [DERIVED] |
| 005d5c28 | aRear3rdpackers | R | Rear3rdPackersString [DERIVED] |
| 005d5c40 | aFront3rdfastre_0 | R | Front3rdFastRebField [DERIVED] |
| 005d5c5c | aFront3rdfastre | R | aFront3rdFastrecovery [DERIVED] |
| 005d5c78 | aFront3rdslowre_0 | R | String_Front3rdSlowRe_0 [DERIVED] |
| 005d5c94 | aFront3rdslowre | R | Front3rdSlowReturnString [DERIVED] |
| 005d5cb0 | aFront3rdfastbu_0 | R | Front3rdfastbuString [DERIVED] |
| 005d5cc8 | aFront3rdfastbu | R | Front3rdFastBumpStopString [DERIVED] |
| 005d5ce0 | aFront3rdslowbu_0 | R | String_Front3rdSlowBump [DERIVED] |
| 005d5cf8 | aFront3rdslowbu | R | Front3rdSlowBumpString [DERIVED] |
| 005d5d10 | aFront3rdspring_0 | R | Front3rdSpring2 [DERIVED] |
| 005d5d24 | aFront3rdspring | R | Front3rdSpringField [DERIVED] |
| 005d5d3c | aFront3rdpacker_0 | R | Front3rdPackerString [DERIVED] |
| 005d5d50 | aFront3rdpacker | R | Front3rdpackerString [DERIVED] |
| 005d5d68 | aRighttrackbarr | R | RighttrackbarrString [DERIVED] |
| 005d5d7c | aRighttrackbars | R | Str_Righttrackbars [DERIVED] |
| 005d5d94 | aLefttrackbarra | R | StringLeftTrackBarRa [DERIVED] |
| 005d5da8 | aLefttrackbarse | R | LeftTrackbarSettingString [DERIVED] |
| 005d5dbc | aRightcasterran | R | RightCasterRangeString [DERIVED] |
| 005d5dd0 | aRightcasterset | R | RightcastersetString [DERIVED] |
| 005d5de4 | aLeftcasterrang | R | LeftCasterRangeStr [DERIVED] |
| 005d5df4 | aLeftcastersett | R | LeftCasterSettingString [DERIVED] |
| 005d5e08 | aRightfenderfla_0 | R | RightFenderFlaField [DERIVED] |
| 005d5e20 | aRightfenderfla | R | aRightFenderFlap [DERIVED] |
| 005d5e38 | aLeftfenderflar_0 | R | String_LeftFenderFlar_0 [DERIVED] |
| 005d5e50 | aLeftfenderflar | R | LeftFenderFlareString [DERIVED] |
| 005d5e68 | aReartoeinrange | R | ReartoeinrangeString [DERIVED] |
| 005d5e78 | aReartoeinsetti | R | RearToeInSettingString [DERIVED] |
| 005d5e8c | aFronttoeinrang | R | String_FrontToeInRange [DERIVED] |
| 005d5e9c | aFronttoeinsett | R | FrontToeInSettingString [DERIVED] |
| 005d5eb0 | aRearantiswayra_0 | R | RearAntiSwayRa2 [DERIVED] |
| 005d5ec4 | aRearantiswayse | R | RearAntiSwaySetField [DERIVED] |
| 005d5ed8 | aFrontantiswayr_0 | R | FrontAntiSway2String [DERIVED] |
| 005d5eec | aFrontantisways | R | FrontantiswaysString [DERIVED] |
| 005d5f04 | aRear3rdrebound_0 | R | Rear3rdreboundString [DERIVED] |
| 005d5f1c | aRear3rdbumpsta | R | Str_Rear3rdbumpsta [DERIVED] |
| 005d5f30 | aRear3rdbumpsto_2 | R | StringRear3rdBumpstop [DERIVED] |
| 005d5f4c | aRear3rdbumpsto_1 | R | Rear3rdBumpstopString [DERIVED] |
| 005d5f64 | aRear3rdbumpsto_0 | R | Rear3rdBumpstopString [DERIVED] |
| 005d5f80 | aRear3rdbumpsto | R | Rear3rdbumpstopsString [DERIVED] |
| 005d5f98 | aRear3rdrebound | R | Rear3rdReboundStr [DERIVED] |
| 005d5fb0 | aRear3rdbumptra | R | Rear3rdBumpTravelString [DERIVED] |
| 005d5fc4 | aFront3rdreboun_0 | R | Front3rdReboundField [DERIVED] |
| 005d5fdc | aFront3rdbumpst_3 | R | aFront3rdBumpstop [DERIVED] |
| 005d5ff0 | aFront3rdbumpst_2 | R | String_Front3rdBumpst_2 [DERIVED] |
| 005d6010 | aFront3rdbumpst_1 | R | Front3rdBumpstopString [DERIVED] |
| 005d6028 | aFront3rdbumpst_0 | R | Front3rdbumpstString [DERIVED] |
| 005d6048 | aFront3rdbumpst | R | Front3rdBumpStopString [DERIVED] |
| 005d6060 | aFront3rdreboun | R | String_Front3rdRebound [DERIVED] |
| 005d6078 | aFront3rdbumptr | R | Front3rdBumpTravelString [DERIVED] |
| 005d608c | aRearantiswayra | R | RearAntiSwayRa [DERIVED] |
| 005d60a0 | aRearantiswayba | R | RearAntiSwayBarField [DERIVED] |
| 005d60b4 | aFrontantiswayr | R | FrontAntiSwayString [DERIVED] |
| 005d60c8 | aFrontantiswayb | R | FrontantiswaybString [DERIVED] |
| 005d60dc | aSpringbasedant | R | SpringbasedantString [DERIVED] |
| 005d60f0 | aRightwheelbase | R | Str_Rightwheelbase [DERIVED] |
| 005d6100 | aLeftwheelbase | R | StringLeftWheelBase [DERIVED] |
| 005d6110 | aRearwheeltrack | R | RearWheelTrackString [DERIVED] |
| 005d6120 | aFrontwheeltrac | R | FrontWheelTrackString [DERIVED] |
| 005d6130 | aAlignwheels | R | AlignwheelsString [DERIVED] |
| 005d613c | aAdjustsusprate | R | AdjustSuspRateStr [DERIVED] |
| 005d614c | aApplyslowtofas | R | ApplySlowToFastString [DERIVED] |
| 005d6164 | off_5D6164 | R | Off5D6164 [DERIVED] |
| 005d6168 | aPhysicalmodelf | R | aPhysicalModelFlag [DERIVED] |
| 005d617c | aSuspension_1 | R | String_Suspension_1 [DERIVED] |
| 005d618c | aDiffusercenter | R | DiffuserCenterString [DERIVED] |
| 005d619c | aDiffusersidewa | R | DiffusersidewaString [DERIVED] |
| 005d61b0 | aDiffuserfronth | R | DiffuserFrontHeightString [DERIVED] |
| 005d61c4 | aDiffuserbase | R | String_DiffuserBase [DERIVED] |
| 005d61d4 | aDiffuser | R | DiffuserString [DERIVED] |
| 005d61e0 | aBrakeductrange | R | BrakeDuctRange [DERIVED] |
| 005d61f0 | aBrakeductsetti | R | BrakeDuctSettingField [DERIVED] |
| 005d6204 | aBrakeductlift | R | BrakeDuctLiftString [DERIVED] |
| 005d6214 | aBrakeductdrag | R | BrakeductdragString [DERIVED] |
| 005d6224 | aRadiatorrange | R | RadiatorrangeString [DERIVED] |
| 005d6234 | aRadiatorsettin | R | Str_Radiatorsetting [DERIVED] |
| 005d6244 | aRadiatorlift | R | StringRadiatorLift [DERIVED] |
| 005d6254 | aRadiatordrag | R | RadiatorDragString [DERIVED] |
| 005d6264 | aBodycenter | R | BodyCenterString [DERIVED] |
| 005d6270 | aBodyrot | R | BodyrotString [DERIVED] |
| 005d6278 | aBodyfore | R | BodyForeStr [DERIVED] |
| 005d6284 | aBodyaft | R | BodyAftString [DERIVED] |
| 005d628c | aBodydown | R | BodyDownField [DERIVED] |
| 005d6298 | aBodyup | R | aBodyUp [DERIVED] |
| 005d62a0 | aBodyright | R | String_BodyRight [DERIVED] |
| 005d62ac | aBodyleft | R | BodyLeftString [DERIVED] |
| 005d62b8 | aBodymaxheight | R | BodymaxheightString [DERIVED] |
| 005d62c8 | aBodydragheight_0 | R | BodyDragHeightString [DERIVED] |
| 005d62dc | aBodydragheight | R | String_BodyDragHeight [DERIVED] |
| 005d62f0 | aBodydragbase | R | BodyDragBaseString [DERIVED] |
| 005d6300 | aBodyaero | R | BodyAero [DERIVED] |
| 005d630c | aRwrange | R | RwRangeField [DERIVED] |
| 005d6314 | aRwsetting | R | RWSettingString [DERIVED] |
| 005d6320 | aRwcenter | R | RwcenterString [DERIVED] |
| 005d632c | aRwrot | R | RwrotString [DERIVED] |
| 005d6334 | aRwfore | R | Str_Rwfore [DERIVED] |
| 005d633c | aRwaft | R | StringRWAft [DERIVED] |
| 005d6344 | aRwdown | R | RWDownString [DERIVED] |
| 005d634c | aRwup | R | RWUpString [DERIVED] |
| 005d6354 | aRwright | R | RwrightString [DERIVED] |
| 005d635c | aRwleft | R | RWLeftStr [DERIVED] |
| 005d6364 | aRwliftsideways | R | RWLiftSidewaysString [DERIVED] |
| 005d6374 | aRwliftparams | R | RwLiftParamsField [DERIVED] |
| 005d6384 | aRwdragparams | R | aRWDragParams [DERIVED] |
| 005d6394 | aRearwing | R | String_RearWing [DERIVED] |
| 005d63a0 | aRightfender | R | RightFenderString [DERIVED] |
| 005d63b0 | aLeftfender | R | LeftfenderString [DERIVED] |
| 005d63c0 | aFwrange | R | FwRangeString [DERIVED] |
| 005d63c8 | aFwsetting | R | String_FwSetting [DERIVED] |
| 005d63d4 | aFwcenter | R | FWCenterString [DERIVED] |
| 005d63e0 | aFwrot | R | FwRot [DERIVED] |
| 005d63e8 | aFwfore | R | FwForeField [DERIVED] |
| 005d63f0 | aFwaft | R | FWAftString [DERIVED] |
| 005d63f8 | aFwdown | R | FwdownString [DERIVED] |
| 005d6400 | aFwup | R | FwupString [DERIVED] |
| 005d6408 | aFwright | R | Str_Fwright [DERIVED] |
| 005d6410 | aFwleft | R | StringFWLeft [DERIVED] |
| 005d6418 | aFwliftsideways | R | FWLiftSidewaysString [DERIVED] |
| 005d6428 | aFwliftheight | R | FWLiftHeightString [DERIVED] |
| 005d6438 | aFwmaxheight | R | FwmaxheightString [DERIVED] |
| 005d6444 | aFwliftparams | R | FWLiftParamsStr [DERIVED] |
| 005d6454 | aFwdragparams | R | FWDragParamsString [DERIVED] |
| 005d6464 | aFrontwing | R | FrontWingField [DERIVED] |
| 005d6470 | aPitstop3range | R | aPitstop3Range [DERIVED] |
| 005d6480 | aPitstop3settin | R | String_Pitstop3Setting [DERIVED] |
| 005d6490 | aPitstop2range | R | Pitstop2RangeString [DERIVED] |
| 005d64a0 | aPitstop2settin | R | Pitstop2settinString [DERIVED] |
| 005d64b0 | aPitstop1range | R | Pitstop1RangeString [DERIVED] |
| 005d64c0 | aPitstop1settin | R | String_Pitstop1Setting [DERIVED] |
| 005d64d0 | aNumpitstopsran | R | NumPitStopsRangeString [DERIVED] |
| 005d64e4 | aNumpitstopsset | R | NumPitStopsSet [DERIVED] |
| 005d64f8 | aFuelrange | R | FuelRangeField [DERIVED] |
| 005d6504 | aFuelsetting | R | FuelSettingString [DERIVED] |
| 005d6510 | aTirecompoundse | R | TirecompoundseString [DERIVED] |
| 005d6524 | aWedgerange | R | WedgerangeString [DERIVED] |
| 005d6530 | aWedgesetting | R | Str_Wedgesetting [DERIVED] |
| 005d6540 | aCgrearrange | R | StringCGRearRange [DERIVED] |
| 005d654c | aCgrearsetting | R | CgRearSettingString [DERIVED] |
| 005d655c | aCgrightrange | R | CGRightRangeString [DERIVED] |
| 005d656c | aCgrightsetting | R | CgrightsettingString [DERIVED] |
| 005d657c | aDamagefile | R | DamageFileStr [DERIVED] |
| 005d6588 | aSymmetric_0 | R | SymmetricString [DERIVED] |
| 005d6594 | aNotes_0 | R | NotesField [DERIVED] |
| 005d659c | aAitorquestab | R | aDriverName_Aitor [DERIVED] |
| 005d65ac | aAidownforcebia | R | String_AiDownforceBias [DERIVED] |
| 005d65bc | aAidownforcezar | R | AiDownforceZARString [DERIVED] |
| 005d65cc | aAidamperfast | R | AidamperfastString [DERIVED] |
| 005d65dc | aAidamperslow | R | AiDamperSlowString [DERIVED] |
| 005d65ec | aAispringrate | R | String_AiSpringRate [DERIVED] |
| 005d65fc | aAievensuspensi | R | AIEvenSuspensionString [DERIVED] |
| 005d6610 | aAirotationthre | R | AiRotationThre [DERIVED] |
| 005d6624 | aAiminpassesper | R | AiMinPassesPerField [DERIVED] |
| 005d6638 | aFueltankmotion | R | FuelTankMotionString [DERIVED] |
| 005d6648 | aFueltankpos | R | FueltankposString [DERIVED] |
| 005d6654 | aSIsAnIllegalSv | R | SIsAnIllegalSvString [DERIVED] |
| 005d6670 | aTirebrand | R | Str_TireBrand [DERIVED] |
| 005d667c | aRrundertray | R | StringRRUndertray [DERIVED] |
| 005d6688 | aRlundertray | R | RLUndertrayString [DERIVED] |
| 005d6694 | aFrundertray | R | FrUndertrayString [DERIVED] |
| 005d66a0 | aFlundertray | R | FlundertrayString [DERIVED] |
| 005d66ac | aGraphicaloffse | R | GraphicalOffsetStr [DERIVED] |
| 005d66bc | aWedgepushrod | R | WedgePushrodString [DERIVED] |
| 005d66cc | aCgheight | R | CGHeightField [DERIVED] |
| 005d66d8 | aInertia | R | aInertia [DERIVED] |
| 005d66e0 | aMass | R | String_Mass [DERIVED] |
| 005d66e8 | aFeelerflags | R | FeelerFlagsString [DERIVED] |
| 005d66f4 | aGaragedisplayf | R | GaragedisplayfString [DERIVED] |
| 005d6708 | aRules | R | RulesString [DERIVED] |
| 005d6710 | aGeneral | R | String_General [DERIVED] |
| 005d671c | aSymmetric | R | SymmetricString [DERIVED] |
| 005d6728 | aCustom | R | Custom [DERIVED] |
| 005d6730 | aGearing | R | GearingField [DERIVED] |
| 005d673c | aRide | R | RideString [DERIVED] |
| 005d6744 | aBalance | R | BalanceString [DERIVED] |
| 005d6750 | aDownforce | R | DownforceString [DERIVED] |
| 005d675c | aNotes | R | Str_Notes [DERIVED] |
| 005d6764 | aSetting | R | StringSetting [DERIVED] |
| 005ea40c | flt_5EA40C | R | Unknown_Physics_5EA40C [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1f0 | CRTMathHelper_e1f0 | Reads range/setting key-value pairs from config and writes computed float values to output struct |
| 0042e530 | TrackConfig | Finalizes track configuration after all vehicle sections parsed |
| 0042ecc0 | ReplayStateCopy | Copies replay state data when a gear file is loaded |
| 0042ed50 | NameStringCopy | Copies tire brand name into vehicle name field of output struct |
| 004317f0 | DynamicsJointSetTargetPosition | Sets target position for dynamics joint (downforce, balance, ride, gearing) |
| 004c40d0 | FileFinder | Locates a referenced config file relative to vehicle file path |
| 004c58a0 | StringCopyWithValidation | Copies string with size limit validation (restrictor plate setting) |
| 004d7880 | TireBrandLookup | Looks up tire brand by name and returns compound data |
| 004d7a50 | StringSplitLoop | Checks debug flag bitmask to gate debug message emission |
| 004d7aa0 | DebugLogWrite | Writes formatted debug message on vehicle setup validation failure |
| 004f24f0 | VehicleDamageModel | Parses the damage model .ini file for the vehicle |
| 004f2c60 | PerWheelBrakeSuspensionDataLoader | Parses per-wheel brake and suspension data for a corner |
| 004f3090 | FenderAeroSetupSectionReader | Parses fender aero setup section for left or right fender |
| 004f3240 | VehicleDampingDirectionValidation | Validates damping direction coefficients for aero surfaces |
| 004f3490 | ArithmeticComparison_3490 | Reads and validates rotational aero coefficients |
| 004f3c10 | EngineMapSetupFieldDefinitions | Parses engine map setup field definitions |
| 004f3c80 | EngineSectionParser | Parses a separate engine .ini file loaded via FileFinder |
| 00534b00 | sub_534B00 | Opens file in binary read mode ("rb") |
| 005351d0 | LineInputReader | Reads next non-empty line from config file into line buffer |
| 00535390 | AudioStreamBufferRead | Seeks back to start of file after first-pass format check |
| 005355a0 | StreamFileTypeCheckWithDispatch | Closes file handle and dispatches based on file type check |
| 005651b0 | sub_5651B0 | Checks line token type (0=section data, 1=end-of-section, 4=EOF) |
| 005654a0 | sub_5654A0 | Reads string value for named key from current config line |
| 005655f0 | sub_5655F0 | Reads boolean/flag value for named key from current config line |
| 00565760 | sub_565760 | Reads integer value for named key from current config line |
| 00565aa0 | sub_565AA0 | Reads one to four numeric values for named key from current config line |
| 005665b0 | sub_5665B0 | Processes/parses the vehicle notes string |
| 00566650 | StringCopyWithBufferRealloc | Copies string into dynamically allocated buffer |
| 00587bcf | FreeWrapper_7bcf | Frees a heap-allocated memory block |
| 00587bdc | CRTFtol | Converts float to truncated integer (gear ratio interpolation) |
| 00587c20 | sub_587C20 | Case-insensitive substring search for section header matching |
| 00587ece | sub_587ECE | Returns length/type info for a string |
| 00588410 | sub_588410 | Case-insensitive exact string comparison (True, Rear, Four, Front) |
| 00589db0 | sub_589DB0 | Finds position of '=' delimiter in config line |

**Guard conditions:** File-open failure (v5==NULL) causes early return -1. On first pass (a4&1): if the file lacks any recognized section header among Setting/Notes/Downforce/Balance/Ride/Gearing/Custom/Symmetric, it is flagged as illegal .SVM and aborted. Non-server sessions (dword_7C569C != 5) trigger debug logging for validation failures. Restrictor plate check: if StringCopyWithValidation fails AND value is neither "True" nor special off-value nor length 1, v55 gates which engine file variant to load. In driveline section, gear count mismatch between ForwardGears and actually-parsed gear settings triggers gear-ratio interpolation. The a4&2 flag gates whether sub-config files (damage, engine, gear) should be actually parsed or just path-stored.
