# WORKER C — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker C of 3, items 569–852.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_C.md

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

## YOUR GAPS (284)

GAP 569: 0x004049cc — 0x00404ac0 (244 bytes)
   hex_head: 909090908a411484c0746a8b41204875648b41508b151c047d00a3442e7d008b4954a118047d003bc8890d10047d007d
   prev_func: 0x00404970 — Check param_1+0x20 == 1, then dispatch sound/render init seq
   next_func: 0x00404ac0 — — RenderNodeListDestructor
   xrefs_into: none

GAP 570: 0x004058cf — 0x00405900 (49 bytes)
   hex_head: 90568bf1c706b4e459008b460485c0740950e8e922180083c404f644240801740956e8d922180083c4048bc65ec20400
   prev_func: 0x004058a0 — — Object Constructor with VTable and Sub-Free
   next_func: 0x00405900 — — Miles Audio Sample Playback Setup
   xrefs_into: none

GAP 571: 0x00406511 — 0x00406640 (303 bytes)
   hex_head: e45900d80d50e4590083e991fbffff8b410c85c074096a0150ff158ce35900c375dc6a008bcbe8f30100e9d1ffffff8b
   prev_func: 0x004064c0 — — View/Camera Reset
   next_func: 0x00406640 — — Conditional Match Trigger
   xrefs_into: none

GAP 572: 0x00406c9b — 0x00406cc0 (37 bytes)
   hex_head: 4d59544800f644240401568bf1c70698e55900740956e8190f180083c4048bc65ec2040090
   prev_func: 0x00406ba0 — Destructor that destroys 4 linked lists with different clean
   next_func: 0x00406cc0 — — Audio Driver Init
   xrefs_into: none

GAP 573: 0x004071c5 — 0x004071f0 (43 bytes)
   hex_head: 74068b0885c975e45e5bc333c089417c898180000000898184000000e95a0b000090909090909090909090
   prev_func: 0x004070e0 — — Spatial Query with Weighted Distance Selection
   next_func: 0x004071f0 — — Audio Sample Position/Volume Setter
   xrefs_into: none

GAP 574: 0x004076d4 — 0x00407be0 (1292 bytes)
   hex_head: e359008115f4e3e962fdffff5356578bf98b473885c08947400f84be0000008b1885db0f84b40000008b4c2410390b74
   prev_func: 0x00407520 — — Linked List Node Insert
   next_func: 0x00407be0 — — Linked List Node Removal by Key
   xrefs_into: none

GAP 575: 0x0040821a — 0x00408230 (22 bytes)
   hex_head: 9090909090906830824000e814f9170059c390909090
   prev_func: 0x00408210 — — Delegation Wrapper to FUN_00408280
   next_func: 0x00408250 — — Short Computation
   xrefs_into: none

GAP 576: 0x004085c8 — 0x004085f0 (40 bytes)
   hex_head: 90dd0590fe8a00c3f644240401568bf1c70634e65900740956e8e9f5170083c4048bc65ec2040090
   prev_func: 0x004085c0 — — Stub Return 1
   next_func: 0x004085f0 — � Sound Effect Playback (Positional Audio)
   xrefs_into: none

GAP 577: 0x00408e1b — 0x00409440 (1573 bytes)
   hex_head: 4d59544800b85c200000e896f3170053558bac246820000085ed56578bf10f84ee0500008d4c2418e868da150033c0b9
   prev_func: 0x00408de0 — Conditionally call subsystem functions based on state flags.
   next_func: 0x00409440 — — View/Camera Mode Dispatch
   xrefs_into: none

GAP 578: 0x004099de — 0x00409a00 (34 bytes)
   hex_head: 90908b0d64fe8a006a006a20e8110814008b0d88fe8a00e9a6c11300909090909090
   prev_func: 0x00409970 — — Conditional Camera Pipeline Setup
   next_func: 0x00409a00 — — CameraModeViewportUpdate
   xrefs_into: none

GAP 579: 0x0040a658 — 0x0040a680 (40 bytes)
   hex_head: 22a6400028a640002ea6400034a640003aa6400040a6400046a640004ca6400052a6400090909090
   prev_func: 0x0040a610 — General utility function. See decompiled code for exact beha
   next_func: 0x0040a680 — — File Path List Search
   xrefs_into: none

GAP 580: 0x0040b25a — 0x0040b410 (438 bytes)
   hex_head: 89e8f9b3ffff83ec1c568bf18b0657ff50148b46148b560c8b0d88fe8a008d3c80c1e705680020000003fae8d6ee1300
   prev_func: 0x0040b030 — — Static Camera Scene Loader
   next_func: 0x0040b410 — — ListContains160ByteElement
   xrefs_into: none

GAP 581: 0x0040b849 — 0x0040bcd0 (1159 bytes)
   hex_head: 01ff5010c20400b8386c0000e866c917005355568be9578d4c2414e847b0150033c0b9600000008dbc24c8010000f3ab
   prev_func: 0x0040b710 — — Camera Transform Computation
   next_func: 0x0040bcd0 — — Resource Lookup with Optional VTable Dispatch
   xrefs_into: none

GAP 582: 0x0040c127 — 0x0040c140 (25 bytes)
   hex_head: 90c4c04000c8c04000cfc04000d6c040009090909090909090
   prev_func: 0x0040c070 — Timer-based state trigger with random outcome selection and 
   next_func: 0x0040c240 — — SceneFile Load by CurrentIndex
   xrefs_into: none

GAP 583: 0x0040d04d — 0x0040d080 (51 bytes)
   hex_head: 8d490003ce400003ce400003ce40005ace4000e9ce400030cf4000e2ce400083cf4000b5cf4000e8cf40001bd0400090
   prev_func: 0x0040cde0 — — Game Action State Machine
   next_func: 0x0040d090 — — Virtual Dispatch + Conditional Audio
   xrefs_into: none

GAP 584: 0x0040d94f — 0x0040d980 (49 bytes)
   hex_head: 9016d94000ebd74000ebd7400032d7400072d7400032d740003bd84000ebd74000ebd74000ebd74000ebd74000ebd740
   prev_func: 0x0040d4c0 — — Race Commentary/Director System
   next_func: 0x0040d980 — Initialize a structure with file/path constant references an
   xrefs_into: none

GAP 585: 0x0040e12f — 0x0040e170 (65 bytes)
   hex_head: 9061df400085df4000afdf4000cfdf4000eedf4000ffdf400026e14000b7e0400086e040001de14000a4e040000de040
   prev_func: 0x0040de60 — ? AI Behavior State Machine
   next_func: 0x0040e170 — — Tick/Update Dispatch
   xrefs_into: none

GAP 586: 0x0040e74f — 0x0040e770 (33 bytes)
   hex_head: 901fe740002fe740003fe740001fe740002fe740003fe740009090909090909090
   prev_func: 0x0040e710 — — Short Computation (Field Set via Switch Dispatch)
   next_func: 0x0040e770 — — Short Computation / Session Update Dispatch
   xrefs_into: none

GAP 587: 0x0040ef52 — 0x0040ef70 (30 bytes)
   hex_head: 8bff0eef40000eef40000eef40000eef40000eef40000eef400090909090
   prev_func: 0x0040eec0 — Processes float parameters through math functions based on a
   next_func: 0x0040ef70 — — Physics State Vector Conversion
   xrefs_into: none

GAP 588: 0x0040f2d8 — 0x0040f300 (40 bytes)
   hex_head: d7f140000bf240003ff24000d7f140000bf240003ff240006ff24000c4f240009090909090909090
   prev_func: 0x0040f1c0 — — Scene Object Loader State Machine
   next_func: 0x0040f300 — — Mode-Dispatched Render/Physics Call
   xrefs_into: none

GAP 589: 0x0040f52c — 0x0040f550 (36 bytes)
   hex_head: d5f44000f2f440000ff54000d5f44000f2f440000ff54000c2f440009090909090909090
   prev_func: 0x0040f4b0 — — Mode Dispatch with Switch (0-6)
   next_func: 0x0040f550 — — UI/Camera Mode Dispatch with Vehicle Data Read
   xrefs_into: none

GAP 590: 0x0040fd81 — 0x0040fda0 (31 bytes)
   hex_head: 909090909090909090909090909090e9bb9704009090909090909090909090
   prev_func: 0x0040fd70 — — Short Computation / VTable Init + Thunk
   next_func: 0x0040fda0 — — short computation
   xrefs_into: none

GAP 591: 0x0041143a — 0x00411570 (310 bytes)
   hex_head: 7ce81952ffff833de4b68a000256578bf10f84ce0000008b56488b7c240c33c085d27e188b4e5081c1d00000003b3974
   prev_func: 0x00411330 — — Short Computation (Vehicle Parameter Setter)
   next_func: 0x00411570 — — Status Field Copy
   xrefs_into: none

GAP 592: 0x00412215 — 0x004122c0 (171 bytes)
   hex_head: 8d4900d71e4100fa1e41001d1f4100dc1f41008f1f4100b41f410001204100262041006a1f41006c2041004920410088
   prev_func: 0x00411e90 — — Sound Event Dispatcher
   next_func: 0x004122c0 — — Session String/Name Lookup
   xrefs_into: none

GAP 593: 0x004132e2 — 0x004133b0 (206 bytes)
   hex_head: 8bff7f2e4100952e4100ab2e4100c12e4100d72e4100ed2e4100032f4100192f41002f2f4100452f41005b2f4100712f
   prev_func: 0x00412e50 — â€” DirectInput Scancode Mapping
   next_func: 0x004133b0 — — Text Attribute Lookup (Format 0)
   xrefs_into: none

GAP 594: 0x004141d7 — 0x00414370 (409 bytes)
   hex_head: ff1544e15900ffffffe80b000000e916000000909090909090b9e8a55e00e9660e00009090909090906810424100e834
   prev_func: 0x004141a0 — — Short Computation (Array Lookup)
   next_func: 0x00414370 — — Short Computation (Conditional Free)
   xrefs_into: none

GAP 595: 0x004155c8 — 0x00415650 (136 bytes)
   hex_head: c484000000c2080053558b6c240c5683c8ff85ed578bf974618b5f2c33f685db7e588d9b0000000085f68bce7c1c3b77
   prev_func: 0x00415550 — — Linked List Index Scanner with Validation
   next_func: 0x00415650 — — Linked List Indexed Accessor
   xrefs_into: none

GAP 596: 0x00418bfc — 0x00418c10 (20 bytes)
   hex_head: a48b4100bc8b4100d18b4100e68b410090909090
   prev_func: 0x00418b90 — — Score/Threshold Gate Check
   next_func: 0x00418c10 — — Memory Allocation / Nested Pointer Free with Conditional D
   xrefs_into: none

GAP 597: 0x00419c0a — 0x00419c50 (70 bytes)
   hex_head: 8bffd49b41009f9b4100039c410000010101010101010101010102020102020202010202020201020202020102020202
   prev_func: 0x004199e0 — — AI Retirement/Vehicle Failure Event
   next_func: 0x00419c50 — — Per-Driver Race Commentary
   xrefs_into: none

GAP 598: 0x0041ad5d — 0x0041ad80 (35 bytes)
   hex_head: 8d4900f0ac4100f0ac4100f7ac4100feac410005ad41000cad410013ad410090909090
   prev_func: 0x0041ac50 — � Race Event Sound Dispatch
   next_func: 0x0041ad80 — � Overtake / Position Swap
   xrefs_into: none

GAP 599: 0x0041c079 — 0x0041c090 (23 bytes)
   hex_head: 8d4900bbbe410056bf410098bf4100bbbf410090909090
   prev_func: 0x0041be60 — — Pit/Race Status Message Dispatcher
   next_func: 0x0041c090 — — Display Message 0x202
   xrefs_into: none

GAP 600: 0x0041f037 — 0x0041f070 (57 bytes)
   hex_head: ff1554e25900ffffff568bf1b9b02d7d00e803380a008bc8e87c210a0085c07e0a85f674068b4486145ec383c8ff5ec3
   prev_func: 0x0041efe0 — — Count Matching Season Entries
   next_func: 0x0041f070 — — Relative Performance Comparator
   xrefs_into: none

GAP 601: 0x0041f82b — 0x0041f8a0 (117 bytes)
   hex_head: 903cf6410043f641004af6410051f6410058f641005ff6410066f641006df6410074f641007bf6410082f6410089f641
   prev_func: 0x0041f220 — — Championship Points Accumulator
   next_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   xrefs_into: none

GAP 602: 0x004201de — 0x004203d0 (498 bytes)
   hex_head: 9090565783cfff85c90f84d50100008db104010000bae0265c008bcee81166140085c0740abf630100008bc75f5ec3ba
   prev_func: 0x0041ff10 — — Scene Element Scan with Condition Check
   next_func: 0x004203d0 — Trampoline -- unconditional jmp to FUN_004201e0. No local lo
   xrefs_into: none

