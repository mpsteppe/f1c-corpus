# WORKER K — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker K of 20, items 431–473.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_K.md

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

GAP 431: 0x00406b74 — 0x00406ba0 (44 bytes)
   hex_head: f9ff0f95c05e83e9ebfeffff568bf1e818000000f644240801740956e83a10180083c4048bc65ec204009090
   prev_func: 0x00406b60 — — MenuSelectSetter
   next_func: 0x00406ba0 — Destructor that destroys 4 linked lists with different clean
   xrefs_into: none

GAP 432: 0x00409f19 — 0x00409f40 (39 bytes)
   hex_head: 8d4900439a4000719a4000ac9a4000da9a4000679b4000959b4000b89b4000db9b4000379c4000
   prev_func: 0x00409a00 — — CameraModeViewportUpdate
   next_func: 0x00409f40 — — VTable Dispatch Chain (GetObject + GetChild)
   xrefs_into: none

GAP 433: 0x0040e12f — 0x0040e170 (65 bytes)
   hex_head: 9061df400085df4000afdf4000cfdf4000eedf4000ffdf400026e14000b7e0400086e040001de14000a4e040000de040
   prev_func: 0x0040de60 — ? AI Behavior State Machine
   next_func: 0x0040e170 — — Tick/Update Dispatch
   xrefs_into: none

GAP 434: 0x00411d42 — 0x00411db0 (110 bytes)
   hex_head: 8bff301c41003b1d4100751c4100971c4100b71c4100d91c4100f91c41001b1d4100551c41003b1d4100000900000102
   prev_func: 0x00411bf0 — — Race Event Message Dispatcher
   next_func: 0x00411db0 — — Font Character Render Dispatcher
   xrefs_into: none

GAP 435: 0x0041b151 — 0x0041b190 (63 bytes)
   hex_head: 8d49002fb0410048b0410061b041007ab0410093b04100acb04100dbb04100dbb04100dbb04100dbb04100f9b0410017
   prev_func: 0x0041afd0 — � Session Event Commentary (Per Car)
   next_func: 0x0041b190 — � Session End Commentary
   xrefs_into: none

GAP 436: 0x00429e9e — 0x00429eb0 (18 bytes)
   hex_head: 8bff5f9d4200a29c42000000000101010090
   prev_func: 0x00429470 — — AI Ability / Lap Ratio / Push Lap Update
   next_func: 0x00429eb0 — — Race-Phase Pit Entry Trigger
   xrefs_into: none

GAP 437: 0x00432816 — 0x00432870 (90 bytes)
   hex_head: 8b096a00e8e9bafeffff8b018b54240483c02085d27c2f3b500c7d2a85d28b007e0c85c074208b40044a85d27ff485c0
   prev_func: 0x00432810 — — Vehicle Field Accessor (Offset +0x2C)
   next_func: 0x00432870 — — Path String Combinator
   xrefs_into: none

GAP 438: 0x0044c709 — 0x0044c720 (23 bytes)
   hex_head: 909090909090906820c74400e824b4130059c390909090
   prev_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   next_func: 0x0044c740 — — CollisionGridInit4
   xrefs_into: none

GAP 439: 0x0044cac9 — 0x0044cae0 (23 bytes)
   hex_head: 9090909090909068e0ca4400e864b0130059c390909090
   prev_func: 0x0044cab4 — — Render State Float Initialization
   next_func: 0x0044cb00 — — Collision Subsystem Init (DAT_007ccfdc)
   xrefs_into: none

GAP 440: 0x0044ce89 — 0x0044cea0 (23 bytes)
   hex_head: 9090909090909068a0ce4400e8a4ac130059c390909090
   prev_func: 0x0044ce74 — — InitFloatGlobals
   next_func: 0x0044cec0 — — CollisionGridInit37
   xrefs_into: none

GAP 441: 0x0044d249 — 0x0044d260 (23 bytes)
   hex_head: 909090909090906860d24400e8e4a8130059c390909090
   prev_func: 0x0044d220 — — InitMouseAbsAxisY
   next_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   xrefs_into: none

