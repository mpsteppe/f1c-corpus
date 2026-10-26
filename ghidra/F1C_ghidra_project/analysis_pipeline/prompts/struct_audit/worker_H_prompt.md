# WORKER H — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker H of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_H.md

## YOUR STRUCT SECTIONS (14)

--- Section 104: Texture/VertexDecoder (param_1 — texture context) (26 offsets) ---
## Texture/VertexDecoder (param_1 — texture context)

Shared decoder struct. Offsets in 0x1000–0x10xx range. Used by ~12 functions.
Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | PostProcessFlag | FUN_00509e85, FUN_0050a34b, FUN_00509644 | Enables post-processing |
| +0x18 | int | PixelDataStart / BaseIndex | FUN_00509e85, FUN_00509de6, FUN_005086dd, FUN_0050a34b, FUN_00509644 | Base offset / index |
| +0x2c | ptr | ColorTableBase / PaletteArrayPtr / SourceDataPtr | FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005085c5, FUN_00508b1d | Float[4] palette entries |
| +0x38 | float[4]×256 | ReferenceVerts / ReferenceArray | FUN_005086dd, FUN_005085c5 | 256×4 floats |
| +0x60 | uint | RenderFlags | FUN_0051378b | Checked against 0x602000 |
| +0x104 | ptr | PixelDataPtr | FUN_0051378b | RGB pixel data |
| +0x108 | ushort | PixelCount | FUN_0051378b | |
| +0x116 | byte | ColorDepthMode | FUN_0051378b | 3=triggers processing |
| +0x138 | int | ColorOffset | FUN_0051378b | Additive offset per channel |
| +0x150 | byte | ShiftR | FUN_0051378b | Clamped 0–8 |
| +0x151 | byte | ShiftG | FUN_0051378b | |
| +0x152 | byte | ShiftB | FUN_0051378b | |
| +0x1034 | int | OffsetA | FUN_0050aeae | Row offset |
| +0x1040 | int | OffsetB | FUN_0050aeae | Column offset |
| +0x1048 | int | TransformFlag / DataTransformFlag / EncryptedFlag | FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005086dd, FUN_0050aeae, FUN_005085c5, FUN_00508b1d, FUN_005093f9 | Non-zero = apply matrix |
| +0x1050 | int | TexStrideX / StrideX / InputStride / WidthFactor | FUN_00509e85, FUN_00509de6, FUN_0050a223, FUN_0050a92d, FUN_0050a34b, FUN_005086dd, FUN_00509644 | Texture/vertex width stride |
| +0x1054 | int | TexStrideY / StrideY / OutputStride / HeightFactor | FUN_00509e85, FUN_00509de6, FUN_0050a223, FUN_0050a92d, FUN_0050a34b, FUN_005086dd, FUN_00509644 | Texture/vertex height stride |
| +0x1058 | int | PixelCount / VertexCount / EntryCount | FUN_00509e85, FUN_00509de6, FUN_00508c22, FUN_0050930b, FUN_005078b5, FUN_0050a223, FUN_0050a34b, FUN_00508d2d, FUN_00507bc5, FUN_005084f5, FUN_005082d1, FUN_005086dd, FUN_0050aeae, FUN_005093f9, FUN_005085c5, FUN_00508b1d, FUN_00509644, FUN_00507845 | Number of pixels/vertices |
| +0x106c | float[8] | InputVertexArray / DestBuffer | FUN_0050a92d, FUN_0050aeae, FUN_0050b27c | Per-vertex input |
| +0x1070 | int | CurrentIndex / RowPitch / Scale | FUN_0050a92d, FUN_0050aeae, FUN_0050b27c | Vertex index / row pitch |
| +0x1078 | int | VertexCount | FUN_0050a92d | Total vertices |
| +0x1080 | int | OutputRowStride | FUN_0050a92d | |
| +0x108c | ptr/int | InputBuffer / CopyCompleteFlag | FUN_0050a92d, FUN_0050aeae | Dirty flag / flag |
| +0x1090 | ptr | OutputBuffer | FUN_0050a92d | Output buffer |
| +0x1094 | int | ChannelBitShift0 | FUN_0050a92d | Bit shift for channel 0/2 |
| +0x1098 | int | ChannelBitShift1 | FUN_0050a92d | Bit shift for channel 1/3 |

---



--- Section 105: ChecksumCompute (checksum/hash context) (3 offsets) ---
## ChecksumCompute (checksum/hash context)

Based on FUN_0051e5d7, FUN_0051e6ec. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x5c | int | BlockSize / OutputElementCount | FUN_0051e6ec, FUN_0051e5d7 | Bytes per block |
| +0x64 | int | EntryCount / TableCount | FUN_0051e6ec, FUN_0051e5d7 | Number of parallel streams |
| +0x1a4 | ptr | TableBase / TableArrayPtr | FUN_0051e6ec, FUN_0051e5d7 | Checksum context |

