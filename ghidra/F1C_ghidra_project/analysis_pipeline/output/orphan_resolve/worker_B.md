=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00585ea0 | callback | HIGH | Address passed as `&LAB_00585ea0` to FUN_0058a6eb from FUN_005837f0 (line 16). FUN_0058a6eb iterates param_3 times calling the function pointer. Registered as init callback. | FUN_005837f0 (via FUN_0058a6eb callback runner) |
| 0x004328c0 | utility_isolated | HIGH | Pure path accessor (17 bytes). Reads string at *param_1+8, returns DAT_005ea438 fallback. No game globals, no cross-refs. Inline-style utility. | — |
| 0x0044cb60 | game_logic_isolated | MEDIUM | Writes collision globals (DAT_007cd108=0x68). Zero cross-refs in any .c file. Likely called via static function pointer table in collision init coordinator (common pattern: ~40 similar collision init functions in same address range). No direct caller found in call graph. | — (table-driven) |
| 0x0044d100 | game_logic_isolated | MEDIUM | Writes collision globals (DAT_007ccf60=0x6b). Zero cross-refs. Same table-driven init pattern as other 0x0044cxxx-0x0044exxx collision inits. | — (table-driven) |
| 0x0044d6a0 | game_logic_isolated | MEDIUM | Writes collision globals (DAT_007cccc0=0x15). Zero cross-refs. Same table-driven init pattern. | — (table-driven) |
| 0x0044dc40 | game_logic_isolated | MEDIUM | Writes collision grid globals (DAT_007cce58=0x31 for 49x49 grid). Zero cross-refs. Same table-driven init pattern. | — (table-driven) |
| 0x0044e1e0 | game_logic_isolated | MEDIUM | Writes collision globals (DAT_007ccf48=0x48, DAT_007ccf5c=18000). Zero cross-refs. Same table-driven init pattern. | — (table-driven) |
| 0x0044e780 | game_logic_isolated | MEDIUM | Writes collision globals (DAT_007ccfec=0x57, DAT_007cd000=9000). Zero cross-refs. Same table-driven init pattern. | — (table-driven) |
| 0x0044ee00 | utility_isolated | HIGH | Simple collision tree node accessor (15 bytes). Returns param_1+0x4c if *param_1 != 0. Pure data structure utility. | — |
| 0x00478090 | game_logic_isolated | HIGH | Calls virtual method at DAT_007cd8c0 vtable+0x1c(0x14) (GameCommandDispatch factory). Stores result at param_1+0xe0. References game command dispatch system. | — |
| 0x0048d1a0 | vtable_member | MEDIUM | Virtual member function — calls virtual methods at this->vtable+0x2c and this->vtable+0xbc. Param_1[0xca] is array size, param_1[0xce] is index with wraparound. Likely a circular buffer/ring indexer. Called through vtable dispatch. | — (vtable dispatch) |
| 0x004a1b20 | utility_isolated | HIGH | String prefix copy utility. Selects between DAT_005cd12c (PrefixStringB) and DAT_005cd138 (StringPrefixA). String concatenation utility, no game logic context. | — |
| 0x0050c0a6 | utility_isolated | HIGH | Pure math: cubic Bezier interpolation (2D). Uses only float constants DAT_0059e478, DAT_0059e43c. No game globals, no struct offsets. | — |
| 0x0050d6ac | utility_isolated | HIGH | Pure math: builds 4x4 Z-axis rotation matrix from angle. No game globals, no cross-refs. | — |
| 0x0050f6f2 | vtable_member | HIGH | thunk_FUN_00516959 at 5 bytes — identical body to FUN_00516959. Compiler-generated thunk for vtable dispatch. Destructor pattern: conditional virtual call at subobject+0x28, then zero fields at +0x4 and +0x10. | — (vtable entry) |
| 0x005289e0 | utility_isolated | HIGH | Color space conversion with 4th-order SIMD polynomial. Uses DAT_005d8XXX codec coefficients (renderer globals, not game logic). Well-documented in docs/19. | — |
| 0x0053bce0 | game_logic_isolated | MEDIUM | Reads struct offsets +0x1c, +0x18, +0x20 from param_1 and +0x48, +0x44, +0x4c from param_2. Scales with DAT_0059fec8 and DAT_0059e440. References physics struct fields but no known callers. | — |
| 0x005607c1 | utility_isolated | HIGH | 16-bit color format conversion (RGB 5-6-5 to custom packed). Uses lookup tables for gamma/color-space transform. Already in docs/19 as triage line. | — |
| 0x00586c90 | utility_isolated | HIGH | Simple bounded counter (12 bytes). Increments, caps at 6. Pure utility. | — |
| 0x0058a935 | utility_isolated | HIGH | _malloc — MSVC CRT wrapper to __nh_malloc. Library function. | — |
| 0x00594ff0 | utility_isolated | HIGH | __aulldiv — MSVC CRT 64-bit unsigned division. Library function. | — |
| 0x00598672 | utility_isolated | HIGH | sendto — Winsock trampoline to ws2_32.dll. Pure import thunk. | — |
| 0x0059a418 | utility_isolated | HIGH | std::_Gninc — MSVC CRT stream buffer pointer increment. Library function. | — |
| 0x0059c91e | entry_point | HIGH | SEH unwind cleanup handler. Calls FUN_00581ad0. MSVC exception handling infrastructure. | — (SEH) |
| 0x0059d0c8 | entry_point | HIGH | SEH unwind handler. Calls FUN_0047aa60. MSVC exception handling infrastructure. | — (SEH) |
| 0x0059d5a8 | entry_point | HIGH | SEH unwind cleanup handler. Calls FUN_0059a9c2. MSVC exception handling infrastructure. | — (SEH) |

