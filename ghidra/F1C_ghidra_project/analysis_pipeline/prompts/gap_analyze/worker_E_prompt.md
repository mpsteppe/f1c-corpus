# WORKER E — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker E of 20, items 173–215.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_E.md

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

GAP 173: 0x00405879 — 0x004058a0 (39 bytes)
   hex_head: 5e83e962ffffff568bf1e818000000f644240801740956e83a23180083c4048bc65ec204009090
   prev_func: 0x004057f0 — — View/Projection Struct Init
   next_func: 0x004058a0 — — Object Constructor with VTable and Sub-Free
   xrefs_into: none

GAP 174: 0x00408712 — 0x00408740 (46 bytes)
   hex_head: 8bff078640000c86400011864000168640001b8640002b86400030864000358640003a8640009090909090909090
   prev_func: 0x004085f0 — � Sound Effect Playback (Positional Audio)
   next_func: 0x00408740 — — Float-Keyed Field Selector
   xrefs_into: none

GAP 175: 0x0040d04d — 0x0040d080 (51 bytes)
   hex_head: 8d490003ce400003ce400003ce40005ace4000e9ce400030cf4000e2ce400083cf4000b5cf4000e8cf40001bd0400090
   prev_func: 0x0040cde0 — — Game Action State Machine
   next_func: 0x0040d090 — — Virtual Dispatch + Conditional Audio
   xrefs_into: none

GAP 176: 0x0040fae4 — 0x0040fb30 (76 bytes)
   hex_head: 66f640008ef64000b6f64000daf64000fff6400024f740009090909033c0568bf1894608894610894618894620894628
   prev_func: 0x0040f600 — — Camera Shake Ring Buffer Write
   next_func: 0x0040fb30 — — Graphics Resource Destructor
   xrefs_into: none

GAP 177: 0x00418da0 — 0x00418db0 (16 bytes)
   hex_head: e80b000000e926000000909090909090
   prev_func: 0x00418d60 — — Destructor with Double Free Pattern
   next_func: 0x00418db0 — — Global Variable Zero-Init
   xrefs_into: none

