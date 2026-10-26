# WORKER N — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker N of 20, items 559–600.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_N.md

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

GAP 559: 0x00406ff1 — 0x004070e0 (239 bytes)
   hex_head: 89472074068b083bcb75e943feffff53568bf18b464885c074278b464c33db85c07e1e5733ff8b46488b0c0785c97405
   prev_func: 0x00406f90 — — Object Array + Linked-List Walk
   next_func: 0x004070e0 — — Spatial Query with Weighted Distance Selection
   xrefs_into: none

GAP 560: 0x0040a8eb — 0x0040a910 (37 bytes)
   hex_head: 4d595448008b4424045332db85c0740c8b1150ff521c85c0b00175028ac35bc20400909090
   prev_func: 0x0040a890 — — Multi-Field Membership Check
   next_func: 0x0040a910 — — MenuSlotActionDispatch
   xrefs_into: none

GAP 561: 0x0040e74f — 0x0040e770 (33 bytes)
   hex_head: 901fe740002fe740003fe740001fe740002fe740003fe740009090909090909090
   prev_func: 0x0040e710 — — Short Computation (Field Set via Switch Dispatch)
   next_func: 0x0040e770 — — Short Computation / Session Update Dispatch
   xrefs_into: none

GAP 562: 0x00412dc6 — 0x00412e50 (138 bytes)
   hex_head: 8bff992d4100892d4100792d4100692d4100592d4100492d4100392d4100292d4100192d4100062d4100f32c4100e02c
   prev_func: 0x00412c30 — — MapCollisionShapeToBoneIndex
   next_func: 0x00412e50 — â€” DirectInput Scancode Mapping
   xrefs_into: none

GAP 563: 0x0041c3ba — 0x0041c3e0 (38 bytes)
   hex_head: 8bff4ac2410054c241007cc241005ec241007cc241007cc2410068c2410072c2410090909090
   prev_func: 0x0041c0f0 — — Pit Exit / Release Order Commentary
   next_func: 0x0041c3e0 — — Display Message 0x151
   xrefs_into: none

GAP 564: 0x0042bb37 — 0x0042bbd0 (153 bytes)
   hex_head: ff15a0e25900fdffffe80b000000e9360000009090909090905657bed8c65e00bf680000008d6424008bcee8b9ad0900
   prev_func: 0x0042b8d0 — — AI Shift Pattern / Upshifts-Downshifts Config
   next_func: 0x0042bbd0 — — Set Player Vehicle Index (DC)
   xrefs_into: none

GAP 565: 0x00433fb5 — 0x00434000 (75 bytes)
   hex_head: 042813005f5ee993feffff538b5c24085657be01000000568bf953b9c0567c00e826bdffff85c075138a44241433f684
   prev_func: 0x00433ed0 — — Validate Vehicle Configuration File
   next_func: 0x00434000 — — File Load with Flag Preserve
   xrefs_into: none

GAP 566: 0x0044c790 — 0x0044c7a0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c770 — — Collision Callback Registration (DAT_0044c780)
   next_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   xrefs_into: none

GAP 567: 0x0044cb44 — 0x0044cb74 (48 bytes)
   hex_head: e864b0130059c390909090c3e80b000000e936000000909090909090c70508d17c0068000000c7050cd17c0000000000
   prev_func: 0x0044cb30 — — CollisionGridFreeA
   next_func: 0x0044cb74 — — Input Handler Global Reset
   xrefs_into: none

GAP 568: 0x0044cf01 — 0x0044cf34 (51 bytes)
   hex_head: ce4400e8a4ac130059c390909090c3e80b000000e936000000909090909090c705a8a37c0026000000c705aca37c0000
   prev_func: 0x0044cef0 — — Collision Callback Registration (DAT_0044cf00)
   next_func: 0x0044cf34 — — Global State Initializer
   xrefs_into: none

