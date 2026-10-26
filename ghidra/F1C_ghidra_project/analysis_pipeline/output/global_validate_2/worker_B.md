=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_008ad3f8 | SlotTableBase | collision | ptr | offset | 3 | ALREADY IN docs/12 (line 1535). Struct base for collision slot table. FUN_004e19d0 iterates 4 slots at stride 0x128. FUN_004ea010 allocates from table (max 0x20=32 slots). FUN_004e2230 iterates slots comparing against pointers at DAT_008ad3ec. |
| DAT_005be5ec | NumberWaypointField | setup/ai | string offset | offset | 1 | "NumberWaypoint" - INI field name string constant for AI waypoint count in track layout config files. Referenced by FUN_00402690. |
| DAT_008aff80 | WaypointDistArray | ai/dynamics | float[14] | write | 1 | Array of 14 float waypoint distance thresholds written by FUN_00402690. Range DAT_008aff80–DAT_008affb8 (0x38=56 bytes = 14 floats). Probably segment distances along track centerline. Referenced in docs/02. |
| DAT_005be468 | WpWidthField | setup/ai | string offset | offset | 1 | "WpWidth" - INI field name for waypoint width parameter. Referenced by FUN_00402690. |
| DAT_005be8d0 | RightOfPitsField | setup | string offset | offset | 1 | "RightOfPits" - INI field name for pit lane side configuration. Referenced by FUN_00408870. |
| DAT_005beaf8 | CameraSelectField | setup/UI | string offset | offset | 1 | "CameraSelect" - INI field name for camera selection configuration. Referenced by FUN_0040d4c0. |
| DAT_005be9e4 | GreetingField | setup/UI | string offset | offset | 1 | "Greeting" - INI field name or string resource identifier. Referenced by FUN_0040d4c0. |
| DAT_005beb68 | WingField | setup/vehicle | string offset | offset | 1 | "Wing" - INI field name for wing/Setup configuration. Referenced by FUN_0040fe50. |
| DAT_005bf9a8 | DriverDataTableSpacing | ai/driver | int | read | 1 | Stride/spacing offset from DriverDataTable base (DAT_005bf9b0). Accessed as `&DAT_005bf9a0 + param_2 * 0x14`. Used by FUN_004144f0 to retrieve default time values indexed by driver ID. |
| DAT_005c259c | RubensBField | setup/driver | string offset | offset | 1 | "Rubens B" - Driver name string constant. Referenced by FUN_00415d90. |
| DAT_005c24d0 | JensonBField | setup/driver | string offset | offset | 1 | "Jenson B" - Driver name string constant. Referenced by FUN_00415d90. |
| DAT_0059e7f4 | ScoringComparisonConst | game/scoring | float | read | 1 | Scoring comparison constant used in FUN_00418ee0 for team-ID-based scoring logic. Compared against DAT_0059e43c to compute scoring thresholds: `(DAT_0059e43c - DAT_0059e7f4) * (float)count`. |
| DAT_005c28d8 | Ferrari2000Field | setup/vehicle | string offset | offset | 1 | "2000 Ferrari" - Vehicle/chassis name string constant. Referenced by FUN_0041b980. |
| DAT_005c27c8 | Bar2002Field | setup/vehicle | string offset | offset | 1 | "2002 Bar" - Vehicle/chassis name string constant. Referenced by FUN_0041b980. |
| DAT_005c2a2c | MoviesField | setup/UI | string offset | offset | 1 | "Movies" - INI section/field name for movie playback configuration. Referenced by FUN_004216f0. |
| DAT_005c2c80 | OptionsFlagsField | setup/UI | string offset | offset | 1 | "OptionsFlags" - INI field name for options flags configuration. Referenced by FUN_00421cd0. |
| DAT_005c2b84 | VideoModeField | setup/UI | string offset | offset | 1 | "VideoMode" - INI field name for video mode configuration. Referenced by FUN_00421cd0. |
| DAT_005c2ffc | SoundDirField | setup/audio | string offset | offset | 1 | "SoundDir %s" - INI field name for sound directory path. Referenced by FUN_00422be0. |
| DAT_005c2eac | TexDetailField | setup/renderer | string offset | offset | 1 | "TexDetail %d" - INI field name for texture detail level. Referenced by FUN_00422be0. |
| DAT_005c3070 | ByteConfig5C3070 | unknown | byte | read | 1 | Single-byte configuration value read by FUN_004230c0. Purpose unclear — likely a flag byte from config parsing. |
| DAT_005c31c4 | CrashField | setup/UI | string offset | offset | 1 | "Crash" - INI field name for crash/replay configuration. Referenced by FUN_00424080. |
| DAT_0059e8b0 | AIOvertakeDistThreshold | ai/dynamics | float | read | 1 | Distance threshold for AI overtaking evaluation in FUN_00425920. Used in comparison: `fVar12 * DAT_0059e8c8` checks if target ahead is reachable. Also compared against `DAT_0059e8c4` (speed threshold). |
| DAT_007cec18 | ByteFlag7CEC18 | session | byte | read | 1 | Byte flag read in FUN_0042b0e0 (race steward logic). Checked in context of session type comparison and scoring gate. Likely a session configuration flag. |
| DAT_005c33fc | AutoShiftingField | setup/vehicle | string offset | offset | 1 | "AutoShifting" - INI field name for automatic transmission setting. Referenced by FUN_0042c440. |
| DAT_007c934c | ZeroedBlock7C934C | game | int[10] | write | 1 | Part of a block of 10 ints (DAT_007c932c–007c9358) zeroed every 10th frame in FUN_0042c690. Reset alongside vehicle update loop. Likely accumulator or counter block. |
| DAT_005c34c8 | RaceField | setup/UI | string offset | offset | 1 | "Race" - INI section/field name for race settings. Referenced by FUN_0042ce30. |
| DAT_005c371c | RearSpoilerAngleField | setup/vehicle | string offset | offset | 1 | "RearSpoilerAng" - INI field name for rear spoiler angle setting. Referenced by FUN_0042e530. |
| DAT_005c3ed0 | GeneralField | setup/vehicle | string offset | offset | 1 | "General" - INI section name for general vehicle setup parameters. Referenced by FUN_0042fd00. |
| DAT_005c3d68 | RadiatorSettingField | setup/vehicle | string offset | offset | 1 | "RadiatorSetting" - INI field name for radiator setting. Referenced by FUN_0042fd00. |
| DAT_005c3b58 | Rear3rdFastBumpField | setup/vehicle | string offset | offset | 1 | "Rear3rdFastBump" - INI field name for rear third spring fast bump setting. Referenced by FUN_0042fd00. |
| DAT_005c3994 | FrontLeftField | setup/vehicle | string offset | offset | 1 | "FrontLeft" - INI field name for front-left wheel setup. Referenced by FUN_0042fd00. |
| DAT_005c3830 | CustomDField | setup/vehicle | string offset | offset | 1 | "Custom D" - INI field name for custom setup parameter D. Referenced by FUN_0042fd00. |
| DAT_005c5670 | SteerLeftField | setup/input | string offset | offset | 1 | "SteerLeft" - INI field for steering left axis binding. Referenced by FUN_00455290. |
| DAT_005c5558 | RpmLimiterField | setup/vehicle | string offset | offset | 1 | "RpmLimiter" - INI field for RPM limiter setting. Referenced by FUN_00455290. |
| DAT_005c5990 | SlocalcamSField | setup/camera | string offset | offset | 1 | "SlocalcamS" - INI field for local camera position string format. Referenced by FUN_00456670. |
| DAT_005c5b00 | STrackingrateFField | setup/camera | string offset | offset | 1 | "STrackingrateF" - INI field for camera tracking rate format string. Referenced by FUN_00458a60. |
| DAT_005c5b9c | GdbField | setup/track | string offset | offset | 1 | ".GDB" - File extension string for track database files. Referenced by FUN_0045c240. |
| DAT_005c5d6c | NextTrackField | setup/session | string offset | offset | 1 | "NextTrack" - INI field for next track identifier. Referenced by FUN_0045d890. |
| DAT_005c5df4 | Autochat09Field | setup/network | string offset | offset | 1 | "Autochat09" - INI field for auto-chat message 09. Referenced by FUN_0045ecd0. |
| DAT_005c6098 | MarkingSlotDAsField | setup/network | string offset | offset | 1 | "MarkingSlot DAs" - Network debug/status string. Referenced by FUN_00460cb0. |
| DAT_005c3f70 | Off5C3F70 | setup | ptr offset | offset | 1 | Pointer table entry referenced by FUN_00431aa0. Likely vtable or function pointer table. |
| DAT_005c4120 | HeadInertiaField | setup/vehicle | string offset | offset | 1 | "HeadInertia" - INI field name for head inertia (FFB/controller) setting. Referenced by FUN_00435410. |
| DAT_0059eb90 | EngineSweptVolumeConst | physics/engine | double | read | 1 | Engine swept volume/cyl constant in FUN_00438130 (engine physics model). Multiplied against displacement +0x314: `*(double*)(param_1 + 0x314) * DAT_0059eb90`. Clamped between DAT_0059e428 and DAT_0059e420 (1.0). Used with DAT_0059eb88 (companion constant). |
| DAT_0059ec00 | DamperCoefficientB | physics/dynamics | double | read | 1 | Secondary damper coefficient in FUN_00439210. Part of suspension damping model. |
| DAT_0059ec38 | AntiRollRateConst | physics/dynamics | double | read | 1 | Anti-roll bar rate constant used in FUN_0043c250 (anti-roll dynamics). |
| DAT_0059eca0 | TorqueDissipationMult | physics/engine | double | read | 1 | Torque dissipation multiplier in FUN_0043ef20 (engine torque/physics model). Used in energy dissipation chain with DAT_0059ea60, DAT_0059ed00. Applied as `dVar3 * DAT_0059ed00` in torque reduction calculation. |
| DAT_007cc1dc | PhysicsStateFlag | physics/dynamics | int | read | 1 | State flag read in FUN_004441f0 (9101-byte physics/dynamics solver). Flags branch selection in large constraint solver function. |
| DAT_0059ee48 | ConstraintSolverConst | physics/dynamics | double | read | 1 | Dynamics solver constant in FUN_004441f0. Double precision coefficient used in constraint force computations. |
| DAT_007c7810 | ContactSurfaceArray | collision | struct[4] | offset | 1 | Array of 4 contact surface parameter structs at stride 0x128 (4 * 0x4a * 4 = 0x128). Used in FUN_004472b0 for tire-terrain contact response. Each struct contains double-precision surface stiffness/ damping parameters at offsets -8, -4, and pointer at +0x42*4. |
| DAT_005c449c | HatField | setup/renderer | string offset | offset | 1 | "Hat" - INI field/string for driver helmet/hat texture config. Referenced by FUN_0044c0e0. |
| DAT_007ccfa8 | FloatBF800000 | collision | float | write | 1 | Initialized to 0xBF800000 (-1.0f) in FUN_0044d1c0. Part of collision globals init block (DAT_007ccfa0=0x6d, cfa4=0, cfa8=-1.0f, cfac=0). Collision sentinel value. |
| DAT_007ccd00 | ZeroedCollisionState | collision | int[2] | write | 1 | Zero-initialized collision state fields in FUN_0044d460. Part of collision init block (DAT_007cccf0=0xf, ccf4=0, ccf8=0, ccfc=0, ccd00=0, ccd04=0). |
| DAT_005b108c | D3DTextureFormatDesc | renderer | struct | offset | 1 | DirectX texture format descriptor referenced in FUN_0044fa60 (D3D renderer setup). Passed to virtual function at vtable+0x2c for texture surface creation. |
| DAT_005ad380 | UIWidgetState | UI | struct | read | 1 | UI widget state reference in FUN_0044ff50 (audio mixer/UI), checked in audio mixer context. |
| DAT_005ad3ac | AudioMixerConfig | audio | struct | read | 1 | Audio mixer configuration data read by FUN_0044ff50 (audio mixing engine). Contains gain curve/sample rate tables. |
| DAT_007cd1f8 | AudioSourceHandle | audio | float | read | 1 | Audio source volume/reference value read in FUN_00451720 (audio system). Compared in audio processing branches. |
| DAT_007cd118 | AudioFilterParam | audio | ptr | read | 1 | Audio filter parameter block pointer. Used in FUN_00452b10 for audio effect/filter assignment in audio graph. References many audio buffer pointers (DAT_007ccd50, ccd38, ccf0, ccd8, ccd20, ccd08, ccc80, etc.). |
| DAT_007ccf58 | CollisionStateInitBlock | collision | struct | write | 1 | Initialization data block in FUN_004537b0 (2590-byte collision/audio state init). Written with float values from vehicle physics parameters at offsets +0x1140..0x1158. Stores bounds/thresholds paired with companion globals for min-clamp. Partners: DAT_007ca494/498, ca3ec/3f0, cd19c/1a0, ccbb4/8, etc. |
| DAT_007ca484 | CollisionStateFloat | collision | float | write | 1 | Float state written in FUN_004537b0 collision init. Part of paired threshold globals with DAT_007ca494/498, ca3ec/3f0 patterns. |
| DAT_007ccc04 | KeyboardLayoutInitGate | input | byte | read/write | 1 | Bit 0 gates keyboard layout initialization in FUN_00455b30. Set to 1 after GetKeyboardLayout is called. Companion flag for keyboard input processing. |
| DAT_007cf044 | Flag7CF044 | setup/session | int | read | 1 | Read in FUN_00461900 session parameter loading. Used with DAT_007cf038 to store session configuration flags. Part of INI parameter loading chain. |
| DAT_007cef48 | PenaltyTimeThreshold | steward | int | read | 1 | Penalty time threshold read in FUN_00461900. Used in steward/penalty configuration loading. |
| DAT_005c6230 | JoinTimedOutField | setup/network | string offset | offset | 1 | "JoinTimedOut" - String for join timeout message. Referenced by FUN_00462da0. |
| DAT_005c6360 | NetCommSetNetworkField | setup/network | string offset | offset | 1 | "NetComm SetNetwork" - String/INI field for network config. Referenced by FUN_00463160. |
| DAT_007d0e9c | MessageBuffer7D0E9C | network/UI | int | read | 1 | Message/state buffer read in FUN_00463f70 (NetComm network message processing). Part of session join handshake. |
| DAT_007cff30 | ExperienceLapsResetFlag | game/save | byte | write | 1 | Reset flag for experience/laps data in FUN_00468a00 (career stats reset). Zeroed at function entry, then conditionally set from DAT_007cff32. Called when resetting career statistics (experience, starts, wins, points, etc.). |
| DAT_005c6a70 | DS4Field | setup/ai | string offset | offset | 1 | "DS_4" - INI field name for driver strength level 4. Referenced by FUN_0046b5f0. |
| DAT_005c6c8c | MaxPlayersField | setup/network | string offset | offset | 1 | "MaxPlayers %d" - INI field name for maximum players. Referenced by FUN_0046de10. |
| DAT_005ec3f8 | FontIconPathPtr | UI/renderer | char* | read | 1 | Font/icon resource path pointer in FUN_00477cb0. Points to directory containing ProfileIcon DFT.bmp and similar UI resources. If NULL, falls back to DAT_005ea438 default path. |
| DAT_005c7340 | ReverseScanField | setup/renderer | string offset | offset | 1 | "ReverseScan" - INI field for reverse-scan video mode. Referenced by FUN_0047daf0. |
| DAT_005c7430 | FoundedField | setup/UI | string offset | offset | 1 | "Founded" - INI field for team founded year/string. Referenced by FUN_0047e0a0. |
| DAT_005abcd0 | TrackSceneVTable | track/renderer | ptr | offset | 1 | VTable/interface pointer for track scene object. Written to param_1[0] in FUN_00488f90 (track scene constructor). Class type with virtual methods. |
| DAT_005cc550 | TooltipColorEdField | setup/UI | string offset | offset | 1 | "TooltipColorEd" - INI field for tooltip text color (editable). Referenced by FUN_00492160. |
| DAT_005cc6c4 | ActionsField | setup/UI | string offset | offset | 1 | "Actions" - INI section/field for UI action bindings. Referenced by FUN_00492a40. |
| DAT_005cc844 | ClickField | setup/UI | string offset | offset | 1 | "Click" - INI field for click sound/action. Referenced by FUN_00493480. |
| DAT_005ac830 | UIFuncTable5AC830 | UI | ptr table | offset | 1 | UI function pointer table. Referenced by FUN_00493fc0. Likely vtable or callback table for UI widget. |
| DAT_005cca78 | SpecifiedSystemField | setup/UI | string offset | offset | 1 | "Specified System" - Error/warning message string. Referenced by FUN_00498440. |
| DAT_007c9158 | TeamMateRaceFlag | game/scoring | int | read | 1 | Team-mate-in-race flag read in FUN_0049b7a0. When non-zero AND player and target share team ID, enables driver matching logic for qualifying/race mode. Controls bitmask return values (1,2,4,8,0xf) for driver classification. |
| DAT_005ccbf8 | Off5CCBF8 | unknown | ptr | read | 1 | Pointer read by FUN_0049c8f0. Purpose unclear — likely vtable or data table. |
| DAT_005ccb60 | Off5CCB60 | unknown | ptr | read | 1 | Pointer read by FUN_0049ca00. Companion to DAT_005ccbf8. |
| DAT_007ce248 | SessionStewardState | steward | int | read | 1 | Session steward state read in FUN_0049f070 (race steward update). Part of scoring/steward processing pipeline. |
| DAT_005cd02c | BikField | setup/UI | string offset | offset | 1 | "Bik" - INI field for Bink video file playback configuration. Referenced by FUN_004a09f0. |
| DAT_007ce2a8 | SessionInitStruct | session | struct | write | 1 | Session initialization structure written in FUN_004a1200. Part of session setup during steward initialization. |
| DAT_005cd31c | FrontJackDownField | setup/pit | string offset | offset | 1 | "FrontJackDown" - Pit crew animation/event string. Referenced by FUN_004a24d0. |
| DAT_005cd1e8 | TenSecSman3Field | setup/pit | string offset | offset | 1 | "10secSman3" - Pit crew command/string (10-second signal). Referenced by FUN_004a24d0. |
| DAT_005cd38c | MoveField | setup/pit | string offset | offset | 1 | "Move" - Pit crew command string. Referenced by FUN_004a2a90. |
| DAT_005cd4d4 | StopGoField | setup/pit | string offset | offset | 1 | "StopGo" - Penalty command string (stop-go penalty). Referenced by FUN_004a47e0. |
| DAT_005cd664 | NoChangeField | setup/pit | string offset | offset | 1 | "NoChange" - Pit stop strategy string (no tire change). Referenced by FUN_004a58b0. |
| DAT_005acb84 | ControlBindingVTable | UI/input | ptr | offset | 1 | VTable pointer for control binding widget class. Written to param_1[0x46] in FUN_004a70e0 (control config UI constructor). Sets up virtual dispatch for UI control binding list with multiple paired entry fields (+0x49, +0x50, +0x57, +0x5e, +0x61, +0x68, +0x6f, +0x76, +0x7d, +0x80, +0x89, +0x92, +0x9b, +0xa7). |
| DAT_005d1f48 | SteeringHelpFuncField | setup/vehicle | string offset | offset | 1 | "SteeringHelpFunc" - INI field for steering assistance function. Referenced by FUN_004aa270 (control config UI). |
| DAT_005d1cb0 | ManualShiftOverField | setup/vehicle | string offset | offset | 1 | "ManualShiftOver" - INI field for manual shift override. Referenced by FUN_004aa270. |
| DAT_005d19f4 | FailureRateField | setup/vehicle | string offset | offset | 1 | "FailureRate" - INI field for mechanical failure rate. Referenced by FUN_004aa270. |
| DAT_005d176c | FormationLapField | setup/session | string offset | offset | 1 | "FormationLap" - INI field for formation lap setting. Referenced by FUN_004aa270. |
| DAT_005d157c | TractionControlField | setup/vehicle | string offset | offset | 1 | "TractionControl" - INI field for traction control setting. Referenced by FUN_004aa270. |
| DAT_005d1388 | PublicAddressRateField | setup/audio | string offset | offset | 1 | "PublicAddressRate" - INI field for public address system rate. Referenced by FUN_004aa270. |
| DAT_005d11dc | BackfireAnimSpeedField | setup/renderer | string offset | offset | 1 | "BackfireAnimSpeed" - INI field for backfire animation speed. Referenced by FUN_004aa270. |
| DAT_005d0fa8 | WhetherToRollTheField | setup/vehicle | string offset | offset | 1 | "WhetherToRollThe" - INI field (likely rollbar/anti-roll). Referenced by FUN_004aa270. |
| DAT_005d0cd0 | AngleToLookUpDownField | setup/camera | string offset | offset | 1 | "AngleToLookUpDown" - INI field for camera look angle. Referenced by FUN_004aa270. |
| DAT_005d0a30 | MaxVisibleVehiclesField | setup/renderer | string offset | offset | 1 | "MaxVisibleVehicles" - INI field for max visible cars. Referenced by FUN_004aa270. |
| DAT_005d0830 | IconsDisplayedField | setup/UI | string offset | offset | 1 | "IconsDisplayed" - INI field for UI icon display config. Referenced by FUN_004aa270. |
| DAT_005d0580 | PrivateTestDayField | setup/session | string offset | offset | 1 | "PrivateTestDay" - INI field for private test day setting. Referenced by FUN_004aa270. |
| DAT_005d02ac | PlayerCarEqualField | setup/session | string offset | offset | 1 | "PlayerCarEqual" - INI field for equal performance option. Referenced by FUN_004aa270. |
| DAT_005d0014 | MeasurementUnitField | setup/UI | string offset | offset | 1 | "MeasurementUnit" - INI field for metric/imperial unit. Referenced by FUN_004aa270. |
| DAT_005cfdd4 | FinesField | setup/steward | string offset | offset | 1 | "Fines" - INI field for penalty fines setting. Referenced by FUN_004aa270. |
| DAT_005cfa64 | NetFlushThreshField | setup/network | string offset | offset | 1 | "NetFlushThresh" - INI field for network flush threshold. Referenced by FUN_004aa270. |
| DAT_005cf638 | IfTrueTheSessionField | setup/session | string offset | offset | 1 | "IfTrueTheSession" - INI field description string. Referenced by FUN_004aa270. |
| DAT_005cf248 | BonespringTmCoField | setup/FFB | string offset | offset | 1 | "BonespringTmCo" - INI field for FFB bone spring coefficient. Referenced by FUN_004aa270. |
| DAT_005cef60 | EnableThisOptionField | setup/UI | string offset | offset | 1 | "EnableThisOption" - INI field for option enable toggle. Referenced by FUN_004aa270. |
| DAT_005cebcc | Controller1RxField | setup/input | string offset | offset | 1 | "Controller1Rx" - INI field for controller 1 RX axis. Referenced by FUN_004aa270. |
| DAT_005ce9f8 | ControlNeutralField | setup/input | string offset | offset | 1 | "ControlNeutral" - INI field for control neutral position. Referenced by FUN_004aa270. |
| DAT_005ce818 | ControlBiasRearField | setup/vehicle | string offset | offset | 1 | "ControlBiasRear" - INI field for rear brake bias. Referenced by FUN_004aa270. |
| DAT_005ce5e8 | NumberOfFfbEffectsField | setup/FFB | string offset | offset | 1 | "NumberOfFfbEff" - INI field for FFB effect count. Referenced by FUN_004aa270. |
| DAT_005ce130 | Recommended115Field | setup/FFB | string offset | offset | 1 | "Recommended115" - INI field description. Referenced by FUN_004aa270. |
| DAT_005cdcc0 | SlopeOfLineDefField | setup/FFB | string offset | offset | 1 | "SlopeOfLineDef" - INI field for FFB slope definition. Referenced by FUN_004aa270. |
| DAT_005cd8f4 | FfbRumbleStripField | setup/FFB | string offset | offset | 1 | "FfbRumbleStrip" - INI field for rumble strip FFB effect. Referenced by FUN_004aa270. |
| DAT_005d2334 | EnteredPlayerField | setup/UI | string offset | offset | 1 | "EnteredPlayerf" - INI field for player entry string. Referenced by FUN_004b1820. |
| DAT_005accc0 | QuantizationLowerBound | renderer | float | read | 1 | Lower bound for 16-bit signed quantization in FUN_004b2840 (vertex processing). Compared against param_4 (value): if value < bound, encodes as 0x8001. Part of clamp pair with DAT_005accc4 (upper bound). |
| DAT_005acd08 | CameraModelVTable | camera/renderer | ptr | read | 1 | VTable pointer written to param_1[0x3dd] in FUN_004b57f0 (camera/renderer object constructor). Class type with virtual dispatch for camera model. |
| DAT_005d24dc | DDevF119992002String | setup/debug | string offset | offset | 1 | "DDevF119992002" - Debug/assert module name string. Referenced by FUN_004ba1f0. |
| DAT_005acd74 | Float5ACD74 | physics | float | read | 1 | Float constant read by FUN_004bc9b0. Purpose unclear — likely physics coefficient. |
| DAT_005acdd0 | Double5ACDD0 | physics | double | read | 1 | Double constant used in FUN_004bea10 (248-byte force computation). Multiplied in tire/force calculation: `fVar3 * fVar2 * DAT_005acdb4 * param_2 - DAT_0059e7f8 + param_2`. Part of anti-roll mixing with DAT_0059e7f8 (AntiRollMixingFactor). |
| DAT_005d26e8 | FinishPointsField | setup/scoring | string offset | offset | 1 | "FinishPoints" - INI field for points awarded per finish position. Referenced by FUN_004c03f0. |
| DAT_005d2830 | RaceSessionField | setup/session | string offset | offset | 1 | "RaceSession" - INI section/field for race session config. Referenced by FUN_004c0b70. |
| DAT_005d2dfc | TotalWinsField | setup/UI | string offset | offset | 1 | "TotalWins %d" - INI field for total wins display. Referenced by FUN_004c2420. |
| DAT_005d2b94 | GameoptTireMulField | setup/game | string offset | offset | 1 | "GameoptTireMul" - INI field for tire multiplier game option. Referenced by FUN_004c2420. |
| DAT_005d2f98 | ManufacturerField | setup/scoring | string offset | offset | 1 | "Manufacturer" - INI field for manufacturer name. Referenced by FUN_004c3200. |
| DAT_005d307c | FailedReadingField | setup/error | string offset | offset | 1 | "FailedReadingD" - Error message string for file read failure. Referenced by FUN_004c3d80. |
| DAT_005d325c | Off5D325C | setup/UI | ptr | write | 1 | Pointer/offset written by FUN_004c83b0. Likely UI resource handle. |
| DAT_007cf530 | AmbientVolumeScale | audio | float | read | 1 | Ambient sound volume scale factor in FUN_004c9840. If <= DAT_0059e440 (zero), sets fVar1 = DAT_0059e43c / DAT_007cf530. Used in audio ambient sound channel setup. |
| DAT_005d3680 | WetSkidField | setup/renderer | string offset | offset | 1 | "WetSkid" - INI field for wet skid effect. Referenced by FUN_004ca480. |
| DAT_005d3578 | FlatShadeField | setup/renderer | string offset | offset | 1 | "FlatShade" - INI field for flat shading option. Referenced by FUN_004ca480. |
| DAT_005d3498 | SrcBlendField | setup/renderer | string offset | offset | 1 | "SrcBlend" - INI field for source blend mode. Referenced by FUN_004ca480. |
| DAT_008acaa8 | TrackLightData | track/renderer | ptr | offset | 1 | Track lighting data array/struct referenced by FUN_004cb120. |
| DAT_005d3888 | SoundField | setup/audio | string offset | offset | 1 | "Sound" - INI section for sound configuration. Referenced by FUN_004cdd80. |
| DAT_005d398c | IncludeTracksField | setup/filter | string offset | offset | 1 | "IncludeTracks" - INI field for track filter inclusion. Referenced by FUN_004cf070. |
| DAT_005d3ad4 | GirlAField | setup/UI | string offset | offset | 1 | "GirlA" - INI field (likely driver model/graphics option). Referenced by FUN_004d0110. |
| DAT_005c713c | GameNameField | setup/game | string offset | offset | 1 | "GameName" - INI field for game name string. Referenced by FUN_004d1450. |
| DAT_005d40b0 | QualifyLapsField | setup/session | string offset | offset | 1 | "QualifyLaps %d" - INI field for qualifying lap count. Referenced by FUN_004d24d0. |
| DAT_005d3ea0 | DriveaidsAutoBField | setup/vehicle | string offset | offset | 1 | "DriveaidsAutoB" - INI field for driving aids auto setting. Referenced by FUN_004d24d0. |
| DAT_005d3d18 | RacePlaceField | setup/scoring | string offset | offset | 1 | "RacePlace %d" - INI field for race position. Referenced by FUN_004d24d0. |
| DAT_005d42f4 | EnteredStewardField | setup/steward | string offset | offset | 1 | "EnteredSteward" - INI field for steward entry. Referenced by FUN_004d38f0. |
| DAT_005d4384 | Dword5D4384 | unknown | int | read | 1 | Integer read by FUN_004d3cf0. Purpose unclear. |
| DAT_007cea34 | PitCrewLHSFlag | pit | int | read | 1 | Pit crew left-hand-side flag read in FUN_004d4a80. Controls pit crew positioning side. |
| DAT_005d44cc | FrField | setup/vehicle | string offset | offset | 1 | "Fr" - INI field prefix (front right). Referenced by FUN_004d4a80. |
| DAT_007c749a | OptionFlagArray | setup/session | byte[11] | read | 1 | Array of 11 option flag bytes read in FUN_004d59b0 (session data serialization). Indexed 0-10, packed into a bitfield for session checksum/hash computation. Flags include EngineWearMode (DAT_007cea5c), TireModelMode (DAT_007ce958), ShiftMode, ABS, TractionControl, etc. |
| DAT_005d4804 | LoadSensField | setup/vehicle | string offset | offset | 1 | "LoadSens" - INI field for load sensitivity (tire model). Referenced by FUN_004d6b00. |
| DAT_005d4944 | SlipCurveField | setup/vehicle | string offset | offset | 1 | "SlipCurve" - INI field for tire slip curve. Referenced by FUN_004d7150. |
| DAT_005d4ac0 | BroadcastDisplayField | setup/network | string offset | offset | 1 | "BroadcastDisplay" - INI field for broadcast display config. Referenced by FUN_004d8450. |
| DAT_005d4af8 | VenueNamePtr | UI | ptr | read | 1 | Pointer to "VenueName" string. Used in FUN_004d99e0 (UI venue/track name display). Checked via FUN_005679c0, paired with DAT_005d4afc ("TrackName"). |
| DAT_005d4c08 | ByteFontData | UI/renderer | byte | read | 1 | Font/byte data read by FUN_004dd030 (UI text rendering). Used in text layout processing. |
| DAT_005c6808 | Asc5C6808 | setup | string offset | offset | 1 | ASCII string constant. Referenced by FUN_004ddf90. |
| DAT_005d4dcc | LfSpindleField | setup/vehicle | string offset | offset | 1 | "LfSpindle" - INI field for left front spindle. Referenced by FUN_004dfce0. |
| DAT_005d4d2c | TreadField | setup/vehicle | string offset | offset | 1 | "Tread" - INI field for tire tread width. Referenced by FUN_004dfce0. |
| DAT_007c920c | VehiclePhysicsState | physics/vehicle | double | read | 1 | Double-precision physics state value in FUN_004e49b0 (vehicle dynamics integration). Used in coordinate transform and position update chain. Read alongside many vehicle struct offsets (+0x34d4, +0x34d8, +0x34dc, etc.). |
| DAT_005ad1e8 | BrakeFluidMult | physics/brake | float | read | 1 | Brake fluid pressure multiplier in FUN_004eb430 (2029-byte brake/physics function). Gates brake force computation in vehicle dynamics update. |
| DAT_007c9138 | FuelConsumptionMult | physics/engine | double | read | 1 | Fuel consumption multiplier in FUN_004f12e0 (engine model). Double precision constant used in fuel burn rate computation alongside vehicle struct offsets (+0x3668, gear system). |
| DAT_005d4f84 | FrontWingCollpField | setup/vehicle | string offset | offset | 1 | "FrontWingCollp" - INI field for front wing collision property. Referenced by FUN_004f24f0. |
| DAT_005d52a8 | BumpStopDamperField | setup/vehicle | string offset | offset | 1 | "BumpStopDamper" - INI field for bump stop damper setting. Referenced by FUN_004f2c60. |
| DAT_005d516c | PressureSettingField | setup/vehicle | string offset | offset | 1 | "PressureSetting" - INI field for tire pressure setting. Referenced by FUN_004f2c60. |
| DAT_005d535c | FenderCenterField | setup/vehicle | string offset | offset | 1 | "FenderCenter" - INI field for fender center position. Referenced by FUN_004f3090. |
| DAT_005d570c | EngineInertiaField | setup/vehicle | string offset | offset | 1 | "EngineInertia" - INI field for engine inertia. Referenced by FUN_004f3c80. |
| DAT_005d5588 | CombustionHeatField | setup/vehicle | string offset | offset | 1 | "CombustionHeat" - INI field for combustion heat. Referenced by FUN_004f3c80. |
| DAT_005d66cc | CGHeightField | setup/vehicle | string offset | offset | 1 | "CGHeight" - INI field for center of gravity height. Referenced by FUN_004f4270. |
| DAT_005d6594 | NotesField | setup/vehicle | string offset | offset | 1 | "Notes" - INI field for vehicle setup notes. Referenced by FUN_004f4270. |
| DAT_005d6464 | FrontWingField | setup/vehicle | string offset | offset | 1 | "FrontWing" - INI field for front wing setting. Referenced by FUN_004f4270. |
| DAT_005d6374 | RwLiftParamsField | setup/vehicle | string offset | offset | 1 | "RwLiftParams" - INI field for rear wing lift parameters. Referenced by FUN_004f4270. |
| DAT_005d628c | BodyDownField | setup/vehicle | string offset | offset | 1 | "BodyDown" - INI field for body downforce. Referenced by FUN_004f4270. |
| DAT_005d6164 | Off5D6164 | setup/vehicle | ptr offset | offset | 1 | Pointer/offset in FUN_004f4270 (setup loading). Part of vehicle config parsing. |
| DAT_005d5fc4 | Front3rdReboundField | setup/vehicle | string offset | offset | 1 | "Front3rdRebound" - INI field for third spring rebound. Referenced by FUN_004f4270. |
| DAT_005d5e08 | RightFenderFlaField | setup/vehicle | string offset | offset | 1 | "RightFenderFla" - INI field for right fender flap. Referenced by FUN_004f4270. |
| DAT_005d5c40 | Front3rdFastRebField | setup/vehicle | string offset | offset | 1 | "Front3rdFastReb" - INI field for third spring fast rebound. Referenced by FUN_004f4270. |
| DAT_005d5a98 | ABSLevelField | setup/vehicle | string offset | offset | 1 | "ABSLevel" - INI field for ABS level. Referenced by FUN_004f4270. |
| DAT_005d5958 | SemiAutomaticField | setup/vehicle | string offset | offset | 1 | "SemiAutomatic" - INI field for semi-automatic gearbox. Referenced by FUN_004f4270. |
| DAT_005d581c | DiffPumpSettingField | setup/vehicle | string offset | offset | 1 | "DiffPumpSetting" - INI field for diff pump setting. Referenced by FUN_004f4270. |
| DAT_005d58d9 | GearField | setup/vehicle | string offset | offset | 1 | "Gear%ds" - INI field format for gear ratios (1st-10th). Referenced by FUN_004f4270. |
| DAT_005d6c80 | PlayerEngineVolField | setup/audio | string offset | offset | 1 | "PlayerEngineVol" - INI field for player engine volume. Referenced by FUN_004f7460. |
| DAT_005d6b03 | AudioStringA | setup/audio | string offset | offset | 1 | Unnamed audio INI string. Referenced by FUN_004f7460. |
| DAT_005d696f | AudioStringB | setup/audio | string offset | offset | 1 | Unnamed audio INI string. Referenced by FUN_004f7460. |
| DAT_005d6d50 | LibFileName | setup/d3d | string | offset | 1 | Library file name string (D3D/DirectX DLL name). Referenced by FUN_004f8b50. |
| DAT_005d6e38 | DfLodBmpField | setup/renderer | string offset | offset | 1 | "DfLodBmp" - INI field for LOD bitmap/DF format. Referenced by FUN_004f9480. |
| DAT_005ec4b4 | Dword5EC4B4 | setup | int | read | 1 | Integer read by FUN_004fa000. Part of setup/init chain. |
| DAT_007cf914 | Float7CF914 | renderer | float | read | 1 | Float read by FUN_004fba10. Likely rendering constant. |
| DAT_005ad29c | Float5AD29C | physics | float | read | 1 | Float constant read by FUN_004fcee0. Part of physics computations. |
| DAT_005ad310 | BrakeForceAccumCoeff | physics/brake | float | read | 1 | Brake force accumulation coefficient in FUN_004fdeb0 (432-byte brake model). Used with DAT_005ad314, DAT_005ad318 for brake pressure decay computation: `fVar3 * DAT_005ad314 + param_4 * DAT_005ad318 + DAT_005ad318`. |
| DAT_005d6fc4 | CoolField | setup/vehicle | string offset | offset | 1 | "Cool" - INI field for cooling/radiator. Referenced by FUN_004fe2b0. |
| DAT_005d7078 | MinuteFormatField | setup/UI | string offset | offset | 1 | "Minute %2f" - Time display format string. Referenced by FUN_004fe820. |
| DAT_008b0094 | Dword8B0094 | physics | int | read | 1 | Integer read by FUN_00500eac (D3D/surface creation). Likely device capability flag. |
| DAT_005ad4d0 | D3DSurfaceDesc | renderer | struct | offset | 1 | D3D surface descriptor struct passed to virtual function at param_2+0x1c in FUN_00506559 (renderer surface creation). DirectX surface description. |
| DAT_005adc28 | RenderNodeVTableADC28 | renderer | ptr | offset | 1 | VTable pointer for renderer node class. Set in FUN_0050ab35 constructor: `*param_1 = &PTR_FUN_005adc28`. Type with virtual dispatch. |
| DAT_005add3c | RenderNodeVTableADD3C | renderer | ptr | offset | 1 | VTable pointer for renderer node class. Set in FUN_0050b3d1 constructor: `*param_1 = &PTR_FUN_005add3c`. Type with virtual dispatch. |
| DAT_005d780c | RenderFuncDispatch | renderer | func ptr | read | 1 | Renderer function dispatch pointer. Called via `(*(code *)PTR_FUN_005d780c)(...)` in FUN_0050c07c after FUN_0050fea7(1). Registered callback for render state setup. |
| DAT_005d783c | RenderFuncDispatch2 | renderer | func ptr | read | 1 | Second renderer function dispatch pointer. Called via `(*(code *)PTR_FUN_005d783c)(...)` in FUN_0050dc90. |
| DAT_005af2c4 | UnknownZlibErrString | zlib | string offset | offset | 1 | "Unknown Zlib Error" - zlib error message string. Referenced by FUN_005118e6. |
| DAT_005af430 | D3DDeviceFlag | renderer | double | read | 1 | D3D device capability flag (double-precision). Read in FUN_00513482 (D3D device/texture management). |
| DAT_005d79c4 | RenderSurfaceScale | renderer | float | read | 1 | Render surface scale factor in FUN_005147ea (2052-byte renderer pipeline). Part of 3D surface/vertex processing. |
| DAT_005afb50 | CrcErrorString | zlib | string offset | offset | 1 | "CRC Error" - zlib CRC error message string. Referenced by FUN_00518828. |
| DAT_005afd90 | OutOfPlaceGama | zlib | string offset | offset | 1 | "Out of place gama" - zlib decompression error string. Referenced by FUN_00518c1e. |
| DAT_005aff88 | DecompressionErrorString | zlib | string offset | offset | 1 | "Decompression Error" - zlib error message string. Referenced by FUN_00519019. |
| DAT_005d8a40 | SIMDVectorNormalizeConst | math | float/int | read | 1 | SIMD vector normalization constant in FUN_0051f160 (156-byte SSE math). Used in Newton-Raphson iteration for inverse sqrt: `1.0/fsqrt(v5)` with refinement `(DAT_005d8a40 - v5*v6*v6) * DAT_005d8a30 * v6`. Companion constant to DAT_005d8a30. |
| DAT_005d8b70 | SIMDMatrixRowConst | math | xmmword | read | 1 | SIMD constant vector (xmmword) in FUN_0051fb1e (198-byte SSE matrix/quaternion math). Used as additive term in quaternion/matrix multiplication: `_mm_add_ps(..., (__m128)xmmword_5D8B70)`. Row/component of matrix multiplication result. |
| DAT_008d6184 | SIMDLowerNormThreshold | math | float | read | 1 | Lower normalization threshold for SIMD vector normalize in FUN_0052035e (184 bytes): `if (*(float *)&dword_8D6180 <= v5)`. Paired with DAT_008d6180 (threshold), DAT_008d6188 (NR constant). If vec length^2 < threshold, zeroes result. |
| DAT_005d8c80 | SIMDMatrixXorMask | math | xmmword | read | 1 | SIMD XOR mask constant in FUN_00520a7e (380-byte SSE matrix/vector math). Applied as `_mm_xor_ps((__m128)xmmword_5D8C60, v7)` for sign bit manipulation in quaternion product. |
| DAT_008d62a0 | SIMDAddConstant | math | xmmword | read | 1 | SIMD additive constant in FUN_00520e0e (179-byte SSE math). Used in quaternion/rotation computation: `_mm_add_ps(..., _mm_xor_ps(..., (__m128)xmmword_8D62A0))`. |
| DAT_005d8f90 | SIMDColorMask | renderer/math | xmmword | read | 1 | SIMD bitmask constant in FUN_005289e0 (492-byte color/SIMD processing). Applied as `& _DAT_005d9060` mask for pixel channel extraction in both FUN_005289e0 and FUN_00528cc0 (color conversion pipeline). |
| DAT_005d9270 | SIMDColorChannelMask | renderer | xmmword | read | 1 | SIMD bitmask for color channel extraction in FUN_00528cc0 (329-byte color conversion). Applied as `& _DAT_005d9280` for per-channel bit masking. |
| DAT_005d93b4 | MMXTrigConstant | math/3dnow | float | read | 1 | MMX/3DNow! trigonometric approximation constant in FUN_00529000 (247-byte SIMD trig). Used in packed floating-point sin/cos computation with polynomial coefficients from DAT_005d935c through DAT_005d93b8 range. |
| DAT_005b0b1c | IncompleteDistanceString | audio/codec | string offset | offset | 1 | "Incomplete distance" - Audio codec (MP3/DSP) error string. Referenced by FUN_0052a4a5. |
| DAT_005b0be0 | AudioCodecStruct | audio | qword | read | 1 | Audio codec structure/magic constant read by FUN_0052ab4e (1720-byte audio codec init). |
| DAT_005da5a4 | CmpegBaseProceString | audio | string offset | offset | 1 | "CmpegBaseProce" - Audio codec debug/error string. Referenced by FUN_0052da30. |
| DAT_005da760 | AudioDecodeJumpTable | audio | ptr table | read | 1 | Audio codec jump table / lookup table in FUN_00531250 (1385-byte audio codec). Indexed by codec mode iVar8: `(&PTR_DAT_005da760)[iVar8]`. Multidimensional decode dispatch table. |
| DAT_008b5930 | DCTScaleFactor0 | audio/DSP | float | write | 1 | DCT coefficient scale factor 0 in FUN_00531b50 (3910-byte audio/DSP transform). Part of 32-element modified DCT (MDCT) coefficient array (DAT_008b5930 through DAT_008b59e0, stride 0x4c). Named coefficients: DAT_005b772c..7768, 776c. |
| DAT_008b597c | DCTScaleFactor1 | audio/DSP | float | write | 1 | DCT coefficient scale factor in FUN_00531b50. Part of MDCT coefficient array with DAT_008b5930. |
| DAT_008b59e0 | DCTScaleFactor2 | audio/DSP | float | write | 1 | DCT coefficient scale factor in FUN_00531b50. Part of MDCT coefficient array. |
| DAT_005b7788 | DCTScaleFactor3 | audio/DSP | float | read | 1 | DCT coefficient read by FUN_00531b50 for MDCT frequency transform. |
| DAT_005b77a0 | DCTScaleFactor4 | audio/DSP | float | read | 1 | DCT coefficient read by FUN_00531b50 for MDCT transform. |
| DAT_005b77ea | AudioDecodeTabSize | audio | ushort[4] | read | 1 | Audio codec decode table sizes in FUN_00536260 (145 bytes). Indexed as `&DAT_005b77ea + iVar2*0xc`, stride 12 bytes, with companion tables at DAT_005b77e8, DAT_005b77ec, DAT_005b77ee. Contains block sizes for codec frame decode. |
| DAT_005dbaa0 | IncompleteDynaString | audio | string offset | offset | 1 | "Incomplete Dyna" - Audio codec error string. Referenced by FUN_00539f70. |
| DAT_008b8dd0 | RendererInitZero | renderer | int | write | 1 | Zero-initialized renderer state flag in FUN_0053c360 (368-byte renderer init). Part of renderer initialization block zeroed alongside DAT_008b8dc4/c8/dcc. |
| DAT_005dbec0 | RefViewField | setup/renderer | string offset | offset | 1 | "RefView" - INI field for reference view mode. Referenced by FUN_00548ad0. |
| DAT_005dc054 | ErrorBinkFormatString | media | string offset | offset | 1 | "Error %s for Bink file" - Bink video error message string. Referenced by FUN_00551a50. |
| DAT_005dc20c | SeparateSurfaceField | setup/renderer | string offset | offset | 1 | "SeparateSurface" - INI field for separate render surface. Referenced by FUN_0055a060. |
| DAT_005dc308 | LightObjectField | setup/renderer | string offset | offset | 1 | "LightObject" - INI field for light object config. Referenced by FUN_0055a910. |
| DAT_005dc3d0 | Exp2Field | setup/renderer | string offset | offset | 1 | "Exp2" - INI field for exponent 2 (fog/lighting). Referenced by FUN_0055b200. |
| DAT_005dc5a4 | Word5DC5A4 | network | ushort | read | 1 | Word value read by FUN_0055f0d0 (NetComm network init). Network port or flag. |
| DAT_005dc538 | Dword5DC538 | network | int | read | 1 | Integer read by FUN_0055f0d0. Network configuration constant. |
| DAT_005dc4f0 | Dword5DC4F0 | network | int | read | 1 | Integer read by FUN_0055f0d0. Network configuration constant. |
| DAT_005dc4a4 | Dword5DC4A4 | network | int | read | 1 | Integer read by FUN_0055f0d0. Network configuration constant. |
| DAT_005e4cd4 | SceneFileDataPtr | setup/scene | ptr | offset | 1 | Scene file data pointer referenced by FUN_005622c0 (585-byte scene file loader). Used as default scene object if param_1 is NULL. Part of scene parsing pipeline. |
| DAT_008cf289 | Byte8CF289 | unknown | byte | read | 1 | Single byte read by FUN_00563410. Purpose unclear. |
| DAT_005e513c | LfLfLfField | setup | string offset | offset | 1 | Format string "%lf %lf %lf". Referenced by FUN_00565aa0. |
| DAT_005e51fc | Com5Field | setup | string offset | offset | 1 | "COM5" - Serial port device string. Referenced by FUN_005687f0. |
| DAT_005e5350 | JointField | setup/dynamics | string offset | offset | 1 | "Joint" - INI field for physics joint config. Referenced by FUN_0056d930. |
| DAT_008cfc90 | LDLTWorkspaceA | dynamics | double[?] | offset | 1 | Part of dynamics constraint solver workspace (0x8D0000 range). Used in FUN_0056fa96 (17786-byte block sparse LDL^T factorization). Workspace array for block factorization index arrays. |
| DAT_008d0eb8 | LDLTWorkspaceB | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008cfdb8 | LDLTWorkspaceC | dynamics | double[?] | write | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1278 | LDLTWorkspaceD | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d14d0 | LDLTWorkspaceE | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d0da8 | LDLTWorkspaceF | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1618 | LDLTWorkspaceG | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d09c0 | LDLTWorkspaceH | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1848 | LDLTWorkspaceI | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d07f0 | LDLTWorkspaceJ | dynamics | double[?] | offset | 1 | Dynamics solver workspace in LDLT factorization (FUN_0056fa96). Part of large block sparse matrix workspace. |
| DAT_008d3a98 | LDLTWorkspaceK | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d0990 | LDLTWorkspaceL | dynamics | double[?] | offset | 1 | Dynamics solver workspace in LDLT factorization (FUN_0056fa96). |
| DAT_008d0ab0 | LDLTWorkspaceM | dynamics | double[?] | write | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d0f58 | LDLTWorkspaceN | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1b60 | LDLTWorkspaceO | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1430 | LDLTWorkspaceP | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1438 | LDLTWorkspaceQ | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1318 | LDLTWorkspaceR | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1698 | LDLTWorkspaceS | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d19a8 | LDLTWorkspaceT | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d1d58 | LDLTWorkspaceU | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d39fc | LDLTWorkspaceV | dynamics | int | offset | 1 | Dynamics solver workspace int in LDLT factorization (FUN_0056fa96). |
| DAT_008d1ab8 | LDLTWorkspaceW | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d20d8 | LDLTWorkspaceX | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d2010 | LDLTWorkspaceY | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d3a18 | LDLTWorkspaceZ | dynamics | int | offset | 1 | Dynamics solver workspace int in LDLT factorization (FUN_0056fa96). |
| DAT_008d3b58 | LDLTWorkspaceAA | dynamics | double[?] | read | 1 | Dynamics solver workspace double in LDLT factorization (FUN_0056fa96). |
| DAT_008d3b78 | CholeskyWorkspaceA | dynamics | int | offset | 1 | Dynamics solver workspace int in FUN_00575bbd (13241-byte Cholesky/LDL^T solver). Part of constraint solver matrix workspace. |
| DAT_008d3b88 | CholeskyWorkspaceB | dynamics | int | offset | 1 | Dynamics solver workspace int in FUN_00575bbd. |
| DAT_008d29e8 | CholeskyWorkspaceC | dynamics | double | write | 1 | Dynamics solver workspace double in FUN_00575bbd. |
| DAT_008d2ec8 | CholeskyWorkspaceD | dynamics | double | write | 1 | Dynamics solver workspace double in FUN_00575bbd. |
| DAT_008d3bd8 | CholeskyWorkspaceE | dynamics | int | offset | 1 | Dynamics solver workspace int in FUN_00575bbd. |
| DAT_008d3bf5 | CholeskyWorkspaceF | dynamics | byte | offset | 1 | Dynamics solver workspace byte in FUN_0057a940 (10-byte trampoline to FUN_00598815). |
| DAT_005e540c | SSDDDDDDField | setup/renderer | string offset | offset | 1 | "%s %d %d %d %d %d %d" - Format string for scene/config parsing. Referenced by FUN_0057bf00. |
| DAT_005e6030 | SocketErrorString | network | string offset | offset | 1 | "The specified address is not a valid address for this socket" - Winsock error string. Referenced by FUN_0057d400. |
| DAT_005e5868 | SocketMarkString | network | string offset | offset | 1 | "The socket is marked as non-blocking" - Winsock error string. Referenced by FUN_0057d400. |
| DAT_005baab4 | LinkedListNodeStruct | memory | struct | offset | 1 | Linked list node structure referenced by FUN_0057e0a0. Part of memory allocator internal data. |
| DAT_005baec4 | ExceptionFrameStruct | runtime | struct | offset | 1 | MSVC exception handling frame structure referenced by FUN_00582ba0 (305-byte allocator constructor with SEH). Used as exception registration record. |
| DAT_005e6348 | PingRequestString | network | string offset | offset | 1 | "Ping Request from" - Network debug/log string. Referenced by FUN_00584230. |
| DAT_005b8c78 | Asc5B8C78 | runtime | string offset | offset | 1 | ASCII string constant used in CRT/startup code. Referenced by FUN_00588a34. |
| DAT_008d3e60 | CacheDateStruct | runtime | struct | read/write | 1 | Date/time cache struct in FUN_005896ee (220-byte time cache). Stores cached SYSTEMTIME fields: wYear (at +0), wMonth (+2), wDayOfWeek (+4), wDay (+6), wHour (+8), wMinute (+0xa), wSecond (+0xc), wMilliseconds (+0xe). Companion globals: DAT_008d3e58 (timezone bias), DAT_008d3e64/68/6c (remaining fields). Cached from GetSystemTime to avoid repeated calls. |
| DAT_005b8c98 | SEHRegistrationBlock | runtime | struct | offset | 1 | MSVC SEH exception registration record in FUN_0058a5f7 (104 bytes). Used as exception handler frame for try/catch in CRT startup. |
| DAT_005b8e00 | Double5B8E00 | runtime | double | read | 1 | Double constant read by FUN_0058dccc (25-byte CPU/feature detection). Used in CPUID feature check. |
| DAT_005e99d8 | D3DDeviceCallbackPtr | renderer | ptr | write | 1 | D3D device creation callback/function pointer written in FUN_0058ef83 (145-byte renderer init). Set to DAT_005e99d0 when dword_8D3F44 is 0. Part of D3D device setup chain. |
| DAT_005e72d0 | LocaleUSAPtr | locale | ptr | offset | 1 | Pointer to "american" string constant in FUN_0058fd90 (381-byte locale detection). Used in Win32 locale/region detection for language/region selection. |
| DAT_005e74f0 | Float5E74F0 | runtime | float | read | 1 | Floating-point constant in FUN_005908b0 (279-byte FP helper). Used in MSVC CRT floating-point division/normalization. |
| DAT_008d4060 | NLSMultiByteConfig | locale | byte | read | 1 | NLS/MultiByte configuration flag in FUN_0059249b (428-byte locale/time validation). Controls locale-specific date/time formatting and validation code path. |
| DAT_005b963c | MsvcrtHeapSelectString | runtime | string offset | offset | 1 | "MSVCRT!heap_select()" - MSVC CRT debug string. Referenced by FUN_00593115. |
| DAT_008d41fc | CRTOpenFlag | runtime | int | read | 1 | CRT file open sharing mode flag in FUN_00595af9 (719-byte fopen implementation). Compared against 0x8000 to set file sharing mode. Part of MSVC CRT file I/O implementation. |
| DAT_008d41e8 | CRTOnexitFuncs | runtime | code ptr | read | 1 | CRT onexit/atexit function pointer table in FUN_00597388 (386-byte onexit handler). Contains registered cleanup callbacks (DAT_008d41e8-41f4). Called during process shutdown with __exit(3) on null entry. |
| DAT_005b9cdc | CRTLocaleSetting | runtime | int | read | 1 | CRT locale setting data read by FUN_0059942b (58-byte locale init). Part of MSVC CRT locale initialization chain. |
| DAT_008d4618 | CRTTermFuncTable | runtime | int[8] | read | 1 | CRT termination function/index table (8 entries, stride 4) in FUN_0059a8fa (78-byte terminate handler). Stores registered atexit/onexit handler IDs. Companion counter at DAT_008d463c. |
| DAT_005bab20 | CxxFrameHandler | runtime | ptr | offset | 1 | Pointer to __CxxFrameHandler function. Used in FUN_0059ca3b (10-byte trampoline: `return __CxxFrameHandler(a1,a2,a3,a4)`). C++ exception handling dispatcher. |
