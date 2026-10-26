# WORKER A — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker A of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_A.md

## YOUR STRUCT SECTIONS (15)

--- Section 1: New Struct Offset Summary (Session 2) (17 offsets) ---
## New Struct Offset Summary (Session 2)
### New Struct Offset Summary (Session 2)

**Physics vehicle instance:**

| Offset | Type | Field |
|--------|------|-------|
| +0x1db4 | double | Effective engine lifetime |
| +0x1dbc | double | LifetimeEngineRPM min |
| +0x1dc4 | double | 1 / LifetimeEngineRPM max |
| +0x1dcc | double | LifetimeOilTemp min |
| +0x1dd4 | double | 1 / LifetimeOilTemp max |
| +0x1140–+0x115c | double×8 | Front tire telemetry |
| +0x1160 | byte[16] | Front compound flags |
| +0x1170 | int | Current front compound index |
| +0x1174–+0x117c | int×3 | Compound selections: stops 2–4 |
| +0x1180 | uint | PitStopFlag bitmask |
| +0x153c–+0x1558 | double×8 | Rear tire telemetry |
| +0x155c | byte[16] | Rear compound flags |

**Player options struct (FUN_004aa270):**

| Offset | Stride | Count | Content |
|--------|--------|-------|---------|
| +0x5c8 | 0x24 | 7 | FailureRate[0..6]: {current=2, min=0, max=3} |

**Wheel corner struct (FUN_004f2c60, per wheel):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0xb8 | BrakeOptimumTemp | +273.15 K applied at load |
| +0xf0 | BrakeWearRate | |
| +0xf8 | BrakeFailure min | |
| +0x100 | BrakeFailure max | |

---



---



--- Section 2: PenaltySlipAngleStruct (5 offsets) ---
## PenaltySlipAngleStruct

Based on FUN_0042e400. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1cb8 | byte | Flag | FUN_0042e400 | Enabled flag |
| +0x1cbc | float | SpeedThreshold | FUN_0042e400 | 295.0, penalty trigger |
| +0x1cd4 | byte[4] | CornerFlags | FUN_0042e400 | Per corner |
| +0x1cd8 | float[4] | CornerThresholds | FUN_0042e400 | Per corner |
| +0x1cec | float[4][3] | CornerTimers | FUN_0042e400 | 3 floats per corner, ~359.0 |

---



--- Section 3: 1. HighResTimer (inferred) (11 offsets) ---
## 1. HighResTimer (inferred)

Performance counter timer. FUN_005564b0, FUN_00556510, FUN_00568c60, FUN_00568cb0.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int32 | Enabled/ActiveFlag | FUN_005564b0, FUN_00568c60, FUN_00568cb0 | 0=disabled |
| +0x08 | double | ScaleFactor | FUN_00556510 | Multiplier for elapsed high part |
| +0x10 | int32 | OtherAccum0 | FUN_00568c60 | Zeroed on reset |
| +0x14 | int32 | OtherAccum1 | FUN_00568c60 | Zeroed on reset |
| +0x18 | uint32 | CurrentLow | FUN_00568c60, FUN_00556510 | QPC low part |
| +0x1c | uint32 | CurrentHigh | FUN_00568c60, FUN_00556510 | QPC high part |
| +0x20 | uint32 | LastLow | FUN_00568c60, FUN_00556510 | Previous sample low |
| +0x24 | uint32 | LastHigh | FUN_00568c60, FUN_00556510 | Previous sample high |
| +0x28 | uint32 | AccumLow | FUN_00568c60 | Accumulated time low |
| +0x2c | uint32 | AccumHigh | FUN_00568c60 | Accumulated time high |
| +0x48 | int/byte | TimerModeFlags | FUN_005564b0, FUN_00568c60, FUN_00568cb0 | Bit 0=QPC mode, bit 1=alternate |



--- Section 4: Source: docs/18-physics-dynamics.md (0 offsets) ---
## Source: docs/18-physics-dynamics.md

