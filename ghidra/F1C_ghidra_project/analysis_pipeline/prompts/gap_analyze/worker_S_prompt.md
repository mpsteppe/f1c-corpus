# WORKER S — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker S of 20, items 769–810.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_S.md

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

GAP 769: 0x00407fad — 0x004080b0 (259 bytes)
   hex_head: 909090568b74240832c083feff74398b511885d2895120742f8b1285d274298d64240039725c741e8b512085d274068b
   prev_func: 0x00407f10 — — Resource ID Lookup by Name String
   next_func: 0x004080b0 — � Linked List Search by Value
   xrefs_into: none

GAP 770: 0x0040b849 — 0x0040bcd0 (1159 bytes)
   hex_head: 01ff5010c20400b8386c0000e866c917005355568be9578d4c2414e847b0150033c0b9600000008dbc24c8010000f3ab
   prev_func: 0x0040b710 — — Camera Transform Computation
   next_func: 0x0040bcd0 — — Resource Lookup with Optional VTable Dispatch
   xrefs_into: none

GAP 771: 0x0040f199 — 0x0040f1c0 (39 bytes)
   hex_head: 8d490042f1400048f140004ef1400042f1400048f140004ef14000909090909090909090909090
   prev_func: 0x0040f130 — — State-Dependent Update Dispatch
   next_func: 0x0040f1c0 — — Scene Object Loader State Machine
   xrefs_into: none

GAP 772: 0x00414477 — 0x004144c0 (73 bytes)
   hex_head: ff15a0e25900ffffffe80b000000e916000000909090909090b918a65e00e91640000090909090909068b0444100e894
   prev_func: 0x00414420 — — Multi-Pointer Free (5 pointers)
   next_func: 0x004144c0 — — TableLookupByIndex
   xrefs_into: none

GAP 773: 0x0041f82b — 0x0041f8a0 (117 bytes)
   hex_head: 903cf6410043f641004af6410051f6410058f641005ff6410066f641006df6410074f641007bf6410082f6410089f641
   prev_func: 0x0041f220 — — Championship Points Accumulator
   next_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   xrefs_into: none

GAP 774: 0x0042d1f4 — 0x0042d210 (28 bytes)
   hex_head: cdd14200f0d14200cdd1420083d14200cdd142009090909090909090
   prev_func: 0x0042cee0 — — PenaltyStateDefaultInit
   next_func: 0x0042d350 — — Session Reset
   xrefs_into: none

GAP 775: 0x00447267 — 0x004472a8 (65 bytes)
   hex_head: 909090909090909090c681591c000000c37a03b0e967ffffffdd81b41d0000dc1de0ec5900dfe0f6c4417514c781b41d
   prev_func: 0x004471f0 — — SuspensionVibration
   next_func: 0x004472a8 — — SetByteOffset7257
   xrefs_into: none

GAP 776: 0x0044c889 — 0x0044c8a0 (23 bytes)
   hex_head: 9090909090909068a0c84400e8a4b2130059c390909090
   prev_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   next_func: 0x0044c8c0 — — CollisionFrictionInit_8
   xrefs_into: none

GAP 777: 0x0044cc49 — 0x0044cc60 (23 bytes)
   hex_head: 909090909090906860cc4400e8e4ae130059c390909090
   prev_func: 0x0044cc34 — — Camera/View Zoom Initializer
   next_func: 0x0044cc80 — — Collision State Init 4
   xrefs_into: none

GAP 778: 0x0044d009 — 0x0044d020 (23 bytes)
   hex_head: 909090909090906820d04400e824ab130059c390909090
   prev_func: 0x0044cff4 — — Float/float init to (0, 1)
   next_func: 0x0044d040 — — CollisionFrictionInit_29
   xrefs_into: none

GAP 779: 0x0044d3c6 — 0x0044d3e0 (26 bytes)
   hex_head: 9090909090909090909068e0d34400e864a7130059c390909090
   prev_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   next_func: 0x0044d400 — — Spatial Node Init (index 14)
   xrefs_into: none

GAP 780: 0x004551f1 — 0x00455258 (103 bytes)
   hex_head: 4804b0015ec20c005f32e996fbffff8b4c240481f980000000b838a45e007c1981e98000000083f958731ec1e10481c1
   prev_func: 0x00454da0 — â€” Vehicle Input Smoothing (Throttle/Brake/Clutch/Steering)
   next_func: 0x00455260 — � Two-Way Dispatch by Index
   xrefs_into: none

GAP 781: 0x0045d4bd — 0x0045d4e0 (35 bytes)
   hex_head: 909090803900740e8a410184c0740733c9e96d4a1000c35f5e5b81c4f400e958fdffff
   prev_func: 0x0045d490 — — Global Flag-Based State Setter
   next_func: 0x0045d4e0 — — String Length Check Dispatch
   xrefs_into: none

GAP 782: 0x0046633f — 0x00466350 (17 bytes)
   hex_head: 908b49406a00e856250300c34d59544800
   prev_func: 0x00466300 — — State Initializer with Flag Check
   next_func: 0x00466350 — � Camera Yaw/Zoom Controller
   xrefs_into: none

