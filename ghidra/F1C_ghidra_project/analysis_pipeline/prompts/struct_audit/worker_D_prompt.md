# WORKER D — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker D of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_D.md

## YOUR STRUCT SECTIONS (15)

--- Section 46: ReplaySaveStruct (param_1 — replay context) (25 offsets) ---
## ReplaySaveStruct (param_1 — replay context)

Based on 2 function observations (FUN_004b7500 replay save, FUN_004ba1f0 replay load). Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | ptr | ListHead | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004bbfc0 | Sorted linked list anchor |
| +0x6c4 | ptr | ListTail | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Linked list tail |
| +0x6c8 | ptr | ListCursor / CurrentNode | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Iterator position |
| +0x6cc | int | ListCount / ItemCount | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Element count |
| +0x6d0 | byte | SortedFlag / DirtyFlag | FUN_004b81a0, FUN_004b7500, FUN_004b8360 | 1=sorted, set to 1 on change |
| +0x6d4 | ptr | LinkedListHead0 | FUN_004b5a30 | Linked list of widgets |
| +0x6e4 | int | ReplayDataPresent | FUN_004b7500 | Flag |
| +0x6e8 | int | HeaderDataSource | FUN_004b7500 | |
| +0x700 | int | SaveState | FUN_004b7500 | 0/1 |
| +0x704 | ptr | InputDataSource / ComponentPtr4 | FUN_004b7500, FUN_004b5a30 | |
| +0x70c | char[] | TrackName / ComponentPtr3 | FUN_004b7500, FUN_004b5a30 | File path base |
| +0x714 | ptr | EntryLinkedListHead | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | Linked list anchor |
| +0x718 | ptr | EntryLinkedListTail | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | |
| +0x71c | ptr | TraversalCursor | FUN_004b7500, FUN_004b7c80, FUN_004b5f60 | |
| +0x720 | int | LinkedListCount | FUN_004b5f60 | |
| +0x724 | ptr | ComponentPtr2 | FUN_004b5a30 | Freed object |
| +0x72c | ptr | ComponentPtr1 | FUN_004b5a30 | Freed object |
| +0x9a4 | int | SubfolderIndex | FUN_004b7500 | 0–4 |
| +0xf30 | float | LapTimeStart / MinValue | FUN_004b7500, FUN_004b86e0 | Session timing |
| +0xf34 | float | LapTimeEnd / MaxValue | FUN_004b7500, FUN_004b86e0 | |
| +0xf38 | float | Value/Threshold/ScoreValue | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8790, FUN_004b86e0 | Sort key / comparison |
| +0xf3c | float | PreviousValue | FUN_004b86e0 | |
| +0xf81 | byte | Mode | FUN_004b86e0 | 0=wrap, non-0=clamp |
| +0xf8c | int | ServiceAnimState | FUN_004b9e40 | Wheel service animation |
| +0xf94 | char[] | OutputFilePath / ComponentPtr0 | FUN_004b7500, FUN_004b5a30 | Output path |

---



--- Section 47: CarPartVisibility (damaged parts) (8 offsets) ---
## CarPartVisibility (damaged parts)

Based on FUN_004ae490. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb10 | int | PartFrontWing1 | FUN_004ae490 | Visibility flag |
| +0xb34 | int | PartFrontWing2 | FUN_004ae490 | |
| +0xb58 | int | PartFrontWing3 | FUN_004ae490 | |
| +0x1ac8 | int | RepairState | FUN_004ae490 | 0=none, 1=repairing, 2=not |
| +0x1c30 | int | PartRearWing | FUN_004ae490 | |
| +0x2348 | float | AnimParamA | FUN_004ae490 | 0.05f or 0.5f |
| +0x236c | float | AnimParamB | FUN_004ae490 | 0.05f or 0.5f |
| +0x26f0–0x2834 | int[7] | BodyParts | FUN_004ae490 | Additional flags |

---



--- Section 48: 4. MutexGuard (inferred) (7 offsets) ---
## 4. MutexGuard (inferred)

