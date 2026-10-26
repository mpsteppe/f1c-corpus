# WORKER D — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
Worker D of 20, items 130–172.

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_D.md

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

GAP 130: 0x00405044 — 0x004053e0 (924 bytes)
   hex_head: 2b180083c404b840a45e00c3568b74240856e885ffffff8bc8e8ae2e000083f8ff740f8b4c240c8901b8010000005ec2
   prev_func: 0x00405030 — — SettingsSaveWrapper
   next_func: 0x004053e0 — — short computation
   xrefs_into: none

GAP 131: 0x004085c8 — 0x004085f0 (40 bytes)
   hex_head: 90dd0590fe8a00c3f644240401568bf1c70634e65900740956e8e9f5170083c4048bc65ec2040090
   prev_func: 0x004085c0 — — Stub Return 1
   next_func: 0x004085f0 — � Sound Effect Playback (Positional Audio)
   xrefs_into: none

GAP 132: 0x0040cdb9 — 0x0040cdd0 (23 bytes)
   hex_head: 8d490077cd400082cd40008dcd400098cd4000a3cd4000
   prev_func: 0x0040cd60 — — Session Phase Decode
   next_func: 0x0040cdd0 — — Simple Setter (Struct + 8 = param_2)
   xrefs_into: none

GAP 133: 0x0040f5da — 0x0040f600 (38 bytes)
   hex_head: 8bff8ff54000a8f54000c1f540008ff54000a8f54000c1f5400062f540009090909090909090
   prev_func: 0x0040f550 — — UI/Camera Mode Dispatch with Vehicle Data Read
   next_func: 0x0040f600 — — Camera Shake Ring Buffer Write
   xrefs_into: none

GAP 134: 0x00418bfc — 0x00418c10 (20 bytes)
   hex_head: a48b4100bc8b4100d18b4100e68b410090909090
   prev_func: 0x00418b90 — — Score/Threshold Gate Check
   next_func: 0x00418c10 — — Memory Allocation / Nested Pointer Free with Conditional D
   xrefs_into: none

GAP 135: 0x00421200 — 0x004212e0 (224 bytes)
   hex_head: af0d4200b60d4200bd0d4200c40d4200cb0d4200d20d4200d90d4200e00d4200e70d4200ee0d4200f50d4200fc0d4200
   prev_func: 0x00420490 — — Position Change Detector
   next_func: 0x004212e0 — — Short Computation (Session Score Aggregation)
   xrefs_into: none

GAP 136: 0x004305e4 — 0x00430600 (28 bytes)
   hex_head: d1034300d8034300e4034300f0034300909090909090909090909090
   prev_func: 0x0042fd00 — — Vehicle Setup File Writer
   next_func: 0x00430600 — — WheelForceAggregate
   xrefs_into: none

GAP 137: 0x0044b8f1 — 0x0044b910 (31 bytes)
   hex_head: 8d490016b8440078b7440078b7440078b74400f3b644009090909090909090
   prev_func: 0x0044b370 — — Bezier Patch Tessellation
   next_func: 0x0044b910 — — Bounding Box Computation from Triangles
   xrefs_into: none

GAP 138: 0x0044c961 — 0x0044c980 (31 bytes)
   hex_head: c94400e844b2130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044c950 — — Collision Sound Unregister (Label)
   next_func: 0x0044c980 — — Collision Global Init (Set 10, -1.0f)
   xrefs_into: none

GAP 139: 0x0044cd21 — 0x0044cd54 (51 bytes)
   hex_head: cc4400e884ae130059c390909090c3e80b000000e936000000909090909090c7050ca57c0021000000c70510a57c0000
   prev_func: 0x0044cd10 — — Collision constructor thunk
   next_func: 0x0044cd54 — — Initialize Physics Constants
   xrefs_into: none

GAP 140: 0x0044d0e1 — 0x0044d100 (31 bytes)
   hex_head: d04400e8c4aa130059c390909090c3e80b000000e936000000909090909090
   prev_func: 0x0044d0d0 — — Collision Sound Unregister (DAT)
   next_func: 0x0044d100 — — Collision Global Init (Set 0x6b, -1.0f)
   xrefs_into: none

