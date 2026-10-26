# WORKER M — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker M of 20, items 517–558.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_M.md

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

## YOUR GAPS (42)

GAP 517: 0x00406d9b — 0x00406e50 (181 bytes)
   hex_head: 4d595448005153578bf98b474c33db3bc3895c24087e61555633ed8b47488b342803c53bf3743c837e140175108bcee8
   prev_func: 0x00406cc0 — — Audio Driver Init
   next_func: 0x00406e50 — — Audio System Shutdown
   xrefs_into: none

GAP 518: 0x0040a658 — 0x0040a680 (40 bytes)
   hex_head: 22a6400028a640002ea6400034a640003aa6400040a6400046a640004ca6400052a6400090909090
   prev_func: 0x0040a610 — General utility function. See decompiled code for exact beha
   next_func: 0x0040a680 — — File Path List Search
   xrefs_into: none

GAP 519: 0x0040e1ca — 0x0040e1e0 (22 bytes)
   hex_head: 90909090909068e0e14000e86499170059c390909090
   prev_func: 0x0040e1c0 — — Delegation Thunk
   next_func: 0x0040e1e0 — — Wrapper: sub_40FB30
   xrefs_into: none

GAP 520: 0x00412aad — 0x00412c30 (387 bytes)
   hex_head: 8d4900cb244100d5244100df244100e9244100f3244100fd2441000725410008264100112541001b254100252541002f
   prev_func: 0x00412490 — ? Game Control Mapping
   next_func: 0x00412c30 — — MapCollisionShapeToBoneIndex
   xrefs_into: none

GAP 521: 0x0041c079 — 0x0041c090 (23 bytes)
   hex_head: 8d4900bbbe410056bf410098bf4100bbbf410090909090
   prev_func: 0x0041be60 — — Pit/Race Status Message Dispatcher
   next_func: 0x0041c090 — — Display Message 0x202
   xrefs_into: none

GAP 522: 0x0042b8aa — 0x0042b8c0 (22 bytes)
   hex_head: 90909090909068c0b84200e884c2150059c390909090
   prev_func: 0x0042b8a0 — — Thunk to FUN_004b3db0
   next_func: 0x0042b8c0 — — Stub to Nullsub
   xrefs_into: none

GAP 523: 0x00433ead — 0x00433ed0 (35 bytes)
   hex_head: 909090568bf1b9c0567c00e8a3adffff6838a45e008d4e08e8862713005ec390909090
   prev_func: 0x00433e60 — — Physics Object Destructor
   next_func: 0x00433ed0 — — Validate Vehicle Configuration File
   xrefs_into: none

GAP 524: 0x0044c769 — 0x0044c780 (23 bytes)
   hex_head: 909090909090906880c74400e8c4b3130059c390909090
   prev_func: 0x0044c740 — — CollisionGridInit4
   next_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   xrefs_into: none

GAP 525: 0x0044cb29 — 0x0044cb40 (23 bytes)
   hex_head: 909090909090906840cb4400e804b0130059c390909090
   prev_func: 0x0044cb14 — — Global Initializer (-1.0, 0.0)
   next_func: 0x0044cb60 — — Initialize Collision Globals D
   xrefs_into: none

GAP 526: 0x0044cee9 — 0x0044cf00 (23 bytes)
   hex_head: 909090909090906800cf4400e844ac130059c390909090
   prev_func: 0x0044ced4 — — InitFloatConstants
   next_func: 0x0044cf20 — — CollisionStateInit_Alpha2
   xrefs_into: none

GAP 527: 0x0044d2a9 — 0x0044d2c0 (23 bytes)
   hex_head: 9090909090909068c0d24400e884a8130059c390909090
   prev_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   next_func: 0x0044d2e0 — — CollisionGlobalsInit
   xrefs_into: none

GAP 528: 0x0044f7b6 — 0x0044f7d0 (26 bytes)
   hex_head: 8bff00f744000df744001af7440027f744009090909090909090
   prev_func: 0x0044f73c — — Cursor/Scroll Position Tracker
   next_func: 0x0044f7d0 — — ContactFlagReadClear
   xrefs_into: none

GAP 529: 0x0045bf5a — 0x0045bf90 (54 bytes)
   hex_head: 9090909090906870bf4500e8d4bb120059c390909090b95cd27c00e9265d0000909090909090e80b000000e966000000
   prev_func: 0x0045bf50 — — Single Function Call Wrapper
   next_func: 0x0045bf90 — — Collision Mutex Initialization
   xrefs_into: none

GAP 530: 0x00465c17 — 0x00465c30 (25 bytes)
   hex_head: 90ba554600c4554600ce554600d85546009090909090909090
   prev_func: 0x00465460 — — Entity Visibility Grid Manager
   next_func: 0x00465c30 — — Linked List Pop-Front
   xrefs_into: none

GAP 531: 0x00469187 — 0x004692a0 (281 bytes)
   hex_head: ff158ce15900e55dc3566a008bf1e846fdffff8b066a008bceff503c33c05ec3ff155ce05900c20400578bf9e8a84102
   prev_func: 0x00468ee0 — — Player Profile Scanner
   next_func: 0x004692a0 — — Short Computation
   xrefs_into: none