Mutex/critical section synchronization struct. Multiple instances at different base offsets within larger structs.

| Offset (base) | Type | Field Name | Observed in | Notes |
|---------------|------|------------|-------------|-------|
| +0x1c/+0x24 | HANDLE+byte | MutexHandle+MutexActive | FUN_005865c0 | Mutex at +0x1c, flag at +0x24 |
| +0x54/+0x5c | HANDLE+byte | MutexHandle+ValidFlag | FUN_00586560 | Mutex at +0x54, flag at +0x5c |
| +0xec/+0xf0/+0xf4 | int+HANDLE+DWORD | SharedValue+MutexHandle+Timeout | FUN_00585770 | Thread-safe read |
| +0x5b4/+0x5b8/+0x5bc | ptr+HANDLE+DWORD | WriteTarget+MutexHandle+Timeout | FUN_00585cd0, FUN_005932f5 | Thread-safe write |
| +0x50/+0x54 | HANDLE+DWORD | MutexHandle+Timeout | FUN_005941ee, FUN_005936ff | From FUN_0058bb79 group |
| +0x08/+0x0c | int32+CRITICAL_SECTION | InitFlag+CriticalSection | FUN_00595a61 | Array of CS at stride 0x24 |
| +0x554/+0x558 | HANDLE+DWORD | MutexHandle+Timeout | FUN_005932f5 |  |



--- Section 49: WheelCornerStruct (per-wheel, stride 0x464) (23 offsets) ---
## WheelCornerStruct (per-wheel, stride 0x464)

Per-wheel vehicle substruct. Used by suspension, brake, tire force computation.

Based on 10+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | float[3] | Position | FUN_004e3aa0 | Wheel position |
| +0x006 | float[3] | Velocity | FUN_004e3aa0 | Wheel velocity |
| +0x00c | float[3] | ForceDir | FUN_004e3aa0 | Force direction in contact frame |
| +0x011 | float | SlipForce | FUN_004e3aa0 | Computed slip force |
| +0x01d | float | ContactLoad | FUN_004e3aa0 | Normal load |
| +0x01e | float[2] | FrictionParams | FUN_004e3aa0 | Friction coefficients |
| +0x024 | float | SuspensionDefl | FUN_004e3aa0 | Suspension deflection |
| +0x033 | float[3] | ContactForce | FUN_004e3aa0 | Output contact force |
| +0x039 | float[4] | SuspensionParams | FUN_004e3aa0 | Suspension parameters |
| +0x0c4 | int | TireInstanceId | FUN_00430750 | Index for tire data lookup |
| +0xc30 | double | LongSlipBias | FUN_00430750 | Longitudinal slip bias |
| +0xc38 | double | LongSlipScale | FUN_00430750 | Longitudinal slip scaling |
| +0xc44 | int | LongSlipFactor | FUN_00430750 | Additional slip factor |
| +0xcb0/cb8/cc4 | double[3] | Load | FUN_00430750 | Tire load (bias/scale/factor) |
| +0x348 | double | DamperForce | FUN_0043fffb, FUN_0043ff3d | Per wheel (stride 0x464) |
| +0x360 | double | SpringForce | FUN_0043fffb, FUN_0043ff3d | Per wheel (stride 0x464) |
| +0x7ac | double | HubForceContrib | FUN_0043fffb | Per wheel hub force |
| +0xc10 | double | ExtraSpringForce | FUN_0043fffb | Additional spring force |
| +0xc28 | double | GeomLeverageRatio | FUN_0043fffb, FUN_0043ff3d | Geometry leverage |
| +0xc30 | double | GeomLeverageAlt | FUN_0043fffb | Alternate geometry leverage |
| +0x1074 | double | ExtraDamperForce | FUN_0043fffb | Additional damper force |
| +0x108c | double | GeomLeverageRatio2 | FUN_0043fffb | Geometry leverage ratio 2 |
| +0x119 | int | WheelSubID | FUN_0043e230 | Wheel substructure ID |

---



