# WORKER F — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker F of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_F.md

## YOUR STRUCT SECTIONS (14)

--- Section 76: OpponentStateStruct (param_2 — opponent/driver in overtaking) (7 offsets) ---
## OpponentStateStruct (param_2 — opponent/driver in overtaking)

Based on FUN_0042a780 (AI pass score) and FUN_004c0cc0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x70 | float | OpponentSpeed | FUN_0042a780 | |
| +0x74 | float | OpponentDistance | FUN_0042a780 | |
| +0x78 | float | OpponentPosition | FUN_0042a780 | |
| +0x84 | float | OpponentSpeedDelta | FUN_0042a780 | |
| +0x4fc | float | LapTimeDelta | FUN_004c0cc0 | |
| +0x69c | float | OvertakeGap | FUN_004c0cc0 | |
| +0x83c | float | OvertakeTarget | FUN_004c0cc0 | |

---



--- Section 77: CollisionContactState (10 offsets) ---
## CollisionContactState

Based on FUN_0054d7a0, FUN_00507845. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | uint | CollisionStateFlags | FUN_0054d7a0 | Bits 0-2 state, bit 4 mode |
| +0x18 | float | ContactMargin | FUN_0054d7a0 | Tolerance |
| +0xf4 | float | OuterRadius | FUN_0054d7a0 | Bounding sphere outer |
| +0xf8 | float | InnerRadius | FUN_0054d7a0 | Bounding sphere inner |
| +0xfc | int | ContactIteration | FUN_0054d7a0 | Solver iteration count |
| +0x1c | float | RefX | FUN_00507845 | Reference X for contact matching |
| +0x20 | float | RefY | FUN_00507845 | |
| +0x24 | float | RefZ | FUN_00507845 | |
| +0x28 | float | RefW | FUN_00507845 | Penetration/distance |
| +0x1058 | int | ContactCount | FUN_00507845 | Contact entries |

---



--- Section 78: 6. GameConfig (inferred — FUN_004216f0) (15 offsets) ---
## 6. GameConfig (inferred — FUN_004216f0)

Config directory/option table. Range +0xb8 to +0xe8.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb8 | int | Field_0xb8 | FUN_004216f0 |  |
| +0xbc | int | Field_0xbc | FUN_004216f0 |  |
| +0xc0 | int | Field_0xc0 | FUN_004216f0 |  |
| +0xc4 | int | Field_0xc4 | FUN_004216f0 | Default 22 (0x16) |
| +0xc8 | bool | Field_0xc8 | FUN_004216f0 | Default 1 |
| +0xcc | int | Field_0xcc | FUN_004216f0 |  |
| +0xd0 | int | Field_0xd0 | FUN_004216f0 |  |
| +0xd4 | byte | Field_0xd4 | FUN_004216f0 |  |
| +0xd5 | byte | Field_0xd5 | FUN_004216f0 | Default 1 |
| +0xd6 | byte | Field_0xd6 | FUN_004216f0 |  |
| +0xd8 | int | Field_0xd8 | FUN_004216f0 | Default 1 |
| +0xdc | int | Field_0xdc | FUN_004216f0 | Default 1 |
| +0xe0 | int | Field_0xe0 | FUN_004216f0 |  |
| +0xe4 | int | Field_0xe4 | FUN_004216f0 | Default 1 |
| +0xe8 | float | Field_0xe8 | FUN_004216f0 | -1.0f (disabled) |



--- Section 79: ConstraintGroupStruct (param_1 for FUN_0056ee40) (7 offsets) ---
## ConstraintGroupStruct (param_1 for FUN_0056ee40)

Constraint solver group descriptor.

Based on 1 function observation (FUN_0056ee40). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x08 | int | Group1Count | Body count for group 1 |
| +0x0c | int* | Group1Array | Body index array |
| +0x10 | int | Group2Count | Pair count for group 2 |
| +0x14 | int* | Group2Array | Pair array |
| +0x18 | int | Group3Count | Body count for group 3 |
| +0x1c | int* | Group3Array | Body array |
| +0x2c | double* | GlobalPosArray | Double-precision position array |

