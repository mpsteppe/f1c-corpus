# WORKER I — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker I of 20, items 345–387.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_I.md

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

GAP 345: 0x00406511 — 0x00406640 (303 bytes)
   hex_head: e45900d80d50e4590083e991fbffff8b410c85c074096a0150ff158ce35900c375dc6a008bcbe8f30100e9d1ffffff8b
   prev_func: 0x004064c0 — — View/Camera Reset
   next_func: 0x00406640 — — Conditional Match Trigger
   xrefs_into: none

GAP 346: 0x00409946 — 0x00409970 (42 bytes)
   hex_head: 0000005b83c41cc208008b0d64fe8a006a016a20e8a10814008b0d88fe8a00e926c2130033e8e9ccffff
   prev_func: 0x00409770 — � File Resource Processing with Callbacks
   next_func: 0x00409970 — — Conditional Camera Pipeline Setup
   xrefs_into: none

GAP 347: 0x0040ddc5 — 0x0040ddf0 (43 bytes)
   hex_head: 8d4900c1dd4000c1dd4000c1dd400092dd400092dd4000b7dd4000c1dd4000909090909090909090909090
   prev_func: 0x0040dd80 — — Short Computation (State Machine)
   next_func: 0x0040ddf0 — — Cinematic Event State Machine
   xrefs_into: none

GAP 348: 0x0041143a — 0x00411570 (310 bytes)
   hex_head: 7ce81952ffff833de4b68a000256578bf10f84ce0000008b56488b7c240c33c085d27e188b4e5081c1d00000003b3974
   prev_func: 0x00411330 — — Short Computation (Vehicle Parameter Setter)
   next_func: 0x00411570 — — Status Field Copy
   xrefs_into: none

GAP 349: 0x0041ac39 — 0x0041ac50 (23 bytes)
   hex_head: 8d4900c3ab4100d9ab4100efab410005ac410090909090
   prev_func: 0x0041ab30 — — Pit State Slot Activation / Commentary
   next_func: 0x0041ac50 — � Race Event Sound Dispatch
   xrefs_into: none

GAP 350: 0x00423e75 — 0x00424080 (523 bytes)
   hex_head: d9fad9592483e919feffff53568bf18d4e0ce874060c008d8e34400000e80979090033db8bce891ec74604ffffffffe8
   prev_func: 0x00423db0 — — short computation
   next_func: 0x00424750 — — AI Difficulty Scalar (Low Range)
   xrefs_into: none

GAP 351: 0x00431c58 — 0x00431c70 (24 bytes)
   hex_head: 909090909090909068701c4300e8d45e150059c390909090
   prev_func: 0x00431c00 — — PhysicsGlobalStateInit
   next_func: 0x00431c70 — — PhysicsShutdown
   xrefs_into: none

GAP 352: 0x0044c6a9 — 0x0044c6c0 (23 bytes)
   hex_head: 9090909090909068c0c64400e884b4130059c390909090
   prev_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   next_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   xrefs_into: none

GAP 353: 0x0044ca69 — 0x0044ca80 (23 bytes)
   hex_head: 909090909090906880ca4400e8c4b0130059c390909090
   prev_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   next_func: 0x0044caa0 — — InitMouseAbsAxisX
   xrefs_into: none

GAP 354: 0x0044ce29 — 0x0044ce40 (23 bytes)
   hex_head: 909090909090906840ce4400e804ad130059c390909090
   prev_func: 0x0044ce14 — — Global State Initializer
   next_func: 0x0044ce60 — — Global State Initializer (Collision Material 2)
   xrefs_into: none

GAP 355: 0x0044d1e9 — 0x0044d200 (23 bytes)
   hex_head: 909090909090906800d24400e844a9130059c390909090
   prev_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   next_func: 0x0044d220 — — InitMouseAbsAxisY
   xrefs_into: none

