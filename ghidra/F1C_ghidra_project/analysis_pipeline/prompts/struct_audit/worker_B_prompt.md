# WORKER B — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker B of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_B.md

## YOUR STRUCT SECTIONS (15)

--- Section 16: Source: docs/06-session-race-logic.md (0 offsets) ---
## Source: docs/06-session-race-logic.md

# Struct Offset Synthesis — Worker A

Source: `docs/06-session-race-logic.md` (845 functions, 287 struct offset sections, 996 offset observations)

Generated: 2026-07-15

---



--- Section 17: ViewportStruct (param_1 — viewport/render target) (7 offsets) ---
## ViewportStruct (param_1 — viewport/render target)

Based on FUN_005425a0, FUN_0054c110. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x54 | int | Width | FUN_005425a0 | Viewport width |
| +0x58 | int | Height | FUN_005425a0 | Viewport height |
| +0x68 | int | XOffset | FUN_005425a0 | Viewport X origin |
| +0x15c | ptr | LocalData | FUN_005425a0 | Renderer data |
| +0x234 | int | RenderTarget1 | FUN_0054c110 | |
| +0x238 | int | RenderTarget2 | FUN_0054c110 | |
| +0x03c | uint | DirtyFlags | FUN_0054c110 | Bitmask |

---



--- Section 18: 2. LinkedList (inferred) (4 offsets) ---
## 2. LinkedList (inferred)

Standard 4-field linked list container.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | HeadPtr | FUN_005819c0, FUN_00581a20, FUN_00586000 | First node |
| +0x04 | ptr | TailPtr | FUN_005819c0, FUN_00586000 | Last node |
| +0x08 | int | Count | FUN_005819c0, FUN_00586000 | Node count |
| +0x0c | int | Capacity | FUN_005819c0 | Max capacity |



--- Section 19: RigidBodyState (inferred) (49 offsets) ---
## RigidBodyState (inferred)

Core rigid body dynamics struct. Position, orientation, velocity, momentum. Used by 20+ functions.

Based on 25+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | double | Pad/Mass? | FUN_00448e90 | first 6 ints zeroed |
| +0x004 | double | PosX | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass X |
| +0x00c | double | PosY | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass Y |
| +0x014 | double | PosZ | FUN_00569a20, FUN_005694e0, FUN_00569860, FUN_0056d1c0, FUN_0043e5d0, FUN_00441d60 | World-space center of mass Z |
| +0x018 | byte | ActiveFlag | FUN_00448e90, FUN_00431390 | set to 1 when active |
| +0x019 | byte | BVType/Flags | FUN_00448e90 | bounding volume type |
| +0x01a | short | CollisionGroupID | FUN_00448e90 | 0xffff = no group |
| +0x01c | double | RotMatrix[0][0] | FUN_00569860, FUN_0056d1c0, FUN_00438930, FUN_004359a0 | Orientation matrix col0.x |
| +0x024 | double | RotMatrix[1][0] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col0.y |
| +0x02c | double | RotMatrix[2][0] | FUN_00569860, FUN_0056d1c0, FUN_00438930, FUN_004359a0, FUN_00441ad0 | Orientation matrix col0.z |
| +0x034 | double | RotMatrix[0][1] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col1.x |
| +0x03c | double | RotMatrix[1][1] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col1.y |
| +0x044 | double | RotMatrix[2][1] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col1.z |
| +0x04c | double | RotMatrix[0][2] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col2.x |
| +0x054 | double | RotMatrix[1][2] | FUN_00569860, FUN_0056d1c0 | Orientation matrix col2.y |
| +0x05c | double | RotMatrix[2][2] | FUN_00569860, FUN_0056d1c0, FUN_00438930 | Orientation matrix col2.z |
| +0x060 | double | ForceAccumX0 | FUN_00441d60 | Force buffer 0 X |
| +0x064 | double | ForceAccumY0 | FUN_00441d60 | Force buffer 0 Y |
| +0x06c | double | ForceAccumZ0 / VelocityX? | FUN_00441d60, FUN_00441ad0 | Force buffer 0 Z or velocity X |
| +0x074 | double | VelocityY? | FUN_00441ad0 | Y velocity component |
| +0x07c | double | TransformResultX | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output X |
| +0x084 | double | TransformResultY | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output Y |
| +0x08c | double | TransformResultZ | FUN_005691d0, FUN_00435e00, FUN_004359a0 | Rotated vector output Z |
| +0x094 | double | InputVectorX | FUN_005691d0, FUN_00469410 | Input vector X component |
| +0x09c | double | InputVectorY | FUN_005691d0 | Input vector Y component |
| +0x0a4 | double | InputVectorZ | FUN_005691d0 | Input vector Z component |
| +0x0b4 | double | ScaleFactor | FUN_00569670, FUN_00569410 | Damping/time-step/scale factor |
| +0x0bc | double | DiagonalScale[0] | FUN_00438130, FUN_00569410 | Diagonal scale S0 |
| +0x0c4 | double | DiagonalScale[1] | FUN_00569410 | Diagonal scale S1 |
| +0x0cc | double | DiagonalScale[2] | FUN_00569410 | Diagonal scale S2 |
| +0x0ec | double | InertiaTensor[0][0] | FUN_00569670, FUN_005691d0 | Row 0 col 0 |
| +0x0f4 | double | InertiaTensor[0][1] | FUN_00569670, FUN_005691d0 | Row 0 col 1 |
| +0x0fc | double | InertiaTensor[0][2] | FUN_00569670, FUN_005691d0 | Row 0 col 2 |
| +0x104 | double | InertiaTensor[1][0] | FUN_00569670, FUN_005691d0 | Row 1 col 0 |
| +0x10c | double | InertiaTensor[1][1] | FUN_00569670, FUN_005691d0 | Row 1 col 1 |
| +0x114 | double | InertiaTensor[1][2] | FUN_00569670, FUN_005691d0 | Row 1 col 2 |
| +0x11c | double | InertiaTensor[2][0] | FUN_00569670, FUN_005691d0 | Row 2 col 0 |
| +0x124 | double | InertiaTensor[2][1] | FUN_00569670, FUN_005691d0 | Row 2 col 1 |
| +0x12c | double | InertiaTensor[2][2] | FUN_00569670, FUN_005691d0 | Row 2 col 2 |
| +0x134 | double | LinearMo
[...1207 chars truncated]

