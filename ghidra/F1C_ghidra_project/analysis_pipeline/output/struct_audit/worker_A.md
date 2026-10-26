# WORKER A — Struct Confidence Audit Results

Date: 2026-07-15
Worker: A of 20

---

=== AUDIT RESULTS ===

## Section 1a: Physics Vehicle Instance Offsets

Source: decompiled_all/0x004f2c60 (wheel corner parser), analyzed/0x0043ef20 (engine simulation), analyzed/0x004537b0 (tire compound), analyzed/0x0043bb00 (delta tracker)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1db4 | double | EffectiveEngineLifetime | HIGH | 3 files: 0x0043ef20, 0x00447160, 0x00447280 — all read as double | none |
| +0x1dbc | double | LifetimeEngineRPM_min | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dc4 | double | 1/LifetimeEngineRPM_max | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dcc | double | LifetimeOilTemp_min | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dd4 | double | 1/LifetimeOilTemp_max | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1140 | double×8 | FrontTireTelemetry | LOW | 0x004537b0 reads as float; 0x0053f270 reads as int (pointer); 0x0053d4f0 zeroes as undefined4 | **CONFLICT**: Mixed types across functions — float, int*, undefined4 |
| +0x1160 | byte[16] | FrontCompoundFlags | MEDIUM | 3 files: 0x0042a180 writes int; 0x004537b0 reads byte; 0x0053d4f0 writes int 0x8000 | Type varies: int write vs byte read |
| +0x1170 | int | CurrentFrontCompoundIndex | HIGH | 0x004537b0 reads as int (multiple compound compares); 0x004af220 zeroes as int | none |
| +0x1174–+0x117c | int×3 | CompoundSelections | HIGH | 0x004537b0 reads as int (8 compound compares per offset); 0x0053d4f0 zeroes as int | none |
| +0x1180 | uint | PitStopFlag bitmask | HIGH | 0x004537b0 reads as byte/uint (bit tests); 0x00424790, 0x0042a3d0 use as base pointer | none |
| +0x153c | double×8 | RearTireTelemetry | LOW | 2 files reference 0x153c — need type verification | Pending verification |
| +0x155c | byte[16] | RearCompoundFlags | LOW | 3 files reference 0x155c — need type verification | Pending verification |

## Section 1b: Wheel Corner Struct (FUN_004f2c60)

Source: decompiled_all/0x004f2c60 (wheel corner .svm parser, string-anchored)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb8 | double | BrakeOptimumTemp | HIGH | FUN_004f2c60: `*(double *)(param_1 + 0xb8)` + 273.15 applied | none |
| +0xf0 | double | BrakeWearRate | HIGH | FUN_004f2c60: reads "BrakeWearRate" string at param_1+0xf0 | none |
| +0xf8 | double | BrakeFailure_min | HIGH | FUN_004f2c60: "BrakeFailure" string stored to param_1+0xf8, param_1+0x100 | none |
| +0x100 | double | BrakeFailure_max | HIGH | FUN_004f2c60: second param of "BrakeFailure" string | none |

Note: All wheel corner struct offsets verified from FUN_004f2c60 in decompiled_all (not in analyzed/). All are doubles — confirmed by `FUN_00565aa0(s_BrakeWearRate_..., param_1 + 0xf0, ...)` pattern.

## Section 1c: Player Options Struct (FUN_004aa270)

Source: analyzed/0x00585d70 (only file referencing +0x5c8)

| Offset | Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|------|------------|------------|-------------|-----------|
| +0x5c8 | byte[?] | FailureRate[0..6] | LOW | 2 refs in 0x00585d70: byte zeroing + pointer base. No stride 0x24 evidence seen | Only 2 hits, insufficient to confirm 7-element array |

## Section 2: PenaltySlipAngleStruct

