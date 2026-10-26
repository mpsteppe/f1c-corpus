# WORKER O — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker O of 20, items 601–642.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_O.md

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

GAP 601: 0x004071c5 — 0x004071f0 (43 bytes)
   hex_head: 74068b0885c975e45e5bc333c089417c898180000000898184000000e95a0b000090909090909090909090
   prev_func: 0x004070e0 — — Spatial Query with Weighted Distance Selection
   next_func: 0x004071f0 — — Audio Sample Position/Volume Setter
   xrefs_into: none

GAP 602: 0x0040ac1a — 0x0040ac40 (38 bytes)
   hex_head: 5de839baffff568bf1e818000000f644240801740956e89acf170083c4048bc65ec204009090
   prev_func: 0x0040ac00 — Initializes a 6-dword struct with vtable, zeroing all fields
   next_func: 0x0040ac40 — — VTable Switch
   xrefs_into: none

GAP 603: 0x0040e83a — 0x0040e860 (38 bytes)
   hex_head: 8bffcbe74000dae74000dae74000dae74000dae74000dae74000909090909090909090909090
   prev_func: 0x0040e770 — — Short Computation / Session Update Dispatch
   next_func: 0x0040e860 — — short computation
   xrefs_into: none

GAP 604: 0x004132e2 — 0x004133b0 (206 bytes)
   hex_head: 8bff7f2e4100952e4100ab2e4100c12e4100d72e4100ed2e4100032f4100192f41002f2f4100452f41005b2f4100712f
   prev_func: 0x00412e50 — â€” DirectInput Scancode Mapping
   next_func: 0x004133b0 — — Text Attribute Lookup (Format 0)
   xrefs_into: none

GAP 605: 0x0041c53a — 0x0041d630 (4342 bytes)
   hex_head: ffe819a1feffa108037d0083ec2c85c053560f84a3090000d905c8f37c00d81d40e45900dfe0f6c4440f8b8c09000083
   prev_func: 0x0041c4c0 — — Position-based Message Display
   next_func: 0x0041d630 — — Race Commentary / Best Lap Tracking
   xrefs_into: none

GAP 606: 0x0042c631 — 0x0042c690 (95 bytes)
   hex_head: 8d490093c44200a9c44200bdc44200d3c44200e9c44200fcc442000dc5420020c5420030c5420043c5420054c542006a
   prev_func: 0x0042c3b0 — — DynMan::Restart()
   next_func: 0x0042c690 — — Main Game Tick Update
   xrefs_into: none

GAP 607: 0x00435250 — 0x00435260 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x00435240 — — StateFlagCheck (inverse bool wrapper)
   next_func: 0x00435260 — — Thunk to FUN_00438c10
   xrefs_into: none

GAP 608: 0x0044c7c9 — 0x0044c7e0 (23 bytes)
   hex_head: 9090909090909068e0c74400e864b3130059c390909090
   prev_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   next_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   xrefs_into: none

GAP 609: 0x0044cb89 — 0x0044cba0 (23 bytes)
   hex_head: 9090909090909068a0cb4400e8a4af130059c390909090
   prev_func: 0x0044cb74 — — Input Handler Global Reset
   next_func: 0x0044cbc0 — — CollisionGlobalInitF
   xrefs_into: none

GAP 610: 0x0044cf49 — 0x0044cf60 (23 bytes)
   hex_head: 909090909090906860cf4400e8e4ab130059c390909090
   prev_func: 0x0044cf34 — — Global State Initializer
   next_func: 0x0044cf80 — — Collision/Audio Init Block (Type 0x27)
   xrefs_into: none

GAP 611: 0x0044d309 — 0x0044d320 (23 bytes)
   hex_head: 909090909090906820d34400e824a8130059c390909090
   prev_func: 0x0044d2f4 — — InitRenderConstantsZeroOne
   next_func: 0x0044d340 — — CollisionGlobalInitG
   xrefs_into: none