Based on 270 function entries, 435+ offset observations.

---



--- Section 5: DeltaUpdateTrackerStruct (3 offsets) ---
## DeltaUpdateTrackerStruct

From FUN_0043bb00. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xd4c | double | CumulativeDelta | Accumulated delta |
| +0x1428 | double | CurrentValue | Current state value |
| +0x1430 | double | DeltaGain | Gain factor for delta tracking |

---



--- Section 6: PerWheelPhysics (inferred) (12 offsets) ---
## PerWheelPhysics (inferred)

Based on 2 function observations (FUN_0043da10, FUN_0043f7f0). Confidence: high.

Per-wheel physics sub-struct accessed as wheel_index × 0x464 from base pointer.
Tire compound data is at wheel_base + 0x28c within this struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x28c | struct | TireCompoundData | FUN_0043da10 | Tire physics params offset within wheel |
| +0x348 | double | Position | FUN_0043f7f0 | Wheel position |
| +0x360 | float | Force | FUN_0043f7f0 | |
| +0x368 | int | ConstraintState | FUN_0043f7f0 | |
| +0x7ac | float | Force2 | FUN_0043f7f0 | |
| +0x7c4 | float | Inertia | FUN_0043f7f0 | |
| +0xc10 | float | Velocity | FUN_0043f7f0 | |
| +0xc28 | float | Mass | FUN_0043f7f0 | |
| +0xc30 | float | Inertia2 | FUN_0043f7f0 | |
| +0x1074 | float | Bias | FUN_0043f7f0 | |
| +0x108c | float | Bias2 | FUN_0043f7f0 | |
| +0x464 | - | WheelStructStride | - | Full wheel struct size |

---



--- Section 7: PLAYERTRACKSTAT Node Struct (int-indexed) (6 offsets) ---
## PLAYERTRACKSTAT Node Struct (int-indexed)

Based on 1 function observation (FUN_004c2420). Confidence: low — single source. Int-indexed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | TrackName string | FUN_004c2420 | [0] |
| +0x01 | char* | TrackName string 2 | FUN_004c2420 | [1] |
| +0x02 | char* | TrackFile string 1 | FUN_004c2420 | [2] |
| +0x03 | char* | TrackFile string 2 | FUN_004c2420 | [3] |
| +0x04 | int | TotalNumLaps | FUN_004c2420 | [4] |
| +0x05 | float | BestLapTime | FUN_004c2420 | [5] |

---



--- Section 8: String Property Struct (3 offsets) ---
## String Property Struct

Based on 1 function observation (FUN_00467430). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x2f0 | char* | stored string | FUN_00467430 | param_1[0xbc] |
| +0x2f4 | char* | cursor pointer | FUN_00467430 | param_1[0xbd] |
| +0x2f8 | int | buffer size | FUN_00467430 | param_1[0xbe] |

---



--- Section 9: Mesh Bounding Box Struct (inferred) (6 offsets) ---
## Mesh Bounding Box Struct (inferred)

Used by FUN_0054d9f0, FUN_0054b6190? Stores mesh bounds, flags,
and subset information.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | int | flags | FUN_0054d9f0 | 0x800000 = LOD mode, 0x80010000 = interpolation |
| +0x18 | float | boundingSphereRadius | FUN_0054d9f0 | sqrt of squared extent |
| +0x1c..0x78 | float[24] | aabbCorners | FUN_0054d9f0 | 8×3 floats (OBB corners) |
| +0xdc | float | centerX | FUN_0054d9f0 | (maxX+minX)×0.5 |
| +0x118 | int | subsetCount | FUN_0054d9f0 | Number of vertex subsets |
| +0x11c | ptr | subsetArray | FUN_0054d9f0 | Vertex array descriptors |



--- Section 10: CollisionBody (inferred — rigid body physics state) (63 offsets) ---
## CollisionBody (inferred — rigid body physics state)