GAP 569: 0x0044d2c1 — 0x0044d2f4 (51 bytes)
   hex_head: d24400e8e4a8130059c390909090c3e80b000000e936000000909090909090c70510a47c003e000000c70514a47c0000
   prev_func: 0x0044d2b0 — — CollisionGridFreeB
   next_func: 0x0044d2f4 — — InitRenderConstantsZeroOne
   xrefs_into: none

GAP 570: 0x0044fa3f — 0x0044fa60 (33 bytes)
   hex_head: 90c2f94400c6f94400cdf94400d4f94400dbf94400e2f94400e9f94400f0f94400
   prev_func: 0x0044f8f0 — — D3D Texture Stage / Render Target Setup
   next_func: 0x0044fa60 — — DirectX Device Initialization
   xrefs_into: none

GAP 571: 0x0045bfe9 — 0x0045c030 (71 bytes)
   hex_head: 909090909090906800c04500e844bb120059c390909090a06cd27c0084c0741aa164d27c0050ff15a8e1590085c0740a
   prev_func: 0x0045bf90 — — Collision Mutex Initialization
   next_func: 0x0045c030 — — Unknown (Struct Init with Float Defaults)
   xrefs_into: none

GAP 572: 0x00465fb6 — 0x00465fd0 (26 bytes)
   hex_head: 8bf15f8bc6e9a1fdffffe80b000000e926000000909090909090
   prev_func: 0x00465d70 — � Recursive Linked List Merge Sort
   next_func: 0x00465fd0 — — Collision Distance Reset
   xrefs_into: none

GAP 573: 0x00469852 — 0x00469872 (32 bytes)
   hex_head: 5e5bc20400b838a45ee9e8fcffff568bf1e8f83a0200508bcee870fbffff5ec3
   prev_func: 0x00469630 — — Setup File Load and Finalize
   next_func: 0x00469872 — — ObjectConstructor (corrupted frame)
   xrefs_into: none

GAP 574: 0x0046ec78 — 0x0046fcf9 (4225 bytes)
   hex_head: e8bbfce9b8feffffa16c665c0081ec1002000055568bb4241c0200008be9538a108a1e8aca3ad3751e84c974168a5001
   prev_func: 0x0046ec10 — — Object Name Matching + Activation
   next_func: 0x0046fcf9 — — ObjectCreate_WithVtable
   xrefs_into: none

GAP 575: 0x004774bb — 0x00477640 (389 bytes)
   hex_head: 4d5954480083ec08535556578be9e8027701008bb5f000000033db3bf374298d9b000000008bfe385f0c8b7604740c8b
   prev_func: 0x00477440 — — UI Element List Destructor
   next_func: 0x00477640 — — Season/Scene Name Accessor
   xrefs_into: none

GAP 576: 0x0047e4a6 — 0x0047e940 (1178 bytes)
   hex_head: cee80ea7000033c05ec381ec04010000a038a45e00568bf133c966894c240557884c240b8844240851b968c38a00e867
   prev_func: 0x0047e440 — � Circuit Info Page
   next_func: 0x0047e940 — Call FUN_00566650 if param_1 non-zero.
   xrefs_into: none

GAP 577: 0x00487f02 — 0x00487f30 (46 bytes)
   hex_head: e8a6e7ffff33c05ec383c8ff5ec3568bf1e818000000f644240801740956e8aafc0f0083c4048bc65ec204009090
   prev_func: 0x00487ed0 — Initializes struct with vtable and two byte params.
   next_func: 0x00487f30 — — VTable Set + Cleanup
   xrefs_into: none

GAP 578: 0x0048d3eb — 0x0048d590 (421 bytes)
   hex_head: 9090909090568bf1c706d0c15a00e8b28afffff644240801740956e8c4a70f0083c4048bc65ec20400007d0689813803
   prev_func: 0x0048d3e0 — — Object Init with VTable + Cleanup
   next_func: 0x0048d590 — — Input Dispatch (Arrow Up/Down: 0xCB, 0xCD)
   xrefs_into: none