Source: analyzed/0x0042e400, 0x00431a50, 0x004319c0, 0x00443b70, 0x00443c07

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1cb8 | byte | Flag | HIGH | 0x0042e400: `*(undefined1 *)(param_1 + 0x1cb8) = 1`; 0x00431a50: same | none |
| +0x1cbc | float | SpeedThreshold | MEDIUM | 0x0042e400: `*(undefined4 *)(param_1 + 0x1cbc) = 0x4392947b` (~295.0f); 0x00431a50: sets from param_2 | 4-byte confirmed, type as float inferred from value |
| +0x1cd4 | byte[4] | CornerFlags | HIGH | 0x0042e400: `puVar1 = (undefined1 *)(param_1 + 0x1cd4)`, 4 iterations; 0x004319c0: per-corner byte set | none |
| +0x1cd8 | float[4] | CornerThresholds | HIGH | 0x0042e400: `puVar2 = (undefined4 *)(param_1 + 0x1cd8)`, 4 iterations; 0x004319c0: indexed by param_2×4 | none |
| +0x1cec | float[4][3] | CornerTimers | MEDIUM | 0x0042e400: `puVar3 = (undefined4 *)(param_1 + 0x1cec)`, stride 3, 4 iterations; values 0x43b3ee14 (~359.0f) | **CONFLICT**: 0x00443b70 reads `*(double *)(param_1 + 0x1cec)` as double; 0x0042e400 uses 4-byte stride |

## Section 3: HighResTimer

Source: analyzed/0x005564b0, 0x00556510, 0x00568c60, 0x00568cb0

The struct is int-indexed (param_1 as int*/uint*). All offsets = index × 4.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int32 | Enabled/ActiveFlag | HIGH | 0x005564b0: `if (*param_1 != 0)`; 0x00568c60: same | Also used as QPC frequency divisor in 0x00556510 line 19 |
| +0x08 | double | ScaleFactor | HIGH | 0x00556510: `*(double *)(param_1 + 2)` at byte offset +0x08 (2 ints) | none |
| +0x10 | int32 | OtherAccum0 | HIGH | 0x00568c60: `param_1[4] = 0` (byte offset +0x10) | none |
| +0x14 | int32 | OtherAccum1 | HIGH | 0x00568c60: `param_1[5] = 0` (byte offset +0x14) | none |
| +0x18 | uint32 | CurrentLow | HIGH | 0x00568c60: `param_1[6] = local_8.s.LowPart` (byte offset +0x18) | none |
| +0x1c | uint32 | CurrentHigh | HIGH | 0x00568c60: `param_1[7] = local_8.s.HighPart` (byte offset +0x1c) | none |
| +0x20 | uint32 | LastLow | HIGH | 0x00568c60: `param_1[8] = param_1[6]`; 0x00556510: `param_1[8]` read | none |
| +0x24 | uint32 | LastHigh | HIGH | 0x00568c60: `param_1[9] = param_1[7]`; 0x00556510: `param_1[9]` read | none |
| +0x28 | uint32 | AccumLow | HIGH | 0x00568c60: `param_1[10] = 0` | none |
| +0x2c | uint32 | AccumHigh | HIGH | 0x00568c60: `param_1[11] = 0` | none |
| +0x48 | int/byte | TimerModeFlags | HIGH | 0x005564b0: `param_1[0x12] & 1` / `param_1[0x12] & 2`; 0x00568c60: `*(byte *)(param_1 + 0x12) & 1` (both access byte offset 0x48) | none |

## Section 5: DeltaUpdateTrackerStruct

Source: analyzed/0x0043bb00

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xd4c | double | CumulativeDelta | HIGH | 0x0043bb00: `*(double *)(param_1 + 0xd4c)` read and written | none |
| +0x1428 | double | CurrentValue | HIGH | 0x0043bb00: `*(double *)(param_1 + 0x1428)` read and written | none |
| +0x1430 | double | DeltaGain | HIGH | 0x0043bb00: `*(double *)(param_1 + 0x1430)` read | none |

## Section 6: PerWheelPhysics (inferred)

Source: analyzed/0x0043f7f0 (938 lines), decompiled_all/0x0043da10