GAP 603: 0x0042145b — 0x00421470 (21 bytes)
   hex_head: 4d59544800e80b000000e916000000909090909090
   prev_func: 0x00421380 — — CountActiveEntitiesByState
   next_func: 0x00421470 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 604: 0x0042382b — 0x00423890 (101 bytes)
   hex_head: 4d595448008b4424088b0085c053568bf07505be38a45e008b4c240c8b0185c07505b838a45e008a108a1e8aca3ad375
   prev_func: 0x004236f0 — — String/Hash Token Parsing (Quote-Delimited)
   next_func: 0x00423a00 — — Binary Search in String Table
   xrefs_into: none

GAP 605: 0x00429e9e — 0x00429eb0 (18 bytes)
   hex_head: 8bff5f9d4200a29c42000000000101010090
   prev_func: 0x00429470 — — AI Ability / Lap Ratio / Push Lap Update
   next_func: 0x00429eb0 — — Race-Phase Pit Entry Trigger
   xrefs_into: none

GAP 606: 0x0042bb37 — 0x0042bbd0 (153 bytes)
   hex_head: ff15a0e25900fdffffe80b000000e9360000009090909090905657bed8c65e00bf680000008d6424008bcee8b9ad0900
   prev_func: 0x0042b8d0 — — AI Shift Pattern / Upshifts-Downshifts Config
   next_func: 0x0042bbd0 — — Set Player Vehicle Index (DC)
   xrefs_into: none

GAP 607: 0x0042ce0a — 0x0042ce20 (22 bytes)
   hex_head: 9090909090906820ce4200e824ad150059c390909090
   prev_func: 0x0042ce00 — — Thunk
   next_func: 0x0042ce20 — — SessionType5Nullsub
   xrefs_into: none

GAP 608: 0x0042dbcb — 0x0042dbe0 (21 bytes)
   hex_head: 9090909090e80b000000e916000000909090909090
   prev_func: 0x0042db20 — — Game::Exit()
   next_func: 0x0042dbe0 — — Thunk to FUN_0042e320
   xrefs_into: none

GAP 609: 0x0042f2ef — 0x0042fd00 (2577 bytes)
   hex_head: 90558bec83e4f883ec148b550c568b75088bc66bc00b03c2c1e00683fa0a8d8408b00000000f871d010000ff249540f4
   prev_func: 0x0042f260 — — Setup Value Format with Offset
   next_func: 0x0042fd00 — — Vehicle Setup File Writer
   xrefs_into: none

GAP 610: 0x0043194a — 0x004319c0 (118 bytes)
   hex_head: 7ee8094dfdff51d94424088b410483f801dc25c8ea5900d95c24087529d9442408b838375c00dc25c0ea5900dc0db8ea
   prev_func: 0x00431930 — — SetContactConstraint
   next_func: 0x004319c0 — — Parameter Array Setter with Dirty Flag
   xrefs_into: none

GAP 611: 0x00431c58 — 0x00431c70 (24 bytes)
   hex_head: 909090909090909068701c4300e8d45e150059c390909090
   prev_func: 0x00431c00 — — PhysicsGlobalStateInit
   next_func: 0x00431c70 — — PhysicsShutdown
   xrefs_into: none

GAP 612: 0x004328b2 — 0x004328e0 (46 bytes)
   hex_head: 0ab838a45e00c20400e9a1ffffff8b0183c0088b0085c07505b838a45e00c3c0108b0085c05e7505b8e9d2ffffff
   prev_func: 0x00432870 — — Path String Combinator
   next_func: 0x004328e0 — — Path Accessor (*param_1)
   xrefs_into: none

GAP 613: 0x00435250 — 0x00435260 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x00435240 — — StateFlagCheck (inverse bool wrapper)
   next_func: 0x00435260 — — Thunk to FUN_00438c10
   xrefs_into: none

GAP 614: 0x0043b9d8 — 0x0043ba20 (72 bytes)
   hex_head: a2b943004eb9430066b94300b4b943007eb9430090b94300c6b94300d5b9430000070707070701020707070307070707
   prev_func: 0x0043b930 — — SolverDispatch (physics solver selector)
   next_func: 0x0043ba20 — — Constraint Force Solver
   xrefs_into: none

GAP 615: 0x00448d80 — 0x00448da0 (32 bytes)
   hex_head: 138944002b8944003b89440053894400638944007b8944009090909090909090
   prev_func: 0x00448730 — — Shadow Volume Extrusion
   next_func: 0x00448da0 — — CollisionTreeTraversal
   xrefs_into: none

GAP 616: 0x0044b8f1 — 0x0044b910 (31 bytes)
   hex_head: 8d490016b8440078b7440078b7440078b74400f3b644009090909090909090
   prev_func: 0x0044b370 — — Bezier Patch Tessellation
   next_func: 0x0044b910 — — Bounding Box Computation from Triangles
   xrefs_into: none

GAP 617: 0x0044c649 — 0x0044c660 (23 bytes)
   hex_head: 909090909090906860c64400e8e4b4130059c390909090
   prev_func: 0x0044c620 — — Collision State Init (Slot 1)
   next_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   xrefs_into: none

GAP 618: 0x0044c6c1 — 0x0044c6e0 (31 bytes)
   hex_head: c64400e8e4b4130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c6b0 — — CollisionDataTeardown (unregister)
   next_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   xrefs_into: none

GAP 619: 0x0044c769 — 0x0044c780 (23 bytes)
   hex_head: 909090909090906880c74400e8c4b3130059c390909090
   prev_func: 0x0044c740 — — CollisionGridInit4
   next_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   xrefs_into: none

GAP 620: 0x0044c7f0 — 0x0044c800 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c7d0 — — StringLogDeallocate
   next_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   xrefs_into: none

GAP 621: 0x0044c889 — 0x0044c8a0 (23 bytes)
   hex_head: 9090909090909068a0c84400e8a4b2130059c390909090
   prev_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   next_func: 0x0044c8c0 — — CollisionFrictionInit_8
   xrefs_into: none

GAP 622: 0x0044c901 — 0x0044c920 (31 bytes)
   hex_head: c84400e8a4b2130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c8f0 — — Thunk to FUN_00587b3e (Collision 5 init)
   next_func: 0x0044c920 — — Collision global init (single group with 1.0)
   xrefs_into: none

GAP 623: 0x0044c9a9 — 0x0044c9c0 (23 bytes)
   hex_head: 9090909090909068c0c94400e884b1130059c390909090
   prev_func: 0x0044c980 — — Collision Global Init (Set 10, -1.0f)
   next_func: 0x0044c9e0 — — Collision Global Struct Init (Block 0xB, unit default)
   xrefs_into: none

GAP 624: 0x0044ca21 — 0x0044ca40 (31 bytes)
   hex_head: c94400e884b1130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044ca10 — — Collision Static Data Registration (1)
   next_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   xrefs_into: none

GAP 625: 0x0044cac9 — 0x0044cae0 (23 bytes)
   hex_head: 9090909090909068e0ca4400e864b0130059c390909090
   prev_func: 0x0044cab4 — — Render State Float Initialization
   next_func: 0x0044cb00 — — Collision Subsystem Init (DAT_007ccfdc)
   xrefs_into: none

GAP 626: 0x0044cb44 — 0x0044cb74 (48 bytes)
   hex_head: e864b0130059c390909090c3e80b000000e936000000909090909090c70508d17c0068000000c7050cd17c0000000000
   prev_func: 0x0044cb30 — — CollisionGridFreeA
   next_func: 0x0044cb74 — — Input Handler Global Reset
   xrefs_into: none

GAP 627: 0x0044cbe9 — 0x0044cc00 (23 bytes)
   hex_head: 909090909090906800cc4400e844af130059c390909090
   prev_func: 0x0044cbd4 — — GlobalStateInitNegOne
   next_func: 0x0044cc20 — — Collision Globals Init #4 (DAT_007ca3b8)
   xrefs_into: none

GAP 628: 0x0044cc61 — 0x0044cc94 (51 bytes)
   hex_head: cc4400e844af130059c390909090c3e80b000000e936000000909090909090c705bcc97c001f000000c705c0c97c0000
   prev_func: 0x0044cc50 — — Collision Resource Release (Base)
   next_func: 0x0044cc94 — — Audio/Renderer Float Constant Initializer
   xrefs_into: none

GAP 629: 0x0044cd09 — 0x0044cd20 (23 bytes)
   hex_head: 909090909090906820cd4400e824ae130059c390909090
   prev_func: 0x0044cce0 — — Collision Material Init (Type 0x20)
   next_func: 0x0044cd40 — — CollisionGlobalsInit
   xrefs_into: none

GAP 630: 0x0044cd81 — 0x0044cdb4 (51 bytes)
   hex_head: cd4400e824ae130059c390909090c3e80b000000e936000000909090909090c705f8d07c0022000000c705fcd07c0000
   prev_func: 0x0044cd70 — — Collision Init Delegator (0xCD70)
   next_func: 0x0044cdb4 — — CollisionScaleInit
   xrefs_into: none

GAP 631: 0x0044ce29 — 0x0044ce40 (23 bytes)
   hex_head: 909090909090906840ce4400e804ad130059c390909090
   prev_func: 0x0044ce14 — — Global State Initializer
   next_func: 0x0044ce60 — — Global State Initializer (Collision Material 2)
   xrefs_into: none

GAP 632: 0x0044cea1 — 0x0044ced4 (51 bytes)
   hex_head: ce4400e804ad130059c390909090c3e80b000000e936000000909090909090c705f4cb7c0025000000c705f8cb7c0000
   prev_func: 0x0044ce90 — — RegisterInputDevice1
   next_func: 0x0044ced4 — — InitFloatConstants
   xrefs_into: none

GAP 633: 0x0044cf49 — 0x0044cf60 (23 bytes)
   hex_head: 909090909090906860cf4400e8e4ab130059c390909090
   prev_func: 0x0044cf34 — — Global State Initializer
   next_func: 0x0044cf80 — — Collision/Audio Init Block (Type 0x27)
   xrefs_into: none

GAP 634: 0x0044cfc1 — 0x0044cff4 (51 bytes)
   hex_head: cf4400e8e4ab130059c390909090c3e80b000000e936000000909090909090c705ecc97c0028000000c705f0c97c0000
   prev_func: 0x0044cfb0 — — ThunkCollisionInitB
   next_func: 0x0044cff4 — — Float/float init to (0, 1)
   xrefs_into: none

GAP 635: 0x0044d069 — 0x0044d080 (23 bytes)
   hex_head: 909090909090906880d04400e8c4aa130059c390909090
   prev_func: 0x0044d054 — — InitFloatGlobals
   next_func: 0x0044d0a0 — — Collision global init (single group with 1.0)
   xrefs_into: none

GAP 636: 0x0044d0e1 — 0x0044d100 (31 bytes)
   hex_head: d04400e8c4aa130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d0d0 — — Collision Sound Unregister (DAT)
   next_func: 0x0044d100 — — Collision Global Init (Set 0x6b, -1.0f)
   xrefs_into: none

GAP 637: 0x0044d189 — 0x0044d1a0 (23 bytes)
   hex_head: 9090909090909068a0d14400e8a4a9130059c390909090
   prev_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   next_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   xrefs_into: none

GAP 638: 0x0044d201 — 0x0044d220 (31 bytes)
   hex_head: d14400e8a4a9130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d1f0 — — Atexit Handler Registration (collision B)
   next_func: 0x0044d220 — — InitMouseAbsAxisY
   xrefs_into: none

GAP 639: 0x0044d2a9 — 0x0044d2c0 (23 bytes)
   hex_head: 9090909090909068c0d24400e884a8130059c390909090
   prev_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   next_func: 0x0044d2e0 — — CollisionGlobalsInit
   xrefs_into: none

GAP 640: 0x0044d321 — 0x0044d340 (31 bytes)
   hex_head: d24400e884a8130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d310 — — CollisionModuleRegister_B
   next_func: 0x0044d340 — — CollisionGlobalInitG
   xrefs_into: none

GAP 641: 0x0044d3c6 — 0x0044d3e0 (26 bytes)
   hex_head: 9090909090909090909068e0d34400e864a7130059c390909090
   prev_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   next_func: 0x0044d400 — — Spatial Node Init (index 14)
   xrefs_into: none

GAP 642: 0x0044d450 — 0x0044d460 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d430 — — Collision Resource Release +30
   next_func: 0x0044d460 — — Global State Initializer (Collision Set 1)
   xrefs_into: none