GAP 579: 0x00490326 — 0x00490450 (298 bytes)
   hex_head: 90909090909090909090568bf1e8e863ffff83f805771bff2485700349008b066a028bceff5040eb098b166a058bceff
   prev_func: 0x004902c0 — Free linked list nodes with vtable+0(1) notification on each
   next_func: 0x00490450 — — UIWidget_ProcessChildren
   xrefs_into: none

GAP 580: 0x00499222 — 0x00499280 (94 bytes)
   hex_head: 8bb68c00000085f675ec33c05ec38a44240484c074188b41108b510c508b4108528b51048b49505052e800feffffc204
   prev_func: 0x004991e0 — Forwards call to another function. No additional logic.
   next_func: 0x00499280 — Destructor walks linked list calling destructors, frees fiel
   xrefs_into: none

GAP 581: 0x0049b8ae — 0x0049b8d0 (34 bytes)
   hex_head: 8bff1fb8490026b849002db8490034b849002db8490026b849009090909090909090
   prev_func: 0x0049b7a0 — � SteeringInputToGear
   next_func: 0x0049b8d0 — — Speed Multiplier
   xrefs_into: none

GAP 582: 0x004a4810 — 0x004a4830 (32 bytes)
   hex_head: 04484a00ec474a00f2474a00f8474a00fe474a00909090909090909090909090
   prev_func: 0x004a47e0 — � Pit Service Type Name Lookup
   next_func: 0x004a4830 — — Tire Compound Name → ID Mapping
   xrefs_into: none

GAP 583: 0x004b39e8 — 0x004b3a90 (168 bytes)
   hex_head: 21344b00be344b00d3364b0049374b00e1394b0071394b0040344b0093344b000001010101010100d6344b00e1394b00
   prev_func: 0x004b3400 — ? Central Message/Event Dispatcher
   next_func: 0x004b3a90 — — Arithmetic/Comparison (Struct Copy with Header Size)
   xrefs_into: none

GAP 584: 0x004b9cb9 — 0x004b9cd0 (23 bytes)
   hex_head: 909090909090908b01d980340f0000c3005f5e83c40cc3
   prev_func: 0x004b9cb0 — — Vehicle Lifetime Average Accessor
   next_func: 0x004b9cd0 — Delegates to FUN_004b86e0().
   xrefs_into: none

GAP 585: 0x004c48f2 — 0x004c4990 (158 bytes)
   hex_head: 10e870ebffff5d81c4e9c8fcffff33c0568bf18906c74604ffffffff89460889460c894610894614e8d10300008bc65e
   prev_func: 0x004c45d0 — — Vehicle Data Copy
   next_func: 0x004c4990 — — Vehicle Filtering/Selection
   xrefs_into: none

GAP 586: 0x004d003a — 0x004d0060 (38 bytes)
   hex_head: 9090909090906850004d00e8f47a0b0059c390909090b9e0ce8a00e9a6d9f3ff909090909090
   prev_func: 0x004d0030 — — Wrapper
   next_func: 0x004d0060 — — Zero-Init + Sub-Call
   xrefs_into: none

GAP 587: 0x004d8a91 — 0x004d8ab0 (31 bytes)
   hex_head: 8d4900888a4d00478a4d004f8a4d00578a4d005f8a4d00678a4d0090909090
   prev_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   next_func: 0x004d8fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 588: 0x004ddf4c — 0x004ddf70 (36 bytes)
   hex_head: 47dc4d0056dc4d0065dc4d0074dc4d0083dc4d0092dc4d00a1dc4d00b0dc4d00bfdc4d00
   prev_func: 0x004ddad0 — â€” Pit Crew Instance Setup
   next_func: 0x004ddf70 — — Zero-Init Wrapper
   xrefs_into: none

GAP 589: 0x004f8113 — 0x004f81d0 (189 bytes)
   hex_head: 90fc804f00ce804f00e5804f00fc804f00ce804f00e5804f00fc804f00ce804f00e5804f00fc804f0044804f005b804f
   prev_func: 0x004f8030 — — Switch-Based Param Setting
   next_func: 0x004f81d0 — — String Match with Wildcard
   xrefs_into: none