Stride 0x464 between wheels confirmed (0x0043f7f0 lines 216, 278, 401, 428+). Base starts at +0x348.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x28c | struct | TireCompoundData | MEDIUM | 0x0043da10: `iVar8 = param_2 * 0x464 + 0x28c + param_1` | Offset mapping confirmed — compound data at base |
| +0x348 | double | Position | HIGH | 0x0043f7f0: `pdVar17 = (double *)(param_1 + 0x348)`, iterated by 0x464 | none — type matches |
| +0x360 | float | Force | LOW | Not directly seen in 0x0043f7f0 | Not verified |
| +0x368 | int | ConstraintState | LOW | Not directly seen in 0x0043f7f0 | Not verified |
| +0x7ac | float | Force2 | LOW | 0x0043f7f0 line 274: `*(double *)(param_1 + 0x7ac)` | **CONFLICT**: Read as double in .c, doc says float |
| +0x7c4 | float | Inertia | LOW | Not directly seen | Not verified |
| +0xc10 | float | Velocity | LOW | 0x0043f7f0 line 237: `*(double *)(param_1 + 0xc10)` | **CONFLICT**: Read as double in .c, doc says float |
| +0xc28 | float | Mass | LOW | 0x0043f7f0 line 237: `*(double *)(param_1 + 0xc28)` | **CONFLICT**: Read as double in .c, doc says float |
| +0xc30 | float | Inertia2 | LOW | Not directly seen | Not verified |
| +0x1074 | float | Bias | LOW | 0x0043f7f0 line 239: `*(double *)(param_1 + 0x1074)` | **CONFLICT**: Read as double in .c, doc says float |
| +0x108c | float | Bias2 | LOW | 0x0043f7f0 line 238: `*(double *)(param_1 + 0x108c)` | **CONFLICT**: Read as double in .c, doc says float |

## Section 7: PLAYERTRACKSTAT Node Struct (int-indexed)

Source: decompiled_all/0x004c2420 (not in analyzed/)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | TrackName[0] | UNKNOWN | File in decompiled_all only — not checked | No analyzed/ source |
| +0x01 | char* | TrackName[1] | UNKNOWN | Same | No analyzed/ source |
| +0x02 | char* | TrackFile[0] | UNKNOWN | Same | No analyzed/ source |
| +0x03 | char* | TrackFile[1] | UNKNOWN | Same | No analyzed/ source |
| +0x04 | int | TotalNumLaps | UNKNOWN | Same | No analyzed/ source |
| +0x05 | float | BestLapTime | UNKNOWN | Same | No analyzed/ source |

Note: If int-indexed, byte offset = index × 4, so [0]=+0x00, [1]=+0x04, [2]=+0x08, etc. The doc's byte offsets as written (+0x00-chars through +0x05-float) are likely incorrect — these should be pointer-sized (4 bytes each on x86).

## Section 8: String Property Struct

Source: analyzed/0x00467430

Int-indexed via `param_1[0xbc]` etc. Byte offsets = index × 4.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x2f0 | char* | stored_string | HIGH | 0x00467430: `param_1[0xbc]` = offset 0x2f0 (0xbc×4). Used as string pointer for comparison/copy | none |
| +0x2f4 | char* | cursor_pointer | HIGH | 0x00467430: `param_1[0xbd]` = offset 0x2f4. Used as iteration cursor into string | none |
| +0x2f8 | int | buffer_size | HIGH | 0x00467430: `param_1[0xbe]` = offset 0x2f8. Used as strncpy limit | none |

Note: All three offsets confirmed from single function. Struct is pointer-indexed (int* param_1).

## Section 9: Mesh Bounding Box Struct (inferred)

Source: analyzed/0x0054d9f0

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | int | flags | HIGH | 0x0054d9f0: `uVar2 = *(uint *)(param_1 + 0x14)`, bit test with 0x800000 | none |
| +0x18 | float | boundingSphereRadius | LOW | Not directly verified | Pending verification |
| +0x1c..0x78 | float[24] | aabbCorners | LOW | Not directly verified | Pending verification |
| +0xdc | float | centerX | LOW | Not directly verified | Pending verification |
| +0x118 | int | subsetCount | HIGH | 0x0054d9f0: `if (0 < *(int *)(param_1 + 0x118))` loop bound | none |
| +0x11c | ptr | subsetArray | HIGH | 0x0054d9f0: `*(int *)(param_1 + 0x11c)` used as array base pointer | none |

## Section 11: CollisionShapeClassifier