GAP 643: 0x0044d4e6 — 0x0044d500 (26 bytes)
   hex_head: 909090909090909090906800d54400e844a6130059c390909090
   prev_func: 0x0044d4c0 — — CollisionGridInit16x16
   next_func: 0x0044d520 — — CollisionStateInit_17
   xrefs_into: none

GAP 644: 0x0044d570 — 0x0044d580 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d550 — — Collision Init Delegator (0xD550)
   next_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   xrefs_into: none

GAP 645: 0x0044f00c — 0x0044f050 (68 bytes)
   hex_head: 90909090d9442404d81540e45900dfe0f6c4057a02d9e0d9442408d81540e45900dfe0f6c4057a02d9e0d9c9d9e0d999
   prev_func: 0x0044efe0 — — CollisionCullCleanup
   next_func: 0x0044f050 — — Collision Node Property Setter
   xrefs_into: none

GAP 646: 0x0044fa3f — 0x0044fa60 (33 bytes)
   hex_head: 90c2f94400c6f94400cdf94400d4f94400dbf94400e2f94400e9f94400f0f94400
   prev_func: 0x0044f8f0 — — D3D Texture Stage / Render Target Setup
   next_func: 0x0044fa60 — — DirectX Device Initialization
   xrefs_into: none

GAP 647: 0x00453293 — 0x004532d0 (61 bytes)
   hex_head: ebdbd90540e45900e9f6feffff56578db110240000bf2c0000008d49008b46f883ee0885c0740950e80f49130083c404
   prev_func: 0x004531a0 — — Memory Allocation / Large Struct Initializer
   next_func: 0x004532d0 — — AudioSceneUpdateLoop (sound parameter iteration)
   xrefs_into: none

GAP 648: 0x00455866 — 0x00455b30 (714 bytes)
   hex_head: 8bff9c554500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc56
   prev_func: 0x00455580 — ? Keyboard Scancode-to-ASCII
   next_func: 0x00455b30 — — TranslateVirtualKey
   xrefs_into: none

GAP 649: 0x00458de4 — 0x00459010 (556 bytes)
   hex_head: 00005b81c400050000c2080083ec3053568bf18d46188b088b50048b4008894424348a86a000000084c057894c243089
   prev_func: 0x004584c0 — — CollisionResponseFilter (contact velocity resolution)
   next_func: 0x00459010 — — Component Transform Initializer
   xrefs_into: none

GAP 650: 0x0045b2e4 — 0x0045b360 (124 bytes)
   hex_head: 83fb087eba5f5e5b83c424c3e80b000000e916000000909090909090b904d27c00e9860800009090909090906820b345
   prev_func: 0x0045b200 — — Game Main Entry / Initialization
   next_func: 0x0045b360 — — Short Computation (Constructor/Initializer)
   xrefs_into: none

GAP 651: 0x0045bb81 — 0x0045bbe0 (95 bytes)
   hex_head: 7d094283c15c83fa087ce28bc65ec356682c0300008bf1e866c0120083c40485c0740d8bc8e895ffffff89068bc65ec3
   prev_func: 0x0045bb60 — — ID to Color Mask Mapper
   next_func: 0x0045bbe0 — — Double Delegate Call
   xrefs_into: none

GAP 652: 0x0045bf3c — 0x0045bf50 (20 bytes)
   hex_head: 90909090e80b000000e916000000909090909090
   prev_func: 0x0045bf10 — — Wide Struct Zero-Init
   next_func: 0x0045bf50 — — Single Function Call Wrapper
   xrefs_into: none

GAP 653: 0x0045c064 — 0x0045c0a0 (60 bytes)
   hex_head: 0ac70564d27c0000000000c3e90b000000909090909090909090909068f853833f68805b5c0068745b5c00b970d27c00
   prev_func: 0x0045c030 — — Unknown (Struct Init with Float Defaults)
   next_func: 0x0045c0a0 — — Zero-Init 5-Float Struct
   xrefs_into: none

GAP 654: 0x0045d2cd — 0x0045d490 (451 bytes)
   hex_head: 9090908b44240883f802560f849901000083f8010f855b0100008b4c2408a2a0d27c00e87b6b100083f8030f87020100
   prev_func: 0x0045d260 — — Network/Replay Buffer Init
   next_func: 0x0045d490 — — Global Flag-Based State Setter
   xrefs_into: none

GAP 655: 0x0045e4ed — 0x0045e570 (131 bytes)
   hex_head: 8d4900dce44500edd94500bdda4500c7db450037dc4500dfd84500cbdc450036de450060de4500d1e145000be3450026
   prev_func: 0x0045d890 — — NetComm Session Message Dispatcher
   next_func: 0x0045e570 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 656: 0x00461c6e — 0x00461cc3 (85 bytes)
   hex_head: 9090566860ce01008bf1e8865f120083c40485c0740e568bc8e8a4b8ffff89068bc65ec333c089068bc65ec3c2e8b949
   prev_func: 0x00461900 — — SessionConfigWriteback
   next_func: 0x00461cd0 — — Session State Check
   xrefs_into: none

GAP 657: 0x00462de1 — 0x00462e00 (31 bytes)
   hex_head: 8d4900b12d4600b92d4600c12d4600c92d4600d12d46009090909090909090
   prev_func: 0x00462d30 — — Enum-to-Enum Translator
   next_func: 0x00462e00 — — Vehicle Name Accessor
   xrefs_into: none

GAP 658: 0x0046493a — 0x00464990 (86 bytes)
   hex_head: 9090909090906850494600e8f431120059c390909090b9a8d27c00e9a6060000909090909090e90b0000009090909090
   prev_func: 0x00464930 — — Single Function Call Wrapper
   next_func: 0x00464990 — — Short Computation / Squared Distance Between 3D Points
   xrefs_into: none

GAP 659: 0x00465c17 — 0x00465c30 (25 bytes)
   hex_head: 90ba554600c4554600ce554600d85546009090909090909090
   prev_func: 0x00465460 — — Entity Visibility Grid Manager
   next_func: 0x00465c30 — — Linked List Pop-Front
   xrefs_into: none

GAP 660: 0x00466114 — 0x00466140 (44 bytes)
   hex_head: 90909090909090909090909032c0c20400909090909090909090909032c0c20c00c0740750e8c0e9d1feffff
   prev_func: 0x00466090 — � UI Visual Struct Init
   next_func: 0x00466140 — — Short Computation (VTable Set + Init Calls)
   xrefs_into: none

GAP 661: 0x0046633f — 0x00466350 (17 bytes)
   hex_head: 908b49406a00e856250300c34d59544800
   prev_func: 0x00466300 — — State Initializer with Flag Check
   next_func: 0x00466350 — � Camera Yaw/Zoom Controller
   xrefs_into: none

GAP 662: 0x00466a2a — 0x00466a70 (70 bytes)
   hex_head: 1ae829fcf9ff8b44240c568bf18b4c240c50518bcee89cfeffff8b542408c70680f35900c786040100000000003fc686
   prev_func: 0x004669a0 — — Setup Value Display Formatter (No Guard)
   next_func: 0x00466a70 — — ConfigObjectDestructor
   xrefs_into: none

GAP 663: 0x0046712f — 0x00467260 (305 bytes)
   hex_head: 9003714600127146002b7146000000000000000000000000000202020202020202020202020202020202020202020101
   prev_func: 0x004670e0 — — Switch on Action ID → Virtual Call
   next_func: 0x00467260 — — Object Constructor with Parameter Setup
   xrefs_into: none

GAP 664: 0x0046808d — 0x004681b0 (291 bytes)
   hex_head: 909090568bf1e8f8dfffffc70668f65900c78628010000ffffffff8bc65ec390909090c78128010000ffffffffe8a1e0
   prev_func: 0x00467f90 — — HTML Output Section Processor
   next_func: 0x004681b0 — — VehicleSceneLoadAndPositionTires
   xrefs_into: none

GAP 665: 0x00468634 — 0x0046890d (729 bytes)
   hex_head: 90909090909090909090909081ec04010000a038a45e00568bf133c966894c2405884c2407b998e47c0088442404e8a9
   prev_func: 0x00468610 — Destructor sets vtable, frees child pointer at +0x174, calls
   next_func: 0x00468910 — — HTML Results Stats Page "World Championships:"
   xrefs_into: none

GAP 666: 0x00469852 — 0x00469872 (32 bytes)
   hex_head: 5e5bc20400b838a45ee9e8fcffff568bf1e8f83a0200508bcee870fbffff5ec3
   prev_func: 0x00469630 — — Setup File Load and Finalize
   next_func: 0x00469872 — — ObjectConstructor (corrupted frame)
   xrefs_into: none

GAP 667: 0x0046a24a — 0x0046a270 (38 bytes)
   hex_head: 00e809c4f9ff568bf1e818000000f644240801740956e86ad9110083c4048bc65ec204009090
   prev_func: 0x0046a220 — — Object Constructor with VTable
   next_func: 0x0046a270 — — VTable Set + Free + Call
   xrefs_into: none

GAP 668: 0x0046a9b5 — 0x0046ad50 (923 bytes)
   hex_head: 00c706e8f959e982ffffff56578bf18dbe0002000057e8b0ffffff8b86f40100008b0f6bc01c8988081b7d008b570489
   prev_func: 0x0046a980 — — ID Pair Match and Clear
   next_func: 0x0046ad50 — — Message/Name Buffer Update
   xrefs_into: none

GAP 669: 0x0046b9ac — 0x0046ba20 (116 bytes)
   hex_head: 90909090568bf1e8f8e20100c78678010000ffffffff833d10047d0005754868ccc45e0068a06a5c00b9c0c45e00e821
   prev_func: 0x0046b830 — � Session Timing Display
   next_func: 0x0046ba20 — � Vehicle Grid/Start Order Builder
   xrefs_into: none

GAP 670: 0x0046c7a6 — 0x0046cb00 (858 bytes)
   hex_head: 4081f910d67c007cefc38a44240484c0bab8d27c007505ba70d47c0033c933c056833c82ff7407414083f8687cf38b44
   prev_func: 0x0046c750 — — Array Shift/Remove by Index
   next_func: 0x0046cb00 — — Global Sign Check
   xrefs_into: none

GAP 671: 0x0046cecf — 0x0046d0d0 (513 bytes)
   hex_head: 905668ccc45e008bf168bc305c00b9c0c45e00e8196bfbff85c0741633c08d49008a88bc305c008888ccc45e004084c9
   prev_func: 0x0046cd20 — — CopyProfileIconBMP
   next_func: 0x0046d0d0 — — SessionCheckEndCondition
   xrefs_into: none

GAP 672: 0x0046e6ee — 0x0046e7f0 (258 bytes)
   hex_head: 9090568bf18b4e408b016a2cff501c85c074138bc8e818b2010085c07408508bcee8acfeffff33c05ec3c40001e9d2fe
   prev_func: 0x0046e600 — — Path Builder with Backslash
   next_func: 0x0046e7f0 — — Polling Loop with Branch
   xrefs_into: none

GAP 673: 0x0046fd4e — 0x00470190 (1090 bytes)
   hex_head: 9090518a81e400000032d23ac2c644240001741b833da4567c0006751f8b01885424008b54240052ff503833c059c3e8
   prev_func: 0x0046fd30 — — Destructor + Conditional Delete
   next_func: 0x00470190 — � Monitor Timing Display
   xrefs_into: none

GAP 674: 0x00470632 — 0x00470f20 (2286 bytes)
   hex_head: 0000c70608035a008be98afcffff5181b904030000b5010000c6442400017505c6442400008b44240083c40489442404
   prev_func: 0x00470490 — — Session Message/UI Command Handler
   next_func: 0x00470f20 — — Race/Session Mode Data Loader
   xrefs_into: none

GAP 675: 0x00472cf5 — 0x004735b0 (2235 bytes)
   hex_head: 8bc8e89f4600e9e5feffff566a028bf1e866930100c70600245a00c7861c030000000000008bc65ec390905356578bf1
   prev_func: 0x00472cc0 — — UI String Format + Display
   next_func: 0x004735b0 — — UI Frontend Counter Display Update
   xrefs_into: none

GAP 676: 0x0047455a — 0x004750f0 (2966 bytes)
   hex_head: 00e8f920f9ff566a018bf1e8f627ffff6aff68a4325c008bcec706403b5a00c7861c03000058fd7c00c7862403000003
   prev_func: 0x00474510 — � SessionEnter_Alt
   next_func: 0x004750f0 — � UI Object Init with Zero Fields
   xrefs_into: none

