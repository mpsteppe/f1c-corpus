# WORKER T — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker T of 20, items 811–852.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_T.md

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

GAP 811: 0x00408200 — 0x00408210 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x004081e0 — General utility function. See decompiled code for exact beha
   next_func: 0x00408210 — — Delegation Wrapper to FUN_00408280
   xrefs_into: none

GAP 812: 0x0040bdd3 — 0x0040be70 (157 bytes)
   hex_head: 1c85c0b00175028ae9e9feffff8bc133c98908894804894808c7400c02000000c74014ffffffff89481889481c894820
   prev_func: 0x0040bd10 — — Multi-Line Text Draw
   next_func: 0x0040be70 — — Keyboard Input Action Mapper
   xrefs_into: none

GAP 813: 0x0040f2d8 — 0x0040f300 (40 bytes)
   hex_head: d7f140000bf240003ff24000d7f140000bf240003ff240006ff24000c4f240009090909090909090
   prev_func: 0x0040f1c0 — — Scene Object Loader State Machine
   next_func: 0x0040f300 — — Mode-Dispatched Render/Physics Call
   xrefs_into: none

GAP 814: 0x0041505d — 0x00415090 (51 bytes)
   hex_head: 9090908bc133c9890889480489480889480c89481089481489481889481c89482089482489482889482cc35f885e105e
   prev_func: 0x00414fe0 — — Text Format Struct Initializer (Small)
   next_func: 0x00415090 — — short computation
   xrefs_into: none

GAP 815: 0x0041fa9d — 0x0041fb10 (115 bytes)
   hex_head: 8d4900ecf84100f3f84100faf8410001f9410008f941000ff9410016f941001df9410024f941002bf9410032f9410039
   prev_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   next_func: 0x0041fb10 — — Memory Allocation (unidentified)
   xrefs_into: none

GAP 816: 0x0042dbcb — 0x0042dbe0 (21 bytes)
   hex_head: 9090909090e80b000000e916000000909090909090
   prev_func: 0x0042db20 — — Game::Exit()
   next_func: 0x0042dbe0 — — Thunk to FUN_0042e320
   xrefs_into: none

GAP 817: 0x00448431 — 0x00448480 (79 bytes)
   hex_head: 8a0040a370ae8a00d849e9e1feffff8b4c24048b542408d94104d85a04dfe0f6c4417506b801000000c3d94104d85a04
   prev_func: 0x00448330 — — AudioDSPStateUpdate
   next_func: 0x00448480 — — Weighted Average Interpolation
   xrefs_into: none

GAP 818: 0x0044c8b0 — 0x0044c8c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c890 — — Collision Init Wrapper (DAT_0044c8a0)
   next_func: 0x0044c8c0 — — CollisionFrictionInit_8
   xrefs_into: none

GAP 819: 0x0044cc61 — 0x0044cc94 (51 bytes)
   hex_head: cc4400e844af130059c390909090c3e80b000000e936000000909090909090c705bcc97c001f000000c705c0c97c0000
   prev_func: 0x0044cc50 — — Collision Resource Release (Base)
   next_func: 0x0044cc94 — — Audio/Renderer Float Constant Initializer
   xrefs_into: none

GAP 820: 0x0044d021 — 0x0044d054 (51 bytes)
   hex_head: cf4400e884ab130059c390909090c3e80b000000e936000000909090909090c705d8a37c0029000000c705dca37c0000
   prev_func: 0x0044d010 — — Collision Init Wrapper (PTR_LAB_0044d020)
   next_func: 0x0044d054 — — InitFloatGlobals
   xrefs_into: none

GAP 821: 0x0044d3e1 — 0x0044d400 (31 bytes)
   hex_head: d34400e8c4a7130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d3d0 — — RegisterRendererObject
   next_func: 0x0044d400 — — Spatial Node Init (index 14)
   xrefs_into: none

GAP 822: 0x00455866 — 0x00455b30 (714 bytes)
   hex_head: 8bff9c554500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc564500bc56
   prev_func: 0x00455580 — ? Keyboard Scancode-to-ASCII
   next_func: 0x00455b30 — — TranslateVirtualKey
   xrefs_into: none

GAP 823: 0x0045d50f — 0x0045d530 (33 bytes)
   hex_head: 90568bf1e828fdffff8b4e0c85c9740ce82c571000c7460c000000005ec3909090
   prev_func: 0x0045d500 — Call init function if global flag is zero.
   next_func: 0x0045d530 — — Audio Channel Init
   xrefs_into: none

GAP 824: 0x00466900 — 0x00466910 (16 bytes)
   hex_head: e89b1a020033c0c36a00e856250300c3
   prev_func: 0x004668e0 — — Init + VTable Set
   next_func: 0x00466910 — — Setup Value Display Formatter
   xrefs_into: none

GAP 825: 0x0046a9b5 — 0x0046ad50 (923 bytes)
   hex_head: 00c706e8f959e982ffffff56578bf18dbe0002000057e8b0ffffff8b86f40100008b0f6bc01c8988081b7d008b570489
   prev_func: 0x0046a980 — — ID Pair Match and Clear
   next_func: 0x0046ad50 — — Message/Name Buffer Update
   xrefs_into: none

