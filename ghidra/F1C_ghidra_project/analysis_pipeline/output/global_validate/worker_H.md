=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007d2db0 | RaceStandingsSortBuffer | race | ptr | read | 39 | Sorting/standings buffer for race results. Used in qualifying/race comparison logic. Compared by TeamID (+0x48a0) and position gaps (+0x4710). Branches on RaceMode (championship DAT_007d0410==4). |
| DAT_008ac388 | VehicleFilePathBuffer | setup | ptr | offset | 21 | File path buffer used in vehicle/scene file name construction. Referenced near VehicleFileCount (DAT_008ac390). Used in file iteration loops in vehicle setup loading. |
| DAT_008d4400 | DynamicsSolverBase_8D4400 | dynamics | ptr | offset | 11 | Dynamics solver workspace base pointer. Referenced by wrapper thunks (FUN_00579ff0, FUN_0057a980, FUN_0057adf0) all calling FUN_00599958. |
| DAT_008d5a58 | LocaleThreadRefCount | runtime | int | read,write | 9 | Thread-safe reference counter for locale/collation operations (0x008d3f38 guard). Checked `if (0 < DAT_008d5a58)` after LOCK()/InterlockedIncrement. Controls whether locale-sensitive string compare uses thread-safe path. |
| DAT_005c25ec | aProst | strings | char* | offset | 7 | String "Prost" - driver/team name. Referenced in game UI and driver data. |
| DAT_0059e714 | FloatToInt16QuantScale | physics_math | float | read | 6 | Quantization multiplier for converting float range [-max, +max] to signed int16. Used with `ROUND(float * scale)`. Clamped against _DAT_005acc94 (max) and _DAT_005acc90 (min). Packing vertex/normal data to 16-bit. |
| DAT_005d3b6c | aDDevF119992002_3 | strings | char* | offset | 6 | String "D:\dev\F1_1999_2002\" - source development root path, embedded as assert/debug string. |
| DAT_005c2694 | aSilverstone | strings | char* | offset | 5 | String "Silverstone" - track name. Referenced in track selection/loading. |
| DAT_007c5698 | SessionTickCounter | race | int | read,write | 5 | Session update tick counter, incremented each frame. Used for periodic operations: modulo 10 (vehicle update), modulo 400 (special state check), modulo 50 (pit/repair update). Near SessionType (DAT_007c56a4). |
| DAT_005d251c | IniKeyValueDelim | config | char* | offset | 5 | Search delimiter string used with FUN_005897ca for INI/config key=value parsing. May be "=" or a config file section marker. |
| DAT_005c2ab4 | FileExtGDBBytes | setup | bytes | offset | 4 | 3-byte file extension pattern for GDB files. Used in directory iteration (FUN_00421b10) comparing file entry bytes against known extensions. Paired with DAT_005c2ab8. |
| DAT_005ec3e0 | AudioDirBasePath | audio | char* | read | 4 | Base directory path for audio/sound assets. Used with format string `"%s\\%s.mp3"` in FUN_004c8de0 and FUN_004c9840 to construct full paths to wav/mp3 files. |
| DAT_005ea518 | ActiveControlProfilePtr | input | ptr | read | 4 | Pointer to active control/input profile or vehicle control config. Compared against DAT_005ea528 (sibling pointer). Reads offset +0x34 for profile mode (1=G27/H-pattern, 2=sequential/buttons). |
| DAT_005af998 | MMMX_PolyCoeffAF998 | physics_math | qword | read | 4 | 3DNow!/MMX packed float polynomial coefficient pair. Used in Hermite/spline evaluation (FUN_00526392) and quaternion math (FUN_00526B55, `PackedFloatingMUL`). |
| DAT_008d3fa4 | LocaleIsThreeLetterFlag | runtime | int | read,write | 4 | Flag set to 1 when locale string length == 3 (abbreviated code like "ENU" vs full "English"). Used in locale-sensitive string comparison code path selection. |
| DAT_005bf994 | aF11999Gdb | strings | char* | offset | 3 | String "f1_1999.gdb" - GDB track database filename. Used in track loading code. |
| DAT_0059eae8 | PhysicsDoubleConst_59EAE8 | physics_math | double | read | 3 | Double constant used in large physics/dynamics function FUN_004441f0 (9101 bytes). Used in vehicle dynamics computations. |
| DAT_005c5974 | aSFovFF | strings | char* | offset | 3 | String "sFovFF" - renderer FOV (field of view) parameter name. Referenced in graphics/display settings code. |
| DAT_005c675c | aRftire | strings | char* | offset | 3 | String "rftire" - right front tire dummy name. Used in vehicle mesh loading (FUN_004681b0) for tire object identification. |
| DAT_005cc7a0 | FileExtSCNByte | setup | byte | read | 3 | Byte value part of file extension handling. Written alongside DAT_005cc79c (".scn" extension). Used in scene file lookup (FUN_00495810). |
| DAT_005acd24 | D3DRenderDefaultColor | renderer | int | read | 3 | Default render state color/value. Used as initial param_1+0x30 value in D3D/texture object creation. Stored at param_1[0x3dd] during object init. Used by texture/render wrapper classes. |
| DAT_005ad260 | ColorGradientLerpFactor | renderer | float | read | 3 | Lerp/factor constant used in color gradient calculations. Used with _DAT_0059e450 (PI constant) in FUN_00502c28 for color blending. |
| DAT_005af978 | MMX_QuatInitConst_AF978 | physics_math | qword | read | 3 | 3DNow! packed float constant for quaternion/rotation init. Used in FUN_00522952, FUN_005229b5, FUN_00522a13 for converting uint32 to packed float rotation representation. |
| DAT_008b8df4 | ShadowMapWidth | renderer | int | read | 3 | Shadow/light texture width parameter. Passed to FUN_00542950 (texture creation). Used in shadow view setup (FUN_00560c10) with FSHADOWVIEW string. |
| DAT_008d2800 | SolverBlock_8D2800 | dynamics | double | read,write | 3 | Dynamics constraint solver workspace double block. Part of the 0x8D0000 workspace. Zeroed in FUN_00579ccf, initialized to identity by FUN_00578f76, read by LDL^T factorization FUN_00575bbd. |
| DAT_008d37d8 | SolverBlock_8D37D8 | dynamics | double | read,write | 3 | Dynamics solver workspace double block (152 bytes). Zeroed via sub_58BB10. Part of constraint solver matrix workspace. |
| DAT_008d3528 | SolverBlock_8D3528 | dynamics | double | read,write | 3 | Dynamics solver workspace double block (40 bytes). Zeroed via sub_58BB10. Part of constraint solver matrix workspace. |
| DAT_005b9bac | MSVC_ostream_vtable | runtime | ptr | offset | 3 | MSVC STL std::ostream vtable (`??_7?$basic_ostream@DU?$char_traits@D@std@@@std@@6B@`). Used by stream operations in CRT/STL code. |
| DAT_005be854 | aSDDMp3 | strings | char* | offset | 2 | String "%s\\%s.mp3" - format for constructing MP3 file paths from directory and filename. |
| DAT_008ad078 | AudioVisDataPtr | audio | ptr | read | 2 | Pointer to audio visualization/telemetry data. Used in FUN_0040fe50 and FUN_004441f0 (spectrum analyzer style display). |
| DAT_005c2730 | aIgnoredStopGoPenalty | strings | char* | offset | 2 | String "Ignored Stop/Go Penalty" - penalty-related UI message text. |
| DAT_005ea40c | Unknown_Physics_5EA40C | physics_math | float | read | 2 | Float constant used in physics calculations. Purpose unclear from limited context. |
| DAT_0059ea18 | TimeDisplayMultMs | ui | double | read | 2 | Double multiplier for time display formatting ("%.3f %s"). Converts game time to display value in milliseconds precision. |
| DAT_005c42f4 | aHdvFileReference | strings | char* | offset | 2 | String message about HDV file references/loading. Used in vehicle setup file parsing. |
| DAT_007ccbb4 | VehicleRideHeightRear | setup | float | write | 2 | Vehicle ride height parameter (rear). Written from vehicle struct offset +0x114c in FUN_004537b0. Clamped against sibling threshold. |
| DAT_007ca3b0 | VehicleCamberFront | setup | float | read,write | 2 | Vehicle camber angle (front). Initialized to 0.0 in sub_44CF34. Read/written in setup loading code FUN_004537b0. |
| DAT_007d22a8 | RenderBloomIntensity | renderer | float | read | 2 | Render parameter for bloom/post-processing intensity. Used in FUN_0044ff50 and FUN_00451720 (renderer setup chain). |
| DAT_007cd1d4 | VehicleToeAngle | setup | int | read | 2 | Vehicle toe angle parameter. Read from struct offset +0x115c in setup loading. |
| DAT_005c44b0 | aEmpty | strings | char* | offset | 2 | String "Empty" - placeholder/empty field name. |
| DAT_005c5c20 | aMapname | strings | char* | offset | 2 | String "mapname" - track/scene map name field identifier. |
| DAT_007d0ea4 | UI_LapDisplayFlags | ui | int | read | 2 | UI display flags for lap/session info panel. Used in HUD rendering code. |
| DAT_0059f718 | RenderEntityVTable_59F718 | renderer | ptr | offset | 2 | Vtable pointer for render entity class. Set during object construction (FUN_004685b0) and dtor (FUN_00468610). |
| DAT_005c7118 | aFtim14blkoutline | strings | char* | offset | 2 | String - UI/display message related to blackout/display lines in practice/session. |
| DAT_005ac1d0 | UIWidgetVTable_5AC1D0 | ui | ptr | offset | 2 | Vtable pointer for UI widget class. Used by FUN_0048d3e0 and FUN_00493fc0. |
| DAT_005cc970 | aError | strings | char* | offset | 2 | String "Error" - generic error label. |
| DAT_005ccea4 | GameWidgetVTable_5CCEA4 | game_logic | ptr | offset | 2 | Vtable pointer for game widget class. Used by FUN_0049c770 and FUN_004a58b0. |
| DAT_005cd5ec | aMts | strings | char* | offset | 2 | String "MTS" - Multi-Threading/Scheduling identifier. Used in task scheduling code. |
| DAT_005acd1c | AIFollowDistThreshold | ai | float | read | 2 | AI following distance threshold. Used in FUN_004b87c0 and FUN_004b8940 (vehicle AI following behavior). Multiplied by _DAT_0059e8a4 for time-scaled following distance. |
| DAT_005d2a3c | aAvgopponentstrength | strings | char* | offset | 2 | String "avg opponent strength" - UI text for AI difficulty/strength display. |
| DAT_005d30c4 | NetSessionInfo_5D30C4 | network | int | read | 2 | Network session info data. Used in multiplayer session setup (FUN_004c4d50). Checked alongside DAT_007d0398 and DAT_007d0410. |
| DAT_005d3c34 | aCommon | strings | char* | offset | 2 | String "common" - common/shared directory path. Used in resource loading. |
| DAT_005ad150 | AITimerRandomScale | ai | float | read | 2 | AI state timer random multiplier. Used with DAT_008aae74 ring buffer random values to add variability to AI behavior timing. Used in vehicle state init (FUN_004e0800). |
| DAT_005d67d0 | ModuleInterfaceVal_5D67D0 | setup | float | read | 2 | Module/plugin interface float value. Selected based on param_1 case in FUN_004f8280 for DLL interface. |
| DAT_007cfb90 | Unknown_Render_7CFB90 | renderer | int | read | 2 | Render state parameter. Read by FUN_004fa320 and FUN_004fa7e0. |
| DAT_005af26c | aIdat | strings | char* | offset | 2 | String "Idat" - data chunk/resource identifier. |
| DAT_005d9358 | MMMX_AtanPolyConst_0 | physics_math | int | read | 2 | 3DNow! atan/asin approximation polynomial constant 0. Used in packed float math FUN_00528f00 and FUN_00529000. Part of coefficient table at 0x005d9358-0x005d93b8. |
| DAT_005da780 | ProtocolHandshakeExpected | network | int[] | read | 2 | Array (2 elements) of expected protocol/handshake values. Compared in FUN_00534d50 against FUN_00534e70 results. |
| DAT_005dbef0 | aIllegalMeshFile | strings | char* | offset | 2 | String "Illegal mesh file" - error message for invalid 3D mesh files. |
| DAT_008cfbf0 | BlockSolver_8CFBF0 | dynamics | double | read | 2 | Dynamics block sparse LDL^T solver workspace. Referenced by FUN_0056fa96 (17KB block sparse solver, docs/18). |
| DAT_008d2550 | SolverBlock_8D2550 | dynamics | double | read,write | 2 | Dynamics solver identity matrix block. Initialized by FUN_00578f76 switch case 2. |
| DAT_008d3888 | SolverBlock_8D3888 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d2fd0 | SolverBlock_8D2FD0 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d2790 | SolverBlock_8D2790 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d34c0 | SolverBlock_8D34C0 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d31d8 | SolverBlock_8D31D8 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d3580 | SolverBlock_8D3580 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d2f30 | SolverBlock_8D2F30 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d3768 | SolverBlock_8D3768 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d3928 | SolverBlock_8D3928 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d3668 | SolverBlock_8D3668 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_008d35e8 | SolverBlock_8D35E8 | dynamics | double | read,write | 2 | Dynamics solver workspace block. Part of constraint solver matrix. |
| DAT_005b8a1c | DynamicsSolverObj_VTable | dynamics | ptr | offset | 2 | Vtable for dynamics solver object class. Set in constructor (sub_57AEC0) and dtor (FUN_0057aef0). |
| DAT_008d3eb4 | CmdLineEnvironmentStr | runtime | char* | read,write | 2 | Command line/environment string pointer. Set by FUN_00592dfa() during CRT startup. Points to raw environment block. Freed after parsing by FUN_0058aa6f. |
| DAT_005e77f8 | DateTimeThresholdStart | runtime | int | read,write | 2 | Date/time threshold for scheduling/event timing. Compared as milliseconds timestamp. Part of date calculation functions (FUN_0059249b, FUN_00592647) used for timed event validation. |
| DAT_008d4438 | DynamicsThreadObj_8D4438 | dynamics | ptr | offset | 2 | Dynamics solver thread object/state. Referenced by thunk FUN_005997cb and passed to FUN_00599ad9. |