GAP 141: 0x0044d4b0 — 0x0044d4c0 (16 bytes)
   hex_head: e80b000000e936000000909090909090
   prev_func: 0x0044d490 — — CollisionCallbackRegister_d4a0
   next_func: 0x0044d4c0 — — CollisionGridInit16x16
   xrefs_into: none

GAP 142: 0x0045954b — 0x00459830 (741 bytes)
   hex_head: 4d5954480081ec54010000dd0530f059005355568bf1dc76288b8ed00000005733ff897c242433dbdc8e80010000dc05
   prev_func: 0x004594d0 — — Struct Init with Float Constants (Physics Params)
   next_func: 0x00459830 — — Float/Double Coordinate Transform
   xrefs_into: none

GAP 143: 0x00461c6e — 0x00461cc3 (85 bytes)
   hex_head: 9090566860ce01008bf1e8865f120083c40485c0740e568bc8e8a4b8ffff89068bc65ec333c089068bc65ec3c2e8b949
   prev_func: 0x00461900 — — SessionConfigWriteback
   next_func: 0x00461cd0 — — Session State Check
   xrefs_into: none

GAP 144: 0x00466d99 — 0x004670e0 (839 bytes)
   hex_head: 5e8ae9b4ffffff8b811c0300005333db3bc30f8498010000837c240801568b30750a8b912c03000003f2eb088b913003
   prev_func: 0x00466d60 — — Short Computation / Object Init + VTable
   next_func: 0x004670e0 — — Switch on Action ID → Virtual Call
   xrefs_into: none

GAP 145: 0x0046c03b — 0x0046c6e5 (1706 bytes)
   hex_head: 4d59544800568bf18b867401000085c07e124885c089867401000075076a01e8b1feffff833de8c95c0001741c8b8678
   prev_func: 0x0046c030 — Sets integer field at +0x174 to 2.
   next_func: 0x0046c6f0 — — Short Computation (Constructor-like)
   xrefs_into: none

GAP 146: 0x0047455a — 0x004750f0 (2966 bytes)
   hex_head: 00e8f920f9ff566a018bf1e8f627ffff6aff68a4325c008bcec706403b5a00c7861c03000058fd7c00c7862403000003
   prev_func: 0x00474510 — � SessionEnter_Alt
   next_func: 0x004750f0 — � UI Object Init with Zero Fields
   xrefs_into: none

GAP 147: 0x0047aa73 — 0x0047aab0 (61 bytes)
   hex_head: c65ec390909090b8e996feffff568bf1c706e0665a00e822b40000f644240801740956e834d1100083c4048bc65ec204
   prev_func: 0x0047aa60 — — Empty Stub
   next_func: 0x0047aab0 — — TextWidget_Init
   xrefs_into: none

GAP 148: 0x00485ad6 — 0x00485b90 (186 bytes)
   hex_head: c4045e8bc5e985ffffff568bf18b867401000085c0740950e8dc20100083c4048bcee843390000f644240801740956e8
   prev_func: 0x00485a90 — � Destructor with Two-Pointer Free
   next_func: 0x00485df0 — — Global Manager Shutdown Sequence
   xrefs_into: none

GAP 149: 0x0048a9e8 — 0x0048aa40 (88 bytes)
   hex_head: 9090909090909090e80bf3ffff33c0c3ff5b83e939f8ffff8b4424108b54240c508b44240c528b54240c5052e827f8ff
   prev_func: 0x0048a8d0 — — UI Scroll List Update
   next_func: 0x0048aa40 — — Object Init with Field Zeroing
   xrefs_into: none

GAP 150: 0x0048e643 — 0x0048e670 (45 bytes)
   hex_head: 302300008bc8e8d93200005ec3568bf1e818000000f644240801740956e86a950f0083c4048bc65ec204009090
   prev_func: 0x0048e600 — — UI Struct Init (Type 0)
   next_func: 0x0048e670 — — Destructor
   xrefs_into: none

GAP 151: 0x0049624d — 0x00496280 (51 bytes)
   hex_head: 8d4900a960490079614900be614900be614900be614900ca604900df604900f46049000d614900226149003b61490051
   prev_func: 0x00496030 — — Car Crash Damage Processing
   next_func: 0x00496280 — — Float Array Init with Random
   xrefs_into: none

