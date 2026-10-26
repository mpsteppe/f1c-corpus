# WORKER P — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker P of 20, items 643–684.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_P.md

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

GAP 643: 0x0040721b — 0x004072e0 (197 bytes)
   hex_head: 4d5954480083ec0c83c1588b018b510489442400d94424008b41088b4c2410d91989542404d94424048b542414d91a89
   prev_func: 0x004071f0 — — Audio Sample Position/Volume Setter
   next_func: 0x004072e0 — — Miles Sound System Sample Allocator
   xrefs_into: none

GAP 644: 0x0040b25a — 0x0040b410 (438 bytes)
   hex_head: 89e8f9b3ffff83ec1c568bf18b0657ff50148b46148b560c8b0d88fe8a008d3c80c1e705680020000003fae8d6ee1300
   prev_func: 0x0040b030 — — Static Camera Scene Loader
   next_func: 0x0040b410 — — ListContains160ByteElement
   xrefs_into: none

GAP 645: 0x0040ee9e — 0x0040eec0 (34 bytes)
   hex_head: 8bff31ed400031ed400031ed400031ed400031ed400031ed4000bfed4000eaed4000
   prev_func: 0x0040ed10 — ? Spatial Distance Query
   next_func: 0x0040eec0 — Processes float parameters through math functions based on a
   xrefs_into: none

GAP 646: 0x00413efa — 0x00414010 (278 bytes)
   hex_head: 8bffb93b4100c33b4100cd3b4100d73b4100e13b4100eb3b4100f53b4100ff3b4100093c4100133c41001d3c4100273c
   prev_func: 0x00413b60 — — Season-Specific Team ID Lookup
   next_func: 0x00414010 — — Enum Value Translation (Resource IDs)
   xrefs_into: none

GAP 647: 0x0041f037 — 0x0041f070 (57 bytes)
   hex_head: ff1554e25900ffffff568bf1b9b02d7d00e803380a008bc8e87c210a0085c07e0a85f674068b4486145ec383c8ff5ec3
   prev_func: 0x0041efe0 — — Count Matching Season Entries
   next_func: 0x0041f070 — — Relative Performance Comparator
   xrefs_into: none

GAP 648: 0x0042cde1 — 0x0042ce00 (31 bytes)
   hex_head: 008b0485f0547c00a3e0547c005ec3e80b000000e916000000909090909090
   prev_func: 0x0042caa0 — — AI Lateral Force Computation
   next_func: 0x0042ce00 — — Thunk
   xrefs_into: none

GAP 649: 0x0043526a — 0x00435290 (38 bytes)
   hex_head: 9090909090906880524300e8c428150059c390909090b928747c00e9163a0000909090909090
   prev_func: 0x00435260 — — Thunk to FUN_00438c10
   next_func: 0x00435290 — — FloatEpsilonCompare
   xrefs_into: none

GAP 650: 0x0044c7f0 — 0x0044c800 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c7d0 — — StringLogDeallocate
   next_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   xrefs_into: none

GAP 651: 0x0044cba2 — 0x0044cbd4 (50 bytes)
   hex_head: 4400e804b0130059c390909090c3e80b000000e936000000909090909090c70588d17c0069000000c7058cd17c000000
   prev_func: 0x0044cb90 — — CollisionModuleRegister_A
   next_func: 0x0044cbd4 — — GlobalStateInitNegOne
   xrefs_into: none

GAP 652: 0x0044cf61 — 0x0044cf94 (51 bytes)
   hex_head: cf4400e844ac130059c390909090c3e80b000000e936000000909090909090c70580a47c0027000000c70584a47c0000
   prev_func: 0x0044cf50 — — Deferred Callback Registration (Collision)
   next_func: 0x0044cf94 — — Audio Mixer Gain Init
   xrefs_into: none

GAP 653: 0x0044d321 — 0x0044d340 (31 bytes)
   hex_head: d24400e884a8130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d310 — — CollisionModuleRegister_B
   next_func: 0x0044d340 — — CollisionGlobalInitG
   xrefs_into: none

GAP 654: 0x00452666 — 0x004526c0 (90 bytes)
   hex_head: 8bff6719450067194500cf194500c9194500c919450077194500a919450089194500b919450099194500611a4500fd25
   prev_func: 0x00451720 — — Driver Input Controller
   next_func: 0x004526c0 — — Array Destructor via Virtual Dispatch
   xrefs_into: none

GAP 655: 0x0045c75e — 0x0045c780 (34 bytes)
   hex_head: 90908b4424048b4c24080fbf000fbf112bc2c3905e5d8ac35b81c48837e9cbfeffff
   prev_func: 0x0045c750 — — Wrapper with Constant
   next_func: 0x0045c780 — — Bounded Byte Array Accessor
   xrefs_into: none

GAP 656: 0x00466114 — 0x00466140 (44 bytes)
   hex_head: 90909090909090909090909032c0c20400909090909090909090909032c0c20c00c0740750e8c0e9d1feffff
   prev_func: 0x00466090 — � UI Visual Struct Init
   next_func: 0x00466140 — — Short Computation (VTable Set + Init Calls)
   xrefs_into: none

