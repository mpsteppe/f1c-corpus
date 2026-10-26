# WORKER O — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker O of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_O.md

## YOUR STRUCT SECTIONS (14)

--- Section 202: PitStop / PitCrewStruct (param_1 — pit state) (7 offsets) ---
## PitStop / PitCrewStruct (param_1 — pit state)

Based on FUN_004a5600, FUN_004b6940, FUN_004b5da0, FUN_004a47e0. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x8 | ptr | CurrentPitState | FUN_004a5600 | byte* animation state |
| +0x184 | int | PitMode | FUN_004a5600 | 3=repair |
| +0x190 | byte | RepairDoneFlag | FUN_004a5600 | Blocks transitions |
| +0x9b0 | int | PitActionBase / DataArrayBase | FUN_004b6940, FUN_004b6130, FUN_004b68c0, FUN_004b6920 | Base pointer |
| +0x9b4 | int | PitActionIndex / Capacity | FUN_004b6940, FUN_004b5da0, FUN_004b68c0, FUN_004b69a0 | Index / modulo limit |
| +0x9b8 | int | PitActionCounter / Head | FUN_004b6940, FUN_004b5da0, FUN_004b68c0, FUN_004b69a0, FUN_004b69f0 | Counter / CoordX |
| +0x9bc | int | Tail / CoordY | FUN_004b68c0, FUN_004b69f0 | |

---



--- Section 203: Summary (0 offsets) ---
## Summary

| Category | Distinct Struct Patterns | Functions | Cross-Function? |
|----------|------------------------|-----------|-----------------|
| Buffer/Stream Descriptor | 5 | 6 | Yes (buffer_descriptor) |
| Timer Struct | 2 | 2 | Yes |
| Dynamic Array | 2 | 2 | Yes |
| Linked List Node | 6 | 5 | Yes (node_entry, linked_list) |
| Array Container | 2 | 2 | Yes |
| Vehicle Struct (high offsets) | 5 | 5 | No |
| FILE* struct | 1 | 1 | No |
| Single-function utility structs | ~160 | ~160 | No |
| **Total** | **~180 struct patterns** | **172** | |

---



--- Section 204: 15. ArrayContainer (various) (6 offsets) ---
## 15. ArrayContainer (various)

Multiple stride-based array container variants.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x04/+0x0c | int | Count | Multiple | Element count |
| +0x08/+0x10/+0x34 | ptr | ArrayBase | Multiple | Array pointer |
| +0x18/+0x2c | int | SlotCount | FUN_00558cf0, FUN_0056eb30 |  |
| +0x1c | ptr | ElementArray | FUN_0056eb30 | Stride 0x48 |
| +0xa4 | int | TableCount | FUN_0058a638 |  |
| +0xa8 | ptr | TableBase | FUN_0058a638 | Stride 0x94 |



--- Section 205: VehicleControllerStruct (AI/player controller state) (23 offsets) ---
## VehicleControllerStruct (AI/player controller state)

