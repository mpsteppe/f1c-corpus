=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005be620 | TeamIndexString | setup/file | char* | read | 1 | "TeamIndex" INI key/format string constant — used in vehicle data file parsing (FUN_00402690) |
| DAT_008affa8 | Unknown_Setup_8AFFA8 | setup | float | write | 1 | Float written in setup/init function (FUN_00402690) — unclear purpose |
| DAT_005be4a4 | WpPosString | setup/file | char* | read | 1 | "WpPos" INI key string constant — used in waypoint/position data file parsing (FUN_00402690) |
| DAT_005ea55c | RenderResourceByte | renderer | byte | read | 1 | Byte resource/ID selector — passed to render function FUN_00456f70 as UI/render element identifier (FUN_004085f0) |
| DAT_007cfe28 | Unknown_Float_7CFE28 | unknown | float | read | 1 | Float constant read in FUN_0040ca30 — context truncated |
| DAT_005bea24 | NoString | setup/file | char* | read | 1 | "No" string constant — used in yes/no or boolean config parsing (FUN_0040d4c0) |
| DAT_005beb98 | DsIndicatorString | setup/file | char* | read | 1 | "DsIndicator" string constant — used in data/display indicator parsing (FUN_0040fe50) |
| DAT_005ea5d4 | FileLoadSentinel | setup/file | int | write | 1 | Sentinel value (-1/0xFFFFFFFF) for file loading state — written alongside DAT_005ea5d0/5d8/5dc during file load/reset (FUN_00411840) |
| DAT_005c240c | CountryBString | driver/data | char* | read | 1 | "CountryB" string constant — driver nationality field name in driver data table (FUN_00414e60) |
| DAT_005c2508 | DriverName_LucianoBurti | driver/data | char* | read | 1 | "Luciano Burti" driver name string — driver name table entry (FUN_00415d90) |
| DAT_005c2434 | DriverName_MarcG | driver/data | char* | read | 1 | "Marc G" driver name string — Marc Gené driver name entry (FUN_00415d90) |
| DAT_005c2920 | TeamName_1999Stewart | setup/data | char* | read | 1 | "1999 Stewart" team/car name string — team name table entry (FUN_0041b980) |
| DAT_005c2808 | TeamName_2001Minardi | setup/data | char* | read | 1 | "2001 Minardi" team/car name string — team name table entry (FUN_0041b980) |
| DAT_005c2a6c | OptionsAnimString | UI | char* | read | 1 | "OptionsAnim" UI element string — used in options/animation menu config (FUN_004216f0) |
| DAT_005c2cc4 | ComponentsString | UI | char* | read | 1 | "Components" UI menu/section string — used in display settings UI (FUN_00421cd0) |
| DAT_005c2bc0 | VideoramString | UI | char* | read | 1 | "Videoram" UI display string — graphics/video memory info label (FUN_00421cd0) |
| DAT_005c2ad0 | IpAddressString | UI/network | char* | read | 1 | "IpAddress" UI string — network IP address label/field (FUN_00421cd0) |
| DAT_005c2efc | GridSizeFormatString | UI | char* | read | 1 | "GridSize: %d" format string — UI display for grid size setting (FUN_00422be0) |
| DAT_005c2dc0 | LaunchTimeFormatString | UI | char* | read | 1 | "LaunchTime: %d" format string — UI display for launch time setting (FUN_00422be0) |
| DAT_005c3200 | RainAbilityString | setup/file | char* | read | 1 | "RainAbility" INI key string — AI driver rain ability parameter (FUN_00424080) |
| DAT_005c30e0 | Unknown_String_5C30E0 | unknown | char* | read | 1 | Unknown string constant — used in AI/performance function (FUN_00424e70); context truncated |
| DAT_005c3260 | DDDDFormatString | setup/file | char* | read | 1 | "DDDD" format/INI key string — used in steering wheel/controller config parsing (FUN_00429960) |
| DAT_005c3464 | OppositeLockAngleString | setup/file | char* | read | 1 | "OppositeLockAngle" HDV/INI key string — steering lock angle parameter (FUN_0042c440) |
| DAT_007c9338 | StewardCounterBlock8 | steward/game | int | write | 1 | Part of 12-field counter block (DAT_007c932c–7c9358) zeroed each tick in game/steward update loop (FUN_0042c690) |
| DAT_005c34f8 | Practice2String | session | char* | read | 1 | "Practice2" session type string — used in session configuration (FUN_0042ce30) |
| DAT_005cd114 | EnteredOsmanExString | debug | char* | read | 1 | "EnteredOsmanEx" debug/assert string — used in Osman (splash/intro) module (FUN_0042db20) |
| DAT_005c373c | VTableRef_5C373C | renderer | ptr | read | 1 | VTable/function pointer table reference — used in renderer object construction (FUN_0042ed70) |
| DAT_005c3db4 | FrontWingString | setup/hdv | char* | read | 1 | "FrontWing" HDV parameter key string — front wing setup parameter (FUN_0042fd00) |
| DAT_005c3be8 | Front3rdSlowReboundString | setup/hdv | char* | read | 1 | "Front3rdSlowRebound" HDV parameter key string — suspension rebound parameter (FUN_0042fd00) |
| DAT_005c3a00 | GearSettingFormatString | setup/hdv | char* | read | 1 | "Gear%dSetting%d" HDV format key string — gear ratio setup parameter (FUN_0042fd00) |
| DAT_005c3870 | BasicString | setup/hdv | char* | read | 1 | "Basic" HDV/INI section key string — basic setup parameters section (FUN_0042fd00) |
| DAT_0059ea90 | Unknown_Double_59EA90 | physics | double | read | 1 | Double constant read in physics function (FUN_00430f00) |
| DAT_005ea538 | FileInitCounter | setup/file | int | write | 1 | File/resource initialization counter — written during setup/init sequence (FUN_00434460) |
| DAT_0059eb18 | EngineThermalConstant | physics/thermal | double | read | 1 | Double constant used in thermal model (FUN_00436870, 6198-byte engine thermal function) — energy dissipation or temperature threshold |
| DAT_005c415c | RrSpindleString | setup/hdv | char* | read | 1 | "RrSpindle" HDV parameter key string — rear spindle geometry parameter (FUN_00438da0) |
| DAT_005c42e4 | FlForeUpperString | setup/hdv | char* | read | 1 | "FlForeUpper" HDV parameter key string — front-left fore upper wishbone attachment (FUN_0043b590) |
| DAT_0059ece8 | DissipationThreshold | physics | double | read | 1 | Double dissipation/comparison threshold in physics collision/impact model (FUN_0043ef20) |
| DAT_007cc6e0 | TireSlipConstant | physics/tire | double | read | 1 | Double tire slip/grip constant — used in tire lateral force computation (FUN_00443b70) |
| DAT_0059ee70 | TireDoubleConstant_59EE70 | physics/tire | double | read | 1 | Double constant read in tire/aero physics (FUN_004441f0, 9101-byte tire model function) |
| DAT_007cc1b8 | TireForceConstant | physics/tire | int | read | 1 | Int constant read in tire physics (FUN_004441f0, 9101-byte tire model) |
| DAT_0059ef18 | TransformMathConstant | renderer | double | read | 1 | Double constant used in vertex/transform math (FUN_00448730, 1616-byte render transform function) |
| DAT_007ca454 | FloatInitOne | renderer | float | write | 1 | Initialized to 1.0f (1065353216) in render state init function (FUN_0044ce74) — pair with DAT_007ca450 |
| DAT_007ccd48 | CollisionInitZeroed | collision | int | write | 1 | Zeroed field in collision system init block — part of 5-field zeroed struct (FUN_0044d400) |
| DAT_005c5450 | CursorFileString | UI | char* | read | 1 | "Cursor00.cur" cursor file path string — used in UI cursor loading (FUN_0044f4e0) |
| DAT_005ad370 | RendererFloatArrayEntry | renderer | float | read | 1 | Float array entry read in renderer/audio processing function (FUN_0044ff50, 5968 bytes) |
| DAT_005ad3b8 | RendererFloatConstant | renderer | float | read | 1 | Float constant used in same renderer processing function (FUN_0044ff50) |
| DAT_007c77f8 | VehicleEffectDouble | physics/effect | double | read | 1 | Double constant in vehicle effect/state update (FUN_00451720) |
| DAT_007ccd80 | CollisionComparisonValue | collision | int | read | 1 | Int read in collision parameter comparison chain — compared against collision param values (FUN_00452b10) |
| DAT_007ccfe0 | RenderStateFloat_7CCFE0 | renderer | float | write | 1 | Float written in render state update — part of render parameter block, clamped to ZeroThreshold (FUN_004537b0) |
| DAT_007ca510 | RenderStateFloatPair | renderer | float | write | 1 | Float init pair in render state update — compared against threshold, clamped to ZeroThreshold (FUN_004537b0) |
| DAT_007ca4b0 | RenderStateDwordPair | renderer | int | write | 1 | Int init pair in render state update — part of render parameter block (FUN_004537b0) |
| DAT_005c559c | LcdUpString | UI | char* | read | 1 | "LcdUp" control mapping string — steering wheel LCD up button (FUN_00455290) |
| DAT_005c5494 | HandbrakeString | UI | char* | read | 1 | "Handbrake" control mapping string — handbrake control binding (FUN_00455290) |
| DAT_005c5788 | RadiusLimitsString | track/ai | char* | read | 1 | "RadiusLimits" track data key string — corner radius limit parameters (FUN_004562f0) |
| DAT_005c5a80 | SControlPointFormat | track | char* | read | 1 | "SControlPoint%d" format string — spline control point index (FUN_00458190) |
| DAT_007cd200 | AudioCollisionFloat | audio/collision | float | read | 1 | Float constant in audio/collision function (FUN_0045b950) |
| DAT_0059f09c | NetCommInitConstant | network | int | read | 1 | Int constant assigned to two struct fields during NetComm object initialization — likely timeout or buffer size constant (FUN_0045d530) |
| DAT_005c5e30 | AutoChatString | network | char* | read | 1 | "AutoChat04" network auto-chat message string (FUN_0045ecd0) |
| DAT_005c5f6c | SendingServerOverflow | network | char* | read | 1 | "SendingServerOverflow..." network debug string (FUN_00460470) |
| DAT_007d001c | SessionConfigField | session | int | read | 1 | Session config field read in session settings loader — part of config-to-global copy block (FUN_00461900) |
| DAT_007d1094 | SessionConfigFloatPair | session | float | read | 1 | Float config value pair used in FUN_004646c0 call during session init (FUN_00461900) |
| DAT_005c61f4 | SendingJoinRequestString | network | char* | read | 1 | "SendingJoinRequest" network debug/message string (FUN_00462c00) |
| DAT_005c642c | NetcommActivateString | network | char* | read | 1 | "NetcommActivate" network module string (FUN_00463160) |
| DAT_007d10ec | NetworkJoinFlag | network | int | read | 1 | Int read in network session join function — checks flag alongside SessionType/SessionType5 (FUN_00463f70) |
| DAT_005c6714 | Header2String | UI | char* | read | 1 | "Header2" UI layout/section string (FUN_00467f90) |
| DAT_007d2de4 | ScoringStandingsValue | scoring | int | read | 1 | Int constant read in scoring/standings computation (FUN_0046a560) |
| DAT_005c6d08 | JoinSessionWasString | network | char* | read | 1 | "JoinSessionWas" network debug/assert string (FUN_0046de10) |
| DAT_005a4600 | VTableRef_5A4600 | UI | ptr | read | 1 | VTable pointer for UI/text class constructor (FUN_00477410) |
| DAT_005c71d4 | VcrString | replay | char* | read | 1 | "Vcr" video capture/replay string constant (FUN_0047bf30) |
| DAT_005c73a4 | StartsString | UI | char* | read | 1 | "Starts" UI grid/event string (FUN_0047dd10) |
| DAT_005a6e98 | VTableRef_5A6E98 | UI | ptr | read | 1 | VTable pointer for UI text class (FUN_0047fba0) |
| DAT_005cc5a4 | DoPageString | UI | char* | read | 1 | "DoPage" UI page navigation string (FUN_00492160) |
| DAT_005cc6f4 | OffsetString | UI | char* | read | 1 | "Offset" UI layout/position string (FUN_00492a40) |
| DAT_005cc8b0 | DoPageTransitionString | UI | char* | read | 1 | "DoPageTransition1" UI page animation string (FUN_00493480) |
| DAT_005ac80c | LogOscInformationString | debug | char* | read | 1 | "LogOscInformation" debug/logging string (FUN_00493f50) |
| DAT_005cca30 | NoDrawStackAvailableString | debug/render | char* | read | 1 | "NoDrawStackAvailable" debug string — draw stack overflow warning (FUN_00496e90) |
| DAT_007ce1e8 | SessionDataBlock | session | struct | read | 1 | Struct base reference — used in session/scoring init sequence (FUN_0049afe0) |
| DAT_005ccea0 | TextByteFlag | UI | byte | read | 1 | Single-byte flag read in UI text processing (FUN_0049c770) |
| DAT_005ccba4 | OffscreenBufferPtr | renderer | ptr | read | 1 | Offscreen buffer/context pointer read in UI/render function (FUN_0049ca00) |
| DAT_005ccef4 | EnteredOnScreenString | debug | char* | read | 1 | "EnteredOnScreen" debug/log string (FUN_0049ef40) |
| DAT_005c6bb0 | FiaShortBikString | video/replay | char* | read | 1 | "FiaShortBik" FIA intro video file string (FUN_004a00a0) |
| DAT_007ce294 | SessionStateByte | session | byte | write | 1 | Session state byte written during steward initialization (FUN_004a1200) |
| DAT_005cd148 | FilePathString | setup | char* | read | 1 | File path string used in file concatenation (FUN_004a1ec0) — appended with FUN_00566650 |
| DAT_005cd224 | TenSecPenaltyString | UI | char* | read | 1 | "10secNMan" penalty/time display string — 10-second stop-go penalty message (FUN_004a24d0) |
| DAT_005cd3d8 | LrWheelOffMtsString | setup/hdv | char* | read | 1 | "LrWheelOffMts" HDV setup key — left-rear wheel offset parameter (FUN_004a2a90) |
| DAT_005acb34 | AIDifficultyFloat | ai | float | read | 1 | Float AI difficulty/aggression multiplier — used in AI ability scaling (FUN_004a4110) |
| DAT_007d0374 | ScoringSessionValue | scoring | int | read | 1 | Int read in session scoring initialization (FUN_004a5330) |
| DAT_005acbc0 | VTableRef_5ACBC0 | game | ptr | read | 1 | VTable pointer for large game object constructor (6669 bytes, FUN_004a70e0) |
| DAT_005d1fa0 | ProfileVehicleString | setup/plr | char* | read | 1 | "ProfileVehicle" PLR config key string (FUN_004aa270) |
| DAT_005d1dac | AutoLiftString | setup/plr | char* | read | 1 | "AutoLift" PLR config key — automatic lifting/throttle lift setting (FUN_004aa270) |
| DAT_005d1a50 | TelemetryF1TelString | setup/plr | char* | read | 1 | "TelemetryF1Tel" PLR config key — F1 telemetry output setting (FUN_004aa270) |
| DAT_005d17e0 | ReconTimerString | setup/plr | char* | read | 1 | "ReconTimer" PLR config key — reconnaissance timer setting (FUN_004aa270) |
| DAT_005d15e4 | RealtimeInMonitorString | setup/plr | char* | read | 1 | "RealtimeInMonitor" PLR config key — real-time telemetry monitor setting (FUN_004aa270) |
| DAT_005d13f8 | CrowdAmbientString | setup/plr | char* | read | 1 | "CrowdAmbient" PLR config key — crowd ambient sound level setting (FUN_004aa270) |
| DAT_005d1278 | RearviewParticleString | setup/plr | char* | read | 1 | "RearviewParticle" PLR config key — rearview mirror particle effect setting (FUN_004aa270) |
| DAT_005d107c | ThunderProbabilityString | setup/plr | char* | read | 1 | "ThunderProbability" PLR config key — thunder/lightning probability setting (FUN_004aa270) |
| DAT_005d0d6c | RainsprayFlowString | setup/plr | char* | read | 1 | "RainsprayFlow" PLR config key — rain spray particle flow setting (FUN_004aa270) |
| DAT_005d0a88 | EnvironmentMapString | setup/plr | char* | read | 1 | "EnvironmentMap" PLR config key — environment mapping quality setting (FUN_004aa270) |
| DAT_005d08c8 | SpeedMphAtWhichString | setup/plr | char* | read | 1 | "SpeedMphAtWhich..." PLR config key — speed threshold at which X happens (FUN_004aa270) |
| DAT_005d0614 | RecordReplaysString | setup/plr | char* | read | 1 | "RecordReplays" PLR config key — replay recording setting (FUN_004aa270) |
| DAT_005d0358 | AiCornerGripUseString | setup/plr | char* | read | 1 | "AiCornerGripUse" PLR config key — AI corner grip usage setting (FUN_004aa270) |
| DAT_005d00a4 | DisplayTrackStateString | setup/plr | char* | read | 1 | "DisplayTrackState" PLR config key — track state overlay display setting (FUN_004aa270) |
| DAT_005cfe58 | SecondsAfterPauseString | setup/plr | char* | read | 1 | "SecondsAfterPause" PLR config key — resume delay after pause setting (FUN_004aa270) |
| DAT_005cfb58 | ClientSettingString | setup/plr | char* | read | 1 | "ClientSetting" PLR config key — network client configuration setting (FUN_004aa270) |
| DAT_005cf740 | PortStartString | setup/plr | char* | read | 1 | "PortStart" PLR config key — network port start range setting (FUN_004aa270) |
| DAT_005cf33c | SplineGenerateString | setup/plr | char* | read | 1 | "SplineGenerate" PLR config key — spline generation detail setting (FUN_004aa270) |
| DAT_005cf070 | KeyboardBrakeString | setup/plr | char* | read | 1 | "KeyboardBrake" PLR config key — keyboard brake control setting (FUN_004aa270) |
| DAT_005cec1c | Controller2XString | setup/plr | char* | read | 1 | "Controller2X" PLR config key — second controller axis setting (FUN_004aa270) |
| DAT_005cea68 | ControlBrakeString | setup/plr | char* | read | 1 | "ControlBrake" PLR config key — brake control axis/binding (FUN_004aa270) |
| DAT_005ce894 | ControlPitMenu2String | setup/plr | char* | read | 1 | "ControlPitMenu2" PLR config key — pit menu control binding (FUN_004aa270) |
| DAT_005ce6d0 | ControlLookDownString | setup/plr | char* | read | 1 | "ControlLookDown" PLR config key — look-down camera control (FUN_004aa270) |
| DAT_005ce2e4 | FfbSteerVibeWaveString | setup/plr | char* | read | 1 | "FfbSteerVibeWave" PLR config key — FFB steering vibration wave setting (FUN_004aa270) |
| DAT_005cde08 | FfbSteerDamperString | setup/plr | char* | read | 1 | "FfbSteerDamper" PLR config key — FFB steering damper setting (FUN_004aa270) |
| DAT_005cd9fc | FfbRumbleStripString | setup/plr | char* | read | 1 | "FfbRumbleStrip" PLR config key — FFB rumble strip intensity setting (FUN_004aa270) |
| DAT_005d2308 | TmpFileString | setup/file | char* | read | 1 | "Tmp" temporary file string used in file path construction (FUN_004b0770) |
| DAT_005acc98 | FloatToShortClampMin | renderer | float | read | 1 | Float-to-short16 clamp minimum threshold — values below clamped to 0x8001 (-32767) (FUN_004b2480) |
| DAT_008ab6f4 | ScoringListTailPtr | scoring | ptr | write | 1 | Tail pointer for scoring linked list — stride 0x1b0 per entry, allocated 0x3600 bytes total (FUN_004b44e0) |
| DAT_005acd14 | CameraMoveMultiplier | game/camera | float | read | 1 | Float multiplier for camera/view movement — applied to scroll/pan delta (FUN_004b9e40) |
| DAT_005d2568 | WarningString | UI | char* | read | 1 | "Warning" UI message string (FUN_004bbc60) |
| DAT_005acdcc | RenderCameraFloat | renderer/camera | float | read | 1 | Float constant used in renderer/camera function (FUN_004be760) |
| DAT_005f0734 | ScoringSeasonRef | scoring | int | read | 1 | Int reference in scoring/season context — checked alongside RaceMode (FUN_004bff70) |
| DAT_005d2754 | OriginalGridPositionString | session/scoring | char* | read | 1 | "OriginalGridPosition" scoring save key — driver's original grid position (FUN_004c0690) |
| DAT_005d2e64 | TotalLapsFormatString | session | char* | read | 1 | "TotalLaps %d" format string — total laps display (FUN_004c2420) |
| DAT_005d2c0c | GameoptRaceLapString | session | char* | read | 1 | "GameoptRaceLap" session config key — race lap count option (FUN_004c2420) |
| DAT_005d2fd8 | MirrorNormString | renderer | char* | read | 1 | "MirrorNorm" render config key — mirror normal/render setting (FUN_004c3200) |
| DAT_005d2e9c | GenString | renderer | char* | read | 1 | "Gen" generic render config key (FUN_004c3200) |
| DAT_005ace04 | AISessionDiffMult | ai | float | read | 1 | Session-type-dependent AI difficulty multiplier — different values for quali/race/practice (FUN_004c7f30) |
| DAT_005ace2c | VTableRef_5ACE2C | renderer/particle | ptr | read | 1 | VTable pointer for particle/weather effect class (FUN_004c8f10) |
| DAT_005d36ac | BlackSmokeString | particle | char* | read | 1 | "BlackSmoke" particle effect key string (FUN_004ca480) |
| DAT_005d35a4 | NumWaypointsString | track | char* | read | 1 | "NumWaypoints" track data key string (FUN_004ca480) |
| DAT_005d34d4 | BillboardsString | renderer | char* | read | 1 | "Billboards" render config key string (FUN_004ca480) |
| DAT_005d3788 | CouldNotCreateString | debug | char* | read | 1 | "CouldNotCreate" error/debug string (FUN_004cb120) |
| DAT_005d38b8 | DamperString | setup/hdv | char* | read | 1 | "Damper" HDV setup key — damper parameter (FUN_004cdd80) |
| DAT_005d3914 | EnteredSpecialString | debug | char* | read | 1 | "EnteredSpecial" debug/assert string (FUN_004ceec0) |
| DAT_005d3b0c | GridModelFormatString | renderer | char* | read | 1 | "GridModel%02d" format string — grid model file naming (FUN_004d0110) |
| DAT_005d3a34 | TeamString | UI | char* | read | 1 | "Team" UI display string (FUN_004d12c0) |
| DAT_005d40f4 | TimestringFormatString | UI | char* | read | 1 | "Timestring: %s" format string — time display format (FUN_004d24d0) |
| DAT_005d3f2c | DriveaidsStabilityString | UI | char* | read | 1 | "DriveaidsStability" UI/display string — stability control driving aid (FUN_004d24d0) |
| DAT_005d3d6c | DriverFormatString | UI | char* | read | 1 | "Driver: %s" format string — driver name display (FUN_004d24d0) |
| DAT_005d4194 | TimeFormatString | UI | char* | read | 1 | "%s %02d:%02d" time format string — minutes:seconds display (FUN_004d2e50) |
| DAT_005d422c | XSector2String | track | char* | read | 1 | "XSector2" track data key — second extra sector timing point (FUN_004d38f0) |
| DAT_005acef0 | RaceLogicDouble | race/scoring | double | read | 1 | Double constant used in race/scoring logic — compared against track time or position (FUN_004d4580) |
| DAT_005d44fc | UnfilteredBrakeString | telemetry | char* | read | 1 | "UnfilteredBrake" telemetry key — raw brake input value (FUN_004d4a80) |
| DAT_007c935c | TelemetryBrakeFloat | telemetry | float | read | 1 | Float threshold/constant in telemetry brake processing (FUN_004d4a80) |
| DAT_005d4838 | RadiusRPMString | setup/hdv | char* | read | 1 | "RadiusRPM" HDV setup key — RPM-based shift radius parameter (FUN_004d6b00) |
| DAT_005d4744 | OptimumPressureString | setup/hdv | char* | read | 1 | "OptimumPressure" HDV setup key — optimum tire pressure parameter (FUN_004d6b00) |
| DAT_005d4a60 | FileIndexEnumOffset | setup/file | byte | read | 1 | Base offset for file index enumeration — used in file list rendering with loop counter (FUN_004d8130) |
| DAT_005d4b00 | GridString | UI | char* | read | 1 | "Grid" UI display string — grid position overlay text (FUN_004d9420) |
| DAT_005ad088 | VTableRef_5AD088 | game | ptr | read | 1 | VTable/function table reference (FUN_004db420) |
| DAT_005d4c2c | LollipopString | pit | char* | read | 1 | "Lollipop" pit crew animation string (FUN_004ddad0) |
| DAT_005ad140 | PitSelectionCost | physics/pit | float | read | 1 | Float priority/cost value in pit stop tire selection — determines tire compound choice (FUN_004dedb0) |
| DAT_005d4d34 | BackfireString | particle | char* | read | 1 | "Backfire" particle effect key — exhaust backfire effect (FUN_004dfce0) |
| DAT_007c911c | SteeringWheelDouble | physics/steering | double | read | 1 | Double constant in wheel/steering physics — used in steering angle computation (FUN_004e49b0) |
| DAT_008adac0 | RingBufferFallback | ai | struct | read | 1 | Fallback allocator buffer for AI waypoint ring buffer — returned when allocation count exceeds 32 (DAT_008adaf8) (FUN_004ea010) |
| DAT_007c8b48 | VehiclePhysicsInt | physics | int | write | 1 | Int written in vehicle physics update function (FUN_004f0430, 2270 bytes) |
| DAT_005d4fe0 | VertMultString | setup/hdv | char* | read | 1 | "VertMult" HDV collision parameter key — vertical multiplier (FUN_004f24f0) |
| DAT_005d4e90 | PartDCollParamString | setup/hdv | char* | read | 1 | "PartDCollParam" HDV collision parameter key (FUN_004f24f0) |
| DAT_005d51b4 | CgOffsetXString | setup/hdv | char* | read | 1 | "CgOffsetX" HDV setup key — center of gravity X offset (FUN_004f2c60) |
| DAT_005d5070 | FastReboundRangeString | setup/hdv | char* | read | 1 | "FastReboundRange" HDV suspension key — fast rebound damper range (FUN_004f2c60) |
| DAT_005d54e4 | EngineMapRangeString | setup/hdv | char* | read | 1 | "EngineMapRange" HDV engine key — engine map range parameter (FUN_004f3c10) |
| DAT_005d55d8 | LifetimeVarString | setup/hdv | char* | read | 1 | "LifetimeVar" HDV engine key — engine lifetime variance parameter (FUN_004f3c80) |
| DAT_005d6708 | RulesString | setup/hdv | char* | read | 1 | "Rules" HDV section key — car rules/regulations section (FUN_004f4270) |
| DAT_005d65dc | AiDamperSlowString | setup/hdv | char* | read | 1 | "AiDamperSlow" HDV AI key — AI slow damper setting (FUN_004f4270) |
| DAT_005d64b0 | Pitstop1RangeString | setup/hdv | char* | read | 1 | "Pitstop1Range" HDV setup key — pit stop 1 strategy range (FUN_004f4270) |
| DAT_005d63c0 | FwRangeString | setup/hdv | char* | read | 1 | "FwRange" HDV setup key — front wing angle range (FUN_004f4270) |
| DAT_005d62c8 | BodyDragHeightString | setup/hdv | char* | read | 1 | "BodyDragHeight" HDV aero key — body drag height parameter (FUN_004f4270) |
| DAT_005d61b0 | DiffuserFrontHeightString | setup/hdv | char* | read | 1 | "DiffuserFrontHeight" HDV aero key — diffuser front height parameter (FUN_004f4270) |
| DAT_005d6048 | Front3rdBumpStopString | setup/hdv | char* | read | 1 | "Front3rdBumpStop" HDV suspension key — third front spring bump stop (FUN_004f4270) |
| DAT_005d5e78 | RearToeInSettingString | setup/hdv | char* | read | 1 | "RearToeInSetting" HDV alignment key — rear toe-in angle setting (FUN_004f4270) |
| DAT_005d5cc8 | Front3rdFastBumpStopString | setup/hdv | char* | read | 1 | "Front3rdFastBumpStop" HDV suspension key — third front fast bump stop (FUN_004f4270) |
| DAT_005d5ae4 | AutoDownshiftGearString | setup/hdv | char* | read | 1 | "AutoDownshiftGear" HDV gearbox key — automatic downshift gear limit (FUN_004f4270) |
| DAT_005d59a4 | ClutchTorqueString | setup/hdv | char* | read | 1 | "ClutchTorque" HDV engine key — clutch torque capacity parameter (FUN_004f4270) |
| DAT_005d5875 | Gear4SettingString | setup/hdv | char* | read | 1 | "Gear4Setting" HDV gearbox key — 4th gear ratio setting (FUN_004f4270) |
| DAT_005d5744 | RideString | setup/hdv | char* | read | 1 | "Ride" HDV setup key — ride height parameter (FUN_004f4270) |
| DAT_005d677c | VsOutsideString | renderer | char* | read | 1 | "VsOutside" render/section key (FUN_004f7460) |
| DAT_005d6b5f | Unknown_ShaderString1 | renderer | char* | read | 1 | Unknown shader/render string (FUN_004f7460) |
| DAT_005d69cb | Unknown_ShaderString2 | renderer | char* | read | 1 | Unknown shader/render string (FUN_004f7460) |
| DAT_005d681f | Unknown_ShaderString3 | renderer | char* | read | 1 | Unknown shader/render string (FUN_004f7460) |
| DAT_008afebc | PhysicsIntWrite | physics | int | write | 1 | Int written in physics/vehicle update (FUN_004f9480) |
| DAT_005ad268 | PhysicsParamSelectorFloat | physics | float | read | 1 | Float converted to double for physics parameter selection — case 1 returns this value (FUN_004f9f70) |
| DAT_005d6f00 | MonacoTrackString | track | char* | read | 1 | "Monaco" track name string — Monte Carlo circuit identifier (FUN_004fb910) |
| DAT_005ad2b0 | PhysicsEffectFloat | physics | float | read | 1 | Float constant in physics/effect function (FUN_004fcee0) |
| DAT_005ad2d4 | VehicleUpdateFloat | physics | float | read | 1 | Float constant in vehicle update function — used with steering/velocity calculations (FUN_004fd8b0) |
| DAT_005d6fd4 | VTableRef_5D6FD4 | game | ptr | read | 1 | VTable pointer reference (FUN_004fe2b0) |
| DAT_005d70e0 | ConditionsFormatString | UI | char* | read | 1 | "Conditions%2f" UI format string — weather/conditions display (FUN_004fe820) |
| DAT_005ad35c | BlendThresholdFloat | renderer | float | read | 1 | Float threshold in vertex blending/interpolation math — compared against squared distance delta (FUN_004ff8f0) |
| DAT_005ba554 | RenderVertexStruct | renderer | struct | read | 1 | Struct/base pointer for renderer vertex processing (FUN_00504f5a) |
| DAT_005adc08 | VertexMatrixCoeff | renderer | float | read | 1 | Float coefficient in vertex transform matrix computation — used in 3D projection transform (FUN_0050a92d) |
| DAT_005adcec | VTableRef_5ADCEC | renderer | ptr | read | 1 | VTable pointer for renderer class constructor (FUN_0050b228) |
| DAT_005ba6c0 | RenderVTableRef | renderer | ptr | read | 1 | VTable/struct reference in renderer destructor (FUN_0050b830) |
| DAT_005d7848 | FunctionPointerTable | renderer | ptr | read | 1 | Function pointer table — called through indirection in render function (FUN_0050d690) |
| DAT_005af878 | DecompressionTreeData | data/math | struct | read | 1 | Huffman/bitstream decompression tree data — used in compressed file/asset reading (FUN_00510d60) |
| DAT_005af248 | DecompressionIntConst | data/math | int | read | 1 | Int constant in decompression/math function (FUN_00511b7c) |
| DAT_005af600 | D3DVertexConstArray | renderer | float[] | read | 1 | DirectX vertex processing constant array — used as coefficient reference in D3D vertex transform (FUN_0051427f) |
| DAT_005afa30 | IncorrectDataChecksumString | image | char* | read | 1 | "IncorrectDataChecksum" image file error string (FUN_00517adc) |
| DAT_005afd1c | NoImageInFileString | image | char* | read | 1 | "NoImageInFile" image loading error string (FUN_00518bd4) |
| DAT_005afe90 | TrnsChunkNotAlignedString | image | char* | read | 1 | "TrnsChunkNotAligned" PNG/TGA transparency chunk error (FUN_00518e18) |
| DAT_008d6004 | SIMDVectorNormFloat | math_util | float | read | 1 | Float constant in SIMD vector normalization — used in fsqrt-based normalization (FUN_0051edae) |
| DAT_005d8bb0 | SIMDQuaternionConst | math_util | int | read | 1 | Int/SIMD constant in quaternion/matrix transform (FUN_0051fb1e) |
| DAT_008d6160 | SIMDColorShaderConst | math_util/render | int | read | 1 | Int in SIMD color/shader processing (FUN_0051febe) |
| DAT_005d8ca0 | SIMDVectorAndMask | math_util | xmm | read | 1 | SIMD AND mask for vector normalization/abs computation (FUN_00520a7e) |
| DAT_008d6280 | SIMDCrossProductFloat | math_util | float | read | 1 | Float constant in SIMD 3x3 matrix cross-product (FUN_00520ce0) |
| DAT_005d9020 | SIMDColorUnpackConst | math_util/render | xmm | read | 1 | SIMD constant in color channel unpack/decode (FUN_005289e0) |
| DAT_005d90c0 | SIMDPixelConst | math_util/render | xmm | read | 1 | SIMD constant in pixel processing (FUN_00528bd0) |
| DAT_005d93a0 | MMXPackMathConst | math_util | int | read | 1 | Int constant in MMX/3DNow packed math (reciprocal sqrt approximation) (FUN_00529000) |
| DAT_005b08f8 | SIMDMathDataTable | math_util | struct | read | 1 | Data table in SIMD/math function (FUN_0052a4a5) |
| DAT_005b0bb8 | PackedShortMulConst1 | math_util | qword | read | 1 | Packed short multiplication constant — used in SIMD packed multiply (FUN_0052ab4e) |
| DAT_005b0c78 | PackedShortMulConst2 | math_util | qword | read | 1 | Packed short multiplication constant (FUN_0052b561) |
| DAT_005b11a4 | TextureColorFloat | renderer | float | read | 1 | Float constant in texture/color processing (FUN_0052e6f0) |
| DAT_005b7730 | DCTTransformCoeff | math_util/render | float | read | 1 | Float coefficient in DCT/block transform math (32x32 matrix processing) (FUN_00531b50) |
| DAT_008b5944 | DCTOutputCoeff1 | math_util/render | float | write | 1 | Float output coefficient in DCT/transform forward pass (FUN_00531b50) |
| DAT_008b5968 | DCTOutputCoeff2 | math_util/render | float | write | 1 | Float output coefficient in DCT/transform forward pass (FUN_00531b50) |
| DAT_008b59cc | DCTOutputCoeff3 | math_util/render | float | write | 1 | Float output coefficient in DCT/transform forward pass (FUN_00531b50) |
| DAT_005b7790 | DCTTransformCoeff2 | math_util/render | float | read | 1 | Float coefficient in DCT/block transform math (FUN_00531b50) |
| DAT_005da818 | VTableRef_5DA818 | renderer | ptr | read | 1 | VTable pointer read in render function (FUN_00535c10) |
| DAT_005b7cb0 | AILookupTableInt | ai | int | read | 1 | Int/byte lookup table reader in AI pathfinding — uses byte_5B84F8 as index table (FUN_00539200) |
| DAT_005b8938 | VTableRef_5B8938 | physics/collision | ptr | read | 1 | VTable pointer for physics/collision object manager singleton (FUN_0053b0d0) |
| DAT_005dbe30 | CouldNotCreateString | debug | char* | read | 1 | "CouldNotCreate" error/debug string (FUN_00545430) |
| DAT_005dc00c | ErrorLoadingMaterialString | renderer | char* | read | 1 | "ErrorLoadingMaterial" renderer error string (FUN_005508a0) |
| DAT_005dc188 | SomeMtsInitErrorString | renderer | char* | read | 1 | "SomeMtsInitError" renderer/MTS initialization error (FUN_00557670) |
| DAT_005dc34c | ZBufferString | renderer | char* | read | 1 | "ZBuffer" render config key string (FUN_0055a910) |
| DAT_005dc3fc | FontFileString | renderer | char* | read | 1 | "FontFile" font configuration key string (FUN_0055b200) |
| DAT_005dc5b4 | D3DRenderIntConst1 | renderer | int | read | 1 | Int constant read in D3D render function (FUN_0055f0d0) |
| DAT_005dc548 | D3DRenderIntConst2 | renderer | int | read | 1 | Int constant read in D3D render function (FUN_0055f0d0) |
| DAT_005dc50c | D3DRenderByteFlag | renderer | byte | read | 1 | Byte flag read in D3D render function (FUN_0055f0d0) |
| DAT_005dc4b4 | D3DRenderIntConst3 | renderer | int | read | 1 | Int constant read in D3D render function (FUN_0055f0d0) |
| DAT_005e0ccc | MulLookupTable | math_util | byte[16384] | write | 1 | Multiplication lookup table (256x64 byte table) — precomputed (i*j)>>8 for all byte pairs (FUN_00561b2a) |
| DAT_005e4fac | ListGameNameFormatString | network/UI | char* | read | 1 | "List: %s, GameName: %s" network list format string (FUN_00562e30) |
| DAT_005e50bc | FFFFString | UI | char* | read | 1 | "FFFF" hex format/display string (FUN_00565870) |
| DAT_005e5224 | ClockString | UI | char* | read | 1 | "Clock" UI display string — clock/time display toggle (FUN_005687f0) |
| DAT_005e5234 | StringEncodingRef | text | char* | read | 1 | String encoding reference — used in +~ notation string encoding/decoding (FUN_00568910) |
| DAT_005e52d4 | BodyDMustBeNamedString | debug | char* | read | 1 | "BodyDMustBeNamed" debug/error string (FUN_0056d930) |
| DAT_008d0c30 | DynamicsSolverWorkspace_8D0C30 | dynamics | double | read | 1 | Double workspace variable in block sparse LDL^T constraint solver (FUN_0056fa96, 17786 bytes) |
| DAT_008d0ec0 | DynamicsSolverWorkspace_8D0EC0 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008cff28 | DynamicsSolverWorkspace_8CFF28 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d0008 | DynamicsSolverWorkspace_8D0008 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d0108 | DynamicsSolverWorkspace_8D0108 | dynamics | double | write | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d3a68 | DynamicsSolverWorkspace_8D3A68 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d3a78 | DynamicsSolverWorkspace_8D3A78 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d39b8 | DynamicsSolverIndex_8D39B8 | dynamics | int | read | 1 | Index/offset variable in dynamics constraint solver workspace (FUN_0056fa96) |
| DAT_008d0a80 | DynamicsSolverWorkspace_8D0A80 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d0750 | DynamicsSolverWorkspace_8D0750 | dynamics | double | write | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1868 | DynamicsSolverWorkspace_8D1868 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1de8 | DynamicsSolverWorkspace_8D1DE8 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d39a8 | DynamicsSolverIndex_8D39A8 | dynamics | int | read | 1 | Index/offset variable in dynamics constraint solver workspace (FUN_0056fa96) |
| DAT_008d1978 | DynamicsSolverWorkspace_8D1978 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d3ad0 | DynamicsSolverWorkspace_8D3AD0 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d0f68 | DynamicsSolverBlock_8D0F68 | dynamics | struct | read | 1 | Struct block in dynamics constraint solver workspace (FUN_0056fa96) |
| DAT_008d10b0 | DynamicsSolverBlock_8D10B0 | dynamics | struct | read | 1 | Struct block in dynamics constraint solver workspace (FUN_0056fa96) |
| DAT_008d11f8 | DynamicsSolverBlock_8D11F8 | dynamics | struct | read | 1 | Struct block in dynamics constraint solver workspace (FUN_0056fa96) |
| DAT_008d1450 | DynamicsSolverWorkspace_8D1450 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d18c0 | DynamicsSolverWorkspace_8D18C0 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1d60 | DynamicsSolverWorkspace_8D1D60 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d20c8 | DynamicsSolverWorkspace_8D20C8 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1ca0 | DynamicsSolverWorkspace_8D1CA0 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1bc0 | DynamicsSolverWorkspace_8D1BC0 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d1d98 | DynamicsSolverWorkspace_8D1D98 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d3b50 | DynamicsSolverWorkspace_8D3B50 | dynamics | double | read | 1 | Double workspace variable in dynamics constraint solver (FUN_0056fa96) |
| DAT_008d3b74 | DynamicsSolverIndex_8D3B74 | dynamics | int | read | 1 | Index/offset in LDL^T factorization solver (FUN_00575bbd, 13241 bytes) |
| DAT_008d25e8 | DynamicsFactorWorkspace_8D25E8 | dynamics | double | write | 1 | Double workspace in LDL^T factorization solver (FUN_00575bbd) |
| DAT_008d29a0 | DynamicsFactorBlock_8D29A0 | dynamics | struct | read | 1 | Struct block in LDL^T factorization solver (FUN_00575bbd) |
| DAT_008d2e38 | DynamicsFactorWorkspace_8D2E38 | dynamics | double | write | 1 | Double workspace in LDL^T factorization solver (FUN_00575bbd) |
| DAT_008d32f8 | DynamicsFactorBlock_8D32F8 | dynamics | struct | read | 1 | Struct block in LDL^T factorization solver (FUN_00575bbd) |
| DAT_008d3bf1 | DynamicsSolverByte | dynamics | byte | read | 1 | Byte in dynamics solver helper function (FUN_00579fb0) |
| DAT_005e5384 | VTableRef_5E5384 | runtime | ptr | read | 1 | VTable/function pointer reference (FUN_0057bf00) |
| DAT_005e5438 | AbortedString | runtime | char* | read | 1 | "Aborted" runtime error message string (FUN_0057cb50) |
| DAT_005e5a98 | TheConnectionHasString | network | char* | read | 1 | "TheConnectionHas..." network error string (FUN_0057d400) |
| DAT_005e625c | WsaEafNoSupportString | network | char* | read | 1 | "WSAEAFNOSUPPORT" network socket error string (FUN_0057d6c0) |
| DAT_005badd8 | MemoryPoolStruct | memory | struct | read | 1 | Memory pool/allocator struct — stride 0x284 per block, used in custom allocator (FUN_005824f0) |
| DAT_005e6384 | RuntimeIntConstant | runtime | int | read | 1 | Int constant in runtime function (FUN_00584230) |
| DAT_005e6744 | CRTFunctionPtr | runtime/CRT | ptr | write | 1 | MSVC CRT function pointer — initialized to __cfltcvt (float conversion) (FUN_00587b97) |
| DAT_005e65a0 | CRTFileHandle | runtime/CRT | int | read | 1 | File/stream handle used in CRT float parsing (FUN_005895a2) |
| DAT_008d3e80 | WinVersionMinor | runtime/CRT | byte | write | 1 | Windows version minor number — extracted from GetVersion() (FUN_0058a19e) |
| DAT_005b8d88 | CRTByteFlag | runtime/CRT | byte | read | 1 | Byte flag read in CRT/string function (FUN_0058d04d) |
| DAT_005e6d58 | ASCIIDataString | text | char* | read | 1 | ASCII string constant in CRT formatted output (FUN_0058e4d2) |
| DAT_008d3f88 | CRTFileHandleFlag | runtime/CRT | word | read | 1 | Word file handle/flag in CRT file I/O (FUN_0058f7c9) |
| DAT_005b9508 | CRTFPUConstant | runtime/CRT | double | read | 1 | Double constant in CRT FPU/exception handling (FUN_0059070a) |
| DAT_008d3fcc | TimeZoneWideCharBuf | runtime | wchar_t[] | read | 1 | Time zone name wide char buffer — converted to multibyte for locale (FUN_005921f3) |
| DAT_008d3ea0 | CmdLineArgvPtr | runtime | char** | write | 1 | Command-line argument vector pointer — set from GetModuleFileNameA (FUN_00592bad) |
| DAT_005b9988 | CRTExceptionStruct | runtime/CRT | struct | read | 1 | CRT exception handling struct — referenced in exception handler chain (FUN_00593c9c) |
| DAT_008d41dc | CRTInitFlag | runtime/CRT | int | write | 1 | CRT initialization state flag (FUN_00597234) |
| DAT_005bb388 | CRTClassStruct | runtime/CRT | struct | read | 1 | CRT class/struct reference (FUN_00598af5) |
| DAT_005bb6e8 | CRTExceptionVTable | runtime/CRT | struct | read | 1 | CRT exception class vtable/struct reference (FUN_0059a728) |
| DAT_005bb9c8 | CRTObjectStruct | runtime/CRT | struct | read | 1 | CRT object structure reference (FUN_0059af68) |
| DAT_005c7538 | CRTDwordWrite | runtime/CRT | int | write | 1 | CRT initialization dword write (FUN_008d8000) |
