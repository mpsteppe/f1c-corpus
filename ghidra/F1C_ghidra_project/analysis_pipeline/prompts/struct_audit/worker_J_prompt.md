# WORKER J — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker J of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_J.md

## YOUR STRUCT SECTIONS (14)

--- Section 132: AudioStreamBuffer (param_1 — audio stream) (14 offsets) ---
## AudioStreamBuffer (param_1 — audio stream)

Based on FUN_00519720, FUN_0051bd61, FUN_0051bcfc. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x030 | byte | ReadyFlag | FUN_00519720 | 0=needs init, 1=ready |
| +0x034 | uint | Position | FUN_00519720 | Current read position |
| +0x038 | ptr | SourcePointer | FUN_00519720 | Varies by buffer index |
| +0x040 | uint | BufferIndex | FUN_00519720 | Double-buffer toggle (xor 1) |
| +0x044 | int | FillState | FUN_00519720 | 0=idle, 1=filling, 2=switch |
| +0x048 | uint | BufferSize | FUN_00519720 | |
| +0x04c | int | BufferCounter | FUN_00519720 | Completed fills |
| +0x114 | int | BufferSizeBase | FUN_00519720 | Size reference |
| +0x118 | int | TotalBuffers | FUN_00519720 | |
| +0x180 | ptr | StreamPtr | FUN_00519720 | Stream state |
| +0x184 | ptr | VtableDecoder / VTablePtrA | FUN_00519720, FUN_0051bcfc, FUN_00515db8 | Method +0xc=data available |
| +0x188 | ptr | VtableFiller / BufferObj / RenderContext | FUN_00519720, FUN_0051bd61, FUN_0051bcfc | Method +4=buffer fill |
| +0x19c | ptr | PlayCallback / WriteVtable | FUN_0051bd61, FUN_0051bcfc | Vtable for playback/write |
| +0x1a4 | ptr | FlushCallback / FlushVtable | FUN_0051bd61, FUN_0051bcfc | Vtable for flush |

---



--- Section 133: GeometryProximityTest (per-element wheel collision) (2 offsets) ---
## GeometryProximityTest (per-element wheel collision)

Based on FUN_004ed420. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x828 | int[4] | ElementFlags | FUN_004ed420 | Per-element flags, stride 0x128 |
| +0x3594 | float[4] | ElementArray | FUN_004ed420 | Stride 0xf8: position+radius |

---



--- Section 134: 10. DynamicBuffer (inferred — FUN_00564930) (4 offsets) ---
## 10. DynamicBuffer (inferred — FUN_00564930)

Growing buffer with accumulator and realloc.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | int | AccumSize | FUN_00564930 | Accumulated count |
| +0x08 | int | ElemSize | FUN_00564930 | Per-element size |
| +0x0c | int | Addend | FUN_00564930 | Growth amount |
| +0x14 | ptr | Buffer | FUN_00564930 | Allocated buffer |



--- Section 135: ContactPairStruct (stride 0x20) (8 offsets) ---
## ContactPairStruct (stride 0x20)

Contact pair entry.

Based on 2+ function observations. Confidence: medium.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int | ContactType | FUN_00449700 | Contact type/flag |
| +0x04 | int | BodyA | FUN_00449700 | First body ID |
| +0x08 | int | BodyB | FUN_00449700 | Second body ID |
| +0x0c | int | BodyC | FUN_00449700 | Third body ID |
| +0x10 | int | BodyVelocity | FUN_00449700 | Body velocity field |
| +0x14 | int | BodyVelocityB | FUN_00449700 | Body velocity field |
| +0x18 | int | Reserved | FUN_00449700 | |
| +0x1c | int | NextPtr | FUN_004496d0 | Linked list next |
| Stride: 0x20 (32 bytes) | | | FUN_00449700, FUN_004496d0 | |

---



--- Section 136: SuspensionCopyStruct (FUN_0043bc20 setup copy) (25 offsets) ---
## SuspensionCopyStruct (FUN_0043bc20 setup copy)