From FUN_00425670, FUN_004e3090. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x70 | int | ActiveFlag | FUN_004e3090 | Must be non-zero |
| +0x74 | float | PosX | FUN_004e3090 | World position X |
| +0x78 | float | PosZ | FUN_004e3090 | World position Z |
| +0xb0 | byte | Enabled | FUN_004e3090 | Enable byte |
| +0xd4 | float | DirX | FUN_004e3090 | Normalised direction X |
| +0xe0 | float | DirZ | FUN_004e3090 | Normalised direction Z |
| +0x11c | int | PointCount | FUN_004e3090 | Number of interpolation points |
| +0x120 | int* | PointArray | FUN_004e3090 | Point array stride 0x20 |
| +0x124 | float | PosY | FUN_004e3090 | World position Y |
| +0x34e0 | float | posX | FUN_00425670 | Current world X |
| +0x34e4 | float | posY | FUN_00425670 | Current world Y |
| +0x34e8 | float | posZ | FUN_00425670 | Current world Z |
| +0x34f0 | float | heading | FUN_00425670 | Current heading angle |
| +0x34f8 | float | velX | FUN_00425670 | Velocity X |
| +0x3500 | float | velZ | FUN_00425670 | Velocity Z |
| +0x39fc | int | aiSubState | FUN_00425670 | AI sub-state counter |
| +0x4354 | int* | targetPtr | FUN_00425670 | Target waypoint pointer |
| +0x4440 | float | speedThreshold2 | FUN_00425670 | Secondary speed check |
| +0x446c | int | headingTimer | FUN_00425670 | Heading deviation timer |
| +0x4470 | float[3] | lastTargetPos | FUN_00425670 | Cached target position |
| +0x447c | float | currentSpeed | FUN_00425670 | Current speed |
| +0x4510 | int | steerState | FUN_00425670, FUN_00426330 | 1=search, 6=track, 7=arrived / current gear |
| +0x4558 | float | headingTimeout | FUN_00425670 | Max heading deviation time |

---



--- Section 206: VehiclePhysicsHeader (inferred) (180 offsets) ---
## VehiclePhysicsHeader (inferred)

Based on 8 function observations. Confidence: high.

