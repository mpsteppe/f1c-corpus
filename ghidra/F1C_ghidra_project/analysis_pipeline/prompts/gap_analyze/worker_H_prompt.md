# WORKER H — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker H of 20, items 302–344.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_H.md

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

GAP 302: 0x0040620f — 0x00406250 (65 bytes)
   hex_head: 90f644240401568bf1c7060ce55900740956e8a919180083c4048bc65ec2040090568bf1e818000000f6442408017409
   prev_func: 0x00406130 — — Mutex/Synchronization Object Init
   next_func: 0x00406250 — — short computation
   xrefs_into: none

GAP 303: 0x004096aa — 0x00409890 (486 bytes)
   hex_head: 8bff8e9440008e9440008e944000ac954000b89540000c9640000c9640000c9640000c96400056578bf98b0d88fe8a00
   prev_func: 0x00409440 — — View/Camera Mode Dispatch
   next_func: 0x00409970 — — Conditional Camera Pipeline Setup
   xrefs_into: none

GAP 304: 0x0040d94f — 0x0040d980 (49 bytes)
   hex_head: 9016d94000ebd74000ebd7400032d7400072d7400032d740003bd84000ebd74000ebd74000ebd74000ebd74000ebd740
   prev_func: 0x0040d4c0 — — Race Commentary/Director System
   next_func: 0x0040d980 — Initialize a structure with file/path constant references an
   xrefs_into: none

GAP 305: 0x004110fd — 0x00411120 (35 bytes)
   hex_head: 8d4900820f4100a80f4100be0f4100e10f4100fd0f4100201041009090909090909090
   prev_func: 0x00410f60 — — SceneNodeDecoder
   next_func: 0x00411120 — — Session Structure Cleanup
   xrefs_into: none

GAP 306: 0x0041ab19 — 0x0041ab30 (23 bytes)
   hex_head: 8d4900a3aa4100b9aa4100cfaa4100e5aa410090909090
   prev_func: 0x0041aa10 — — AI Session Phase Counter
   next_func: 0x0041ab30 — — Pit State Slot Activation / Commentary
   xrefs_into: none

GAP 307: 0x0042382b — 0x00423890 (101 bytes)
   hex_head: 4d595448008b4424088b0085c053568bf07505be38a45e008b4c240c8b0185c07505b838a45e008a108a1e8aca3ad375
   prev_func: 0x004236f0 — — String/Hash Token Parsing (Quote-Delimited)
   next_func: 0x00423a00 — — Binary Search in String Table
   xrefs_into: none

GAP 308: 0x00431bca — 0x00431c00 (54 bytes)
   hex_head: 90909090909068e01b4300e8645f150059c390909090b9e0737c00e9e6040000909090909090e80b000000e966000000
   prev_func: 0x00431bc0 — — Thunk
   next_func: 0x00431c00 — — PhysicsGlobalStateInit
   xrefs_into: none

GAP 309: 0x0044c661 — 0x0044c680 (31 bytes)
   hex_head: c9d9e0d95908ddd8ddd85e59c20800e80b000000e936000000909090909090
   prev_func: 0x0044c650 — — Collision Init Registration (DAT_0044c660)
   next_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   xrefs_into: none

GAP 310: 0x0044ca21 — 0x0044ca40 (31 bytes)
   hex_head: c94400e884b1130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044ca10 — — Collision Static Data Registration (1)
   next_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   xrefs_into: none

GAP 311: 0x0044cde1 — 0x0044ce14 (51 bytes)
   hex_head: cd4400e8c4ad130059c390909090c3e80b000000e936000000909090909090c70538a47c0023000000c7053ca47c0000
   prev_func: 0x0044cdd0 — — Collision Init Registration (DAT_0044cde0)
   next_func: 0x0044ce14 — — Global State Initializer
   xrefs_into: none