GAP 612: 0x004516a0 — 0x00451720 (128 bytes)
   hex_head: 680645003b07450075084500ae0945004e0c4500e50e4500c51045009f1145003a13450099104500e21345000d144500
   prev_func: 0x0044ff50 — â€” Audio Channel Initialization
   next_func: 0x00451720 — — Driver Input Controller
   xrefs_into: none

GAP 613: 0x0045c064 — 0x0045c0a0 (60 bytes)
   hex_head: 0ac70564d27c0000000000c3e90b000000909090909090909090909068f853833f68805b5c0068745b5c00b970d27c00
   prev_func: 0x0045c030 — — Unknown (Struct Init with Float Defaults)
   next_func: 0x0045c0a0 — — Zero-Init 5-Float Struct
   xrefs_into: none

GAP 614: 0x00465fe5 — 0x00466080 (155 bytes)
   hex_head: 90909090909090909090906800604600e8441b120059c390909090a160d47c0085c0740750e8c01b120059c3005f5d5e
   prev_func: 0x00465fd0 — — Collision Distance Reset
   next_func: 0x00466080 — Forward param_1 to FUN_00566650.
   xrefs_into: none

GAP 615: 0x004698bc — 0x00469900 (68 bytes)
   hex_head: 90909090568bf18b868001000085c0740950e8fce2110083c4048bcee863fb0100f644240801740956e8e5e2110083c4
   prev_func: 0x00469880 — — UI Dialog/Property Page Constructor
   next_func: 0x00469900 — � Individual Race Results HTML Writer
   xrefs_into: none

GAP 616: 0x0046fd4e — 0x00470190 (1090 bytes)
   hex_head: 9090518a81e400000032d23ac2c644240001741b833da4567c0006751f8b01885424008b54240052ff503833c059c3e8
   prev_func: 0x0046fd30 — — Destructor + Conditional Delete
   next_func: 0x00470190 — � Monitor Timing Display
   xrefs_into: none

GAP 617: 0x00477b67 — 0x00477ba0 (57 bytes)
   hex_head: ff1564e059000000c3e81b7a010085c074238b400485c07505b838a45e0050b968c38a00e820da04006a00b968c38a00
   prev_func: 0x00477aa0 — — Game Content Filter Check
   next_func: 0x00477ba0 — — Scene List Search by Path
   xrefs_into: none

GAP 618: 0x0047e95a — 0x0047ee5c (1282 bytes)
   hex_head: 83e8f97cf8ff56576aff6a018bf1e893a1000033c9898eec000000c786f0000000ffffffffc706786c5a008b7e443bf9
   prev_func: 0x0047e940 — Call FUN_00566650 if param_1 non-zero.
   next_func: 0x0047ee5c — — InitFromDataBlock
   xrefs_into: none

GAP 619: 0x00487f3b — 0x00488180 (581 bytes)
   hex_head: 90909090908b81840000003b442404741b8b1133c0898184000000898180000000c744240401000000ff622cc204008b
   prev_func: 0x00487f30 — — VTable Set + Cleanup
   next_func: 0x00488180 — — UI Text Display Constructor
   xrefs_into: none

GAP 620: 0x0048d67f — 0x0048d6a0 (33 bytes)
   hex_head: 90568bf1e818000000f644240801740956e83aa50f0083c4048bc65ec204009090
   prev_func: 0x0048d660 — — Constructor Dual Sub-Init
   next_func: 0x0048d6a0 — — Short Computation / VTable Init + Call
   xrefs_into: none

GAP 621: 0x00490535 — 0x00490550 (27 bytes)
   hex_head: 8d4900900449009004490090044900a8044900a8044900a8044900
   prev_func: 0x00490450 — — UIWidget_ProcessChildren
   next_func: 0x00490550 — — PanelMouseInteractionHandler
   xrefs_into: none