Main vehicle physics instance struct (param_1). Contains pointers to sub-structs,
physics body references, wheel arrays, suspension/steering linkage systems,
aero data, and center-of-mass parameters.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (header start) | FUN_00439210, FUN_00430f00, FUN_0042f470, FUN_0042fd00 | Base of vehicle physics struct |
| +0x04 | unknown | (unknown) | FUN_0042f470 | Near UnitName string ptr |
| +0x08 | (ptr) | GearEnableFlag | FUN_0042f470, FUN_0042fd00 | Per-gear enable flag at +0x08 within gear slot (stride 0x40) |
| +0x18 | char* | SpeedUnit | FUN_0042f470 | Unit string (e.g. "kph") |
| +0x28 | char* | UnitName | FUN_0042f470 | Unit string (e.g. "mm", "deg") |
| +0x58 | char* | CarName/SetupName | FUN_0042f470 | Display name string |
| +0x68 | char* | Notes | FUN_0042fd00 | Driver notes string |
| +0x84 | double | SteeringRatioReduction | FUN_0043b590 | |
| +0x8c | double | SteeringRatio | FUN_0043b590 | 1.0/travel if travel>0 |
| +0x94 | double | MaxSteeringAngle | FUN_0043b590 | Radians |
| +0xa4 | int | SteeringFlags1 | FUN_0043b590 | |
| +0xa8 | int | SteeringFlags2 | FUN_0043b590 | |
| +0xbb0 | struct[] | SetupParamArray | FUN_0042f470 | Array of 64-byte setup parameter entries |
| +0xbc4 | int | TireCompoundSetting | FUN_0042fd00 | |
| +0xc04 | int | CGRightSetting | FUN_0042fd00 | |
| +0xc44 | int | CGRearSetting | FUN_0042fd00 | |
| +0xc84 | int | WedgeSetting | FUN_0042fd00 | |
| +0xcc4 | int | FuelSetting | FUN_0042fd00 | Also brake bias split from FUN_004e5f60 |
| +0xd04 | int | AntiSwaySetting | FUN_0042fd00 | Front anti-sway bar |
| +0xd44 | int | ToeInLeftSetting | FUN_0042fd00 | |
| +0xd84 | int | ToeInRightSetting | FUN_0042fd00 | |
| +0xdc4 | int | (Suspension param) | FUN_0042fd00 | |
| +0xe04 | int | LeftFenderFlareSetting | FUN_0042fd00 | |
| +0xe44 | int | RightFenderFlareSetting | FUN_0042fd00 | |
| +0xe84 | int | CasterLeftSetting | FUN_0042fd00 | |
| +0xec4 | int | CasterRightSetting | FUN_0042fd00 | |
| +0xf04 | int | TrackBarLeftSetting | FUN_0042fd00 | |
| +0xf44 | int | TrackBarRightSetting | FUN_0042fd00 | |
| +0xf84 | int | Front3rdSpringSetting | FUN_0042fd00 | |
| +0xfc4 | int | FrontPackerSetting | FUN_0042fd00 | |
| +0x1004 | int | FrontBumpSetting | FUN_0042fd00 | |
| +0x1044 | int | FrontReboundSetting | FUN_0042fd00 | |
| +0x1084 | int | Rear3rdSpringSetting | FUN_0042fd00 | |
| +0x10c4 | int | RearPackerSetting | FUN_0042fd00 | |
| +0x1104 | int | RearBumpSetting | FUN_0042fd00 | |
| +0x1144 | int | RearReboundSetting | FUN_0042fd00 | |
| +0x1184 | int | (Susp param) | FUN_0042fd00 | |
| +0x11c4 | int | (Susp param) | FUN_0042fd00 | |
| +0x1204 | int | (Susp param) | FUN_0042fd00 | |
| +0x1244 | int | (Susp param) | FUN_0042fd00 | |
| +0x1284 | int | FWSetting | FUN_0042fd00 | Front wing setting |
| +0x12c4 | int | RWSetting | FUN_0042fd00 | Rear wing setting |
| +0x1304 | int | RadiatorSetting | FUN_0042fd00 | |
| +0x1344 | int | BrakeDuctSetting | FUN_0042fd00 | |
| +0x1384 | int | RearBrakeSetting | FUN_0042fd00 | |
| +0x13c4 | int | BrakePressureSetting | FUN_0042fd00 | |
| +0x1404 | int | HandbrakePressSetting | FUN_0042fd00 | |
| +0x141c | (ptr) | AttachedBodyPtr / RearAxlePtr | FUN_00439210, FUN_00438da0, FUN_0043f7f0, FUN_00442060 | Attached aero body / rear axle / alternate force target |
| +0x1428 | unknown | AeroDataStart | FUN_00439210 | Aero data region |
| +0x1430 | unknown | AeroDataEnd | FUN_00439210 | |
| +0x1444 | int | SteerLockSetting | FUN_0042fd00 | |
| +0x1448 | double | FrontAeroDownforce | FUN_00439210 | |
| +0x1450 | double | RearAeroDownforce | FUN_00439210 | |
| +0x1484 | int | DiffPumpSetting | FUN_0042fd00 | |
| +0x14c4 | int | DiffPowerSetting | FUN_0042fd00 | |
| +0x1504 | int | DiffCoastSetting | FUN_0042fd00 | |
| +0x1544 | int | DiffPreloadSetting | FUN_0
[...9413 chars truncated]

--- Section 207: VehicleSetupFileWriterLayout (setup file struct region) (0 offsets) ---
## VehicleSetupFileWriterLayout (setup file struct region)

Based on 1 function observation (FUN_0042fd00). Confidence: high.

The setup file writer accesses a large region of the vehicle struct devoted to setup
parameter values. These offsets overlap with the main VehiclePhysicsHeader struct
at the +0xbb0–+0x1ccx range.

Most setup fields are `int` type (4 bytes). See VehiclePhysicsHeader table above for
complete listing. This section cross-references which entries are setup-file moddable.

**Moddable setup fields (confirmed by FUN_0042fd00):**
All int-type fields from +0xbc4 (TireCompoundSetting) through +0x1ccx (GearSettings)
are written to setup files. Full list in VehiclePhysicsHeader table above.

---



--- Section 208: Filter List State (4 offsets) ---
## Filter List State

Based on 1 function observation (FUN_004c5e50). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | void* | list head | FUN_004c5e50 | |
| +0x0c | void* | list tail | FUN_004c5e50 | |
| +0x10 | void* | current iterator | FUN_004c5e50 | |
| +0x14 | int | node count | FUN_004c5e50 | |

