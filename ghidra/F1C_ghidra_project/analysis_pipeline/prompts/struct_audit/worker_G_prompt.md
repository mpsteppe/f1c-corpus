# WORKER G — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker G of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_G.md

## YOUR STRUCT SECTIONS (14)

--- Section 90: VibrationEffectController (param_1/unaff_ESI — controller) (21 offsets) ---
## VibrationEffectController (param_1/unaff_ESI — controller)

Based on FUN_00545d00 and FUN_005169ac. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | activeFlag | FUN_00545d00 | Master enable |
| +0x14 | int | state | FUN_00545d00, FUN_005169ac | State ID |
| +0x16 | int | active | FUN_00545d00 | Active flag |
| +0x19 | byte | mode | FUN_00545d00 | Mode (3=triggered) |
| +0x1d | byte | subState | FUN_00545d00 | Sub-state for mode 3 |
| +0x20 | int | ModeA | FUN_005169ac | Must be 3 |
| +0x24 | int | ModeB | FUN_005169ac | Must be 3 |
| +0x28 | int | ModeC | FUN_005169ac | Must be 2 |
| +0x32 | byte | altMode | FUN_00545d00 | Alternative mode flag |
| +0x41 | byte | processingFlag | FUN_00545d00 | Processing path selector |
| +0x46 | byte | durationMultiplier | FUN_00545d00 | Scales effect duration |
| +0x48 | byte | FlagA | FUN_005169ac | Must be 0 |
| +0x4a | byte | globalEnable | FUN_00545d00 | Master enable byte |
| +0x59 | byte | flagRight | FUN_00545d00 | Right-side trigger |
| +0x5a | byte | flagLeft | FUN_00545d00 | Left-side trigger |
| +0x64 | int | ModeD | FUN_005169ac | Must be 3 |
| +0x69 | byte | intensity | FUN_00545d00 | Effect intensity |
| +0xc4 | ptr | SubStructPtr | FUN_005169ac | Pointer to sub-struct |
| +0xc9 | byte | extendedFlag | FUN_00545d00 | Extended processing flag |
| +0x108 | byte | FlagB | FUN_005169ac | Must be 0 |
| +0x114 | int | MatchID | FUN_005169ac | Cross-check value |

---



--- Section 91: UIListComboBox (list/combo control) (4 offsets) ---
## UIListComboBox (list/combo control)

Based on FUN_0051a4f2, FUN_0051bc88. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | int | ItemCount | FUN_0051a4f2, FUN_0051bc88 | |
| +0xc4 | ptr[] | ItemArray | FUN_0051a4f2, FUN_0051bc88 | Stride 0x50/0x15×4 |
| +0x184 | ptr | ListDataPtr | FUN_0051a4f2 | Allocated storage |
| +0x198 | ptr | ListDataPtr | FUN_0051bc88 | Control header |

---



--- Section 92: 7. UIObjectList (inferred — FUN_0047e960) (7 offsets) ---
## 7. UIObjectList (inferred — FUN_0047e960)

UI option list manager.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x44 (0x11) | ptr | ItemListHead | FUN_0047e960 |  |
| +0x48 (0x12) | ptr | ItemListTail | FUN_0047e960 |  |
| +0x4c (0x13) | ptr | CurrentItem | FUN_0047e960 |  |
| +0x50 (0x14) | int | ItemCount | FUN_0047e960 |  |
| +0xec (0x3b) | int | InitField | FUN_0047e960 | zeroed |
| +0xf0 (0x3c) | int | EndMarker | FUN_0047e960 | -1 |
| +0xf4 (0x3d) | int | OptionID | FUN_0047e960 |  |



--- Section 93: ConstraintEntryStruct (stride 0x48) (4 offsets) ---
## ConstraintEntryStruct (stride 0x48)

Per-constraint entry in constraint array.

Based on 1 function observation (FUN_0043ba20). Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | int | BodyA_ID | First body identifier |
| +0x08 | int* | ForcePtrA | Force pointer for body A |
| +0x0c | int | BodyB_ID | Second body identifier |
| +0x10 | int* | ForcePtrB | Force pointer for body B |
| Stride: 0x48 | | | |

---



--- Section 94: ForceIntegratorStruct (FUN_00438130 + FUN_00438100 overlap) (5 offsets) ---
## ForceIntegratorStruct (FUN_00438130 + FUN_00438100 overlap)

From FUN_00438100, FUN_00438130. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x364 | double | FactorA | Multiplication factor A |
| +0x36c | double | FactorB | Multiplication factor B |
| +0x374 | double | Product | Computed product |
| +0x38c | double | Multiplier | Force multiplier |
| +0x384 (900) | double | BiasTerm | Addition bias |

---



--- Section 95: WheelSuspensionForceStruct (stride 0x13c) (inferred) (13 offsets) ---
## WheelSuspensionForceStruct (stride 0x13c) (inferred)