GAP 312: 0x0044d1b0 — 0x0044d1c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d190 — — Collision Static Data Registration (2)
   next_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   xrefs_into: none

GAP 313: 0x0044d570 — 0x0044d580 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d550 — — Collision Init Delegator (0xD550)
   next_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   xrefs_into: none

GAP 314: 0x0045b99d — 0x0045b9c0 (35 bytes)
   hex_head: 9090905633f689b11c0300008da4240000000056e87afaffff4683fe087cf45ec39090
   prev_func: 0x0045b840 — — Collision Damage Decay Processor
   next_func: 0x0045b9c0 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 315: 0x00464278 — 0x00464290 (24 bytes)
   hex_head: 2e414600354146003c414600434146009090909090909090
   prev_func: 0x00463f70 — — Session Type Setter
   next_func: 0x00464290 — — SynchronizeWithServer
   xrefs_into: none

GAP 316: 0x0046808d — 0x004681b0 (291 bytes)
   hex_head: 909090568bf1e8f8dfffffc70668f65900c78628010000ffffffff8bc65ec390909090c78128010000ffffffffe8a1e0
   prev_func: 0x00467f90 — — HTML Output Section Processor
   next_func: 0x004681b0 — — VehicleSceneLoadAndPositionTires
   xrefs_into: none

GAP 317: 0x0046cceb — 0x0046cd20 (53 bytes)
   hex_head: 4d59544800518bd15783c9ff33c0bf18d87c00f2aef7d149c6442404005f7505c6442400018b4c24008b02518bcaff50
   prev_func: 0x0046cb50 — — Profile Already Exists Page Handler
   next_func: 0x0046cd20 — — CopyProfileIconBMP
   xrefs_into: none

GAP 318: 0x00476073 — 0x004760d0 (93 bytes)
   hex_head: 90909090909090909090909090568bf1c70650445a008b463085c0740950e8391b110083c404c7063c445a008b460485
   prev_func: 0x00476060 — — Car Flag Byte Setter
   next_func: 0x004760d0 — � Object Constructor with VTable (0x005a4464)
   xrefs_into: none

GAP 319: 0x0047c6b6 — 0x0047c770 (186 bytes)
   hex_head: 4940e8ffa3e994fcffff568bf1e8e8d500006a008bcee8dfdc000033c05ec35d5b81c45c01e9d6ffffff566a018bf1e8
   prev_func: 0x0047c0d0 — — Object Init with VTable
   next_func: 0x0047c770 — — UI FPS/Performance Setting Display
   xrefs_into: none

GAP 320: 0x0048730d — 0x00487330 (35 bytes)
   hex_head: 8d4900a672480076724800bc72480090724800d2724800909090909090909090909090
   prev_func: 0x00487260 — � State-Dependent vTable Dispatcher with bool Param
   next_func: 0x00487330 — — State-Dependent VTable Dispatch
   xrefs_into: none

GAP 321: 0x0048b90a — 0x0048b91a (16 bytes)
   hex_head: 33e849adf7ff538a5c2408568bf18b06
   prev_func: 0x0048b8f0 — Sets field at +0x2f8 to param_2 if in range [0, 0x100).
   next_func: 0x0048b91a — — UI Widget Visibility Toggle
   xrefs_into: none

GAP 322: 0x0048fb96 — 0x0048fc50 (186 bytes)
   hex_head: 0000e80ffde9c4ffffff56578bf98b8fe000000085c97457e8ddf9ffffe92adb10009068580200006a0068200300006a
   prev_func: 0x0048fb70 — — Short Computation (UI Widget Constructor)
   next_func: 0x0048fc50 — — UI Object Constructor
   xrefs_into: none

GAP 323: 0x00498cf6 — 0x00498d20 (42 bytes)
   hex_head: 651000005fe9d1fcffff8b442404568bf1508d4e3ce840d90c008b4c240c894e445ec208004d59544800
   prev_func: 0x00498950 — — Sprite/Texture Enumeration
   next_func: 0x00498d20 — Calls init, sets vtable, calls post-init, stores param.
   xrefs_into: none