--- Section 50: WheelForceArrayStruct (9 offsets) ---
## WheelForceArrayStruct

From FUN_004e3aa0. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00..2 | float[3] | Position | Wheel position |
| +0x06..8 | float[3] | Velocity | Wheel velocity |
| +0x0e..10 | float[3] | ForceDir | Force direction in contact frame |
| +0x11 | float | SlipForce | Computed slip force |
| +0x1d | float | ContactLoad | Normal load |
| +0x1e..1f | float[2] | FrictionParams | Friction coefficients |
| +0x24 | float | SuspensionDefl | Suspension deflection |
| +0x33..35 | float[3] | ContactForce | Output contact force |
| +0x39..3c | float[4] | SuspensionParams | Suspension parameters |

---



--- Section 51: FenderStruct (inferred) (6 offsets) ---
## FenderStruct (inferred)

Based on 1 function observation (FUN_004f3090). Confidence: high.

Fender flare aero setup per wheel.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ActiveFlag | FUN_004f3090 | Set to 1 if FenderCenter present |
| +0x04 | double[3] | DragParams | FUN_004f3090 | Drag coefficient params |
| +0x1c | double[3] | LiftParams | FUN_004f3090 | Lift coefficient params |
| +0x34 | double | SidewaysCoeff | FUN_004f3090 | Sideways force coefficient |
| +0x3c | double[3] | CenterPosition | FUN_004f3090 | Fender center x, y, z |
| +0x54 | double | FlareSetting | FUN_004f3090 | |

---



--- Section 52: Game Data File State Struct (5 offsets) ---
## Game Data File State Struct

Based on 1 function observation (FUN_004b7300). Confidence: low — single source, no cross-validation.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | void* | DataListHead | FUN_004b7300 | linked list of data blocks |
| +0x6e4 | int | SuccessFlag | FUN_004b7300 | |
| +0x700 | int | OpState | FUN_004b7300 | operation state |
| +0xf1c | int | PlayerTeamID | FUN_004b7300 | |
| +0xf20 | int | SessionType | FUN_004b7300 | |

---



--- Section 53: UI Options / Display Settings Struct (7 offsets) ---
## UI Options / Display Settings Struct