=== FULL ENTRIES ===
<!-- target: docs/21-audio-network-internals.md -->
## FUN_00585ea0 — Mutex Pair Initializer (Callback)

Source: Network/SyncPrimitives.cpp. Initializes a struct with two Windows mutexes.
Registered as callback via FUN_0058a6eb from FUN_005837f0.

**Key logic:**
- Initializes first half: zeros fields, sets v4 = 0xffffffff (infinite timeout)
- Calls CreateMutexA with inheritable security attributes
- On success: sets active byte
- Repeats same pattern for second mutex
- Returns initialized struct pointer
- **NEW: Called as registered callback** — address passed to FUN_0058a6eb as `&LAB_00585ea0` from FUN_005837f0 (network sync object constructor)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| [0] | queue_data | queue data pointer |
| [1] | queue_size | queue size |
| [2] | active1 | mutex1 active flag (byte) |
| [3] | mutex1 | mutex1 handle |
| [4] | timeout1 | mutex1 wait timeout |
| [5] | active2 | mutex2 active flag (byte) |
| [7] | mutex2 | mutex2 handle |
| [8] | timeout2 | mutex2 wait timeout |

**Globals:** none

**Calls:** CreateMutexA (Win32)

**Called by:** FUN_005837f0 (network sync object constructor), via FUN_0058a6eb callback runner

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044cb60 — Initialize Collision Globals D (Table-Driven)

Source: collision init. Writes collision global block. Called via function pointer table (no direct callers found).

**Key logic:**
- DAT_007cd108 = 0x68
- Zeros 2 dwords at 007cd10c, 007cd110
- DAT_007cd114 = 1.0f
- Part of collision system initialization table (~40 similar functions in 0x0044c000–0x0044f000 range)

**Globals:** DAT_007cd108–DAT_007cd114

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d100 — Collision Global Init (Set 0x6b, -1.0f) (Table-Driven)

Source: collision init. Initializes collision system global state block. Called via function pointer table.

**Key logic:**
- DAT_007ccf60 = 0x6b (107)
- Zeros _DAT_007ccf64, _DAT_007ccf6c
- Sets _DAT_007ccf68 = 0xbf800000 (-1.0f)
- Part of collision system initialization table

**Globals:**
- `DAT_007ccf60` — collision global, int = 0x6b
- `DAT_007ccf68` — collision global, float = -1.0f

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d6a0 — Collision Global Init (Group 0x15) (Table-Driven)

Source: collision init. Writes collision global block. Called via function pointer table.

**Key logic:**
- DAT_007cccc0 = 0x15 (21)
- Zeros _DAT_007cccc4, DAT_007cccc8, _DAT_007ccccc, _DAT_007cccd0, _DAT_007cccd4
- Part of collision system initialization table

**Globals:** DAT_007cccc0..._DAT_007cccd4

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044dc40 — CollisionGridInit49x49 (Table-Driven)

Source: collision init. Initializes collision grid parameters. Called via function pointer table.

**Key logic:**
- DAT_007cce58 = 0x31 (grid dimension = 49)
- Zeroes 5 ints at 007cce5c-007cce6c
- Part of collision system initialization table

**Globals:** DAT_007cce58, DAT_007cce5c–_DAT_007cce6c

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e1e0 — Collision Global Init (Group 0x48)

Source: collision init. Sets DAT_007ccf48=0x48, zeroes 4 fields, DAT_007ccf5c=18000. Not previously documented.

**Key logic:**
- DAT_007ccf48 = 0x48 (72)
- Zeros _DAT_007ccf4c, DAT_007ccf50, _DAT_007ccf54, _DAT_007ccf58
- DAT_007ccf5c = 18000
- Part of collision system initialization table (no direct callers found)

