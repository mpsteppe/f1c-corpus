=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005ea618 | PointerTableEntry | setup | ptr | read | 63 | Pointer table member — part of a group of pointers (0x005ea510, 0x005ea618, 0x005eb978, 0x005ec6d0) used as data object table in setup/file system |
| DAT_005e69c8 | CharTypeTable | file | ptr | read | 23 | Character classification table (2 bytes per char) — bit 8=whitespace, bit 4=digit, bit 0x103=alphanumeric. Used by string-to-int/float parsers |
| DAT_007ce24c | CriticalSection | race | ptr | offset | 13 | HUD/game state object — passed to sub_4A0590 for synchronization. Checked before HUD rendering updates |
| DAT_007cd9d8 | Unknown_Race_7CD9D8 | race | ptr | offset | 9 | Memory allocation context — offset only, no direct read/write. Likely struct base for race UI system |
| DAT_005c260c | Str_Team_Williams | setup | string | offset | 7 | String literal "Williams" — team name string for Jordan/Williams. Used in team data initialization |
| DAT_008ac38c | CurrentFontHandle | setup | ptr | read,write | 7 | Font/texture handle — set from FUN_004c5130(). Used with FUN_004c78f0 (font binding) and FUN_004c6960 (text drawing) |
| DAT_005ccf10 | AssertStr_SourcePath_16 | setup | string | offset | 6 | Assert string "D:\\dev\\F1_1999_2002\\Source\\..." — source path for debug asserts |
| DAT_005c26c4 | Str_TrackName_Monaco | setup | string | offset | 5 | String "Monaco" — track name literal. Used in track database initialization |
| DAT_0059e900 | Physics_Double_59E900 | physics | double | read | 5 | Physics constant (double) — used in suspension/ride height computations in FUN_004270a0, FUN_00436870, FUN_0043ef20 |
| DAT_007cef84 | PenaltiesEnabled | steward | int | read | 5 | Penalties enable flag — already documented. 0=disabled, non-zero=enabled. Checked in steward penalty logic |
| DAT_005b9d7c | VTable_std_logic_error | runtime | ptr | offset | 5 | C++ std::logic_error vtable — standard library exception. No documentation needed |
| DAT_0059eb38 | Physics_Double_59EB38 | physics | double | read | 4 | Double constant — used in physics simulation (suspension/damper computations in FUN_00438130, FUN_0043ef20, FUN_004441f0) |
| DAT_008ac36c | Unknown_VehicleSetup_8AC36C | setup | ptr | offset | 4 | Near DAT_008ac390 (VehicleFileCount) and DAT_008ac394 (VehicleArray). Likely vehicle setup pointer/counter. Part of vehicle file enumeration system |
| DAT_005af968 | ThreeDNow_Constant_5AF968 | physics | qword | read | 4 | 3DNow!/MMX packed double constant — used in 3DNow geometry operations (ray-triangle intersection in sub_521079, sub_521295) |
| DAT_005e775c | DSTActiveFlag | file | int | read,write | 4 | Daylight saving time flag. Set to 1 when DST bias is active, 0 otherwise. Read from GetTimeZoneInformation result. |
| DAT_005be958 | AssertStr_SourcePath_15 | setup | string | offset | 3 | Assert string with source path — debug assert |
| DAT_005c3734 | MessageBufferConfig | setup | byte | offset | 3 | Config string buffer — used in message routing. Alternates with DAT_005c3738 based on mode param |
| DAT_005c57d8 | Str_LodMultiplier | renderer | string | offset | 3 | Config key string "LodMultiplier" — LOD distance multiplier setting. Read by renderer |
| DAT_007d0990 | RaceSessionVehicleCount | race | int | read,write | 3 | Vehicle count for current session. Set from DAT_007d0998 or DAT_007d099c based on session type. Used in AI/race logic |
| DAT_007cdcf0 | Unknown_RaceUI_7CDCF0 | race | ptr | offset | 3 | Game state object — offset access only. Referenced in race UI system with other 0x007CDxxx globals |
| DAT_005d23c8 | AssertStr_SourcePath_21 | setup | string | offset | 3 | Assert string with source path — debug assert |
| DAT_008ad3f8 | SoundChannelArray | audio | ptr | offset | 3 | Array of audio channel objects (stride 0x4a ints). Used by sound system for channel state management. Calls FUN_005506a0 for audio playback |
| DAT_005d8ab0 | SSE_CubicSplineCoeffB | renderer | xmmword | read | 3 | SSE vector constant — Hermite/cubic spline coefficient B. Used in quaternion interpolation for smooth camera/object rotation |
| DAT_008b8f0c | AudioStreamHandle_2 | audio | int | read,write | 3 | Audio stream buffer handle — passed to FUN_0053e070 (stream start) and FUN_0053ead0 (stream stop). Part of Miles Sound System wrapper |
| DAT_008d2750 | DynamicsMatrix_0_9 | dynamics | double | read,write | 3 | Dynamics constraint solver matrix element (block 0, row 9, column 0) — part of LDL^T factorization workspace at 0x8D0000–0x8D9000 |
| DAT_008d3578 | DynamicsMatrix_3_6 | dynamics | double | read,write | 3 | Dynamics constraint solver matrix element (block 3, row 6, column 0) — part of LDL^T factorization workspace |
| DAT_008d3228 | DynamicsMatrix_3_3 | dynamics | double | read,write | 3 | Dynamics constraint solver matrix element (block 3, row 3, column 1) — part of LDL^T factorization workspace |
| DAT_008d48f4 | HeapFreeListCount | heap | int | read,write | 3 | Free list allocation counter — tracks number of free blocks in heap allocator. Part of custom heap manager (HeapAlloc-based)
| DAT_0059e490 | VTable_Object_59E490 | setup | ptr | offset | 2 | Virtual function table pointer — used in object constructor/destructor. Initializes various float constants (0x3c23d70a, 0x3f79999a, etc.)
| DAT_0059e6e0 | RandomScalingFactor | math_util | float | read | 2 | Random number scaling factor (approximately 1/RAND_MAX). Used with _rand() to normalize random values to [0,1) range in FUN_0040de60 and FUN_004b3bd0 |
| DAT_005c271c | Str_SpeedingInPitL | race | string | offset | 2 | Message string "SpeedingInPitL" — penalty message for pit lane speeding |
| DAT_0059e944 | Physics_Float_59E944 | physics | float | read | 2 | Float physics constant — used in vehicle physics computation (FUN_004270a0 suspension/setup) |
| DAT_007ce2d8 | FileHandle_7CE2D8 | setup | ptr | read,write | 2 | Windows file/event handle (IDA names it hObject). Used for file I/O operations |
| DAT_005c4060 | Str_FormatSpec_5C4060 | file | string | offset | 2 | ASCII format string constant — used in string formatting operations |
| DAT_007cd19c | VehicleHeatDisplayTread | game_logic | float | write | 2 | Vehicle tire tread temperature display value — copied from struct offset +0x1148. Part of HUD display system |
| DAT_007ca518 | VehicleHeatDisplayRear | game_logic | float | read,write | 2 | Vehicle rear heat display value — initialized to 0.0. Part of tire/brake temperature HUD display system |
| DAT_005ad490 | D3D_VertexBufferDesc | renderer | ptr | offset | 2 | Direct3D vertex buffer description — used in COM-based D3D object creation (IDirect3DDevice::CreateVertexBuffer pattern). DO NOT DOCUMENT AS VEHICLE STRUCT |
| DAT_007ccbdc | RaceFlagValue_7CCBDC | race | int | read | 2 | Race flag/mode value — compared against a chain of other DAT_007ccXXX globals in race steward system |
| DAT_007ca434 | Unknown_HeatDisplay_7CA434 | game_logic | float | read | 2 | Heat display threshold — read in FUN_004537b0 heat display update. Part of temperature gauge system |
| DAT_008d468c | XORKey_NetworkAuth | network | int | write | 2 | XOR-obfuscated network authentication key — XORed with 0x3E. Used in FUN_0045d260 for lobby/network session setup |
| DAT_007ced44 | Flag_DamageDisplay | game_logic | int | read,write | 2 | Damage display mode flag — extracted from bit 10 of option word. Controls damage visualization mode in HUD |
| DAT_0059f140 | VTable_UI_Object_59F140 | UI | ptr | offset | 2 | UI object vtable pointer — used in object constructor (float constants: 5.0, 10.0, 4.0, -1.0 etc. for UI layout) |
| DAT_007ce630 | ProfileIconPath_ptr | UI | ptr | read | 2 | Profile icon path string pointer — read from dword_7CE684. NULL-checked with fallback to default. Used in profile icon file copy |
| DAT_005cc214 | CharFormatSpec_5CC214 | file | word | offset | 2 | Format/type specifier used in character conversion functions — passed to FUN_00588f66 |
| DAT_005cc644 | Str_SoundFocus | audio | string | offset | 2 | Config key string "SoundFocus" — audio focus/sound quality setting name |
| DAT_005cce34 | Str_ShaderEffectFile | renderer | string | offset | 2 | Shader/effect filename "2d063f" — DirectX effect file for 2D rendering |
| DAT_005cd5c4 | Str_MenuFile_cdbmas | audio | string | offset | 2 | Menu audio file "cdb.mas" — MAS audio archive for menu sounds |
| DAT_008ab6f0 | AudioBucketListHead | audio | ptr | write | 2 | Audio sample bucket list — linked list of audio sample buffers. Head pointer for free list. Each bucket is 0x1B0 bytes, 32 buckets total (0x3600 bytes) |
| DAT_005d2a88 | Str_TotalLapRecord | setup | string | offset | 2 | Config key string "TotalLapRecord" — lap record tracking configuration parameter |
| DAT_005d2ce0 | Str_MechFailRate | setup | string | offset | 2 | Config key string "MechFailRate" — mechanical failure rate configuration parameter |
| DAT_005d3968 | Str_SearchPath | setup | string | offset | 2 | Config key string "SearchPath" — file system search path configuration parameter |
| DAT_005ad11c | VTable_FunctionPtrTable | renderer | ptr | offset | 2 | Function pointer vtable — used in renderer object creation (allocates 0x10 bytes, sets type=4, flags=0) |
| DAT_005d67c0 | D3D_LightColorB | renderer | int | read | 2 | Direct3D light color component B (blue) — part of lighting parameter table indexed by light type. Used in FUN_004f8280 |
| DAT_008afe9c | TimeAccumulator_A | dynamics | double | write | 2 | Time accumulation double — accumulates frame delta time (_DAT_008afe90) for physics simulation stepping. Used by dynamics time-stepper |
| DAT_005d782c | Ptr_FunctionTable_5D782C | renderer | ptr | read | 2 | Function pointer table — indirect call target. Called through trampoline thunk_FUN_0050dd0c. Renderer/UI dispatch table |
| DAT_005af940 | ThreeDNow_AndMask_Packed | physics | qword | read | 2 | 3DNow! packed double AND mask — used in packed floating point operations for geometry computations |
| DAT_005b2ba4 | VideoCodec_DataTable | renderer | ptr | offset | 2 | Video codec/bitstream data table — used in bink video decoding functions (bit unpacking, shift operations) |
| DAT_008b8de4 | AudioStream_Param4 | audio | int | read,write | 2 | Audio stream parameter — stored alongside stream buffer handle. Part of packet/stream setup for audio playback |
| DAT_005e507c | Str_DirectDrawPrefix | renderer | string | offset | 2 | String "dd" — DirectDraw/DirectX prefix used for mode enumeration |
| DAT_008d2290 | DynamicsMatrix_2_2 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 2, row 2, column 2) — identity matrix diagonal. Part of LDL^T factorization workspace |
| DAT_008d2b10 | DynamicsMatrix_2_7 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 2, row 7) — part of LDL^T factorization workspace |
| DAT_008d2778 | DynamicsMatrix_2_3 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 2, row 3) — part of LDL^T factorization workspace |
| DAT_008d2d50 | DynamicsMatrix_3_1 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 3, row 1) — part of LDL^T factorization workspace |
| DAT_008d31c0 | DynamicsMatrix_3_4_col0 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 3, row 4, column 0) — part of LDL^T factorization workspace |
| DAT_008d3410 | DynamicsMatrix_4_0 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 0) — part of LDL^T factorization workspace |
| DAT_008d3420 | DynamicsMatrix_4_1 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 1) — part of LDL^T factorization workspace |
| DAT_008d3750 | DynamicsMatrix_4_5 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 5) — part of LDL^T factorization workspace |
| DAT_008d3148 | DynamicsMatrix_3_4_col1 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 3, row 4, column 1) — part of LDL^T factorization workspace |
| DAT_008d3650 | DynamicsMatrix_4_3 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 3) — part of LDL^T factorization workspace |
| DAT_008d33b8 | DynamicsMatrix_3_5 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 3, row 5) — part of LDL^T factorization workspace |
| DAT_008d3710 | DynamicsMatrix_4_4_col0 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 4, column 0) — part of LDL^T factorization workspace |
| DAT_008d3860 | DynamicsMatrix_4_5_col0 | dynamics | double | read,write | 2 | Dynamics constraint solver matrix element (block 4, row 5, column 0) — part of LDL^T factorization workspace |
| DAT_005b8c74 | Str_FormatSpec_5B8C74 | file | string | offset | 2 | ASCII string constant — used in character processing/comparison functions |
| DAT_008d400e | TimeZone_DSTFlag | file | byte | read | 2 | Time zone DST (Daylight Saving Time) flag — read from TIME_ZONE_INFORMATION structure. Controls DST bias adjustment |
| DAT_008d46e0 | CharUpperTable | file | byte | read,write | 2 | Character case mapping table (256 bytes) — uppercase/lowercase conversion lookup. Used with GetCPInfo for code page support |