---



--- Section 209: Transform/4x4 Matrix Struct (inferred) (16 offsets) ---
## Transform/4x4 Matrix Struct (inferred)

Used by FUN_0054b570, FUN_00541db0. Holds Euler-angle orientation and
4x4 transformation matrix with backup copy.

Based on 2 function observations. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x20 | float | positionX | FUN_0054b570 | Translation X |
| +0x24..0x2c | float[3] | inputVec | FUN_00541db0 | Input direction vector (x,y,z) |
| +0x2c | float | yaw | FUN_0054b570, FUN_00541db0 | Heading/rotation about Y |
| +0x30 | float | pitch | FUN_0054b570, FUN_00541db0 | Rotation about X |
| +0x34 | float | roll | FUN_0054b570, FUN_00541db0 | Rotation about Z |
| +0x38 | float | rollAlt | FUN_00541db0 | Roll angle (random) |
| +0x40 | int | matrixSlot | FUN_0054b570 | Non-0 = use alt slot (+0xd4) |
| +0xd4/0xe4/0xf4 | float[12] | matrixAlt | FUN_0054b570 | Alternate transform slot |
| +0x114/124/134 | float[12] | matrixRows | FUN_0054b570 | Primary 4×4 rows 0/1/2 |
| +0x144/0x104 | float[4] | positionRow3 | FUN_0054b570 | Translation row + W=1 |
| +0x154 | float[16] | matrixBackup | FUN_0054b570 | Cached copy of 4×4 |
| +0x15c..0x198 | float[16] | rotMatrix | FUN_00541db0 | 4×4 rotation matrix |
| +0x18c | float | resultX | FUN_00541db0 | Rotated vector X |
| +0x190 | float | resultY | FUN_00541db0 | Rotated vector Y |
| +0x194 | float | resultZ | FUN_00541db0 | Rotated vector Z |
| +0x198 | float | one | FUN_00541db0 | Constant 1.0 |



--- Section 210: Render Property Slots (inferred) (3 offsets) ---
## Render Property Slots (inferred)

Used by FUN_00554700. Stores value and index property slots
with vtable object for dispatch.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1398 | int | valueSlot1 | FUN_00554700 | Property value (param_1[0x4e6]) |
| +0x139c | int | valueSlot2 | FUN_00554700 | Property index (param_1[0x4e7]) |
| +0x1100 | ptr | vtableObj | FUN_00554700 | Object with vtable (param_1[0x440]) |



--- Section 211: SpringDamperState (inferred — param_1 as int[] in FUN_0044f6f0) (0 offsets) ---
## SpringDamperState (inferred — param_1 as int[] in FUN_0044f6f0)

Based on FUN_0044f6f0. Confidence: **medium**.

| Index | Field | Notes |
|-------|-------|-------|
| [0x00] | MinVelocity | Velocity lower bound |
| [0x01] | MaxVelocity | Velocity upper bound |
| [0x02] | MinPosition | Position lower bound |
| [0x03] | MaxPosition | Position upper bound |
| [0x04] | PrevPosition | Previous frame position |
| [0x05] | PrevParam3 | Previous param_3 value |
| [0x06] | SpringK1 | Spring coefficient (float bit pattern) |
| [0x07] | SpringK2 | Secondary spring coefficient |
| [0x08] | DeltaPosition | Computed position delta |
| [0x09] | DeltaVelocity | Computed velocity delta |
| [0x0A] | OutputPosition | Clamped position × K1 |
| [0x0B] | OutputVelocity | Clamped velocity × K2 |
| [0x2C-0x2F] | Coeffs | Coefficient registers |

---



--- Section 212: Summary (0 offsets) ---
## Summary