GAP 677: 0x00475ff3 — 0x00476030 (61 bytes)
   hex_head: 90a57c00e81df0fde987fdffffb990a57c00e8c6d2fdffb990a57c00e88cd3fdffb990a57c00e942d5fdff90908b0dc0
   prev_func: 0x00475d90 — — 2D Rectangle Drawing with Outline
   next_func: 0x00476030 — — UI Options Constructor (Graphics)
   xrefs_into: none

GAP 678: 0x00476359 — 0x004765f0 (663 bytes)
   hex_head: 9c04e957feffff81ec400200005355568bd957895c2414e85b8801008bb3f000000033ed3bf574258bfe8a470c84c08b
   prev_func: 0x00476250 — — Frontend Screen/Loading Display Handler
   next_func: 0x004765f0 — — LoadPath Getter
   xrefs_into: none

GAP 679: 0x00477079 — 0x00477280 (519 bytes)
   hex_head: 0000e902ffffff568bf1e8487b0100c6867c0100000033c05ec3ca83e103f3a45f5ee9d9ffffff8b917001000085d256
   prev_func: 0x00476fc0 — — Driver Name Copy from Global Array
   next_func: 0x00477280 — — Object Name Comparison
   xrefs_into: none

GAP 680: 0x00477ea0 — 0x00477f30 (144 bytes)
   hex_head: 568bf1e8d80201008d8e24010000e85d1c020083c8ff89865c010000c786580100000000000089861c01000089862001
   prev_func: 0x00477cb0 — — Profile Bitmap Browser
   next_func: 0x00477f30 — — ProfileIconBmpLoader
   xrefs_into: none

GAP 681: 0x00478ed0 — 0x00479170 (672 bytes)
   hex_head: 568bf18b865c01000085c07505b838a45e00578bf883c9ff33c0f2aef7d1495f742da1d0e57c0085c08bc87505b938a4
   prev_func: 0x00478e80 — Delegates to FUN_00499b80().
   next_func: 0x00479320 — — Hit Test / Bounds Check
   xrefs_into: none

GAP 682: 0x00479684 — 0x0047a080 (2556 bytes)
   hex_head: 5e5d5b81c428010000c204005668cdcc4c3f6a008bf1e841ffffffc706904b5a008bc65ec390909090909090b834e97c
   prev_func: 0x00479600 — — Value Bar Display Formatter
   next_func: 0x0047a080 — — Parameter value clamping across array
   xrefs_into: none

GAP 683: 0x0047abb3 — 0x0047b730 (2941 bytes)
   hex_head: 34d1100083c4048be9e4feffff83ec405355568bf18b86e00000008b2885ed577505bd38a45e008b4e40e84edb0100d8
   prev_func: 0x0047abb0 — — Return 0 Stub
   next_func: 0x0047b730 — — Menu Cursor Navigation Helper
   xrefs_into: none

GAP 684: 0x0047c6b6 — 0x0047c770 (186 bytes)
   hex_head: 4940e8ffa3e994fcffff568bf1e8e8d500006a008bcee8dfdc000033c05ec35d5b81c45c01e9d6ffffff566a018bf1e8
   prev_func: 0x0047c0d0 — — Object Init with VTable
   next_func: 0x0047c770 — — UI FPS/Performance Setting Display
   xrefs_into: none

GAP 685: 0x0047dbb7 — 0x0047dbe0 (41 bytes)
   hex_head: ff1518e05900fdffff568bf1e868af0000f644240801740956e8fa9f100083c4048bc65ec204009090
   prev_func: 0x0047d800 — � Season Stats Display (PrevYear/Drivers/Times)
   next_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   xrefs_into: none

GAP 686: 0x0047e4a6 — 0x0047e940 (1178 bytes)
   hex_head: cee80ea7000033c05ec381ec04010000a038a45e00568bf133c966894c240557884c240b8844240851b968c38a00e867
   prev_func: 0x0047e440 — � Circuit Info Page
   next_func: 0x0047e940 — Call FUN_00566650 if param_1 non-zero.
   xrefs_into: none

GAP 687: 0x0047ef75 — 0x0047eff0 (123 bytes)
   hex_head: 8d490093eb4700c1eb4700efeb47001dec47004bec470079ec4700a7ec4700d5ec470003ed470031ed47005bed470085
   prev_func: 0x0047ef3c — — Percentage Display Formatter
   next_func: 0x0047eff0 — — Short Computation (UI List Init)
   xrefs_into: none

GAP 688: 0x0047f43a — 0x0047fb10 (1750 bytes)
   hex_head: 9090909090905355568b742410578d7eff33db3bfb8be90f8cbb05000081fffc0100000f8daf050000399cbd1c190000
   prev_func: 0x0047f3f0 — — Destructor (3 sub-objects)
   next_func: 0x0047fb10 — � Destructor with List Cleanup and Conditional Free
   xrefs_into: none

GAP 689: 0x00485a65 — 0x00485a90 (43 bytes)
   hex_head: 0083c4045e8bc35bc20400568bf1e8c806fefff644240801740956e84a21100083c4048bc65ec204009090
   prev_func: 0x004859d0 — — LinkedListDtor
   next_func: 0x00485a90 — � Destructor with Two-Pointer Free
   xrefs_into: none

GAP 690: 0x004866db — 0x00486710 (53 bytes)
   hex_head: 4d595448008b442404398184000000741d8981840000008b01c7818000000000000000c744240401000000ff602cc204
   prev_func: 0x004866ad — — UI Widget Property Propagator
   next_func: 0x00486710 — — Byte Field Getter at +100
   xrefs_into: none

GAP 691: 0x004873de — 0x00487400 (34 bytes)
   hex_head: 8bff7373480045734800887348005e7348009d734800909090909090909090909090
   prev_func: 0x00487330 — — State-Dependent VTable Dispatch
   next_func: 0x00487400 — — UI State Change Dispatcher
   xrefs_into: none

GAP 692: 0x004876bb — 0x00487720 (101 bytes)
   hex_head: 90909090908b442404568bf1398684000000742a8a8ee200000084c975208986840000008b066a018bcec78680000000
   prev_func: 0x004876b0 — — Short Computation (Constructor)
   next_func: 0x00487720 — — Short Computation / State Value Transform
   xrefs_into: none

GAP 693: 0x00487f3b — 0x00488180 (581 bytes)
   hex_head: 90909090908b81840000003b442404741b8b1133c0898184000000898180000000c744240401000000ff622cc204008b
   prev_func: 0x00487f30 — — VTable Set + Cleanup
   next_func: 0x00488180 — — UI Text Display Constructor
   xrefs_into: none

GAP 694: 0x00488a1e — 0x00488a30 (18 bytes)
   hex_head: 9090e9abf9ffff9090909090909090909090
   prev_func: 0x004889d0 — — Short Computation / Frame Rate Ratio
   next_func: 0x00488a30 — — UIScrollWidgetUpdate
   xrefs_into: none

GAP 695: 0x00488fa9 — 0x004893c0 (1047 bytes)
   hex_head: fcffff5ec21000568bf1c706d0bc5a00e8f2cefffff644240801740956e804ec0f0083c4048bc65ec2040000c686e400
   prev_func: 0x00488f90 — Calls FUN_00485e30, sets vtable, sets byte flag at +0xE4 to 
   next_func: 0x004893c0 — — Unknown (Options Screen Init)
   xrefs_into: none

GAP 696: 0x0048a9e8 — 0x0048aa40 (88 bytes)
   hex_head: 9090909090909090e80bf3ffff33c0c3ff5b83e939f8ffff8b4424108b54240c508b44240c528b54240c5052e827f8ff
   prev_func: 0x0048a8d0 — — UI Scroll List Update
   next_func: 0x0048aa40 — — Object Init with Field Zeroing
   xrefs_into: none

GAP 697: 0x0048b5f4 — 0x0048b7e0 (492 bytes)
   hex_head: 00100000008981e953ffffff83ec14568bf18a86ec02000084c0750933c05e83c414c208008b4c24205733c033ff85c9
   prev_func: 0x0048b560 — — Unknown (Path/File Char Validator)
   next_func: 0x0048b7e0 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 698: 0x0048bbd6 — 0x0048c070 (1178 bytes)
   hex_head: 81f8020000e92afdffff568bf18b4e40e8e5bd00003bc68a86e0000000742284c0743e8a86e100000084c074346a008b
   prev_func: 0x0048b9c0 — — Text Input Render / Password Mask
   next_func: 0x0048c070 — � Constructor with Parameter Storage
   xrefs_into: none

GAP 699: 0x0048d095 — 0x0048d230 (411 bytes)
   hex_head: 0074068b0085e908fcffff568bf18b4e40e885b60000518bced91c24e84afaffff8b068bceff90ac00000033c05ec333
   prev_func: 0x0048ccb0 — â€” Scrollable UI List Rendering
   next_func: 0x0048d230 — — Linked List Destruction with VTable Call
   xrefs_into: none

GAP 700: 0x0048d6ab — 0x0048d740 (149 bytes)
   hex_head: 9090909090568bf18b4e40e8d580000085c08986ec00000074208b80c000000085c07505b838a45e00508bcee864b4ff
   prev_func: 0x0048d6a0 — — Short Computation / VTable Init + Call
   next_func: 0x0048d740 — — Large Zero-Init Constructor
   xrefs_into: none

GAP 701: 0x0048ddf5 — 0x0048df40 (331 bytes)
   hex_head: 908b016a00ffe9eaf9ffff83ec0856578bf1e81489ffff8bf88d44240c508d4c240c518b4e40e860aa000085ff0f84c5
   prev_func: 0x0048d9d0 — — Media Buffer Playback Manager
   next_func: 0x0048df40 — — UIWidgetDragHandler
   xrefs_into: none

GAP 702: 0x0048e33a — 0x0048e360 (38 bytes)
   hex_head: c4e81983f7ff568bf1e818000000f644240801740956e87a980f0083c4048bc65ec204009090
   prev_func: 0x0048e300 — — Short Computation (UI Widget Constructor)
   next_func: 0x0048e360 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 703: 0x0048e858 — 0x0048e890 (56 bytes)
   hex_head: 502c5fe9e9feffff568bf18b86e800000085c075138b4e40e8cb8500008b068bce5effa0a00000005ec301892a5d5b33
   prev_func: 0x0048e750 — — Viewport Rectangle Render Setup
   next_func: 0x0048e890 — — Resource Cleanup (Free + Zero)
   xrefs_into: none

GAP 704: 0x0048fb96 — 0x0048fc50 (186 bytes)
   hex_head: 0000e80ffde9c4ffffff56578bf98b8fe000000085c97457e8ddf9ffffe92adb10009068580200006a0068200300006a
   prev_func: 0x0048fb70 — — Short Computation (UI Widget Constructor)
   next_func: 0x0048fc50 — — UI Object Constructor
   xrefs_into: none

GAP 705: 0x0048febb — 0x0048fee0 (37 bytes)
   hex_head: 9090909090568bf18b8ee00000008b06518bceff50408bcee8c802000033c05ec390909090
   prev_func: 0x0048feb0 — — VTable + Sub-Init
   next_func: 0x0048fee0 — — UI Full Render with Dimensions
   xrefs_into: none

GAP 706: 0x00490326 — 0x00490450 (298 bytes)
   hex_head: 90909090909090909090568bf1e8e863ffff83f805771bff2485700349008b066a028bceff5040eb098b166a058bceff
   prev_func: 0x004902c0 — Free linked list nodes with vtable+0(1) notification on each
   next_func: 0x00490450 — — UIWidget_ProcessChildren
   xrefs_into: none

GAP 707: 0x00491e91 — 0x00491ee0 (79 bytes)
   hex_head: 56e85f5d0f0083c4048be9d9ffffffe90b000000909090909090909090909033c057b960000000bf70db7c00f3aba358
   prev_func: 0x00491e80 — General utility function. See decompiled code for exact beha
   next_func: 0x00491ee0 — — File Open Wrapper with Mode Check
   xrefs_into: none

GAP 708: 0x004945f0 — 0x00494600 (16 bytes)
   hex_head: e80b000000e926000000909090909090
   prev_func: 0x00494470 — — UI Destructor with Self-Free
   next_func: 0x00494600 — — Collision Global Zeroing
   xrefs_into: none

GAP 709: 0x004952d6 — 0x00495300 (42 bytes)
   hex_head: c95a00d91de9a3feffff568bf1e818000000f644240801740956e8da280f0083c4048bc65ec204009090
   prev_func: 0x00495190 — — Large Struct Zero-Init (Renderer Context)
   next_func: 0x00495300 — � Full Object Destructor with Multi-List Cleanup
   xrefs_into: none

