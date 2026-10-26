=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be610 | PitOriString | setup | char* | offset | 1 | "PitOri" string constant — used in vehicle/team file parsing for pit orientation config key |
| DAT_008affb0 | UnknownPhysicsFloat | physics | float | write | 1 | Physics-related float written during initialization in FUN_00402690 |
| DAT_005be488 | WpGrooveLatString | setup | char* | offset | 1 | "WpGrooveLat" INI key string — waypoint groove lateral offset setting in track/ai config |
| DAT_005be8b0 | TwoSeaterString | setup | char* | offset | 1 | "2seater" string constant — vehicle classification flag for 2-seater car body type |
| DAT_008acebc | PhysicsEventCounter | physics | int | read | 1 | Physics event counter/flag read in FUN_0040ca30 — gates physics processing during update loop |
| DAT_005bea10 | PositionString | setup | char* | offset | 1 | "Position" string constant — INI/config key for position parameter |
| DAT_005beb88 | ConeString | setup | char* | offset | 1 | "Cone" string constant — track cone/marker object name in scene file parsing |
| DAT_005ea5dc | FileEnumSentinel | setup | int | write | 1 | File enumeration sentinel (-1) — initialized to 0xFFFFFFFF in DAT_005ea5d0..5dc struct during file directory scan |
| DAT_005c23f4 | CircuitBString | setup | char* | offset | 1 | "CircuitB" string constant — circuit/scene filename suffix or key |
| DAT_005c24f4 | JosVString | setup | char* | offset | 1 | "Jos V" driver name string — driver name constant used in driver data table |
| DAT_005c2418 | ToranosukeTString | setup | char* | offset | 1 | "Toranosuke T" driver name string — driver name constant used in driver data table |
| DAT_005c2904 | Arrows2000String | setup | char* | offset | 1 | "2000 Arrows" team name string — team name constant used in team/vehicle data |
| DAT_005c27f0 | Sauber2001String | setup | char* | offset | 1 | "2001 Sauber" team name string — team name constant used in team/vehicle data |
| DAT_005c2a4c | AudioOptionsString | setup | char* | offset | 1 | "AudioOptions" INI section string — audio options config section key |
| DAT_005c2cac | SoundDirString | setup | char* | offset | 1 | "SoundDir" INI key string — sound directory path config key |
| DAT_005c2ba8 | TexDetailString | setup | char* | offset | 1 | "TexDetail" INI key string — texture detail level config key |
| DAT_005c2abc | VersionString | setup | char* | offset | 1 | "Version" INI key string — version string config key |
| DAT_005c2edc | SystemRamDString | setup | char* | offset | 1 | "SystemRam D" display/info string — system RAM detection display label |
| DAT_005c2da8 | VersionFString | setup | char* | offset | 1 | "Version F" display string — version info display label |
| DAT_005c31ec | PassingString | setup | char* | offset | 1 | "Passing" INI/config key string — passing/track aggression parameter key |
| DAT_0059e8c4 | SteeringDeltaThreshold | dynamics | float | read | 1 | Steering angle delta threshold — added to vehicle velocity magnitude in AI steering/follow logic (FUN_00425920) |
| DAT_0059e984 | AIOvertakeDistance | ai | float | read | 1 | AI overtaking distance threshold — compared in AI overtake/rejoin logic for gap evaluation (FUN_0042a7d0) |
| DAT_005c3430 | StabilityAssistString | setup | char* | offset | 1 | "StabilityAssist" INI key string — stability assist setting config key |
| DAT_007c9340 | ScoringAudioAccum0 | steward | int | write | 1 | Scoring/audio accumulation counter (part of 12-zeroed block 0x7c932c-0x7c9358) — reset each 10th tick in steward update loop |
| DAT_005c34e0 | Practice4String | setup | char* | offset | 1 | "Practice4" session name string — practice session 4 label |
| DAT_005c36d8 | RatioString | setup | char* | offset | 1 | "Ratio" INI key string — gear ratio or differential ratio config key |
| DAT_0059ea10 | GearChangeThreshold | dynamics | double | read | 1 | Gear ratio change threshold — used in gear selection ratio comparison (FUN_0042f1e0) |
| DAT_005c3d98 | RearWingString | setup | char* | offset | 1 | "RearWing" INI key string — rear wing angle/aero config key |
| DAT_005c3bac | Rear3rdPackersString | setup | char* | offset | 1 | "Rear3rdPackers" INI key string — rear third spring packers config key |
| DAT_005c39d4 | DiffPowerSettingString | setup | char* | offset | 1 | "DiffPowerSetting" INI key string — differential power setting config key |
| DAT_005c3854 | BalanceFString | setup | char* | offset | 1 | "Balance F" INI key string — front brake balance config key |
| DAT_005c3f24 | GString | setup | char* | offset | 1 | "G" string constant — short config key/format string |
| DAT_005c4088 | GridWalkCamString | setup | char* | offset | 1 | "GridWalkCam" INI key string — grid walk camera mode config key |
| DAT_0059eb00 | EngineTempDamageThreshold | physics/thermal | double | read | 1 | Engine temperature damage threshold — compared in thermal/damage model (FUN_00436870) |
| DAT_005c4144 | FuelTankString | setup | char* | offset | 1 | "FuelTank" INI key string — fuel tank capacity config key |
| DAT_005c42c4 | FrForeUpperString | setup | char* | offset | 1 | "FrForeUpper" INI key string — front fore upper wishbone config key |
| DAT_0059ecc0 | ClutchSlipThreshold | dynamics | double | read | 1 | Clutch slip engagement threshold — used in clutch/transmission torque transfer model (FUN_0043ef20) |
| DAT_0059edb0 | DifferentialLockThreshold | dynamics | double | read | 1 | Differential locking threshold — controls diff lockup based on wheel speed difference ratio (FUN_00443b70) |
| DAT_0059ee60 | AntiRollBarStiffness | dynamics | double | read | 1 | Anti-roll bar stiffness constant — used in suspension anti-roll force calculation (FUN_004441f0) |
| DAT_0059edd8 | WheelLoadTransferScale | dynamics | double | read | 1 | Wheel load transfer scale factor — scales load transfer in suspension/tire model (FUN_004441f0) |
| DAT_005c4404 | GaussianEliminationString | setup | char* | offset | 1 | "GaussianElimination" debug/assert string — solver debug label |
| DAT_007ca488 | CollisionScaleInit | collision | int | write | 1 | Collision scale initialization (-1082130432 = -1.0f) — paired with DAT_007ca48C=0.0f as initial collision parameters |
| DAT_007cccf4 | CollisionStateCounter | collision | int | write | 1 | Collision state counter — zeroed with 5 companions (0xcccf0-0xccd04) in collision state init |
| DAT_005c5430 | Cursor02CurString | setup | char* | offset | 1 | "Cursor02.cur" cursor filename string — mouse cursor resource name |
| DAT_005ad378 | AIAudioStateBuffer | ai/audio | int | read | 1 | AI audio state buffer pointer — used in AI state machine for audio-triggered state transitions (FUN_0044ff50) |
| DAT_005ad3a0 | AIAudioStateBuffer2 | ai/audio | int | read | 1 | AI audio state buffer pointer (secondary) — paired with DAT_005ad378 in audio processing |
| DAT_007c8a80 | VehicleBodyAngularVel | dynamics | double | read | 1 | Vehicle body angular velocity correction — double-precision angular velocity used in vehicle position/rotation update (FUN_00451720) |
| DAT_007cd1c0 | CollisionObjectListPtr | collision | int | read | 1 | Collision object list pointer — compared against known object bases in collision type dispatch (FUN_00452b10) |
| DAT_007cd18c | CameraMinClipDist | renderer | float | write | 1 | Camera minimum clip distance — set from vehicle config field +0x1148 in camera setup (FUN_004537b0) |
| DAT_007ca43c | CameraFovScale | renderer | float | write | 1 | Camera FOV scale factor — set from vehicle config field +0x1150 in camera FOV setup (FUN_004537b0) |
| DAT_007cd168 | CameraLookOffset | renderer | struct | offset | 1 | Camera look-at offset — used in camera target position calculation (FUN_00454350) |
| DAT_005c5580 | LcdIncreaseString | setup | char* | offset | 1 | "LcdIncrease" INI key string — LCD increase control binding key |
| DAT_005c5480 | LookDownString | setup | char* | offset | 1 | "LookDown" INI key string — look down camera control binding key |
| DAT_005c5768 | PositionOffsetString | setup | char* | offset | 1 | "PositionOffset" INI key string — camera position offset config key |
| DAT_005c5ac8 | MovementRateString | setup | char* | offset | 1 | "MovementRate" INI key string — camera movement rate config key |
| DAT_005c5b60 | S5FormatString | setup | char* | offset | 1 | "%s" format string — used in path concatenation (FUN_0045bc10) |
| DAT_005c5dac | NextSessionString | setup | char* | offset | 1 | "NextSession" INI key string — next session/config option key |
| DAT_005c5e18 | AutoChat06String | setup | char* | offset | 1 | "AutoChat06" INI key string — auto chat message config key |
| DAT_005c602c | NetCommSetSelfString | setup | char* | offset | 1 | "NetComm_SetSelf" INI/function string — network self-identification function key |
| DAT_007ceb18 | RaceSetupParam | race | int | read | 1 | Race setup parameter — loaded from player data in FUN_00461900 as char-to-int config value |
| DAT_007ced4c | RaceSetupParam2 | race | int | read | 1 | Race setup parameter (secondary) — loaded from player data at offset +0x6f |
| DAT_005c6260 | TheGameIsFullString | setup | char* | offset | 1 | "The game is full!" error string — network session full error message |
| DAT_005c63c8 | NewAddressString | setup | char* | offset | 1 | "NewAddress" string — network address change config key |
| DAT_007d0eac | NetworkSessionStruct | network | struct | offset | 1 | Network session structure — session join/create data block used in FUN_00463f70 |
| DAT_005c678c | VviewScnString | setup | char* | offset | 1 | "vview.scn" filename string — vehicle view scene file suffix |
| DAT_005c69e0 | PopupControlSetString | setup | char* | offset | 1 | "PopupControlSet" INI key string — popup control set config key |
| DAT_005c6cd4 | SceneBaseSString | setup | char* | offset | 1 | "SceneBaseS" format string — scene filename base pattern |
| DAT_005c7150 | GameFilterString | setup | char* | offset | 1 | "Game Filter" string constant — game filter category name in device enumeration (FUN_00477830) |
| DAT_005c7368 | BeginString | setup | char* | offset | 1 | "Begin" string constant — scene file begin marker |
| DAT_005c7394 | WinsString | setup | char* | offset | 1 | "Wins" INI key string — wins statistic config key |
| DAT_005c6b5c | PopupAddProfileString | setup | char* | offset | 1 | "PopupAddProfile" INI key string — add profile popup config key |
| DAT_005cc584 | SystemFontString | setup | char* | offset | 1 | "SystemFont" INI key string — system font selection key |
| DAT_005cc6e0 | TooltipString | setup | char* | offset | 1 | "Tooltip" INI key string — tooltip display config key |
| DAT_005cc870 | DoPageTransitionString | setup | char* | offset | 1 | "DoPageTransition" INI key string — page transition animation config key |
| DAT_005cc270 | ControlBindingsTable | setup | void* | read | 1 | Control bindings function/offset table — pointer array for control binding configuration |
| DAT_005cca48 | NoDropIconString | setup | char* | offset | 1 | "nodropicon_0000" bitmap resource string — no-drop zone icon bitmap name |
| DAT_005ccdf4 | NetProblemBmpString | setup | char* | offset | 1 | "netproblem.bmp" bitmap filename — network problem warning bitmap |
| DAT_005cce98 | FormatSString | setup | char* | offset | 1 | "%1f %s" format string — display format for timed score values |
| DAT_005ccbac | ScoringConfigTable | scoring | void* | read | 1 | Scoring configuration table pointer — points to points/scoring config data array |
| DAT_005ccf54 | EnteredOnScreenString | setup | char* | offset | 1 | "EnteredOnScreen" INI key string — on-screen entry display config key |
| DAT_005cd00c | WinRaceBikString | setup | char* | offset | 1 | "winrace.bik" video filename — win race celebration video file |
| DAT_007ce280 | RaceSessionStateFlag | race | int | write | 1 | Race session state flag — set during session state transitions (FUN_004a1200) |
| DAT_005cd14c | CubeErrorLoadingString | setup | char* | offset | 1 | "Cube Error Loading" string — cube map loading error message |
| DAT_005cd20c | TimerManString | setup | char* | offset | 1 | "10sec_Rman2" string — 10-second timer animation/sound resource name |
| DAT_005cd3b8 | RrwheeloffMtsString | setup | char* | offset | 1 | "Rrwheeloff.mts" filename — rear wheel off material/shader filename |
| DAT_005cd4f0 | TyresString | setup | char* | offset | 1 | "Tyres" INI key string — tyre selection/config key |
| DAT_0059ea40 | SuspensionSpringK | dynamics | double | read | 1 | Suspension spring rate base constant — used in spring force calculation (FUN_004a58b0) |
| DAT_005acba8 | SoundManagerVTable | audio | ptr | offset | 1 | Sound manager vtable pointer — sound manager object virtual function table reference (FUN_004a70e0) |
| DAT_005d1f84 | DriverNameString | setup | char* | offset | 1 | "DriverName" INI key string — driver name config/display key |
| DAT_005d1d3c | AutoBlipString | setup | char* | offset | 1 | "AutoBlip" INI key string — auto blip (throttle blip on downshift) config key |
| DAT_005d1a28 | TelemetryString | setup | char* | offset | 1 | "Telemetry Telemetry" INI section string — telemetry output config key |
| DAT_005d17a4 | ReconnaissanceString | setup | char* | offset | 1 | "Reconnaissance" INI key string — reconnaissance mode config key |
| DAT_005d15a8 | SoundFxVolumeString | setup | char* | offset | 1 | "SoundFXVolume" INI key string — sound effects volume config key |
| DAT_005d13c0 | AirhornRangeString | setup | char* | offset | 1 | "AirhornRange" INI key string — airhorn range config key |
| DAT_005d1238 | ShowRearWingAngleString | setup | char* | offset | 1 | "ShowRearWingAngle" INI key string — rear wing angle display config key |
| DAT_005d1040 | CloudScrollString | setup | char* | offset | 1 | "CloudScroll" INI key string — cloud scroll speed config key |
| DAT_005d0d54 | GlanceRateString | setup | char* | offset | 1 | "GlanceRate" INI key string — glance/look rate config key |
| DAT_005d0a68 | CompressedTextureString | setup | char* | offset | 1 | "CompressedTexture" INI key string — compressed texture config key |
| DAT_005d08a0 | AllowHudInCockpitString | setup | char* | offset | 1 | "AllowHUDInCockpit" INI key string — HUD-in-cockpit toggle config key |
| DAT_005d05bc | RecordHotlapsString | setup | char* | offset | 1 | "RecordHotlaps" INI key string — hotlap recording config key |
| DAT_005d0310 | AiMaxLoadString | setup | char* | offset | 1 | "AIMaxLoad" INI key string — AI maximum load config key |
| DAT_005d0074 | CurrentGdbFileNameString | setup | char* | offset | 1 | "The current GDB file name is" string — debug/status message about GDB file |
| DAT_005cfe0c | ArtificiallyKeepString | setup | char* | offset | 1 | "ArtificiallyKeep" INI key string — artificially keep AI in race config key |
| DAT_005cfb1c | DefinedByTheHostString | setup | char* | offset | 1 | "DefinedByTheHost" INI key string — host-defined setting indicator |
| DAT_005cf6e0 | GameListSortMethodString | setup | char* | offset | 1 | "GameListSortMethod" INI key string — game list sort method config key |
| DAT_005cf2e8 | BoneSpringThresholdString | setup | char* | offset | 1 | "BoneSpringThreshold" INI key string — bone spring threshold config key |
| DAT_005cf050 | ForceFeedbackString | setup | char* | offset | 1 | "ForceFeedback" INI key string — force feedback config section key |
| DAT_005cebfc | Controller2YString | setup | char* | offset | 1 | "Controller2Y" INI key string — controller 2 Y-axis binding key |
| DAT_005cea38 | ControlSteerRightString | setup | char* | offset | 1 | "ControlSteerRight" INI key string — steer right control binding key |
| DAT_005ce860 | ControlLaunchControlString | setup | char* | offset | 1 | "ControlLaunchControl" INI key string — launch control control binding |
| DAT_005ce698 | ControlLookRollString | setup | char* | offset | 1 | "ControlLookRoll" INI key string — look roll control binding key |
| DAT_005ce220 | FfbSteerForceString | setup | char* | offset | 1 | "FFBSteerForce" INI key string — force feedback steering force config key |
| DAT_005cdd8c | FfbThrottleVibString | setup | char* | offset | 1 | "FFBThrottleVib" INI key string — force feedback throttle vibration config key |
| DAT_005cd998 | FfbRumbleStripString | setup | char* | offset | 1 | "FFBRumbleStrip" INI key string — force feedback rumble strip config key |
| DAT_005d2018 | AscStringConstant | setup | char* | offset | 1 | String constant (prefix) — used in file path construction (FUN_004b0770) |
| DAT_005accb8 | ShortConversionClampLow | renderer | float | read | 1 | Float-to-short conversion lower clamp bound — values below this become 0x8001 (-32767) (FUN_004b2750) |
| DAT_008ab6fc | PhysicsMemoryBlockCount | dynamics | int | write | 1 | Physics memory block allocation counter — incremented per block in dynamics solver workspace init (FUN_004b44e0) |
| DAT_005d2494 | ReplayRecordingString | setup | char* | offset | 1 | "ReplayRecording" INI key string — replay recording config key |
| DAT_00680000 | SceneDataBaseAddress | renderer | struct | offset | 1 | Scene/data base address (0x680000) — base address for scene object data, compared in rendering/scene object pointer checks (FUN_004bbfc0) |
| DAT_005d2630 | RenderStateTable | renderer | void* | read | 1 | Render state function table — vtable/function pointer table for render state handling |
| DAT_005d2710 | RcdFileString | setup | char* | offset | 1 | "RCDFile" INI key string — replay/recording file config key |
| DAT_005d272c | ControlTypeDString | setup | char* | offset | 1 | "ControlType" format/display string — control type label in driver stats serialization (FUN_004c0690) |
| DAT_005d2e3c | TotalRacesWithString | setup | char* | offset | 1 | "TotalRacesWith" INI key string — total races with ... config key |
| DAT_005d2bdc | GameOptRaceLenString | setup | char* | offset | 1 | "GameoptRaceLen" INI key string — game option race length config key |
| DAT_005d2fbc | NumberString | setup | char* | offset | 1 | "Number" INI key string — number/config selection key |
| DAT_005d306c | ExtensionSuffixData | file | int | read | 1 | File extension suffix bytes (2 dwords) — appended during filename extension replacement: `.scn`/`.dat` suffix construction (FUN_004c38d0) |
| DAT_005ec448 | TrackDirPathPtr | setup | char* | read | 1 | Track directory path pointer — second track path (alternate/fallback track directory) |
| DAT_005d3448 | AmbientString | setup | char* | offset | 1 | "Ambient" string constant — ambient audio filename prefix (FUN_004c9840) |
| DAT_005d369c | SkidString | setup | char* | offset | 1 | "Skid" string constant — skid sound filename prefix |
| DAT_005d3594 | EmapString | setup | char* | offset | 1 | "Emap" string constant — environment map suffix |
| DAT_005d34bc | SingleSidedString | setup | char* | offset | 1 | "SingleSided" string constant — single-sided render flag |
| DAT_005acea0 | ParticleGravityScale | renderer | float | read | 1 | Particle gravity scale factor — used in particle physics (FUN_004cb120) |
| DAT_005d38a4 | SparksString | setup | char* | offset | 1 | "Sparks" string constant — sparks particle effect name |
| DAT_005d39b4 | EnteredSpecialString | setup | char* | offset | 1 | "EnteredSpecial" INI key string — entered special mode config key |
| DAT_005d3aec | GridgirlbMtsString | setup | char* | offset | 1 | "gridgirlb.mts" filename — grid girl material/shader filename |
| DAT_005d3bd8 | FalseString | setup | char* | offset | 1 | "False" string constant — boolean false display string |
| DAT_005d40dc | RacemodeDString | setup | char* | offset | 1 | "Racemode" format/display string — race mode display label |
| DAT_005d3eec | DriveaidsAllowedString | setup | char* | offset | 1 | "DriveaidsAllowed" INI key string — driving aids allowance config key |
| DAT_005d3d50 | QualplaceDString | setup | char* | offset | 1 | "Qualplace" format string — qualifying position display label |
| DAT_005d41e4 | VehicleString | setup | char* | offset | 1 | "Vehicle" INI key string — vehicle selection/identifier key |
| DAT_005d4208 | HelicopterString | setup | char* | offset | 1 | "Helicopter" string constant — helicopter object/scene name |
| DAT_005d43ac | EnteredStewardString | setup | char* | offset | 1 | "EnteredSteward" debug string — steward entry log message |
| DAT_005c6f30 | SteeringString | setup | char* | offset | 1 | "Steering" INI key string — steering control config key |
| DAT_005d45b8 | SsFormatString | setup | char* | offset | 1 | "%s %s" format string — used in command line construction for CreateProcess (FUN_004d5885) |
| DAT_005d4824 | SpringBaseString | setup | char* | offset | 1 | "SpringBase" INI key string — suspension spring base config key |
| DAT_005d4728 | BrakingCurveString | setup | char* | offset | 1 | "BrakingCurve" INI key string — AI braking curve config key |
| DAT_005d4a64 | DisplayLineCount | UI | int | read | 1 | Display/UI line count — number of lines to display in on-screen text rendering (FUN_004d8130) |
| DAT_005acf64 | DisplayYSpacing | UI | float | read | 1 | Display Y spacing — Y position spacing constant for UI text output (FUN_004d9420) |
| DAT_005d4be0 | DDevString | setup | char* | offset | 1 | "D_DEV" debug identifier string — used for diagnostic/debug output (FUN_004dc770) |
| DAT_005d4c14 | RefuelerString | setup | char* | offset | 1 | "Refueler" string constant — refueler pit crew object name |
| DAT_005d4e04 | UnableToSetupString | setup | char* | offset | 1 | "Unable to setup" error string — device/subsystem setup failure message |
| DAT_005ad14c | RenderTargetWidth | renderer | float | read | 1 | Render target width constant — used in render target setup and resolution scaling (FUN_004dfce0) |
| DAT_007c74ac | VehicleVelocityVector | dynamics | double | read | 1 | Vehicle velocity vector component — double-precision velocity in vehicle movement/physics update (FUN_004e49b0) |
| DAT_005ad1dc | SuspensionDampingMult | dynamics | float | read | 1 | Suspension damping multiplier — scales suspension damping force in wheel/suspension physics (FUN_004ea970) |
| DAT_008afecc | TrackSurfaceFriction | physics/track | float | read | 1 | Track surface friction constant — used in tire/ground friction calculations (FUN_004f0430) |
| DAT_005d4fc0 | FrontWingRandomString | setup | char* | offset | 1 | "FrontWingRandom" INI key string — front wing random variance config key |
| DAT_005d52e0 | ReboundTravelString | setup | char* | offset | 1 | "ReboundTravel" INI key string — suspension rebound travel config key |
| DAT_005d5198 | PushrodBodyString | setup | char* | offset | 1 | "PushrodBody" INI key string — pushrod body type config key |
| DAT_005d504c | BrakeDiscRangeString | setup | char* | offset | 1 | "BrakeDiscRange" INI key string — brake disc range config key |
| DAT_005d54b4 | EngineBrakingMultString | setup | char* | offset | 1 | "EngineBrakingMult" INI key string — engine braking multiplier config key |
| DAT_005d55b8 | OnboardStarterString | setup | char* | offset | 1 | "OnboardStarter" INI key string — onboard starter config key |
| DAT_005d66e8 | FeelerFlagsString | setup | char* | offset | 1 | "FeelerFlags" INI key string — feeler flag config key |
| DAT_005d65bc | AiDownforceZARString | setup | char* | offset | 1 | "AIDownforceZAR" INI key string — AI downforce ZAR config key |
| DAT_005d6490 | Pitstop2RangeString | setup | char* | offset | 1 | "Pitstop2Range" INI key string — pitstop 2 range config key |
| DAT_005d63a0 | RightFenderString | setup | char* | offset | 1 | "RightFender" INI key string — right fender config key |
| DAT_005d62ac | BodyLeftString | setup | char* | offset | 1 | "BodyLeft" INI key string — left body config key |
| DAT_005d618c | DiffuserCenterString | setup | char* | offset | 1 | "DiffuserCenter" INI key string — diffuser center config key |
| DAT_005d6010 | Front3rdBumpstopString | setup | char* | offset | 1 | "Front3rdBumpstop" INI key string — front 3rd bumpstop config key |
| DAT_005d5e50 | LeftFenderFlareString | setup | char* | offset | 1 | "LeftFenderFlare" INI key string — left fender flare config key |
| DAT_005d5c94 | Front3rdSlowReturnString | setup | char* | offset | 1 | "Front3rdSlowReturn" INI key string — front 3rd slow return config key |
| DAT_005d5ab8 | TractionControlString | setup | char* | offset | 1 | "TractionControl" INI key string — traction control config key |
| DAT_005d5988 | ClutchFrictionString | setup | char* | offset | 1 | "ClutchFriction" INI key string — clutch friction config key |
| DAT_005d585b | Gear6SettingString | setup | char* | offset | 1 | "Gear6Setting" INI key string — gear 6 ratio config key |
| DAT_005d584e | Gear7SettingString | setup | char* | offset | 1 | "Gear7Setting" INI key string — gear 7 ratio config key |
| DAT_005d6cd8 | EngineRpmSoundString | setup | char* | offset | 1 | "EngineRPMSound" INI key string — engine RPM sound config key |
| DAT_005d6b3f | EngineSoundSubKey | setup | char* | offset | 1 | Engine sound sub-key string — RPM sound sub-range key |
| DAT_005d69a7 | EngineSoundSubKey2 | setup | char* | offset | 1 | Engine sound sub-key string (secondary) — RPM sound sub-range key |
| DAT_005d67fb | EngineSoundSubKey3 | setup | char* | offset | 1 | Engine sound sub-key string (tertiary) — RPM sound sub-range key |
| DAT_005d6e44 | AudioChannelCount | audio | int | read | 1 | Audio channel count — number of audio channels/sources (FUN_004f9480) |
| DAT_005d6e60 | AudioByteFlag | audio | byte | read | 1 | Audio byte flag — single-byte audio config flag (FUN_004fa000) |
| DAT_005d6f28 | SkyboxString | setup | char* | offset | 1 | "Skybox" INI key string — skybox texture config key |
| DAT_005ad2a8 | ParticleLifeScale | renderer | float | read | 1 | Particle lifetime scale factor — scales particle lifetime (FUN_004fcee0) |
| DAT_005ad304 | ParticleFadeOutSlope | renderer | float | read | 1 | Particle fade-out slope — controls fade-out rate in particle 4-segment opacity curve (FUN_004fde00) |
| DAT_005d6fcc | WarmString | setup | char* | offset | 1 | "Warm" INI key string — warm tire temperature label |
| DAT_005d70b0 | OffPathWetnessString | setup | char* | offset | 1 | "OffPathWetness" INI key string — off-path wetness config key |
| DAT_005d7150 | ConfigLookupTableEnd | setup | void* | read | 1 | Config lookup table end sentinel — end-of-table pointer for configuration attribute lookup (FUN_00500680) |
| DAT_005ba580 | DeviceIDTable | renderer | struct | offset | 1 | Device/interface ID table — COM interface ID table used in D3D/device creation (FUN_005054ec) |
| DAT_005adbfc | LightAttenuationConst | renderer | float | read | 1 | Light attenuation constant — used in 3D vertex lighting/normal computation (FUN_0050a92d) |
| DAT_005add0c | VertexPipeVTable | renderer | ptr | offset | 1 | Vertex pipeline vtable — virtual function table for vertex processing pipeline object |
| DAT_005ade2c | ShaderVTable | renderer | ptr | offset | 1 | Shader vtable — virtual function table for shader/pixel processing object |
| DAT_005d7868 | DrawPrimitiveFuncPtr | renderer | ptr | read | 1 | Draw primitive function pointer — indirect call target for D3D draw primitive operation (FUN_0050d93f) |
| DAT_005af210 | TextureByteData | renderer | byte | read | 1 | Texture byte data — single byte read in texture processing (FUN_005117c8) |
| DAT_005af3f0 | WidthTooLargeString | setup | char* | offset | 1 | "Width too large" error string — texture width exceeded limit error message |
| DAT_005af5e0 | TextureRowStartData | renderer | struct | offset | 1 | Texture row start data table — lookup table for texture row start positions (FUN_0051427f) |
| DAT_005afa90 | OutOfMemoryString | setup | char* | offset | 1 | "Out of memory" error string — memory allocation failure message |
| DAT_005afddc | MissingIHDRString | setup | char* | offset | 1 | "Missing IHDR" error string — PNG loader missing IHDR chunk error |
| DAT_005afad8 | PNGChunkTypeData | file | int | read | 1 | PNG chunk type data — 4-byte PNG chunk type identifier constant (FUN_00519019) |
| DAT_008d6014 | SSENormalizeScale | math/SIMD | float | read | 1 | SSE vector normalize scale parameter — used in Newton-Raphson reciprocal sqrt with NR refinement (FUN_0051ee7e) |
| DAT_005d8b80 | SSEConstantBias | math/SIMD | __m128 | read | 1 | SSE constant bias vector — used in double-to-SIMD conversion with Newton-Raphson reciprocal sqrt (FUN_0051fb1e) |
| DAT_008d6140 | SSEXorMask | math/SIMD | __m128 | read | 1 | SSE XOR mask — used in SIMD matrix/vector math for sign manipulation (FUN_0051febe) |
| DAT_008d6224 | SSENRConstant2 | math/SIMD | float | read | 1 | SSE Newton-Raphson refinement constant 2 — used in reciprocal sqrt approximation (FUN_00520a7e) |
| DAT_008d6284 | CrossProductScale4 | math/SIMD | float | read | 1 | Cross product scale factor — 4th scale factor in SIMD cross product / eigenvalue computation (FUN_00520ce0) |
| DAT_005d9000 | SSEDecodeBias | renderer/SIMD | __m128 | read | 1 | SSE decode bias vector — used in SIMD pixel/color component decoding (FUN_005289e0) |
| DAT_005d90a0 | SSERoundConstant | renderer/SIMD | __m128 | read | 1 | SSE rounding constant — used in SIMD pixel format conversion (FUN_00528bd0) |
| DAT_005d93a8 | SSECubicCoeffA | math/SIMD | int | read | 1 | SSE cubic/sqrt polynomial coefficient A — used in MMX/3DNow! approximation polynomial (FUN_00529000) |
| DAT_005b09f0 | UnknTextureData | renderer | struct | offset | 1 | Unknown texture data block — referenced in texture processing function (FUN_0052a4a5) |
| DAT_005b0bd8 | PixelBlendFactor | renderer | qword | read | 1 | Pixel blend factor — used in short-vector pixel blending operations (FUN_0052ab4e) |
| DAT_005b0c88 | PixelBlendFactor2 | renderer | qword | read | 1 | Pixel blend factor (secondary) — used in short-vector pixel operations (FUN_0052b561) |
| DAT_005b10a4 | DCTDecodeTable | renderer | float | read | 1 | DCT/quantization decode table — used in JPEG/DXT-like texture decode with quantization (FUN_00530050) |
| DAT_008b592c | ColorTransformChromaB | renderer | float | write | 1 | Color transform chroma B coefficient — written during color space matrix calculation (FUN_00531b50) |
| DAT_008b5980 | ColorTransformChromaR | renderer | float | write | 1 | Color transform chroma R coefficient — written during color space matrix calculation (FUN_00531b50) |
| DAT_005b7768 | YUVConvMatrixCoeff | renderer | float | read | 1 | YUV conversion matrix coefficient — used in RGB↔YUV color space conversion (FUN_00531b50, coefficient row 15) |
| DAT_005b7784 | YUVConvMatrixCoeff2 | renderer | float | read | 1 | YUV conversion matrix coefficient (row 17) — used in color space conversion pipeline |
| DAT_005b7798 | YUVConvMatrixCoeff3 | renderer | float | read | 1 | YUV conversion matrix coefficient (row 18) — used in color space conversion pipeline |
| DAT_005da838 | FontConfigTable | UI | void* | read | 1 | Font configuration table pointer — used in UI font setup (FUN_00535e80) |
| DAT_005b7d28 | FontGlyphData | UI | int | read | 1 | Font glyph metric data — glyph width/metrics lookup in text rendering (FUN_00539200) |
| DAT_008b6abc | MemPoolEndMarker | memory | struct | offset | 1 | Memory pool end boundary address — used as loop termination in memory pool zero-init (FUN_0053c360) |
| DAT_005dbe60 | AlreadyDeletedString | setup | char* | offset | 1 | "Already deleted" debug string — object double-deletion warning |
| DAT_005dc0bc | StringListData | setup | int | read | 1 | String list data — referenced in string list processing (FUN_00551a50) |
| DAT_005dc1a4 | ActorAlreadyExistsString | setup | char* | offset | 1 | "Actor already exists" error string — duplicate actor warning |
| DAT_005dc32c | ShadowReceiverString | setup | char* | offset | 1 | "ShadowReceiver" INI key string — shadow receiver config key |
| DAT_005dc3e4 | FogModeString | setup | char* | offset | 1 | "FogMode" INI key string — fog mode config key |
| DAT_005dc598 | SceneConfigDword | renderer | int | read | 1 | Scene configuration dword — render scene config parameter (FUN_0055f0d0) |
| DAT_005dc550 | SceneConfigDword2 | renderer | int | read | 1 | Scene configuration dword (secondary) — render scene config parameter |
| DAT_005dc4fc | SceneConfigWord | renderer | word | read | 1 | Scene configuration word — render scene config parameter |
| DAT_005dc498 | SceneConfigDword3 | renderer | int | read | 1 | Scene configuration dword (tertiary) — render scene config parameter |
| DAT_005ddccc | AlphaBlendSumTable | renderer | byte[4096] | write | 1 | Alpha blend sum table — precomputed 64x64 lookup: clamped (jj+kk) for alpha blending (FUN_00561b2a) |
| DAT_005e4f50 | StatusString | setup | char* | offset | 1 | "Status" INI key string — status/config key |
| DAT_005e50a8 | FFString | setup | char* | offset | 1 | "FF" string constant — force feedback short identifier |
| DAT_005e5214 | Com2String | setup | char* | offset | 1 | "COM2" string constant — serial port identifier |
| DAT_005e525c | ModelErrorTxtString | setup | char* | offset | 1 | "pmodel_error.txt" filename — model error log filename (FUN_0056d8f0) |
| DAT_005e528c | InvalidCopyBodyString | setup | char* | offset | 1 | "Invalid copy body" error string — 3D model copy error message |
| DAT_008d0d70 | DynamicsWorkMatrixA | dynamics | double[?] | read | 1 | Dynamics constraint solver matrix A — LDL^T factorization workspace (FUN_0056fa96, block sparse) |
| DAT_008d1140 | DynamicsWorkMatrixB | dynamics | double[?] | read | 1 | Dynamics constraint solver matrix B — LDL^T workspace block |
| DAT_008d0268 | DynamicsWorkDiagInv | dynamics | double[?] | read | 1 | Dynamics solver diagonal inverse — D^-1 in LDL^T factorization workspace |
| DAT_008d0348 | DynamicsWorkDiagBlock | dynamics | double[?] | read | 1 | Dynamics solver diagonal block — D matrix block in LDL^T workspace |
| DAT_008d01d0 | DynamicsWorkRHS | dynamics | double[?] | read | 1 | Dynamics solver right-hand side vector — LDL^T solve step workspace |
| DAT_008d14f0 | DynamicsWorkSolution | dynamics | double[?] | read | 1 | Dynamics solver solution vector — LDL^T solve result workspace |
| DAT_008d04e0 | DynamicsWorkScratch | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace — LDL^T intermediate computation |
| DAT_008d05b0 | DynamicsWorkScratch2 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 2 — LDL^T intermediate computation |
| DAT_008d0b58 | DynamicsWorkScratch3 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 3 — LDL^T intermediate computation |
| DAT_008d0770 | DynamicsWorkTemp | dynamics | double[?] | write | 1 | Dynamics solver temporary workspace — written during LDL^T factorization iterations |
| DAT_008d1a48 | DynamicsWorkTemp2 | dynamics | double[?] | read | 1 | Dynamics solver temporary workspace 2 — used in LDL^T solver |
| DAT_008d1f98 | DynamicsWorkTemp3 | dynamics | double[?] | read | 1 | Dynamics solver temporary workspace 3 — used in LDL^T solver |
| DAT_008d39dc | DynamicsWorkIndex | dynamics | int | offset | 1 | Dynamics solver index/offset — block index parameter in LDL^T factorization |
| DAT_008d1a68 | DynamicsWorkTemp4 | dynamics | double[?] | read | 1 | Dynamics solver temporary workspace 4 — used in LDL^T solver |
| DAT_008d10a0 | DynamicsWorkScratch4 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 4 — LDL^T intermediate computation |
| DAT_008d10a8 | DynamicsWorkScratch5 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 5 — LDL^T intermediate computation |
| DAT_008d11f0 | DynamicsWorkScratch6 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 6 — LDL^T intermediate computation |
| DAT_008d1320 | DynamicsWorkScratch7 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 7 — LDL^T intermediate computation |
| DAT_008d16a0 | DynamicsWorkScratch8 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 8 — LDL^T intermediate computation |
| DAT_008d1aa0 | DynamicsWorkScratch9 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 9 — LDL^T intermediate computation |
| DAT_008d1f10 | DynamicsWorkScratch10 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 10 — LDL^T intermediate computation |
| DAT_008d3b10 | DynamicsWorkScratch11 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 11 — LDL^T intermediate computation |
| DAT_008d1e50 | DynamicsWorkScratch12 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 12 — LDL^T intermediate computation |
| DAT_008d1d88 | DynamicsWorkScratch13 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 13 — LDL^T intermediate computation |
| DAT_008d1f48 | DynamicsWorkScratch14 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 14 — LDL^T intermediate computation |
| DAT_008d2110 | DynamicsWorkScratch15 | dynamics | double[?] | read | 1 | Dynamics solver scratch workspace 15 — LDL^T intermediate computation |
| DAT_008d2130 | SolverMatrixA | dynamics | double[?] | read | 1 | Cholesky/LDL^T solver matrix A — main system matrix in constraint solver (FUN_00575bbd, 13KB) |
| DAT_008d2630 | SolverMatrixDiag | dynamics | double[?] | write | 1 | Cholesky solver diagonal matrix — D matrix in LDL^T factorization (FUN_00575bbd) |
| DAT_008d2950 | SolverRHSVector | dynamics | double[?] | write | 1 | Cholesky solver RHS vector — right-hand side b in Ax=b solve (FUN_00575bbd) |
| DAT_008d2e50 | SolverSolutionVec | dynamics | double[?] | write | 1 | Cholesky solver solution vector — x in Ax=b (FUN_00575bbd) |
| DAT_008d3bd4 | SolverBlockIndex | dynamics | int | offset | 1 | Cholesky solver block index — block/row index parameter (FUN_00575bbd) |
| DAT_005bb498 | FileAccessMutex | file | struct | offset | 1 | File access mutex/struct — initialized in file I/O subsystem (FUN_00579ff0) |
| DAT_005e5424 | SsdFormatString | setup | char* | offset | 1 | "%s %d" format string — formatted output for debugging/status messages |
| DAT_005e6208 | SuccessfulWSAStartupString | setup | char* | offset | 1 | "A successful WSAStartup" debug string — Winsock startup success message |
| DAT_005e5a38 | DescriptorInvalidString | setup | char* | offset | 1 | "The descriptor is invalid" error string — network socket error message |
| DAT_005e62c8 | DuplicateConnectionString | setup | char* | offset | 1 | "Duplicate connection" debug string — duplicate network connection warning |
| DAT_005bae30 | ThreadDataStruct | runtime | struct | offset | 1 | Thread data structure — per-thread data allocation in thread init (FUN_00582780, stride 0x54) |
| DAT_005e6370 | UnknownAddressString | setup | char* | offset | 1 | "Unknown address" error string — network address resolution error |
| DAT_005e63b0 | CRTConvertConst | runtime/CRT | double | read | 1 | CRT conversion constant — used in floating-point rounding check (FUN_005883e5) |
| DAT_008d3e68 | SystemTimeCache | runtime | word[4] | read | 1 | System time cache — cached SYSTEMTIME fields (year, month, day, hour, minute) for timezone calculations (FUN_005896ee) |
| DAT_008d3e78 | OSVersionPacked | runtime | int | write | 1 | OS version packed integer — combined major*0x100+minor from GetVersion() (FUN_0058a19e) |
| DAT_005e6be0 | CRTInitFuncPtr | runtime | void* | read | 1 | CRT initialization function pointer — indirect call in CRT startup (FUN_0058d04d) |
| DAT_008d3f44 | CRTDllSwitch | runtime | int | read | 1 | CRT DLL/static switch flag — determines if CRT uses DLL or static linking (FUN_0058ef83) |
| DAT_005e69cc | CRTCodePageBuffer | runtime | undefined2* | write | 1 | CRT code page buffer — pointer to code page data in CRT locale init (FUN_0058f939) |
| DAT_005b94e0 | CRTFPUnderflowThreshold | runtime/CRT | double | read | 1 | CRT FP underflow threshold — used in floating-point exception handling / denormal detection (FUN_0059070a) |
| DAT_008d4020 | TimeZoneDaylightName | runtime | widechar[] | offset | 1 | Time zone daylight name buffer — wide char daylight time zone name (FUN_005921f3) |
| DAT_008d3e84 | CRTArgc | runtime | int | write | 1 | CRT argument count (argc) — stored from command line parsing (FUN_00592bad) |
| DAT_005e7960 | CRTOnexitFuncPtr | runtime | void* | read | 1 | CRT onexit/atexit function pointer — registered atexit handler target (FUN_00593cfd) |
| DAT_008d41f0 | CRTExceptionHandler | runtime | ptr | read | 1 | CRT exception handler function pointer — used in signal/exception dispatch (FUN_00597388) |
| DAT_005bb3d8 | CRTVFTableStruct | runtime | struct | offset | 1 | CRT virtual function table struct — C++ exception type_info vtable setup (FUN_00598bbc) |
| DAT_005bb738 | ExceptionVFTable | runtime | struct | offset | 1 | Exception vtable struct — C++ exception vtable reference in destructor (FUN_0059a7de) |
| DAT_005b9db8 | TypeInfoVFTable | runtime | ptr | offset | 1 | Type info vtable — C++ type_info::vftable pointer stored in RTTI struct (FUN_0059baa3) |
