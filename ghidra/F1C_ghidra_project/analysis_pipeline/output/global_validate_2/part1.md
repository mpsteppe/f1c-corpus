=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CE6AC | HUD_PosOffsets | UI/display | byte[] | read | 4 | Already in docs/12 as part of HUD_PosOffsets array (0x007ce6ac-0x007ce8a4). Used as HUD position offset index and string format base offset in FUN_00438cc0 and FUN_0049e170 |
| DAT_005BE600 | TrackWaypoint_Garori | track | char* | read | 1 | string literal — waypoint name "garori" used in FUN_00402690 track/waypoint system |
| DAT_005BE500 | TrackSurface_Intermediate | track | char* | read | 1 | string literal — track surface type "intermediate" for wet/dry line detection |
| DAT_005BE474 | TrackWaypoint_Perp | track | char* | read | 1 | string literal — "wp_perp" waypoint perpendicular offset parameter |
| DAT_005BE8C0 | TrackPitExit_LeftOfPits | track | char* | read | 1 | string literal — "leftOfPits" pit entry/exit side marker used in FUN_00408870 |
| DAT_005BEB08 | Commentary_Type | audio/commentary | char* | read | 1 | string literal — "type" commentary system key used in FUN_0040d4c0 |
| DAT_005BE9F0 | Commentary_Commentary | audio/commentary | char* | read | 1 | string literal — "commentary" file prefix for commentary audio |
| DAT_005BEB78 | Track_Sign | track | char* | read | 1 | string literal — "sign" track marker/signpost identifier in FUN_0040fe50 |
| DAT_005BEE08 | SoundBankIndexMap | audio | int[] | read | 1 | Integer lookup table indexed by sound ID (param_1 * 4). Maps sound identifiers (0x2693=9859, 0x2694=9876) to bank slot indices (0x2a-0x2e). Read as `*(int *)(&base + param_1 * 4)` in FUN_00411b50 |
| DAT_005C25A8 | DriverName_MichaelS | game/driver | char* | read | 1 | string literal — driver name "Michael Schumacher" used in FUN_00415d90 |
| DAT_005C24DC | DriverName_GiancarloF | game/driver | char* | read | 1 | string literal — driver name "Giancarlo Fisichella" used in FUN_00415d90 |
| DAT_005BF9AC | AnimationTimingFloats | animation/timing | float[][5] | read | 1 | Float array with stride 0x14 (5 floats per entry). Indexed by vehicle anim state `*(int *)(param_1 + 0x864)`. Compared against elapsed time for animation state transitions in FUN_004186f0 |
| DAT_005C28E8 | TeamName_2000Benetton | game/team | char* | read | 1 | string literal — team name "2000 Benetton" used in FUN_0041b980 |
| DAT_005C27D4 | TeamName_2002Arrows | game/team | char* | read | 1 | string literal — team name "2002 Arrows" used in FUN_0041b980 |
| DAT_005C2A34 | Path_Replays | game/path | char* | read | 1 | string literal — "replays" directory path used in FUN_004216f0 |
| DAT_005C2C90 | Path_OptionsAnim | UI/options | char* | read | 1 | string literal — "optionsanim" animation file path used in FUN_00421cd0 |
| DAT_005C2B90 | Path_VideoDriver | UI/options | char* | read | 1 | string literal — "videodriver" config path used in FUN_00421cd0 |
| DAT_005C300C | Format_SeasonDir | game/setup | char* | read | 1 | string literal — "seasondir %s" format string for season directory used in FUN_00422be0 |
| DAT_005C2EBC | Path_ObjDetail | game/setup | char* | read | 1 | string literal — "objdetail %d" config path used in FUN_00422be0 |
| DAT_005C3030 | Path_Config | game/setup | char* | read | 1 | string literal — "config %s" file path used in FUN_00423070 |
| DAT_005C31CC | SetupParam_CorneringMult | setup/vehicle | char* | read | 1 | string literal — "corneringmult" vehicle setup parameter name used in FUN_00424080 |
| DAT_0059E8B8 | AI_VehicleDistanceThreshold | AI | float | read | 1 | Float threshold used in AI vehicle distance calculation in FUN_00425920 |
| DAT_0059E998 | AI_SteeringAngleThreshold | AI | float | read | 1 | Float angle threshold compared against random heading delta in FUN_0042b0e0. When heading deviation > threshold, AI applies corrective steering |
| DAT_005C340C | SetupParam_Invulnerability | setup/vehicle | char* | read | 1 | string literal — "invulnerability" setup/save parameter name used in FUN_0042c440 |
| DAT_007C9348 | PhysicsAccum_07 | physics | int | write | 1 | Part of 12-consecutive-DWORD physics accumulation block (0x007c932c-0x007c9358) zeroed every 10 game ticks by FUN_0042c690. Stores per-frame physics accumulator state |
| DAT_005C34D0 | UISession_Warmup | UI | char* | read | 1 | string literal — "warmup" session label used in FUN_0042ce30 |
| DAT_005C36C0 | GraphicsParam_Bevel | renderer/graphics | char* | read | 1 | string literal — "bevel" render effect parameter name used in FUN_0042de10 |
| DAT_005C3EDC | SetupError_FailedToOpen | setup | char* | read | 1 | string literal — "Failed to open setup file" error message used in FUN_0042fd00 |
| DAT_005C3D7C | SetupParam_BodyAero | setup/vehicle | char* | read | 1 | string literal — "body aero" vehicle setup parameter name used in FUN_0042fd00 |
| DAT_005C3B74 | SetupParam_RearThirdSlowBump | setup/suspension | char* | read | 1 | string literal — "rear 3rd slowbump" suspension setup parameter name used in FUN_0042fd00 |
| DAT_005C39A4 | SetupParam_DiffPreload | setup/differential | char* | read | 1 | string literal — "diffpreload" differential setup parameter name used in FUN_0042fd00 |
| DAT_005C383C | SetupParam_Gearing | setup/transmission | char* | read | 1 | string literal — "gearing %f" transmission setup parameter name used in FUN_0042fd00 |
| DAT_005C3F74 | Format_3DEquals | UI/setup | char* | read | 1 | string literal — "3d=%s" format string for 3D setup display used in FUN_00431aa0 |
| DAT_005C412C | SetupParam_HeadMass | setup/vehicle | char* | read | 1 | string literal — "headmass" driver head mass setup parameter used in FUN_00435410 |
| DAT_0059EAF0 | Trans_SetupDouble_01 | physics/transmission | double | read | 1 | Double constant in FUN_00436870 (6198 bytes, large vehicle setup/transmission function) |
| DAT_0059EC08 | Physics_ConstantDouble_01 | physics | double | read | 1 | Double constant used in FUN_00439210 |
| DAT_0059EC40 | Physics_ConstantDouble_02 | physics | double | read | 1 | Double constant used in FUN_0043c250 |
| DAT_0059ECB0 | Engine_ThermalDouble | physics/engine | double | read | 1 | Double constant in FUN_0043ef20 (engine thermal/damage model). Used in thermal dynamics calculation with `_DAT_0059ed00` multiplier |
| DAT_007CC1B0 | Dynamics_StateDWORD | dynamics | int | read | 1 | DWORD in FUN_004441f0 (9101 bytes, large dynamics/transmission function). Read in transmission/drivetrain solver context |
| DAT_0059EE50 | Dynamics_Float_01 | dynamics | float | read | 1 | Float in FUN_004441f0 (9101 bytes, dynamics/transmission solver) |
| DAT_0059EDC8 | Dynamics_Double_01 | dynamics | double | read | 1 | Double in FUN_004441f0 (9101 bytes, dynamics/transmission solver) |
| DAT_005C44A4 | Path_HatExtension | renderer/path | char* | read | 1 | string literal — "hat" file extension for helmet texture paths used in FUN_0044c0e0 |
| DAT_007CCF9C | RenderState_OneFloat | renderer | float | write | 1 | Written to 0x3f800000 (1.0f) as render state init by FUN_0044d0a0. Part of renderer state block at 0x007ccf90 |
| DAT_007CCCFC | RenderState_Zero_05 | renderer | int | write | 1 | Written to 0 as render state init by FUN_0044d460. Part of renderer state group 0x007cccf0-0x007ccd04 |
| DAT_007CB310 | DeviceCreateResult | renderer | int | write | 1 | Written to 0 as success flag during DirectX device creation in FUN_0044fa60. Set before COM interface calls for render device setup |
| DAT_007D24C4 | Scene_StatePointer | renderer/scene | ptr | offset | 1 | Pointer/state value in FUN_0044ff50 (5968 bytes, renderer/scene setup). Compared against known state block addresses (0x007ca3b8, 0x007cc9bc, etc.) for state selection |
| DAT_005AD3A8 | Render_ConstantInt | renderer | int | read | 1 | Integer constant read in FUN_0044ff50 renderer/scene function |
| DAT_007D2188 | Anim_FadeSpeed | renderer/animation | float | read | 1 | Float read in FUN_00451720 (3910 bytes, renderer/animation). Used as fade/blend speed for render state transitions |
| DAT_007CD1D8 | StateTracker_Index | renderer/state | int | read | 1 | State tracker index read in FUN_00452b10. Function matches param_2 against 30+ render state globals and stores matching address |
| DAT_007CD1D0 | VehicleState_DoubleBuffer_08 | renderer/vehicle | float | write | 1 | Float in vehicle state double-buffer block written by FUN_004537b0 (2590 bytes). Part of render state copy-and-clamp pattern from vehicle parameter |
| DAT_007CA3AC | VehicleState_Float_03 | renderer/vehicle | float | write | 1 | Float in vehicle render state block written by FUN_004537b0. Part of the state double-buffer pattern with clamp threshold |
| DAT_005C567C | InputBinding_SteerRight | input/controls | char* | read | 1 | string literal — "Steer Right" input binding name in FUN_00455290 |
| DAT_005C5564 | InputBinding_RequestPit | input/controls | char* | read | 1 | string literal — "Request Pit" input binding name in FUN_00455290 |
| DAT_005C5460 | InputBinding_LookRollRight | input/controls | char* | read | 1 | string literal — "Look Roll Right" input binding name in FUN_00455290 |
| DAT_005C574C | CameraParam_Radius | camera | char* | read | 1 | string literal — "radius" camera parameter name used in FUN_004562f0 |
| DAT_005C5B18 | Format_TrackingCam | camera | char* | read | 1 | string literal — "%s tracking cam" format string for tracking camera mode used in FUN_00458a60 |
| DAT_007CD20C | Sentinel_NegOne | game/state | int | write | 1 | Written to 0xFFFFFFFF (-1) as sentinel/initializer in FUN_0045be50. Used alongside DAT_007cd208 |
| DAT_007C9574 | Vehicle_UnknownDWORD | vehicle | int | offset | 1 | Unknown in 0x007cXXXX vehicle data range. Referenced by FUN_0045d890 |
| DAT_005C5E00 | Format_AutoChat | network/chat | char* | read | 1 | string literal — "autochat %s" format for auto-chat messages used in FUN_0045ecd0 |
| DAT_005C5F98 | NetComm_SetSelf | network | char* | read | 1 | string literal — "netcomm setself" network command identifier used in FUN_00460520 |
| DAT_007CF13C | Config_FlagDWORD_01 | game/config | int | read | 1 | Configuration DWORD read in FUN_00461900. Part of bitfield-parsed config block where bits in param_1+0x76 control which globals get written (0xce874, 0xce88c, 0xce958, etc.) |
| DAT_007CEE48 | Config_FlagDWORD_02 | game/config | int | read | 1 | Configuration DWORD read in FUN_00461900. Same bitfield-parsed config block |
| DAT_005C6240 | Network_BadPassword | network | char* | read | 1 | string literal — "Bad Password" error message used in FUN_00462da0 |
| DAT_005C6384 | Field_Name | network/UI | char* | read | 1 | string literal — "name" form/network field name used in FUN_00463160 |
| DAT_007D0EB4 | Network_SessionContext | network/session | int | offset | 1 | Network session context value in FUN_00463f70. Function sets DAT_007c56a0 based on connection type (1/2 → 3, else → 2). Used with player name (DAT_007ce684) and config string (DAT_007cfe0c) |
| DAT_007CFF32 | UI_TriggerFlag | game/UI | byte | read | 1 | Byte flag read in FUN_00468a00 (sub_468A00 IDA decomp). If set, copied to byte_7CFF30. Controls UI trigger/activation behavior during session destroy |
| DAT_005C6A78 | UI_ASCString | UI | char* | read | 1 | string literal — ASCII string used in FUN_0046b5f0 |
| DAT_005C6CA4 | Format_HumanOppD | network/debug | char* | read | 1 | string literal — "HumanOpp %d" debug format for human opponent logging used in FUN_0046de10 |
| DAT_005C6A04 | UI_CarIconBitmap | UI | char* | read | 1 | string literal — "dfcaricon.bmp" car icon bitmap filename used in FUN_00477830 |
| DAT_005C7350 | UI_ReverseScanFast | UI/options | char* | read | 1 | string literal — "Reverse Scan (Fast)" UI option label used in FUN_0047daf0 |
