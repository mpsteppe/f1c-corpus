# WORKER E — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker E of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_E.md

## YOUR STRUCT SECTIONS (15)

--- Section 61: ScoringDB / StandingsEntry (per-driver season data) (19 offsets) ---
## ScoringDB / StandingsEntry (per-driver season data)

Based on 4+ function observations. Confidence: **high**.

Stride 0x1B4 between entries.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | CategoryID | FUN_00435390 | -1=unset |
| +0x04 | int | Reserved0 | FUN_00435390 | Zeroed |
| +0x10 | float | Weight | FUN_00435390 | ~1.875 |
| +0x18 | int[48] | FINISHPOSITION | FUN_004c03f0, FUN_004c07f0 | Max 48 races |
| +0xd8 | int[48] | FINISHPOINTS | FUN_004c03f0, FUN_004c07f0 | Points per race |
| +0x198 | int | SEASONPOINTS | FUN_004c03f0, FUN_004c0f60 | AccumulatorA |
| +0x19c | int | POINTSPOSITION | FUN_004c03f0 | AccumulatorB |
| +0x1a0 | int | POLESTAKEN | FUN_004c03f0 | AccumulatorC |
| +0x1a4 | int | ORIGINALGRIDPOSITION | FUN_004c03f0 | Reserved |
| +0x1a8 | int | CURRENTGRIDPOSITION | FUN_004c03f0 | Sentinel -1 |
| +0x1ac | int | CONTROLTYPE | FUN_004c03f0 | Sentinel -1 |
| +0x1b0 | byte | ACTIVE | FUN_004c03f0, FUN_004c0f60, FUN_004c1370 | Bool, stride 0x1b4 |
| +0xb108 | int | RankEntry0 | FUN_004c0f60 | Rank count |
| +0xb120 | ptr | PitAllocA | FUN_004c0b10 | Freed on cleanup |
| +0xb128 | ptr | PitAllocB | FUN_004c0b10 | Freed on cleanup |
| +0xb144 | int | SeasonStatus | FUN_004c03f0 | |
| +0xb148 | int | CurrentRace / UnknownFlags | FUN_004c03f0, FUN_004c11d0 | |
| +0xb14c | int | RaceSession / SessionType / TireWearValue | FUN_004c03f0, FUN_004c0f60, FUN_004c11c0, FUN_004c15a0 | Compared to 7 (race) |
| +0xb150 | byte | RaceOver / RankingsDirtyFlag / PitPhaseSubStep | FUN_004c03f0, FUN_004c0f60, FUN_004c15a0 | 0=needs compute |

---



--- Section 62: AIStateBuffer (param_1 — AI history buffer) (4 offsets) ---
## AIStateBuffer (param_1 — AI history buffer)

Based on FUN_0042ec60, FUN_0042ebc0. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | byte | InitializedFlag | FUN_0042ec60 | Set to 1 |
| +0x0c4 | dword[4][11] | HistoryBuffer1 | FUN_0042ec60 | Stride 0x40 |
| +0xbc4 | dword[55] | HistoryBuffer2 | FUN_0042ec60 | Stride 0x40 |
| +0x1ca8 | float[4] | SmoothCoeff | FUN_0042ec60, FUN_0042e320 | 0.5f |

---



--- Section 63: 5. CamMan (docs/01) (7 offsets) ---
## 5. CamMan (docs/01)

Camera manager struct (FUN_0040c9e0, FUN_0040cce0).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | MAINVIEWSceneNode | FUN_0040cce0 |  |
| +0x08 | ptr | CurrentCamera | FUN_0040cce0 |  |
| +0x18 | ptr | CameraObject1 | FUN_0040cce0 |  |
| +0x1c | ptr | CameraObject2 | FUN_0040cce0 |  |
| +0x20 | ptr | CameraObject3 | FUN_0040cce0 |  |
| +0x2e | byte | Flag | FUN_0040c9e0 |  |
| +0x38 | int | CameraIndex | FUN_0040c9e0 | -1=none |



--- Section 64: BodyStateArray (stride 0x244) (23 offsets) ---
## BodyStateArray (stride 0x244)

Array of body states for multi-body physics.

