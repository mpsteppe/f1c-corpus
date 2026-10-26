# WORKER A — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker A of 3, items 1–284.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_A.md

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

## YOUR GAPS (284)

GAP 1: 0x00401061 — 0x00401180 (287 bytes)
   hex_head: ceffd303f54f75f75f5ee990ffffffe80b000000e916000000909090909090b9c0a25e00e92600000090909090909068
   prev_func: 0x00401030 — — Array Destructor Iterator
   next_func: 0x00401180 — — Ray-Sphere/Quadratic Intersection Test
   xrefs_into: none

GAP 2: 0x00405044 — 0x004053e0 (924 bytes)
   hex_head: 2b180083c404b840a45e00c3568b74240856e885ffffff8bc8e8ae2e000083f8ff740f8b4c240c8901b8010000005ec2
   prev_func: 0x00405030 — — SettingsSaveWrapper
   next_func: 0x004053e0 — — short computation
   xrefs_into: none

GAP 3: 0x00405a46 — 0x00405b00 (186 bytes)
   hex_head: 00c74658000000005ec38b415885c0740e8b401085c0740750ff15d4e35900c37407508115fce35900c383ec2c53568b
   prev_func: 0x00405a30 — — StopAudioSample
   next_func: 0x00405b00 — — Audio Resource Release
   xrefs_into: none

GAP 4: 0x00406b44 — 0x00406b60 (28 bytes)
   hex_head: 909090909090909090909090d94150c3909090909090909090909090
   prev_func: 0x00406b30 — — Integer Setter
   next_func: 0x00406b60 — — MenuSelectSetter
   xrefs_into: none

GAP 5: 0x00406d9b — 0x00406e50 (181 bytes)
   hex_head: 4d595448005153578bf98b474c33db3bc3895c24087e61555633ed8b47488b342803c53bf3743c837e140175108bcee8
   prev_func: 0x00406cc0 — — Audio Driver Init
   next_func: 0x00406e50 — — Audio System Shutdown
   xrefs_into: none

GAP 6: 0x0040721b — 0x004072e0 (197 bytes)
   hex_head: 4d5954480083ec0c83c1588b018b510489442400d94424008b41088b4c2410d91989542404d94424048b542414d91a89
   prev_func: 0x004071f0 — — Audio Sample Position/Volume Setter
   next_func: 0x004072e0 — — Miles Sound System Sample Allocator
   xrefs_into: none

GAP 7: 0x00407fad — 0x004080b0 (259 bytes)
   hex_head: 909090568b74240832c083feff74398b511885d2895120742f8b1285d274298d64240039725c741e8b512085d274068b
   prev_func: 0x00407f10 — — Resource ID Lookup by Name String
   next_func: 0x004080b0 — � Linked List Search by Value
   xrefs_into: none

GAP 8: 0x00408237 — 0x00408290 (89 bytes)
   hex_head: 5f5e5d8be994ffffffe80b000000e916000000909090909090b910a55e00e9863b00009090909090906870824000e8d4
   prev_func: 0x00408220 — Thin wrapper that registers a static data block via FUN_0058
   next_func: 0x00408290 — — State Init with Global Constants
   xrefs_into: none

GAP 9: 0x00408712 — 0x00408740 (46 bytes)
   hex_head: 8bff078640000c86400011864000168640001b8640002b86400030864000358640003a8640009090909090909090
   prev_func: 0x004085f0 — � Sound Effect Playback (Positional Audio)
   next_func: 0x00408740 — — Float-Keyed Field Selector
   xrefs_into: none

GAP 10: 0x004096aa — 0x00409890 (486 bytes)
   hex_head: 8bff8e9440008e9440008e944000ac954000b89540000c9640000c9640000c9640000c96400056578bf98b0d88fe8a00
   prev_func: 0x00409440 — — View/Camera Mode Dispatch
   next_func: 0x00409970 — — Conditional Camera Pipeline Setup
   xrefs_into: none

GAP 11: 0x00409f19 — 0x00409f40 (39 bytes)
   hex_head: 8d4900439a4000719a4000ac9a4000da9a4000679b4000959b4000b89b4000db9b4000379c4000
   prev_func: 0x00409a00 — — CameraModeViewportUpdate
   next_func: 0x00409f40 — — VTable Dispatch Chain (GetObject + GetChild)
   xrefs_into: none

GAP 12: 0x0040a8eb — 0x0040a910 (37 bytes)
   hex_head: 4d595448008b4424045332db85c0740c8b1150ff521c85c0b00175028ac35bc20400909090
   prev_func: 0x0040a890 — — Multi-Field Membership Check
   next_func: 0x0040a910 — — MenuSlotActionDispatch
   xrefs_into: none

GAP 13: 0x0040b48b — 0x0040b560 (213 bytes)
   hex_head: 4d5954480083ec1c5356578b7c242c32db85ff8bf1744e8b460c85c07447688000000057e88205180083c4088d4c240c
   prev_func: 0x0040b450 — — Lookup with Optional Callback
   next_func: 0x0040b560 — — Struct Init with Vtable
   xrefs_into: none

GAP 14: 0x0040bdd3 — 0x0040be70 (157 bytes)
   hex_head: 1c85c0b00175028ae9e9feffff8bc133c98908894804894808c7400c02000000c74014ffffffff89481889481c894820
   prev_func: 0x0040bd10 — — Multi-Line Text Draw
   next_func: 0x0040be70 — — Keyboard Input Action Mapper
   xrefs_into: none

GAP 15: 0x0040c5fe — 0x0040c610 (18 bytes)
   hex_head: 8bfff1c54000fdc54000f1c54000e8c54000
   prev_func: 0x0040c5b0 — — Camera Mode Change Request
   next_func: 0x0040c610 — — Conditional Mode Dispatch with Global Gate
   xrefs_into: none

GAP 16: 0x0040d0ea — 0x0040d100 (22 bytes)
   hex_head: 8bffe2d04000cad04000d2d04000dad0400090909090
   prev_func: 0x0040d0b0 — — Mode-Dispatched Subsystem Call
   next_func: 0x0040d100 — — Game State Branch Dispatch
   xrefs_into: none

GAP 17: 0x0040ddc5 — 0x0040ddf0 (43 bytes)
   hex_head: 8d4900c1dd4000c1dd4000c1dd400092dd400092dd4000b7dd4000c1dd4000909090909090909090909090
   prev_func: 0x0040dd80 — — Short Computation (State Machine)
   next_func: 0x0040ddf0 — — Cinematic Event State Machine
   xrefs_into: none

GAP 18: 0x0040e1ae — 0x0040e1c0 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x0040e170 — — Tick/Update Dispatch
   next_func: 0x0040e1c0 — — Delegation Thunk
   xrefs_into: none

GAP 19: 0x0040e83a — 0x0040e860 (38 bytes)
   hex_head: 8bffcbe74000dae74000dae74000dae74000dae74000dae74000909090909090909090909090
   prev_func: 0x0040e770 — — Short Computation / Session Update Dispatch
   next_func: 0x0040e860 — — short computation
   xrefs_into: none

GAP 20: 0x0040f0b0 — 0x0040f0d0 (32 bytes)
   hex_head: 8cef4000b2ef40008cef4000b2ef40008cef4000b2ef40009090909090909090
   prev_func: 0x0040ef70 — — Physics State Vector Conversion
   next_func: 0x0040f0d0 — — Short Computation (Conditional Multi-Init)
   xrefs_into: none

GAP 21: 0x0040f35e — 0x0040f380 (34 bytes)
   hex_head: 8bff12f3400023f3400034f3400012f3400023f3400034f3400045f3400090909090
   prev_func: 0x0040f300 — — Mode-Dispatched Render/Physics Call
   next_func: 0x0040f380 — — Switch-Based State Handler
   xrefs_into: none

GAP 22: 0x0040f5da — 0x0040f600 (38 bytes)
   hex_head: 8bff8ff54000a8f54000c1f540008ff54000a8f54000c1f5400062f540009090909090909090
   prev_func: 0x0040f550 — — UI/Camera Mode Dispatch with Vehicle Data Read
   next_func: 0x0040f600 — — Camera Shake Ring Buffer Write
   xrefs_into: none

GAP 23: 0x00410f44 — 0x00410f60 (28 bytes)
   hex_head: 1c0d4100350d41004e0d4100670d4100050e4100b10e410090909090
   prev_func: 0x00410bc0 — — Wheel Controller Input Decoder
   next_func: 0x00410f60 — — SceneNodeDecoder
   xrefs_into: none

GAP 24: 0x004119a3 — 0x004119d0 (45 bytes)
   hex_head: d8f85b00c702e0f85b00c21400a1d0a55e0085c0740750e81062170059c35b59c208005f5e5d33c05b59c20800
   prev_func: 0x00411840 — — Font Rendering Prep
   next_func: 0x004119d0 — — Short Computation (Range Check Classification)
   xrefs_into: none

GAP 25: 0x00412aad — 0x00412c30 (387 bytes)
   hex_head: 8d4900cb244100d5244100df244100e9244100f3244100fd2441000725410008264100112541001b254100252541002f
   prev_func: 0x00412490 — ? Game Control Mapping
   next_func: 0x00412c30 — — MapCollisionShapeToBoneIndex
   xrefs_into: none

GAP 26: 0x00413efa — 0x00414010 (278 bytes)
   hex_head: 8bffb93b4100c33b4100cd3b4100d73b4100e13b4100eb3b4100f53b4100ff3b4100093c4100133c41001d3c4100273c
   prev_func: 0x00413b60 — — Season-Specific Team ID Lookup
   next_func: 0x00414010 — — Enum Value Translation (Resource IDs)
   xrefs_into: none

GAP 27: 0x00414477 — 0x004144c0 (73 bytes)
   hex_head: ff15a0e25900ffffffe80b000000e916000000909090909090b918a65e00e91640000090909090909068b0444100e894
   prev_func: 0x00414420 — — Multi-Pointer Free (5 pointers)
   next_func: 0x004144c0 — — TableLookupByIndex
   xrefs_into: none

GAP 28: 0x004184a9 — 0x004184f0 (71 bytes)
   hex_head: 0000005bc21000568bf1e8c891ffff8d8e64080000ba14000000e808c0ffff83c1204a75f533c08bce8886f00a000089
   prev_func: 0x00417f60 — — Track Name → Display ID Lookup
   next_func: 0x004184f0 — — Lazy Renderer/Audio Init Check
   xrefs_into: none

GAP 29: 0x00418da0 — 0x00418db0 (16 bytes)
   hex_head: e80b000000e926000000909090909090
   prev_func: 0x00418d60 — — Destructor with Double Free Pattern
   next_func: 0x00418db0 — — Global Variable Zero-Init
   xrefs_into: none

GAP 30: 0x0041ab19 — 0x0041ab30 (23 bytes)
   hex_head: 8d4900a3aa4100b9aa4100cfaa4100e5aa410090909090
   prev_func: 0x0041aa10 — — AI Session Phase Counter
   next_func: 0x0041ab30 — — Pit State Slot Activation / Commentary
   xrefs_into: none

GAP 31: 0x0041b151 — 0x0041b190 (63 bytes)
   hex_head: 8d49002fb0410048b0410061b041007ab0410093b04100acb04100dbb04100dbb04100dbb04100dbb04100f9b0410017
   prev_func: 0x0041afd0 — � Session Event Commentary (Per Car)
   next_func: 0x0041b190 — � Session End Commentary
   xrefs_into: none

GAP 32: 0x0041c3ba — 0x0041c3e0 (38 bytes)
   hex_head: 8bff4ac2410054c241007cc241005ec241007cc241007cc2410068c2410072c2410090909090
   prev_func: 0x0041c0f0 — — Pit Exit / Release Order Commentary
   next_func: 0x0041c3e0 — — Display Message 0x151
   xrefs_into: none

GAP 33: 0x0041f147 — 0x0041f190 (73 bytes)
   hex_head: ff1538e05900c05bc3568bf185f67420b9b02d7d00e8ef360a008bc8e868200a0085c07e0b837c8614047f04b0015ec3
   prev_func: 0x0041f100 — — Triple-Value Equality Check
   next_func: 0x0041f190 — — Short Computation (Multi-Condition State Check)
   xrefs_into: none

GAP 34: 0x0041fa9d — 0x0041fb10 (115 bytes)
   hex_head: 8d4900ecf84100f3f84100faf8410001f9410008f941000ff9410016f941001df9410024f941002bf9410032f9410039
   prev_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   next_func: 0x0041fb10 — — Memory Allocation (unidentified)
   xrefs_into: none