GAP 532: 0x0046e842 — 0x0046ec10 (974 bytes)
   hex_head: fe5900c68674010000008bc65ec383ec288b4424388b542430535556578be98b4c2444508b4424405152508bcd896c24
   prev_func: 0x0046e7f0 — — Polling Loop with Branch
   next_func: 0x0046ec10 — — Object Name Matching + Activation
   xrefs_into: none

GAP 533: 0x00477079 — 0x00477280 (519 bytes)
   hex_head: 0000e902ffffff568bf1e8487b0100c6867c0100000033c05ec3ca83e103f3a45f5ee9d9ffffff8b917001000085d256
   prev_func: 0x00476fc0 — — Driver Name Copy from Global Array
   next_func: 0x00477280 — — Object Name Comparison
   xrefs_into: none

GAP 534: 0x0047e390 — 0x0047e3f4 (100 bytes)
   hex_head: 56e80afdffff8b0dc0d87c008b016a15ff501c85c0744a8bc8e8e211010085c0743f8b484885c97e078b403c85c07504
   prev_func: 0x0047e384 — — ByteAccumAdd
   next_func: 0x0047e3f4 — — Race Laps String Load on Trigger
   xrefs_into: none

GAP 535: 0x00487755 — 0x00487ed0 (1915 bytes)
   hex_head: 83e802740332e9d3ffffff53e8baefffff83f8040f879a000000ff2485107848008a44240884c00f85870000008b015b
   prev_func: 0x00487740 — — Range Check
   next_func: 0x00487ed0 — Initializes struct with vtable and two byte params.
   xrefs_into: none

GAP 536: 0x0048d095 — 0x0048d230 (411 bytes)
   hex_head: 0074068b0085e908fcffff568bf18b4e40e885b60000518bced91c24e84afaffff8b068bceff90ac00000033c05ec333
   prev_func: 0x0048ccb0 — â€” Scrollable UI List Rendering
   next_func: 0x0048d230 — — Linked List Destruction with VTable Call
   xrefs_into: none

GAP 537: 0x00490282 — 0x004902c0 (62 bytes)
   hex_head: 909090909090909090909090909033c0c2100000020000005fe9a3ffffff568bf1e818000000f644240801740956e81a
   prev_func: 0x00490250 — — Object Init with Field Zeroing
   next_func: 0x004902c0 — Free linked list nodes with vtable+0(1) notification on each
   xrefs_into: none

GAP 538: 0x0049918b — 0x004991e0 (85 bytes)
   hex_head: 909090909033c0c208000630ca5a008be9b9ffffff56e89afcffff8bd0e8b3fdffff85d28bf074078bcae86603000085
   prev_func: 0x00499180 — — Short Computation (VTable Set)
   next_func: 0x004991e0 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 539: 0x0049b66f — 0x0049b6d0 (97 bytes)
   hex_head: 9051d9442408568bf1e85fc50e0089442404db442404d80dbce95900e84cc50e008b4c24108b54241889442404db4424
   prev_func: 0x0049b630 — — SpatialGridCell
   next_func: 0x0049b6d0 — — Lap Time Gap Calculation
   xrefs_into: none

GAP 540: 0x004a4097 — 0x004a40e0 (73 bytes)
   hex_head: ff1590e35900ffffffe80b000000e916000000909090909090c390909090909090909090909090909068d0404a00e874
   prev_func: 0x004a4050 — Updates accumulator based on state at +0x78.
   next_func: 0x004a40e0 — — Large Buffer Zero-Init (0x68 ints)
   xrefs_into: none

GAP 541: 0x004b21ca — 0x004b21e0 (22 bytes)
   hex_head: 90909090909068e0214b00e864590d0059c390909090
   prev_func: 0x004b21c0 — — Single Call Wrapper
   next_func: 0x004b21e0 — — DebugPrintNullWrapper
   xrefs_into: none

GAP 542: 0x004b97a9 — 0x004b97d0 (39 bytes)
   hex_head: c0010000c20c00568b3185f674108bcee872c2ffff56e80be40c0083c4045ec3c089068bc65ec3
   prev_func: 0x004b9780 — — Arithmetic/Comparison / Memory Allocation with Constructor
   next_func: 0x004b97d0 — — Thunk to FUN_004b7300
   xrefs_into: none

GAP 543: 0x004c3d38 — 0x004c3d80 (72 bytes)
   hex_head: 5b81c4e9b5fcffff8b0d94c38a0085c974358b41fc538d59fc568bf069f62404000003f1487815578d780181ee240400
   prev_func: 0x004c3a00 — — TGA Texture File Scanner
   next_func: 0x004c3f80 — — Vehicle Lookup by Name
   xrefs_into: none

GAP 544: 0x004d001d — 0x004d0030 (19 bytes)
   hex_head: 909090e80b000000e916000000909090909090
   prev_func: 0x004cfff0 — — SpecialFX::Exit
   next_func: 0x004d0030 — — Wrapper
   xrefs_into: none

