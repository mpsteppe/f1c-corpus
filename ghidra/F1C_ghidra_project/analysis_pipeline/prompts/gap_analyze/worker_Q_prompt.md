# WORKER Q — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker Q of 20, items 685–726.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_Q.md

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

GAP 685: 0x00407405 — 0x00407520 (283 bytes)
   hex_head: 5052e8290b00005ec20c008b44240483e80074164875236a326a2aff159ce35900ff15f4e35900c204006a086a2aff15
   prev_func: 0x004072e0 — — Miles Sound System Sample Allocator
   next_func: 0x00407520 — — Linked List Node Insert
   xrefs_into: none

GAP 686: 0x0040b48b — 0x0040b560 (213 bytes)
   hex_head: 4d5954480083ec1c5356578b7c242c32db85ff8bf1744e8b460c85c07447688000000057e88205180083c4088d4c240c
   prev_func: 0x0040b450 — — Lookup with Optional Callback
   next_func: 0x0040b560 — — Struct Init with Vtable
   xrefs_into: none

GAP 687: 0x0040ef52 — 0x0040ef70 (30 bytes)
   hex_head: 8bff0eef40000eef40000eef40000eef40000eef40000eef400090909090
   prev_func: 0x0040eec0 — Processes float parameters through math functions based on a
   next_func: 0x0040ef70 — — Physics State Vector Conversion
   xrefs_into: none

GAP 688: 0x004140e4 — 0x00414140 (92 bytes)
   hex_head: 28404100324041003c404100464041004d404100544041005b404100624041006940410070404100774041007e404100
   prev_func: 0x00414010 — — Enum Value Translation (Resource IDs)
   next_func: 0x00414140 — — Decrement Counter with Floor at Zero
   xrefs_into: none

GAP 689: 0x0041f147 — 0x0041f190 (73 bytes)
   hex_head: ff1538e05900c05bc3568bf185f67420b9b02d7d00e8ef360a008bc8e868200a0085c07e0b837c8614047f04b0015ec3
   prev_func: 0x0041f100 — — Triple-Value Equality Check
   next_func: 0x0041f190 — — Short Computation (Multi-Condition State Check)
   xrefs_into: none

GAP 690: 0x0042ce0a — 0x0042ce20 (22 bytes)
   hex_head: 9090909090906820ce4200e824ad150059c390909090
   prev_func: 0x0042ce00 — — Thunk
   next_func: 0x0042ce20 — — SessionType5Nullsub
   xrefs_into: none

GAP 691: 0x00438c9f — 0x00438cc0 (33 bytes)
   hex_head: 90568bf1e8885500008d8eac150000e85d4713008d8eec0100005ee931ccffff90
   prev_func: 0x00438c10 — — Dynamics Object Initialization
   next_func: 0x00438cc0 — — BrakeBiasSetup
   xrefs_into: none

GAP 692: 0x0044c829 — 0x0044c840 (23 bytes)
   hex_head: 909090909090906840c84400e804b3130059c390909090
   prev_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   next_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   xrefs_into: none

GAP 693: 0x0044cbe9 — 0x0044cc00 (23 bytes)
   hex_head: 909090909090906800cc4400e844af130059c390909090
   prev_func: 0x0044cbd4 — — GlobalStateInitNegOne
   next_func: 0x0044cc20 — — Collision Globals Init #4 (DAT_007ca3b8)
   xrefs_into: none

GAP 694: 0x0044cfa9 — 0x0044cfc0 (23 bytes)
   hex_head: 9090909090909068c0cf4400e884ab130059c390909090
   prev_func: 0x0044cf94 — — Audio Mixer Gain Init
   next_func: 0x0044cfe0 — — Collision Material Coefficients Set 6 (ID 40, 1.0f)
   xrefs_into: none

GAP 695: 0x0044d369 — 0x0044d380 (23 bytes)
   hex_head: 909090909090906880d34400e8c4a7130059c390909090
   prev_func: 0x0044d340 — — CollisionGlobalInitG
   next_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   xrefs_into: none