GAP 152: 0x0049ad73 — 0x0049adb0 (61 bytes)
   hex_head: 08894e0c8946105ee9caffffff8b4424043b410c7c1b3b41107f168b4424083b41047c0d3b41087f08b801000000c208
   prev_func: 0x0049ad50 — � String/Path Processing
   next_func: 0x0049adb0 — — Short Computation (Field Getter at +0xc)
   xrefs_into: none

GAP 153: 0x004a0615 — 0x004a0630 (27 bytes)
   hex_head: 8d4900ae054a00b5054a00bc054a00c3054a00ca054a00d1054a00
   prev_func: 0x004a0590 — � Session Type Dispatch
   next_func: 0x004a0630 — — Session/Scene Init Chain
   xrefs_into: none

GAP 154: 0x004af1f4 — 0x004af220 (44 bytes)
   hex_head: 0aea4a0076ec4a00e2ee4a0046f04a00c7f14a00d6f14a00d6f14a00e5f14a00909090909090909090909090
   prev_func: 0x004ae9f0 — � AI Difficulty Configuration per Race Mode
   next_func: 0x004af220 — — TireCompoundClamp
   xrefs_into: none

GAP 155: 0x004b5be0 — 0x004b5c50 (112 bytes)
   hex_head: 8b44240483f8048981ac0900007745ff2485385c4b00c7817c0f0000abaa2a3ec20400c7817c0f00000000003ec20400
   prev_func: 0x004b5a30 — — DestroyUIWidgetHierarchy
   next_func: 0x004b5c50 — — Vehicle Instance List Builder
   xrefs_into: none

GAP 156: 0x004be67c — 0x004be6f0 (116 bytes)
   hex_head: 90909090e90b000000909090909090909090909033c057b960000000bfe8c18a00f3aba3d0c18a00a3e4c18a00a3dcc1
   prev_func: 0x004be4e0 — — Sprite Grid Render
   next_func: 0x004be6f0 — — Delegation
   xrefs_into: none

GAP 157: 0x004c902c — 0x004c91d0 (420 bytes)
   hex_head: 90909090a114ce5a0050e8d5feffff33c089411c894120894124894128c7013cce5a008bc1c3d9e08bced91fff5004e9
   prev_func: 0x004c9000 — — Arithmetic/Comparison (Chained Validation)
   next_func: 0x004c91d0 — — Triple VTable Destructor Release
   xrefs_into: none

GAP 158: 0x004d48f6 — 0x004d4a58 (354 bytes)
   hex_head: 5ec2080033e9a1ffffffa1cc435d0085c0741a8b490485c974138b54240c528b54240c528b54240cffd0c20c0033c0c2
   prev_func: 0x004d48b0 — — Countdown Timer with Callback
   next_func: 0x004d4a58 — — Struct Field Initializer
   xrefs_into: none

GAP 159: 0x004db02c — 0x004db070 (68 bytes)
   hex_head: bdae4d00e6ae4d000faf4d0038af4d0061af4d008eaf4d00b4af4d00d9af4d0002b04d0029b04d000001020909090304
   prev_func: 0x004daea0 — — Direct3D Object Factory
   next_func: 0x004db070 — — Constructor: VTable + 3 Fields
   xrefs_into: none

GAP 160: 0x004ee133 — 0x004ee150 (29 bytes)
   hex_head: 90aadb4e005edf4e0025e04e0081e04e00909090909090909090909090
   prev_func: 0x004ed960 — — FuelConsumptionAndWear
   next_func: 0x004ee150 — — Engine Wear/Failure Simulation
   xrefs_into: none

GAP 161: 0x004ff0d7 — 0x004ff127 (80 bytes)
   hex_head: d999b000e953ffffffd94120d81d40e45900dfe0f6c4447a06b802000000c3d94124d81d40e45900dfe0f6c4447a06b8
   prev_func: 0x004ff040 — — ValueClampRange (clamp two values with min bound)
   next_func: 0x004ff127 — — Render Object Field Setter
   xrefs_into: none