Based on 6 function observations (FUN_00436870, FUN_004542d0, FUN_00457a00, FUN_004584c0, FUN_004987b0, FUN_0044fee0). Confidence: **high**.

This is the primary rigid body collision structure — contains contact geometry, friction model, impulse accumulation, and body state flags. Large struct likely spanning 0x0000–0x1184+.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x040 | float[3] | AxisCoeff | FUN_004542d0 | Per-axis scaling coefficient |
| +0x060 | float[3] | AxisMin | FUN_004542d0 | AABB min bounds |
| +0x068-0x070 | int32[3] | BodyStateFlags | FUN_004987b0 | Collision body type flags |
| +0x084-0x08C | int32[3] | ContactStateFlags | FUN_004987b0 | Per-contact state flags |
| +0x090 | float | ContactPosX | FUN_00457a00 | Contact point world X |
| +0x094 | float | ContactPosY | FUN_00457a00, FUN_004039c0, FUN_004038e0 | Contact/position Y |
| +0x098 | float | ContactPosZ | FUN_00457a00, FUN_004039c0, FUN_004038e0 | Contact/position Z |
| +0x0A4 | float | RestitutionFactor | FUN_004584c0, FUN_00403aa0 | Restitution coefficient / normal X |
| +0x0AC | float | NormalZ | FUN_00403aa0, FUN_004038e0, FUN_00456f70 | Collision normal Z / body collision base |
| +0x0D8 | double | PositionX | FUN_004599c0 | Body position X (double) |
| +0x0E0 | double | PositionY | FUN_004599c0 | Body position Y |
| +0x0E4 | float | FrictionAccum1 | FUN_00436870 | Accumulated friction displacement |
| +0x0E8 | double | PositionZ | FUN_004599c0 | Body position Z |
| +0x0EC | float | FrictionAccum2 | FUN_00436870 | Accumulated friction displacement |
| +0x0F4 | float | FrictionAccum3 | FUN_00436870 | Accumulated friction displacement |
| +0x0FC | float | ContactPointWorldX | FUN_00436870 | X of contact point |
| +0x100 | float | ContactPointWorldY | FUN_00436870 | Y of contact point |
| +0x100 | int | FlagA | FUN_004987b0 | First-level branch flag (int32) — note: overlaps ContactY, may be union |
| +0x10C | int* | NextPrimary | FUN_00403aa0, FUN_004039c0 | Primary child / linked list next |
| +0x110 | int* | NextSecondary | FUN_00403aa0, FUN_004039c0 | Sibling/alternative / return value |
| +0x12C | int | TypeFilterField | FUN_004038e0 | Entity/type filter |
| +0x134 | float | FrictionMagnitude | FUN_00436870 | |
| +0x144 | float | StiffnessTerm | FUN_00436870 | Spring-like term |
| +0x15C | int* | TriangleDataPtr | FUN_00436870 | Pointer to triangle vertices |
| +0x180 | uint32 | MassLow | FUN_00459950 | Low part of mass double |
| +0x184 | uint32 | MassHigh | FUN_00459950 | High part of mass double |
| +0x188 | double | InvMass | FUN_00459950 | 1.0/mass |
| +0x200 | float | TimeAccum | FUN_004987b0 | Accumulated timestep |
| +0x20C | float | Damping | FUN_00436870 | Velocity damping |
| +0x214 | float | Restitution | FUN_00436870 | Bounce coefficient |
| +0x21C | float | HalfExtent | FUN_00436870 | Bounding radius |
| +0x224 | float[3] | RotationMatrix | FUN_00436870 | Body orientation row |
| +0x264 | int | BestTriIndex | FUN_00436870 | Which triangle face hit |
| +0x278 | int | CullFlag | FUN_0044efe0 | Collision culling enable flag |
| +0x27C–0x290 | float | FrictionCurveParams | FUN_00436870 | Falloff coefficients |
| +0x27C | byte[] | PropertyBlock | FUN_0044f050 | Per-node byte properties |
| +0x298–0x2D0 | float | FrictionFalloff | FUN_00436870 | cos/sin friction curve |
| +0x2E4 | float | FrictionScale | FUN_00436870 | Overall friction scalar |
| +0x2EC | float | RollingResistance | FUN_00436870 | Rolling resistance factor |
| +0x2F4 | int | StoredParam | FUN_0044fbb0, FUN_0044fbe0 | Reference/state flag |
| +0x304 | float | StiffnessAngle | FUN_00436870 | Angle for stiffness response |
| +0x314 | float | RandomSeed | FUN_00436870 | Stochastic element |
| +0x31C | float | ContactForce | FUN_00436870 | Normal impulse magnitude |
| +0x31C | int | ContactCount | FUN_0045b840 | Number of active contacts |
| +0x320 | float | ContactEn
[...1655 chars truncated]