GAP 696: 0x00453293 — 0x004532d0 (61 bytes)
   hex_head: ebdbd90540e45900e9f6feffff56578db110240000bf2c0000008d49008b46f883ee0885c0740950e80f49130083c404
   prev_func: 0x004531a0 — — Memory Allocation / Large Struct Initializer
   next_func: 0x004532d0 — — AudioSceneUpdateLoop (sound parameter iteration)
   xrefs_into: none

GAP 697: 0x0045cc23 — 0x0045cd50 (301 bytes)
   hex_head: ffff4683fe687cf25f5ec20400b918fe8a00e826d309008b4424088b4c2410dd18a0a4567c008b54240cc70101000000
   prev_func: 0x0045cbf0 — — Short Array Lookup and Zero Check
   next_func: 0x0045cd50 — — Struct Initializer (Flags + Fields)
   xrefs_into: none

GAP 698: 0x004661a5 — 0x0046624e (169 bytes)
   hex_head: 90909090909032c0c20c00568bf18b86e800000085c0740b8b4e406a0056e888050300d98624010000d81d40e45900df
   prev_func: 0x00466160 — Forwards call to another function. No additional logic.
   next_func: 0x00466250 — Calls FUN_004988a0(3) and sets byte flag at +0xf4 to 1, retu
   xrefs_into: none

GAP 699: 0x0046a24a — 0x0046a270 (38 bytes)
   hex_head: 00e809c4f9ff568bf1e818000000f644240801740956e86ad9110083c4048bc65ec204009090
   prev_func: 0x0046a220 — — Object Constructor with VTable
   next_func: 0x0046a270 — — VTable Set + Free + Call
   xrefs_into: none

GAP 700: 0x004702fb — 0x00470400 (261 bytes)
   hex_head: 9090909090568bf18b86040300000551feffff83f8060f87c4000000ff2485e00347006a1a6818d87c008bcec60518d8
   prev_func: 0x004702f0 — — Short Computation (VTable Set)
   next_func: 0x00470400 — — Engine Temperature Debug Display
   xrefs_into: none

GAP 701: 0x00477f9e — 0x00478e80 (3810 bytes)
   hex_head: 9090568bf18b4e408b01576a03ff501c8bf885ff74268bcfe8a553010039861c01000074178bcfe8965301008b168bce
   prev_func: 0x00477f30 — — ProfileIconBmpLoader
   next_func: 0x00478e80 — Delegates to FUN_00499b80().
   xrefs_into: none

GAP 702: 0x0047ef75 — 0x0047eff0 (123 bytes)
   hex_head: 8d490093eb4700c1eb4700efeb47001dec47004bec470079ec4700a7ec4700d5ec470003ed470031ed47005bed470085
   prev_func: 0x0047ef3c — — Percentage Display Formatter
   next_func: 0x0047eff0 — — Short Computation (UI List Init)
   xrefs_into: none

GAP 703: 0x00488301 — 0x004883a0 (159 bytes)
   hex_head: 040090909090906a00e879e2ffffc383ec34568bf18b0657ff90a80000008bf885ff743f538d9ee0000000538bcfe8bc
   prev_func: 0x004881f0 — � Surface Render Region Setup
   next_func: 0x004883a0 — — 5-Field Init
   xrefs_into: none

GAP 704: 0x0048d7c3 — 0x0048d850 (141 bytes)
   hex_head: 909090909090909090909090908b01ff90ac00000033c0c390909090908b016a00ff504033c0c333e8698ef7ff8b5424
   prev_func: 0x0048d740 — — Large Zero-Init Constructor
   next_func: 0x0048d850 — — UI Scroll Area/Auto-Scroll Manager
   xrefs_into: none

GAP 705: 0x00491e91 — 0x00491ee0 (79 bytes)
   hex_head: 56e85f5d0f0083c4048be9d9ffffffe90b000000909090909090909090909033c057b960000000bf70db7c00f3aba358
   prev_func: 0x00491e80 — General utility function. See decompiled code for exact beha
   next_func: 0x00491ee0 — — File Open Wrapper with Mode Check
   xrefs_into: none

