# WORKER N — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker N of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_N.md

## YOUR STRUCT SECTIONS (14)

--- Section 188: AnimationNode / BoneGroup (16 offsets) ---
## AnimationNode / BoneGroup

Based on FUN_0054bf60 and FUN_004be9e0. Confidence: **medium**.

**Anim node:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | ptr | NextNode | FUN_0054bf60 | Linked list next |
| +0x118 | int | BoneGroupCount | FUN_0054bf60 | |
| +0x11c | ptr | BoneGroupArray | FUN_0054bf60 | |

**Bone group:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | GroupID | FUN_0054bf60 | Matches param_2 |
| +0x04 | int | BoneCount | FUN_0054bf60 | |
| +0x08 | ptr | BoneDataArray | FUN_0054bf60 | Bone transforms |
| +0x30 | int | DirtyFlags | FUN_0054bf60 | Bitmask |

**Animation state:**
| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x340 | byte | AnimFlag1 | FUN_004be9e0, FUN_004be700 | Animation state flag |
| +0x341 | byte | AnimFlag2 | FUN_004be9e0, FUN_004be700 | Animation state flag |
| +0x342 | byte | FlagC | FUN_004be700 | 0 |
| +0x344 | int/float | MultiplierA / AnimValue1 | FUN_004be9e0, FUN_004be700 | |
| +0x348 | float | MultiplierB | FUN_004be700 | |
| +0x34C | float | ThresholdRef | FUN_004be700 | From DAT_005ACDAC |
| +0x350 | float | FloatLimit / AnimValue2 | FUN_004be9e0, FUN_004be700 | 10.0 |
| +0x35C | int | IterationCount | FUN_004be700 | 10 |
| +0x360 | int | SubIterationCount | FUN_004be700 | 5 |

---



--- Section 189: Source: docs/20-math-utilities.md (0 offsets) ---
## Source: docs/20-math-utilities.md

# Consolidated Struct Definitions from docs/20-math-utilities.md

Generated from 235 struct offset observations across 172 function entries in `20-math-utilities.md`. 
Most observations (163) are from single-function structs — unique to individual functions.
Only 9 observations have 2+ functions sharing the same struct pattern.

---



--- Section 190: 14. AnimationList (inferred) (4 offsets) ---
## 14. AnimationList (inferred)

Animation/sprite list container.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x204 | ptr | ListHead | FUN_00585bf0, FUN_004f2e90 | Linked list of anim objects |
| +0x10 (node) | ptr | NextPtr | FUN_004f2e90 | Node next ptr |
| +0x118 | int | ElementCount | FUN_004f2e90 | Per-node sub-element count |
| +0x11c | ptr | ElementBase | FUN_004f2e90 | Per-element data array |



--- Section 191: VehicleWheelDataStruct (stride 0x3e/0x4a) (17 offsets) ---
## VehicleWheelDataStruct (stride 0x3e/0x4a)

From FUN_004EE2D0 vehicle dynamics update.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x32bc | int | PhysicsMode | 0=suspension, 1=brake, 2=tire, 3=replay |
| +0x34ac | float | RotationAngle | Vehicle rotation |
| +0x34b0-0x34e0 | float[9] | RotationMatrix | 3x3 rotation matrix |
| +0x34d4-0x34dc | float[3] | PositionOffset | Translation vector |
| +0x34ec-0x34f4 | float[3] | LocalPosition | Local space position |
| +0x34f8-0x3500 | float[3] | LocalOffset | Additional offset |
| +0x3590 | float[] | WheelData[4] | Per-wheel data stride 0x3e |
| +0x3668 | int | ContactCount | Number of contacts |
| +0x36c4 | float | ContactActive | Contact active flag |
| +0x3760 | int | WheelCount | Number of wheels |
| +0x3be8-0x3bf0 | float[3] | SurfaceNormal | Track surface normal |
| +0x3d54-0x3d5c | float[3] | ContactPos | Track contact point |
| +0x6e4 | ? | SuspensionData | Suspension state |
| +0x77c | ? | TireDataStart | Tire slip data |
| +0x7d4 | float[] | BrakeData[4] | Per-wheel brake stride 0x4a |
| +0x8cc-0xc44 | float[4] | TireWearChannels | 4 tire wear values stride 0x128 |
| +0x1070 | byte | ActiveFlag | Active flag |

---



--- Section 192: Source: docs/10-vehicle-physics.md (0 offsets) ---
## Source: docs/10-vehicle-physics.md

# Struct Offset Synthesis — Worker E

Source: `docs/10-vehicle-physics.md` (80 entries, 257 offset observations)

---



--- Section 193: WheelSuspensionInitStruct (inferred) (11 offsets) ---
## WheelSuspensionInitStruct (inferred)

Based on 1 function observation (FUN_004e2540). Confidence: medium.

Per-wheel suspension/tire initialization state.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x48 | float | PosX | FUN_004e2540 | |
| +0x4c | float | PosY | FUN_004e2540 | |
| +0x50 | float | PosZ | FUN_004e2540 | |
| +0x74 | float | VelocityStore1 | FUN_004e2540 | velocity = param_3 - position |
| +0x8c | int[9] | CoeffCopySource | FUN_004e2540 | 9 ints copied from +0xd0 |
| +0xb8 | float | VelocityStore2 | FUN_004e2540 | |
| +0xc4 | float | ParamStore1 | FUN_004e2540 | |
| +0xcc | float | ParamStore2 | FUN_004e2540 | |
| +0xd0 | int[9] | CoeffCopyTarget | FUN_004e2540 | Source for 9-int copy |
| +0xf8 | float | ParamStore3 | FUN_004e2540 | |
| +0xfc | float | ParamStore4 | FUN_004e2540 | |

