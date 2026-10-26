=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005EB978 | GameStatePtrArray3 | game | ptr | read | 32 | Pointer stored alongside &DAT_005ea510, &DAT_005ea618, &DAT_005ec6d0 in param structure init. Part of game module state pointer array. |
| DAT_005EA560 | GlobalInstance_5EA560 | game | ptr | offset | 20 | Passed as opaque instance handle to FUN_0040fb30. Used by multiple init/query functions. |
| DAT_005D3624 | SourcePath_25 | setup | string | offset | 10 | Path string constant from dev build (D:\dev\F1_1999_2002\Source). |
| DAT_005C36F0 | Token_R | setup | string | offset | 8 | String "r" — compared via FUN_00588410 to classify file path tokens. Sets field value 2 when matched. |
| DAT_005C25CC | TeamName_Benetton | setup | string | offset | 7 | Team name string "Benetton". Used in vehicle file parsing. |
| DAT_007CEC30 | ReconPitOpen | race | dword | read,write | 6 | Recon pit window open flag. Clamped values in FUN_0042b0e0 (race timing logic) and written in UI save/load (FUN_00461610/00461900). |
| DAT_008D3FB8 | LocaleInfoFunc | system | ptr | read | 6 | Function pointer for locale info retrieval. Initialized to FUN_005904f7 or GetLocaleInfoA_exref based on OS version check. |
| DAT_005C265C | TrackName_Spa | track | string | offset | 5 | Track name string "Spa Francorchamps". Used in track DB parsing. |
| DAT_005C421C | SourcePathPrefix | setup | string | offset | 5 | Dev source path prefix constant (D:\dev\F1_1999_2002\Source\). |
| DAT_005AF980 | SIMD_Const_5AF980 | math_util | __m64 | read | 5 | 64-bit packed float constant used in 3DNow! MMX math functions (PackedFloatingMUL). |
| DAT_0059E8F4 | PhysicsThreshold_59E8F4 | physics | float | read | 4 | Comparison threshold in FUN_004b66e0 (contact/boundary check) and vehicle physics in FUN_004270a0. |
| DAT_005C57C8 | String_Center | renderer | string | offset | 4 | String "Center". Used in rendering/UI functions. |
| DAT_005D23A8 | FormatString_Comment | UI | string | offset | 4 | Format string " // %s". Used in serialization/key-value output. |
| DAT_005B8960 | PhysicsDouble_5B8960 | dynamics | double | read | 4 | Double constant used in rotation matrix construction functions. |
| DAT_005E65B4 | ConsoleAttachedFlag | system | dword | read | 4 | Flag (compared to 1) controlling whether STD handles are set/managed. Part of console subsystem. |
| DAT_005C302C | ModeString_wt | setup | string | offset | 3 | String "wt" — file open mode string. Used with FUN_00587db0. |
| DAT_005C41BC | ParamName_FrSteering | vehicle | string | offset | 3 | Parameter name "FrSteering" — front steering parameter key from .hdv/.svm files. |
| DAT_005C5910 | ParamName_LODMultiplier | renderer | string | offset | 3 | Parameter name "LODMultiplier" — LOD scaling parameter from .scn files. |
| DAT_005C6880 | StatKey_Points | UI | string | offset | 3 | String "Points" — key for driver stats database. Used in career stats reset. |
| DAT_005ACAF4 | PathLengthThreshold | ai | float | read | 3 | Float threshold subtracted from AI path length computations. Used in driver path following (FUN_0049b900, FUN_004a35f0). |
| DAT_005D31C8 | ParamKey_SeasonRaces | setup | string | offset | 3 | String "SeasonRaces" — config file key for number of races in season. |
| DAT_005ADB58 | Unknown_5ADB58 | unknown | double | read | 3 | Double value referenced by COM init, codec, and conversion functions. Context insufficient for purpose. |
| DAT_005DA574 | AudioDevicePath | audio | string | offset | 3 | Audio device shared source path string (D:\dev\F1_1999_2002\Source\Audio\Dev\Sh...). |
| DAT_005DD804 | ImageBlitTransparentColor | renderer | uint | write | 3 | Transparent color key for image blit operations. Compared to 0xffff/0xffffff to skip transparent pixels during surface copy. |
| DAT_008D29C8 | DynamicsSolverBlock_8D29C8 | dynamics | double | read,write | 3 | Block within dynamics constraint solver workspace (0x8D0000-0x8D9000). Zeroed by FUN_00579ccf (memset), initialized to identity by FUN_00578f76, factorized by FUN_00575bbd (LDL^T). Size 32 bytes (4 doubles). |
| DAT_008D30B8 | DynamicsSolverBlock_8D30B8 | dynamics | double | read,write | 3 | Dynamics solver workspace block. Zeroed in FUN_00579ccf with size 24 bytes (3 doubles). |
| DAT_008D3C00 | GenericList_Tail | internals | ptr | read,write | 3 | Tail pointer for generic doubly-linked list. Used with DAT_008D3BFC (head), DAT_008D3C08 (count). List nodes contain pointer + next + prev. |
| DAT_005B9C48 | VTable_basic_ostream_wchar | MSVCRT | vtable | offset | 3 | MSVC vtable for `std::basic_ostream<unsigned short, std::char_traits<unsigned short> >`. Set on stream objects during construction. |
| DAT_005EA500 | GameStateFlag_5EA500 | game | dword | read,write | 2 | State flag checked in FUN_00409440 (game state jump table dispatcher). |
| DAT_005BF2F8 | DriverDataTable2 | ai | ushort[] | offset | 2 | USHORT lookup table indexed by driver ID from FUN_004144c0(). Contains paired values (base + delta) used for driver attribute randomization in range [0, 0x218). |
| DAT_005C2D9C | WindowsXPString | system | string | offset | 2 | String "Windows XP". Used for OS version detection/comparison. |
| DAT_0059E990 | PhysicsConstant_59E990 | physics | float | read | 2 | Physics multiplier constant used in FUN_0045f50 (engine RPM/speed computation) and FUN_0042b0e0 (race timing/physics). |
| DAT_005C3810 | OffsetTable_5C3810 | unknown | ptr[] | offset | 2 | Pointer/offset lookup table. |
| DAT_0059ECC8 | EngineModelConstant_59ECC8 | vehicle_physics | double | read | 2 | Double constant in engine thermal/damage model. Multiplied with velocity delta in FUN_0043ef20 (engine simulation). |
| DAT_007CCA70 | VehicleSetup_BrakeBalance | vehicle_physics | float | write | 2 | Target float for vehicle setup parameter at offset +0x1150. Copied during setup parameter sync in FUN_004537b0. Brake balance or bias value. |
| DAT_007CCF90 | VehicleSetup_Target_7CCF90 | vehicle_physics | dword | read,write | 2 | Target int for vehicle setup parameter. Initialized to 0x6a (106). Compared in large if-else chain in FUN_00452810 selecting setup parameter targets. |
| DAT_007D24A0 | VehiclePhysics_Param_7D24A0 | vehicle_physics | float | read | 2 | Float parameter used in vehicle physics setup functions. |
| DAT_007CD018 | VehicleSetup_Target_7CD018 | vehicle_physics | dword | read | 2 | Vehicle setup parameter target. Read during setup parameter sync. |
| DAT_005C59C8 | String_Orientation | renderer | string | offset | 2 | String "Orientation". Used in rendering/scene file parsing. |
| DAT_0059F094 | PhysicsConstant_59F094 | unknown | float | read | 2 | Float constant referenced by two functions. |
| DAT_007D0A50 | TimeAccelSetting | race | dword | read | 2 | Time acceleration/fast-forward setting. Read in UI settings save (FUN_00461900) and restore (FUN_00463ef0). Negative values used for rewind. |
| DAT_005C6920 | StatKey_Circuit | UI | string | offset | 2 | String "Circuit". Key for driver stats database. |
| DAT_005C71CC | CodeKey_TTGJZ | game_logic | string | offset | 2 | String "TTGJZ" — scoring/classification key identifier. |
| DAT_005AC490 | VTable_5AC490 | UI | ptr[] | offset | 2 | Vtable/function pointer table for UI component class. Set in constructor (FUN_0048e300) and used in destructor (FUN_0048e360). |
| DAT_005AC9E8 | VTable_5AC9E8 | AI | ptr[] | offset | 2 | Vtable for AI/scoring class. Set in FUN_00498d20 and referenced in FUN_00498d90. |
| DAT_005ACB00 | Threshold_LowerBound_5ACB00 | UI | float | read | 2 | Lower bound threshold in color-blending function (FUN_0049e5b0) and running-average clamp (FUN_004c2dc0). |
| DAT_005ACBF0 | VTable_VideoPlayback_5ACBF0 | renderer | ptr[] | offset | 2 | Vtable for video playback class. Used in large init function FUN_004a70e0 (6669 bytes) as sentinel pointer pattern for video state objects. |
| DAT_005D267C | String_Active | config | string | offset | 2 | String "Active". Config key/value identifier. |
| DAT_005D29E8 | RaceConditionFormat | race | string | offset | 2 | Race condition format string. |
| DAT_005ACE00 | RaceSpeedFactor | race | float | read | 2 | Session-dependent speed/factor for session type 7 (race). Used in FUN_004c7f30 to compute race session speed factor with thresholds based on RacePhase. |
| DAT_005D433C | ASCIIString_5D433C | unknown | string | offset | 2 | ASCII string constant. |
| DAT_007C8A24 | SteeringGeometry_dbl_7C8A24 | vehicle_physics | double | read | 2 | Double vector component used in wheel steering geometry computation. Passed to FUN_0043aee0 for vehicle kinematics. |
| DAT_005D6798 | BrakeForceConst_5D6798 | vehicle_physics | dword | read,write | 2 | Constant term in brake force calculation (FUN_004f8440). Used in formula: `local_24 = (dword_5D67A0 * local_20 + dword_5D679C * param[0x24] + dword_5D6798) * ...`. |
| DAT_005AD2B8 | SteeringNoise_dbl_5AD2B8 | vehicle_physics | double | read | 2 | Double constant in steering input noise simulation. Multiplied with random values in FUN_004fd8b0 driver steering model. |
| DAT_005AFAA0 | CodecBlockSizeTable | codec | uint[] | read | 2 | Array of uint[4] indexed by codec quality byte. Used in JPEG/codec buffer size calculation (FUN_0051868c). |
| DAT_005D9320 | TrigConst_qword_5D9320 | math_util | __m64 | read | 2 | 64-bit packed floating-point constant used in 3DNow! trigonometric function approximations (polynomial expansion term). |
| DAT_005B8908 | Unknown_dbl_5B8908 | unknown | double | read | 2 | Double constant used in audio buffer init and display mode selection. |
| DAT_005DC228 | String_Orient | renderer | string | offset | 2 | String "Orient". Used in scene file parsing. |
| DAT_008D2338 | DynamicsSolverBlock_8D2338 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block (0x8D0000 region). Zeroed and set to identity in sub_578F76 case 1. Used in LDL^T factorization. |
| DAT_008D2B08 | DynamicsSolverBlock_8D2B08 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. Zeroed in sub_578F76 case 2. |
| DAT_008D2610 | DynamicsSolverBlock_8D2610 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. Zeroed in sub_578F76 case 4, read in sub_575BBD factorization. |
| DAT_008D26D0 | DynamicsSolverBlock_8D26D0 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. Used in sub_578F76 identity init and sub_575BBD LDL^T. |
| DAT_008D2FE8 | DynamicsSolverBlock_8D2FE8 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D2A70 | DynamicsSolverBlock_8D2A70 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D34D8 | DynamicsSolverBlock_8D34D8 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D37E0 | DynamicsSolverBlock_8D37E0 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D3598 | DynamicsSolverBlock_8D3598 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D3640 | DynamicsSolverBlock_8D3640 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D3788 | DynamicsSolverBlock_8D3788 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D3940 | DynamicsSolverBlock_8D3940 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_008D3848 | DynamicsSolverBlock_8D3848 | dynamics | double | read,write | 2 | Dynamics constraint solver workspace block. |
| DAT_005E5374 | WindowClassName | system | string | read | 2 | Window class name string for Win32 window registration. Used in window creation. |
| DAT_005E6C6C | TransDispTable | MSVCRT | byte[] | offset | 2 | Jump table base for MSVC CRT transcendental function dispatch (__trandisp1, __trandisp2). Indexed by rounding mode to select target function. |
| DAT_005E7888 | ExceptionEntryCount | MSVCRT | dword | read | 2 | Count of exception handler entries. Used in SEH/vectored exception handler management. |
| DAT_008D45F8 | CriticalSection_Global | system | CRITICAL_SECTION | offset | 2 | Win32 CRITICAL_SECTION for global thread synchronization. Initialized on first use via InterlockedExchange pattern. |