--- Section 11: CollisionShapeClassifier (inferred — param_1 in FUN_004139c0 / FUN_00412c30) (2 offsets) ---
## CollisionShapeClassifier (inferred — param_1 in FUN_004139c0 / FUN_00412c30)

Based on 2 function observations. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x08 | int | ShapeClass | FUN_004139c0, FUN_00412c30 | Size class (0x20-0x2f) or bone index (0x99-0xBD) |
| +0x0C | int | SecondaryClass | FUN_004139c0, FUN_00412c30 | Secondary class / bone-related value |

**Conflict:** +0x08 used as both SizeClass and BoneIndex — these are different structs; same offset pattern reused.

---



--- Section 12: Consolidated Notes (0 offsets) ---
## Consolidated Notes

### Conflicts

1. **+0x1328** — FUN_004f3c80 stores `LifetimeOilTemp_max` as raw double (no offset). FUN_0043c250 stores `1/LifetimeOilTemp_max` at +0x1dd4 (runtime reciprocal copy). No actual conflict — the parser and runtime use different offsets for different representations.

2. **+0x1344** — FUN_004f3c80 treats this as part of the EngineEmission double array (double at +0x1340, +0x1348, +0x1350). FUN_004e6d93 reads a 4-byte int at +0x1344 (`LifetimeRandomCoeff`). **Resolution:** The struct layout has 3 doubles at +0x1340, +0x1348, +0x1350 occupying +0x1340–+0x1357 (24 bytes). The 4-byte int at +0x1344 falls inside the first double's storage — this suggests either: (a) the double at +0x1340 is actually a union/packing with the int, or (b) the random coefficient is a separate 4-byte field at +0x1344 that overlays the double's lower/higher 4 bytes. Most likely: the double at +0x1340 is `EngineEmission[0]` (8 bytes +0x1340–+0x1347), and +0x1344 is a separate int field that shares space with the upper 4 bytes of that double — a classic MSVC union or bitfield overlay.

### Overlaps with docs/13-struct-offsets.md

Existing docs/13 entries are confirmed and expanded:
- +0x1db4, +0x1dbc, +0x1dc4, +0x1dcc, +0x1dd4: confirmed from 2 functions
- +0x1140–+0x115c, +0x1160, +0x1170, +0x1174–+0x117c, +0x1180: confirmed from 2 functions
- +0x153c–+0x1558, +0x155c: confirmed from 2 functions

### New offsets not in docs/13

The following offsets from FUN_004f3c80 (engine section parser) are **new** and should be added to docs/13:
- +0x674 (FuelConsumption) through +0x6c8 (RPMTorque array)
- +0x12c8 (OptimumOilTemp) through +0x136c (StarterTiming)
- +0x1340–+0x1350 (EngineEmission)
- +0x19c (RPM_current), +0x1c5c (CrankDelta), +0x1d4 (GaugePtr)
- +0x1d4c (OilTemp), +0x1d8c (HeadTemp), +0x1dac (Vibration)
- +0x1de4, +0x1dec, +0x1df4 (WearAxes), +0x1f00 (VehicleSelfPtr)
- +0x3978 (FuelLevel), +0x4068 (ReasonCode)

