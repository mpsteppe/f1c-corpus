=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x004066c0 | utility_isolated | HIGH | Pure Win32 sync utility: WaitForSingleObject/ReleaseMutex wrapper. No game globals. No cross-refs found. Called directly as __fastcall utility. | — |
| 0x0044c740 | static_init | HIGH | CRT static initializer. Sets DAT_007ca470=4 (CollisionGridSize). Globals referenced by FUN_00452810, FUN_0044ff50. Called implicitly via .CRT$XIU table before main(). | CRT startup |
| 0x0044cce0 | static_init | HIGH | CRT static initializer. Sets DAT_007cd158=0x20 (MaterialStride). Globals referenced by FUN_00452810, FUN_0044ff50. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044d280 | static_init | HIGH | CRT static initializer. Sets DAT_007ca57c=0x3d. Globals referenced by FUN_00452810. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044d820 | static_init | HIGH | CRT static initializer. Sets DAT_007ccc50=0x19. Globals referenced by FUN_00452b10. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044ddc0 | static_init | HIGH | CRT static initializer. Sets DAT_007ccdf8=0x35 (CollisionTableInit_35). Globals referenced by FUN_00452b10. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044e360 | static_init | HIGH | CRT static initializer. Sets DAT_007cd118=0x4c, DAT_007cd12c=18000. Globals referenced by FUN_00452b10. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044e900 | static_init | HIGH | CRT static initializer. Sets DAT_007ca564=0x5b, DAT_007ca578=9000. Globals referenced by FUN_00452b10. Called implicitly via .CRT$XIU table. | CRT startup |
| 0x0044fbb0 | game_logic_isolated | MEDIUM | __thiscall method on collision data struct. Copies 0x91 dwords to param_1+0x84. Struct offset +0x2F4 known (docs/13). No game globals. Likely called via virtual dispatch or function pointer — class method with no direct callers in analyzed code. | Virtual dispatch |
| 0x00478220 | game_logic_isolated | MEDIUM | Uses DAT_007cd8c0 (GameCommandDispatchInterface, docs/12). Calls vtable+0x1c(0x16) and self-vtable+0x2c(1). Compares param_1[0x3a] with *(iVar1+0x174). Monitors selection state change. Likely registered as callback via command dispatch system. | GameCommandDispatch system |
| 0x0048fc10 | game_logic_isolated | MEDIUM | Similar structure to FUN_00478220. Monitors param_1[0x38]->+0x174 state, calls self-vtable+0x2c(1) on change. Also calls self-vtable+0xa8. Uses game object vtable pattern. Likely registered as UI/game state callback. | Virtual dispatch (UI/state monitor) |
| 0x004c1660 | utility_isolated | HIGH | 5-byte thunk to FUN_004c0f60 (complex sorting logic with 0x68-element array at stride 0x1b4). No game globals. Thunk called indirectly — the target function is the real game logic. | — (thunk) |
| 0x0050c2e3 | utility_isolated | HIGH | Pure math: 4-point cubic Bezier interpolation (3D). No game globals, uses _DAT_0059e478 as coefficient constant. | — |
| 0x0050dcb0 | utility_isolated | HIGH | Pure math: rotation matrix from axis/angle via fcos/fsin. Calls thunk_FUN_0050c2a6 for basis vectors. Uses _DAT_0059e450 (deg→rad constant). | — |
| 0x00510975 | utility_isolated | HIGH | Byte-stream decompressor with callback-based buffer refill. MIDI-like event dispatch (status 0x4e=note, 0x1a/0x1b=control). No game globals. Called via buffer refill callback pattern. | — |
| 0x0052d8c0 | entry_point | HIGH | VTable destructor wrapper (thunk to FUN_0052d990). COM-style smart pointer cleanup: checks *param_1 non-null, calls vtable->dtor(1), sets *param_1=0. Called by compiler-generated cleanup code. | Compiler-generated cleanup |
| 0x005567a9 | utility_isolated | HIGH | Pure math: fixed-point division with sign handling (64-bit intermediate, 32-bit result). No game globals. | — |
| 0x00564680 | entry_point | HIGH | Winsock WSACleanup import thunk (5 bytes). Indirect jump via IAT. Called by network shutdown code. | Import Address Table |
| 0x00587dd0 | entry_point | HIGH | MSVC CRT _strncpy library function (254 bytes). Called by compiler-generated string copy code. Identified as "Library Function - Single Match" in Ghidra. | Compiler-generated code |
| 0x0058bb10 | entry_point | HIGH | MSVC CRT _memset library function (88 bytes). Called by compiler-generated zero-init/memset code. Identified as "Library Function - Single Match" in Ghidra. | Compiler-generated code |
| 0x00598630 | entry_point | HIGH | Winsock ntohs import thunk (6 bytes). Indirect jump via IAT. Called by network byte-order conversion code. | Import Address Table |
| 0x0059868a | entry_point | HIGH | Winsock setsockopt import thunk (6 bytes). Indirect jump via IAT. Called by network socket configuration code. | Import Address Table |
| 0x0059c464 | entry_point | HIGH | SEH unwind handler. Frees pointer at EBP-0x30 via FUN_00587bcf. Called by MSVC exception handling mechanism during stack unwinding. | SEH unwinder |
| 0x0059cbe8 | entry_point | HIGH | SEH unwind helper. Thunk to FUN_005819c0 (8 bytes). Called by MSVC exception handling mechanism during stack unwinding. | SEH unwinder |
| 0x0059d3cc | entry_point | HIGH | SEH unwind conditional cleanup. Checks flag at EBP-0x10 bit 0; if set, calls FUN_00599be5() (locale vtable destructor). Called by MSVC exception handling during stack unwinding. | SEH unwinder |

=== FULL ENTRIES ===
<!-- No new call relationships were discovered. All 25 orphans are reachable through mechanisms outside the analyzed call graph (CRT startup, SEH, IAT, compiler-generated code, virtual dispatch). Existing doc entries are correct and complete. -->
