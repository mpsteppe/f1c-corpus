# WORKER G — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker G of 20, items 259–301.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_G.md

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

GAP 259: 0x00405a46 — 0x00405b00 (186 bytes)
   hex_head: 00c74658000000005ec38b415885c0740e8b401085c0740750ff15d4e35900c37407508115fce35900c383ec2c53568b
   prev_func: 0x00405a30 — — StopAudioSample
   next_func: 0x00405b00 — — Audio Resource Release
   xrefs_into: none

GAP 260: 0x00408e1b — 0x00409440 (1573 bytes)
   hex_head: 4d59544800b85c200000e896f3170053558bac246820000085ed56578bf10f84ee0500008d4c2418e868da150033c0b9
   prev_func: 0x00408de0 — Conditionally call subsystem functions based on state flags.
   next_func: 0x00409440 — — View/Camera Mode Dispatch
   xrefs_into: none

GAP 261: 0x0040d197 — 0x0040d1b0 (25 bytes)
   hex_head: 907fd140001fd1400037d140004fd1400067d1400090909090
   prev_func: 0x0040d100 — — Game State Branch Dispatch
   next_func: 0x0040d1b0 — — Session Phase Dispatch with Cascade Checks
   xrefs_into: none

GAP 262: 0x00410f44 — 0x00410f60 (28 bytes)
   hex_head: 1c0d4100350d41004e0d4100670d4100050e4100b10e410090909090
   prev_func: 0x00410bc0 — — Wheel Controller Input Decoder
   next_func: 0x00410f60 — — SceneNodeDecoder
   xrefs_into: none

GAP 263: 0x00419c0a — 0x00419c50 (70 bytes)
   hex_head: 8bffd49b41009f9b4100039c410000010101010101010101010102020102020202010202020201020202020102020202
   prev_func: 0x004199e0 — — AI Retirement/Vehicle Failure Event
   next_func: 0x00419c50 — — Per-Driver Race Commentary
   xrefs_into: none

GAP 264: 0x0042347e — 0x00423490 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x00423459 — — Handle/Resource Cleanup (LocalFree + FreeSid)
   next_func: 0x00423490 — — Single Function Call Wrapper
   xrefs_into: none

GAP 265: 0x00431ba2 — 0x00431bc0 (30 bytes)
   hex_head: 1c81c6840ae81c0000015ec20c00e80b000000e916000000909090909090
   prev_func: 0x00431aa0 — — Setup Date/Angle Display Format
   next_func: 0x00431bc0 — — Thunk
   xrefs_into: none

GAP 266: 0x0044c649 — 0x0044c660 (23 bytes)
   hex_head: 909090909090906860c64400e8e4b4130059c390909090
   prev_func: 0x0044c620 — — Collision State Init (Slot 1)
   next_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   xrefs_into: none

GAP 267: 0x0044ca09 — 0x0044ca20 (23 bytes)
   hex_head: 909090909090906820ca4400e824b1130059c390909090
   prev_func: 0x0044c9f4 — — SteeringSensitivityInit
   next_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   xrefs_into: none

GAP 268: 0x0044cdc9 — 0x0044cde0 (23 bytes)
   hex_head: 9090909090909068e0cd4400e864ad130059c390909090
   prev_func: 0x0044cdb4 — — CollisionScaleInit
   next_func: 0x0044ce00 — — Spatial Node Init (index 35, radius -1.0)
   xrefs_into: none

GAP 269: 0x0044d189 — 0x0044d1a0 (23 bytes)
   hex_head: 9090909090909068a0d14400e8a4a9130059c390909090
   prev_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   next_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   xrefs_into: none

GAP 270: 0x0044d546 — 0x0044d560 (26 bytes)
   hex_head: 909090909090909090906860d54400e8e4a5130059c390909090
   prev_func: 0x0044d520 — — CollisionStateInit_17
   next_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   xrefs_into: none

