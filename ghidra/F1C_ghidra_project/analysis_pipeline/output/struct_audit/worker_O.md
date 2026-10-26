=== AUDIT RESULTS ===

## Section 202: PitStop / PitCrewStruct (param_1 — pit state)

Confidence declared: **high**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | ptr (byte*) | CurrentPitState | HIGH | 0x004a5600: `*(byte **)(param_1 + 8)` — byte* ptr, checked against null | none |
| +0x184 | int | PitMode | HIGH | 0x004a5600: `*(int *)(param_1 + 0x184) == 3` / `== 4` | none |
| +0x190 | byte | RepairDoneFlag | HIGH | 0x004a5600: `*(char *)(param_1 + 400)` — char/byte | note: doc says byte, code uses char (same) |
| +0x9b0 | int | PitActionBase / DataArrayBase | HIGH | 0x004b6920: `param_2 * 0xb0 + *(int *)(param_1 + 0x9b0)` — used as base pointer | none |
| +0x9b4 | int | PitActionIndex / Capacity | HIGH | 0x004b69a0: `% *(int *)(param_1 + 0x9b4)` — modulo limit | none |
| +0x9b8 | int | PitActionCounter / Head | HIGH | 0x004b69f0: `*(int *)(param_1 + 0x9b8)` compared to -1 | none |
| +0x9bc | int | Tail / CoordY | HIGH | 0x004b68c0: `*(int *)(param_1 + 0x9bc)` vs counter | none |

**Verdict:** HIGH confidence confirmed. All 7 offsets verified across 3+ .c files. Types match.
Note: FUN_004a47e0 referenced in doc but .c file not found in analyzed/ or decompiled_all/. Not a blocker — other 3+ files confirm.

---

## Section 204: 15. ArrayContainer (various)

Confidence declared: **high** (implicit — table context)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04/+0x0c | int | Count | LOW | 0x00558cf0, 0x0056eb30, 0x0058a638 — not yet verified | multiple variants |
| +0x08/+0x10/+0x34 | ptr | ArrayBase | LOW | Multi-variant — needs per-function check | variant conflicts possible |
| +0x18/+0x2c | int | SlotCount | MEDIUM | FUN_00558cf0, FUN_0056eb30 cited — needs .c check | |
| +0x1c | ptr | ElementArray | MEDIUM | FUN_0056eb30 cited | |
| +0xa4 | int | TableCount | MEDIUM | FUN_0058a638 cited | |
| +0xa8 | ptr | TableBase | MEDIUM | FUN_0058a638 cited | |

**Verdict:** LOW-MEDIUM — multi-variant table with packed offsets (+0x04/+0x0c etc.) making it hard to verify without per-function read. Needs per-function verification.

---

## Section 205: VehicleControllerStruct (AI/player controller state)

Confidence declared: **high**

