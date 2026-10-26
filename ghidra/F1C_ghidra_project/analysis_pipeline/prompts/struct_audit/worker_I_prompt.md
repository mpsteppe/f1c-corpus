# WORKER I — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker I of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_I.md

## YOUR STRUCT SECTIONS (14)

--- Section 118: SceneNode / DrawableList (param_1 — scene graph node) (30 offsets) ---
## SceneNode / DrawableList (param_1 — scene graph node)

Based on 5+ functions. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | ActiveFlag | FUN_00545d00, FUN_00512322 | -1 = inactive |
| +0x0c | int | param_1[3] | FUN_0040f130 | Data passed to dispatch |
| +0x1c | int | param_1[7] | FUN_0040f130 | State selector (0-5) |
| +0x04 | uint | CullFlags | FUN_0054a0a0 | 1=inside, 2=outside, 4=partial |
| +0x0c | int | LastAppended | FUN_00545d00 | Node list node |
| +0x10 | int | Count | FUN_00545d00 | List count |
| +0x14 | uint | Flags / CullFlags | FUN_0054d030, FUN_0054d910 | Bit 0x8000000=children dirty |
| +0x18 | float | NearPlaneDist | FUN_00549fb0 | Frustum near plane |
| +0x20 | int | TypeTag | FUN_00545d00 | 6=vehicle/player |
| +0x24–0x2c | float[3] | BoxVertices / SphereOffset | FUN_0054a0a0, FUN_00549fb0 | AABB / sphere |
| +0x3c | int | SomeFlag | FUN_00545d00 | 0=init |
| +0x40 | ptr | ParentPtr | FUN_0054b770 | Parent transform/container |
| +0x50 | int | TypeTag | FUN_00545d00 | 6=vehicle/player object type |
| +0x7c–0x84 | float[3] | FrustumPosition | FUN_00549fb0 | Camera/frustum world pos |
| +0x94 | ptr | AltTransformDest | FUN_0054b770 | Used with bit0 flag |
| +0xd4 | float[16] | LocalMatrix | FUN_0054b770 | 4×4 matrix |
| +0xfc | int | ElementCount | FUN_0054d910 | Elements to test |
| +0x100 | ptr | NodeChainHead / HeadPtr | FUN_005453a0, FUN_0054a2d0 | Linked list pointer |
| +0x104 | float[4]×6 | FrustumPlanes | FUN_00549fb0 | 6 planes (a,b,c,d) |
| +0x108 | ptr | DefaultNode | FUN_005453a0 | Fallback node |
| +0x114 | float[16] | WorldMatrix | FUN_0054b770 | Computed 4×4 |
| +0x118 | int | ChildCount / RecordCount | FUN_0054d030, FUN_0054e100, FUN_0054e120, FUN_00519986 | Number of children/records |
| +0x11c | ptr | ChildArrayPtr / RecordArrayPtr | FUN_0054d030, FUN_0054e100, FUN_0054e120 | Stride 0x40 |
| +0x120 | int | FrameCount / ObjectCount | FUN_00519986, FUN_0054e080 | |
| +0x124 | ptr | FrameArray / ObjectArrayPtr | FUN_00519986, FUN_0054e080 | Array of frame/object data |
| +0x194 | float | ScaleX | FUN_0054b770 | Row0 multiplier |
| +0x198 | float | ScaleY | FUN_0054b770 | Row1 multiplier |
| +0x19C | float | ScaleZ | FUN_0054b770 | Row2 multiplier |
| +0x1A0 | float[16] | OutputMatrix | FUN_0054b770 | Result 4×4 |
| +0x204 | ptr | AnimNodeListHead / ListHead | FUN_0054bf60, FUN_0054ac30, FUN_0054abe0 | Anim node/anchor |

---



--- Section 119: AudioRingBuffer (buffer manager) (4 offsets) ---
## AudioRingBuffer (buffer manager)

Based on FUN_004b3af0, FUN_004b3b30. Confidence: **low** (large stride).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c000–+0x6c00c | various | RingBuffer | FUN_004b3af0, FUN_004b3b30 | Base/end/current pointers |
| +0x6c004 | ptr | EndPtr | FUN_004b3af0 | |
| +0x6c008 | ptr | StartPtr / SourceValue | FUN_004b3af0, FUN_004b3b30 | |
| +0x6c00c | ptr | CurrentPtr / DestValue | FUN_004b3af0, FUN_004b3b30 | |

---



--- Section 120: 9. RaceModeBackup (inferred — FUN_00404890, FUN_004049d0) (5 offsets) ---
## 9. RaceModeBackup (inferred — FUN_00404890, FUN_004049d0)

