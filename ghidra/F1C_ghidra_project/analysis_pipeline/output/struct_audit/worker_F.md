# WORKER F — Struct Confidence Audit Results

Audit date: 2026-07-15
Sections processed: 76–89 (14 sections)

---

=== AUDIT RESULTS ===

## Section 76: OpponentStateStruct (param_2 — opponent/driver in overtaking)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x70 | float | OpponentPosition | HIGH | FUN_0042a780: `*(undefined4 *)(param_2 + 0x70)` in float context | none |
| +0x74 | float | OpponentDistance | HIGH | FUN_0042a780: `*(undefined4 *)(param_2 + 0x74)` passed to float FUN_004e8ce0 | none |
| +0x78 | float | OpponentPosition | HIGH | FUN_0042a780: `param_2 + 0x78` passed as float arg | none |
| +0x84 | float | OpponentSpeedDelta | HIGH | FUN_0042a780: `*(float *)(param_2 + 0x84)` | none |
| +0x4fc | float | LapTimeDelta | MEDIUM | FUN_0041ad80: `*(float *)(param_1 + 0x4fc + idx*4)` — float ✓ | CONFLICT: FUN_004423b0 accesses as `(double *)(param_1 + 0x4fc)` and writes double values (stride 0x464) |
| +0x69c | float | OvertakeGap | MEDIUM | FUN_0041ad80: `*(float *)(param_1 + 0x69c + idx*4)` — float ✓ | none found |
| +0x83c | float | OvertakeTarget | MEDIUM | FUN_004c71c0: `*(float *)(iVar4 + param_1 + 0x83c)` — float in array context | CONFLICT: FUN_0041ad80 uses `*(int *)(param_1 + 0x83c + idx*4) = param_3` — stores driver index as INT, not float |

### Issues found:
1. **+0x4fc type mismatch**: Docs say float. FUN_004423b0 accesses as `(double *)(param_1 + 0x4fc)` with stride 0x464 (4 entries). This may be a different struct layout — the stride 0x464 spans 1124 bytes, much larger than a per-driver array. Likely different struct.
2. **+0x83c type conflict**: Docs say float. Code shows int (stores driver index) in FUN_0041ad80, but float in FUN_004c71c0. Recommend: rename OvertakeTarget to int (driver index), flag the float usage as possible different struct.
3. No .c file found for FUN_004c0cc0 (claimed observer in docs). Offsets +0x4fc, +0x69c, +0x83c verified through other files.

---