The entire DamageModelSubStruct (+0x00–+0x250, 37+ offsets) is new.
The entire RPMPerGearSubStruct (stride 0x0c × 5 gears) is new.

---



--- Section 13: AudioHandleStruct / MilesSampleStruct (inferred) (10 offsets) ---
## AudioHandleStruct / MilesSampleStruct (inferred)

Based on 4+ function observations. Confidence: high.

Used by Miles Sound System wrapper functions. Contains audio handle, filter state, and control fields.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | void* | SubResource | FUN_00552760, FUN_00406750 | Sub-resource pointer, freed conditionally |
| +0x10 | void* | MilesSampleHandle | FUN_00405b50, FUN_004059f0, FUN_004060c0 | (dereferenced from +0x58) Miles sample handle |
| +0x14 | int | PlayState | FUN_00405b50 | Play state/flag |
| +0x24 | uint32 | FlagBitmask | FUN_00552760 | Bit 0x20000 gates sub-resource cleanup |
| +0x58 | void* | AudioHandle | FUN_00405b50, FUN_004060c0, FUN_004059f0 | Audio handle/sample struct pointer |
| +0x5c | int | StreamHandle | FUN_00406750 | -1 = closed |
| +0x60 | int | FilterType | FUN_004060c0 | -1 = no filter |
| +0x64 | int | FilterParam | FUN_004060c0 | Parameter for filter |
| +0x68 | byte[] | FilterState | FUN_004060c0 | Filter state struct |
| +0x868 | void* | SecondaryResource | FUN_00552760 | Secondary sub-resource, conditionally freed |

**Notes:**
- +0x24 bit 0x20000 (131072) is a cleanup gate flag
- +0x58 is a common audio handle pattern across multiple MSS wrapper functions
- +0x64 (100) used as resource handle offset in FUN_00552760

---



--- Section 14: Struct 2: AI Database Struct (aiDB, param_1 in FUN_004040a0 / FUN_00402690) (32 offsets) ---
## Struct 2: AI Database Struct (aiDB, param_1 in FUN_004040a0 / FUN_00402690)

Based on 2 function observations. These two functions index the struct differently — FUN_004040a0 uses `param_1[idx]` (4-byte stride), FUN_00402690 uses byte offsets. Both are consistent when converting: byte_offset = idx × 4.

Offset range: +0x00–+0x168 (360 bytes). Confidence: **high**.

| Byte Offset | Index (×4) | Type | Field Name | Observed in | Notes |
|-------------|-----------|------|------------|-------------|-------|
| +0x00 | [0x00] | float | GrooveWidth | FUN_004040a0, FUN_00402690 | Default 4.5f |
| +0x04 | [0x01] | float | GrooveWidthWet | FUN_004040a0, FUN_00402690 | Default 4.3125f |
| +0x11c | [0x47] | float | AiSpeedMultMin | FUN_004040a0, FUN_00402690 | Default 0.5f. Global speed mult lower bound |
| +0x118 | [0x46] | float | AiGlobalSpeedMult | FUN_004040a0 | Computed from slider interpolation |
| +0x120 | [0x48] | float | AiSpeedMultMid | FUN_004040a0, FUN_00402690 | Default 1.0f. Mid bound |
| +0x124 | [0x49] | float | AiSpeedMultMax | FUN_004040a0, FUN_00402690 | Default 1.3f. Upper bound |
| +0x13c | — | float | LapLength | FUN_00402690 | Track lap length |
| +0x140 | — | float | Sector1Length | FUN_00402690 | Sector 1 length |
| +0x144 | — | float | Sector2Length | FUN_00402690 | Sector 2 length |
| +0x14c | — | float | FuelUse | FUN_00402690 | Fuel consumption rate |
| +0x150 | — | struct[] | GridArray | FUN_00402690 | Stride 0x1c, max 104 entries |
| +0x154 | — | struct[] | PitArray | FUN_00402690 | Stride 0x1c, max 52 entries |
| +0x158 | — | struct[] | GarageArray | FUN_00402690 | Stride 0x1c |
| +0x15c | [0x57] | int | PitlaneCount | FUN_004040a0, FUN_00402690 | Default 3 (per FUN_004040a0 [0x5a] — **see conflict below**) |
| +0x160 | [0x58] | int | StartingGridSlots | FUN_004040a0, FUN_00402690 | Default 104. Minimum 104 |
| +0x164 | [0x59] | int | PitSpots | FUN_004040a0, FUN_00402690 | Default 52. Minimum 52 |
| +0x168 | [0x5a] | int | GarageSpots | FUN_004040a0, FUN_00402690 | Default 3. Minimum 3 |
| +0x130 | — | int | WaypointCount | FUN_00402690 | Waypoint array count |
| +0x134 | — | ptr | WaypointArray | FUN_00402690 | Array of waypoints, stride 0x13c |
| +0x12c | — | bool | LeftHandedPits | FUN_00402690 | Boolean flag |