GAP 657: 0x00469dcd — 0x0046a220 (1107 bytes)
   hex_head: 909090568bf18b4e40e855e90200d88674010000d99674010000d81d00e85900dfe0f6c441752f8b867801000033c983
   prev_func: 0x00469d30 — — Player Stats Display Cleanup
   next_func: 0x0046a220 — — Object Constructor with VTable
   xrefs_into: none

GAP 658: 0x00470230 — 0x004702f0 (192 bytes)
   hex_head: 566a006a016a006a006a006a008bf1e8dcb10100c70650025a008bc65ec39090568bf1e888b20100f644240801740956
   prev_func: 0x00470190 — � Monitor Timing Display
   next_func: 0x004702f0 — — Short Computation (VTable Set)
   xrefs_into: none

GAP 659: 0x00477ea0 — 0x00477f30 (144 bytes)
   hex_head: 568bf1e8d80201008d8e24010000e85d1c020083c8ff89865c010000c786580100000000000089861c01000089862001
   prev_func: 0x00477cb0 — — Profile Bitmap Browser
   next_func: 0x00477f30 — — ProfileIconBmpLoader
   xrefs_into: none

GAP 660: 0x0047ee94 — 0x0047ef3c (168 bytes)
   hex_head: a134f17c0083f8050f8785000000ff2485d0ef470068e8745c008bcbe88bfaffff33c05f5e5b83c420c368586e5c008b
   prev_func: 0x0047ee5c — — InitFromDataBlock
   next_func: 0x0047ef3c — — Percentage Display Formatter
   xrefs_into: none

GAP 661: 0x004881a4 — 0x004881f0 (76 bytes)
   hex_head: 908b01ff90a800000033c0c3568bf18d8ee0000000e8921901008bcee8ebdcfffff644240801740956e8fdf90f0083c4
   prev_func: 0x00488180 — — UI Text Display Constructor
   next_func: 0x004881f0 — � Surface Render Region Setup
   xrefs_into: none

GAP 662: 0x0048d6ab — 0x0048d740 (149 bytes)
   hex_head: 9090909090568bf18b4e40e8d580000085c08986ec00000074208b80c000000085c07505b838a45e00508bcee864b4ff
   prev_func: 0x0048d6a0 — — Short Computation / VTable Init + Call
   next_func: 0x0048d740 — — Large Zero-Init Constructor
   xrefs_into: none

GAP 663: 0x00490635 — 0x00490660 (43 bytes)
   hex_head: 909090909090e955fcffff568bf18b066a00ff50408bce5ee90e0000009090909090909090909090909090
   prev_func: 0x00490550 — — PanelMouseInteractionHandler
   next_func: 0x00490660 — Iterates linked list, calling vtable method on each node bas
   xrefs_into: none

GAP 664: 0x0049964b — 0x00499660 (21 bytes)
   hex_head: 4d59544800e80b000000e916000000909090909090
   prev_func: 0x00499620 — — Short Computation (Destructor — Double Free Check)
   next_func: 0x00499660 — — Short Computation / Single Call Wrapper
   xrefs_into: none

GAP 665: 0x0049d6ab — 0x0049d700 (85 bytes)
   hex_head: 90e8d54900e8d549009bd64900e8d54900e8d5490041d6490085d64900a7d6490073d6490090d6490052d6490052d649
   prev_func: 0x0049d5d0 — � HUD_TachoRenderDispatch
   next_func: 0x0049d700 — — Unknown (String Formatting Pipeline)
   xrefs_into: none