GAP 710: 0x0049787b — 0x00497890 (21 bytes)
   hex_head: 90177849003078490049784900627849006c784900
   prev_func: 0x004977e0 — — Unknown (State Setter with Float Constant)
   next_func: 0x00497890 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 711: 0x00498d42 — 0x00498d90 (78 bytes)
   hex_head: d90c008b4c240c894e445ec208008a44240484c074158b41108b510c508b4108528b51045052e8e3020000c20400568b
   prev_func: 0x00498d20 — Calls init, sets vtable, calls post-init, stores param.
   next_func: 0x00498d90 — — Dual-List Destruction
   xrefs_into: none

GAP 712: 0x00499159 — 0x00499180 (39 bytes)
   hex_head: 085be9d1ffffff568bf1e818000000f644240801740956e85aea0e0083c4048bc65ec204009090
   prev_func: 0x00499140 — Call FUN_00498d20, set vtable.
   next_func: 0x00499180 — — Short Computation (VTable Set)
   xrefs_into: none

GAP 713: 0x00499516 — 0x00499580 (106 bytes)
   hex_head: 5052e800fee933fdffff568b714485f674148b068bceff90a40000008bb68c00000085f675ec33c05ec3568b714485f6
   prev_func: 0x004993d0 — — Render Dispatch with Iteration
   next_func: 0x00499580 — — Linked List Destroy (vtable destructor variant)
   xrefs_into: none

GAP 714: 0x00499bef — 0x00499c50 (97 bytes)
   hex_head: 908b44240450e8b6fffffff7d81bc040c204008b4e2c85c95e7405e946670b00c38b442408568bf18b08890e8b500489
   prev_func: 0x00499bb0 — — Struct Equality (7 Fields)
   next_func: 0x00499c50 — — Constructor: Init with -1 Sentinels
   xrefs_into: none

GAP 715: 0x0049a8fe — 0x0049a930 (50 bytes)
   hex_head: 8bffeaa54900efa5490072a64900dda6490048a74900afa7490016a84900f8a8490068a849009aa84900aca84900bca8
   prev_func: 0x0049a5a0 — — Dual Conditional Free
   next_func: 0x0049a930 — — Constructor with -1 Sentinels
   xrefs_into: none

GAP 716: 0x0049ad73 — 0x0049adb0 (61 bytes)
   hex_head: 08894e0c8946105ee9caffffff8b4424043b410c7c1b3b41107f168b4424083b41047c0d3b41087f08b801000000c208
   prev_func: 0x0049ad50 — � String/Path Processing
   next_func: 0x0049adb0 — — Short Computation (Field Getter at +0xc)
   xrefs_into: none

GAP 717: 0x0049afca — 0x0049afe0 (22 bytes)
   hex_head: 909090909090e80b000000e946000000909090909090
   prev_func: 0x0049afc0 — — CleanupCallbackRegister
   next_func: 0x0049afe0 — — Multi-Call Sequence
   xrefs_into: none

GAP 718: 0x0049b051 — 0x0049b070 (31 bytes)
   hex_head: 9090909090909090909090909090906870b04900e8d4ca0e0059c390909090
   prev_func: 0x0049b050 — — Empty Stub
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 719: 0x0049b66f — 0x0049b6d0 (97 bytes)
   hex_head: 9051d9442408568bf1e85fc50e0089442404db442404d80dbce95900e84cc50e008b4c24108b54241889442404db4424
   prev_func: 0x0049b630 — — SpatialGridCell
   next_func: 0x0049b6d0 — — Lap Time Gap Calculation
   xrefs_into: none

GAP 720: 0x0049d6ab — 0x0049d700 (85 bytes)
   hex_head: 90e8d54900e8d549009bd64900e8d54900e8d5490041d6490085d64900a7d6490073d6490090d6490052d6490052d649
   prev_func: 0x0049d5d0 — � HUD_TachoRenderDispatch
   next_func: 0x0049d700 — — Unknown (String Formatting Pipeline)
   xrefs_into: none

GAP 721: 0x0049f66d — 0x0049f6a0 (51 bytes)
   hex_head: 8d490063f549007ff549009df54900bbf54900d3f54900fcf54900fcf5490010f6490010f64900909090909090909090
   prev_func: 0x0049f530 — — ParamRangeClampedLerp
   next_func: 0x0049f6a0 — — String Format and Render
   xrefs_into: none

GAP 722: 0x004a0087 — 0x004a00a0 (25 bytes)
   hex_head: 9042004a0042004a0042004a0042004a0062004a0062004a00
   prev_func: 0x004a0030 — � Monitor Page Display
   next_func: 0x004a00a0 — � FIA Short Bink Video
   xrefs_into: none

GAP 723: 0x004a11bb — 0x004a11d0 (21 bytes)
   hex_head: e89954f6ffe80b000000e916000000909090909090
   prev_func: 0x004a11b0 — — Global Flag Clear
   next_func: 0x004a11d0 — — Wrapper (same as 0049afa0)
   xrefs_into: none

GAP 724: 0x004a192a — 0x004a1969 (63 bytes)
   hex_head: ffe8294df6ff68b101000068ecd05c006a02b95cd28a00e80a61030084c074126814d15c00685cd28a00e84761030083
   prev_func: 0x004a18d0 — — OSMan::Enter
   next_func: 0x004a1990 — — ObjectHandleReader
   xrefs_into: none

GAP 725: 0x004a1e55 — 0x004a1ea0 (75 bytes)
   hex_head: c023c1a3e8e2e955ffffff8b411485c07505b838a45e008b490485c97505b938a45e00568b7424085051683cd15c0056
   prev_func: 0x004a1e20 — Call FUN_00566650 three times with different params, then FU
   next_func: 0x004a1ea0 — — Reverse Dynamics Stub
   xrefs_into: none

GAP 726: 0x004a4810 — 0x004a4830 (32 bytes)
   hex_head: 04484a00ec474a00f2474a00f8474a00fe474a00909090909090909090909090
   prev_func: 0x004a47e0 — � Pit Service Type Name Lookup
   next_func: 0x004a4830 — — Tire Compound Name → ID Mapping
   xrefs_into: none

GAP 727: 0x004a6fc4 — 0x004a6fe0 (28 bytes)
   hex_head: c41ce9bed2ffff5e83c41cc3e80b000000e916000000909090909090
   prev_func: 0x004a6e50 — — Pit State Update Machine
   next_func: 0x004a6fe0 — � Single Call Wrapper
   xrefs_into: none

GAP 728: 0x004a8b47 — 0x004a8b80 (57 bytes)
   hex_head: ff1560e35900c204008bc133c9894804c74008ffffffffba5900000089480c895010894814895018c70014cc5a00c3ff
   prev_func: 0x004a8b30 — — Short Constructor
   next_func: 0x004a8b80 — — StaticInitBulk
   xrefs_into: none

GAP 729: 0x004ae46c — 0x004ae490 (36 bytes)
   hex_head: 46e44a0029df4a0097e04a0005e24a00f4e24a0098e34a00909090909090909090909090
   prev_func: 0x004adf10 — — Driving Mode Parameter Setup
   next_func: 0x004ae490 — — Car Part Visibility Controller
   xrefs_into: none

GAP 730: 0x004b0153 — 0x004b0170 (29 bytes)
   hex_head: 90bbf34a0024f84a0094fc4a0029ff4a00909090909090909090909090
   prev_func: 0x004af3a0 — — Physics Parameter Initialization
   next_func: 0x004b0170 — — Empty Stub (vtable slot)
   xrefs_into: none

GAP 731: 0x004b2055 — 0x004b20d0 (123 bytes)
   hex_head: 9090668b4116e959ffffff518b5424085332db85d2568bf174525783c9ff33c08bfaf2aef7d1495f74428d4424105052
   prev_func: 0x004b1fc0 — — UI Config Entry Serialization
   next_func: 0x004b20d0 — — Arithmetic/Comparison (Clamp with Bounds)
   xrefs_into: none

GAP 732: 0x004b21aa — 0x004b21c0 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004b21a0 — — SeasonScoringDBCallback
   next_func: 0x004b21c0 — — Single Call Wrapper
   xrefs_into: none

GAP 733: 0x004b3acf — 0x004b3af0 (33 bytes)
   hex_head: 908bc18d480489880cc00600898808c00600898804c00600c70000000000c39090
   prev_func: 0x004b3a90 — — Arithmetic/Comparison (Struct Copy with Header Size)
   next_func: 0x004b3af0 — — AdvanceRingBuffer
   xrefs_into: none

GAP 734: 0x004b419d — 0x004b41b0 (19 bytes)
   hex_head: 909090e80b000000e916000000909090909090
   prev_func: 0x004b4170 — — Render::Post()
   next_func: 0x004b41b0 — — Short Computation (Call Wrapper)
   xrefs_into: none

GAP 735: 0x004b45d8 — 0x004b46b0 (216 bytes)
   hex_head: 909090909090909068f0454b00e854350d0059c3909090908a0de0b68a00b00184c80f85ab00000053568b3500b78a00
   prev_func: 0x004b44e0 — â€” Fixed-Block Memory Pool Init
   next_func: 0x004b46b0 — — Struct Zero-Init (Three Regions)
   xrefs_into: none

GAP 736: 0x004b5be0 — 0x004b5c50 (112 bytes)
   hex_head: 8b44240483f8048981ac0900007745ff2485385c4b00c7817c0f0000abaa2a3ec20400c7817c0f00000000003ec20400
   prev_func: 0x004b5a30 — — DestroyUIWidgetHierarchy
   next_func: 0x004b5c50 — — Vehicle Instance List Builder
   xrefs_into: none

GAP 737: 0x004b67ac — 0x004b67d0 (36 bytes)
   hex_head: f3664b00fb664b0003674b000b674b0070674b0078674b0080674b0088674b0090909090
   prev_func: 0x004b66e0 — — Lap/Speed Comparison with Switch-Selectable Thresholds
   next_func: 0x004b67d0 — — Steering Alignment Tolerance Check
   xrefs_into: none

GAP 738: 0x004b7c60 — 0x004b7c80 (32 bytes)
   hex_head: e67b4b00f37b4b00f37b4b00f37b4b00077c4b00f37b4b009090909090909090
   prev_func: 0x004b7a90 — — Pit Timing Update
   next_func: 0x004b7c80 — — NetworkBufferRead
   xrefs_into: none

GAP 739: 0x004b97a9 — 0x004b97d0 (39 bytes)
   hex_head: c0010000c20c00568b3185f674108bcee872c2ffff56e80be40c0083c4045ec3c089068bc65ec3
   prev_func: 0x004b9780 — — Arithmetic/Comparison / Memory Allocation with Constructor
   next_func: 0x004b97d0 — — Thunk to FUN_004b7300
   xrefs_into: none

GAP 740: 0x004b9d87 — 0x004b9da0 (25 bytes)
   hex_head: 9090909090909090908b4424048b0950e8b4e3ffffc2040090
   prev_func: 0x004b9d80 — � Single Delegate (thunk to FUN_004b8140)
   next_func: 0x004b9da0 — — MenuActionDispatch
   xrefs_into: none

GAP 741: 0x004b9f90 — 0x004b9fa0 (16 bytes)
   hex_head: 83c108e918f8ffff9090909090909090
   prev_func: 0x004b9f70 — — Object Init
   next_func: 0x004b9fa0 — — Single Call Wrapper
   xrefs_into: none

GAP 742: 0x004bd782 — 0x004bd7d0 (78 bytes)
   hex_head: 000000005f5e5d5b83c42cc20400e80b000000e916000000909090909090b910b78a00e9e603000090909090909068c0
   prev_func: 0x004bd760 — — Sentinel Slot Fill
   next_func: 0x004bd7d0 — — 3-Field Init + Call
   xrefs_into: none

GAP 743: 0x004bec05 — 0x004bec55 (80 bytes)
   hex_head: 8b4424208da42400000000d98550030000d887a0010000d99fa00100008b34388b86c832000083f8ff0f84a702000085
   prev_func: 0x004beb10 — — AI Overtake / Collision Detection Loop
   next_func: 0x004bec55 — — EngineFailureCheck
   xrefs_into: none

GAP 744: 0x004c2c24 — 0x004c2c40 (28 bytes)
   hex_head: 909090909090909090909090ff413cc35f8bce5ee9bd01e936feffff
   prev_func: 0x004c2c20 — — Simple Counter Increment
   next_func: 0x004c2c40 — — Running Average Filter
   xrefs_into: none

GAP 745: 0x004c2fea — 0x004c3020 (54 bytes)
   hex_head: 9090909090906800304c00e8444b0c0059c390909090b96cc38a00e926190000909090909090e80b000000e916000000
   prev_func: 0x004c2fe0 — — Delegation
   next_func: 0x004c3020 — — Delegation Thunk
   xrefs_into: none