Race mode save/restore struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | byte | InitFlag | FUN_00404890, FUN_004049d0 | WasInitialized |
| +0x15 | byte | InitFlag2 | FUN_00404890 |  |
| +0x20 | byte | StateCondition | FUN_00404890, FUN_004049d0 | 1=active |
| +0x50 | int | SavedSessionType | FUN_00404890, FUN_004049d0 | Backup DAT_007d2e44 |
| +0x54 | int | SavedRaceMode | FUN_00404890, FUN_004049d0 | Backup DAT_007d0410 |



--- Section 121: BVH/TreeNode (0x60 bytes) (11 offsets) ---
## BVH/TreeNode (0x60 bytes)

Spatial partitioning tree node for broadphase collision.

Based on 6+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | SplitX | FUN_004485d0 | X partition boundary |
| +0x04 | byte[8] | Pad1 | FUN_004485d0 | 8 bytes padding |
| +0x0c | float | SplitY | FUN_004485d0 | Y partition boundary |
| +0x10 | double | DoubleKey | FUN_004485d0, FUN_00448de0 | Unique key for exact match / accumulator |
| +0x04 | double | LocalValue | FUN_00448de0 | Node's local contribution |
| +0x48 | int | LinearIndex | FUN_004486e0 | Assigned DFS index |
| +0x4c | int* | Child[0] | FUN_004486e0, FUN_004485d0, FUN_00448da0, FUN_00448e50, FUN_004486a0, FUN_00448de0 | Child node pointer 0 |
| +0x50 | int* | Child[1] | Same set | Child node pointer 1 |
| +0x54 | int* | Child[2] | Same set | Child node pointer 2 |
| +0x58 | int* | Child[3] | Same set | Child node pointer 3 |
| +0x5c | int* | NextSibling | Same set | Overflow/sibling pointer |

---



--- Section 122: EnergyAccumulationStruct (7 offsets) ---
## EnergyAccumulationStruct

From FUN_004390a0. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x138 | double[4] | WheelEnergy | Per wheel, stride 0x58 |
| +0xdf0 | double[3] | FrontEnergyParams | Front energy parameters |
| +0xe30 | double[3] | RearEnergyParams | Rear energy parameters |
| +0x1270 | double[3] | ChassisEnergyParams | Chassis energy parameters |
| +0x12b0 | double[3] | SecondaryEnergyParams | Secondary component |
| +0x12f0 | double[3] | FrontCombinedParams | Combined front params |
| +0x1330 | double[3] | RearCombinedParams | Combined rear params |

---



--- Section 123: VehicleSceneNodeMap (inferred) (21 offsets) ---
## VehicleSceneNodeMap (inferred)

Based on 1 function observation (FUN_004dfce0). Confidence: high.

Maps mesh names to scene node indices. Int-indexed array (param_1[int_index]).

| Int Index | Real Offset | Type | Field Name | Observed in | Notes |
|-----------|-------------|------|------------|-------------|-------|
| 0x51 | +0x144 | int | LFTIRE_idx | FUN_004dfce0 | Left front tire mesh |
| 0x62 | +0x188 | int | LFSPINDLE_idx | FUN_004dfce0 | |
| 0x9b | +0x26c | int | RFTIRE_idx | FUN_004dfce0 | |
| 0xac | +0x2b0 | int | RFSPINDLE_idx | FUN_004dfce0 | |
| 0xe5 | +0x394 | int | LRTIRE_idx | FUN_004dfce0 | |
| 0xf6 | +0x3d8 | int | LRSPINDLE_idx | FUN_004dfce0 | |
| 0x12f | +0x4bc | int | RRTIRE_idx | FUN_004dfce0 | |
| 0x140 | +0x500 | int | RRSPINDLE_idx | FUN_004dfce0 | |
| 0x179 | +0x5e4 | int | FWING_idx | FUN_004dfce0 | Front wing |
| 0x18a | +0x628 | int | RWING_idx | FUN_004dfce0 | Rear wing |
| 0x19b–0x247 | +0x66c–+0x91c | int[?] | DEBRIS0–7_idx | FUN_004dfce0 | 8 debris meshes, stride 0x11 |
| 0x223 | +0x88c | int | COCKPIT_idx | FUN_004dfce0 | |
| 0x224 | +0x890 | int | SUSPENSION_idx | FUN_004dfce0 | |
| 0x225 | +0x894 | int | HELMET_idx | FUN_004dfce0 | |
| 0x226 | +0x898 | int | (unnamed) | FUN_004dfce0 | DAT_005c674c related |
| 0x227 | +0x89c | int | (unnamed) | FUN_004dfce0 | DAT_005d4d64 related |
| 0x228 | +0x8a0 | int | WHEEL_idx | FUN_004dfce0 | |
| 0x229 | +0x8a4 | int | RAINLIGHT_idx | FUN_004dfce0 | |
| 0x22a | +0x8a8 | int | BRAKELIGHT_idx | FUN_004dfce0 | |
| 0x22b | +0x8ac | int | HEADLIGHT_idx | FUN_004dfce0 | |
| 0x22c | +0x8b0 | int | BACKFIRE_idx | FUN_004dfce0 | |