GAP 271: 0x0045b3dd — 0x0045b400 (35 bytes)
   hex_head: 909090568bf1e818000000f644240801740956e8dac7120083c4048bc65ec204009090
   prev_func: 0x0045b360 — — Short Computation (Constructor/Initializer)
   next_func: 0x0045b400 — — Destructor with Resource Cleanup
   xrefs_into: none

GAP 272: 0x00462de1 — 0x00462e00 (31 bytes)
   hex_head: 8d4900b12d4600b92d4600c12d4600c92d4600d12d46009090909090909090
   prev_func: 0x00462d30 — — Enum-to-Enum Translator
   next_func: 0x00462e00 — — Vehicle Name Accessor
   xrefs_into: none

GAP 273: 0x00467864 — 0x00467e40 (1500 bytes)
   hex_head: cfff502c5f5e33c05dc2040081ec380300005355568bf15733c033dbb9600000008dbc24c8010000f3ab8b4e40899c24
   prev_func: 0x004677e0 — — LinkedListNodeDestructor
   next_func: 0x00467e40 — — credits.txt Parser
   xrefs_into: none

GAP 274: 0x0046cb0b — 0x0046cb50 (69 bytes)
   hex_head: 4d59544800e8ebffffff84c0742733c9908d6424008b048d70d47c0085c07c1269c0c04800004183f968898830075f00
   prev_func: 0x0046cb00 — — Global Sign Check
   next_func: 0x0046cb50 — — Profile Already Exists Page Handler
   xrefs_into: none

GAP 275: 0x00475ff3 — 0x00476030 (61 bytes)
   hex_head: 90a57c00e81df0fde987fdffffb990a57c00e8c6d2fdffb990a57c00e88cd3fdffb990a57c00e942d5fdff90908b0dc0
   prev_func: 0x00475d90 — — 2D Rectangle Drawing with Outline
   next_func: 0x00476030 — — UI Options Constructor (Graphics)
   xrefs_into: none

GAP 276: 0x0047c054 — 0x0047c360 (780 bytes)
   hex_head: 01005e81c48000e9c6feffffdd0590fe8a00568bf1d8ae74010000d99674010000d81d40e45900dfe0f6c4417a0fe8a9
   prev_func: 0x0047beb0 — — File Extension Stripper
   next_func: 0x0047c6c0 — � Double Delegate Call
   xrefs_into: none

GAP 277: 0x00486efb — 0x00486f30 (53 bytes)
   hex_head: 4d595448008bc18a4c240484c9741f8b889800000085c974158b5010528b500c528b50088b40045250e827210100c204
   prev_func: 0x00486ed0 — — Set Four Colors to White
   next_func: 0x00486f30 — Allocate linked list nodes and insert into doubly-linked lis
   xrefs_into: none

GAP 278: 0x0048b5f4 — 0x0048b7e0 (492 bytes)
   hex_head: 00100000008981e953ffffff83ec14568bf18a86ec02000084c0750933c05e83c414c208008b4c24205733c033ff85c9
   prev_func: 0x0048b560 — — Unknown (Path/File Char Validator)
   next_func: 0x0048b7e0 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 279: 0x0048eda1 — 0x0048f590 (2031 bytes)
   hex_head: 000a000000888e7c0100008bc65ec383ec08538b5c241055568bf18b460c8b4c242089018b56108b44242489108b4e04
   prev_func: 0x0048ebd0 — — UI Dimension Capture
   next_func: 0x0048f590 — — Linked List Indexed Accessor
   xrefs_into: none

GAP 280: 0x00498650 — 0x004986a0 (80 bytes)
   hex_head: 8b54240485d2568bf1743a5783c9ff33c08bfaf2aef7d1495f742a528d8e58150000e8d9df0c008b44240c8b4c24108b
   prev_func: 0x004985d0 — — String Truncation Wrapper
   next_func: 0x004986a0 — — Render State Reset
   xrefs_into: none

