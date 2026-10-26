# WORKER F — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker F of 20, items 216–258.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_F.md

## CATEGORIES
- `missed_function` — valid x86 code (55 8B EC / 53 56 57 prologue)
- `jump_table_data` — switch/case target table (array of addrs in 0x00400000-0x005E0000)
- `data_table` — numeric lookup table, coefficient array, constant pool
- `vtable` — virtual function table (array of function pointers)
- `string_data` — embedded string literals (mostly 0x20-0x7E bytes)
- `padding` — alignment fill (0x90/0xCC/0x00 repeats)
- `mixed` — combination
- `unknown` — unclassifiable

## HOW TO CLASSIFY
- `55 8B EC` or `53 56 57` at start → missed_function
- Repeating 4-byte values in game address range → vtable or jump_table_data
- Mostly 0x20-0x7E ASCII bytes → string_data
- `90 90 90` or `CC CC CC` → padding
- Regular 8-byte blocks with small exponent pattern → data_table (doubles)
- Check xrefs_into: what instruction type references this region?
- Check surrounding functions: which system context?

## OUTPUT FORMAT

```
=== GAP CLASSIFICATIONS ===
| Start | End | Size | Classification | Confidence | Description |
|-------|-----|------|----------------|------------|-------------|

=== NOTABLE FINDINGS ===
[Gaps likely containing missed functions, vtables, or important data — describe fully]
```

## YOUR GAPS (43)

GAP 216: 0x004058cf — 0x00405900 (49 bytes)
   hex_head: 90568bf1c706b4e459008b460485c0740950e8e922180083c404f644240801740956e8d922180083c4048bc65ec20400
   prev_func: 0x004058a0 — — Object Constructor with VTable and Sub-Free
   next_func: 0x00405900 — — Miles Audio Sample Playback Setup
   xrefs_into: none

GAP 217: 0x004087da — 0x00408800 (38 bytes)
   hex_head: 8bff598740005e87400063874000688740006d8740007d87400082874000878740008c874000
   prev_func: 0x00408740 — — Float-Keyed Field Selector
   next_func: 0x00408800 — — File Path Entry Array Destructor
   xrefs_into: none

GAP 218: 0x0040d0ea — 0x0040d100 (22 bytes)
   hex_head: 8bffe2d04000cad04000d2d04000dad0400090909090
   prev_func: 0x0040d0b0 — — Mode-Dispatched Subsystem Call
   next_func: 0x0040d100 — — Game State Branch Dispatch
   xrefs_into: none

GAP 219: 0x0040fd81 — 0x0040fda0 (31 bytes)
   hex_head: 909090909090909090909090909090e9bb9704009090909090909090909090
   prev_func: 0x0040fd70 — — Short Computation / VTable Init + Thunk
   next_func: 0x0040fda0 — — short computation
   xrefs_into: none

GAP 220: 0x00418dc7 — 0x00418e50 (137 bytes)
   hex_head: 90909090909090909068e08d4100e864ed160059c390909090b978b95e00e9060000009090909090905355568be9e8c6
   prev_func: 0x00418db0 — — Global Variable Zero-Init
   next_func: 0x00418e50 — — HUD/Display Data Reset
   xrefs_into: none

GAP 221: 0x00421566 — 0x004216f0 (394 bytes)
   hex_head: 8b4424085d5b83c454c3568bf18b86b000000085c0740950e84c66160083c4048b86a800000085c0740950e839661600
   prev_func: 0x004214a0 — Initializes 46 dwords with alternating 0/0xffffffff pattern.
   next_func: 0x004216f0 — — Config Directory Path Registration
   xrefs_into: none

GAP 222: 0x0043194a — 0x004319c0 (118 bytes)
   hex_head: 7ee8094dfdff51d94424088b410483f801dc25c8ea5900d95c24087529d9442408b838375c00dc25c0ea5900dc0db8ea
   prev_func: 0x00431930 — — SetContactConstraint
   next_func: 0x004319c0 — — Parameter Array Setter with Dirty Flag
   xrefs_into: none

GAP 223: 0x0044c5ea — 0x0044c620 (54 bytes)
   hex_head: 9090909090906800c64400e844b5130059c390909090b990a57c00e9966c0000909090909090e80b000000e936000000
   prev_func: 0x0044c5e0 — — Collision thunk
   next_func: 0x0044c620 — — Collision State Init (Slot 1)
   xrefs_into: none