From FUN_0043bc20. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1900 | double | FlagType | Copy from template +0x1ec |
| +0x1910 | float | SetupValue1 | Copy from template +0x1f0 |
| +0x1914 | float | SetupValue2 | Copy from template +500 |
| +0x1938 | float | SetupValue3 | Copy from template +0x228 |
| +0x193c | float | SetupValue4 | Copy from template +0x22c |
| +0x1940 | float | SetupValue5 | Copy from template +0x230 |
| +0x1944 | float | SetupValue6 | Copy from template +0x234 |
| +0x1960 | float[36] | SpringDamperMatrix | 6x6 symmetric matrix |
| +0x19f0 | float[6] | BiasVector | 6-element bias |
| +0x17a8 | float[6*4] | HubPositions | 6 hub XYZ positions + extra |
| +0x17c0 | float[6*4] | PatchPositions | 6 contact patch positions |
| +0x1c08-0x1c14 | float[6*4] | MirroredPositions | Mirrored hub/patch data |
| +0x1a08 | flag | DampingFlag | Flag for damping curves |
| +0x1a14/0x1a18 | float | BumpRebound | Bump/rebound rates |
| +0x1a34 | float[36] | DampingMatrix | 6x6 damping matrix |
| +0x1ac4 | float[6] | DampingBias | Damping bias vector |
| +0x17d8-0x1804 | float[12] | TravelLimits | 6x2 values per wheel |
| +0x1828-0x1834 | float[6] | WheelMassInertia | Wheel mass/inertia |
| +0x1ae4-0x1af8 | float[6] | InertiaMatrix | 6x6 inertia matrix |
| +0x1b14-0x1ba4 | float[36] | ComplianceMatrix | 6x6 compliance matrix |
| +0x1808 | float | SpringPreloadToe | Scaled spring preload + toe offset |
| +0x1810/0x1814 | float | CamberToe | Camber/toe angles |
| +0x1818 | float | ScaledCaster | Scaled caster angle |
| +0x1820/0x1824 | float | CasterAngles | Additional caster values |
| +0x1bbc-0x1be4 | float[8] | AntiRollBarParams | Anti-roll bar stiffness and travel |

---



--- Section 137: CameraStruct (inferred) (6 offsets) ---
## CameraStruct (inferred)

Based on 1 function observation (FUN_0040b850). Confidence: medium.

Camera definition struct for MAINVIEW and TRACKINGCAM. Stride 0xd0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (start) | FUN_0040b850 | |
| +0x04 | int | CameraCount | FUN_0040b850 | From FUN_00544f50 |
| +0x0c | (ptr) | CameraArrayPtr | FUN_0040b850 | Array of camera structs |
| +0x10 | int | CameraCount2 | FUN_0040b850 | Second count |
| +0x14 | int | CurrentIndex | FUN_0040b850 | Initialized to 0 |
| +0xd0 | - | CameraStructSize | - | Stride |

---



--- Section 138: Per-Vehicle Filter State Struct (stride 0x1b4) (4 offsets) ---
## Per-Vehicle Filter State Struct (stride 0x1b4)

Based on 1 function observation (FUN_004c0db0). Confidence: low — stride 0x1b4 per vehicle.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x194 | int | filter index start | FUN_004c0db0 | |
| +0x198 | int | filter index end | FUN_004c0db0 | |
| +0x19c | int | filter flags | FUN_004c0db0 | |
| +0x1a0 | bool | filter active flag | FUN_004c0db0 | |

---



--- Section 139: Scoring Database Struct (at DAT_007d2e48 + season_index * 0x48c0) (4 offsets) ---
## Scoring Database Struct (at DAT_007d2e48 + season_index * 0x48c0)

Based on 1 function observation (FUN_004c0910). Confidence: medium — aligns with vehicle struct offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x403c | int | season points total | FUN_004c0910 | |
| +0x4060 | int | finish position | FUN_004c0910 | |
| +0x4064 | int | finish state | FUN_004c0910 | 3 = DNF/excluded |
| +0x409c | float | best lap time | FUN_004c0910 | |

Note: These offsets (+0x403c through +0x409c) match the vehicle struct offsets from FUN_004c2a80. Suggests scoring DB entries may be vehicle structs or a compatible layout. ✅ Consistent with Vehicle Array Entry (stride 0x424 → vehicle struct ≈0x48c0).

---



--- Section 140: Circular Buffer Slot Allocator (inferred) (5 offsets) ---
## Circular Buffer Slot Allocator (inferred)

Used by FUN_004cb540. Tracks max count, slot array, current index,
allocation count, and mapping.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x58 | int | maxCount | FUN_004cb540 | Maximum slot count |
| +0x5c | ptr | slotArray | FUN_004cb540 | Slot array base ptr |
| +0x60 | int | currentIndex | FUN_004cb540 | Current allocation index |
| +0x64 | int | allocCount | FUN_004cb540 | Number of allocated slots |
| +0x68 | ptr | mappingArray | FUN_004cb540 | Index-to-slot mapping array |



