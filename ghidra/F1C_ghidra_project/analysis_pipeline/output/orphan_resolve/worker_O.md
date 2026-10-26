=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x0040be20 | vtable_member | MEDIUM | Object cleanup pattern: calls 3 function pointers at offsets +0x18/+0x1c/+0x20 then zeros them — destructor/cleanup method in a COM-style object hierarchy | Virtual destructor chain |
| 0x0044caa0 | vtable_member | HIGH | Init table entry: writes ID byte 0x66 (102) + 3 coefficient fields to collision global DAT_007cd148 — matches pattern of 50+ collision init functions in docs/17 called from a function-pointer init table | CollisionInitTable (array of function pointers called during collision system setup) |
| 0x0044d040 | vtable_member | HIGH | Init table entry: writes ID byte 0x29 (41) + coefficient fields to DAT_007ca3d8 including -1.0f restitution — matches collision friction init function pattern | CollisionInitTable |
| 0x0044d5e0 | vtable_member | HIGH | Init table entry: writes ID byte 0x13 (19) + zeros 5 coefficient dwords at DAT_007ccc80 — material coefficients init (already documented in docs/17 as table entry) | CollisionMaterialInitTable |
| 0x0044db80 | vtable_member | HIGH | Init table entry: writes ID byte 0x2f (47) + zeros 5 dwords at DAT_007ccee8 — spatial node init (already in docs/17) | SpatialNodeInitTable |
| 0x0044e120 | vtable_member | HIGH | Init table entry: writes ID byte 0x46 (70) + zeros 5 dwords at DAT_007cd1a8 — collision globals init (already in docs/17) | CollisionGlobalsInitTable |
| 0x0044e6c0 | vtable_member | HIGH | Init table entry: writes ID byte 0x55 (85) + 4 zero dwords + DAT_007cd078=27000 at DAT_007cd064 — collision static init with distance threshold (already in docs/17) | CollisionStaticInitTable |
| 0x0044ec60 | vtable_member | HIGH | Init table entry: writes ID byte 100 + 4 zero dwords + DAT_007ca4b4=18000 at DAT_007ca4a0 — material coefficients set 4 (already in docs/17) | CollisionMaterialInitTable |
| 0x00474c80 | vtable_member | HIGH | thiscall at struct offset +0x31c: switch mapping values 0x1a2-0x1ac (418-428) to bitmask (1,2,4,8,0x10...0x400) — virtual method mapping an index/enum to bitmask | Virtual method on class with +0x31c field (likely input/render device class) |
| 0x004888f0 | game_logic_isolated | HIGH | thiscall byte setter at param_1+0xec — trivial virtual setter; no globals but clearly part of a game logic class (already in docs/06) | Virtual method on session/state class with +0xec field |
| 0x0049b050 | vtable_member | MEDIUM | Empty stub (1-byte RET) — unused virtual method placeholder or interface gap filler | Virtual method slot in some object hierarchy |
| 0x0050696c | vtable_member | HIGH | Thunk: reads vtable from *param_1, calls (*(*param_1)+0x28)(param_1) — standard COM-style thunk destructor for D3D object | D3D object destructor chain (already in docs/19 as thunk) |
| 0x0050d57f | utility_isolated | HIGH | Pure math: builds 4x4 Y-axis rotation matrix using cos/sin — no globals, no struct fields (already in docs/20 as leaf function) | — |
| 0x0050edd2 | utility_isolated | MEDIUM | Wrapper composing thunk_FUN_0050dd0c + thunk_FUN_0050d84a — utility composition helper | — |
| 0x0051bdf1 | game_logic_isolated | MEDIUM | Complex buffered data reader with virtual dispatch through class members at +0x4 and +0x1a4 — real game I/O code, edges missing because virtual calls are unresolved in Ghidra | Called at some point during data loading (streaming I/O path) |
| 0x0053b110 | utility_isolated | HIGH | Power function (x^y) via x87 f2xm1+log2 instructions: computes 1+f2xm1(y*log2(x)) = x^y — pure math leaf | — |
| 0x00560547 | game_logic_isolated | MEDIUM | RLE transparency-masked sprite blit: copies pixel data with per-row skip counts, handles stride, uses DAT_005ddxxx renderer globals — real renderer code (already in docs/19) | Sprite/texture rendering pipeline |
| 0x0057e410 | entry_point | HIGH | Windows message pump: PeekMessageA loop with GetMessageA/TranslateMessage/DispatchMessageA — called from WinMain/main loop (already in docs/01) | Main game loop (FUN_0042d8a0 or similar top-level function) |
| 0x0058a7ec | entry_point | HIGH | MSVC CRT __setjmp3 — saves register state into jmp_buf; called implicitly by compiler-generated setjmp() calls | Compiler-generated (setjmp call sites) |
| 0x00591cf3 | entry_point | HIGH | MSVC CRT __frnd — rounding via ROUND instruction; called implicitly by compiler | Compiler-generated (rounding operations) |
| 0x00598666 | entry_point | HIGH | MSVC CRT inet_addr wrapper — called via compiler-generated import thunk from networking code | Compiler-generated import |
| 0x00599d31 | vtable_member | HIGH | MSVC C++ std::basic_streambuf::uflow — virtual method called by stream I/O operations | C++ stream hierarchy (iostream/sstream/fstream) |
| 0x0059c878 | entry_point | HIGH | SEH unwind handler: calls FUN_00582650 — called implicitly by MSVC exception handling unwinder | MSVC exception handling runtime |
| 0x0059d036 | entry_point | HIGH | SEH unwind cleanup: calls FUN_00586460 — called implicitly by MSVC exception handling unwinder | MSVC exception handling runtime |
| 0x0059d580 | entry_point | HIGH | SEH unwind: destroys exception object via exception::~exception — called implicitly by MSVC exception handling unwinder | MSVC exception handling runtime |

=== FULL ENTRIES ===

No new call relationships discovered — all existing doc entries are accurate and complete. No full entries need updating.