--- Section 20: PhysicsQueryStruct (5 offsets) ---
## PhysicsQueryStruct

From FUN_00583790. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x0c | byte | ReadyFlag | 0 = no data ready |
| +0x10 | double | ReferenceValue | Base reference |
| +0x18 | double | DeltaValue | Delta/adjustment |
| +0x20 | byte[] | DataBuffer | Variable-length data |
| +0x120 | int | DataCount | Number of entries |

---



--- Section 21: PerWheelTireCompound (inferred) (33 offsets) ---
## PerWheelTireCompound (inferred)

Based on 1 function observation (FUN_0043da10). Confidence: high.

Located at wheel_base + 0x28c within per-wheel physics struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | compound[0] | FUN_0043da10 | Tire width source |
| +0x08 | unknown | compound[1] | FUN_0043da10 | Tire width 2 source |
| +0x08 | float | TireRadiusMax | FUN_0043da10 | From compound +0x08 |
| +0x20c | float | GripParam1 | FUN_0043da10 | From compound +0x24 |
| +0x210 | float | GripParam2 | FUN_0043da10 | From compound +0x24 (same source) |
| +0x214 | float | GripParam3 | FUN_0043da10 | From compound +0x28 |
| +0x218 | float | GripParam4 | FUN_0043da10 | From compound +0x2c |
| +0x21c | float | CamberFactor1 | FUN_0043da10 | compound[6] × _DAT_0059ec68 |
| +0x224 | float | CamberFactor2 | FUN_0043da10 | compound[6] × _DAT_0059ec60 |
| +0x22c | float | LoadSensitivity | FUN_0043da10 | Computed via FUN_004d6ae0 |
| +0x234 | float | GripMultiplier | FUN_0043da10 | From compound +0x48 |
| +0x238 | float | GripMultiplier2 | FUN_0043da10 | From compound +0x4c |
| +0x278 | float | TireRadiusMin | FUN_0043da10 | From compound +0x00 |
| +0x280 | float | TireWidth | FUN_0043da10 | compound[0] - compound[2] |
| +0x288 | float | TireRadiusMax | FUN_0043da10 | From compound +0x08 |
| +0x290 | float | TireWidth2 | FUN_0043da10 | compound[1] - compound[3] |
| +0x2d8 | (ptr) | SlipCurve1 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2dc | (ptr) | SlipCurve2 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2e0 | (ptr) | SlipCurve3 | FUN_0043da10 | Via FUN_004d75d0 lookup |
| +0x2e4 | float | LoadNormalization | FUN_0043da10 | 1.0 / (load_norm × _DAT_0059ec58) |
| +0x2f4 | float | OptimumCamber | FUN_0043da10 | compound[0x13] |
| +0x2fc | float | CamberSensitivity | FUN_0043da10 | compound[0x15] × _DAT_0059ec50 |
| +0x304 | float | CamberFactorMain | FUN_0043da10 | Computed: _DAT_0059e898 / camber |
| +0x30c | float | CamberSlope | FUN_0043da10 | Computed: _DAT_0059e890 / (max_camber - opt_camber) |
| +0x334 | float | OptimumTemp | FUN_0043da10 | compound[0x23] + 273.15 K |
| +0x34c | float[11] | CamberSensitivityTable | FUN_0043da10 | 0x34c-0x378, hardcoded values |
| +0x384 | float | BaseGrip | FUN_0043da10 | From compound +0x38 |
| +0x388 | float | GripFactor | FUN_0043da10 | From compound +0x3c |
| +0x38c | float | SensFactor | FUN_0043da10 | From compound +0x40 |
| +0x390 | float | SensFactor2 | FUN_0043da10 | From compound +0x44 |
| +0x394 | float | WearInit0 | FUN_0043da10 | Hardcoded 0 |
| +0x398 | float | WearInit1 | FUN_0043da10 | Hardcoded 1.0 |
| +0x3cc | float | WearRate | FUN_0043da10 | compound[0x1c] × DAT_007d0c60 × load_norm |

