# WORKER B — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker B of 3, items 285–568.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_B.md

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

GAP 285: 0x00404805 — 0x00404850 (75 bytes)
   hex_head: 0100003bf87ce25b5f5ec3e80b000000e916000000909090909090b93ca45e00e9260200009090909090906840484000
   prev_func: 0x004047d0 — — Counted Loop Call to Element Update
   next_func: 0x00404850 — — Path String Utility
   xrefs_into: none

GAP 286: 0x00405879 — 0x004058a0 (39 bytes)
   hex_head: 5e83e962ffffff568bf1e818000000f644240801740956e83a23180083c4048bc65ec204009090
   prev_func: 0x004057f0 — — View/Projection Struct Init
   next_func: 0x004058a0 — — Object Constructor with VTable and Sub-Free
   xrefs_into: none

GAP 287: 0x0040620f — 0x00406250 (65 bytes)
   hex_head: 90f644240401568bf1c7060ce55900740956e8a919180083c4048bc65ec2040090568bf1e818000000f6442408017409
   prev_func: 0x00406130 — — Mutex/Synchronization Object Init
   next_func: 0x00406250 — — short computation
   xrefs_into: none

GAP 288: 0x00406b74 — 0x00406ba0 (44 bytes)
   hex_head: f9ff0f95c05e83e9ebfeffff568bf1e818000000f644240801740956e83a10180083c4048bc65ec204009090
   prev_func: 0x00406b60 — — MenuSelectSetter
   next_func: 0x00406ba0 — Destructor that destroys 4 linked lists with different clean
   xrefs_into: none

GAP 289: 0x00406ff1 — 0x004070e0 (239 bytes)
   hex_head: 89472074068b083bcb75e943feffff53568bf18b464885c074278b464c33db85c07e1e5733ff8b46488b0c0785c97405
   prev_func: 0x00406f90 — — Object Array + Linked-List Walk
   next_func: 0x004070e0 — — Spatial Query with Weighted Distance Selection
   xrefs_into: none

GAP 290: 0x00407405 — 0x00407520 (283 bytes)
   hex_head: 5052e8290b00005ec20c008b44240483e80074164875236a326a2aff159ce35900ff15f4e35900c204006a086a2aff15
   prev_func: 0x004072e0 — — Miles Sound System Sample Allocator
   next_func: 0x00407520 — — Linked List Node Insert
   xrefs_into: none

GAP 291: 0x00408200 — 0x00408210 (16 bytes)
   hex_head: e80b000000e916000000909090909090
   prev_func: 0x004081e0 — General utility function. See decompiled code for exact beha
   next_func: 0x00408210 — — Delegation Wrapper to FUN_00408280
   xrefs_into: none

GAP 292: 0x004084ff — 0x00408520 (33 bytes)
   hex_head: 90568bf1e818000000f644240801740956e8baf6170083c4048bc65ec204009090
   prev_func: 0x004084b0 — — short computation
   next_func: 0x00408520 — — Vtable Entry Notify/Cleanup
   xrefs_into: none

GAP 293: 0x004087da — 0x00408800 (38 bytes)
   hex_head: 8bff598740005e87400063874000688740006d8740007d87400082874000878740008c874000
   prev_func: 0x00408740 — — Float-Keyed Field Selector
   next_func: 0x00408800 — — File Path Entry Array Destructor
   xrefs_into: none

GAP 294: 0x00409946 — 0x00409970 (42 bytes)
   hex_head: 0000005b83c41cc208008b0d64fe8a006a016a20e8a10814008b0d88fe8a00e926c2130033e8e9ccffff
   prev_func: 0x00409770 — � File Resource Processing with Callbacks
   next_func: 0x00409970 — — Conditional Camera Pipeline Setup
   xrefs_into: none

GAP 295: 0x00409f51 — 0x0040a610 (1727 bytes)
   hex_head: a10814008b0d88fe8a00e90afaffffa170c47c0083ec1885c053568bf18b4e4057751fa088137d0084c07412a144c47c
   prev_func: 0x00409f40 — — VTable Dispatch Chain (GetObject + GetChild)
   next_func: 0x0040a610 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 296: 0x0040ac1a — 0x0040ac40 (38 bytes)
   hex_head: 5de839baffff568bf1e818000000f644240801740956e89acf170083c4048bc65ec204009090
   prev_func: 0x0040ac00 — Initializes a 6-dword struct with vtable, zeroing all fields
   next_func: 0x0040ac40 — — VTable Switch
   xrefs_into: none

GAP 297: 0x0040b57a — 0x0040b5a0 (38 bytes)
   hex_head: 83e8d9b0ffff568bf1e818000000f644240801740956e83ac6170083c4048bc65ec204009090
   prev_func: 0x0040b560 — — Struct Init with Vtable
   next_func: 0x0040b5a0 — — VTable Switch with Virtual Call
   xrefs_into: none

GAP 298: 0x0040bfc1 — 0x0040c070 (175 bytes)
   hex_head: 8d49006abf400075bf400080bf4000f3be400015bf40004cbf4000b7be40008cbf400000070707010707070707070707
   prev_func: 0x0040be70 — — Keyboard Input Action Mapper
   next_func: 0x0040c070 — Timer-based state trigger with random outcome selection and 
   xrefs_into: none

GAP 299: 0x0040cdb9 — 0x0040cdd0 (23 bytes)
   hex_head: 8d490077cd400082cd40008dcd400098cd4000a3cd4000
   prev_func: 0x0040cd60 — — Session Phase Decode
   next_func: 0x0040cdd0 — — Simple Setter (Struct + 8 = param_2)
   xrefs_into: none

GAP 300: 0x0040d197 — 0x0040d1b0 (25 bytes)
   hex_head: 907fd140001fd1400037d140004fd1400067d1400090909090
   prev_func: 0x0040d100 — — Game State Branch Dispatch
   next_func: 0x0040d1b0 — — Session Phase Dispatch with Cascade Checks
   xrefs_into: none

GAP 301: 0x0040de4b — 0x0040de60 (21 bytes)
   hex_head: 9047de400009de4000000000010101019090909090
   prev_func: 0x0040ddf0 — — Cinematic Event State Machine
   next_func: 0x0040de60 — ? AI Behavior State Machine
   xrefs_into: none

GAP 302: 0x0040e1ca — 0x0040e1e0 (22 bytes)
   hex_head: 90909090909068e0e14000e86499170059c390909090
   prev_func: 0x0040e1c0 — — Delegation Thunk
   next_func: 0x0040e1e0 — — Wrapper: sub_40FB30
   xrefs_into: none

GAP 303: 0x0040ee9e — 0x0040eec0 (34 bytes)
   hex_head: 8bff31ed400031ed400031ed400031ed400031ed400031ed4000bfed4000eaed4000
   prev_func: 0x0040ed10 — ? Spatial Distance Query
   next_func: 0x0040eec0 — Processes float parameters through math functions based on a
   xrefs_into: none

GAP 304: 0x0040f199 — 0x0040f1c0 (39 bytes)
   hex_head: 8d490042f1400048f140004ef1400042f1400048f140004ef14000909090909090909090909090
   prev_func: 0x0040f130 — — State-Dependent Update Dispatch
   next_func: 0x0040f1c0 — — Scene Object Loader State Machine
   xrefs_into: none

GAP 305: 0x0040f481 — 0x0040f4b0 (47 bytes)
   hex_head: 8d49009af340009af34000bdf340009af340009af340009af34000f4f3400047f44000909090909090909090909090
   prev_func: 0x0040f380 — — Switch-Based State Handler
   next_func: 0x0040f4b0 — — Mode Dispatch with Switch (0-6)
   xrefs_into: none

GAP 306: 0x0040fae4 — 0x0040fb30 (76 bytes)
   hex_head: 66f640008ef64000b6f64000daf64000fff6400024f740009090909033c0568bf1894608894610894618894620894628
   prev_func: 0x0040f600 — — Camera Shake Ring Buffer Write
   next_func: 0x0040fb30 — — Graphics Resource Destructor
   xrefs_into: none

GAP 307: 0x004110fd — 0x00411120 (35 bytes)
   hex_head: 8d4900820f4100a80f4100be0f4100e10f4100fd0f4100201041009090909090909090
   prev_func: 0x00410f60 — — SceneNodeDecoder
   next_func: 0x00411120 — — Session Structure Cleanup
   xrefs_into: none

GAP 308: 0x00411d42 — 0x00411db0 (110 bytes)
   hex_head: 8bff301c41003b1d4100751c4100971c4100b71c4100d91c4100f91c41001b1d4100551c41003b1d4100000900000102
   prev_func: 0x00411bf0 — — Race Event Message Dispatcher
   next_func: 0x00411db0 — — Font Character Render Dispatcher
   xrefs_into: none

GAP 309: 0x00412dc6 — 0x00412e50 (138 bytes)
   hex_head: 8bff992d4100892d4100792d4100692d4100592d4100492d4100392d4100292d4100192d4100062d4100f32c4100e02c
   prev_func: 0x00412c30 — — MapCollisionShapeToBoneIndex
   next_func: 0x00412e50 — â€” DirectInput Scancode Mapping
   xrefs_into: none

GAP 310: 0x004140e4 — 0x00414140 (92 bytes)
   hex_head: 28404100324041003c404100464041004d404100544041005b404100624041006940410070404100774041007e404100
   prev_func: 0x00414010 — — Enum Value Translation (Resource IDs)
   next_func: 0x00414140 — — Decrement Counter with Floor at Zero
   xrefs_into: none

GAP 311: 0x0041505d — 0x00415090 (51 bytes)
   hex_head: 9090908bc133c9890889480489480889480c89481089481489481889481c89482089482489482889482cc35f885e105e
   prev_func: 0x00414fe0 — — Text Format Struct Initializer (Small)
   next_func: 0x00415090 — — short computation
   xrefs_into: none

GAP 312: 0x00418a51 — 0x00418ac0 (111 bytes)
   hex_head: baffffb00183c1204a75e9b7ffffff568bf18b8ef40a000085c974258b01ff500885c0741c8b86ec0a000085c07e123d
   prev_func: 0x00418a20 — — Boolean OR of Two Checks
   next_func: 0x00418ac0 — — Array Slot Compaction with Gap Filling
   xrefs_into: none

GAP 313: 0x00418dc7 — 0x00418e50 (137 bytes)
   hex_head: 90909090909090909068e08d4100e864ed160059c390909090b978b95e00e9060000009090909090905355568be9e8c6
   prev_func: 0x00418db0 — — Global Variable Zero-Init
   next_func: 0x00418e50 — — HUD/Display Data Reset
   xrefs_into: none

GAP 314: 0x0041ac39 — 0x0041ac50 (23 bytes)
   hex_head: 8d4900c3ab4100d9ab4100efab410005ac410090909090
   prev_func: 0x0041ab30 — — Pit State Slot Activation / Commentary
   next_func: 0x0041ac50 — � Race Event Sound Dispatch
   xrefs_into: none

GAP 315: 0x0041b8f0 — 0x0041b910 (32 bytes)
   hex_head: 99b44100d0b8410081b6410027b84100d0b8410043b841009090909090909090
   prev_func: 0x0041b3c0 — — Pit Selection State Machine
   next_func: 0x0041b910 — — Clear Pit Selection Flags
   xrefs_into: none

GAP 316: 0x0041c53a — 0x0041d630 (4342 bytes)
   hex_head: ffe819a1feffa108037d0083ec2c85c053560f84a3090000d905c8f37c00d81d40e45900dfe0f6c4440f8b8c09000083
   prev_func: 0x0041c4c0 — — Position-based Message Display
   next_func: 0x0041d630 — — Race Commentary / Best Lap Tracking
   xrefs_into: none

GAP 317: 0x0041f55b — 0x0041f5d0 (117 bytes)
   hex_head: 908cf3410093f341009af34100a1f34100a8f34100aff34100b6f34100bdf34100c4f34100cbf34100d2f34100d9f341
   prev_func: 0x0041f220 — — Championship Points Accumulator
   next_func: 0x0041f8a0 — — Constructor Championship Clinch Detection
   xrefs_into: none

GAP 318: 0x0041ff05 — 0x00420000 (251 bytes)
   hex_head: 0183c454c332c083c454c383ec5053568bd957b9b02d7d00e86e2a0a008bf86a508d44241050b9b02d7d00e81b290a00
   prev_func: 0x0041fe00 — — ConfigSectionSearchByKeyValue
   next_func: 0x004203d0 — Trampoline -- unconditional jmp to FUN_004201e0. No local lo
   xrefs_into: none

GAP 319: 0x00421200 — 0x004212e0 (224 bytes)
   hex_head: af0d4200b60d4200bd0d4200c40d4200cb0d4200d20d4200d90d4200e00d4200e70d4200ee0d4200f50d4200fc0d4200
   prev_func: 0x00420490 — — Position Change Detector
   next_func: 0x004212e0 — — Short Computation (Session Score Aggregation)
   xrefs_into: none

