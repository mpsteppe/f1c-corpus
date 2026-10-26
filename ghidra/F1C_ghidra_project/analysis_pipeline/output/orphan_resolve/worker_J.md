=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00407d40 | utility_isolated | HIGH | Vector angle/rotation math using fsin/fcos. Reads DAT_0059e440 (ZeroThreshold, used as 0.0f constant). No game-logic globals. Pure math leaf function. Likely called inlined or via function pointer; no cross-refs because callers are in compiled C++ templates. | — |
| 0x0044c8c0 | callback | HIGH | Collision friction init function. Sets DAT_007ccfb0=8, DAT_007ccfb4=0, DAT_007ccfb8=-1.0f, DAT_007ccfbc=0. Pattern matches collision init table entry — one of dozens of similar small void(void) callbacks called during engine startup via static function pointer array. No direct callers in .c files because the table is a static C array without string-anchored xrefs. | init_table_master |
| 0x0044ce60 | callback | MEDIUM | Collision material init function. Sets DAT_007ca448(36), DAT_007ca44c(0), DAT_007ca450(0), DAT_007ca454(1.0f). Pattern identical to other collision init table entries. Called via init function pointer array during collision system startup. | init_table_master |
| 0x0044d400 | callback | MEDIUM | Spatial node init (index 14). Sets DAT_007ccd38=0xe, zeros 5 dwords. One of ~30+ spatial node init functions following same pattern. Called via init function pointer table. | init_table_master |
| 0x0044d9a0 | callback | MEDIUM | Collision counter init. Sets DAT_007ccf30=0x2a, zeros 5 dwords. Collision Counter Block init (DAT_007ccf30–007ccf44). Called via init function pointer table. | init_table_master |
| 0x0044df40 | callback | MEDIUM | Collision static init (type 0x39/57). Sets DAT_007ccbc4=0x39, zeros 5 dwords. Called via init function pointer table. | init_table_master |
| 0x0044e4e0 | callback | MEDIUM | Collision material coefficients set 3 (ID 0x50/80). Sets DAT_007cd0c8=0x50, zeros 3 dwords, sets DAT_007cd0dc=18000. Called via init function pointer table. | init_table_master |
| 0x0044ea80 | callback | MEDIUM | Spatial node init (index 95, distance 9000). Sets DAT_007ca4e0=0x5f, zeros 3 dwords, sets DAT_007ca4f4=9000. Called via init function pointer table. | init_table_master |
| 0x00465fd0 | callback | MEDIUM | Collision distance reset. Sets DAT_007cd460=0, DAT_007cd464=-1 (0xffffffff). Called via init function pointer table. | init_table_master |
| 0x0047b1b0 | vtable_member | MEDIUM | Triple virtual call dispatch. Sets param_1[0x41]=0, then calls vtable slots +0x40(arg=0), +0x2c(arg=1), +0x9c() on same object. This function IS a vtable method itself — no direct callers because all invocations go through the vtable. No cross-refs because Ghidra does not statically resolve virtual dispatch. | vtable_(unknown_base_class) |
| 0x004979b0 | game_logic_isolated | MEDIUM | Polling loop wrapper. Reads param_1+0x18 (status flag). Loops calling FUN_00498f70 (poll function) and FUN_00495ae0 (idle yield) until poll returns != 1. Name thunk_FUN_00495b30 suggests wrapper around FUN_00495b30 with polling. Called via function pointer — the polling behavior prevents static resolution. Calls FUN_00498f70 and FUN_00495ae0. | callback_dispatch_unknown |
| 0x004c9960 | vtable_member | MEDIUM | Cleanup/destructor pattern. Checks param_1+0x1c for non-null, calls through double-pointer (**ptr)(1) then clears ptr. The `(1)` argument = C++ "delete this" flag. IS a vtable method itself; no direct callers due to virtual dispatch. | vtable_(unknown_class) |
| 0x0050c887 | utility_isolated | HIGH | Catmull-Rom spline interpolation. 4 control points + 1D parameter → 4-component result. Uses DAT_0059e450, DAT_0059e800, DAT_0059e478, DAT_0059e46c, DAT_0059e7ec — all math basis constants, not game globals. Pure math leaf. | — |
| 0x0050e04f | callback | HIGH | 6-byte indirect jump thunk. Calls through global function pointer DAT_005d78a4. Acts as a patching/hook point — the global pointer is set at runtime, making static resolution impossible. DAT_005d78a4 not in docs/12 (unnamed). Dispatch mechanism for plugin/callback system. | FUN_0050dff5 (fellow thunk) or DAT_005d78a4 writer |
| 0x00515986 | utility_isolated | HIGH | Bitfield-controlled memory copy. Copies (param_3 & 0x1ffffff)<<5 DWORDs from param_1 to param_2. Second loop is dead code (iVar1=0). No game globals. Utility memset/memcpy variant. | — |
| 0x00534ae0 | entry_point | HIGH | Import thunk: jmp [AVIFileExit@vfw32.dll]. Called by the PE loader/import resolver, not by game code directly. No .c file cross-refs because imports are resolved by the loader, not by static code. | IAT (import address table) |
| 0x0055ee20 | utility_isolated | MEDIUM | Batch 4×4 matrix transform. Reads count/array pointers from param_3+8/0xc/0x3c. Performs per-element coordinate transforms (matrix×vec → 6-component output). Writes to DAT_005dc470 as compiler register spill, not game logic. Batch math utility for 3D scene transforms. | — |
| 0x00567b00 | utility_isolated | MEDIUM | String trimming utility (thunk to FUN_00567b10). Scans string via FUN_005678f0 (character decoder), copies to output, strips trailing whitespace. Uses FUN_00587c20 for null termination. Pure utility — string processing. | — |
| 0x0058890e | entry_point | HIGH | MSVC CRT __abnormal_termination. Checks if current exception handler matches SEH cleanup pattern. Called by C++ exception handling machinery, not by game code directly. | MSVC SEH dispatch |
| 0x0058dce5 | entry_point | HIGH | MSVC CRT __fload_withFB. Checks double for NaN exponent (0x7ff00000). Called by MSVC float-to-int conversion and formatting routines. | MSVC CRT |
| 0x00598648 | entry_point | HIGH | Import thunk: jmp [socket@ws2_32.dll]. Called via IAT. No .c file cross-refs. | IAT (import address table) |
| 0x005986a2 | entry_point | HIGH | Import thunk: jmp [WSACleanup@ws2_32.dll]. Called via IAT. Referenced indirectly in FUN_00564680 (WSACleanup wrapper). | IAT (import address table) |
| 0x0059c666 | entry_point | HIGH | MSVC SEH unwind handler. Calls FUN_00587bcf with exception object pointer (unaff_EBP+8). Registered by C++ try/catch in _except_handler3 table. No static callers — invoked by SEH dispatcher. | SEH exception handler table |
| 0x0059ce00 | entry_point | HIGH | MSVC SEH unwind handler. Calls FUN_005819c0. Registered in _except_handler3 scope table. Invoked by SEH unwinder during exception propagation. | SEH exception handler table |
| 0x0059d4ac | entry_point | HIGH | MSVC SEH unwind handler. Destructs exception object via exception::~exception(). Registered in _except_handler3 scope table for C++ catch blocks needing object cleanup. | SEH exception handler table |