Based on 1 function observation (FUN_00401340). Confidence: low.

Per-wheel suspension force calculations. Array of stride 0x13c from param_1+0x134.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x70 | float | LateralForce | FUN_00401340 | Output: lateral suspension force |
| +0x74 | float | LongitudinalForce | FUN_00401340 | Output: longitudinal suspension force |
| +0x78 | float | SpringForce0 | FUN_00401340 | Spring/damper force |
| +0x7c | float | SpringForce1 | FUN_00401340 | |
| +0x80 | float | SpringForce2 | FUN_00401340 | |
| +0x94 | float | BodyAttachX | FUN_00401340 | Body attachment point |
| +0x98 | float | BodyAttachY | FUN_00401340 | |
| +0x9c | float | BodyAttachZ | FUN_00401340 | |
| +0x10c | (ptr) | SuspGeomPtr | FUN_00401340 | Suspension geometry index/ptr |
| +0x110 | (ptr) | ContactPtr | FUN_00401340 | Collision contact surface pointer |
| +0x130 | int | NumWheels | FUN_00401340 | Wheel count for this vehicle |
| +0x134 | (ptr) | WheelArrayPtr | FUN_00401340 | Pointer to wheel struct array |
| +0x13c | - | StructStride | FUN_00401340 | Per-wheel stride |

---



--- Section 96: AutoLoadEntry List Head Struct (5 offsets) ---
## AutoLoadEntry List Head Struct

Based on 1 function observation (FUN_00432e70). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1c | void* | head | FUN_00432e70 | list head pointer |
| +0x20 | void* | tail | FUN_00432e70 | list tail pointer |
| +0x24 | void* | iterator | FUN_00432e70 | current traversal position |
| +0x28 | int | count | FUN_00432e70 | entry count |
| +0x18 | int | loaded flag | FUN_00432e70 | set to 1 at end of load |

**Conflict:** +0x18 is both "loaded flag" and overlaps with AutoLoadEntry node struct +0x18 (next pointer for unnamed alloc). These are different structs — the list head struct is a separate container. ✅ Consistent.

---



--- Section 97: Season Database Struct (FUN_0047f440) (2 offsets) ---
## Season Database Struct (FUN_0047f440)

Based on 1 function observation (FUN_0047f440). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x191c | void** | entryArray[508] | FUN_0047f440 | array of 508 object pointers |
| +0x1fe8 | void* | specialPtr | FUN_0047f440 | for index 0x1b4 case |

---



--- Section 98: UI Control Struct (common) (inferred) (29 offsets) ---
## UI Control Struct (common) (inferred)

Used across many UI functions: FUN_004a70e0, FUN_00487400, FUN_00488180,
FUN_00489530, FUN_0048bbe0, FUN_0048e860, FUN_0048fdb0, etc. Large struct
with vtable, state fields, and function table slots.

Based on 15+ function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | vtable | FUN_0048f640, FUN_00487400, FUN_00488180 | Virtual method table |
| +0x08 | ushort | renderMode | FUN_0040eb30 | Render mode flag |
| +0x0c | int | width | FUN_0048fdb0 | Width/dimension A |
| +0x10 | int | height | FUN_0048fdb0, FUN_0048f640 | Height/dimension B |
| +0x18 | ptr | nextNode | FUN_00486540 | Linked list next |
| +0x1c | int | typeID | FUN_0040eb30 | Type/ID (3 for camera/projection) |
| +0x20 | ptr/uint | reference/resource | FUN_0040eb30, FUN_0048f640, FUN_004c9310 | Reference parameter / flags |
| +0x24-0x28 | ptr[3] | resourcePtrs | FUN_004c9310 | 3 vtable+8 resource slots |
| +0x38 | char | visibility | FUN_0048bbe0 | Active/visibility flag |
| +0x3c | ptr | elementList | FUN_0048f640 | Linked list of layout elements |
| +0x3e | ptr | currentElement | FUN_0048f640 | Iterator during traversal |
| +0x40 | int | layoutMode | FUN_0048f640 | 0=horizontal, 1=vertical-first |
| +0x45 | byte | activeFlag | FUN_00488180 | Active/visible flag (1) |
| +0x48 | int | headerWidth | FUN_0048f640 | Fixed header width |
| +0x49 | int | contentWidth | FUN_0048f640 | Content/total width |
| +0x50 | int | headerHeight | FUN_0048f640 | Fixed header height |
| +0x51 | int | contentHeight | FUN_0048f640 | Content/total height |
| +0x54 | int | maxElementWidth | FUN_0048f640 | Maximum element width |
| +0x55 | int | maxElementHeight | FUN_0048f640 | Maximum element height |
| +0x56 | int | columnCount | FUN_0048f640 | Computed columns |
| +0x57 | int | rowCount | FUN_0048f640 | Computed rows |
| +0x58 | int | viewWidth | FUN_0048f640 | Visible viewport width |
| +0x59 | int | viewHeight | FUN_0048f640 | Visible viewport height |
| +0x5b | int | scrollRange | FUN_0048f640 | Computed scroll range |
| +0xe1 | char | secondaryFlag | FUN_0048bbe0 | Secondary active flag |
| +0xe8 | int | guardFlag | FUN_0048e860 | Conditional dispatch guard |
| +0x118 | ptr | ptrSlot1 | FUN_004a70e0 | First function ptr table entry |
| +0x130 | ptr | ptrSlot2 | FUN_004a70e0 | Second function ptr table entry |
| +0x14c | int | navigationPos | FUN_00489530 | Counter/navigation position |