GAP 35: 0x00420c43 — 0x00420cf0 (173 bytes)
   hex_head: 907c084200830842008a08420091084200980842009f084200a6084200ad084200b4084200bb084200c2084200c90842
   prev_func: 0x00420490 — — Position Change Detector
   next_func: 0x004212e0 — — Short Computation (Session Score Aggregation)
   xrefs_into: none

GAP 36: 0x00421566 — 0x004216f0 (394 bytes)
   hex_head: 8b4424085d5b83c454c3568bf18b86b000000085c0740950e84c66160083c4048b86a800000085c0740950e839661600
   prev_func: 0x004214a0 — Initializes 46 dwords with alternating 0/0xffffffff pattern.
   next_func: 0x004216f0 — — Config Directory Path Registration
   xrefs_into: none

GAP 37: 0x00423e75 — 0x00424080 (523 bytes)
   hex_head: d9fad9592483e919feffff53568bf18d4e0ce874060c008d8e34400000e80979090033db8bce891ec74604ffffffffe8
   prev_func: 0x00423db0 — — short computation
   next_func: 0x00424750 — — AI Difficulty Scalar (Low Range)
   xrefs_into: none

GAP 38: 0x0042b887 — 0x0042b8a0 (25 bytes)
   hex_head: ff154ce05900005ec3e80b000000e916000000909090909090
   prev_func: 0x0042b0e0 — — AI Steering & Racing Line Correction
   next_func: 0x0042b8a0 — — Thunk to FUN_004b3db0
   xrefs_into: none

GAP 39: 0x0042c631 — 0x0042c690 (95 bytes)
   hex_head: 8d490093c44200a9c44200bdc44200d3c44200e9c44200fcc442000dc5420020c5420030c5420043c5420054c542006a
   prev_func: 0x0042c3b0 — — DynMan::Restart()
   next_func: 0x0042c690 — — Main Game Tick Update
   xrefs_into: none

GAP 40: 0x0042cea0 — 0x0042cf10 (112 bytes)
   hex_head: 40ce420046ce42004cce420052ce420058ce420088ce42008ece420094ce42006ace420070ce420076ce42007cce4200
   prev_func: 0x0042ce30 — — Session Type Name Lookup
   next_func: 0x0042d350 — — Session Reset
   xrefs_into: none

GAP 41: 0x0042dbea — 0x0042dc60 (118 bytes)
   hex_head: 9090909090906800dc4200e8449f150059c390909090b930707c00e8c6010000a128577c0085c0740750e8b69f150059
   prev_func: 0x0042dbe0 — — Thunk to FUN_0042e320
   next_func: 0x0042dc60 — — Small Data Struct Init
   xrefs_into: none

GAP 42: 0x004305e4 — 0x00430600 (28 bytes)
   hex_head: d1034300d8034300e4034300f0034300909090909090909090909090
   prev_func: 0x0042fd00 — — Vehicle Setup File Writer
   next_func: 0x00430600 — — WheelForceAggregate
   xrefs_into: none

GAP 43: 0x00431ba2 — 0x00431bc0 (30 bytes)
   hex_head: 1c81c6840ae81c0000015ec20c00e80b000000e916000000909090909090
   prev_func: 0x00431aa0 — — Setup Date/Angle Display Format
   next_func: 0x00431bc0 — — Thunk
   xrefs_into: none

GAP 44: 0x0043209e — 0x00432180 (226 bytes)
   hex_head: 9090566a408bf1e8595b150083c40485c0740d8bc8e888fcffff89068bc65ec333c089068bc65ec35e18895e1c8bc65e
   prev_func: 0x00431db0 — — Directory File Enumerator
   next_func: 0x00432180 — — Settings Setup File Read
   xrefs_into: none

GAP 45: 0x00433ead — 0x00433ed0 (35 bytes)
   hex_head: 909090568bf1b9c0567c00e8a3adffff6838a45e008d4e08e8862713005ec390909090
   prev_func: 0x00433e60 — — Physics Object Destructor
   next_func: 0x00433ed0 — — Validate Vehicle Configuration File
   xrefs_into: none

GAP 46: 0x0043526a — 0x00435290 (38 bytes)
   hex_head: 9090909090906880524300e8c428150059c390909090b928747c00e9163a0000909090909090
   prev_func: 0x00435260 — — Thunk to FUN_00438c10
   next_func: 0x00435290 — — FloatEpsilonCompare
   xrefs_into: none

GAP 47: 0x00447267 — 0x004472a8 (65 bytes)
   hex_head: 909090909090909090c681591c000000c37a03b0e967ffffffdd81b41d0000dc1de0ec5900dfe0f6c4417514c781b41d
   prev_func: 0x004471f0 — — SuspensionVibration
   next_func: 0x004472a8 — — SetByteOffset7257
   xrefs_into: none

GAP 48: 0x004499c3 — 0x00449a20 (93 bytes)
   hex_head: 4383c5203bd87cc15d5f5e5bc3e80b000000e92600000090909090909033c0a364937c00a360937c00b960937c00e97a
   prev_func: 0x004497e0 — — Sweep-and-Prune AABB Overlap Detection
   next_func: 0x00449a20 — — Registry Key Query
   xrefs_into: none

GAP 49: 0x0044c5c9 — 0x0044c5e0 (23 bytes)
   hex_head: 000000803f59c3e80b000000e916000000909090909090
   prev_func: 0x0044c550 — — CollisionNormalFromFeature
   next_func: 0x0044c5e0 — — Collision thunk
   xrefs_into: none

GAP 50: 0x0044c661 — 0x0044c680 (31 bytes)
   hex_head: c9d9e0d95908ddd8ddd85e59c20800e80b000000e936000000909090909090
   prev_func: 0x0044c650 — — Collision Init Registration (DAT_0044c660)
   next_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   xrefs_into: none

GAP 51: 0x0044c709 — 0x0044c720 (23 bytes)
   hex_head: 909090909090906820c74400e824b4130059c390909090
   prev_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   next_func: 0x0044c740 — — CollisionGridInit4
   xrefs_into: none

GAP 52: 0x0044c790 — 0x0044c7a0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c770 — — Collision Callback Registration (DAT_0044c780)
   next_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   xrefs_into: none

GAP 53: 0x0044c829 — 0x0044c840 (23 bytes)
   hex_head: 909090909090906840c84400e804b3130059c390909090
   prev_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   next_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   xrefs_into: none

GAP 54: 0x0044c8b0 — 0x0044c8c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c890 — — Collision Init Wrapper (DAT_0044c8a0)
   next_func: 0x0044c8c0 — — CollisionFrictionInit_8
   xrefs_into: none

GAP 55: 0x0044c949 — 0x0044c960 (23 bytes)
   hex_head: 909090909090906860c94400e8e4b1130059c390909090
   prev_func: 0x0044c920 — — Collision global init (single group with 1.0)
   next_func: 0x0044c980 — — Collision Global Init (Set 10, -1.0f)
   xrefs_into: none

GAP 56: 0x0044c9c1 — 0x0044c9f4 (51 bytes)
   hex_head: c94400e8e4b1130059c390909090c3e80b000000e936000000909090909090c705b0cc7c000b000000c705b4cc7c0000
   prev_func: 0x0044c9b0 — — Thunk
   next_func: 0x0044c9f4 — — SteeringSensitivityInit
   xrefs_into: none

GAP 57: 0x0044ca69 — 0x0044ca80 (23 bytes)
   hex_head: 909090909090906880ca4400e8c4b0130059c390909090
   prev_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   next_func: 0x0044caa0 — — InitMouseAbsAxisX
   xrefs_into: none

GAP 58: 0x0044cae4 — 0x0044cb14 (48 bytes)
   hex_head: e8c4b0130059c390909090c3e80b000000e936000000909090909090c705dccf7c0067000000c705e0cf7c0000000000
   prev_func: 0x0044cad0 — — Thunk
   next_func: 0x0044cb14 — — Global Initializer (-1.0, 0.0)
   xrefs_into: none

GAP 59: 0x0044cb89 — 0x0044cba0 (23 bytes)
   hex_head: 9090909090909068a0cb4400e8a4af130059c390909090
   prev_func: 0x0044cb74 — — Input Handler Global Reset
   next_func: 0x0044cbc0 — — CollisionGlobalInitF
   xrefs_into: none

GAP 60: 0x0044cc02 — 0x0044cc34 (50 bytes)
   hex_head: 4400e8a4af130059c390909090c3e80b000000e936000000909090909090c705b8a37c001e000000c705bca37c000000
   prev_func: 0x0044cbf0 — — Collision Data Registration Block 1
   next_func: 0x0044cc34 — — Camera/View Zoom Initializer
   xrefs_into: none

GAP 61: 0x0044cca9 — 0x0044ccc0 (23 bytes)
   hex_head: 9090909090909068c0cc4400e884ae130059c390909090
   prev_func: 0x0044cc94 — — Audio/Renderer Float Constant Initializer
   next_func: 0x0044cce0 — — Collision Material Init (Type 0x20)
   xrefs_into: none

GAP 62: 0x0044cd21 — 0x0044cd54 (51 bytes)
   hex_head: cc4400e884ae130059c390909090c3e80b000000e936000000909090909090c7050ca57c0021000000c70510a57c0000
   prev_func: 0x0044cd10 — — Collision constructor thunk
   next_func: 0x0044cd54 — — Initialize Physics Constants
   xrefs_into: none

GAP 63: 0x0044cdc9 — 0x0044cde0 (23 bytes)
   hex_head: 9090909090909068e0cd4400e864ad130059c390909090
   prev_func: 0x0044cdb4 — — CollisionScaleInit
   next_func: 0x0044ce00 — — Spatial Node Init (index 35, radius -1.0)
   xrefs_into: none

GAP 64: 0x0044ce41 — 0x0044ce74 (51 bytes)
   hex_head: cd4400e864ad130059c390909090c3e80b000000e936000000909090909090c70548a47c0024000000c7054ca47c0000
   prev_func: 0x0044ce30 — — CollisionDataTeardown_2
   next_func: 0x0044ce74 — — InitFloatGlobals
   xrefs_into: none

GAP 65: 0x0044cee9 — 0x0044cf00 (23 bytes)
   hex_head: 909090909090906800cf4400e844ac130059c390909090
   prev_func: 0x0044ced4 — — InitFloatConstants
   next_func: 0x0044cf20 — — CollisionStateInit_Alpha2
   xrefs_into: none

GAP 66: 0x0044cf61 — 0x0044cf94 (51 bytes)
   hex_head: cf4400e844ac130059c390909090c3e80b000000e936000000909090909090c70580a47c0027000000c70584a47c0000
   prev_func: 0x0044cf50 — — Deferred Callback Registration (Collision)
   next_func: 0x0044cf94 — — Audio Mixer Gain Init
   xrefs_into: none

GAP 67: 0x0044d009 — 0x0044d020 (23 bytes)
   hex_head: 909090909090906820d04400e824ab130059c390909090
   prev_func: 0x0044cff4 — — Float/float init to (0, 1)
   next_func: 0x0044d040 — — CollisionFrictionInit_29
   xrefs_into: none

GAP 68: 0x0044d090 — 0x0044d0a0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d070 — — Thunk to FUN_00587b3e (Collision 6 init)
   next_func: 0x0044d0a0 — — Collision global init (single group with 1.0)
   xrefs_into: none

GAP 69: 0x0044d129 — 0x0044d140 (23 bytes)
   hex_head: 909090909090906840d14400e804aa130059c390909090
   prev_func: 0x0044d100 — — Collision Global Init (Set 0x6b, -1.0f)
   next_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   xrefs_into: none

GAP 70: 0x0044d1b0 — 0x0044d1c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d190 — — Collision Static Data Registration (2)
   next_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   xrefs_into: none

GAP 71: 0x0044d249 — 0x0044d260 (23 bytes)
   hex_head: 909090909090906860d24400e8e4a8130059c390909090
   prev_func: 0x0044d220 — — InitMouseAbsAxisY
   next_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   xrefs_into: none

GAP 72: 0x0044d2c1 — 0x0044d2f4 (51 bytes)
   hex_head: d24400e8e4a8130059c390909090c3e80b000000e936000000909090909090c70510a47c003e000000c70514a47c0000
   prev_func: 0x0044d2b0 — — CollisionGridFreeB
   next_func: 0x0044d2f4 — — InitRenderConstantsZeroOne
   xrefs_into: none

GAP 73: 0x0044d369 — 0x0044d380 (23 bytes)
   hex_head: 909090909090906880d34400e8c4a7130059c390909090
   prev_func: 0x0044d340 — — CollisionGlobalInitG
   next_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   xrefs_into: none

