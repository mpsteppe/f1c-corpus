# WORKER L — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker L of 20, items 474–516.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_L.md

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

GAP 474: 0x00406c9b — 0x00406cc0 (37 bytes)
   hex_head: 4d59544800f644240401568bf1c70698e55900740956e8190f180083c4048bc65ec2040090
   prev_func: 0x00406ba0 — Destructor that destroys 4 linked lists with different clean
   next_func: 0x00406cc0 — — Audio Driver Init
   xrefs_into: none

GAP 475: 0x00409f51 — 0x0040a610 (1727 bytes)
   hex_head: a10814008b0d88fe8a00e90afaffffa170c47c0083ec1885c053568bf18b4e4057751fa088137d0084c07412a144c47c
   prev_func: 0x00409f40 — — VTable Dispatch Chain (GetObject + GetChild)
   next_func: 0x0040a610 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 476: 0x0040e1ae — 0x0040e1c0 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x0040e170 — — Tick/Update Dispatch
   next_func: 0x0040e1c0 — — Delegation Thunk
   xrefs_into: none

GAP 477: 0x00412215 — 0x004122c0 (171 bytes)
   hex_head: 8d4900d71e4100fa1e41001d1f4100dc1f41008f1f4100b41f410001204100262041006a1f41006c2041004920410088
   prev_func: 0x00411e90 — — Sound Event Dispatcher
   next_func: 0x004122c0 — — Session String/Name Lookup
   xrefs_into: none

GAP 478: 0x0041b8f0 — 0x0041b910 (32 bytes)
   hex_head: 99b44100d0b8410081b6410027b84100d0b8410043b841009090909090909090
   prev_func: 0x0041b3c0 — — Pit Selection State Machine
   next_func: 0x0041b910 — — Clear Pit Selection Flags
   xrefs_into: none

GAP 479: 0x0042b887 — 0x0042b8a0 (25 bytes)
   hex_head: ff154ce05900005ec3e80b000000e916000000909090909090
   prev_func: 0x0042b0e0 — — AI Steering & Racing Line Correction
   next_func: 0x0042b8a0 — — Thunk to FUN_004b3db0
   xrefs_into: none

GAP 480: 0x004328b2 — 0x004328e0 (46 bytes)
   hex_head: 0ab838a45e00c20400e9a1ffffff8b0183c0088b0085c07505b838a45e00c3c0108b0085c05e7505b8e9d2ffffff
   prev_func: 0x00432870 — — Path String Combinator
   next_func: 0x004328e0 — — Path Accessor (*param_1)
   xrefs_into: none

GAP 481: 0x0044c721 — 0x0044c740 (31 bytes)
   hex_head: c64400e884b4130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c710 — — RegisterInputDevice0
   next_func: 0x0044c740 — — CollisionGridInit4
   xrefs_into: none

GAP 482: 0x0044cae4 — 0x0044cb14 (48 bytes)
   hex_head: e8c4b0130059c390909090c3e80b000000e936000000909090909090c705dccf7c0067000000c705e0cf7c0000000000
   prev_func: 0x0044cad0 — — Thunk
   next_func: 0x0044cb14 — — Global Initializer (-1.0, 0.0)
   xrefs_into: none

GAP 483: 0x0044cea1 — 0x0044ced4 (51 bytes)
   hex_head: ce4400e804ad130059c390909090c3e80b000000e936000000909090909090c705f4cb7c0025000000c705f8cb7c0000
   prev_func: 0x0044ce90 — — RegisterInputDevice1
   next_func: 0x0044ced4 — — InitFloatConstants
   xrefs_into: none

GAP 484: 0x0044d261 — 0x0044d280 (31 bytes)
   hex_head: d24400e844a9130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d250 — — Thunk
   next_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   xrefs_into: none

GAP 485: 0x0044f42c — 0x0044f460 (52 bytes)
   hex_head: fff3440012f4440000000000000000000000010101010000000000000000000101010101000000000000009090909090
   prev_func: 0x0044f150 — â€” Force Feedback / Joystick Input Processing
   next_func: 0x0044f460 — — PackedFlagRead
   xrefs_into: none

GAP 486: 0x0045bf3c — 0x0045bf50 (20 bytes)
   hex_head: 90909090e80b000000e916000000909090909090
   prev_func: 0x0045bf10 — — Wide Struct Zero-Init
   next_func: 0x0045bf50 — — Single Function Call Wrapper
   xrefs_into: none

GAP 487: 0x00464fd0 — 0x00465150 (384 bytes)
   hex_head: 5668d0e500008bf1e8262c120083c40485c0740d8bc8e825fcffff89068bc65ec333c089068bc65ec35d5be949ffffff
   prev_func: 0x00464f90 — — Threshold-to-Rank Classifier
   next_func: 0x00465150 — — Single Call Wrapper
   xrefs_into: none

GAP 488: 0x00468b4b — 0x00468bf0 (165 bytes)
   hex_head: 4d5954480055578bf98b878401000085c08daf840100007505b838a45e0053568bf0b8ace47c008a088a1e8ad13acb75
   prev_func: 0x00468a00 — — Career Mode Driver Stats Reset
   next_func: 0x00468bf0 — � Grand Prix Results HTML Writer
   xrefs_into: none