GAP 320: 0x0042347e — 0x00423490 (18 bytes)
   hex_head: 9090e80b000000e916000000909090909090
   prev_func: 0x00423459 — — Handle/Resource Cleanup (LocalFree + FreeSid)
   next_func: 0x00423490 — — Single Function Call Wrapper
   xrefs_into: none

GAP 321: 0x004263e9 — 0x00426430 (71 bytes)
   hex_head: 9090ded9dfe0f6c44175e4d981cc370000d81dcce85900dfe0f6c44175d1d981c4380000d81dcce85900dfe0f6c44175
   prev_func: 0x00426330 — — Physics Gear/Shift Logic with Thresholds
   next_func: 0x00426430 — â€” AI Waypoint Steering
   xrefs_into: none

GAP 322: 0x0042b8aa — 0x0042b8c0 (22 bytes)
   hex_head: 90909090909068c0b84200e884c2150059c390909090
   prev_func: 0x0042b8a0 — — Thunk to FUN_004b3db0
   next_func: 0x0042b8c0 — — Stub to Nullsub
   xrefs_into: none

GAP 323: 0x0042cde1 — 0x0042ce00 (31 bytes)
   hex_head: 008b0485f0547c00a3e0547c005ec3e80b000000e916000000909090909090
   prev_func: 0x0042caa0 — — AI Lateral Force Computation
   next_func: 0x0042ce00 — — Thunk
   xrefs_into: none

GAP 324: 0x0042d1f4 — 0x0042d210 (28 bytes)
   hex_head: cdd14200f0d14200cdd1420083d14200cdd142009090909090909090
   prev_func: 0x0042cee0 — — PenaltyStateDefaultInit
   next_func: 0x0042d350 — — Session Reset
   xrefs_into: none

GAP 325: 0x0042ea97 — 0x0042ebc0 (297 bytes)
   hex_head: ff155ce05900f9ffff538b5c24088bc36bc00b558b6c241003c556c1e0068bf18b8c30c4000000578dbc30b00000008b
   prev_func: 0x0042e530 — — Track Config / Garage Auto-Setup
   next_func: 0x0042ebc0 — — History Buffer Shift
   xrefs_into: none