GAP 74: 0x0044d3e1 — 0x0044d400 (31 bytes)
   hex_head: d34400e8c4a7130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d3d0 — — RegisterRendererObject
   next_func: 0x0044d400 — — Spatial Node Init (index 14)
   xrefs_into: none

GAP 75: 0x0044d486 — 0x0044d4a0 (26 bytes)
   hex_head: 9090909090909090909068a0d44400e8a4a6130059c390909090
   prev_func: 0x0044d460 — — Global State Initializer (Collision Set 1)
   next_func: 0x0044d4c0 — — CollisionGridInit16x16
   xrefs_into: none

GAP 76: 0x0044d510 — 0x0044d520 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d4f0 — — Collision constructor thunk
   next_func: 0x0044d520 — — CollisionStateInit_17
   xrefs_into: none

GAP 77: 0x0044d5a6 — 0x0044d5c0 (26 bytes)
   hex_head: 9090909090909090909068c0d54400e884a5130059c390909090
   prev_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   next_func: 0x0044d5e0 — — Collision Material Coefficients Set 1 (ID 0x13)
   xrefs_into: none

GAP 78: 0x0044f42c — 0x0044f460 (52 bytes)
   hex_head: fff3440012f4440000000000000000000000010101010000000000000000000101010101000000000000009090909090
   prev_func: 0x0044f150 — â€” Force Feedback / Joystick Input Processing
   next_func: 0x0044f460 — — PackedFlagRead
   xrefs_into: none

GAP 79: 0x004516a0 — 0x00451720 (128 bytes)
   hex_head: 680645003b07450075084500ae0945004e0c4500e50e4500c51045009f1145003a13450099104500e21345000d144500
   prev_func: 0x0044ff50 — â€” Audio Channel Initialization
   next_func: 0x00451720 — — Driver Input Controller
   xrefs_into: none

GAP 80: 0x00454c4b — 0x00454d30 (229 bytes)
   hex_head: 903d4c4500454c4500484c45000001010101010101010101010102020202020202020202020202020202020202020202
   prev_func: 0x00454c20 — — Enum-to-ID Mapping with Default Fallthrough
   next_func: 0x00454d30 — Try two lookup methods: named parameter then numeric ID, sto
   xrefs_into: none

GAP 81: 0x004562b5 — 0x004562f0 (59 bytes)
   hex_head: 240c89510489e9d7ffffff568bf1c706ccef59008b460485c0740950e8f918130083c404f644240801740956e8e91813
   prev_func: 0x004562a0 — — Short Computation (VTable Set + Conditional Free)
   next_func: 0x004569b0 — — Steering/input smoothing with saturation
   xrefs_into: none

GAP 82: 0x0045954b — 0x00459830 (741 bytes)
   hex_head: 4d5954480081ec54010000dd0530f059005355568bf1dc76288b8ed00000005733ff897c242433dbdc8e80010000dc05
   prev_func: 0x004594d0 — — Struct Init with Float Constants (Physics Params)
   next_func: 0x00459830 — — Float/Double Coordinate Transform
   xrefs_into: none

GAP 83: 0x0045b3dd — 0x0045b400 (35 bytes)
   hex_head: 909090568bf1e818000000f644240801740956e8dac7120083c4048bc65ec204009090
   prev_func: 0x0045b360 — — Short Computation (Constructor/Initializer)
   next_func: 0x0045b400 — — Destructor with Resource Cleanup
   xrefs_into: none

GAP 84: 0x0045be3d — 0x0045be50 (19 bytes)
   hex_head: 909090e80b000000e926000000909090909090
   prev_func: 0x0045be00 — — Collision Penalty Scaler
   next_func: 0x0045be50 — — Global State Initializer (Collision System Reset)
   xrefs_into: none

GAP 85: 0x0045bf5a — 0x0045bf90 (54 bytes)
   hex_head: 9090909090906870bf4500e8d4bb120059c390909090b95cd27c00e9265d0000909090909090e80b000000e966000000
   prev_func: 0x0045bf50 — — Single Function Call Wrapper
   next_func: 0x0045bf90 — — Collision Mutex Initialization
   xrefs_into: none

GAP 86: 0x0045c75e — 0x0045c780 (34 bytes)
   hex_head: 90908b4424048b4c24080fbf000fbf112bc2c3905e5d8ac35b81c48837e9cbfeffff
   prev_func: 0x0045c750 — — Wrapper with Constant
   next_func: 0x0045c780 — — Bounded Byte Array Accessor
   xrefs_into: none

GAP 87: 0x0045d4bd — 0x0045d4e0 (35 bytes)
   hex_head: 909090803900740e8a410184c0740733c9e96d4a1000c35f5e5b81c4f400e958fdffff
   prev_func: 0x0045d490 — — Global Flag-Based State Setter
   next_func: 0x0045d4e0 — — String Length Check Dispatch
   xrefs_into: none

GAP 88: 0x0045f275 — 0x0045f2a0 (43 bytes)
   hex_head: 8d49009cf04500a3f04500aaf04500b1f04500b8f04500bff04500c6f04500cdf04500d4f04500dbf04500
   prev_func: 0x0045f030 — — Mouse Input Handler
   next_func: 0x0045f2a0 — — CollisionInvDistanceStore
   xrefs_into: none

GAP 89: 0x00461f68 — 0x00461f90 (40 bytes)
   hex_head: c0c3b801000000c38b018b889cb7010085c97405e98f141000c3021310005eb0015f83c440c20400
   prev_func: 0x00461ed0 — — Directory String Processing with Decode
   next_func: 0x00461f90 — — Conditional Network/System Dispatch
   xrefs_into: none

GAP 90: 0x00464278 — 0x00464290 (24 bytes)
   hex_head: 2e414600354146003c414600434146009090909090909090
   prev_func: 0x00463f70 — — Session Type Setter
   next_func: 0x00464290 — — SynchronizeWithServer
   xrefs_into: none

GAP 91: 0x00464ec9 — 0x00464ee0 (23 bytes)
   hex_head: 8d4900a14e4600a94e4600b14e4600b94e460090909090
   prev_func: 0x00464e90 — — Buffer Size Lookup
   next_func: 0x00464ee0 — — Conditional Delegate Based on Counter
   xrefs_into: none

GAP 92: 0x00465fb6 — 0x00465fd0 (26 bytes)
   hex_head: 8bf15f8bc6e9a1fdffffe80b000000e926000000909090909090
   prev_func: 0x00465d70 — � Recursive Linked List Merge Sort
   next_func: 0x00465fd0 — — Collision Distance Reset
   xrefs_into: none

GAP 93: 0x004661a5 — 0x0046624e (169 bytes)
   hex_head: 90909090909032c0c20c00568bf18b86e800000085c0740b8b4e406a0056e888050300d98624010000d81d40e45900df
   prev_func: 0x00466160 — Forwards call to another function. No additional logic.
   next_func: 0x00466250 — Calls FUN_004988a0(3) and sets byte flag at +0xf4 to 1, retu
   xrefs_into: none

GAP 94: 0x00466900 — 0x00466910 (16 bytes)
   hex_head: e89b1a020033c0c36a00e856250300c3
   prev_func: 0x004668e0 — — Init + VTable Set
   next_func: 0x00466910 — — Setup Value Display Formatter
   xrefs_into: none

GAP 95: 0x00466b17 — 0x00466d60 (585 bytes)
   hex_head: ff15b0e35900ffffffa064707c0084c0568bf1742a6a00e8dd040200508d8eb8000000e811fb0f006a008bcee8a81d02
   prev_func: 0x00466a70 — — ConfigObjectDestructor
   next_func: 0x00466d60 — — Short Computation / Object Init + VTable
   xrefs_into: none

GAP 96: 0x004672b6 — 0x004677e0 (1322 bytes)
   hex_head: e8bc450200e999ffffff566a008bf1e8a64d02008b4424088b4c240c8bd06bd20b03d1c1e20681c270577c0089962003
   prev_func: 0x00467260 — — Object Constructor with Parameter Setup
   next_func: 0x004677e0 — — LinkedListNodeDestructor
   xrefs_into: none

GAP 97: 0x0046846a — 0x004685b0 (326 bytes)
   hex_head: e1e8e9e1f9ffa030ff7c0081ec0002000084c0568bf174248b066a01ff50388b166a008bceff523c8b4e406a00e80404
   prev_func: 0x004681b0 — — VehicleSceneLoadAndPositionTires
   next_func: 0x004685b0 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 98: 0x00468b4b — 0x00468bf0 (165 bytes)
   hex_head: 4d5954480055578bf98b878401000085c08daf840100007505b838a45e0053568bf0b8ace47c008a088a1e8ad13acb75
   prev_func: 0x00468a00 — — Career Mode Driver Stats Reset
   next_func: 0x00468bf0 — � Grand Prix Results HTML Writer
   xrefs_into: none

GAP 99: 0x004698bc — 0x00469900 (68 bytes)
   hex_head: 90909090568bf18b868001000085c0740950e8fce2110083c4048bcee863fb0100f644240801740956e8e5e2110083c4
   prev_func: 0x00469880 — — UI Dialog/Property Page Constructor
   next_func: 0x00469900 — � Individual Race Results HTML Writer
   xrefs_into: none

GAP 100: 0x0046a3c7 — 0x0046a560 (409 bytes)
   hex_head: 9090909090909090906a00e8c9feffff33c0c359e879c2f9ffa1ece57c0085c0568bf17505b838a45e005750b968c38a
   prev_func: 0x0046a270 — — VTable Set + Free + Call
   next_func: 0x0046a560 — — Standings Display
   xrefs_into: none

GAP 101: 0x0046aef9 — 0x0046b070 (375 bytes)
   hex_head: 5f5ee955ffffff568bf1e858ffffff6a016a008bcee89deb010033c05ec3ff1528e05900ffffffa124147d0083ec5853
   prev_func: 0x0046ae60 — — Session Entry List Cleanup
   next_func: 0x0046b070 — — Double-threshold timing check
   xrefs_into: none

GAP 102: 0x0046c03b — 0x0046c6e5 (1706 bytes)
   hex_head: 4d59544800568bf18b867401000085c07e124885c089867401000075076a01e8b1feffff833de8c95c0001741c8b8678
   prev_func: 0x0046c030 — Sets integer field at +0x174 to 2.
   next_func: 0x0046c6f0 — — Short Computation (Constructor-like)
   xrefs_into: none

GAP 103: 0x0046cb0b — 0x0046cb50 (69 bytes)
   hex_head: 4d59544800e8ebffffff84c0742733c9908d6424008b048d70d47c0085c07c1269c0c04800004183f968898830075f00
   prev_func: 0x0046cb00 — — Global Sign Check
   next_func: 0x0046cb50 — — Profile Already Exists Page Handler
   xrefs_into: none

GAP 104: 0x0046d1dc — 0x0046dd30 (2900 bytes)
   hex_head: 90909090568bf157b9b02d7d0033ffe86056050085c0741e83b844b100000275158b4e406aff68746b5c00e834a70200
   prev_func: 0x0046d0d0 — — SessionCheckEndCondition
   next_func: 0x0046dd30 — — Multiplayer Password Validation
   xrefs_into: none

GAP 105: 0x0046e842 — 0x0046ec10 (974 bytes)
   hex_head: fe5900c68674010000008bc65ec383ec288b4424388b542430535556578be98b4c2444508b4424405152508bcd896c24
   prev_func: 0x0046e7f0 — — Polling Loop with Branch
   next_func: 0x0046ec10 — — Object Name Matching + Activation
   xrefs_into: none

GAP 106: 0x00470230 — 0x004702f0 (192 bytes)
   hex_head: 566a006a016a006a006a006a008bf1e8dcb10100c70650025a008bc65ec39090568bf1e888b20100f644240801740956
   prev_func: 0x00470190 — � Monitor Timing Display
   next_func: 0x004702f0 — — Short Computation (VTable Set)
   xrefs_into: none

GAP 107: 0x00470f79 — 0x004713e0 (1127 bytes)
   hex_head: 33c0e937fdffff566a018bf1e8d65dffff6aff68a4325c008bcec706800a5a00c7861c0300005cf67c00c78624030000
   prev_func: 0x00470f20 — — Race/Session Mode Data Loader
   next_func: 0x004713e0 — — UI Toggle Increment/Decrement Handler
   xrefs_into: none

GAP 108: 0x0047364f — 0x00473b68 (1305 bytes)
   hex_head: 90568bf18b0dc0d87c008b016a13ff501c85c07408568bc8e8143c00008b168bceff92ac00000033c05ec301e8d92ff9
   prev_func: 0x004735b0 — — UI Frontend Counter Display Update
   next_func: 0x00473b90 — Check resource, conditionally dispatch, set global string re
   xrefs_into: none

