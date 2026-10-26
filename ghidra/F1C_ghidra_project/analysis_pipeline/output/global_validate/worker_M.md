=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_005ea2c0 | SetupScenePtr | setup | ptr | offset | 31 | Setup/scene loading context pointer — passed to multiple scene/vehicle init functions, likely struct with +0x170 float arrays and +0x130 count fields |
| DAT_005e6768 | NullSubDispatcher | setup | ptr | offset | 20 | Array of null-sub dispatcher pointers — 10-byte thunks each calling different functions (FUN_00598815, FUN_00599958), used as trampoline table |
| DAT_008d4370 | DynamicsWorkBuffer | dynamics | ptr | offset | 10 | Dynamics solver workspace buffer — referenced by constraint solver functions, part of 0x8D0000 block |
| DAT_005c596c | sTrue | UI | string | offset | 8 | String literal "True" — used in UI text rendering |
| DAT_005c25c4 | sTeamName_Renault | setup | string | offset | 7 | String "Renault" — team name used in vehicle setup/config |
| DAT_005c3334 | sBuildPath | setup | string | offset | 6 | Build path string "D:\dev\F1_1999_2002\Source\..." — source directory assert string |
| DAT_008d3fa8 | LocaleLanguageStr | system | ptr | read,write | 6 | Locale/language string pointer — stores user-selected language name, used with GetLocaleInfoA |
| DAT_005c2654 | sTrackName_Monza | setup | string | offset | 5 | String "Monza" — track name lookup in scene configuration |
| DAT_0059ec60 | SuspensionTravelOffset | physics | double | read | 5 | Double added to suspension travel accumulator — used in spring/damper force calculation (+0x1c20, +0x1808 offsets) |
| DAT_005af9c8 | MMatrixConstants | math_util | 64-bit | read | 5 | 3DNow! matrix/rotation constants — used in MMX matrix construction (identity, rotation around axes) |
| DAT_0059e974 | AI_TrackPosThreshold | ai_db | float | read | 4 | AI track position threshold — compared with _DAT_008afee8 in gear/ability selection logic |
| DAT_005c57a0 | sClear | UI | string | offset | 4 | String "Clear" — used in UI rendering |
| DAT_007ced8c | UIRacePhaseFlag | UI | int | read,write | 4 | Race phase UI flag — zeroed during setup, checked during race phase transitions |
| DAT_008b6ac8 | StringBuffer | misc | byte | offset,write | 4 | String buffer area — copy/compare string operations, buffer at 0x8B6AC8 |
| DAT_005e7968 | HeapListHead | system | ptr | offset | 4 | Heap allocator linked list head — VirtualAlloc-based memory pool manager (block size 0x2020, arena 0x400000) |
| DAT_005c307c | sUnknown | UI | string | offset,read | 3 | String "Unknown" — used in UI for unknown driver/team name fallback |
| DAT_007ce97c | TireModelFlag | hdvehicle | byte | read,write | 3 | Tire model configuration bit — stored from config bitmask (bit 8 of setting word), format: (word >> 9) & 1 |
| DAT_005c58fc | sFormat_2s | UI | string | offset | 3 | Format string with two string placeholders — used in sprintf style calls |
| DAT_005c694c | FormatWord | UI | word | offset,read | 3 | Format specifier word — used in string formatting for display text |
| DAT_005cce6c | sLaps | UI | string | offset | 3 | String "Laps" — UI text for laps remaining display |
| DAT_005d3490 | CockpitUIFloat | UI | float | read,write | 3 | Cockpit UI display float — used in HUD/display rendering code |
| DAT_005d76c0 | PTR_FUN_SteerTable | dynamics | ptr | read,write | 3 | Steering function pointer table — dispatch table for steering calculations, assigned based on FUN_0050fc7d() return value |
| DAT_005da564 | sSDS_Format | audio | string | offset | 3 | SDS audio format string — used in Miles Sound System configuration |
| DAT_005e4eac | sFinal | audio | string | offset | 3 | String "Final" — audio/music state label |
| DAT_008d2a60 | DynMatrix_8D2A60 | dynamics | double | offset,read,write | 3 | Dynamics constraint matrix element — part of block sparse LDL^T factorization workspace, stride 40 between adjacent blocks |
| DAT_008d3138 | DynMatrix_8D3138 | dynamics | double | offset,read,write | 3 | Dynamics constraint matrix element — sub-block of factorization workspace, zeroed by sub_58BB10 with size 24 |
| DAT_008d3c04 | TaskListTail | system | ptr | read,write | 3 | Thread/task linked list tail pointer — doubly-linked list of task objects with alloc/free tracking |
| DAT_005b9c68 | PTR_VTABLE_5B9C68 | misc | ptr | offset | 3 | C++ vtable pointer — set in constructor/destructor, points to FUN_005b9ca0 and FUN_005b9c68 |
| DAT_005ea504 | UIMenuState | UI | int | read,write | 2 | UI menu state index — used in jump table dispatch based on param_2 |
| DAT_005bebb0 | DriverDataTable | ai_db | ushort | offset | 2 | Driver data table — array of ushort pairs (offset/range) indexed by driver ID from FUN_004144c0(), size 0x219 entries |
| DAT_005c2d90 | sWindowsNt | system | string | offset,read | 2 | String "Windows NT" — OS detection string |
| DAT_005c330c | PTR_SetupVTable | setup | ptr | offset | 2 | Setup module vtable pointer — used by FUN_0042bdd0 and FUN_004fe350 |
| DAT_005c3820 | sFormat_2fS | UI | string | offset | 2 | Format string "%.2f %s" — used in lap time formatting |
| DAT_0059eca8 | PhysicsTireDamping | physics | double | read | 2 | Double physics constant — used in tire damping calculation, combined with angular velocity |
| DAT_007cca74 | DriverStatThreshold | UI | float | read,write | 2 | Driver stat threshold float — initialized to 0, compared with vehicle stat values |
| DAT_007ccf94 | UIStatThreshold | UI | float | write | 2 | UI stat threshold float — initialized to 0, part of stat display values |
| DAT_007d23ec | UIRenderFloat | UI | float | read | 2 | UI render float constant — used in render/comparison logic |
| DAT_007cd0f4 | UIStatValue | UI | int | read | 2 | UI stat int value — read in driver stat display code |
| DAT_005c59b4 | sActivationLocation | UI | string | offset | 2 | String related to activation/location — UI text |
| DAT_0059f110 | PhysicsBrakeBias | physics | float | read | 2 | Physics brake bias coefficient — used in brake force calculation |
| DAT_007d0a4c | RaceModeIndex | race | int | read | 2 | Race mode index — compared with 1 to determine championship mode setup |
| DAT_005c6914 | sBestLap | UI | string | offset | 2 | String "Best Lap" — driver stats label |
| DAT_007cf230 | FramerateCounter | renderer | int | read | 2 | Framerate/render counter — compared with 16 threshold, formatted as "%d" |
| DAT_005ac540 | PTR_VTABLE_5AC540 | misc | ptr | offset | 2 | C++ vtable pointer — set in ctor, cleared in dtor |
| DAT_005aca30 | PTR_VTABLE_5ACA30 | misc | ptr | offset | 2 | C++ vtable pointer — set in ctor/dtor of UI class |
| DAT_005cd0a4 | sCubeRealTime | renderer | string | offset | 2 | String "CubeRealTime" — renderer object/class name |
| DAT_005acbe4 | PTR_LABEL_5ACBE4 | misc | ptr | offset | 2 | C++ vtable/label pointer — used by UI/input handler classes |
| DAT_005d2804 | sSeasonScoringInfo | game | string | offset | 2 | String "SeasonScoringInfo" — season scoring config identifier |
| DAT_005d29d4 | sRaceCondFlagRule | race | string | offset | 2 | String "RaceCondFlagRule" — race condition/flag rule identifier |
| DAT_005d3254 | SceneIndexCounter | setup | int | read | 2 | Scene index counter — cyclic counter 0-3, used in scene file path construction |
| DAT_005acf08 | PTR_VTABLE_5ACF08 | misc | ptr | offset | 2 | C++ vtable pointer — set in ctor/dtor |
| DAT_005ad184 | SteeringFilterThreshold | physics | float | read | 2 | Steering filtering threshold — clamps steering value to ±0.1 |
| DAT_005d679c | PedalForceCoeff | physics | int | read,write | 2 | Pedal force coefficient — used in brake/throttle force calculation with multiple coefficients |
| DAT_005ad2c0 | InterpCoeff | physics | float | read | 2 | Interpolation coefficient — used in LERP for physics parameter blending |
| DAT_005afd70 | D3DMatrixConstant | renderer | double | read | 2 | 3DNow! matrix constant — used in rotation/transformation matrix construction |
| DAT_005d9328 | TrigApproxCoeff | math_util | qword | read | 2 | 3DNow! trigonometric approximation coefficient — used in sin/cos polynomial approximation |
| DAT_008b6bd0 | UTF16_Buffer | misc | byte | offset | 2 | Unicode/buffer area — referenced by string functions, adjacent to DAT_008b6ac8 |
| DAT_005dc224 | sDir | system | string | offset | 2 | String "Dir" — directory path component |
| DAT_008d23e8 | DynMatrix_8D23E8 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (case 4: set to 0.0, memset size 32) |
| DAT_008d2c18 | DynMatrix_8D2C18 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (case 2: zero-filled during init) |
| DAT_008d26c0 | DynMatrix_8D26C0 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (case 4: zero-filled) |
| DAT_008d2780 | DynMatrix_8D2780 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (not in init: allocated but used by solver) |
| DAT_008d38b0 | DynMatrix_8D38B0 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (not in init: allocated for solver) |
| DAT_008d31c8 | DynMatrix_8D31C8 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace (gap between 0x8D3138 and 0x8D31B8 blocks) |
| DAT_008d38e0 | DynMatrix_8D38E0 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d38f0 | DynMatrix_8D38F0 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d3628 | DynMatrix_8D3628 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d36d8 | DynMatrix_8D36D8 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d3820 | DynMatrix_8D3820 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d3480 | DynMatrix_8D3480 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_008d3958 | DynMatrix_8D3958 | dynamics | double | read,write | 2 | Dynamics constraint matrix element — block sparse LDL^T workspace |
| DAT_005b8b60 | PTR_VTABLE_5B8B60 | system | ptr | offset | 2 | C++ vtable pointer — file/stream I/O class vtable, constructor loads from param_2+10 |
| DAT_005e9ac0 | PTR_AudioStreamBuffer | audio | ptr | read | 2 | Audio/Miles stream buffer pointer array — 3-entry buffer used by audio streaming code |
| DAT_005e788c | ExceptionHandlerCount | system | int | read | 2 | Exception handler registry counter — used in SEH handler iteration, compared with DAT_005e7888 |
| DAT_005bb668 | TypeInfo_IOSFailure | system | byte | offset | 2 | C++ RTTI type info for `std::ios_base::failure` — used in exception throw (`__CxxThrowException`) |