GAP 545: 0x004d89ca — 0x004d8a30 (102 bytes)
   hex_head: 89e889dcf2ff8bd183c8ff8902894204894208a134cf5a008982dc000000c682e000000001b80000803f8982e4000000
   prev_func: 0x004d8950 — Iterate arrays of interface pointers, call vtable+0(1) on ea
   next_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   xrefs_into: none

GAP 546: 0x004dceb9 — 0x004dcee0 (39 bytes)
   hex_head: 8d4900ebcd4d0001ce4d001cce4d003cce4d0055ce4d005ace4d007dce4d0083ce4d008fce4d00
   prev_func: 0x004dcdd0 — — Position Computation with Alignment (9 cases)
   next_func: 0x004dcee0 — � Float-to-Int Chain Delegate
   xrefs_into: none

GAP 547: 0x004f6ef9 — 0x004f7010 (279 bytes)
   hex_head: 0589e985feffff8bc133c9880889480489480889480c88481089481489481889481cc390909090568bf1578d96b40000
   prev_func: 0x004f6d90 — — Parametric Interpolation/Blending
   next_func: 0x004f7010 — — StateHandlerDispatch
   xrefs_into: none

GAP 548: 0x00517569 — 0x005176ec (387 bytes)
   hex_head: 8b4424088b54240c8b4c2404d900d80ad900d84a08d900d84a04d900d84a0cd9cbd94004d84a10d94004d84a18d94004
   prev_func: 0x00517534 — — Mat2x2Mul
   next_func: 0x005176ec — — Vector Normalize (Fast rsqrt)
   xrefs_into: none

GAP 549: 0x005207b9 — 0x005207ce (21 bytes)
   hex_head: 8db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052050e — — SSEMatrix4x4Multiply
   next_func: 0x005207ce — — SSEVectorCross
   xrefs_into: none

GAP 550: 0x0052d225 — 0x0052d294 (111 bytes)
   hex_head: 0000000cc300800000000010d45a00c40000000cc400800000000010d45a00c50000000cc500800000000010d45a00c6
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 551: 0x0053b3db — 0x0053b490 (181 bytes)
   hex_head: e879b2ecff8b0183e001fec8f6d81bc040c390909051d9413cd94138d9c0d8c9d9c2d8cbdec1d9fad95c2400ddd8ddd8
   prev_func: 0x0053b3b0 — — Identity 4×4 Matrix Init
   next_func: 0x0053b490 — — Identity Function
   xrefs_into: none

GAP 552: 0x0054d00a — 0x0054d030 (38 bytes)
   hex_head: 8bffc7cb540013cc540053cc54008ccc540028ce54007bce5400bfce5400fcce540090909090
   prev_func: 0x0054ca00 — � D3D Vertex Buffer Creation and Software T&L
   next_func: 0x0054d030 — — SceneNodeChildrenClear
   xrefs_into: none

GAP 553: 0x00556896 — 0x00556900 (106 bytes)
   hex_head: 8b00e81ffde984feffffe80b000000e9260000009090909090905657be70bf8c00bf000200008d6424008bcee83925ff
   prev_func: 0x0055687b — — RDTSC Timestamp Read
   next_func: 0x00556900 — — Add Float to Animation Channels
   xrefs_into: none

GAP 554: 0x00574010 — 0x00575863 (6227 bytes)
   hex_head: 8b44240483f8270f87d1110000ff2485f1515700d9e8dd1df0fb8c00d9eedd1db8fc8c00d9eedd1d80fd8c00d9eedd1d
   prev_func: 0x0056fa96 — — Block LDL^T Sparse Constraint Factorization
   next_func: 0x00575875 — — Enum value check (== 34)
   xrefs_into: none

GAP 555: 0x0057af75 — 0x0057afa0 (43 bytes)
   hex_head: 20894824c700e966ffffff8a442404568bf1a801c706408a5b00740956e838cc000083c4048bc65ec20400
   prev_func: 0x0057aef0 — � Linked List Destruction & Cleanup
   next_func: 0x0057afa0 — — Network Packet Constructor
   xrefs_into: none

GAP 556: 0x00582f2a — 0x00582f60 (54 bytes)
   hex_head: cccc003bccc38a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8e44b0000
   prev_func: 0x00582eb0 — — Linked-List Node Removal with Cleanup Callback
   next_func: 0x00582f60 — — SEH-Protected Linked List Destruction
   xrefs_into: none

GAP 557: 0x005876ca — 0x005876f0 (38 bytes)
   hex_head: 90909090909068e0765800e86404000059c390909090b9383e8d00e9ef230100909090909090
   prev_func: 0x005876c0 — — Single Function Call Wrapper
   next_func: 0x005876f0 — — Buffered Char I/O Init
   xrefs_into: none

GAP 558: 0x005966e6 — 0x00596716 (48 bytes)
   hex_head: af625900fe625900556359007f635900da6359005164590087645900d1645900b0645900356559001f655900eb645900
   prev_func: 0x00596245 — @ 0x00596245
   next_func: 0x00596716 — @ 0x00596716 — 93 bytes
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_M.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