=== FULL ENTRIES ===
<!-- target: docs/17-physics-collision.md -->
## FUN_0044c8c0 — CollisionFrictionInit_8

Source: collision_static_init.cpp. Part of collision system init table — one of ~30+ small void(void) functions registered in a static function pointer array and called during engine startup.

**Key logic:**
- Sets `DAT_007ccfb0 = 8` (friction type/contact struct type 8)
- Sets `_DAT_007ccfb4 = 0`
- Sets `_DAT_007ccfb8 = 0xbf800000` (-1.0f sentinel)
- Sets `_DAT_007ccfbc = 0`

**Called by:** Master collision init function via static function pointer array. Exact call location: the array iterates over a table of ~30+ function pointers, calling each in sequence. Not visible in .c file cross-refs because the table is a static C array of function pointers without string anchors.

**Globals:**
- `DAT_007ccfb0` — friction/contact type (8)
- `DAT_007ccfb4` — zeroed
- `DAT_007ccfb8` — -1.0f sentinel
- `DAT_007ccfbc` — zeroed

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044ce60 — Global State Initializer (Collision Material 2)

Source: physics_globals.cpp. Init table callback for collision material/coefficient block (type 0x24 = 36).

**Key logic:**
- Sets DAT_007ca448 = 0x24 (36, block type ID)
- Zeroes DAT_007ca44c, DAT_007ca450
- Sets DAT_007ca454 = 0x3f800000 (1.0f, coefficient default)