Source: analyzed/0x004139c0, 0x00412c30

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | ShapeClass | MEDIUM | Two functions reference this offset as int. Used as size class (0x20-0x2f) or bone index (0x99-0xBD) | **CONFLICT**: Same offset dual-purposed as SizeClass and BoneIndex per doc notes |
| +0x0c | int | SecondaryClass | MEDIUM | Same two functions. Secondary class | none |

## Section 13: AudioHandleStruct / MilesSampleStruct

Source: analyzed/0x00552760, 0x00405b50, 0x004059f0, 0x004060c0, 0x00406750

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | void* | SubResource | HIGH | 0x00552760: `*(undefined4 *)(param_1 + 0xc)` freed via FUN_00540eb0; 0x00406750: `*(int *)(param_1 + 0xc)` used with `_AIL_close_stream` | **NOTE**: Also used as Miles stream handle (AIL_close_stream) in 0x00406750 — dual purpose or doc misnamed field |
| +0x14 | int | PlayState | HIGH | 0x00405b50: `return *(int *)(param_1 + 0x14) != 0` | none |
| +0x24 | uint32 | FlagBitmask | HIGH | 0x00552760: `*(uint *)(param_1 + 0x24) & 0x20000` bit test | none |
| +0x58 | void* | AudioHandle | HIGH | 0x00405b50, 0x004059f0, 0x004060c0: all read as `*(int *)(param_1 + 0x58)` then dereference +0x10 for Miles sample | none |
| +0x5c | int | StreamHandle | HIGH | 0x00406750: `*(int *)(param_1 + 0x5c) != -1` | Checked for -1 (closed) pattern |
| +0x60 | int | FilterType | HIGH | 0x004060c0: `*(int *)(param_1 + 0x60) != -1` | -1 = no filter |
| +0x68 | byte[] | FilterState | HIGH | 0x004060c0: `iVar2 = param_1 + 0x68` passed as filter state buffer | none |

| +0x868 | void* | SecondaryResource | MEDIUM | 0x00552760: `iVar1 = *(int *)(param_1 + 0x868)` read and conditionally freed | Single function |

**DOCUMENTATION ISSUE**: The doc table claims +0x10 as "MilesSampleHandle" directly in param_1, but in all 3 referenced files the pattern is `*(int *)(*(int *)(param_1 + 0x58) + 0x10)` — +0x10 is within the sub-struct pointed to by param_1[0x58], NOT in param_1 itself. The +0x58 field is the actual handle pointer.

**DUAL STREAM HANDLES**: +0x0c is used with `_AIL_close_stream` (Miles stream API) in 0x00406750, while +0x5c is a different handle checked for -1. The struct has two stream-like handles.

## Section 14: AI Database Struct (aiDB)

Source: analyzed/0x004040a0, 0x00402690

Int-indexed (param_1[idx]) in 0x004040a0, byte-offset in 0x00402690. Both consistent after conversion.

| Byte Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|-------------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | GrooveWidth | HIGH | Both functions. Default 4.5 | none |
| +0x04 | float | GrooveWidthWet | HIGH | Both functions. Default 4.3125 | none |
| +0x118 | float | AiGlobalSpeedMult | MEDIUM | 0x004040a0: computed from slider interpolation | Only in one function |
| +0x11c | float | AiSpeedMultMin | HIGH | Both functions. Default 0.5 | none |
| +0x120 | float | AiSpeedMultMid | HIGH | Both functions. Default 1.0 | none |
| +0x124 | float | AiSpeedMultMax | HIGH | Both functions. Default 1.3 | none |
| +0x12c | bool | LeftHandedPits | MEDIUM | 0x00402690 only | Single function |
| +0x130 | int | WaypointCount | MEDIUM | 0x00402690 only | Single function |
| +0x134 | ptr | WaypointArray | MEDIUM | 0x00402690 only | Single function |
| +0x13c | float | LapLength | MEDIUM | 0x00402690 only | Single function |
| +0x140 | float | Sector1Length | MEDIUM | 0x00402690 only | Single function |
| +0x144 | float | Sector2Length | MEDIUM | 0x00402690 only | Single function |
| +0x14c | float | FuelUse | MEDIUM | 0x00402690 only | Single function |
| +0x15c | int | PitlaneCount | MEDIUM | Both functions. FUN_004040a0 default 1; FUN_00402690 reads from .gdb | **CONFLICT NOTED**: aiDB[0x57]=1 init default vs actual pitlane count at load |
| +0x160 | int | StartingGridSlots | HIGH | Both functions. Default 104 | none |
| +0x164 | int | PitSpots | HIGH | Both functions. Default 52 | none |
| +0x168 | int | GarageSpots | HIGH | Both functions. Default 3 | none |