GAP 356: 0x0044d5a6 — 0x0044d5c0 (26 bytes)
   hex_head: 9090909090909090909068c0d54400e884a5130059c390909090
   prev_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   next_func: 0x0044d5e0 — — Collision Material Coefficients Set 1 (ID 0x13)
   xrefs_into: none

GAP 357: 0x0045bb81 — 0x0045bbe0 (95 bytes)
   hex_head: 7d094283c15c83fa087ce28bc65ec356682c0300008bf1e866c0120083c40485c0740d8bc8e895ffffff89068bc65ec3
   prev_func: 0x0045bb60 — — ID to Color Mask Mapper
   next_func: 0x0045bbe0 — — Double Delegate Call
   xrefs_into: none

GAP 358: 0x0046491f — 0x00464930 (17 bytes)
   hex_head: 90e80b000000e916000000909090909090
   prev_func: 0x004647d0 — — Linked List Merge Sort (Recursive)
   next_func: 0x00464930 — — Single Function Call Wrapper
   xrefs_into: none

GAP 359: 0x0046846a — 0x004685b0 (326 bytes)
   hex_head: e1e8e9e1f9ffa030ff7c0081ec0002000084c0568bf174248b066a01ff50388b166a008bceff523c8b4e406a00e80404
   prev_func: 0x004681b0 — — VehicleSceneLoadAndPositionTires
   next_func: 0x004685b0 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 360: 0x0046cecf — 0x0046d0d0 (513 bytes)
   hex_head: 905668ccc45e008bf168bc305c00b9c0c45e00e8196bfbff85c0741633c08d49008a88bc305c008888ccc45e004084c9
   prev_func: 0x0046cd20 — — CopyProfileIconBMP
   next_func: 0x0046d0d0 — — SessionCheckEndCondition
   xrefs_into: none

GAP 361: 0x0047619a — 0x004761c0 (38 bytes)
   hex_head: 8be8b904f9ff8b44240485c0740c8944240483c150e99c040f00c20400ff1550e35900ffffff
   prev_func: 0x00476100 — — VTable Object Destructor (Multi-Stage Cleanup)
   next_func: 0x004761c0 — — UI Object Init
   xrefs_into: none

GAP 362: 0x0047c7ba — 0x0047c860 (166 bytes)
   hex_head: 50e8999ef8ff56680000803f6a008bf1e8d10b01008b4424088986fc000000c706b0695a008bc65ec20400cee85bf000
   prev_func: 0x0047c770 — — UI FPS/Performance Setting Display
   next_func: 0x0047c860 — — UILoadingPercentDisplay
   xrefs_into: none

GAP 363: 0x004873de — 0x00487400 (34 bytes)
   hex_head: 8bff7373480045734800887348005e7348009d734800909090909090909090909090
   prev_func: 0x00487330 — — State-Dependent VTable Dispatch
   next_func: 0x00487400 — — UI State Change Dispatcher
   xrefs_into: none

GAP 364: 0x0048b94c — 0x0048b9c0 (116 bytes)
   hex_head: 909090908a4424048bd15683c9ff84c057742d8b82f00200008982f4020000c600008db2e701000033c08bfef2aef7d1
   prev_func: 0x0048b91a — — UI Widget Visibility Toggle
   next_func: 0x0048b9c0 — — Text Input Render / Password Mask
   xrefs_into: none

GAP 365: 0x0048fd79 — 0x0048fdb0 (55 bytes)
   hex_head: 445ae9f1feffff568bf1c7063c445a008b460485c0740950e8397e0f0083c404f644240801740956e8297e0f0083c404
   prev_func: 0x0048fd60 — — Constructor
   next_func: 0x0048fdb0 — — Viewport/Rect Size Calc
   xrefs_into: none

