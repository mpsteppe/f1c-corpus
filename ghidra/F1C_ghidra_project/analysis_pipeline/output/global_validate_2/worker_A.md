=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CE6AC | HUD_PosOffsets | UI/display | byte[] | read | 4 | Already in docs/12 as part of HUD_PosOffsets array (0x007ce6ac-0x007ce8a4). Used as HUD position offset index and string format base offset in FUN_00438cc0 and FUN_0049e170 |
| DAT_005BE600 | TrackWaypoint_Garori | track | char* | read | 1 | string literal ??? waypoint name "garori" used in FUN_00402690 track/waypoint system |
| DAT_005BE500 | TrackSurface_Intermediate | track | char* | read | 1 | string literal ??? track surface type "intermediate" for wet/dry line detection |
| DAT_005BE474 | TrackWaypoint_Perp | track | char* | read | 1 | string literal ??? "wp_perp" waypoint perpendicular offset parameter |
| DAT_005BE8C0 | TrackPitExit_LeftOfPits | track | char* | read | 1 | string literal ??? "leftOfPits" pit entry/exit side marker used in FUN_00408870 |
| DAT_005BEB08 | Commentary_Type | audio/commentary | char* | read | 1 | string literal ??? "type" commentary system key used in FUN_0040d4c0 |
| DAT_005BE9F0 | Commentary_Commentary | audio/commentary | char* | read | 1 | string literal ??? "commentary" file prefix for commentary audio |
| DAT_005BEB78 | Track_Sign | track | char* | read | 1 | string literal ??? "sign" track marker/signpost identifier in FUN_0040fe50 |
| DAT_005BEE08 | SoundBankIndexMap | audio | int[] | read | 1 | Integer lookup table indexed by sound ID (param_1 * 4). Maps sound identifiers (0x2693=9859, 0x2694=9876) to bank slot indices (0x2a-0x2e). Read as `*(int *)(&base + param_1 * 4)` in FUN_00411b50 |
| DAT_005C25A8 | DriverName_MichaelS | game/driver | char* | read | 1 | string literal ??? driver name "Michael Schumacher" used in FUN_00415d90 |
| DAT_005C24DC | DriverName_GiancarloF | game/driver | char* | read | 1 | string literal ??? driver name "Giancarlo Fisichella" used in FUN_00415d90 |
| DAT_005BF9AC | AnimationTimingFloats | animation/timing | float[][5] | read | 1 | Float array with stride 0x14 (5 floats per entry). Indexed by vehicle anim state `*(int *)(param_1 + 0x864)`. Compared against elapsed time for animation state transitions in FUN_004186f0 |
| DAT_005C28E8 | TeamName_2000Benetton | game/team | char* | read | 1 | string literal ??? team name "2000 Benetton" used in FUN_0041b980 |
| DAT_005C27D4 | TeamName_2002Arrows | game/team | char* | read | 1 | string literal ??? team name "2002 Arrows" used in FUN_0041b980 |
| DAT_005C2A34 | Path_Replays | game/path | char* | read | 1 | string literal ??? "replays" directory path used in FUN_004216f0 |
| DAT_005C2C90 | Path_OptionsAnim | UI/options | char* | read | 1 | string literal ??? "optionsanim" animation file path used in FUN_00421cd0 |
| DAT_005C2B90 | Path_VideoDriver | UI/options | char* | read | 1 | string literal ??? "videodriver" config path used in FUN_00421cd0 |
| DAT_005C300C | Format_SeasonDir | game/setup | char* | read | 1 | string literal ??? "seasondir %s" format string for season directory used in FUN_00422be0 |
| DAT_005C2EBC | Path_ObjDetail | game/setup | char* | read | 1 | string literal ??? "objdetail %d" config path used in FUN_00422be0 |
| DAT_005C3030 | Path_Config | game/setup | char* | read | 1 | string literal ??? "config %s" file path used in FUN_00423070 |
| DAT_005C31CC | SetupParam_CorneringMult | setup/vehicle | char* | read | 1 | string literal ??? "corneringmult" vehicle setup parameter name used in FUN_00424080 |
| DAT_0059E8B8 | AI_VehicleDistanceThreshold | AI | float | read | 1 | Float threshold used in AI vehicle distance calculation in FUN_00425920 |
| DAT_0059E998 | AI_SteeringAngleThreshold | AI | float | read | 1 | Float angle threshold compared against random heading delta in FUN_0042b0e0. When heading deviation > threshold, AI applies corrective steering |
| DAT_005C340C | SetupParam_Invulnerability | setup/vehicle | char* | read | 1 | string literal ??? "invulnerability" setup/save parameter name used in FUN_0042c440 |
| DAT_007C9348 | PhysicsAccum_07 | physics | int | write | 1 | Part of 12-consecutive-DWORD physics accumulation block (0x007c932c-0x007c9358) zeroed every 10 game ticks by FUN_0042c690. Stores per-frame physics accumulator state |
| DAT_005C34D0 | UISession_Warmup | UI | char* | read | 1 | string literal ??? "warmup" session label used in FUN_0042ce30 |
| DAT_005C36C0 | GraphicsParam_Bevel | renderer/graphics | char* | read | 1 | string literal ??? "bevel" render effect parameter name used in FUN_0042de10 |
| DAT_005C3EDC | SetupError_FailedToOpen | setup | char* | read | 1 | string literal ??? "Failed to open setup file" error message used in FUN_0042fd00 |
| DAT_005C3D7C | SetupParam_BodyAero | setup/vehicle | char* | read | 1 | string literal ??? "body aero" vehicle setup parameter name used in FUN_0042fd00 |
| DAT_005C3B74 | SetupParam_RearThirdSlowBump | setup/suspension | char* | read | 1 | string literal ??? "rear 3rd slowbump" suspension setup parameter name used in FUN_0042fd00 |
| DAT_005C39A4 | SetupParam_DiffPreload | setup/differential | char* | read | 1 | string literal ??? "diffpreload" differential setup parameter name used in FUN_0042fd00 |
| DAT_005C383C | SetupParam_Gearing | setup/transmission | char* | read | 1 | string literal ??? "gearing %f" transmission setup parameter name used in FUN_0042fd00 |
| DAT_005C3F74 | Format_3DEquals | UI/setup | char* | read | 1 | string literal ??? "3d=%s" format string for 3D setup display used in FUN_00431aa0 |
| DAT_005C412C | SetupParam_HeadMass | setup/vehicle | char* | read | 1 | string literal ??? "headmass" driver head mass setup parameter used in FUN_00435410 |
| DAT_0059EAF0 | Trans_SetupDouble_01 | physics/transmission | double | read | 1 | Double constant in FUN_00436870 (6198 bytes, large vehicle setup/transmission function) |
| DAT_0059EC08 | Physics_ConstantDouble_01 | physics | double | read | 1 | Double constant used in FUN_00439210 |
| DAT_0059EC40 | Physics_ConstantDouble_02 | physics | double | read | 1 | Double constant used in FUN_0043c250 |
| DAT_0059ECB0 | Engine_ThermalDouble | physics/engine | double | read | 1 | Double constant in FUN_0043ef20 (engine thermal/damage model). Used in thermal dynamics calculation with `_DAT_0059ed00` multiplier |
| DAT_007CC1B0 | Dynamics_StateDWORD | dynamics | int | read | 1 | DWORD in FUN_004441f0 (9101 bytes, large dynamics/transmission function). Read in transmission/drivetrain solver context |
| DAT_0059EE50 | Dynamics_Float_01 | dynamics | float | read | 1 | Float in FUN_004441f0 (9101 bytes, dynamics/transmission solver) |
| DAT_0059EDC8 | Dynamics_Double_01 | dynamics | double | read | 1 | Double in FUN_004441f0 (9101 bytes, dynamics/transmission solver) |
| DAT_005C44A4 | Path_HatExtension | renderer/path | char* | read | 1 | string literal ??? "hat" file extension for helmet texture paths used in FUN_0044c0e0 |
| DAT_007CCF9C | RenderState_OneFloat | renderer | float | write | 1 | Written to 0x3f800000 (1.0f) as render state init by FUN_0044d0a0. Part of renderer state block at 0x007ccf90 |
| DAT_007CCCFC | RenderState_Zero_05 | renderer | int | write | 1 | Written to 0 as render state init by FUN_0044d460. Part of renderer state group 0x007cccf0-0x007ccd04 |
| DAT_007CB310 | DeviceCreateResult | renderer | int | write | 1 | Written to 0 as success flag during DirectX device creation in FUN_0044fa60. Set before COM interface calls for render device setup |
| DAT_007D24C4 | Scene_StatePointer | renderer/scene | ptr | offset | 1 | Pointer/state value in FUN_0044ff50 (5968 bytes, renderer/scene setup). Compared against known state block addresses (0x007ca3b8, 0x007cc9bc, etc.) for state selection |
| DAT_005AD3A8 | Render_ConstantInt | renderer | int | read | 1 | Integer constant read in FUN_0044ff50 renderer/scene function |
| DAT_007D2188 | Anim_FadeSpeed | renderer/animation | float | read | 1 | Float read in FUN_00451720 (3910 bytes, renderer/animation). Used as fade/blend speed for render state transitions |
| DAT_007CD1D8 | StateTracker_Index | renderer/state | int | read | 1 | State tracker index read in FUN_00452b10. Function matches param_2 against 30+ render state globals and stores matching address |
| DAT_007CD1D0 | VehicleState_DoubleBuffer_08 | renderer/vehicle | float | write | 1 | Float in vehicle state double-buffer block written by FUN_004537b0 (2590 bytes). Part of render state copy-and-clamp pattern from vehicle parameter |
| DAT_007CA3AC | VehicleState_Float_03 | renderer/vehicle | float | write | 1 | Float in vehicle render state block written by FUN_004537b0. Part of the state double-buffer pattern with clamp threshold |
| DAT_005C567C | InputBinding_SteerRight | input/controls | char* | read | 1 | string literal ??? "Steer Right" input binding name in FUN_00455290 |
| DAT_005C5564 | InputBinding_RequestPit | input/controls | char* | read | 1 | string literal ??? "Request Pit" input binding name in FUN_00455290 |
| DAT_005C5460 | InputBinding_LookRollRight | input/controls | char* | read | 1 | string literal ??? "Look Roll Right" input binding name in FUN_00455290 |
| DAT_005C574C | CameraParam_Radius | camera | char* | read | 1 | string literal ??? "radius" camera parameter name used in FUN_004562f0 |
| DAT_005C5B18 | Format_TrackingCam | camera | char* | read | 1 | string literal ??? "%s tracking cam" format string for tracking camera mode used in FUN_00458a60 |
| DAT_007CD20C | Sentinel_NegOne | game/state | int | write | 1 | Written to 0xFFFFFFFF (-1) as sentinel/initializer in FUN_0045be50. Used alongside DAT_007cd208 |
| DAT_007C9574 | Vehicle_UnknownDWORD | vehicle | int | offset | 1 | Unknown in 0x007cXXXX vehicle data range. Referenced by FUN_0045d890 |
| DAT_005C5E00 | Format_AutoChat | network/chat | char* | read | 1 | string literal ??? "autochat %s" format for auto-chat messages used in FUN_0045ecd0 |
| DAT_005C5F98 | NetComm_SetSelf | network | char* | read | 1 | string literal ??? "netcomm setself" network command identifier used in FUN_00460520 |
| DAT_007CF13C | Config_FlagDWORD_01 | game/config | int | read | 1 | Configuration DWORD read in FUN_00461900. Part of bitfield-parsed config block where bits in param_1+0x76 control which globals get written (0xce874, 0xce88c, 0xce958, etc.) |
| DAT_007CEE48 | Config_FlagDWORD_02 | game/config | int | read | 1 | Configuration DWORD read in FUN_00461900. Same bitfield-parsed config block |
| DAT_005C6240 | Network_BadPassword | network | char* | read | 1 | string literal ??? "Bad Password" error message used in FUN_00462da0 |
| DAT_005C6384 | Field_Name | network/UI | char* | read | 1 | string literal ??? "name" form/network field name used in FUN_00463160 |
| DAT_007D0EB4 | Network_SessionContext | network/session | int | offset | 1 | Network session context value in FUN_00463f70. Function sets DAT_007c56a0 based on connection type (1/2 ??? 3, else ??? 2). Used with player name (DAT_007ce684) and config string (DAT_007cfe0c) |
| DAT_007CFF32 | UI_TriggerFlag | game/UI | byte | read | 1 | Byte flag read in FUN_00468a00 (sub_468A00 IDA decomp). If set, copied to byte_7CFF30. Controls UI trigger/activation behavior during session destroy |
| DAT_005C6A78 | UI_ASCString | UI | char* | read | 1 | string literal ??? ASCII string used in FUN_0046b5f0 |
| DAT_005C6CA4 | Format_HumanOppD | network/debug | char* | read | 1 | string literal ??? "HumanOpp %d" debug format for human opponent logging used in FUN_0046de10 |
| DAT_005C6A04 | UI_CarIconBitmap | UI | char* | read | 1 | string literal ??? "dfcaricon.bmp" car icon bitmap filename used in FUN_00477830 |
| DAT_005C7350 | UI_ReverseScanFast | UI/options | char* | read | 1 | string literal ??? "Reverse Scan (Fast)" UI option label used in FUN_0047daf0 |
| DAT_005c743c | TeamString | UI | char* | offset | 1 | UI string "Team" for player/team display in FUN_0047e0a0 |
| DAT_005abb78 | PTR_VTable_FUN00488180 | UI | int* | read | 1 | VTable pointer set by FUN_00488180 constructor; class with param_1[0x45]=1 |
| DAT_005cc564 | TooltipColorFilter | UI | char* | offset | 1 | UI string "TooltipColorFilter" for tooltip color filter in FUN_00492160 |
| DAT_005cc6cc | ChildWindow | UI | char* | offset | 1 | UI string "Child" for child window registration in FUN_00492a40 |
| DAT_005cc84c | DoLayer | UI | char* | offset | 1 | UI string "DoLayer" for layer rendering command in FUN_00493480 |
| DAT_005cc990 | PrelinkedGizmo | UI | char* | offset | 1 | UI string "PrelinkedGizmo" for prelinked gizmo widget in FUN_00493fc0 |
| DAT_005ccab4 | TextString | UI | char* | offset | 1 | UI string "Text" for text widget labeling in FUN_00498440 |
| DAT_005ccdd4 | NextSessionBmp | UI | char* | offset | 1 | UI string "NextSession.bmp" for next session button bitmap in FUN_0049b0a0 |
| DAT_005ccbdc | Ptr_DAT_5CCBDC | UI | char* | read | 1 | Pointer to a null-terminated string buffer; compared/copied via strcmp in FUN_0049c830 string copy utility |
| DAT_005ccb58 | Ptr_DAT_5CCB58 | UI | char* | read | 1 | String pointer buffer used by FUN_0049ca00 for text copy |
| DAT_007ce244 | Dword_7CE244 | game_logic | int | read | 1 | State variable read by FUN_0049f070 initialization chain; read but not modified locally |
| DAT_005cd018 | WinConstructor | UI | char* | offset | 1 | UI debug string "WinConstructor" for window class construction in FUN_004a08e0 |
| DAT_005cd098 | FormatSV03f | UI | char* | offset | 1 | Format string "%s v%0.3f" used by FUN_004a1200 for window title bar construction ("F1 Challenge 99-02 v1.xx") |
| DAT_005cd32c | FrontJackUp | UI | char* | offset | 1 | UI string "FrontJackUp" for pitstop animation state in FUN_004a24d0 |
| DAT_005cd1f4 | Pitstop10secSman2 | UI | char* | offset | 1 | UI string "10secSman2" for 10-second pitstop warning animation in FUN_004a24d0 |
| DAT_005cd394 | PositionFFF | UI | char* | offset | 1 | Format string "Position%f%f%f" for position display formatting in FUN_004a2a90 |
| DAT_005cd4e0 | DamageString | UI | char* | offset | 1 | UI string "Damage" for damage display label in FUN_004a47e0 |
| DAT_005cd670 | FormatDS_6 | UI | char* | offset | 1 | Format string used by FUN_004a58b0 for repair/damage status display formatting |
| DAT_005acb90 | PTR_VTable_FUN004A70E0 | UI | int* | offset | 1 | VTable pointer (PTR_FUN_005acbfc) set at param_1[0x46] in FUN_004a70e0 UI constructor; class with nested sub-objects for 4 control groups |
| DAT_005d1f64 | StrSteeringHelp | UI | char* | offset | 1 | Config option label "SteeringHelp" for driving aids settings page in FUN_004aa270 |
| DAT_005d1ccc | StrShiftMode | UI | char* | offset | 1 | Config option label "ShiftMode" for transmission settings in FUN_004aa270 |
| DAT_005d1a04 | StrMechanicalFailure | UI | char* | offset | 1 | Config option label "MechanicalFailure" for damage/failure settings in FUN_004aa270 |
| DAT_005d177c | StrGridWalkthrough | UI | char* | offset | 1 | Config option label "GridWalkthrough" for pre-race grid display settings in FUN_004aa270 |
| DAT_005d1590 | StrEngineVolume | audio | char* | offset | 1 | Config option label "EngineVolume" for audio engine volume slider in FUN_004aa270 |
| DAT_005d13a0 | StrAirhornAmbient | audio | char* | offset | 1 | Config option label "AirhornAmbient" for ambient airhorn audio volume in FUN_004aa270 |
| DAT_005d11f0 | StrWhetherSparksOn | renderer | char* | offset | 1 | Config option label "WhetherSparksOn" for spark particle toggle in FUN_004aa270 |
| DAT_005d1008 | StrCloudBlend | renderer | char* | offset | 1 | Config option label "CloudBlend" for cloud blending mode in FUN_004aa270 |
| DAT_005d0d18 | StrLookUpDownAngle | camera | char* | offset | 1 | Config option label "LookUpDownAngle" for camera look angle in FUN_004aa270 |
| DAT_005d0a48 | StrDynamicLighting | renderer | char* | offset | 1 | Config option label "DynamicLighting" for dynamic light toggle in FUN_004aa270 |
| DAT_005d0874 | StrDisplayIcons | UI | char* | offset | 1 | Config option label "DisplayIcons" for HUD icon toggle in FUN_004aa270 |
| DAT_005d0594 | StrReplayFidelity | game_logic | char* | offset | 1 | Config option label "ReplayFidelity" for replay quality setting in FUN_004aa270 |
| DAT_005d02c0 | StrAiMinRadius | AI | char* | offset | 1 | Config option label "AiMinRadius" for AI minimum cornering radius in FUN_004aa270 |
| DAT_005d0028 | StrUnitsForEverything | UI | char* | offset | 1 | Config option label "UnitsForEverything" for metric/imperial units toggle in FUN_004aa270 |
| DAT_005cfddc | StrGetFinesInstead | game_logic | char* | offset | 1 | Config option label "GetFinesInstead" for penalty mode (fines vs. suspension) in FUN_004aa270 |
| DAT_005cfa78 | StrThresholdForAuto | game_logic | char* | offset | 1 | Config option label "ThresholdForAuto" for automatic driving aid engagement threshold in FUN_004aa270 |
| DAT_005cf694 | StrAllowChatInCar | network | char* | offset | 1 | Config option label "AllowChatInCar" for multiplayer chat while driving in FUN_004aa270 |
| DAT_005cf2a0 | StrBonespringMinC | controller | char* | offset | 1 | Config option label "BonespringMinC" for FFB bone spring minimum corner force in FUN_004aa270 |
| DAT_005cf00c | StrMimicSteering | controller | char* | offset | 1 | Config option label "MimicSteering" for steering wheel mimic toggle in FUN_004aa270 |
| DAT_005cebdc | StrController2Z | controller | char* | offset | 1 | Config option label "Controller2Z" for controller 2 Z-axis binding in FUN_004aa270 |
| DAT_005cea0c | StrControlShiftDown | controller | char* | offset | 1 | Config option label "ControlShiftDown" for downshift button binding in FUN_004aa270 |
| DAT_005ce830 | StrControlBiasFor | controller | char* | offset | 1 | Config option label "ControlBiasFor" for controller bias direction in FUN_004aa270 |
| DAT_005ce640 | StrFfbDeviceType | controller | char* | offset | 1 | Config option label "FfbDeviceType" for force feedback device type selector in FUN_004aa270 |
| DAT_005ce178 | StrFfbSteerForceE | controller | char* | offset | 1 | Config option label "FfbSteerForceE" for FFB steering force effect strength in FUN_004aa270 |
| DAT_005cdd2c | StrFfbThrottleVib | controller | char* | offset | 1 | Config option label "FfbThrottleVib" for FFB throttle vibration effect in FUN_004aa270 |
| DAT_005cd918 | StrHowStronglyWheel | controller | char* | offset | 1 | Config option label "HowStronglyWheel" for FFB overall wheel strength in FUN_004aa270 |
| DAT_005d2328 | NoPlayerError | network | char* | offset | 1 | Error string "NoPlayer" displayed when no player data available in FUN_004b17f0 |
| DAT_005accc8 | FloatClampMax | physics_math | float | read | 1 | Float threshold (0.0-1.0 range upper clamp) used in FUN_004b2840 packing function; if param_3 > this, output byte = 0x7f |
| DAT_005acd30 | DoubleDistThreshold | game_logic | double | read | 1 | Double threshold cast to float for distance comparison in FUN_004b5630 linked-list iterator; ABS(position diff) <= this skips removal |
| DAT_007d1d8c | Unknown_7D1D8C | game_logic | struct | offset | 1 | Opaque struct passed to FUN_00455260 in FUN_004b9fd0 replay activation handler; likely replay state/config block |
| DAT_005acd78 | Float_5ACD78 | unknown | float | read | 1 | Float constant read by FUN_004bc9b0; context unknown |
| DAT_005acdb8 | Float_5ACDB8 | unknown | float | read | 1 | Float constant read by FUN_004be760; context unknown |
| DAT_005d26f8 | FormatS22d | game_logic | char* | offset | 1 | Format string "%s_%2d" used by FUN_004c03f0 for session data key construction (e.g. "FinishPosition_0") |
| DAT_005d283c | SeasonStatus | game_logic | char* | offset | 1 | String "SeasonStatus" for championship season status tracking in FUN_004c0b70 |
| DAT_005d2e0c | TotalChampionships | game_logic | char* | offset | 1 | String "TotalChampionships" for championship history data key in FUN_004c2420 |
| DAT_005d2bac | GameoptFuelMult | game_logic | char* | offset | 1 | String "GameoptFuelMult" for fuel multiplier game option in FUN_004c2420 |
| DAT_005d2fa8 | Description | UI | char* | offset | 1 | String "Description" for UI description field label in FUN_004c3200 |
| DAT_005d3098 | VehExtension | game_logic | char* | offset | 1 | File extension ".veh" for vehicle data file loading in FUN_004c3d80 |
| DAT_005d335c | Mp3Extension | audio | char* | offset | 1 | File extension ".mp3" for music file loading in FUN_004c83b0 |
| DAT_007cf578 | AudioVolumeFactor | audio | float | read | 1 | Audio volume factor/pan read by FUN_004c9840; used in volume calculation: volume = (1.0 - pan_factor * this) |
| DAT_005d3688 | SprayKeyword | renderer | char* | offset | 1 | Renderer keyword "SPRAY" for particle spray effect configuration in FUN_004ca480 |
| DAT_005d3584 | NoShadeKeyword | renderer | char* | offset | 1 | Renderer keyword "NOSHADE" for disabling shading on particle effects in FUN_004ca480 |
| DAT_005d34a4 | DestBlendKeyword | renderer | char* | offset | 1 | Renderer keyword "DESTBLEND" for destination blend mode in particle effect rendering in FUN_004ca480 |
| DAT_008ac828 | ReactionParticleDir | renderer | float[] | write | 1 | Float array (10-float stride) for pre-computed reaction particle direction vectors; written by FUN_004cb120 special effects particle system |
| DAT_005d3890 | SinkKeyword | physics | char* | offset | 1 | Physics surface parameter keyword "SINK" for terrain sink depth in FUN_004cdd80 track surface loader |
| DAT_005d399c | FeedbackKeyword | renderer | char* | offset | 1 | Renderer keyword "FEEDBACK" for feedback effect configuration in FUN_004cf070 special effects |
| DAT_005acedc | FloatGridOffset | renderer | float | read | 1 | Float constant in FUN_004d0110 grid scene setup; used in position offset: local_35c = local_35c - DAT_005acedc |
| DAT_005d3c20 | Format4s | game_logic | char* | offset | 1 | Format string "%4s" for fixed-width text formatting in FUN_004d1450 |
| DAT_005d40c4 | FormatAidbS | game_logic | char* | offset | 1 | Format string "AIDb_%s" for AI database key construction in FUN_004d24d0 results export |
| DAT_005d3eb8 | DriveAidsAutoLoad | game_logic | char* | offset | 1 | String "DriveAidsAutoLoad" for driving aids auto-load configuration in FUN_004d24d0 |
| DAT_005d3d28 | QualTime | game_logic | char* | offset | 1 | String "QualTime" for qualifying time data field in FUN_004d24d0 results export |
| DAT_005d4380 | aPitstop | ui | char* | read | 1 | Pitstop UI string, referenced in menu/garage display |
| DAT_005d438c | off_5D438C | ui | code* | read | 1 | Function pointer or vtable offset, read in FUN_004d3cf0 for UI/garage component |
| DAT_005d43c8 | off_5D43C8 | vehicle | code* | read | 1 | VTable pointer assigned in FUN_004d4860 constructor, set to PTR_FUN_005acf08 |
| DAT_005d44d0 | aFl | game_logic | char* | read | 1 | Format/control string "fl", used in FUN_004d4a80 |
| DAT_007c8310 | SessionStartPaused | game_logic | int | write | 1 | State flag written to 0 in FUN_0059dba9 during session start/reset; paired with DAT_007c8314 (0x3fe80000) |
| DAT_005d4810 | aDamper | vehicle | char* | read | 1 | "Damper" parameter string, used in FUN_004d6b00 for suspension setup |
| DAT_005acf28 | DoubleConst_5ACF28 | vehicle | double | read | 1 | Double constant used in FUN_004d6b00 damper/suspension calculations |
| DAT_007cfea0 | InputDisplayMode | input | int | read | 1 | State flag compared to 0/2 in FUN_004d82d0; controls input display overlays (gear/input bar rendering) |
| DAT_005d4b14 | FormatTimeString | ui | char* | read | 1 | Format string "%2d/%2d/%2d" or "%06.3f" for time display in FUN_004d9690 |
| DAT_005d4c04 | Dword_5D4C04 | ui | int | read | 1 | DWORD constant used in FUN_004dd030 text rendering |
| DAT_007cf818 | Dword_7CF818 | renderer | int | read | 1 | DWORD in renderer function FUN_004ddf90 |
| DAT_005d4dd8 | aCouldNotFindIn | game_logic | char* | read | 1 | Error string "CouldNotFindIn..." used in FUN_004dfce0 error path |
| DAT_008ad3f4 | Dword_8AD3F4 | game_logic | int | write | 1 | DWORD written to in FUN_004dfce0 error handling |
| DAT_007c91dc | DoubleCarOrientationThreshold | vehicle | double | read | 1 | Double threshold compared to _DAT_0059e430 in FUN_004e49b0; controls car orientation/quaternion setup branching |
| DAT_008ad42c | VehicleArrayOffset_PitCrew | vehicle | int | read | 1 | Offset into vehicle data array in FUN_004eb430 pit crew AI logic |
| DAT_005ad238 | WeightTransferMultiplier | vehicle | float | read | 1 | Float multiplier (_DAT_005ad238) in FUN_004f12e0; scales weight transfer in team/driver management physics |
| DAT_005d4f98 | aFrontWingMass | vehicle | char* | read | 1 | Vehicle setup parameter string "FrontWingMass", used in FUN_004f24f0 |
| DAT_005d52b8 | aBumpstopRising | vehicle | char* | read | 1 | Vehicle setup parameter string "BumpstopRising", used in FUN_004f2c60 |
| DAT_005d517c | aCamberRange | vehicle | char* | read | 1 | Vehicle setup parameter string "CamberRange", used in FUN_004f2c60 |
| DAT_005d502c | aBrakePadRange | vehicle | char* | read | 1 | Vehicle setup parameter string "BrakePadRange", used in FUN_004f2c60 |
| DAT_005d571c | aFuelEstimate | vehicle | char* | read | 1 | Vehicle setup parameter string "FuelEstimate", used in FUN_004f3c80 |
| DAT_005d5598 | aOptimumOilTemp | vehicle | char* | read | 1 | Vehicle setup parameter string "OptimumOilTemp", used in FUN_004f3c80 |
| DAT_005d66d8 | aInertia | vehicle | char* | read | 1 | Vehicle setup parameter string "Inertia", used in FUN_004f4270 |
| DAT_005d659c | aDriverName_Aitor | vehicle | char* | read | 1 | Driver name string "AitorQuestab" or similar, used in FUN_004f4270 |
| DAT_005d6470 | aPitstop3Range | vehicle | char* | read | 1 | Vehicle setup parameter string "Pitstop3Range", used in FUN_004f4270 |
| DAT_005d6384 | aRWDragParams | vehicle | char* | read | 1 | Vehicle setup parameter string "RWDragParams", used in FUN_004f4270 |
| DAT_005d6298 | aBodyUp | vehicle | char* | read | 1 | Vehicle setup parameter string "BodyUp", used in FUN_004f4270 |
| DAT_005d6168 | aPhysicalModelFlag | vehicle | char* | read | 1 | Vehicle setup parameter string "PhysicalModelF..." (PhysicalModelFlag), used in FUN_004f4270 |
| DAT_005d5fdc | aFront3rdBumpstop | vehicle | char* | read | 1 | Vehicle setup parameter string "Front3rdBumpst...", used in FUN_004f4270 |
| DAT_005d5e20 | aRightFenderFlap | vehicle | char* | read | 1 | Vehicle setup parameter string "RightFenderFla...", used in FUN_004f4270 |
| DAT_005d5c5c | aFront3rdFastrecovery | vehicle | char* | read | 1 | Vehicle setup parameter string "Front3rdFastre...", used in FUN_004f4270 |
| DAT_005d5aa4 | aAbsGrip | vehicle | char* | read | 1 | Vehicle setup parameter string "AbsGrip", used in FUN_004f4270 |
| DAT_005d5968 | aAllowManualOverride | vehicle | char* | read | 1 | Vehicle setup parameter string "AllowManualOver...", used in FUN_004f4270 |
| DAT_005d582c | aReverseSetting | vehicle | char* | read | 1 | Vehicle setup parameter string "ReverseSetting", used in FUN_004f4270 |
| DAT_005d58cc | aGear9Setting | vehicle | char* | read | 1 | Vehicle setup parameter string "Gear9Setting", used in FUN_004f4270 |
| DAT_005d6ca4 | aPlayerEngineVolume | audio | char* | read | 1 | Audio parameter string "PlayerEngineVol..." used in FUN_004f7460 engine sound setup |
| DAT_005d6b17 | UnnamedString_5D6B17 | audio | char* | read | 1 | Unnamed string (empty IDA name) used in FUN_004f7460 audio/engine setup |
| DAT_005d6983 | UnnamedString_5D6983 | audio | char* | read | 1 | Unnamed string (empty IDA name) used in FUN_004f7460 audio/engine setup |
| DAT_007cf314 | SuspensionDampingMultiplier | vehicle | float | read | 1 | Float multiplier _DAT_007cf314 used in FUN_004f8440; scales suspension damping force (param_1[399] *= _DAT_007cf314 * local_24) |
| DAT_008afeb0 | VehicleDataOffset_8AFEB0 | vehicle | int | read | 1 | DWORD offset into vehicle data, used in FUN_004f9480 |
| DAT_005d6e50 | FlagByte_5D6E50 | game_logic | byte | read | 1 | Byte flag read in FUN_004fa000 |
| DAT_005d6f10 | aCloudRainy | weather | char* | read | 1 | Weather string "Cloud/Rainy" or "Cloudrny", used in FUN_004fba10 weather display |
| DAT_005ad2a0 | FloatConst_5AD2A0 | physics | float | read | 1 | Float constant used in physics function FUN_004fcee0 |
| DAT_005ad314 | TractionControlMultiplier | vehicle | float | read | 1 | Float multiplier _DAT_005ad314 in FUN_004fdeb0; scales stability/traction control decay (fVar3 * _DAT_005ad314 + ...) |
| DAT_005c6eb8 | aMedium | ui | char* | read | 1 | UI string "Medium", used in FUN_004fe2b0 for difficulty/skill level display |
| DAT_005d7088 | aTrackTempFormat | weather | char* | read | 1 | Format string "TrackTemp%d.%d" or "TrackTemp%2f", used in FUN_004fe820 weather display |
| DAT_005ad4e0 | LookupTableEndMarker | game_logic | int* | read | 1 | End marker for lookup table at 0x005ad508; returned by FUN_00500680 when key not found in table (sentinel value) |
| DAT_005ba5e0 | ComInterfaceTable | com | byte[] | read | 1 | Struct/table used in COM interface function FUN_00506003; contains vtable/data for COM interaction |
| DAT_005adc18 | VTablePtr_CoClassA | com | code* | read | 1 | VTable pointer assigned to *param_1 in FUN_0050ab19 COM constructor; set to PTR_FUN_005adc18 |
| DAT_005add2c | VTablePtr_CoClassB | com | code* | read | 1 | VTable pointer assigned to *param_1 in FUN_0050b3b5 COM constructor; set to PTR_FUN_005add2c |
| DAT_005ade3c | EpsilonFloat | math | float | read | 1 | Float threshold _DAT_005ade3c in FUN_0050c042; compared against param_1-param_2 difference for approximate equality test |
| DAT_005d786c | Ptr_FUN_5D786C | game_logic | code* | read | 1 | Function pointer (indirect call target) called via (*(code *)PTR_FUN_005d786c)(...) in FUN_0050d97e; dispatches to parameterized handler |
| DAT_005af2d8 | a113 | game_logic | char* | read | 1 | String "113" or similar identifier, used in FUN_005118e6 |
| DAT_005af438 | AudioCompressionDouble | audio | double | read | 1 | Double constant used in FUN_00513482 audio compression/encoding (sample rate or bitrate constant) |
| DAT_005d79c0 | Audio3DPositionFloat | audio | float | read | 1 | Float constant used in FUN_005147ea 3D audio position calculation |
| DAT_005afb2c | aIgnoringBadAddress | game_logic | char* | read | 1 | Error/debug string "IgnoringBadAddress", used in FUN_00518511 |
| DAT_005afda8 | aInvalidGammaAfter | game_logic | char* | read | 1 | Error/debug string "InvalidGammaAfter", used in FUN_00518c1e |
| DAT_005afb10 | aIdat | game_logic | char* | read | 1 | Debug string "Idat", used in FUN_00519019 |
| DAT_005d8a20 | Xmmword_CrossProductSignFlip | math | __m128 | read | 1 | SIMD XOR mask (xmmword_5D8A20) used in sub_51F0BE cross product; applied via _mm_xor_ps to flip sign of cross product result |
| DAT_005d8b60 | Xmmword_NormalizeCoeffC | math | __m128 | read | 1 | SIMD polynomial coefficient (xmmword_5D8B60) used in sub_51FB1E vector normalization; added as constant term in SSE polynomial evaluation for rsqrt approximation |
| DAT_008d6188 | Dword_NewtonRaphsonConstant | math | int | read | 1 | Newton-Raphson constant for fast inverse sqrt (dword_8D6188) in sub_52035E; part of (float)(dword_8D6184 * v6) * (float)(dword_8D6188 - (v5 * v6) * v6) |
| DAT_005d8c60 | Xmmword_SignNegation | math | __m128 | read | 1 | SIMD XOR mask (xmmword_5D8C60) in sub_520A7E; applied via _mm_xor_ps to negate sign of quaternion/vector components |
| DAT_008d62b0 | Xmmword_QuaternionMultiply | math | __m128 | read | 1 | SIMD multiply constant (xmmword_8D62B0) in sub_520E0E; used with _mm_mul_ps in quaternion multiplication setup |
| DAT_005d8fc0 | Xmmword_3DNowMatrixMask | math | __m128 | read | 1 | SIMD/x86 constant (xmmword_5D8FC0) used in FUN_005289e0 3DNow matrix multiply; accessed both as float __m128 and uint bitmask via PTR_DAT_005d8fc0 |
| DAT_005d9080 | Xmmword_5D9080 | math | __m128 | read | 1 | SIMD constant (xmmword_5D9080) referenced by FUN_00528bd0 or used elsewhere; part of 3DNow SSE constant pool |
| DAT_005d93ac | Dword_3DNowPolyConstant | math | int | read | 1 | DWORD constant (dword_5D93AC) in FUN_00529000; used as packed floating polynomial constant via PackedFloatingADD in MMX/3DNow rsqrt approximation |
| DAT_005b0b38 | aOversubscribed | game_logic | char* | read | 1 | Error string "Oversubscribed" used in FUN_0052a4a5 |
| DAT_005b0b98 | Qword_CompressionTable | audio | ulonglong | read | 1 | QWORD entry in compression/encoding table (qword_5B0B98) used in FUN_0052ab4e Huffman-like encoding |
| DAT_005b4764 | Dword_EncodingConstant | audio | int | read | 1 | DWORD constant (dword_5B4764) used in encoding function FUN_0052da30 |
| DAT_005b6620 | Word_HuffmanTable | audio | ushort | read | 1 | WORD entry in encoding/Huffman table (word_5B6620) used in FUN_00531250 compression/decompression |
| DAT_XXXXXXXX | ProposedName | system | type | access | N | purpose |
| DAT_008b5998 | IDCTOutputBuffer | renderer/texture | float | write | 1 | DCT decompression output buffer, written by FUN_00531b50 |
| DAT_005b7750 | DCTCoeff9 | audio/compression | float | read | 1 | DCT coefficient for element index 9, used in 16-element DCT filter bank |
| DAT_005b776c | DCTCrossCoeff0 | audio/compression | float | read | 1 | DCT cross-term coefficient ((a+b)-(c+d)) scaling factor |
| DAT_008b59c0 | IDCTWorkspace | renderer/texture | float | write | 1 | IDCT intermediate workspace buffer, written by FUN_00531b50 |
| DAT_005b779c | DCTCoeff15 | audio/compression | float | read | 1 | DCT coefficient for last element index 15/16 in filter bank |
| DAT_005da82c | RendererFuncPtrTable | renderer | code** | read | 1 | Pointer table used by renderer init, read by FUN_00535e80 |
| DAT_005dbac4 | StrOversubscribed | network | char* | read | 1 | "oversubscribed" string for network connection error message |
| DAT_008b8dcc | RendererStateFlag | renderer/state | int | write | 1 | Renderer state initialization flag, zeroed in FUN_0053c360 as part of state block reset |
| DAT_005dbec8 | StrNoReflectionMap | renderer | char* | read | 1 | "No reflection map" error string for texture/shader system |
| DAT_005dc070 | StrErrorSetting | renderer | char* | read | 1 | "Error while setting..." renderer error format string |
| DAT_005dc21c | StrBgmap | renderer | char* | read | 1 | "bgmap" config/command string for background map rendering |
| DAT_005dc314 | StrMorphtarget | renderer | char* | read | 1 | "morphtarget" config/command string for vertex morph target |
| DAT_005dc3d8 | StrExp | renderer/shader | char* | read | 1 | "exp" shader parameter string for exposure/exponent uniform |
| DAT_005dc5a0 | MixerDword3 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param) |
| DAT_005dc558 | MixerWordFlag | audio/mixer | short | read | 1 | Miles Sound System mixer flag/mask (16-bit word param) |
| DAT_005dc4ec | MixerDword2 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param) |
| DAT_005dc4a0 | MixerDword1 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param, base) |
| DAT_005e4e80 | StrBroadcastAddr | network | char* | read | 1 | "255.255.255.255" broadcast address string for UDP/networking |
| DAT_008cf288 | NetworkPacketBuf | network | byte[] | read | 1 | Byte array buffer for network packet data manipulation |
| DAT_005e514c | StrNewlines4 | debug/log | char* | read | 1 | "\n\n\n\n" padding string used in debug logging output |
| DAT_005e5204 | StrCom4 | serial/input | char* | read | 1 | "COM4" serial port name string for wheel/controller input |
| DAT_005e5358 | StrBody | renderer/mesh | char* | read | 1 | "body" mesh part name string for car body render group |
| DAT_008d39d8 | SolverWorkspaceIndex | dynamics/constraint solver | int | read | 1 | Index/offset into constraint solver LDL^T factorization workspace |
| DAT_008d0eb0 | SolverPivotD0 | dynamics/constraint solver | double | read | 1 | LDL^T pivot value, diagonal entry read during block sparse factorization |
| DAT_008cfdb0 | SolverFactorOutput1 | dynamics/constraint solver | double | write | 1 | LDL^T factorization output, computed double written to solver workspace |
| DAT_008d1270 | SolverDiagEntry1 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| DAT_008d13a8 | SolverDiagEntry2 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| DAT_008d0ee8 | SolverPivotD1 | dynamics/constraint solver | double | read | 1 | LDL^T pivot value, diagonal entry in 8D0E... range |
| DAT_008d12a0 | SolverDiagEntry3 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| DAT_008d08f8 | SolverRowEntry1 | dynamics/constraint solver | double | read | 1 | Solver matrix row entry read during LDL^T factorization inner loop |
| DAT_008d09c8 | SolverRowEntry2 | dynamics/constraint solver | double | read | 1 | Solver matrix row entry read during LDL^T factorization inner loop |
| DAT_008d3a90 | SolverRemoteD | dynamics/constraint solver | double | read | 1 | Solver double at distant workspace offset, read during factorization |
| DAT_008d39c4 | SolverBlockIndex | dynamics/constraint solver | int | read | 1 | Block/segment index into solver workspace structure |
| DAT_008d1c28 | SolverSubdiagEntry1 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d0b30 | SolverArrayBase | dynamics/constraint solver | double[] | read | 1 | Solver workspace array base, pointer to double array for LDL^T workspace |
| DAT_008d0e18 | SolverWorkspaceD0 | dynamics/constraint solver | double | read | 1 | Solver workspace double read during LDL^T step |
| DAT_008d1b58 | SolverSubdiagEntry2 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d1308 | SolverDiagEntry4 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| DAT_008d1310 | SolverDiagEntry5 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| DAT_008d0190 | SolverBaseD | dynamics/constraint solver | double | read | 1 | Base workspace double, read as pivot/scaling factor in LDL^T |
| DAT_008d1570 | SolverSubdiagEntry3 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d18b8 | SolverSubdiagEntry4 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d1c80 | SolverSubdiagEntry5 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d20c0 | SolverSubdiagEntry6 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d19c8 | SolverSubdiagEntry7 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d2000 | SolverSubdiagEntry8 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d1f38 | SolverSubdiagEntry9 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d20f8 | SolverSubdiagEntry10 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| DAT_008d2040 | SolverFactorOutput2 | dynamics/constraint solver | double | write | 1 | LDL^T factorization output double written to solver workspace |
| DAT_008d2328 | CholeskyFactorOut1 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD (LDL^T Cholesky factor, 13KB) |
| DAT_008d2698 | CholeskyFactorOut2 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD (LDL^T Cholesky factor, 13KB) |
| DAT_008d2a38 | CholeskyWorkspace | dynamics/constraint solver | double[] | read/write | 1 | Cholesky workspace array base, offset by sub_575BBD during factorization |
| DAT_008d2eb8 | CholeskyFactorOut3 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD during LDL^T factor step |
| DAT_008d3080 | CholeskyDiagonalIn | dynamics/constraint solver | double | read | 1 | Double read by sub_575BBD for diagonal comparison/pivot test |
| DAT_005ba8c4 | SEHExceptionFilter | runtime/SEH | struct | read | 1 | Exception filter structure used in __try/__except block (0x0057a760) |
| DAT_005e5388 | RendererVTablePtr | renderer | void** | read | 1 | Vtable/function pointer table read by FUN_0057bf00 |
| DAT_005e6060 | StrSocketLocal | network/socket | char* | read | 1 | "The socket is local" error string for socket address check |
| DAT_005e58b8 | StrSocketHasBeen | network/socket | char* | read | 1 | "The socket has been..." status/error string for socket state |
| DAT_005e62e0 | StrDropFlagSet | network/socket | char* | read | 1 | "drop flag set" debug/log string for packet drop detection |
| DAT_005bae98 | AllocListNode | memory/allocator | struct | read | 1 | Allocation linked list node structure, traversed by FUN_00582a10 during free |
| DAT_005e6360 | StrHst | network | char* | read | 1 | "hst" (host) string for network configuration lookup |
| DAT_005e6c5a | MathPiOver2 | math/CRT | float10 | read | 1 | Extended-precision constant (PI/2 or similar) used in acos/atan implementation |
| DAT_008d3e62 | CachedMonth | time/date | short | read | 1 | Cached SYSTEMTIME wMonth field, part of time-of-day check in FUN_005896ee |
| DAT_005e65b0 | PtrExitFunc | CRT/exit | code* | read | 1 | Pointer to __exit function, called by __amsg_exit on fatal error |
| DAT_005e6c22 | RoundingConstant | math/CRT | double | read | 1 | Double constant used in floating-point rounding (frndint helper) |
| DAT_005e99d0 | IOFunctionPtr | CRT/io | void*** | write | 1 | Function pointer written by sub_58EF83 during CRT IO init |
| DAT_008d3f70 | CodePageTablePtr | CRT/codepage | short* | read | 1 | Pointer to codepage translation table, freed during CRT teardown |
| DAT_005e74e0 | MathLookupTable | math/CRT | byte[8] | read | 1 | Byte lookup table for fmod/remainder classification (indexed by exponent bits) |
| DAT_008d406e | DateCompareParam3 | CRT/time | short | read | 1 | Date comparison parameter word passed to FUN_00592647 for time window check |
| DAT_008d4924 | FileHandleTable | CRT/startup | void** | read/write | 1 | CRT file handle table array, dynamically allocated during startup |
| DAT_005e99b8 | VtordispVTablePtr | CRT/vtable | struct | read | 1 | Vtordisp vtable pointer/offset table passed to FUN_005953b8 |
| DAT_008d41f4 | AtExitFuncPtr | CRT/atexit | code* | read | 1 | atexit handler function pointer, invoked by FUN_00597388 for signal 0xF |
| DAT_005b9cd8 | ObjectInitData1 | runtime/init | int | read | 1 | Object initialization constant copied to instance field at offset +8 |
| DAT_005bb760 | VTableTable | runtime/vtable | struct | read | 1 | Virtual function table pointer table used by object destructor FUN_0059a86c |
| DAT_005b9de0 | CxxExceptionInfo | runtime/SEH | struct | read | 1 | C++ exception raise parameters (8 DWORDs), copied by __CxxThrowException@8 |
