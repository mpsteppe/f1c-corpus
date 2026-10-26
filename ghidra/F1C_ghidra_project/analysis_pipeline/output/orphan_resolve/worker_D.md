=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x00405b50 | game_logic_isolated | MEDIUM | Calls AIL_sample_status_4 (Miles Sound System); checks sample state (SMP_DONE=4, SMP_PLAYING=0x10); reads audio struct at param_1+0x58 and +0x14. No callers in .c files — likely called from audio manager via indirect dispatch. | — |
| 0x0044c680 | game_logic_isolated | MEDIUM | Writes collision global DAT_007cca44=2 (type ID), +0x48=0, +0x4c=-1.0f, +0x50=0. Part of collision region init table. No callers — called via coll_init_func_table[] iteration in startup code. | — |
| 0x0044cc20 | game_logic_isolated | MEDIUM | Writes collision global DAT_007ca3b8=0x1e(30), +0xbc=0, +0xc0=0, +0xc4=1.0f. Same pattern as #80. Referenced as key in FUN_00452810 and FUN_0044ff50. | — |
| 0x0044d1c0 | game_logic_isolated | MEDIUM | Writes collision global DAT_007ccfa0=0x6d(109), +0xa4=0, +0xa8=-1.0f, +0xac=0. Same pattern as #80. Referenced as key in FUN_00452810. | — |
| 0x0044d760 | game_logic_isolated | MEDIUM | Writes collision global DAT_007ccc20=0x17(23), +0x24=0, +0x28=0, +0x2c=0, +0x30=0, +0x34=0. Same pattern as #80. Referenced as key in FUN_00452b10. | — |
| 0x0044dd00 | game_logic_isolated | MEDIUM | Writes collision global DAT_007cce88=0x33(51), +0x8c=0, +0x90=0, +0x94=0, +0x98=0, +0x9c=0. Same pattern as #80. Referenced as key in FUN_00452b10. | — |
| 0x0044e2a0 | game_logic_isolated | MEDIUM | Writes collision global DAT_007cd098=0x4a(74), +0x9c=0, +0xa0=0, +0xa4=0, +0xa8=0, +0xac=0. Same pattern as #80. Referenced as key in FUN_00452b10. | — |
| 0x0044e840 | game_logic_isolated | MEDIUM | Writes collision global DAT_007cd01c=0x59(89), +0x20=0, +0x24=0, +0x28=0, +0x2c=0, +0x30=27000. Same pattern as #80. Referenced as key in FUN_00452b10. | — |
| 0x0044f010 | game_logic_isolated | MEDIUM | Stores -abs(param_2) to param_1+0xc7c and -abs(param_3) to param_1+0xc80. Accesses vehicle collision struct at vehicle offset 0xc7c/0xc80 (collision response forces). Called from collision response pipeline. | — |
| 0x00478180 | game_logic_isolated | MEDIUM | Command dispatch handler for command 0x11. Calls through vtable at DAT_007cd8c0+0x1c, stores result to param_1+0xe0. Command Dispatch (0x11) is part of session/race command system. Called via command dispatch table. | — |
| 0x0048ea40 | utility_isolated | HIGH | Simple 4-field setter (param_1+0x1c/0x20/0x24/0x28). No game globals, no struct offsets. Pure setter utility. | — |
| 0x004b44e0 | game_logic_isolated | MEDIUM | Fixed-block memory pool init. Allocates 0x3600-byte pool, initializes DAT_008ab6f0 (pool head), DAT_008ab700 (free list). Creates linked list of 0x1b0-byte blocks. Called once at startup. | — |
| 0x0050c23c | utility_isolated | HIGH | Bilinear interpolation in 2D (float params). Pure math. No game globals. | — |
| 0x0050d857 | game_logic_isolated | MEDIUM | Thunk to indirect call via _DAT_005d7860 (global function pointer). 6-byte jump-through-pointer. Called by release-build code that inlined the dispatch. | — |
| 0x00510012 | game_logic_isolated | MEDIUM | Image format stream decoder. Reads byte stream through refill callback at puVar3[3], decodes pixel data (width/height from stream), writes to texture memory at *unaff_ESI + offsets. Called from texture loader. | — |
| 0x00528cc0 | utility_isolated | HIGH | Color space transformation (3D LUT / gamma correction). Mass of float math with bit manipulation. Uses constant tables at 0x005d9xxx. Renderer pixel processing — no game globals. | — |
| 0x0054fe00 | utility_isolated | HIGH | Inverse scale: writes _DAT_0059e43c(1.0)/param_2 to param_1+0x58. Uses constant 1.0 only. | — |
| 0x00561acf | utility_isolated | HIGH | Array fill with value (param_1=start, param_2=count, param_3=value, param_4=base). Simple loop. | — |
| 0x00587bdc | utility_isolated | HIGH | CRT __ftol (float-to-long conversion). MSVC library function. | — |
| 0x0058b050 | utility_isolated | HIGH | CRT _strrchr (reverse string search). MSVC library function. | — |
| 0x00596100 | utility_isolated | HIGH | CRT __aullrem (unsigned long long remainder). MSVC library function. | — |
| 0x0059867e | utility_isolated | HIGH | send() Winsock wrapper (import thunk). 6-byte jump to WS2_32.send. | — |
| 0x0059b250 | utility_isolated | HIGH | Direct3DCreate8 import thunk. 6-byte jump to d3d8.Direct3DCreate8. | — |
| 0x0059ca10 | game_logic_isolated | MEDIUM | SEH unwind handler. Calls FUN_00587bcf with EBP-0x10. Called by MSVC runtime exception handling (__except_handler3 table). Not a normal function call — invoked by unwind machinery. | — |
| 0x0059d2b4 | game_logic_isolated | MEDIUM | SEH unwind handler. Calls FUN_00598c70. Called by MSVC runtime exception handling. Invoked by unwind machinery. | — |

=== FULL ENTRIES ===
<!-- No new call relationships discovered. Existing doc entries are accurate. -->
<!-- Collision init functions (#80-#87) are part of a table-driven collision region init loop. -->
<!-- The init table lives in .rdata (function pointer array), so cross-references don't appear as direct calls in decompiled code. -->
<!-- Command dispatch (#88) uses vtable at DAT_007cd8c0+0x1c — called indirectly through dispatch table. -->
<!-- SEH handlers (#102-#103) are invoked by MSVC runtime exception unwinding, not by direct function calls. -->
<!-- CRT functions (#97-#99) and import thunks (#100-#101) are called by linker-generated code. -->
