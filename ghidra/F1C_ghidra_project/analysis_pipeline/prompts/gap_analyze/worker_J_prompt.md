# WORKER J — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker J of 20, items 388–430.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_J.md

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

GAP 388: 0x00406b44 — 0x00406b60 (28 bytes)
   hex_head: 909090909090909090909090d94150c3909090909090909090909090
   prev_func: 0x00406b30 — — Integer Setter
   next_func: 0x00406b60 — — MenuSelectSetter
   xrefs_into: none

GAP 389: 0x004099de — 0x00409a00 (34 bytes)
   hex_head: 90908b0d64fe8a006a006a20e8110814008b0d88fe8a00e9a6c11300909090909090
   prev_func: 0x00409970 — — Conditional Camera Pipeline Setup
   next_func: 0x00409a00 — — CameraModeViewportUpdate
   xrefs_into: none

GAP 390: 0x0040de4b — 0x0040de60 (21 bytes)
   hex_head: 9047de400009de4000000000010101019090909090
   prev_func: 0x0040ddf0 — — Cinematic Event State Machine
   next_func: 0x0040de60 — ? AI Behavior State Machine
   xrefs_into: none

GAP 391: 0x004119a3 — 0x004119d0 (45 bytes)
   hex_head: d8f85b00c702e0f85b00c21400a1d0a55e0085c0740750e81062170059c35b59c208005f5e5d33c05b59c20800
   prev_func: 0x00411840 — — Font Rendering Prep
   next_func: 0x004119d0 — — Short Computation (Range Check Classification)
   xrefs_into: none

GAP 392: 0x0041ad5d — 0x0041ad80 (35 bytes)
   hex_head: 8d4900f0ac4100f0ac4100f7ac4100feac410005ad41000cad410013ad410090909090
   prev_func: 0x0041ac50 — � Race Event Sound Dispatch
   next_func: 0x0041ad80 — � Overtake / Position Swap
   xrefs_into: none

GAP 393: 0x004263e9 — 0x00426430 (71 bytes)
   hex_head: 9090ded9dfe0f6c44175e4d981cc370000d81dcce85900dfe0f6c44175d1d981c4380000d81dcce85900dfe0f6c44175
   prev_func: 0x00426330 — — Physics Gear/Shift Logic with Thresholds
   next_func: 0x00426430 — â€” AI Waypoint Steering
   xrefs_into: none

GAP 394: 0x0043209e — 0x00432180 (226 bytes)
   hex_head: 9090566a408bf1e8595b150083c40485c0740d8bc8e888fcffff89068bc65ec333c089068bc65ec35e18895e1c8bc65e
   prev_func: 0x00431db0 — — Directory File Enumerator
   next_func: 0x00432180 — — Settings Setup File Read
   xrefs_into: none

GAP 395: 0x0044c6c1 — 0x0044c6e0 (31 bytes)
   hex_head: c64400e8e4b4130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c6b0 — — CollisionDataTeardown (unregister)
   next_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   xrefs_into: none

GAP 396: 0x0044ca84 — 0x0044cab4 (48 bytes)
   hex_head: e824b1130059c390909090c3e80b000000e936000000909090909090c70548d17c0066000000c7054cd17c0000000000
   prev_func: 0x0044ca70 — — Atexit Handler Registration (collision A)
   next_func: 0x0044cab4 — — Render State Float Initialization
   xrefs_into: none

GAP 397: 0x0044ce41 — 0x0044ce74 (51 bytes)
   hex_head: cd4400e864ad130059c390909090c3e80b000000e936000000909090909090c70548a47c0024000000c7054ca47c0000
   prev_func: 0x0044ce30 — — CollisionDataTeardown_2
   next_func: 0x0044ce74 — — InitFloatGlobals
   xrefs_into: none

GAP 398: 0x0044d201 — 0x0044d220 (31 bytes)
   hex_head: d14400e8a4a9130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d1f0 — — Atexit Handler Registration (collision B)
   next_func: 0x0044d220 — — InitMouseAbsAxisY
   xrefs_into: none