## Section 77: CollisionContactState

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | uint | CollisionStateFlags | HIGH | FUN_0054d7a0: `*(uint *)(param_1 + 0x14)` — bitwise state operations | none |
| +0x18 | float | ContactMargin | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0x18)` — tolerance comparison | none |
| +0xf4 | float | OuterRadius | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0xf4)` — bounding sphere outer | none |
| +0xf8 | float | InnerRadius | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0xf8)` — bounding sphere inner | none |
| +0xfc | int | ContactIteration | HIGH | FUN_0054d7a0: `*(int *)(param_1 + 0xfc)` — solver iteration count (compared to 5) | none |
| +0x1c | float | RefX | HIGH | FUN_00507845: `*(float *)(param_1 + 0x1c)` — reference X | none |
| +0x20 | float | RefY | HIGH | FUN_00507845: `*(float *)(param_1 + 0x20)` — reference Y | none |
| +0x24 | float | RefZ | HIGH | FUN_00507845: `*(float *)(param_1 + 0x24)` — reference Z | none |
| +0x28 | float | RefW | HIGH | FUN_00507845: `*(float *)(param_1 + 0x28)` — penetration/distance | none |
| +0x1058 | int | ContactCount | HIGH | FUN_00507845: `*(int *)(param_1 + 0x1058) * 0x10` — count, also used in 10+ other collision files | none |

**Grade: HIGH — All 10 offsets confirmed with correct types across 2+ functions.**

---

## Section 78: GameConfig (inferred — FUN_004216f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb8 | int | Field_0xb8 | LOW | No .c file for FUN_004216f0. Offset +0xb8 used in >50 files with MANY types: int, float, pointer, vtable dispatch | Cannot verify — +0xb8 is a common offset in multiple structs |
| +0xbc | int | Field_0xbc | LOW | Same — no .c file. Cannot distinguish from other structs using +0xbc | — |
| +0xc0 | int | Field_0xc0 | LOW | Same | — |
| +0xc4 | int | Field_0xc4 | LOW | Default 22 cited in notes — unverifiable without .c | — |
| +0xc8 | bool | Field_0xc8 | LOW | Default 1 cited — unverifiable | — |
| +0xcc | int | Field_0xcc | LOW | — | — |
| +0xd0 | int | Field_0xd0 | LOW | — | — |
| +0xd4 | byte | Field_0xd4 | LOW | — | — |
| +0xd5 | byte | Field_0xd5 | LOW | Default 1 cited | — |
| +0xd6 | byte | Field_0xd6 | LOW | — | — |
| +0xd8 | int | Field_0xd8 | LOW | Default 1 cited | — |
| +0xdc | int | Field_0xdc | LOW | Default 1 cited | — |
| +0xe0 | int | Field_0xe0 | LOW | — | — |
| +0xe4 | int | Field_0xe4 | LOW | Default 1 cited | — |
| +0xe8 | float | Field_0xe8 | LOW | -1.0f (disabled) cited — unverifiable | — |

**Grade: LOW — No source file available for FUN_004216f0. All 15 offsets unverifiable. Offset +0xb8 is a known false-positive magnet (used across renderer, physics, audio, UI structs). Recommend: locate FUN_004216f0 source or mark section as speculative.**

---

## Section 79: ConstraintGroupStruct (param_1 for FUN_0056ee40)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | Group1Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 8)` — loop bound check | none |
| +0x0c | int* | Group1Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0xc)` used as pointer base for body index array | none |
| +0x10 | int | Group2Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x10)` — loop bound check | none |
| +0x14 | int* | Group2Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x14)` used as pointer base for pair array | none |
| +0x18 | int | Group3Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x18)` — loop bound check | none |
| +0x1c | int* | Group3Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x1c)` used as pointer base | none |
| +0x2c | double* | GlobalPosArray | HIGH | FUN_0056ee40: `pdVar1 = (double*)(*(int*)(param_1 + 0x2c) + ...)` — pointer to double array | none |

**Grade: HIGH — All 7 offsets confirmed with correct types from FUN_0056ee40.**

---

## Section 80: AudioSceneUpdateStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xd80 | int | SceneEntryCount | MEDIUM | FUN_004532d0: `*(int *)(param_1 + 0xd80)` read in loop bound check | none |

**Grade: MEDIUM — 1 offset confirmed. Only 1 function evidence. Rename from "low" to "medium".**

---

## Section 81: WheelFloatArray (per-wheel state as float[]) (inferred)

| Float Index | Real Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|-------------|-------------|-------------|--------------|------------|-------------|-----------|
| 0x0e | +0x38 | float[3] | SuspAxisVectors | MEDIUM | FUN_004e3d00: `param_1[0xe]` as scalar float | NAME OVERLAP: float[3] at +0x38 conflicts with +0x3c (SuspType) and +0x40 (WheelNormal) which are inside the array |
| 0x0f | +0x3c | float | SuspType | MEDIUM | FUN_004e3d00: `param_1[0xf]` — compared to threshold | NAME OVERLAP: inside float[3] at +0x38 if array is 12 bytes |
| 0x10 | +0x40 | float | WheelNormal | MEDIUM | FUN_004e3d00: `param_1[0x10]` — axis cross product | NAME OVERLAP: inside float[3] at +0x38 |
| 0x11 | +0x44 | float | RideHeight | HIGH | FUN_004e3d00: `param_1[0x11]` — current travel, used in spring/damper calc | none |
| 0x12 | +0x48 | float | SpringK | HIGH | FUN_004e3d00: `param_1[0x12] = 5.0` — hardcoded 5.0 | none |
| 0x13 | +0x4c | float | SpringForce | HIGH | FUN_004e3d00: `param_1[0x13]` — computed, clamped | none |
| 0x14 | +0x50 | float | DampingEnabled | HIGH | FUN_004e3d00: `param_1[0x14] = 0.0` / `= 1.0` — on/off switch | none |
| 0x15 | +0x54 | float | DamperForce | HIGH | FUN_004e3d00: `param_1[0x15]` — accumulator | none |
| 0x16 | +0x58 | float | BumpForce | HIGH | FUN_004e3d00: `param_1[0x16]` — accumulator | none |
| 0x24 | +0x90 | float | WheelRadius | HIGH | FUN_004e3d00: `param_1[0x24]` — used in force calc | none |
| 0x25 | +0x94 | float | DampingFactor | HIGH | FUN_004e3d00: `param_1[0x25]` — multiplier | none |
| 0x27 | +0x9c | float | SpringRateMult | HIGH | FUN_004e3d00: `param_1[0x27]` — multiplier | none |
| 0x2a | +0xa8 | float | ProgressiveRate | HIGH | FUN_004e3d00: `param_1[0x2a]` — progressive spring factor | none |
| 0x2b | +0xac | float | BumpStopTravel | HIGH | FUN_004e3d00: `param_1[0x2b]` — bump stop limit | none |
| 0x2c | +0xb0 | float | AlignmentCamber | LOW | FUN_004e3d00: NOT directly accessed as float in this function. `param_1[0x2c]` not used. `param_1[0x2e]` used instead. | Possible index off-by-one |
| 0x2d | +0xb4 | float | AlignmentCaster | LOW | FUN_004e3d00: NOT directly accessed. | Unused in this function |
| 0x2e | +0xb8 | float | (alignment) | MEDIUM | FUN_004e3d00: `param_1[0x2e]` — used in steering axis calc | Name unclear in docs |
| 0x2f | +0xbc | float | SteerCasterCos | HIGH | FUN_004e3d00: `param_1[0x2f]` — compared to 1.0, steering angle cos | none |
| 0x30 | +0xc0 | float | SteerKingpin | HIGH | FUN_004e3d00: `param_1[0x30]` — steering axis angle | none |
| 0x31 | +0xc4 | float | LastContactX | HIGH | FUN_004e3d00: `param_1[0x31]` — contact point X | none |
| 0x32 | +0xc8 | float | LastContactZ | HIGH | FUN_004e3d00: `param_1[0x32]` — contact point Z | none |
| 0x36 | +0xd8 | float[3] | WheelVelocity | HIGH | FUN_004e3d00: `param_1[0x36]`, `[0x37]`, `[0x38]` — 3-component output velocity | none |

### Issues found:
1. **NAME OVERLAP at +0x38**: The docs list +0x38 as `float[3] SuspAxisVectors` (12 bytes spanning 0x38–0x43), but also list +0x3c and +0x40 as separate fields (`SuspType`, `WheelNormal`). If the 3 floats at 0x38/0x3c/0x40 are genuinely separate fields, change to three individual floats. If they form a 3-component vector, rename SuspType/WheelNormal as aliases.
2. **+0xb0 (AlignmentCamber)**: Index 0x2c not directly used in FUN_004e3d00. The function uses index 0x2e (+0xb8) instead. Either +0xb0 is unused in this function or offset is wrong.
3. **Undocumented fields**: +0x1b (0x6c) and +0x1c (0x70) used at line 127 for force computation — not in docs.

---

## Section 82: AutoLoadEntry Linked List Node Struct (stride 0x1c)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | Track path (alloc) | LOW | No .c file for FUN_00432e70 | Unverifiable |
| +0x04 | int | next pointer | LOW | Same | — |
| +0x08 | char* | Classes (alloc) | LOW | Same | — |
| +0x0c | int | next pointer | LOW | Same | — |
| +0x14 | char* | (unnamed, alloc) | LOW | Same | — |
| +0x18 | int | next pointer | LOW | Same | — |

**Grade: LOW — No source file available. Docs note stride 0x1c and "string-pair list node" pattern. Unverifiable.**

---

## Section 83: File Handle Close Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | FileHandle | HIGH | FUN_00566b90: `iVar1 = *param_1;` — int file handle | none |
| +0x10 | int | CloseFlags | HIGH | FUN_00566b90: `param_1[4] == 0` — int, branch on zero | none |

**Grade: HIGH — Both offsets confirmed with exact types from FUN_00566b90.**

---

## Section 84: Display Mode Init Struct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | initialized | HIGH | FUN_00563e00: `if (*param_1 != 0)` — guard check | none |
| +0x04 | int | modeHandle | HIGH | FUN_00563e00: `param_1[1] = iVar1;` — mode init result | none |
| +0x94 | int | bufferHandle | HIGH | FUN_00563e00: `param_1[0x25] = iVar1;` — buffer creation result (0x25*4 = 0x94) | none |
| +0x98 | int | bufferCount | HIGH | FUN_00563e00: `param_1[0x26] = 0;` — set to 0 | none |

**Grade: HIGH — All 4 offsets confirmed with exact types from FUN_00563e00.**

---

## Section 85: CollisionMaterialGroup (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | MaterialID | HIGH | FUN_0044da60: `DAT_007cced0 = 0x2c;` — ID 44. FUN_0044d5e0: `DAT_007ccc80 = 0x13;` — ID 19. | These are GLOBAL arrays, not per-param_1 struct fields |
| +0x04 | int | ParamA | HIGH | Both functions: `_DAT_xxxxx4 = 0;` — zeroed | — |
| +0x08 | int | ParamB | HIGH | Both functions: `DAT_xxxxx8 = 0;` — zeroed | — |
| +0x0C | float | Coefficient | MEDIUM | FUN_0044c9e0 (ID 0xb=11): `_DAT_007cccbc = 0x3f800000` = 1.0f. Others set to 0. | —

### Issues found:
1. **Not per-param_1 struct**: These are GLOBAL variables (DAT_007cccXX, DAT_007ccdXX, DAT_007cceXX), not accessed through a function parameter. The struct representation is inferred from the global array layout.
2. **Actual struct has 6 int fields, not 4**: Each entry writes 6 values (MaterialID, ParamA, ParamB, Coefficient, +0x10, +0x14). Docs only describe 4 fields.
3. **Stride between entries is 0x18 (24 bytes), not 0x10-0x14**: Most adjacent material entries are spaced 0x18 bytes apart (e.g., 0xccc80 → 0xccc98). The extra 8 bytes correspond to the undocumented +0x10 and +0x14 fields.
4. **Coefficient type ambiguity**: Most entries set coefficient to 0 (int zero). Only FUN_0044c9e0 sets `0x3f800000` (1.0f as float). Could be int or float depending on material.

---

## Section 86: CollisionContactSolver (inferred — param_1 in FUN_0045c8f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | byte | ContactCountAccum | MEDIUM | FUN_0045c8f0: `*(uint *)(param_1 + 4)` — read/written as **uint**, not byte! | **TYPE CONFLICT: docs say byte, code shows uint (4 bytes)** |
| +0x08 | int | ContactCount | HIGH | FUN_0045c8f0: `*(int *)(param_1 + 8) += 1` | none |
| +0x14+id*4 | int | ContactActiveFlag[i] | HIGH | FUN_0045c8f0: `*(undefined4 *)(param_1 + 0x14 + uVar6 * 4) = 0` | none |
| +0x1B4+id*4 | float | ContactTimer[i] | HIGH | FUN_0045c8f0: `*(float *)(param_1 + 0x1b4 + uVar6 * 4)` | none |
| +0x354+id | byte | ContactPosition[i] | HIGH | FUN_0045c8f0: `*(byte *)(uVar6 + 0x354 + param_1)` — capped 0x10 | none |
| +0x3BC+id | byte | ContactWrapIndex[i] | HIGH | FUN_0045c8f0: `*(byte *)(uVar6 + 0x3bc + param_1)` — masked 0xF | none |
| +0x1124+id*4 | float | ContactOutput[i] | HIGH | FUN_0045c8f0: `*(undefined4 *)(param_1 + 0x1124 + uVar6 * 4) = 0xbf800000` (-1.0f) | none |

### Issues found:
1. **+0x04 TYPE CONFLICT**: Docs say `byte` but code at line 48 shows `*(uint *)(param_1 + 4)` — reads/writes 4 bytes. Change type to `uint` or `int`.

---

## Section 87: 4. Vehicle Struct (shared — FinishPosition, TeamID, etc.)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x58..0x60 | float[3]? | Velocity | HIGH | FUN_0040adb0: `*(float *)(iVar1 + 0x58/0x5c/0x60)` — 3 floats | none |
| +0x130 | int? | GearData1 | LOW | No .c for FUN_0042e530 | Unverifiable |
| +0x138 | int? | GearData2 | LOW | Same | — |
| +0x144 | int? | GearData3 | LOW | Same | — |
| +0x1f0 | unknown[0x2c0]×4 | WingPosArray | LOW | Same | — |
| +0x3f0 | int? | GearData4 | LOW | Same | — |
| +0x3f8 | int? | GearData5 | LOW | Same | — |
| +0x400 | int? | GearData6 | LOW | Same | — |
| +0x404 | int? | GearData7 | LOW | Same | — |
| +0x4060 | int | FinishPosition | HIGH | FUN_0040c540 + 26 other files: `*(int *)(...+0x4060)` — int | none |
| +0x4064 | int | FinishState | HIGH | FUN_004beb10 + 30 other files: `*(int *)(...+0x4064)`, compared to 0/1/2/3 | none |
| +0x4070 | int | MessageFlag | MEDIUM | Only documented in docs/09 FUN_00419c50 — no .c to verify | Unverifiable without source |
| +0x409c | float | BestLapTime | HIGH | FUN_004bf0a0: `*(float *)(...+0x409c)` — float, compared to threshold | none |
| +0x4894 | int | TeamID | HIGH | 100+ files: `*(int *)(...+0x4894)` — int team identifier | none |
| +0x489c | int | DriverNumber | HIGH | 28 files: `*(int *)(...+0x489c)` or `*(undefined4 *)(...+0x489c)` — int | none |
| +0x6b0 | unknown | AeroData1 | LOW | No .c for FUN_0042e530 | — |
| +0x704..0x70c | float[3]? | Orientation | HIGH | FUN_0040adb0: `*(float *)(DAT_007c54e0 + 0x704/0x708/0x70c)` | none |
| +0x744..0x74c | float[3]? | WorldPos | HIGH | FUN_0040adb0: `*(float *)(iVar1 + 0x744/0x748/0x74c)` | none |
| +0x970 | unknown | AeroData2 | LOW | No .c for FUN_0042e530 | — |
| +0xff0..0x1230 | unknown | WingArray1-8 | LOW | No .c for FUN_0042e530 | — |
| +0x12b0..0x12c4 | unknown | AeroData3-5 | LOW | No .c for FUN_0042e530 | — |

### Issues found:
1. **FUN_0042e530 has no .c file** — all gear/wing/aero offsets (16 offsets) are unverifiable. LOW confidence.
2. **+0x4070 (MessageFlag)**: Only cited from FUN_00419c50 in docs/09 — no .c found. MEDIUM confidence.
3. **Common offsets (Velocity, FinishPosition, FinishState, BestLapTime, TeamID, DriverNumber, Orientation, WorldPos)**: HIGH confidence — verified in 10-100+ files each.

---

## Section 88: AudioSampleRingBuffer (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1018 | double | LastSampleTime | MEDIUM | FUN_004ef2e0: `*(float *)(param_1 + 0x1018)` — **read/written as float, NOT double!** | **TYPE CONFLICT: docs say double, code shows float** |
| +0x101c | short[5] | LastFrameData | MEDIUM | FUN_004ef2e0: reads 18 bytes starting at +0x101c (4+4+4+4+2), compares 10 shorts (20 bytes) | **SIZE MISMATCH: short[5] = 10 bytes, but code reads 18+ bytes** |

### Issues found:
1. **+0x1018 TYPE CONFLICT**: Docs say `double` (8 bytes), but FUN_004ef2e0 reads/writes as `*(float *)(param_1 + 0x1018)` (4 bytes). Change to `float`.
2. **+0x1018 SIZE**: The next field at +0x101c is only separated by 4 bytes, confirming +0x1018 is 4 bytes (float), not 8 (double).
3. **+0x101c SIZE MISMATCH**: Docs say `short[5]` (10 bytes). Code reads from +0x101c through +0x102d (18 bytes: dword at 0x101c, dword at 0x1020, dword at 0x1024, dword at 0x1028, word at 0x102c), then compares 10 shorts (20 bytes). The actual data region is at least 18 bytes, may extend to 20 with next field.

---

## Section 89: Struct 7: Linked List Node (FUN_004bf790)

| Offset | Size | Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|------|------|-------------|------------|-------------|-----------|
| +0x00 | 8 | struct | EntrySubNode | LOW | No .c file for FUN_004bf790 | Docs note overlap with +0x04 — impossible layout |
| +0x04 | 4 | ptr | NextNode | LOW | Same | OVERLAP with +0x00 (docs note this) |
| +0x08 | 1 | byte | Flag | LOW | Same | Set to 1 |

### Issues found:
1. **No source file**: FUN_004bf790 has no .c available. Entire section unverifiable.
2. **Structural overlap**: Docs note "+0x00 and +0x04 overlap by 4 bytes" — the subnode (8 bytes at +0x00) overlaps with NextNode ptr (4 bytes at +0x04). Layout is 0xc bytes total with subnode inline: [ID(4)][QA(4)][NextPtr(4)][Flag(1)] = 13 bytes but described as 12.

---

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| WheelFloatArray | +0x6c | float | FUN_004e3d00 line 127 | Force factor `param_1[0x1b]` — not in docs |
| WheelFloatArray | +0x70 | float | FUN_004e3d00 line 127 | Force factor `param_1[0x1c]` — not in docs |
| CollisionMaterialGroup | +0x10 | int | All material init functions | Unnamed field at +0x10 — zeroed in all entries |
| CollisionMaterialGroup | +0x14 | int | All material init functions | Unnamed field at +0x14 — zeroed in all entries |
| Vehicle (camera/scene) | +0x14 | int | FUN_0040adb0 line 29 | Animation/frame selector — NOT vehicle velocity |
| Vehicle (camera/scene) | +0x0c | int* | FUN_0040adb0 line 30 | Scene node pointer array — NOT vehicle position |
| Vehicle (camera/scene) | +0x04 | int | FUN_0040adb0 line 34 | Active flag — NOT vehicle velocity |

---

=== SUMMARY ===

| Section | Name | Grade | Type Conflicts | Size Conflicts | Missing .c |
|---------|------|-------|----------------|----------------|------------|
| 76 | OpponentStateStruct | MEDIUM | 2 (+0x4fc double/float, +0x83c int/float) | 0 | FUN_004c0cc0 |
| 77 | CollisionContactState | HIGH | 0 | 0 | — |
| 78 | GameConfig | LOW | 0 | 0 | FUN_004216f0 |
| 79 | ConstraintGroupStruct | HIGH | 0 | 0 | — |
| 80 | AudioSceneUpdateStruct | MEDIUM | 0 | 0 | — |
| 81 | WheelFloatArray | HIGH | 1 naming overlap (float[3] vs separate) | 0 | — |
| 82 | AutoLoadEntry | LOW | 0 | 0 | FUN_00432e70 |
| 83 | FileHandleClose | HIGH | 0 | 0 | — |
| 84 | DisplayModeInit | HIGH | 0 | 0 | — |
| 85 | CollisionMaterialGroup | MEDIUM | 1 (global vs struct, 6 vs 4 fields) | 1 (stride 0x18 vs 0x10) | — |
| 86 | CollisionContactSolver | HIGH | 1 (+0x04 byte vs uint) | 0 | — |
| 87 | VehicleStruct | MIXED | 0 | 0 | FUN_0042e530, FUN_00419c50, FUN_0041d630 |
| 88 | AudioSampleRingBuffer | MEDIUM | 1 (+0x1018 double vs float) | 1 (+0x101c short[5] vs 18+ bytes) | — |
| 89 | LinkedListNode | LOW | 1 (structural overlap) | 0 | FUN_004bf790 |

**Total type conflicts: 7**
**Total structs requiring source recovery: 5 (Sections 78, 82, parts of 76, 87, 89)**