**Called by:** Master collision init via static function pointer table iteration.

**Globals:**
- `DAT_007ca448` — material block type ID (36)
- `DAT_007ca44c` — zero init
- `DAT_007ca450` — zero init
- `DAT_007ca454` — 1.0f coefficient

**Moddability:** configurable — surface material properties from .trk or .gdb

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d400 — Spatial Node Init (index 14)

Source: spatial_init.cpp. Init table callback for spatial partitioning node with element count 0xe (14).

**Key logic:**
- Sets `DAT_007ccd38 = 0xe` (14 elements)
- Zeros 5 following dwords: `_DAT_007ccd3c` through `_DAT_007ccd4c`

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007ccd38` — node element count
- `DAT_007ccd3c`–`DAT_007ccd4c` — zeroed

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d9a0 — Collision Globals Init #1 (DAT_007ccf30)

Source: collision_init.cpp. Init table callback. Initializes collision counter block (DAT_007ccf30 through DAT_007ccf44).

**Key logic:**
- Sets DAT_007ccf30 = 0x2a (42, collision counter initial)
- Zeros 5 following dwords

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007ccf30` — CollisionParam42
- `DAT_007ccf34`–`DAT_007ccf44` — zeroed (CollisionCounterBlock)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044df40 — CollisionStaticInit_39 (init 0x007ccbc4)

Source: collision_static_init.cpp. Init table callback for collision state block (type 0x39 = 57).

**Key logic:**
- Sets DAT_007ccbc4 = 0x39 (57, block type ID)
- Zeros 5 following dwords

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007ccbc4` — block type ID
- Subsequent 5 dwords — zeroed

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e4e0 — Collision Material Coefficients Set 3 (ID 0x50)

Source: collision_material.cpp. Init table callback for material coefficient block (type 0x50 = 80).

**Key logic:**
- Sets DAT_007cd0c8 = 0x50 (80, block type / material count)
- Zeros 3 following dwords
- Sets DAT_007cd0dc = 18000 (max range / threshold)

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007cd0c8` — CollisionMaterialCount (80)
- `DAT_007cd0dc` — max range (18000)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_0044ea80 — Spatial Node Init (index 95, distance 9000)

Source: spatial_init.cpp. Init table callback for spatial partitioning node (index 95, max distance 9000).

**Key logic:**
- Sets DAT_007ca4e0 = 0x5f (95, node index / element count)
- Zeros 3 following dwords
- Sets DAT_007ca4f4 = 9000 (max search distance)

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007ca4e0` — node element count
- `DAT_007ca4f4` — max search distance (9000)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->
## FUN_00465fd0 — Collision Distance Reset

Source: collision_distance.cpp. Init table callback for collision distance/state fields.

**Key logic:**
- Sets DAT_007cd460 = 0 (distance/contact counter reset)
- Sets DAT_007cd464 = 0xffffffff (-1, invalid state sentinel)

**Called by:** Master collision init via static function pointer table.

**Globals:**
- `DAT_007cd460` — distance/contact counter
- `DAT_007cd464` — state sentinel (-1)

**Moddability:** hardcoded