GAP 706: 0x0049966a — 0x00499680 (22 bytes)
   hex_head: 9090909090906880964900e8c4e40e0059c390909090
   prev_func: 0x00499660 — — Short Computation / Single Call Wrapper
   next_func: 0x00499680 — — NullsubWrapper
   xrefs_into: none

GAP 707: 0x0049e489 — 0x0049e4e0 (87 bytes)
   hex_head: 00e8b90d0000c333c0880189410489410889410c89411089411489411889411c89412089412489412889412c89413089
   prev_func: 0x0049e410 — — Dual Text Display
   next_func: 0x0049e4e0 — — Audio/Effect Trigger
   xrefs_into: none

GAP 708: 0x004a6fc4 — 0x004a6fe0 (28 bytes)
   hex_head: c41ce9bed2ffff5e83c41cc3e80b000000e916000000909090909090
   prev_func: 0x004a6e50 — — Pit State Update Machine
   next_func: 0x004a6fe0 — � Single Call Wrapper
   xrefs_into: none

GAP 709: 0x004b3d4a — 0x004b3d60 (22 bytes)
   hex_head: 90909090909068603d4b00e8e43d0d0059c390909090
   prev_func: 0x004b3d40 — — Single Function Call Wrapper
   next_func: 0x004b3d60 — — Nullsub Wrapper (UI Singleton)
   xrefs_into: none

GAP 710: 0x004b9e02 — 0x004b9e30 (46 bytes)
   hex_head: 8bffb79d4b00c49d4b00d29d4b00de9d4b00ea9d4b00f69d4b000000000000000000000102030405909090909090
   prev_func: 0x004b9da0 — — MenuActionDispatch
   next_func: 0x004b9e30 — — Vehicle Data Accessor
   xrefs_into: none

GAP 711: 0x004c7773 — 0x004c77d0 (93 bytes)
   hex_head: 908b4f38c1e91980e101888b671000008bcde876b3feff508bcbe85e0400008bcde8e7b3feff668983b04800008a573b
   prev_func: 0x004c73f0 — — Vehicle Physics Time Step
   next_func: 0x004c77d0 — — TireTemperatureSimStep
   xrefs_into: none

GAP 712: 0x004d22f1 — 0x004d23d0 (223 bytes)
   hex_head: 90909090909090909090909090909051b95cd27c00e8a5faf8ff84c07421dd05a0fe8a00dc1df0ce5a00dfe0f6c4050f
   prev_func: 0x004d22c0 — Set flag, float from global, copy field, call FUN_0042d140.
   next_func: 0x004d23d0 — — Pit Timer State Init
   xrefs_into: none

GAP 713: 0x004d921a — 0x004d9280 (102 bytes)
   hex_head: 8bfff2914d0012924d00fa914d0012924d0012924d0012924d0012924d0002924d0002924d0012924d0012924d001292
   prev_func: 0x004d91e0 — — ID-to-Value Mapper
   next_func: 0x004d9280 — — Return 0 Stub
   xrefs_into: none

GAP 714: 0x004e169a — 0x004e16c0 (38 bytes)
   hex_head: 8bff240f4e0072114e006c134e0047164e0030104e00cc104e00000100010100009090909090
   prev_func: 0x004e0ed0 — — Audio/Sound Effect Controller
   next_func: 0x004e16c0 — Reads 6 fields from param_1 and passes to FUN_0054b4d0.
   xrefs_into: none

GAP 715: 0x004f9121 — 0x004f9150 (47 bytes)
   hex_head: 8d49007a8f4f00da8f4f0020904f00a1904f00909090909090909090909090568bf1e858fa06008bc65ec390909090
   prev_func: 0x004f8f10 — — Conditional Init Branch
   next_func: 0x004f9150 — — Short Computation (Delegation)
   xrefs_into: none