GAP 224: 0x0044c9c1 — 0x0044c9f4 (51 bytes)
   hex_head: c94400e8e4b1130059c390909090c3e80b000000e936000000909090909090c705b0cc7c000b000000c705b4cc7c0000
   prev_func: 0x0044c9b0 — — Thunk
   next_func: 0x0044c9f4 — — SteeringSensitivityInit
   xrefs_into: none

GAP 225: 0x0044cd81 — 0x0044cdb4 (51 bytes)
   hex_head: cd4400e824ae130059c390909090c3e80b000000e936000000909090909090c705f8d07c0022000000c705fcd07c0000
   prev_func: 0x0044cd70 — — Collision Init Delegator (0xCD70)
   next_func: 0x0044cdb4 — — CollisionScaleInit
   xrefs_into: none

GAP 226: 0x0044d150 — 0x0044d160 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d130 — — Thunk
   next_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   xrefs_into: none

GAP 227: 0x0044d510 — 0x0044d520 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d4f0 — — Collision constructor thunk
   next_func: 0x0044d520 — — CollisionStateInit_17
   xrefs_into: none

GAP 228: 0x0045b2e4 — 0x0045b360 (124 bytes)
   hex_head: 83fb087eba5f5e5b83c424c3e80b000000e916000000909090909090b904d27c00e9860800009090909090906820b345
   prev_func: 0x0045b200 — — Game Main Entry / Initialization
   next_func: 0x0045b360 — — Short Computation (Constructor/Initializer)
   xrefs_into: none

GAP 229: 0x0046200e — 0x00462156 (328 bytes)
   hex_head: 90908b018b5424048b889cb701005657e85d1e10008bf085f60f840701000068f05b5c00bafc5b5c008bcee872241000
   prev_func: 0x00461ff0 — — Short Computation (Conditional Delegation)
   next_func: 0x00462160 — — Network Filter/Sort (numplayers/mapname/hostname)
   xrefs_into: none

GAP 230: 0x004672b6 — 0x004677e0 (1322 bytes)
   hex_head: e8bc450200e999ffffff566a008bf1e8a64d02008b4424088b4c240c8bd06bd20b03d1c1e20681c270577c0089962003
   prev_func: 0x00467260 — — Object Constructor with Parameter Setup
   next_func: 0x004677e0 — — LinkedListNodeDestructor
   xrefs_into: none

GAP 231: 0x0046c7a6 — 0x0046cb00 (858 bytes)
   hex_head: 4081f910d67c007cefc38a44240484c0bab8d27c007505ba70d47c0033c933c056833c82ff7407414083f8687cf38b44
   prev_func: 0x0046c750 — — Array Shift/Remove by Index
   next_func: 0x0046cb00 — — Global Sign Check
   xrefs_into: none

GAP 232: 0x00475529 — 0x00475c80 (1879 bytes)
   hex_head: 435a008bc65ec3568bf1c60550d87c0000e811fcffffa1740e7d0085c07524a0ac0f7d0084c0741b8a867c01000084c0
   prev_func: 0x00475140 — Forwards call to another function. No additional logic.
   next_func: 0x00475c80 — — Conditional Draw
   xrefs_into: none

GAP 233: 0x0047be6e — 0x0047be90 (34 bytes)
   hex_head: 9090568bf1e848d50000c70688675a00c78674010000000000008bc65ec390909090
   prev_func: 0x0047be00 — � Menu Scroll Position Calculator with Clamp
   next_func: 0x0047be90 — — Short Computation (Destructor)
   xrefs_into: none

GAP 234: 0x004866db — 0x00486710 (53 bytes)
   hex_head: 4d595448008b442404398184000000741d8981840000008b01c7818000000000000000c744240401000000ff602cc204
   prev_func: 0x004866ad — — UI Widget Property Propagator
   next_func: 0x00486710 — — Byte Field Getter at +100
   xrefs_into: none

GAP 235: 0x0048b4d0 — 0x0048b4e0 (16 bytes)
   hex_head: 8b016a01ff90a800000033c0c3909090
   prev_func: 0x0048b420 — — Constructor with String Copy
   next_func: 0x0048b4e0 — Set vtable pointer, call FUN_00485eb0.
   xrefs_into: none