Based on 3+ function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x04 | double | PosX | FUN_0056d1c0 | Body position |
| +0x0c | double | PosY | FUN_0056d1c0 | Body position |
| +0x14 | double | PosZ | FUN_0056d1c0 | Body position |
| +0x1c | double | Rot00 | FUN_0056d1c0 | Rotation matrix element |
| +0x24 | double | Rot01 | FUN_0056d1c0 | Rotation matrix element |
| +0x2c | double | Rot02 | FUN_0056d1c0 | Rotation matrix element |
| +0x34 | double | Rot10 | FUN_0056d1c0 | Rotation matrix element |
| +0x3c | double | Rot11 | FUN_0056d1c0 | Rotation matrix element |
| +0x44 | double | Rot12 | FUN_0056d1c0 | Rotation matrix element |
| +0x4c | double | Rot20 | FUN_0056d1c0 | Rotation matrix element |
| +0x54 | double | Rot21 | FUN_0056d1c0 | Rotation matrix element |
| +0x5c | double | Rot22 | FUN_0056d1c0 | Rotation matrix element |
| +0x60 | double | PosDeltaX | FUN_0041ad0, FUN_0041d60 | Position offset |
| +0x64 | double | PosDeltaY | FUN_0041ad0, FUN_0041d60 | Position offset |
| +0x6c | double | PosDeltaZ | FUN_0041ad0, FUN_0041d60 | Position offset / angular vel X |
| +0x74 | double | AngularVelY | FUN_0041ad0 | Angular velocity Y |
| +0x7c | double | AngularVelZ | FUN_0041ad0 | Angular velocity Z |
| +0x134 | double | AngMomX | FUN_0041d60 | Angular momentum X |
| +0x13c | double | AngMomY | FUN_0041d60 | Angular momentum Y |
| +0x144 | double | AngMomZ | FUN_0041d60 | Angular momentum Z |
| +0x14c | double | ForceX | FUN_0041d60 | Force accumulation X |
| +0x154 | double | ForceY | FUN_0041d60 | Force accumulation Y |
| +0x15c | double | ForceZ | FUN_0041d60 | Force accumulation Z |
| Stride: 0x244 (580 bytes) | | | FUN_0041d60 | Per-body state |

---



--- Section 65: PerElementForceScalingStruct (3 offsets) ---
## PerElementForceScalingStruct

From FUN_0059d9d7. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x39d4 | float* | ForceArrayBase | Base of per-element force array |
| +0x39f8 | int | ElementCount | Number of elements to process |
| +0x3a0c | float | LocalForceMultiplier | Per-instance scaling factor |

---



--- Section 66: SuspensionForceValidator (inferred) (3 offsets) ---
## SuspensionForceValidator (inferred)

Based on 1 function observation (FUN_004f3240). Confidence: low.

Per-axis force validation data. Reads 3 doubles at stride 0x18 (3 axes × 2 directions).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | double | ForceX | FUN_004f3240 | Per-axis force coefficient |
| +0x18 | double | ForceY | FUN_004f3240 | Stride 0x18 between axes |
| +0x30 | double | ForceZ | FUN_004f3240 | |

---



--- Section 67: AutoLoadEntry Struct (int-indexed) (4 offsets) ---
## AutoLoadEntry Struct (int-indexed)

Based on 2 function observations (FUN_00432bf0 writer, FUN_00432a70 reader). Confidence: high — reader and writer agree on field names.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | Track path | FUN_00432bf0, FUN_00432a70 | [0] |
| +0x02 | char* | Classes | FUN_00432bf0, FUN_00432a70 | [2] |
| +0x04 | int | Session | FUN_00432bf0, FUN_00432a70 | [4] |
| +0x05 | char* | (unnamed string) | FUN_00432bf0, FUN_00432a70 | [5] |

**Conflict:** FUN_00432a70 stores offsets as byte addresses: +0x00 Track, +0x08 Classes, +0x10 Session, +0x14 (unnamed). These are actual byte offsets (8 bytes apart = 2 int-indexed slots apart). Compatible because int-indexed: [0] = +0x00, [2] = +0x08, [4] = +0x10, [5] = +0x14. ✅ Consistent.

---



--- Section 68: File Read Loop Struct (5 offsets) ---
## File Read Loop Struct