GAP 442: 0x0044f00c — 0x0044f050 (68 bytes)
   hex_head: 90909090d9442404d81540e45900dfe0f6c4057a02d9e0d9442408d81540e45900dfe0f6c4057a02d9e0d9c9d9e0d999
   prev_func: 0x0044efe0 — — CollisionCullCleanup
   next_func: 0x0044f050 — — Collision Node Property Setter
   xrefs_into: none

GAP 443: 0x0045be6e — 0x0045bea0 (50 bytes)
   hex_head: 90906880be4500e8c4bc120059c390909090b908d27c00e816000000a108d27c0085c0740750e836bd120059c34d5954
   prev_func: 0x0045be50 — — Global State Initializer (Collision System Reset)
   next_func: 0x0045bea0 — — AVI Stream Cleanup
   xrefs_into: none

GAP 444: 0x00464ec9 — 0x00464ee0 (23 bytes)
   hex_head: 8d4900a14e4600a94e4600b14e4600b94e460090909090
   prev_func: 0x00464e90 — — Buffer Size Lookup
   next_func: 0x00464ee0 — — Conditional Delegate Based on Counter
   xrefs_into: none

GAP 445: 0x00468634 — 0x0046890d (729 bytes)
   hex_head: 90909090909090909090909081ec04010000a038a45e00568bf133c966894c2405884c2407b998e47c0088442404e8a9
   prev_func: 0x00468610 — Destructor sets vtable, frees child pointer at +0x174, calls
   next_func: 0x00468910 — — HTML Results Stats Page "World Championships:"
   xrefs_into: none

GAP 446: 0x0046e229 — 0x0046e5c0 (919 bytes)
   hex_head: c8e910bb0100c351568bf18b4e408b016a1fc644240801ff501c85c0741a8b887801000085c97d108bc8e8c8b6010085
   prev_func: 0x0046e1b0 — — Deferred Texture/Object Loader
   next_func: 0x0046e5c0 — — Init with Stack Buffer
   xrefs_into: none

GAP 447: 0x004765fd — 0x00476660 (99 bytes)
   hex_head: 909090568bf1c7068c445a008b463c85c0740950e8b915110083c404c70650445a008b463085c0740950e8a315110083
   prev_func: 0x004765f0 — — LoadPath Getter
   next_func: 0x00476660 — — Season Path Match Search
   xrefs_into: none

GAP 448: 0x0047dbb7 — 0x0047dbe0 (41 bytes)
   hex_head: ff1518e05900fdffff568bf1e868af0000f644240801740956e8fa9f100083c4048bc65ec204009090
   prev_func: 0x0047d800 — � Season Stats Display (PrevYear/Drivers/Times)
   next_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   xrefs_into: none

GAP 449: 0x00487688 — 0x004876b0 (40 bytes)
   hex_head: a800000033c05ec3568bf1e818000000f644240801740956e82a05100083c4048bc65ec204009090
   prev_func: 0x00487660 — — UI Object Init with Byte Params
   next_func: 0x004876b0 — — Short Computation (Constructor)
   xrefs_into: none

GAP 450: 0x0048c0db — 0x0048c9a0 (2245 bytes)
   hex_head: 9090909090568bf18b86b800000085c07505b838a45e00681cc25c0050e813c30f0083c40885c0750689860c0300008b
   prev_func: 0x0048c0d0 — — VTable + Init
   next_func: 0x0048c9a0 — — Simple VTable + Null Init
   xrefs_into: none

GAP 451: 0x0048febb — 0x0048fee0 (37 bytes)
   hex_head: 9090909090568bf18b8ee00000008b06518bceff50408bcee8c802000033c05ec390909090
   prev_func: 0x0048feb0 — — VTable + Sub-Init
   next_func: 0x0048fee0 — — UI Full Render with Dimensions
   xrefs_into: none