GAP 109: 0x00475116 — 0x00475140 (42 bytes)
   hex_head: 8bceff5038e9c8ffffff568bf1e818000000f644240801740956e89a2a110083c4048bc65ec204009090
   prev_func: 0x004750f0 — � UI Object Init with Zero Fields
   next_func: 0x00475140 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 110: 0x00476073 — 0x004760d0 (93 bytes)
   hex_head: 90909090909090909090909090568bf1c70650445a008b463085c0740950e8391b110083c404c7063c445a008b460485
   prev_func: 0x00476060 — — Car Flag Byte Setter
   next_func: 0x004760d0 — � Object Constructor with VTable (0x005a4464)
   xrefs_into: none

GAP 111: 0x004765fd — 0x00476660 (99 bytes)
   hex_head: 909090568bf1c7068c445a008b463c85c0740950e8b915110083c404c70650445a008b463085c0740950e8a315110083
   prev_func: 0x004765f0 — — LoadPath Getter
   next_func: 0x00476660 — — Season Path Match Search
   xrefs_into: none

GAP 112: 0x004774bb — 0x00477640 (389 bytes)
   hex_head: 4d5954480083ec08535556578be9e8027701008bb5f000000033db3bf374298d9b000000008bfe385f0c8b7604740c8b
   prev_func: 0x00477440 — — UI Element List Destructor
   next_func: 0x00477640 — — Season/Scene Name Accessor
   xrefs_into: none

GAP 113: 0x00477f9e — 0x00478e80 (3810 bytes)
   hex_head: 9090568bf18b4e408b01576a03ff501c8bf885ff74268bcfe8a553010039861c01000074178bcfe8965301008b168bce
   prev_func: 0x00477f30 — — ProfileIconBmpLoader
   next_func: 0x00478e80 — Delegates to FUN_00499b80().
   xrefs_into: none

GAP 114: 0x0047931b — 0x004793ec (209 bytes)
   hex_head: 4d5954480083ec085356578bf18d44240c508d4c2414518b4e40e846f501008b866401000085c089866c0100000f8494
   prev_func: 0x00478ed0 — � SessionExitOrChecks
   next_func: 0x004793ec — — File Path Resolver with Extension Append
   xrefs_into: none

GAP 115: 0x0047a115 — 0x0047aa60 (2379 bytes)
   hex_head: faa8177d007ce953ffffff8b89040100008d8140ffffff83f8077737ff24856ca14700b848147d00c3b8b4147d00c3b8
   prev_func: 0x0047a080 — — Parameter value clamping across array
   next_func: 0x0047aa60 — — Empty Stub
   xrefs_into: none

GAP 116: 0x0047be6e — 0x0047be90 (34 bytes)
   hex_head: 9090568bf1e848d50000c70688675a00c78674010000000000008bc65ec390909090
   prev_func: 0x0047be00 — � Menu Scroll Position Calculator with Clamp
   next_func: 0x0047be90 — — Short Computation (Destructor)
   xrefs_into: none

GAP 117: 0x0047c7ba — 0x0047c860 (166 bytes)
   hex_head: 50e8999ef8ff56680000803f6a008bf1e8d10b01008b4424088986fc000000c706b0695a008bc65ec20400cee85bf000
   prev_func: 0x0047c770 — — UI FPS/Performance Setting Display
   next_func: 0x0047c860 — — UILoadingPercentDisplay
   xrefs_into: none

GAP 118: 0x0047dcf1 — 0x0047dd10 (31 bytes)
   hex_head: 8d490001dc470022dc470069dc47009edc4700909090909090909090909090
   prev_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   next_func: 0x0047dd10 — — DriverCareerStatsHTMLWriter
   xrefs_into: none

GAP 119: 0x0047e95a — 0x0047ee5c (1282 bytes)
   hex_head: 83e8f97cf8ff56576aff6a018bf1e893a1000033c9898eec000000c786f0000000ffffffffc706786c5a008b7e443bf9
   prev_func: 0x0047e940 — Call FUN_00566650 if param_1 non-zero.
   next_func: 0x0047ee5c — — InitFromDataBlock
   xrefs_into: none

GAP 120: 0x0047f10d — 0x0047f180 (115 bytes)
   hex_head: 909090568b3568d47c0085f6578bf97505be38a45e0068ccc45e0056b9c0c45e00e8cd48faff85c0742d85f67422bacc
   prev_func: 0x0047f0a0 — — LoadAndProcessMessageBuffer
   next_func: 0x0047f180 — — Doubly-Linked List Append
   xrefs_into: none

GAP 121: 0x0047fc54 — 0x004857e0 (23436 bytes)
   hex_head: 80100083c4048be964ffffff8b442404566a7f8db10c2100005056c60600e85981100083c40cc6467f005ec204009090
   prev_func: 0x0047fbd0 — — Linked List Destroy at +0x444
   next_func: 0x004857e0 — — Linked-List Buffer Destructor
   xrefs_into: none

GAP 122: 0x00485ad6 — 0x00485b90 (186 bytes)
   hex_head: c4045e8bc5e985ffffff568bf18b867401000085c0740950e8dc20100083c4048bcee843390000f644240801740956e8
   prev_func: 0x00485a90 — � Destructor with Two-Pointer Free
   next_func: 0x00485df0 — — Global Manager Shutdown Sequence
   xrefs_into: none

GAP 123: 0x00486efb — 0x00486f30 (53 bytes)
   hex_head: 4d595448008bc18a4c240484c9741f8b889800000085c974158b5010528b500c528b50088b40045250e827210100c204
   prev_func: 0x00486ed0 — — Set Four Colors to White
   next_func: 0x00486f30 — Allocate linked list nodes and insert into doubly-linked lis
   xrefs_into: none

GAP 124: 0x0048752f — 0x00487660 (305 bytes)
   hex_head: 90568bf1e8a8ffffff85c074296a018bcee81bfdffff8bcee814ffffff8b068bceff909800000085c0750b8bcee89ff0
   prev_func: 0x004874e0 — — UI Value Validator
   next_func: 0x00487660 — — UI Object Init with Byte Params
   xrefs_into: none

GAP 125: 0x00487755 — 0x00487ed0 (1915 bytes)
   hex_head: 83e802740332e9d3ffffff53e8baefffff83f8040f879a000000ff2485107848008a44240884c00f85870000008b015b
   prev_func: 0x00487740 — — Range Check
   next_func: 0x00487ed0 — Initializes struct with vtable and two byte params.
   xrefs_into: none

GAP 126: 0x004881a4 — 0x004881f0 (76 bytes)
   hex_head: 908b01ff90a800000033c0c3568bf18d8ee0000000e8921901008bcee8ebdcfffff644240801740956e8fdf90f0083c4
   prev_func: 0x00488180 — — UI Text Display Constructor
   next_func: 0x004881f0 — � Surface Render Region Setup
   xrefs_into: none

GAP 127: 0x00488aaa — 0x00488b00 (86 bytes)
   hex_head: 5fe8a9dbf7ff568bf18b06c686ed00000000ff909c00000085c075108b166a018bceff522c8bcee85adbffff33c05ec3
   prev_func: 0x00488a30 — — UIScrollWidgetUpdate
   next_func: 0x00488b00 — — Constructor: Init + VTable
   xrefs_into: none

GAP 128: 0x00489fc8 — 0x0048a3b0 (1000 bytes)
   hex_head: 010000ddd85e59c383ec2453568bf18b864c0100008b9e900000005733ff85c0897c240c7e168bff85db740c8b9b8c00
   prev_func: 0x00489f40 — — Unidentified / Clamped Index Computation
   next_func: 0x0048a3b0 — — Byte Setter at +0xe0
   xrefs_into: none

GAP 129: 0x0048ab24 — 0x0048b024 (1280 bytes)
   hex_head: 0000c70628be5a008bc65ec351568d442404508bf1c744240800000000e88a0300008b4c2404518bcee8de0400008b44
   prev_func: 0x0048aaa0 — — Linked-List Pool Destructor
   next_func: 0x0048b024 — — Stub Returning Zero
   xrefs_into: none

GAP 130: 0x0048b90a — 0x0048b91a (16 bytes)
   hex_head: 33e849adf7ff538a5c2408568bf18b06
   prev_func: 0x0048b8f0 — Sets field at +0x2f8 to param_2 if in range [0, 0x100).
   next_func: 0x0048b91a — — UI Widget Visibility Toggle
   xrefs_into: none

GAP 131: 0x0048c0db — 0x0048c9a0 (2245 bytes)
   hex_head: 9090909090568bf18b86b800000085c07505b838a45e00681cc25c0050e813c30f0083c40885c0750689860c0300008b
   prev_func: 0x0048c0d0 — — VTable + Init
   next_func: 0x0048c9a0 — — Simple VTable + Null Init
   xrefs_into: none

GAP 132: 0x0048d3eb — 0x0048d590 (421 bytes)
   hex_head: 9090909090568bf1c706d0c15a00e8b28afffff644240801740956e8c4a70f0083c4048bc65ec20400007d0689813803
   prev_func: 0x0048d3e0 — — Object Init with VTable + Cleanup
   next_func: 0x0048d590 — — Input Dispatch (Arrow Up/Down: 0xCB, 0xCD)
   xrefs_into: none

GAP 133: 0x0048d7c3 — 0x0048d850 (141 bytes)
   hex_head: 909090909090909090909090908b01ff90ac00000033c0c390909090908b016a00ff504033c0c333e8698ef7ff8b5424
   prev_func: 0x0048d740 — — Large Zero-Init Constructor
   next_func: 0x0048d850 — — UI Scroll Area/Auto-Scroll Manager
   xrefs_into: none

GAP 134: 0x0048dfe9 — 0x0048e070 (135 bytes)
   hex_head: 5b83c41cc21000568bf1e82887ffff4883f8047742ff248550e048008b066a068bceff50408b068bceff909c00000033
   prev_func: 0x0048df40 — — UIWidgetDragHandler
   next_func: 0x0048e070 — — Constructor (Zero Init + Defaults)
   xrefs_into: none

GAP 135: 0x0048e4a9 — 0x0048e600 (343 bytes)
   hex_head: 830d008bc65ec3568bf18b86b000000085c07505b838a45e008b8efc00000085c97505b938a45e005051e8389f0f0083
   prev_func: 0x0048e3a0 — — Font Resource Loader
   next_func: 0x0048e600 — — UI Struct Init (Type 0)
   xrefs_into: none

GAP 136: 0x0048ea31 — 0x0048ea60 (47 bytes)
   hex_head: da320b005f32c05e81c4e991ffffff8b44240c8b54241089411c8b4424048951208b542408894124895128c2100090
   prev_func: 0x0048ea20 — � Two-Field Setter
   next_func: 0x0048ea60 — — Rectangle Bounds Check
   xrefs_into: none

GAP 137: 0x0048fd79 — 0x0048fdb0 (55 bytes)
   hex_head: 445ae9f1feffff568bf1c7063c445a008b460485c0740950e8397e0f0083c404f644240801740956e8297e0f0083c404
   prev_func: 0x0048fd60 — — Constructor
   next_func: 0x0048fdb0 — — Viewport/Rect Size Calc
   xrefs_into: none

GAP 138: 0x0049015e — 0x00490190 (50 bytes)
   hex_head: 90908a44240484c0740cc781e000000000000000eb0ac781e0000000010000008b01c744240401000000ff602c909090
   prev_func: 0x004900a0 — — Unidentified / UI State Machine Update
   next_func: 0x00490190 — — Zero-Check Getter
   xrefs_into: none

GAP 139: 0x00490535 — 0x00490550 (27 bytes)
   hex_head: 8d4900900449009004490090044900a8044900a8044900a8044900
   prev_func: 0x00490450 — — UIWidget_ProcessChildren
   next_func: 0x00490550 — — PanelMouseInteractionHandler
   xrefs_into: none

GAP 140: 0x004943cf — 0x00494430 (97 bytes)
   hex_head: 90354049005a4049007f404900a4404900df4049000c4149008f414900ad414900cb414900ec414900194249003a4249
   prev_func: 0x00493e20 — — Resource Path Builder
   next_func: 0x00494470 — — UI Destructor with Self-Free
   xrefs_into: none

GAP 141: 0x00494617 — 0x00494630 (25 bytes)
   hex_head: 9090909090909090906830464900e814350f0059c390909090
   prev_func: 0x00494600 — — Collision Global Zeroing
   next_func: 0x00494630 — — LinkedListCleanupDestroy
   xrefs_into: none

