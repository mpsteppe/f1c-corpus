# WORKER R — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker R of 20, items 727–768.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_R.md

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

GAP 727: 0x004076d4 — 0x00407be0 (1292 bytes)
   hex_head: e359008115f4e3e962fdffff5356578bf98b473885c08947400f84be0000008b1885db0f84b40000008b4c2410390b74
   prev_func: 0x00407520 — — Linked List Node Insert
   next_func: 0x00407be0 — — Linked List Node Removal by Key
   xrefs_into: none

GAP 728: 0x0040b57a — 0x0040b5a0 (38 bytes)
   hex_head: 83e8d9b0ffff568bf1e818000000f644240801740956e83ac6170083c4048bc65ec204009090
   prev_func: 0x0040b560 — — Struct Init with Vtable
   next_func: 0x0040b5a0 — — VTable Switch with Virtual Call
   xrefs_into: none

GAP 729: 0x0040f0b0 — 0x0040f0d0 (32 bytes)
   hex_head: 8cef4000b2ef40008cef4000b2ef40008cef4000b2ef40009090909090909090
   prev_func: 0x0040ef70 — — Physics State Vector Conversion
   next_func: 0x0040f0d0 — — Short Computation (Conditional Multi-Init)
   xrefs_into: none

GAP 730: 0x004141d7 — 0x00414370 (409 bytes)
   hex_head: ff1544e15900ffffffe80b000000e916000000909090909090b9e8a55e00e9660e00009090909090906810424100e834
   prev_func: 0x004141a0 — — Short Computation (Array Lookup)
   next_func: 0x00414370 — — Short Computation (Conditional Free)
   xrefs_into: none

GAP 731: 0x0041f55b — 0x0041f5d0 (117 bytes)
   hex_head: 908cf3410093f341009af34100a1f34100a8f34100aff34100b6f34100bdf34100c4f34100cbf34100d2f34100d9f341
   prev_func: 0x0041f220 — — Championship Points Accumulator
   next_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   xrefs_into: none

GAP 732: 0x0042cea0 — 0x0042cf10 (112 bytes)
   hex_head: 40ce420046ce42004cce420052ce420058ce420088ce42008ece420094ce42006ace420070ce420076ce42007cce4200
   prev_func: 0x0042ce30 — — Session Type Name Lookup
   next_func: 0x0042d350 — — Session Reset
   xrefs_into: none

GAP 733: 0x0043b9d8 — 0x0043ba20 (72 bytes)
   hex_head: a2b943004eb9430066b94300b4b943007eb9430090b94300c6b94300d5b9430000070707070701020707070307070707
   prev_func: 0x0043b930 — — SolverDispatch (physics solver selector)
   next_func: 0x0043ba20 — — Constraint Force Solver
   xrefs_into: none

GAP 734: 0x0044c850 — 0x0044c860 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c830 — — ThunkCollisionInitA
   next_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   xrefs_into: none

GAP 735: 0x0044cc02 — 0x0044cc34 (50 bytes)
   hex_head: 4400e8a4af130059c390909090c3e80b000000e936000000909090909090c705b8a37c001e000000c705bca37c000000
   prev_func: 0x0044cbf0 — — Collision Data Registration Block 1
   next_func: 0x0044cc34 — — Camera/View Zoom Initializer
   xrefs_into: none

GAP 736: 0x0044cfc1 — 0x0044cff4 (51 bytes)
   hex_head: cf4400e8e4ab130059c390909090c3e80b000000e936000000909090909090c705ecc97c0028000000c705f0c97c0000
   prev_func: 0x0044cfb0 — — ThunkCollisionInitB
   next_func: 0x0044cff4 — — Float/float init to (0, 1)
   xrefs_into: none

GAP 737: 0x0044d390 — 0x0044d3a0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d370 — — Collision Data Registration Block 2
   next_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   xrefs_into: none

GAP 738: 0x00454c4b — 0x00454d30 (229 bytes)
   hex_head: 903d4c4500454c4500484c45000001010101010101010101010102020202020202020202020202020202020202020202
   prev_func: 0x00454c20 — — Enum-to-ID Mapping with Default Fallthrough
   next_func: 0x00454d30 — Try two lookup methods: named parameter then numeric ID, sto
   xrefs_into: none

GAP 739: 0x0045d2cd — 0x0045d490 (451 bytes)
   hex_head: 9090908b44240883f802560f849901000083f8010f855b0100008b4c2408a2a0d27c00e87b6b100083f8030f87020100
   prev_func: 0x0045d260 — — Network/Replay Buffer Init
   next_func: 0x0045d490 — — Global Flag-Based State Setter
   xrefs_into: none

GAP 740: 0x00466250 — 0x004662e0 (144 bytes)
   hex_head: 568bf18b4e406a03e843260300c686f40000000133c05ec3a800000033c05ec3568bf18b4e406a03e823260300c686f5
   prev_func: 0x004661b0 — — Game Object Update Frame
   next_func: 0x004662e0 — — State Reset with Zero
   xrefs_into: none