GAP 452: 0x00499082 — 0x00499140 (190 bytes)
   hex_head: 8b066a008bceff502c5f33c05ec38b5424043b510c567c4b3b51107f468b74240c3b71047c3d3b71087f388b415085c0
   prev_func: 0x00499050 — — Guarded Sub-Rectangle Render Dispatch
   next_func: 0x00499140 — Call FUN_00498d20, set vtable.
   xrefs_into: none

GAP 453: 0x0049b071 — 0x0049b0a0 (47 bytes)
   hex_head: 450800000000c7450c00e904ffffffe90b0000009090909090909090909090a1c0cb5c0083c00aa338e27c00c39090
   prev_func: 0x0049b060 — — Free Callback Registration (atexit-like)
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 454: 0x004a1e55 — 0x004a1ea0 (75 bytes)
   hex_head: c023c1a3e8e2e955ffffff8b411485c07505b838a45e008b490485c97505b938a45e00568b7424085051683cd15c0056
   prev_func: 0x004a1e20 — Call FUN_00566650 three times with different params, then FU
   next_func: 0x004a1ea0 — — Reverse Dynamics Stub
   xrefs_into: none

GAP 455: 0x004b218a — 0x004b21a0 (22 bytes)
   hex_head: 90909090909068a0214b00e8a4590d0059c390909090
   prev_func: 0x004b2180 — — Thunk to FUN_004b3ad0
   next_func: 0x004b21a0 — — SeasonScoringDBCallback
   xrefs_into: none

GAP 456: 0x004b7fff — 0x004b8010 (17 bytes)
   hex_head: 90387f4b003c7f4b00437f4b004a7f4b00
   prev_func: 0x004b7de0 — � Hot Lap File Writer
   next_func: 0x004b8010 — — File/Setting Existence Check
   xrefs_into: none

GAP 457: 0x004c2fea — 0x004c3020 (54 bytes)
   hex_head: 9090909090906800304c00e8444b0c0059c390909090b96cc38a00e926190000909090909090e80b000000e916000000
   prev_func: 0x004c2fe0 — — Delegation
   next_func: 0x004c3020 — — Delegation Thunk
   xrefs_into: none

GAP 458: 0x004ce813 — 0x004ce860 (77 bytes)
   hex_head: 32c05ec204005fb0e9b4fbffff8bc133c9890889480489480889480c89481089481489481889481c8948208948248948
   prev_func: 0x004ce3e0 — — CollisionEffectDispatch
   next_func: 0x004ce860 — — String List Lookup
   xrefs_into: none

GAP 459: 0x004d7fd0 — 0x004d7fe0 (16 bytes)
   hex_head: c87f4d00b07f4d00b87f4d00c07f4d00
   prev_func: 0x004d7fa0 — — Switch-Based Global Lookup (0..3)
   next_func: 0x004d7fe0 — � Delegate with Dereference
   xrefs_into: none

GAP 460: 0x004dc2b7 — 0x004dc340 (137 bytes)
   hex_head: 00e83d2fe9c6ffffffe80b000000e916000000909090909090b9b4d38a00e926b7080090909090909068f0c24d00e854
   prev_func: 0x004dc290 — — Fixed Node Allocator
   next_func: 0x004dc340 — — Alignment/Position Switch
   xrefs_into: none

GAP 461: 0x004f6ae9 — 0x004f6b40 (87 bytes)
   hex_head: 9090909090909068006b4f00e84410090059c3909090905657be74fc8a00bf2d0000008d6424008b46ec83ee1485c074
   prev_func: 0x004f6ab0 — — Global Table Initialization
   next_func: 0x004f6b40 — — Tire/Grip Data Array Init (Rear)
   xrefs_into: none

GAP 462: 0x00513cf0 — 0x00513d2f (63 bytes)
   hex_head: 8b442404f6800c01000020740f8b505cb90003000023d13bd17507c3f6405d08751c56ff7424108db000010000ff7424
   prev_func: 0x00513cd8 — — AnimationHandleAlloc
   next_func: 0x00513d2f — — Short Computation / Zero-Init 16 Dwords
   xrefs_into: none

