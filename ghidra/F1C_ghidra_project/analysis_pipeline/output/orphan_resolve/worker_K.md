=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x0040a890 | utility_isolated | HIGH | Multi-field membership check on struct fields at +0x10/+0x14/+0x18/+0x1c/+0x24/+0x28/+0x2c/+0x30 with stride-200 array loop at +0x20. No game globals, no cross-refs. Pure utility — checks if param_2 matches any field in param_1 struct. | — |
| 0x0044c920 | game_logic_isolated | MEDIUM | Collision state init: sets DAT_007cca6c=9, zeros 2 fields, sets DAT_007cca78=1.0f. One of ~30 identical-pattern void(void) collision table init functions. Likely called via function pointer array from master collision init (FUN_0044bb60 or similar), but no call edge found in available .c files. | FUN_0044bb60 (inferred) |
| 0x0044cec0 | game_logic_isolated | MEDIUM | Collision grid init: DAT_007ccbf4=0x25(37), zero, -1.0f sentinel, zero. Same pattern as sibling collision inits. Likely vtable member or array of init functions. | FUN_0044bb60 (inferred) |
| 0x0044d460 | game_logic_isolated | MEDIUM | Collision state init: DAT_007cccf0=15, zeros 5 fields. Same pattern as sibling collision inits. See 0x0044c920. | FUN_0044bb60 (inferred) |
| 0x0044da00 | game_logic_isolated | MEDIUM | Collision state init: DAT_007ccf18=0x2b(43), zeros 5 fields. Already documented as "Collision State Init 1". | FUN_0044bb60 (inferred) |
| 0x0044dfa0 | game_logic_isolated | MEDIUM | Collision init: DAT_007ccdb0=0x42(66), zeros 5 fields. Only in triage index, not yet in docs/17. Same void(void) collision table init pattern as sibling functions. | FUN_0044bb60 (inferred) |
| 0x0044e540 | game_logic_isolated | MEDIUM | Collision table init: DAT_007cd0e0=0x51(81), zeros 4 fields, DAT_007cd0f4=27000. Already documented as "CollisionTableInit_51". | FUN_0044bb60 (inferred) |
| 0x0044eae0 | game_logic_isolated | MEDIUM | Collision init: DAT_007ca54c=0x60(96), zeros 4 fields, DAT_007ca560=18000. Already documented as "Global State Initializer (Collision Set 4)". | FUN_0044bb60 (inferred) |
| 0x00466030 | game_logic_isolated | MEDIUM | Collision flag init: DAT_007cd468=0, DAT_007cd46c=0xffffffff(-1). 2-field variant of collision init pattern. Already documented as "CollisionFlagInit". | FUN_0044bb60 (inferred) |
| 0x0047f180 | utility_isolated | HIGH | Doubly-linked list append: operator_new(0x10), inserts node with next/prev pointers, increments counter at param_1[3]. No game globals, no cross-refs. Generic data structure utility. | — |
| 0x00498940 | utility_isolated | HIGH | Inline-able float accessor (__fastcall): returns *(float *)(param_1 + 0xc4). 7 bytes. Pure field read, no logic or globals. | — |
| 0x004d5c40 | utility_isolated | HIGH | Zeros DAT_008ad254 and DAT_008ad258 (adjacent state/flag pair). Globals reference identifies as StateFlagPair with no other usage. Likely module state reset for an unloaded system. No cross-refs. | — |
| 0x0050c9a9 | utility_isolated | HIGH | 4-component bilinear interpolation: out = lerp(lerp(p2,p3,px), lerp(p4,p1,px), py) per component. Pure math leaf (119 bytes, no calls, no globals). | — |
| 0x0050e0d3 | callback | LOW | Indirect jump through DAT_005d78a8 (IndirectJumpTarget in globals ref). Ghidra cannot resolve jump target. The function pointer at DAT_005d78a8 is set elsewhere — this is a dispatch stub called via function pointer assignment. | setter of DAT_005d78a8 (unknown) |
| 0x0051941d | utility_isolated | HIGH | Texture row copy with transpose/rearrangement. Accessed fields at unaff_EDI+0x20(counter), +0x114(stride), +0x180(dest), +0xc4(src). No game globals. Already documented as "Texture Row Copy" in docs/19. | — |
| 0x00534ae6 | entry_point | HIGH | AVIFileRelease import trampoline. Indirect jump to Video for Windows API. No game logic. Already documented in docs/01. | — |
| 0x0055eeaf | utility_isolated | HIGH | 4x3 matrix × 3D vector transform (__fastcall). Computes vec_out = M[4x3] * vec_in using coefficients at param_5[0..14]. Pure math leaf (117 bytes, no calls, no globals). | — |
| 0x0056f818 | utility_isolated | MEDIUM | Data validation/CRC function with 0x52-entry lookup table (local_bc) and run-length decode. Uses DAT_0059e430 (ZeroSentinel, ~0.0) as sentinel comparison. Compares param_2 against 0x28 (40). No game globals beyond ZeroSentinel physics constant. | — |
| 0x00588931 | entry_point | HIGH | __NLG_Notify1 — MSVC CRT NLG (New Language Generation) notification function. Stores EAX/EBP/param_1 to DAT_005e63d4/d8/dc. Part of MSVC structured exception handling. Already documented in docs/06. | — |
| 0x0058dd4b | entry_point | HIGH | __math_exit — MSVC CRT math error handler. Checks FPU status word for error flags, calls __startOneArgErrorHandling if set. No game logic. | — |
| 0x0059864e | entry_point | HIGH | recvfrom Winsock import thunk. Delegates to ws2_32.recvfrom. No game logic. Already documented in docs/21. | — |
| 0x00598cdc | entry_point | HIGH | std::basic_streambuf::uflow — MSVC 2003 CRT virtual method. Reads from stream buffer via vtable+0x10 call, returns character. CRT vtable member. | — |
| 0x0059c6de | entry_point | HIGH | SEH unwind handler. Calls FUN_00587bcf(*(ebp+8)) — passes exception context. Compiler-generated for C++ try/catch. | — |
| 0x0059ced7 | entry_point | HIGH | SEH unwind cleanup. Calls FUN_005833e0() — walk list + destructor + free. Compiler-generated C++ cleanup. Already documented in docs/01. | — |
| 0x0059d4c0 | entry_point | HIGH | SEH unwind thunk. Calls FUN_00598c70(). Compiler-generated SEH cleanup. | — |

=== FULL ENTRIES ===

No new entries needed. All 25 orphans already have adequate documentation or are trivially classifiable with no new call relationships discovered.

=== NOTES ===

**Collision init function pattern (orphans 255–262):** Eight void(void) functions (FUN_0044c920, 0044cec0, 0044d460, 0044da00, 0044dfa0, 0044e540, 0044eae0, 00466030) all follow the same pattern: write a count/type ID at the base address, zero 2–5 following fields, optionally write a float/int threshold at the last field. These are 30+ collision subsystem initialization functions that each initialize one row of a global parameter table. They are almost certainly dispatched from a single master collision init (likely FUN_0044bb60 or FUN_0044c620) through a function pointer array or switch table, but no call edges exist in the available .c files to confirm which function acts as the dispatcher.

**Orphan 259 (0x0044dfa0)** is the only collision init not yet present as a `## FUN_` entry in docs/17-physics-collision.md. No new call relationship found to justify adding a full entry per rules. It follows the identical pattern: count=0x42(66), 5 zero fields.
