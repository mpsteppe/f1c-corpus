=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00407070 | vtable_member | HIGH | owned object with array (+0x48, stride 0x14) + linked list (+0x18) iterators calling vtable+0x10 and vtable+0x14 — is itself a class method invoked via the parent's vtable | parent class update loop |
| 0x0044c800 | game_logic_isolated | HIGH | writes collision globals DAT_007ca3c8..DAT_007ca3d4 (region type 6, sentinel -1.0f) — real collision init code, missing edges from init dispatcher | collision init table |
| 0x0044cda0 | game_logic_isolated | HIGH | writes collision globals DAT_007cd0f8..DAT_007cd104 (cell count 0x22, scale 1.0f) — real collision init, missing edges | collision init table |
| 0x0044d340 | game_logic_isolated | HIGH | writes collision globals DAT_007ca4d0..DAT_007ca4dc (type 0x3f, sentinel -1.0f) — real collision init, missing edges | collision init table |
| 0x0044d8e0 | game_logic_isolated | HIGH | writes collision globals DAT_007ccde0..DAT_007ccdf4 (type 0x1b, zeroed) — real collision init, missing edges | collision init table |
| 0x0044de80 | game_logic_isolated | HIGH | writes collision globals DAT_007cce28..DAT_007cce3c (type 0x37, zeroed) — real collision init, missing edges | collision init table |
| 0x0044e420 | game_logic_isolated | HIGH | writes collision globals DAT_007cd004..DAT_007cd018 (type 0x4e, zeroed) — real collision init, missing edges | collision init table |
| 0x0044e9c0 | game_logic_isolated | HIGH | writes collision globals DAT_007cca54..DAT_007cca68 (type 0x5d, threshold 27000) — real collision detection init, missing edges | collision init table |
| 0x00462410 | game_logic_isolated | MEDIUM | copies 0x23 entries × 0x8c bytes from this+0x394, plus int from this+0x3c74[param_2]; checks against this+0x3e14 — game data accessor, no game globals touched but accesses typed data table | game object data accessor |
| 0x004782c0 | game_logic_isolated | HIGH | queries DAT_007cd8c0 (GameCommandDispatchInterface) vtable+0x1c(0x10), syncs param_1[0x3a] with result+0x174, calls vtable+0x2c when dirty — real game logic | game object state sync |
| 0x00494600 | game_logic_isolated | HIGH | zeros collision globals DAT_007cddf0..DAT_007cddfc (collision list head/tail/count) — real collision cleanup, missing edges | collision shutdown/reset |
| 0x004c9310 | vtable_member | HIGH | releases 3 resources at this+0x20/0x24/0x28 via vtable+8 — is a destructor/cleanup method on a resource-holding object | parent class destructor |
| 0x0050c4bb | utility_isolated | HIGH | pure 3D bilinear interpolation with 4 float3 control points — no game globals, no cross-refs | inline math leaf |
| 0x0050dd40 | utility_isolated | HIGH | Euler angles (float xyz) to quaternion — reads only _DAT_0059e450 (0.5f deg-to-rad constant), no game state | inline math leaf |
| 0x005111d3 | utility_isolated | HIGH | JPEG marker reader — reads SOI marker (0xFF 0xD8), sets error codes at *param_1+0x14/0x18/0x1c — media decode utility | JPEG decoder pipeline |
| 0x0052e520 | entry_point | HIGH | halt/assert handler — calls assertion handler through PTR_FUN_005da714 with "Halting program" string, then swi(3) breakpoint | MSVC CRT assert handler |
| 0x005567e1 | utility_isolated | HIGH | float scale and round to int — ROUND(param_1 * _DAT_005dc164) — reads only FloatToIntScaleFactor constant | inline math leaf |
| 0x005667b0 | utility_isolated | HIGH | in-place string shift (subset memmove) — shifts characters within a string buffer, returns -1 on bounds error | string utility leaf |
| 0x00588640 | utility_isolated | HIGH | _strncmp — MSVC CRT library function, single match | CRT library |
| 0x0058da70 | utility_isolated | HIGH | __trandisp1 — MSVC CRT internal transcendental dispatch | CRT library |
| 0x0059863c | utility_isolated | HIGH | bind() wrapper — Winsock import thunk (6 bytes, indirect jump) | Winsock import |
| 0x00598696 | utility_isolated | HIGH | inet_ntoa (import thunk) — Winsock import thunk (6 bytes, indirect jump) | Winsock import |
| 0x0059c5e4 | entry_point | HIGH | SEH unwind handler — calls FUN_00587bcf (exception list destructor) with exception pointer from EBP+8 | SEH exception handler registration |
| 0x0059cd00 | entry_point | HIGH | SEH unwind cleanup — calls FUN_00583360() (list destructor with deallocation) | SEH exception handler registration |
| 0x0059d484 | entry_point | HIGH | SEH unwind — calls exception::~exception() to destroy exception object at EBP-0x10 | SEH exception handler registration |