GAP 281: 0x0049afca — 0x0049afe0 (22 bytes)
   hex_head: 909090909090e80b000000e946000000909090909090
   prev_func: 0x0049afc0 — — CleanupCallbackRegister
   next_func: 0x0049afe0 — — Multi-Call Sequence
   xrefs_into: none

GAP 282: 0x004a1553 — 0x004a1830 (733 bytes)
   hex_head: 9090c70550e27c00e95bfcffff8b4424085633f63d000200000f87dd0100000f84b30100008d48fe83f91e0f87330200
   prev_func: 0x004a1367 — — Window Rect Adjustment
   next_func: 0x004a1830 — � Windows Message Pump with Sleep
   xrefs_into: none

GAP 283: 0x004b1d15 — 0x004b1d90 (123 bytes)
   hex_head: 180090908a41e957ffffff518b5424085332db85d2568bf1744a5783c9ff33c08bfaf2aef7d1495f743a8d4424105052
   prev_func: 0x004b1c80 — — ConfigKeyValueSerialize
   next_func: 0x004b1d90 — — Multi-Field Setter with String Copy
   xrefs_into: none

GAP 284: 0x004b67ac — 0x004b67d0 (36 bytes)
   hex_head: f3664b00fb664b0003674b000b674b0070674b0078674b0080674b0088674b0090909090
   prev_func: 0x004b66e0 — — Lap/Speed Comparison with Switch-Selectable Thresholds
   next_func: 0x004b67d0 — — Steering Alignment Tolerance Check
   xrefs_into: none

GAP 285: 0x004c1643 — 0x004c1660 (29 bytes)
   hex_head: 90ba154c00cd154c00e0154c00f3154c0006164c0019164c002c164c00
   prev_func: 0x004c15a0 — — PitStop Phase Advance
   next_func: 0x004c1660 — @ 0x004c1660 — NOT FOUND
   xrefs_into: none

GAP 286: 0x004c94fb — 0x004c9790 (661 bytes)
   hex_head: e859d1f3ffa1a4567c0083ec0c85c0538bd90f84ac000000a170ae8a008bc881e1ff000000d9048d74ae8a0040d905b8
   prev_func: 0x004c94d0 — � Virtual Release Array (3 elements)
   next_func: 0x004c9790 — — Vtable Destructor + Null
   xrefs_into: none

GAP 287: 0x004d790b — 0x004d7920 (21 bytes)
   hex_head: e849edf2ffe80b000000e916000000909090909090
   prev_func: 0x004d7800 — — Texture/Surface Destroyer
   next_func: 0x004d7920 — — Single Function Call Wrapper
   xrefs_into: none

GAP 288: 0x004db4d6 — 0x004db546 (112 bytes)
   hex_head: b801000000e93bffffff568bf1c706dcd05a008b461085c0740950e8d9c60a0083c404f644240801c7066cd05a007409
   prev_func: 0x004db170 — — Steering/Ackermann Computation
   next_func: 0x004db546 — — Byte Increment on Struct [PARTIAL]
   xrefs_into: none

GAP 289: 0x004f2382 — 0x004f23a0 (30 bytes)
   hex_head: e8100000005f5d5e83c458c20400e80b000000e916000000909090909090
   prev_func: 0x004f2320 — — Vehicle Dynamics State Reset
   next_func: 0x004f23a0 — — Short Computation (Delegation)
   xrefs_into: none

GAP 290: 0x0050c28c — 0x0050c2a6 (26 bytes)
   hex_head: 6a01e8143c0000ff25ec775d006a01e8073c0000ff25dc775d00
   prev_func: 0x0050c27f — — Startup Call Wrapper
   next_func: 0x0050c2a6 — — DirectX Call Wrapper
   xrefs_into: none

GAP 291: 0x00520032 — 0x0052004e (28 bytes)
   hex_head: 8db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ff8e — — SSE 3x4 Matrix-Vector Transform
   next_func: 0x0052004e — — 3×4 Matrix Transform with SSE
   xrefs_into: none