GAP 826: 0x00471484 — 0x00472cc0 (6204 bytes)
   hex_head: 008bcee8930000008bc65ec3566a018bf1e8c658ffff6aff680c675c008bcec706800d5a00c78634030000eb000000e8
   prev_func: 0x00471440 — — Mode-Specific Screen Setup
   next_func: 0x00472cc0 — — UI String Format + Display
   xrefs_into: none

GAP 827: 0x0047931b — 0x004793ec (209 bytes)
   hex_head: 4d5954480083ec085356578bf18d44240c508d4c2414518b4e40e846f501008b866401000085c089866c0100000f8494
   prev_func: 0x00478ed0 — � SessionExitOrChecks
   next_func: 0x004793ec — — File Path Resolver with Extension Append
   xrefs_into: none

GAP 828: 0x0047f43a — 0x0047fb10 (1750 bytes)
   hex_head: 9090909090905355568b742410578d7eff33db3bfb8be90f8cbb05000081fffc0100000f8daf050000399cbd1c190000
   prev_func: 0x0047f3f0 — — Destructor (3 sub-objects)
   next_func: 0x0047fb10 — � Destructor with List Cleanup and Conditional Free
   xrefs_into: none

GAP 829: 0x00488f3a — 0x00488f90 (86 bytes)
   hex_head: ffe819d7f7ff568bf18b86c800000085c074158b404085c07505b838a45e008b4e4050e8fef500008b4424148b4c2410
   prev_func: 0x00488be0 — — UI Large Render Dispatcher
   next_func: 0x00488f90 — Calls FUN_00485e30, sets vtable, sets byte flag at +0xE4 to 
   xrefs_into: none

GAP 830: 0x0048dfe9 — 0x0048e070 (135 bytes)
   hex_head: 5b83c41cc21000568bf1e82887ffff4883f8047742ff248550e048008b066a068bceff50408b068bceff909c00000033
   prev_func: 0x0048df40 — — UIWidgetDragHandler
   next_func: 0x0048e070 — — Constructor (Zero Init + Defaults)
   xrefs_into: none

GAP 831: 0x004945f0 — 0x00494600 (16 bytes)
   hex_head: e80b000000e926000000909090909090
   prev_func: 0x00494470 — — UI Destructor with Self-Free
   next_func: 0x00494600 — — Collision Global Zeroing
   xrefs_into: none

GAP 832: 0x0049a110 — 0x0049a180 (112 bytes)
   hex_head: 8b5424048b490833c085d27e0f8d490085c9740f8b4924403bc27cf485c974038b492833c085c9740f8da42400000000
   prev_func: 0x0049a102 — — Vtable Field Getter
   next_func: 0x0049a180 — — Zero-Init Int
   xrefs_into: none

GAP 833: 0x0049fda7 — 0x0049feb0 (265 bytes)
   hex_head: ff1554e259000000c351a054e27c0084c0570f85e9000000b95cd27c00e8e71ffcff84c00f84d7000000b95cd27c00e8
   prev_func: 0x0049f870 — � Race Monitor Overlay Renderer
   next_func: 0x0049feb0 — — Merge Sort (Linked List)
   xrefs_into: none

GAP 834: 0x004a8b47 — 0x004a8b80 (57 bytes)
   hex_head: ff1560e35900c204008bc133c9894804c74008ffffffffba5900000089480c895010894814895018c70014cc5a00c3ff
   prev_func: 0x004a8b30 — — Short Constructor
   next_func: 0x004a8b80 — — StaticInitBulk
   xrefs_into: none

GAP 835: 0x004b44d0 — 0x004b44e0 (16 bytes)
   hex_head: e80b000000e906010000909090909090
   prev_func: 0x004b44a0 — � File Operation Open + Write
   next_func: 0x004b44e0 — â€” Fixed-Block Memory Pool Init
   xrefs_into: none

GAP 836: 0x004bb775 — 0x004bb800 (139 bytes)
   hex_head: 8d49003fb74b0045b74b004bb74b0051b74b0057b74b005db74b004bb74b0063b74b0069b74b0090909090568bf18d46
   prev_func: 0x004bb730 — — Failure Category Name Lookup
   next_func: 0x004bb800 — — Zero Two Fields
   xrefs_into: none

GAP 837: 0x004c7c5a — 0x004c7c70 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004c7c50 — — PhysicsVectorGetter
   next_func: 0x004c7c70 — — Passthrough
   xrefs_into: none

GAP 838: 0x004d348d — 0x004d36d0 (579 bytes)
   hex_head: 8d4900922e4d00c52e4d0057304d00e4304d0010314d0086324d009090909090909090a1a4567c0085c0568bf10f8c8d
   prev_func: 0x004d2e50 — — Pit Timer / Race Phase State Machine
   next_func: 0x004d3740 — — Timer/Frame Rate Throttle
   xrefs_into: none