GAP 142: 0x0049624d — 0x00496280 (51 bytes)
   hex_head: 8d4900a960490079614900be614900be614900be614900ca604900df604900f46049000d614900226149003b61490051
   prev_func: 0x00496030 — — Car Crash Damage Processing
   next_func: 0x00496280 — — Float Array Init with Random
   xrefs_into: none

GAP 143: 0x00498650 — 0x004986a0 (80 bytes)
   hex_head: 8b54240485d2568bf1743a5783c9ff33c08bfaf2aef7d1495f742a528d8e58150000e8d9df0c008b44240c8b4c24108b
   prev_func: 0x004985d0 — — String Truncation Wrapper
   next_func: 0x004986a0 — — Render State Reset
   xrefs_into: none

GAP 144: 0x00498fde — 0x0049904c (110 bytes)
   hex_head: 9090568bf18b466085c074578b0657ff502884c074208b7e048b4e088b560c8b46102bcf512bc2505752e81379ffff8b
   prev_func: 0x00498fb0 — — List Iteration with VTable Dispatch
   next_func: 0x00499050 — — Guarded Sub-Rectangle Render Dispatch
   xrefs_into: none

GAP 145: 0x0049918b — 0x004991e0 (85 bytes)
   hex_head: 909090909033c0c208000630ca5a008be9b9ffffff56e89afcffff8bd0e8b3fdffff85d28bf074078bcae86603000085
   prev_func: 0x00499180 — — Short Computation (VTable Set)
   next_func: 0x004991e0 — Forwards call to another function. No additional logic.
   xrefs_into: none

GAP 146: 0x0049964b — 0x00499660 (21 bytes)
   hex_head: 4d59544800e80b000000e916000000909090909090
   prev_func: 0x00499620 — — Short Computation (Destructor — Double Free Check)
   next_func: 0x00499660 — — Short Computation / Single Call Wrapper
   xrefs_into: none

GAP 147: 0x00499cbe — 0x00499ce0 (34 bytes)
   hex_head: 9090568bf1e818000000f644240801740956e8fade0e0083c4048bc65ec204009090
   prev_func: 0x00499c50 — — Constructor: Init with -1 Sentinels
   next_func: 0x00499ce0 — — Destructor with Multiple Conditional Frees
   xrefs_into: none

GAP 148: 0x0049a96b — 0x0049a990 (37 bytes)
   hex_head: 4d59544800568bf1e818000000f644240801740956e84ad20e0083c4048bc65ec204009090
   prev_func: 0x0049a930 — — Constructor with -1 Sentinels
   next_func: 0x0049a990 — — Short Computation (Destructor)
   xrefs_into: none

GAP 149: 0x0049af84 — 0x0049afa0 (28 bytes)
   hex_head: b0015bc20c008ac35bc20c00e80b000000e916000000909090909090
   prev_func: 0x0049af30 — — Linked List Free
   next_func: 0x0049afa0 — — Wrapper
   xrefs_into: none

GAP 150: 0x0049b01c — 0x0049b030 (20 bytes)
   hex_head: 909090906830b04900e814cb0e0059c390909090
   prev_func: 0x0049afe0 — — Multi-Call Sequence
   next_func: 0x0049b030 — — UI Delegate Wrapper
   xrefs_into: none

GAP 151: 0x0049b071 — 0x0049b0a0 (47 bytes)
   hex_head: 450800000000c7450c00e904ffffffe90b0000009090909090909090909090a1c0cb5c0083c00aa338e27c00c39090
   prev_func: 0x0049b060 — — Free Callback Registration (atexit-like)
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 152: 0x0049b8ae — 0x0049b8d0 (34 bytes)
   hex_head: 8bff1fb8490026b849002db8490034b849002db8490026b849009090909090909090
   prev_func: 0x0049b7a0 — � SteeringInputToGear
   next_func: 0x0049b8d0 — — Speed Multiplier
   xrefs_into: none

GAP 153: 0x0049e489 — 0x0049e4e0 (87 bytes)
   hex_head: 00e8b90d0000c333c0880189410489410889410c89411089411489411889411c89412089412489412889412c89413089
   prev_func: 0x0049e410 — — Dual Text Display
   next_func: 0x0049e4e0 — — Audio/Effect Trigger
   xrefs_into: none

GAP 154: 0x0049fda7 — 0x0049feb0 (265 bytes)
   hex_head: ff1554e259000000c351a054e27c0084c0570f85e9000000b95cd27c00e8e71ffcff84c00f84d7000000b95cd27c00e8
   prev_func: 0x0049f870 — � Race Monitor Overlay Renderer
   next_func: 0x0049feb0 — — Merge Sort (Linked List)
   xrefs_into: none

GAP 155: 0x004a042a — 0x004a0490 (102 bytes)
   hex_head: c4e82962f6ffa110047d0085c07e4c83f8047e3583f8057542b95cd27c00e87319fcff84c08b0dc0d87c006aff740d68
   prev_func: 0x004a03f0 — — System/OS API Call (Cursor Show)
   next_func: 0x004a0490 — � Main Menu Page
   xrefs_into: none

GAP 156: 0x004a11da — 0x004a11f0 (22 bytes)
   hex_head: 90909090909068f0114a00e854690e0059c390909090
   prev_func: 0x004a11d0 — — Wrapper (same as 0049afa0)
   next_func: 0x004a11f0 — — No-op thunk
   xrefs_into: none

GAP 157: 0x004a1970 — 0x004a1990 (32 bytes)
   hex_head: 8b44240450e8956b0e008b4c240cd91983c404b804000000c20800e8c94cf6ff
   prev_func: 0x004a1930 — — OSMan::Exit()
   next_func: 0x004a1990 — — ObjectHandleReader
   xrefs_into: none

GAP 158: 0x004a4026 — 0x004a4050 (42 bytes)
   hex_head: ffff5e81c4a4000000c3c74178020000008b496485c9740d6a006a016a016a01e8e57f0a00c390909090
   prev_func: 0x004a4000 — General utility function. See decompiled code for exact beha
   next_func: 0x004a4050 — Updates accumulator based on state at +0x78.
   xrefs_into: none

GAP 159: 0x004a48b1 — 0x004a4900 (79 bytes)
   hex_head: ffddd85f5e5d32c05b83e923feffff5356578bf98d7718bb050000008d49008bcee8e998f8ff83c6404b75f333c08bcf
   prev_func: 0x004a4830 — — Tire Compound Name → ID Mapping
   next_func: 0x004a4db0 — — UIComponentCleanup
   xrefs_into: none

GAP 160: 0x004a6fea — 0x004a7000 (22 bytes)
   hex_head: 9090909090906800704a00e8440b0e0059c390909090
   prev_func: 0x004a6fe0 — � Single Call Wrapper
   next_func: 0x004a7000 — — AutoLoadConfigFileInit
   xrefs_into: none

GAP 161: 0x004aa248 — 0x004aa270 (40 bytes)
   hex_head: f2a14a00f9a14a0000a24a0007a24a000ea24a0015a24a001ca24a00909090909090909090909090
   prev_func: 0x004aa1b0 — — Free Two Pointers
   next_func: 0x004aa270 — — Player Options Initializer / FailureRate Slots
   xrefs_into: none

GAP 162: 0x004af1f4 — 0x004af220 (44 bytes)
   hex_head: 0aea4a0076ec4a00e2ee4a0046f04a00c7f14a00d6f14a00d6f14a00e5f14a00909090909090909090909090
   prev_func: 0x004ae9f0 — � AI Difficulty Configuration per Race Mode
   next_func: 0x004af220 — — TireCompoundClamp
   xrefs_into: none

GAP 163: 0x004b1d15 — 0x004b1d90 (123 bytes)
   hex_head: 180090908a41e957ffffff518b5424085332db85d2568bf1744a5783c9ff33c08bfaf2aef7d1495f743a8d4424105052
   prev_func: 0x004b1c80 — — ConfigKeyValueSerialize
   next_func: 0x004b1d90 — — Multi-Field Setter with String Copy
   xrefs_into: none

GAP 164: 0x004b20f7 — 0x004b2180 (137 bytes)
   hex_head: ff154ce05900ffffff51568b3185f6894c2404744355578bff8bee8a450884c08b760474208b7d0085ff74198b470485
   prev_func: 0x004b20d0 — — Arithmetic/Comparison (Clamp with Bounds)
   next_func: 0x004b2180 — — Thunk to FUN_004b3ad0
   xrefs_into: none

GAP 165: 0x004b21ca — 0x004b21e0 (22 bytes)
   hex_head: 90909090909068e0214b00e864590d0059c390909090
   prev_func: 0x004b21c0 — — Single Call Wrapper
   next_func: 0x004b21e0 — — DebugPrintNullWrapper
   xrefs_into: none

GAP 166: 0x004b3d2e — 0x004b3d40 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x004b3ce0 — — Random/Noise Value Generator
   next_func: 0x004b3d40 — — Single Function Call Wrapper
   xrefs_into: none

GAP 167: 0x004b41ba — 0x004b41e0 (38 bytes)
   hex_head: 90909090909068d0414b00e874390d0059c390909090b9e4b68a00e9b65d0000909090909090
   prev_func: 0x004b41b0 — — Short Computation (Call Wrapper)
   next_func: 0x004b41e0 — — File Stream Writer
   xrefs_into: none

GAP 168: 0x004b4a10 — 0x004b4a30 (32 bytes)
   hex_head: 07494b000b494b000b494b0012494b0020494b0019494b009090909090909090
   prev_func: 0x004b48e0 — — Collision Object Insertion
   next_func: 0x004b4a30 — � Network Packet Router & Queue Manager
   xrefs_into: none

GAP 169: 0x004b6059 — 0x004b6130 (215 bytes)
   hex_head: 5e5de9fbfeffff538bd9e8c80000008b83a409000083f8040f879e000000ff248518614b00c783b409000010000000eb
   prev_func: 0x004b5f60 — — LinkedBufferTransfer
   next_func: 0x004b6130 — — Sprite/Overlay List Cleanup
   xrefs_into: none

GAP 170: 0x004b6899 — 0x004b68c0 (39 bytes)
   hex_head: 8d4900e4674b00ee674b00f8674b0002684b0039684b0041684b0049684b0051684b0090909090
   prev_func: 0x004b67d0 — — Steering Alignment Tolerance Check
   next_func: 0x004b68c0 — — CircularBufferCheck
   xrefs_into: none

GAP 171: 0x004b7fff — 0x004b8010 (17 bytes)
   hex_head: 90387f4b003c7f4b00437f4b004a7f4b00
   prev_func: 0x004b7de0 — � Hot Lap File Writer
   next_func: 0x004b8010 — — File/Setting Existence Check
   xrefs_into: none

GAP 172: 0x004b9cb9 — 0x004b9cd0 (23 bytes)
   hex_head: 909090909090908b01d980340f0000c3005f5e83c40cc3
   prev_func: 0x004b9cb0 — — Vehicle Lifetime Average Accessor
   next_func: 0x004b9cd0 — Delegates to FUN_004b86e0().
   xrefs_into: none

GAP 173: 0x004b9e02 — 0x004b9e30 (46 bytes)
   hex_head: 8bffb79d4b00c49d4b00d29d4b00de9d4b00ea9d4b00f69d4b000000000000000000000102030405909090909090
   prev_func: 0x004b9da0 — — MenuActionDispatch
   next_func: 0x004b9e30 — — Vehicle Data Accessor
   xrefs_into: none

GAP 174: 0x004bb775 — 0x004bb800 (139 bytes)
   hex_head: 8d49003fb74b0045b74b004bb74b0051b74b0057b74b005db74b004bb74b0063b74b0069b74b0090909090568bf18d46
   prev_func: 0x004bb730 — — Failure Category Name Lookup
   next_func: 0x004bb800 — — Zero Two Fields
   xrefs_into: none

GAP 175: 0x004bdbde — 0x004bdc10 (50 bytes)
   hex_head: 9090568db100090000578bcee801fcffffbf4000000083ee248bcee8f2fbffff4f75f35f5ec3433bd87ca35f5e5d5bc2
   prev_func: 0x004bdb90 — — AudioMixerChannelInit
   next_func: 0x004bdde0 — Call FUN_004bd800() 65 times (8*8+1) via nested loops.
   xrefs_into: none

GAP 176: 0x004bf380 — 0x004bf390 (16 bytes)
   hex_head: 20f14b0040f34b0071f34b0020f14b00
   prev_func: 0x004bf0a0 — — AI Behavior Initialization / Tick
   next_func: 0x004bf390 — — AI Driver Sorting / Priority
   xrefs_into: none