GAP 399: 0x0044d5c1 — 0x0044ee10 (6223 bytes)
   hex_head: d54400e8e4a5130059c390909090c3e80b000000e93600000090909090909033c0c70580cc7c0013000000a384cc7c00
   prev_func: 0x0044d5b0 — — Collision Init Registration (DAT_0044d5c0)
   next_func: 0x0044ee10 — — D3D Window/Surface Creation
   xrefs_into: none

GAP 400: 0x0045be3d — 0x0045be50 (19 bytes)
   hex_head: 909090e80b000000e926000000909090909090
   prev_func: 0x0045be00 — — Collision Penalty Scaler
   next_func: 0x0045be50 — — Global State Initializer (Collision System Reset)
   xrefs_into: none

GAP 401: 0x0046493a — 0x00464990 (86 bytes)
   hex_head: 9090909090906850494600e8f431120059c390909090b9a8d27c00e9a6060000909090909090e90b0000009090909090
   prev_func: 0x00464930 — — Single Function Call Wrapper
   next_func: 0x00464990 — — Short Computation / Squared Distance Between 3D Points
   xrefs_into: none

GAP 402: 0x004685df — 0x00468610 (49 bytes)
   hex_head: 90c21000920e0033c05e81c400020000c3568bf1e818000000f644240801740956e8caf5110083c4048bc65ec2040090
   prev_func: 0x004685b0 — Forwards call to another function. No additional logic.
   next_func: 0x00468610 — Destructor sets vtable, frees child pointer at +0x174, calls
   xrefs_into: none

GAP 403: 0x0046d1dc — 0x0046dd30 (2900 bytes)
   hex_head: 90909090568bf157b9b02d7d0033ffe86056050085c0741e83b844b100000275158b4e406aff68746b5c00e834a70200
   prev_func: 0x0046d0d0 — — SessionCheckEndCondition
   next_func: 0x0046dd30 — — Multiplayer Password Validation
   xrefs_into: none

GAP 404: 0x00476359 — 0x004765f0 (663 bytes)
   hex_head: 9c04e957feffff81ec400200005355568bd957895c2414e85b8801008bb3f000000033ed3bf574258bfe8a470c84c08b
   prev_func: 0x00476250 — — Frontend Screen/Loading Display Handler
   next_func: 0x004765f0 — — LoadPath Getter
   xrefs_into: none

GAP 405: 0x0047c8fc — 0x0047daf0 (4596 bytes)
   hex_head: 90909090c705ccff7c000000000033c0c390909056680000803f6a008bf1e8810a0100c786fc00000000000000c70668
   prev_func: 0x0047c860 — — UILoadingPercentDisplay
   next_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   xrefs_into: none

GAP 406: 0x0048752f — 0x00487660 (305 bytes)
   hex_head: 90568bf1e8a8ffffff85c074296a018bcee81bfdffff8bcee814ffffff8b068bceff909800000085c0750b8bcee89ff0
   prev_func: 0x004874e0 — — UI Value Validator
   next_func: 0x00487660 — — UI Object Init with Byte Params
   xrefs_into: none

GAP 407: 0x0048bbd6 — 0x0048c070 (1178 bytes)
   hex_head: 81f8020000e92afdffff568bf18b4e40e8e5bd00003bc68a86e0000000742284c0743e8a86e100000084c074346a008b
   prev_func: 0x0048b9c0 — — Text Input Render / Password Mask
   next_func: 0x0048c070 — � Constructor with Parameter Storage
   xrefs_into: none

GAP 408: 0x0048fe86 — 0x0048feb0 (42 bytes)
   hex_head: 016a01ff502c5ec20800568bf1e818000000f644240801740956e82a7d0f0083c4048bc65ec204009090
   prev_func: 0x0048fe60 — — UI Component Init 5
   next_func: 0x0048feb0 — — VTable + Sub-Init
   xrefs_into: none

