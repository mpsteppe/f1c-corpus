=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be648 | GridString | setup | char* | read | 1 | "Grid" string constant for grid/starting position format |
| DAT_005be568 | GrooveWidthString | setup | char* | read | 1 | "GrooveWidth" parameter string for track surface config |
| DAT_005be4d4 | RainyDarknessString | setup | char* | read | 1 | "RainyDarkness" parameter string for weather/lighting |
| DAT_005be720 | LowpassFilterString | audio | char* | read | 1 | "LowPassFilter" audio DSP filter parameter name string |
| DAT_007c5bc8 | ScoringDBEndSentinel | scoring | ptr | read | 1 | Loop boundary sentinel for SeasonScoringDB (stride 0x48c0) iteration — terminates at address < &DAT_007c5bc8 |
| DAT_005bea50 | ScriptEndString | setup | char* | read | 1 | "ScriptEnd" — script/INI section terminator string |
| DAT_005beb4c | DotExtension | file | char[] | read | 1 | "." dot extension string — used in file path manipulation (strips file extension, appends to directory path) |
| DAT_005bf8f0 | CommentaryAudioPtr_Tv | audio | ptr | read | 1 | TV commentary audio pointer table entry — returned as param_5 when type=1 (TV mode), paired with PTR_s_Audio_Commentary_Tv__005bf8e8 |
| DAT_005c23d8 | FormatString_SSSPwsS | UI | char* | read | 1 | Format string "%s %s %s Pws: %s" for UI display |
| DAT_005c2538 | DriverNameEddieI | setup | char* | read | 1 | "Eddie Irvine" driver name string |
| DAT_005c246c | DriverNameAlexanderW | setup | char* | read | 1 | "Alexander Wurz" driver name string |
| DAT_005c2968 | TeamName1999Jordan | setup | char* | read | 1 | "1999 Jordan" team name string |
| DAT_005c2850 | TeamName2001Benetton | setup | char* | read | 1 | "2001 Benetton" team name string |
| DAT_0059e838 | PositionThreshold | ai | double | read | 1 | Position ratio threshold for finish position classification — compared with `(double)(int)uVar1 < (double)(int)DAT_005c329c * _DAT_0059e838` to determine top/bottom split in finish position handling |
| DAT_005c2d6c | WindowTitle_F1999 | UI | char* | read | 1 | "F1 Challenge 99-02" window title string |
| DAT_005c2c08 | SaveDirString | setup | char* | read | 1 | "SaveDir" — save game directory config key |
| DAT_005c2b04 | AutoLaunchString | setup | char* | read | 1 | "AutoLaunch" — auto-launch config parameter string |
| DAT_005c2f50 | DriversDirFormat | setup | char* | read | 1 | "DriversDir\" — drivers directory path format string (appended to season path) |
| DAT_005c2e0c | InstallString | setup | char* | read | 1 | "Install" — install path registry/config key string |
| DAT_005c323c | StartsWetString | setup | char* | read | 1 | "StartsWet" — weather/wet start config parameter string |
| DAT_005ea3dc | DifficultySlopeLow | ai | float | read | 1 | Low end of AI difficulty interpolation slope — used when AIDifficultySlider < 100: `(fVar1 - _DAT_005ea3dc) * (float10)(DAT_007d01a0 + -0x46) * _DAT_0059e474 + _DAT_005ea3dc` |
| DAT_0059e924 | WheelContactLerpFactor | physics | float | read | 1 | Wheel-ground contact interpolation factor — used in FUN_004270a0 (9165-byte vehicle update) with `_DAT_0059e924` as linear interpolation weight for wheel/tire contact state smoothing |
| DAT_005c335c | EnteredDynmanString | setup | char* | read | 1 | "Entered DynMan.dll" — debug/trace string for dynamics manager load |
| DAT_007cc704 | RendererStateFlag | renderer | int | read | 1 | Renderer state flag checked in rendering pipeline |
| DAT_005c3530 | PracticeString | setup | char* | read | 1 | "Practice" — session type display string |
| DAT_005c3640 | EnteredGameIniString | setup | char* | read | 1 | "Entered game.ini" — debug/trace string for game config load |
| DAT_005c374c | FormatString_SSS | UI | char* | read | 1 | Format string "%s %s %s" for multi-string concatenation |
| DAT_005c3e10 | PitstopSettingString | setup | char* | read | 1 | "Pitstop2Setting" — pit stop configuration INI key (variant) |
| DAT_005c3c78 | RightTrackBarsString | setup | char* | read | 1 | "RightTrackBars" — UI display toggle INI key (variant) |
| DAT_005c3a6c | EngineMapSettingString | setup | char* | read | 1 | "EngineMapSetting" — engine map configuration INI key (variant) |
| DAT_005c38d8 | FastBumpSettingString | setup | char* | read | 1 | "FastBumpSetting" — fast bump damping configuration INI key (variant) |
| DAT_005c3f48 | FormatString_S0Ds | UI | char* | read | 1 | Format string "%s %0d %s" for numeric-string formatting |
| DAT_005c4078 | RaceString | setup | char* | read | 1 | "Race" — session type display string |
| DAT_005c40b8 | SpringBodyString | setup | char* | read | 1 | "SpringBody" — suspension body parameter name string |
| DAT_005c4198 | FrWheelString | setup | char* | read | 1 | "FrWheel" — front wheel label for display/debug |
| DAT_0059ebb8 | PositionTransitionConst | dynamics | double | read | 1 | Double constant used in position/velocity update math |
| DAT_0059ec88 | FuelConsumptionRate | dynamics | double | read | 1 | Fuel consumption rate multiplier — `*(double *)(param_1 + 0x1bc0) = param_2 * _DAT_0059ec88 + ...` — scales fuel flow by this factor per time step |
| DAT_0059eda0 | DragForceMultiplier | physics | double | read | 1 | Aerodynamic drag force multiplier — used in FUN_004423b0 (2261-byte physics function) as double-precision scaling factor for drag computation |
| DAT_0059ee90 | ContactPatchScale | physics | float | read | 1 | Contact patch scaling factor — used in tire/ground contact physics (FUN_004441f0, 9101-byte tire model function) |
| DAT_0059edf8 | TireContactGain | physics | double | read | 1 | Tire contact gain multiplier — double-precision gain factor in tire force computation (FUN_004441f0) |
| DAT_007cf59c | EngineRPMThreshold | audio | float | read | 1 | Engine RPM threshold for audio sample selection — gates engine sound pitch/sample switching |
| DAT_007cd154 | FloatOneInit | renderer | int | write | 1 | Initialized to 1065353216 (1.0f as IEEE 754 int) along with flt_7CD150 = 0.0 — renderer float state reset |
| DAT_007ccd5c | CollisionGridZeroField | collision | int | write | 1 | Zeroed field in collision grid struct (companion to DAT_007ccd50=0xd, _DAT_007ccd54=0, DAT_007ccd58=0) — collision grid initialization |
| DAT_007ccd10 | CollisionGridField | collision | int | write | 1 | Zeroed field in collision grid struct (companion to DAT_007ccd08=0x12) — initialized during collision grid setup |
| DAT_005ad364 | AudioChannelConfig | audio | int | read | 1 | Audio channel/bus configuration index — read in FUN_0044ff50 (5968-byte audio processing function) for channel routing setup |
| DAT_005ad3d4 | AudioMixerParam | audio | int | read | 1 | Audio mixer parameter — companion to DAT_005ad364, used in same audio processing pipeline |
| DAT_007cc130 | RendererTintParam | renderer | float | read | 1 | Renderer tint/color parameter — read in FUN_00451720 (3910-byte render scene function) |
| DAT_007d247c | CameraDistanceParam | camera | float | read | 1 | Camera distance parameter — read in rendering/scene function for view distance |
| DAT_007cca54 | ControlBindingIndex | input | int | read | 1 | Control/input binding index — used in FUN_00452b10 for matching against control scheme IDs |
| DAT_007cca3c | ControlStateStore | input | float | write | 1 | Control state storage — written in FUN_004537b0 during control state update |
| DAT_007ca4c8 | ControlThresholdStore | input | float | write | 1 | Control axis threshold — written in FUN_004537b0 during sensitivity/range update |
| DAT_005c55f0 | FifthGearString | setup | char* | read | 1 | "FifthGear" — gear ratio parameter name for 5th gear |
| DAT_005c54c8 | VehicleLabelString | setup | char* | read | 1 | "Vehicle Labels" — UI display toggle INI key |
| DAT_005c571c | EnteredHWInputString | setup | char* | read | 1 | "Entered HWInput_3.dll" — debug/trace string for hardware input DLL |
| DAT_0059efec | VTable_ObjectBase | UI | ptr | offset | 1 | Vtable/function pointer table for object base class — stored at `*param_1 = &PTR_LAB_0059efec` in constructor (FUN_004571e0), initializes ~40 fields including default float constants (60.0, 45.0, etc.) |
| DAT_0059f060 | AccelerationDamping | dynamics | double | read | 1 | Double acceleration damping constant — used in velocity/acceleration update math |
| DAT_005c5c40 | PasswordString | network | char* | read | 1 | "Password" — network/game password parameter string |
| DAT_007d11c4 | NetworkPacketInterval | network | float | read | 1 | Network packet send interval — used in FUN_0045e620 for timing network packet dispatch |
| DAT_005c5eb4 | UnloadingSlotString | network | char* | read | 1 | "Unloading slot %i" — debug string for network slot cleanup |
| DAT_007d0c24 | TireWearMultTarget | config | int | read | 1 | Target storage for TireWearMultiplier — read in config load function as deduplication/sync target |
| DAT_007ce964 | TireModelModeTarget | config | int | read | 1 | Target storage for TireModelMode — companion to DAT_007ce958, used as sync target in config load |
| DAT_007d1028 | RaceSetupParam | config | int | read | 1 | Race setup parameter read in config/setup sync function |
| DAT_005c64a0 | HostString | network | char* | read | 1 | "Host" — network host mode string |
| DAT_005c65ec | SelectCircuitPrompt | UI | char* | read | 1 | "SelectCircuitPrompt" — UI prompt/string for circuit selection screen |
| DAT_007c7064 | SceneDestroyedFlag | renderer | byte | read | 1 | Flag checked before scene destruction — when 0, calls scene cleanup function; gates linked-list cleanup loop |
| DAT_005c684c | FormatString_Ss1f | UI | char* | read | 1 | Format string "%s %s %1f" for UI text formatting |
| DAT_007cd850 | MultiClientPassword | network | char[] | offset | 1 | Password string buffer — used for multi-client password entry comparison; compared with FUN_00462c00 and written to param_1+0xe4 as 4.0f on match |
| DAT_005c6b1c | FormatString_DD4 | UI | char* | read | 1 | Format string "%d %d %d %d" for numeric display |
| DAT_007cd817 | FilePathNullTerminator | file | byte | write | 1 | Null terminator (0) written at end of file path buffer (byte_7CD718) — marks end of path string |
| DAT_005c73fc | DriverString | setup | char* | read | 1 | "Driver" — driver configuration section string |
| DAT_007d0a30 | ConnectionStringData | network | byte[] | offset | 1 | Connection string data block (36 bytes) — copied via qmemcpy in socket connection setup |
| DAT_005cc524 | SourceMassString | setup | char* | read | 1 | "SourceMass" — vehicle setup parameter name (mass distribution) |
| DAT_005cc734 | SourceVariableString | setup | char* | read | 1 | "SourceVariable" — setup parameter name |
| DAT_005cc794 | Font3String | UI | char* | read | 1 | "Font3" — font resource name string |
| DAT_005cc980 | UndefinedErrorString | UI | char* | read | 1 | "Undefined Error" — generic error display string |
| DAT_005cc9f0 | GameTitleBmpString | UI | char* | read | 1 | "GameTitle.bmp" — title screen bitmap filename |
| DAT_005ccb44 | CurrentPageString | UI | char* | read | 1 | "CurrentPage" — UI page state parameter string |
| DAT_005cce64 | FormatString_DS | UI | char* | read | 1 | Format string "%d %s" for numeric-string display |
| DAT_005ccb90 | PageJumpTable | UI | ptr | read | 1 | Page/callback function pointer table for UI navigation |
| DAT_007c7ab8 | PhysicsTimestepMultiplier | physics | double | read | 1 | Double-precision physics timestep multiplier used in dynamics update |
| DAT_007cc310 | ButtonStateFlag | UI | int | read | 1 | Button/UI element state flag checked in FUN_0049f790 — when non-zero, calls FUN_004a57a0 |
| DAT_007ce278 | SessionInitFlag | session | byte | offset | 1 | Session initialization flag — part of session init state group |
| DAT_007ce2b8 | SessionStateTimer | session | int | write | 1 | Session state timer/counter — written during session setup |
| DAT_005cd280 | RearRightWheelString | setup | char* | read | 1 | "RearRightWheel" — wheel label for setup display |
| DAT_005cd428 | MeshFormatString | renderer | char* | read | 1 | "Mesh %s" — mesh loading format string |
| DAT_005cd490 | UnknownByteConstant | misc | byte | read | 1 | Byte constant read in utility function |
| DAT_005cd598 | PitCrewString1002 | setup | char* | read | 1 | "PitCrew10Sec02" — pit crew animation/sequence filename |
| DAT_005cd698 | ExitingPitsString | setup | char* | read | 1 | "ExitingPitsUnd" — pit exit state string |
| DAT_005cd6cc | RPlayString | setup | char* | read | 1 | "RPlay" — replay system string |
| DAT_005d1e6c | NoAIControlString | setup | char* | read | 1 | "NoAIControl" — AI control mode parameter string |
| DAT_005d1ac8 | DifficultyLevelString | setup | char* | read | 1 | "0 Normal 1 Extra Hard 0" — difficulty level options description |
| DAT_005d18f8 | SecondsBetweenString | setup | char* | read | 1 | "SecondsBetween" — time interval parameter string |
| DAT_005d1670 | MusicToggleString | setup | char* | read | 1 | "MusicToggle" — music on/off config key |
| DAT_005d1454 | SoundDetailString | setup | char* | read | 1 | "SoundDetail" — sound quality/detail config key |
| DAT_005d12c8 | BroadcastOverlayString | setup | char* | read | 1 | "BroadcastOverlay" — broadcast UI overlay toggle key |
| DAT_005d10f0 | ShadowsString | setup | char* | read | 1 | "Shadows" — shadow rendering toggle config key |
| DAT_005d0e18 | TireSmokeString | setup | char* | read | 1 | "WhetherTireSmoke" — tire smoke particle toggle config key |
| DAT_005d0b00 | HeadFractionString | setup | char* | read | 1 | "FractionOfHead" — cockpit head movement fraction config key |
| DAT_005d0958 | StartingViewString | setup | char* | read | 1 | "StartingView" — initial camera view config key |
| DAT_005d06c8 | BasicAudioString | setup | char* | read | 1 | "BasicAudio" — audio mode config key (basic vs enhanced) |
| DAT_005d0418 | TheoreticalFractionString | setup | char* | read | 1 | "FractionOfTheoretical" — wheel rotation fraction config key |
| DAT_005d0128 | VehicleSpecificString | setup | char* | read | 1 | "VehicleSpecific" — vehicle-specific setup toggle key |
| DAT_005cff74 | OpponentsString | setup | char* | read | 1 | "Opponents" — opponent count/config config key |
| DAT_005cfbf4 | InactiveSleepString | setup | char* | read | 1 | "InactiveSleepTime" — sleep/idle timeout for inactive players key |
| DAT_005cf7b0 | GameLanModeString | setup | char* | read | 1 | "IfTrueTheGameLAN" — LAN mode enable description string |
| DAT_005cf428 | KbitsPerSecondString | setup | char* | read | 1 | "KbitsPerSecond" — network bandwidth config key |
| DAT_005cf0c4 | PageTransitionString | setup | char* | read | 1 | "PageTransition" — UI page transition effect key |
| DAT_005ceca0 | ExponentToString | setup | char* | read | 1 | "ExponentToApply" — FFB exponent parameter key |
| DAT_005ceb1c | AxisDeadzoneString | setup | char* | read | 1 | "Axis(2,2)DeadZone" — FFB axis deadzone config key |
| DAT_005ce90c | ControlDisplayString | setup | char* | read | 1 | "ControlDisplay" — input control display toggle key |
| DAT_005ce734 | ControlStarterString | setup | char* | read | 1 | "ControlStarter" — starter button assignment key |
| DAT_005ce400 | SteeringMagnitudeString | setup | char* | read | 1 | "MagnitudeOfSteering" — FFB steering magnitude key |
| DAT_005cdee0 | SaturationValueString | setup | char* | read | 1 | "SaturationValue" — FFB saturation key |
| DAT_005cdae0 | FfbBrakeVibeString | setup | char* | read | 1 | "FfbBrakeVibeSlope" — FFB brake vibration key |
| DAT_005cd704 | FfbJoyAxisString | setup | char* | read | 1 | "FfbJoy2dAxis(2,2)" — FFB joystick axis config key |
| DAT_005acc68 | VTable_RenderObject | renderer | ptr | offset | 1 | Vtable/function pointer table for renderer object class — stored at `*param_1 = &PTR_LAB_005acc68` in constructor |
| DAT_005d23b0 | EnteredRenderString | setup | char* | read | 1 | "Entered Render Init" — debug/trace string for renderer init |
| DAT_005d2454 | SavingHotlapString | setup | char* | read | 1 | "Saving Hotlap" — debug/info string for hotlap save |
| DAT_005d2524 | SystemMemoryBlock | memory | byte[] | offset | 1 | System memory block used in low-level memory operations |
| DAT_005acd84 | DepthOfFieldScale | renderer | float | read | 1 | Depth of field scaling factor for renderer post-processing |
| DAT_008aae6c | ScoringDataQueuePtr | scoring | ptr | write | 1 | Scoring data queue pointer — written to &DAT_0083ee64 as linked-list head for scoring event queue |
| DAT_005d27c0 | FinishPositionFormat | file | char* | read | 1 | "FinishPosition %2d %d" — format string for race results file writing |
| DAT_005d28e4 | BestLapTimeString | file | char* | read | 1 | "BestLapTime" — results file field name |
| DAT_005d2c90 | RaceCondFormatString | file | char* | read | 1 | "RaceCondFormat" — race conditions format string for file output |
| DAT_005d3018 | GraphicsString | setup | char* | read | 1 | "Graphics" — graphics configuration section string |
| DAT_005d2f0c | PitcrewLiveryString | setup | char* | read | 1 | "PitCrewLivery" — pit crew appearance config key |
| DAT_005d31d4 | EventNameString | setup | char* | read | 1 | "EventName" — event/scenario name string |
| DAT_005d340c | EnteredSoundString | setup | char* | read | 1 | "Entered Sound Post" — debug string for sound system post-init |
| DAT_005ace94 | ParticleSpreadScale | renderer | float | read | 1 | Particle spread/randomization scale factor — used in particle effect position calculation with _DAT_0059ed28 multiplier |
| DAT_005d35e0 | DurationString | renderer | char* | read | 1 | "Duration" — particle/lifetime parameter string |
| DAT_005d34fc | PlaneString | renderer | char* | read | 1 | "Plane" — render plane/surface name string |
| DAT_005d370c | InverseDestAlphaString | renderer | char* | read | 1 | "InvDstAlpha" — D3D blend mode parameter name |
| DAT_005d38e8 | WetString | setup | char* | read | 1 | "Wet" — weather condition display string |
| DAT_007cf9d4 | WeatherParticleGate | renderer | byte | read | 1 | Weather particle enable gate — checked in rain/snow particle update loop |
| DAT_005d3b58 | CouldNotLoadString | file | char* | read | 1 | "Could not load %s" — file load error message format |
| DAT_005d3b94 | CouldNotFindGLString | renderer | char* | read | 1 | "Could not find GL" — OpenGL/extension not found error string |
| DAT_005d413c | DateFormatString | UI | char* | read | 1 | Date format "%02d/%02d/%02d/%02d" for UI display |
| DAT_005d3fb8 | DriveAidsString | setup | char* | read | 1 | "DriveAids AntiLock" — driving aids INI section key |
| DAT_005d3db0 | VehiclesAllowedString | setup | char* | read | 1 | "Vehicles Allowed" — vehicle filter/limit config key |
| DAT_005acefc | TrackSurfaceScale | track | float | read | 1 | Track surface texture/mapping scale factor |
| DAT_005d427c | NoPitOutPolyString | track | char* | read | 1 | "No pit out poly for %d" — track loading error message format |
| DAT_005d4320 | TrackCVarConstant | track | int | read | 1 | Track configuration variable constant |
| DAT_005d453c | LongAccelMSString | setup | char* | read | 1 | "LongAccelMS" — longitudinal acceleration unit string |
| DAT_005d4418 | TyreWearString | setup | char* | read | 1 | "TyreWear" — tire wear display/unit string |
| DAT_005d486c | FrontString | setup | char* | read | 1 | "Front" — front axle label string |
| DAT_005d478c | AIGripMultString | setup | char* | read | 1 | "AIGripMult" — AI grip multiplier config key |
| DAT_005d49e4 | NonExistentTireString | setup | char* | read | 1 | "Non-existent tire" — error message for invalid tire compound |
| DAT_005d4ad8 | HudTextureString | setup | char* | read | 1 | "Hud512_64.tga" — HUD texture filename |
| DAT_005acf8c | VTable_InputHandler | input | ptr | offset | 1 | Vtable/function pointer table for input handler class — used in switch-based object factory (FUN_004daea0) creating different input handler types (keyboard, mouse, DInput, etc.) for cases 0-0x13 |
| DAT_005d4c64 | WcPitBodyString | setup | char* | read | 1 | "WcPitBody" — pit body/wall name string |
| DAT_005c67b4 | MediumString | setup | char* | read | 1 | "Med" — medium option string (tire compound / detail level) |
| DAT_005c674c | ArmsString | setup | char* | read | 1 | "Arms" — suspension arm label string |
| DAT_005d4e58 | DefaultLimitString | setup | char* | read | 1 | "DefaultLimit" — limit/default parameter name string |
| DAT_005ad18c | FlipbookFrameRate | renderer | float | read | 1 | Flipbook/animation frame rate scaling factor — read in FUN_004e5f60 (3593-byte animation/rendering function) |
| DAT_008aced0 | TireFrictionRangeLow | physics | float | read | 1 | Low end of tire friction range — `fVar3 = (_DAT_008aced4 - _DAT_008aced0) * _DAT_008afee8 + _DAT_008aced0` interpolates grip across friction range |
| DAT_005d5014 | RadiusAddString | setup | char* | read | 1 | "RadiusAdd" — collision radius adjustment parameter name |
| DAT_005d4ee4 | WheelCollParamString | setup | char* | read | 1 | "WheelDCollParams" — wheel collision parameter name |
| DAT_005d5200 | BrakeDiscInertiaString | setup | char* | read | 1 | "BrakeDiscInertia" — brake disc inertia parameter name |
| DAT_005d50d0 | FastBumpSettingString | setup | char* | read | 1 | "FastBumpSetting" — fast bump damping parameter name |
| DAT_005d539c | ZForceAppliedString | setup | char* | read | 1 | "ZForceAppliedWheel" — vertical wheel force parameter name |
| DAT_005d5638 | RpmTorqueBrakeString | setup | char* | read | 1 | "RpmTorqueBrake" — engine braking torque parameter name |
| DAT_005d673c | RideString | setup | char* | read | 1 | "Ride" — ride height parameter name |
| DAT_005d6638 | FuelTankMotionString | setup | char* | read | 1 | "FuelTankMotion" — fuel tank movement simulation parameter name |
| DAT_005d6504 | FuelSettingString | setup | char* | read | 1 | "FuelSetting" — fuel load/strategy parameter name |
| DAT_005d63f0 | FWAftString | setup | char* | read | 1 | "FWAft" — front wing aft/position parameter name |
| DAT_005d6314 | RWSettingString | setup | char* | read | 1 | "RWSetting" — rear wing setting parameter name |
| DAT_005d6204 | BrakeDuctLiftString | setup | char* | read | 1 | "BrakeDuctLift" — brake duct lift parameter name |
| DAT_005d60b4 | FrontAntiSwayString | setup | char* | read | 1 | "FrontAntiSwayRate" — front anti-roll bar rate parameter name |
| DAT_005d5ed8 | FrontAntiSway2String | setup | char* | read | 1 | "FrontAntiSwayRate..." — front anti-roll bar rate variant |
| DAT_005d5d3c | Front3rdPackerString | setup | char* | read | 1 | "Front3rdPacker..." — front 3rd spring packer parameter name |
| DAT_005d5b54 | RearSlowReboundString | setup | char* | read | 1 | "Rear3rdSlowRebound..." — rear slow rebound damping parameter |
| DAT_005d59dc | RestrictorPlateString | setup | char* | read | 1 | "RestrictorPlate" — engine restrictor plate parameter name |
| DAT_005d58b6 | GearFileString | setup | char* | read | 1 | "GearFile" — gear ratio file parameter name |
| DAT_005d5774 | RearLeftString | setup | char* | read | 1 | "RearLeft" — rear-left wheel label string |
| DAT_008af574 | PhysicsConstraintIndex | physics | int | read | 1 | Physics constraint/index value read in dynamics constraint solver |
| DAT_005d6ba4 | ShiftAmbientString | audio | char* | read | 1 | "ShiftAmbient" — gear shift ambient sound parameter name |
| DAT_005d6a27 | ShiftSoundByteSeq | audio | byte[] | offset | 1 | Gear shift sound byte sequence / parameter data |
| DAT_005d6897 | EngineSoundByteSeq | audio | byte[] | offset | 1 | Engine sound byte sequence / parameter data |
| DAT_005d6da8 | FormatString_Ins32f | renderer | char* | read | 1 | Format string "ins(32,%f)" for shader/instruction format |
| DAT_005d6e04 | FormatString_FTim28wht | renderer | char* | read | 1 | Format string "ftim2.8wht" for texture/timing format |
| DAT_005d6ed0 | EnteredVidmanString | setup | char* | read | 1 | "Entered VidMan Post" — debug string for video manager post-init |
| DAT_007cf17c | WeatherStateFlag | weather | byte | read | 1 | Weather state flag checked in weather/sky update function |
| DAT_005ad2e8 | CameraSwayScale | camera | float | read | 1 | Camera sway/movement scale factor — used in FUN_004fd8b0 (1358-byte camera shake/sway function) with `_DAT_005ad300` as clamp threshold |
| DAT_005ad31c | CameraFOVScale | camera | float | read | 1 | Camera FOV/zoom scale factor — read in camera update function |
| DAT_005d7128 | DevPathString | setup | char* | read | 1 | "D:\Dev\F1_1999_2002" — development source path string |
| DAT_007cf8f0 | RainIntensityFactor | weather | float | read | 1 | Rain intensity factor — used in FUN_004feaf0 (1231-byte rain particle/weather effect update) |
| DAT_00800080 | ColorBlendLookupTable | renderer | byte[] | offset | 1 | Color blending lookup table — used in FUN_00503533 (294-byte image blend function) for 32-bit pixel color blending with `&DAT_00800080 + (uVar3 >> 2 & 0x3fc03fc0) + ...` address computation |
| DAT_005adbd8 | VTable_TextureLoader | renderer | ptr | offset | 1 | Vtable/function pointer table for texture loader class — stored at `*param_1 = &PTR_FUN_005adbd8` in constructor (28 bytes) |
| DAT_005adc9c | VTable_ShaderLoader | renderer | ptr | offset | 1 | Vtable/function pointer table for shader loader class — stored at `*param_1 = &PTR_FUN_005adc9c` in constructor |
| DAT_005addcc | VTable_VertexDecl | renderer | ptr | offset | 1 | Vtable/function pointer table for vertex declaration class — stored at `*param_1 = &PTR_FUN_005addcc` in constructor |
| DAT_005d78a0 | PTR_Func_DrawCallback | renderer | ptr | read | 1 | Function pointer for render draw callback — called as `(*(code *)PTR_FUN_005d78a0)(param_1,param_2,param_3,param_4,param_5,param_6)` |
| DAT_005ade74 | CPUID_GenuineIntel | setup | char* | read | 1 | "GenuineIntel" — CPUID vendor string for Intel CPU detection |
| DAT_005af294 | FormatString_Trns | file | char* | read | 1 | "Trns" — format/type string for file conversion |
| DAT_005af5c4 | RemapCoefficientTable | math | float[] | offset | 1 | Remap/interpolation coefficient table — selected between two tables (DAT_005af5c4 for size=6, DAT_005af58c for size=8) in FUN_00513f7a (773-byte coefficient remap function). Used with DAT_005af5ac as corresponding "to" table. Implements spline/bezier coefficient remapping |
| DAT_005afa10 | UnknownVendorString | setup | char* | read | 1 | "Unknown vendor" — CPUID unrecognized vendor string |
| DAT_005afce4 | PNG_NoIHDRString | file | char* | read | 1 | "Missing IHDR before IDAT" — PNG decoder error string |
| DAT_005aff20 | PNG_NoPLTEString | file | char* | read | 1 | "Missing PLTE before IDAT" — PNG decoder error string |
| DAT_005d8a00 | SIMD_QWordConstant | renderer | qword | read | 1 | Qword constant used in SIMD pixel processing (MMX/SSE) for color channel manipulation |
| DAT_005d8b00 | SIMD_XorMask | renderer | xmmword | read | 1 | XMM word constant used as XOR mask in SIMD vector operations (FUN_0051f98e) — `_mm_xor_ps((__m128)xmmword_5D8B00, v7)` for sign bit flipping in vector math |
| DAT_008d6138 | NormalizationReciprocal | math | float | read | 1 | Reciprocal divisor for vector normalization — `flt_8D6138 / v12` in cross-product normal computation (FUN_0051fd90, 276 bytes) |
| DAT_008d61f0 | SIMD_MatrixInitConst | renderer | xmmword | read | 1 | XMM word constant for matrix/transform initialization — stored as `*(_OWORD *)(a1 + 16) = xmmword_8D61F0` in SIMD math function |
| DAT_008d627c | NormalizationThreshold2 | math | float | read | 1 | Second normalization threshold/constant — parallel to flt_8D6118 group, used in cross-product normal compute variant (FUN_00520ce0) |
| DAT_005b0734 | PNG_InvalidBitLength | file | char* | read | 1 | "invalid bit length" — PNG/zlib decoder error string |
| DAT_005d9110 | SIMD_UnusedConstant | math | xmmword | read | 1 | XMM word constant referenced in stub/single-instruction function (FUN_00528bd0 — empty body, likely dead code) |
| DAT_005d9390 | RecipPoly_CoeffC | math | int | read | 1 | Coefficient C for Newton-Raphson reciprocal approximation polynomial (3DNow!/MMX) — packed float constant used in `PackedFloatingADD((ulonglong)DAT_005d9390, uVar4)` sequence along with DAT_005d9388/938c/9394/9398/939c |
| DAT_005d93e0 | ReciprocalStubConstant | math | int | read | 1 | Stub/referenced constant in empty function (sub_529200 — dead/stub code) |
| DAT_005b0ba8 | SIMD_MADD_QWordA | math | qword | read | 1 | Qword constant for packed 16-bit multiply-accumulate in SIMD short-vector multiplication (FUN_0052ab4e, 1720 bytes) |
| DAT_005b0c40 | SIMD_MADD_QWordB | math | qword | read | 1 | Qword constant for packed 16-bit multiply-accumulate — second operand in SIMD short multiplication |
| DAT_005da6f0 | MPEG_Fail2Format | audio | char* | read | 1 | "mpeg fail 2 %d" — MPEG audio decoder error format string |
| DAT_005b6f0c | DCT_LookupTableA | audio | byte[] | offset | 1 | DCT lookup table A (source data at 0x5b6f0a+2) — used in FUN_005317c0 to initialize 32-entry, 8-word lookup table with stride 0x40. Second source at 0x5b730a+2 initializes secondary table. Likely audio/MPEG decoder coefficient tables |
| DAT_005b7744 | DCT_Coefficient07 | audio | float | read | 1 | DCT coefficient #7 (0-indexed) in 16-element coefficient array (0x5b772c–0x5b776c) — transforms `(param_3[6] - param_3[0x19]) * _DAT_005b7744` in forward DCT |
| DAT_008b5958 | DCT_OutputBuffer0 | audio | float | write | 1 | DCT output buffer location — written to during forward DCT transform |
| DAT_008b59b4 | DCT_OutputBuffer1 | audio | float | write | 1 | DCT output buffer location — secondary write target in DCT |
| DAT_008b59f8 | DCT_OutputBuffer2 | audio | float | write | 1 | DCT output buffer location — tertiary write target in DCT |
| DAT_005da7fc | UnknownCompressionString | file | char* | read | 1 | "unknown compression" — decompression error string |
| DAT_005da928 | VTable_AudioClass | audio | ptr | offset | 1 | Vtable/function pointer table for audio class (~0xB00+ byte struct) — stored at `*(undefined ***)(param_1 + 0xb16) = &PTR_DAT_005da928` in constructor |
| DAT_005da998 | GetterReturnConstant | misc | int | read | 1 | Constant 0 returned by trivial getter function (copies to *param_1, returns 0) |
| DAT_005dbdb4 | FormatString_SMip2dS | renderer | char* | read | 1 | MIP mapping format string "%s Mip2d %s" for texture debug |
| DAT_008c5f48 | AudioInitArrayBase | audio | byte[] | offset | 1 | Array base address for audio initialization loop — FUN_0054eaa0 calls FUN_00548e00() 0x400 (1024) times |
| DAT_008b8c48 | SoundRoutingFlag | audio | byte | read | 1 | Sound routing/UI feedback flag — when bit 0 set, routes parameter 2 to function pointer call via vtable (FUN_00554560) |
| DAT_005dc388 | AnimFileString | renderer | char* | read | 1 | "AnimFile" — animation file path parameter string |
| DAT_005dc2a0 | ResponseString | network | char* | read | 1 | "Response" — network response message string |
| DAT_005dc5c0 | CPUID_GenuineIntel_0 | setup | char* | read | 1 | "GenuineIntel" — CPUID vendor string for Intel detection |
| DAT_005dc55c | CPUID_FeatureMask | setup | int | read | 1 | CPUID feature bitmask/flag for feature detection |
| DAT_005dc514 | CPUID_DataEntry | setup | int | read | 1 | CPUID data table entry for processor feature detection |
| DAT_005dc4d8 | CPUID_DataWord | setup | word | read | 1 | CPUID data table word entry |
| DAT_005dc5e4 | UnableToAllocateString | memory | char* | read | 1 | "Unable to allocate %d bytes" — memory allocation failure format |
| DAT_005e5038 | FormatString_18 | UI | char* | read | 1 | "18" — version/format number string |
| DAT_005e5064 | HostAddrString | network | char* | read | 1 | "HostAddr" — network host address config key |
| DAT_005e5180 | FileModeWriteBin | file | char* | offset | 1 | File open mode string ("wb" or similar binary write mode) — selected vs DAT_005e517c based on param_1[3] flag |
| DAT_005e51ac | LPT6String | setup | char* | read | 1 | "lpt6" — legacy parallel port device name |
| DAT_005e5308 | MemoryOpJumpTable | memory | ptr | offset | 1 | Jump table / function pointer table for memory operations |
| DAT_008cfd58 | LDLT_WorkspaceBase | dynamics | byte[] | offset | 1 | Constraint solver matrix workspace base address (0x8D0000–0x8D9000 block) — block sparse LDL^T factorization workspace in dynamics constraint solver (sub_56FA96, 17KB) |
| DAT_008cfd90 | LDLT_MatrixElement_A | dynamics | double | read | 1 | Double-precision matrix element in LDL^T constraint solver workspace |
| DAT_008cfe70 | LDLT_MatrixElement_B | dynamics | double | write | 1 | Double-precision matrix output element in LDL^T solver |
| DAT_008cff48 | LDLT_MatrixElement_C | dynamics | double | write | 1 | Double-precision matrix output element in LDL^T solver |
| DAT_008d0da0 | LDLT_MatrixElement_D | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d14e8 | LDLT_MatrixElement_E | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d0420 | LDLT_MatrixElement_F | dynamics | double | write | 1 | Double-precision matrix output element in LDL^T solver |
| DAT_008d1c00 | LDLT_MatrixElement_G | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d0668 | LDLT_MatrixElement_H | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1ea0 | LDLT_MatrixElement_I | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d0840 | LDLT_MatrixElement_J | dynamics | double | write | 1 | Double-precision matrix output element in LDL^T solver |
| DAT_008d3ab0 | LDLT_MatrixElement_K | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d0cd0 | LDLT_MatrixElement_L | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1678 | LDLT_MatrixElement_M | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1ed8 | LDLT_MatrixElement_N | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1e08 | LDLT_MatrixElement_O | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1e10 | LDLT_MatrixElement_P | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1d40 | LDLT_MatrixElement_Q | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1fd0 | LDLT_MatrixElement_R | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1458 | LDLT_IndexBase | dynamics | byte[] | offset | 1 | Index array base for LDL^T solver — accessed with multiple offsets |
| DAT_008d18c8 | LDLT_MatrixElement_S | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1c90 | LDLT_MatrixElement_T | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d18e0 | LDLT_WorkspaceIndex | dynamics | byte[] | offset | 1 | Workspace index array in LDL^T solver — accessed with offset pattern |
| DAT_008d2008 | LDLT_MatrixElement_U | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1f40 | LDLT_MatrixElement_V | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d1f58 | LDLT_MatrixElement_W | dynamics | double | read | 1 | Double-precision matrix input element in LDL^T solver |
| DAT_008d21c8 | Cholesky_WorkspaceBase | dynamics | byte[] | write | 1 | LDL^T/Cholesky factorization solver workspace — sub_575BBD (13KB), second solver in dynamics pipeline |
| DAT_008d2508 | Cholesky_IndexArray | dynamics | byte[] | offset | 1 | Index array base for Cholesky factorization — accessed with offset pattern |
| DAT_008d3bc8 | Cholesky_WorkOffset | dynamics | int | offset | 1 | Cholesky solver workspace integer field |
| DAT_008d3bac | Cholesky_WorkOffset2 | dynamics | int | offset | 1 | Cholesky solver workspace integer field |
| DAT_008d3190 | Cholesky_WorkBlock | dynamics | byte[] | offset | 1 | Cholesky solver workspace block |
| DAT_008d3be8 | Cholesky_WorkOffset3 | dynamics | int | offset | 1 | Cholesky solver workspace integer field |
| DAT_005ba9d0 | VTable_ObjectWithSEH | runtime | ptr | offset | 1 | Vtable/typeinfo structure for C++ class with SEH — stores `&PTR_FUN_005b8b3c` in param_1[0x250], initializes large struct with exception handler table (FUN_0057ba10, 606 bytes) |
| DAT_005e5470 | NetworkResetString | network | char* | read | 1 | "Network Reset" — network status/error message |
| DAT_005e5c9c | WSAErrorString | network | char* | read | 1 | "The specified procedure..." — Windows Sockets error string |
| DAT_005e62b0 | WSAENOTSOCKString | network | char* | read | 1 | "WSAENOTSOCK" — socket error code name string |
| DAT_005bace4 | VTable_NestedSEH | runtime | ptr | offset | 1 | Vtable pointer for nested SEH handler C++ class — stores `&PTR_FUN_005b8b3c` into `*param_1` (84-byte constructor) |
| DAT_005bb130 | VTable_HandleManager | runtime | ptr | offset | 1 | Vtable for handle-managing class (threads/events) — stores `&PTR_LAB_005b8b60`; destructor closes kernel handles, iterates linked list (FUN_00583ae0, 602 bytes) |
| DAT_008d3e39 | CodePtr_CallbackTarget | runtime | ptr | offset | 1 | Code pointer / callback target address used in runtime dispatch |
| DAT_008d3e4c | Timezone_DSTConstant | runtime | word | read | 1 | Daylight saving time / timezone formatting constant — passed to FUN_0058cc00 for timezone string parsing (timezone names like "C" for Central) |
| DAT_005be3e4 | Atexit_HandlerPair | runtime | ptr | offset | 1 | Atexit-style cleanup handler function pointer pair — registered with FUN_00589d7d for process shutdown |
| DAT_005b8d18 | SEH_MemoryAllocator | memory | ptr | offset | 1 | SEH exception handler scope table for custom memory allocator — stored as exception cookie in FUN_0058b5d4 (781 bytes) |
| DAT_005e6cb4 | CriticalSectionPtr | runtime | ptr | offset | 1 | Critical section pointer — passed to `InitializeCriticalSection` for thread synchronization |
| DAT_008d3f3c | MemPool_AllocFlag | memory | int | read | 1 | Memory pool allocation strategy flag — when non-zero, allocates new block and links into free list; when zero, reuses existing head (sub_58F6FE, 203 bytes) |
| DAT_005e6d78 | UnidentifiedDataBlock | misc | byte[] | offset | 1 | Unidentified data block |
| DAT_005b9620 | Timezone_TZString | runtime | char* | read | 1 | "tz" — timezone environment variable name string read for TZ initialization |
| DAT_008d4014 | Timezone_DSTTransition | runtime | word | read | 1 | Daylight saving time transition data — packed multi-field (word at 0x4014, 0x4016, 0x4018, 0x401a) passed to timezone transition check function |
| DAT_005b98e0 | MicrosoftVisualString | runtime | char* | read | 1 | "Microsoft Visual..." — CRT/compiler identification string |
| DAT_008d41d8 | CRT_LocaleData | runtime | int | read | 1 | C runtime locale data — referenced by CRT locale function |
| DAT_005b9b88 | SEH_LocaleCompare | runtime | ptr | offset | 1 | SEH exception handler scope table for locale-aware string comparison (Unicode vs ANSI CompareString) |
| DAT_005b9d00 | IOStreamFailbitString | runtime | char* | read | 1 | "ios::failbit set" — C++ iostream error string (MSVC STL) |
| DAT_005bb900 | RTTI_LogicError | runtime | ptr | offset | 1 | C++ RTTI typeinfo descriptor for `std::logic_error` — thrown by __CxxThrowException in error path |
| DAT_005c7528 | UninitializedData | misc | int | write | 1 | Possibly uninitialized/written data — reference from 0x008d8000 (data section, not code) |