GAP 746: 0x004c48f2 — 0x004c4990 (158 bytes)
   hex_head: 10e870ebffff5d81c4e9c8fcffff33c0568bf18906c74604ffffffff89460889460c894610894614e8d10300008bc65e
   prev_func: 0x004c45d0 — — Vehicle Data Copy
   next_func: 0x004c4990 — — Vehicle Filtering/Selection
   xrefs_into: none

GAP 747: 0x004c7773 — 0x004c77d0 (93 bytes)
   hex_head: 908b4f38c1e91980e101888b671000008bcde876b3feff508bcbe85e0400008bcde8e7b3feff668983b04800008a573b
   prev_func: 0x004c73f0 — — Vehicle Physics Time Step
   next_func: 0x004c77d0 — — TireTemperatureSimStep
   xrefs_into: none

GAP 748: 0x004c7c5a — 0x004c7c70 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004c7c50 — — PhysicsVectorGetter
   next_func: 0x004c7c70 — — Passthrough
   xrefs_into: none

GAP 749: 0x004c81ee — 0x004c82c0 (210 bytes)
   hex_head: 90908bc133c9890889480489480889480c884810894814c740180000c842c39090905355568bd98b335733ff3bf7743c
   prev_func: 0x004c81a0 — — List Search with Global Match
   next_func: 0x004c82c0 — Call init functions, store global result, return success ind
   xrefs_into: none

GAP 750: 0x004c9339 — 0x004c94d0 (407 bytes)
   hex_head: 5e83e9c1ffffffa114ce5a0050e8c5fbffffc7014cce5a0033d289511c8951208951248bc1c390568bf1c7064cce5a00
   prev_func: 0x004c9310 — — Resource Release Triple Dispatch
   next_func: 0x004c94d0 — � Virtual Release Array (3 elements)
   xrefs_into: none

GAP 751: 0x004c9b7a — 0x004c9b90 (22 bytes)
   hex_head: 90909090909068909b4c00e8b4df0b0059c390909090
   prev_func: 0x004c9b70 — — Thunk to FUN_004ce820
   next_func: 0x004c9b90 — — Nullsub Wrapper for Render Object
   xrefs_into: none

GAP 752: 0x004cfc65 — 0x004cfc90 (43 bytes)
   hex_head: 8d4900aaf94c009ff94c00a3f94c00aff94c00000301010102020000009090909090909090909090909090
   prev_func: 0x004cf070 — — SpecialFX::Init
   next_func: 0x004cfc90 — — SpecialFX::Restart()
   xrefs_into: none

GAP 753: 0x004d0f09 — 0x004d1027 (286 bytes)
   hex_head: c40c5f5ec2080056578bf1e867caf3ff33d28996e00000008996e40000008996ec0000008996f00000008996f8000000
   prev_func: 0x004d0f00 — — Short Computation / Single Field Setter
   next_func: 0x004d1027 — — SetThisFromArg
   xrefs_into: none

GAP 754: 0x004d2448 — 0x004d24a0 (88 bytes)
   hex_head: 5900d95e0c5e59c38b0d9c325c0033c085c9567e398d49008b1485f0547c008bb26440000085f67407403bc17cea5ec3
   prev_func: 0x004d23d0 — — Pit Timer State Init
   next_func: 0x004d24a0 — � Check First Uninitialized Vehicle
   xrefs_into: none

GAP 755: 0x004d3cd4 — 0x004d3cf0 (28 bytes)
   hex_head: 693c4d006d3c4d00713c4d007d3c4d00713c4d009090909090909090
   prev_func: 0x004d37b0 — — TrackTemperatureDisplay
   next_func: 0x004d4580 — � Steward Update Main Dispatch
   xrefs_into: none

GAP 756: 0x004d48f6 — 0x004d4a58 (354 bytes)
   hex_head: 5ec2080033e9a1ffffffa1cc435d0085c0741a8b490485c974138b54240c528b54240c528b54240cffd0c20c0033c0c2
   prev_func: 0x004d48b0 — — Countdown Timer with Callback
   next_func: 0x004d4a58 — — Struct Field Initializer
   xrefs_into: none

GAP 757: 0x004d790b — 0x004d7920 (21 bytes)
   hex_head: e849edf2ffe80b000000e916000000909090909090
   prev_func: 0x004d7800 — — Texture/Surface Destroyer
   next_func: 0x004d7920 — — Single Function Call Wrapper
   xrefs_into: none

GAP 758: 0x004d7d79 — 0x004d7e00 (135 bytes)
   hex_head: 0100e967ffffffe80b000000e916000000909090909090b964d28a00e936fdffff90909090909068b07d4d00e894fd0a
   prev_func: 0x004d7cf0 — — Float Wrap + Table Interpolation
   next_func: 0x004d7e00 — — VTable Dispatch Chain
   xrefs_into: none

GAP 759: 0x004d89ca — 0x004d8a30 (102 bytes)
   hex_head: 89e889dcf2ff8bd183c8ff8902894204894208a134cf5a008982dc000000c682e000000001b80000803f8982e4000000
   prev_func: 0x004d8950 — Iterate arrays of interface pointers, call vtable+0(1) on ea
   next_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   xrefs_into: none

GAP 760: 0x004d90bb — 0x004d90d0 (21 bytes)
   hex_head: 9045904d004c904d0053904d005a904d0061904d00
   prev_func: 0x004d9030 — — Audio Resource Release by Type
   next_func: 0x004d90d0 — Renders a quad/triangle strip with colors using FUN_00553650
   xrefs_into: none

GAP 761: 0x004d9400 — 0x004d9420 (32 bytes)
   hex_head: f3934d00f3934d00f3934d00f3934d00f3934d00909090909090909090909090
   prev_func: 0x004d93e0 — — Range Check (1-5)
   next_func: 0x004d9420 — — StartingGridUIDraw
   xrefs_into: none

GAP 762: 0x004da83c — 0x004da990 (340 bytes)
   hex_head: 90909090568bf18b46105733ff2bc70f84f7000000480f84d4000000480f85260100008b462485c0751a57b9e0ce8a00
   prev_func: 0x004da820 — — State Block Initializer (7 fields)
   next_func: 0x004da990 — � Vehicle Count by Threshold
   xrefs_into: none

GAP 763: 0x004db0b9 — 0x004db0e0 (39 bytes)
   hex_head: 03b0e9d9fdffff8b411040894110992bc2d1f889411433c0c35ec204009033c08941e9d9ffffff
   prev_func: 0x004db0b0 — — InitTwoFieldsToZero
   next_func: 0x004db0e0 — — Small Struct Constructor
   xrefs_into: none

GAP 764: 0x004db5c6 — 0x004db6f0 (298 bytes)
   hex_head: cee80e00000033c05ec3a1a4567c0083f80756578b7c240c8bf17743ff248538b64d00578bcee89f0600006882000000
   prev_func: 0x004db550 — Conditional dispatch based on DAT_007d0474, compute and disp
   next_func: 0x004db6f0 — — Position/Order Name Display
   xrefs_into: none

GAP 765: 0x004dc2b7 — 0x004dc340 (137 bytes)
   hex_head: 00e83d2fe9c6ffffffe80b000000e916000000909090909090b9b4d38a00e926b7080090909090909068f0c24d00e854
   prev_func: 0x004dc290 — — Fixed Node Allocator
   next_func: 0x004dc340 — — Alignment/Position Switch
   xrefs_into: none

GAP 766: 0x004ddf4c — 0x004ddf70 (36 bytes)
   hex_head: 47dc4d0056dc4d0065dc4d0074dc4d0083dc4d0092dc4d00a1dc4d00b0dc4d00bfdc4d00
   prev_func: 0x004ddad0 — â€” Pit Crew Instance Setup
   next_func: 0x004ddf70 — — Zero-Init Wrapper
   xrefs_into: none

GAP 767: 0x004e169a — 0x004e16c0 (38 bytes)
   hex_head: 8bff240f4e0072114e006c134e0047164e0030104e00cc104e00000100010100009090909090
   prev_func: 0x004e0ed0 — — Audio/Sound Effect Controller
   next_func: 0x004e16c0 — Reads 6 fields from param_1 and passes to FUN_0054b4d0.
   xrefs_into: none

GAP 768: 0x004e44f2 — 0x004e45b0 (190 bytes)
   hex_head: d999e0000000ddd883e9c4feffff53568bf1578d4e08e8132a01008d8ee4060000e898b6ffff8d8ec0320000e89d03fc
   prev_func: 0x004e43d0 — — Unidentified Logic (Physics Integration with Clamp/ABS)
   next_func: 0x004e45b0 — — Large Config Function with Physics Constants
   xrefs_into: none

GAP 769: 0x004ed35d — 0x004ed380 (35 bytes)
   hex_head: 8d49006fd24e00c9d24e00d7d24e0032d34e0000000000010203030303030303039090
   prev_func: 0x004ed250 — — Repair/Service State Dispatcher
   next_func: 0x004ed380 — — AnisoVectorTripleProduct
   xrefs_into: none

GAP 770: 0x004f0d0e — 0x004f0d20 (18 bytes)
   hex_head: 8bff8e074f0075044f00a1044f008f0b4f00
   prev_func: 0x004f0430 — � Vehicle Setup Init / Per-Frame Update
   next_func: 0x004f0d20 — � Camera FOV / Zoom by Proximity
   xrefs_into: none

GAP 771: 0x004f3471 — 0x004f3490 (31 bytes)
   hex_head: 8d490083324f00d9324f002f334f0086334f00dd334f0027344f0090909090
   prev_func: 0x004f3240 — For each axis direction (param_3 0-5), validates that force 
   next_func: 0x004f3490 — — Arithmetic/Comparison (ABS-Vector Load)
   xrefs_into: none

GAP 772: 0x004f6b79 — 0x004f6bf0 (119 bytes)
   hex_head: 9090909090909068906b4f00e8b40f090059c3909090905657beecf88a00bf2d0000008d6424008b46ec83ee1485c074
   prev_func: 0x004f6b40 — — Tire/Grip Data Array Init (Rear)
   next_func: 0x004f6bf0 — â€” RPM Range Loader (Per Gear)
   xrefs_into: none

GAP 773: 0x004f82f2 — 0x004f8330 (62 bytes)
   hex_head: 8bffbc824f00d7824f00ee824f0000000000000202020202020201010101010101010102020202020202020202020202
   prev_func: 0x004f8280 — — Color/Palette Lookup by Index
   next_func: 0x004f8330 — — Arithmetic/Comparison (Rate Computation with Clamp)
   xrefs_into: none

GAP 774: 0x004fa7b8 — 0x004fa7e0 (40 bytes)
   hex_head: 90a64f0090a64f0090a64f0090a64f0090a64f00a3a64f00cba64f00cba64f009090909090909090
   prev_func: 0x004fa640 — — VidMan::Restart
   next_func: 0x004fac00 — — VidMan::Post()
   xrefs_into: none

GAP 775: 0x004fb9ef — 0x004fba10 (33 bytes)
   hex_head: 9028b94f003ab94f0048b94f0056b94f0068b94f007ab94f008cb94f0096b94f00
   prev_func: 0x004fb8f0 — — Callback Registration
   next_func: 0x004fbd70 — — Camera/Viewport Render Setup
   xrefs_into: none

GAP 776: 0x004ff0d7 — 0x004ff127 (80 bytes)
   hex_head: d999b000e953ffffffd94120d81d40e45900dfe0f6c4447a06b802000000c3d94124d81d40e45900dfe0f6c4447a06b8
   prev_func: 0x004ff040 — — ValueClampRange (clamp two values with min bound)
   next_func: 0x004ff127 — — Render Object Field Setter
   xrefs_into: none

GAP 777: 0x0050c28c — 0x0050c2a6 (26 bytes)
   hex_head: 6a01e8143c0000ff25ec775d006a01e8073c0000ff25dc775d00
   prev_func: 0x0050c27f — — Startup Call Wrapper
   next_func: 0x0050c2a6 — — DirectX Call Wrapper
   xrefs_into: none

GAP 778: 0x0050ecf9 — 0x0050ed19 (32 bytes)
   hex_head: b7eb500019ec50001cec50001fec500023ec500026ec500029ec50002dec5000
   prev_func: 0x0050eb73 — � Skeleton Animation Blending
   next_func: 0x0050ed19 — — Quaternion Normalize
   xrefs_into: none

GAP 779: 0x00517569 — 0x005176ec (387 bytes)
   hex_head: 8b4424088b54240c8b4c2404d900d80ad900d84a08d900d84a04d900d84a0cd9cbd94004d84a10d94004d84a18d94004
   prev_func: 0x00517534 — — Mat2x2Mul
   next_func: 0x005176ec — — Vector Normalize (Fast rsqrt)
   xrefs_into: none