---



--- Section 106: 8. PauseStringTable (inferred — FUN_004541d0) (2 offsets) ---
## 8. PauseStringTable (inferred — FUN_004541d0)

Pause menu string table manager.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xc88 | int | EntryCount | FUN_004541d0 | Max string count |
| +0xc8c | int | CurrentID | FUN_004541d0 | Current string ID |



--- Section 107: ConstraintSolverParamStruct (from FUN_00434860) (16 offsets) ---
## ConstraintSolverParamStruct (from FUN_00434860)

Constraint solver parameter struct.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | byte | Flag0 | 0 |
| +0x01 | byte | Enabled | 1 = enabled |
| +0x02 | byte | Flag2 | 0 |
| +0x04 | int | ParamI0 | 0 |
| +0x08 | int | ParamI1 | 0 |
| +0x0c | int | ParamI2 | 0 |
| +0x10 | float | AngleLimit1 | 90.0f |
| +0x14 | float | AngleLimit2 | 75.0f |
| +0x18 | int | Sentinel | 0xffffffff (-1) |
| +0x1c | int | ParamI3 | 0 |
| +0x20 | int | ParamI4 | 0 |
| +0x24 | float | MaxForce | 2.0f |
| +0x28 | int | ParamI5 | 0 |
| +0x2c | int | ParamI6 | 0 |
| +0x30 | float | FrictionCoeff | 3.25f |
| +0x34 | int | ParamI7 | 0 |

---



--- Section 108: ConstraintEnforceStruct (4 offsets) ---
## ConstraintEnforceStruct

From FUN_004380b0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1e8 | double | DispX | Displacement X |
| +0x1f0 | double | DispY | Displacement Y |
| +0x1f8 | double | RestPosX | Rest position X |
| +0x204 | double | Distance | Computed distance |

---



--- Section 109: SetupParamArrayEntry (inferred) (8 offsets) ---
## SetupParamArrayEntry (inferred)

Based on 1 function observation (FUN_0042f470). Confidence: high.

Entry in SetupParamArray at param_1 + 0xbb0, stride 0x40 per entry.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | double | BaseValue | FUN_0042f470 | Base setup value |
| +0x08 | double | Multiplier | FUN_0042f470 | Scale factor |
| +0x10 | int | ParamCount | FUN_0042f470 | |
| +0x14 | int | CurrentValue | FUN_0042f470 | |
| +0x18 | char* | FormatName | FUN_0042f470 | String name |
| +0x1c | int | Flags | FUN_0042f470 | Attribute flags |
| +0x20 | (extra) | (padding) | FUN_0042f470 | Remaining bytes to 0x40 stride |
| +0x40 | - | EntryStride | - | 0x40 |

---



--- Section 110: Game State / Session Config Struct (13 offsets) ---
## Game State / Session Config Struct

Based on 3 function observations (FUN_004c11e0, FUN_004c0b70, FUN_004c0db0). Confidence: medium — offsets overlap suggest large struct with multiple sections.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb110 | int | filter base start | FUN_004c0db0 | |
| +0xb114 | int | filter base repeat | FUN_004c0db0 | |
| +0xb118 | int | filter count | FUN_004c0db0 | |
| +0xb11c | bool | filter active flag | FUN_004c0db0 | |
| +0xb130 | int | QualifyLaps | FUN_004c11e0 | |
| +0xb134 | int | QualifyTime | FUN_004c11e0 | |
| +0xb138 | int | RaceLaps | FUN_004c11e0 | |
| +0xb13c | int | RaceTime | FUN_004c11e0 | |
| +0xb140 | void* | Current track data ptr | FUN_004c11e0 | |
| +0xb144 | int | session filter type (=2) | FUN_004c0db0, FUN_004c0b70 | also SEASONSTATUS |
| +0xb148 | int | CURRENTRACE | FUN_004c0b70, FUN_004c0db0 | current race index |
| +0xb14c | int | RACESESSION | FUN_004c0b70 | |
| +0xb150 | bool | RACEOVER | FUN_004c0b70 | |

**Conflict:** +0xb144 is called "session filter type" in FUN_004c0db0 and "SEASONSTATUS" in FUN_004c0b70. Both may be aliases for same field (season status determines filter type). Uncertain.

---



--- Section 111: Buffer Flush/Write I/O Struct (FUN_0058a05a) (5 offsets) ---
## Buffer Flush/Write I/O Struct (FUN_0058a05a)

Based on 1 function observation (FUN_0058a05a). Confidence: low — offset names from doc comment.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | WritePos | FUN_0058a05a | current write position |
| +0x04 | void* | StartPos | FUN_0058a05a | start of buffer |
| +0x08 | void* | BufferStart | FUN_0058a05a | buffer base |
| +0x0c | uint | Flags | FUN_0058a05a | mode bits |
| +0x10 | int | IOHandle | FUN_0058a05a | underlying I/O handle |