GAP 177: 0x004c2f8c — 0x004c2fa0 (20 bytes)
   hex_head: 90909090e80b000000e916000000909090909090
   prev_func: 0x004c2f20 — — LinkedListDestructorWithData
   next_func: 0x004c2fa0 — — Delegation Wrapper
   xrefs_into: none

GAP 178: 0x004c302a — 0x004c3050 (38 bytes)
   hex_head: 9090909090906840304c00e8044b0c0059c390909090b968c38a00e936210000909090909090
   prev_func: 0x004c3020 — — Delegation Thunk
   next_func: 0x004c3050 — � State Struct Multi-Field Init
   xrefs_into: none

GAP 179: 0x004c5172 — 0x004c51a0 (46 bytes)
   hex_head: 5f03c15ec204008bc7e95affffffa190c48a0085c0741350e8402a0c0083c404c70590c48a0000000000c3909090
   prev_func: 0x004c5130 — — List Indexed Accessor
   next_func: 0x004c51a0 — — Track File Path Builder
   xrefs_into: none

GAP 180: 0x004c7c1b — 0x004c7c30 (21 bytes)
   hex_head: e839eaf3ffe80b000000e916000000909090909090
   prev_func: 0x004c7c10 — — Conditional Delegation (if param_1 == 1)
   next_func: 0x004c7c30 — — Single Function Call Wrapper
   xrefs_into: none

GAP 181: 0x004c7c7a — 0x004c7ca0 (38 bytes)
   hex_head: 90909090909068907c4c00e8b4fe0b0059c390909090b994c48a00e976050000909090909090
   prev_func: 0x004c7c70 — — Passthrough
   next_func: 0x004c7ca0 — — Network Message Receive and Dispatch
   xrefs_into: none

GAP 182: 0x004c902c — 0x004c91d0 (420 bytes)
   hex_head: 90909090a114ce5a0050e8d5feffff33c089411c894120894124894128c7013cce5a008bc1c3d9e08bced91fff5004e9
   prev_func: 0x004c9000 — — Arithmetic/Comparison (Chained Validation)
   next_func: 0x004c91d0 — — Triple VTable Destructor Release
   xrefs_into: none

GAP 183: 0x004c94fb — 0x004c9790 (661 bytes)
   hex_head: e859d1f3ffa1a4567c0083ec0c85c0538bd90f84ac000000a170ae8a008bc881e1ff000000d9048d74ae8a0040d905b8
   prev_func: 0x004c94d0 — � Virtual Release Array (3 elements)
   next_func: 0x004c9790 — — Vtable Destructor + Null
   xrefs_into: none

GAP 184: 0x004cdb55 — 0x004cdb90 (59 bytes)
   hex_head: 8d490036db4c003bdb4c0040db4c0045db4c004adb4c004fdb4c0054db4c000000000000010202030606060405909090
   prev_func: 0x004cdb20 — � Steward: Scoring/Overtake/AI Pace
   next_func: 0x004cdb90 — — Constructor: Init Fields
   xrefs_into: none

GAP 185: 0x004d001d — 0x004d0030 (19 bytes)
   hex_head: 909090e80b000000e916000000909090909090
   prev_func: 0x004cfff0 — — SpecialFX::Exit
   next_func: 0x004d0030 — — Wrapper
   xrefs_into: none

GAP 186: 0x004d21ee — 0x004d2210 (34 bytes)
   hex_head: 8bffe8214d00eb214d00000000000001010101909090909090909090909090909090
   prev_func: 0x004d21d0 — � Race Phase Check
   next_func: 0x004d2210 — — Pit Close: Team Ready Check
   xrefs_into: none

GAP 187: 0x004d2dbb — 0x004d2dd0 (21 bytes)
   hex_head: 90fb2c4d00b72c4d00fb2c4d00222d4d0090909090
   prev_func: 0x004d24d0 — � Race Results File Writer (raceresults.txt)
   next_func: 0x004d2dd0 — � Conditional Allocation with Callbacks
   xrefs_into: none

GAP 188: 0x004d4539 — 0x004d4580 (71 bytes)
   hex_head: 8d490069414d0096414d0096414d0096414d0096414d0096414d0096414d0048434d00eb414d00eb414d00f5414d00f5
   prev_func: 0x004d37b0 — — TrackTemperatureDisplay
   next_func: 0x004d4580 — � Steward Update Main Dispatch
   xrefs_into: none

GAP 189: 0x004d5c2e — 0x004d5c40 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x004d5be0 — � FIR Filter / Convolution Accumulator
   next_func: 0x004d5c40 — — Short Computation (Global Zero Pair)
   xrefs_into: none

GAP 190: 0x004d792a — 0x004d7960 (54 bytes)
   hex_head: 9090909090906840794d00e804020b0059c390909090b95cd28a00e9060000009090909090908b410485c0740750e8a5
   prev_func: 0x004d7920 — — Single Function Call Wrapper
   next_func: 0x004d7960 — — TraceLogInit
   xrefs_into: none

GAP 191: 0x004d7fd0 — 0x004d7fe0 (16 bytes)
   hex_head: c87f4d00b07f4d00b87f4d00c07f4d00
   prev_func: 0x004d7fa0 — — Switch-Based Global Lookup (0..3)
   next_func: 0x004d7fe0 — � Delegate with Dereference
   xrefs_into: none

GAP 192: 0x004d8a91 — 0x004d8ab0 (31 bytes)
   hex_head: 8d4900888a4d00478a4d004f8a4d00578a4d005f8a4d00678a4d0090909090
   prev_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   next_func: 0x004d8fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 193: 0x004d921a — 0x004d9280 (102 bytes)
   hex_head: 8bfff2914d0012924d00fa914d0012924d0012924d0012924d0012924d0002924d0002924d0012924d0012924d001292
   prev_func: 0x004d91e0 — — ID-to-Value Mapper
   next_func: 0x004d9280 — — Return 0 Stub
   xrefs_into: none

GAP 194: 0x004d9c0a — 0x004d9dd0 (454 bytes)
   hex_head: 00e849caf2ffa1e0547c00d9807434000081ec80000000d81d40e45900565733ffdfe08bf1f6c441751ed94610d81d40
   prev_func: 0x004d99e0 — — HUD Venue / Track Name Overlay
   next_func: 0x004d9dd0 — — Timer Display Render
   xrefs_into: none

GAP 195: 0x004dad0a — 0x004dad30 (38 bytes)
   hex_head: 8bffe9ac4d0044ac4d0065ac4d0086ac4d00a7ac4d00c8ac4d00909090909090909090909090
   prev_func: 0x004dac30 — — Size/Offset Table by Mode
   next_func: 0x004dad30 — — Single Function Call Wrapper
   xrefs_into: none

GAP 196: 0x004db139 — 0x004db420 (743 bytes)
   hex_head: f889e992ffffffa15ccf5a00894110c74114000080bfc6411801c7411c00000000c39090909090c741140000a041a15c
   prev_func: 0x004db130 — — Physics Constant Initializer
   next_func: 0x004db4e0 — — Dual-Vtable Destructor
   xrefs_into: none

GAP 197: 0x004db9f2 — 0x004dbb60 (366 bytes)
   hex_head: cfe862c6ffff5f5e83e9e6fdffff83ec0856578bf9b934e27c0033f6e88dfffbff84c0740ac644240882be01000000b9
   prev_func: 0x004db9a0 — — Utility Function (Number Format + UI Draw)
   next_func: 0x004dbb60 — — DrawDebugTextOverlay
   xrefs_into: none

GAP 198: 0x004dc401 — 0x004dc430 (47 bytes)
   hex_head: 8d490057c34d0067c34d007dc34d00bfc34d0098c34d00b4c34d00e6c34d00d5c34d00dbc34d009090909090909090
   prev_func: 0x004dc340 — — Alignment/Position Switch
   next_func: 0x004dc430 — — Conditional Dispatch with Global Check
   xrefs_into: none

GAP 199: 0x004de57f — 0x004de5d0 (81 bytes)
   hex_head: 9076e14d0080e14d008ae14d0094e14d008b442404d9400c8b4c2408d9410cd9c1d8d9dfe0f6c441750addd8b8010000
   prev_func: 0x004ddf90 — — Scene File TEAMDIR/VEHDIR/NOTSPIN Writer
   next_func: 0x004de5d0 — � Indexed Struct Field Compute
   xrefs_into: none

GAP 200: 0x004e189e — 0x004e18c0 (34 bytes)
   hex_head: 8bffdd174e003f184e004d184e0073184e0000000000010203030303030303039090
   prev_func: 0x004e17c0 — — Subsystem state machine (activate/deactivate)
   next_func: 0x004e18c0 — — Subsystem ready query
   xrefs_into: none

GAP 201: 0x004e7f37 — 0x004e8010 (217 bytes)
   hex_head: 90908d8b781000008d83b83a0000c74424580d000000d99b683900008bd08b3a8bf1893e8b7a048b5208897e04895608
   prev_func: 0x004e6d93 — � Wheel Contact Force & Suspension Update
   next_func: 0x004e8010 — — Tire Brush Model Force Solver
   xrefs_into: none

GAP 202: 0x004ee133 — 0x004ee150 (29 bytes)
   hex_head: 90aadb4e005edf4e0025e04e0081e04e00909090909090909090909090
   prev_func: 0x004ed960 — — FuelConsumptionAndWear
   next_func: 0x004ee150 — — Engine Wear/Failure Simulation
   xrefs_into: none

GAP 203: 0x004f2382 — 0x004f23a0 (30 bytes)
   hex_head: e8100000005f5d5e83c458c20400e80b000000e916000000909090909090
   prev_func: 0x004f2320 — — Vehicle Dynamics State Reset
   next_func: 0x004f23a0 — — Short Computation (Delegation)
   xrefs_into: none

GAP 204: 0x004f6a9c — 0x004f6ab0 (20 bytes)
   hex_head: 90909090e80b000000e946000000909090909090
   prev_func: 0x004f6a50 — — Quadratic Force/Torque Curve Evaluation
   next_func: 0x004f6ab0 — — Global Table Initialization
   xrefs_into: none

GAP 205: 0x004f6ef9 — 0x004f7010 (279 bytes)
   hex_head: 0589e985feffff8bc133c9880889480489480889480c88481089481489481889481cc390909090568bf1578d96b40000
   prev_func: 0x004f6d90 — — Parametric Interpolation/Blending
   next_func: 0x004f7010 — — StateHandlerDispatch
   xrefs_into: none

GAP 206: 0x004f8cfa — 0x004f8d10 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x004f8cf0 — — Nullsub Wrapper
   next_func: 0x004f8d10 — — Delegation Thunk
   xrefs_into: none

GAP 207: 0x004fb8c2 — 0x004fb8e0 (30 bytes)
   hex_head: 5f5e5d5b59c3ddd85f5e5d5b59c3e80b000000e916000000909090909090
   prev_func: 0x004fb6d0 — — Unidentified Logic / Collision Impulse/Response Computatio
   next_func: 0x004fb8e0 — — Thunk to FUN_004fc9c0
   xrefs_into: none

GAP 208: 0x004fca48 — 0x004fcaa0 (88 bytes)
   hex_head: ff15d4e35900040053558be9568b755433db3bf3742557908bfe385f088b7604740b8b0750e85db1080083c40457e854
   prev_func: 0x004fc9c0 — Initializes a struct with float values and sentinel defaults
   next_func: 0x004fd6d0 — — Two-Call Delegation
   xrefs_into: none

GAP 209: 0x00504f3a — 0x00504f5a (32 bytes)
   hex_head: d64c5000464c50004f4c5000584c5000614c50006a4c5000734c50007c4c5000
   prev_func: 0x00504b37 — — COM Interface Vector Processing Method
   next_func: 0x00504f5a — Complex buffer allocation with vector construction and float
   xrefs_into: none

GAP 210: 0x0050da8b — 0x0050dab2 (39 bytes)
   hex_head: 6a01e815240000ff2534785d006a01e808240000ff2538785d006a01e8fb230000ff2524785d00
   prev_func: 0x0050d9a5 — — Transform/Offset Setup
   next_func: 0x0050dab2 — — Quaternion Normalize and Decompose
   xrefs_into: none

GAP 211: 0x00513cf0 — 0x00513d2f (63 bytes)
   hex_head: 8b442404f6800c01000020740f8b505cb90003000023d13bd17507c3f6405d08751c56ff7424108db000010000ff7424
   prev_func: 0x00513cd8 — — AnimationHandleAlloc
   next_func: 0x00513d2f — — Short Computation / Zero-Init 16 Dwords
   xrefs_into: none

