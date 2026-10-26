=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CE24D | SessionTransitionFlag | game/engine | byte | read/write | 26 | Flag controlling session mode transitions. Checked/set by session management functions alongside RaceMode (DAT_007d0410). Set during initialization of race/practice sessions. |
| DAT_005C5CE4 | SourceDevPathStr | setup | string | read | 16 | Path string constant "D:\dev\F1_1999_2002\Source\" used in debug assert messages across multiple game systems. |
| DAT_0059E87C | TimeStepMultiplier | physics | float | read | 9 | Physics timestep multiplier used in position/velocity updates. Multiplied against delta values in vehicle movement calculations (FUN_00466350). |
| DAT_008D3FB0 | LocaleValidationFlags | locale/win32 | int | read/write | 8 | Bitmask tracking locale/codepage validation results. Set during EnumSystemLocalesA callback (FUN_0058ffec). Bits indicate which locale names/code pages matched. Used by string conversion functions to select ANSI vs Wide API paths. |
| DAT_0059E920 | SuspensionAntirollFactor | physics | float | read | 7 | Anti-roll bar / suspension force constant used in large physics functions (FUN_004270a0, FUN_004441f0, FUN_00451720). Multiplied against suspension displacement values. |
| DAT_007CD8BC | LocaleTestStringA | locale/win32 | string | read | 6 | Empty string "" used as test parameter in GetStringTypeA/LCMapStringA detect whether OS supports wide-character APIs. Determines ANSI vs Wide code path for locale operations. |
| DAT_005BF970 | TrackDbFileName | file/track | string | read | 5 | String constant "F12002.GDB" — track database file name used by track/scene loading functions. |
| DAT_0059E830 | TempWarningThreshold | physics | double | read | 5 | Temperature warning threshold in HUD display logic (FUN_0041be60). Compared against combined temperature sum to decide whether to show warning indicator. Also used in engine/brake thermal calculations. |
| DAT_005C6878 | StrWins | UI | string | read | 5 | String constant "Wins" used in driver statistics display UI (career/standings screens). |
| DAT_008D48FC | LocaleConvBuffer | locale/win32 | ptr | read/write | 5 | Heap-allocated buffer (0x140 bytes) for locale/codepage conversion workspace. Allocated via HeapAlloc in FUN_00593dd3, used by string conversion and validation routines. |
| DAT_0059EA68 | WheelSpeedFactor | physics | double | read | 4 | Wheel rotation speed conversion factor. Used in drivetrain/differential calculations multiplying wheel angular velocity against differential ratios (FUN_00430a50, FUN_0043ef20). |
| DAT_007CE25F | SessionPauseFlag | game/engine | byte | read/write | 4 | Pause state flag. Set to 1 by sub_4A0E68 to trigger session pause. Checked in FUN_004a0fd0 to determine return value for game loop (returns 4=paused or 6=running). Related to DAT_007ce25d, DAT_007ce25e. |
| DAT_008AD394 | AudioEmitter3 | audio/3d | ptr | read/write | 4 | Third (index 3) audio/3D sound emitter object pointer. Part of array DAT_008AD388-DAT_008AD3AC (4 emitters). Passed to sound library functions for 3D positional audio playback. |
| DAT_008D3870 | DynamicsBlock_14 | dynamics/solver | double | read/write | 4 | Element of dynamics constraint solver workspace block (0x8D0000-0x8D9000). Used in LDL^T factorization (FUN_00575bbd), identity init (FUN_00578f76), and zero-init (FUN_00579ccf). Part of 272-byte block at offset 0x3870. |
| DAT_005BE8E0 | StrMainView | UI | string | read | 3 | String constant "MainView" used by view/camera system. Passed to sub_544F50 for view object lookup. |
| DAT_005C3310 | StrD063F | UI/renderer | string | read | 3 | Format/identifier string "D063F" used by UI or renderer setup functions. |
| DAT_007CCA6C | RenderStateInt_9 | renderer/d3d | int | read/write | 3 | D3D render state parameter initialized to 9 in FUN_0044c920 (with associated floats at +0x70,+0x74,+0x78). One of many render state globals (0x7cca44-0x7cca7c range). Used in FUN_00452810 lookup table for state pointer matching. |
| DAT_007D0FC4 | RaceSetupByte_0FC4 | race/session | byte | read/write | 3 | Configuration byte read from track/session setup files. Written to vehicle struct field +0x66 in FUN_00461900. Read back in FUN_00461610 and FUN_00462550 for controller/track config. |
| DAT_005A443C | VTable_ControlBase | UI/controls | ptr | read | 3 | C++ vtable pointer for control base class. Used by UI control object constructors/destructors (FUN_00476100, FUN_004761e0, FUN_0048e9e0). Part of vtable chain (also 0x5A4450, 0x5A4464). |
| DAT_005D173C | StrWeather | file/setup | string | read | 3 | String constant "Weather" used for weather data file/directory path construction. |
| DAT_008AD3A0 | AudioEmitter_Idx3 | audio/3d | ptr | read/write | 3 | Fourth audio emitter pointer (index 3) in 5-element sound emitter array (DAT_008AD398-DAT_008AD3A8). Used by FUN_004D8A30 and FUN_004D9030 for emitter lifecycle management. |
| DAT_005D8A70 | HermiteCoeff_2 | math | SSE vector | read | 3 | SSE xmmword constant for cubic Hermite interpolation polynomial evaluation. Used alongside xmmword_5D8A50, xmmword_5D8A60, xmmword_5D8A80 in Hermite/spline interpolation (FUN_0051F200, FUN_0051F2C0, FUN_0051F350). |
| DAT_005DBB90 | Unknown_5DBB90 | unknown | int | read | 3 | Address referenced by 3 functions but no source excerpts provided. Purpose unclear. |
| DAT_008D2490 | DynamicsBlock_4 | dynamics/solver | double | read/write | 3 | Element of dynamics constraint solver workspace. Initialized to 0.0 in identity init (FUN_00578f76), zeroed by FUN_00579ccf with memset(48 bytes). Used in LDL^T factorization. |
| DAT_008D2C80 | DynamicsBlock_8_80 | dynamics/solver | double | read/write | 3 | Element of dynamics constraint solver workspace. Zeroed by FUN_00579ccf. Used in LDL^T factorization. |
| DAT_008D3510 | DynamicsBlock_11 | dynamics/solver | double | read/write | 3 | Element of dynamics constraint solver workspace. Part of identity init block (FUN_00578f76 case 4 sets to 0.0). |
| DAT_005E998C | PoolAllocMaxBlock | locale/mem | int | read | 3 | Maximum block size threshold for pool allocator. Used in FUN_0058A973, FUN_0058AB58, FUN_0058B5D4 to determine whether allocation can be served from pool vs HeapAlloc. Pool allocator active when DAT_008d4908 == 2. |
| DAT_007CB304 | InitConst_7CB304 | game/engine | int | read | 2 | Initialization constant copied to struct offset +0x6c in FUN_00498740. Part of triple-const init sequence (0x7cb2fc→+100, 0x7cb300→+0x68, 0x7cb304→+0x6c). |
| DAT_0059E678 | VTable_UIObject_59E678 | UI | ptr | read | 2 | C++ vtable pointer for UI object class. Used in constructor FUN_0040ac00 and destructor FUN_0040ac40. |
| DAT_0059E790 | Threshold_59E790 | physics | double | read | 2 | Threshold comparison constant used in a chain of 12+ double comparisons (FUN_00413820, FUN_004139c0). Maps input parameter value to output enum index (0x0-0x10 range). |
| DAT_008ACFB8 | TimingsConst2 | race/session | float | read | 2 | Timing/race session constant used in FUN_004C7F30 alongside RaceTimeOffset/RaceTimeThreshold for session progress calculation. |
| DAT_007D00F8 | GameStateUpperBound | game/engine | int | read | 2 | Upper bound/clamp maximum for GameState (DAT_007d00ec). If GameState exceeds this value, it's clamped back. Related to GameStateMin (DAT_007d00f4). |
| DAT_005C3F90 | VTable_5C3F90 | unknown | ptr | read | 2 | C++ vtable pointer referenced by FUN_00432A70 and FUN_00432BF0. No source excerpts — exact class unknown. |
| DAT_007CCA48 | RenderFloat_A | renderer/d3d | float | read/write | 2 | D3D render state float parameter. Initialized to 0 by FUN_0044C680. Updated from vehicle struct field +0x1140 in FUN_004537B0. Clamped against minimum value at +0x50. |
| DAT_007CCFE8 | RenderFloat_CFE8 | renderer/d3d | float | read/write | 2 | D3D render state float parameter. Initialized to 0.0 by sub_44CB14. Used in vehicle setup function FUN_004537B0. |
| DAT_007CCFA4 | RenderFloat_CFA4 | renderer/d3d | float | write | 2 | D3D render state float parameter. Initialized to 0 by FUN_0044D1C0 alongside int at +0xA0 set to 0x6D and float at +0xA8 set to -1.0. |
| DAT_007CCDE0 | RenderStatePtr_CDE0 | renderer/d3d | ptr | read | 2 | Render state pointer used in large switch/if-else chain in FUN_00452B10 (one of ~30 render state globals matched by pointer identity). |
| DAT_007CA578 | RenderState_A578 | renderer/d3d | int | read | 2 | Render state parameter referenced by FUN_004537B0 and FUN_00454350. |
| DAT_007C56B0 | SessionState_56B0 | game/engine | int | read/write | 2 | Session/state variable near SessionType (0x7c56a4) and RacePhase (0x7c56a8). Used by session management functions. |
| DAT_007C56B8 | SessionHashSeed | game/engine | int | read | 2 | Hash function seed used in FUN_00460770 for checksum/hash computation: `param1*0x122572e8 + param2*-0x13797 + 0x1bf00fb1 + DAT_007c56b8`. |
| DAT_005C6590 | StrClientTeamSelect | UI | string | read | 2 | String constant "ClientTeamSelect" or similar UI menu string. Used in network/client UI code. |
| DAT_005C6954 | StrProfileIconBmp | UI | string | read | 2 | Filename string "profileicon.bmp" for profile icon bitmap in UI/profile management functions. |
| DAT_005ABAC8 | VTable_UIObject_BAC8 | UI | ptr | read | 2 | C++ vtable pointer for UI/RenderView class. Used in FUN_00487ed0 constructor and FUN_00487f30 destructor. |
| DAT_005CC5BC | StrAttributeSet | UI/renderer | string | read | 2 | String constant "AttributeSet" used in UI render/attribute system. |
| DAT_005ACAF0 | ABNormalThreshold2 | ai_physics | float | read | 2 | AI ability/braking threshold in rating calculation (FUN_0049B7A0). Second-tier threshold for race ability/aggression classification. |
| DAT_005ACB30 | PhysicsForceThreshold | physics | float | read | 2 | Force/traction comparison threshold used in physics collision/grip calculations. Compared against dot product of direction vectors (FUN_004A3B50). |
| DAT_005ACC90 | ShortNormMin | math/utility | float | read | 2 | Minimum clamp value for float-to-short (16-bit) conversion in audio/3D math. Used with ShortNormMax (0x5acc94) to clamp values before multiplying by _DAT_0059E714 for short quantization. |
| DAT_005D2AC4 | StrTotalPointsScore | UI | string | read | 2 | String constant "TotalPointsScored" or similar scoring text for season/standings display. |
| DAT_005D293C | StrGameOptOpponent | UI | string | read | 2 | String constant "GameOptOpponent" for game options opponent selection UI. |
| DAT_005ACEA4 | RotationFactor | math/3d | float | read | 2 | Rotation/quaternion factor used in 3D audio math (FUN_005285F2). Multiplied with delta angles in rotation matrix calculations. |
| DAT_005D4AE9 | FmtStr_5D4AE9 | locale/ui | byte | read | 2 | Format string identifier passed to FUN_0058815F for text rendering in HUD/UI overlay functions (FUN_004D9DD0, FUN_004DB7F0). |
| DAT_005D67B0 | D3DCaps_BlendVal0 | renderer/d3d | int | read | 2 | D3D device capability value for blend state 0. Part of a set (0x5d67b0-0x5d67d0) indexed by device cap switch in FUN_004F8280. |
| DAT_008AFE7C | RaceFlag_7C | race/session | int | read/write | 2 | Race session flag checked for zero in FUN_004F9B20. Located near RaceTimeOffset (0x8afea0) timing globals. |
| DAT_005D77C8 | FnPtr_5D77C8 | audio/3d | ptr | read | 2 | Function pointer called in FUN_0050C27F with sub_50FEA7(1u). Audio/3D sound callback. |
| DAT_008D46B0 | SSEMathInitFlags | math/sse | byte | read/write | 2 | Lazy initialization flags for SSE math constants (Newton-Raphson sqrt approximation). Bit 0 tracks xmmword_8D4690 init, bit 1 tracks xmmword_8D46A0 init. Used in 3D vector normalization. |
| DAT_005B0840 | StrInvalidDistance | zlib | string | read | 2 | Zlib string constant "invalid distance code" — part of zlib decompression library embedded in executable. Not game logic. |
| DAT_008B8E4C | MipLODBiasCount | renderer/texture | int | read/write | 2 | Mipmap LOD bias reduction count. Stored via FUN_0053D400, read in FUN_00550080. Controls how many mip levels are skipped during texture resolution reduction. |
| DAT_005B8998 | ShadowFrustumScale | renderer/shadow | double | read | 2 | Shadow frustum scale multiplier. Used in shadow view rendering (FUN_00560C10, FUN_00560FE0) to scale scene bounds for shadow projection frustum calculation. |
| DAT_008D2C10 | DynamicsBlock_2C10 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity initialization (FUN_00578F76 case 1 sets to 0.0). |
| DAT_008D2558 | DynamicsBlock_2558 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization (FUN_00575BBD). Set to 0.0 in identity init (FUN_00578F76 cases 3 and 4). |
| DAT_008D24B8 | DynamicsBlock_24B8 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Set to 0.0 in identity init (FUN_00578F76 cases 3 and 4). Initialized to 1.0 in case 4. |
| DAT_008D26D8 | DynamicsBlock_26D8 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity init. |
| DAT_008D38C0 | DynamicsBlock_38C0 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace (272-byte block). Used in LDL^T factorization and identity initialization. |
| DAT_008D2A78 | DynamicsBlock_2A78 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity initialization. |
| DAT_008D32A0 | DynamicsBlock_32A0 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity initialization. |
| DAT_008D34F0 | DynamicsBlock_34F0 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace (block at 0x8D34F0). Used in LDL^T factorization and identity init. |
| DAT_008D37F8 | DynamicsBlock_37F8 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace (near 0x8D3870 block). Used in LDL^T factorization and identity init. |
| DAT_008D3778 | DynamicsBlock_3778 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity init. |
| DAT_008D36F8 | DynamicsBlock_36F8 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity init. |
| DAT_008D3948 | DynamicsBlock_3948 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace (272-byte block ending). Used in LDL^T factorization and identity init. |
| DAT_008D37C0 | DynamicsBlock_37C0 | dynamics/solver | double | read/write | 2 | Element of dynamics constraint solver workspace. Used in LDL^T factorization and identity init. |
| DAT_005E6BF0 | FPUConst_5E6BF0 | math/crt | tbyte | read | 2 | x87 FPU extended-precision constant used in floating-point math library routines (_ftol2/_ftol internal). Loaded via `fld tbyte_5E6BF0` in FUN_0058D9BE. |
| DAT_005E751C | FPUDivConst_5E751C | math/crt | double | read | 2 | Double constant used in x87 FPU division/math library routines (FUN_005910B6, FUN_0059136E). Multiplied against divisor in iterative division. |
| DAT_005E9C38 | CodePageTableEnd | locale/codepage | byte | read | 2 | End marker for codepage conversion tables (range 0x5E9B48-0x5E9C37). Used in codepage initialization loop boundary check. |
| DAT_005BB9B8 | TypeInfo_out_of_range | crt/exceptions | ptr | read | 2 | C++ RTTI type info for `std::out_of_range` exception. Used by `__CxxThrowException_8` in FUN_0059AFFF and FUN_0059AF68. |