GAP 716: 0x0051ee66 — 0x0051ee7e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051edae — — Normalized Vector with Threshold (Physics)
   next_func: 0x0051ee7e — — Vector Normalize with Threshold
   xrefs_into: none

GAP 717: 0x00520a64 — 0x00520a7e (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052098e — — PlaneFromEdgesNormalizeSSE
   next_func: 0x00520a7e — — QuaternionToRotationMatrix
   xrefs_into: none

GAP 718: 0x0052df5d — 0x0052df70 (19 bytes)
   hex_head: 909090e80b000000e9f6000000909090909090
   prev_func: 0x0052df10 — — [PARTIAL] Unknown
   next_func: 0x0052df70 — — State Check and Conditional Init
   xrefs_into: none

GAP 719: 0x0053c14a — 0x0053c190 (70 bytes)
   hex_head: 9090909090906860c15300e8e4b9040059c3909090908a0de48e8b00b00184c875120ac8880de48e8b00b9d06b8b00e9
   prev_func: 0x0053c140 — Call FUN_00556220.
   next_func: 0x0053c190 — — Arithmetic/Comparison (Loop Call x42)
   xrefs_into: none

GAP 720: 0x0054fd1d — 0x0054fd30 (19 bytes)
   hex_head: 8d49000efd5400fbfc5400e8fc5400d5fc5400
   prev_func: 0x0054fcc0 — — Unidentified Logic (Render/Format Mode Set)
   next_func: 0x0054fd30 — — Short Computation / Struct Field Double-Setter
   xrefs_into: none

GAP 721: 0x0055c9b7 — 0x0055ca40 (137 bytes)
   hex_head: 83c8ff83e992feffff568bf18b860011000085c05774638b44240c8986e41300008b86b013000033ff85c07e4d538d9e
   prev_func: 0x0055c9b0 — Returns field at param_1+0x1550.
   next_func: 0x0055ca40 — — Enum-to-VTable-Call Mapper (3 Cases)
   xrefs_into: none

GAP 722: 0x00579fba — 0x00579ff0 (54 bytes)
   hex_head: 90909090909068d09f5700e874db000059c390909090b9f13b8d00e9bae90100909090909090e80b000000e916000000
   prev_func: 0x00579fb0 — — [PARTIAL] Unknown
   next_func: 0x00579ff0 — � Single Function Call Wrapper
   xrefs_into: none

GAP 723: 0x0057b6ca — 0x0057b780 (182 bytes)
   hex_head: cc00004bcc0051568bf18b4c24108d442404578b7c24105051578bcec744241400000000e87debffff8b542408668b8e
   prev_func: 0x0057b6c0 — — Setter at +0x24
   next_func: 0x0057b780 — — Object Init with VTable + Field Set
   xrefs_into: none

GAP 724: 0x00584f27 — 0x00584f90 (105 bytes)
   hex_head: 9090909090909090908b81a805000053568db19805000032db85c074388b4e145150ff15a0e1590085c074073d800000
   prev_func: 0x00584e30 — @ 0x00584e30 — 247 bytes
   next_func: 0x00584f90 — — Mutex-Guarded Timer Read
   xrefs_into: none

GAP 725: 0x00587b50 — 0x00587b7f (47 bytes)
   hex_head: 6880000000e8db2d000085c059a3545a8d00750d6a18e83b270000a1545a8d0059832000a1545a8d00a3505a8d00c3
   prev_func: 0x00587b3e — — Boolean-to-Int Conversion
   next_func: 0x00587b7f — — Init Wrapper Calling 3 Subroutines
   xrefs_into: none

GAP 726: 0x005992d3 — 0x005992ef (28 bytes)
   hex_head: 568bf1e85efbfffff644240801740756e8e7e8feff598bc65ec20400
   prev_func: 0x005992b7 — — Destructor with Flag Cleanup
   next_func: 0x005992ef — Realloc if needed; validate; _memset fill; null-terminate
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_Q.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