GAP 212: 0x00517e0b — 0x00517e43 (56 bytes)
   hex_head: 207b51007f7b51002b7d5100547d51007d7d5100a67d5100db7d5100e17b5100477c5100747c5100a17c5100ca7c5100
   prev_func: 0x00517ac5 — — [PARTIAL] Unknown
   next_func: 0x00517e43 — — Alloc and Zero Init (Size by Type)
   xrefs_into: none

GAP 213: 0x0051ee66 — 0x0051ee7e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051edae — — Normalized Vector with Threshold (Physics)
   next_func: 0x0051ee7e — — Vector Normalize with Threshold
   xrefs_into: none

GAP 214: 0x0051f7be — 0x0051f7ce (16 bytes)
   hex_head: 8bf6538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051f700 — — Newton-Raphson reciprocal with vector interpolation
   next_func: 0x0051f7ce — — Det3x3From4x4
   xrefs_into: none

GAP 215: 0x0051fb0a — 0x0051fb1e (20 bytes)
   hex_head: 8db600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051f98e — — 4x4 reflection/orientation matrix multiply
   next_func: 0x0051fb1e — — QuaternionToRotationMatrix
   xrefs_into: none

GAP 216: 0x0051ff71 — 0x0051ff8e (29 bytes)
   hex_head: 908db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051febe — — Quaternion Construction/Transform (SSE)
   next_func: 0x0051ff8e — — SSE 3x4 Matrix-Vector Transform
   xrefs_into: none

GAP 217: 0x005201fb — 0x0052020e (19 bytes)
   hex_head: 908d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052014e — — SSE 4x4 Matrix × 4-Vector Multiply
   next_func: 0x0052020e — — 4x4 Matrix Multiply (SSE)
   xrefs_into: none

