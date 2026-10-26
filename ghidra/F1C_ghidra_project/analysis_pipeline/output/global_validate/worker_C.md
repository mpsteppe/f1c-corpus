=== TRIAGE LINES ===
(leave blank)

=== FULL ENTRIES ===
<!-- target: docs/12-globals-reference.md -->

| Address | Name | Module | Type | Access | Ref Count | Notes |
|---------|------|--------|------|--------|-----------|-------|
| DAT_008afe64 | RaceTimeDelta | race | float | read | 73 | Accumulated race time delta — added to lap/session timers each frame. Adjacent to _DAT_008afe98 (RaceTimeOffset), _DAT_008afea0 (RaceTimeAbsolute). High ref count across physics, HUD, replay, and AI systems. |
| DAT_00800000 | MMXFlag | math_util | int | offset | 23 | CPU feature detection flag — bit mask 0x800000 from CPUID leaf 1 (EDX bit 23 = MMX technology support). Functions check this to select MMX-optimized 3D geometry code paths. Referenced alongside cpuid_Version_info(). |
| DAT_005c6784 | sFormatPath | setup | const char* | offset | 14 | Format string "%s%s" used in file path concatenation — builds "tmpvehicle.scn", "vview.scn", and other scene filenames from directory base + filename. Occupies .rdata segment. |
| DAT_007ca594 | WheelBrakeBiasThreshold | vehicle_physics | float | offset | 9 | Brake bias ratio threshold — compared against _DAT_0059e43c (1.0f) and DAT_0059e440 (0.0f). State variable for wheel brake torque application mode (0=open, 1=applied, 2=released). |
| DAT_005c2618 | sTeamFerrari | setup | const char* | offset | 7 | String literal "Ferrari" — team name constant used in setup/season data files. |
| DAT_005c5798 | sFalse | setup | const char* | offset | 7 | String literal "False" — boolean display string used in config menu and UI elements. |
| DAT_005cce54 | asc_5CCE54 | UI | const char* | offset | 6 | Format string used in championship standings display — associated with FUN_0049c0b0-family functions (standings/points rendering). |
| DAT_005c26cc | sTrackImola | track | const char* | offset | 5 | String literal "Imola" — track name constant for Autodromo Enzo e Dino Ferrari circuit. |
| DAT_0059e8e4 | WetGripThreshold | vehicle_physics | float | read | 5 | Wet traction threshold float — compared against tire slip angle/ratio in vehicle dynamics (FUN_00426cf0, FUN_004270a0). When exceeded, triggers wet-surface grip reduction logic. |
| DAT_007d032c | Unknown_Race_TimerFlag | race | int | read | 5 | Race timer/clock state flag — read by session initialization, HUD update, and race flow functions. Functions: 0x004a00a0, 0x004a0760, 0x004a08e0, 0x004a09f0, 0x004fa320. |
| DAT_005b9c50 | VTable_basic_ios | CRT | ptr | offset | 5 | MSVC C++ standard library vtable for `std::basic_ios<unsigned short>` — RTTI-excluded vtable pointer for stream I/O objects. Occupies .rdata. |
| DAT_008afee4 | RainFadeCoeff | renderer | float | read | 4 | Rain/splash fade coefficient — used in particle emitter update (FUN_004ca2d0) for rain drop scaling, and in renderer culling (FUN_004cfcc0) to fade particle systems. Multiplied with _DAT_005ace98 (rain density). |
| DAT_005a4550 | VTable_UISlider | UI | ptr | offset | 4 | Vtable pointer for UI slider/control class — referenced in destructor chains (FUN_00476730, FUN_00477440, FUN_0047fb10). Superclass in slider widget hierarchy. |
| DAT_005af778 | ZLibDistanceTable | network | int* | offset/read | 4 | Huffman distance lookup table for zlib decompression (inflate). Indexed by bit-length patterns in FUN_00510d60 (decompression core). Reference to address 0x005af778 is loaded as loop base. |
| DAT_008d3e40 | MathErrHandlingFlag | CRT | int | read | 4 | Math library error handling mode flag — checked in FUN_00588212 (double->string conversion), FUN_0058858d (asin), FUN_005894bd (acos). When 0, triggers __startOneArgErrorHandling/__math_exit; when nonzero, returns directly. Controls whether math domain errors are handled or suppressed. |
| DAT_005ecdc8 | SeasonScoringArray[0x48c0] | game | struct | offset | 3 | Base of season scoring array (stride 0x48c0 per driver). Indexed by TeamID to store points/standings. Referenced alongside DAT_005ed700, DAT_005ed704 (per-vehicle scoring fields). Iterated in FUN_0040c7a0 (team color sync). |
| DAT_005c3738 | MessageFormatBuffer | UI | char* | offset | 3 | String buffer for printf-style formatted messages — used in FUN_0042ec00 (message formatting) with _DAT_005ec4cc (MessageBuffer). Points to either this or AT_005c3734 depending on param. |
| DAT_005c55cc | sClutch | UI | const char* | offset | 3 | String literal "Clutch" — control binding label for clutch input mapping in settings UI. |
| DAT_005c6620 | sGameTitle | setup | const char* | offset | 3 | String literal "F1 Challenge 99-02" — game title string used in window caption, splash screen, and file dialogs. |
| DAT_005cc9e4 | GameMenuState | game | int | read/write | 3 | Game menu/flow state flag — set to 2 in FUN_004a0a80 (game flow advance) when entering race session. Read by FUN_00485b90, FUN_00496e90 for menu state branching. |
| DAT_005f073c | VehiclePitFlags[0x48c0] | race | int | read/write | 3 | Per-vehicle pit stop state flags array (stride 0x48c0). 0 = not pitting, 1 = pitting. Indexed by VehicleIndex. Read in FUN_004dad80 (race logic update) and FUN_004dae00 (finish order check). Written in FUN_004b3400 (game message handler, case 2/2). |
| DAT_005d4ae8 | PositionNameSuffix | UI | byte | read | 3 | Ordinal suffix offset for position display — added to driver index to select "1st", "2nd", "3rd", etc. text. Used in FUN_004d98a0 (standings overlay rendering) with string format from DAT_005ccef0. |
| DAT_005d8ac0 | SplineCoeffB | renderer | xmmword | read | 3 | SSE packed float polynomial coefficients for Hermite/cubic spline interpolation in 3D geometry processing. Used by sub_51F400, sub_51F4C0, sub_51F560 — degree-3 polynomial evaluation with SSE `_mm_mul_ps`/`_mm_add_ps`. Adjacent to xmmword_5D8AB0 (CoeffA) and xmmword_5D8A90 (CoeffC). |
| DAT_008b8e2c | RendererMipmapFlag | renderer | int | read/write | 3 | Mipmap/texture filtering mode flag — set to 1 in renderer init (FUN_0053c360), can be toggled via FUN_0053d410. Checked in FUN_00550080 (surface/texture creation) to select resolution level or filtering mode. Part of renderer config block (0x008b8e24-0x008b8e34). |
| DAT_008d26a0 | DynSolver_Block5_Element00 | dynamics | double | read/write | 3 | Dynamics constraint solver workspace double — element [5][0] of the block-sparse LDL^T/Cholesky factorization matrix at 0x008d2120-0x008d3938. Indexed by vehicle skeleton node index (0-34). Zeroed by sub_579CCF (memset pattern), set to identity by sub_578F76 (case 0-34), factorized by sub_575BBD. |
| DAT_008d2c88 | DynSolver_Block11_Element13 | dynamics | double | read/write | 3 | Dynamics solver workspace — element in block 11 of constraint matrix. Referenced by same three functions (sub_575BBD, sub_578F76, sub_579CCF). |
| DAT_008d3160 | DynSolver_Block13_Element24 | dynamics | double | read/write | 3 | Dynamics solver workspace — element in block 13 of constraint matrix. |
| DAT_008d2768 | DynSolver_Block6_Element13 | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 6. |
| DAT_008d26c8 | DynSolver_Block5_Element6 | dynamics | double | read/write | 2 | Dynamics solver workspace — element [5][6] of constraint matrix. |
| DAT_008d2c40 | DynSolver_Block11_Element8 | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 11. |
| DAT_008d2a68 | DynSolver_Block9_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 9. |
| DAT_008d3350 | DynSolver_Block14_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 14. |
| DAT_008d3368 | DynSolver_Block14_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 14 (adjacent). |
| DAT_008d36b8 | DynSolver_Block15_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 15. |
| DAT_008d30c8 | DynSolver_Block13_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 13. |
| DAT_008d36e8 | DynSolver_Block15_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 15 (adjacent). |
| DAT_008d3938 | DynSolver_Block16_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 16 of constraint matrix. |
| DAT_008d3678 | DynSolver_Block15_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 15. |
| DAT_008d37c8 | DynSolver_Block16_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — element in block 16 (adjacent). |
| DAT_005e77f0 | DST_StartYear | setup | int | read/write | 3 | Daylight Saving Time start year — set to -1 initially, then updated to current year by timezone initialization (FUN_005921f3). Written alongside DAT_005e7800 (DST_EndYear), DAT_005e77f4 (DST_StartMonth), DAT_005e775c (DST_Enabled). |
| DAT_005be6c4 | VTable_CTI_PtrArray | UI | ptr | read | 2 | Vtable pointer table for class/type-info hierarchy — indexed by param_1 to return function pointers for UI object dispatch. Used by FUN_00404cc0, FUN_00404d00. |
| DAT_005bea08 | sDriver | UI | const char* | offset | 2 | String literal "Driver" — UI label for driver selection/name display. |
| DAT_005f0714 | VehicleDNFCount[0x48c0] | race | int | read | 2 | Per-vehicle DNF (Did Not Finish) or retirement count array (stride 0x48c0). Checked >=1 before allowing driver swap/penalty application in FUN_00419690 (session UI events). Also compared against DAT_008acf8c (TotalRaceLaps) in race phase logic (FUN_004c7f30). |
| DAT_0059e958 | WheelbaseMult | vehicle_physics | float | read | 2 | Wheelbase scaling multiplier — used in vehicle dynamics (FUN_004270a0) and suspension geometry (FUN_00451720) to scale longitudinal weight transfer calculations. |
| DAT_005cd0ec | sBuildVersion | setup | const char* | offset | 2 | Build version string "D:\Dev\F1_1999_2002" path suffix — used in debug/log output and version display. |
| DAT_005c3f88 | Off_ButtonBinding | UI | ptr | read | 2 | Function pointer table for button binding UI class — vtable/offset table for control mapping dialog. |
| DAT_007ca3f0 | SteeringWheelRange | input | float | read/write | 2 | Steering wheel rotation range (degrees) — initialized to 0.0 in FUN_0044c6e0 (input reset), compared against minimum threshold in FUN_004537b0 (wheel calibration). Part of input device config block. |
| DAT_007cc9c8 | BrakePedalDeadzone | input | float | read/write | 2 | Brake pedal deadzone threshold — initialized to 0.0 in FUN_0044cc94, compared against calibrated brake value in FUN_004537b0 (pedal calibration). |
| DAT_007ca57c | ForceFeedbackGain | input | int | read/write | 2 | Force feedback overall gain (0x3d = 61%) — initialized in FUN_0044d280, read in FUN_00452810 (FFB effect binding). Part of input device config block. |
| DAT_007ccdf8 | SteeringSensitivity | input | int | offset/read | 2 | Steering sensitivity curve index — used in input binding resolution (FUN_00452b10, FUN_004537b0) to select sensitivity profile from steering config table. |
| DAT_007ca560 | ThrottlePedalRange | input | int | read | 2 | Throttle pedal maximum range value — read during input calibration (FUN_004537b0, FUN_00454350) to normalize throttle axis. |
| DAT_008d4688 | NetworkSaltBuffer | network | int | write | 2 | XOR-key buffer for network packet obfuscation (6 bytes XORed with 0x3E from _DAT_0059f0c4). Used in FUN_0045d260 to initialize session authentication key for multiplayer game state packets. |
| DAT_007ceb10 | RaceSetting_Flag1 | game | int | offset/read | 2 | Session configuration flag byte — written from network/load game state (FUN_00461900), read back during save state (FUN_00461610). Part of session save block alongside DAT_007d0a44, DAT_007d0fc4, etc. |
| DAT_007cd468 | Unk_Setup_Flag | setup | int | offset | 2 | Setup/scene flag — referenced in FUN_00466080 (thunk to scene load) and FUN_0046de10 (multiplayer session join). Unclear purpose. |
| DAT_005c6658 | sProfileIconBmp | UI | const char* | read/write | 2 | String pointer for profile icon bitmap filename "ProfileIcon_DFT.bmp" — used in UI profile management (FUN_0046cd20 reads for CopyFileA, FUN_00477cb0 overrides path in destructor). |
| DAT_005abed0 | VTable_EditBox | UI | ptr | offset | 2 | Vtable pointer for UI editbox/text input class — assigned in constructor (FUN_0048b420) and cleared in destructor (FUN_0048b4e0). |
| DAT_005cc542 | byte_5CC542 | UI | byte | read | 2 | Single-byte flag used in UI rendering functions (FUN_00492160, FUN_00493480). Exact purpose unclear — likely a text alignment or formatting flag. |
| DAT_005cce44 | sFormatTime | UI | const char* | offset | 2 | Format string "2d:06.3f" — time display format for lap/race time strings. Used in UI time formatting (FUN_0049be50, FUN_0049c4e0). |
| DAT_005cd5d8 | sTeamMass | UI | const char* | offset | 2 | String literal "TeamMass" — UI label for team mass/driver weight setting in car setup screen. |
| DAT_005acd28 | ScaleFactor | audio | double | read | 2 | Audio playback rate scaling factor — used in Miles Sound System integration (FUN_004b42e0, FUN_004b4360) to convert sample position/rate values. Multiplied with sample offset in FUN_004b4360. |
| DAT_005d2a98 | sTotalPoles | UI | const char* | offset | 2 | String "TotalPoles" — career/season statistics label for total pole positions earned. |
| DAT_005d2900 | sGameOptSpeedCompare | UI | const char* | offset | 2 | String "GameOptSpeedCompare" — UI label for game options speed comparison setting. |
| DAT_005acebc | RainDropAlphaMult | renderer | float | read | 2 | Rain drop alpha multiplier — used in particle/weather rendering (FUN_004cd6c0, FUN_004ce110) to scale raindrop transparency from hue value. Multiplied with _DAT_005acec0 (rain hue-to-alpha). |
| DAT_005acf5c | Unk_RaceState_Flag | race | int | read | 2 | Race state flag — read as constant 1082130432 (1.0f as int) in FUN_004db100, FUN_004db130 (trivial setters). Likely a speed factor or race rate multiplier. |
| DAT_005d67bc | HelmColor_Dark | UI | int | offset/read | 2 | Dark helmet color value — one of 3 helmet color pointers returned by FUN_004f8280 based on driver index. Switch cases 0xc-0x2c (helmet types) map to this color triplet. |
| DAT_008afe94 | RaceTimeAbsolute2 | race | float | read | 2 | Secondary race time accumulator — updated in FUN_004f9ad0 alongside _DAT_008afe90, _DAT_008afe98 (RaceTimeOffset), _DAT_008afea0 (RaceTimeAbsolute). Part of the layered race time system. |
| DAT_005d7860 | VTable_D3DDeviceVtable | renderer | ptr | read | 2 | Indirect function pointer — dereferenced and called in FUN_0050d84a as `(*_DAT_005d7860)()`. Direct3D device vtable or function pointer table for rendering context dispatch. |
| DAT_005af918 | MMX_PackedConstant | math_util | __m64 | read | 2 | MMX packed 64-bit constant used in 3DNow!/MMX vector normalization routines — bit pattern 0x8000000080000000 for sign masking. Used in sub_521831 (packed floating-point reciprocal square root). |
| DAT_005b47a0 | ZLibBitCountTable | network | int* | read | 2 | Huffman bit-length count table for zlib inflate — indexed by code length in FUN_0052e6f0, FUN_00531250 (decompression). Base address for bit-length lookup in .data section. |
| DAT_005dbce4 | sFormatHex | UI | const char* | offset | 2 | Format string "%s: 0x%X" — hex debug output format for setup/configuration logging. |
| DAT_005e5084 | sFormatDouble | UI | const char* | offset | 2 | Format string "%f %f %f" — double/float format string used in file I/O and debug output. |
| DAT_008d3878 | DynSolver_Block16_Element? | dynamics | double | read/write | 2 | Dynamics solver workspace — block 16 auxiliary element in constraint matrix. |
| DAT_005e64fc | MathFunctionPtrTable | CRT | ptr | offset/read | 2 | CRT math function pointer table — referenced by FUN_00588a34, FUN_00588d95. Dispatch table for double-precision math operations (sin, cos, sqrt, etc.). |
| DAT_008d3fc0 | TimeZoneInitFlag | setup | int | read/write | 2 | Timezone initialization flag — set to 0 initially, then 1 after GetTimeZoneInformation succeeds. Checked in FUN_0059249b to determine whether to use Windows timezone API or string-based offset parsing. |
| DAT_008d41d4 | CodePageAutoFlag | CRT | int | read/write | 2 | Code page auto-detection flag — set to 1 for OEM (GetOEMCP) or ACP (GetACP) auto-detection modes. Written in FUN_00596fed, read in FUN_00596e40 during code page table initialization. |