GAP 409: 0x00498fde — 0x0049904c (110 bytes)
   hex_head: 9090568bf18b466085c074578b0657ff502884c074208b7e048b4e088b560c8b46102bcf512bc2505752e81379ffff8b
   prev_func: 0x00498fb0 — — List Iteration with VTable Dispatch
   next_func: 0x00499050 — — Guarded Sub-Rectangle Render Dispatch
   xrefs_into: none

GAP 410: 0x0049b051 — 0x0049b070 (31 bytes)
   hex_head: 9090909090909090909090909090906870b04900e8d4ca0e0059c390909090
   prev_func: 0x0049b050 — — Empty Stub
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 411: 0x004a19ab — 0x004a19d0 (37 bytes)
   hex_head: 90909090908b44240450e814650e008b4c240c66890183c404b802000000c2080090909090
   prev_func: 0x004a1990 — — ObjectHandleReader
   next_func: 0x004a19d0 — — StringCompareWithDefault
   xrefs_into: none

GAP 412: 0x004b20f7 — 0x004b2180 (137 bytes)
   hex_head: ff154ce05900ffffff51568b3185f6894c2404744355578bff8bee8a450884c08b760474208b7d0085ff74198b470485
   prev_func: 0x004b20d0 — — Arithmetic/Comparison (Clamp with Bounds)
   next_func: 0x004b2180 — — Thunk to FUN_004b3ad0
   xrefs_into: none

GAP 413: 0x004b7c60 — 0x004b7c80 (32 bytes)
   hex_head: e67b4b00f37b4b00f37b4b00f37b4b00077c4b00f37b4b009090909090909090
   prev_func: 0x004b7a90 — — Pit Timing Update
   next_func: 0x004b7c80 — — NetworkBufferRead
   xrefs_into: none

GAP 414: 0x004c2faa — 0x004c2fe0 (54 bytes)
   hex_head: 90909090909068c02f4c00e8844b0c0059c390909090b988c38a00e9760d0000909090909090e80b000000e916000000
   prev_func: 0x004c2fa0 — — Delegation Wrapper
   next_func: 0x004c2fe0 — — Delegation
   xrefs_into: none

GAP 415: 0x004cdb55 — 0x004cdb90 (59 bytes)
   hex_head: 8d490036db4c003bdb4c0040db4c0045db4c004adb4c004fdb4c0054db4c000000000000010202030606060405909090
   prev_func: 0x004cdb20 — � Steward: Scoring/Overtake/AI Pace
   next_func: 0x004cdb90 — — Constructor: Init Fields
   xrefs_into: none

GAP 416: 0x004d7d79 — 0x004d7e00 (135 bytes)
   hex_head: 0100e967ffffffe80b000000e916000000909090909090b964d28a00e936fdffff90909090909068b07d4d00e894fd0a
   prev_func: 0x004d7cf0 — — Float Wrap + Table Interpolation
   next_func: 0x004d7e00 — — VTable Dispatch Chain
   xrefs_into: none

GAP 417: 0x004dc0ab — 0x004dc1a0 (245 bytes)
   hex_head: e8a9a5f2ff83ec4056576a408d44240c8bf150b934e27c00e83805fcff8b7c244c680000803f680000803f6a026a0168
   prev_func: 0x004dbf90 — — Multi-Color Text Render
   next_func: 0x004dc1a0 — — Double Render Pass
   xrefs_into: none

GAP 418: 0x004f6a9c — 0x004f6ab0 (20 bytes)
   hex_head: 90909090e80b000000e946000000909090909090
   prev_func: 0x004f6a50 — — Quadratic Force/Torque Curve Evaluation
   next_func: 0x004f6ab0 — — Global Table Initialization
   xrefs_into: none

GAP 419: 0x0050ecf9 — 0x0050ed19 (32 bytes)
   hex_head: b7eb500019ec50001cec50001fec500023ec500026ec500029ec50002dec5000
   prev_func: 0x0050eb73 — � Skeleton Animation Blending
   next_func: 0x0050ed19 — — Quaternion Normalize
   xrefs_into: none