GAP 741: 0x0046a3c7 — 0x0046a560 (409 bytes)
   hex_head: 9090909090909090906a00e8c9feffff33c0c359e879c2f9ffa1ece57c0085c0568bf17505b838a45e005750b968c38a
   prev_func: 0x0046a270 — — VTable Set + Free + Call
   next_func: 0x0046a560 — — Standings Display
   xrefs_into: none

GAP 742: 0x00470632 — 0x00470f20 (2286 bytes)
   hex_head: 0000c70608035a008be98afcffff5181b904030000b5010000c6442400017505c6442400008b44240083c40489442404
   prev_func: 0x00470490 — — Session Message/UI Command Handler
   next_func: 0x00470f20 — — Race/Session Mode Data Loader
   xrefs_into: none

GAP 743: 0x00478e8b — 0x00478ec9 (62 bytes)
   hex_head: 90909090908bd18b825c01000085c07505b838a45e00578bf883c9ff33c0f2aef7d1495f74118b823c01000085c07407
   prev_func: 0x00478e80 — Delegates to FUN_00499b80().
   next_func: 0x00478ed0 — � SessionExitOrChecks
   xrefs_into: none

GAP 744: 0x0047f10d — 0x0047f180 (115 bytes)
   hex_head: 909090568b3568d47c0085f6578bf97505be38a45e0068ccc45e0056b9c0c45e00e8cd48faff85c0742d85f67422bacc
   prev_func: 0x0047f0a0 — — LoadAndProcessMessageBuffer
   next_func: 0x0047f180 — — Doubly-Linked List Append
   xrefs_into: none

GAP 745: 0x00488a1e — 0x00488a30 (18 bytes)
   hex_head: 9090e9abf9ffff9090909090909090909090
   prev_func: 0x004889d0 — — Short Computation / Frame Rate Ratio
   next_func: 0x00488a30 — — UIScrollWidgetUpdate
   xrefs_into: none

GAP 746: 0x0048d9b5 — 0x0048d9d0 (27 bytes)
   hex_head: 8d4900ead8480087d848004cd94800000202010202000001019090
   prev_func: 0x0048d850 — — UI Scroll Area/Auto-Scroll Manager
   next_func: 0x0048d9d0 — — Media Buffer Playback Manager
   xrefs_into: none

GAP 747: 0x004943cf — 0x00494430 (97 bytes)
   hex_head: 90354049005a4049007f404900a4404900df4049000c4149008f414900ad414900cb414900ec414900194249003a4249
   prev_func: 0x00493e20 — — Resource Path Builder
   next_func: 0x00494470 — — UI Destructor with Self-Free
   xrefs_into: none

GAP 748: 0x00499bef — 0x00499c50 (97 bytes)
   hex_head: 908b44240450e8b6fffffff7d81bc040c204008b4e2c85c95e7405e946670b00c38b442408568bf18b08890e8b500489
   prev_func: 0x00499bb0 — — Struct Equality (7 Fields)
   next_func: 0x00499c50 — — Constructor: Init with -1 Sentinels
   xrefs_into: none

GAP 749: 0x0049e670 — 0x0049e7b0 (320 bytes)
   hex_head: 51a1e4547c008b15dc547c00558be98b0c85f0547c008b0495f0547c008b90944800003b91944800000f8590000000b8
   prev_func: 0x0049e663 — — SetFourDwords
   next_func: 0x0049e7b0 — � HUD_TachoTick
   xrefs_into: none

GAP 750: 0x004a6fea — 0x004a7000 (22 bytes)
   hex_head: 9090909090906800704a00e8440b0e0059c390909090
   prev_func: 0x004a6fe0 — � Single Call Wrapper
   next_func: 0x004a7000 — — AutoLoadConfigFileInit
   xrefs_into: none

GAP 751: 0x004b419d — 0x004b41b0 (19 bytes)
   hex_head: 909090e80b000000e916000000909090909090
   prev_func: 0x004b4170 — — Render::Post()
   next_func: 0x004b41b0 — — Short Computation (Call Wrapper)
   xrefs_into: none

GAP 752: 0x004b9f47 — 0x004b9f89 (66 bytes)
   hex_head: 905f9e4b007c9e4b00b49e4b00be9e4b00dd9e4b00419f4b00f69e4b000d9f4b002a9f4b0090909090568bf18d4e08e8
   prev_func: 0x004b9e40 — — Pit Service Steering Animation Step
   next_func: 0x004b9fa0 — — Single Call Wrapper
   xrefs_into: none

GAP 753: 0x004c7c1b — 0x004c7c30 (21 bytes)
   hex_head: e839eaf3ffe80b000000e916000000909090909090
   prev_func: 0x004c7c10 — — Conditional Delegation (if param_1 == 1)
   next_func: 0x004c7c30 — — Single Function Call Wrapper
   xrefs_into: none

GAP 754: 0x004d2448 — 0x004d24a0 (88 bytes)
   hex_head: 5900d95e0c5e59c38b0d9c325c0033c085c9567e398d49008b1485f0547c008bb26440000085f67407403bc17cea5ec3
   prev_func: 0x004d23d0 — — Pit Timer State Init
   next_func: 0x004d24a0 — � Check First Uninitialized Vehicle
   xrefs_into: none