GAP 666: 0x004a5311 — 0x004a5330 (31 bytes)
   hex_head: 8d49003b524a0031524a0027524a001d524a00909090909090909090909090
   prev_func: 0x004a4ed0 — Also handles: SHADOWOBJECT, LODOUT, LODIN, MESHFILE (level-o
   next_func: 0x004a5330 — — Pit Part State Copy
   xrefs_into: none

GAP 667: 0x004b3d2e — 0x004b3d40 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x004b3ce0 — — Random/Noise Value Generator
   next_func: 0x004b3d40 — — Single Function Call Wrapper
   xrefs_into: none

GAP 668: 0x004b9d87 — 0x004b9da0 (25 bytes)
   hex_head: 9090909090909090908b4424048b0950e8b4e3ffffc2040090
   prev_func: 0x004b9d80 — � Single Delegate (thunk to FUN_004b8140)
   next_func: 0x004b9da0 — — MenuActionDispatch
   xrefs_into: none

GAP 669: 0x004c6917 — 0x004c6960 (73 bytes)
   hex_head: d85f5e8be9e9feffff568bf1e858d5f5ff8bcec78694480000ffffffffe8a7100000568bcee8ffd6f5ff8bc65ec38974
   prev_func: 0x004c6810 — — MergeSortLinkedList
   next_func: 0x004c6960 — — TeamIDSetter
   xrefs_into: none

GAP 670: 0x004d21ee — 0x004d2210 (34 bytes)
   hex_head: 8bffe8214d00eb214d00000000000001010101909090909090909090909090909090
   prev_func: 0x004d21d0 — � Race Phase Check
   next_func: 0x004d2210 — — Pit Close: Team Ready Check
   xrefs_into: none

GAP 671: 0x004d90bb — 0x004d90d0 (21 bytes)
   hex_head: 9045904d004c904d0053904d005a904d0061904d00
   prev_func: 0x004d9030 — — Audio Resource Release by Type
   next_func: 0x004d90d0 — Renders a quad/triangle strip with colors using FUN_00553650
   xrefs_into: none

GAP 672: 0x004dfbaa — 0x004dfca0 (246 bytes)
   hex_head: 41e8a96af2ff53568bf1578d4e04e893feffffc7869000000000000000c78694000000ffffffff8dbed4000000bb0400
   prev_func: 0x004dfb90 — � 26-Byte Zero-Init
   next_func: 0x004dfca0 — — Dual Array Destructor Loop + Free
   xrefs_into: none

GAP 673: 0x004f8cfa — 0x004f8d10 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004f8cf0 — — Nullsub Wrapper
   next_func: 0x004f8d10 — — Delegation Thunk
   xrefs_into: none

GAP 674: 0x0051ed91 — 0x0051edae (29 bytes)
   hex_head: 908db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ecee — — 4x4 matrix × 4-vector transform
   next_func: 0x0051edae — — Normalized Vector with Threshold (Physics)
   xrefs_into: none

GAP 675: 0x00520972 — 0x0052098e (28 bytes)
   hex_head: 8db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x005208fe — — SSE Matrix Construction from 4×4 Data
   next_func: 0x0052098e — — PlaneFromEdgesNormalizeSSE
   xrefs_into: none

GAP 676: 0x0052d9c6 — 0x0052d9f0 (42 bytes)
   hex_head: 47348b450c5f5e5bc9c3568bf1e8d8fffffff644240801740956e8eaa1050083c4048bc65ec204009090
   prev_func: 0x0052d9b0 — — C++ Constructor (VTable Setup)
   next_func: 0x0052d9f0 — — Object VTable Initialization
   xrefs_into: none

GAP 677: 0x0053c110 — 0x0053c140 (48 bytes)
   hex_head: 8b4424048b4c2408d94008d84908d94004d84904dec1d900d809dec1c2080090e80b000000e916000000909090909090
   prev_func: 0x0053c102 — — Float Store from x87 ST(2)
   next_func: 0x0053c140 — Call FUN_00556220.
   xrefs_into: none

GAP 678: 0x0054ee72 — 0x0054ee90 (30 bytes)
   hex_head: 8bff54eb5400f7eb540084ec540001ed540082ed5400faed540090909090
   prev_func: 0x0054eb40 — — 2D/3D Triangle Point Test
   next_func: 0x0054ee90 — Computes 2D cross product (perp dot product) of two vectors.
   xrefs_into: none

GAP 679: 0x0055c62d — 0x0055c650 (35 bytes)
   hex_head: 8d4900a9c4550076c4550099c45500ccc45500efc45500efc455009090909090909090
   prev_func: 0x0055c450 — (0x0055c450)
   next_func: 0x0055c650 — @ 0x0055c650
   xrefs_into: none

GAP 680: 0x00579fa0 — 0x00579fb0 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x00579f89 — @ 0x00579f89 — 23 bytes
   next_func: 0x00579fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 681: 0x0057b2e4 — 0x0057b330 (76 bytes)
   hex_head: c4045fb8010000005ec204008b54240485d27c273b51247d228b411885d27e0c85c074178b40044a85d27ff485c0740b
   prev_func: 0x0057b2e0 — Returns field at param_1+0x24.
   next_func: 0x0057b330 — — Network Connection List Duplication
   xrefs_into: none

GAP 682: 0x00584c27 — 0x00584c70 (73 bytes)
   hex_head: 90fa425800734458005e455800be46580071475800084c5800474858006f485800ed48580020495800994958004e4a58
   prev_func: 0x00584130 — ```
   next_func: 0x00584c70 — — Thread-Safe Call with Mutex
   xrefs_into: none

GAP 683: 0x00587a9a — 0x00587ac0 (38 bytes)
   hex_head: 90909090909068b07a5800e89400000059c390909090b93c3e8d00e91f200100909090909090
   prev_func: 0x00587a90 — — Single Function Call Wrapper
   next_func: 0x00587ac0 — @ 0x00587ac0 — 126 bytes
   xrefs_into: none

GAP 684: 0x00598815 — 0x00598994 (383 bytes)
   hex_head: b818d25900e8b91dffff51515356894dec33f68d4df08975f0e81a1d00003935f49e5e007c0aff05f49e5e0032dbeb0c
   prev_func: 0x0059880b — — PhysicsThunk
   next_func: 0x00598994 — — Ref Count Decrement with Cleanup
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_P.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