GAP 326: 0x0043138a — 0x004313c0 (54 bytes)
   hex_head: 83e8c952fdff8b442404d9442408c681a419000000c60101d99c81a81c0000e812000000c20800e06d150083c4145f5e
   prev_func: 0x00430f00 — — Vehicle Stats Estimation Display (ACCEL/TOP SPEED/CORNERIN
   next_func: 0x004313c0 — — Pressure/Force Field Mapping
   xrefs_into: none

GAP 327: 0x00431bca — 0x00431c00 (54 bytes)
   hex_head: 90909090909068e01b4300e8645f150059c390909090b9e0737c00e9e6040000909090909090e80b000000e966000000
   prev_func: 0x00431bc0 — — Thunk
   next_func: 0x00431c00 — — PhysicsGlobalStateInit
   xrefs_into: none

GAP 328: 0x00432816 — 0x00432870 (90 bytes)
   hex_head: 8b096a00e8e9bafeffff8b018b54240483c02085d27c2f3b500c7d2a85d28b007e0c85c074208b40044a85d27ff485c0
   prev_func: 0x00432810 — — Vehicle Field Accessor (Offset +0x2C)
   next_func: 0x00432870 — — Path String Combinator
   xrefs_into: none

GAP 329: 0x00433fb5 — 0x00434000 (75 bytes)
   hex_head: 042813005f5ee993feffff538b5c24085657be01000000568bf953b9c0567c00e826bdffff85c075138a44241433f684
   prev_func: 0x00433ed0 — — Validate Vehicle Configuration File
   next_func: 0x00434000 — — File Load with Flag Preserve
   xrefs_into: none

GAP 330: 0x00438c9f — 0x00438cc0 (33 bytes)
   hex_head: 90568bf1e8885500008d8eac150000e85d4713008d8eec0100005ee931ccffff90
   prev_func: 0x00438c10 — — Dynamics Object Initialization
   next_func: 0x00438cc0 — — BrakeBiasSetup
   xrefs_into: none

GAP 331: 0x00448431 — 0x00448480 (79 bytes)
   hex_head: 8a0040a370ae8a00d849e9e1feffff8b4c24048b542408d94104d85a04dfe0f6c4417506b801000000c3d94104d85a04
   prev_func: 0x00448330 — — AudioDSPStateUpdate
   next_func: 0x00448480 — — Weighted Average Interpolation
   xrefs_into: none

GAP 332: 0x0044a121 — 0x0044a170 (79 bytes)
   hex_head: cfe825faffff5f5e5b8be55dc204008b4c24048b542408d9410cd85a0cdfe0f6c4417506b801000000c3d9410cd85a0c
   prev_func: 0x0044a070 — — QuadraticSurfaceCollisionTest
   next_func: 0x0044a170 — — Visibility/Frustum Test
   xrefs_into: none

GAP 333: 0x0044c5ea — 0x0044c620 (54 bytes)
   hex_head: 9090909090906800c64400e844b5130059c390909090b990a57c00e9966c0000909090909090e80b000000e936000000
   prev_func: 0x0044c5e0 — — Collision thunk
   next_func: 0x0044c620 — — Collision State Init (Slot 1)
   xrefs_into: none

GAP 334: 0x0044c6a9 — 0x0044c6c0 (23 bytes)
   hex_head: 9090909090909068c0c64400e884b4130059c390909090
   prev_func: 0x0044c680 — — Spatial Node Init (index 2, radius -1.0)
   next_func: 0x0044c6e0 — — Global State Initializer (Collision Material 1)
   xrefs_into: none

GAP 335: 0x0044c721 — 0x0044c740 (31 bytes)
   hex_head: c64400e884b4130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c710 — — RegisterInputDevice0
   next_func: 0x0044c740 — — CollisionGridInit4
   xrefs_into: none

GAP 336: 0x0044c7c9 — 0x0044c7e0 (23 bytes)
   hex_head: 9090909090909068e0c74400e864b3130059c390909090
   prev_func: 0x0044c7a0 — — CollisionStateInit_Alpha
   next_func: 0x0044c800 — — Collision Region Init 5 (Type 6, -1.0f)
   xrefs_into: none

GAP 337: 0x0044c850 — 0x0044c860 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044c830 — — ThunkCollisionInitA
   next_func: 0x0044c860 — — Collision Material Coefficients Set 5 (ID 7, 1.0f)
   xrefs_into: none

GAP 338: 0x0044c8e9 — 0x0044c900 (23 bytes)
   hex_head: 909090909090906800c94400e844b2130059c390909090
   prev_func: 0x0044c8c0 — — CollisionFrictionInit_8
   next_func: 0x0044c920 — — Collision global init (single group with 1.0)
   xrefs_into: none

GAP 339: 0x0044c961 — 0x0044c980 (31 bytes)
   hex_head: c94400e844b2130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c950 — — Collision Sound Unregister (Label)
   next_func: 0x0044c980 — — Collision Global Init (Set 10, -1.0f)
   xrefs_into: none

GAP 340: 0x0044ca09 — 0x0044ca20 (23 bytes)
   hex_head: 909090909090906820ca4400e824b1130059c390909090
   prev_func: 0x0044c9f4 — — SteeringSensitivityInit
   next_func: 0x0044ca40 — — CollisionStaticInit_12 (init 0x007cca7c)
   xrefs_into: none

GAP 341: 0x0044ca84 — 0x0044cab4 (48 bytes)
   hex_head: e824b1130059c390909090c3e80b000000e936000000909090909090c70548d17c0066000000c7054cd17c0000000000
   prev_func: 0x0044ca70 — — Atexit Handler Registration (collision A)
   next_func: 0x0044cab4 — — Render State Float Initialization
   xrefs_into: none

GAP 342: 0x0044cb29 — 0x0044cb40 (23 bytes)
   hex_head: 909090909090906840cb4400e804b0130059c390909090
   prev_func: 0x0044cb14 — — Global Initializer (-1.0, 0.0)
   next_func: 0x0044cb60 — — Initialize Collision Globals D
   xrefs_into: none

GAP 343: 0x0044cba2 — 0x0044cbd4 (50 bytes)
   hex_head: 4400e804b0130059c390909090c3e80b000000e936000000909090909090c70588d17c0069000000c7058cd17c000000
   prev_func: 0x0044cb90 — — CollisionModuleRegister_A
   next_func: 0x0044cbd4 — — GlobalStateInitNegOne
   xrefs_into: none

GAP 344: 0x0044cc49 — 0x0044cc60 (23 bytes)
   hex_head: 909090909090906860cc4400e8e4ae130059c390909090
   prev_func: 0x0044cc34 — — Camera/View Zoom Initializer
   next_func: 0x0044cc80 — — Collision State Init 4
   xrefs_into: none

GAP 345: 0x0044ccc1 — 0x0044ccf4 (51 bytes)
   hex_head: cc4400e8e4ae130059c390909090c3e80b000000e936000000909090909090c70558d17c0020000000c7055cd17c0000
   prev_func: 0x0044ccb0 — — CollisionCallbackRegister_ccc0
   next_func: 0x0044cd10 — — Collision constructor thunk
   xrefs_into: none

GAP 346: 0x0044cd69 — 0x0044cd80 (23 bytes)
   hex_head: 909090909090906880cd4400e8c4ad130059c390909090
   prev_func: 0x0044cd54 — — Initialize Physics Constants
   next_func: 0x0044cda0 — — Collision State Init (Slot 0x22, Scale 1.0)
   xrefs_into: none

GAP 347: 0x0044cde1 — 0x0044ce14 (51 bytes)
   hex_head: cd4400e8c4ad130059c390909090c3e80b000000e936000000909090909090c70538a47c0023000000c7053ca47c0000
   prev_func: 0x0044cdd0 — — Collision Init Registration (DAT_0044cde0)
   next_func: 0x0044ce14 — — Global State Initializer
   xrefs_into: none

GAP 348: 0x0044ce89 — 0x0044cea0 (23 bytes)
   hex_head: 9090909090909068a0ce4400e8a4ac130059c390909090
   prev_func: 0x0044ce74 — — InitFloatGlobals
   next_func: 0x0044cec0 — — CollisionGridInit37
   xrefs_into: none

GAP 349: 0x0044cf01 — 0x0044cf34 (51 bytes)
   hex_head: ce4400e8a4ac130059c390909090c3e80b000000e936000000909090909090c705a8a37c0026000000c705aca37c0000
   prev_func: 0x0044cef0 — — Collision Callback Registration (DAT_0044cf00)
   next_func: 0x0044cf34 — — Global State Initializer
   xrefs_into: none

GAP 350: 0x0044cfa9 — 0x0044cfc0 (23 bytes)
   hex_head: 9090909090909068c0cf4400e884ab130059c390909090
   prev_func: 0x0044cf94 — — Audio Mixer Gain Init
   next_func: 0x0044cfe0 — — Collision Material Coefficients Set 6 (ID 40, 1.0f)
   xrefs_into: none

GAP 351: 0x0044d021 — 0x0044d054 (51 bytes)
   hex_head: cf4400e884ab130059c390909090c3e80b000000e936000000909090909090c705d8a37c0029000000c705dca37c0000
   prev_func: 0x0044d010 — — Collision Init Wrapper (PTR_LAB_0044d020)
   next_func: 0x0044d054 — — InitFloatGlobals
   xrefs_into: none

GAP 352: 0x0044d0c9 — 0x0044d0e0 (23 bytes)
   hex_head: 9090909090909068e0d04400e864aa130059c390909090
   prev_func: 0x0044d0a0 — — Collision global init (single group with 1.0)
   next_func: 0x0044d100 — — Collision Global Init (Set 0x6b, -1.0f)
   xrefs_into: none

GAP 353: 0x0044d150 — 0x0044d160 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d130 — — Thunk
   next_func: 0x0044d160 — — Collision Global Struct Init (Block 0x6C, unit default)
   xrefs_into: none

GAP 354: 0x0044d1e9 — 0x0044d200 (23 bytes)
   hex_head: 909090909090906800d24400e844a9130059c390909090
   prev_func: 0x0044d1c0 — — CollisionStaticInit_6d (init 0x007ccfa0)
   next_func: 0x0044d220 — — InitMouseAbsAxisY
   xrefs_into: none

GAP 355: 0x0044d261 — 0x0044d280 (31 bytes)
   hex_head: d24400e844a9130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d250 — — Thunk
   next_func: 0x0044d280 — — Collision Subsystem Init (DAT_007ca57c)
   xrefs_into: none

GAP 356: 0x0044d309 — 0x0044d320 (23 bytes)
   hex_head: 909090909090906820d34400e824a8130059c390909090
   prev_func: 0x0044d2f4 — — InitRenderConstantsZeroOne
   next_func: 0x0044d340 — — CollisionGlobalInitG
   xrefs_into: none

GAP 357: 0x0044d390 — 0x0044d3a0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d370 — — Collision Data Registration Block 2
   next_func: 0x0044d3a0 — — Collision Broadphase Reset (Slot 0xD)
   xrefs_into: none

GAP 358: 0x0044d426 — 0x0044d440 (26 bytes)
   hex_head: 909090909090909090906840d44400e804a7130059c390909090
   prev_func: 0x0044d400 — — Spatial Node Init (index 14)
   next_func: 0x0044d460 — — Global State Initializer (Collision Set 1)
   xrefs_into: none

GAP 359: 0x0044d4b0 — 0x0044d4c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d490 — — CollisionCallbackRegister_d4a0
   next_func: 0x0044d4c0 — — CollisionGridInit16x16
   xrefs_into: none

GAP 360: 0x0044d546 — 0x0044d560 (26 bytes)
   hex_head: 909090909090909090906860d54400e8e4a5130059c390909090
   prev_func: 0x0044d520 — — CollisionStateInit_17
   next_func: 0x0044d580 — — Collision Region Init 1 (Type 18)
   xrefs_into: none

GAP 361: 0x0044d5c1 — 0x0044ee10 (6223 bytes)
   hex_head: d54400e8e4a5130059c390909090c3e80b000000e93600000090909090909033c0c70580cc7c0013000000a384cc7c00
   prev_func: 0x0044d5b0 — — Collision Init Registration (DAT_0044d5c0)
   next_func: 0x0044ee10 — — D3D Window/Surface Creation
   xrefs_into: none

GAP 362: 0x0044f7b6 — 0x0044f7d0 (26 bytes)
   hex_head: 8bff00f744000df744001af7440027f744009090909090909090
   prev_func: 0x0044f73c — — Cursor/Scroll Position Tracker
   next_func: 0x0044f7d0 — — ContactFlagReadClear
   xrefs_into: none

GAP 363: 0x00452666 — 0x004526c0 (90 bytes)
   hex_head: 8bff6719450067194500cf194500c9194500c919450077194500a919450089194500b919450099194500611a4500fd25
   prev_func: 0x00451720 — — Driver Input Controller
   next_func: 0x004526c0 — — Array Destructor via Virtual Dispatch
   xrefs_into: none

GAP 364: 0x004551f1 — 0x00455258 (103 bytes)
   hex_head: 4804b0015ec20c005f32e996fbffff8b4c240481f980000000b838a45e007c1981e98000000083f958731ec1e10481c1
   prev_func: 0x00454da0 — â€” Vehicle Input Smoothing (Throttle/Brake/Clutch/Steering)
   next_func: 0x00455260 — � Two-Way Dispatch by Index
   xrefs_into: none

GAP 365: 0x00456a32 — 0x00456f60 (1326 bytes)
   hex_head: 83c4205f5e33c05b8be969ffffff8b442408d9058cef590083f801568bf17508ddd8d90590ef59008a44240884c07506
   prev_func: 0x004569b0 — — Steering/input smoothing with saturation
   next_func: 0x00456f70 — — Collision Coefficient Application
   xrefs_into: none

GAP 366: 0x0045a833 — 0x0045a8e0 (173 bytes)
   hex_head: e8e4180f005f5e83e994f2ffff83ec0c568bf1dd86d80000006a00d95c24088d442408dd86e000000050d95c2410b9c0
   prev_func: 0x00459ae0 — — Vehicle Physics Velocity/Angular-Velocity Integrator
   next_func: 0x0045a8e0 — � Vehicle Body Position Update
   xrefs_into: none

GAP 367: 0x0045b99d — 0x0045b9c0 (35 bytes)
   hex_head: 9090905633f689b11c0300008da4240000000056e87afaffff4683fe087cf45ec39090
   prev_func: 0x0045b840 — — Collision Damage Decay Processor
   next_func: 0x0045b9c0 — General utility function. See decompiled code for exact beha
   xrefs_into: none

GAP 368: 0x0045be6e — 0x0045bea0 (50 bytes)
   hex_head: 90906880be4500e8c4bc120059c390909090b908d27c00e816000000a108d27c0085c0740750e836bd120059c34d5954
   prev_func: 0x0045be50 — — Global State Initializer (Collision System Reset)
   next_func: 0x0045bea0 — — AVI Stream Cleanup
   xrefs_into: none

GAP 369: 0x0045bfe9 — 0x0045c030 (71 bytes)
   hex_head: 909090909090906800c04500e844bb120059c390909090a06cd27c0084c0741aa164d27c0050ff15a8e1590085c0740a
   prev_func: 0x0045bf90 — — Collision Mutex Initialization
   next_func: 0x0045c030 — — Unknown (Struct Init with Float Defaults)
   xrefs_into: none

GAP 370: 0x0045cc23 — 0x0045cd50 (301 bytes)
   hex_head: ffff4683fe687cf25f5ec20400b918fe8a00e826d309008b4424088b4c2410dd18a0a4567c008b54240cc70101000000
   prev_func: 0x0045cbf0 — — Short Array Lookup and Zero Check
   next_func: 0x0045cd50 — — Struct Initializer (Flags + Fields)
   xrefs_into: none

GAP 371: 0x0045d50f — 0x0045d530 (33 bytes)
   hex_head: 90568bf1e828fdffff8b4e0c85c9740ce82c571000c7460c000000005ec3909090
   prev_func: 0x0045d500 — Call init function if global flag is zero.
   next_func: 0x0045d530 — — Audio Channel Init
   xrefs_into: none

GAP 372: 0x004618b2 — 0x004618d0 (30 bytes)
   hex_head: 8bff1f184600261846002d18460034184600909090909090909090909090
   prev_func: 0x00461610 — — SessionConfigBuilder
   next_func: 0x004618d0 — Extracts filename from a path by scanning backwards for last
   xrefs_into: none

GAP 373: 0x0046200e — 0x00462156 (328 bytes)
   hex_head: 90908b018b5424048b889cb701005657e85d1e10008bf085f60f840701000068f05b5c00bafc5b5c008bcee872241000
   prev_func: 0x00461ff0 — — Short Computation (Conditional Delegation)
   next_func: 0x00462160 — — Network Filter/Sort (numplayers/mapname/hostname)
   xrefs_into: none

GAP 374: 0x0046491f — 0x00464930 (17 bytes)
   hex_head: 90e80b000000e916000000909090909090
   prev_func: 0x004647d0 — — Linked List Merge Sort (Recursive)
   next_func: 0x00464930 — — Single Function Call Wrapper
   xrefs_into: none

GAP 375: 0x00464fd0 — 0x00465150 (384 bytes)
   hex_head: 5668d0e500008bf1e8262c120083c40485c0740d8bc8e825fcffff89068bc65ec333c089068bc65ec35d5be949ffffff
   prev_func: 0x00464f90 — — Threshold-to-Rank Classifier
   next_func: 0x00465150 — — Single Call Wrapper
   xrefs_into: none

GAP 376: 0x00465fe5 — 0x00466080 (155 bytes)
   hex_head: 90909090909090909090906800604600e8441b120059c390909090a160d47c0085c0740750e8c01b120059c3005f5d5e
   prev_func: 0x00465fd0 — — Collision Distance Reset
   next_func: 0x00466080 — Forward param_1 to FUN_00566650.
   xrefs_into: none

GAP 377: 0x00466250 — 0x004662e0 (144 bytes)
   hex_head: 568bf18b4e406a03e843260300c686f40000000133c05ec3a800000033c05ec3568bf18b4e406a03e823260300c686f5
   prev_func: 0x004661b0 — — Game Object Update Frame
   next_func: 0x004662e0 — — State Reset with Zero
   xrefs_into: none

GAP 378: 0x0046697c — 0x004669a0 (36 bytes)
   hex_head: 909090908b442408568bf18b4c240850518bcee80c6a0200c706c8f259008bc65ec20800
   prev_func: 0x00466910 — — Setup Value Display Formatter
   next_func: 0x004669a0 — — Setup Value Display Formatter (No Guard)
   xrefs_into: none

GAP 379: 0x00466d99 — 0x004670e0 (839 bytes)
   hex_head: 5e8ae9b4ffffff8b811c0300005333db3bc30f8498010000837c240801568b30750a8b912c03000003f2eb088b913003
   prev_func: 0x00466d60 — — Short Computation / Object Init + VTable
   next_func: 0x004670e0 — — Switch on Action ID → Virtual Call
   xrefs_into: none

GAP 380: 0x00467864 — 0x00467e40 (1500 bytes)
   hex_head: cfff502c5f5e33c05dc2040081ec380300005355568bf15733c033dbb9600000008dbc24c8010000f3ab8b4e40899c24
   prev_func: 0x004677e0 — — LinkedListNodeDestructor
   next_func: 0x00467e40 — — credits.txt Parser
   xrefs_into: none

GAP 381: 0x004685df — 0x00468610 (49 bytes)
   hex_head: 90c21000920e0033c05e81c400020000c3568bf1e818000000f644240801740956e8caf5110083c4048bc65ec2040090
   prev_func: 0x004685b0 — Forwards call to another function. No additional logic.
   next_func: 0x00468610 — Destructor sets vtable, frees child pointer at +0x174, calls
   xrefs_into: none

GAP 382: 0x00469187 — 0x004692a0 (281 bytes)
   hex_head: ff158ce15900e55dc3566a008bf1e846fdffff8b066a008bceff503c33c05ec3ff155ce05900c20400578bf9e8a84102
   prev_func: 0x00468ee0 — — Player Profile Scanner
   next_func: 0x004692a0 — — Short Computation
   xrefs_into: none

GAP 383: 0x00469dcd — 0x0046a220 (1107 bytes)
   hex_head: 909090568bf18b4e40e855e90200d88674010000d99674010000d81d00e85900dfe0f6c441752f8b867801000033c983
   prev_func: 0x00469d30 — — Player Stats Display Cleanup
   next_func: 0x0046a220 — — Object Constructor with VTable
   xrefs_into: none

GAP 384: 0x0046a86e — 0x0046a980 (274 bytes)
   hex_head: 9090e8ebfcffff33c0c3909090e955fcffff81ec000100005768000100008d4424088bf950b998e47c00e8836204008b
   prev_func: 0x0046a560 — — Standings Display
   next_func: 0x0046a980 — — ID Pair Match and Clear
   xrefs_into: none

GAP 385: 0x0046b317 — 0x0046b580 (617 bytes)
   hex_head: ff150ce35900fbffff81ec00010000568bf18b0dc0d87c008b01576a11ff501c8bf885ff740e8bcfe8dcc300008bcfe8
   prev_func: 0x0046b310 — � Offset Accessor (+0x174)
   next_func: 0x0046b580 — — Short Computation (UI Options Constructor)
   xrefs_into: none

GAP 386: 0x0046c6e6 — 0x0046c74c (102 bytes)
   hex_head: e830ad01005e33c05bc3568bf1e8c8cc01008a442408888674010000c70658fb59008bc65ec2040090908a9174010000
   prev_func: 0x0046c210 — � Championship Standings HTML Writer
   next_func: 0x0046c74c — — Key Binding Array Remove/Shift
   xrefs_into: none

GAP 387: 0x0046cceb — 0x0046cd20 (53 bytes)
   hex_head: 4d59544800518bd15783c9ff33c0bf18d87c00f2aef7d149c6442404005f7505c6442400018b4c24008b02518bcaff50
   prev_func: 0x0046cb50 — — Profile Already Exists Page Handler
   next_func: 0x0046cd20 — — CopyProfileIconBMP
   xrefs_into: none

GAP 388: 0x0046e229 — 0x0046e5c0 (919 bytes)
   hex_head: c8e910bb0100c351568bf18b4e408b016a1fc644240801ff501c85c0741a8b887801000085c97d108bc8e8c8b6010085
   prev_func: 0x0046e1b0 — — Deferred Texture/Object Loader
   next_func: 0x0046e5c0 — — Init with Stack Buffer
   xrefs_into: none

GAP 389: 0x0046ec78 — 0x0046fcf9 (4225 bytes)
   hex_head: e8bbfce9b8feffffa16c665c0081ec1002000055568bb4241c0200008be9538a108a1e8aca3ad3751e84c974168a5001
   prev_func: 0x0046ec10 — — Object Name Matching + Activation
   next_func: 0x0046fcf9 — — ObjectCreate_WithVtable
   xrefs_into: none

GAP 390: 0x004702fb — 0x00470400 (261 bytes)
   hex_head: 9090909090568bf18b86040300000551feffff83f8060f87c4000000ff2485e00347006a1a6818d87c008bcec60518d8
   prev_func: 0x004702f0 — — Short Computation (VTable Set)
   next_func: 0x00470400 — — Engine Temperature Debug Display
   xrefs_into: none

GAP 391: 0x00471484 — 0x00472cc0 (6204 bytes)
   hex_head: 008bcee8930000008bc65ec3566a018bf1e8c658ffff6aff680c675c008bcec706800d5a00c78634030000eb000000e8
   prev_func: 0x00471440 — — Mode-Specific Screen Setup
   next_func: 0x00472cc0 — — UI String Format + Display
   xrefs_into: none

GAP 392: 0x00473b6b — 0x00474510 (2469 bytes)
   hex_head: 4d59544800568bf18b86200300000fb608518bcee88c340100508bcee8847c010033c05ec3568bf18b0dc0d87c008b01
   prev_func: 0x00473b00 — — Constructor (VTable + Config Data)
   next_func: 0x00474510 — � SessionEnter_Alt
   xrefs_into: none

GAP 393: 0x00475529 — 0x00475c80 (1879 bytes)
   hex_head: 435a008bc65ec3568bf1c60550d87c0000e811fcffffa1740e7d0085c07524a0ac0f7d0084c0741b8a867c01000084c0
   prev_func: 0x00475140 — Forwards call to another function. No additional logic.
   next_func: 0x00475c80 — — Conditional Draw
   xrefs_into: none

GAP 394: 0x0047619a — 0x004761c0 (38 bytes)
   hex_head: 8be8b904f9ff8b44240485c0740c8944240483c150e99c040f00c20400ff1550e35900ffffff
   prev_func: 0x00476100 — — VTable Object Destructor (Multi-Stage Cleanup)
   next_func: 0x004761c0 — — UI Object Init
   xrefs_into: none

GAP 395: 0x004767cf — 0x00476ec0 (1777 bytes)
   hex_head: 9081ec540300005355568be957896c2410e8eb830100a038a45e008884242401000033c0b90f0000008dbc2425010000
   prev_func: 0x004767c0 — — Renderer State Reset
   next_func: 0x00476ec0 — — Season Scene Search by Name
   xrefs_into: none

GAP 396: 0x00477b67 — 0x00477ba0 (57 bytes)
   hex_head: ff1564e059000000c3e81b7a010085c074238b400485c07505b838a45e0050b968c38a00e820da04006a00b968c38a00
   prev_func: 0x00477aa0 — — Game Content Filter Check
   next_func: 0x00477ba0 — — Scene List Search by Path
   xrefs_into: none

GAP 397: 0x00478e8b — 0x00478ec9 (62 bytes)
   hex_head: 90909090908bd18b825c01000085c07505b838a45e00578bf883c9ff33c0f2aef7d1495f74118b823c01000085c07407
   prev_func: 0x00478e80 — Delegates to FUN_00499b80().
   next_func: 0x00478ed0 — � SessionExitOrChecks
   xrefs_into: none

GAP 398: 0x004795db — 0x00479600 (37 bytes)
   hex_head: 4d595448008b442408568bf18b4c240850518bcee8ac3d0100c706d84a5a008bc65ec20800
   prev_func: 0x004793ec — — File Path Resolver with Extension Append
   next_func: 0x00479600 — — Value Bar Display Formatter
   xrefs_into: none

GAP 399: 0x0047aa73 — 0x0047aab0 (61 bytes)
   hex_head: c65ec390909090b8e996feffff568bf1c706e0665a00e822b40000f644240801740956e834d1100083c4048bc65ec204
   prev_func: 0x0047aa60 — — Empty Stub
   next_func: 0x0047aab0 — — TextWidget_Init
   xrefs_into: none

GAP 400: 0x0047c054 — 0x0047c360 (780 bytes)
   hex_head: 01005e81c48000e9c6feffffdd0590fe8a00568bf1d8ae74010000d99674010000d81d40e45900dfe0f6c4417a0fe8a9
   prev_func: 0x0047beb0 — — File Extension Stripper
   next_func: 0x0047c6c0 — � Double Delegate Call
   xrefs_into: none

GAP 401: 0x0047c8fc — 0x0047daf0 (4596 bytes)
   hex_head: 90909090c705ccff7c000000000033c0c390909056680000803f6a008bf1e8810a0100c786fc00000000000000c70668
   prev_func: 0x0047c860 — — UILoadingPercentDisplay
   next_func: 0x0047dbe0 — — TelemetryDisplaySwitch
   xrefs_into: none

GAP 402: 0x0047e390 — 0x0047e3f4 (100 bytes)
   hex_head: 56e80afdffff8b0dc0d87c008b016a15ff501c85c0744a8bc8e8e211010085c0743f8b484885c97e078b403c85c07504
   prev_func: 0x0047e384 — — ByteAccumAdd
   next_func: 0x0047e3f4 — — Race Laps String Load on Trigger
   xrefs_into: none

GAP 403: 0x0047ee94 — 0x0047ef3c (168 bytes)
   hex_head: a134f17c0083f8050f8785000000ff2485d0ef470068e8745c008bcbe88bfaffff33c05f5e5b83c420c368586e5c008b
   prev_func: 0x0047ee5c — — InitFromDataBlock
   next_func: 0x0047ef3c — — Percentage Display Formatter
   xrefs_into: none

GAP 404: 0x0047f3c2 — 0x0047f3f0 (46 bytes)
   hex_head: 68c38a00e8916104005f5e5d5bc3568bf1e818000000f644240801740956e8ea87100083c4048bc65ec204009090
   prev_func: 0x0047f370 — — Screen Data Struct Init
   next_func: 0x0047f3f0 — — Destructor (3 sub-objects)
   xrefs_into: none

GAP 405: 0x00485864 — 0x004859d0 (364 bytes)
   hex_head: 24100083c4048bc65ec20400568bf18d8e30010000e8d24201008b862801000085c0740950e84123100083c4048b8620
   prev_func: 0x004857e0 — — Linked-List Buffer Destructor
   next_func: 0x004859d0 — — LinkedListDtor
   xrefs_into: none

GAP 406: 0x0048669b — 0x004866ad (18 bytes)
   hex_head: 4d59544800538b5c2408568bf13a5e657407
   prev_func: 0x00486660 — — State Change Notification
   next_func: 0x004866ad — — UI Widget Property Propagator
   xrefs_into: none

GAP 407: 0x0048730d — 0x00487330 (35 bytes)
   hex_head: 8d4900a672480076724800bc72480090724800d2724800909090909090909090909090
   prev_func: 0x00487260 — � State-Dependent vTable Dispatcher with bool Param
   next_func: 0x00487330 — — State-Dependent VTable Dispatch
   xrefs_into: none

GAP 408: 0x00487688 — 0x004876b0 (40 bytes)
   hex_head: a800000033c05ec3568bf1e818000000f644240801740956e82a05100083c4048bc65ec204009090
   prev_func: 0x00487660 — — UI Object Init with Byte Params
   next_func: 0x004876b0 — — Short Computation (Constructor)
   xrefs_into: none

GAP 409: 0x00487f02 — 0x00487f30 (46 bytes)
   hex_head: e8a6e7ffff33c05ec383c8ff5ec3568bf1e818000000f644240801740956e8aafc0f0083c4048bc65ec204009090
   prev_func: 0x00487ed0 — Initializes struct with vtable and two byte params.
   next_func: 0x00487f30 — — VTable Set + Cleanup
   xrefs_into: none

GAP 410: 0x00488301 — 0x004883a0 (159 bytes)
   hex_head: 040090909090906a00e879e2ffffc383ec34568bf18b0657ff90a80000008bf885ff743f538d9ee0000000538bcfe8bc
   prev_func: 0x004881f0 — � Surface Render Region Setup
   next_func: 0x004883a0 — — 5-Field Init
   xrefs_into: none

GAP 411: 0x00488f3a — 0x00488f90 (86 bytes)
   hex_head: ffe819d7f7ff568bf18b86c800000085c074158b404085c07505b838a45e008b4e4050e8fef500008b4424148b4c2410
   prev_func: 0x00488be0 — — UI Large Render Dispatcher
   next_func: 0x00488f90 — Calls FUN_00485e30, sets vtable, sets byte flag at +0xE4 to 
   xrefs_into: none

GAP 412: 0x0048a634 — 0x0048a650 (28 bytes)
   hex_head: 9da44800d7a448004aa5480067a54800909090909090909090909090
   prev_func: 0x0048a3c0 — — UI List Management Handler
   next_func: 0x0048a650 — — UI Scrollbar/Thumb Drag Handler
   xrefs_into: none

GAP 413: 0x0048b4d0 — 0x0048b4e0 (16 bytes)
   hex_head: 8b016a01ff90a800000033c0c3909090
   prev_func: 0x0048b420 — — Constructor with String Copy
   next_func: 0x0048b4e0 — Set vtable pointer, call FUN_00485eb0.
   xrefs_into: none

GAP 414: 0x0048b94c — 0x0048b9c0 (116 bytes)
   hex_head: 909090908a4424048bd15683c9ff84c057742d8b82f00200008982f4020000c600008db2e701000033c08bfef2aef7d1
   prev_func: 0x0048b91a — — UI Widget Visibility Toggle
   next_func: 0x0048b9c0 — — Text Input Render / Password Mask
   xrefs_into: none

GAP 415: 0x0048ca30 — 0x0048ca50 (32 bytes)
   hex_head: 568bf1e818000000f644240801740956e88ab10f0083c4048bc65ec204009090
   prev_func: 0x0048ca26 — — IntFieldSetter
   next_func: 0x0048ca50 — — Linked List Destructor (Cleanup + Free)
   xrefs_into: none

GAP 416: 0x0048d67f — 0x0048d6a0 (33 bytes)
   hex_head: 90568bf1e818000000f644240801740956e83aa50f0083c4048bc65ec204009090
   prev_func: 0x0048d660 — — Constructor Dual Sub-Init
   next_func: 0x0048d6a0 — — Short Computation / VTable Init + Call
   xrefs_into: none

GAP 417: 0x0048d9b5 — 0x0048d9d0 (27 bytes)
   hex_head: 8d4900ead8480087d848004cd94800000202010202000001019090
   prev_func: 0x0048d850 — — UI Scroll Area/Auto-Scroll Manager
   next_func: 0x0048d9d0 — — Media Buffer Playback Manager
   xrefs_into: none

GAP 418: 0x0048e0a5 — 0x0048e0d0 (43 bytes)
   hex_head: ff50405f33c05e83c408c3568bf1e818000000f644240801740956e80a9b0f0083c4048bc65ec204009090
   prev_func: 0x0048e070 — — Constructor (Zero Init + Defaults)
   next_func: 0x0048e0d0 — � UI Destructor with Conditional Release
   xrefs_into: none

GAP 419: 0x0048e643 — 0x0048e670 (45 bytes)
   hex_head: 302300008bc8e8d93200005ec3568bf1e818000000f644240801740956e86a950f0083c4048bc65ec204009090
   prev_func: 0x0048e600 — — UI Struct Init (Type 0)
   next_func: 0x0048e670 — — Destructor
   xrefs_into: none

GAP 420: 0x0048eda1 — 0x0048f590 (2031 bytes)
   hex_head: 000a000000888e7c0100008bc65ec383ec08538b5c241055568bf18b460c8b4c242089018b56108b44242489108b4e04
   prev_func: 0x0048ebd0 — — UI Dimension Capture
   next_func: 0x0048f590 — — Linked List Indexed Accessor
   xrefs_into: none

GAP 421: 0x0048fe86 — 0x0048feb0 (42 bytes)
   hex_head: 016a01ff502c5ec20800568bf1e818000000f644240801740956e82a7d0f0083c4048bc65ec204009090
   prev_func: 0x0048fe60 — — UI Component Init 5
   next_func: 0x0048feb0 — — VTable + Sub-Init
   xrefs_into: none

GAP 422: 0x00490282 — 0x004902c0 (62 bytes)
   hex_head: 909090909090909090909090909033c0c2100000020000005fe9a3ffffff568bf1e818000000f644240801740956e81a
   prev_func: 0x00490250 — — Object Init with Field Zeroing
   next_func: 0x004902c0 — Free linked list nodes with vtable+0(1) notification on each
   xrefs_into: none

GAP 423: 0x00490635 — 0x00490660 (43 bytes)
   hex_head: 909090909090e955fcffff568bf18b066a00ff50408bce5ee90e0000009090909090909090909090909090
   prev_func: 0x00490550 — — PanelMouseInteractionHandler
   next_func: 0x00490660 — Iterates linked list, calling vtable method on each node bas
   xrefs_into: none

GAP 424: 0x00494437 — 0x004944a0 (105 bytes)
   hex_head: ff150ce35900fbffff568bf1c706d8c85a00e8022efffff644240801740956e874370f0083c4048bc65ec20400009090
   prev_func: 0x00493e20 — — Resource Path Builder
   next_func: 0x00494600 — — Collision Global Zeroing
   xrefs_into: none

GAP 425: 0x00495156 — 0x00495190 (58 bytes)
   hex_head: 90909090a1e9b6ffffffe90b0000009090909090909090909090d9053ce45900d83590c95a00d91d30de7c00c3909090
   prev_func: 0x00495150 — — Global Accessor
   next_func: 0x00495190 — — Large Struct Zero-Init (Renderer Context)
   xrefs_into: none

GAP 426: 0x00496dd5 — 0x00496e20 (75 bytes)
   hex_head: 8d4900926949009c6949000000010001000101008d4900bd6a4900bd6a4900a66b49004d6c49007f6c49007b6a490002
   prev_func: 0x00496930 — — UI Large Render (Type-based)
   next_func: 0x00496e20 — � Float Threshold Comparison
   xrefs_into: none

GAP 427: 0x00498cf6 — 0x00498d20 (42 bytes)
   hex_head: 651000005fe9d1fcffff8b442404568bf1508d4e3ce840d90c008b4c240c894e445ec208004d59544800
   prev_func: 0x00498950 — — Sprite/Texture Enumeration
   next_func: 0x00498d20 — Calls init, sets vtable, calls post-init, stores param.
   xrefs_into: none

GAP 428: 0x00499082 — 0x00499140 (190 bytes)
   hex_head: 8b066a008bceff502c5f33c05ec38b5424043b510c567c4b3b51107f468b74240c3b71047c3d3b71087f388b415085c0
   prev_func: 0x00499050 — — Guarded Sub-Rectangle Render Dispatch
   next_func: 0x00499140 — Call FUN_00498d20, set vtable.
   xrefs_into: none

GAP 429: 0x00499222 — 0x00499280 (94 bytes)
   hex_head: 8bb68c00000085f675ec33c05ec38a44240484c074188b41108b510c508b4108528b51048b49505052e800feffffc204
   prev_func: 0x004991e0 — Forwards call to another function. No additional logic.
   next_func: 0x00499280 — Destructor walks linked list calling destructors, frees fiel
   xrefs_into: none

GAP 430: 0x0049966a — 0x00499680 (22 bytes)
   hex_head: 9090909090906880964900e8c4e40e0059c390909090
   prev_func: 0x00499660 — — Short Computation / Single Call Wrapper
   next_func: 0x00499680 — — NullsubWrapper
   xrefs_into: none

GAP 431: 0x0049a110 — 0x0049a180 (112 bytes)
   hex_head: 8b5424048b490833c085d27e0f8d490085c9740f8b4924403bc27cf485c974038b492833c085c9740f8da42400000000
   prev_func: 0x0049a102 — — Vtable Field Getter
   next_func: 0x0049a180 — — Zero-Init Int
   xrefs_into: none

GAP 432: 0x0049ac34 — 0x0049acc0 (140 bytes)
   hex_head: 41100354240889e949feffff8b511483c8ff3bd0750f394118750a39411c750539412074058b410c03c2c3908b511483
   prev_func: 0x0049ac20 — — Texture/Surface Dimension Validity Check
   next_func: 0x0049acc0 — Update four scroll/offset fields with signed addition and di
   xrefs_into: none

GAP 433: 0x0049afaa — 0x0049afc0 (22 bytes)
   hex_head: 90909090909068c0af4900e884cb0e0059c390909090
   prev_func: 0x0049afa0 — — Wrapper
   next_func: 0x0049afc0 — — CleanupCallbackRegister
   xrefs_into: none

GAP 434: 0x0049b03a — 0x0049b050 (22 bytes)
   hex_head: 909090909090e80b000000e916000000909090909090
   prev_func: 0x0049b030 — — UI Delegate Wrapper
   next_func: 0x0049b050 — — Empty Stub
   xrefs_into: none

GAP 435: 0x0049b1ab — 0x0049b1c0 (21 bytes)
   hex_head: 900eb1490015b149001cb1490023b1490090909090
   prev_func: 0x0049b060 — — Free Callback Registration (atexit-like)
   next_func: 0x0049b1c0 — — Static Array Cleanup
   xrefs_into: none

GAP 436: 0x0049cfbd — 0x0049d070 (179 bytes)
   hex_head: 909090568bf18b464c85c074188b405485c07411508d4660506a00b948e07c00e84e2500008b465085c0741b8b405485
   prev_func: 0x0049ca00 — — Cockpit Dashboard LED/Gauge Setup
   next_func: 0x0049d070 — — Steering Wheel Animation
   xrefs_into: none

GAP 437: 0x0049e670 — 0x0049e7b0 (320 bytes)
   hex_head: 51a1e4547c008b15dc547c00558be98b0c85f0547c008b0495f0547c008b90944800003b91944800000f8590000000b8
   prev_func: 0x0049e663 — — SetFourDwords
   next_func: 0x0049e7b0 — � HUD_TachoTick
   xrefs_into: none

GAP 438: 0x0049ffa1 — 0x004a0030 (143 bytes)
   hex_head: 6a008bcfe8bbce03005e5d5b5f59c3e80b000000e916000000909090909090b94de27c00e9e63d010090909090909068
   prev_func: 0x0049feb0 — — Merge Sort (Linked List)
   next_func: 0x004a0030 — � Monitor Page Display
   xrefs_into: none

GAP 439: 0x004a0615 — 0x004a0630 (27 bytes)
   hex_head: 8d4900ae054a00b5054a00bc054a00c3054a00ca054a00d1054a00
   prev_func: 0x004a0590 — � Session Type Dispatch
   next_func: 0x004a0630 — — Session/Scene Init Chain
   xrefs_into: none

GAP 440: 0x004a1553 — 0x004a1830 (733 bytes)
   hex_head: 9090c70550e27c00e95bfcffff8b4424085633f63d000200000f87dd0100000f84b30100008d48fe83f91e0f87330200
   prev_func: 0x004a1367 — — Window Rect Adjustment
   next_func: 0x004a1830 — � Windows Message Pump with Sleep
   xrefs_into: none

GAP 441: 0x004a19ab — 0x004a19d0 (37 bytes)
   hex_head: 90909090908b44240450e814650e008b4c240c66890183c404b802000000c2080090909090
   prev_func: 0x004a1990 — — ObjectHandleReader
   next_func: 0x004a19d0 — — StringCompareWithDefault
   xrefs_into: none

GAP 442: 0x004a4097 — 0x004a40e0 (73 bytes)
   hex_head: ff1590e35900ffffffe80b000000e916000000909090909090c390909090909090909090909090909068d0404a00e874
   prev_func: 0x004a4050 — Updates accumulator based on state at +0x78.
   next_func: 0x004a40e0 — — Large Buffer Zero-Init (0x68 ints)
   xrefs_into: none

GAP 443: 0x004a5311 — 0x004a5330 (31 bytes)
   hex_head: 8d49003b524a0031524a0027524a001d524a00909090909090909090909090
   prev_func: 0x004a4ed0 — Also handles: SHADOWOBJECT, LODOUT, LODIN, MESHFILE (level-o
   next_func: 0x004a5330 — — Pit Part State Copy
   xrefs_into: none

GAP 444: 0x004a7079 — 0x004a70e0 (103 bytes)
   hex_head: 64f6e944ffffff83ec088b54240c33c05689442404894424088d442408508bf18d4c24085168c0d65c0052e844170e00
   prev_func: 0x004a7040 — — DebugCoordinateFormat
   next_func: 0x004a70e0 — — UI Control Window Initialization
   xrefs_into: none

GAP 445: 0x004add23 — 0x004add50 (45 bytes)
   hex_head: 9054d24a0074d24a0094d24a00b1d24a00cbd24a00e5d24a00ffd24a0019d34a00909090909090909090909090
   prev_func: 0x004accfa — — Force Feedback Config Initializer
   next_func: 0x004ade20 — — TrackEnvironmentSelect (track env/weather handler)
   xrefs_into: none

GAP 446: 0x004af382 — 0x004af3a0 (30 bytes)
   hex_head: 8bff38f24a0086f24a00d4f24a001cf34a00909090909090909090909090
   prev_func: 0x004af220 — — TireCompoundClamp
   next_func: 0x004af3a0 — — Physics Parameter Initialization
   xrefs_into: none

GAP 447: 0x004b1eb5 — 0x004b1f50 (155 bytes)
   hex_head: 078b44240489e95bffffff518b5424085332db85d2568bf174645783c9ff33c08bfaf2aef7d1495f74548d4424105052
   prev_func: 0x004b1e20 — — ConfigKeyValueWrite
   next_func: 0x004b1f50 — — Short Field Setter
   xrefs_into: none

GAP 448: 0x004b218a — 0x004b21a0 (22 bytes)
   hex_head: 90909090909068a0214b00e8a4590d0059c390909090
   prev_func: 0x004b2180 — — Thunk to FUN_004b3ad0
   next_func: 0x004b21a0 — — SeasonScoringDBCallback
   xrefs_into: none

GAP 449: 0x004b39e8 — 0x004b3a90 (168 bytes)
   hex_head: 21344b00be344b00d3364b0049374b00e1394b0071394b0040344b0093344b000001010101010100d6344b00e1394b00
   prev_func: 0x004b3400 — ? Central Message/Event Dispatcher
   next_func: 0x004b3a90 — — Arithmetic/Comparison (Struct Copy with Header Size)
   xrefs_into: none

GAP 450: 0x004b3d4a — 0x004b3d60 (22 bytes)
   hex_head: 90909090909068603d4b00e8e43d0d0059c390909090
   prev_func: 0x004b3d40 — — Single Function Call Wrapper
   next_func: 0x004b3d60 — — Nullsub Wrapper (UI Singleton)
   xrefs_into: none

GAP 451: 0x004b44d0 — 0x004b44e0 (16 bytes)
   hex_head: e80b000000e906010000909090909090
   prev_func: 0x004b44a0 — � File Operation Open + Write
   next_func: 0x004b44e0 — â€” Fixed-Block Memory Pool Init
   xrefs_into: none

GAP 452: 0x004b4b33 — 0x004b4b50 (29 bytes)
   hex_head: 904f4a4b00534a4b00534a4b005a4a4b00684a4b00614a4b0090909090
   prev_func: 0x004b4a30 — � Network Packet Router & Queue Manager
   next_func: 0x004b4b50 — — Collision Object List Management
   xrefs_into: none

GAP 453: 0x004b66bd — 0x004b66e0 (35 bytes)
   hex_head: 8d490096634b0087634b0087634b0087634b0087634b0087634b009090909090909090
   prev_func: 0x004b6360 — � Game Command Data Validator
   next_func: 0x004b66e0 — — Lap/Speed Comparison with Switch-Selectable Thresholds
   xrefs_into: none

GAP 454: 0x004b784d — 0x004b7860 (19 bytes)
   hex_head: 8d4900fa754b00fe754b0005764b000c764b00
   prev_func: 0x004b7500 — � Replay Save State Machine (Saving Replay)
   next_func: 0x004b7860 — ? Render Batch Node Allocator
   xrefs_into: none

GAP 455: 0x004b8d8b — 0x004b8da0 (21 bytes)
   hex_head: 905d8c4b00c08c4b00e68c4b00068d4b003d8d4b00
   prev_func: 0x004b8c40 — — Unidentified Logic (Float Switch with AI/Game Mode Dispatc
   next_func: 0x004b8da0 — — ProcessDriverEntries
   xrefs_into: none

GAP 456: 0x004b9d1b — 0x004b9d80 (101 bytes)
   hex_head: e839c9f4ff568bf18b0e32d2e864eaffffd9813c0f0000ded9dfe0f6c4447a0a8a81800f000084c07436e856f0ffff8b
   prev_func: 0x004b9d00 — — Float Accumulator
   next_func: 0x004b9d80 — � Single Delegate (thunk to FUN_004b8140)
   xrefs_into: none

GAP 457: 0x004b9f47 — 0x004b9f89 (66 bytes)
   hex_head: 905f9e4b007c9e4b00b49e4b00be9e4b00dd9e4b00419f4b00f69e4b000d9f4b002a9f4b0090909090568bf18d4e08e8
   prev_func: 0x004b9e40 — — Pit Service Steering Animation Step
   next_func: 0x004b9fa0 — — Single Call Wrapper
   xrefs_into: none

GAP 458: 0x004bc984 — 0x004bc9b0 (44 bytes)
   hex_head: 4ac84b002ec74b002ec74b002ec74b002ec74b002ec74b002ec74b0023c64b00909090909090909090909090
   prev_func: 0x004bc4e0 — — Lap Completion / Penalty Processing
   next_func: 0x004bc9b0 — � Jumped Start / Grid Penalty Detection
   xrefs_into: none

GAP 459: 0x004be67c — 0x004be6f0 (116 bytes)
   hex_head: 90909090e90b000000909090909090909090909033c057b960000000bfe8c18a00f3aba3d0c18a00a3e4c18a00a3dcc1
   prev_func: 0x004be4e0 — — Sprite Grid Render
   next_func: 0x004be6f0 — — Delegation
   xrefs_into: none

GAP 460: 0x004c1643 — 0x004c1660 (29 bytes)
   hex_head: 90ba154c00cd154c00e0154c00f3154c0006164c0019164c002c164c00
   prev_func: 0x004c15a0 — — PitStop Phase Advance
   next_func: 0x004c1660 — @ 0x004c1660 — NOT FOUND
   xrefs_into: none

GAP 461: 0x004c2faa — 0x004c2fe0 (54 bytes)
   hex_head: 90909090909068c02f4c00e8844b0c0059c390909090b988c38a00e9760d0000909090909090e80b000000e916000000
   prev_func: 0x004c2fa0 — — Delegation Wrapper
   next_func: 0x004c2fe0 — — Delegation
   xrefs_into: none

GAP 462: 0x004c3d38 — 0x004c3d80 (72 bytes)
   hex_head: 5b81c4e9b5fcffff8b0d94c38a0085c974358b41fc538d59fc568bf069f62404000003f1487815578d780181ee240400
   prev_func: 0x004c3a00 — — TGA Texture File Scanner
   next_func: 0x004c3f80 — — Vehicle Lookup by Name
   xrefs_into: none

GAP 463: 0x004c6917 — 0x004c6960 (73 bytes)
   hex_head: d85f5e8be9e9feffff568bf1e858d5f5ff8bcec78694480000ffffffffe8a7100000568bcee8ffd6f5ff8bc65ec38974
   prev_func: 0x004c6810 — — MergeSortLinkedList
   next_func: 0x004c6960 — — TeamIDSetter
   xrefs_into: none

GAP 464: 0x004c7c3a — 0x004c7c50 (22 bytes)
   hex_head: 90909090909068507c4c00e8f4fe0b0059c390909090
   prev_func: 0x004c7c30 — — Single Function Call Wrapper
   next_func: 0x004c7c50 — — PhysicsVectorGetter
   xrefs_into: none

GAP 465: 0x004c8143 — 0x004c8180 (61 bytes)
   hex_head: 90527f4c005f7f4c006c7f4c00ea7f4c00f77f4c0018804c0018804c00dd7f4c0025804c0047804c00e3804c00e3804c
   prev_func: 0x004c7f30 — — UpdateCameraFOV
   next_func: 0x004c8180 — — Virtual Call on DAT_008ac4c4
   xrefs_into: none

GAP 466: 0x004c9211 — 0x004c9260 (79 bytes)
   hex_head: 56e84eeb0b0083c4048be96afeffff566a008bf1e85600000084c075078bcee8db000000a1a4567c0085c07419d905b8
   prev_func: 0x004c91d0 — — Triple VTable Destructor Release
   next_func: 0x004c9260 — Returns field at +0x20/+0x24/+0x28 based on state at +0x1c.
   xrefs_into: none

GAP 467: 0x004c9af3 — 0x004c9b70 (125 bytes)
   hex_head: 90639a4c00789a4c00f09a4c00f09a4c008d9a4c00b19a4c00c69a4c00568bf1c7066cce5a00e842fefffff644240801
   prev_func: 0x004c9a50 — — Memory Allocation / Particle Emitter Factory
   next_func: 0x004c9b70 — — Thunk to FUN_004ce820
   xrefs_into: none

GAP 468: 0x004ce813 — 0x004ce860 (77 bytes)
   hex_head: 32c05ec204005fb0e9b4fbffff8bc133c9890889480489480889480c89481089481489481889481c8948208948248948
   prev_func: 0x004ce3e0 — — CollisionEffectDispatch
   next_func: 0x004ce860 — — String List Lookup
   xrefs_into: none

GAP 469: 0x004d003a — 0x004d0060 (38 bytes)
   hex_head: 9090909090906850004d00e8f47a0b0059c390909090b9e0ce8a00e9a6d9f3ff909090909090
   prev_func: 0x004d0030 — — Wrapper
   next_func: 0x004d0060 — — Zero-Init + Sub-Call
   xrefs_into: none

GAP 470: 0x004d22f1 — 0x004d23d0 (223 bytes)
   hex_head: 90909090909090909090909090909051b95cd27c00e8a5faf8ff84c07421dd05a0fe8a00dc1df0ce5a00dfe0f6c4050f
   prev_func: 0x004d22c0 — Set flag, float from global, copy field, call FUN_0042d140.
   next_func: 0x004d23d0 — — Pit Timer State Init
   xrefs_into: none

GAP 471: 0x004d348d — 0x004d36d0 (579 bytes)
   hex_head: 8d4900922e4d00c52e4d0057304d00e4304d0010314d0086324d009090909090909090a1a4567c0085c0568bf10f8c8d
   prev_func: 0x004d2e50 — — Pit Timer / Race Phase State Machine
   next_func: 0x004d3740 — — Timer/Frame Rate Throttle
   xrefs_into: none

GAP 472: 0x004d4798 — 0x004d4840 (168 bytes)
   hex_head: 5f33c0e94af1ffff8b44240451506a0152e891380b0083c410c20800c408c39051e86ce9d8ffffff8b442404505251e8
   prev_func: 0x004d4790 — — Delegation Wrapper
   next_func: 0x004d4840 — — Object Init (Zero Fields + VTable)
   xrefs_into: none

GAP 473: 0x004d5c4d — 0x004d5c60 (19 bytes)
   hex_head: 90909068605c4d00e8e41e0b0059c390909090
   prev_func: 0x004d5c40 — — Short Computation (Global Zero Pair)
   next_func: 0x004d5c60 — — Wrapper: sub_4D7800
   xrefs_into: none

GAP 474: 0x004d7ac6 — 0x004d7b00 (58 bytes)
   hex_head: 5fc20c0032c05fc20c00568bc1578d5018be0300000083cfff90c7420c00000000c70200000000897ae8897af483c204
   prev_func: 0x004d7aa0 — — Debug Log Write
   next_func: 0x004d7b00 — — Unidentified Logic (3-Way Range Check with Track Data)
   xrefs_into: none

GAP 475: 0x004d8294 — 0x004d82c4 (48 bytes)
   hex_head: 20e830fcffff83e976ffffff56578d7110bf190000008d9b000000008b0e85c97405e875fbffff83c6044f75ef5f5ec3
   prev_func: 0x004d8220 — — Race Init with Constants
   next_func: 0x004d82c4 — — Thunk with Byte Increment + Jump
   xrefs_into: none

GAP 476: 0x004d8f91 — 0x004d8fb0 (31 bytes)
   hex_head: 8d4900268d4d00408d4d005a8d4d00308e4d00578e4d009090909090909090
   prev_func: 0x004d8a30 — — Unidentified Logic (Audio/State Dispatch by Index)
   next_func: 0x004d8fb0 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 477: 0x004d92e2 — 0x004d93e0 (254 bytes)
   hex_head: 8bffa3924d00bd924d00cd924d00cd924d00cd924d00dd924d00df924d00000100010100000100000000010101010101
   prev_func: 0x004d9290 — — ID/Type Permission Matrix
   next_func: 0x004d93e0 — — Range Check (1-5)
   xrefs_into: none

GAP 478: 0x004d9ed1 — 0x004da820 (2383 bytes)
   hex_head: 85e0ffff8bc75f5e81c4e9e6feffff81ec8000000056578bf9e8e1feffff8bf085f6757168ccc45e00682c4b5d00b9c0
   prev_func: 0x004d9dd0 — — Timer Display Render
   next_func: 0x004da820 — — State Block Initializer (7 fields)
   xrefs_into: none

GAP 479: 0x004db02c — 0x004db070 (68 bytes)
   hex_head: bdae4d00e6ae4d000faf4d0038af4d0061af4d008eaf4d00b4af4d00d9af4d0002b04d0029b04d000001020909090304
   prev_func: 0x004daea0 — — Direct3D Object Factory
   next_func: 0x004db070 — — Constructor: VTable + 3 Fields
   xrefs_into: none

GAP 480: 0x004db4d6 — 0x004db546 (112 bytes)
   hex_head: b801000000e93bffffff568bf1c706dcd05a008b461085c0740950e8d9c60a0083c404f644240801c7066cd05a007409
   prev_func: 0x004db170 — — Steering/Ackermann Computation
   next_func: 0x004db546 — — Byte Increment on Struct [PARTIAL]
   xrefs_into: none

GAP 481: 0x004dc0ab — 0x004dc1a0 (245 bytes)
   hex_head: e8a9a5f2ff83ec4056576a408d44240c8bf150b934e27c00e83805fcff8b7c244c680000803f680000803f6a026a0168
   prev_func: 0x004dbf90 — — Multi-Color Text Render
   next_func: 0x004dc1a0 — — Double Render Pass
   xrefs_into: none

GAP 482: 0x004dceb9 — 0x004dcee0 (39 bytes)
   hex_head: 8d4900ebcd4d0001ce4d001cce4d003cce4d0055ce4d005ace4d007dce4d0083ce4d008fce4d00
   prev_func: 0x004dcdd0 — — Position Computation with Alignment (9 cases)
   next_func: 0x004dcee0 — � Float-to-Int Chain Delegate
   xrefs_into: none

GAP 483: 0x004dfbaa — 0x004dfca0 (246 bytes)
   hex_head: 41e8a96af2ff53568bf1578d4e04e893feffffc7869000000000000000c78694000000ffffffff8dbed4000000bb0400
   prev_func: 0x004dfb90 — � 26-Byte Zero-Init
   next_func: 0x004dfca0 — — Dual Array Destructor Loop + Free
   xrefs_into: none

GAP 484: 0x004e1946 — 0x004e1970 (42 bytes)
   hex_head: 8bffd7184e00eb184e0007194e0023194e00000000000102030303030303030390909090909090909090
   prev_func: 0x004e18c0 — — Subsystem ready query
   next_func: 0x004e1970 — — Effect Data Table Initialization
   xrefs_into: none

GAP 485: 0x004ebc1d — 0x004ebc60 (67 bytes)
   hex_head: 8d490074b94e00b8b64e00a2b94e0025b94e00000000000000010303028bff6aba4e0078ba4e0086ba4e006aba4e0078
   prev_func: 0x004eb430 — — ParticleEffectUpdateDispatch
   next_func: 0x004ebc60 — — Vehicle Contact Force Accumulation
   xrefs_into: none

GAP 486: 0x004ef167 — 0x004ef180 (25 bytes)
   hex_head: 90afe34e00bae44e0004e94e0004e94e009090909090909090
   prev_func: 0x004ee2d0 — � Vehicle Dynamics Update (Brake/Tire/Suspension)
   next_func: 0x004ef180 — — WheelContactTransform
   xrefs_into: none

GAP 487: 0x004f23aa — 0x004f2430 (134 bytes)
   hex_head: 90909090909068c0234f00e88457090059c390909090a12cdb8a0085c0740950e80058090083c404a124db8a0085c074
   prev_func: 0x004f23a0 — — Short Computation (Delegation)
   next_func: 0x004f2430 — — Constructor: Zero-Init + Sub-Calls
   xrefs_into: none

GAP 488: 0x004f6ae9 — 0x004f6b40 (87 bytes)
   hex_head: 9090909090909068006b4f00e84410090059c3909090905657be74fc8a00bf2d0000008d6424008b46ec83ee1485c074
   prev_func: 0x004f6ab0 — — Global Table Initialization
   next_func: 0x004f6b40 — — Tire/Grip Data Array Init (Rear)
   xrefs_into: none

GAP 489: 0x004f8113 — 0x004f81d0 (189 bytes)
   hex_head: 90fc804f00ce804f00e5804f00fc804f00ce804f00e5804f00fc804f00ce804f00e5804f00fc804f0044804f005b804f
   prev_func: 0x004f8030 — — Switch-Based Param Setting
   next_func: 0x004f81d0 — — String Match with Wildcard
   xrefs_into: none

GAP 490: 0x004f9121 — 0x004f9150 (47 bytes)
   hex_head: 8d49007a8f4f00da8f4f0020904f00a1904f00909090909090909090909090568bf1e858fa06008bc65ec390909090
   prev_func: 0x004f8f10 — — Conditional Init Branch
   next_func: 0x004f9150 — — Short Computation (Delegation)
   xrefs_into: none

GAP 491: 0x004fb8ea — 0x004fb910 (38 bytes)
   hex_head: 9090909090906800b94f00e844c2080059c390909090b9c0fe8a00e946110000909090909090
   prev_func: 0x004fb8e0 — — Thunk to FUN_004fc9c0
   next_func: 0x004fbd70 — — Camera/Viewport Render Setup
   xrefs_into: none

GAP 492: 0x004fe79f — 0x004fe7c0 (33 bytes)
   hex_head: 90f0e34f009ee34f00a5e34f00a5e34f00c7e34f00cee34f00f0e34f0090909090
   prev_func: 0x004fe1e0 — — Weather Severity → Grip Multiplier
   next_func: 0x004feaa0 — — Threshold-Based Return
   xrefs_into: none

GAP 493: 0x0050bfc9 — 0x0050c021 (88 bytes)
   hex_head: f2b8500019b9500043b950006db9500097b95000c1b95000ebb9500015ba50003fba500069ba500093ba5000bdba5000
   prev_func: 0x0050b8a9 — — DirectX Texture/Surface Factory Dispatching FourCC Codes
   next_func: 0x0050c021 — — Render Object Destructor (thunk_FUN_0050b830)
   xrefs_into: none

GAP 494: 0x0050eb53 — 0x0050eb73 (32 bytes)
   hex_head: 2cea50008eea500092ea500096ea50009aea50009eea5000a1ea5000a5ea5000
   prev_func: 0x0050e9e6 — — Color Matrix Transform with Blend
   next_func: 0x0050eb73 — � Skeleton Animation Blending
   xrefs_into: none

GAP 495: 0x0051588c — 0x005158af (35 bytes)
   hex_head: ff742408ff742408e816f9ffff85c059597c0f8b4c2404e807e5ffff85c07c0233c0c3
   prev_func: 0x00515869 — — File Open and Validate
   next_func: 0x005158af — Calls FUN_00513e2d() and FUN_00515303() with error propagati
   xrefs_into: none

GAP 496: 0x0051ecd9 — 0x0051ecee (21 bytes)
   hex_head: 8db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051eca0 — — SSE Weighted Vector Sum
   next_func: 0x0051ecee — — 4x4 matrix × 4-vector transform
   xrefs_into: none

GAP 497: 0x0051ef48 — 0x0051ef5e (22 bytes)
   hex_head: 908db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ee7e — — Vector Normalize with Threshold
   next_func: 0x0051ef5e — — SSE 4x4 Matrix Multiply
   xrefs_into: none

GAP 498: 0x0051f88b — 0x0051f89e (19 bytes)
   hex_head: 908d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051f7ce — — Det3x3From4x4
   next_func: 0x0051f89e — — PlaneFromThreePoints
   xrefs_into: none

GAP 499: 0x0051fd1c — 0x0051fd2e (18 bytes)
   hex_head: 8d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051fc80 — — Vector Normalize with Newton-Raphson Refinement
   next_func: 0x0051fd2e — — Vec3NormalizeNewtonRaphson
   xrefs_into: none

GAP 500: 0x00520032 — 0x0052004e (28 bytes)
   hex_head: 8db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051ff8e — — SSE 3x4 Matrix-Vector Transform
   next_func: 0x0052004e — — 3×4 Matrix Transform with SSE
   xrefs_into: none

GAP 501: 0x00520346 — 0x0052035e (24 bytes)
   hex_head: 8d76008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052020e — — 4x4 Matrix Multiply (SSE)
   next_func: 0x0052035e — — VectorNormalizeThreshold
   xrefs_into: none

GAP 502: 0x005207b9 — 0x005207ce (21 bytes)
   hex_head: 8db42600000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x0052050e — — SSEMatrix4x4Multiply
   next_func: 0x005207ce — — SSEVectorCross
   xrefs_into: none

GAP 503: 0x00520972 — 0x0052098e (28 bytes)
   hex_head: 8db426000000008dbc2700000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x005208fe — — SSE Matrix Construction from 4×4 Data
   next_func: 0x0052098e — — PlaneFromEdgesNormalizeSSE
   xrefs_into: none

GAP 504: 0x00520df4 — 0x00520e0e (26 bytes)
   hex_head: 8db6000000008dbf00000000538bdc83ec0883e4f083c408eb03
   prev_func: 0x00520ce0 — — TriangleClosestPointOrNormal
   next_func: 0x00520e0e — — SSE Quaternion Composition from Axis-Angle Components
   xrefs_into: none

GAP 505: 0x0052690f — 0x0052692f (32 bytes)
   hex_head: e96752003b6852003f685200436852005468520058685200696852007a685200
   prev_func: 0x005267a7 — — Quaternion/Transform Composition
   next_func: 0x0052692f — — Matrix Interpolation/Blend
   xrefs_into: none

GAP 506: 0x00527393 — 0x00527578 (485 bytes)
   hex_head: 0f0e8b4424048b54240c8b4c24080f6f020f6e4a080f6f110f6e59080f0fd0b40f0fd9b40f0fd2ae0f0fd39e0f7f000f
   prev_func: 0x005272b5 — — 3DNow! Cubic Bezier Interpolation
   next_func: 0x00527578 — Normalize 2-component 3DNow! packed float vector using SIMD 
   xrefs_into: none

GAP 507: 0x005290f7 — 0x00529200 (265 bytes)
   hex_head: 8da424000000008bff0f6e3558935d000f6e3d5c935d000f6e256c935d000fdbf00f6e2d68935d000fdbc70f7fc30f66
   prev_func: 0x00529000 — — Square Root Approximation (SIMD/3DNow!)
   next_func: 0x00529200 — — Empty Stub
   xrefs_into: none

GAP 508: 0x0052a068 — 0x0052a090 (40 bytes)
   hex_head: 789b52004e9c5200fe9c5200599d5200e29d5200089e5200f99e52000fa0520061a05200e29f5200
   prev_func: 0x00529af8 — — Field Setter with VTable Alloc
   next_func: 0x0052a090 — — Indirect Call Dispatch
   xrefs_into: none

GAP 509: 0x0052d2a5 — 0x0052d8b0 (1547 bytes)
   hex_head: 0000000ccb00800000000010d45a00cc0000000ccc00800000000010d45a00cd0000000ccd00800000000010d45a00ce
   prev_func: 0x0052b561 — — Quaternion Multiply & Surface Sample (Wheel Contact)
   next_func: 0x0052d8b0 — — DirectInput8Create Import Stub
   xrefs_into: none

GAP 510: 0x0052df5d — 0x0052df70 (19 bytes)
   hex_head: 909090e80b000000e9f6000000909090909090
   prev_func: 0x0052df10 — — [PARTIAL] Unknown
   next_func: 0x0052df70 — — State Check and Conditional Init
   xrefs_into: none

GAP 511: 0x0052e530 — 0x0052e550 (32 bytes)
   hex_head: 568bf133c06a01890189410450884108e80b0000008bc65ec35b83c408c20800
   prev_func: 0x0052e520 — — Halt/Assert Handler
   next_func: 0x0052e550 — — Bounds-Checked Byte Setter
   xrefs_into: none

GAP 512: 0x00530739 — 0x00530840 (263 bytes)
   hex_head: 8d4900f602530004035300130353002203530031035300400353004f0353005e0353006d0353007c0353008b0353009a
   prev_func: 0x00530050 — — MP3 Audio Decoder — Huffman + Sample Rendering
   next_func: 0x00530840 — � Bitstream Texture Decompression
   xrefs_into: none

GAP 513: 0x00535bca — 0x00535c10 (70 bytes)
   hex_head: 8bff32585300a95853008b5a5300c45a5300025b53003c5b5300865b53001b59530082595300b7595300f15953002b5a
   prev_func: 0x005357c0 — — Argument Reorder Wrapper
   next_func: 0x00535e10 — — Conditional Multi-Field Reset
   xrefs_into: none

GAP 514: 0x00539f2e — 0x00539f60 (50 bytes)
   hex_head: 8bffbf9853007b9953006f9a5300f09a5300b09b5300239c53004f9d5300829e5300d39e5300d79e5300909090909090
   prev_func: 0x00539830 — — Object Alloc + Field Init
   next_func: 0x00539f60 — — Indirect Call via VTable+0x24
   xrefs_into: none

GAP 515: 0x0053b19a — 0x0053b1d0 (54 bytes)
   hex_head: 24e8b9b4ecff8b44240485c074058b511089108b44240885c074058b511489108b44240c85c074058b49188908c20c00
   prev_func: 0x0053b170 — — Three-Field Accessor
   next_func: 0x0053b1d0 — — Triple Field Getter
   xrefs_into: none

GAP 516: 0x0053be91 — 0x0053c102 (625 bytes)
   hex_head: 0f29442400d94424008be9bbffffff8b4424108b4c240c8b542408505152e87030020083c40cc3ff15a4e35900ffff8b
   prev_func: 0x0053be60 — — 3D Squared Distance
   next_func: 0x0053c102 — — Float Store from x87 ST(2)
   xrefs_into: none

GAP 517: 0x0053c1b0 — 0x0053c200 (80 bytes)
   hex_head: 68c0c15300e884b9040059c3909090908a0de48e8b00b00284c87523560ac857880de48e8b00bea0788b00bf2a000000
   prev_func: 0x0053c190 — — Arithmetic/Comparison (Loop Call x42)
   next_func: 0x0053c200 — — Delegation Wrapper
   xrefs_into: none

GAP 518: 0x0053d729 — 0x0053d750 (39 bytes)
   hex_head: 83c40433c05ec356578db198130000bf080000008d490083ee448bcee8262af7ff4f75f35f5ec3
   prev_func: 0x0053d4f0 — — DirectX Device/Surface Initialization
   next_func: 0x0053d850 — — Object Release with Vtable Call
   xrefs_into: none

GAP 519: 0x00544720 — 0x00544740 (32 bytes)
   hex_head: ab455400bb455400c8455400dd455400f1455400064654001b46540090909090
   prev_func: 0x00543fa0 — — Vertex Buffer Resource Allocation
   next_func: 0x00544af0 — — Audio/Network Stream Cleanup
   xrefs_into: none

GAP 520: 0x00545ff6 — 0x00546010 (26 bytes)
   hex_head: 8bfff15f5400735f5400a75f5400e15f54009090909090909090
   prev_func: 0x00545f50 — — Audio Volume/Load Computation
   next_func: 0x00546010 — — Audio Engine Initialization
   xrefs_into: none

GAP 521: 0x00547355 — 0x00547370 (27 bytes)
   hex_head: 8d4900e2725400fe7254001a735400367354009090909090909090
   prev_func: 0x005472d0 — — Float-to-Int Switch (Cases 1-4)
   next_func: 0x00547370 — — Arithmetic/Comparison (String Copy with Offset)
   xrefs_into: none

GAP 522: 0x0054d00a — 0x0054d030 (38 bytes)
   hex_head: 8bffc7cb540013cc540053cc54008ccc540028ce54007bce5400bfce5400fcce540090909090
   prev_func: 0x0054ca00 — � D3D Vertex Buffer Creation and Software T&L
   next_func: 0x0054d030 — — SceneNodeChildrenClear
   xrefs_into: none

GAP 523: 0x0054ee72 — 0x0054ee90 (30 bytes)
   hex_head: 8bff54eb5400f7eb540084ec540001ed540082ed5400faed540090909090
   prev_func: 0x0054eb40 — — 2D/3D Triangle Point Test
   next_func: 0x0054ee90 — Computes 2D cross product (perp dot product) of two vectors.
   xrefs_into: none

GAP 524: 0x005504bb — 0x005504d0 (21 bytes)
   hex_head: 906d04550053045500630455003a04550090909090
   prev_func: 0x005503a0 — (0x005503a0)
   next_func: 0x005504d0 — — Indexed Array Lookup with Bounds Check
   xrefs_into: none

GAP 525: 0x00552fa9 — 0x00552fc0 (23 bytes)
   hex_head: 8d4900382f5500382f5500412f5500412f550090909090
   prev_func: 0x00552f20 — — Texture Path Parsing and Dimension Calculation
   next_func: 0x00552fc0 — — Field Setter at +0x48
   xrefs_into: none

GAP 526: 0x0055422c — 0x00554260 (52 bytes)
   hex_head: eb3f5500c74055009e41550023425500344155000e40550058405500b44155009e415500234255002342550023425500
   prev_func: 0x00553fc0 — (0x00553fc0)
   next_func: 0x00554260 — — Enum-to-Field-Offset Setter
   xrefs_into: none

GAP 527: 0x00554f6a — 0x00554f80 (22 bytes)
   hex_head: 8bffd94e5500e34e5500ed4e5500f74e5500014f5500
   prev_func: 0x00554e90 — 
   next_func: 0x00554f80 — ```
   xrefs_into: none

GAP 528: 0x0055678d — 0x005567f5 (104 bytes)
   hex_head: 909090558bec528b4508f76d0c050080000083d2000facd0105ac9c3558bec515233c98b450823c0790341f7d8990fa4
   prev_func: 0x00556760 — @ 0x00556760 — 45 bytes
   next_func: 0x005567f5 — @ 0x005567f5 — 101 bytes
   xrefs_into: none

GAP 529: 0x0055bdc7 — 0x0055bde0 (25 bytes)
   hex_head: 9090909090909090908b811c010000c348188948e933fdffff
   prev_func: 0x0055bdc0 — — Field Getter at +0x118
   next_func: 0x0055bde0 — — Unidentified Logic / Linked List Indexed Traversal
   xrefs_into: none

GAP 530: 0x0055c9b7 — 0x0055ca40 (137 bytes)
   hex_head: 83c8ff83e992feffff568bf18b860011000085c05774638b44240c8986e41300008b86b013000033ff85c07e4d538d9e
   prev_func: 0x0055c9b0 — Returns field at param_1+0x1550.
   next_func: 0x0055ca40 — — Enum-to-VTable-Call Mapper (3 Cases)
   xrefs_into: none

GAP 531: 0x005604c0 — 0x005609de (1310 bytes)
   hex_head: 558bec83c4fc5657608b4530668945fefc8b7d188b7508d165288b45148b5510f7e203450c03450c03f08b45248b5520
   prev_func: 0x00560410 — 
   next_func: 0x005609de — ```
   xrefs_into: none

GAP 532: 0x00562509 — 0x00562530 (39 bytes)
   hex_head: 8d490098235600ae235600c4235600da235600f023560039245600b2245600c624560090909090
   prev_func: 0x005622c0 — — File Path/Name Lookup
   next_func: 0x00562530 — @ 0x00562530
   xrefs_into: none

GAP 533: 0x00564375 — 0x00564390 (27 bytes)
   hex_head: 8d4900234356002f4356003b4356003b4356009090909090909090
   prev_func: 0x005642f0 — — Struct Alloc/Init with Switch-Based Type
   next_func: 0x00564390 — — Audio Mixer Polling/Update Loop
   xrefs_into: none

GAP 534: 0x005653ab — 0x005653f0 (69 bytes)
   hex_head: 90c552560061525600675256006d52560094525600000404000404040404040404040404040404040404040404040404
   prev_func: 0x005651b0 — 
   next_func: 0x005653f0 — — String-Based Lookup / Key-Value Match
   xrefs_into: none

GAP 535: 0x0056f657 — 0x0056f7f9 (418 bytes)
   hex_head: 5f5e5b8be993faffff8bc1c700c0895b00c70588398d00f0fb8c00c7058c398d00b8fc8c00c70590398d0080fd8c00c7
   prev_func: 0x0056f100 — (0x0056f100)
   next_func: 0x0056f80b — — Node Count Check
   xrefs_into: none

GAP 536: 0x00579f6b — 0x00579f89 (30 bytes)
   hex_head: e900000000b984398d00e9e656ffffe900000000b980398d00e97db7ffff
   prev_func: 0x00579ccf — — Physics State Zero-Init
   next_func: 0x00579f89 — @ 0x00579f89 — 23 bytes
   xrefs_into: none

GAP 537: 0x00579ffa — 0x0057a020 (38 bytes)
   hex_head: 9090909090906810a05700e834db000059c390909090b9f03b8d00e9bffa0100909090909090
   prev_func: 0x00579ff0 — � Single Function Call Wrapper
   next_func: 0x0057a020 — — Struct Zero-Init (4 + 8 Words)
   xrefs_into: none

GAP 538: 0x0057a927 — 0x0057a940 (25 bytes)
   hex_head: 909090909090909090e80b000000e916000000909090909090
   prev_func: 0x0057a920 — — Single Function Call Wrapper
   next_func: 0x0057a940 — — Thunk to FUN_00598815
   xrefs_into: none

GAP 539: 0x0057a9d0 — 0x0057aa10 (64 bytes)
   hex_head: 8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e844d1000059c390909090
   prev_func: 0x0057a9b0 — — GenericDtorStub
   next_func: 0x0057aa10 — — Single Function Call Wrapper
   xrefs_into: none

GAP 540: 0x0057ab43 — 0x0057abb0 (109 bytes)
   hex_head: 90c4000000f6d81bc040c2040053568b35fc3b8d0033db3bf3743155578bfe8b7604385f0c74168b2f3beb74108bcde8
   prev_func: 0x0057ab20 — — Pointer Check with Fallback
   next_func: 0x0057abb0 — (0x0057abb0)
   xrefs_into: none

GAP 541: 0x0057adfa — 0x0057ae30 (54 bytes)
   hex_head: 9090909090906810ae5700e834cd000059c390909090b9f83b8d00e9bfec0100909090909090e80b000000e916000000
   prev_func: 0x0057adf0 — — Single Function Call Wrapper
   next_func: 0x0057ae30 — — [PARTIAL] Unknown
   xrefs_into: none

GAP 542: 0x0057af75 — 0x0057afa0 (43 bytes)
   hex_head: 20894824c700e966ffffff8a442404568bf1a801c706408a5b00740956e838cc000083c4048bc65ec20400
   prev_func: 0x0057aef0 — � Linked List Destruction & Cleanup
   next_func: 0x0057afa0 — — Network Packet Constructor
   xrefs_into: none

GAP 543: 0x0057b2e4 — 0x0057b330 (76 bytes)
   hex_head: c4045fb8010000005ec204008b54240485d27c273b51247d228b411885d27e0c85c074178b40044a85d27ff485c0740b
   prev_func: 0x0057b2e0 — Returns field at param_1+0x24.
   next_func: 0x0057b330 — — Network Connection List Duplication
   xrefs_into: none

GAP 544: 0x0057c795 — 0x0057c7b0 (27 bytes)
   hex_head: 8d49001fc7570044c7570060c7570068c757009090909090909090
   prev_func: 0x0057bee0 — — NetworkSocketCreate
   next_func: 0x0057c7b0 — — SocketBindPortScan
   xrefs_into: none

GAP 545: 0x0057d4ea — 0x0057d5d0 (230 bytes)
   hex_head: 8bff90d4570084d457008ad457006cd4570072d4570054d45700b4d4570042d4570048d45700a2d45700d2d45700bad4
   prev_func: 0x0057ca10 — (0x0057ca10)
   next_func: 0x0057d5d0 — — Structured Memory Copy with Header Prepend
   xrefs_into: none

GAP 546: 0x0057ef97 — 0x0057f0c8 (305 bytes)
   hex_head: a4e15900e9d3feffff83ec38555733ff8be9897c2408e8ce660000dd85e0000000db442478dc0d08ea5900ded9dfe025
   prev_func: 0x0057ef80 — — VtableDeleteWrapper
   next_func: 0x0057f0c8 — — NetworkSocketAddressInit
   xrefs_into: none

GAP 547: 0x005806f9 — 0x00580c10 (1303 bytes)
   hex_head: 8bc0e9d1f7ccff518b81680b00005356578db9480b0000894c240c85c0741a8b4f245150ff15a0e1590085c074073d80
   prev_func: 0x005805c0 — — Network Packet Queue Reader
   next_func: 0x00580c10 — — Network Packet Send
   xrefs_into: none

GAP 548: 0x00581939 — 0x005819c0 (135 bytes)
   hex_head: 01cc0000cc3bff56578b7c240c33c03bf8746a8b3133d23bf07462393e740e8bd68b76043bf075f35f5ec208003b7108
   prev_func: 0x005818e0 — — List Destruction with Handle Close
   next_func: 0x005819c0 — — Linked List Destroy with Vtable Destructor Call
   xrefs_into: none

GAP 549: 0x0058326f — 0x005832e0 (113 bytes)
   hex_head: 9051568b3185f6894c2404743d55578bee8b76048a450884c0741c8b7d0085ff74158b0f85c974068b016a03ff1057e8
   prev_func: 0x00583210 — — Linked List Node Alloc & Prepend
   next_func: 0x005832e0 — @ 0x005832e0 — 122 bytes
   xrefs_into: none

GAP 550: 0x00584f27 — 0x00584f90 (105 bytes)
   hex_head: 9090909090909090908b81a805000053568db19805000032db85c074388b4e145150ff15a0e1590085c074073d800000
   prev_func: 0x00584e30 — @ 0x00584e30 — 247 bytes
   next_func: 0x00584f90 — — Mutex-Guarded Timer Read
   xrefs_into: none

GAP 551: 0x00585d63 — 0x00585de0 (125 bytes)
   hex_head: 7407568115a4e159005ec20400568bf1576a058b861806000033ff50ff15a0e159003d02010000744783f8ff74428b54
   prev_func: 0x00585d20 — — Mutex-Protected Pointer Read + Release
   next_func: 0x00585de0 — — QueueUserAPC Async Procedure Call
   xrefs_into: none

GAP 552: 0x005861d9 — 0x00586240 (103 bytes)
   hex_head: cc00ff1500ffff568bf18a465c84c074158b465450ff15a8e1590085c07407c74654000000005ec3c05e890389430489
   prev_func: 0x00586170 — — Handle Close & Linked List Cleanup
   next_func: 0x00586240 — — Linked-List Destruction with SEH + Alloc Cleanup
   xrefs_into: none

GAP 553: 0x00586e8d — 0x00586ed0 (67 bytes)
   hex_head: 9090908a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e8840c000059c390
   prev_func: 0x00586e50 — — Short Computation / Struct Copy Assignment
   next_func: 0x00586ed0 — — Thunk to FUN_00598815
   xrefs_into: none

GAP 554: 0x00587062 — 0x00587090 (46 bytes)
   hex_head: 3bfe72d38b4424105b5f5e5d59c3568bf1e858000000f644240801740956e84a0b000083c4048bc65ec204009090
   prev_func: 0x00587030 — — Object Init with VTable Setup
   next_func: 0x00587090 — — Object Copy-Construct from Source
   xrefs_into: none

GAP 555: 0x0058768a — 0x005876c0 (54 bytes)
   hex_head: 90909090909068a0765800e8a404000059c390909090b9393e8d00e9ea120100909090909090e80b000000e916000000
   prev_func: 0x00587680 — � Single Delegate (thunk to FUN_00598815)
   next_func: 0x005876c0 — — Single Function Call Wrapper
   xrefs_into: none

GAP 556: 0x00587a5a — 0x00587a90 (54 bytes)
   hex_head: 90909090909068707a5800e8d400000059c390909090b93d3e8d00e91a0f0100909090909090e80b000000e916000000
   prev_func: 0x00587a50 — — Thunk to FUN_00598815
   next_func: 0x00587a90 — — Single Function Call Wrapper
   xrefs_into: none

GAP 557: 0x00588a19 — 0x00588a34 (27 bytes)
   hex_head: 558b4c24088b298b411c508b411850e879feffff83c4085dc20400
   prev_func: 0x0058895c — — ScriptFrameProcessor
   next_func: 0x00588c7a — @ 0x00588c7a
   xrefs_into: none

GAP 558: 0x0058b59f — 0x0058b5d4 (53 bytes)
   hex_head: 558bec51518d45f85650ff15b8e159006a016a006a00ff75fce8331100008b4df833f603c113d6a3c03e8d008915c43e
   prev_func: 0x0058b4d4 — 
   next_func: 0x0058b5d4 — @ 0x0058b5d4
   xrefs_into: none

GAP 559: 0x0058d76e — 0x0058d78e (32 bytes)
   hex_head: ecd15800c2d05800ddd0580029d1580060d1580068d158009dd1580030d25800
   prev_func: 0x0058cf35 — 
   next_func: 0x0058d78e — — Stream Byte Output with Buffer Management
   xrefs_into: none

GAP 560: 0x0058dd3e — 0x0058dd75 (55 bytes)
   hex_head: 66813c247f027403d92c245ac3668b0424663d7f02741e6683e02074159bdfe06683e020740cb808000000e8e9feffff
   prev_func: 0x0058dd28 — — Float Exponent Extract with NaN Guard
   next_func: 0x0058dd75 — — FPU Status/Error Handler
   xrefs_into: none

GAP 561: 0x005909c7 — 0x005910a0 (1753 bytes)
   hex_head: 83ec2c83e03fff24853e755e00d8f083c42cc383c42ccd06d8f883c42cc383c42ccd06d8f083c42cc3def883c42cc3d8
   prev_func: 0x005908b0 — — Extended-Precision Division with Overflow Fixup
   next_func: 0x005910a1 — — Double Arithmetic Wrapper
   xrefs_into: none

GAP 562: 0x005966e6 — 0x00596716 (48 bytes)
   hex_head: af625900fe625900556359007f635900da6359005164590087645900d1645900b0645900356559001f655900eb645900
   prev_func: 0x00596245 — @ 0x00596245
   next_func: 0x00596716 — @ 0x00596716 — 93 bytes
   xrefs_into: none

GAP 563: 0x00598815 — 0x00598994 (383 bytes)
   hex_head: b818d25900e8b91dffff51515356894dec33f68d4df08975f0e81a1d00003935f49e5e007c0aff05f49e5e0032dbeb0c
   prev_func: 0x0059880b — — PhysicsThunk
   next_func: 0x00598994 — — Ref Count Decrement with Cleanup
   xrefs_into: none

GAP 564: 0x00599958 — 0x00599ad9 (385 bytes)
   hex_head: b878d35900e8760cffff51515356894dec33f68d4df08975f0e8d70b000039354ca05e007c0aff054ca05e0032dbeb0c
   prev_func: 0x0059994e — — Thin Forwarding Wrapper
   next_func: 0x00599ad9 — — Ref Count Decrement with Check
   xrefs_into: none

GAP 565: 0x0059ac63 — 0x0059ac7f (28 bytes)
   hex_head: 568bf1e814000000f644240801740756e857cffeff598bc65ec20400
   prev_func: 0x0059ac46 — — std::locale::facet Destructor
   next_func: 0x0059ac7f — — Object Teardown with Iterator Cleanup
   xrefs_into: none

GAP 566: 0x0059bacc — 0x0059bae8 (28 bytes)
   hex_head: 568bf1e8cffffffff644240801740756e8eec0feff598bc65ec20400
   prev_func: 0x0059baa3 — — Type-Info Destructor
   next_func: 0x0059bae8 — Calls FUN_0059c127(param_1, param_2[0], param_2[1], 0)
   xrefs_into: none

GAP 567: 0x0059ca45 — 0x0059ca69 (36 bytes)
   hex_head: cccccccccccccccccccccc8b85ecfeffff50e873b1feff59c38d8dc8feffffe91750feff
   prev_func: 0x0059ca3b — — ExceptionHandlerThunk
   next_func: 0x0059ca69 — — C++ Exception Handler Wrapper
   xrefs_into: none

GAP 568: 0x0059cab2 — 0x0059cb33 (129 bytes)
   hex_head: cccccccccccccccccccccccccccc8b45e050e806b1feff59c3b8b8ab5b00e9abd8feffcccccccccccccccccccccc8d4d
   prev_func: 0x0059caa8 — — CxxFrameHandlerWrapper
   next_func: 0x0059cb33 — — C++ Exception Handler Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_B.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