GAP 178: 0x0042145b — 0x00421470 (21 bytes)
   hex_head: 4d59544800e80b000000e916000000909090909090
   prev_func: 0x00421380 — — CountActiveEntitiesByState
   next_func: 0x00421470 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 179: 0x0043138a — 0x004313c0 (54 bytes)
   hex_head: 83e8c952fdff8b442404d9442408c681a419000000c60101d99c81a81c0000e812000000c20800e06d150083c4145f5e
   prev_func: 0x00430f00 — — Vehicle Stats Estimation Display (ACCEL/TOP SPEED/CORNERIN
   next_func: 0x004313c0 — — Pressure/Force Field Mapping
   xrefs_into: none

GAP 180: 0x0044c5c9 — 0x0044c5e0 (23 bytes)
   hex_head: 000000803f59c3e80b000000e916000000909090909090
   prev_func: 0x0044c550 — — CollisionNormalFromFeature
   next_func: 0x0044c5e0 — — Collision thunk
   xrefs_into: none

GAP 181: 0x0044c9a9 — 0x0044c9c0 (23 bytes)
   hex_head: 9090909090909068c0c94400e884b1130059c390909090
   prev_func: 0x0044c980 — — Collision Global Init (Set 10, -1.0f)
   next_func: 0x0044c9e0 — — Collision Global Struct Init (Block 0xB, unit default)
   xrefs_into: none

GAP 182: 0x0044cd69 — 0x0044cd80 (23 bytes)
   hex_head: 909090909090906880cd4400e8c4ad130059c390909090
   prev_func: 0x0044cd54 — — Initialize Physics Constants
   next_func: 0x0044cda0 — — Collision State Init (Slot 0x22, Scale 1.0)
   xrefs_into: none

GAP 183: 0x0044d129 — 0x0044d140 (23 bytes)
   hex_head: 909090909090906840d14400e804aa130059c390909090
   prev_func: 0x0044d100 — — Collision Global Init (Set 0x6b, -1.0f)
   next_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   xrefs_into: none

GAP 184: 0x0044d4e6 — 0x0044d500 (26 bytes)
   hex_head: 909090909090909090906800d54400e844a6130059c390909090
   prev_func: 0x0044d4c0 — — CollisionGridInit16x16
   next_func: 0x0044d520 — — CollisionStateInit_17
   xrefs_into: none

GAP 185: 0x0045a833 — 0x0045a8e0 (173 bytes)
   hex_head: e8e4180f005f5e83e994f2ffff83ec0c568bf1dd86d80000006a00d95c24088d442408dd86e000000050d95c2410b9c0
   prev_func: 0x00459ae0 — — Vehicle Physics Velocity/Angular-Velocity Integrator
   next_func: 0x0045a8e0 — � Vehicle Body Position Update
   xrefs_into: none

GAP 186: 0x00461f68 — 0x00461f90 (40 bytes)
   hex_head: c0c3b801000000c38b018b889cb7010085c97405e98f141000c3021310005eb0015f83c440c20400
   prev_func: 0x00461ed0 — — Directory String Processing with Decode
   next_func: 0x00461f90 — — Conditional Network/System Dispatch
   xrefs_into: none

GAP 187: 0x0046712f — 0x00467260 (305 bytes)
   hex_head: 9003714600127146002b7146000000000000000000000000000202020202020202020202020202020202020202020101
   prev_func: 0x004670e0 — — Switch on Action ID → Virtual Call
   next_func: 0x00467260 — — Object Constructor with Parameter Setup
   xrefs_into: none

GAP 188: 0x0046c6e6 — 0x0046c74c (102 bytes)
   hex_head: e830ad01005e33c05bc3568bf1e8c8cc01008a442408888674010000c70658fb59008bc65ec2040090908a9174010000
   prev_func: 0x0046c210 — � Championship Standings HTML Writer
   next_func: 0x0046c74c — — Key Binding Array Remove/Shift
   xrefs_into: none

GAP 189: 0x00475116 — 0x00475140 (42 bytes)
   hex_head: 8bceff5038e9c8ffffff568bf1e818000000f644240801740956e89a2a110083c4048bc65ec204009090
   prev_func: 0x004750f0 — � UI Object Init with Zero Fields
   next_func: 0x00475140 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 190: 0x0047abb3 — 0x0047b730 (2941 bytes)
   hex_head: 34d1100083c4048be9e4feffff83ec405355568bf18b86e00000008b2885ed577505bd38a45e008b4e40e84edb0100d8
   prev_func: 0x0047abb0 — — Return 0 Stub
   next_func: 0x0047b730 — — Menu Cursor Navigation Helper
   xrefs_into: none

GAP 191: 0x0048669b — 0x004866ad (18 bytes)
   hex_head: 4d59544800538b5c2408568bf13a5e657407
   prev_func: 0x00486660 — — State Change Notification
   next_func: 0x004866ad — — UI Widget Property Propagator
   xrefs_into: none

GAP 192: 0x0048ab24 — 0x0048b024 (1280 bytes)
   hex_head: 0000c70628be5a008bc65ec351568d442404508bf1c744240800000000e88a0300008b4c2404518bcee8de0400008b44
   prev_func: 0x0048aaa0 — — Linked-List Pool Destructor
   next_func: 0x0048b024 — — Stub Returning Zero
   xrefs_into: none

GAP 193: 0x0048e858 — 0x0048e890 (56 bytes)
   hex_head: 502c5fe9e9feffff568bf18b86e800000085c075138b4e40e8cb8500008b068bce5effa0a00000005ec301892a5d5b33
   prev_func: 0x0048e750 — — Viewport Rectangle Render Setup
   next_func: 0x0048e890 — — Resource Cleanup (Free + Zero)
   xrefs_into: none

GAP 194: 0x00496dd5 — 0x00496e20 (75 bytes)
   hex_head: 8d4900926949009c6949000000010001000101008d4900bd6a4900bd6a4900a66b49004d6c49007f6c49007b6a490002
   prev_func: 0x00496930 — — UI Large Render (Type-based)
   next_func: 0x00496e20 — � Float Threshold Comparison
   xrefs_into: none

GAP 195: 0x0049af84 — 0x0049afa0 (28 bytes)
   hex_head: b0015bc20c008ac35bc20c00e80b000000e916000000909090909090
   prev_func: 0x0049af30 — — Linked List Free
   next_func: 0x0049afa0 — — Wrapper
   xrefs_into: none

GAP 196: 0x004a11bb — 0x004a11d0 (21 bytes)
   hex_head: e89954f6ffe80b000000e916000000909090909090
   prev_func: 0x004a11b0 — — Global Flag Clear
   next_func: 0x004a11d0 — — Wrapper (same as 0049afa0)
   xrefs_into: none

GAP 197: 0x004af382 — 0x004af3a0 (30 bytes)
   hex_head: 8bff38f24a0086f24a00d4f24a001cf34a00909090909090909090909090
   prev_func: 0x004af220 — — TireCompoundClamp
   next_func: 0x004af3a0 — — Physics Parameter Initialization
   xrefs_into: none

GAP 198: 0x004b6059 — 0x004b6130 (215 bytes)
   hex_head: 5e5de9fbfeffff538bd9e8c80000008b83a409000083f8040f879e000000ff248518614b00c783b409000010000000eb
   prev_func: 0x004b5f60 — — LinkedBufferTransfer
   next_func: 0x004b6130 — — Sprite/Overlay List Cleanup
   xrefs_into: none

GAP 199: 0x004bec05 — 0x004bec55 (80 bytes)
   hex_head: 8b4424208da42400000000d98550030000d887a0010000d99fa00100008b34388b86c832000083f8ff0f84a702000085
   prev_func: 0x004beb10 — — AI Overtake / Collision Detection Loop
   next_func: 0x004bec55 — — EngineFailureCheck
   xrefs_into: none

GAP 200: 0x004c9211 — 0x004c9260 (79 bytes)
   hex_head: 56e84eeb0b0083c4048be96afeffff566a008bf1e85600000084c075078bcee8db000000a1a4567c0085c07419d905b8
   prev_func: 0x004c91d0 — — Triple VTable Destructor Release
   next_func: 0x004c9260 — Returns field at +0x20/+0x24/+0x28 based on state at +0x1c.
   xrefs_into: none

GAP 201: 0x004d5c2e — 0x004d5c40 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x004d5be0 — � FIR Filter / Convolution Accumulator
   next_func: 0x004d5c40 — — Short Computation (Global Zero Pair)
   xrefs_into: none

GAP 202: 0x004db0b9 — 0x004db0e0 (39 bytes)
   hex_head: 03b0e9d9fdffff8b411040894110992bc2d1f889411433c0c35ec204009033c08941e9d9ffffff
   prev_func: 0x004db0b0 — — InitTwoFieldsToZero
   next_func: 0x004db0e0 — — Small Struct Constructor
   xrefs_into: none

GAP 203: 0x004ef167 — 0x004ef180 (25 bytes)
   hex_head: 90afe34e00bae44e0004e94e0004e94e009090909090909090
   prev_func: 0x004ee2d0 — � Vehicle Dynamics Update (Brake/Tire/Suspension)
   next_func: 0x004ef180 — — WheelContactTransform
   xrefs_into: none

GAP 204: 0x00504f3a — 0x00504f5a (32 bytes)
   hex_head: d64c5000464c50004f4c5000584c5000614c50006a4c5000734c50007c4c5000
   prev_func: 0x00504b37 — — COM Interface Vector Processing Method
   next_func: 0x00504f5a — Complex buffer allocation with vector construction and float
   xrefs_into: none

GAP 205: 0x0051fea4 — 0x0051febe (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051fd90 — — Rotation matrix to axis-angle conversion
   next_func: 0x0051febe — — Quaternion Construction/Transform (SSE)
   xrefs_into: none

GAP 206: 0x00527393 — 0x00527578 (485 bytes)
   hex_head: 0f0e8b4424048b54240c8b4c24080f6f020f6e4a080f6f110f6e59080f0fd0b40f0fd9b40f0fd2ae0f0fd39e0f7f000f
   prev_func: 0x005272b5 — — 3DNow! Cubic Bezier Interpolation
   next_func: 0x00527578 — Normalize 2-component 3DNow! packed float vector using SIMD 
   xrefs_into: none

GAP 207: 0x0053554c — 0x00535560 (20 bytes)
   hex_head: 909090906a0133d2e837feffffc3c8e8f910edff
   prev_func: 0x005354e0 — � File Open by Type
   next_func: 0x00535560 — — 4-Bit Field Pack
   xrefs_into: none

GAP 208: 0x00545b8a — 0x00545bb0 (38 bytes)
   hex_head: 90909090909081a1ec000000ff7fffffc390909090908189ec00000000800000c3e8a90aecff
   prev_func: 0x00545a40 — � Visible Object List Collection
   next_func: 0x00545bb0 — — Scene Instance Collection
   xrefs_into: none

GAP 209: 0x0055422c — 0x00554260 (52 bytes)
   hex_head: eb3f5500c74055009e41550023425500344155000e40550058405500b44155009e415500234255002342550023425500
   prev_func: 0x00553fc0 — (0x00553fc0)
   next_func: 0x00554260 — — Enum-to-Field-Offset Setter
   xrefs_into: none

GAP 210: 0x00564081 — 0x00564110 (143 bytes)
   hex_head: 7a0783c8ff83c408c333c083c408c38b4c24088b15b4468d008b442404568b098b92800000008b306838a45e00e8fd03
   prev_func: 0x00564000 — — PhysicsObjectNameCompare
   next_func: 0x00564220 — — String Tokenizer (strtok Equivalent)
   xrefs_into: none

GAP 211: 0x0057aa1a — 0x0057aa50 (54 bytes)
   hex_head: 9090909090906830aa5700e814d1000059c390909090b9fa3b8d00e916010000909090909090e80b000000e926000000
   prev_func: 0x0057aa10 — — Single Function Call Wrapper
   next_func: 0x0057aa50 — @ 0x0057aa50
   xrefs_into: none

GAP 212: 0x0057ef97 — 0x0057f0c8 (305 bytes)
   hex_head: a4e15900e9d3feffff83ec38555733ff8be9897c2408e8ce660000dd85e0000000db442478dc0d08ea5900ded9dfe025
   prev_func: 0x0057ef80 — — VtableDeleteWrapper
   next_func: 0x0057f0c8 — — NetworkSocketAddressInit
   xrefs_into: none

GAP 213: 0x00586c86 — 0x00586ca0 (26 bytes)
   hex_head: b8010000005e59c20c008b014083f80689010f9cc0c390909090
   prev_func: 0x00586aa0 — ```
   next_func: 0x00586ca0 — � Bit-Field Extraction with Status
   xrefs_into: none

GAP 214: 0x0058d857 — 0x0058d9be (359 bytes)
   hex_head: eb0233c0e992f3ffffc68570fffffffe0aed754bd9c9d9f1eb0dc68570fffffffe32edd9eadec9e83b010000d9e8dec1
   prev_func: 0x0058d849 — — Read 2-Byte Value from Stream Pointer
   next_func: 0x0058d9be — — x87 pow(2,x) / exp2 via f2xm1
   xrefs_into: none

GAP 215: 0x0059bacc — 0x0059bae8 (28 bytes)
   hex_head: 568bf1e8cffffffff644240801740756e8eec0feff598bc65ec20400
   prev_func: 0x0059baa3 — — Type-Info Destructor
   next_func: 0x0059bae8 — Calls FUN_0059c127(param_1, param_2[0], param_2[1], 0)
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_E.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
