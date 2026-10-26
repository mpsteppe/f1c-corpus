=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_007CD204 | ResourceDispatch_007CD204 | setup | int[] | read | 31 | Dispatch table for resource/data parsing. Used in FUN_0045f030 with switch on values 0x1002-0x100b. Iterates linked list at param_1+0x1b780. |
| DAT_005E6788 | AssetBankVTable | dynamics | ptr | offset | 19 | Vtable or function pointer table for asset bank. Referenced by 10-byte thunk wrappers calling FUN_00598815 / FUN_00599958. |
| DAT_008D4248 | DynamicsBlock_8D4248 | dynamics | ptr | offset | 10 | Pointer within physics dynamics workspace (0x8D0000 block). Referenced by constraint solver thunks. |
| DAT_007CDB70 | StringCompareBuffer_007CDB70 | session | ptr | offset | 8 | Buffer used in FUN_00587c20 string comparison context with DAT_005CC4F8 and DAT_005CC4F4. Part of session initialization logic. |
| DAT_005C25BC | String_Stewart | fileformats | char[] | offset | 7 | String literal "Stewart" — driver name used in file parsing (references from 0x00417640, 0x0041f340, etc.). |
| DAT_005C56A4 | SourcePathFormatString | fileformats | char[] | offset | 6 | Format string for D:\dev\F1_1999_2002\Source\ path construction. Used by 0x00455bf0-0x00455f00. |
| DAT_008D3F98 | CurrentLocaleID | system | int | both | 6 | Windows locale identifier. Read via IsValidLocale(), written by EnumSystemLocalesA callback. Controls language/codepage selection for text rendering. |
| DAT_005C2648 | String_Nurburgring | track | char[] | offset | 5 | String literal "Nurburgring" — track name in setup file parsing. |
| DAT_0059ED28 | PhysicsMinDeltaThreshold | physics_math | double | read | 5 | Physics constant threshold. Compared with param in FUN_00441650 (engine model). Multiplied with _DAT_0059ed38. Clamped to 3.814697265625e-06 minimum. |
| DAT_005B4788 | HuffmanDecodeTable | audio | int[] | read | 5 | Huffman/arithmetic decoding lookup table. Indexed by `*(uint *)(&DAT_005b4788 + iVar1 * 4)`. Used in FUN_0052e5e0 and FUN_0052e6f0 (audio codec). |
| DAT_0059E9C8 | Unknown_Double_59E9C8 | physics_math | double | read | 4 | Physics/engine double constant. Only read access by 4 functions. Exact purpose unclear. |
| DAT_005C5988 | FormatString_S | setup | char[] | offset | 4 | Format string "%s" for menu/UI text formatting. |
| DAT_007CEE88 | SessionInitFlags | session | int | both | 4 | Session initialization flag, set to 0 during vehicle load (FUN_004b70b0). Checked in race UI logic. |
| DAT_008B8E24 | AudioInitFlag | audio | int | both | 4 | Audio system initialization flag. Set to 1 in FUN_0053c360 init. Set to 0 in FUN_0053d430. Controls whether audio subsystem is active. |
| DAT_005B9D28 | RuntimeErrorVTable | system | ptr | offset | 4 | MSVC `std::runtime_error` vtable (`??_7runtime_error@std@@6B@`). |
| DAT_005C30B0 | StringDelimiter_CStr | system | char[] | offset | 3 | String terminator/delimiter constant used in FUN_004236f0 and FUN_004a1b90 for CSS/INI parsing. |
| DAT_005D6D70 | EngineBrakeTorqueFactor | physics_math | double | both | 3 | Engine braking torque multiplier. Set by FUN_004f9f70: 0→1.0, 1→_DAT_005ad268, 2→0.12. Used in engine simulation (FUN_00441650). |
| DAT_005C58E4 | FormatString_SCenterFF | UI | char[] | offset | 3 | Format string "S_CenterF_F" for UI text centering. |
| DAT_005C6930 | FormatString_I063f | setup | char[] | offset | 3 | Format string "%I06.3f" for lap time formatting. |
| DAT_005ACB08 | FloatThreshold_5ACB08 | game_logic | float | read | 3 | Comparison threshold float. Used in FUN_0049e5b0 (color mapping) and FUN_004a6e50 (animation state). |
| DAT_005D3494 | PhysicsStepAccumulator | dynamics | float | both | 3 | Accumulator for physics sub-stepping. Read/written in integration loops (FUN_004cb860, FUN_004cc1d0). |
| DAT_005D76C4 | CollisionDispatchFn | collision | ptr | both | 3 | Function pointer for collision dispatch. Set to FUN_0050368a or FUN_00503772 based on CPU detection (FUN_0050fc7d). |
| DAT_005DA718 | FileStreamVTable | system | ptr | offset | 3 | Vtable for file I/O stream class. |
| DAT_008D2FA8 | ConstraintMatrix_8D2FA8 | dynamics | double | both | 3 | Element of constraint solver matrix workspace. Part of LDL^T factorization (FUN_00575bbd). Zeroed in solver init (FUN_00579ccf). 80-byte stride block. |
| DAT_008D31B8 | ConstraintMatrix_8D31B8 | dynamics | double | both | 3 | Element of constraint solver matrix workspace. LDL^T factorized. 64-byte stride block. |
| DAT_008D2EB0 | ConstraintMatrix_8D2EB0 | dynamics | double | both | 3 | Element of constraint solver matrix workspace. Zeroed in init. Part of block sparse structure. |
| DAT_008D3C08 | PoolAllocCounter | dynamics | int | both | 3 | Counter for linked-list memory pool allocations in constraint solver. Incremented on alloc (FUN_0057abb0), decremented on free (FUN_0057acb0). |
| DAT_005B9DC0 | ExceptionVTable | system | ptr | offset | 3 | MSVC `std::exception` vtable (`??_7exception@@6B@`). Used in custom exception constructors FUN_0059bf19, FUN_0059bf56, ~exception. |
| DAT_005EA508 | UIDispatchTable | UI | ptr | read | 2 | Jump table base for UI mode dispatch in FUN_00409440. Indexed by param_2 (0-8+). |
| DAT_0059E7C8 | RangeThreshold_59E7C8 | game_logic | double | read | 2 | Threshold constant for range-based value selection. Part of cascade: 59E7C8 > 59E7C0 > 59E7B8 > ... Used in AI ability mapping. |
| DAT_005C2D80 | String_Windows2000 | system | char[] | offset | 2 | String literal "Windows 2000" used in OS detection. |
| DAT_0059E9BC | AngleConversionFactor | math_util | float | read | 2 | Float conversion factor for angle/time. Used in FUN_00567700 for angle decomposition. |
| DAT_007C740C | Unknown_Camera_7C740C | renderer | int | write | 2 | Initialized to 0 alongside camera system globals (0x7c73e8-0x7c7424). Part of camera state. Freed in shutdown. |
| DAT_0059EDB8 | ShiftPointFactor | vehicle_physics | double | read | 2 | Double factor for gear shift point calculation. Used in FUN_00443b70 and FUN_004441f0. |
| DAT_007CCF84 | VehicleSetupFloat_7CCF84 | vehicle_physics | float | write | 2 | Initialized to 0, then set from vehicle struct at +0x1150 in FUN_004537b0. Copied with lower-bound clamp. Part of vehicle parameter block. |
| DAT_007CCF98 | VehicleSetupFloat_7CCF98 | vehicle_physics | float | both | 2 | Initialized to 0.0 in FUN_0044d0a0, read in FUN_004537b0 vehicle setup copy. Part of vehicle parameter block. |
| DAT_0059EF64 | HeadlightRangeFactor | renderer | float | read | 2 | Float multiplier for headlight/distance rendering. Used in FUN_00451720 and FUN_004feaf0. |
| DAT_007CD060 | VehicleSetupDWord_7CD060 | vehicle_physics | float | read | 2 | Read in FUN_004537b0 vehicle parameter copy block. |
| DAT_005C59A0 | String_ActivationRadius | setup | char[] | offset | 2 | String "ActivationRadi" or similar — collision/trigger activation radius setting. |
| DAT_005C5E60 | MenuResourcePtr | UI | ptr | offset | 2 | Menu resource pointer, used in UI rendering functions. |
| DAT_007D0EC8 | OptionFlagBuffer | session | ptr | both | 2 | Buffer for game option flags. Written during config read (FUN_00461900), used for flag lookup. Part of option/SESSION block. |
| DAT_005C6968 | FormatString_SS | UI | char[] | offset | 2 | Format string "%s %s" for concatenated text display. |
| DAT_005A6E70 | TextureManagerVTable | renderer | ptr | offset | 2 | Vtable for texture manager class. Set in ctor FUN_0047f370, used in dtor FUN_0047f3f0. |
| DAT_005CC220 | String_CubeError | renderer | char[] | offset | 2 | Error string "Cube error loading..." for cube map/texture load failures. |
| DAT_005ACA74 | UIElementVTable | UI | ptr | offset | 2 | Vtable for UI element class. Set in FUN_004991e0 constructor. |
| DAT_005CD090 | String_ClassName | UI | char[] | offset | 2 | String literal "ClassName" used in UI class registration. |
| DAT_005ACBD8 | UITextureVTable | UI | ptr | offset | 2 | Vtable for UI texture class. Set in FUN_004a70e0 (large UI setup function). |
| DAT_005D2858 | String_Opponent | session | char[] | offset | 2 | String "Opponent" used in race session setup. |
| DAT_005D29C0 | String_RaceCondWeather | weather | char[] | offset | 2 | String "RaceCondWeathe" — race condition / weather string. |
| DAT_005D36D8 | String_Reaction | ai | char[] | offset | 2 | String "Reaction" used in AI personality setup. |
| DAT_005C753C | Unknown_5C753C | network | int | both | 2 | Referenced near 0x008d8000. Purpose unclear. One function is 36-byte stub. |
| DAT_005AD1C4 | CollisionVelocityThreshold | collision | float | read | 2 | Minimum velocity threshold for collision detection. Used in FUN_004e96c0 and FUN_004f1c40. |
| DAT_005D67A0 | SteeringForceCoeff | vehicle_physics | float | both | 2 | Steering force calculation coefficient. Part of array with _DAT_005d679c, _DAT_005d6798, _DAT_005d67ac, _DAT_005d67a8, _DAT_005d67a4. Used in vehicle dynamics (FUN_004f8440). |
| DAT_005C6E7C | String_Monsoon | weather | char[] | offset | 2 | String "Monsoon" — weather mode name. |
| DAT_005AFD68 | TickIntervalDouble | math_util | double | read | 2 | Double interval constant for tick/timing conversions. |
| DAT_005D9338 | MathSinCosPolyCoeff | math_util | double | read | 2 | 64-bit polynomial coefficient for MMX sin/cos approximation (FUN_005295e0, FUN_00529700). Part of coefficient table with DAT_005d9320-0x5d9348. |
| DAT_008B8E40 | AudioMixFixedPointConst | audio | int64 | both | 2 | Packed 64-bit constant 0x1000100010001 for audio mixing. Used as multiply-add constant for 16.16 fixed-point sample blending in FUN_0055eb30. |
| DAT_005DC274 | String_Type | fileformats | char[] | offset | 2 | String "Type" used in file format parsing. |
| DAT_008D2498 | ConstraintMatrix_8D2498 | dynamics | double | both | 2 | Constraint solver matrix element. Part of identity initialization in sub_578F76 case 1. |
| DAT_008D2D28 | ConstraintMatrix_8D2D28 | dynamics | double | both | 2 | Constraint solver matrix element. Case 2 in sub_578F76 identity init. |
| DAT_008D2770 | ConstraintMatrix_8D2770 | dynamics | double | both | 2 | Constraint solver matrix element. Case 4 in sub_578F76 identity init. |
| DAT_008D2B28 | ConstraintMatrix_8D2B28 | dynamics | double | both | 2 | Constraint solver matrix element. Case 2 zero-init. |
| DAT_008D2798 | ConstraintMatrix_8D2798 | dynamics | double | both | 2 | Constraint solver matrix element. Not in identity init (case untracked). |
| DAT_008D3288 | ConstraintMatrix_8D3288 | dynamics | double | both | 2 | Constraint solver matrix element. Stride-based block in LDL^T workspace. |
| DAT_008D3BF0 | ConstraintSolverState | dynamics | ptr | offset | 2 | Constraint solver state pointer. Referenced by LDL^T factorization and thunk. |
| DAT_008D2DA0 | ConstraintMatrix_8D2DA0 | dynamics | double | both | 2 | Constraint solver matrix element. 24-byte stride block. |
| DAT_008D3630 | ConstraintMatrix_8D3630 | dynamics | double | both | 2 | Constraint solver matrix element. 136-byte stride block. |
| DAT_008D3770 | ConstraintMatrix_8D3770 | dynamics | double | both | 2 | Constraint solver matrix element. 144-byte stride block. |
| DAT_008D3930 | ConstraintMatrix_8D3930 | dynamics | double | both | 2 | Constraint solver matrix element. 272-byte stride block (largest). |
| DAT_008D3540 | ConstraintMatrix_8D3540 | dynamics | double | both | 2 | Constraint solver matrix element. 120-byte stride block. |
| DAT_008D3688 | ConstraintMatrix_8D3688 | dynamics | double | both | 2 | Constraint solver matrix element. 136-byte stride block (offset). |
| DAT_008D5A54 | CleanupStackPtr | system | ptr | read | 2 | Stack pointer for atexit cleanup handlers. Used in FUN_00587ac0 (push) and FUN_00589cc6 (pop/execute on terminate). |
| DAT_008D41CC | ConfigParseBuffer | system | ptr | offset | 2 | Configuration parse buffer boundary. Checked in FUN_0058f8eb (mem cleanup) and FUN_005968f6 (config value parsing, iterates 0x8d41c4-0x8d41cb). |
| DAT_008D5A48 | ArgvParsedFlag | system | int | both | 2 | Flag set to 1 after command-line argv is parsed into DAT_008d3e90 array. Checked before config key lookup. |
| DAT_005B9CE4 | IosFailureVTable | system | ptr | offset | 2 | MSVC `std::ios_base::failure` vtable (`??_7failure@ios_base@std@@6B@`). Used in exception FUN_0059a854. |