GAP 236: 0x0048ea31 — 0x0048ea60 (47 bytes)
   hex_head: da320b005f32c05e81c4e991ffffff8b44240c8b54241089411c8b4424048951208b542408894124895128c2100090
   prev_func: 0x0048ea20 — � Two-Field Setter
   next_func: 0x0048ea60 — — Rectangle Bounds Check
   xrefs_into: none

GAP 237: 0x0049787b — 0x00497890 (21 bytes)
   hex_head: 90177849003078490049784900627849006c784900
   prev_func: 0x004977e0 — — Unknown (State Setter with Float Constant)
   next_func: 0x00497890 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 238: 0x0049afaa — 0x0049afc0 (22 bytes)
   hex_head: 90909090909068c0af4900e884cb0e0059c390909090
   prev_func: 0x0049afa0 — — Wrapper
   next_func: 0x0049afc0 — — CleanupCallbackRegister
   xrefs_into: none

GAP 239: 0x004a11da — 0x004a11f0 (22 bytes)
   hex_head: 90909090909068f0114a00e854690e0059c390909090
   prev_func: 0x004a11d0 — — Wrapper (same as 0049afa0)
   next_func: 0x004a11f0 — — No-op thunk
   xrefs_into: none

GAP 240: 0x004b0153 — 0x004b0170 (29 bytes)
   hex_head: 90bbf34a0024f84a0094fc4a0029ff4a00909090909090909090909090
   prev_func: 0x004af3a0 — — Physics Parameter Initialization
   next_func: 0x004b0170 — — Empty Stub (vtable slot)
   xrefs_into: none

GAP 241: 0x004b66bd — 0x004b66e0 (35 bytes)
   hex_head: 8d490096634b0087634b0087634b0087634b0087634b0087634b009090909090909090
   prev_func: 0x004b6360 — � Game Command Data Validator
   next_func: 0x004b66e0 — — Lap/Speed Comparison with Switch-Selectable Thresholds
   xrefs_into: none

GAP 242: 0x004bf380 — 0x004bf390 (16 bytes)
   hex_head: 20f14b0040f34b0071f34b0020f14b00
   prev_func: 0x004bf0a0 — — AI Behavior Initialization / Tick
   next_func: 0x004bf390 — — AI Driver Sorting / Priority
   xrefs_into: none

GAP 243: 0x004c9339 — 0x004c94d0 (407 bytes)
   hex_head: 5e83e9c1ffffffa114ce5a0050e8c5fbffffc7014cce5a0033d289511c8951208951248bc1c390568bf1c7064cce5a00
   prev_func: 0x004c9310 — — Resource Release Triple Dispatch
   next_func: 0x004c94d0 — � Virtual Release Array (3 elements)
   xrefs_into: none

GAP 244: 0x004d5c4d — 0x004d5c60 (19 bytes)
   hex_head: 90909068605c4d00e8e41e0b0059c390909090
   prev_func: 0x004d5c40 — — Short Computation (Global Zero Pair)
   next_func: 0x004d5c60 — — Wrapper: sub_4D7800
   xrefs_into: none

GAP 245: 0x004db139 — 0x004db420 (743 bytes)
   hex_head: f889e992ffffffa15ccf5a00894110c74114000080bfc6411801c7411c00000000c39090909090c741140000a041a15c
   prev_func: 0x004db130 — — Physics Constant Initializer
   next_func: 0x004db4e0 — — Dual-Vtable Destructor
   xrefs_into: none

GAP 246: 0x004f0d0e — 0x004f0d20 (18 bytes)
   hex_head: 8bff8e074f0075044f00a1044f008f0b4f00
   prev_func: 0x004f0430 — � Vehicle Setup Init / Per-Frame Update
   next_func: 0x004f0d20 — � Camera FOV / Zoom by Proximity
   xrefs_into: none

GAP 247: 0x0050bfc9 — 0x0050c021 (88 bytes)
   hex_head: f2b8500019b9500043b950006db9500097b95000c1b95000ebb9500015ba50003fba500069ba500093ba5000bdba5000
   prev_func: 0x0050b8a9 — — DirectX Texture/Surface Factory Dispatching FourCC Codes
   next_func: 0x0050c021 — — Render Object Destructor (thunk_FUN_0050b830)
   xrefs_into: none