GAP 324: 0x0049b01c — 0x0049b030 (20 bytes)
   hex_head: 909090906830b04900e814cb0e0059c390909090
   prev_func: 0x0049afe0 — — Multi-Call Sequence
   next_func: 0x0049b030 — — UI Delegate Wrapper
   xrefs_into: none

GAP 325: 0x004a192a — 0x004a1969 (63 bytes)
   hex_head: ffe8294df6ff68b101000068ecd05c006a02b95cd28a00e80a61030084c074126814d15c00685cd28a00e84761030083
   prev_func: 0x004a18d0 — — OSMan::Enter
   next_func: 0x004a1990 — — ObjectHandleReader
   xrefs_into: none

GAP 326: 0x004b1eb5 — 0x004b1f50 (155 bytes)
   hex_head: 078b44240489e95bffffff518b5424085332db85d2568bf174645783c9ff33c08bfaf2aef7d1495f74548d4424105052
   prev_func: 0x004b1e20 — — ConfigKeyValueWrite
   next_func: 0x004b1f50 — — Short Field Setter
   xrefs_into: none

GAP 327: 0x004b6899 — 0x004b68c0 (39 bytes)
   hex_head: 8d4900e4674b00ee674b00f8674b0002684b0039684b0041684b0049684b0051684b0090909090
   prev_func: 0x004b67d0 — — Steering Alignment Tolerance Check
   next_func: 0x004b68c0 — — CircularBufferCheck
   xrefs_into: none

GAP 328: 0x004c2c24 — 0x004c2c40 (28 bytes)
   hex_head: 909090909090909090909090ff413cc35f8bce5ee9bd01e936feffff
   prev_func: 0x004c2c20 — — Simple Counter Increment
   next_func: 0x004c2c40 — — Running Average Filter
   xrefs_into: none

GAP 329: 0x004c9af3 — 0x004c9b70 (125 bytes)
   hex_head: 90639a4c00789a4c00f09a4c00f09a4c008d9a4c00b19a4c00c69a4c00568bf1c7066cce5a00e842fefffff644240801
   prev_func: 0x004c9a50 — — Memory Allocation / Particle Emitter Factory
   next_func: 0x004c9b70 — — Thunk to FUN_004ce820
   xrefs_into: none

GAP 330: 0x004d792a — 0x004d7960 (54 bytes)
   hex_head: 9090909090906840794d00e804020b0059c390909090b95cd28a00e9060000009090909090908b410485c0740750e8a5
   prev_func: 0x004d7920 — — Single Function Call Wrapper
   next_func: 0x004d7960 — — TraceLogInit
   xrefs_into: none

GAP 331: 0x004db5c6 — 0x004db6f0 (298 bytes)
   hex_head: cee80e00000033c05ec3a1a4567c0083f80756578b7c240c8bf17743ff248538b64d00578bcee89f0600006882000000
   prev_func: 0x004db550 — Conditional dispatch based on DAT_007d0474, compute and disp
   next_func: 0x004db6f0 — — Position/Order Name Display
   xrefs_into: none

GAP 332: 0x004f23aa — 0x004f2430 (134 bytes)
   hex_head: 90909090909068c0234f00e88457090059c390909090a12cdb8a0085c0740950e80058090083c404a124db8a0085c074
   prev_func: 0x004f23a0 — — Short Computation (Delegation)
   next_func: 0x004f2430 — — Constructor: Zero-Init + Sub-Calls
   xrefs_into: none

GAP 333: 0x0050da8b — 0x0050dab2 (39 bytes)
   hex_head: 6a01e815240000ff2534785d006a01e808240000ff2538785d006a01e8fb230000ff2524785d00
   prev_func: 0x0050d9a5 — — Transform/Offset Setup
   next_func: 0x0050dab2 — — Quaternion Normalize and Decompose
   xrefs_into: none

