## TireModelDataInit_004f34e0 — Tire Model Data Structure Initializer

**Summary:** Initializes the per-vehicle tire model data structure with default values: zeroes out runtime accumulators, sets sentinel handles (-1), populates tire friction/camber/slip-angle coefficient arrays, and loads a configuration file path.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireModelInit (0043e050), sub_45C400 (0045c400), TelemetryDataDump (004d4a80), sub_4E3360 (004e3360), LargeConfigFunctionWithPhysicsConstants (004e45b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Handle0 (index/handle, 0 = unset) |
| this | 0x4 | RW | 18446744073709551615 | Handle1 (-1 sentinel = invalid handle) |
| this | 0x8 | RW | 18446744073709551615 | Handle2 (-1 sentinel) |
| this | 0xC | RW | 0 | Handle3 |
| this | 0x10 | RW | 18446744073709551615 | Handle4 (-1 sentinel) |
| this | 0x14 | RW | 0 | Handle5 |
| this | 0x18 | RW | 18446744073709551615 | Handle6 (-1 sentinel) |
| this | 0x1C | RW | 0 | Handle7 |
| this | 0x20 | RW | 18446744073709551615 | Handle8 (-1 sentinel) |
| this | 0x24 | RW | 0 | Handle9 |
| this | 0x28 | RW | 18446744073709551615 | Handle10 (-1 sentinel) |
| this | 0x2C | RW | 0 | Handle11 |
| this | 0x30 | RW | 18446744073709551615 | Handle12 (-1 sentinel) |
| this | 0x34 | RW | 0 | Handle13 |
| this | 0x38 | RW | 0 | ZeroField (cleared) |
| this | 0x3C | RW | 15 | ArrayCount (likely number of tire compound entries) |
| this | 0x60 | RW | 18446744071991564698 | CoefficientA0 (negative float constant for tire model) |
| this | 0x64 | RW | 1070176665 → 1.575f | CoefficientB0 (tire friction/lateral force coefficient) |
| this | 0x68 | RW | 0 | Accumulator0 (runtime scratch, zero-init) |
| this | 0x6C | RW | 0 | Accumulator1 |
| this | 0x70 | RW | 0 | Accumulator2 |
| this | 0x74 | RW | 0 | Accumulator3 |
| this | 0x78 | RW | 0 | Accumulator4 |
| this | 0x7C | RW | 0 | Accumulator5 |
| this | 0x80 | RW | 0 | Accumulator6 |
| this | 0x84 | RW | 0 | Accumulator7 |
| this | 0xE0 | RW | 0 | SubStructStart (zero-init block via ZeroInit) |
| this | 0xE4 | RW | 1082228736 → 4.0469f | TireStiffness (longitudinal/lateral stiffness coefficient) |
| this | 0xE8 | RW | 1717986918 | TireConstantInt (bit-pattern constant, likely packed flags) |
| this | 0xEC | RW | 1072064102 → 1.8f | TireFrictionPeak (peak friction coefficient) |
| this | 0xF0 | RW | 2 | TireModelMode (2 = some active mode) |
| this | 0xF4 | RW | 18446744073365954232 | TireModelParamA (negative constant) |
| this | 0xF8 | RW | 1067366481 → 1.24f | TireModelParamB (friction sliding coefficient) |
| this | 0xFC | RW | 0 | Accumulator8 |
| this | 0x100 | RW | 1071644672 → 1.75f | TireCamberCoeff (camber stiffness coefficient) |
| this | 0x104 | RW | 18446744072098938880 | TireCamberOffset (negative camber offset constant) |
| this | 0x108 | RW | 1071225241 → 1.7f | TireSlipAngleCoeff (slip angle coefficient) |
| this | 0x10C | RW | 1073741824 → 2.0f | TireLoadSensitivity (load sensitivity factor) |
| this | 0x110 | RW | 1072902963 → 1.9f | TireCurvatureFactor (curvature/fall-off factor) |
| this | 0x114 | RW | 0 | Accumulator9 |
| this | 0x118 | RW | 1071644672 → 1.75f | TireCamberCoeff2 (camber coefficient duplicate) |
| this | 0x11C | RW | 18446744072635809792 → -2.0f | TireCamberOffset2 (negative camber offset) |
| this | 0x120 | RW | 1070386380 → 1.6f | TireRelaxationLength (relaxation length coefficient) |
| this | 0x124 | RW | 0 | Accumulator10 |
| this | 0x128 | RW | 1072693248 → 1.875f | TireAligningTorqueCoeff (aligning torque coefficient) |
| this | 0x1EC | RW | 0 | SubStruct1 (zero-init via sub_4F31F0) |
| this | 0x1F0 | RW | 0 | SubStruct1_Field4 |
| this | 0x1F4 | RW | 0 | SubStruct1_Field5 |
| this | 0x1F8 | RW | 0 | SubStruct1_Field6 |
| this | 0x1FC | RW | 0 | SubStruct1_Field7 |
| this | 0x200 | RW | 0 | SubStruct1_Field8 |
| this | 0x204 | RW | 0 | SubStruct1_Field9 |
| this | 0x208 | RW | 0 | SubStruct1_Field10 |
| this | 0x20C | RW | 0 | SubStruct1_Field11 |
| this | 0x210 | RW | 0 | SubStruct1_Field12 |
| this | 0x214 | RW | 0 | SubStruct1_Field13 |
| this | 0x218 | RW | 0 | SubStruct1_Field14 |
| this | 0x21C | RW | 0 | SubStruct1_Field15 |
| this | 0x220 | RW | 0 | SubStruct1_Field16 |
| this | 0x224 | RW | 0 | SubStruct1_Field17 |
| this | 0x228 | RW | 0 | SubStruct1_Field18 |
| this | 0x22C | RW | 0 | SubStruct1_Field19 |
| this | 0x230 | RW | 0 | SubStruct1_Field20 |
| this | 0x234 | RW | 0 | SubStruct1_Field21 |
| this | 0x2E0 | RW | 0 | SubStruct2 (zero-init via sub_4F31F0) |
| this | 0x2E4 | RW | 0 | SubStruct2_Field4 |
| this | 0x2E8 | RW | 0 | SubStruct2_Field5 |
| this | 0x2EC | RW | 0 | SubStruct2_Field6 |
| this | 0x2F0 | RW | 0 | SubStruct2_Field7 |
| this | 0x2F4 | RW | 0 | SubStruct2_Field8 |
| this | 0x2F8 | RW | 0 | SubStruct2_Field9 |
| this | 0x2FC | RW | 0 | SubStruct2_Field10 |
| this | 0x300 | RW | 0 | SubStruct2_Field11 |
| this | 0x304 | RW | 0 | SubStruct2_Field12 |
| this | 0x308 | RW | 0 | SubStruct2_Field13 |
| this | 0x30C | RW | 0 | SubStruct2_Field14 |
| this | 0x310 | RW | 0 | SubStruct2_Field15 |
| this | 0x314 | RW | 0 | SubStruct2_Field16 |
| this | 0x318 | RW | 0 | SubStruct2_Field17 |
| this | 0x31C | RW | 0 | SubStruct2_Field18 |
| this | 0x320 | RW | 0 | SubStruct2_Field19 |
| this | 0x324 | RW | 0 | SubStruct2_Field20 |
| this | 0x328 | RW | 0 | SubStruct2_Field21 |
| this | 0x32C | RW | 0 | SubStruct2_Field22 |
| this | 0x330 | RW | 0 | SubStruct2_Field23 |
| this | 0x3DC | RW | 0 | SubStruct3 (zero-init via sub_4F31F0) |
| this | 0x3E0 | RW | 0 | SubStruct3_Field4 |
| this | 0x3E4 | RW | 0 | SubStruct3_Field5 |
| this | 0x3E8 | RW | 0 | SubStruct3_Field6 |
| this | 0x3EC | RW | 0 | SubStruct3_Field7 |
| this | 0x3F0 | RW | 0 | SubStruct3_Field8 |
| this | 0x3F4 | RW | 0 | SubStruct3_Field9 |
| this | 0x3F8 | RW | 0 | SubStruct3_Field10 |
| this | 0x3FC | RW | 0 | SubStruct3_Field11 |
| this | 0x400 | RW | 0 | SubStruct3_Field12 |
| this | 0x404 | RW | 0 | SubStruct3_Field13 |
| this | 0x408 | RW | 0 | SubStruct3_Field14 |
| this | 0x40C | RW | 0 | SubStruct3_Field15 |
| this | 0x410 | RW | 0 | SubStruct3_Field16 |
| this | 0x414 | RW | 0 | SubStruct3_Field17 |
| this | 0x418 | RW | 0 | SubStruct3_Field18 |
| this | 0x41C | RW | 0 | SubStruct3_Field19 |
| this | 0x420 | RW | 0 | SubStruct3_Field20 |
| this | 0x424 | RW | 0 | SubStruct3_Field21 |
| this | 0x428 | RW | 0 | SubStruct3_Field22 |
| this | 0x4D4 | RW | 0 | ZeroArray0 (16-element zero-init via ZeroInit16ElementArray) |
| this | 0x4D8 | RW | 0 | ZeroArray0_Field4 |
| this | 0x4DC | RW | 0 | ZeroArray0_Field5 |
| this | 0x4E0 | RW | 0 | ZeroArray0_Field6 |
| this | 0x4E4 | RW | 0 | ZeroArray0_Field7 |
| this | 0x4E8 | RW | 0 | ZeroArray0_Field8 |
| this | 0x4EC | RW | 0 | ZeroArray0_Field9 |
| this | 0x4F0 | RW | 0 | ZeroArray0_Field10 |
| this | 0x4F4 | RW | 0 | ZeroArray0_Field11 |
| this | 0x4F8 | RW | 0 | ZeroArray0_Field12 |
| this | 0x4FC | RW | 0 | ZeroArray0_Field13 |
| this | 0x500 | RW | 0 | ZeroArray0_Field14 |
| this | 0x504 | RW | 0 | ZeroArray0_Field15 |
| this | 0x508 | RW | 0 | ZeroArray0_Field16 |
| this | 0x50C | RW | 0 | ZeroArray0_Field17 |
| this | 0x510 | RW | 0 | ZeroArray0_Field18 |
| this | 0x514 | RW | 0 | ZeroArray0_Field19 |
| this | 0x518 | RW | 0 | ZeroArray0_Field20 |
| this | 0x51C | RW | 0 | ZeroArray0_Field21 |
| this | 0x520 | RW | 0 | ZeroArray0_Field22 |
| this | 0x524 | RW | 0 | ZeroArray0_Field23 |
| this | 0x528 | RW | 0 | ZeroArray0_Field24 |
| this | 0x52C | RW | 0 | ZeroArray0_Field25 |
| this | 0x530 | RW | 0 | ZeroArray0_Field26 |
| this | 0x534 | RW | 0 | ZeroArray0_Field27 |
| this | 0x548 | RW | 0 | ByteFieldInit0 (zeroed byte) |
| this | 0x549 | RW | 1 | ByteFlag1 (set to 1) |
| this | 0x54A | RW | 1 | ByteFlag2 (set to 1) |
| this | 0x54C | RW | 0 | ZeroFieldA |
| this | 0x550 | RW | 0 | ZeroFieldB |
| this | 0x554 | RW | 0 | ZeroFieldC |
| this | 0x558 | RW | 0 | ZeroFieldD |
| this | 0x55C | RW | 0 | ZeroFieldE |
| this | 0x560 | RW | 0 | ZeroFieldF |
| this | 0x564 | RW | 0 | ZeroFieldG |
| this | 0x568 | RW | 0 | ZeroFieldH |
| this | 0x56C | RW | 0 | ZeroFieldI |
| this | 0x570 | RW | 0 | ZeroFieldJ |
| this | 0x574 | RW | 0 | ZeroFieldK |
| this | 0x578 | RW | 0 | ZeroFieldL |
| this | 0x57C | RW | 0 | ZeroFieldM |
| this | 0x580 | RW | 0 | ZeroFieldN |
| this | 0x584 | W | 0 | OutputField0 (write-only block, zeroed) |
| this | 0x588 | W | 0 | OutputField1 |
| this | 0x58C | W | 0 | OutputField2 |
| this | 0x590 | W | 0 | OutputField3 |
| this | 0x594 | W | 0 | OutputField4 |
| this | 0x598 | W | 0 | OutputField5 |
| this | 0x59C | W | 0 | OutputField6 |
| this | 0x620 | W | 18446744072678759465 → -71.68f | TireCompoundParam0_A (negative coefficient pair A) |
| this | 0x624 | W | 1071917301 → 1.7825f | TireCompoundParam0_B (coefficient pair B) |
| this | 0x628 | W | 18446744072678759465 → -71.68f | TireCompoundParam1_A |
| this | 0x62C | W | 1071917301 → 1.7825f | TireCompoundParam1_B |
| this | 0x630 | W | 0 | TireCompoundParam2_A (zero) |
| this | 0x634 | W | 1072693248 → 1.875f | TireCompoundParam2_B |
| this | 0x638 | W | 18446744071991564698 | TireCompoundParam3_A (negative coefficient) |
| this | 0x63C | W | 1070176665 → 1.575f | TireCompoundParam3_B |
| this | 0x640 | W | 858993459 | TireCompoundParam3_C (bit pattern) |
| this | 0x644 | W | 1070805811 → 1.65f | TireCompoundParam3_D |
| this | 0x648 | W | 18446744072850558157 → -107374184.0f | TireCompoundParam3_E (large negative) |
| this | 0x64C | W | 1072483532 → 1.85f | TireCompoundParam3_F |
| this | 0x650 | W | 1 | TireCompoundFlag0 |
| this | 0x654 | W | 0 | TireCompoundReserved0 |
| this | 0x658 | W | 1072693248 → 1.875f | TireCompoundParam4_B |
| this | 0x65C | W | 18446744071991564698 | TireCompoundParam4_A |
| this | 0x660 | W | 1070176665 → 1.575f | TireCompoundParam4_C |
| this | 0x664 | W | 858993459 | TireCompoundParam4_D |
| this | 0x668 | W | 1070805811 → 1.65f | TireCompoundParam4_E |
| this | 0x66C | W | 18446744072850558157 → -107374184.0f | TireCompoundParam4_F |
| this | 0x670 | W | 1072483532 → 1.85f | TireCompoundParam4_G |
| this | 0x674 | W | 2096768674 | TireWearParamA (bit pattern constant) |
| this | 0x678 | W | 1057427860 → 0.5276f | TireWearParamB |
| this | 0x67C | W | 0 | TireWearReserved0 |
| this | 0x680 | W | 1072693248 → 1.875f | TireWearParamC |
| this | 0x69C | W | 0 | TireCompoundSlot0_ParamA |
| this | 0x6A0 | W | 1072693248 → 1.875f | TireCompoundSlot0_ParamB |
| this | 0x6A4 | W | 0 | TireCompoundSlot0_Zero0 |
| this | 0x6A8 | W | 0 | TireCompoundSlot0_Zero1 |
| this | 0x6AC | W | 0 | TireCompoundSlot0_Zero2 |
| this | 0x6B0 | W | 1081262080 → 3.793f | TireCompoundSlot0_GripCoeff |
| this | 0x6B4 | W | 0 | TireCompoundSlot0_Zero3 |
| this | 0x6B8 | W | 1081671680 → 3.8906f | TireCompoundSlot0_WearCoeff |
| this | 0x6BC | W | 693450846 | TireCompoundSlot0_IntParam |
| this | 0x6C0 | W | 1076849274 → 2.7409f | TireCompoundSlot0_TempCoeff |
| this | 0x6C4 | RW | 0 | TireCompoundSlot0_Reserved (read-write zero) |
| this | 0x12C8 | W | 1546188227 | TireCompoundSlot1_GripParam (bit pattern) |
| this | 0x12CC | W | 1081561743 → 3.8644f | TireCompoundSlot1_GripCoeff |
| this | 0x12D0 | W | 0 | TireCompoundSlot1_Zero0 |
| this | 0x12D4 | W | 1079164928 → 3.293f | TireCompoundSlot1_WearCoeff |
| this | 0x12D8 | W | 432932703 | TireCompoundSlot1_IntParam |
| this | 0x12DC | W | 1062984273 → 0.8588f | TireCompoundSlot1_TempCoeffA |
| this | 0x12E0 | W | 18446744071792278215 | TireCompoundSlot1_NegParamA |
| this | 0x12E4 | W | 1061613574 → 0.7771f | TireCompoundSlot1_TempCoeffB |
| this | 0x12E8 | W | 34359738 | TireCompoundSlot1_IntParamB |
| this | 0x12EC | W | 1064732459 → 0.963f | TireCompoundSlot1_TempCoeffC |
| this | 0x12F0 | W | 18446744072035545163 | TireCompoundSlot1_NegParamB |
| this | 0x12F4 | W | 1057805817 → 0.5501f | TireCompoundSlot1_TempCoeffD |
| this | 0x12F8 | W | 18446744072953637372 → -518969491456.0f | TireCompoundSlot1_LargeNegParam |
| this | 0x12FC | W | 1063281229 → 0.8765f | TireCompoundSlot1_TempCoeffE |
| this | 0x1300 | W | 18446744072116634145 | TireCompoundSlot1_NegParamC |
| this | 0x1304 | W | 1061080394 → 0.7453f | TireCompoundSlot1_TempCoeffF |
| this | 0x1308 | W | 18446744071873367198 | TireCompoundSlot1_NegParamD |
| this | 0x130C | W | 1059645271 → 0.6598f | TireCompoundSlot1_TempCoeffG |
| this | 0x1310 | W | 0 | TireCompoundSlot1_Zero1 |
| this | 0x1314 | W | 1083922432 → 4.8545f | TireCompoundSlot1_PeakCoeff |
| this | 0x1318 | W | 0 | TireCompoundSlot1_Zero2 |
| this | 0x131C | W | 1078525952 → 3.1406f | TireCompoundSlot1_SlideCoeff |
| this | 0x1320 | W | 1546188227 | TireCompoundSlot2_GripParam (bit pattern) |
| this | 0x1324 | W | 1081643663 → 3.8839f | TireCompoundSlot2_GripCoeff |
| this | 0x1328 | W | 0 | TireCompoundSlot2_Zero0 |
| this | 0x132C | W | 1074790400 → 2.25f | TireCompoundSlot2_SlipCoeff |
| this | 0x1330 | W | 0 | TireCompoundSlot2_Zero1 |
| this | 0x1334 | W | 1086556160 → 6.1104f | TireCompoundSlot2_GripCoeff2 |
| this | 0x1338 | W | 0 | TireCompoundSlot2_Zero2 |
| this | 0x133C | W | 1085022208 → 5.3789f | TireCompoundSlot2_SlideCoeff |
| this | 0x1340 | W | 0 | TireCompoundSlot2_Zero3 |
| this | 0x1344 | W | 0 | TireCompoundSlot2_Zero4 |
| this | 0x1348 | W | 858993459 | TireCompoundSlot2_IntParam |
| this | 0x134C | W | 1071854387 → 1.775f | TireCompoundSlot2_FloatParam |
| this | 0x1350 | W | 0 | TireCompoundSlot2_Zero5 |
| this | 0x1354 | W | 0 | TireCompoundSlot2_Zero6 |
| this | 0x1358 | W | 1 | TireCompoundSlot2_ByteFlag |
| this | 0x135C | W | 1717986918 | TireCompoundSlot2_IntParamB |
| this | 0x1360 | W | 1073112678 → 1.925f | TireCompoundSlot2_FloatParamB |
| this | 0x1364 | W | 18446744071991564698 | TireCompoundSlot2_NegParam |
| this | 0x1368 | W | 1071225241 → 1.7f | TireCompoundSlot2_FloatParamC |
| this | 0x136C | W | 0 | TireCompoundSlot2_Zero7 |
| this | 0x1370 | W | 1073217536 → 1.9375f | TireCompoundSlot2_FloatParamD |
| this | 0x139C | W | 1 | WearModelFlag1 (byte flag) |
| this | 0x139D | W | 1 | WearModelFlag2 (byte flag) |
| this | 0x13A0 | W | 18446744071991564698 | WearModelNegCoeffA |
| this | 0x13A4 | W | 1069128089 → 1.45f | WearModelCoeffA |
| this | 0x13A8 | W | 18446744071991564698 | WearModelNegCoeffB |
| this | 0x13AC | W | 1070176665 → 1.575f | WearModelCoeffB |
| this | 0x13B0 | W | 18446744071991564698 | WearModelNegCoeffC |
| this | 0x13B4 | W | 1069128089 → 1.45f | WearModelCoeffC |
| this | 0x13B8 | W | 18446744071991564698 | WearModelNegCoeffD |
| this | 0x13BC | W | 1070176665 → 1.575f | WearModelCoeffD |
| this | 0x13C8 | RW | 0 | ConfigPathHandle (zeroed, then loaded via StringCopyWithBufferRealloc) |
| this | 0x13CC | RW | 1080623104 → 3.6406f | ConfigFloatParam |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x78: recalc every frame — external poke does NOT persist
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x80: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0xE0: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist
- this 0xE8: recalc every frame — external poke does NOT persist
- this 0xEC: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0xF4: recalc every frame — external poke does NOT persist
- this 0xF8: recalc every frame — external poke does NOT persist
- this 0xFC: recalc every frame — external poke does NOT persist
- this 0x100: recalc every frame — external poke does NOT persist
- this 0x104: recalc every frame — external poke does NOT persist
- this 0x108: recalc every frame — external poke does NOT persist
- this 0x10C: recalc every frame — external poke does NOT persist
- this 0x110: recalc every frame — external poke does NOT persist
- this 0x114: recalc every frame — external poke does NOT persist
- this 0x118: recalc every frame — external poke does NOT persist
- this 0x11C: recalc every frame — external poke does NOT persist
- this 0x120: recalc every frame — external poke does NOT persist
- this 0x124: recalc every frame — external poke does NOT persist
- this 0x128: recalc every frame — external poke does NOT persist
- this 0x1EC: recalc every frame — external poke does NOT persist
- this 0x1F0: recalc every frame — external poke does NOT persist
- this 0x1F4: recalc every frame — external poke does NOT persist
- this 0x1F8: recalc every frame — external poke does NOT persist
- this 0x1FC: recalc every frame — external poke does NOT persist
- this 0x200: recalc every frame — external poke does NOT persist
- this 0x204: recalc every frame — external poke does NOT persist
- this 0x208: recalc every frame — external poke does NOT persist
- this 0x20C: recalc every frame — external poke does NOT persist
- this 0x210: recalc every frame — external poke does NOT persist
- this 0x214: recalc every frame — external poke does NOT persist
- this 0x218: recalc every frame — external poke does NOT persist
- this 0x21C: recalc every frame — external poke does NOT persist
- this 0x220: recalc every frame — external poke does NOT persist
- this 0x224: recalc every frame — external poke does NOT persist
- this 0x228: recalc every frame — external poke does NOT persist
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x230: recalc every frame — external poke does NOT persist
- this 0x234: recalc every frame — external poke does NOT persist
- this 0x2E0: recalc every frame — external poke does NOT persist
- this 0x2E4: recalc every frame — external poke does NOT persist
- this 0x2E8: recalc every frame — external poke does NOT persist
- this 0x2EC: recalc every frame — external poke does NOT persist
- this 0x2F0: recalc every frame — external poke does NOT persist
- this 0x2F4: recalc every frame — external poke does NOT persist
- this 0x2F8: recalc every frame — external poke does NOT persist
- this 0x2FC: recalc every frame — external poke does NOT persist
- this 0x300: recalc every frame — external poke does NOT persist
- this 0x304: recalc every frame — external poke does NOT persist
- this 0x308: recalc every frame — external poke does NOT persist
- this 0x30C: recalc every frame — external poke does NOT persist
- this 0x310: recalc every frame — external poke does NOT persist
- this 0x314: recalc every frame — external poke does NOT persist
- this 0x318: recalc every frame — external poke does NOT persist
- this 0x31C: recalc every frame — external poke does NOT persist
- this 0x320: recalc every frame — external poke does NOT persist
- this 0x324: recalc every frame — external poke does NOT persist
- this 0x328: recalc every frame — external poke does NOT persist
- this 0x32C: recalc every frame — external poke does NOT persist
- this 0x330: recalc every frame — external poke does NOT persist
- this 0x3DC: recalc every frame — external poke does NOT persist
- this 0x3E0: recalc every frame — external poke does NOT persist
- this 0x3E4: recalc every frame — external poke does NOT persist
- this 0x3E8: recalc every frame — external poke does NOT persist
- this 0x3EC: recalc every frame — external poke does NOT persist
- this 0x3F0: recalc every frame — external poke does NOT persist
- this 0x3F4: recalc every frame — external poke does NOT persist
- this 0x3F8: recalc every frame — external poke does NOT persist
- this 0x3FC: recalc every frame — external poke does NOT persist
- this 0x400: recalc every frame — external poke does NOT persist
- this 0x404: recalc every frame — external poke does NOT persist
- this 0x408: recalc every frame — external poke does NOT persist
- this 0x40C: recalc every frame — external poke does NOT persist
- this 0x410: recalc every frame — external poke does NOT persist
- this 0x414: recalc every frame — external poke does NOT persist
- this 0x418: recalc every frame — external poke does NOT persist
- this 0x41C: recalc every frame — external poke does NOT persist
- this 0x420: recalc every frame — external poke does NOT persist
- this 0x424: recalc every frame — external poke does NOT persist
- this 0x428: recalc every frame — external poke does NOT persist
- this 0x4D4: recalc every frame — external poke does NOT persist
- this 0x4D8: recalc every frame — external poke does NOT persist
- this 0x4DC: recalc every frame — external poke does NOT persist
- this 0x4E0: recalc every frame — external poke does NOT persist
- this 0x4E4: recalc every frame — external poke does NOT persist
- this 0x4E8: recalc every frame — external poke does NOT persist
- this 0x4EC: recalc every frame — external poke does NOT persist
- this 0x4F0: recalc every frame — external poke does NOT persist
- this 0x4F4: recalc every frame — external poke does NOT persist
- this 0x4F8: recalc every frame — external poke does NOT persist
- this 0x4FC: recalc every frame — external poke does NOT persist
- this 0x500: recalc every frame — external poke does NOT persist
- this 0x504: recalc every frame — external poke does NOT persist
- this 0x508: recalc every frame — external poke does NOT persist
- this 0x50C: recalc every frame — external poke does NOT persist
- this 0x510: recalc every frame — external poke does NOT persist
- this 0x514: recalc every frame — external poke does NOT persist
- this 0x518: recalc every frame — external poke does NOT persist
- this 0x51C: recalc every frame — external poke does NOT persist
- this 0x520: recalc every frame — external poke does NOT persist
- this 0x524: recalc every frame — external poke does NOT persist
- this 0x528: recalc every frame — external poke does NOT persist
- this 0x52C: recalc every frame — external poke does NOT persist
- this 0x530: recalc every frame — external poke does NOT persist
- this 0x534: recalc every frame — external poke does NOT persist
- this 0x548: recalc every frame — external poke does NOT persist
- this 0x549: recalc every frame — external poke does NOT persist
- this 0x54A: recalc every frame — external poke does NOT persist
- this 0x54C: recalc every frame — external poke does NOT persist
- this 0x550: recalc every frame — external poke does NOT persist
- this 0x554: recalc every frame — external poke does NOT persist
- this 0x558: recalc every frame — external poke does NOT persist
- this 0x55C: recalc every frame — external poke does NOT persist
- this 0x560: recalc every frame — external poke does NOT persist
- this 0x564: recalc every frame — external poke does NOT persist
- this 0x568: recalc every frame — external poke does NOT persist
- this 0x56C: recalc every frame — external poke does NOT persist
- this 0x570: recalc every frame — external poke does NOT persist
- this 0x574: recalc every frame — external poke does NOT persist
- this 0x578: recalc every frame — external poke does NOT persist
- this 0x57C: recalc every frame — external poke does NOT persist
- this 0x580: recalc every frame — external poke does NOT persist
- this 0x584: recalc every frame — external poke does NOT persist
- this 0x588: recalc every frame — external poke does NOT persist
- this 0x58C: recalc every frame — external poke does NOT persist
- this 0x590: recalc every frame — external poke does NOT persist
- this 0x594: recalc every frame — external poke does NOT persist
- this 0x598: recalc every frame — external poke does NOT persist
- this 0x59C: recalc every frame — external poke does NOT persist
- this 0x620: recalc every frame — external poke does NOT persist
- this 0x624: recalc every frame — external poke does NOT persist
- this 0x628: recalc every frame — external poke does NOT persist
- this 0x62C: recalc every frame — external poke does NOT persist
- this 0x630: recalc every frame — external poke does NOT persist
- this 0x634: recalc every frame — external poke does NOT persist
- this 0x638: recalc every frame — external poke does NOT persist
- this 0x63C: recalc every frame — external poke does NOT persist
- this 0x640: recalc every frame — external poke does NOT persist
- this 0x644: recalc every frame — external poke does NOT persist
- this 0x648: recalc every frame — external poke does NOT persist
- this 0x64C: recalc every frame — external poke does NOT persist
- this 0x650: recalc every frame — external poke does NOT persist
- this 0x654: recalc every frame — external poke does NOT persist
- this 0x658: recalc every frame — external poke does NOT persist
- this 0x65C: recalc every frame — external poke does NOT persist
- this 0x660: recalc every frame — external poke does NOT persist
- this 0x664: recalc every frame — external poke does NOT persist
- this 0x668: recalc every frame — external poke does NOT persist
- this 0x66C: recalc every frame — external poke does NOT persist
- this 0x670: recalc every frame — external poke does NOT persist
- this 0x674: recalc every frame — external poke does NOT persist
- this 0x678: recalc every frame — external poke does NOT persist
- this 0x67C: recalc every frame — external poke does NOT persist
- this 0x680: recalc every frame — external poke does NOT persist
- this 0x69C: recalc every frame — external poke does NOT persist
- this 0x6A0: recalc every frame — external poke does NOT persist
- this 0x6A4: recalc every frame — external poke does NOT persist
- this 0x6A8: recalc every frame — external poke does NOT persist
- this 0x6AC: recalc every frame — external poke does NOT persist
- this 0x6B0: recalc every frame — external poke does NOT persist
- this 0x6B4: recalc every frame — external poke does NOT persist
- this 0x6B8: recalc every frame — external poke does NOT persist
- this 0x6BC: recalc every frame — external poke does NOT persist
- this 0x6C0: recalc every frame — external poke does NOT persist
- this 0x6C4: recalc every frame — external poke does NOT persist
- this 0x12C8: recalc every frame — external poke does NOT persist
- this 0x12CC: recalc every frame — external poke does NOT persist
- this 0x12D0: recalc every frame — external poke does NOT persist
- this 0x12D4: recalc every frame — external poke does NOT persist
- this 0x12D8: recalc every frame — external poke does NOT persist
- this 0x12DC: recalc every frame — external poke does NOT persist
- this 0x12E0: recalc every frame — external poke does NOT persist
- this 0x12E4: recalc every frame — external poke does NOT persist
- this 0x12E8: recalc every frame — external poke does NOT persist
- this 0x12EC: recalc every frame — external poke does NOT persist
- this 0x12F0: recalc every frame — external poke does NOT persist
- this 0x12F4: recalc every frame — external poke does NOT persist
- this 0x12F8: recalc every frame — external poke does NOT persist
- this 0x12FC: recalc every frame — external poke does NOT persist
- this 0x1300: recalc every frame — external poke does NOT persist
- this 0x1304: recalc every frame — external poke does NOT persist
- this 0x1308: recalc every frame — external poke does NOT persist
- this 0x130C: recalc every frame — external poke does NOT persist
- this 0x1310: recalc every frame — external poke does NOT persist
- this 0x1314: recalc every frame — external poke does NOT persist
- this 0x1318: recalc every frame — external poke does NOT persist
- this 0x131C: recalc every frame — external poke does NOT persist
- this 0x1320: recalc every frame — external poke does NOT persist
- this 0x1324: recalc every frame — external poke does NOT persist
- this 0x1328: recalc every frame — external poke does NOT persist
- this 0x132C: recalc every frame — external poke does NOT persist
- this 0x1330: recalc every frame — external poke does NOT persist
- this 0x1334: recalc every frame — external poke does NOT persist
- this 0x1338: recalc every frame — external poke does NOT persist
- this 0x133C: recalc every frame — external poke does NOT persist
- this 0x1340: recalc every frame — external poke does NOT persist
- this 0x1344: recalc every frame — external poke does NOT persist
- this 0x1348: recalc every frame — external poke does NOT persist
- this 0x134C: recalc every frame — external poke does NOT persist
- this 0x1350: recalc every frame — external poke does NOT persist
- this 0x1354: recalc every frame — external poke does NOT persist
- this 0x1358: recalc every frame — external poke does NOT persist
- this 0x135C: recalc every frame — external poke does NOT persist
- this 0x1360: recalc every frame — external poke does NOT persist
- this 0x1364: recalc every frame — external poke does NOT persist
- this 0x1368: recalc every frame — external poke does NOT persist
- this 0x136C: recalc every frame — external poke does NOT persist
- this 0x1370: recalc every frame — external poke does NOT persist
- this 0x139C: recalc every frame — external poke does NOT persist
- this 0x139D: recalc every frame — external poke does NOT persist
- this 0x13A0: recalc every frame — external poke does NOT persist
- this 0x13A4: recalc every frame — external poke does NOT persist
- this 0x13A8: recalc every frame — external poke does NOT persist
- this 0x13AC: recalc every frame — external poke does NOT persist
- this 0x13B0: recalc every frame — external poke does NOT persist
- this 0x13B4: recalc every frame — external poke does NOT persist
- this 0x13B8: recalc every frame — external poke does NOT persist
- this 0x13BC: recalc every frame — external poke does NOT persist
- this 0x13C8: recalc every frame — external poke does NOT persist
- this 0x13CC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f2430 | ConstructorZeroInitSubCalls | Call sub-object constructors with zero-init for nested struct at this+1532 |
| 004f2b10 | ZeroInit16ElementArray | Zero-initialize 16-element array blocks (used for two arrays at this+360 and this+376) |
| 004f2b50 | PhysicsDefaultsInitializer | Initialize a per-compound physics defaults block (called 4 times in loop) |
| 004f3040 | ZeroInit | Zero-initialize a block of struct memory |
| 004f31f0 | sub_4F31F0 | Initialize sub-structure fields (called for 3 sub-structs at this+142, this+205, this+267) |
| 00566650 | StringCopyWithBufferRealloc | Copy configuration file path string with buffer reallocation |

**Guard conditions:** No guard conditions — pure initialization function, always executes to completion.