---



--- Section 80: AudioSceneUpdateStruct (1 offsets) ---
## AudioSceneUpdateStruct

From FUN_004532d0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xd80 | int | SceneEntryCount | Number of scene entries |

---



--- Section 81: WheelFloatArray (per-wheel state as float[]) (inferred) (22 offsets) ---
## WheelFloatArray (per-wheel state as float[]) (inferred)

Based on 1 function observation (FUN_004e3d00). Confidence: medium.

Wheel state represented as float array (int-indexed at param_1[N]).

| Float Index | Real Offset | Type | Field Name | Observed in | Notes |
|-------------|-------------|------|------------|-------------|-------|
| 0x0e | +0x38 | float[3] | SuspAxisVectors | FUN_004e3d00 | Suspension axis (3 floats) |
| 0x0f | +0x3c | float | SuspType | FUN_004e3d00 | 0=double-wishbone, 1=rigid axle |
| 0x10 | +0x40 | float | WheelNormal | FUN_004e3d00 | |
| 0x11 | +0x44 | float | RideHeight | FUN_004e3d00 | Current travel |
| 0x12 | +0x48 | float | SpringK | FUN_004e3d00 | Hardcoded 5.0 |
| 0x13 | +0x4c | float | SpringForce | FUN_004e3d00 | Computed |
| 0x14 | +0x50 | float | DampingEnabled | FUN_004e3d00 | 1.0 = enabled |
| 0x15 | +0x54 | float | DamperForce | FUN_004e3d00 | Accumulator |
| 0x16 | +0x58 | float | BumpForce | FUN_004e3d00 | |
| 0x24 | +0x90 | float | WheelRadius | FUN_004e3d00 | |
| 0x25 | +0x94 | float | DampingFactor | FUN_004e3d00 | |
| 0x27 | +0x9c | float | SpringRateMult | FUN_004e3d00 | |
| 0x2a | +0xa8 | float | ProgressiveRate | FUN_004e3d00 | |
| 0x2b | +0xac | float | BumpStopTravel | FUN_004e3d00 | |
| 0x2c | +0xb0 | float | AlignmentCamber | FUN_004e3d00 | |
| 0x2d | +0xb4 | float | AlignmentCaster | FUN_004e3d00 | |
| 0x2e | +0xb8 | float | (alignment) | FUN_004e3d00 | |
| 0x2f | +0xbc | float | SteerCasterCos | FUN_004e3d00 | Caster angle cosine |
| 0x30 | +0xc0 | float | SteerKingpin | FUN_004e3d00 | Kingpin angle |
| 0x31 | +0xc4 | float | LastContactX | FUN_004e3d00 | |
| 0x32 | +0xc8 | float | LastContactZ | FUN_004e3d00 | |
| 0x36 | +0xd8 | float[3] | WheelVelocity | FUN_004e3d00 | 3-component output velocity |

---



--- Section 82: AutoLoadEntry Linked List Node Struct (stride 0x1c) (6 offsets) ---
## AutoLoadEntry Linked List Node Struct (stride 0x1c)

Based on 1 function observation (FUN_00432e70). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | Track path (alloc) | FUN_00432e70 | string allocation |
| +0x04 | int | next pointer | FUN_00432e70 | -1 = end |
| +0x08 | char* | Classes (alloc) | FUN_00432e70 | string allocation |
| +0x0c | int | next pointer | FUN_00432e70 | -1 = end |
| +0x14 | char* | (unnamed, alloc) | FUN_00432e70 | string allocation |
| +0x18 | int | next pointer | FUN_00432e70 | -1 = end |

Note: This appears to be a string-pair list node where each string pointer is followed by a "next" link. Stride 0x1c.

---



--- Section 83: File Handle Close Struct (2 offsets) ---
## File Handle Close Struct

Based on 1 function observation (FUN_00566b90). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | FileHandle | FUN_00566b90 | handle to close |
| +0x10 | int | CloseFlags | FUN_00566b90 | 0 → method A, else → method B |