GAP 162: 0x0051fd1c — 0x0051fd2e (18 bytes)
   hex_head: 8d742600538bdc83ec0883e4f083c408eb03
   prev_func: 0x0051fc80 — — Vector Normalize with Newton-Raphson Refinement
   next_func: 0x0051fd2e — — Vec3NormalizeNewtonRaphson
   xrefs_into: none

GAP 163: 0x00526c88 — 0x0052704a (962 bytes)
   hex_head: 926b52009e6b5200a16b5200a46b5200a86b5200ab6b5200ae6b5200b26b52000f0e8b4424088b54240c8b4c24040f6f
   prev_func: 0x00526b55 — — 3DNow Vector Transform
   next_func: 0x0052704a — — QuaternionProduct3DNow
   xrefs_into: none

GAP 164: 0x00531147 — 0x00531250 (265 bytes)
   hex_head: 90a40c5300b50c5300c70c5300d90c5300eb0c5300fd0c53000f0d5300210d5300330d5300450d5300570d5300690d53
   prev_func: 0x00530840 — � Bitstream Texture Decompression
   next_func: 0x00531250 — — Texture Decompression (Variable-Length Code Decoder)
   xrefs_into: none

GAP 165: 0x00544720 — 0x00544740 (32 bytes)
   hex_head: ab455400bb455400c8455400dd455400f1455400064654001b46540090909090
   prev_func: 0x00543fa0 — — Vertex Buffer Resource Allocation
   next_func: 0x00544af0 — — Audio/Network Stream Cleanup
   xrefs_into: none

GAP 166: 0x00553cc5 — 0x00553db0 (235 bytes)
   hex_head: fbffff5b8946185ec208003bca7e068bc18bca8bd08b442410508b44240c2bd14250528b5424100faf54241803d152e8
   prev_func: 0x00553aa0 — @ 0x00553aa0
   next_func: 0x00553db0 — — Struct Init with Default Values
   xrefs_into: none

GAP 167: 0x00563f0f — 0x00563f70 (97 bytes)
   hex_head: 90d03e5600d73e5600de3e5600e53e56008b4c24088b15b4468d008b442404568b098b92800000008b30576a00e8ef05
   prev_func: 0x00563ec0 — — Switch Param Store + Global Set
   next_func: 0x00563f70 — — Physics Sign/Direction Function
   xrefs_into: none

GAP 168: 0x0057a9d0 — 0x0057aa10 (64 bytes)
   hex_head: 8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa4700e844d1000059c390909090
   prev_func: 0x0057a9b0 — — GenericDtorStub
   next_func: 0x0057aa10 — — Single Function Call Wrapper
   xrefs_into: none

GAP 169: 0x0057ed35 — 0x0057ee80 (331 bytes)
   hex_head: 008ac35f5b83e9c3feffff53578bf933db8b87100b00003bc374738b8f140b00005150ff15a0e159003bc374073d8000
   prev_func: 0x0057ec10 — 
   next_func: 0x0057ee80 — — Thread-Safe Mutex Queue with Timed Wait
   xrefs_into: none

GAP 170: 0x00586634 — 0x00586670 (60 bytes)
   hex_head: 89460489460889e997feffff8a0db8468d00b00184c875080ac8880db8468d00e907000000909090909090906860aa47
   prev_func: 0x00586620 — — Node Destruction with Virtual Call
   next_func: 0x00586670 — (0x00586670)
   xrefs_into: none

GAP 171: 0x0058d76e — 0x0058d78e (32 bytes)
   hex_head: ecd15800c2d05800ddd0580029d1580060d1580068d158009dd1580030d25800
   prev_func: 0x0058cf35 — 
   next_func: 0x0058d78e — — Stream Byte Output with Buffer Management
   xrefs_into: none

GAP 172: 0x0059b050 — 0x0059b07a (42 bytes)
   hex_head: f605b8468d00017507800db8468d0001e815000000f605645a8d00017507800d645a8d0001e90c000000
   prev_func: 0x0059b038 — — Object Init with VTable
   next_func: 0x0059b07a — — Single Function Call Wrapper
   xrefs_into: none

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\gap_analyze\worker_D.md.
1. Classify EVERY gap.
2. For missed_function: note the prologue bytes.
3. For data_table: note element type and estimated count.
4. Write to disk after every 20 classifications.