=== FULL ENTRIES ===

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e9c0 — Collision Detection Init (Type 0x5d, Threshold 27000)

Source: collision detection init. Initializes collision detection state block with type ID 0x5d and threshold 27000.

**Key logic:**
- Sets DAT_007cca54 = 0x5d (93) — collision detection type/ID
- Zeros _DAT_007cca58, DAT_007cca5c, _DAT_007cca60, _DAT_007cca64 — clear data fields
- Sets DAT_007cca68 = 27000 — threshold/limit value (large value, likely distance or count)

**Globals:**
- `DAT_007cca54` — collision detection state block type ID (93)
- `DAT_007cca68` — collision threshold (27000)

**Moddability:** hardcoded — static init pattern.

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup. Part of the same init function family as FUN_0044c800, FUN_0044cda0, FUN_0044d340, FUN_0044d8e0, FUN_0044de80, FUN_0044e420.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044c800 — Collision Region Init 5 (Type 6, -1.0f)

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup. Part of the same init function family as FUN_0044cda0, FUN_0044d340, FUN_0044d8e0, FUN_0044de80, FUN_0044e420, FUN_0044e9c0.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044cda0 — Collision State Init (Slot 0x22, Scale 1.0)

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d340 — CollisionGlobalInitG

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d8e0 — Initialize Collision Globals A

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044de80 — Collision Global Init (Set 0x37)

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e420 — CollisionStateInit_4e

**Orphan classification:** `game_logic_isolated` — real collision init code, missing edges from init dispatcher. No cross-references found in .c files. Likely called from a function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->
## FUN_00494600 — Collision Global Zeroing

**Orphan classification:** `game_logic_isolated` — real collision cleanup/reset code, missing edges. Zeroes collision list tracking globals (DAT_007cddf0-DAT_007cddfc). Likely called during collision system shutdown or reset.

<!-- target: docs/01-engine-architecture.md -->
## FUN_00407070 — Array + Linked-List Virtual Dispatch Iterator

**Orphan classification:** `vtable_member` — called via parent class vtable. This function is a method on a class that manages both an array (at +0x48, stride 0x14, count +0x4c) and a linked list (head at +0x18). Dispatches to child objects via vtable+0x10 (array phase) and vtable+0x14 (list phase). Missing edges because callers go through the vtable, not direct calls.

<!-- target: docs/19-renderer.md -->
## FUN_004c9310 — Resource Release Triple Dispatch

**Orphan classification:** `vtable_member` — called via parent class vtable+8 or higher. This function releases 3 resource pointers at this+0x20/0x24/0x28 by dispatching vtable+8 on each. It is a destructor or cleanup method on a resource-holding object. Missing edges because callers go through the vtable.

<!-- target: docs/01-engine-architecture.md -->
## FUN_0059c5e4 — SEH Unwind Handler

**Orphan classification:** `entry_point` — MSVC SEH exception handler. Called by the runtime when an exception unwinds past this frame. Missing from call graph because SEH registration is implicit (__try/__except or /EHsc handler).

**Calls:** FUN_00587bcf (exception list destructor)

<!-- target: docs/01-engine-architecture.md -->
## FUN_0059cd00 — SEH Unwind Cleanup

**Orphan classification:** `entry_point` — MSVC SEH exception handler cleanup. Called by the runtime during exception unwinding. Missing from call graph because SEH registration is implicit.

**Calls:** FUN_00583360 (list destructor with deallocation)

<!-- target: docs/01-engine-architecture.md -->
## FUN_0059d484 — SEH Unwind: Destroy Exception Object

**Orphan classification:** `entry_point` — MSVC SEH exception handler. Destroys a C++ exception object during unwind. Missing from call graph because SEH registration is implicit.

**Calls:** exception::~exception (exception destructor)