Based on 1 function observation (FUN_004726c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x31c | void** | screenModePtr | FUN_004726c0 | param_1[199] → &DAT_007cff84 |
| +0x324 | void* | optionCount | FUN_004726c0 | param_1[0xc9] = 3 |
| +0x328 | int | flag1 | FUN_004726c0 | param_1[0xca] = 1 |
| +0x32c | int | flag2 | FUN_004726c0 | param_1[0xcb] = 1 |
| +0x330 | int | flag3 | FUN_004726c0 | param_1[0xcc] = 1 |
| +0x334 | int | defaultID | FUN_004726c0 | param_1[0xcd] = 0x103 |
| +0x338 | int | sentinel | FUN_004726c0 | param_1[0xce] = -1 |

---



--- Section 54: Resource Manager (texture loading) (inferred) (0 offsets) ---
## Resource Manager (texture loading) (inferred)

Used by FUN_0053d970. Per-resource state tracking with 6 resource slots.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| param_1[0x43f] | ptr | resourceManager | FUN_0053d970 | Interface pointer with vtable |
| param_1[3..] | int[] | perResourceState | FUN_0053d970 | Stride 0x10f ints per resource |



--- Section 55: DualLinkedListHeader (inferred) (8 offsets) ---
## DualLinkedListHeader (inferred)

Based on 2 function observations (FUN_004bad70, FUN_00490d00). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int* | ListA_Head | FUN_004bad70 | Primary list head |
| +0x04 | int* | ListA_Tail | FUN_004bad70 | Primary list tail |
| +0x08 | int* | ListA_Last | FUN_004bad70 | Primary list iterator/last |
| +0x0C | int | ListA_Count | FUN_004bad70 | Primary list element count |
| +0x10 | int* | ListB_Head | FUN_004bad70 | Secondary list head |
| +0x14 | int* | ListB_Tail | FUN_004bad70 | Secondary list tail |
| +0x18 | int* | ListB_Last | FUN_004bad70 | Secondary list iterator/last |
| +0x1C | int | ListB_Count | FUN_004bad70 | Secondary list element count |

---



--- Section 56: CollisionNoiseRange (inferred — param_1 in FUN_004962c0) (1 offsets) ---
## CollisionNoiseRange (inferred — param_1 in FUN_004962c0)

Based on FUN_004962c0. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x162C | float[16] | NoiseRangeTable | Base range for noise, indexed by param_3 |

---



--- Section 57: 2. Commentary/Director Event Struct (inferred) (5 offsets) ---
## 2. Commentary/Director Event Struct (inferred)

Based on 1 function observation (FUN_0040d4c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | EventID | FUN_0040d4c0 | Event identifier |
| +0x0c | float | Probability | FUN_0040d4c0 | Default 1.0 |
| +0x10 | unknown | Param | FUN_0040d4c0 | Additional parameter |
| +0x24 | int | EventTypeCode | FUN_0040d4c0 | 0–0xc (CAMERA_ACQUIRE_CONTROL, COMMENTARY_START, SCRIPT_END, etc.) |
| +0x28 | unknown | Unknown | FUN_0040d4c0 | Not documented |

---



--- Section 58: NetworkSessionState (inferred) (5 offsets) ---
## NetworkSessionState (inferred)

Based on 1 function (FUN_00563260). Confidence: medium.

Separate from the 0xbf8 manager struct. Contains connection state and client tracking.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ConnectionState | FUN_00563260 | 0=initial, 1+=connected |
| +0x04 | int | ClientArrayPtr | FUN_00563260 | param_1[1]? needs cross-ref |
| +0x70 | int | MaxClientCount | FUN_00563260 | param_1[0x1c] |
| +0x74 | int | ConnAttemptCounter | FUN_00563260 | param_1[0x1d] |
| +0x98 | int | ReconnRetryCounter | FUN_00563260 | param_1[0x26] |

---



--- Section 59: Struct 5: AI Path / Entrant Struct (stride 0x48c0, from FUN_00418ee0) (1 offsets) ---
## Struct 5: AI Path / Entrant Struct (stride 0x48c0, from FUN_00418ee0)

Based on FUN_00418ee0 (target driver selection). Confidence: **low** — only 1 observation.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00–+0x48bf | byte[0x48c0] | EntrantEntry | Full entrant data block, stride 0x48c0 |
| (entry base) | — | DriverIndex | Iterated from DAT_005f0cf8 |

---



--- Section 60: UIComboBox (inferred) (14 offsets) ---
## UIComboBox (inferred)

UI widget struct passed as `param_1` to FUN_00470da0. Used for weather mode selection dropdown. `param_1` is `undefined4*` (int-indexed). Vtable pointer at +0x00, widget-specific fields start at int-index +0xc9 (byte offset +0x324).

Based on 1 function observation. Confidence: **medium** (only one function touches this struct).

| Byte Offset | Int Index | Type | Field Name | Observed in | Notes |
|-------------|-----------|------|------------|-------------|-------|
| +0x000 | +0x00 | pointer | vtable | FUN_00470da0 | set to PTR_FUN_005a09c0 |
| +0x324 | +0xc9 | int | option_count | FUN_00470da0 | set to 5 (5 weather mode options) |
| +0x328 | +0xca | int | default_index | FUN_00470da0 | set to 0 |
| +0x32c | +0xcb | int | active_flag | FUN_00470da0 | set to 1 |
| +0x330 | +0xcc | int | unknown_flag | FUN_00470da0 | set to 1 |
| +0x334 | +0xcd | int | scroll_offset | FUN_00470da0 | set to 0x19b (411) |
| +0x338 | +0xce | pointer | weather_mode_ptr | FUN_00470da0 | set to `&DAT_007cf080 + DAT_007d0410 * 9` (per-season weather offset) |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_D.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