**Globals:** DAT_007ccf48, _DAT_007ccf4c, DAT_007ccf50, _DAT_007ccf54, _DAT_007ccf58, DAT_007ccf5c

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e780 — Collision Subsystem Init (DAT_007ccfec) (Table-Driven)

Source: collision init. Sets DAT_007ccfec=0x57, zeroes 4 fields, DAT_007cd000=9000. Called via function pointer table.

**Key logic:**
- DAT_007ccfec = 0x57 (87)
- Zeros _DAT_007ccff0, DAT_007ccff4, _DAT_007ccff8, _DAT_007ccffc
- DAT_007cd000 = 9000
- Part of collision system initialization table

**Globals:** DAT_007ccfec, DAT_007cd000

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## FUN_00478090 — Virtual Factory + Store (GameCommandDispatch)

Source: unknown. Calls virtual factory on GameCommandDispatch interface, stores result.

**Key logic:**
- Calls virtual method at (*DAT_007cd8c0)+0x1c with argument 0x14 (command ID)
- If non-null: stores result at param_1+0xe0
- Returns 0
- Factory pattern: allocates/provides resource by command ID

**Globals:**
- `DAT_007cd8c0` — GameCommandDispatchInterface (docs/12)

**Calls:** Virtual factory via DAT_007cd8c0+0x1c (command ID 0x14)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## FUN_0048d1a0 — Circular Buffer Indexer (Virtual Member)

Source: unknown. Index manipulation with wraparound. Called via vtable dispatch.

**Key logic:**
- Reads current index at param_1[0xce] and direction flag at param_1[0xcf] (bool)
- Adjusts index: if param_2==1 (forward), adds 2, else subtracts 1
- Clamps: if negative, wraps to param_1[0xca]-1
- Wraps modulo param_1[0xca] (buffer size)
- Calls virtual method at vtable+0x2c with arg 1
- Calls virtual method at vtable+0xbc with (param_2, new_index)
- Circular buffer/ring navigation pattern

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x328 (ca*4) | buffer_size | uint, array/circular buffer size (power of 2) |
| +0x338 (ce*4) | current_index | uint, current position in buffer |
| +0x33c (cf*4) | direction | bool, direction flag (1=forward) |

**Calls:** Virtual methods at vtable+0x2c, vtable+0xbc

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->
## FUN_0050d6ac — 2D Rotation Matrix (Z-axis, 4x4)

Source: math_util.cpp. Builds a 4x4 rotation matrix around Z-axis.

**Key logic:**
- Computes cos(angle) and sin(angle) via fcos/fsin
- Builds 4x4 matrix: [cos, sin, 0, 0; -sin, cos, 0, 0; 0, 0, 1, 0; 0, 0, 0, 1]
- 3D graphics/math utility — standard Z-axis rotation

**Globals:** none

**Calls:** fcos, fsin (x87 FPU)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->
## FUN_0053bce0 — Force/Scale Calculation

Source: physics/dynamics. Computes scaled force vector from two structs.

**Key logic:**
- Reads three values from param_1 offsets +0x18, +0x1c, +0x20 (dimensions/coefficients)
- Reads three values from param_2 offsets +0x44, +0x48, +0x4c (force/scale factors)
- Multiplies each pair with DAT_0059fec8 (global force scale factor)
- Outputs 4 values: X, Y, Z forces, and DAT_0059e440³ (cube of zero threshold)
- No direct callers found — likely called via function pointer or inline expansion

**Globals:**
- `DAT_0059fec8` — global force multiplier
- `DAT_0059e440` — zero threshold (cubed for output[3])

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
## FUN_0050f6f2 — VTable Dtor + Null Fields (thunk to FUN_00516959)

Source: unknown | Confidence: high
5-byte thunk to FUN_00516959. Compiler-generated vtable entry point. Partial destructor with conditional subobject cleanup.

**Key logic:**
- If param_1+0x4 (subobject pointer) is non-null: calls virtual method at vtable offset +0x28 on it (destructor/cleanup)
- Sets param_1+0x4 = 0, param_1+0x10 = 0
- Identical to FUN_00516959 — this thunk at 0x50f6f2 is a vtable dispatch entry

**Struct offsets (param_1):**
| Offset | Field name | Type | Notes |
|--------|------------|------|-------|
| +0x4 | subobject_ptr | void* | Subobject pointer, dtor called if non-null |
| +0x10 | unknown | undefined4 | Zeroed after cleanup |

**Calls:** Virtual method at subobject vtable+0x28

**Moddability:** hardcoded