GAP 489: 0x0046e6ee — 0x0046e7f0 (258 bytes)
   hex_head: 9090568bf18b4e408b016a2cff501c85c074138bc8e818b2010085c07408508bcee8acfeffff33c05ec3c40001e9d2fe
   prev_func: 0x0046e600 — — Path Builder with Backslash
   next_func: 0x0046e7f0 — — Polling Loop with Branch
   xrefs_into: none

GAP 490: 0x004767cf — 0x00476ec0 (1777 bytes)
   hex_head: 9081ec540300005355568be957896c2410e8eb830100a038a45e008884242401000033c0b90f0000008dbc2425010000
   prev_func: 0x004767c0 — — Renderer State Reset
   next_func: 0x00476ec0 — — Season Scene Search by Name
   xrefs_into: none

GAP 491: 0x0047dcf1 — 0x0047dd10 (31 bytes)
   hex_head: 8d490001dc470022dc470069dc47009edc4700909090909090909090909090
   prev_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   next_func: 0x0047dd10 — — DriverCareerStatsHTMLWriter
   xrefs_into: none

GAP 492: 0x004876bb — 0x00487720 (101 bytes)
   hex_head: 90909090908b442404568bf1398684000000742a8a8ee200000084c975208986840000008b066a018bcec78680000000
   prev_func: 0x004876b0 — — Short Computation (Constructor)
   next_func: 0x00487720 — — Short Computation / State Value Transform
   xrefs_into: none

GAP 493: 0x0048ca30 — 0x0048ca50 (32 bytes)
   hex_head: 568bf1e818000000f644240801740956e88ab10f0083c4048bc65ec204009090
   prev_func: 0x0048ca26 — — IntFieldSetter
   next_func: 0x0048ca50 — — Linked List Destructor (Cleanup + Free)
   xrefs_into: none

GAP 494: 0x0049015e — 0x00490190 (50 bytes)
   hex_head: 90908a44240484c0740cc781e000000000000000eb0ac781e0000000010000008b01c744240401000000ff602c909090
   prev_func: 0x004900a0 — — Unidentified / UI State Machine Update
   next_func: 0x00490190 — — Zero-Check Getter
   xrefs_into: none

GAP 495: 0x00499159 — 0x00499180 (39 bytes)
   hex_head: 085be9d1ffffff568bf1e818000000f644240801740956e85aea0e0083c4048bc65ec204009090
   prev_func: 0x00499140 — Call FUN_00498d20, set vtable.
   next_func: 0x00499180 — — Short Computation (VTable Set)
   xrefs_into: none

GAP 496: 0x0049b1ab — 0x0049b1c0 (21 bytes)
   hex_head: 900eb1490015b149001cb1490023b1490090909090
   prev_func: 0x0049b060 — — Free Callback Registration (atexit-like)
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 497: 0x004a4026 — 0x004a4050 (42 bytes)
   hex_head: ffff5e81c4a4000000c3c74178020000008b496485c9740d6a006a016a016a01e8e57f0a00c390909090
   prev_func: 0x004a4000 — General utility function. See decompiled code for exact beha
   next_func: 0x004a4050 — Updates accumulator based on state at +0x78.
   xrefs_into: none

GAP 498: 0x004b21aa — 0x004b21c0 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004b21a0 — — SeasonScoringDBCallback
   next_func: 0x004b21c0 — — Single Call Wrapper
   xrefs_into: none