### FUN_004040a0 aiDB[] mappings (4-byte stride indexing)

| Index | Byte Offset | Field Name | Default | Notes |
|-------|-------------|------------|---------|-------|
| [0x00] | +0x00 | GrooveWidth | 4.5 | Confirmed |
| [0x01] | +0x04 | GrooveWidthWet | 4.3125 | Confirmed |
| [0x46] | +0x118 | AiGlobalSpeedMult | computed | Slider interpolation result |
| [0x47] | +0x11c | WorstAdjust / AiSpeedMultMin | 0.5 | Confirmed by FUN_00402690 |
| [0x48] | +0x120 | MidAdjust / AiSpeedMultMid | 1.0 | Confirmed by FUN_00402690 |
| [0x49] | +0x124 | BestAdjust / AiSpeedMultMax | 1.3 | Confirmed by FUN_00402690 |
| [0x4f–0x51] | +0x13c–+0x144 | (default triple) | _DAT_0059e478 | Unknown purpose |
| [0x57] | +0x15c | PitlaneCount | 1 | FUN_004040a0 sets [0x57]=1 |
| [0x58] | +0x160 | StartingGridSlots | 104 | FUN_004040a0 says 104 |
| [0x59] | +0x164 | PitSpots | 52 | FUN_004040a0 says 52 |
| [0x5a] | +0x168 | GarageSpots | 3 | FUN_004040a0 says 3 |

### CONFLICT: aiDB[0x57] vs +0x15c

| Source | Offset | Value | Interpretation |
|--------|--------|-------|---------------|
| FUN_004040a0 | aiDB[0x57] = +0x15c | 1 | Unknown flag / PitlaneCount? |
| FUN_00402690 | +0x15c | pitlanes count | Track-dependent (reads from .gdb) |

**Assessment:** The default value 1 at aiDB[0x57] likely represents a flag (not pitlane count) that gets overwritten when the .gdb file is loaded. At init, aiDB[0x57]=1 is a placeholder. When FUN_00402690 loads the track database, +0x15c is set to the actual pitlane count. No real conflict — same field dual-purposed as flag-at-init and count-at-load.

---



--- Section 15: New Offsets vs Existing Reference (0 offsets) ---
## New Offsets vs Existing Reference

Offsets in this analysis **not present** in `13-struct-offsets.md`:

- VehiclePhysicsInstance: +0x0060, +0x0064, +0x0068, +0x1f00
- TireBrandManager: +0x00, +0x04
- TireBrandEntry: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14
- TireCompoundEntry: +0x0e0, +0x0f0, +0x0f8, +0x100, +0x110
- SlipCurveEntry: +0x00, +0x04, +0x08, +0x0c, +0x10, +0x14

Offsets already in `13-struct-offsets.md` (confirmed):
- VehiclePhysicsInstance: +0x1140–+0x115c, +0x1160, +0x1170, +0x1174–+0x117c, +0x1180, +0x153c–+0x1558, +0x155c

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_A.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