GAP 292: 0x00528e09 — 0x00528f00 (247 bytes)
   hex_head: 8db42600000000cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
   prev_func: 0x00528cc0 — â€” Color Space Transformation (3D LUT / Gamma)
   next_func: 0x00528f00 — — 3D Vector Normalize (3DNow!)
   xrefs_into: none

GAP 293: 0x00536fc3 — 0x00536ff0 (45 bytes)
   hex_head: 0f94c05d5b8d44000183c410c38b4424045052e87d3b050083c408c20400909090909090909090909090909090
   prev_func: 0x00536e90 — — [PARTIAL] Unknown
   next_func: 0x00536ff0 — — Allocator Free Wrapper
   xrefs_into: none

GAP 294: 0x00545ff6 — 0x00546010 (26 bytes)
   hex_head: 8bfff15f5400735f5400a75f5400e15f54009090909090909090
   prev_func: 0x00545f50 — — Audio Volume/Load Computation
   next_func: 0x00546010 — — Audio Engine Initialization
   xrefs_into: none

GAP 295: 0x005544a7 — 0x005544c0 (25 bytes)
   hex_head: 901b43550063435500ab435500194455005344550090909090
   prev_func: 0x005542f0 — @ 0x005542f0
   next_func: 0x005544c0 — — Game State Setting via Virtual Dispatch
   xrefs_into: none

GAP 296: 0x0056459d — 0x00564600 (99 bytes)
   hex_head: 9090908b09e90900000090909090909090909053568bf15733ff8bda8a0684c0741d0fbec050e89d6e020069ffe76c30
   prev_func: 0x00564580 — — Audio Mixer Sample Get with Fallback
   next_func: 0x00564600 — — IndirectDwordCompare
   xrefs_into: none

GAP 297: 0x0057ab43 — 0x0057abb0 (109 bytes)
   hex_head: 90c4000000f6d81bc040c2040053568b35fc3b8d0033db3bf3743155578bfe8b7604385f0c74168b2f3beb74108bcde8
   prev_func: 0x0057ab20 — — Pointer Check with Fallback
   next_func: 0x0057abb0 — (0x0057abb0)
   xrefs_into: none

GAP 298: 0x0057fed1 — 0x005805c0 (1775 bytes)
   hex_head: 0000e82fd8ffff8a8674e9f9fcffff83ec1c5355568d442410578bd950895c241cc644241700e8d44d000084c00f847b
   prev_func: 0x0057fde0 — — Audio Streaming Thread Shutdown
   next_func: 0x005805c0 — — Network Packet Queue Reader
   xrefs_into: none

GAP 299: 0x00586eda — 0x00586f10 (54 bytes)
   hex_head: 90909090909068f06e5800e8540c000059c390909090b9313e8d00e99a1a0100909090909090e80b000000e916000000
   prev_func: 0x00586ed0 — — Thunk to FUN_00598815
   next_func: 0x00586f10 — — Single Function Call Wrapper
   xrefs_into: none

GAP 300: 0x0058dd3e — 0x0058dd75 (55 bytes)
   hex_head: 66813c247f027403d92c245ac3668b0424663d7f02741e6683e02074159bdfe06683e020740cb808000000e8e9feffff
   prev_func: 0x0058dd28 — — Float Exponent Extract with NaN Guard
   next_func: 0x0058dd75 — — FPU Status/Error Handler
   xrefs_into: none

GAP 301: 0x0059c3f5 — 0x0059ca3b (1606 bytes)
   hex_head: ccccccccccccccccccccccff75ace8c7b7feff59c3ff75a4e8bdb7feff59c3ff75b8e8b3b7feff59c3b870a45b00e958
   prev_func: 0x0059c30e — @ 0x0059c30e — 231 bytes
   next_func: 0x0059ca3b — — ExceptionHandlerThunk
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_G.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