GAP 499: 0x004b8d8b — 0x004b8da0 (21 bytes)
   hex_head: 905d8c4b00c08c4b00e68c4b00068d4b003d8d4b00
   prev_func: 0x004b8c40 — — Unidentified Logic (Float Switch with AI/Game Mode Dispatc
   next_func: 0x004b8da0 — — ProcessDriverEntries
   xrefs_into: none

GAP 500: 0x004c302a — 0x004c3050 (38 bytes)
   hex_head: 9090909090906840304c00e8044b0c0059c390909090b968c38a00e936210000909090909090
   prev_func: 0x004c3020 — — Delegation Thunk
   next_func: 0x004c3050 — � State Struct Multi-Field Init
   xrefs_into: none

GAP 501: 0x004cfc65 — 0x004cfc90 (43 bytes)
   hex_head: 8d4900aaf94c009ff94c00a3f94c00aff94c00000301010102020000009090909090909090909090909090
   prev_func: 0x004cf070 — — SpecialFX::Init
   next_func: 0x004cfc90 — — SpecialFX::Restart()
   xrefs_into: none

GAP 502: 0x004d8294 — 0x004d82c4 (48 bytes)
   hex_head: 20e830fcffff83e976ffffff56578d7110bf190000008d9b000000008b0e85c97405e875fbffff83c6044f75ef5f5ec3
   prev_func: 0x004d8220 — — Race Init with Constants
   next_func: 0x004d82c4 — — Thunk with Byte Increment + Jump
   xrefs_into: none

GAP 503: 0x004dc401 — 0x004dc430 (47 bytes)
   hex_head: 8d490057c34d0067c34d007dc34d00bfc34d0098c34d00b4c34d00e6c34d00d5c34d00dbc34d009090909090909090
   prev_func: 0x004dc340 — — Alignment/Position Switch
   next_func: 0x004dc430 — — Conditional Dispatch with Global Check
   xrefs_into: none

GAP 504: 0x004f6b79 — 0x004f6bf0 (119 bytes)
   hex_head: 9090909090909068906b4f00e8b40f090059c3909090905657beecf88a00bf2d0000008d6424008b46ec83ee1485c074
   prev_func: 0x004f6b40 — — Tire/Grip Data Array Init (Rear)
   next_func: 0x004f6bf0 — â€” RPM Range Loader (Per Gear)
   xrefs_into: none

GAP 505: 0x0051588c — 0x005158af (35 bytes)
   hex_head: ff742408ff742408e816f9ffff85c059597c0f8b4c2404e807e5ffff85c07c0233c0c3
   prev_func: 0x00515869 — — File Open and Validate
   next_func: 0x005158af — Calls FUN_00513e2d() and FUN_00515303() with error propagati
   xrefs_into: none

GAP 506: 0x005204f8 — 0x0052050e (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052042e — — Velocity/Friction Clamp with Stiction Threshold
   next_func: 0x0052050e — — SSEMatrix4x4Multiply
   xrefs_into: none

GAP 507: 0x0052c5e9 — 0x0052d214 (3115 bytes)
   hex_head: e8d7fcffff5ec310d45a00000000000c0000800000000010d45a00010000000c0100800000000010d45a00020000000c
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 508: 0x0053b19a — 0x0053b1d0 (54 bytes)
   hex_head: 24e8b9b4ecff8b44240485c074058b511089108b44240885c074058b511489108b44240c85c074058b49188908c20c00
   prev_func: 0x0053b170 — — Three-Field Accessor
   next_func: 0x0053b1d0 — — Triple Field Getter
   xrefs_into: none

GAP 509: 0x0054c251 — 0x0054c320 (207 bytes)
   hex_head: 740c8d6424008b491040e9c9ffffffe80b000000e9260000009090909090905657be408f8b00bf000100008d6424008b
   prev_func: 0x0054c230 — — Linked List Indexed Accessor
   next_func: 0x0054c410 — — QueueResourceCleanup
   xrefs_into: none

GAP 510: 0x0055685a — 0x0055687b (33 bytes)
   hex_head: 558bec83c4fcdbe366c745fe5a5add7dfe668b45fe3c007504b001eb02b000c9c3
   prev_func: 0x005567f5 — @ 0x005567f5 — 101 bytes
   next_func: 0x0055687b — — RDTSC Timestamp Read
   xrefs_into: none

GAP 511: 0x0056f657 — 0x0056f7f9 (418 bytes)
   hex_head: 5f5e5b8be993faffff8bc1c700c0895b00c70588398d00f0fb8c00c7058c398d00b8fc8c00c70590398d0080fd8c00c7
   prev_func: 0x0056f100 — (0x0056f100)
   next_func: 0x0056f80b — — Node Count Check
   xrefs_into: none

GAP 512: 0x0057ae7a — 0x0057aea0 (38 bytes)
   hex_head: 9090909090906890ae5700e8b4cc000059c390909090b9183c8d00e93fec0100909090909090
   prev_func: 0x0057ae70 — — Single Function Call Wrapper (to constructor)
   next_func: 0x0057aea0 — — WindowProc_Ignore6666
   xrefs_into: none

GAP 513: 0x00582331 — 0x00582360 (47 bytes)
   hex_head: 0800000000c7450c0000e9c4ffffff8a410884c0740d8b0985c974078b016a01ff5004c37407c7461000e9d1ffffff
   prev_func: 0x00582310 — — CloseHandle Wrapper
   next_func: 0x00582360 — — Win32 Mutex Create/Recreate
   xrefs_into: none

GAP 514: 0x0058768a — 0x005876c0 (54 bytes)
   hex_head: 90909090909068a0765800e8a404000059c390909090b9393e8d00e9ea120100909090909090e80b000000e916000000
   prev_func: 0x00587680 — � Single Delegate (thunk to FUN_00598815)
   next_func: 0x005876c0 — — Single Function Call Wrapper
   xrefs_into: none

GAP 515: 0x0059573c — 0x005957bd (129 bytes)
   hex_head: 53576a0233dbe8a388ffff596a035f393d405a8d007e5d56a1244a8d008bf7c1e6028b040685c07441f6400c83740d50
   prev_func: 0x00595733 — — __amsg_exit Runtime Error (CRT)
   next_func: 0x005957bd — — Memory Allocator Init (0x1000)
   xrefs_into: none

GAP 516: 0x0059cb3d — 0x0059d6a9 (2924 bytes)
   hex_head: cccccc8b4dece92867feff8b4df0e9304dfeffb858ac5b00e926d8feffcccccccccccc8b4dece9f867feff8b4df0e970
   prev_func: 0x0059cb33 — — C++ Exception Handler Wrapper
   next_func: 0x0059d6a9 — — Null-Checked Call Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_L.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