GAP 366: 0x00498d42 — 0x00498d90 (78 bytes)
   hex_head: d90c008b4c240c894e445ec208008a44240484c074158b41108b510c508b4108528b51045052e8e3020000c20400568b
   prev_func: 0x00498d20 — Calls init, sets vtable, calls post-init, stores param.
   next_func: 0x00498d90 — — Dual-List Destruction
   xrefs_into: none

GAP 367: 0x0049b03a — 0x0049b050 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x0049b030 — — UI Delegate Wrapper
   next_func: 0x0049b050 — — Empty Stub
   xrefs_into: none

GAP 368: 0x004a1970 — 0x004a1990 (32 bytes)
   hex_head: 8b44240450e8956b0e008b4c240cd91983c404b804000000c20800e8c94cf6ff
   prev_func: 0x004a1930 — — OSMan::Exit()
   next_func: 0x004a1990 — — ObjectHandleReader
   xrefs_into: none

GAP 369: 0x004b2055 — 0x004b20d0 (123 bytes)
   hex_head: 9090668b4116e959ffffff518b5424085332db85d2568bf174525783c9ff33c08bfaf2aef7d1495f74428d4424105052
   prev_func: 0x004b1fc0 — — UI Config Entry Serialization
   next_func: 0x004b20d0 — — Arithmetic/Comparison (Clamp with Bounds)
   xrefs_into: none

GAP 370: 0x004b784d — 0x004b7860 (19 bytes)
   hex_head: 8d4900fa754b00fe754b0005764b000c764b00
   prev_func: 0x004b7500 — � Replay Save State Machine (Saving Replay)
   next_func: 0x004b7860 — ? Render Batch Node Allocator
   xrefs_into: none

GAP 371: 0x004c2f8c — 0x004c2fa0 (20 bytes)
   hex_head: 90909090e80b000000e916000000909090909090
   prev_func: 0x004c2f20 — — LinkedListDestructorWithData
   next_func: 0x004c2fa0 — — Delegation Wrapper
   xrefs_into: none

GAP 372: 0x004c9b7a — 0x004c9b90 (22 bytes)
   hex_head: 90909090909068909b4c00e8b4df0b0059c390909090
   prev_func: 0x004c9b70 — — Thunk to FUN_004ce820
   next_func: 0x004c9b90 — — Nullsub Wrapper for Render Object
   xrefs_into: none

GAP 373: 0x004d7ac6 — 0x004d7b00 (58 bytes)
   hex_head: 5fc20c0032c05fc20c00568bc1578d5018be0300000083cfff90c7420c00000000c70200000000897ae8897af483c204
   prev_func: 0x004d7aa0 — — Debug Log Write
   next_func: 0x004d7b00 — — Unidentified Logic (3-Way Range Check with Track Data)
   xrefs_into: none

GAP 374: 0x004db9f2 — 0x004dbb60 (366 bytes)
   hex_head: cfe862c6ffff5f5e83e9e6fdffff83ec0856578bf9b934e27c0033f6e88dfffbff84c0740ac644240882be01000000b9
   prev_func: 0x004db9a0 — — Utility Function (Number Format + UI Draw)
   next_func: 0x004dbb60 — — DrawDebugTextOverlay
   xrefs_into: none

GAP 375: 0x004f3471 — 0x004f3490 (31 bytes)
   hex_head: 8d490083324f00d9324f002f334f0086334f00dd334f0027344f0090909090
   prev_func: 0x004f3240 — For each axis direction (param_3 0-5), validates that force 
   next_func: 0x004f3490 — — Arithmetic/Comparison (ABS-Vector Load)
   xrefs_into: none

GAP 376: 0x0050eb53 — 0x0050eb73 (32 bytes)
   hex_head: 2cea50008eea500092ea500096ea50009aea50009eea5000a1ea5000a5ea5000
   prev_func: 0x0050e9e6 — — Color Matrix Transform with Blend
   next_func: 0x0050eb73 — � Skeleton Animation Blending
   xrefs_into: none