GAP 780: 0x0051ed91 — 0x0051edae (29 bytes)
   hex_head: 908db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ecee — — 4x4 matrix × 4-vector transform
   next_func: 0x0051edae — — Normalized Vector with Threshold (Physics)
   xrefs_into: none

GAP 781: 0x0051f0a8 — 0x0051f0be (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ef5e — — SSE 4x4 Matrix Multiply
   next_func: 0x0051f0be — — SSE 3D Cross Product with 3×3 Matrix
   xrefs_into: none

GAP 782: 0x0051f974 — 0x0051f98e (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051f89e — — PlaneFromThreePoints
   next_func: 0x0051f98e — — 4x4 reflection/orientation matrix multiply
   xrefs_into: none

GAP 783: 0x0051fea4 — 0x0051febe (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051fd90 — — Rotation matrix to axis-angle conversion
   next_func: 0x0051febe — — Quaternion Construction/Transform (SSE)
   xrefs_into: none

GAP 784: 0x00520133 — 0x0052014e (27 bytes)
   hex_head: 8db6000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052004e — — 3×4 Matrix Transform with SSE
   next_func: 0x0052014e — — SSE 4x4 Matrix × 4-Vector Multiply
   xrefs_into: none

GAP 785: 0x00520416 — 0x0052042e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052035e — — VectorNormalizeThreshold
   next_func: 0x0052042e — — Velocity/Friction Clamp with Stiction Threshold
   xrefs_into: none

GAP 786: 0x00520866 — 0x0052087e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x005207ce — — SSEVectorCross
   next_func: 0x0052087e — — SSEVectorMatrixInit
   xrefs_into: none

GAP 787: 0x00520a64 — 0x00520a7e (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052098e — — PlaneFromEdgesNormalizeSSE
   next_func: 0x00520a7e — — QuaternionToRotationMatrix
   xrefs_into: none

GAP 788: 0x00520ec1 — 0x00520fc6 (261 bytes)
   hex_head: 908db426000000008dbc27000000008b54240c8b4424080f6f120f6f5a080f7fd40f7fdd0f6f000f6ae20f6aeb0f6f48
   prev_func: 0x00520e0e — — SSE Quaternion Composition from Axis-Angle Components
   next_func: 0x00520fc6 — � SSE 3D Vector Normalization with Length
   xrefs_into: none

GAP 789: 0x00526b35 — 0x00526b55 (32 bytes)
   hex_head: 70695200c5695200d9695200ed6952000c6a52001d6a52003c6a52005b6a5200
   prev_func: 0x0052692f — — Matrix Interpolation/Blend
   next_func: 0x00526b55 — — 3DNow Vector Transform
   xrefs_into: none

GAP 790: 0x00527ec5 — 0x00527eed (40 bytes)
   hex_head: f9775200c378520024795200147a5200e37a5200617c5200027d5200737e5200be7e5200aa7d5200
   prev_func: 0x005276c5 — � Multi-Block Memory Allocator
   next_func: 0x00527eed — — [PARTIAL] Unknown
   xrefs_into: none

GAP 791: 0x005292e9 — 0x005295e0 (759 bytes)
   hex_head: 8da424000000008da424000000008da424000000008bffe8fbfeffff0f6e0d0c945d000f0fc1b4c38da424000000008d
   prev_func: 0x00529200 — — Empty Stub
   next_func: 0x005295e0 — — Packed Floating-Point Math (3DNow!)
   xrefs_into: none

GAP 792: 0x0052c5e9 — 0x0052d214 (3115 bytes)
   hex_head: e8d7fcffff5ec310d45a00000000000c0000800000000010d45a00010000000c0100800000000010d45a00020000000c
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 793: 0x0052d96c — 0x0052d990 (36 bytes)
   hex_head: 909090908b0985c974128b4424088b5424045052e8cb090000c2080033c0c20800909090
   prev_func: 0x0052d8d0 — — Threaded Object Creator with SEH
   next_func: 0x0052d990 — — Virtual Cleanup
   xrefs_into: none

GAP 794: 0x0052e051 — 0x0052e080 (47 bytes)
   hex_head: 9090909090909090909090909090906870e05200e8d49a050059c390909090a108018b0085c07405e9f220f8ffc390
   prev_func: 0x0052df90 — Checks CPU feature flags via cpuid instruction.
   next_func: 0x0052e080 — — 64-bit Integer Division
   xrefs_into: none

GAP 795: 0x0052e567 — 0x0052e577 (16 bytes)
   hex_head: e80b0000008bc65ec3e90b0000009090
   prev_func: 0x0052e550 — — Bounds-Checked Byte Setter
   next_func: 0x0052e577 — — BufferInitZero
   xrefs_into: none

GAP 796: 0x00531147 — 0x00531250 (265 bytes)
   hex_head: 90a40c5300b50c5300c70c5300d90c5300eb0c5300fd0c53000f0d5300210d5300330d5300450d5300570d5300690d53
   prev_func: 0x00530840 — � Bitstream Texture Decompression
   next_func: 0x00531250 — — Texture Decompression (Variable-Length Code Decoder)
   xrefs_into: none

GAP 797: 0x00536fc3 — 0x00536ff0 (45 bytes)
   hex_head: 0f94c05d5b8d44000183c410c38b4424045052e87d3b050083c408c20400909090909090909090909090909090
   prev_func: 0x00536e90 — — [PARTIAL] Unknown
   next_func: 0x00536ff0 — — Allocator Free Wrapper
   xrefs_into: none

GAP 798: 0x0053ad08 — 0x0053ad50 (72 bytes)
   hex_head: ff1550e059000400568bf18d4e04e8851500006a10c70610895b00e8dbce04006a10894610e8d1ce04006a40894620e8
   prev_func: 0x0053acf0 — — Thin wrapper, drops a1
   next_func: 0x0053ad50 — � Multi-Field Free + Cleanup
   xrefs_into: none

GAP 799: 0x0053b3db — 0x0053b490 (181 bytes)
   hex_head: e879b2ecff8b0183e001fec8f6d81bc040c390909051d9413cd94138d9c0d8c9d9c2d8cbdec1d9fad95c2400ddd8ddd8
   prev_func: 0x0053b3b0 — — Identity 4×4 Matrix Init
   next_func: 0x0053b490 — — Identity Function
   xrefs_into: none

GAP 800: 0x0053c110 — 0x0053c140 (48 bytes)
   hex_head: 8b4424048b4c2408d94008d84908d94004d84904dec1d900d809dec1c2080090e80b000000e916000000909090909090
   prev_func: 0x0053c102 — — Float Store from x87 ST(2)
   next_func: 0x0053c140 — Call FUN_00556220.
   xrefs_into: none

GAP 801: 0x0053c20a — 0x0053c2a0 (150 bytes)
   hex_head: 9090909090906820c25300e824b9040059c3909090908a0de58e8b00b00184c875120ac8880de58e8b00b9a0788b00e9
   prev_func: 0x0053c200 — — Delegation Wrapper
   next_func: 0x0053c2a0 — — Global Zero Init
   xrefs_into: none

GAP 802: 0x0054074d — 0x00540760 (19 bytes)
   hex_head: 8d4900e60654004f0654000001000000000090
   prev_func: 0x005404d0 — — 2D Surface Blit/Fill
   next_func: 0x00540760 — � Multi-List Destructor with Virtual Release
   xrefs_into: none

GAP 803: 0x00545b8a — 0x00545bb0 (38 bytes)
   hex_head: 90909090909081a1ec000000ff7fffffc390909090908189ec00000000800000c3e8a90aecff
   prev_func: 0x00545a40 — � Visible Object List Collection
   next_func: 0x00545bb0 — — Scene Instance Collection
   xrefs_into: none

GAP 804: 0x005471af — 0x005471c0 (17 bytes)
   hex_head: 90537154006a7154008171540098715400
   prev_func: 0x00547140 — — Indexed Field Copy
   next_func: 0x005471c0 — — Simple Setter (+0xb0)
   xrefs_into: none

GAP 805: 0x0054a1a6 — 0x0054a1c0 (26 bytes)
   hex_head: 9090909090909090909033c08981a80100008981a4010000c390
   prev_func: 0x0054a160 — — Flag Bit Setter (0x1000/0x2000)
   next_func: 0x0054a1c0 — � Bitmask Global Set/Clear
   xrefs_into: none

GAP 806: 0x0054ea88 — 0x0054eaa0 (24 bytes)
   hex_head: ff15fce359005dc3e80b000000e926000000909090909090
   prev_func: 0x0054e270 — — Bounding-Box Computation from Vertex Data
   next_func: 0x0054eaa0 — Call FUN_00548e00() 1024 (0x400) times.
   xrefs_into: none

GAP 807: 0x0054fd1d — 0x0054fd30 (19 bytes)
   hex_head: 8d49000efd5400fbfc5400e8fc5400d5fc5400
   prev_func: 0x0054fcc0 — — Unidentified Logic (Render/Format Mode Set)
   next_func: 0x0054fd30 — — Short Computation / Struct Field Double-Setter
   xrefs_into: none

GAP 808: 0x00551db3 — 0x00551dd0 (29 bytes)
   hex_head: 90381d55003f1d5500461d55004d1d5500909090909090909090909090
   prev_func: 0x00551cf0 — — Bink Video Frame Render
   next_func: 0x00551dd0 — — Bink Video Frame Decoder
   xrefs_into: none

GAP 809: 0x00553039 — 0x00553050 (23 bytes)
   hex_head: 8d49002f305500253055001b3055001130550007305500
   prev_func: 0x00552ff0 — — Switch-Based Parameter Field Set with Flags
   next_func: 0x00553050 — — Two-Field Setter
   xrefs_into: none

GAP 810: 0x005542af — 0x005542f0 (65 bytes)
   hex_head: 90944255007342550078425500874255008c42550091425500aa425500aa425500aa425500aa425500aa425500aa4255
   prev_func: 0x00554260 — — Enum-to-Field-Offset Setter
   next_func: 0x005542f0 — @ 0x005542f0
   xrefs_into: none

GAP 811: 0x00555e3e — 0x00555e50 (18 bytes)
   hex_head: 8bff845255009b525500b0525500f0525500
   prev_func: 0x005550e0 — @ 0x005550e0 — 3422 bytes
   next_func: 0x00556040 — — Graphics/Display State Sync with Vehicle
   xrefs_into: none

GAP 812: 0x0055685a — 0x0055687b (33 bytes)
   hex_head: 558bec83c4fcdbe366c745fe5a5add7dfe668b45fe3c007504b001eb02b000c9c3
   prev_func: 0x005567f5 — @ 0x005567f5 — 101 bytes
   next_func: 0x0055687b — — RDTSC Timestamp Read
   xrefs_into: none

GAP 813: 0x0055be5e — 0x0055be80 (34 bytes)
   hex_head: 9090a1288f8b005051b9a0788b00e8df9fffffc204007cf25ec2040033e998ffffff
   prev_func: 0x0055be20 — � String Copy + Field Reader (Void)
   next_func: 0x0055be80 — @ 0x0055be80
   xrefs_into: none

GAP 814: 0x0055eeaf — 0x0055ef24 (117 bytes)
   hex_head: 558bec5657505351528b75088b7d0c8b4510d900d80ed94004d80ed94008d80ed94010d84e04d94014d84e04d94018d8
   prev_func: 0x0055ee20 — (0x0055ee20)
   next_func: 0x0055ef24 — — 3x3 Matrix × Float3 Vector Multiply
   xrefs_into: none

GAP 815: 0x00561dff — 0x00561e30 (49 bytes)
   hex_head: 90568bf185f675068b35fc4d5e008bcee8bc0000008bce5ee9140000009090909085c975068b0dfc4d5e00e901000000
   prev_func: 0x00561d40 — @ 0x00561d40
   next_func: 0x00561e30 — — NetworkPacketReceive
   xrefs_into: none

GAP 816: 0x00563f0f — 0x00563f70 (97 bytes)
   hex_head: 90d03e5600d73e5600de3e5600e53e56008b4c24088b15b4468d008b442404568b098b92800000008b30576a00e8ef05
   prev_func: 0x00563ec0 — — Switch Param Store + Global Set
   next_func: 0x00563f70 — — Physics Sign/Direction Function
   xrefs_into: none

GAP 817: 0x0056459d — 0x00564600 (99 bytes)
   hex_head: 9090908b09e90900000090909090909090909053568bf15733ff8bda8a0684c0741d0fbec050e89d6e020069ffe76c30
   prev_func: 0x00564580 — — Audio Mixer Sample Get with Fallback
   next_func: 0x00564600 — — IndirectDwordCompare
   xrefs_into: none

GAP 818: 0x005679a5 — 0x005679b7 (18 bytes)
   hex_head: 74108b4c240485c97e088b40044985c075f4
   prev_func: 0x005679a0 — Null-check wrapper: returns 0 if param_1 is null, otherwise 
   next_func: 0x005679c0 — — String-Keyed Linked List Search
   xrefs_into: none

GAP 819: 0x00574010 — 0x00575863 (6227 bytes)
   hex_head: 8b44240483f8270f87d1110000ff2485f1515700d9e8dd1df0fb8c00d9eedd1db8fc8c00d9eedd1d80fd8c00d9eedd1d
   prev_func: 0x0056fa96 — — Block LDL^T Sparse Constraint Factorization
   next_func: 0x00575875 — — Enum value check (== 34)
   xrefs_into: none

GAP 820: 0x00579fa0 — 0x00579fb0 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x00579f89 — @ 0x00579f89 — 23 bytes
   next_func: 0x00579fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 821: 0x0057a127 — 0x0057a160 (57 bytes)
   hex_head: 04005e32c05bc204008a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8e4
   prev_func: 0x0057a0f0 — — Byte-Aligned Memory Copy with Offset
   next_func: 0x0057a160 — Constructor with vtable assignment and init call.
   xrefs_into: none

GAP 822: 0x0057a94a — 0x0057a980 (54 bytes)
   hex_head: 9090909090906860a95700e8e4d1000059c390909090b9f53b8d00e92ae00100909090909090e80b000000e916000000
   prev_func: 0x0057a940 — — Thunk to FUN_00598815
   next_func: 0x0057a980 — — Entity Constructor Wrapper
   xrefs_into: none

GAP 823: 0x0057aa1a — 0x0057aa50 (54 bytes)
   hex_head: 9090909090906830aa5700e814d1000059c390909090b9fa3b8d00e916010000909090909090e80b000000e926000000
   prev_func: 0x0057aa10 — — Single Function Call Wrapper
   next_func: 0x0057aa50 — @ 0x0057aa50
   xrefs_into: none

GAP 824: 0x0057ad6f — 0x0057adb0 (65 bytes)
   hex_head: 908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8a4cd000059c3909090
   prev_func: 0x0057acb0 — ```
   next_func: 0x0057adb0 — � Single Delegation Call
   xrefs_into: none

GAP 825: 0x0057ae3a — 0x0057ae70 (54 bytes)
   hex_head: 9090909090906850ae5700e8f4cc000059c390909090b9193c8d00e93adb0100909090909090e80b000000e916000000
   prev_func: 0x0057ae30 — — [PARTIAL] Unknown
   next_func: 0x0057ae70 — — Single Function Call Wrapper (to constructor)
   xrefs_into: none

GAP 826: 0x0057b17a — 0x0057b230 (182 bytes)
   hex_head: ccccccff15ff8b41185685c0570f848e0000008b74240c8b1085d27404393274118b400485c075ef5fb8010000005ec2
   prev_func: 0x0057b100 — — Linked-List Buffer Manager Destructor
   next_func: 0x0057b230 — — IntSetInsert
   xrefs_into: none

GAP 827: 0x0057b6ca — 0x0057b780 (182 bytes)
   hex_head: cc00004bcc0051568bf18b4c24108d442404578b7c24105051578bcec744241400000000e87debffff8b542408668b8e
   prev_func: 0x0057b6c0 — — Setter at +0x24
   next_func: 0x0057b780 — — Object Init with VTable + Field Set
   xrefs_into: none

GAP 828: 0x0057ca07 — 0x0057cb50 (329 bytes)
   hex_head: e35900b0015ec2080083ec6c8b4424708d54242cc644242c002bd08a08880c024084c975f6538d442430686c3f5c0050
   prev_func: 0x0057c950 — — Thread-Safe Linked-List Lookup with Mutex + Data Copy
   next_func: 0x0057d5d0 — — Structured Memory Copy with Header Prepend
   xrefs_into: none

GAP 829: 0x0057d84d — 0x0057d890 (67 bytes)
   hex_head: 8d4900ded7570001d85700fad75700a6d75700ecd75700f3d757000fd85700e5d7570008d857003cd857000009090909
   prev_func: 0x0057d660 — — Buffer Unpack with Size Check + Byte/Word Copy
   next_func: 0x0057d890 — — Sound Play Dispatch with State Change Check
   xrefs_into: none

GAP 830: 0x0057f158 — 0x0057fb90 (2616 bytes)
   hex_head: ff153ce35900ffff568bf15733ff8b86f40a000085c074308b8ef80a00005150ff15a0e1590085c074073d8000000075
   prev_func: 0x0057f0c8 — — NetworkSocketAddressInit
   next_func: 0x0057fb90 — — WinsockInit
   xrefs_into: none

GAP 831: 0x0058122c — 0x00581600 (980 bytes)
   hex_head: 909090908b814006000053568db12406000032db85c0741a8b4e205150ff15a0e1590085c074073d8000000075048bce
   prev_func: 0x0058119a — — Network File Transfer Accept Handler
   next_func: 0x00581600 — — Network Buffer Search (Mutex-Protected Linked List)
   xrefs_into: none

GAP 832: 0x00582331 — 0x00582360 (47 bytes)
   hex_head: 0800000000c7450c0000e9c4ffffff8a410884c0740d8b0985c974078b016a01ff5004c37407c7461000e9d1ffffff
   prev_func: 0x00582310 — — CloseHandle Wrapper
   next_func: 0x00582360 — — Win32 Mutex Create/Recreate
   xrefs_into: none

GAP 833: 0x005834b4 — 0x00583530 (124 bytes)
   hex_head: 89460489460889e914ffffff51568b3185f6894c2404743e55578bee8b76048a450884c0741d8b7d0085ff74168b0f85
   prev_func: 0x00583430 — ```
   next_func: 0x00583530 — — Zero-Fill Memory Region with Step
   xrefs_into: none

GAP 834: 0x0058543e — 0x00585470 (50 bytes)
   hex_head: 9090568bf18d8e2c010000e8422400008b4c24083bc87e0a8986800000005ec20400898e800000005ec20400cc0000cc
   prev_func: 0x00585400 — — VTable Dispatch with Conditional Branch
   next_func: 0x00585470 — (0x00585470)
   xrefs_into: none

GAP 835: 0x00585df3 — 0x00585e80 (141 bytes)
   hex_head: 8115a4e159008bc7e9daffffffe80b000000e916000000909090909090b92d3e8d00e9fb29010090909090909068305e
   prev_func: 0x00585de0 — — QueueUserAPC Async Procedure Call
   next_func: 0x00585e80 — — Index-to-Bitmask Conversion
   xrefs_into: none

GAP 836: 0x00586634 — 0x00586670 (60 bytes)
   hex_head: 89460489460889e997feffff8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa47
   prev_func: 0x00586620 — — Node Destruction with Virtual Call
   next_func: 0x00586670 — (0x00586670)
   xrefs_into: none

GAP 837: 0x00586eda — 0x00586f10 (54 bytes)
   hex_head: 90909090909068f06e5800e8540c000059c390909090b9313e8d00e99a1a0100909090909090e80b000000e916000000
   prev_func: 0x00586ed0 — — Thunk to FUN_00598815
   next_func: 0x00586f10 — — Single Function Call Wrapper
   xrefs_into: none

GAP 838: 0x005873a3 — 0x00587460 (189 bytes)
   hex_head: 08005e8ac35d5b83c408c208008a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa
   prev_func: 0x00587370 — — Copy Buffer Header Fields + Call Init
   next_func: 0x00587460 — � Array/Struct Alloc with Count + Init
   xrefs_into: none

GAP 839: 0x005876ca — 0x005876f0 (38 bytes)
   hex_head: 90909090909068e0765800e86404000059c390909090b9383e8d00e9ef230100909090909090
   prev_func: 0x005876c0 — — Single Function Call Wrapper
   next_func: 0x005876f0 — — Buffered Char I/O Init
   xrefs_into: none

GAP 840: 0x00587a9a — 0x00587ac0 (38 bytes)
   hex_head: 90909090909068b07a5800e89400000059c390909090b93c3e8d00e91f200100909090909090
   prev_func: 0x00587a90 — — Single Function Call Wrapper
   next_func: 0x00587ac0 — @ 0x00587ac0 — 126 bytes
   xrefs_into: none

GAP 841: 0x00589584 — 0x005895a2 (30 bytes)
   hex_head: d9c9833d443e8d00017404d9f8eb05e8247d00009bdfe09b9e7ae7ddd9c3
   prev_func: 0x0058957a — — Interrupt Dispatch
   next_func: 0x005895a2 — (0x005895a2)
   xrefs_into: none

GAP 842: 0x0058bd29 — 0x0058bd8f (102 bytes)
   hex_head: 8b4424048a15d86b5e008a0884c9740c3aca74088a48014084c975f48a084084c9742a8a0884c9740d80f965740880f9
   prev_func: 0x0058bccf — ```
   next_func: 0x0058bd8f — � CRT __fassign
   xrefs_into: none

GAP 843: 0x0058d857 — 0x0058d9be (359 bytes)
   hex_head: eb0233c0e992f3ffffc68570fffffffe0aed754bd9c9d9f1eb0dc68570fffffffe32edd9eadec9e83b010000d9e8dec1
   prev_func: 0x0058d849 — — Read 2-Byte Value from Stream Pointer
   next_func: 0x0058d9be — — x87 pow(2,x) / exp2 via f2xm1
   xrefs_into: none

GAP 844: 0x0059067e — 0x00590703 (133 bytes)
   hex_head: 558bec81c430fdffff539bd9bd5cffffff833dd09a5e0000741be8d3d3ffff808d38fdffff0180a538fdfffffde85a00
   prev_func: 0x00590640 — — __cintrindisp2 (MSVC CRT Internal)
   next_func: 0x00590703 — @ 0x00590703
   xrefs_into: none

GAP 845: 0x00591629 — 0x0059163b (18 bytes)
   hex_head: e88efcffffc3e840ffffffc3d9f3c3d9f2c3
   prev_func: 0x00591574 — — Double-Precision Float Classification
   next_func: 0x0059163b — If DAT_005e9ad0==0: calls FUN_00591bf1; else errno 0x21
   xrefs_into: none

GAP 846: 0x00597303 — 0x00597321 (30 bytes)
   hex_head: 68bd725900ff1584e05900a3e4418d00c3ff35e4418d00ff1584e05900c3
   prev_func: 0x005972bd — � Exception/Error Filter with Magic Comparison
   next_func: 0x00597321 — — IsBadReadPtr Wrapper
   xrefs_into: none

GAP 847: 0x005992d3 — 0x005992ef (28 bytes)
   hex_head: 568bf1e85efbfffff644240801740756e8e7e8feff598bc65ec20400
   prev_func: 0x005992b7 — — Destructor with Flag Cleanup
   next_func: 0x005992ef — Realloc if needed; validate; _memset fill; null-terminate
   xrefs_into: none

GAP 848: 0x0059a38d — 0x0059a3a9 (28 bytes)
   hex_head: 568bf1e8dcfafffff644240801740756e82dd8feff598bc65ec20400
   prev_func: 0x0059a371 — Call FUN_00599d17 then conditionally free param_1 based on p
   next_func: 0x0059a3a9 — — Stream Creation with Flag Init
   xrefs_into: none

GAP 849: 0x0059ad07 — 0x0059ad31 (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x0059ac7f — — Object Teardown with Iterator Cleanup
   next_func: 0x0059ad31 — — Thunk
   xrefs_into: none

GAP 850: 0x0059bffd — 0x0059c0ac (175 bytes)
   hex_head: cccccc8b44240c85c074448b54240456578bf28b7c24100bd783e2037432a901000000740b8a0e3a0f7552464748741d
   prev_func: 0x0059bfc3 — — __CxxThrowException_8
   next_func: 0x0059c0ac — @ 0x0059c0ac
   xrefs_into: none

GAP 851: 0x0059ca73 — 0x0059ca8b (24 bytes)
   hex_head: cccccccccccccccccccccccccc8d8df4feffffe9d5dfedff
   prev_func: 0x0059ca69 — — C++ Exception Handler Wrapper
   next_func: 0x0059ca8b — — CxxFrameHandlerWrapper
   xrefs_into: none

GAP 852: 0x0059cb3d — 0x0059d6a9 (2924 bytes)
   hex_head: cccccc8b4dece92867feff8b4df0e9304dfeffb858ac5b00e926d8feffcccccccccccc8b4dece9f867feff8b4df0e970
   prev_func: 0x0059cb33 — — C++ Exception Handler Wrapper
   next_func: 0x0059d6a9 — — Null-Checked Call Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_C.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