GAP 622: 0x00499516 — 0x00499580 (106 bytes)
   hex_head: 5052e800fee933fdffff568b714485f674148b068bceff90a40000008bb68c00000085f675ec33c05ec3568b714485f6
   prev_func: 0x004993d0 — — Render Dispatch with Iteration
   next_func: 0x00499580 — — Linked List Destroy (vtable destructor variant)
   xrefs_into: none

GAP 623: 0x0049cfbd — 0x0049d070 (179 bytes)
   hex_head: 909090568bf18b464c85c074188b405485c07411508d4660506a00b948e07c00e84e2500008b465085c0741b8b405485
   prev_func: 0x0049ca00 — — Cockpit Dashboard LED/Gauge Setup
   next_func: 0x0049d070 — — Steering Wheel Animation
   xrefs_into: none

GAP 624: 0x004a48b1 — 0x004a4900 (79 bytes)
   hex_head: ffddd85f5e5d32c05b83e923feffff5356578bf98d7718bb050000008d49008bcee8e998f8ff83c6404b75f333c08bcf
   prev_func: 0x004a4830 — — Tire Compound Name → ID Mapping
   next_func: 0x004a4db0 — — UIComponentCleanup
   xrefs_into: none

GAP 625: 0x004b3acf — 0x004b3af0 (33 bytes)
   hex_head: 908bc18d480489880cc00600898808c00600898804c00600c70000000000c39090
   prev_func: 0x004b3a90 — — Arithmetic/Comparison (Struct Copy with Header Size)
   next_func: 0x004b3af0 — — AdvanceRingBuffer
   xrefs_into: none

GAP 626: 0x004b9d1b — 0x004b9d80 (101 bytes)
   hex_head: e839c9f4ff568bf18b0e32d2e864eaffffd9813c0f0000ded9dfe0f6c4447a0a8a81800f000084c07436e856f0ffff8b
   prev_func: 0x004b9d00 — — Float Accumulator
   next_func: 0x004b9d80 — � Single Delegate (thunk to FUN_004b8140)
   xrefs_into: none

GAP 627: 0x004c5172 — 0x004c51a0 (46 bytes)
   hex_head: 5f03c15ec204008bc7e95affffffa190c48a0085c0741350e8402a0c0083c404c70590c48a0000000000c3909090
   prev_func: 0x004c5130 — — List Indexed Accessor
   next_func: 0x004c51a0 — — Track File Path Builder
   xrefs_into: none

GAP 628: 0x004d0f09 — 0x004d1027 (286 bytes)
   hex_head: c40c5f5ec2080056578bf1e867caf3ff33d28996e00000008996e40000008996ec0000008996f00000008996f8000000
   prev_func: 0x004d0f00 — — Short Computation / Single Field Setter
   next_func: 0x004d1027 — — SetThisFromArg
   xrefs_into: none

GAP 629: 0x004d8f91 — 0x004d8fb0 (31 bytes)
   hex_head: 8d4900268d4d00408d4d005a8d4d00308e4d00578e4d009090909090909090
   prev_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   next_func: 0x004d8fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 630: 0x004de57f — 0x004de5d0 (81 bytes)
   hex_head: 9076e14d0080e14d008ae14d0094e14d008b442404d9400c8b4c2408d9410cd9c1d8d9dfe0f6c441750addd8b8010000
   prev_func: 0x004ddf90 — — Scene File TEAMDIR/VEHDIR/NOTSPIN Writer
   next_func: 0x004de5d0 — � Indexed Struct Field Compute
   xrefs_into: none

GAP 631: 0x004f82f2 — 0x004f8330 (62 bytes)
   hex_head: 8bffbc824f00d7824f00ee824f0000000000000202020202020201010101010101010102020202020202020202020202
   prev_func: 0x004f8280 — — Color/Palette Lookup by Index
   next_func: 0x004f8330 — — Arithmetic/Comparison (Rate Computation with Clamp)
   xrefs_into: none