---



--- Section 22: Standings / Scoring Struct (int-indexed) (6 offsets) ---
## Standings / Scoring Struct (int-indexed)

Based on 2 function observations (FUN_004c0910, FUN_004c03f0). Confidence: medium — pattern consistent but only 2 functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x18 + i*4 | int | FINISHPOSITION[0..47] | FUN_004c0910 | array of finish positions |
| +0xd8 + i*4 | int | FINISHPOINTS[0..47] | FUN_004c0910 | array of points per race |
| +0x198 | int | SEASONPOINTS | FUN_004c0910 | accumulated total |
| +0x1a0 | int | POLESTAKEN | FUN_004c0910 | pole position count |
| +0x1a4 | int | ORIGINALGRIDPOSITION | FUN_004c0910 | |
| +0x1a8 | int | CURRENTGRIDPOSITION | FUN_004c0910 | |

Note: +0x18 to +0xd8 = 0xc0 bytes = 48 entries × 4 bytes. +0xd8 to +0x198 = 0xc0 bytes = same 48 entries × 4 bytes. Stride 0x18? No — the arrays have 48 elements each (0xc0 bytes each).

---



--- Section 23: UI State Struct (2 offsets) ---
## UI State Struct

Based on 1 function observation (FUN_004662c0). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xf4 | byte | flag | FUN_004662c0 | zeroed on reset |
| +0xf5 | byte | flag | FUN_004662c0 | zeroed on reset |

---



--- Section 24: D3D Vertex Buffer Object (inferred) (4 offsets) ---
## D3D Vertex Buffer Object (inferred)

Used by FUN_0054ca00. Per-buffer state with block descriptors,
render flags, and device handle.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | flags | FUN_0054ca00 | 0x8000000=clip, 0x800000=alpha |
| +0x118 | int | numBlocks | FUN_0054ca00 | Sub-mesh block count |
| +0x11c | ptr | blockArray | FUN_0054ca00 | Block descriptor array |
| +0x138 | ptr | devicePtr | FUN_0054ca00 | D3D device pointer |



--- Section 25: BVH/SpatialTreeNode (inferred) (12 offsets) ---
## BVH/SpatialTreeNode (inferred)

Based on 4 function observations (FUN_00403aa0, FUN_004039c0, FUN_0044aa30, FUN_004038e0). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x08 | short | NodeIdx | FUN_0044aa30 | Negative=leaf, 0=axis test |
| +0x0A | short | AxisIdx | FUN_0044aa30 | Comparison axis selector |
| +0x0C | int* | ChildPtr | FUN_0044aa30 | Child/sibling node pointer |
| +0x3C | float | Stride | FUN_004039c0 | Element stride |
| +0x94 | float | PosX | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center X |
| +0x98 | float | PosY | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center Y |
| +0x9C | float | PosZ | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Node center Z |
| +0xA4 | float | NormalX | FUN_00403aa0, FUN_004038e0 | Split plane normal X |
| +0xAC | float | NormalZ | FUN_00403aa0, FUN_004038e0 | Split plane normal Z |
| +0x10C | int* | NextPrimary | FUN_00403aa0 | Primary child / linked list |
| +0x110 | int* | NextSecondary | FUN_00403aa0, FUN_004039c0, FUN_004038e0 | Sibling/alternate / return value |
| +0x12C | int | CategoryTag | FUN_004038e0, FUN_00403aa0 | Match filter/type field (+300) |