---



--- Section 124: Vehicle Setup Struct (8 offsets) ---
## Vehicle Setup Struct

Based on 1 function observation (FUN_004f6300). Confidence: low — single source, offsets sparse within large struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xbc0 | void* | Tire brand data ptr | FUN_004f6300 | |
| +0x13c0 | int | SetupType | FUN_004f6300 | 0=Custom, 1=Gearing, 2=Balance, 3=Downforce |
| +0x1988 | bool | Auto-setup enabled | FUN_004f6300 | from file +0x548 |
| +0x1989 | bool | Auto-setup sub-flag | FUN_004f6300 | from file +0x56c |
| +0x1990 | bool | Auto-setup flag | FUN_004f6300 | default 1 |
| +0x1994 | float | FuelConsumptionRecip | FUN_004f6300 | 1 / computed fuel |
| +0x19a4 | bool | Setup bool flag | FUN_004f6300 | |
| +0x19a5 | bool | Setup bool flag 2 | FUN_004f6300 | |

---



--- Section 125: File Close Wrapper Struct (FUN_00599495) (1 offsets) ---
## File Close Wrapper Struct (FUN_00599495)

Based on 1 function observation (FUN_00599495). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x50 | int | FileHandle | FUN_00599495 | |

---



--- Section 126: Linked List Node (inferred) (3 offsets) ---
## Linked List Node (inferred)

Used by FUN_00486540. Generic node for render/display lists.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | data | FUN_00486540 | Node data |
| +0x04 | ptr | next | FUN_00486540 | Next node pointer |
| +0x08 | ptr | prev | FUN_00486540 | Previous node pointer |



--- Section 127: CollisionResponseState (inferred — param_1 in FUN_004a6b80, FUN_00453100, FUN_00462ce0) (5 offsets) ---
## CollisionResponseState (inferred — param_1 in FUN_004a6b80, FUN_00453100, FUN_00462ce0)

Based on 3 function observations. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x10 | int | CollisionThreshold | FUN_00462ce0 | Threshold value from _DAT_0059f0a0 |
| +0x29 | byte | ActiveFlag | FUN_00462ce0 | Collision response active |
| +0x374 | int | ResponseFlag | FUN_00463cd0 | Collision response flag |
| +0x388 | float | SpeedParam | FUN_004636a0 | Vehicle speed/parameter |
| +0x3FC4 | int | CollisionType | FUN_00462ce0, FUN_00462940, FUN_0045f390 | Collision type code |

---



--- Section 128: ConstraintForceState (inferred — param_1 in FUN_00454250) (5 offsets) ---
## ConstraintForceState (inferred — param_1 in FUN_00454250)

Based on FUN_00454250. Confidence: **low**.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x040 | float | Stiffness | Constraint stiffness coefficient |
| +0x060 | float | RestValue | Rest/equilibrium value |
| +0x398 | float | CurrentValue | Current constraint value |
| +0xD88 | float[] | ConstraintSetPrimary | Primary constraint array |
| +0x1184 | float[] | ConstraintSetSecondary | Secondary constraint array |

---



--- Section 129: 7. Camera Struct (200 bytes, stride 200) (26 offsets) ---
## 7. Camera Struct (200 bytes, stride 200)