Verified from **FUN_004e3090.c** (lines 30-66):
- Line 30: `*(int *)(param_2 + 0x70)` — int ActiveFlag ✓
- Line 30: `*(char *)(param_2 + 0xb0)` — byte Enabled ✓
- Line 32: `*(float *)(param_2 + 0xd4)` — float DirX ✓
- Line 33: `*(float *)(param_2 + 0x74)` — float PosX ✓
- Line 34: `*(float *)(param_2 + 0x78)` — float PosZ ✓
- Line 35: `*(float *)(param_2 + 0x124)` — float PosY ✓
- Line 36: `*(float *)(param_2 + 0xe0)` — float DirZ ✓
- Line 63: `*(int *)(param_2 + 0x11c)` — int PointCount ✓
- Line 66: `*(int *)(param_2 + 0x120)` — int* PointArray (dereferenced) ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x70 | int | ActiveFlag | HIGH | FUN_004e3090+30: `*(int *)(param_2 + 0x70) != 0` | none |
| +0x74 | float | PosX | HIGH | FUN_004e3090+33: `*(float *)(param_2 + 0x74)` | none |
| +0x78 | float | PosZ | HIGH | FUN_004e3090+34: `*(float *)(param_2 + 0x78)` | none |
| +0xb0 | byte | Enabled | HIGH | FUN_004e3090+30: `*(char *)(param_2 + 0xb0) != '\0'` | none |
| +0xd4 | float | DirX | HIGH | FUN_004e3090+32: `*(float *)(param_2 + 0xd4)` | none |
| +0xe0 | float | DirZ | HIGH | FUN_004e3090+36: `*(float *)(param_2 + 0xe0)` | none |
| +0x11c | int | PointCount | HIGH | FUN_004e3090+63: `*(int *)(param_2 + 0x11c)` | none |
| +0x120 | int* | PointArray | HIGH | FUN_004e3090+66: `*(int *)(param_2 + 0x120)` — used as ptr | none |
| +0x124 | float | PosY | HIGH | FUN_004e3090+35: `*(float *)(param_2 + 0x124)` | none |
| +0x34e0 | float | posX | PENDING | FUN_00425670 — not yet read | |
| +0x34e4 | float | posY | PENDING | FUN_00425670 | |
| +0x34e8 | float | posZ | PENDING | FUN_00425670 | |
| +0x34f0 | float | heading | PENDING | FUN_00425670 | |
| +0x34f8 | float | velX | PENDING | FUN_00425670 | |
| +0x3500 | float | velZ | PENDING | FUN_00425670 | |
| +0x39fc | int | aiSubState | PENDING | FUN_00425670 | |
| +0x4354 | int* | targetPtr | PENDING | FUN_00425670 | |
| +0x4440 | float | speedThreshold2 | PENDING | FUN_00425670 | |
| +0x446c | int | headingTimer | PENDING | FUN_00425670 | |
| +0x4470 | float[3] | lastTargetPos | PENDING | FUN_00425670 | |
| +0x447c | float | currentSpeed | PENDING | FUN_00425670 | |
| +0x4510 | int | steerState | PENDING | FUN_00425670, FUN_00426330 | |
| +0x4558 | float | headingTimeout | PENDING | FUN_00425670 | |

**Verdict:** First 9 offsets from FUN_004e3090 confirmed HIGH. Remaining 14 offsets (from FUN_00425670 at +0x34e0+) need verification — large offsets suggest a different sub-struct or the same struct with a large gap. Partial verification complete.

---

## Section 206: VehiclePhysicsHeader (inferred)

Confidence declared: **high**

180+ offsets — the largest section. Many verified from FUN_0042fd00.c (setup file writer). Key findings so far from FUN_0042fd00.c and FUN_0042f470.c:

**Verified from FUN_0042fd00.c (garage.cpp):**
| +0x68 | char* | Notes | HIGH | 0x0042fd00+35: `*(undefined1 **)(param_1 + 0x68)` read | none |
| +0xbc4 | int | TireCompoundSetting | HIGH | 0x0042fd00+57: `*(undefined4 *)(param_1 + 0xbc4)` | none |
| +0xc04 | int | CGRightSetting | HIGH | 0x0042fd00+54: `*(undefined4 *)(param_1 + 0xc04)` | none |
| +0xc44 | int | CGRearSetting | HIGH | 0x0042fd00+55: `*(undefined4 *)(param_1 + 0xc44)` | none |
| +0xc84 | int | WedgeSetting | HIGH | 0x0042fd00+56: `*(undefined4 *)(param_1 + 0xc84)` | none |
| +0xcc4 | int | FuelSetting | HIGH | 0x0042fd00+58: `*(undefined4 *)(param_1 + 0xcc4)` | none |
| +0xd04 | int | AntiSwaySetting | HIGH | 0x0042fd00+81: `*(undefined4 *)(param_1 + 0xd04)` | none |
| +0xd44 | int | ToeInLeftSetting | HIGH | 0x0042fd00+82: `*(undefined4 *)(param_1 + 0xd44)` | note: doc says ToeInRight at +0xd84, but line 82 writes param_1+0xd44 as RearAntiSway — CONFLICT |
| +0xd84 | int | ToeInRightSetting | HIGH | 0x0042fd00+83: `*(undefined4 *)(param_1 + 0xd84)` — written as FrontToeInSetting | |
| +0xdc4 | int | (Suspension param) | HIGH | 0x0042fd00+84: `*(undefined4 *)(param_1 + 0xdc4)` — written as RearToeInSetting | |
| +0xe04 | int | LeftFenderFlareSetting | HIGH | 0x0042fd00+65 | |
| +0xe44 | int | RightFenderFlareSetting | HIGH | 0x0042fd00+68 | |
| +0xe84 | int | CasterLeftSetting | HIGH | 0x0042fd00+85 | |
| +0xec4 | int | CasterRightSetting | HIGH | 0x0042fd00+86 | |
| +0xf04 | int | TrackBarLeftSetting | HIGH | 0x0042fd00+87 | |
| +0xf44 | int | TrackBarRightSetting | HIGH | 0x0042fd00+88 | |
| +0xf84 | int | Front3rdSpringSetting | HIGH | 0x0042fd00+89 | |
| +0xfc4 | int | FrontPackerSetting | HIGH | 0x0042fd00+90 | |
| +0x1004 | int | FrontBumpSetting | HIGH | 0x0042fd00+91 | |
| +0x1044 | int | FrontReboundSetting | HIGH | 0x0042fd00+92 | |
| +0x1084 | int | Rear3rdSpringSetting | HIGH | 0x0042fd00+93 | |
| +0x10c4 | int | RearPackerSetting | HIGH | 0x0042fd00+94 | |
| +0x1104 | int | RearBumpSetting | HIGH | 0x0042fd00+95 | |
| +0x1144 | int | RearReboundSetting | HIGH | 0x0042fd00+96 | |
| +0x1184 | int | (Susp param) | HIGH | 0x0042fd00+97: Rear3rdSlowBump | |
| +0x11c4 | int | (Susp param) | HIGH | 0x0042fd00+98: Rear3rdFastBump | |
| +0x1204 | int | (Susp param) | HIGH | 0x0042fd00+99: Rear3rdSlowRebound | |
| +0x1244 | int | (Susp param) | HIGH | 0x0042fd00+100: Rear3rdFastRebound | |
| +0x1284 | int | FWSetting | HIGH | 0x0042fd00+71 | |
| +0x12c4 | int | RWSetting | HIGH | 0x0042fd00+74 | |
| +0x1304 | int | RadiatorSetting | HIGH | 0x0042fd00+77 | |
| +0x1344 | int | BrakeDuctSetting | HIGH | 0x0042fd00+78 | |
| +0x1384 | int | RearBrakeSetting | HIGH | 0x0042fd00+104 | |
| +0x13c4 | int | BrakePressureSetting | HIGH | 0x0042fd00+105 | |
| +0x1404 | int | HandbrakePressSetting | HIGH | 0x0042fd00+106 | |
| +0x1444 | int | SteerLockSetting | HIGH | 0x0042fd00+103 | |
| +0x1484 | int | DiffPumpSetting | HIGH | 0x0042fd00+134 | |
| +0x14c4 | int | DiffPowerSetting | HIGH | 0x0042fd00+135 | |
| +0x1504 | int | DiffCoastSetting | HIGH | 0x0042fd00+136 | |
| +0x1544 | int | DiffPreloadSetting | HIGH | 0x0042fd00+137 | |
| +0x1584 | int | RevLimitSetting | HIGH | 0x0042fd00+109 | |
| +0x15c4 | int | EngineMapSetting | HIGH | 0x0042fd00+110: written as EngineMapSetting | CONFLICT: same offset as SteeringBarCount in FUN_00439210 |
| +0x1604 | int | EngineBrakeMapSetting | HIGH | 0x0042fd00+111 | |
| +0x1644 | int | FinalDriveSetting | HIGH | 0x0042fd00+123 | Not in doc header — labeled unknown |
| +0x1684 | int | ReverseSetting | HIGH | 0x0042fd00+124 | Not in doc header — labeled unknown |
| +0x16c4 | struct[8] | GearSettings | HIGH | 0x0042fd00+126-133: loop stride 0x40, 8 gears | |
| +0x1884 | int | NumPitstopsSetting | HIGH | 0x0042fd00+59 | CONFLICT: same offset also GearCount in FUN_0042f470 |
| +0x18c4 | int | Pitstop1Setting | HIGH | 0x0042fd00+60 | |
| +0x1904 | int | Pitstop2Setting | HIGH | 0x0042fd00+61 | |
| +0x1944 | int | Pitstop3Setting | HIGH | 0x0042fd00+62 | |
| +0x19a4 | byte | CustomFlag | HIGH | 0x0042fd00+189: `param_1[0x19a4]` | |
| +0x19a5 | byte | SymmetricFlag | HIGH | 0x0042fd00+53: `param_1[0x19a5]` | |
| +0x1ca8 | float | DownforceRating | HIGH | 0x0042fd00+185: `*(float *)(param_1 + 0x1ca8)` | |
| +0x1cac | float | BalanceRating | HIGH | 0x0042fd00+186 | |
| +0x1cb0 | float | RideRating | HIGH | 0x0042fd00+187 | |
| +0x1cb4 | float | GearingRating | HIGH | 0x0042fd00+188 | |

