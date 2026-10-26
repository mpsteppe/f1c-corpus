=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be400 | IncompleteWaypointString | setup | char* | offset | 1 | "Incomplete Waypoint" string constant — used in waypoint validation error message |
| DAT_005be5c4 | MidAdjustString | setup | char* | offset | 1 | "MidAdjust" string constant — configuration key for waypoint mid-point adjustment |
| DAT_005be4f0 | RainyFogColorString | setup | char* | offset | 1 | "RainyFogColor" string constant — configuration key for rain/fog color setting |
| DAT_005be444 | WpPtrsString | setup | char* | offset | 1 | "WpPtrs" string constant — configuration key for waypoint pointer array |
| DAT_007cfe70 | ReconScreenFlag | UI | byte | read | 1 | Gate flag for recon/screen display; when non-zero, triggers screen rendering in FUN_00409a00 case 1 |
| DAT_005beab0 | CameraReleaseCamString | setup | char* | offset | 1 | "CameraReleaseCam" string constant — camera configuration key |
| DAT_005be9bc | WeatherString | setup | char* | offset | 1 | "Weather" string constant — configuration key for weather settings |
| DAT_0059e768 | SessionManagerVTable | runtime | ptr | offset | 1 | VTable pointer for session manager object — used in FUN_0040fe50 object construction |
| DAT_005c23a8 | FbString | setup | char* | offset | 1 | "Fb" string constant — short key name in config parsing |
| DAT_005c2584 | RalfSString | setup | char* | offset | 1 | "Ralf S" driver name string constant — driver name reference |
| DAT_005c24b4 | AllanMString | setup | char* | offset | 1 | "Allan M" driver name string constant — driver name reference |
| DAT_0059e81c | LeadInPositionThreshold | physics | double | read | 1 | Position threshold for lead-in timing; compared against cumulative time offset in FUN_0041a500 for race timing intervals |
| DAT_005c28b0 | Year2000McLarenString | setup | char* | offset | 1 | "2000 McLaren" season/team string constant |
| DAT_005c27a0 | Year2002JordanString | setup | char* | offset | 1 | "2002 Jordan" season/team string constant |
| DAT_005c2a08 | DriversString | setup | char* | offset | 1 | "Drivers" string constant — INI section key for driver data |
| DAT_005c2c58 | MovieDirString | setup | char* | offset | 1 | "MovieDir" string constant — configuration key for movie directory path |
| DAT_005c2b54 | RunBenchmarksString | setup | char* | offset | 1 | "RunBenchmarks" string constant — configuration key for benchmark mode flag |
| DAT_005c2fc4 | OptionsFlagsString | setup | char* | offset | 1 | "OptionsFlags" string constant — configuration key for option bitmask flags |
| DAT_005c2e7c | VideoModeString | setup | char* | offset | 1 | "VideoMode" string constant — configuration key for video mode settings |
| DAT_005c3044 | StartupCheckFlag | setup | byte | read | 1 | Startup configuration check flag; read during option initialization in FUN_004230c0 |
| DAT_007d017c | ConfigFloatValue | setup | float | read | 1 | Configuration float value read during game setup — passed to FUN_00424080 |
| DAT_0059e964 | EngineWearAccumScale | physics/engine | double | read | 1 | Scale factor for engine wear accumulation in FUN_004270a0; scales wear contribution per lap/phase |
| DAT_005c32b0 | UpshiftsString | setup | char* | offset | 1 | "Upshifts" string constant — configuration key for auto-upshift setting |
| DAT_005c33bc | PitLaneAssistString | setup | char* | offset | 1 | "PitLaneAssist" string constant — configuration key for pit lane assistance |
| DAT_007c9358 | SimulationAccumBlock | physics | int[12] | write | 1 | Part of 12-int block (DAT_007c932c-9358) zeroed in simulation tick loop; per-vehicle simulation accumulator state |
| DAT_005c35e8 | NoSceneFilesFoundString | setup | char* | offset | 1 | "No Scene Files Found" error string constant — scene loading error message |
| DAT_0059e9f8 | SceneLoadTimeout | setup | double | read | 1 | Timeout threshold for scene file loading; compared against elapsed time in FUN_0042e530 |
| DAT_005c3ea0 | CgRightSettingString | setup | char* | offset | 1 | "CgRight" INI key string — CG right setting in vehicle setup (HDV) |
| DAT_005c3d24 | FrontAntiSwayString | setup | char* | offset | 1 | "FrontAntiSway" INI key string — front anti-sway bar setting |
| DAT_005c3b0c | ControlsString | setup | char* | offset | 1 | "Controls" INI section string — controls configuration section |
| DAT_005c3968 | RearRightString | setup | char* | offset | 1 | "RearRight" INI key string — rear right setting in vehicle setup |
| DAT_0059ea48 | SteeringResponseSpeedScale | physics | double | read | 1 | Speed-dependent steering response scale factor in FUN_00430750; scales steering torque based on vehicle speed and suspension geometry |
| DAT_005c3fa4 | VehiclePartVTable | runtime | ptr | read | 1 | VTable pointer for vehicle part object — used in part construction FUN_004326a0 |
| DAT_005c4108 | MinoriString | setup | char* | offset | 1 | "Minori" string constant — driver/minor character name reference |
| DAT_0059eb70 | TireSlipForceMult | physics/tire | double | read | 1 | Tire slip force multiplier in FUN_00438130; scales lateral force from slip angle with speed and load dependency |
| DAT_0059ebe8 | ContactStiffnessScale | physics/collision | double | read | 1 | Contact stiffness scale factor used in FUN_00439210 for collision response computation |
| DAT_007c9310 | EngineFailureThreshold | physics/engine | double | read | 1 | Engine failure threshold used in FUN_0043c250; compared against cumulative damage/wear to trigger engine failure state |
| DAT_0059ed30 | MinVelocityThreshold | physics | double | read | 1 | Minimum velocity floor threshold in FUN_00441650; when velocity below this, clamped to 3.814697e-06 to prevent division-by-zero in integration |
| DAT_007ce8ec | SuspensionDamperRate | physics/suspension | float | read | 1 | Suspension damper rate factor in FUN_004441f0; scales damping force for suspension integration |
| DAT_0059ee30 | TireWearAccumFactor | physics/tire | double | read | 1 | Tire wear accumulation factor in FUN_004441f0; scales tire wear rate per unit slip |
| DAT_0059eed8 | SlipForceGainFactor | physics/tire | double | read | 1 | Slip force gain factor in FUN_004472b0; scales lateral force output from normalized slip ratio |
| DAT_0059ef50 | SineLUTPhaseScale | math_util | double | read | 1 | Phase scale factor for 8-entry sine lookup table initialization in FUN_0044c430; multiplied by loop index for sine LUT values |
| DAT_007ca504 | AudioMixerInitFloat | audio | float | write | 1 | Audio mixer init float (1.0f) in FUN_0044d220; part of audio state block (DAT_007ca4f8-504) |
| DAT_007ccce4 | AudioState2Block | audio | int | write | 1 | Part of audio state block (DAT_007cccd8-cec) zeroed in FUN_0044d4c0; audio mixer initialization group |
| DAT_007d2070 | RenderStateStackDepth | renderer | int | read | 1 | Render state stack depth/selector in FUN_0044ff50; selects render state storage block (DAT_007ca3b8, 007cc9bc, etc.) |
| DAT_005ad38c | RenderStateArray2 | renderer | int[] | read | 1 | Render state storage array accessed in FUN_0044ff50; used as comparison for render state slot matching |
| DAT_005ad398 | RenderStateArray3 | renderer | int[] | read | 1 | Additional render state storage array in FUN_0044ff50; paired with DAT_005ad38c for render state management |
| DAT_007d20b0 | VehicleEffectParam | renderer/vehicle | float | read | 1 | Vehicle effect parameter in FUN_00451720; controls visual effect intensity/scale |
| DAT_007cd064 | CollisionObjectMapping | collision | int | read | 1 | Collision object type mapping; used in FUN_00452b10 to match object types to collision parameter blocks |
| DAT_007cd0c0 | CollisionMaterialConfig | collision | float | write | 1 | Collision material property values (friction/restitution) copied from vehicle struct offsets +0x1140-115c in FUN_004537b0; written to paired global pairs |
| DAT_007ccfd4 | CollisionMaterialPairB | collision | float | write | 1 | Second set of collision material properties; paired with DAT_007cd19c etc. for per-material response parameters |
| DAT_005c5644 | ShiftDownString | setup | char* | offset | 1 | "ShiftDown" string constant — control binding key for downshift |
| DAT_005c552c | LookLeftString | setup | char* | offset | 1 | "LookLeft" string constant — control binding key for look-left camera |
| DAT_007ccbc0 | KeyboardCharBuffer | input | ushort | write | 1 | Keyboard character buffer; written from ToAsciiEx/MapVirtualKey result in FUN_00455b30; stores translated virtual key code |
| DAT_005c5840 | PositionOffsetString | setup | char* | offset | 1 | "PositionOffset" string constant — configuration key for position offset |
| DAT_0059f050 | MathTransformConstant | math_util | double | read | 1 | Math transform constant used in FUN_00459ae0; part of coordinate transform or rotation computation |
| DAT_005c5bd4 | GameNameString | setup | char* | offset | 1 | "GameName" string constant — INI section key for game name |
| DAT_005c5d18 | MismatchString | setup | char* | offset | 1 | "Mismatch" string constant — version/file mismatch error key |
| DAT_007d0f04 | NetCommStateFlag | network | int | read | 1 | Network communication state flag in FUN_0045f710; checked during session message processing |
| DAT_005c612c | OpenedString | setup | char* | offset | 1 | "Opened" string constant — file/session opened status key |
| DAT_007d0854 | WeatherModeConfig | weather | float | read | 1 | Weather mode configuration float in FUN_00461900; passed to FUN_004646c0 as weather parameter pair |
| DAT_007cec38 | PitWindowTimerConfig | pit | float | read | 1 | Pit window timer configuration value in FUN_00461900; used as pit open/close window timing parameter |
| DAT_005c6310 | LocalString | setup | char* | offset | 1 | "Local" string constant — network/local game mode key |
| DAT_005c65c8 | JoiningSessionString | setup | char* | offset | 1 | "Joining Session" string constant — network join status message |
| DAT_005c6634 | EnteringSyncString | setup | char* | offset | 1 | "Entering Synchronization" string constant — sync phase message |
| DAT_005c665c | SessionDispatchVTable | runtime | ptr | read | 1 | VTable pointer for session dispatch object — used in FUN_0046a2a0 |
| DAT_005c6a8c | Format62fString | setup | char* | offset | 1 | "%6.2f" format string — float formatting with 6 width 2 precision |
| DAT_005c6e1c | FormatSSSSIIString | setup | char* | offset | 1 | Format string with 4 string + 2 int placeholders — used in debug/log output |
| DAT_005c71a4 | CoordinateString | setup | char* | offset | 1 | "Coordinate" string constant — coordinate system key |
| DAT_005c7320 | PlayString | setup | char* | offset | 1 | "Play" string constant — play mode/action key |
| DAT_005c74a0 | CircuitNameString | setup | char* | offset | 1 | "CircuitName" string constant — circuit name INI key |
| DAT_005ac110 | TrackMapScrollSpeed | UI | float | read | 1 | Track map scroll speed/step in FUN_0048cb00; controls position advance per tick in track map scrolling |
| DAT_005cc658 | UndefinedLayerString | renderer | char* | offset | 1 | "Undefined Layer" string constant — render layer error message |
| DAT_005cc7e4 | SoundReleaseString | audio | char* | offset | 1 | "SoundRelease" string constant — audio release event/debug key |
| DAT_005cc81c | SimulateClickString | UI | char* | offset | 1 | "SimulateClick" string constant — UI click simulation debug key |
| DAT_005cc9c0 | EasBikString | renderer | char* | offset | 1 | ".EAS/.BIK" extension string — Bink/EAS video format extension |
| DAT_007cb278 | FontRendererConfig | UI | float | read | 1 | Font renderer configuration float; assigned to widget field at +0x70 in FUN_00498740 |
| DAT_005ec354 | DriverPresentFlag | game | byte | read | 1 | Driver presence flag array indexed by team/driver ID; set to 1 when driver is present in session in FUN_0049b9a0 |
| DAT_005ccb78 | DebugCallbackVTable | runtime | ptr | read | 1 | Debug/assert callback vtable pointer — used in FUN_0049ca00 |
| DAT_005ccebc | MemPoolInitData | memory | int | read | 1 | Memory pool initialization data constant — used in pool setup FUN_0049cd80 |
| DAT_008ad384 | SessionInitCompleteFlag | session | byte | write | 1 | Session init complete flag; set to param_2==1 in FUN_0049f150; gates session state transitions |
| DAT_005cd034 | SkipOptionsString | setup | char* | offset | 1 | "SkipOptions" string constant — command-line arg to skip options screen |
| DAT_007ce2b0 | SessionCatchupTimer | session | float | offset | 1 | Session timing value used in FUN_004a1200; controls catchup/sync timing |
| DAT_005cd2ec | LollipopDownString | setup | char* | offset | 1 | "LollipopDown" string constant — pit lollipop animation key |
| DAT_005cd474 | FuelRigMtsString | setup | char* | offset | 1 | "FuelRig.MTS" string constant — fuel rig animation model file |
| DAT_005cd36c | RotateString | setup | char* | offset | 1 | "Rotate" string constant — rotation animation key |
| DAT_005cd524 | SoftCompoundString | setup | char* | offset | 1 | "SoftCompound" string constant — tire compound name key |
| DAT_005cd644 | RepairString | setup | char* | offset | 1 | "Repair" string constant — repair action/menu key |
| DAT_005acc08 | PlayerVehicleVTable | runtime | ptr | offset | 1 | VTable pointer for player vehicle object; assigned in FUN_004a8b10 constructor with &PTR_LAB_005acc08 |
| DAT_005d1ed8 | BrakeHelpString | setup | char* | offset | 1 | "BrakeHelp" — INI key for brake assistance setting |
| DAT_005d1bf0 | HowLongAfterString | setup | char* | offset | 1 | "HowLongAfter" — INI key for timing parameter after event |
| DAT_005d1990 | RunPractice1String | setup | char* | offset | 1 | "RunPractice1" — INI key for first practice session |
| DAT_005d1720 | RandomSeasonString | setup | char* | offset | 1 | "RandomSeason" — INI key for random season flag |
| DAT_005d1520 | AdditionalVolumeString | setup | char* | offset | 1 | "AdditionalVolume" — INI key for audio volume setting |
| DAT_005d1348 | PitHornRangeString | setup | char* | offset | 1 | "PitHornRange" — INI key for pit horn audible range |
| DAT_005d11ac | LcdDisplayModeString | setup | char* | offset | 1 | "LcdDisplayMode" — INI key for LCD display mode |
| DAT_005d0f28 | VehicleFlowRadString | setup | char* | offset | 1 | "VehicleFlowRad" — INI key for vehicle flow (radiator) setting |
| DAT_005d0c64 | LookRollAngleString | setup | char* | offset | 1 | "LookRollAngle" — INI key for camera roll angle |
| DAT_005d09c8 | ShadowsInTVCockString | setup | char* | offset | 1 | "ShadowsInTVCock" — INI key for shadow in cockpit view |
| DAT_005d077c | AlwaysRebuildHString | setup | char* | offset | 1 | "AlwaysRebuildH" — INI key for HUD rebuild flag |
| DAT_005d0548 | DamageDynamicsString | setup | char* | offset | 1 | "DamageDynamics" — INI key for damage dynamics flag |
| DAT_005d0274 | PlayMoviesString | setup | char* | offset | 1 | "PlayMovies" — INI key for movie playback flag |
| DAT_005cffe0 | InGarageOptionsString | setup | char* | offset | 1 | "InGarageOptions" — INI key for in-garage options |
| DAT_005cfd30 | UsedForAssigningString | setup | char* | offset | 1 | "UsedForAssigning" — INI description text for control assignment |
| DAT_005cf950 | HowLongToWaitWString | setup | char* | offset | 1 | "HowLongToWaitW" — INI key for wait time parameter |
| DAT_005cf5f4 | ThrottlingString | setup | char* | offset | 1 | "Throttling" — INI key for throttle assist setting |
| DAT_005cf1b4 | DampingMultiplString | setup | char* | offset | 1 | "DampingMultiplier" — INI key for controller damping |
| DAT_005ceed8 | AlternateRearlString | setup | char* | offset | 1 | "AlternateRear" — INI key for alternate rear view |
| DAT_005ceb9c | Controller2RyString | setup | char* | offset | 1 | "Controller2Ry" — INI key for controller 2 ry axis |
| DAT_005ce9b0 | ControlSecondGString | setup | char* | offset | 1 | "ControlSecondG" — INI key for second gear control |
| DAT_005ce7d8 | ControlRearLookString | setup | char* | offset | 1 | "ControlRearLook" — INI key for rear look control |
| DAT_005ce590 | FfbGainString | setup | char* | offset | 1 | "FfbGain" — INI key for force feedback gain |
| DAT_005ce0b4 | FfbSteerForceOString | setup | char* | offset | 1 | "FfbSteerForceO" — INI key for FF steer force offset |
| DAT_005cdc48 | AmountOfChangeString | setup | char* | offset | 1 | "AmountOfChange" — INI key for change magnitude |
| DAT_005cd840 | HowStrongJoltsString | setup | char* | offset | 1 | "HowStrongJolts" — INI key for jolt strength |
| DAT_005d238c | EnteredPlayerfString | setup | char* | offset | 1 | "EnteredPlayerf" string constant — player entry format |
| DAT_008afedc | NetSessionPacketData | network | float | write | 1 | Network session packet data field; written in FUN_004b3400 network message dispatch for packet type 6 |
| DAT_005acd50 | SuspensionBumpStopScale | physics/suspension | float | read | 1 | Suspension bump stop scale factor in FUN_004b66e0; used in bump stop contact force computation for case 3 |
| DAT_005d2520 | InCarVTRendererVTable | renderer | ptr | read | 1 | VTable pointer for in-car/VR renderer — used in FUN_004ba460 |
| DAT_005acda0 | WheelContactForceThreshold | dynamics | double | read | 1 | Wheel contact force threshold in FUN_004bccc0; gates wheel-terrain contact force integration |
| DAT_005acdd8 | CrashDetectionThreshold | physics/collision | float | read | 1 | Crash/impact detection threshold in FUN_004bec55; compared against collision velocity to trigger crash effects |
| DAT_005d26bc | PolesTakenString | setup | char* | offset | 1 | "PolesTaken" — INI key for pole position count |
| DAT_005d28a0 | SeasonStatusString | setup | char* | offset | 1 | "SeasonStatus" — INI key for season status display |
| DAT_005d2dc0 | AvgStartPositionString | setup | char* | offset | 1 | "AvgStartPosition" — INI key for average start position |
| DAT_005d2b5c | TrackfileString | setup | char* | offset | 1 | "Trackfile" — INI key for track file name |
| DAT_005d2f7c | TeamFoundedString | setup | char* | offset | 1 | "TeamFounded" — INI key for team founding year |
| DAT_005d31b0 | ScnString | setup | char* | offset | 1 | ".scn" file extension string — scene file extension |
| DAT_005d336c | PitPitsoundsMpString | setup | char* | offset | 1 | "Pit/Pitsounds.mp" string — pit audio file path |
| DAT_005ace24 | RenderDevicePtr | renderer | int | read | 1 | Render device pointer; dereferenced in FUN_004c99d0 for method dispatch (GetTransform) |
| DAT_005d3660 | ParticleString | renderer | char* | offset | 1 | "Particle" string constant — particle system INI key |
| DAT_005d354c | SpecularString | renderer | char* | offset | 1 | "Specular" string constant — specular rendering INI key |
| DAT_005d3760 | SrcColorString | renderer | char* | offset | 1 | "SrcColor" string constant — source color blend mode key |
| DAT_005ece1c | SceneDataBlockPtr | data | ptr | offset | 1 | Scene data block struct — used in FUN_004cc1d0 for scene/particle management |
| DAT_005d3870 | GravelString | setup | char* | offset | 1 | "Gravel" string constant — surface type key |
| DAT_005d3954 | AiDryGripString | setup | char* | offset | 1 | "AiDryGrip" string constant — AI dry grip setting |
| DAT_005d3aac | GgirlsignMtsString | setup | char* | offset | 1 | "Ggirlsign.MTS" string — pit girl sign animation file |
| DAT_005d3bf8 | LogoSBmpString | setup | char* | offset | 1 | "Logo?.bmp" format string — logo bitmap file name |
| DAT_005d407c | RaceLength3fString | setup | char* | offset | 1 | "RaceLength" format string — race length/format specifier |
| DAT_005d3e44 | DriveaidsSpeedString | setup | char* | offset | 1 | "DriveaidsSpeed" INI key — drive aids speed threshold |
| DAT_005d3cd4 | RacebestlapDString | setup | char* | offset | 1 | "RaceBestLap" format string — best lap time format |
| DAT_005d42d8 | Ptglow02String | setup | char* | offset | 1 | "ptglow02" string constant — glow texture name |
| DAT_005d4368 | HUDVisibilityFlag | UI | byte | read | 1 | HUD/UI element visibility flag; read in FUN_004d3cf0 for UI element visibility checks |
| DAT_005d45a4 | ElapsedTimeString | setup | char* | offset | 1 | "ElapsedTime" format string — elapsed time display format |
| DAT_005d44b0 | WheelspinRadsString | setup | char* | offset | 1 | "WheelspinRads" format string — wheel speed display format |
| DAT_005d4700 | DataString | setup | char* | offset | 1 | "Data" string constant — data section/file key |
| DAT_005d47e0 | CamberLatLongString | setup | char* | offset | 1 | "CamberLatLong" INI key — camber lateral/longitudinal setting |
| DAT_005d48e0 | BadSyntaxString | setup | char* | offset | 1 | "Bad syntax in file" error string constant |
| DAT_005d4a98 | HudOffString | setup | char* | offset | 1 | "HudOff" string constant — HUD toggle key |
| DAT_005d4b74 | Format3fString | setup | char* | offset | 1 | "%3f" format string — float formatting specifier |
| DAT_005d4ca4 | DriverString | setup | char* | offset | 1 | "Driver" string constant — driver name/section key |
| DAT_005c67dc | IdString | setup | char* | offset | 1 | "Id" string constant — identifier key |
| DAT_005d4da8 | RrspindleString | setup | char* | offset | 1 | "Rrspindle" INI key — rear-right spindle geometry |
| DAT_005d4d08 | TireString | setup | char* | offset | 1 | "Tire" string constant — tire section key |
| DAT_007c8a2c | VehiclePhysicsState | dynamics | double | read | 1 | Vehicle physics state double in FUN_004e5f60; part of per-vehicle dynamics integration workspace |
| DAT_008ad404 | VehicleSetupBlock | setup/vehicle | byte | offset | 1 | Vehicle setup data block accessed in FUN_004eb430; configuration copied during vehicle initialization |
| DAT_005ad240 | VehicleSimTickScale | dynamics | double | read | 1 | Simulation tick scaling factor in FUN_004f1510; scales per-vehicle throttle/brake values by frame time ratio |
| DAT_005d4f58 | RearwingposString | setup | char* | offset | 1 | "Rearwingpos" INI key — rear wing position setting |
| DAT_005d5274 | Reboundstage2String | setup | char* | offset | 1 | "ReboundStage2" INI key — rebound stage 2 damping |
| DAT_005d5138 | RideheightrangeString | setup | char* | offset | 1 | "Rideheightrange" INI key — ride height range setting |
| DAT_005d5324 | FendersidewaysString | setup | char* | offset | 1 | "Fendersideways" INI key — fender lateral offset |
| DAT_005d56d4 | BadEngineIdleString | setup | char* | offset | 1 | "BadEngineIdle" INI key — engine idle RPM setting |
| DAT_005d554c | OilwaterheattrString | setup | char* | offset | 1 | "Oilwaterheattr" INI key — oil/water heat transfer rate |
| DAT_005d66a0 | FlundertrayString | setup | char* | offset | 1 | "Flundertray" INI key — floor/undertray geometry setting |
| DAT_005d656c | CgrightsettingString | setup | char* | offset | 1 | "Cgrightsetting" INI key — CG right setting |
| DAT_005d6438 | FwmaxheightString | setup | char* | offset | 1 | "Fwmaxheight" INI key — front wing max height |
| DAT_005d6354 | RwrightString | setup | char* | offset | 1 | "Rwright" INI key — rear wing right setting |
| DAT_005d6270 | BodyrotString | setup | char* | offset | 1 | "Bodyrot" INI key — body rotation setting |
| DAT_005d6130 | AlignwheelsString | setup | char* | offset | 1 | "Alignwheels" INI key — wheel alignment setting |
| DAT_005d5f80 | Rear3rdbumpstopsString | setup | char* | offset | 1 | "Rear3rdBumpstop" INI key — rear third spring bump stop |
| DAT_005d5dd0 | RightcastersetString | setup | char* | offset | 1 | "Rightcaster" INI key — right caster angle setting |
| DAT_005d5bfc | Rear3rdspringsString | setup | char* | offset | 1 | "Rear3rdspring" INI key — rear third spring setting |
| DAT_005d5a60 | RearbrakesettingString | setup | char* | offset | 1 | "Rearbrakesetting" INI key — rear brake setting |
| DAT_005d5924 | DownshiftdelayString | setup | char* | offset | 1 | "Downshiftdelay" INI key — downshift delay setting |
| DAT_005d57e8 | DiffpowerrangeString | setup | char* | offset | 1 | "Diffpowerrange" INI key — differential power range |
| DAT_005d67d4 | NaturalrpmString | setup | char* | offset | 1 | "Naturalrpm" INI key — natural engine RPM |
| DAT_005d6c18 | NonPlayerengineString | setup | char* | offset | 1 | "NonPlayerengine" INI key — AI/non-player engine params |
| DAT_005d6abb | NonPlayerTuningByteArray | setup | byte[] | offset | 1 | Non-player engine tuning bytes — part of vehicle configuration block |
| DAT_005d6933 | NonPlayerTuningByte | setup | byte | offset | 1 | Non-player engine tuning byte — part of vehicle configuration |
| DAT_005d6d3c | VfxcloseString | setup | char* | offset | 1 | "Vfxclose" string constant — visual effect close key |
| DAT_005d6e30 | RenderStateConfigBlock | renderer | int | read | 1 | Render state configuration value read in FUN_004f9480 |
| DAT_007cf65c | ShadowMapConfigValue | renderer | int | read | 1 | Shadow map configuration value in FUN_004fa320; controls shadow rendering |
| DAT_007cf938 | RenderClearFlag | renderer | byte | read | 1 | Render clear/skip flag in FUN_004fbd70; when set, skips viewport clear during render frame |
| DAT_005ad294 | ViewportTransformConstant | renderer | float | read | 1 | Viewport transformation constant used in FUN_004fcee0 for projection |
| DAT_005ad324 | CameraDistanceScale | renderer | float | read | 1 | Camera distance scale factor in FUN_004fe0d0; scales camera position/orbit distance |
| DAT_005d7028 | ConditionsString | setup | char* | offset | 1 | "Conditions" INI key — weather/conditions section |
| DAT_005d7044 | AmbienttempString | setup | char* | offset | 1 | "AmbientTemp" INI key — ambient temperature setting |
| DAT_005adb30 | DebugsetmuteString | audio | char* | offset | 1 | "DebugSetMute" — audio debug/mute command string |
| DAT_005ba604 | RendererTextureVTable | renderer | ptr | offset | 1 | VTable pointer for renderer texture object; assigned in FUN_00506fd9 constructor with &PTR_FUN_005adb90 |
| DAT_005adc3c | TextureColorScale | renderer | float | read | 1 | Texture color channel scale factor in FUN_0050ab51; multiplies decoded color components during texture decompression |
| DAT_005add6c | RenderTargetVTable | renderer | ptr | offset | 1 | VTable pointer for render target object; assigned in FUN_0050b42a with &PTR_FUN_005add6c |
| DAT_005d788c | RendererDispatchPtr | renderer | ptr | read | 1 | Renderer indirect function pointer; called with 6 params in FUN_0050c2b9 after FUN_0050fea7(1) |
| DAT_005d78a8 | RenderJumpTablePtr | renderer | ptr | read | 1 | Renderer jumptable/callback pointer; called indirectly via (*_DAT_005d78a8)() in FUN_0050e0d3 |
| DAT_005af378 | NotAPngFileString | renderer | char* | offset | 1 | "Not a PNG file" error string — PNG loader error message |
| DAT_005af450 | PngDoDitherRetString | renderer | char* | offset | 1 | "PngDoDitherRet" string — PNG dither debug string |
| DAT_005d79d4 | TextureProcConstant | renderer | float | read | 1 | Texture processing constant in FUN_005147ea; used in pixel/texel processing pipeline |
| DAT_005afc30 | InvalidImageSizeString | renderer | char* | offset | 1 | "Invalid image size" error string — image loading error |
| DAT_005afe58 | IncorrectSrgbString | renderer | char* | offset | 1 | "Incorrect sRGB" error string — sRGB profile mismatch |
| DAT_005b03a0 | VQDecodeTableEntry | renderer/VQ | int | read | 1 | VQ (Vector Quantization) decode table entry used in FUN_0051a9c6 for compressed texture decompression |
| DAT_005d8ae0 | SIMDVectorHalfConst | math_util | xmmword | read | 1 | SIMD vector constant (0.5f in each lane) used in Newton-Raphson reciprocal sqrt refinement in FUN_0051f89e: `0.5 - (x * rsqrte * rsqrte) * 0.5` |
| DAT_008d60e0 | SIMDQuatXorMask1 | math_util | xmmword | read | 1 | SIMD XOR mask for quaternion cross-product in FUN_0051fbf0; used in _mm_xor_ps for sign flipping in 4-component cross product |
| DAT_008d6190 | SIMDLengthThreshold | math_util | float | read | 1 | Vector length threshold in FUN_0052042e; if squared length < threshold, result zeroed; else = reciprocal sqrt with Newton-Raphson refinement |
| DAT_005d8d00 | SIMDCRCPolyEvalCoeff | math_util | float | read | 1 | SIMD polynomial evaluation coefficient in FUN_00520c0e; used in rsqrt Newton-Raphson `3/2 - x/2 * rsqrte^2` computation |
| DAT_005b06e0 | AABBTreeSplitData | collision | qword | read | 1 | AABB tree splitting/partition data in FUN_005219e1; used in SAH (Surface Area Heuristic) partitioning for BVH construction |
| DAT_005d8f60 | ColorTransformCoeff4 | renderer | xmmword | read | 1 | Fourth set of color transform coefficients in FUN_005289e0; part of 4x4 color matrix for pixel format conversion |
| DAT_005d9220 | ColorTransformCoeffB | renderer | xmmword | read | 1 | Coefficient group B in FUN_00528cc0 color space conversion; subtractive delta correction for color channel decoding |
| DAT_005d9364 | EmptyFunctionPtr | runtime | int | read | 1 | Function pointer or sentinel; FUN_00529200 at this address is an empty stub function (retn) |
| DAT_005b0ab4 | IncompleteLitteralString | renderer | char* | offset | 1 | "Incomplete Litteral" error string — texture/literal parsing error |
| DAT_005b0c10 | SIMDPackedMultiplyConst | math_util | qword | read | 1 | SIMD packed floating-point multiplier constant in FUN_0052ab4e; used in packed 4-float multiply-accumulate operations |
| DAT_005da5fc | CMpegFilePlayerHeaderString | media | char* | offset | 1 | "CMpegFilePlayer::DecodeHeader" debug string — MPEG decode header trace |
| DAT_005b47d0 | VLCBitstreamTable | media | int | read | 1 | VLC (Variable Length Coding) bitstream decoding table in FUN_00531250; used for MPEG/audio stream huffman decoding |
| DAT_008b5934 | DCTDifferenceCoeff | media/audio | float | write | 1 | DCT difference coefficient in FUN_00531b50; scalar for 32-element DCT inverse transform difference kernel |
| DAT_008b5978 | DCTDiffCoeff2 | media/audio | float | write | 1 | Second DCT difference coefficient in FUN_00531b50; part of 16-pair difference butterfly |
| DAT_008b59dc | DCTDiffCoeff3 | media/audio | float | write | 1 | Third DCT difference coefficient in FUN_00531b50; used in inverse DCT butterfly structure |
| DAT_008b5a1c | DCTDiffCoeff4 | media/audio | float | write | 1 | Fourth DCT difference coefficient in FUN_00531b50; completes 16-element DCT difference pair array |
| DAT_008b59fc | DCTDiffCoeff5 | media/audio | float | write | 1 | Fifth DCT difference coefficient in FUN_00531b50; part of inverse DCT difference kernel array |
| DAT_005b77ee | CodecModeTable | media | ushort | read | 1 | Codec mode table entry in FUN_00536260; indexed by mode*12 for codec configuration values (block count, window size, etc.) |
| DAT_005b8890 | SoundInstanceVTable | audio | ptr | offset | 1 | Sound instance vtable pointer — used in FUN_0053a4d0 sound object construction |
| DAT_005dbc30 | ErrorCreatingDString | media | char* | offset | 1 | "Error creating D" error string — DirectX/DirectShow creation error |
| DAT_005dbf2c | ForFileSString | media | char* | offset | 1 | "for file '%s'" format string — file error context message |
| DAT_005dc0f8 | Grab3dBmpString | renderer | char* | offset | 1 | "Grab3D.bmp" string — screenshot/bitmap capture file name |
| DAT_005dc254 | DirectionalString | renderer | char* | offset | 1 | "Directional" string constant — directional light type key |
| DAT_005dc2e8 | BillboardString | renderer | char* | offset | 1 | "Billboard" string constant — billboard sprite type key |
| DAT_005dc3b4 | FogoutString | renderer | char* | offset | 1 | "Fogout" string constant — fog out distance key |
| DAT_005dc588 | D3DTextureConfig1 | renderer | int | read | 1 | D3D texture configuration value read in FUN_0055f0d0; texture format/usage flags |
| DAT_005dc544 | D3DTextureConfig2 | renderer | ushort | read | 1 | D3D texture configuration short value in FUN_0055f0d0; format sub-type identifier |
| DAT_005dc4dc | D3DTextureConfig3 | renderer | int | read | 1 | D3D texture configuration value in FUN_0055f0d0; texture dimension/level setting |
| DAT_005dc490 | D3DTextureConfig4 | renderer | int | read | 1 | D3D texture configuration value in FUN_0055f0d0; additional texture creation parameter |
| DAT_005e4e90 | QueryIdFormatString | network | char* | offset | 1 | "QueryId %d %d" format string — network query debug message |
| DAT_005b89a0 | NetworkInitConstant | network | int | read | 1 | Network initialization constant used in FUN_00563ab0; socket/connection config value |
| DAT_005e5160 | CommPortString | network | char* | offset | 1 | "COM" port name string — serial/communication port prefix |
| DAT_005e51e4 | Com8String | network | char* | offset | 1 | "COM8" string — 8th serial port name |
| DAT_005e5330 | JointHingeString | physics | char* | offset | 1 | "JointHinge" string constant — hinge joint type identifier for physics constraint system |
| DAT_008cfbf8 | LDLTWorkspaceA | dynamics | double | write | 1 | LDL^T factorization workspace variable; written in FUN_0056fa96 (block sparse LDL^T solver, 17KB function). Part of 0x8D0000 dynamics solver workspace |
| DAT_008d1130 | LDLTWorkspaceB | dynamics | double | read | 1 | LDL^T solver workspace double; read in FUN_0056fa96 during sparse matrix factorization |
| DAT_008d3a38 | LDLTWorkspaceC | dynamics | double | read | 1 | LDL^T solver workspace double; used in FUN_0056fa96 for matrix factor element storage |
| DAT_008d14c0 | LDLTWorkspaceD | dynamics | double | read | 1 | LDL^T solver workspace double; used in FUN_0056fa96 during forward/backward substitution |
| DAT_008d00a8 | LDLTWorkspaceBlock1 | dynamics | byte | offset | 1 | LDL^T solver workspace data block at 0x8D00A8; part of dynamics constraint solver matrix workspace |
| DAT_008d0238 | LDLTWorkspaceBlock2 | dynamics | byte | offset | 1 | LDL^T solver workspace data block at 0x8D0238; sparse matrix index/pointer array |
| DAT_008d3a70 | LDLTWorkspaceE | dynamics | double | read | 1 | LDL^T factorization workspace double in FUN_0056fa96; pivot element storage |
| DAT_008d1928 | LDLTWorkspaceF | dynamics | double | read | 1 | LDL^T solver workspace double; element of factored matrix L or D |
| DAT_008d1b18 | LDLTWorkspaceG | dynamics | double | read | 1 | LDL^T solver workspace double; intermediate product in forward substitution |
| DAT_008d0a88 | LDLTWorkspaceH | dynamics | double | read | 1 | LDL^T solver workspace double; accumulated dot product in factorization |
| DAT_008d0b68 | LDLTWorkspaceI | dynamics | double | read | 1 | LDL^T solver workspace double; Schur complement element in factorization |
| DAT_008d09f0 | LDLTWorkspaceJ | dynamics | double | read | 1 | LDL^T solver workspace double; temporary in diagonal update |
| DAT_008d1d18 | LDLTWorkspaceK | dynamics | double | read | 1 | LDL^T solver workspace double; element of L matrix column |
| DAT_008d12f8 | LDLTWorkspaceL | dynamics | double | read | 1 | LDL^T solver workspace double; workspace for solver back-substitution |
| DAT_008d39e0 | LDLTWorkspacePtr | dynamics | int | offset | 1 | LDL^T solver workspace pointer/offset; index array pointer for sparse matrix structure |
| DAT_008d17a8 | LDLTWorkspaceM | dynamics | double | read | 1 | LDL^T solver workspace double; matrix element cache in factorization |
| DAT_008d17b0 | LDLTWorkspaceN | dynamics | double | read | 1 | LDL^T solver workspace double; neighbor block element in sparse factorization |
| DAT_008d1690 | LDLTWorkspaceO | dynamics | double | read | 1 | LDL^T solver workspace double; block matrix element in factorization |
| DAT_008d19a0 | LDLTWorkspaceP | dynamics | double | read | 1 | LDL^T solver workspace double; sparse matrix element workspace |
| DAT_008d1c78 | LDLTWorkspaceQ | dynamics | double | read | 1 | LDL^T solver workspace double; factorization intermediate |
| DAT_008d1fe0 | LDLTWorkspaceR | dynamics | double | read | 1 | LDL^T solver workspace double; diagonal block workspace |
| DAT_008d17e0 | LDLTSolverWorkspaceS | dynamics | double | read | 1 | LDL^T solver workspace double; column scaling factor |
| DAT_008d39d0 | LDLTSolverBlockOffset | dynamics | int | offset | 1 | LDL^T solver block offset — index offset into sparse matrix block array |
| DAT_008d3b20 | LDLTSolverWorkspaceT | dynamics | double | read | 1 | LDL^T solver workspace double; regularization factor |
| DAT_008d1bc8 | LDLTSolverBlockPtr | dynamics | byte | offset | 1 | LDL^T solver data block pointer — dynamic workspace for matrix block data |
| DAT_008d1e78 | LDLTSolverWorkspaceU | dynamics | double | read | 1 | LDL^T solver workspace double; residual norm accumulator |
| DAT_008d3b60 | LDLTSolverWorkspaceV | dynamics | double | read | 1 | LDL^T solver workspace double; convergence check value |
| DAT_008d23d8 | LDLTFactorWorkspaceA | dynamics | double | write | 1 | LDL^T factorization workspace in FUN_00575bbd (13KB function, dense LDL^T/Cholesky factor); part of dynamics constraint solver |
| DAT_008d2748 | LDLTFactorWorkspaceB | dynamics | double | write | 1 | LDL^T factorization workspace double in FUN_00575bbd; matrix diagonal element |
| DAT_008d2bb8 | LDLTFactorBlockPtr | dynamics | byte | offset | 1 | LDL^T factor workspace data block; dense matrix storage in constraint solver |
| DAT_008d2f80 | LDLTFactorBlockPtr2 | dynamics | byte | offset | 1 | Second LDL^T factor workspace block; lower-triangular L matrix storage |
| DAT_008d3550 | LDLTFactorBlockPtr3 | dynamics | byte | offset | 1 | Third LDL^T factor workspace block; right-hand side / solution storage |
| DAT_008d3bf9 | DynamicsSolverByte | dynamics | byte | offset | 1 | Dynamics constraint solver byte-sized data; part of 0x8D3BF9 block used in FUN_0057adb0 |
| DAT_005baa90 | UtilityListVTable | runtime | ptr | offset | 1 | Utility/linked-list node vtable pointer — used in FUN_0057bf00 memory management |
| DAT_005e5e84 | TheRemoteAddrString | network | char* | offset | 1 | "The remote address" string — network connection debug message |
| DAT_005e5720 | TheVirtualCircString | network | char* | offset | 1 | "The virtual circuit" string — virtual circuit debug message |
| DAT_005baafc | HeapManagerVTable | memory | ptr | offset | 1 | Heap manager vtable pointer — used in FUN_0057ef20 heap init (allocates 0x20 bytes) |
| DAT_005baf38 | MemListDestructVTable | memory | ptr | offset | 1 | Memory list destructor vtable pointer — used in FUN_00582f60 for walking and freeing linked list |
| DAT_005bb220 | AllocatorListVTable | memory | ptr | offset | 1 | Allocator list vtable pointer — used in FUN_00586070 for dual-list memory cleanup; walks primary and secondary lists |
| DAT_005e64f8 | FormatFuncDispatchTable | runtime | ptr[] | read | 1 | Function pointer dispatch table (stride 0xC per entry) in FUN_00588c7a; indexed by locale type for format string processing |
| DAT_005be3d8 | LocaleDataEndPtr | runtime | ptr | offset | 1 | Locale data end pointer; used in FUN_00589c77 as range endpoint (DAT_005be3c0 to DAT_005be3d8) for locale data cleanup |
| DAT_005b8cd0 | HeapAllocExceptionInfo | runtime | ptr | offset | 1 | Exception handler data for heap allocation in FUN_0058a973; linked into exception chain during HeapAlloc call |
| DAT_005b8e3c | FPUScaleThreshold | math/CRT | double | read | 1 | FPU scaling threshold in FUN_0058dd89; when param value is denormalized (exponent == 0), applies fscale; when NaN (+7ff), applies fscale at exponent offset |
| DAT_008d3f40 | LocaleInitFlag | runtime | int | read | 1 | Locale/codec initialization flag in FUN_0058f4f2; gates locale data initialization for code page conversion |
| DAT_005b94d0 | CPInfoVTable | runtime | ptr | offset | 1 | Code page / locale info vtable pointer — used in FUN_005903da for code page name lookup |
| DAT_005e7728 | FPUDoubleConstant | math/CRT | double | read | 1 | FPU double constant in FUN_005919da; compared during floating-point rounding/exception handling tests |
| DAT_008d4068 | DateFieldSize | runtime | ushort | read | 1 | Date field format sizes in FUN_0059249b; part of locale date/time format parameter array (DAT_008d4060-406e) |
| DAT_005e78c0 | FormatSpecPtr | runtime | int | offset | 1 | Format specification pointer — used in FUN_005932f3 for format string processing |
| DAT_008d41c4 | NumberParseBuffer | runtime | byte | offset | 1 | Number parsing buffer in FUN_005968f6; holds 4-byte digit character data during integer parsing from locale string |
| DAT_005b9b4c | InfString | runtime | char* | offset | 1 | "1#INF" string constant — MSVC CRT infinity representation |
| DAT_005bb4f0 | CxxExceptionVTable | runtime | ptr | offset | 1 | C++ exception vtable pointer — used in FUN_00599b1c (__CxxFrameHandler) during exception object construction |
| DAT_005bb788 | CriticalSectionVTable | runtime | ptr | offset | 1 | Critical section / sync object vtable pointer — used in FUN_0059aab9 for thread synchronization init |
| DAT_005bab94 | CxxFrameHandlerTramp | runtime | ptr | offset | 1 | __CxxFrameHandler trampoline — stub function that delegates to __CxxFrameHandler in FUN_0059caa8 |