---



--- Section 112: List Container (doubly-linked) (inferred) (4 offsets) ---
## List Container (doubly-linked) (inferred)

Used by FUN_004967d0, FUN_004b9000, FUN_00486540. Generic
doubly-linked list with head/tail/element tracking.

Based on 3 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x18cc | ptr | head | FUN_004967d0 | List head pointer |
| +0x18d0 | ptr | tailWrite | FUN_004967d0 | Tail write pointer |
| +0x18d4 | ptr | tailAlt | FUN_004967d0 | Alternative tail |
| +0x18d8 | int | elementCount | FUN_004967d0 | Element count |



--- Section 113: CollisionDeformationMesh (inferred — param_1 in FUN_004DF110) (7 offsets) ---
## CollisionDeformationMesh (inferred — param_1 in FUN_004DF110)

Based on FUN_004DF110. Confidence: **medium**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x00 | float | MaxValue | Current max, updated to param_2 |
| +0x08 | int | GroupCount | Number of vertex groups |
| +0x0C | int* | GroupArray | Pointer to group data (stride 0xC) |
| +0x10 | int | EntityCount | Number of entities |
| +0x14 | int* | EntityArray | Pointer to entity array |
| +0x18 | int | EntryCount | Number of entries |
| +0x1C | float* | EntryArray | Entries start (stride 9 floats = 0x24 bytes) |

---



--- Section 114: Tire/vehicle struct (partial from FUN_004a6b80 comments) (3 offsets) ---
## Tire/vehicle struct (partial from FUN_004a6b80 comments)

Based on FUN_004a6b80 description. Confidence: **low** — listed in comments but not explicitly tabulated.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x344C | int | ActiveFlag | Vehicle collision active |
| +0x34E0 | float[3] | Position | Vehicle position |
| +0x34F8 | float[3] | Direction | Vehicle direction normal |

---



--- Section 115: 6. Camera Manager Struct (inferred) (11 offsets) ---
## 6. Camera Manager Struct (inferred)

Based on observations from FUN_00408e20, FUN_00408870. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | Camera* | NoseCam | FUN_00408e20 | NOSECAM camera object |
| +0x14 | Camera* | CockpitCam | FUN_00408e20 | COCKPIT camera object |
| +0x18 | Camera* | TVCockpitCam | FUN_00408e20 | TVCOCKPIT camera object |
| +0x1c | Camera* | SwingmanCam | FUN_00408e20 | SWINGMAN camera (TV broadcast) |
| +0x20 | Camera* | ExtraCamArray | FUN_00408e20 | Array of additional cameras (200 bytes each) |
| +0x24 | Camera* | PitCam | FUN_00408e20 | Set by FUN_00408870 (2SEATER/3SEATER/pits) |
| +0x28 | Camera* | Unused1 | FUN_00408e20 | UNUSED allocated camera |
| +0x2c | Camera* | Unused2 | FUN_00408e20 | UNUSED allocated camera |
| +0x30 | Camera* | Unused3 | FUN_00408e20 | UNUSED allocated camera |
| +0x40 | int/str? | CameraName | FUN_00408e20 | Camera name identifier |
| +0x44 | int | CameraCount | FUN_00408e20 | Camera slot count |

**Note:** There is a potential struct size issue. Offsets +0x28 to +0x30 are 4 bytes each (3 Camera* pointers). But +0x40 appears right after +0x30 with +0x10 gap — suggests additional fields between +0x30 and +0x40 not documented, or +0x40 is relative to a different struct.

---



--- Section 116: AudioMixerValueStruct (inferred) (3 offsets) ---
## AudioMixerValueStruct (inferred)

Based on 1 function (FUN_00562fe0). Confidence: medium.

Simple value store with vtable-based audio dispatch callback.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Value | FUN_00562fe0 | Written from param_2 |
| +0x78 | code* | vtable_fn | FUN_00562fe0 | Audio callback at vtable+0x78 |
| +0x7c | int | ChannelId | FUN_00562fe0 | Passed as third arg to callback |

---



--- Section 117: Struct 9: Race Mode State Struct (FUN_004ae9f0 / FUN_004af220) (2 offsets) ---
## Struct 9: Race Mode State Struct (FUN_004ae9f0 / FUN_004af220)

Based on 2 observations. Confidence: **low** — sparse data. These may overlap with the Vehicle struct (param_1) at different offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1b10 | int | DifficultyMode | FUN_004ae9f0 | 1-4 selector |
| +0x1b34 | int | ModeSelector | FUN_004af220 | 1-4 selector |

These are at high offsets (+0x1b10, +0x1b34) — likely still within the Vehicle struct (stride ~0x48C0), not a separate struct.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_H.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