--- Section 141: BSPTreeNode (inferred — param_1/param_2 in FUN_0044a4b0) (9 offsets) ---
## BSPTreeNode (inferred — param_1/param_2 in FUN_0044a4b0)

Based on FUN_0044a4b0. Confidence: **medium**.

**Node output (param_1):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x08 | short | SplitDir | 0=left child, 1=right child, 0xffff=leaf, 0xfffe=2-node |
| +0x0A | short | SplitIndex | Index of split plane (0..14) |
| +0x0C | int* | VertexPtr | Output vertex buffer pointer |

**Allocator context (param_2):**
| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1C | int | NodeCount | Total nodes allocated |
| +0x1C | int* | NextPtr | Linked list next (same offset as NodeCount — union/overlap?) |
| +0x24 | int* | DataBase | Base of data buffer |
| +0x28 | int | VertexCount | Vertex count |
| +0x30 | int* | VertexBase | Base of vertex buffer |
| +0x34 | int | SomeParam | Parameter passed to children |

**Conflict:** +0x1C used as both int (nodeCount) and int* (nextPtr) — likely same field reused depending on node type.

---



--- Section 142: VehicleLapTime (inferred — from FUN_0049b6d0) (1 offsets) ---
## VehicleLapTime (inferred — from FUN_0049b6d0)

Based on FUN_0049b6d0. Confidence: **high** (matches known vehicle struct in docs/01-10).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x403C | int | CurrentLap | Current lap number |

---



--- Section 143: 8. Scene File Struct (param_1, fog parameters) (7 offsets) ---
## 8. Scene File Struct (param_1, fog parameters)

Based on 1 function observation (FUN_0055b200). Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x188 | short | FogColorR | FUN_0055b200 | FOGCOLOR red component (short) |
| +0x18a | short | FogColorG | FUN_0055b200 | FOGCOLOR green component (short) |
| +0x18c | short | FogColorB | FUN_0055b200 | FOGCOLOR blue component (short) |
| +0x194 | float | FogInDist | FUN_0055b200 | FOGIN distance (float) |
| +0x198 | float | FogOutDist | FUN_0055b200 | FOGOUT distance (float) |
| +0x190 | float | FogDensity | FUN_0055b200 | FOGDENSITY (float) |
| +0x19c | int | FogModeMask | FUN_0055b200 | Fog mode (LINEAR=0x20000, FOG=0x40000/0x80000) |

**NOTE:** +0x190 is documented as "400" (decimal) in the source doc — likely 0x190 hex = 400 decimal. It sits between the color shorts and the distance floats. Alignment: shorts at +0x188–0x18c (6 bytes), then FogDensity at +0x190 (4-byte aligned), FogInDist at +0x194, FogOutDist at +0x198.

---



--- Section 144: AudioArrayContainer (inferred) (2 offsets) ---
## AudioArrayContainer (inferred)

Based on 1 function (FUN_00564740). Confidence: high.

Simple array container with data buffer and element count.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | DataBuffer | FUN_00564740 | Element data buffer, freed via FUN_0058aa6f |
| +0x04 | int | ElementCount | FUN_00564740 | Loop bound for element cleanup |

---



--- Section 145: Cross-reference: fields already in docs/13-struct-offsets.md (7 offsets) ---
## Cross-reference: fields already in docs/13-struct-offsets.md

| Field | 13-struct-offsets.md | 02-ai-system.md | Match? |
|-------|---------------------|------------------|--------|
| EffectiveLifetimeAtSpawn | +0x1db4 | Not used in AI doc | N/A |
| LifetimeEngineRPM min/max | +0x1dbc/+0x1dc4 | Not used in AI doc | N/A |
| LifetimeOilTemp min/max | +0x1dcc/+0x1dd4 | Not used in AI doc | N/A |
| PitStopFlag bitmask | +0x1180 | +0x1178 | **MISMATCH** — AI doc says +0x1178 for PlannedStopsBitmask, 13-struct-offsets says +0x1180. Need resolution. |

### CONFLICT: PitStopFlag offset

| Source | Offset | Notes |
|--------|--------|-------|
| docs/13-struct-offsets.md | +0x1180 | PitStopFlag bitmask |
| docs/02-ai-system.md (FUN_0042a3d0) | +0x1178 | PlannedStopsBitmask |

These may be **different fields** at adjacent offsets: +0x1178 = planned stops bitmask (from .rcd, written by FUN_0042a3d0), +0x1180 = runtime pit stop flag (set during pit operations). No conflict — adjacent fields in the same struct.

**Recommendation:** Retain both offsets as separate fields in the consolidated struct definition.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_J.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