| Struct name | # observations | Confidence | Key functions |
|-------------|---------------|------------|---------------|
| CollisionBody | 6 | high | 0x436870, 0x4542d0, 0x457a00, 0x4584c0, 0x4987b0, 0x44fee0 |
| BVH/SpatialTreeNode | 4 | high | 0x403aa0, 0x4039c0, 0x44aa30, 0x4038e0 |
| CollisionLinkedNode | 4 | high | 0x494e60, 0x4bac20, 0x4ba140, 0x4bad70 |
| DualLinkedListHeader | 2 | high | 0x4bad70, 0x490d00 |
| CollisionGridParams | 8 | medium | Dozens of grid init functions |
| CollisionMaterialGroup | 8 | high | Dozens of material init functions |
| WheelContactState | 1 | high | 0x4e96c0 |
| CollisionDamageContactStore | 2 | medium | 0x45b840 |
| BSPTreeNode | 1 | medium | 0x44a4b0 |
| CollisionRaycastPlane | 1 | medium | 0x44ba40 |
| ProximitySphere | 1 | high | 0x4bda20 |
| CollisionContactSolver | 1 | medium | 0x45c8f0 |
| SpringDamperState | 1 | medium | 0x44f6f0 |
| SensorState | 1 | low | 0x464a40 |
| CollisionPositionStepper | 1 | low | 0x48cb00 |
| CollisionProxyRegistration | 2 | medium | 0x44f0e0, 0x44f0a0 |
| CollisionElementArray | 1 | low | 0x4046b0 |
| CollisionShapeClassifier | 2 | medium | 0x4139c0, 0x412c30 |
| ImpulseAccumulator | 1 | medium | 0x44fee0 |
| CollisionDataBlock | 3 | medium | 0x44fbb0, 0x44fbe0, 0x44efc0 |
| ConstraintSolverState | 2 | low | 0x454250, 0x4542d0 |
| AnimationFrameTimer | 1 | low | 0x469dd0 |
| VehicleLapTime | 1 | high | 0x49b6d0 |
| ViewportRect | 1 | medium | 0x44f680 |
| OscillatoryCollisionState | 2 | low | 0x45c7e0, 0x45c8f0 |
| CollisionNoiseRange | 1 | low | 0x4962c0 |
| Tire/vehicle struct (partial) | 1 | low | 0x4a6b80 |
| ConstraintForceState | 1 | low | 0x454250 |
| GridCellIndex | 1 | low | 0x51d247 |
| CollisionTerrainSurface | 1 | low | 0x45ca20 |
| CollisionProxyFlagSetter | 1 | low | 0x4ba140 |
| CollisionDeformationMesh | 1 | medium | 0x4df110 |
| CollisionMutexState | 1 | low | 0x45bf90 |
| CollisionResponseState | 3 | medium | 0x462ce0, 0x463cd0, 0x453100 |

Total distinct structs: **34** identified from 41 offset table observations in docs/17-physics-collision.md.

**Key insights:**
- The **CollisionBody** struct is dominant — ~58 field observations across 6 functions, spanning 0x040 to 0x1184
- Per-contact sub-struct within CollisionBody has stride 0x90 (144 bytes) for contact data
- Grid and material init functions follow a repetitive 4-field pattern with count/zero/zero/(1.0f or -1.0f or range)
- Multiple structures share offset +0x94/0x98/0x9C for position (consistent across BVH, spatial trees, collision bodies)
- Linked list node pattern (data + next + flags) is consistent at 0xC bytes across multiple collision subsystems

---



--- Section 213: 13. Commentary Path List Struct (inferred) (6 offsets) ---
## 13. Commentary Path List Struct (inferred)

Based on 1 function observation (FUN_00414e60). Confidence: very low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char*? | CircuitNamePtr | FUN_00414e60 | Circuit/season name pointer |
| +0x02 | unknown | PathData | FUN_00414e60 | Path data |
| +0x05 | char*? | CountryE | FUN_00414e60 | English country name (entry 2) |
| +0x0a | char*? | CountryB | FUN_00414e60 | Broadcast language country name (entry 3) |
| +0x12 | char*? | CircuitE | FUN_00414e60 | English circuit name (entry 4) |
| +0x17 | char*? | CircuitB | FUN_00414e60 | Broadcast language circuit name (entry 5) |