GAP 783: 0x0046a86e — 0x0046a980 (274 bytes)
   hex_head: 9090e8ebfcffff33c0c3909090e955fcffff81ec000100005768000100008d4424088bf950b998e47c00e8836204008b
   prev_func: 0x0046a560 — — Standings Display
   next_func: 0x0046a980 — — ID Pair Match and Clear
   xrefs_into: none

GAP 784: 0x00470f79 — 0x004713e0 (1127 bytes)
   hex_head: 33c0e937fdffff566a018bf1e8d65dffff6aff68a4325c008bcec706800a5a00c7861c0300005cf67c00c78624030000
   prev_func: 0x00470f20 — — Race/Session Mode Data Loader
   next_func: 0x004713e0 — — UI Toggle Increment/Decrement Handler
   xrefs_into: none

GAP 785: 0x00478ed0 — 0x00479170 (672 bytes)
   hex_head: 568bf18b865c01000085c07505b838a45e00578bf883c9ff33c0f2aef7d1495f742da1d0e57c0085c08bc87505b938a4
   prev_func: 0x00478e80 — Delegates to FUN_00499b80().
   next_func: 0x00479320 — — Hit Test / Bounds Check
   xrefs_into: none

GAP 786: 0x0047f3c2 — 0x0047f3f0 (46 bytes)
   hex_head: 68c38a00e8916104005f5e5d5bc3568bf1e818000000f644240801740956e8ea87100083c4048bc65ec204009090
   prev_func: 0x0047f370 — — Screen Data Struct Init
   next_func: 0x0047f3f0 — — Destructor (3 sub-objects)
   xrefs_into: none

GAP 787: 0x00488aaa — 0x00488b00 (86 bytes)
   hex_head: 5fe8a9dbf7ff568bf18b06c686ed00000000ff909c00000085c075108b166a018bceff522c8bcee85adbffff33c05ec3
   prev_func: 0x00488a30 — — UIScrollWidgetUpdate
   next_func: 0x00488b00 — — Constructor: Init + VTable
   xrefs_into: none

GAP 788: 0x0048ddf5 — 0x0048df40 (331 bytes)
   hex_head: 908b016a00ffe9eaf9ffff83ec0856578bf1e81489ffff8bf88d44240c508d4c240c518b4e40e860aa000085ff0f84c5
   prev_func: 0x0048d9d0 — — Media Buffer Playback Manager
   next_func: 0x0048df40 — — UIWidgetDragHandler
   xrefs_into: none

GAP 789: 0x00494437 — 0x004944a0 (105 bytes)
   hex_head: ff150ce35900fbffff568bf1c706d8c85a00e8022efffff644240801740956e874370f0083c4048bc65ec20400009090
   prev_func: 0x00493e20 — — Resource Path Builder
   next_func: 0x00494600 — — Collision Global Zeroing
   xrefs_into: none

GAP 790: 0x00499cbe — 0x00499ce0 (34 bytes)
   hex_head: 9090568bf1e818000000f644240801740956e8fade0e0083c4048bc65ec204009090
   prev_func: 0x00499c50 — — Constructor: Init with -1 Sentinels
   next_func: 0x00499ce0 — — Destructor with Multiple Conditional Frees
   xrefs_into: none

GAP 791: 0x0049f66d — 0x0049f6a0 (51 bytes)
   hex_head: 8d490063f549007ff549009df54900bbf54900d3f54900fcf54900fcf5490010f6490010f64900909090909090909090
   prev_func: 0x0049f530 — — ParamRangeClampedLerp
   next_func: 0x0049f6a0 — — String Format and Render
   xrefs_into: none

GAP 792: 0x004a7079 — 0x004a70e0 (103 bytes)
   hex_head: 64f6e944ffffff83ec088b54240c33c05689442404894424088d442408508bf18d4c24085168c0d65c0052e844170e00
   prev_func: 0x004a7040 — — DebugCoordinateFormat
   next_func: 0x004a70e0 — — UI Control Window Initialization
   xrefs_into: none

GAP 793: 0x004b41ba — 0x004b41e0 (38 bytes)
   hex_head: 90909090909068d0414b00e874390d0059c390909090b9e4b68a00e9b65d0000909090909090
   prev_func: 0x004b41b0 — — Short Computation (Call Wrapper)
   next_func: 0x004b41e0 — — File Stream Writer
   xrefs_into: none

GAP 794: 0x004b9f90 — 0x004b9fa0 (16 bytes)
   hex_head: 83c108e918f8ffff9090909090909090
   prev_func: 0x004b9f70 — — Object Init
   next_func: 0x004b9fa0 — — Single Call Wrapper
   xrefs_into: none

GAP 795: 0x004c7c3a — 0x004c7c50 (22 bytes)
   hex_head: 90909090909068507c4c00e8f4fe0b0059c390909090
   prev_func: 0x004c7c30 — — Single Function Call Wrapper
   next_func: 0x004c7c50 — — PhysicsVectorGetter
   xrefs_into: none

