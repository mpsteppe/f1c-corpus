# WORKER R — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker R of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_R.md

## YOUR STRUCT SECTIONS (14)

--- Section 244: AudioSoundInstance (param_1 — sound instance) (5 offsets) ---
## AudioSoundInstance (param_1 — sound instance)

Based on FUN_00541810. Confidence: **low** (unusual offset encoding).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x000 | undefined4 | AudioResult | FUN_00541810 | Stores last op result |
| +0x4f6×4 | int | SoundSystemPtr | FUN_00541810 | Null guard |
| +0x440×4 | int | SoundSystemVtable | FUN_00541810 | |
| +0x557×4 | int | InstanceCount | FUN_00541810 | |
| +0x558×4 | int[] | InstanceIDs | FUN_00541810 | Array of sound IDs |

---



--- Section 245: Vehicle/AI Struct Offsets (High Offset Ranges) (13 offsets) ---
## Vehicle/AI Struct Offsets (High Offset Ranges)

These offsets (>0x1000 or known AI offsets) suggest vehicle or AI struct access rather than utility struct access. From docs/20-math-utilities.md.

| Offset | Field | Type | Notes | Function |
|--------|-------|------|-------|----------|
| +0x1000 | ReadCursor | short | Ring buffer head | FUN_0057b530 (?) |
| +0x1000 | ReadCursor | short | | FUN_0057b630 (?) |
| +0x1002 | AvailableData | ushort | Ring buffer tail | FUN_0057b530 (?) |
| +0x1002 | AvailableData | ushort | | FUN_0057b630 (?) |
| +0x1040 | Scale | float | Graphics scale factor | FUN_00530b50 (?) |
| +0x105c | ObjectIndex | int | Object/vertex index | FUN_00530b50 (?) |
| +0x1b79c | ? | ? | | FUN_005a7320 (?) |
| +0x32d0 | ? | int | | FUN_004A3570 (?) |
| +0x3e18 | ? | int | | FUN_005a0d00 (?) |
| +0x3fc4 | SessionState | int | | FUN_004AB040 (?), FUN_004AB230 (?) |
| +0x4034 | ? | int | | FUN_004a1dc0 (?) |
| +0x4038 | ? | int | | FUN_004A3570 (?) |
| +0x4354 | AIStateFlags | int | Overtaking zone flag | FUN_0052bbe8 (?) |

Note: These offsets appear in math-utility-targeted functions that may actually belong to game-logic subsystems despite being filed under docs/20.

---



--- Section 246: 18. FreeableMultiPtr (inferred) (3 offsets) ---
## 18. FreeableMultiPtr (inferred)

Struct with 3-7 freeable pointer fields, often freed in cleanup loops.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c..+0x24 | void*[7] | FreeablePtrs | FUN_0058f8eb | Freed if not sentinel |
| +0x224..+0x240 | ptr*3+int*3 | SubBuffers | FUN_005913d0 | 3 ptrs + counters |
| +0x0c/+0x1c/+0x20 | ptr*3 | ResourcePtrs | FUN_0059a17b | Freed with release+free |



--- Section 247: EntityGridManagerStruct (16 offsets) ---
## EntityGridManagerStruct

From FUN_00465460. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x6c | int* | ListHead | Master entity list head |
| +0x74 | int* | ListCurrent | Traversal cursor |
| +0x7c | int* | AltListHead | Secondary list head |
| +0x84 | int* | AltListCur | Secondary cursor |
| +0x2b4 | short | BudgetRemaining | Per-vehicle budget carry-over (stride 0x230) |
| +0x2b6 | byte | EntityTypeFilter | Per-vehicle type check |
| +0x2b8 | int* | EntityPtrs | Per-slot entity pointers |
| +0xe410 | int[32] | EntityTypeMap | Per-slot entity type filter |
| +0xe5b0 | int* | ActiveListHead | Active processing list |
| +0xe5b4 | int* | ActiveListTail | Tail |
| +0xe5b8 | int* | ActiveListIter | Iterator |
| +0xe5bc | int | ActiveListCount | Count |
| +0xe5c0 | int* | WorkListHead | Pending-entity work list |
| +0xe5c4 | int* | WorkListTail | Tail for append |
| +0xe5c8 | int* | WorkListIter | Iterator |
| +0xe5cc | int | WorkListCount | Entity count |

---



--- Section 248: PhysicsBody (solver system) (inferred) (13 offsets) ---
## PhysicsBody (solver system) (inferred)