GAP 377: 0x005201fb — 0x0052020e (19 bytes)
   hex_head: 908d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052014e — — SSE 4x4 Matrix × 4-Vector Multiply
   next_func: 0x0052020e — — 4x4 Matrix Multiply (SSE)
   xrefs_into: none

GAP 378: 0x005292e9 — 0x005295e0 (759 bytes)
   hex_head: 8da424000000008da424000000008da424000000008bffe8fbfeffff0f6e0d0c945d000f0fc1b4c38da424000000008d
   prev_func: 0x00529200 — — Empty Stub
   next_func: 0x005295e0 — — Packed Floating-Point Math (3DNow!)
   xrefs_into: none

GAP 379: 0x00539f2e — 0x00539f60 (50 bytes)
   hex_head: 8bffbf9853007b9953006f9a5300f09a5300b09b5300239c53004f9d5300829e5300d39e5300d79e5300909090909090
   prev_func: 0x00539830 — — Object Alloc + Field Init
   next_func: 0x00539f60 — — Indirect Call via VTable+0x24
   xrefs_into: none

GAP 380: 0x00547224 — 0x00547240 (28 bytes)
   hex_head: e1715400f17154000172540011725400909090909090909090909090
   prev_func: 0x005471d0 — — Switch-Based Float Setter
   next_func: 0x00547240 — � Gear Ratio Setter with Flag Condition
   xrefs_into: none

GAP 381: 0x00555e3e — 0x00555e50 (18 bytes)
   hex_head: 8bff845255009b525500b0525500f0525500
   prev_func: 0x005550e0 — @ 0x005550e0 — 3422 bytes
   next_func: 0x00556040 — — Graphics/Display State Sync with Vehicle
   xrefs_into: none

GAP 382: 0x005653ab — 0x005653f0 (69 bytes)
   hex_head: 90c552560061525600675256006d52560094525600000404000404040404040404040404040404040404040404040404
   prev_func: 0x005651b0 — 
   next_func: 0x005653f0 — — String-Based Lookup / Key-Value Match
   xrefs_into: none

GAP 383: 0x0057adba — 0x0057adf0 (54 bytes)
   hex_head: 90909090909068d0ad5700e874cd000059c390909090b9f93b8d00e9badb0100909090909090e80b000000e916000000
   prev_func: 0x0057adb0 — � Single Delegation Call
   next_func: 0x0057adf0 — — Single Function Call Wrapper
   xrefs_into: none

GAP 384: 0x0058122c — 0x00581600 (980 bytes)
   hex_head: 909090908b814006000053568db12406000032db85c0741a8b4e205150ff15a0e1590085c074073d8000000075048bce
   prev_func: 0x0058119a — — Network File Transfer Accept Handler
   next_func: 0x00581600 — — Network Buffer Search (Mutex-Protected Linked List)
   xrefs_into: none

GAP 385: 0x00587062 — 0x00587090 (46 bytes)
   hex_head: 3bfe72d38b4424105b5f5e5d59c3568bf1e858000000f644240801740956e84a0b000083c4048bc65ec204009090
   prev_func: 0x00587030 — — Object Init with VTable Setup
   next_func: 0x00587090 — — Object Copy-Construct from Source
   xrefs_into: none

GAP 386: 0x0059083b — 0x0059086e (51 bytes)
   hex_head: 558bec81c430fdffff53ff750cff7508e81e00000083c4089bd9bd5cffffff80a538fdfffffde80ad2ffffe898feffff
   prev_func: 0x0059070a — (0x0059070a)
   next_func: 0x0059086e — — CRT __fload (float load)
   xrefs_into: none

GAP 387: 0x0059ca73 — 0x0059ca8b (24 bytes)
   hex_head: cccccccccccccccccccccccccc8d8df4feffffe9d5dfedff
   prev_func: 0x0059ca69 — — C++ Exception Handler Wrapper
   next_func: 0x0059ca8b — — CxxFrameHandlerWrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_I.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
