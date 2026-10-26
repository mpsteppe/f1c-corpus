=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be65c | PitSpotsString | track | char[] | offset | 1 | String constant "PitSpots" used in track file parsing (FUN_00402690). Identifies pit spot area in track layout data |
| DAT_005be57c | Sector2LengthString | track | char[] | offset | 1 | String constant "Sector2Length" used in track file parsing (FUN_00402690). Identifies track sector 2 length parameter |
| DAT_008affac | PitEntryCheckFloat | physics | float | write | 1 | Float written in FUN_00402690 during track/pit entry validation. Stores computed check value for pit entry detection |
| DAT_007cb260 | FileParserStateFlag | file | int | read | 1 | State flag read in FUN_00404b60 during file parsing. Controls parser flow for setup/config file processing |
| DAT_0059e604 | SetupDataVTable | setup | ptr | read | 1 | VTable pointer for setup data object (FUN_0040c140). Points to virtual function table for setup serialization/deserialization class |
| DAT_005bea64 | GridwalkString | track | char[] | offset | 1 | String constant "Gridwalk" used in track/event configuration (FUN_0040d4c0). Identifies gridwalk event section |
| DAT_005beb18 | AnyTracksideString | track | char[] | offset | 1 | String constant "Any Trackside" used in track camera/event configuration (FUN_0040db00). Identifies trackside camera positions |
| DAT_0059e72c | CameraControllerVTable | camera | ptr | offset | 1 | VTable pointer for camera controller object (FUN_0040fe50). Routes camera update calls to active camera mode implementation |
| DAT_005be868 | StrncpyFillPattern | data | byte[4] | read | 1 | 4-byte pattern written at end of strncpy buffer in FUN_00414900. Used as padding/fill after string copy operations |
| DAT_005c254c | JacquesVString | driver | char[] | offset | 1 | String constant "Jacques V" (driver name) used in FUN_00415d90. Part of driver name table for AI driver data initialization |
| DAT_005c2480 | TakumaSString | driver | char[] | offset | 1 | String constant "Takuma S" (driver name) used in FUN_00415d90. Part of driver name table for AI driver data initialization |
| DAT_005c2984 | Benetton1999String | vehicle | char[] | offset | 1 | String constant "1999 Benetton" used in FUN_0041b980. Car/team name lookup for vehicle data initialization |
| DAT_005c286c | Arrows2001String | vehicle | char[] | offset | 1 | String constant "2001 Arrows" used in FUN_0041b980. Car/team name lookup for vehicle data initialization |
| DAT_005c2758 | Toyota2002String | vehicle | char[] | offset | 1 | String constant "2002 Toyota" used in FUN_0041b980. Car/team name lookup for vehicle data initialization |
| DAT_005c29d0 | SchoolString | setup | char[] | offset | 1 | String constant "School" used in FUN_004216f0. Identifies school/tutorial mode in game configuration/season setup |
| DAT_005c2c1c | ReplayDirString | setup | char[] | offset | 1 | String constant "ReplayDir" used in FUN_00421cd0. Identifies replay directory path in config file parsing |
| DAT_005c2b20 | InstallFromString | setup | char[] | offset | 1 | String constant "InstallFrom" used in FUN_00421cd0. Identifies installation source path in config |
| DAT_005c2f70 | TracksDirSString | setup | char[] | offset | 1 | String constant "TracksDirS" used in FUN_00422be0. Identifies tracks directory path in config/INI parsing |
| DAT_005c2e28 | VsyncDString | renderer | char[] | offset | 1 | String constant "VsyncD" used in FUN_00422be0. Identifies VSync toggle in config/INI parsing |
| DAT_005c3254 | DefaultScpString | setup | char[] | offset | 1 | String constant "Default.scp" used in FUN_00424080. Default setup file name parsed during vehicle setup loading |
| DAT_005ea2d0 | AIConfigZeroFloat | ai | float | read | 1 | Zero/epsilon float read in FUN_00424790 during AI initialization. Compared against AI ability thresholds for behavior setup |
| DAT_0059e938 | AIParamFloat1 | ai | float | read | 1 | Float parameter read in large AI update function FUN_004270a0 (9165 bytes). Used in AI vehicle behavior calculations including speed and aggression |
| DAT_005c3298 | VehicleArrayPtrPtr | setup | ptr | read | 1 | Pointer to VehicleArray (DAT_008ac394) stored as additional reference. Read in FUN_0042bdd0 during vehicle setup list management |
| DAT_007cc3ec | SessionTypeGateFlag | session | int | read | 1 | Session type gating flag read in FUN_0042c440. Controls session flow based on current session type setting |
| DAT_005c3548 | TestDayString | session | char[] | offset | 1 | String constant "TestDay" used in FUN_0042ce30. Identifies test day session type in event/session configuration |
| DAT_005c3600 | PitString | session | char[] | offset | 1 | String constant "Pit" used in FUN_0042d370. Identifies pit lane configuration section in session setup |
| DAT_005c3760 | SS_1String | session | char[] | offset | 1 | String constant "SS_1" used in FUN_0042ed70. Identifies sector/split section in session file parsing |
| DAT_005c3e38 | NumPitStopsSetString | setup | char[] | offset | 1 | String constant "NumPitStopsSet" used in FUN_0042fd00. Identifies pit stop count field in vehicle setup file (.svm) |
| DAT_005c3cac | RightCasterSetString | setup | char[] | offset | 1 | String constant "RightCasterSet" used in FUN_0042fd00. Identifies right caster angle field in vehicle setup file |
| DAT_005c3a98 | EngineString | setup | char[] | offset | 1 | String constant "Engine" used in FUN_0042fd00. Identifies engine settings section in vehicle setup file |
| DAT_005c3900 | RideHeightSetString | setup | char[] | offset | 1 | String constant "RideHeightSet" used in FUN_0042fd00. Identifies ride height setting field in vehicle setup file |
| DAT_005c3f64 | SetupOptionsVTable | setup | ptr | offset | 1 | VTable pointer for setup options class (FUN_00430f00). Used for setup file I/O object construction |
| DAT_005c4068 | DotExtension | file | char[] | offset | 1 | String constant "." (dot) used in FUN_00433290. Default file extension separator for path manipulation when no extension found |
| DAT_005c40d0 | SpringDirString | setup | char[] | offset | 1 | String constant "SpringDir" used in FUN_00435410. Identifies spring direction parameter in suspension setup section |
| DAT_005c41b0 | FlWheelString | setup | char[] | offset | 1 | String constant "FlWheel" used in FUN_00438da0. Identifies front-left wheel setup section in vehicle configuration |
| DAT_0059ebc0 | SuspensionDoubleConst | physics | double | read | 1 | Double constant used in FUN_00439210 for suspension geometry calculation. Part of wheel/suspension kinematic model |
| DAT_005c4328 | TireOptimumCamString | setup | char[] | offset | 1 | String constant "TireOptimumCam" used in FUN_0043da10. Identifies optimal camber field in tire setup section |
| DAT_0059ed60 | TireWearWobbleDouble | physics/tire | double | read | 1 | Double constant used in FUN_00442060 for tire wear wobble simulation. Controls amplitude of tire vibration with wear as function of DAT_008aae70 ring buffer |
| DAT_0059ee98 | TireTempIntegration | physics/tire | double | read | 1 | Double constant used in large tire temperature integration function FUN_004441f0 (9101 bytes). Part of thermal model integration |
| DAT_0059ee08 | TireTempIntegration2 | physics/tire | double | read | 1 | Second double constant used in tire temperature integration FUN_004441f0. Paired with DAT_0059ee98 for thermal calculation |
| DAT_005c43b8 | SamBientHelicoString | audio | char[] | offset | 1 | String constant "SamBientHelico" used in FUN_00448140. Identifies helicopter ambient sound source in audio configuration |
| DAT_007cca78 | FloatInit | audio | float | write | 1 | Initialized to 1.0f (0x3f800000) in FUN_0044c920. Part of audio source initialization block (group with DAT_007cca6c/70/74) |
| DAT_007ca4dc | FloatInit | audio | float | write | 1 | Initialized to 0.0f in FUN_0044d340. Part of audio source init block (group with DAT_007ca4d0/4d4/4d8). Audio channel/parameter startup value |
| DAT_007ccd30 | CollisionInitBlock | collision | int | write | 1 | Zeroed as part of collision grid param init block in FUN_0044d520. Group of 5 fields initialized alongside size constants |
| DAT_007d21f4 | RenderParamFloat | renderer | float | read | 1 | Float parameter read in large rendering function FUN_0044ff50 (5968 bytes). Controls render state or visual effect parameter |
| DAT_005ad3cc | RenderParamFlag | renderer | int | read | 1 | Integer flag read in FUN_0044ff50 for render state decision. Controls rendering path selection or feature toggle |
| DAT_007d1358 | EnableFlag | game | byte | read | 1 | Enable/disable flag checked in FUN_00451720. Controls particle/effect rendering toggle — when zero, skips display object creation |
| DAT_0059ef5c | RenderEffectFloat | renderer | float | read | 1 | Float parameter read in FUN_00451720 for rendering effect calculation. Controls visual effect intensity or scale |
| DAT_007ca564 | AudioBufferPointer | audio | ptr | read | 1 | Audio buffer/source pointer read in FUN_00452b10. Compared against known audio source addresses for channel routing/assignment |
| DAT_007cd0f0 | CollisionCellCount | collision | int | write | 1 | Written in FUN_004537b0 during collision system setup. Cell count or grid dimension for spatial partitioning |
| DAT_007cca24 | CollisionMiscFloat | collision | float | write | 1 | Written in FUN_004537b0 during collision parameter initialization. Part of collision config struct alongside related DAT_ globals |
| DAT_005c5608 | ThirdGearString | UI | char[] | offset | 1 | String constant "ThirdGear" used in FUN_00455290. UI text string for HUD/menu display |
| DAT_005c54ec | RestartRaceString | UI | char[] | offset | 1 | String constant "RestartRace" used in FUN_00455290. UI text string for restart race menu option |
| DAT_005c56e8 | EnteredHwinputString | input | char[] | offset | 1 | String constant "EnteredHwinput" used in FUN_00455d50. Debug/log message for hardware input device registration |
| DAT_0059ef9c | ForceFeedbackGain | input | float | read | 1 | Force feedback gain multiplier. Used in FUN_00456f70: scales force feedback effect magnitude. Branch selects DAT_0059efa0 for effect type 1 |
| DAT_0059f070 | TrackCollisionDouble | physics | double | read | 1 | Double constant used in FUN_0045a8e0 for track/tire collision detection. Part of vehicle-track interaction model |
| DAT_005c5bf0 | OpenPlayingString | network | char[] | offset | 1 | String constant "OpenPlaying" used in FUN_0045cf50. Network session state string for open playing session status |
| DAT_007d117c | InputDeadzoneFloat | input | float | read | 1 | Input deadzone threshold float read in FUN_0045e620. Controls joystick/wheel input deadzone for steering and pedal axes |
| DAT_005c5ef0 | HasEnteredTheGString | network | char[] | offset | 1 | String constant "HasEnteredTheG" used in FUN_0045fc50. Network message for driver entrance to garages area |
| DAT_007d0fc4 | AudioConfigTarget1 | audio | int | write | 1 | Audio configuration target value written in FUN_00461900. Controls audio channel/output routing from config parsing |
| DAT_007ce88e | AudioConfigFlag | audio | byte | read | 1 | Audio configuration flag byte read in FUN_00461900. Part of audio config block parsed from game settings |
| DAT_005c6194 | StartingLanUpdString | network | char[] | offset | 1 | String constant "StartingLanUpd" used in FUN_00461de0. Network debug log for LAN update starting |
| DAT_005c64b4 | SettingGamePasString | network | char[] | offset | 1 | String constant "SettingGamePas" used in FUN_00463160. Network debug log for game password setup |
| DAT_005c6508 | CouldNotAutojoString | network | char[] | offset | 1 | String constant "CouldNotAutojo" used in FUN_004637a0. Error message when auto-join to network session fails |
| DAT_0059f210 | NetworkVTable | network | ptr | offset | 1 | VTable pointer for network object (FUN_004668e0). Part of network subsystem object construction |
| DAT_007d2dd8 | NetSessionFlag | network | int | read | 1 | Network session flag read in FUN_0046a560. Controls network session state/behavior |
| DAT_005c6b38 | ProfileAlreadyString | UI | char[] | offset | 1 | String constant "ProfileAlready" used in FUN_0046cb50. UI error message for duplicate profile name |
| DAT_007cd84d | FilmModeFlag | renderer | byte | write | 1 | Flag written to 0 in FUN_00470490. Controls render-to-texture/film mode toggle for special rendering effects |
| DAT_005c7194 | TrackExtMagic | file | short | read | 1 | 2-byte magic value read in track file path resolution FUN_004793ec. Part of filename extension matching logic |
| DAT_005c7374 | DS_7String | debug | char[] | offset | 1 | String constant "DS_7" used in debug display function FUN_0047dbe0. Debug overlay label for state/display data |
| DAT_005c7464 | LapRecordString | UI | char[] | offset | 1 | String constant "LapRecord" used in FUN_0047e440. UI text for lap record display |
| DAT_005ac5f0 | VTablePtr | unknown | ptr | offset | 1 | VTable pointer set in FUN_0048fb70 during object construction. Generic object vtable initialization |
| DAT_005cc75c | NullGizmonamePString | UI | char[] | offset | 1 | String constant "NullGizmonameP" used in FUN_00492a40. UI debug/error message for unnamed gizmo element |
| DAT_005cc7ac | Font1String | UI | char[] | offset | 1 | String constant "Font1" used in FUN_00493060. Identifies font resource name for UI rendering |
| DAT_005cc920 | AnimruleString | UI | char[] | offset | 1 | String constant "Animrule" used in FUN_00493990. Identifies animation rule section in UI config |
| DAT_005ac9d0 | AILearningDouble | ai | double | read | 1 | Double constant used in FUN_004962c0 for AI learning/interpolation. Controls AI driver behavior learning rate between stored and computed values |
| DAT_005ccb30 | CouldNotLoadSString | UI | char[] | offset | 1 | String constant "CouldNotLoadS" used in FUN_00499f70. Error message for UI asset load failure |
| DAT_005ccbec | UIObjectVTable | UI | ptr | read | 1 | VTable pointer for UI object class (FUN_0049c140). Dispatches UI object virtual method calls |
| DAT_005ccb88 | UIManagerVTable | UI | ptr | read | 1 | VTable pointer for UI manager class (FUN_0049ca00). Dispatches UI manager virtual calls |
| DAT_005ccee0 | OilString | setup | char[] | offset | 1 | String constant "Oil" used in FUN_0049db80. Identifies oil parameter field in vehicle setup file |
| DAT_007cc2b8 | AudioChannelBusyFlag | audio | int | read | 1 | Audio channel busy flag read in FUN_0049f790. Controls audio channel allocation — non-zero value blocks channel reuse |
| DAT_007ce284 | SessionStateWrite42 | session | int | write | 1 | Written in FUN_004a1200 as part of session state update. Part of session data synchronization block |
| DAT_007ce2cc | SessionStateWrite43 | session | int | write | 1 | Written in FUN_004a1200 alongside DAT_007ce284. Session state synchronization value |
| DAT_005cd2a4 | FrontRightWheeString | setup | char[] | offset | 1 | String constant "FrontRightWhee" used in FUN_004a24d0. Identifies front right wheel section in vehicle setup |
| DAT_005cd438 | DetailDString | UI | char[] | offset | 1 | String constant "DetailD" used in FUN_004a2a90. Identifies detail level setting in UI config |
| DAT_005cd4b0 | LeftString | UI | char[] | offset | 1 | String constant "Left" used in FUN_004a3910. UI direction/label string for left-side controls |
| DAT_005cd5cc | PitsMasString | UI | char[] | offset | 1 | String constant "PitsMas" used in FUN_004a4900. UI text for pit mass/crew display |
| DAT_008acfc8 | RaceStartGateFlag | race | int | read | 1 | Race start gating flag read in FUN_004a5ea0. Controls race start phase transitions |
| DAT_005cd6dc | ChampString | UI | char[] | offset | 1 | String constant "Champ" used in FUN_004aa1e0. UI label for championship mode/standings display |
| DAT_005d1e90 | OppositeLockString | setup | char[] | offset | 1 | String constant "OppositeLock" used in FUN_004aa270. Identifies opposite lock steering setting in controller config |
| DAT_005d1b40 | WhetherOldCarsString | session | char[] | offset | 1 | String constant "WhetherOldCars" used in FUN_004aa270. Config key for enabling/disabling old car models in session |
| DAT_005d1948 | RunWarmupString | session | char[] | offset | 1 | String constant "RunWarmup" used in FUN_004aa270. Config key for warmup lap enable in session settings |
| DAT_005d1688 | MaximumSoundEfString | audio | char[] | offset | 1 | String constant "MaximumSoundEf" used in FUN_004aa270. Config key for maximum sound effects count setting |
| DAT_005d1478 | ControlsVoString | input | char[] | offset | 1 | String constant "0010ControlsVo" used in FUN_004aa270. Config key for controls/voice settings section |
| DAT_005d12ec | HelicopterAmbiString | audio | char[] | offset | 1 | String constant "HelicopterAmbi" used in FUN_004aa270. Config key for helicopter ambient sound toggle |
| DAT_005d112c | GarageDetailString | renderer | char[] | offset | 1 | String constant "GarageDetail" used in FUN_004aa270. Config key for garage detail rendering level |
| DAT_005d0e60 | WhetherEngineSString | audio | char[] | offset | 1 | String constant "WhetherEngineS" used in FUN_004aa270. Config key for engine sound enable/disable |
| DAT_005d0b68 | AngleToLookaheString | ai | char[] | offset | 1 | String constant "AngleToLookahe" used in FUN_004aa270. Config key for AI lookahead angle setting |
| DAT_005d0978 | SkidDetailString | renderer | char[] | offset | 1 | String constant "SkidDetail" used in FUN_004aa270. Config key for skid mark detail level |
| DAT_005d06e4 | BasicControlsString | input | char[] | offset | 1 | String constant "BasicControls" used in FUN_004aa270. Config key for basic controls settings section |
| DAT_005d0470 | AdditionalFuelString | setup | char[] | offset | 1 | String constant "AdditionalFuel" used in FUN_004aa270. Config key for additional fuel load setting |
| DAT_005d01d4 | AutocalibrateAString | input | char[] | offset | 1 | String constant "AutocalibrateA" used in FUN_004aa270. Config key for auto-calibration of analog axes |
| DAT_005cff94 | RaceLengthString | session | char[] | offset | 1 | String constant "RaceLength" used in FUN_004aa270. Config key for race length/distance setting |
| DAT_005cfcb8 | AndFormulaoneOString | session | char[] | offset | 1 | String constant "AndFormulaoneO" used in FUN_004aa270. Config key for F1 season/event options |
| DAT_005cf820 | WhetherServersString | network | char[] | offset | 1 | String constant "WhetherServers" used in FUN_004aa270. Config key for dedicated server mode toggle |
| DAT_005cf4f0 | ServerSettingWString | network | char[] | offset | 1 | String constant "ServerSettingW" used in FUN_004aa270. Config key for server settings window/section |
| DAT_005cf0e8 | OptionsString | UI | char[] | offset | 1 | String constant "Options" used in FUN_004aa270. Config key for options menu section |
| DAT_005ced38 | ExponentToApplString | input | char[] | offset | 1 | String constant "ExponentToAppl" used in FUN_004aa270. Config key for input response curve exponent |
| DAT_005ceb4c | Controller1S1String | input | char[] | offset | 1 | String constant "Controller1S1" used in FUN_004aa270. Config key for controller 1 button/axis mapping |
| DAT_005ce938 | ControlSeventhString | input | char[] | offset | 1 | String constant "ControlSeventh" used in FUN_004aa270. Config key for 7th controller control mapping |
| DAT_005ce75c | ControlDisplayString | UI | char[] | offset | 1 | String constant "ControlDisplay" used in FUN_004aa270. Config key for control display settings |
| DAT_005ce458 | ControlsFrequeString | input | char[] | offset | 1 | String constant "ControlsFreque" used in FUN_004aa270. Config key for control polling frequency |
| DAT_005cdf40 | CoefficientToUString | input | char[] | offset | 1 | String constant "CoefficientToU" used in FUN_004aa270. Config key for force feedback coefficient |
| DAT_005cdb60 | FfbBrakeVibeZeString | input | char[] | offset | 1 | String constant "FfbBrakeVibeZe" used in FUN_004aa270. Config key for FFB brake vibration zone setting |
| DAT_005cd76c | DirectinputCoeString | input | char[] | offset | 1 | String constant "DirectinputCoe" used in FUN_004aa270. Config key for DirectInput coefficient |
| DAT_005acc50 | InputObjectVTable | input | ptr | offset | 1 | VTable pointer for input device object (FUN_004b1a30). Input device class virtual function table |
| DAT_005accf4 | RandomSeedMult | math | float | read | 1 | Float multiplier used in FUN_004b3c60 for seeded random number generation. Combined with GetTickCount for hash-based randomization |
| DAT_005d2444 | SavingReplayString | replay | char[] | offset | 1 | String constant "SavingReplay" used in FUN_004b7500. UI/message for replay saving progress |
| DAT_005d2530 | ElectronicsString | setup | char[] | offset | 1 | String constant "Electronics" used in FUN_004bb730. Identifies electronics settings section in vehicle setup |
| DAT_005d25b0 | WrongWayString | UI | char[] | offset | 1 | String constant "WrongWay" used in FUN_004bccc0. UI warning text displayed when driving wrong direction |
| DAT_0083ee58 | ScoringDataPtr | scoring | ptr | write | 1 | Pointer written in FUN_004bf4f0. Points to scoring data structure (DAT_007d2e54) for post-race scoring calculations |
| DAT_005d27e8 | VehfileSString | file | char[] | offset | 1 | String constant "VehFile: %s" format used in FUN_004c0690. Debug/log format string for vehicle file path display |
| DAT_005d28c0 | QualifytimeString | session | char[] | offset | 1 | String constant "Qualifytime" used in FUN_004c11e0. Identifies qualifying time field in session data display |
| DAT_005d2cc4 | RacecondReconnString | network | char[] | offset | 1 | String constant "RacecondReconn" used in FUN_004c2420. Network status message for race condition reconnection |
| DAT_005d302c | HeadphysicsString | session | char[] | offset | 1 | String constant "Headphysics" used in FUN_004c3200. Identifies head physics enable flag in session configuration |
| DAT_005d2f2c | TeamworldchampString | scoring | char[] | offset | 1 | String constant "Teamworldchamp" used in FUN_004c3200. Identifies team world championship field in scoring data |
| DAT_005d31c0 | SS_ScnString | file | char[] | offset | 1 | String constant "%s.scn" format used in FUN_004c54f0. SCN file path format for scene loading |
| DAT_005d33f0 | EnteredSoundReString | audio | char[] | offset | 1 | String constant "EnteredSoundRe" used in FUN_004c8b20. Debug/log for sound resource entry |
| DAT_005ace5c | SoundObjVTable | audio | ptr | offset | 1 | VTable pointer for sound object class (FUN_004c9a50). Dispatches sound object virtual methods based on sound type (1-7) |
| DAT_005d35f8 | GrowthString | renderer | char[] | offset | 1 | String constant "Growth" used in FUN_004ca480. Identifies growth parameter in material/texture effect settings |
| DAT_005d350c | ChromakeyString | renderer | char[] | offset | 1 | String constant "Chromakey" used in FUN_004ca480. Identifies chroma key setting in renderer material config |
| DAT_005d3724 | InvdstcolorString | renderer | char[] | offset | 1 | String constant "Invdstcolor" used in FUN_004cada0. Identifies inverted destination color blend mode in render state |
| DAT_005d38f0 | LegalString | UI | char[] | offset | 1 | String constant "Legal" used in FUN_004cdd80. Identifies legal/disclaimer section in menu configuration |
| DAT_005d3838 | MaterialsString | renderer | char[] | offset | 1 | String constant "Materials" used in FUN_004cdd80. Identifies materials library section in scene config |
| DAT_005d3a0c | EnteredSpecialString | game | char[] | offset | 1 | String constant "EnteredSpecial" used in FUN_004cfff0. Debug/log for special mode entry |
| DAT_005d3a3c | UnableToSetupSString | UI | char[] | offset | 1 | String constant "UnableToSetupS" used in FUN_004d0110. Error message for setup save failure |
| DAT_005d4164 | DateFormatString | UI | char[] | offset | 1 | String constant "%02d/%02d/%02d/%02d" used in FUN_004d24d0. Date/time format for session result display |
| DAT_005d3ff4 | DriveaidsThrotString | setup | char[] | offset | 1 | String constant "DriveaidsThrot" used in FUN_004d24d0. Identifies throttle drive aid setting in setup file |
| DAT_005d3dc8 | TireMultDString | setup | char[] | offset | 1 | String constant "TireMultD" used in FUN_004d24d0. Identifies tire multiplier parameter in result display |
| DAT_005d3c74 | RacedateDqString | session | char[] | offset | 1 | String constant "RacedateDq" used in FUN_004d24d0. Identifies race date or DQ flag in session results |
| DAT_005d429c | NoPitInPolyFouString | track | char[] | offset | 1 | String constant "NoPitInPolyFou" used in FUN_004d38f0. Error string for track polygon without pit entry |
| DAT_005d432c | RacetimescaledString | session | char[] | offset | 1 | String constant "Racetimescaled" used in FUN_004d3cf0. Identifies race time scaling setting in session config |
| DAT_005d4564 | LatAccelMSString | telemetry | char[] | offset | 1 | String constant "LatAccelMS" used in FUN_004d4a80. Telemetry label for lateral acceleration display |
| DAT_005d4438 | TyreRightTempKString | telemetry | char[] | offset | 1 | String constant "TyreRightTempK" used in FUN_004d4a80. Telemetry label for right tire temperature |
| DAT_005d4610 | FirstDataPointString | telemetry | char[] | offset | 1 | String constant "FirstDataPoint" used in FUN_004d5f70. Identifies first data point in telemetry logging |
| DAT_005d47a0 | SoftnessString | tire | char[] | offset | 1 | String constant "Softness" used in FUN_004d6b00. Identifies tire compound softness setting in setup |
| DAT_005d49dc | TbcString | setup | char[] | offset | 1 | String constant "Tbc" used in FUN_004d7660. Identifies TBC (traction/brake control) setting in setup |
| DAT_005d4a50 | TelemetryVTable | telemetry | ptr | read | 1 | VTable pointer for telemetry data object (FUN_004d8ab0). Telemetry recording class dispatch table |
| DAT_005acfc4 | GameObjVTable | game | ptr | offset | 1 | VTable pointer for game object class (FUN_004daea0). Factory creates objects of types 0-0x13 with different vtable assignments |
| DAT_005d4c78 | WchelmetString | UI | char[] | offset | 1 | String constant "Wchelmet" used in FUN_004ddad0. Identifies wheel/helmet camera setting in UI config |
| DAT_005c67bc | SpinString | physics | char[] | offset | 1 | String constant "Spin" used in FUN_004ddf90. Debug/log for vehicle spin detection |
| DAT_005d4d74 | SuspensionString | setup | char[] | offset | 1 | String constant "Suspension" used in FUN_004dfce0. Identifies suspension setup section in vehicle config |
| DAT_005d4e7c | RestrictionsphString | track | char[] | offset | 1 | String constant "Restrictionsph" used in FUN_004e3360. Identifies track restriction zone (speed limit) in physics |
| DAT_005ad19c | TireWearDecayMult | physics/tire | float | read | 1 | Float multiplier used in FUN_004e5f60 (tire wear model, 3593 bytes). Scales tire wear decay rate during vehicle dynamics |
| DAT_005ad200 | TireGripCalcFloat | physics/tire | float | read | 1 | Float constant used in FUN_004ed960 (tire grip calculation, 2003 bytes). Controls tire grip computation with DAT_007d0c60 (TireWearMultiplier) |
| DAT_007d0a8c | PitTimerFloat | session | float | read | 1 | Pit timer threshold float read in vehicle update FUN_004f1fe0. Controls pit lane speed limit timer duration |
| DAT_005d4f0c | WheelrandomString | physics | char[] | offset | 1 | String constant "Wheelrandom" used in FUN_004f24f0. Identifies wheel random vibration parameter in physics config |
| DAT_005d5224 | BrakeoptimumteString | setup | char[] | offset | 1 | String constant "Brakeoptimumte" used in FUN_004f2c60. Identifies optimum brake temperature setting in vehicle setup |
| DAT_005d50f0 | SlowbumpsettinString | setup | char[] | offset | 1 | String constant "Slowbumpsettin" used in FUN_004f2c60. Identifies slow bump setting in suspension setup |
| DAT_005d53fc | YForceAppliedWString | telemetry | char[] | offset | 1 | String constant "YForceAppliedW" used in FUN_004f3240. Telemetry label for lateral force on wheels |
| DAT_005d567c | RpmtorqueString | telemetry | char[] | offset | 1 | String constant "Rpmtorque" used in FUN_004f3c80. Telemetry label for RPM vs torque display |
| DAT_005d6750 | DownforceString | setup | char[] | offset | 1 | String constant "Downforce" used in FUN_004f4270. Identifies downforce setup section in vehicle config |
| DAT_005d6654 | SIsAnIllegalSvString | UI | char[] | offset | 1 | String constant "SIsAnIllegalSv" used in FUN_004f4270. Error message for illegal setup value in vehicle config |
| DAT_005d6524 | WedgerangeString | setup | char[] | offset | 1 | String constant "Wedgerange" used in FUN_004f4270. Identifies wedge (corner weight) range setting in vehicle setup |
| DAT_005d6400 | FwupString | setup | char[] | offset | 1 | String constant "Fwup" used in FUN_004f4270. Identifies front wing up setting in aerodynamics setup |
| DAT_005d632c | RwrotString | setup | char[] | offset | 1 | String constant "Rwrot" used in FUN_004f4270. Identifies rear wing rotation/angle setting in aero setup |
| DAT_005d6224 | RadiatorrangeString | setup | char[] | offset | 1 | String constant "Radiatorrange" used in FUN_004f4270. Identifies radiator opening range in vehicle setup |
| DAT_005d60dc | SpringbasedantString | setup | char[] | offset | 1 | String constant "Springbasedant" used in FUN_004f4270. Identifies spring-based anti-roll bar setting in suspension setup |
| DAT_005d5f04 | Rear3rdreboundString | setup | char[] | offset | 1 | String constant "Rear3rdrebound" used in FUN_004f4270. Identifies rear 3rd spring rebound setting in suspension |
| DAT_005d5d68 | RighttrackbarrString | setup | char[] | offset | 1 | String constant "Righttrackbarr" used in FUN_004f4270. Identifies right track bar setting in suspension setup |
| DAT_005d5b88 | Rear3rdfastbumString | setup | char[] | offset | 1 | String constant "Rear3rdfastbum" used in FUN_004f4270. Identifies rear 3rd fast bump setting in suspension setup |
| DAT_005d59f8 | HandbrakepressString | setup | char[] | offset | 1 | String constant "Handbrakepress" used in FUN_004f4270. Identifies handbrake pressure in vehicle setup |
| DAT_005d58ea | FourString | setup | char[] | offset | 1 | String constant "Four" used in FUN_004f4270. Numeric string "4" for setup value/option identification |
| DAT_005d5790 | FrontleftString | setup | char[] | offset | 1 | String constant "Frontleft" used in FUN_004f4270. Identifies front-left wheel corner in vehicle setup |
| DAT_008af8fc | TireDynamicsFloat | physics/tire | float | read | 1 | Float constant read in tire/vehicle dynamics function FUN_004f70c0. Controls tire force calculation parameter |
| DAT_005d6bc0 | ShiftrangeString | setup | char[] | offset | 1 | String constant "Shiftrange" used in FUN_004f7460. Identifies shift range setting in gearbox setup |
| DAT_005d6a4f | ShiftSetupByte1 | setup | byte | offset | 1 | Byte located at offset in shift setup data block (FUN_004f7460). Part of gear ratio/settings table |
| DAT_005d68bf | ShiftSetupByte2 | setup | byte | offset | 1 | Byte located at offset in shift setup data block (FUN_004f7460). Paired with DAT_005d6a4f in gear ratio table |
| DAT_005d6d94 | FontMasString | UI | char[] | offset | 1 | String constant "FontMas" used in FUN_004f8d70. Identifies font size/mass setting in UI configuration |
| DAT_008afeb8 | TrackSurfaceFloat | track | float | offset | 1 | Float constant used in track surface/rendering function FUN_004f9480. Controls track surface visual parameter |
| DAT_007cfc68 | WeatherStateFlag | weather | int | read | 1 | Weather state flag read in FUN_004fa7e0. Controls weather system state transitions |
| DAT_005d6f5c | WccloudsString | weather | char[] | offset | 1 | String constant "Wcclouds" used in FUN_004fc550. Identifies weather cloud coverage setting in weather config |
| DAT_005ad2f8 | RainDropScale | weather | float | read | 1 | Weather rain drop scale multiplier used in FUN_004fd8b0. Controls rain drop visual size in weather rendering |
| DAT_005ad320 | WetnessGainFloat | weather | float | read | 1 | Float constant read in FUN_004fe0d0 for weather/wetness visual gain. Controls surface wetness rendering intensity |
| DAT_005d6fe0 | TracktempString | weather | char[] | offset | 1 | String constant "Tracktemp" used in FUN_004fe350. Identifies track temperature field in weather/conditions config |
| DAT_005a0038 | WeatherThreshold | weather | float | read | 1 | Weather threshold float used in FUN_004feaa0 for rain intensity level selection. Returns 4 or 5 based on comparison with DAT_005ad334 and DAT_0059e6e8 |
| DAT_005d71f8 | D3DFormatTable | renderer | int[] | read | 1 | DirectX surface format lookup table used in FUN_005026a4. Array of format descriptors with stride 9 ints each, terminated by 0. Maps D3D format GUIDs to internal surface format IDs |
| DAT_005ba678 | DXVertexBuffer | renderer | struct | offset | 1 | DirectX vertex buffer structure used in FUN_0050a7e1. Contains vertex buffer allocation with stride 0x10 per element and count based on input param |
| DAT_005adc7c | DXTextureVTable | renderer | ptr | offset | 1 | VTable pointer for DirectX texture object (FUN_0050ae76). Texture class dispatch for D3D operations |
| DAT_005addac | DXSurfaceVTable | renderer | ptr | offset | 1 | VTable pointer for DirectX surface object (FUN_0050b743). Surface class dispatch with size 0x30 allocation |
| DAT_005d7898 | RendererFuncPtr | renderer | ptr | read | 1 | Renderer function pointer read in FUN_0050c762. Called as indirect jump for render dispatch with 6 parameters |
| DAT_005ade68 | DXTextureValueName | renderer | char[] | offset | 1 | String constant "ValueName" used in DirectX texture operations (FUN_0050fc7d). Identifies value name field in texture config |
| DAT_005af284 | GamaString | renderer | char[] | offset | 1 | String constant "Gama" used in FUN_005119e9. Identifies gamma correction setting in renderer configuration |
| DAT_005af4ec | SameStructureRString | file | char[] | offset | 1 | String constant "SameStructureR" used in FUN_00513bf9. Debug/log message for identical file structure check |
| DAT_005af8b8 | MemPoolFreeList | memory | ptr[] | read | 1 | Memory pool free list array indexed by allocation type (param_2 = 0 or 1). Points to first free block in each pool. Used in FUN_00515f23 memory allocator |
| DAT_005afb7c | UnknownCompresString | file | char[] | offset | 1 | String constant "UnknownCompres" used in FUN_005188b4. Error message for unknown compression type in file loading |
| DAT_005afdf8 | SSEMathFloat | math | float | read | 1 | Float constant used in SIMD math function FUN_00518d29. Part of SSE-optimized vector/matrix operations |
| DAT_005d89f0 | SSESubwordConstant | renderer | int | read | 1 | SIMD subword constant used in FUN_0051c813 for pixel/surface processing. Used with psubsw instruction for packed word operations in texture decode |
| DAT_008d60c4 | SIMD_RSqrtConst | math/SIMD | float | read | 1 | Float constant for SSE reciprocal square root approximation in FUN_0051f98e. Part of Newton-Raphson refinement for vector normalization |
| DAT_008d6130 | SIMD_VecMathConst | math/SIMD | float | read | 1 | Float constant used in SIMD 3x3 matrix symmetric Eigenvalue/vector computation (FUN_0051fd90). Added to diagonal during covariance matrix decomposition |
| DAT_008d6210 | SIMD_XMMConst | math/SIMD | int[4] | read | 1 | 128-bit XMM constant used in FUN_005208fe for SSE vector permutation/shuffle operations. Part of quaternion/matrix transformation pipeline |
| DAT_005d8cc0 | SIMD_FilterConst | math/SIMD | int[4] | read | 1 | 128-bit SSE constant used in FUN_00520c0e for 4x4 matrix/vector transformation. Part of polynomial evaluation for 4D vector operations |
| DAT_005b0774 | InvalidStoredBString | file | char[] | offset | 1 | String constant "InvalidStoredB" used in FUN_00527752. Error message for invalid stored data format in file I/O |
| DAT_005d9130 | SIMD_3DNowConst | math/3DNow | int[4] | read | 1 | 64-bit MMX/3DNow! constant used in FUN_00528bd0 for SIMD floating-point operations. Part of 3DNow! instruction path for vector math |
| DAT_005d9398 | SIMD_MathCoeff | math/3DNow | int | read | 1 | Integer constant used in FUN_00528f00 for 3DNow!/MMX polynomial evaluation pipeline. Part of packed floating-point arithmetic for vector math |
| DAT_005d93c8 | SIMD_3DNowConst2 | math/3DNow | int | read | 1 | 3DNow!/MMX constant used in FUN_00529200 for SIMD floating point operations. Part of 3DNow! vector math pipeline |
| DAT_005b0bb0 | AudioMixConst | audio | int | read | 1 | Constant used in large audio mixing function FUN_0052ab4e (1720 bytes). Part of 16-bit precision audio mixing with packed word arithmetic |
| DAT_005b0c50 | AudioMixConst2 | audio | int | read | 1 | Second constant used in FUN_0052ab4e audio mixing pipeline. Paired with DAT_005b0bb0 for packed audio sample processing |
| DAT_005da698 | CmpegfileplayeString | audio | char[] | offset | 1 | String constant "Cmpegfileplaye" used in FUN_0052e1d0. Identifies MPEG file player class string in audio system |
| DAT_008b04a4 | AudioCodecTable | audio | ptr | offset | 1 | Audio codec lookup table used in FUN_00531250 (1385 bytes). Indexed by codec type to select decode parameters and settings |
| DAT_008b598c | WaveletDSPFloat | audio/DSP | float | write | 1 | Written in FUN_00531b50 audio/DSP processing function (3910 bytes). Part of wavelet/subband transform coefficients for audio filtering |
| DAT_005b775c | WaveletCoeff14 | audio/DSP | float | read | 1 | Wavelet transform coefficient used in FUN_00531b50 (row 14 of 16). Multiplied against delayed sample differences in discrete wavelet transform |
| DAT_005b7778 | WaveletTransformAdd | audio/DSP | float | read | 1 | Wavelet transform addition coefficient used in FUN_00531b50. Part of the sum/difference operation in subband decomposition |
| DAT_008b59f4 | WaveletOutFloat | audio/DSP | float | write | 1 | Output float written during wavelet transform in FUN_00531b50. Stores transformed coefficient for subsequent audio synthesis |
| DAT_005da784 | AudioCodecStateFlag | audio | int | read | 1 | State flag read in FUN_00534b10 audio codec function. Controls audio decoder state machine transitions |
| DAT_005da8d0 | TooManyLengthOString | audio | char[] | offset | 1 | String constant "TooManyLengthO" used in FUN_00537110. Error message for audio buffer overflow / length limit |
| DAT_005dbb0c | OversubscribedString | audio | char[] | offset | 1 | String constant "Oversubscribed" used in FUN_0053a4d0. Error message for audio channel oversubscription |
| DAT_005dbd60 | ErrorCreatingIString | renderer | char[] | offset | 1 | String constant "ErrorCreatingI" used in FUN_00540fc0. Error message for DirectX interface creation failure |
| DAT_005dbfd0 | SurfaceMatLibMString | renderer | char[] | offset | 1 | String constant "SurfaceMatLibM" used in FUN_0054c510. Identifies surface material library method in renderer |
| DAT_005dc140 | TooManyVerticeString | renderer | char[] | offset | 1 | String constant "TooManyVertice" used in FUN_00553650. Error message for vertex buffer overflow |
| DAT_005dc27c | StorageString | renderer | char[] | offset | 1 | String constant "Storage" used in FUN_0055a790. Identifies storage format/type in render resource management |
| DAT_005dc2b8 | PlanesString | renderer | char[] | offset | 1 | String constant "Planes" used in FUN_0055a910. Identifies plane count in render surface/config parsing |
| DAT_005dc470 | VertexTransformCount | renderer | int | write | 1 | Vertex transform count written in FUN_0055ee20. Stores number of vertices to transform in matrix multiply pipeline |
| DAT_005dc578 | RenderStateEnum | renderer | int | read | 1 | Render state enumeration value read in FUN_0055f0d0. Controls specific D3D render state parameter |
| DAT_005dc526 | RenderStateByte | renderer | byte | read | 1 | Byte parameter read in FUN_0055f0d0 for render state configuration. Part of D3D render state setup |
| DAT_005dc4d0 | RenderFormatConst | renderer | int | read | 1 | Integer constant read in FUN_0055f0d0 for render surface format selection |
| DAT_005dc484 | RenderBlendConst | renderer | int | read | 1 | Integer constant read in FUN_0055f0d0 for render blend state configuration |
| DAT_005e4ef8 | CppNameString | file | char[] | offset | 1 | String constant "name" used in FUN_00562d90 for C++ name/label lookup in file operations |
| DAT_005e505c | QueryidString | file | char[] | offset | 1 | String constant "Queryid" used in FUN_00564410 for file resource query identification |
| DAT_005e5168 | FileModeByte | file | byte | read | 1 | Byte read in FUN_00566940 for file open mode selection. Part of file I/O mode parameter string construction |
| DAT_005e51bc | Lpt4String | file | char[] | offset | 1 | String constant "Lpt4" used in FUN_005687f0 for LPT port name in parallel device I/O |
| DAT_005e5310 | FileOpVTable | file | ptr | offset | 1 | VTable pointer for file operation class (FUN_0056d930). File I/O method dispatch table |
| DAT_008d0198 | SolverWorkspaceDbl1 | dynamics | double | read | 1 | Double workspace variable in LDL^T block sparse solver (FUN_0056fa96, 17786 bytes). Part of dynamics constraint solver matrix workspace at 0x8D0000-0x8D9000 |
| DAT_008d3990 | SolverWorkspaceInt1 | dynamics | int | offset | 1 | Integer workspace variable in LDL^T block sparse solver (FUN_0056fa96). Index/offset tracking for constraint matrix factorization |
| DAT_008cfe58 | SolverWorkspaceDbl2 | dynamics | double | write | 1 | Double workspace variable written in LDL^T solver. Stores intermediate factor during block decomposition |
| DAT_008d1718 | SolverWorkspaceDbl3 | dynamics | double | read | 1 | Double workspace variable read in LDL^T solver. Constraint matrix diagonal element in factorization |
| DAT_008d01c8 | SolverWorkspaceDbl4 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Part of constraint matrix element storage during decomposition |
| DAT_008d1298 | SolverWorkspaceDbl5 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Off-diagonal matrix element in constraint factorization |
| DAT_008d0418 | SolverWorkspaceDbl6 | dynamics | double | write | 1 | Double workspace variable written in LDL^T solver. Stores computed Schur complement update |
| DAT_008d1b10 | SolverWorkspaceDbl7 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Right-hand side vector element for constraint solve |
| DAT_008d0718 | SolverWorkspaceUnk1 | dynamics | unk | offset | 1 | Unclassified workspace variable in LDL^T block sparse solver. Part of constraint matrix workspace block at 0x8D0000 |
| DAT_008d1dc8 | SolverWorkspaceDbl8 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Intermediate product in forward/back substitution |
| DAT_008d2058 | SolverWorkspaceDbl9 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Diagonal scaling factor in constraint preconditioner |
| DAT_008d1c30 | SolverWorkspaceDbl10 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Element of permuted constraint matrix during factorization |
| DAT_008d0c08 | SolverWorkspaceUnk2 | dynamics | unk | offset | 1 | Unclassified workspace variable in LDL^T solver. Part of constraint matrix workspace at 0x8D0000 |
| DAT_008d1550 | SolverWorkspaceDbl11 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Row/column scaling factor in constraint solve |
| DAT_008d1e00 | SolverWorkspaceDbl12 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Accumulated product in forward substitution pass |
| DAT_008d1c58 | SolverWorkspaceDbl13 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Backup/temporary storage during pivot modification |
| DAT_008d1c60 | SolverWorkspaceDbl14 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Element of decomposed L factor matrix |
| DAT_008d1b78 | SolverWorkspaceDbl15 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Subdiagonal entry in L factor during decomposition |
| DAT_008d1e20 | SolverWorkspaceDbl16 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Scaled right-hand side during backward substitution |
| DAT_008d20b0 | SolverWorkspaceDbl17 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Permuted solution component during substitution |
| DAT_008d16b0 | SolverWorkspaceDbl18 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Temporary in Schur complement computation |
| DAT_008d1ab0 | SolverWorkspaceDbl19 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Accumulated update for constraint impulse |
| DAT_008d20d0 | SolverWorkspaceDbl20 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Diagonal entry in pivoted factorization |
| DAT_008d1e58 | SolverWorkspaceDbl21 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Residual tracking in iterative refinement |
| DAT_008d1d90 | SolverWorkspaceDbl22 | dynamics | double | read | 1 | Double workspace variable in LDL^T solver. Off-diagonal entry in sparse factorization |
| DAT_008d1e80 | SolverWorkspaceUnk3 | dynamics | unk | offset | 1 | Unclassified workspace variable in LDL^T solver. Part of constraint matrix workspace |
| DAT_008d3ba4 | FactorWorkspaceInt1 | dynamics | int | offset | 1 | Integer workspace variable in LDL^T factorization (FUN_00575bbd, 13241 bytes). Index tracking for block sparse Cholesky/LDL^T decomposition |
| DAT_008d3b80 | FactorWorkspaceInt2 | dynamics | int | offset | 1 | Integer workspace variable in LDL^T factorization. Block column index in sparse matrix decomposition |
| DAT_008d3b94 | FactorWorkspaceInt3 | dynamics | int | offset | 1 | Integer workspace variable in LDL^T factorization. Row offset in constraint block matrix |
| DAT_008d2c90 | FactorWorkspaceDbl1 | dynamics | double | write | 1 | Double workspace variable written in LDL^T factorization. Stores computed factor diagonal block |
| DAT_008d3110 | FactorWorkspaceUnk1 | dynamics | unk | offset | 1 | Unclassified workspace variable in LDL^T factorization. Part of block sparse factor workspace at 0x8D0000-0x8D9000 |
| DAT_008d3730 | FactorWorkspaceDbl2 | dynamics | double | write | 1 | Double workspace variable written in LDL^T factorization. Stores computed factor off-diagonal block |
| DAT_005ba90c | NetSocketStruct | network | struct | offset | 1 | Network socket structure used in FUN_0057b330 (509 bytes). Contains socket address linked list for network connection management |
| DAT_005e5490 | FaultString | network | char[] | offset | 1 | String constant "Fault" used in FUN_0057cb50. Debug/error string for network fault detection |
| DAT_005e5cf0 | TheNameOrTheNaString | file | char[] | offset | 1 | String constant "TheNameOrTheNa" used in FUN_0057d400. Error message for invalid file name in CRT/file operations |
| DAT_005e54e4 | WsagetlasterroString | network | char[] | offset | 1 | String constant "Wsagetlasterro" used in FUN_0057d400. Debug string for Winsock getlasterror call |
| DAT_005bac84 | FileHandleStruct | file | struct | offset | 1 | File handle/IO completion structure used in FUN_00581c20 (278 bytes). Manages file handle and linked list of pending I/O operations |
| DAT_005b8b5c | FactoryStructPtr | file | int | read | 1 | Integer read during factory object initialization in FUN_005837f0. Part of COM-like factory pattern for file/memory system object creation |
| DAT_008d3e31 | EHCodePtr | CRT | ptr | offset | 1 | Exception handling code pointer in MSVC CRT (FUN_00586ed0). Part of C++ exception handling data in .text section |
| DAT_005e63e4 | LocaleString1 | CRT | char[] | offset | 1 | Locale/encoding string constant used in FUN_00588e4e for character set conversion. Compared against input for locale-sensitive string processing |
| DAT_008d3eac | AppExitFlag | CRT | int | write | 1 | Application exit flag written in FUN_00589cc6. Set to 1 when initiating process termination. Controls CRT cleanup path |
| DAT_005e65c4 | KeyCodeTable | input | int | read | 1 | Keyboard scancode-to-virtual-key lookup table read in FUN_0058af5c. Maps hardware scancodes to virtual key codes. Array of pairs with stride 8 |
| DAT_005e7738 | MathConstDouble | math | double | read | 1 | Double constant used in FUN_0058de2c for math library function (atan/atan2 variant). Branch-specific return value for special IEEE cases |
| DAT_005e9a88 | LocaleDataPtr | CRT | ptr | offset | 1 | Locale data pointer in FUN_0058f4f2 for internationalization. Points to locale-specific string/code page data blocks |
| DAT_005e6d6c | LocaleTablePtr | CRT | ptr | read | 1 | Locale table pointer read in FUN_005904f7 for locale-dependent format/parsing operations |
| DAT_005b95c8 | LocaleInfoStruct | CRT | struct | offset | 1 | Locale info exception handling structure used in FUN_00591fa1. Part of LCID-to-string mapping for internationalization |
| DAT_008d4018 | LocaleTimeField | CRT | ushort | read | 1 | Locale time field value read in FUN_0059249b for time range validation. Part of locale-specific time format data |
| DAT_005b9908 | LocaleSepString | CRT | char[] | offset | 1 | ASCII string constant used in FUN_005932f3 for locale-specific separator/format character |
| DAT_005e9b40 | CodePageTable | CRT | byte | read | 1 | Code page mapping table byte read in FUN_00596e40 for character set conversion. Part of multi-byte to wide-char translation lookup |
| DAT_005b9b78 | LocaleInfoStruct2 | CRT | struct | offset | 1 | Locale info structure used in FUN_00597e4f for GetLocaleInfo API wrapper. Part of CRT locale data infrastructure |
| DAT_005bb5c8 | LocaleObjVTable | CRT | ptr | offset | 1 | VTable pointer for locale object class (FUN_00599e71). Locale info object destructor dispatch table |
| DAT_005bb8a0 | LocaleObjVTable2 | CRT | ptr | offset | 1 | VTable pointer for secondary locale object class (FUN_0059ad49). Alternative locale object dispatch table |
| DAT_005c7524 | NullPtrSentinel | data | int | write | 1 | Written at address 0x008d8000 (out of normal range). Likely a null pointer sentinel or debug marker at end of data segment |