Based on 1 function observation (FUN_005352d0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | zeroed on start | FUN_005352d0 | |
| +0x10 | int | bufferAvail | FUN_005352d0 | available bytes count |
| +0x40 | void* | buffer | FUN_005352d0 | data buffer |
| +0x48 | void* | readBufPtr | FUN_005352d0 | read position |
| +0x5c | char | modeFlag | FUN_005352d0 | 'w' = write mode |

---



--- Section 69: Texture Allocation Format Struct (inferred) (3 offsets) ---
## Texture Allocation Format Struct (inferred)

Used by FUN_00558d10. Dual-format texture allocation with state flag.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | uint | flags | FUN_00558d10 | Bit 0x100 = allocated |
| +0x2c | int | multiplier | FUN_00558d10 | Size multiplier for format path 2 |
| +0x50 | ptr | subStruct | FUN_00558d10 | Resource array ptr (stride 0x40) |



--- Section 70: CollisionGridParams (inferred — broadphase grid state) (4 offsets) ---
## CollisionGridParams (inferred — broadphase grid state)

Based on 8 function observations (FUN_0044d520/FUN_0044dca0/etc — grid init functions, FUN_0044ba40). Confidence: **medium**.

Many init functions across 0x007cxxxx globals appear to follow this pattern per grid cell:
| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | CellCount | Multiple init functions | Grid cell count (varies: 4, 16, 37, 49, 77, 97) |
| +0x04 | int | Flags/Counter | init patterns | Zeroed field |
| +0x08 | int | Sentinel/Scale | init patterns | Often -1.0f (0xBF800000) as sentinel or 1.0f |
| +0x0C | int | MaxDistance | init patterns | 9000 or 27000 for search radius |

Per-grid-cell stride = 0x10 (16 bytes) based on the 4-field pattern.

---



--- Section 71: Small structs (single observation) (8 offsets) ---
## Small structs (single observation)

### InvDistance (FUN_0045f2a0)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | float | InvDistance | 1.0/distance |

### FloatFraction (FUN_00464ef0)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x68 | float | ComputedFraction | Iterative float conversion result |

### CollisionFillBlock (FUN_0044f070)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x27C | byte[0x100] | FillBlock | 0x40 dword fill block |

### ConstraintSolverState (FUN_00454250)
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x040 | float | Stiffness | Constraint stiffness |
| +0x060 | float | RestValue | Constraint rest value |
| +0x398 | float | CurrentValue | Constraint current value |
| +0xD88 | float[] | ConstraintSet1 | Primary constraint set |
| +0x1184 | float[] | ConstraintSet2 | Secondary constraint set |

---



--- Section 72: 3. Cockpit Dashboard Struct (inferred) (16 offsets) ---
## 3. Cockpit Dashboard Struct (inferred)

Based on 1 function observation (FUN_0049ca00). Confidence: medium.

**Gauge textures (array, stride 0x4c):**

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x60 | char*? | TAC_01_texture | FUN_0049ca00 | Tachometer texture |
| +0xac | char*? | WATERTEMP_texture | FUN_0049ca00 | Water temp gauge |
| +0xf8 | char*? | OILTEMP_texture | FUN_0049ca00 | Oil temp gauge |
| +0x144 | char*? | OILPRESS_texture | FUN_0049ca00 | Oil pressure gauge |
| +0x190 | char*? | FUEL_texture | FUN_0049ca00 | Fuel gauge |

**LED indicators (at param_1 + 0x20–0x48):**

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | char*? | LED165 | FUN_0049ca00 | 165°C temp LED |
| +0x24 | char*? | LED170 | FUN_0049ca00 | 170°C temp LED |
| +0x28 | char*? | LED175 | FUN_0049ca00 | 175°C temp LED |
| +0x2c | char*? | LED182 | FUN_0049ca00 | 182°C temp LED |
| +0x30 | char*? | LEDSL | FUN_0049ca00 | Shift light LED |
| +0x34 | char*? | LEDPSY | FUN_0049ca00 | Pit speed yellow LED |
| +0x38 | char*? | LEDPSR | FUN_0049ca00 | Pit speed red LED |
| +0x3c | char*? | LEDLF | FUN_0049ca00 | Low fuel LED |
| +0x40 | char*? | LEDFR | FUN_0049ca00 | Fuel red LED |
| +0x44 | char*? | LEDFY | FUN_0049ca00 | Fuel yellow LED |
| +0x48 | char*? | LEDFB | FUN_0049ca00 | Fuel blue LED |

---



--- Section 73: PacketQueueStruct (inferred) (5 offsets) ---
## PacketQueueStruct (inferred)

Based on 1 function (FUN_0057afa0). Confidence: medium.

Linked-list packet queue with head/current/tail pointers.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | byte | ActiveFlag | FUN_0057afa0 | Activity flag, reset to 0 |
| +0x08 | int* | HeadPtr | FUN_0057afa0 | List head |
| +0x0c | int* | CurrentPtr | FUN_0057afa0 | Current insertion point |
| +0x10 | int* | TailPtr | FUN_0057afa0 | List tail |
| +0x14 | uint | Counter | FUN_0057afa0 | Total packet count |

---



--- Section 74: Struct 6: Shift Struct (param_1 in FUN_0042b8d0) (3 offsets) ---
## Struct 6: Shift Struct (param_1 in FUN_0042b8d0)

Based on 1 observation. Confidence: **medium**.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00 | float | UpshiftRPM | AI upshift RPM target |
| +0x04 | float | DownshiftRPM | AI downshift RPM target |
| +0x08 | int | DisallowedFlags | Bitmask of disallowed ranges |

---



--- Section 75: Summary (0 offsets) ---
## Summary

- **WeatherState**: 30 fields documented across 0x0c–0x1c4 range. Struct size >= 0x1c8 (452+ bytes). High confidence.
- **WeatherChangeNode**: 4 fields, stride 0x10. High confidence (traversal pattern confirmed in 2 functions).
- **UIComboBox**: 7 fields documented. Medium confidence (single function observation). Likely shared widget type used by multiple UI screens.

No conflicts detected across all observations — all offset types and uses are consistent.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_E.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