GAP 755: 0x004d92e2 — 0x004d93e0 (254 bytes)
   hex_head: 8bffa3924d00bd924d00cd924d00cd924d00cd924d00dd924d00df924d00000100010100000100000000010101010101
   prev_func: 0x004d9290 — — ID/Type Permission Matrix
   next_func: 0x004d93e0 — — Range Check (1-5)
   xrefs_into: none

GAP 756: 0x004e189e — 0x004e18c0 (34 bytes)
   hex_head: 8bffdd174e003f184e004d184e0073184e0000000000010203030303030303039090
   prev_func: 0x004e17c0 — — Subsystem state machine (activate/deactivate)
   next_func: 0x004e18c0 — — Subsystem ready query
   xrefs_into: none

GAP 757: 0x004fa7b8 — 0x004fa7e0 (40 bytes)
   hex_head: 90a64f0090a64f0090a64f0090a64f0090a64f00a3a64f00cba64f00cba64f009090909090909090
   prev_func: 0x004fa640 — — VidMan::Restart
   next_func: 0x004fac00 — — VidMan::Post()
   xrefs_into: none

GAP 758: 0x0051ef48 — 0x0051ef5e (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ee7e — — Vector Normalize with Threshold
   next_func: 0x0051ef5e — — SSE 4x4 Matrix Multiply
   xrefs_into: none

GAP 759: 0x00520bfa — 0x00520c0e (20 bytes)
   hex_head: 8db600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x00520a7e — — QuaternionToRotationMatrix
   next_func: 0x00520c0e — — SSE Reciprocal Square Root with Newton-Raphson + Quaternio
   xrefs_into: none

GAP 760: 0x0052e051 — 0x0052e080 (47 bytes)
   hex_head: 9090909090909090909090909090906870e05200e8d49a050059c390909090a108018b0085c07405e9f220f8ffc390
   prev_func: 0x0052df90 — Checks CPU feature flags via cpuid instruction.
   next_func: 0x0052e080 — — 64-bit Integer Division
   xrefs_into: none

GAP 761: 0x0053c1b0 — 0x0053c200 (80 bytes)
   hex_head: 68c0c15300e884b9040059c3909090908a0de48e8b00b00284c87523560ac857880de48e8b00bea0788b00bf2a000000
   prev_func: 0x0053c190 — — Arithmetic/Comparison (Loop Call x42)
   next_func: 0x0053c200 — — Delegation Wrapper
   xrefs_into: none

GAP 762: 0x0054ffe4 — 0x00550080 (156 bytes)
   hex_head: 1dff540018ff540000000100010101000101010101010100010101010101010101010101010101000101010101010101
   prev_func: 0x0054fe50 — � String Allocation + Path Extract
   next_func: 0x00550080 — — D3D Texture Creation
   xrefs_into: none

GAP 763: 0x0055eeaf — 0x0055ef24 (117 bytes)
   hex_head: 558bec5657505351528b75088b7d0c8b4510d900d80ed94004d80ed94008d80ed94010d84e04d94014d84e04d94018d8
   prev_func: 0x0055ee20 — (0x0055ee20)
   next_func: 0x0055ef24 — — 3x3 Matrix × Float3 Vector Multiply
   xrefs_into: none

GAP 764: 0x00579ffa — 0x0057a020 (38 bytes)
   hex_head: 9090909090906810a05700e834db000059c390909090b9f03b8d00e9bffa0100909090909090
   prev_func: 0x00579ff0 — � Single Function Call Wrapper
   next_func: 0x0057a020 — — Struct Zero-Init (4 + 8 Words)
   xrefs_into: none

GAP 765: 0x0057b7ac — 0x0057b7f0 (68 bytes)
   hex_head: 90909090568bf1e838000000f644240801740956e80ac4000083c4048bc65ec2040090908b44240456508bf1e8b3b800
   prev_func: 0x0057b780 — — Object Init with VTable + Field Set
   next_func: 0x0057b7f0 — — VTable Pointer Init
   xrefs_into: none

GAP 766: 0x0058543e — 0x00585470 (50 bytes)
   hex_head: 9090568bf18d8e2c010000e8422400008b4c24083bc87e0a8986800000005ec20400898e800000005ec20400cc0000cc
   prev_func: 0x00585400 — — VTable Dispatch with Conditional Branch
   next_func: 0x00585470 — (0x00585470)
   xrefs_into: none

GAP 767: 0x00588a19 — 0x00588a34 (27 bytes)
   hex_head: 558b4c24088b298b411c508b411850e879feffff83c4085dc20400
   prev_func: 0x0058895c — — ScriptFrameProcessor
   next_func: 0x00588c7a — @ 0x00588c7a
   xrefs_into: none

GAP 768: 0x00599754 — 0x0059977e (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x00599707 — — Char-by-Char Backward Scan with Validation
   next_func: 0x0059977e — — Cleanup Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_R.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