GAP 420: 0x00520346 — 0x0052035e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052020e — — 4x4 Matrix Multiply (SSE)
   next_func: 0x0052035e — — VectorNormalizeThreshold
   xrefs_into: none

GAP 421: 0x0052981b — 0x00529af8 (733 bytes)
   hex_head: 05000000000f7ec00f7fc10f6e1d5c935d008bd88bd00fdbc381e300000080c1ea1f33c33b0514945d000f6e1510945d
   prev_func: 0x00529700 — � MMX Polynomial Approximation
   next_func: 0x00529af8 — — Field Setter with VTable Alloc
   xrefs_into: none

GAP 422: 0x0053ad08 — 0x0053ad50 (72 bytes)
   hex_head: ff1550e059000400568bf18d4e04e8851500006a10c70610895b00e8dbce04006a10894610e8d1ce04006a40894620e8
   prev_func: 0x0053acf0 — — Thin wrapper, drops a1
   next_func: 0x0053ad50 — � Multi-Field Free + Cleanup
   xrefs_into: none

GAP 423: 0x00547355 — 0x00547370 (27 bytes)
   hex_head: 8d4900e2725400fe7254001a735400367354009090909090909090
   prev_func: 0x005472d0 — — Float-to-Int Switch (Cases 1-4)
   next_func: 0x00547370 — — Arithmetic/Comparison (String Copy with Offset)
   xrefs_into: none

GAP 424: 0x00556015 — 0x00556040 (43 bytes)
   hex_head: 8d4900855f55008c5f5500935f55009a5f55009f5f55000001020404040404040404040404039090909090
   prev_func: 0x005550e0 — @ 0x005550e0 — 3422 bytes
   next_func: 0x00556040 — — Graphics/Display State Sync with Vehicle
   xrefs_into: none

GAP 425: 0x005679a5 — 0x005679b7 (18 bytes)
   hex_head: 74108b4c240485c97e088b40044985c075f4
   prev_func: 0x005679a0 — Null-check wrapper: returns 0 if param_1 is null, otherwise 
   next_func: 0x005679c0 — — String-Keyed Linked List Search
   xrefs_into: none

GAP 426: 0x0057adfa — 0x0057ae30 (54 bytes)
   hex_head: 9090909090906810ae5700e834cd000059c390909090b9f83b8d00e9bfec0100909090909090e80b000000e916000000
   prev_func: 0x0057adf0 — — Single Function Call Wrapper
   next_func: 0x0057ae30 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 427: 0x00581746 — 0x00581780 (58 bytes)
   hex_head: 15a4e159008bc75f5ec3568bf18a460c84c074158b460450ff15a8e1590085c07407c74604000000005ec3508115a4e1
   prev_func: 0x005816b0 — — Thread Pool Job Dequeue by Type
   next_func: 0x00581780 — — Linked List Node Advance
   xrefs_into: none

GAP 428: 0x005873a3 — 0x00587460 (189 bytes)
   hex_head: 08005e8ac35d5b83c408c208008a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa
   prev_func: 0x00587370 — — Copy Buffer Header Fields + Call Init
   next_func: 0x00587460 — � Array/Struct Alloc with Count + Init
   xrefs_into: none

GAP 429: 0x005909c7 — 0x005910a0 (1753 bytes)
   hex_head: 83ec2c83e03fff24853e755e00d8f083c42cc383c42ccd06d8f883c42cc383c42ccd06d8f083c42cc3def883c42cc3d8
   prev_func: 0x005908b0 — — Extended-Precision Division with Overflow Fixup
   next_func: 0x005910a1 — — Double Arithmetic Wrapper
   xrefs_into: none

GAP 430: 0x0059ca95 — 0x0059caa8 (19 bytes)
   hex_head: cccccccccccccccccccccc8d4db4e9b8dfedff
   prev_func: 0x0059ca8b — — CxxFrameHandlerWrapper
   next_func: 0x0059caa8 — — CxxFrameHandlerWrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_J.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