--- Section 99: WheelContactState (inferred — per-wheel collision from vehicle struct) (4 offsets) ---
## WheelContactState (inferred — per-wheel collision from vehicle struct)

Based on FUN_004e96c0. Confidence: **high**. Offsets relative to vehicle struct base.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x828 | int[4] | WheelActiveFlags | FUN_004e96c0 | Per-wheel active flags, stride 0x4a |
| +0x34D4 | float[3] | VehiclePos | FUN_004e96c0 | Vehicle position (x, y, z) |
| +0x3AAC | float[3] | TargetPos | FUN_004e96c0 | Contact point / target |
| +0x3B6C | float | SuspensionTravel | FUN_004e96c0 | Suspension travel bounds |

---



--- Section 100: AnimationFrameTimer (inferred — param_1 in FUN_00469dd0) (0 offsets) ---
## AnimationFrameTimer (inferred — param_1 in FUN_00469dd0)

Based on FUN_00469dd0. Confidence: **low**.

| Index | Type | Field | Notes |
|-------|------|-------|-------|
| [0x5D] | float | FrameTimer | Accumulated frame time |
| [0x5E] | int | FrameIndex | Animation frame index (wraps at DAT_007d2dcc) |

---



--- Section 101: 5. SpecialFX Struct (inferred) (10 offsets) ---
## 5. SpecialFX Struct (inferred)

Based on observations from specialfx.cpp entries (FUN_004cee90–FUN_004cfff0). Confidence: low.

**WARNING:** Offsets listed in doc as +0x00, +0x01, +0x02, +0x03, +0x04, +0x05, +0x06–0x0a, +0x0b, +0x0c, +0x0d — these appear to be sequential byte offsets in a packed struct or may have been mis-extracted. They do not follow the typical DWORD-aligned pattern seen in other game structs. Likely these are fields within a small header or the doc extraction is incomplete.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | LPTreeCount | specialfx.cpp Init | LPTREE scene node count |
| +0x01 | ptr? | LPTreeArray | specialfx.cpp Init | Stride 0x3c |
| +0x02 | int | FeedbackCount | specialfx.cpp Init | Feedback material count |
| +0x03 | ptr? | FeedbackArray | specialfx.cpp Init | Stride 0x6c |
| +0x04 | int | LooseMatCount | specialfx.cpp Init | Loose material count |
| +0x05 | ptr? | LooseMatArray | specialfx.cpp Init | Stride 0x6c |
| +0x06–0x0a | ptr[5]? | SpecialMaterials | specialfx.cpp Init | Pointers for material types 0xc, 0xd, 1, 3, 4 |
| +0x0b | unknown | SceneExtents | specialfx.cpp Init | Scene extent data |
| +0x0c | float | AIDryGrip | specialfx.cpp Init | AI dry grip multiplier |
| +0x0d | float | AIWetGrip | specialfx.cpp Init | AI wet grip multiplier |

**CONFLICT:** Offsets +0x00 through +0x0d are suspiciously small (not DWORD-aligned). Compare with other structs in this game which use DWORD offsets (multiples of 4). Possible extraction error in doc or unusual packed struct. If offsets are actually DWORD-based: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14, +0x18, +0x28, +0x30, +0x34 would be the real DWORD-aligned offsets.

---



--- Section 102: DynamicStackStruct (inferred) (3 offsets) ---
## DynamicStackStruct (inferred)

Based on 1 function (FUN_005648d0). Confidence: high.

Dynamic stack/buffer with automatic growth on overflow. Used in audio mixer buffer management.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int32 | Top | FUN_005648d0 | Stack pointer / write index |
| +0x04 | int32 | Capacity | FUN_005648d0 | Allocated element count |
| +0x08 | int32 | ElementSize | FUN_005648d0 | Size of each element for growth calc |

---



--- Section 103: Struct 8: Config Entry Node (FUN_00433b60) (1 offsets) ---
## Struct 8: Config Entry Node (FUN_00433b60)

Based on 1 observation. Confidence: **low** — only total size known.

| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00–+0x1b | byte[0x1c] | ConfigNode | Allocated and linked. Total size 0x1c bytes |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_G.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