GAP 334: 0x00520133 — 0x0052014e (27 bytes)
   hex_head: 8db6000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052004e — — 3×4 Matrix Transform with SSE
   next_func: 0x0052014e — — SSE 4x4 Matrix × 4-Vector Multiply
   xrefs_into: none

GAP 335: 0x005290f7 — 0x00529200 (265 bytes)
   hex_head: 8da424000000008bff0f6e3558935d000f6e3d5c935d000f6e256c935d000fdbf00f6e2d68935d000fdbc70f7fc30f66
   prev_func: 0x00529000 — — Square Root Approximation (SIMD/3DNow!)
   next_func: 0x00529200 — — Empty Stub
   xrefs_into: none

GAP 336: 0x00537c9b — 0x00537ce0 (69 bytes)
   hex_head: 90627153004b725300bc725300ea7353008374530067755300b1775300a87b53000f7c5300547c5300c0715300de7153
   prev_func: 0x00537070 — — Multi-Block Allocator
   next_func: 0x00537ce0 — — Triple VTable Call
   xrefs_into: none

GAP 337: 0x005471af — 0x005471c0 (17 bytes)
   hex_head: 90537154006a7154008171540098715400
   prev_func: 0x00547140 — — Indexed Field Copy
   next_func: 0x005471c0 — — Simple Setter (+0xb0)
   xrefs_into: none

GAP 338: 0x00554f6a — 0x00554f80 (22 bytes)
   hex_head: 8bffd94e5500e34e5500ed4e5500f74e5500014f5500
   prev_func: 0x00554e90 — 
   next_func: 0x00554f80 — ```
   xrefs_into: none

GAP 339: 0x0056462f — 0x00564640 (17 bytes)
   hex_head: 908b0150e83764020059c35ec0a9ffccff
   prev_func: 0x00564620 — — Integer Difference Comparator
   next_func: 0x00564640 — — GetTickCount Win32 Stub
   xrefs_into: none

GAP 340: 0x0057ad6f — 0x0057adb0 (65 bytes)
   hex_head: 908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8a4cd000059c3909090
   prev_func: 0x0057acb0 — ```
   next_func: 0x0057adb0 — � Single Delegation Call
   xrefs_into: none

GAP 341: 0x005806f9 — 0x00580c10 (1303 bytes)
   hex_head: 8bc0e9d1f7ccff518b81680b00005356578db9480b0000894c240c85c0741a8b4f245150ff15a0e1590085c074073d80
   prev_func: 0x005805c0 — — Network Packet Queue Reader
   next_func: 0x00580c10 — — Network Packet Send
   xrefs_into: none

GAP 342: 0x00586f1a — 0x00586f40 (38 bytes)
   hex_head: 90909090909068306f5800e8140c000059c390909090b9303e8d00e99f2b0100909090909090
   prev_func: 0x00586f10 — — Single Function Call Wrapper
   next_func: 0x00586f40 — — Compute Bitmask from Bitmap Entry Count
   xrefs_into: none

GAP 343: 0x0059067e — 0x00590703 (133 bytes)
   hex_head: 558bec81c430fdffff539bd9bd5cffffff833dd09a5e0000741be8d3d3ffff808d38fdffff0180a538fdfffffde85a00
   prev_func: 0x00590640 — — __cintrindisp2 (MSVC CRT Internal)
   next_func: 0x00590703 — @ 0x00590703
   xrefs_into: none

GAP 344: 0x0059ca45 — 0x0059ca69 (36 bytes)
   hex_head: cccccccccccccccccccccc8b85ecfeffff50e873b1feff59c38d8dc8feffffe91750feff
   prev_func: 0x0059ca3b — — ExceptionHandlerThunk
   next_func: 0x0059ca69 — — C++ Exception Handler Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_H.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