GAP 632: 0x0051ecd9 — 0x0051ecee (21 bytes)
   hex_head: 8db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051eca0 — — SSE Weighted Vector Sum
   next_func: 0x0051ecee — — 4x4 matrix × 4-vector transform
   xrefs_into: none

GAP 633: 0x005208eb — 0x005208fe (19 bytes)
   hex_head: 908d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052087e — — SSEVectorMatrixInit
   next_func: 0x005208fe — — SSE Matrix Construction from 4×4 Data
   xrefs_into: none

GAP 634: 0x0052d96c — 0x0052d990 (36 bytes)
   hex_head: 909090908b0985c974128b4424088b5424045052e8cb090000c2080033c0c20800909090
   prev_func: 0x0052d8d0 — — Threaded Object Creator with SEH
   next_func: 0x0052d990 — — Virtual Cleanup
   xrefs_into: none

GAP 635: 0x0053be91 — 0x0053c102 (625 bytes)
   hex_head: 0f29442400d94424008be9bbffffff8b4424108b4c240c8b542408505152e87030020083c40cc3ff15a4e35900ffff8b
   prev_func: 0x0053be60 — — 3D Squared Distance
   next_func: 0x0053c102 — — Float Store from x87 ST(2)
   xrefs_into: none

GAP 636: 0x0054eac0 — 0x0054eaf0 (48 bytes)
   hex_head: 68d0ea5400e87490030059c3909090905657be48bf8c00bf000400008d64240083ee188bcee88616f6ff4f75f35f5ec3
   prev_func: 0x0054eaa0 — Call FUN_00548e00() 1024 (0x400) times.
   next_func: 0x0054eaf0 — — Short Computation (Struct Zero-Init)
   xrefs_into: none

GAP 637: 0x0055be5e — 0x0055be80 (34 bytes)
   hex_head: 9090a1288f8b005051b9a0788b00e8df9fffffc204007cf25ec2040033e998ffffff
   prev_func: 0x0055be20 — � String Copy + Field Reader (Void)
   next_func: 0x0055be80 — @ 0x0055be80
   xrefs_into: none

GAP 638: 0x00579f6b — 0x00579f89 (30 bytes)
   hex_head: e900000000b984398d00e9e656ffffe900000000b980398d00e97db7ffff
   prev_func: 0x00579ccf — — Physics State Zero-Init
   next_func: 0x00579f89 — @ 0x00579f89 — 23 bytes
   xrefs_into: none

GAP 639: 0x0057b290 — 0x0057b2e0 (80 bytes)
   hex_head: 8a410484c07405b001c204008b411885c089412074288b0085c074228b5424043b1074e38b412085c074068b40048941
   prev_func: 0x0057b230 — — IntSetInsert
   next_func: 0x0057b2e0 — Returns field at param_1+0x24.
   xrefs_into: none

GAP 640: 0x005834b4 — 0x00583530 (124 bytes)
   hex_head: 89460489460889e914ffffff51568b3185f6894c2404743e55578bee8b76048a450884c0741d8b7d0085ff74168b0f85
   prev_func: 0x00583430 — ```
   next_func: 0x00583530 — — Zero-Fill Memory Region with Step
   xrefs_into: none

GAP 641: 0x00587a5a — 0x00587a90 (54 bytes)
   hex_head: 90909090909068707a5800e8d400000059c390909090b93d3e8d00e91a0f0100909090909090e80b000000e916000000
   prev_func: 0x00587a50 — — Thunk to FUN_00598815
   next_func: 0x00587a90 — — Single Function Call Wrapper
   xrefs_into: none

GAP 642: 0x00597371 — 0x00597388 (23 bytes)
   hex_head: 6a0ae87bbfffff6a16e80900000059596a03e82d29ffff
   prev_func: 0x00597359 — — Code Pointer Validation (IsBadCodePtr Wrapper)
   next_func: 0x00597388 — @ 0x00597388 — 386 bytes
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_O.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