---



--- Section 84: Display Mode Init Struct (inferred) (4 offsets) ---
## Display Mode Init Struct (inferred)

Used by FUN_00563e00. Guards against re-init, stores mode/buffer handles.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | initialized | FUN_00563e00 | Non-zero = already done |
| +0x04 | int | modeHandle | FUN_00563e00 | Display mode init result |
| +0x94 | int | bufferHandle | FUN_00563e00 | Buffer creation result |
| +0x98 | int | bufferCount | FUN_00563e00 | Set to 0 |



--- Section 85: CollisionMaterialGroup (inferred) (4 offsets) ---
## CollisionMaterialGroup (inferred)

Based on 8 function observations (FUN_0044da60, FUN_0044d5e0, various material init functions). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | MaterialID | Multiple material init functions | Type/subtype ID (varies: 7, 19, 40, 52, 80, 100) |
| +0x04 | int | ParamA | init patterns | Zeroed |
| +0x08 | int | ParamB | init patterns | Zeroed |
| +0x0C | float | Coefficient | init patterns | 1.0f (restitution default) or 18000 (range) |

Stride 0x10–0x14 per material entry based on pattern.

---



--- Section 86: CollisionContactSolver (inferred — param_1 in FUN_0045c8f0) (7 offsets) ---
## CollisionContactSolver (inferred — param_1 in FUN_0045c8f0)

Based on FUN_0045c8f0. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | byte | ContactCountAccum | Accumulated byte count |
| +0x08 | int | ContactCount | Contact count accumulator |
| +0x14+id*4 | int | ContactActiveFlag[i] | Per-contact active flag |
| +0x1B4+id*4 | float | ContactTimer[i] | Per-contact timer |
| +0x354+id | byte | ContactPosition[i] | Per-contact position index (capped 0x10) |
| +0x3BC+id | byte | ContactWrapIndex[i] | Per-contact wrap index (masked to 0xF) |
| +0x1124+id*4 | float | ContactOutput[i] | Per-contact output value |

---



--- Section 87: 4. Vehicle Struct (shared — FinishPosition, TeamID, etc.) (30 offsets) ---
## 4. Vehicle Struct (shared — FinishPosition, TeamID, etc.)

Based on observations from FUN_0041d630, FUN_00419c50, FUN_0040c540, FUN_0040adb0, FUN_0045d890, FUN_0042e530. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x58..0x60 | float[3]? | Velocity | FUN_0040adb0 | Velocity vector (also +0x58/0x5c/0x60 in FUN_0040b710) |
| +0x130 | int? | GearData1 | FUN_0042e530 | Gear ratio data |
| +0x138 | int? | GearData2 | FUN_0042e530 | Gear ratio data |
| +0x144 | int? | GearData3 | FUN_0042e530 | Gear ratio data |
| +0x1f0 | unknown[0x2c0]×4 | WingPosArray | FUN_0042e530 | Wing position arrays, stride 0x2c0 × 4 entries |
| +0x3f0 | int? | GearData4 | FUN_0042e530 | Gear ratio data |
| +0x3f8 | int? | GearData5 | FUN_0042e530 | Gear ratio data |
| +0x400 | int? | GearData6 | FUN_0042e530 | Gear ratio data |
| +0x404 | int? | GearData7 | FUN_0042e530 | Gear ratio data |
| +0x4060 | int | FinishPosition | FUN_0041d630, FUN_0040c540 | Finish position |
| +0x4064 | int | FinishState | FUN_0041d630, FUN_00419c50 | 0=running, 1=finished, 2=DNF, 3=DSQ |
| +0x4070 | int | MessageFlag | FUN_00419c50 | Previous commentary message flag |
| +0x409c | float | BestLapTime | FUN_0041d630, FUN_0045d890 | Best overall lap time |
| +0x4894 | int | TeamID | FUN_00419c50, FUN_0040c540, FUN_0045d890 | Team identifier |
| +0x489c | int | DriverNumber | FUN_0041d630 | Driver number |
| +0x6b0 | unknown | AeroData1 | FUN_0042e530 | Aero data |
| +0x704..0x70c | float[3]? | Orientation | FUN_0040adb0 | Orientation vector |
| +0x744..0x74c | float[3]? | WorldPos | FUN_0040adb0 | World position |
| +0x970 | unknown | AeroData2 | FUN_0042e530 | Aero data |
| +0xff0 | unknown | WingArray1 | FUN_0042e530 | Wing position array entry |
| +0x1030 | unknown | WingArray2 | FUN_0042e530 | Wing position array entry |
| +0x1070 | unknown | WingArray3 | FUN_0042e530 | Wing position array entry |
| +0x10b0 | unknown | WingArray4 | FUN_0042e530 | Wing position array entry |
| +0x1170 | unknown | WingArray5 | FUN_0042e530 | Wing position array entry |
| +0x11b0 | unknown | WingArray6 | FUN_0042e530 | Wing position array entry |
| +0x11f0 | unknown | WingArray7 | FUN_0042e530 | Wing position array entry |
| +0x1230 | unknown | WingArray8 | FUN_0042e530 | Wing position array entry |
| +0x12b0 | unknown | AeroData3 | FUN_0042e530 | Aero data |
| +0x12c0 | unknown | AeroData4 | FUN_0042e530 | Aero data |
| +0x12c4 | unknown | AeroData5 | FUN_0042e530 | Aero data |