GAP 248: 0x0051ff71 — 0x0051ff8e (29 bytes)
   hex_head: 908db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051febe — — Quaternion Construction/Transform (SSE)
   next_func: 0x0051ff8e — — SSE 3x4 Matrix-Vector Transform
   xrefs_into: none

GAP 249: 0x00527ec5 — 0x00527eed (40 bytes)
   hex_head: f9775200c378520024795200147a5200e37a5200617c5200027d5200737e5200be7e5200aa7d5200
   prev_func: 0x005276c5 — � Multi-Block Memory Allocator
   next_func: 0x00527eed — — [PARTIAL] Unknown
   xrefs_into: none

GAP 250: 0x00535bca — 0x00535c10 (70 bytes)
   hex_head: 8bff32585300a95853008b5a5300c45a5300025b53003c5b5300865b53001b59530082595300b7595300f15953002b5a
   prev_func: 0x005357c0 — — Argument Reorder Wrapper
   next_func: 0x00535e10 — — Conditional Multi-Field Reset
   xrefs_into: none

GAP 251: 0x00545f23 — 0x00545f40 (29 bytes)
   hex_head: 90325e5400405e54004e5e54005c5e5400909090909090909090909090
   prev_func: 0x00545d00 — ? Bitfield Flag Propagation
   next_func: 0x00545f40 — — Value Getter
   xrefs_into: none

GAP 252: 0x005542af — 0x005542f0 (65 bytes)
   hex_head: 90944255007342550078425500874255008c42550091425500aa425500aa425500aa425500aa425500aa425500aa4255
   prev_func: 0x00554260 — — Enum-to-Field-Offset Setter
   next_func: 0x005542f0 — @ 0x005542f0
   xrefs_into: none

GAP 253: 0x00564375 — 0x00564390 (27 bytes)
   hex_head: 8d4900234356002f4356003b4356003b4356009090909090909090
   prev_func: 0x005642f0 — — Struct Alloc/Init with Switch-Based Type
   next_func: 0x00564390 — — Audio Mixer Polling/Update Loop
   xrefs_into: none

GAP 254: 0x0057aa67 — 0x0057aaf0 (137 bytes)
   hex_head: 9090909090909090906880aa5700e8c4d0000059c3909090908a0dfb3b8d00b00184c8756153568b35fc3b8d0033db0a
   prev_func: 0x0057aa50 — @ 0x0057aa50
   next_func: 0x0057aaf0 — — Stack Buffer Copy + Predicate Call
   xrefs_into: none

GAP 255: 0x0057f158 — 0x0057fb90 (2616 bytes)
   hex_head: ff153ce35900ffff568bf15733ff8b86f40a000085c074308b8ef80a00005150ff15a0e1590085c074073d8000000075
   prev_func: 0x0057f0c8 — — NetworkSocketAddressInit
   next_func: 0x0057fb90 — — WinsockInit
   xrefs_into: none

GAP 256: 0x00586e8d — 0x00586ed0 (67 bytes)
   hex_head: 9090908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8840c000059c390
   prev_func: 0x00586e50 — — Short Computation / Struct Copy Assignment
   next_func: 0x00586ed0 — — Thunk to FUN_00598815
   xrefs_into: none

GAP 257: 0x0058db63 — 0x0058dc29 (198 bytes)
   hex_head: e8c1000000d9c9ddd8c3e8b7000000ebf6ddd8ddd8d9eec3ddd8ddd8d9e8c3dbbd62ffffffdbad62fffffff68569ffff
   prev_func: 0x0058dad7 — @ 0x0058dad7
   next_func: 0x0058dc29 — — SetByteFlag
   xrefs_into: none

GAP 258: 0x0059bffd — 0x0059c0ac (175 bytes)
   hex_head: cccccc8b44240c85c074448b54240456578bf28b7c24100bd783e2037432a901000000740b8a0e3a0f7552464748741d
   prev_func: 0x0059bfc3 — — __CxxThrowException_8
   next_func: 0x0059c0ac — @ 0x0059c0ac
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_F.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
