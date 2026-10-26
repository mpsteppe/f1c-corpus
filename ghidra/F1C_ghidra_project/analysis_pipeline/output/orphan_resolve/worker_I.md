=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x004070e0 | game_logic_isolated | MEDIUM | spatial query iterates array at +0x48 (stride 0x14), weighted distance comparison, virtual dispatch at *entry+0x1c (type check) and *winner+8 (activate). No game globals directly but matches collision broadphase query pattern. | — |
| 0x0044c860 | callback | MEDIUM | collision material init: writes DAT_007ccbb0..DAT_007ccbbc (type=7, 1.0f). Identical pattern to ~30 other init functions — part of function pointer table called from collision setup loop. | collision_init_loop (unknown address) |
| 0x0044ce00 | callback | MEDIUM | spatial node init: writes DAT_007ca438..DAT_007ca444 (index=35, radius=-1.0). Part of spatial node init function pointer table. | spatial_init_loop (unknown address) |
| 0x0044d3a0 | callback | MEDIUM | broadphase reset: writes DAT_007ccd50..DAT_007ccd64 (slot=0xD). Part of collision broadphase bucket reset table. | broadphase_init_loop (unknown address) |
| 0x0044d940 | callback | MEDIUM | global collision init: writes DAT_007ccdc8..DAT_007ccddc (index=0x1C). Part of collision global init table. | collision_global_init_loop (unknown address) |
| 0x0044dee0 | callback | MEDIUM | collision init (slot 0x38): writes DAT_007ccbdc..DAT_007ccbf0. Same pattern as other collision init table entries — sets slot ID, zeros 5 adjacent fields. | collision_init_table_loop (unknown address) |
| 0x0044e480 | callback | MEDIUM | collision region init: writes DAT_007cd034..DAT_007cd048 (type=79, limit=9000). Part of collision region init table. | region_init_table_loop (unknown address) |
| 0x0044ea20 | callback | MEDIUM | broadphase reset: writes DAT_007ca4b8..DAT_007ca4cc (slot=0x5E). Part of broadphase bucket reset table. | broadphase_init_loop (unknown address) |
| 0x00463c80 | game_logic_isolated | MEDIUM | vehicle description accessor: reads string at *param_1+0xb4, fallback to DAT_005ea438 (LoadPath). Vehicle setup code, missing call edges. | — |
| 0x00478690 | vtable_member | MEDIUM | virtual method: checks param_1[0x4e] field, dispatches vtable+0x3c(0/1), returns param_1+0x46 or null. Called via `this->vtbl[0x3c/4](flag)` pattern. | any owner-of-this-class |
| 0x004967d0 | game_logic_isolated | MEDIUM | doubly-linked list append to render object at +0x18cc. Called at runtime when render layer receives new node. | — |
| 0x004c9820 | vtable_member | MEDIUM | virtual method: array lookup at param_1+0x20 indexed by +0x1c, calls vtable+0x1c on found entry. Checks if indexed sub-object returns 2. State query on container. | any owner-of-this-class |
| 0x0050c78c | utility_isolated | HIGH | Catmull-Rom spline interpolation: 4 control points (float* p1-p4, float* out, float t). Standard basis with coefficients DAT_0059e478/DAT_0059e43c. Pure math — no game globals, no cross-refs. | — |
| 0x0050df95 | callback | MEDIUM | thunk via indirect jump through DAT_005d7878. Target set dynamically at runtime — dispatch mechanism. | whoever sets DAT_005d7878 |
| 0x00513daf | utility_isolated | HIGH | batch clamp: iterates 16 groups of 4 floats, clamps first 3 elements to [0, element[3]]. Pure math utility — no game globals. | — |
| 0x00534aac | entry_point | HIGH | Miles Sound System import thunk: _AIL_shutdown@0. Not game code — DLL import stub. | AIL_shutdown caller via import |
| 0x0055685a | utility_isolated | HIGH | constant return 1: trivial `return 1;`. Likely default stub or placeholder callback. | — |
| 0x00567af0 | utility_isolated | HIGH | thunk to FUN_00567b10 — string cleanup utility. Removes specific characters from paths using FUN_005678f0 filter. Not game logic, string utility. | — |
| 0x00588864 | entry_point | HIGH | MSVC CRT __global_unwind2: calls RtlUnwind. Library function (VS 1998/2003). Called by SEH infrastructure. | MSVC CRT exception handler |
| 0x0058dad7 | entry_point | HIGH | MSVC CRT __trandisp2: transition dispatch for exception handling. Library function (VS 1998-2008). | MSVC CRT exception handler |
| 0x00598642 | entry_point | HIGH | htonl Winsock import thunk. NOT game code — DLL import stub. | any networking code |
| 0x0059869c | entry_point | HIGH | WSAStartup Winsock import thunk. NOT game code — DLL import stub. | any networking code |
| 0x0059c5ee | entry_point | HIGH | SEH unwind handler: calls FUN_00587bcf with EBP-relative variable. Called by exception infrastructure for object cleanup. | MSVC CRT exception handler |
| 0x0059cdc0 | entry_point | HIGH | SEH unwind thunk: calls FUN_00581880. Called by exception infrastructure. | MSVC CRT exception handler |
| 0x0059d498 | entry_point | HIGH | SEH unwind destructor: calls exception::~exception() on caught exception object. Called by catch block cleanup. | MSVC CRT exception handler |

=== FULL ENTRIES ===

<!-- target: docs/17-physics-collision.md -->
## FUN_0044dee0 — Collision Init (Slot 0x38)

Source: collision_init_table.cpp. Initializes one slot of collision global state data block at 0x007ccbdc.

**Key logic:**
- Sets `DAT_007ccbdc = 0x38` (56) — collision slot index/type identifier
- Zeros 5 adjacent dwords (`_DAT_007ccbe0` through `_DAT_007ccbf0`) — collision state fields

**Globals:**
- `DAT_007ccbdc` — collision slot index (56 / 0x38)

**Called by:** collision_init_table_loop (unknown address) — one of many similar init functions called from a table-driven initialization loop during collision system startup.

**Call pattern:** Identical to FUN_0044d3a0, FUN_0044ea20, and ~50 other collision init functions — each writes a unique slot ID and zeros adjacent state. The slot addresses are non-consecutive, suggesting entries in different collision subsystems (broadphase, material, region, spatial).

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->
## FUN_004c9820 — Virtual State Check via Index

Source: collision_manager.cpp. Queries state of an indexed sub-object by virtual dispatch.

**Key logic:**
- Computes pointer from array at `param_1 + 0x20` indexed by `*(param_1 + 0x1c)`
- If non-null, calls virtual method at `vtable+0x1c` on the sub-object
- Returns 1 if virtual call result != 2, else 0

**Struct offsets (param_1):**
| Offset | Type | Purpose |
|--------|------|---------|
| +0x1c | int | Index into sub-object array |
| +0x20 | void** | Array of sub-object pointers |

**Virtual dispatch:**
- Calls `subobj->vtbl[0x1c/4](subobj)` — vtable offset 0x1c (method slot 7)
- Return value 2 appears to be a "busy/deactivated" sentinel

**Used by:** collision or spatial manager — checks whether a specific indexed collider/spatial node is available (not in state 2).

**Moddability:** `hardcoded` — interface contract