GAP 218: 0x005204f8 — 0x0052050e (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052042e — — Velocity/Friction Clamp with Stiction Threshold
   next_func: 0x0052050e — — SSEMatrix4x4Multiply
   xrefs_into: none

GAP 219: 0x005208eb — 0x005208fe (19 bytes)
   hex_head: 908d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052087e — — SSEVectorMatrixInit
   next_func: 0x005208fe — — SSE Matrix Construction from 4×4 Data
   xrefs_into: none

GAP 220: 0x00520bfa — 0x00520c0e (20 bytes)
   hex_head: 8db600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x00520a7e — — QuaternionToRotationMatrix
   next_func: 0x00520c0e — — SSE Reciprocal Square Root with Newton-Raphson + Quaternio
   xrefs_into: none

GAP 221: 0x005261ea — 0x005262c2 (216 bytes)
   hex_head: 0f0e8b4424088b54240c8b4c24040f6f000f7fc10f62c00f6ac90f6e50080f62d20f7fc30f0f02b40f7fcc0f0f4a10b4
   prev_func: 0x005261ce — — 3DNow! 4×4 Matrix Multiply Wrapper
   next_func: 0x005262c2 — — Unidentified Logic / SSE/3DNow! Vector Normalize
   xrefs_into: none

GAP 222: 0x00526c88 — 0x0052704a (962 bytes)
   hex_head: 926b52009e6b5200a16b5200a46b5200a86b5200ab6b5200ae6b5200b26b52000f0e8b4424088b54240c8b4c24040f6f
   prev_func: 0x00526b55 — — 3DNow Vector Transform
   next_func: 0x0052704a — — QuaternionProduct3DNow
   xrefs_into: none

GAP 223: 0x00528e09 — 0x00528f00 (247 bytes)
   hex_head: 8db42600000000cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
   prev_func: 0x00528cc0 — â€” Color Space Transformation (3D LUT / Gamma)
   next_func: 0x00528f00 — — 3D Vector Normalize (3DNow!)
   xrefs_into: none

GAP 224: 0x0052981b — 0x00529af8 (733 bytes)
   hex_head: 05000000000f7ec00f7fc10f6e1d5c935d008bd88bd00fdbc381e300000080c1ea1f33c33b0514945d000f6e1510945d
   prev_func: 0x00529700 — � MMX Polynomial Approximation
   next_func: 0x00529af8 — — Field Setter with VTable Alloc
   xrefs_into: none

GAP 225: 0x0052d225 — 0x0052d294 (111 bytes)
   hex_head: 0000000cc300800000000010d45a00c40000000cc400800000000010d45a00c50000000cc500800000000010d45a00c6
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 226: 0x0052d9c6 — 0x0052d9f0 (42 bytes)
   hex_head: 47348b450c5f5e5bc9c3568bf1e8d8fffffff644240801740956e8eaa1050083c4048bc65ec204009090
   prev_func: 0x0052d9b0 — — C++ Constructor (VTable Setup)
   next_func: 0x0052d9f0 — — Object VTable Initialization
   xrefs_into: none

GAP 227: 0x0052e198 — 0x0052e1c0 (40 bytes)
   hex_head: ff1560e35900ffff568bf1e818000000f644240801740956e81a9a050083c4048bc65ec204009090
   prev_func: 0x0052e170 — — Render Object Constructor (vtable + props)
   next_func: 0x0052e1c0 — — Thunk with VTable + Flag Check
   xrefs_into: none

GAP 228: 0x0052e58a — 0x0052e5a0 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x0052e577 — — BufferInitZero
   next_func: 0x0052e5a0 — — Short Computation (Delegation)
   xrefs_into: none

GAP 229: 0x0053554c — 0x00535560 (20 bytes)
   hex_head: 909090906a0133d2e837feffffc3c8e8f910edff
   prev_func: 0x005354e0 — � File Open by Type
   next_func: 0x00535560 — — 4-Bit Field Pack
   xrefs_into: none

GAP 230: 0x00537c9b — 0x00537ce0 (69 bytes)
   hex_head: 90627153004b725300bc725300ea7353008374530067755300b1775300a87b53000f7c5300547c5300c0715300de7153
   prev_func: 0x00537070 — — Multi-Block Allocator
   next_func: 0x00537ce0 — — Triple VTable Call
   xrefs_into: none

GAP 231: 0x0053b018 — 0x0053b0d0 (184 bytes)
   hex_head: ff159ce25900ffff518b4c24080fb654240a33c08ac10fb6cd8954240889442400db4424008b44240c894c240cd80d60
   prev_func: 0x0053b000 — — WrapperTo55EF88
   next_func: 0x0053b0d0 — — Arithmetic/Comparison (Singleton Alloc)
   xrefs_into: none

GAP 232: 0x0053b4a1 — 0x0053b4c0 (31 bytes)
   hex_head: 9090909090909090909090909090908b44240483c02889442404e900000000
   prev_func: 0x0053b4a0 — — Empty Stub
   next_func: 0x0053b4c0 — — Unidentified Logic / 3x3 Rotation Matrix from Quaternion
   xrefs_into: none

GAP 233: 0x0053c14a — 0x0053c190 (70 bytes)
   hex_head: 9090909090906860c15300e8e4b9040059c3909090908a0de48e8b00b00184c875120ac8880de48e8b00b9d06b8b00e9
   prev_func: 0x0053c140 — Call FUN_00556220.
   next_func: 0x0053c190 — — Arithmetic/Comparison (Loop Call x42)
   xrefs_into: none

GAP 234: 0x0053d1c1 — 0x0053d1f0 (47 bytes)
   hex_head: 5f5e5d33c05b81c400010000c20c008b44240450e81600000085c074078bc8e80b570100c20400ff155ce059000400
   prev_func: 0x0053d130 — Searches linked list for matching wide string, frees param_1
   next_func: 0x0053d1f0 — — Wide-String Linked List Search
   xrefs_into: none

GAP 235: 0x0054279a — 0x005427d0 (54 bytes)
   hex_head: 8bff1d2754002c2754003b2754004a275400592754005927540068275400772754001d2754001d2754001d2754001d27
   prev_func: 0x005426a0 — — Audio Emitter Create (Init)
   next_func: 0x00542950 — — Utility Function / Output Device Register
   xrefs_into: none

GAP 236: 0x00545f23 — 0x00545f40 (29 bytes)
   hex_head: 90325e5400405e54004e5e54005c5e5400909090909090909090909090
   prev_func: 0x00545d00 — ? Bitfield Flag Propagation
   next_func: 0x00545f40 — — Value Getter
   xrefs_into: none

GAP 237: 0x00547224 — 0x00547240 (28 bytes)
   hex_head: e1715400f17154000172540011725400909090909090909090909090
   prev_func: 0x005471d0 — — Switch-Based Float Setter
   next_func: 0x00547240 — � Gear Ratio Setter with Flag Condition
   xrefs_into: none

GAP 238: 0x0054c251 — 0x0054c320 (207 bytes)
   hex_head: 740c8d6424008b491040e9c9ffffffe80b000000e9260000009090909090905657be408f8b00bf000100008d6424008b
   prev_func: 0x0054c230 — — Linked List Indexed Accessor
   next_func: 0x0054c410 — — QueueResourceCleanup
   xrefs_into: none

GAP 239: 0x0054eac0 — 0x0054eaf0 (48 bytes)
   hex_head: 68d0ea5400e87490030059c3909090905657be48bf8c00bf000400008d64240083ee188bcee88616f6ff4f75f35f5ec3
   prev_func: 0x0054eaa0 — Call FUN_00548e00() 1024 (0x400) times.
   next_func: 0x0054eaf0 — — Short Computation (Struct Zero-Init)
   xrefs_into: none

GAP 240: 0x0054ffe4 — 0x00550080 (156 bytes)
   hex_head: 1dff540018ff540000000100010101000101010101010100010101010101010101010101010101000101010101010101
   prev_func: 0x0054fe50 — � String Allocation + Path Extract
   next_func: 0x00550080 — — D3D Texture Creation
   xrefs_into: none

GAP 241: 0x00551e94 — 0x00551eb0 (28 bytes)
   hex_head: 181e55001f1e5500261e55002d1e5500909090909090909090909090
   prev_func: 0x00551dd0 — — Bink Video Frame Decoder
   next_func: 0x00551eb0 — 
   xrefs_into: none

GAP 242: 0x00553cc5 — 0x00553db0 (235 bytes)
   hex_head: fbffff5b8946185ec208003bca7e068bc18bca8bd08b442410508b44240c2bd14250528b5424100faf54241803d152e8
   prev_func: 0x00553aa0 — @ 0x00553aa0
   next_func: 0x00553db0 — — Struct Init with Default Values
   xrefs_into: none

GAP 243: 0x005544a7 — 0x005544c0 (25 bytes)
   hex_head: 901b43550063435500ab435500194455005344550090909090
   prev_func: 0x005542f0 — @ 0x005542f0
   next_func: 0x005544c0 — — Game State Setting via Virtual Dispatch
   xrefs_into: none

GAP 244: 0x00556015 — 0x00556040 (43 bytes)
   hex_head: 8d4900855f55008c5f5500935f55009a5f55009f5f55000001020404040404040404040404039090909090
   prev_func: 0x005550e0 — @ 0x005550e0 — 3422 bytes
   next_func: 0x00556040 — — Graphics/Display State Sync with Vehicle
   xrefs_into: none

GAP 245: 0x00556896 — 0x00556900 (106 bytes)
   hex_head: 8b00e81ffde984feffffe80b000000e9260000009090909090905657be70bf8c00bf000200008d6424008bcee83925ff
   prev_func: 0x0055687b — — RDTSC Timestamp Read
   next_func: 0x00556900 — — Add Float to Animation Channels
   xrefs_into: none

GAP 246: 0x0055c62d — 0x0055c650 (35 bytes)
   hex_head: 8d4900a9c4550076c4550099c45500ccc45500efc45500efc455009090909090909090
   prev_func: 0x0055c450 — (0x0055c450)
   next_func: 0x0055c650 — @ 0x0055c650
   xrefs_into: none

GAP 247: 0x0055fa1a — 0x0055fbc0 (422 bytes)
   hex_head: 8bff1af4550054f4550088f45500c6f455006bf955000004040404040404040404040404040404040404040404040404
   prev_func: 0x0055f080 — — Struct Zero-Init Constructor (Large)
   next_func: 0x0055fbc0 — — Global Data Copy
   xrefs_into: none

GAP 248: 0x00561f3a — 0x00561f60 (38 bytes)
   hex_head: 90909090909085c975068b0dfc4d5e00ba01000000e96c0b0000909090909090909090909090
   prev_func: 0x00561ed0 — — Tick Count Comparison, Handle Inactivity Timeout
   next_func: 0x00561f60 — — Single Function Call Wrapper
   xrefs_into: none

GAP 249: 0x00564081 — 0x00564110 (143 bytes)
   hex_head: 7a0783c8ff83c408c333c083c408c38b4c24088b15b4468d008b442404568b098b92800000008b306838a45e00e8fd03
   prev_func: 0x00564000 — — PhysicsObjectNameCompare
   next_func: 0x00564220 — — String Tokenizer (strtok Equivalent)
   xrefs_into: none

GAP 250: 0x0056462f — 0x00564640 (17 bytes)
   hex_head: 908b0150e83764020059c35ec0a9ffccff
   prev_func: 0x00564620 — — Integer Difference Comparator
   next_func: 0x00564640 — — GetTickCount Win32 Stub
   xrefs_into: none

GAP 251: 0x00568782 — 0x005687f0 (110 bytes)
   hex_head: 8bff7b8756007d8756000000010000000000000001010000000001010101010101010101000001000101000101010101
   prev_func: 0x00568750 — — ASCII Char Code Validation (Printable vs Special)
   next_func: 0x00568910 — 
   xrefs_into: none

GAP 252: 0x00579c47 — 0x00579ccf (136 bytes)
   hex_head: 8a8f570007905700849057000191570074915700df915700429257009d925700f09257003b9357007e935700db935700
   prev_func: 0x00578f76 — — InitPhysicsTransformIdentity
   next_func: 0x00579ccf — — Physics State Zero-Init
   xrefs_into: none

GAP 253: 0x00579fba — 0x00579ff0 (54 bytes)
   hex_head: 90909090909068d09f5700e874db000059c390909090b9f13b8d00e9bae90100909090909090e80b000000e916000000
   prev_func: 0x00579fb0 — — [PARTIAL] Unknown
   next_func: 0x00579ff0 — � Single Function Call Wrapper
   xrefs_into: none

GAP 254: 0x0057a55b — 0x0057a570 (21 bytes)
   hex_head: 90909090908b018a405dc390909090909090909090
   prev_func: 0x0057a4f0 — — Virtual Function Dispatch with Stack Frames
   next_func: 0x0057a570 — — Byte Field Setter at Offset +0x5d
   xrefs_into: none

GAP 255: 0x0057a98a — 0x0057a9b0 (38 bytes)
   hex_head: 90909090909068a0a95700e8a4d1000059c390909090b9f43b8d00e92ff10100909090909090
   prev_func: 0x0057a980 — — Entity Constructor Wrapper
   next_func: 0x0057a9b0 — — GenericDtorStub
   xrefs_into: none

GAP 256: 0x0057aa67 — 0x0057aaf0 (137 bytes)
   hex_head: 9090909090909090906880aa5700e8c4d0000059c3909090908a0dfb3b8d00b00184c8756153568b35fc3b8d0033db0a
   prev_func: 0x0057aa50 — @ 0x0057aa50
   next_func: 0x0057aaf0 — — Stack Buffer Copy + Predicate Call
   xrefs_into: none

GAP 257: 0x0057adba — 0x0057adf0 (54 bytes)
   hex_head: 90909090909068d0ad5700e874cd000059c390909090b9f93b8d00e9badb0100909090909090e80b000000e916000000
   prev_func: 0x0057adb0 — � Single Delegation Call
   next_func: 0x0057adf0 — — Single Function Call Wrapper
   xrefs_into: none

GAP 258: 0x0057ae7a — 0x0057aea0 (38 bytes)
   hex_head: 9090909090906890ae5700e8b4cc000059c390909090b9183c8d00e93fec0100909090909090
   prev_func: 0x0057ae70 — — Single Function Call Wrapper (to constructor)
   next_func: 0x0057aea0 — — WindowProc_Ignore6666
   xrefs_into: none

GAP 259: 0x0057b290 — 0x0057b2e0 (80 bytes)
   hex_head: 8a410484c07405b001c204008b411885c089412074288b0085c074228b5424043b1074e38b412085c074068b40048941
   prev_func: 0x0057b230 — — IntSetInsert
   next_func: 0x0057b2e0 — Returns field at param_1+0x24.
   xrefs_into: none

GAP 260: 0x0057b7ac — 0x0057b7f0 (68 bytes)
   hex_head: 90909090568bf1e838000000f644240801740956e80ac4000083c4048bc65ec2040090908b44240456508bf1e8b3b800
   prev_func: 0x0057b780 — — Object Init with VTable + Field Set
   next_func: 0x0057b7f0 — — VTable Pointer Init
   xrefs_into: none

GAP 261: 0x0057d376 — 0x0057d400 (138 bytes)
   hex_head: 8bff1cd3570058d357003ad35700e4d2570044d3570012d3570030d3570062d3570050d2570026d357004ed357006cd3
   prev_func: 0x0057ca10 — (0x0057ca10)
   next_func: 0x0057d5d0 — — Structured Memory Copy with Header Prepend
   xrefs_into: none

GAP 262: 0x0057ed35 — 0x0057ee80 (331 bytes)
   hex_head: 008ac35f5b83e9c3feffff53578bf933db8b87100b00003bc374738b8f140b00005150ff15a0e159003bc374073d8000
   prev_func: 0x0057ec10 — 
   next_func: 0x0057ee80 — — Thread-Safe Mutex Queue with Timed Wait
   xrefs_into: none

GAP 263: 0x0057fed1 — 0x005805c0 (1775 bytes)
   hex_head: 0000e82fd8ffff8a8674e9f9fcffff83ec1c5355568d442410578bd950895c241cc644241700e8d44d000084c00f847b
   prev_func: 0x0057fde0 — — Audio Streaming Thread Shutdown
   next_func: 0x005805c0 — — Network Packet Queue Reader
   xrefs_into: none

GAP 264: 0x00581746 — 0x00581780 (58 bytes)
   hex_head: 15a4e159008bc75f5ec3568bf18a460c84c074158b460450ff15a8e1590085c07407c74604000000005ec3508115a4e1
   prev_func: 0x005816b0 — — Thread Pool Job Dequeue by Type
   next_func: 0x00581780 — — Linked List Node Advance
   xrefs_into: none

GAP 265: 0x00582f2a — 0x00582f60 (54 bytes)
   hex_head: cccc003bccc38a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8e44b0000
   prev_func: 0x00582eb0 — — Linked-List Node Removal with Cleanup Callback
   next_func: 0x00582f60 — — SEH-Protected Linked List Destruction
   xrefs_into: none

GAP 266: 0x00584c27 — 0x00584c70 (73 bytes)
   hex_head: 90fa425800734458005e455800be46580071475800084c5800474858006f485800ed48580020495800994958004e4a58
   prev_func: 0x00584130 — ```
   next_func: 0x00584c70 — — Thread-Safe Call with Mutex
   xrefs_into: none

GAP 267: 0x00585805 — 0x00585860 (91 bytes)
   hex_head: 8115a4e159008bc75f5ec38b814006000053568db12406000085c0741a8b4e205150ff15a0e1590085c074073d800000
   prev_func: 0x005857c0 — — Mutex-Protected Field Write
   next_func: 0x00585860 — — Single Field Setter (Returns 1)
   xrefs_into: none

GAP 268: 0x00585f2e — 0x00585f60 (50 bytes)
   hex_head: 9090568bf18a465884c074158b465050ff15a8e1590085c07407c74650000000008bce5ee9f9d6ffff90909090909090
   prev_func: 0x00585ea0 — — Mutex Pair Initializer
   next_func: 0x00585f60 — — Mutex Wait with Success Check
   xrefs_into: none

GAP 269: 0x00586c86 — 0x00586ca0 (26 bytes)
   hex_head: b8010000005e59c20c008b014083f80689010f9cc0c390909090
   prev_func: 0x00586aa0 — ```
   next_func: 0x00586ca0 — � Bit-Field Extraction with Status
   xrefs_into: none

GAP 270: 0x00586f1a — 0x00586f40 (38 bytes)
   hex_head: 90909090909068306f5800e8140c000059c390909090b9303e8d00e99f2b0100909090909090
   prev_func: 0x00586f10 — — Single Function Call Wrapper
   next_func: 0x00586f40 — — Compute Bitmask from Bitmap Entry Count
   xrefs_into: none

GAP 271: 0x0058763b — 0x00587680 (69 bytes)
   hex_head: e819f0e7ff8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8d404000059
   prev_func: 0x00587620 — — Buffer Write with Params
   next_func: 0x00587680 — � Single Delegate (thunk to FUN_00598815)
   xrefs_into: none

GAP 272: 0x00587a0f — 0x00587a50 (65 bytes)
   hex_head: 908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e80401000059c3909090
   prev_func: 0x005879f0 — — Field Constants Initialization
   next_func: 0x00587a50 — — Thunk to FUN_00598815
   xrefs_into: none

GAP 273: 0x00587b50 — 0x00587b7f (47 bytes)
   hex_head: 6880000000e8db2d000085c059a3545a8d00750d6a18e83b270000a1545a8d0059832000a1545a8d00a3505a8d00c3
   prev_func: 0x00587b3e — — Boolean-to-Int Conversion
   next_func: 0x00587b7f — — Init Wrapper Calling 3 Subroutines
   xrefs_into: none

GAP 274: 0x00589d97 — 0x00589db0 (25 bytes)
   hex_head: cccccccccccccccccc8d42ff5bc38da424000000008d642400
   prev_func: 0x00589d7d — — Utility Function / Function Pointer Array Call-All
   next_func: 0x00589db0 — 
   xrefs_into: none

GAP 275: 0x0058c0f5 — 0x0058c1b1 (188 bytes)
   hex_head: a1405a8d00566a1485c05e7507b800020000eb063bc67d078bc6a3405a8d006a0450e83ceaffff59a3244a8d0085c059
   prev_func: 0x0058c0d0 — — String Shift by Offset
   next_func: 0x0058c1b1 — — Stream Buffer Lock via Critical Section
   xrefs_into: none

GAP 276: 0x0058db63 — 0x0058dc29 (198 bytes)
   hex_head: e8c1000000d9c9ddd8c3e8b7000000ebf6ddd8ddd8d9eec3ddd8ddd8d9e8c3dbbd62ffffffdbad62fffffff68569ffff
   prev_func: 0x0058dad7 — @ 0x0058dad7
   next_func: 0x0058dc29 — — SetByteFlag
   xrefs_into: none

GAP 277: 0x0059083b — 0x0059086e (51 bytes)
   hex_head: 558bec81c430fdffff53ff750cff7508e81e00000083c4089bd9bd5cffffff80a538fdfffffde80ad2ffffe898feffff
   prev_func: 0x0059070a — (0x0059070a)
   next_func: 0x0059086e — — CRT __fload (float load)
   xrefs_into: none

GAP 278: 0x0059573c — 0x005957bd (129 bytes)
   hex_head: 53576a0233dbe8a388ffff596a035f393d405a8d007e5d56a1244a8d008bf7c1e6028b040685c07441f6400c83740d50
   prev_func: 0x00595733 — — __amsg_exit Runtime Error (CRT)
   next_func: 0x005957bd — — Memory Allocator Init (0x1000)
   xrefs_into: none

GAP 279: 0x00597371 — 0x00597388 (23 bytes)
   hex_head: 6a0ae87bbfffff6a16e80900000059596a03e82d29ffff
   prev_func: 0x00597359 — — Code Pointer Validation (IsBadCodePtr Wrapper)
   next_func: 0x00597388 — @ 0x00597388 — 386 bytes
   xrefs_into: none

GAP 280: 0x00599754 — 0x0059977e (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x00599707 — — Char-by-Char Backward Scan with Validation
   next_func: 0x0059977e — — Cleanup Wrapper
   xrefs_into: none

GAP 281: 0x0059a50b — 0x0059a535 (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x0059a4c9 — — Self-Referential Pointer Ring Init
   next_func: 0x0059a535 — — Delegation (atexit Register)
   xrefs_into: none

GAP 282: 0x0059b050 — 0x0059b07a (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x0059b038 — — Object Init with VTable
   next_func: 0x0059b07a — — Single Function Call Wrapper
   xrefs_into: none

GAP 283: 0x0059c3f5 — 0x0059ca3b (1606 bytes)
   hex_head: ccccccccccccccccccccccff75ace8c7b7feff59c3ff75a4e8bdb7feff59c3ff75b8e8b3b7feff59c3b870a45b00e958
   prev_func: 0x0059c30e — @ 0x0059c30e — 231 bytes
   next_func: 0x0059ca3b — — ExceptionHandlerThunk
   xrefs_into: none

GAP 284: 0x0059ca95 — 0x0059caa8 (19 bytes)
   hex_head: cccccccccccccccccccccc8d4db4e9b8dfedff
   prev_func: 0x0059ca8b — — CxxFrameHandlerWrapper
   next_func: 0x0059caa8 — — CxxFrameHandlerWrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_A.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