GAP 839: 0x004d9c0a — 0x004d9dd0 (454 bytes)
   hex_head: 00e849caf2ffa1e0547c00d9807434000081ec80000000d81d40e45900565733ffdfe08bf1f6c441751ed94610d81d40
   prev_func: 0x004d99e0 — — HUD Venue / Track Name Overlay
   next_func: 0x004d9dd0 — — Timer Display Render
   xrefs_into: none

GAP 840: 0x004e44f2 — 0x004e45b0 (190 bytes)
   hex_head: d999e0000000ddd883e9c4feffff53568bf1578d4e08e8132a01008d8ee4060000e898b6ffff8d8ec0320000e89d03fc
   prev_func: 0x004e43d0 — — Unidentified Logic (Physics Integration with Clamp/ABS)
   next_func: 0x004e45b0 — — Large Config Function with Physics Constants
   xrefs_into: none

GAP 841: 0x004fb8ea — 0x004fb910 (38 bytes)
   hex_head: 9090909090906800b94f00e844c2080059c390909090b9c0fe8a00e946110000909090909090
   prev_func: 0x004fb8e0 — — Thunk to FUN_004fc9c0
   next_func: 0x004fbd70 — — Camera/Viewport Render Setup
   xrefs_into: none

GAP 842: 0x0051f7be — 0x0051f7ce (16 bytes)
   hex_head: 8bf6538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051f700 — — Newton-Raphson reciprocal with vector interpolation
   next_func: 0x0051f7ce — — Det3x3From4x4
   xrefs_into: none

GAP 843: 0x00520ec1 — 0x00520fc6 (261 bytes)
   hex_head: 908db426000000008dbc27000000008b54240c8b4424080f6f120f6f5a080f7fd40f7fdd0f6f000f6ae20f6aeb0f6f48
   prev_func: 0x00520e0e — — SSE Quaternion Composition from Axis-Angle Components
   next_func: 0x00520fc6 — � SSE 3D Vector Normalization with Length
   xrefs_into: none

GAP 844: 0x0052e530 — 0x0052e550 (32 bytes)
   hex_head: 568bf133c06a01890189410450884108e80b0000008bc65ec35b83c408c20800
   prev_func: 0x0052e520 — — Halt/Assert Handler
   next_func: 0x0052e550 — — Bounds-Checked Byte Setter
   xrefs_into: none

GAP 845: 0x0053d1c1 — 0x0053d1f0 (47 bytes)
   hex_head: 5f5e5d33c05b81c400010000c20c008b44240450e81600000085c074078bc8e80b570100c20400ff155ce059000400
   prev_func: 0x0053d130 — Searches linked list for matching wide string, frees param_1
   next_func: 0x0053d1f0 — — Wide-String Linked List Search
   xrefs_into: none

GAP 846: 0x00551db3 — 0x00551dd0 (29 bytes)
   hex_head: 90381d55003f1d5500461d55004d1d5500909090909090909090909090
   prev_func: 0x00551cf0 — — Bink Video Frame Render
   next_func: 0x00551dd0 — — Bink Video Frame Decoder
   xrefs_into: none

GAP 847: 0x005604c0 — 0x005609de (1310 bytes)
   hex_head: 558bec83c4fc5657608b4530668945fefc8b7d188b7508d165288b45148b5510f7e203450c03450c03f08b45248b5520
   prev_func: 0x00560410 — 
   next_func: 0x005609de — ```
   xrefs_into: none

GAP 848: 0x0057a55b — 0x0057a570 (21 bytes)
   hex_head: 90909090908b018a405dc390909090909090909090
   prev_func: 0x0057a4f0 — — Virtual Function Dispatch with Stack Frames
   next_func: 0x0057a570 — — Byte Field Setter at Offset +0x5d
   xrefs_into: none

GAP 849: 0x0057ca07 — 0x0057cb50 (329 bytes)
   hex_head: e35900b0015ec2080083ec6c8b4424708d54242cc644242c002bd08a08880c024084c975f6538d442430686c3f5c0050
   prev_func: 0x0057c950 — — Thread-Safe Linked-List Lookup with Mutex + Data Copy
   next_func: 0x0057d5d0 — — Structured Memory Copy with Header Prepend
   xrefs_into: none

GAP 850: 0x00585d63 — 0x00585de0 (125 bytes)
   hex_head: 7407568115a4e159005ec20400568bf1576a058b861806000033ff50ff15a0e159003d02010000744783f8ff74428b54
   prev_func: 0x00585d20 — — Mutex-Protected Pointer Read + Release
   next_func: 0x00585de0 — — QueueUserAPC Async Procedure Call
   xrefs_into: none

GAP 851: 0x00589d97 — 0x00589db0 (25 bytes)
   hex_head: cccccccccccccccccc8d42ff5bc38da424000000008d642400
   prev_func: 0x00589d7d — — Utility Function / Function Pointer Array Call-All
   next_func: 0x00589db0 — 
   xrefs_into: none

GAP 852: 0x0059a38d — 0x0059a3a9 (28 bytes)
   hex_head: 568bf1e8dcfafffff644240801740756e82dd8feff598bc65ec20400
   prev_func: 0x0059a371 — Call FUN_00599d17 then conditionally free param_1 based on p
   next_func: 0x0059a3a9 — — Stream Creation with Flag Init
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_T.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