**CONFLICT:** Offsets (+0x00, +0x02, +0x05, +0x0a, +0x12, +0x17) are not DWORD-aligned in a typical 32-bit PE struct. Likely multiple struct sizes being accessed, or the doc offsets are relative to different base pointers. Not reliable for struct synthesis.

---



--- Section 214: MessageSlotStruct (inferred, 0x18 bytes per slot) (4 offsets) ---
## MessageSlotStruct (inferred, 0x18 bytes per slot)

Based on 1 function (FUN_0057b840). Confidence: medium.

Network message comparison slot layout (inner struct, pointed to by +0x1c of parent).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x02 | int16 | MessageID | FUN_0057b840 | Short-masked event type |
| +0x04 | int32 | MessageValue | FUN_0057b840 | Subtype or parameter value |
| +0x12 | int16 | MessageID_alt | FUN_0057b840 | Alternative slot ID |
| +0x14 | int32 | MessageValue_alt | FUN_0057b840 | Alternative slot value |

---



--- Section 215: Struct 1: VehiclePhysicsInstance (tire region) (18 offsets) ---
## Struct 1: VehiclePhysicsInstance (tire region)

Based on 3 function observations (FUN_0043e050, FUN_004537b0, FUN_00454350).
Confidence: **high** — offsets confirmed by multiple functions and match existing
13-struct-offsets.md reference.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0060 | int | wheelState0 | FUN_0043e050 | zero-initialized; per-wheel state |
| +0x0064 | int | wheelState1 | FUN_0043e050 | zero-initialized; per-wheel state |
| +0x0068 | double | tireModelStep | FUN_0043e050 | computed: `400 >> TireModelMode` × multiplier |
| +0x1140 | double[8] | frontTireTelemetry | FUN_004537b0, FUN_00454350 | 8 double telemetry values per front axle; consistent with 13-struct-offsets.md |
| +0x1160 | byte[16] | frontCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array; consistent with ref |
| +0x1170 | int | currentFrontCompound | FUN_004537b0, FUN_00454350 | index into compound array; compared to 4 constants → HUD display |
| +0x1174 | int | pitstopCompound2 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 2 |
| +0x1178 | int | pitstopCompound3 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 3 |
| +0x117c | int | pitstopCompound4 | FUN_004537b0, FUN_00454350 | compound selection for pitstop 4 |
| +0x1180 | uint | pitStopFlag | FUN_004537b0, FUN_00454350 | bitmask: bit0=stop1, bit0x100=stop2, bit0x200=stop3, bit0x400=stop4 |
| +0x153c | double[8] | rearTireTelemetry | FUN_004537b0, FUN_00454350 | 8 double telemetry values per rear axle; consistent with ref |
| +0x155c | byte[16] | rearCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array; consistent with ref |
| +0x1f00 | int/ptr | contextData | FUN_0043e050 | set from stack parameter (opaque context ptr) |

**Pre-existing reference offsets (from 13-struct-offsets.md, same struct):**
| +0x1db4 | double | effectiveLifetime | existing ref | engine lifetime at spawn |
| +0x1dbc | double | lifetimeRPMMin | existing ref | |
| +0x1dc4 | double | invLifetimeRPMMax | existing ref | 1 / max (stored as reciprocal) |
| +0x1dcc | double | lifetimeOilTempMin | existing ref | |
| +0x1dd4 | double | invLifetimeOilTempMax | existing ref | 1 / max (stored as reciprocal) |

**Coverage gap:** Offsets +0x006c to +0x113f (~4,308 bytes) between wheel states
and tire telemetry region are undocumented.

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_O.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