GAP 590: 0x00517e0b — 0x00517e43 (56 bytes)
   hex_head: 207b51007f7b51002b7d5100547d51007d7d5100a67d5100db7d5100e17b5100477c5100747c5100a17c5100ca7c5100
   prev_func: 0x00517ac5 — — [PARTIAL] Unknown
   next_func: 0x00517e43 — — Alloc and Zero Init (Size by Type)
   xrefs_into: none

GAP 591: 0x00520866 — 0x0052087e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x005207ce — — SSEVectorCross
   next_func: 0x0052087e — — SSEVectorMatrixInit
   xrefs_into: none

GAP 592: 0x0052d2a5 — 0x0052d8b0 (1547 bytes)
   hex_head: 0000000ccb00800000000010d45a00cc0000000ccc00800000000010d45a00cd0000000ccd00800000000010d45a00ce
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 593: 0x0053b4a1 — 0x0053b4c0 (31 bytes)
   hex_head: 9090909090909090909090909090908b44240483c02889442404e900000000
   prev_func: 0x0053b4a0 — — Empty Stub
   next_func: 0x0053b4c0 — — Unidentified Logic / 3x3 Rotation Matrix from Quaternion
   xrefs_into: none

GAP 594: 0x0054ea88 — 0x0054eaa0 (24 bytes)
   hex_head: ff15fce359005dc3e80b000000e926000000909090909090
   prev_func: 0x0054e270 — — Bounding-Box Computation from Vertex Data
   next_func: 0x0054eaa0 — Call FUN_00548e00() 1024 (0x400) times.
   xrefs_into: none

GAP 595: 0x0055bdc7 — 0x0055bde0 (25 bytes)
   hex_head: 9090909090909090908b811c010000c348188948e933fdffff
   prev_func: 0x0055bdc0 — — Field Getter at +0x118
   next_func: 0x0055bde0 — — Unidentified Logic / Linked List Indexed Traversal
   xrefs_into: none

GAP 596: 0x00579c47 — 0x00579ccf (136 bytes)
   hex_head: 8a8f570007905700849057000191570074915700df915700429257009d925700f09257003b9357007e935700db935700
   prev_func: 0x00578f76 — — InitPhysicsTransformIdentity
   next_func: 0x00579ccf — — Physics State Zero-Init
   xrefs_into: none

GAP 597: 0x0057b17a — 0x0057b230 (182 bytes)
   hex_head: ccccccff15ff8b41185685c0570f848e0000008b74240c8b1085d27404393274118b400485c075ef5fb8010000005ec2
   prev_func: 0x0057b100 — — Linked-List Buffer Manager Destructor
   next_func: 0x0057b230 — — IntSetInsert
   xrefs_into: none

GAP 598: 0x0058326f — 0x005832e0 (113 bytes)
   hex_head: 9051568b3185f6894c2404743d55578bee8b76048a450884c0741c8b7d0085ff74158b0f85c974068b016a03ff1057e8
   prev_func: 0x00583210 — — Linked List Node Alloc & Prepend
   next_func: 0x005832e0 — @ 0x005832e0 — 122 bytes
   xrefs_into: none

GAP 599: 0x00587a0f — 0x00587a50 (65 bytes)
   hex_head: 908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e80401000059c3909090
   prev_func: 0x005879f0 — — Field Constants Initialization
   next_func: 0x00587a50 — — Thunk to FUN_00598815
   xrefs_into: none

GAP 600: 0x00597303 — 0x00597321 (30 bytes)
   hex_head: 68bd725900ff1584e05900a3e4418d00c3ff35e4418d00ff1584e05900c3
   prev_func: 0x005972bd — � Exception/Error Filter with Magic Comparison
   next_func: 0x00597321 — — IsBadReadPtr Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_N.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