GAP 463: 0x00520416 — 0x0052042e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052035e — — VectorNormalizeThreshold
   next_func: 0x0052042e — — Velocity/Friction Clamp with Stiction Threshold
   xrefs_into: none

GAP 464: 0x0052a068 — 0x0052a090 (40 bytes)
   hex_head: 789b52004e9c5200fe9c5200599d5200e29d5200089e5200f99e52000fa0520061a05200e29f5200
   prev_func: 0x00529af8 — — Field Setter with VTable Alloc
   next_func: 0x0052a090 — — Indirect Call Dispatch
   xrefs_into: none

GAP 465: 0x0053b018 — 0x0053b0d0 (184 bytes)
   hex_head: ff159ce25900ffff518b4c24080fb654240a33c08ac10fb6cd8954240889442400db4424008b44240c894c240cd80d60
   prev_func: 0x0053b000 — — WrapperTo55EF88
   next_func: 0x0053b0d0 — — Arithmetic/Comparison (Singleton Alloc)
   xrefs_into: none

GAP 466: 0x0054a1a6 — 0x0054a1c0 (26 bytes)
   hex_head: 9090909090909090909033c08981a80100008981a4010000c390
   prev_func: 0x0054a160 — — Flag Bit Setter (0x1000/0x2000)
   next_func: 0x0054a1c0 — � Bitmask Global Set/Clear
   xrefs_into: none

GAP 467: 0x0055678d — 0x005567f5 (104 bytes)
   hex_head: 909090558bec528b4508f76d0c050080000083d2000facd0105ac9c3558bec515233c98b450823c0790341f7d8990fa4
   prev_func: 0x00556760 — @ 0x00556760 — 45 bytes
   next_func: 0x005567f5 — @ 0x005567f5 — 101 bytes
   xrefs_into: none

GAP 468: 0x00568782 — 0x005687f0 (110 bytes)
   hex_head: 8bff7b8756007d8756000000010000000000000001010000000001010101010101010101000001000101000101010101
   prev_func: 0x00568750 — — ASCII Char Code Validation (Printable vs Special)
   next_func: 0x00568910 — 
   xrefs_into: none

GAP 469: 0x0057ae3a — 0x0057ae70 (54 bytes)
   hex_head: 9090909090906850ae5700e8f4cc000059c390909090b9193c8d00e93adb0100909090909090e80b000000e916000000
   prev_func: 0x0057ae30 — — [PARTIAL] Unknown
   next_func: 0x0057ae70 — — Single Function Call Wrapper (to constructor)
   xrefs_into: none

GAP 470: 0x00581939 — 0x005819c0 (135 bytes)
   hex_head: 01cc0000cc3bff56578b7c240c33c03bf8746a8b3133d23bf07462393e740e8bd68b76043bf075f35f5ec208003b7108
   prev_func: 0x005818e0 — — List Destruction with Handle Close
   next_func: 0x005819c0 — — Linked List Destroy with Vtable Destructor Call
   xrefs_into: none

GAP 471: 0x0058763b — 0x00587680 (69 bytes)
   hex_head: e819f0e7ff8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8d404000059
   prev_func: 0x00587620 — — Buffer Write with Params
   next_func: 0x00587680 — � Single Delegate (thunk to FUN_00598815)
   xrefs_into: none

GAP 472: 0x00591629 — 0x0059163b (18 bytes)
   hex_head: e88efcffffc3e840ffffffc3d9f3c3d9f2c3
   prev_func: 0x00591574 — — Double-Precision Float Classification
   next_func: 0x0059163b — If DAT_005e9ad0==0: calls FUN_00591bf1; else errno 0x21
   xrefs_into: none

GAP 473: 0x0059cab2 — 0x0059cb33 (129 bytes)
   hex_head: cccccccccccccccccccccccccccc8b45e050e806b1feff59c3b8b8ab5b00e9abd8feffcccccccccccccccccccccc8d4d
   prev_func: 0x0059caa8 — — CxxFrameHandlerWrapper
   next_func: 0x0059cb33 — — C++ Exception Handler Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_K.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