---



--- Section 194: Filter Node Linked List (stride 0xc) (3 offsets) ---
## Filter Node Linked List (stride 0xc)

Based on 1 function observation (FUN_004c5e50). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | scene index | FUN_004c5e50 | |
| +0x04 | void* | next pointer | FUN_004c5e50 | |
| +0x08 | bool | active flag | FUN_004c5e50 | set to 1 |

---



--- Section 195: Camera/Projection Struct (inferred) (21 offsets) ---
## Camera/Projection Struct (inferred)

Used by FUN_004c7f30, FUN_00542050, possibly FUN_00542200.
Stores viewport/projection parameters and FOV settings.

Based on 2+ function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | float | nearClipZ | FUN_00542050 | Near clipping plane Z |
| +0x08 | float | farClipZ | FUN_00542050 | Far clipping plane Z |
| +0x0c | float | projScaleX | FUN_00542050 | Projection X scale |
| +0x10 | float | projScaleY | FUN_00542050 | Projection Y scale |
| +0x14 | float | widthFloat | FUN_00542200 | Viewport width as float |
| +0x18 | float | heightFloat | FUN_00542200 | Viewport height as float |
| +0x1c | float | tanHalfFovX | FUN_00542050 | tan(FOV_X/2) |
| +0x20 | float | tanHalfFovY | FUN_00542050 | tan(FOV_Y/2) |
| +0x54 | int | screenWidth | FUN_00542050, FUN_00542200 | Screen width in pixels |
| +0x58 | int | screenHeight | FUN_00542050, FUN_00542200 | Screen height in pixels |
| +0x5c | int | centerX | FUN_00542200 | Viewport center X |
| +0x60 | int | centerY | FUN_00542200 | Viewport center Y |
| +0x6c | float | fov | FUN_00542050, FUN_004c7f30 | Field of view |
| +0x70 | float | pitch | FUN_00542050 | Vertical angle |
| +0x74 | float | aspectRatio | FUN_00542200 | width/height |
| +0x78 | float | farDiagonal | FUN_00542050 | Far plane diagonal distance |
| +0x80 | int | flags | FUN_00542050, FUN_00542200 | Bit 4 = negate projection X |
| +0x9c..0xd8 | float[15] | viewMatrix | FUN_00542050 | 3×3 orientation matrix |
| +0xec..0xf8 | float[3] | translation | FUN_00542050 | Zeroed translation |
| +0xdc..0xe8 | float[3] | forwardZ | FUN_00542050 | Forward vector Z component |
| +0x19c | ptr | chainTexture | FUN_00495dc0 | Dereference chain to source texture |



--- Section 196: Lazy Init Struct (inferred) (2 offsets) ---
## Lazy Init Struct (inferred)

Used by FUN_004184f0. Guards subsystem initialization with
flag and resource handle.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xaf0 | byte | initFlag | FUN_004184f0 | Non-zero if initialized |
| +0xaf4 | int | resourceHandle | FUN_004184f0 | Initialized resource handle |



--- Section 197: ProximitySphere (inferred — entry in FUN_004bda20) (6 offsets) ---
## ProximitySphere (inferred — entry in FUN_004bda20)

Based on FUN_004bda20. Confidence: **high**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x04 | int | Tag | Owner/type tag |
| +0x0C | float | CenterX | Sphere center X |
| +0x10 | float | CenterY | Sphere center Y |
| +0x14 | float | CenterZ | Sphere center Z |
| +0x18 | float | Radius | Sphere radius |
| +0x20 | int | ExcludeTag | Exclude from matching |

---



--- Section 198: CollisionProxyFlagSetter (inferred — from FUN_004ba140) (0 offsets) ---
## CollisionProxyFlagSetter (inferred — from FUN_004ba140)

Based on FUN_004ba140. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| param_1+0x08 | int* | EntityPtr | Base pointer to entity/proxy |
| EntityPtr+0xF78 | byte | FlagField | Byte field being set |

---



--- Section 199: 12. Environment/Track Struct (inferred) (4 offsets) ---
## 12. Environment/Track Struct (inferred)

Based on 1 function observation (FUN_004ade20). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1aec | int | EnvMode | FUN_004ade20 | Environment mode (1=dry, 2=wet, 3=mixed) |
| +0x1b10 | int | CameraCount | FUN_004ade20 | Number of track cameras |
| +0x1b18 | int | CameraMin | FUN_004ade20 | Minimum camera count bound |
| +0x1b1c | int | CameraMax | FUN_004ade20 | Maximum camera count bound |

---



--- Section 200: StreamBufferReadStruct (inferred) (5 offsets) ---
## StreamBufferReadStruct (inferred)

Based on 1 function (FUN_0050fab7). Confidence: low.

Stream/buffer read state machine with vtable dispatch.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | uint | vtable | FUN_0050fab7 | Virtual method table |
| +0x08 | uint | IOCallback | FUN_0050fab7 | I/O callback function pointer |
| +0x10 | int | MagicCheck | FUN_0050fab7 | param_1[4]; must be 0xcd |
| +0x60 | uint | CompletionCallback | FUN_0050fab7 | Completion handler (conflict: also listed as total size) |
| +0x78 | uint | ReadCursor | FUN_0050fab7 | Current read position |

**Conflict:** +0x60 appears as both CompletionCallback and TotalSize in the same source. Needs verification.

---



--- Section 201: Source: docs/04-tire-system.md (0 offsets) ---
## Source: docs/04-tire-system.md

Source: `docs/04-tire-system.md` — 6 functions with struct offset observations,
~35 offset observations across 5 inferred structs.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_N.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