Consistency check: +0x4060 (FinishPosition) and +0x4894 (TeamID) confirmed by 2+ functions each. +0x4064 (FinishState) confirmed by 2 functions with same value 2=DNF.

---



--- Section 88: AudioSampleRingBuffer (inferred) (2 offsets) ---
## AudioSampleRingBuffer (inferred)

Based on 1 function (FUN_004ef2e0). Confidence: medium.

Ring buffer for audio sample streaming with deduplication.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1018 | double | LastSampleTime | FUN_004ef2e0 | Timestamp of last frame push |
| +0x101c | short[5] | LastFrameData | FUN_004ef2e0 | Previous frame for dedup (10 bytes) |

---



--- Section 89: Struct 7: Linked List Node (FUN_004bf790) (3 offsets) ---
## Struct 7: Linked List Node (FUN_004bf790)

Based on 1 observation. Confidence: **medium**.

| Offset | Size | Type | Field Name | Notes |
|--------|------|------|------------|-------|
| +0x00 | 8 | struct | EntrySubNode | 8 bytes: ID (4) + QA score float (4) |
| +0x04 | 4 | ptr | NextNode | Next linked list node pointer |
| +0x08 | 1 | byte | Flag | Set to 1 |

**Note:** +0x00 and +0x04 overlap by 4 bytes. The node is 0xc (12) bytes total, with sub-node contained inline. Layout appears to be: [subnode 8 bytes][next ptr 4 bytes][flag byte 1 byte] with alignment padding.

---



## TASK
For each struct section:
1. Extract all offset rows from the section (lines with `| +0x`)
2. For each offset: grep analyzed/ for files containing that offset pattern
   e.g. `grep -rl "+ 0x1330" analysis_pipeline/analyzed/`
3. Read matched .c files and verify: does the dereference type match docs/13?
   - `*(double *)(param + 0xXXX)` → double
   - `*(float *)(param + 0xXXX)` → float
   - `*(int *)(param + 0xXXX)` → int/dword
   - `param_1[0x4a]` → int-indexed, byte offset = 0x4a × 4
4. Grade confidence: HIGH (3+ agree), MEDIUM (1-2 agree), LOW (no .c evidence)
5. Flag CONFLICTS: same offset claimed as different types

## OUTPUT FORMAT

```
=== AUDIT RESULTS ===
## StructName

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0000 | int | field_name | HIGH | 5 files agree | none |
| +0x1330 | double | ??? | LOW | 0 files | FUN_X says float |

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
```

## RULES
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_F.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