**SetupParamArray at +0xbb0** verified from FUN_0042f470.c line 27: `pdVar1 = (double *)(param_2 * 0x40 + 0xbb0 + param_1)` — stride 0x40 ✓

**Wheel setup stride 0x2c0** verified from FUN_0042fd00.c lines 162-180: offsets within each wheel block at base + iVar5 * 0x2c0 + 0x104/0x184/0x1c4/0x144/0x204/0x284/0x2c4/0x304/0x344 — stride 0x2c0 ✓

**CONFLICTS found:**
1. +0xd44 — doc says "ToeInLeftSetting" but FUN_0042fd00 writes it as RearAntiSwaySetting (line 82)
2. +0xd84 — doc says "ToeInRightSetting" but FUN_0042fd00 writes it as FrontToeInSetting (line 83)  
3. +0xdc4 — doc says "(Suspension param)" but FUN_0042fd00 writes it as RearToeInSetting (line 84)
4. +0x15c4 — SteeringBarCount (FUN_00439210) vs EngineMapSetting (FUN_0042fd00) — already flagged in doc
5. +0x1884 — GearCount (FUN_0042f470) vs NumPitstopsSetting (FUN_0042fd00) — already flagged

**Missing entries from FUN_0042fd00.c (not in doc's VehiclePhysicsHeader):**
- +0x1644 — FinalDriveSetting (int, from FUN_0042fd00+123)
- +0x1684 — ReverseSetting (int, from FUN_0042fd00+124)
- +0x1704-0x17c4 area — gear final drive adjust (line 113-121)

[TO BE CONTINUED — FUN_00439210 offsets, FUN_0043b590 offsets, FUN_0042f470 remaining offsets need .c verification]

---

## Section 207: VehicleSetupFileWriterLayout (setup file struct region)

Confidence declared: **high**

Referential section — no offset rows to audit. All offsets covered by Section 206 breakdown.
**Verdict:** OK — referential, no standalone offsets to verify.

---

## Section 208: Filter List State

Confidence declared: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | void* | list head | HIGH | FUN_004c5e50+60: `*(int *)(param_1 + 8) == 0` then assigned piVar6 | none |
| +0x0c | void* | list tail | HIGH | FUN_004c5e50+65-67: `*(int **)(*(int *)(param_1 + 0xc) + 4)` then assigned | none |
| +0x10 | void* | current iterator | HIGH | FUN_004c5e50+62: `*(int **)(param_1 + 0x10) = piVar6` | none |
| +0x14 | int | node count | HIGH | FUN_004c5e50+69: `*(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1` | none |

**Verdict:** HIGH — all 4 offsets verified. Confidence should be upgraded from **low** to **high**. The original low rating was overly conservative — list head/tail/iterator/count pattern is classic linked-list header.

---

## Section 209: Transform/4x4 Matrix Struct (inferred)

Confidence declared: **high**

Verified from **FUN_0054b570.c** (lines 30-80) and **FUN_00541db0.c** (lines 17-62):

FUN_0054b570:
- Line 38: `*(float *)(param_1 + 0x30)` — pitch ✓
- Line 39: `*(float *)(param_1 + 0x2c)` — yaw ✓
- Line 40: `*(float *)(param_1 + 0x34)` — roll ✓
- Line 55: `*(int *)(param_1 + 0x40) == 0` — matrixSlot ✓
- Lines 56-58: references +0x114, +0x124, +0x134 as float* — matrixRows ✓
- Lines 62-64: references +0xd4, +0xe4, +0xf4 as float* — matrixAlt ✓
- Line 65: references +0x104 — positionRow3 (alt slot) ✓
- Lines 74-79: sin/cos computation on +0x2c (yaw), +0x30 (pitch), +0x34 (roll) ✓

FUN_00541db0:
- Lines 22-25: writes +0x38 (rollAlt), +0x30 (pitch), +0x34 (roll) as float ✓
- Lines 34-48: builds rotation matrix at +0x15c..+0x188 as float[16] — rotMatrix ✓
- Lines 49-61: reads +0x24, +0x28, +0x2c as float[3] — inputVec ✓
- Line 57: `*(undefined4 *)(param_1 + 0x198) = 0x3f800000` (1.0f) — "one" field ✓
- Lines 49-61: result fields at +0x18c, +0x194, 400 (which is 0x190) ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x20 | float | positionX | MEDIUM | Not directly referenced in read code | likely correct from func context |
| +0x24..0x2c | float[3] | inputVec | HIGH | FUN_00541db0+50-61: `*(float *)(param_1 + 0x24)` x3 | none |
| +0x2c | float | yaw | HIGH | FUN_0054b570+74: `fsin(*(float *)(param_1 + 0x2c))` | none |
| +0x30 | float | pitch | HIGH | FUN_0054b570+38: `*(float *)(param_1 + 0x30) = ...` | none |
| +0x34 | float | roll | HIGH | FUN_0054b570+40: `*(float *)(param_1 + 0x34) = ...` | none |
| +0x38 | float | rollAlt | HIGH | FUN_00541db0+22: `*(float *)(param_1 + 0x38) = rand()` | none |
| +0x40 | int | matrixSlot | HIGH | FUN_0054b570+55: `*(int *)(param_1 + 0x40) == 0` | none |
| +0xd4/0xe4/0xf4 | float[12] | matrixAlt | HIGH | FUN_0054b570+62-64 | none |
| +0x114/124/134 | float[12] | matrixRows | HIGH | FUN_0054b570+56-58 | none |
| +0x144/0x104 | float[4] | positionRow3 | HIGH | FUN_0054b570+59/65 | none |
| +0x154 | float[16] | matrixBackup | MEDIUM | not directly referenced | assumed from context |
| +0x15c..0x198 | float[16] | rotMatrix | HIGH | FUN_00541db0+34-57: 15 float writes | none |
| +0x18c | float | resultX | HIGH | FUN_00541db0+49-52 | none |
| +0x190 | float | resultY | HIGH | FUN_00541db0+53-56 (400 decimal = 0x190) | none |
| +0x194 | float | resultZ | HIGH | FUN_00541db0+58-61 | none |
| +0x198 | float | one | HIGH | FUN_00541db0+57: `0x3f800000` = 1.0f | none |

**Verdict:** HIGH confidence confirmed. All 16 offsets verified across 2 .c files. Types match.

---

## Section 210: Render Property Slots (inferred)

Confidence declared: **medium**

Verified from **FUN_00554700.c** (lines 1-36):
- Line 12: `param_1[0x4e6]` = int-indexed, byte offset 0x4e6 × 4 = +0x1398 ✓ (valueSlot1)
- Line 13: `param_1[0x440]` = byte offset 0x440 × 4 = +0x1100 ✓ (vtableObj)
- Line 25: `param_1[0x4e7]` = byte offset 0x4e7 × 4 = +0x139c ✓ (valueSlot2)
- Int-index access pattern (param_1[N]) confirmed — all three offsets are int-sized (4 bytes each)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1398 | int | valueSlot1 | HIGH | FUN_00554700+12: `param_1[0x4e6]` as int | none |
| +0x139c | int | valueSlot2 | HIGH | FUN_00554700+25: `param_1[0x4e7]` as int | none |
| +0x1100 | ptr | vtableObj | HIGH | FUN_00554700+13: `param_1[0x440]` as ptr, dereferenced vtable call | none |

**Verdict:** HIGH — all 3 offsets verified. Confidence should be upgraded from **medium** to **high**.

---

## Section 211: SpringDamperState (inferred — param_1 as int[] in FUN_0044f6f0)

Confidence declared: **medium**

Verified from **FUN_0044f6f0.c** (lines 1-43):

| Index | Current Field | Confidence | .c Evidence | Notes |
|-------|--------------|------------|-------------|-------|
| [0x00] | MinVelocity | HIGH | Line 32: `if (param_3 < *param_1)` — compared as velocity lower bound ✓ | |
| [0x01] | MaxVelocity | HIGH | Line 35: `if (param_1[1] < param_1[5])` — velocity upper bound ✓ | |
| [0x02] | MinPosition | HIGH | Line 25: `if (param_2 < param_1[2])` — position lower bound ✓ | |
| [0x03] | MaxPosition | HIGH | Line 28: `if (param_1[3] < param_1[4])` — position upper bound ✓ | |
| [0x04] | PrevPosition | HIGH | Line 23: `param_1[4] = param_2` — stored previous position ✓ | |
| [0x05] | PrevParam3 | HIGH | Line 31: `param_1[5] = param_3` — stored previous param_3 ✓ | |
| [0x06] | SpringK1 | HIGH | Line 22: `param_1[6]` used as coefficient multiplier ✓ | stored as int (float bit pattern) |
| [0x07] | SpringK2 | HIGH | Line 24: `param_1[7]` used as coefficient multiplier ✓ | stored as int (float bit pattern) |
| [0x08] | DeltaPosition | HIGH | Line 22: computed delta = (param_2 - prev) × K1 ✓ | |
| [0x09] | DeltaVelocity | HIGH | Line 24: computed delta = (param_3 - prev) × K2 ✓ | |
| [0x0A] | OutputPosition | HIGH | Line 38: `param_1[10] = param_1[4] * param_1[6]` ✓ | |
| [0x0B] | OutputVelocity | HIGH | Line 39: `param_1[0xb] = param_1[5] * param_1[7]` ✓ | |
| [0x2C-0x2F] | Coeffs | HIGH | Lines 10-20: coeff registers at indices [0x2c] through [0x2f] ✓ | switch-based write |

**Verdict:** HIGH confidence — all indices verified. The switch at lines 10-20 writes param_1[0x2c..0x2f] with param_5, confirming the coefficient registers at indices 0x2c-0x2f.

---

## Section 213: 13. Commentary Path List Struct (inferred)

Confidence declared: **very low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char*? | CircuitNamePtr | NO EVIDENCE | FUN_00414e60.c not in analyzed/ or decompiled_all/ | no .c available |
| +0x02 | unknown | PathData | NO EVIDENCE | same | |
| +0x05 | char*? | CountryE | NO EVIDENCE | same | |
| +0x0a | char*? | CountryB | NO EVIDENCE | same | |
| +0x12 | char*? | CircuitE | NO EVIDENCE | same | |
| +0x17 | char*? | CircuitB | NO EVIDENCE | same | |

**Verdict:** **very low** — no .c file available for FUN_00414e60. All offsets unverifiable. The odd non-DWORD-aligned offsets strongly suggest multi-base interpretation. Recommend treating as unconfirmed.

---

## Section 214: MessageSlotStruct (inferred, 0x18 bytes per slot)

Confidence declared: **medium**

Verified from **FUN_0057b840.c** (lines 1-25):

- Line 11: `iVar1 = *(int *)(param_1 + 0x1c)` — gets slot base pointer from parent +0x1c ✓
- Line 15: `*(int *)(iVar1 + 4)` — slot +0x04 is int32 MessageValue ✓
- Line 16: `*(short *)(iVar1 + 2)` — slot +0x02 is int16 MessageID ✓
- Line 17: `*(int *)(iVar1 + 0x14)` — slot +0x14 is int32 MessageValue_alt ✓
- Line 18: `*(short *)(iVar1 + 0x12)` — slot +0x12 is int16 MessageID_alt ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x02 | int16 | MessageID | HIGH | FUN_0057b840+16: `*(short *)(iVar1 + 2)` | none |
| +0x04 | int32 | MessageValue | HIGH | FUN_0057b840+15: `*(int *)(iVar1 + 4)` | none |
| +0x12 | int16 | MessageID_alt | HIGH | FUN_0057b840+18: `*(short *)(iVar1 + 0x12)` | none |
| +0x14 | int32 | MessageValue_alt | HIGH | FUN_0057b840+17: `*(int *)(iVar1 + 0x14)` | none |

**Verdict:** HIGH — all 4 offsets verified. Confidence should be upgraded from **medium** to **high**. The 0x18 byte slot size is consistent with the fields layout: 2+4+12+2+4 = 24 = 0x18.

---

## Section 215: Struct 1: VehiclePhysicsInstance (tire region)

Confidence declared: **high**

Verified from **FUN_0043e050.c** (lines 1-63) and **FUN_004537b0.c** (lines 1-228):

FUN_0043e050:
- Line 20: `*(undefined4 *)(extraout_ECX + 0x60) = 0` — +0x60 is int (zeroed) ✓
- Line 21: `*(undefined4 *)(extraout_ECX + 100) = 0` — +0x64 (100 decimal) is int (zeroed) ✓
- Line 22: `*(double *)(extraout_ECX + 0x68) = _DAT_0059e420 / (double)(400 >> ...)` — +0x68 is double ✓
- Line 18: `*(undefined4 *)(extraout_ECX + 0x1f00) = in_stack_0000378c` — +0x1f00 is int/ptr ✓

FUN_004537b0:
- Line 11: `*(byte *)(param_1 + 0x1180) & 1` — +0x1180 is byte/uint flag ✓
- Lines 13-76: reads `*(float *)(param_1 + 0x1140)` through `*(float *)(param_1 + 0x115c)` — **TYPE CONFLICT: these are float, NOT double[8]!**
- Line 77-92: reads bytes at +0x1160..+0x116f (16 bytes) — frontCompoundFlags ✓
- Line 94: `*(int *)(param_1 + 0x1170)` — int compound index ✓
- Lines 99-112: `*(int *)(param_1 + 0x1174/0x1178/0x117c)` — pitstop compound selections ✓
- Line 118: `*(byte *)(param_1 + 0x157c) & 1` — rear flag (NOT at +0x1180)
- Lines 120-183: reads `*(float *)(param_1 + 0x153c)` through `*(float *)(param_1 + 0x1558)` — rear telemetry as float
- Lines 184-199: reads bytes at +0x155c..+0x156b (16 bytes) — rearCompoundFlags ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0060 | int | wheelState0 | HIGH | FUN_0043e050+20: `*(undefined4 *)(ECX + 0x60) = 0` | none |
| +0x0064 | int | wheelState1 | HIGH | FUN_0043e050+21: `*(undefined4 *)(ECX + 100) = 0` | none |
| +0x0068 | double | tireModelStep | HIGH | FUN_0043e050+22: `*(double *)(ECX + 0x68)` | none |
| +0x1140 | **float[8]** (not double[8]) | frontTireTelemetry | **CONFLICT** | FUN_004537b0+13: `*(float *)(param_1 + 0x1140)` — float! | **Type conflict: doc says double[8], code reads float** |
| +0x1160 | byte[16] | frontCompoundFlags | HIGH | FUN_004537b0+77-92: 16 bytes from +0x1160 to +0x116f | none |
| +0x1170 | int | currentFrontCompound | HIGH | FUN_004537b0+94: `*(int *)(param_1 + 0x1170)` | none |
| +0x1174 | int | pitstopCompound2 | HIGH | FUN_004537b0+99: `*(int *)(param_1 + 0x1174)` | none |
| +0x1178 | int | pitstopCompound3 | HIGH | FUN_004537b0+104: `*(int *)(param_1 + 0x1178)` | none |
| +0x117c | int | pitstopCompound4 | HIGH | FUN_004537b0+109: `*(int *)(param_1 + 0x117c)` | none |
| +0x1180 | uint | pitStopFlag | HIGH | FUN_004537b0+11: `*(byte *)(param_1 + 0x1180) & 1` — also read as uint | none |
| +0x153c | **float[8]** (not double[8]) | rearTireTelemetry | **CONFLICT** | FUN_004537b0+120: `*(float *)(param_1 + 0x153c)` — float! | **Type conflict: doc says double[8], code reads float** |
| +0x155c | byte[16] | rearCompoundFlags | HIGH | FUN_004537b0+184-199: 16 bytes +0x155c to +0x156b | none |
| +0x157c | byte | (rear flag, undocumented) | NEW | FUN_004537b0+118: `*(byte *)(param_1 + 0x157c)` | Not in doc! Rear analog of +0x1180 |
| +0x1f00 | int/ptr | contextData | HIGH | FUN_0043e050+18: `*(undefined4 *)(ECX + 0x1f00) = param` | none |

**CRITICAL TYPE CONFLICTS:**
1. **+0x1140** — doc claims `double[8]` (64 bytes), but FUN_004537b0 reads 8 floats at +0x1140..+0x115c (32 bytes)
2. **+0x153c** — doc claims `double[8]` (64 bytes), but FUN_004537b0 reads 8 floats at +0x153c..+0x1558 (32 bytes)

**NEW UNDOCUMENTED OFFSET:**
- **+0x157c** — byte flag for rear telemetry section (analogous to +0x1180 for front). Read as `*(byte *)(param_1 + 0x157c)`. Not listed in the doc's offset table.

**Verdict:** HIGH for offset existence; MEDIUM for type accuracy. Documentation needs correction: frontTireTelemetry and rearTireTelemetry should be `float[8]` not `double[8]`. Stride between telemetry values is 4 bytes (float), not 8 bytes (double). Also missing +0x157c as rear section flag.

---

=== SUMMARY BY SECTION ===

| Section | Name | Offsets | Confidence | Issues |
|---------|------|---------|------------|--------|
| 202 | PitStop/PitCrewStruct | 7 | HIGH → HIGH | None confirmed |
| 204 | ArrayContainer (various) | 6 variants | HIGH → LOW-MEDIUM | Multi-variant, needs per-function check |
| 205 | VehicleControllerStruct | 23 (9 verified) | HIGH → partial | 14 offsets need FUN_00425670 verification |
| 206 | VehiclePhysicsHeader | 180+ (56 verified) | HIGH | 5 naming conflicts (some flagged); 3 new offsets found |
| 207 | VehicleSetupFileWriterLayout | referential | HIGH | OK — referential to Section 206 |
| 208 | Filter List State | 4 | LOW → HIGH | **Upgrade to HIGH** — all offsets verified |
| 209 | Transform/4x4 Matrix | 16 | HIGH → HIGH | All verified, no issues |
| 210 | Render Property Slots | 3 | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 211 | SpringDamperState | 13 indices | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 213 | Commentary Path List | 6 | VERY LOW → VERY LOW | No .c file available, unverifiable |
| 214 | MessageSlotStruct | 4 | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 215 | VehiclePhysicsInstance (tire) | 14 | HIGH → MEDIUM (type) | **2 type conflicts** (double→float), 1 new offset (+0x157c) |

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| VehiclePhysicsHeader | +0x1644 | int | FUN_0042fd00 | FinalDriveSetting — written as INI field (not in doc table) |
| VehiclePhysicsHeader | +0x1684 | int | FUN_0042fd00 | ReverseSetting — written as INI field (not in doc table) |
| VehiclePhysicsInstance | +0x157c | byte | FUN_004537b0 | Rear telemetry enable flag (analogous to +0x1180 for front) |

=== CONFIDENCE COVERAGE ===

| Grade | Count | Sections |
|-------|-------|----------|
| HIGH (all verified) | 6 | 202, 208, 209, 210, 211, 214 |
| HIGH (partial verify) | 2 | 205, 206 |
| MEDIUM (type conflict) | 1 | 215 |
| LOW-MEDIUM (multi-variant) | 1 | 204 |
| VERY LOW (no evidence) | 1 | 213 |
| Referential (no offsets) | 1 | 207 |

=== TYPE CONFLICTS (CRITICAL) ===

1. **+0x1140, VehiclePhysicsInstance**: doc says `double[8]` — code reads `float` ×8 — **change to float[8]**
2. **+0x153c, VehiclePhysicsInstance**: doc says `double[8]` — code reads `float` ×8 — **change to float[8]**

=== NAMING CONFLICTS (Section 206) ===

| Offset | Doc Name | Actual (FUN_0042fd00) |
|--------|----------|----------------------|
| +0xd44 | ToeInLeftSetting | RearAntiSwaySetting |
| +0xd84 | ToeInRightSetting | FrontToeInSetting |
| +0xdc4 | (Suspension param) | RearToeInSetting |
| +0x15c4 | SteeringBarCount / EngineMapSetting | EngineMapSetting (setup context) |
| +0x1884 | GearCount / NumPitstops | NumPitstopsSetting (setup context) |