Inside BodyArray (stride 0x244) from FUN_0056d930.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | NameString | FUN_0056d930 | |
| +0x04 | double[4] | PositionQuaternion | FUN_0056d930 | 4 doubles (pos + quaternion) |
| +0x1c | double[4] | OrientationQuat | FUN_0056d930 | Continuation? |
| +0x20 | double[3] | InertiaDiagonal | FUN_0056d930 | Principal inertia |
| +0x34 | double[3] | InertiaOffDiagonal | FUN_0056d930 | Products of inertia |
| +0x38 | double[3] | InertiaOffDiag2 | FUN_0056d930 | |
| +0x48 | double[3] | TransformMatrixRaw | FUN_0056d930 | |
| +0x4c | double[4×4] | TransformMatrix | FUN_0056d930 | 4×4 transform |
| +0x224 | (ptr) | AuxDataPtr | FUN_0056d930 | Per-body auxiliary pointer |
| +0x228 | (ptr) | BodyDataPtr | FUN_0056d930 | Per-body data pointer |
| +0x22c | int | JointRefCount | FUN_0056d930 | Number of joints referencing this body |
| +0x234 | int | HingeRefCount | FUN_0056d930 | Number of hinges referencing this body |
| +0x23c | int | BarRefCount | FUN_0056d930 | Number of bars referencing this body |

---



--- Section 249: Vehicle Struct (int-indexed from .veh file parser) (26 offsets) ---
## Vehicle Struct (int-indexed from .veh file parser)

Based on 1 function observation (FUN_004c3200). Confidence: medium — int-indexed, stride unclear.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | filename | FUN_004c3200 | string pointer (int-indexed [0]) |
| +0x02 | char* | HDVehicle file path | FUN_004c3200 | [2] |
| +0x04 | char* | HeadPhysics file path | FUN_004c3200 | [4] |
| +0x06 | char* | Sounds file path | FUN_004c3200 | [6] |
| +0x08 | char* | Graphics file path | FUN_004c3200 | [8] |
| +0x0a | char* | GenString | FUN_004c3200 | [0xa] |
| +0x0e–+0x10 | float×3 | Eyepoint | FUN_004c3200 | 3 floats at [0xe], [0xf], [0x10] |
| +0x11–+0x13 | float×3 | CameraTarget | FUN_004c3200 | 3 floats at [0x11], [0x12], [0x13] |
| +0x14–+0x16 | float×3 | MirrorPos | FUN_004c3200 | 3 floats at [0x14], [0x15], [0x16] |
| +0x17–+0x19 | float×3 | MirrorNorm | FUN_004c3200 | 3 floats at [0x17], [0x18], [0x19] |
| +0x1a–+0x1c | float×3 | SteeringWheelAxis | FUN_004c3200 | 3 floats at [0x1a], [0x1b], [0x1c] |
| +0x1d | char* | Number | FUN_004c3200 | [0x1d] |
| +0x1f | char* | (unknown) | FUN_004c3200 | [0x1f] |
| +0x2f | char* | Driver name | FUN_004c3200 | [0x2f] |
| +0x3f | char* | Description | FUN_004c3200 | [0x3f] |
| +0x4f | char* | Engine file | FUN_004c3200 | [0x4f] |
| +0x5f | char* | Manufacturer | FUN_004c3200 | [0x5f] |
| +0x6f | char* | Classes | FUN_004c3200 | [0x6f] |
| +0xaf | char* | FullTeamName | FUN_004c3200 | [0xaf] |
| +0xcf | char* | TeamFounded | FUN_004c3200 | [0xcf] |
| +0xd3 | char* | TeamHeadquarters | FUN_004c3200 | [0xd3] |
| +0xe3 | char* | TeamStarts | FUN_004c3200 | [0xe3] |
| +0xe7 | char* | TeamPoles | FUN_004c3200 | [0xe7] |
| +0xeb | char* | TeamWins | FUN_004c3200 | [0xeb] |
| +0xef | char* | TeamWorldChampionships | FUN_004c3200 | [0xef] |
| +0xf5 | void* | TrackLivery linked list | FUN_004c3200 | [0xf5] |

Note: This is clearly a string-table struct (int-indexed, each slot = 4 bytes pointer). Total ~0xf9 slots ≈ 996 bytes. Not the physics vehicle struct.

---



--- Section 250: Stream Object Struct (4 offsets) ---
## Stream Object Struct

Based on 1 function observation (FUN_0059a3a9). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04 | uint | status/flags | FUN_0059a3a9 | |
| +0x28 | void* | stored reference | FUN_0059a3a9 | param_2 |
| +0x2c | void* | zeroed | FUN_0059a3a9 | |
| +0x30 | ushort | buffer/chunk size | FUN_0059a3a9 | |

---



--- Section 251: Animation State Struct (inferred) (9 offsets) ---
## Animation State Struct (inferred)

Used by FUN_00486730, FUN_00403cd0. Timed animation trigger with
frame index, accumulator, and loop settings.