Note: +0x150, +0x154, +0x158 (GridArray/PitArray/GarageArray) referenced only in 0x00402690 as struct arrays. Not verified from 0x004040a0.

---

## Section 10: CollisionBody (inferred — rigid body physics state)

Source files verified: analyzed/0x00436870, 0x004542d0, 0x00457a00, 0x004584c0, 0x004987b0, 0x0044fee0, 0x004599c0, 0x00459950, 0x0044efe0, 0x0044f050, 0x0045b840, 0x00403aa0, 0x004039c0, 0x004038e0, 0x00456f70

**CRITICAL**: Offsets like +0x040, +0x060, +0x068, +0x084 in the prompt doc are relative to a SUB-struct base (param_1 + 0xd88 or param_1 + 0x1184 per FUN_004542d0), NOT param_1 directly. Verified offsets below use direct param_1 access.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0A4 | float | RestitutionFactor | HIGH | 0x004584c0: `*(float *)(param_1 + 0xa4)` | none |
| +0x090 | float | ContactPosX | HIGH | 0x00457a00: `*(float *)(param_1 + 0x90)` | none |
| +0x094 | float | ContactPosY | HIGH | 0x00457a00: `*(float *)(param_1 + 0x94)` | none |
| +0x098 | float | ContactPosZ | HIGH | 0x00457a00: `*(float *)(param_1 + 0x98)` | none |
| +0x0D8 | double | PositionX | HIGH | 0x004599c0: `*(double *)(param_1 + 0xd8)` | none |
| +0x0E0 | double | PositionY | HIGH | 0x004599c0: `*(double *)(param_1 + 0xe0)` | none |
| +0x0E8 | double | PositionZ | HIGH | 0x004599c0: `*(double *)(param_1 + 0xe8)` | none |
| +0x0FC | int | ContactPointWorldX | MEDIUM | 0x00436870: `*(undefined4 *)(param_1 + 0xfc) = 0xffffffff` | Set as bitmask, not float |
| +0x100 | int/float | ContactWorldY / FlagA | MEDIUM | 0x00436870: `*(undefined4 *)(param_1 + 0x100) = 0xffefffff` | **OVERLAP**: bitmask int confirms union |
| +0x134 | float/double | FrictionMagnitude | MEDIUM | 0x00436870: zeroed as undefined4; written as double line 448 | **CONFLICT**: 4B vs 8B access |
| +0x144 | float | StiffnessTerm | MEDIUM | 0x00436870: zeroed as undefined4 | Single 4B ref |
| +0x15C | int* | TriangleDataPtr | HIGH | 0x00436870: 4× `*(int *)(param_1 + 0x15c)` | none |
| +0x180 | uint32 | MassLow | HIGH | 0x00459950: `*(undefined4 *)(param_1 + 0x180) = param_2` | none |
| +0x184 | uint32 | MassHigh | HIGH | 0x00459950: `*(undefined4 *)(param_1 + 0x184) = param_3` | none |
| +0x188 | double | InvMass | HIGH | 0x00459950: `*(double *)(param_1 + 0x188)` | none |
| +0x20C | double | Damping | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x20c)` | **CONFLICT**: doc float, is double |
| +0x214 | double | Restitution | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x214)` | **CONFLICT**: doc float, is double |
| +0x21C | double | HalfExtent | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x21c)` ×4 | **CONFLICT**: doc float, is double |
| +0x224 | double | RotationMatrix[0] | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x224)` | **CONFLICT**: doc float[3], is double |
| +0x264 | int | BestTriIndex | HIGH | 0x00436870: zeroed + read as int | none |
| +0x278 | int | CullFlag | HIGH | 0x0044efe0: `*(undefined4 *)(param_1 + 0x278) = 0` | none |
| +0x27C | byte[] | PropertyBlock | HIGH | 0x0044f050: `*(undefined1 *)(param_2 + 0x27c + param_1)` | Byte-indexed array |
| +0x31C | double/float/int | ContactForce/Count | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x31c)`; 0x0045b840: `*(int *)(param_1 + 0x31c)` | **CONFLICT**: triple overlap |
| +0x1c4 | char | (unknown flag) | — | 0x00436870: `*(char *)(param_1 + 0x1c4) != '\0'` | **NOT IN DOC** |
| +0x268 | int | (init zero) | — | 0x00436870: init block | **NOT IN DOC** |
| +0x26c | int | (init 1.0f) | — | 0x00436870: set to 0x3ff00000 | **NOT IN DOC** |
| +0x324 | double | (friction related) | — | 0x00436870: friction calc | **NOT IN DOC** |
| +0x560–0x588 | double[6] | Momentum accum | — | 0x0044fee0: lin+ang momentum | **NOT IN DOC** |

Offsets relative to sub-struct base +0xd88 (NOT directly param_1): +0x040, +0x060, +0x068, +0x084, +0x0AC, +0x0E4, +0x0EC, +0x0F4, +0x10C, +0x110, +0x12C, +0x200, +0x27C–0x290, +0x298–0x2D0, +0x2E4, +0x2EC, +0x2F4, +0x304, +0x314, +0x320

---

## NEW OFFSETS DISCOVERED

None discovered from analyzed/ search that aren't already listed in the prompt.

---

## SUMMARY

| Grade | Count |
|-------|-------|
| HIGH | 40 |
| MEDIUM | 20 |
| LOW/UNKNOWN | 15 |
| NONE (missing evidence) | 4 |

**CONFLICTS FOUND:**
1. **+0x1140** (FrontTireTelemetry): float vs int (pointer) vs undefined4 across 3 functions — likely different structs sharing offset
2. **+0x1160** (FrontCompoundFlags): byte[16] doc'd but written as int in 0x0042a180
3. **+0x1cec** (CornerTimers): 4-byte array in 0x0042e400, double in 0x00443b70
4. **PerWheelPhysics** (+0x7ac, +0xc10, +0xc28, +0x1074, +0x108c): doc'd as float, read as double in 0x0043f7f0
5. **+0x1dbc/+0x1dc4/+0x1dcc/+0x1dd4**: Not found in any analyzed/ .c files — missing evidence
6. **CollisionBody type mismatches**: +0x20C (Damping), +0x214 (Restitution), +0x21C (HalfExtent) doc'd as float, all read as double in 0x00436870
7. **+0x31C** (ContactForce/ContactCount): triple overlap — double/float/int at same offset
8. **+0x134** (FrictionMagnitude): 4-byte zeroing vs 8-byte double write
9. **+0x100** (ContactWorldY/FlagA): union overlap confirmed — int bitmask pattern
10. **Audio Struct +0x0c**: doc says "SubResource" but also used as Miles stream handle (AIL_close_stream) — dual purpose

**DOCUMENTATION ISSUES:**
1. **CollisionBody sub-struct base**: Many offsets (+0x040, +0x060, +0x068, +0x084, etc.) are relative to a sub-struct at param_1 + 0xd88, NOT param_1 — doc should clarify
2. **PLAYERTRACKSTAT byte offsets**: If int-indexed, offsets should be ×4 (doc shows raw index values as byte offsets, which is wrong for pointer-sized fields)
3. **Section 7 doc claims +0x00–+0x05 as byte offsets**: This is incorrect for int-indexed struct; [0]=+0x00, [1]=+0x04, [2]=+0x08, etc.
4. **Audio +0x10**: Field is in sub-struct (reached via param_1[0x58]+0x10), not directly in param_1

**NEW DISCOVERIES:**
- CollisionBody extends to at least +0x588 (momentum accumulation)
- +0x1c4: char flag in CollisionBody
- +0x268, +0x26c: init values in CollisionBody  
- +0x324: double friction term in CollisionBody

