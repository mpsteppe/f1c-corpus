=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CD2AC | SceneNodeListHead | renderer | ptr | read/write | 2 | Linked list head for scene graph nodes. Used in FUN_00465460 (scene traversal) and FUN_00465d70 (linked list merge sort). Accessed at +0xe410 offset from this base. |
| DAT_005BE5D0 | WorstAdjustFormatString | ui | char* | offset | 1 | Format string "worstadjust" used in UI/menu code for worst-adjustment display (FUN_00402690). |
| DAT_008AFF88 | UnknownFloat_8AFF88 | renderer | float | write | 1 | Written in FUN_00402690. Purpose unclear without more context. |
| DAT_005BE44C | WpBitfieldsFormatString | ui | char* | offset | 1 | Format string "wp_bitfields" used in UI code (FUN_00402690). |
| DAT_005BE8EC | RearviewFormatString | ui | char* | offset | 1 | Format string "rearview" used in UI display code (FUN_00409890). |
| DAT_005BEAC8 | CameraAcquireCFmt | ui | char* | offset | 1 | Format string "camera_acquire_c" used in camera config (FUN_0040D4C0). |
| DAT_005BE9C4 | TrackInfoFormatString | ui | char* | offset | 1 | Format string "track_info" used in track info display (FUN_0040D4C0). |
| DAT_008AD074 | FileSystemParam | fileio | int | read | 1 | Parameter read in file system/scene loading (FUN_0040FE50). Likely file read size or flag. |
| DAT_005C23AC | SpwsSFormatString | fileio | char* | offset | 1 | Format string "spwsS" used in file parsing (FUN_00414600). |
| DAT_005C258C | DavidCFormatString | fileio | char* | offset | 1 | Format string "davidC" used in file parsing (FUN_00415D90). |
| DAT_005C24BC | TarsoMFormatString | fileio | char* | offset | 1 | Format string "tarsoM" used in file parsing (FUN_00415D90). |
| DAT_0059E804 | DistanceSquaredThreshold | physics | float | read | 1 | Distance-squared comparison threshold in FUN_00419120 (race position/points logic). Compared against squared 3D distance between vehicle and scoring data. |
| DAT_005C28C0 | Year2000JordanString | setup | char* | offset | 1 | Team/year string "2000Jordan" used in vehicle/scene setup (FUN_0041B980). |
| DAT_005C27AC | Year2002JaguarString | setup | char* | offset | 1 | Team/year string "2002Jaguar" used in vehicle/scene setup (FUN_0041B980). |
| DAT_005C2A14 | VehiclesDirString | setup | char* | offset | 1 | Directory string "vehicles" used in file path construction (FUN_004216F0). |
| DAT_005C2C64 | OptionsDirString | setup | char* | offset | 1 | Directory string "optionsdir" used in options file path resolution (FUN_00421CD0). |
| DAT_005C2B64 | WindowedModeString | setup | char* | offset | 1 | Config key "windowedmode" used in options/config parsing (FUN_00421CD0). |
| DAT_005C2FD8 | OptionsAnimSString | setup | char* | offset | 1 | Config key "optionsanimS" used in animation/display options (FUN_00422BE0). |
| DAT_005C2E8C | VideoDriverDString | setup | char* | offset | 1 | Config key "videodriverD" used in video driver configuration (FUN_00422BE0). |
| DAT_005C3058 | UnknownByte_5C3058 | renderer | byte | read | 1 | Byte flag read in video mode/display configuration (FUN_004230C0). |
| DAT_005C31AC | ScriptDirString | setup | char* | offset | 1 | Directory string "script" used in script file path building (FUN_00424080). |
| DAT_0059E8E8 | LateralSpeedThreshold | physics | float | read | 1 | Lateral speed threshold for AI/vehicle control in FUN_00426CF0. Compared against lateral velocity at +0x442c; when exceeded, scales lateral control output. |
| DAT_005C32BC | DownshiftsConfigString | setup | char* | offset | 1 | Config key "downshifts" used in control configuration (FUN_0042B8D0). |
| DAT_005C33D4 | AntiLockBrakesCfgStr | setup | char* | offset | 1 | Config key "anti-lock brakes" used in driving aids configuration (FUN_0042C440). |
| DAT_007C9354 | LapScoringFlagsBatch | steward | int | write | 1 | One of 12 consecutive flag variables (DAT_007c932c-007c9358) zeroed together in the game loop (FUN_0042C690). Part of lap/scoring reset batch. |
| DAT_005C35B4 | BeginFormationString | steward | char* | offset | 1 | Session message "begin formation" used in race state transitions (FUN_0042D140). |
| DAT_005C3704 | RoadCourseConfigStr | setup | char* | offset | 1 | Config key "roadCourse" used in session/track configuration (FUN_0042E530). |
| DAT_005C3EB4 | SymmetricDConfigStr | setup | char* | offset | 1 | Config key "symmetricD" used in vehicle setup (FUN_0042FD00). |
| DAT_005C3D40 | SuspensionCfgStr | setup | char* | offset | 1 | Config key "suspension" used in vehicle setup configuration (FUN_0042FD00). |
| DAT_005C3B18 | Rear3rdFastRebCfgStr | setup | char* | offset | 1 | Config key "rear3rdfastreb" used in vehicle suspension setup (FUN_0042FD00). |
| DAT_005C3978 | RearLeftCfgStr | setup | char* | offset | 1 | Config key "rearleft" used in vehicle setup (FUN_0042FD00). |
| DAT_0059EA50 | ContactSurfaceFriction | physics | double | read | 1 | Contact friction multiplier used in FUN_00430750 (tire contact model). Multiplied into contact force computation along with other physics constants. |
| DAT_007D03F8 | SessionConfigGate | session | byte | read | 1 | Session configuration byte checked in FUN_00432220. Controls session config path. |
| DAT_005C4110 | MaxPosConfigStr | setup | char* | offset | 1 | Config key "maxpos" used in position/display configuration (FUN_00435410). |
| DAT_0059EB80 | SteeringReturnDamping | physics | double | read | 1 | Steering return damping constant used in FUN_00438130 (steering/alignment dynamics). Scales steering self-alignment torque based on wheel velocity and suspension geometry. |
| DAT_0059EBF0 | AntiRollBarStiffness | physics | double | read | 1 | Anti-roll bar stiffness constant used in FUN_00439210 (suspension anti-roll dynamics). |
| DAT_0059EC28 | FuelConsumptionRate | physics | double | read | 1 | Fuel consumption rate multiplier used in FUN_0043C250 (engine/fuel model). |
| DAT_0059ED38 | SpeedSmoothingGain | physics | double | read | 1 | Speed smoothing gain used in FUN_00441650 (vehicle speed/dynamics smoothing). Clamped against threshold; multiplied into speed delta for gradual speed change. |
| DAT_007CC33C | VehicleClassIndex | vehicle | int | read | 1 | Vehicle class index read in FUN_004441F0 (9101-byte vehicle dynamics function). Controls vehicle class-specific behavior. |
| DAT_0059EE38 | TorqueSplitRatio | physics | double | read | 1 | Torque split ratio used in FUN_004441F0 (large vehicle dynamics function). Controls front/rear torque distribution. |
| DAT_0059EEE0 | SteeringDeadzoneThreshold | physics | float | read | 1 | Steering deadzone threshold in FUN_004472B0 (steering/input processing). Below this threshold, steering input is zeroed. |
| DAT_005C4494 | ScnFileExtension | fileio | char* | offset | 1 | File extension ".scn" used in scene file path construction (FUN_0044C0E0). |
| DAT_007CA500 | RenderStateColorValue | renderer | int | write | 1 | One of 4 render state values (DAT_007ca4f8-007ca504) initialized in FUN_0044D220. Likely D3D render state color/alpha. |
| DAT_007CCCE0 | CollisionGridParam | collision | int | write | 1 | One of 6 collision grid parameters (DAT_007cccd8-007cccec) initialized in FUN_0044D4C0. Grid parameter value. |
| DAT_007D2050 | UIScrollPosition | ui | int | read | 1 | UI scroll position/offset read in FUN_0044FF50 (5968-byte UI/audio processing function). Controls UI element scroll state. |
| DAT_005AD388 | UITexturePointer | renderer | int | read | 1 | Texture/surface pointer read in FUN_0044FF50 (UI rendering). Indexes texture or surface resources. |
| DAT_005AD394 | UIFontPointer | renderer | int | read | 1 | Font/surface pointer read in FUN_0044FF50 (UI rendering). Indexes font or glyph resources. |
| DAT_007D20D4 | CameraShakeMagnitude | camera | float | read | 1 | Camera shake magnitude in FUN_00451720 (camera/cockpit effects). Controls vibration intensity based on vehicle state. |
| DAT_007CD04C | CollisionShapeTable | collision | ptr | read | 1 | Collision shape/geometry table pointer used in FUN_00452B10 (collision object matching). Compared against multiple shape type pointers to identify collision geometry. |
| DAT_007CD0A8 | CollisionZeroFlag | collision | int | write | 1 | Written to 0 in FUN_004537B0 (collision/audio parameter init). Part of a batch of collision parameter zeroing. |
| DAT_007CA3DC | SuspensionBumpTravel | physics | float | write | 1 | Suspension bump travel parameter in FUN_004537B0. Copied from vehicle struct +0x1140-0x1158 and clamped against min threshold. Paired with companion globals for left/right, front/rear wheels. |
| DAT_005C5650 | ShiftUpConfigStr | setup | char* | offset | 1 | Config key "shift up" used in control configuration (FUN_00455290). |
| DAT_005C5538 | BrakeBiasRConfigStr | setup | char* | offset | 1 | Config key "brake bias r" used in control configuration (FUN_00455290). |
| DAT_007CCAB0 | KeyboardStateBuffer | input | byte[256] | offset | 1 | 256-byte keyboard state buffer passed to GetKeyboardState() and ToAsciiEx() in FUN_00455B30 (keyboard input handler). |
| DAT_005C5864 | OrientationRateFormat | ui | char* | offset | 1 | Format string "s_orientationrate" used in UI text rendering (FUN_00456670). |
| DAT_0059F058 | CollisionRestitution | physics | double | read | 1 | Collision restitution coefficient used in FUN_00459AE0 (3411-byte collision response function). Controls bounciness of collision contacts. |
| DAT_0059F0BC | MouseSensitivity | input | float | read | 1 | Mouse sensitivity multiplier read in FUN_0045C7A0 (mouse input processing). |
| DAT_005C5D2C | NetMessageBufferSize | network | byte | read | 1 | Network message buffer size limit read in FUN_0045D890 (NetComm message processing). |
| DAT_0059F114 | AIOvertakeDetection | ai | float | read | 1 | AI overtake detection threshold in FUN_0045F030 (AI driver update). Compared against vehicle speed at +0x384; gates AI overtaking logic when below threshold. |
| DAT_005C60F8 | ClosingTrackMsgString | network | char* | offset | 1 | Network message "closing track" used in session management (FUN_00461020). |
| DAT_007D0858 | ServerAddressParam | network | float | read | 1 | Server address/port parameter read in FUN_00461900 (session configuration parsing). Paired with DAT_007d0854. |
| DAT_007CEC3C | PitWindowTimer | race | int | read | 1 | Pit window open/close timer value read in FUN_00461900 (session config). Used in pit window timing logic. |
| DAT_005C6318 | ComparingNodeIStr | network | char* | offset | 1 | Debug/log string "comparing nodei" used in network code (FUN_00462E20). |
| DAT_005C65D8 | AutojoinWaitStr | network | char* | offset | 1 | Network status string "autojoin wait" used in multiplayer lobby (FUN_004637A0). |
| DAT_007D0EE0 | SessionMessageFlag | session | int | read | 1 | Session message flag read in FUN_00463F70 (session message dispatch). Controls message routing. |
| DAT_005C6660 | VTableFuncPtrArray | renderer | ptr | read | 1 | VTable/function pointer table read in FUN_0046A2A0. Used for renderer method dispatch. |
| DAT_0059FB50 | SuspensionSpringK | physics | double | read | 1 | Suspension spring rate constant K used in FUN_0046B830 (suspension force computation). |
| DAT_005A00F0 | VehicleVTablePtr | vehicle | ptr | offset | 1 | Vehicle class vtable pointer (FUN_0046FCF9, IDA-only). Set as `v4 = &off_5A00F0` during vehicle object construction. |
| DAT_005C71B0 | NumCoordinatesStr | fileio | char* | offset | 1 | Format string "numcoordinates" used in file parsing (FUN_00479170). |
| DAT_005C7328 | StopCmdString | fileio | char* | offset | 1 | Command string "stop" used in script/command processing (FUN_0047DAF0). |
| DAT_005C7404 | ConstructorChaStr | ui | char* | offset | 1 | Debug string "constructor_championship" used in UI text (FUN_0047E0A0). |
| DAT_005CC218 | ModalDialogClass | ui | char* | offset | 1 | Window class string used in modal dialog creation (FUN_0048B9C0). |
| DAT_005CC670 | ModalString | ui | char* | offset | 1 | UI string "modal" used in dialog/window management (FUN_00492460). |
| DAT_005CC7F4 | SoundClickString | ui | char* | offset | 1 | UI string "sound_click" used in sound/UI config (FUN_00493060). |
| DAT_005CC82C | ExitGameString | ui | char* | offset | 1 | UI string "exit game" used in menu system (FUN_00493480). |
| DAT_005CC2CC | UTF8ByteFlag | string | byte | read | 1 | Byte flag read in string/character conversion (FUN_004944A0). Controls UTF-8 processing mode. |
| DAT_007CB274 | UITextColor | ui | float | read | 1 | UI text color component read in FUN_00498740. Used to set text rendering color values. |
| DAT_007C9204 | EngineWearThreshold | physics | double | read | 1 | Engine wear comparison threshold in FUN_0049B9A0. Compared against DAT_007c9174 to determine if engine wear is active. |
| DAT_005CCB74 | VTableFunc_Anim1 | renderer | ptr | read | 1 | Animation/render vtable pointer read in FUN_0049CA00. |
| DAT_005CCB6C | VTableFunc_Anim2 | renderer | ptr | read | 1 | Animation/render vtable pointer read in FUN_0049CA00. |
| DAT_005CCFA8 | EnteredOnscreenStr | ui | char* | offset | 1 | UI string "entered_onscreen" used in telemetry/display (FUN_0049F120). |
| DAT_007CE268 | SessionInitByte | session | byte | write | 1 | Written in FUN_004A0D50 as part of session initialization. |
| DAT_007CE2D0 | SessionStateField | session | byte | offset | 1 | Session state byte used in session initialization logic (FUN_004A1200). |
| DAT_005CD2FC | RearJackDownStr | ui | char* | offset | 1 | UI string "rear jack down" used in pit animation system (FUN_004A24D0). |
| DAT_005CD1C8 | TenSecStarterStr | ui | char* | offset | 1 | UI string "10sec_starterrelease" used in start sequence (FUN_004A24D0). |
| DAT_005CD374 | SAnmStr | ui | char* | offset | 1 | Animation string "s_anm" used in scene/animation loading (FUN_004A2A90). |
| DAT_005CD534 | HardCompoundStr | setup | char* | offset | 1 | Tire compound string "hard compound" used in tire config (FUN_004A4830). |
| DAT_005CD64C | DDStr | ui | char* | offset | 1 | Display string "DD" used in UI rendering (FUN_004A58B0). |
| DAT_005ACB6C | ScreenEffectVTable | renderer | ptr | offset | 1 | VTable pointer for screen effect/base class in FUN_004A70E0 (6669-byte UI/screen effect init). Used to set method dispatch. |
| DAT_005D1EE4 | ThrottleControlStr | setup | char* | offset | 1 | Config key "throttle control" in control settings (FUN_004AA270). |
| DAT_005D1C3C | AutoShiftOverrideStr | setup | char* | offset | 1 | Config key "auto shift override" in control settings (FUN_004AA270). |
| DAT_005D19A0 | RaceConditionsStr | setup | char* | offset | 1 | Config key "race conditions" in session settings (FUN_004AA270). |
| DAT_005D1744 | LevelOfRuleEnforceStr | setup | char* | offset | 1 | Config key "level of rule enforcement" in session settings (FUN_004AA270). |
| DAT_005D1554 | PlayerVolumeRangeStr | audio | char* | offset | 1 | Config key "player volume range" in audio settings (FUN_004AA270). |
| DAT_005D1358 | PublicAddressAmpStr | audio | char* | offset | 1 | Config key "public address amp" in audio settings (FUN_004AA270). |
| DAT_005D11C0 | SoundOptionsArray | audio | ptr | offset | 1 | Sound options data array used in settings parser (FUN_004AA270). |
| DAT_005D0F40 | NumbersLessThanStr | ui | char* | offset | 1 | Format string "numbers less than" used in UI display (FUN_004AA270). |
| DAT_005D0C78 | AngleToLeanHeadStr | input | char* | offset | 1 | Config key "angle to lean head" in controller settings (FUN_004AA270). |
| DAT_005D09E0 | MapOpponentDetStr | radar | char* | offset | 1 | Config key "map opponent detail" in display settings (FUN_004AA270). |
| DAT_005D0790 | NightLightLevelStr | renderer | char* | offset | 1 | Config key "00 night light level" in display settings (FUN_004AA270). |
| DAT_005D0558 | QuickRaceStartStr | ui | char* | offset | 1 | Config key "quick race start" in session settings (FUN_004AA270). |
| DAT_005D0280 | CommentaryDetailStr | audio | char* | offset | 1 | Config key "commentary detail" in audio settings (FUN_004AA270). |
| DAT_005CFFF4 | SpeedUnitsStr | ui | char* | offset | 1 | Config key "speed units" in display settings (FUN_004AA270). |
| DAT_005CFD60 | ExtraStatsStr | ui | char* | offset | 1 | Config key "extra stats" in display settings (FUN_004AA270). |
| DAT_005CF9A8 | NetLazyFlushStr | network | char* | offset | 1 | Config key "net lazy flush" in network settings (FUN_004AA270). |
| DAT_005CF600 | EnableThrottlingStr | network | char* | offset | 1 | Config key "enable throttling" in network settings (FUN_004AA270). |
| DAT_005CF1C8 | CriticalDampingStr | physics | char* | offset | 1 | Config key "10 critical damp" in FFB/controller settings (FUN_004AA270). |
| DAT_005CEEF8 | IfLeftLookAndRightStr | input | char* | offset | 1 | Config key "if left look and right" in control settings (FUN_004AA270). |
| DAT_005CEBAC | Controller1RyStr | input | char* | offset | 1 | Config key "controller 1 ry" in controller axis mapping (FUN_004AA270). |
| DAT_005CE9C8 | ControlFirstGearStr | input | char* | offset | 1 | Config key "control first gear" in controller settings (FUN_004AA270). |
| DAT_005CE7EC | ControlLookRightStr | input | char* | offset | 1 | Config key "control look right" in controller settings (FUN_004AA270). |
| DAT_005CE59C | StrengthOfForceStr | input | char* | offset | 1 | Config key "strength of force" in FFB settings (FUN_004AA270). |
| DAT_005CE0D0 | MaximumForceOutStr | input | char* | offset | 1 | Config key "maximum force out" in FFB settings (FUN_004AA270). |
| DAT_005CDC88 | FfbThrottleVibStr | input | char* | offset | 1 | Config key "ffb throttle vib" in FFB settings (FUN_004AA270). |
| DAT_005CD890 | FfbRumbleStripStr | input | char* | offset | 1 | Config key "ffb rumble strip" in FFB settings (FUN_004AA270). |
| DAT_005D236C | EnteredPlayerFileStr | ui | char* | offset | 1 | UI string "entered_playerfile" in player file display (FUN_004B18D0). |
| DAT_005ACCE4 | VehicleSkinScaleFactor | renderer | float | read | 1 | Scale factor for vehicle skin/color selection in FUN_004B2C50. Multiplied by bitfield-extracted value to produce color index. |
| DAT_005ACD54 | WheelSlipThreshold | physics | float | read | 1 | Wheel slip comparison threshold in FUN_004B66E0 (tire/brake slip detection). One of 4 slip thresholds (0-3) for different surfaces. |
| DAT_005D24AC | PreppingReplayStr | ui | char* | offset | 1 | UI string "prepping replay" in replay/playback system (FUN_004BA1F0). |
| DAT_005D2598 | NotLinedUpPropStr | ui | char* | offset | 1 | UI string "not lined up properly" in grid/start sequence (FUN_004BC9B0). |
| DAT_005ACDDC | AIDecisionRandomizer | ai | float | read | 1 | AI decision randomizer threshold in FUN_004BEC55 (IDA-only, 765-byte AI function). Compared against ring-buffer noise value for probabilistic AI decisions. |
| DAT_005D26C8 | PointsPositionStr | ui | char* | offset | 1 | UI string "pointsposition" used in standings display (FUN_004C03F0). |
| DAT_005D2818 | CurrentRaceStr | ui | char* | offset | 1 | UI string "currentrace" used in race info display (FUN_004C0B70). |
| DAT_005D2DD8 | TotalLapRecordStr | ui | char* | offset | 1 | UI string "totallaprecord" used in lap record display (FUN_004C2420). |
| DAT_005D2B6C | TrackNameFormatStr | ui | char* | offset | 1 | UI string "trackname" used in track info display (FUN_004C2420). |
| DAT_005D2F88 | FullTeamNameStr | ui | char* | offset | 1 | UI string "fullteamname" used in team info display (FUN_004C3200). |
| DAT_005D30A0 | CouldNotFindStr | ui | char* | offset | 1 | Error string "could not find" in file/resource resolution (FUN_004C40D0). |
| DAT_005ACDEC | ScreenColorTable | renderer | int[] | read | 1 | Lookup table (4 entries) for screen color cycling in FUN_004C8650. Indexed by DAT_008ac4c0 counter, wraps at 4. |
| DAT_005ACE28 | TriggerFunctionPtr | renderer | ptr | read | 1 | Function pointer/interface for trigger/event system (FUN_004C99D0, IDA-only). Calls vtable+36 for trigger processing. |
| DAT_005D366C | WetGrooveStr | renderer | char* | offset | 1 | Texture/effect string "wetgroove" used in track surface config (FUN_004CA480). |
| DAT_005D3558 | AlphaChannelStr | renderer | char* | offset | 1 | Config key "alphachannel" used in renderer settings (FUN_004CA480). |
| DAT_005D376C | OneStr | ui | char* | offset | 1 | UI number string "one" used in text/display formatting (FUN_004CADA0). |
| DAT_007CFA28 | AITargetSelection | ai | int | read | 1 | AI target selection parameter in FUN_004CB860 (IDA-only, 1008-byte AI function). Controls target vehicle selection logic. |
| DAT_005D3878 | GrassStr | renderer | char* | offset | 1 | Surface string "grass" used in track surface/material definitions (FUN_004CDD80). |
| DAT_005D3974 | LooseStr | renderer | char* | offset | 1 | Surface string "loose" used in track surface definitions (FUN_004CF070). |
| DAT_005D3ABC | GridSignFormatStr | ui | char* | offset | 1 | Format string "gridsign%02d" used in grid position sign rendering (FUN_004D0110). |
| DAT_005D3C04 | LogoSSBmpStr | ui | char* | offset | 1 | Image path "logo_s_s.bmp" for small logo bitmap (FUN_004D1450). |
| DAT_005D4090 | RaceTimeDFormatStr | ui | char* | offset | 1 | Format string "race time %d" in HUD/timing display (FUN_004D24D0). |
| DAT_005D3E68 | DriveAidsAutoRStr | ui | char* | offset | 1 | Format string "driveaids_auto_r" in HUD/aids display (FUN_004D24D0). |
| DAT_005D3CEC | LapDFormatStr | ui | char* | offset | 1 | Format string "lap %d %f %f" in HUD/lap display (FUN_004D24D0). |
| DAT_005D42E4 | StliteStr | ui | char* | offset | 1 | UI string "stlite" in rendering/text display (FUN_004D38F0). |
| DAT_005D4374 | CarNumberFontIndex | ui | byte | read | 1 | Font index for car number rendering (FUN_004D3CF0). |
| DAT_007CE9F4 | PitCrewAnimState | pit | int | read | 1 | Pit crew animation state index in FUN_004D4A80. Controls pit crew animation selection. |
| DAT_005D44C4 | RrStr | ui | char* | offset | 1 | Abbreviation string "rr" used in tire/position labels (FUN_004D4A80). |
| DAT_005D4708 | StepStr | ui | char* | offset | 1 | UI string "step" used in control step/sequencing (FUN_004D5F70). |
| DAT_005D47F0 | LongPeakStr | ui | char* | offset | 1 | UI string "longpeak" in audio/visualization (FUN_004D6B00). |
| DAT_005D491C | NoCompoundsFoundStr | ui | char* | offset | 1 | Error string "no compounds found" in tire selection (FUN_004D7150). |
| DAT_005D4AA0 | HudOnStr | ui | char* | offset | 1 | UI string "hud on" in HUD configuration (FUN_004D8450). |
| DAT_005D4AEC | DefaultTextColor | ui | byte | read | 1 | Default text color code used in FUN_004D99E0 (HUD text rendering). Passed to string formatting function. |
| DAT_005D4CAC | WcdriverStr | ui | char* | offset | 1 | UI string "wcdriver" used in world championship/driver display (FUN_004DDAD0). |
| DAT_005C67E0 | DoesNotHaveMatStr | renderer | char* | offset | 1 | Error string "does not have material" in renderer/material loading (FUN_004DDF90). |
| DAT_005D4DB4 | LrSpindleStr | setup | char* | offset | 1 | Config key "lrspindle" in vehicle setup (FUN_004DFCE0). |
| DAT_005D4D14 | TreadlowStr | setup | char* | offset | 1 | Config key "treadlow" in tire setup (FUN_004DFCE0). |
| DAT_007C921C | SpeedComparisonThreshold | physics | double | read | 1 | Speed comparison threshold in FUN_004E49B0 (vehicle orientation/speed calculation). Compared against speed vector for orientation computation. |
| DAT_005AD1E4 | CollisionResponseThreshold | physics | float | read | 1 | Threshold for collision response activation in FUN_004EB430 (2029-byte collision/effect handler). Gates collision effect processing. |
| DAT_005AD248 | DamageResponseScale | physics | double | read | 1 | Damage response scaling factor in FUN_004F1510 (damage/impact handler). Scales damage effects applied to vehicle subsystems. |
| DAT_005D4F64 | RearWingRandomStr | setup | char* | offset | 1 | Config key "rearwingrandomizer" in vehicle setup (FUN_004F24F0). |
| DAT_005D5284 | BumpStage2Str | setup | char* | offset | 1 | Config key "bumpstage2" in suspension setup (FUN_004F2C60). |
| DAT_005D5148 | RideHeightSettingStr | setup | char* | offset | 1 | Config key "rideheightsetting" in suspension setup (FUN_004F2C60). |
| DAT_005D5334 | FenderLiftParamsStr | setup | char* | offset | 1 | Config key "fenderliftparams" in vehicle setup (FUN_004F3090). |
| DAT_005D56EC | IdleRPMLogicStr | setup | char* | offset | 1 | Config key "idlerpmlogic" in engine setup (FUN_004F3C80). |
| DAT_005D5564 | OilMinCoolStr | setup | char* | offset | 1 | Config key "oilminimumcool" in engine thermal setup (FUN_004F3C80). |
| DAT_005D66AC | GraphicalOffsetStr | setup | char* | offset | 1 | Config key "graphicaloffset" in vehicle/graphics setup (FUN_004F4270). |
| DAT_005D657C | DamageFileStr | setup | char* | offset | 1 | Config key "damagefile" in vehicle setup (FUN_004F4270). |
| DAT_005D6444 | FWLiftParamsStr | setup | char* | offset | 1 | Config key "fwliftparams" in vehicle aero setup (FUN_004F4270). |
| DAT_005D635C | RWLeftStr | setup | char* | offset | 1 | Config key "rwleft" in vehicle setup (FUN_004F4270). |
| DAT_005D6278 | BodyForeStr | setup | char* | offset | 1 | Config key "bodyfore" in vehicle body setup (FUN_004F4270). |
| DAT_005D613C | AdjustSuspRateStr | setup | char* | offset | 1 | Config key "adjustsusprate" in suspension setup (FUN_004F4270). |
| DAT_005D5F98 | Rear3rdReboundStr | setup | char* | offset | 1 | Config key "rear3rdrebound" in suspension setup (FUN_004F4270). |
| DAT_005D5DE4 | LeftCasterRangeStr | setup | char* | offset | 1 | Config key "leftcasterrange" in suspension geometry setup (FUN_004F4270). |
| DAT_005D5C14 | Rear3rdPackerRngStr | setup | char* | offset | 1 | Config key "rear3rdpackerrange" in suspension setup (FUN_004F4270). |
| DAT_005D5A74 | SteerLockRangeStr | setup | char* | offset | 1 | Config key "steerlockrange" in steering setup (FUN_004F4270). |
| DAT_005D5934 | UpshiftClutchTimeStr | setup | char* | offset | 1 | Config key "upshiftclutchtim" in gearbox setup (FUN_004F4270). |
| DAT_005D57F8 | DiffPowerSetStr | setup | char* | offset | 1 | Config key "diffpowersetting" in differential setup (FUN_004F4270). |
| DAT_005D67E0 | MaximumRPMStr | setup | char* | offset | 1 | Config key "maximumrpm" in engine setup (FUN_004F6BF0). |
| DAT_005D6C40 | NonPlayerEngineStr | setup | char* | offset | 1 | Config key "non-player engine" in engine setup (FUN_004F7460). |
| DAT_005D6AD3 | NonPlayerStr1 | setup | char* | offset | 1 | Config key substring in non-player engine setup (FUN_004F7460). |
| DAT_005D6947 | NonPlayerStr2 | setup | char* | offset | 1 | Config key substring in non-player engine setup (FUN_004F7460). |
| DAT_008AFC7C | CachedFrameCount | renderer | int | write | 1 | Cached frame/update counter written in FUN_004F8B50 (rendering pipeline). |
| DAT_005D6E2C | AnimStateDuration | renderer | int | read | 1 | Animation state duration value read in FUN_004F9480 (animation timing). |
| DAT_005D6E9C | EnteredVidManStr | renderer | char* | offset | 1 | Debug string "entered vidman init" in video manager (FUN_004FA320). |
| DAT_008AFEC8 | RenderStateChangeFlag | renderer | float | read | 1 | Render state change flag in FUN_004FBD70 (1024-byte renderer update). Compared against stored state to detect changes requiring render state update. |
| DAT_005AD298 | ParticleEmitRate | renderer | float | read | 1 | Particle emission rate constant in FUN_004FCEE0 (particle system update). |
| DAT_005D6FA4 | BestStr | ui | char* | offset | 1 | UI label string "best" in timing/HUD display (FUN_004FE0D0). |
| DAT_005D6FBC | ColdStr | ui | char* | offset | 1 | UI label string "cold" in tire temperature display (FUN_004FE2B0). |
| DAT_005D705C | ConditionsFormatStr | ui | char* | offset | 1 | Format string "conditions%s%f" in session/weather display (FUN_004FE820). |
| DAT_005ADB40 | GPUMemoryModuleName | renderer | char* | offset | 1 | Module name string in GPU memory management code (FUN_00500EAC). |
| DAT_005AD4B0 | GPUBufferDescriptor | renderer | ptr | offset | 1 | GPU buffer descriptor/interface pointer in DirectX resource management (FUN_00506971). |
| DAT_005ADC40 | GPUColorScaleFactor | renderer | float | read | 1 | Color value scale factor in FUN_0050AB51 (texture/color pipeline). Multiplied with color channel values for byte-to-float conversion. |
| DAT_005ADD5C | GPUBufferVTable | renderer | ptr | offset | 1 | VTable pointer for GPU buffer class in FUN_0050B409. |
| DAT_005D7888 | RendererFuncPtr | renderer | ptr | read | 1 | Function pointer table in renderer (FUN_0050C20D). Indirect dispatch to renderer implementation. |
| DAT_005D78A4 | JumpTablePtr | renderer | ptr | read | 1 | Jump table function pointer called via indirect call in FUN_0050E04F. |
| DAT_005AF29C | ZlibVersionErrStr | zlib | char* | offset | 1 | zlib error string "zlib version error!" (FUN_005118E6). Skip - library code. |
| DAT_005AF474 | NullRowBufferStr | fileio | char* | offset | 1 | Error string "null row buffer" in file/PNG loading (FUN_0051389E). |
| DAT_005D79D0 | TextureQuantScale | renderer | float | read | 1 | Texture quantization scale factor in FUN_005147EA (2052-byte texture processing). Scales normalized float values during texture conversion. |
| DAT_005AFC4C | InvalidIHDRChunkStr | png | char* | offset | 1 | PNG error string "invalid IHDR chunk" (FUN_005188B4). Skip - library code. |
| DAT_005AFE74 | MissingIHDRStr | png | char* | offset | 1 | PNG error string "missing IHDR before" (FUN_00518D29). Skip - library code. |
| DAT_005AFFA0 | CRC32LookupTable | math | uint[256] | read | 1 | CRC32 lookup table (256 entries) used in FUN_0051923D (CRC32 checksum computation). Standard CRC-32 algorithm table. |
| DAT_008B00E0 | SIMDCompareConst | math | float | read | 1 | SIMD comparison constant in FUN_0051F700 (IDA-only, SSE math). Compared against float for zero-detection in SSE vector operations. |
| DAT_008D60F0 | SIMDXorMask_X | math | xmmword | read | 1 | SSE XOR mask for cross-product sign flips in FUN_0051FBF0 (IDA-only, 3D vector cross product with SIMD). Used for permutation of vector components. |
| DAT_008D6194 | SIMDRecipScale | math | float | read | 1 | SSE reciprocal estimation scale factor in FUN_0052042E (IDA-only, vector normalization). Used in Newton-Raphson refinement of reciprocal sqrt. |
| DAT_005D8D20 | SIMDAndMask5D8D20 | math | xmmword | read | 1 | SSE AND mask in FUN_00520C0E (IDA-only, SIMD vector math). Used for absolute value / sign bit removal. |
| DAT_005AF928 | CollisionSATWorkspace | collision | double[?] | read | 1 | Workspace memory for SAT collision detection in FUN_005219E1 (2649-byte SAT/GJK collision test). Used for packed floating-point computations. |
| DAT_005D8F70 | TexelDecodeCoefficients | renderer | float[32] | read | 1 | Coefficients for DXT/S3TC texel decoding in FUN_005289E0 (492-byte texture decompression). Part of polynomial decode matrix for color reconstruction. |
| DAT_005D9230 | TexelDecodeCoeffSet2 | renderer | float[32] | read | 1 | Second set of texel decode coefficients in FUN_00528CC0 (329-byte texture decode). Used for different DXT format or color channel. |
| DAT_005D9360 | EmptyFuncPtr | renderer | ptr | read | 1 | Function pointer table entry in FUN_00529200 (IDA-only, empty stub function). |
| DAT_005B0AD4 | OversubscribedStr | network | char* | offset | 1 | Network error string "oversubscribed" in session join logic (FUN_0052A4A5). |
| DAT_005B0BC8 | AudioMixWorkspace | audio | double[?] | read | 1 | Workspace memory for audio mixing/SIMD processing in FUN_0052AB4E (1720-byte audio mixing function). Used in packed arithmetic operations. |
| DAT_005DA65C | WaitingForCDStr | fileio | char* | offset | 1 | Status string "waiting for cd access" in CD/media access (FUN_0052DC90). |
| DAT_005B47B8 | AudioDecodeBitTable | audio | int | read | 1 | Bit table/index in FUN_00531250 (1385-byte audio codec decode). Used in bitstream parsing for audio sample extraction. |
| DAT_008B5994 | AudioMixBuffer | audio | float | write | 1 | Audio mix buffer output written in FUN_00531B50 (3910-byte audio/SIMD mixing function). Part of audio DSP pipeline. |
| DAT_005B7754 | AudioMixCoeff_7754 | audio | float | read | 1 | Audio mixing coefficient in FUN_00531B50 (3910-byte audio DSP). One of ~32 paired coefficients for audio channel mixing. |
| DAT_005B7770 | AudioMixCoeff_7770 | audio | float | read | 1 | Audio mixing coefficient in FUN_00531B50 (audio DSP pipeline). Part of coefficient matrix for audio processing. |
| DAT_008B59E4 | AudioMixOutput_59E4 | audio | float | write | 1 | Audio mix output value written in FUN_00531B50 (audio DSP mixing). |
| DAT_008B5A00 | AudioMixOutput_5A00 | audio | float | write | 1 | Audio mix output value written in FUN_00531B50 (audio DSP mixing). |
| DAT_005B77EC | AudioDecodeTable | audio | word | read | 1 | Table word read in FUN_00536260 (audio codec decode table). Part of codec coefficient lookup. |
| DAT_005B8718 | MFCModuleHandle | runtime | ptr | offset | 1 | Module/instance handle in MFC/compat code (FUN_0053A4D0). |
| DAT_008B8F10 | ObjMgrParam | memory | int | write | 1 | Object manager parameter written in FUN_0053C680. One of 3 stored as linked-list globals. |
| DAT_008B8F38 | ObjMgrBufferEnd | memory | ptr | read | 1 | Buffer end pointer in FUN_0054A580 (data buffer management). Used for boundary calculation in buffer read operations. |
| DAT_008CBF48 | TCPBufferAddress | network | int | read | 1 | TCP buffer/address parameter in network socket operations (FUN_00551FD0). |
| DAT_005DC260 | IntensityStr | renderer | char* | offset | 1 | Config key "intensity" in scene/lighting config (FUN_0055A500). |
| DAT_005DC2F4 | StampStr | renderer | char* | offset | 1 | Config key "stamp" in renderer/texture config (FUN_0055A910). |
| DAT_005DC3BC | FogInStr | renderer | char* | offset | 1 | Config key "fogin" in fog/atmosphere config (FUN_0055B200). |
| DAT_005DC584 | SceneGraphNodePtr | renderer | int | read | 1 | Scene graph node pointer in renderer scene traversal (FUN_0055F0D0). |
| DAT_005DC540 | SceneMaterialPtr | renderer | int | read | 1 | Scene material pointer in renderer scene traversal (FUN_0055F0D0). |
| DAT_005DC4F6 | SceneNodeFlags | renderer | byte | read | 1 | Scene node flags in renderer scene traversal (FUN_0055F0D0). |
| DAT_005DC48C | SceneTransformPtr | renderer | int | read | 1 | Scene transform matrix pointer in renderer (FUN_0055F0D0). |
| DAT_008CF088 | FilePathStringBuffer | fileio | char[256] | offset | 1 | 256-byte string buffer for file path construction (FUN_00562530). Alternates between two buffers via XOR toggle of DAT_008cf080. |
| DAT_008CFA90 | SocketBufferArray | network | int[] | offset | 1 | Socket buffer/state array in network/comm code (FUN_00563870). Entries zeroed on init, filled with socket handles. |
| DAT_005E5128 | LfStr | ui | char* | offset | 1 | String "lf" used in skin/texture file naming (FUN_00565AA0). |
| DAT_005E51EC | Com7Str | fileio | char* | offset | 1 | Device path "com7" in serial port/controller detection (FUN_005687F0). |
| DAT_005E5340 | BarStr | ui | char* | offset | 1 | Unit string "bar" used in tire pressure display (FUN_0056D930). |
| DAT_008CFCB8 | DynamicsSolver_CFCB8 | dynamics | double | read | 1 | Constraint solver double constant in FUN_0056FA96 (17786-byte LDL^T dynamics solver). Matrix workspace in vehicle dynamics constraint solver. |
| DAT_008D0FF8 | DynamicsSolver_DFF8 | dynamics | double | read | 1 | Constraint solver double constant in FUN_0056FA96. Workspace for LDL^T factorization in dynamics solver. |
| DAT_008D3A00 | DynamicsSolver_D3A00 | dynamics | int | offset | 1 | Index/offset in FUN_0056FA96 dynamics solver. Used for matrix index computation in LDL^T. |
| DAT_008D13A0 | DynamicsSolver_D13A0 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1720 | DynamicsSolver_D1720 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1168 | DynamicsSolver_D1168 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D03E8 | DynamicsSolver_D03E8 | dynamics | byte | offset | 1 | Matrix workspace in FUN_0056FA96 dynamics solver. Part of constraint matrix data block (0x8D0000-0x8D9000). |
| DAT_008D1840 | DynamicsSolver_D1840 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1A28 | DynamicsSolver_D1A28 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D0820 | DynamicsSolver_D0820 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D0A90 | DynamicsSolver_D0A90 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D3AA8 | DynamicsSolver_D3AA8 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D0B88 | DynamicsSolver_D0B88 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D11D8 | DynamicsSolver_D11D8 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1C50 | DynamicsSolver_D1C50 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1680 | DynamicsSolver_D1680 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1688 | DynamicsSolver_D1688 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1568 | DynamicsSolver_D1568 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D18B0 | DynamicsSolver_D18B0 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1B88 | DynamicsSolver_D1B88 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1F08 | DynamicsSolver_D1F08 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D3B08 | DynamicsSolver_D3B08 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D1C98 | DynamicsSolver_D1C98 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D19D8 | DynamicsSolver_D19D8 | dynamics | byte | offset | 1 | Matrix workspace in FUN_0056FA96 dynamics solver. Part of constraint matrix data block. |
| DAT_008D3A10 | DynamicsSolver_D3A10 | dynamics | int | offset | 1 | Matrix workspace index/offset in FUN_0056FA96 dynamics solver. |
| DAT_008D3B40 | DynamicsSolver_D3B40 | dynamics | double | read | 1 | Matrix workspace double in FUN_0056FA96 dynamics solver. Part of constraint matrix storage. |
| DAT_008D3A24 | DynamicsSolver_D3A24 | dynamics | int | offset | 1 | Matrix workspace index/offset in FUN_0056FA96 dynamics solver. |
| DAT_008D23A8 | DynamicsSolver_D23A8 | dynamics | byte | offset | 1 | Matrix workspace in FUN_00575BBD (13241-byte LDL^T Cholesky factorization). Part of constraint matrix data block (0x8D0000-0x8D9000). |
| DAT_008D26E8 | DynamicsSolver_D26E8 | dynamics | double | write | 1 | Matrix workspace written in FUN_00575BBD (LDL^T factorization). Diagonal or off-diagonal element of factorized matrix. |
| DAT_008D2AD0 | DynamicsSolver_D2AD0 | dynamics | byte | offset | 1 | Matrix workspace in FUN_00575BBD (LDL^T factorization). Part of constraint matrix data block. |
| DAT_008D3BB8 | DynamicsSolver_D3BB8 | dynamics | int | offset | 1 | Matrix workspace index in FUN_00575BBD (LDL^T factorization). |
| DAT_008D3088 | DynamicsSolver_D3088 | dynamics | double | read | 1 | Matrix workspace constant in FUN_00575BBD (LDL^T factorization). Read during matrix decomposition. |
| DAT_005BA8E8 | ThreadPoolVTable | runtime | ptr | offset | 1 | VTable/struct for thread pool/async task manager in FUN_0057ABB0. Part of linked list chain (DAT_008d3bfc/c00/c04/c08). |
| DAT_005E53EC | DStr | fileio | char* | offset | 1 | String "D" used in file/device path construction (FUN_0057BF00). |
| DAT_005E5EC8 | ANonblockingCoStr | network | char* | offset | 1 | Winsock error string "a nonblocking connect" in network code (FUN_0057D400). |
| DAT_005E57B0 | RemoteHostConnectStr | network | char* | offset | 1 | Winsock error string "the remote host" in network code (FUN_0057D400). |
| DAT_005E5378 | MainWindowClassName | ui | char* | offset | 1 | Window class name "lpWindowName" for main application window (FUN_0057E480). |
| DAT_005BAF14 | SocketEventVTable | network | ptr | offset | 1 | VTable for network socket event handler in FUN_00582DC0. Linked list cleanup node for socket events. |
| DAT_005BB1F4 | SerialPortVTable | input | ptr | offset | 1 | VTable for serial port/controller handler in FUN_00585870. Manages controller input via serial. |
| DAT_008D3F4C | CodePageConversionBuf | system | int | write | 1 | Code page conversion buffer state written in FUN_00588C7A. Stores locale/codepage conversion context. |
| DAT_005E63A4 | SystemEventCallback | system | ptr | read | 1 | System event callback function pointer in FUN_00589C77. Called if non-null during system event dispatch. |
| DAT_005B8CB8 | ExceptionHandlerStruct | runtime | ptr | offset | 1 | Exception handler structure in FUN_0058A6EB. Used in SEH/exception handling chain. |
| DAT_005B8E1C | FPUControlConstant | math | double | read | 1 | FPU control word constant in FUN_0058DD89 (FPU precision/exception handler). Used in fscale operations for FPU state management. |
| DAT_008D3F94 | CodePageShareMemHandle | system | word | read | 1 | Shared memory/file mapping handle for code page data (FUN_0058F014). Paired with DAT_008d3f92. |
| DAT_005B94D4 | OSModuleHandle | runtime | ptr | offset | 1 | OS module instance handle in code page/system locale init (FUN_005903DA). |
| DAT_005E74F8 | MathLibConst_5E74F8 | math | float | read | 1 | Math library constant in FUN_005908B0 (IDA-only, floating-point arithmetic helper). Used in scaled division fallback. |
| DAT_008D406A | SerialPortConfigByte | input | byte | read | 1 | Serial port config byte in FUN_0059249B (serial port/FFB configuration). Part of config struct for controller serial params. |
| DAT_008D41AC | InitCallbackFunc | runtime | ptr | read | 1 | Initialization callback function pointer in FUN_005932BA. Called during system init sequence if non-null. |
| DAT_005B99C8 | StringTypeVTable | system | ptr | offset | 1 | Exception/type info struct in FUN_00595DC8 (string type classification handler). Used in GetStringType/character processing. |
| DAT_005B9B54 | IndFormatString | fileio | char* | offset | 1 | Format string "1IND" in serialization/data file parsing (FUN_005976E8). |
| DAT_005BB440 | CRTExceptionTypeInfo | runtime | ptr | offset | 1 | C++ exception type info in FUN_0059964A (CRT exception handling). Used in C++ new handler / EH init. |
| DAT_008D464C | GlobalObjManagerPtr | runtime | ptr | write | 1 | Global object manager pointer in FUN_0059AAB9. Stores result of FUN_0059ABCD singleton construction. |
| DAT_005BAB70 | CxxFrameHandlerFunc | runtime | ptr | offset | 1 | __CxxFrameHandler function reference in FUN_0059CA8B (IDA-only, 10-byte CRT EH wrapper). |