Based on 2 function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x10 | int | maxFrames | FUN_00486730 | Frame count limit |
| +0x18 | int | duration | FUN_00486730 | Per-frame duration |
| +0x1c | int | loopMode | FUN_00486730 | 0=wrap, non-0=modulo |
| +0x28 | int | active | FUN_00486730 | 0=disabled |
| +0x80 | float | accumulator | FUN_00486730 | Elapsed time accumulator |
| +0x84 | int | stateID | FUN_00486730 | Animation state identifier |
| +0x88 | int | frameIndex | FUN_00486730 | Current animation frame |
| +0xdc | int | repeatCount | FUN_00486730 | Remaining repeats |
| +0x150 | float[7] | keyframeArray | FUN_00403cd0 | Frames: pos xyz + quaternion xyzw |



--- Section 252: Offset conflicts (3 offsets) ---
## Offset conflicts

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x14 | int flags | FUN_0054ca00 (0x8000000 clip), FUN_0054d9f0 (0x800000 LOD), FUN_004e2d00 (bit 26 transformed) | Same struct? Unlikely — different struct types, likely int flags in each |
| +0x20 | different usage | FUN_0040eb30 (ref param), FUN_00558d80 (flags), FUN_00558dc0 (byte flag), FUN_00586d70 (bitmap data) | Different struct types — not same struct |
| +0x50 | different usage | FUN_00558d80 (surface array ptr), FUN_00558dc0 (pixel buffer ptr), FUN_00558d10 (sub-struct ptr) | Same texture manager struct across these functions — consistent |



--- Section 253: OscillatoryCollisionState (inferred — FUN_0045c7e0 / FUN_0045c8f0) (11 offsets) ---
## OscillatoryCollisionState (inferred — FUN_0045c7e0 / FUN_0045c8f0)

Based on 2 function observations. Confidence: **low**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | Accum0 | FUN_0045c7e0 | Primary accumulator |
| +0x04 | float | Accum1 | FUN_0045c7e0 | Secondary accumulator |
| +0x08 | float | Accum2 | FUN_0045c7e0 | Tertiary accumulator |
| +0x0C | int | OverflowScaled | FUN_0045c7e0 | Overflow scaled result |
| +0x10 | float | Accum3 | FUN_0045c7e0 | |
| +0x14 | float | Accum4 | FUN_0045c7e0 | |
| +0x68 (stride) | float | ContactTimer[i] | FUN_0045c8f0 | Per-contact timers |
| +0x1B4+id*4 | float | ContactThreshold[i] | FUN_0045c8f0 | Per-contact threshold |
| +0x354+id | byte | ContactActive[i] | FUN_0045c8f0 | Per-contact active flag |
| +0x3BC+id | byte | ContactPosIdx[i] | FUN_0045c8f0 | Per-contact position index |
| +0x1124+id*4 | float | ContactOutput[i] | FUN_0045c8f0 | Per-contact output (-1.0f) |

---



--- Section 254: DamageModelSubStruct (PHYSICAL section) (24 offsets) ---
## DamageModelSubStruct (PHYSICAL section)

Based on 1 function observation (FUN_004f24f0). Confidence: **medium**.

Loaded by `vehload.cpp` from `.svm`/`.hdv` PHYSICAL section. Could be a sub-struct within the vehicle struct at some base offset, or a separate allocation passed as param_1. The doc treats it as param_1 base.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | float | RadiusAdd | FUN_004f24f0 | body collision radius addition |
| +0x04 | float | RadiusMult | FUN_004f24f0 | body collision radius multiplier |
| +0x08 | float | RadiusMax | FUN_004f24f0 | maximum collision radius |
| +0x0c | float | EngineCollision | FUN_004f24f0 | engine collision parameter |
| +0x10 | float | AeroDiv | FUN_004f24f0 | aero division factor |
| +0x14 | float | AeroMin | FUN_004f24f0 | aero minimum |
| +0x18 | float | VertMult | FUN_004f24f0 | vertical multiplier |
| +0x1c | float | FrontWingDetach | FUN_004f24f0 | front wing detach threshold |
| +0x20 | float | FrontWingRandom | FUN_004f24f0 | front wing random failure chance |
| +0x24–+0x2c | float×3 | FrontWingPos | FUN_004f24f0 | xyz position (3 floats) |
| +0x30–+0x3c | 4 vals | FrontWingMassInertia | FUN_004f24f0 | mass + 3 inertia; exact type uncertain |
| +0x40–+0x48 | 3 vals | FrontWingCollParams | FUN_004f24f0 | 3 collision params; exact type uncertain |
| +0x4c | float | RearWingDetach | FUN_004f24f0 | rear wing detach threshold |
| +0x50 | float | RearWingRandom | FUN_004f24f0 | rear wing random failure chance |
| +0x54–+0x5c | float×3 | RearWingPos | FUN_004f24f0 | xyz position (3 floats) |
| +0x60–+0x6c | 4 vals | RearWingMassInertia | FUN_004f24f0 | mass + 3 inertia |
| +0x70–+0x78 | 3 vals | RearWingCollParams | FUN_004f24f0 | 3 collision params |
| +0x7c | float | WheelBendThreshold | FUN_004f24f0 | wheel bending threshold |
| +0x80 | float | WheelDetachThreshold | FUN_004f24f0 | wheel detach threshold |
| +0x84 | float | WheelRandomFail | FUN_004f24f0 | wheel random failure chance |
| +0x88–+0xfc | stride 0x1c ×4 | Wheel_MassInertia[4] | FUN_004f24f0 | 4 wheels × 4 values each (mass + 3 inertia) |
| +0x118–+0x158 | float×8 | PartDetach[0..7] | FUN_004f24f0 | 8 part detach thresholds (4 bytes each) |
| +0x13c–+0x178 | stride 0xc ×8 | PartPos[0..7] | FUN_004f24f0 | 8 parts × 3 floats each (xyz position) |
| +0x1a0–+0x250 | stride 0x1c ×8 | PartMassInertia[0..7] | FUN_004f24f0 | 8 parts × (mass + 3 inertia + 3 collision params) |