Based on observations from FUN_00408e20, FUN_00408870, FUN_0040db00. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | char*? | NodeName | FUN_004fc2f0 | Scene node name |
| +0x18 | int*? | Interface1 | FUN_0040c890 | First vtable interface pointer |
| +0x1c | int*? | Interface2 | FUN_0040c890 | Second vtable interface pointer |
| +0x20 | int*? | Interface3 | FUN_0040c890 | Third vtable interface pointer |
| +0x30 | float | Param1 | FUN_00408e20, FUN_00408870 | FOV/settings (60.0 for fixed cams) |
| +0x34 | float | Param2 | FUN_00408e20, FUN_00408870 | FOV/settings (45.0 for fixed cams) |
| +0x38 | float | NearClip | FUN_00408e20, FUN_00408870 | Near clip plane (60.0 for fixed cams) |
| +0x3c | float | FarClip | FUN_00408e20, FUN_00408870 | Far clip plane (45.0 for fixed cams) |
| +0x40 | int | NameID | FUN_00408e20, FUN_00408870 | Camera name ID / FOV-Zoom param |
| +0x44 | int | SlotCount | FUN_00408e20 | Camera slot count / Range (500.0) |
| +0x48 | float | ScaleX | FUN_00408870 | Scale X (1.0) |
| +0x4c | float | ScaleY | FUN_00408870 | Scale Y (1.0) |
| +0x50 | float | ScaleZ | FUN_00408870 | Scale Z (1.0) |
| +0x54 | float | AspectClipX | FUN_00408870 | Aspect/clip X (0.5) |
| +0x58 | float | AspectClipY | FUN_00408870 | Aspect/clip Y (0.5) |
| +0x60 | int | ActiveFlag | FUN_00408870 | Active flag (1) |
| +0x64–0x78 | byte[0x14]? | Padding | FUN_00408870 | Zero padding |
| +0x80 | float | BaseOffsetX | FUN_00408870 | Base offset X |
| +0x84 | float | BaseOffsetY | FUN_00408870 | Base offset Y |
| +0x88–0x90 | float[3]? | PositionRot | FUN_00408870 | Position/rotation vector |
| +0x8c | Camera* | OriginalTarget | FUN_0040db00 | Original camera target |
| +0x90 | Camera* | LastTarget | FUN_0040db00 | Last camera target |
| +0x94–0xa8 | float[4]? | LookAtQuat | FUN_00408870 | Look-at/direction quaternion |
| +0xa0 | float | ExtraOffsetX | FUN_00408870 | Extra offset X |
| +0xa4 | float | ExtraOffsetY | FUN_00408870 | Extra offset Y |
| +0xa8 | float | ExtraOffsetZ | FUN_00408870 | Extra offset Z |

**CONFLICT:** +0x40 documented as "Camera Name ID" in FUN_00408e20 but as "FOV/Zoom parameter" in FUN_00408870. These may be different structs (camera view definition vs camera instance), or the field is multi-purpose.
**CONFLICT:** +0x44 documented as "Camera slot count" in FUN_00408e20 but as "Range (500.0)" in FUN_00408870. Same struct reinterpretation issue.
**NOTE:** +0x8c and +0x90 overlap with the PositionRot/LookAtQuat range from FUN_00408870. The camera manager struct (+0x08e20) has +0x8c as OriginalTarget, while the camera camera definition struct (+0x08870) has +0x88–0x90 as position/rotation. These are likely different structs at different scopes.

---



--- Section 130: AudioResourceStruct (inferred) (4 offsets) ---
## AudioResourceStruct (inferred)

Based on 1 function (FUN_00552760). Confidence: medium.

Resource management struct with flag-gated sub-resource cleanup.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | uint32 | SubResourcePtr | FUN_00552760 | Freed and zeroed; gated by +0x24 bit 0x20000 |
| +0x24 | uint32 | FlagBitmask | FUN_00552760 | Bit 0x20000 gates cleanup |
| +0x64 | uint32 | ResourceHandle | FUN_00552760 | Primary resource at offset 100, released via FUN_0053cb90 |
| +0x868 | uint32 | SecondaryResource | FUN_00552760 | Conditionally freed |

---



--- Section 131: Summary of New Offset Regions Not in docs/13-struct-offsets.md (0 offsets) ---
## Summary of New Offset Regions Not in docs/13-struct-offsets.md

The following regions have offset observations from 02-ai-system.md that are **not yet present** in `docs/13-struct-offsets.md`:

1. **AI Ability region** (+0x112e–+0x1144): 15 fields (TireStartTempMult, QualifyingAbility stored, RaceAbility scaled, RainSensitivity, Passing, PushLapProbRef, SpeedVarWindow, BaseSpeedTarget, TrackAggression scaled, CorneringAdd, CorneringMult, LapTypeFlag, PushLapCounter, AIBehaviorState, LiveLapRatio)

2. **Steering output region** (+0x1102–+0x1110): 5 fields (filtered steering, steering output, left/right limits, raw steering, speed ref)

3. **Command queue** (+0x112a–+0x112c): 3 fields (queue array, capacity, count)

4. **Brake/steering control** (+0x1152–+0x115d): 5 fields (steering overwrite, push active, brake acc, brake timers)

5. **AI adjustment region** (+0x1135–+0x1141): 6 additional fields from .rcd processing

6. **Path tracking** (+0x32bc–+0x3a9c): 10 fields (path valid, orientation matrix, offset x/y/z, target pos x/y/z, lateral forces, tracking flag)

7. **AI session fields** in the +0x834–+0xcb2 range: 3 fields (slot active flags, phase slot flags, AI active flag)

8. **Pit/retirement related** (+0x40d0–+0x45e0): 8 fields (retirement links, pit exit timestamp, pit crew timer, proximity flag, brake active, pit cleared, stint counter, AI follow target, ring buffer, AIBehaviorState)

9. **Composite fields**: +0x0d5, +0x0d98, +0x0da0, +0xda4, +0x1170, +0x1178, +0x117c, +0x1b10, +0x1b34

All of these should be added to `docs/13-struct-offsets.md` for completeness.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_I.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