GAP 796: 0x004d2dbb — 0x004d2dd0 (21 bytes)
   hex_head: 90fb2c4d00b72c4d00fb2c4d00222d4d0090909090
   prev_func: 0x004d24d0 — � Race Results File Writer (raceresults.txt)
   next_func: 0x004d2dd0 — � Conditional Allocation with Callbacks
   xrefs_into: none

GAP 797: 0x004d9400 — 0x004d9420 (32 bytes)
   hex_head: f3934d00f3934d00f3934d00f3934d00f3934d00909090909090909090909090
   prev_func: 0x004d93e0 — — Range Check (1-5)
   next_func: 0x004d9420 — — StartingGridUIDraw
   xrefs_into: none

GAP 798: 0x004e1946 — 0x004e1970 (42 bytes)
   hex_head: 8bffd7184e00eb184e0007194e0023194e00000000000102030303030303030390909090909090909090
   prev_func: 0x004e18c0 — — Subsystem ready query
   next_func: 0x004e1970 — — Effect Data Table Initialization
   xrefs_into: none

GAP 799: 0x004fb8c2 — 0x004fb8e0 (30 bytes)
   hex_head: 5f5e5d5b59c3ddd85f5e5d5b59c3e80b000000e916000000909090909090
   prev_func: 0x004fb6d0 — — Unidentified Logic / Collision Impulse/Response Computatio
   next_func: 0x004fb8e0 — — Thunk to FUN_004fc9c0
   xrefs_into: none

GAP 800: 0x0051f0a8 — 0x0051f0be (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ef5e — — SSE 4x4 Matrix Multiply
   next_func: 0x0051f0be — — SSE 3D Cross Product with 3×3 Matrix
   xrefs_into: none

GAP 801: 0x00520df4 — 0x00520e0e (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x00520ce0 — — TriangleClosestPointOrNormal
   next_func: 0x00520e0e — — SSE Quaternion Composition from Axis-Angle Components
   xrefs_into: none

GAP 802: 0x0052e198 — 0x0052e1c0 (40 bytes)
   hex_head: ff1560e35900ffff568bf1e818000000f644240801740956e81a9a050083c4048bc65ec204009090
   prev_func: 0x0052e170 — — Render Object Constructor (vtable + props)
   next_func: 0x0052e1c0 — — Thunk with VTable + Flag Check
   xrefs_into: none

GAP 803: 0x0053c20a — 0x0053c2a0 (150 bytes)
   hex_head: 9090909090906820c25300e824b9040059c3909090908a0de58e8b00b00184c875120ac8880de58e8b00b9a0788b00e9
   prev_func: 0x0053c200 — — Delegation Wrapper
   next_func: 0x0053c2a0 — — Global Zero Init
   xrefs_into: none

GAP 804: 0x005504bb — 0x005504d0 (21 bytes)
   hex_head: 906d04550053045500630455003a04550090909090
   prev_func: 0x005503a0 — (0x005503a0)
   next_func: 0x005504d0 — — Indexed Array Lookup with Bounds Check
   xrefs_into: none

GAP 805: 0x0055fa1a — 0x0055fbc0 (422 bytes)
   hex_head: 8bff1af4550054f4550088f45500c6f455006bf955000004040404040404040404040404040404040404040404040404
   prev_func: 0x0055f080 — — Struct Zero-Init Constructor (Large)
   next_func: 0x0055fbc0 — — Global Data Copy
   xrefs_into: none

GAP 806: 0x0057a127 — 0x0057a160 (57 bytes)
   hex_head: 04005e32c05bc204008a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8e4
   prev_func: 0x0057a0f0 — — Byte-Aligned Memory Copy with Offset
   next_func: 0x0057a160 — Constructor with vtable assignment and init call.
   xrefs_into: none

GAP 807: 0x0057c795 — 0x0057c7b0 (27 bytes)
   hex_head: 8d49001fc7570044c7570060c7570068c757009090909090909090
   prev_func: 0x0057bee0 — — NetworkSocketCreate
   next_func: 0x0057c7b0 — — SocketBindPortScan
   xrefs_into: none

GAP 808: 0x00585805 — 0x00585860 (91 bytes)
   hex_head: 8115a4e159008bc75f5ec38b814006000053568db12406000085c0741a8b4e205150ff15a0e1590085c074073d800000
   prev_func: 0x005857c0 — — Mutex-Protected Field Write
   next_func: 0x00585860 — — Single Field Setter (Returns 1)
   xrefs_into: none

GAP 809: 0x00589584 — 0x005895a2 (30 bytes)
   hex_head: d9c9833d443e8d00017404d9f8eb05e8247d00009bdfe09b9e7ae7ddd9c3
   prev_func: 0x0058957a — — Interrupt Dispatch
   next_func: 0x005895a2 — (0x005895a2)
   xrefs_into: none

GAP 810: 0x00599958 — 0x00599ad9 (385 bytes)
   hex_head: b878d35900e8760cffff51515356894dec33f68d4df08975f0e8d70b000039354ca05e007c0aff054ca05e0032dbeb0c
   prev_func: 0x0059994e — — Thin Forwarding Wrapper
   next_func: 0x00599ad9 — — Ref Count Decrement with Check
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_S.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