**Type uncertainty:** The doc does not explicitly state types for damage struct fields. Types above are inferred from offset spacing (0x04 = float, ranges covering 3 values over 12 bytes = float×3). The `MassInertia` and `CollParams` ranges use stride 0x1c = 28 bytes, which may contain doubles or structs — verify against Ghidra pseudocode.

---



--- Section 255: Summary (15 offsets) ---
## Summary

| # | Struct Name | Observed Offsets Span | Functions | Confidence |
|---|-------------|----------------------|-----------|------------|
| 1 | TrackMaterial | +0x08 to +0x60 | 1 | medium |
| 2 | CommentaryEvent | +0x04 to +0x28 | 1 | low |
| 3 | CockpitDashboard | +0x20 to +0x190 | 1 | medium |
| 4 | Vehicle | +0x58 to +0x489c | 7 | high |
| 5 | SpecialFX | +0x00 to +0x0d | 1 | low |
| 6 | CameraManager | +0x10 to +0x44 | 1 | medium |
| 7 | Camera (200B) | +0x14 to +0xa8 | 4 | medium |
| 8 | SceneFile | +0x188 to +0x19c | 1 | medium |
| 9 | SceneNode/Instance | +0x3c to +0x174 | 2 | low |
| 10 | NetCommSession | +0x0c to +0x1b79c | 14 | high |
| 11 | PlayerSlot (0x8c) | +0x00 to +0x8b | 2 | medium |
| 12 | Environment/Track | +0x1aec to +0x1b1c | 1 | low |
| 13 | CommentaryPathList | +0x00 to +0x17 | 1 | very low |
| 14 | UIDialog | +0x1fc to +0x304 | 2 | low |
| 15 | NetSessionFilter | +0xc4 | 1 | low |

Total offset observations extracted: ~100+
Total distinct structs identified: 15

---



--- Section 256: Source: docs/02-ai-system.md (0 offsets) ---
## Source: docs/02-ai-system.md



--- Section 257: Struct 4: TireCompoundEntry (stride 0x2a8 = 680 bytes) (7 offsets) ---
## Struct 4: TireCompoundEntry (stride 0x2a8 = 680 bytes)

Based on 2 function observations (FUN_004d6b00, FUN_004d7570).
Confidence: **medium** — compound stride (0x2a8) confirmed by VALIDATE pattern
in FUN_004d7570 (index × 0x2a8).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00–+0xdf | — | (header/gap) | — | 224 bytes undocumented |
| +0x0e0 | unknown (likely double) | wearRate | FUN_004d6b00 | player tire wear rate |
| +0x0f0 | unknown (likely double) | aiSensitivityMin | FUN_004d6b00 | AI tire sensitivity minimum |
| +0x0f8 | unknown (likely double) | aiSensitivityMax | FUN_004d6b00 | AI tire sensitivity maximum |
| +0x100 | unknown (likely double) | aiGripMult | FUN_004d6b00 | AI grip multiplier |
| +0x110 | unknown (likely double) | aiWearMult | FUN_004d6b00 | AI-specific wear multiplier (independent from wearRate) |
| +0x114–+0x2a7 | — | (rest) | — | 404 bytes undocumented |

**Type ambiguity:** The doc does not specify types for these fields. They are
loaded by .tbc parser and used in physics sim — doubles are typical for this
game's physics parameters, but could be floats.

**Moddability:** All 5 fields in this struct are `.tbc` file parameters and
thus `configurable`.

**Note on +0x0f0/+0x0f8:** doc describes as "AI tire sensitivity, min/max" at
+0x0f0 with max at +0x0f8. These likely form a min/max range pair.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_R.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