---



--- Section 26: ImpulseAccumulator (inferred — param_1 in FUN_0044fee0) (6 offsets) ---
## ImpulseAccumulator (inferred — param_1 in FUN_0044fee0)

Based on FUN_0044fee0. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x560 | double | LinearImpulseX | Accumulated linear impulse |
| +0x568 | double | LinearImpulseY | |
| +0x570 | double | LinearImpulseZ | |
| +0x578 | double | AngularImpulseX | Accumulated angular impulse |
| +0x580 | double | AngularImpulseY | |
| +0x588 | double | AngularImpulseZ | |

---



--- Section 27: Source: docs/09-track-system.md (0 offsets) ---
## Source: docs/09-track-system.md

# Struct Offset Synthesis — Worker J

Source: docs/09-track-system.md



--- Section 28: AudioStreamStruct (inferred) (5 offsets) ---
## AudioStreamStruct (inferred)

Based on 2+ function observations. Confidence: medium.

Large audio codec/stream struct used by resampler and codec functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x24a4 | void* | InputBufferPtr | FUN_0052e6f0 | Input buffer pointer, null-checked |
| +0x24a8 | int | BitPosition | FUN_0052e6f0 | Bitstream read position |
| +0x24bc | int | RingBufIndex | FUN_00532aa0 | 16-entry ring buffer, decremented & masked |
| +0x24cc | int | EntryCount | FUN_00532aa0, FUN_0052e6f0 | 2=stereo, 1=mono |
| +0x24d0 | int | OutputStride | FUN_0052e6f0 | Output byte stride per channel |

---



--- Section 29: Struct 3: Waypoint Struct (stride 0x13c = 316 bytes) (14 offsets) ---
## Struct 3: Waypoint Struct (stride 0x13c = 316 bytes)

Based on FUN_00402690 observations. Confidence: **medium** — offset calculations may use mixed indexing (some byte, some word).

**NOTE:** Offsets below are as documented in FUN_00402690. The +0x0b and +0x25 field positions suggest these may not be simple byte offsets but a mix of byte and sub-byte offsets in a compressed struct.

| Offset | Size | Type | Field Name | Notes |
|--------|------|------|------------|-------|
| +0x00 | 12 | float[3] | Position (x, y, z) | World position |
| +0x08 | 12 | float[3] | PerpVector | Perpendicular direction to track |
| +0x0b | 16 | float[4] | Width | Track width at waypoint |
| +0x16 | 16 | float[4] | DWidth | Width delta |
| +0x12 | 4 | float? | Score | Waypoint score |
| +0x21 | 2 | byte[2] | Event | Event trigger values |
| +0x25 | 12 | float[3] | PosBackup | Backup copy of position |
| +0x46 | 1 | byte | GAlpha | Groove alpha |
| +0x47 | 1 | byte | GrooveLat | Groove lateral offset |
| +0x48 | 12 | ptr[3] | NextPtrs | 3 next-waypoint pointers |
| +0x4b | 1 | byte | BranchID | Branch identifier |
| +0x4c | 1 | byte | Bitfields | Waypoint flags |
| +0x4d | 2 | byte[2] | Wpse | Waypoint sequence data |
| +0x110 | 4 | ptr | NextWpPtr | Linked list next pointer |

**Offset overlap concerns:**
- +0x0b (Width, 4 floats = 16 bytes) overlaps with +0x12 (Score, 4 bytes) and +0x21 (Event, 2 bytes) and +0x25 (PosBackup, 12 bytes)
- +0x46 (GAlpha) overlaps with +0x47 (GrooveLat) → these are single bytes, adjacent
- The true byte layout likely differs from the documented offsets. These may be word indices or from an alternate decompile view.

**Recommendation:** Re-examine the .c source for FUN_00402690 to resolve the byte addressing scheme for this struct.

---



--- Section 30: Source: docs/05-weather-system.md (0 offsets) ---
## Source: docs/05-weather-system.md

Source: docs/05-weather-system.md (3 function entries, 13+ offset observations)

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_B.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
