# WORKER C — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker C of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_C.md

## YOUR STRUCT SECTIONS (15)

--- Section 31: VehicleStruct (param_1 — vehicle struct) (192 offsets) ---
## VehicleStruct (param_1 — vehicle struct)

Largest observed struct. Range 0x0000–0x48C0. Used by physics, AI, session, and replay functions.

Based on 48+ function observations. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0000–0x07 | various | VTable / object header | multiple | Standard MSVC object header |
| +0x08 | float | PositionX | FUN_004e2130, FUN_004e2070 | World position; aligned |
| +0x0c | float | PositionY | FUN_004e2130, FUN_004e2070 | |
| +0x10 | float | PositionZ | FUN_004e2130, FUN_004e2070 | |
| +0x14 | float[4] | Orientation | FUN_004e2130 | Quaternion (x,y,z,w) |
| +0x20–+0x40 | float[3][3] | RotationMatrix | FUN_004e2130, FUN_004ed420, FUN_004e9bd0, FUN_004ef180, FUN_004f17d0, FUN_004eff00, FUN_004e9980 | Column-major, 9 floats |
| +0x34b0 | float | RotationMatrix[0][0] | FUN_004e9bd0, FUN_004ed420, FUN_004ef180, FUN_004f17d0 | Row 0 |
| +0x34b8 | float | CoolingCoeff1 / DirX | FUN_004e87e0, FUN_004eff00 | Direction/thermal |
| +0x34bc | float | RotMatrix_row1[0] | FUN_004ed420 | |
| +0x34c4 | float | GridForwardDirX / DirY | FUN_004d0110, FUN_004eff00 | |
| +0x34c8 | float | RotMatrix_row2[0] | FUN_004ed420 | |
| +0x34d0 | float | GridForwardDirY / DirZ | FUN_004d0110, FUN_004eff00, FUN_004e9980 | |
| +0x34d4 | float | TranslationX / PosX | FUN_004e9bd0, FUN_004ef6c0, FUN_004e9980, FUN_004e9630 | World position X |
| +0x34d8 | float | PosY | FUN_004ef6c0, FUN_004e9980, FUN_004e9630 | World position Y |
| +0x34dc | float | PosZ / GridForwardDirZ | FUN_004d0110, FUN_004ef6c0, FUN_004e9980, FUN_004e9630, FUN_004f0050 | World position Z |
| +0x34e0 | ptr | AIStateStructBase | FUN_0042add0 | Pointer to AI substate |
| +0x34ec–+0x34f4 | float[3] | InputVector / Velocity | FUN_004eff00, FUN_004f1aa0 | Force/velocity input |
| +0x34f8 | float | Velocity/PositionZ | FUN_004d0110 | |
| +0x34fc | float | Velocity/PositionY | FUN_004d0110 | |
| +0x3500 | float | Velocity/PositionX | FUN_004d0110, FUN_004e87e0 | Also BrakePadTemp |
| +0x3504 | float | VarA | FUN_004e4e60 | Physics integration state |
| +0x3508 | float | VarB | FUN_004e4e60 | |
| +0x350c | float | VarC | FUN_004e4e60 | |
| +0x3514 | float | ForceScaleFactor / DampingCoeff | FUN_004e9100, FUN_004e9300, FUN_004e8010, FUN_004e8b80 | Scales force terms |
| +0x3518 | float | OutputScaleFactor / GripMultiplier / ScaleFactor | FUN_004e9100, FUN_004e9300, FUN_004e8010, FUN_004e8b80 | Final force scaling |
| +0x3534 | float[3] | InputVec | FUN_004f17d0 | Input vector XYZ |
| +0x3540–+0x3548 | float[3] | OutputVec | FUN_004f17d0 | Transformed result |
| +0x3570 | float | CoolingVelocity / SpeedRatio / ForceScaling | FUN_004e5080, FUN_004e513e, FUN_004ee230 | Clamped velocity/force |
| +0x3578 | float | Speed | FUN_004ef930 | Race start speed |
| +0x3580+0x90 | float | RearAxleRef | FUN_004e9300 | Rear axle parameter |
| +0x358c/+0x3594 | float | SuspensionDeflection_L/R | FUN_004e8010 | L/R front suspension |
| +0x3594 | float[4] | ElementArray | FUN_004ed420 | Per-element position+radius, stride 0xf8 |
| +0x35b0 | float | LateralForce1 | FUN_004ed810 | Per-wheel lateral force |
| +0x35d8 | float | WheelCoeffs[0] | FUN_004ed810 | Per-wheel coefficient |
| +0x35dc | float | WheelForcePrev[0] | FUN_004ed810 | Per-wheel previous force |
| +0x35f0 | float[4] | WheelOutputs | FUN_004e4e60 | Per-wheel outputs, stride ~0x3e |
| +0x3610/+0x362c | float | WheelForceBase | FUN_004e8010 | Wheel force base values |
| +0x361c | float[4] | PitchScale | FUN_004f1510 | 4 floats, stride 0x3e |
| +0x3664 | int | WheelForce[0] | FUN_004f1ba0 | Per-wheel force param |
| +0x3668 | int | ContactID | FUN_004ef180 | Per wheel contact ID (stride 0xf8) |
| +0x3684/+0x368c | float | SuspensionVelocity_L/R | FUN_004e8010 | |
| +0x36a8 | float | LateralForce2 | FUN_004ed810 | |
| +0x36d0 | float | WheelCoeffs[1] | FUN_004ed810 | |
| +0x36d4 | float | WheelForceCopy[0] | FUN_004ed810 | |
| +0x3708/+0x
[...11054 chars truncated]

--- Section 32: VehicleTelemetryBroadcast (param_1 — telemetry) (6 offsets) ---
## VehicleTelemetryBroadcast (param_1 — telemetry)

Based on FUN_004ec080. Confidence: **low** (single function).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xcaf | int | BroadcastMode | FUN_004ec080 | 0=full broadcast, 2=team-filtered |
| +0xd2c | ptr | RotationPtr | FUN_004ec080 | Transform input |
| +0xd35 | float | PosX | FUN_004ec080 | Accumulator |
| +0xd36 | int | PosY | FUN_004ec080 | Accumulator |
| +0xd37 | int | PosZ | FUN_004ec080 | Accumulator |
| +0xd38 | float | PosFloat | FUN_004ec080 | Position for transform |

---



--- Section 33: 3. LinkedListNode (inferred) (3 offsets) ---
## 3. LinkedListNode (inferred)

Node with data, next, and optional free flag.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | ptr | DataPtr | Multiple | Pointer to node data |
| +0x04 | ptr | NextPtr | Multiple | Next node in list |
| +0x08 | byte | FreeFlag | Multiple | If non-zero, free data on destroy |



--- Section 34: VehiclePhysicsState (inferred) (140 offsets) ---
## VehiclePhysicsState (inferred)

Large vehicle dynamics & suspension struct. Stride 0x464 per wheel substruct. Used by 20+ functions.

Based on 20+ function observations. Confidence: high.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x000 | int/byte | ActiveFlag | FUN_00431390 | Set to 1 on init |
| +0x004 | byte | ActiveFlag | FUN_004f8370, FUN_00434450 | Set to 1 on init |
| +0x008 | int | Mode/Magic | FUN_00434450 | Config init |
| +0x00c | int | DataPtr | FUN_0040ef70 | Target data struct pointer |
| +0x010 | float | ResultFloat | FUN_0040ef70 | Stored result |
| +0x014 | float | InitFlag | FUN_00434450 | Config init |
| +0x018 | int | Sentinel/-1 | FUN_00434450, FUN_00434860 | Config init (0xffffffff) |
| +0x01c | int | Mode | FUN_0040ef70, FUN_0040f550, FUN_00434450, FUN_00434860 | Processing mode 0-5 |
| +0x020 | float | MaxForce? | FUN_00434450, FUN_00434860 | Config default 2.0f |
| +0x024 | float | MaxForce2? | FUN_00434450 | Config default 2.0f |
| +0x028 | int | Reserved | FUN_00434450 | Set to 0 |
| +0x02c | int | Reserved2 | FUN_00434450, FUN_00432810 | Config init |
| +0x030 | float | FrictionCoeff | FUN_00434450, FUN_00434860 | Config default 3.25f |
| +0x034 | int | Reserved3 | FUN_00434450, FUN_00434860 | Config init |
| +0x038 | double | SomeValue | FUN_00431850 | Suspension model intermediate |
| +0x060 | double | InputAngle | FUN_00447ab0 | Table lookup input |
| +0x064 | double | MomentumAccumX | FUN_00569670 | Linear momentum accumulator |
| +0x06c | double | MomentumAccumY | FUN_00569670 | Linear momentum accumulator |
| +0x074 | double | MomentumAccumZ | FUN_00569670 | Linear momentum accumulator |
| +0x078 | int | VehicleIndex | FUN_00438130 | Index in vehicle array |
| +0x094 | double | Counter/State | FUN_004f8370 | Reset to 0 on init |
| +0x0a8 | float | StoredValue | FUN_004fefc0 | Clamped value |
| +0x0ac | float | Reciprocal | FUN_004fefc0 | 1/value for fast multiply |
| +0x0b0 | float | Reciprocal2 | FUN_004fefc0 | Second reciprocal |
| +0x0b4 | int | (varies) | FUN_0040ef70 | Mode 0-5 processing |
| +0x0bc | double | DampingCoeff | FUN_00438130 | Velocity-based damping |
| +0x0d4 | float | DirX | FUN_004e3090 | Normalised direction X |
| +0x0e0 | float | DirZ | FUN_004e3090 | Normalised direction Z |
| +0x124 | float | PosY | FUN_004e3090 | World position Y |
| +0x134 | double | — | FUN_00441360 | Position/velocity component |
| +0x13c | double | — | FUN_00441360 | Position/velocity component |
| +0x144 | double | — | FUN_00441360 | Position/velocity component |
| +0x14c | double | SpringCoeff | FUN_00438130, FUN_00441360 | Spring/damper coefficient |
| +0x154 | double | — | FUN_00441360 | Position/velocity component |
| +0x15c | double | SubstructPtr | FUN_00438130, FUN_00441360 | Pointer to substruct (or double) |
| +0x19c | double | IntegrationFlag | FUN_00447b10, FUN_0041d60, FUN_00438130 | 0 = step pending |
| +0x1c59 | byte | DisableFlag | FUN_00447b10, FUN_00447270 | 0 = disabled |
| +0x234 | double | — | FUN_00438130 | Unnamed double |
| +0x268 | double | SpringForce2 | FUN_00438130 | Spring force |
| +0x270 | double | — | FUN_00438130 | Unnamed double |
| +0x278 | double | — | FUN_00438130 | Unnamed double |
| +0x288 | double | — | FUN_00438130 | Unnamed double |
| +0x314 | double | — | FUN_00438130 | Unnamed double |
| +0x31c | double | SpringForce1 | FUN_00438130 | Spring force |
| +0x324 | double | DampingCoeff2 | FUN_00438130 | Velocity-based damping |
| +0x334 | double | ForceRatio1 | FUN_00438130 | Convergence computation |
| +0x33c | double | — | FUN_00438130 | Unnamed double |
| +0x344 | double | — | FUN_00438130 | Unnamed double |
| +0x34c-0x36c | double[6] | ForceAccumulator | FUN_00438130 | 6-slot force accumulator |
| +0x354 | double | — | FUN_00438130 | Unnamed double |
| +0x35c | double | — | FUN_00438130 | Unnamed double |
| +0x364 | double | FactorA | FUN_00438100 | Multiplication factor A |
| +0x368 | double | 
[...7027 chars truncated]

--- Section 35: SparseParamArray (4 offsets) ---
## SparseParamArray

From FUN_004319c0, FUN_00431a70. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x1cd4 | byte[] | ParamFlags | Per-parameter dirty flags |
| +0x1cd8 | int[] | ParamValues | Per-parameter values |
| +0x1ce8 | byte[] | RowActiveFlags | Per-row active flags |
| +0x000 | int[3] | GridBase | 3-wide grid (4-byte elements) |

---



--- Section 36: WheelSuspensionData (inferred) (11 offsets) ---
## WheelSuspensionData (inferred)

Based on 1 function observation (FUN_0042fd00). Confidence: medium.

Per-wheel setup data, stride 0x2c0. Used in [FRONTLEFT]/[FRONTRIGHT]/[REARLEFT]/[REARRIGHT] sections.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x104 | int | CamberSetting | FUN_0042fd00 | |
| +0x144 | int | RideHeightSetting | FUN_0042fd00 | |
| +0x184 | int | PackerSetting | FUN_0042fd00 | |
| +0x1c4 | int | SpringSetting | FUN_0042fd00 | |
| +0x204 | int | SlowBumpSetting | FUN_0042fd00 | |
| +0x244 | int | FastBumpSetting | FUN_0042fd00 | |
| +0x284 | int | SlowReboundSetting | FUN_0042fd00 | |
| +0x2c4 | int | FastReboundSetting | FUN_0042fd00 | |
| +0x304 | int | BrakeDiscSetting | FUN_0042fd00 | |
| +0x344 | int | BrakePadSetting | FUN_0042fd00 | |
| +0x2c0 | - | WheelSetupStride | - | Per-wheel stride |

---



--- Section 37: Player File Struct (6 offsets) ---
## Player File Struct

Based on 2 function observations (plrfile.cpp section, FUN_004b0540). Confidence: medium — offsets from different sections consistent.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x14 | char* | FilePath | FUN_004b0540 | player data path |
| +0x114 | int | FileExistsFlag | FUN_004b0540 | |
| +0x1f78 | int | GameMode | FUN_004b0540 | also called "state (4=?)" in plrfile |
| +0x24f8 | int | VehicleCountTable | FUN_004b0540 | clamped 1-104 |
| +0x2f8c | int | AIDifficulty | FUN_004b0540 | |
| +0x49b0 | char* | player data path ptr | plrfile.cpp section | duplicate of +0x14? |

**Conflict:** +0x14 is FilePath (char*) and +0x49b0 is also player data path pointer. These may be different fields (primary path vs backup), or the plrfile.cpp section refers to a different struct. Uncertain.

---



--- Section 38: UI Dialog/Property Page Struct (6 offsets) ---
## UI Dialog/Property Page Struct

Based on 1 function observation (FUN_00469880). Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | void* | vtablePtr | FUN_00469880 | PTR_FUN_0059f7c8 |
| +0x174 | int | zeroed | FUN_00469880 | param_1[0x5d] |
| +0x178 | int | zeroed | FUN_00469880 | param_1[0x5e] |
| +0x17c | byte | activeFlag | FUN_00469880 | set to 1 |
| +0x180 | int | zeroed | FUN_00469880 | param_1[0x60] |
| +0x184 | int | sentinel | FUN_00469880 | param_1[0x61] = -1 |

---



--- Section 39: Screen-Space Tile Renderer (inferred) (4 offsets) ---
## Screen-Space Tile Renderer (inferred)

Used by FUN_00495dc0. Controls full vs tiled blit rendering.

Based on 1 function observation. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1578 | int | renderMode | FUN_00495dc0 | 0=full blit, 1=tiled (80 steps) |
| +0x157c | ptr | chainPtr | FUN_00495dc0 | Dereference chain to source texture |
| +0x1580 | int | screenOffsetX | FUN_00495dc0 | Accumulated X scroll/offset |
| +0x1584 | int | screenOffsetY | FUN_00495dc0 | Accumulated Y scroll/offset |



--- Section 40: CollisionLinkedNode (inferred — generic collision/proxy linked list node) (3 offsets) ---
## CollisionLinkedNode (inferred — generic collision/proxy linked list node)

Based on 4 function observations (FUN_00494e60, FUN_004bac20, FUN_004ba140, FUN_004bad70). Confidence: **high**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | int* | Data | FUN_004bac20, FUN_00494e60 | Proxy data pointer / resource handle |
| +0x04 | int* | Next | FUN_004bac20, FUN_00494e60 | Next node pointer |
| +0x08 | byte | Flag | FUN_004bac20, FUN_00494e60 | Byte flag/type, non-zero=active |

---



--- Section 41: CollisionDataBlock (inferred — param_1 in FUN_0044fbb0) (4 offsets) ---
## CollisionDataBlock (inferred — param_1 in FUN_0044fbb0)

Based on FUN_0044fbb0, FUN_0044fbe0, FUN_0044efc0. Confidence: **medium**.

| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x080 | int* | VTablePtr | FUN_0044fbe0, FUN_0044f7f0 | Vtable/collision object pointer |
| +0x084 | int[0x91] | DataBlock | FUN_0044fbb0, FUN_0044efc0 | Collision data payload (364–580 bytes) |
| +0x278 | int | Handle | FUN_0044efc0 | Handle/ID |
| +0x2F4 | int | StoredParam | FUN_0044fbb0, FUN_0044fbe0 | Reference/state flag |

---



--- Section 42: 1. Track Material Struct (inferred) (12 offsets) ---
## 1. Track Material Struct (inferred)

Based on 1 function observation (FUN_004cdd80). Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x08 | float? | GripLevel | FUN_004cdd80 | Read from MATERIALS file section |
| +0x0c | float? | GripLevel2 | FUN_004cdd80 | Computed (grip - offset) |
| +0x10 | float? | Resistance | FUN_004cdd80 | Collision resistance |
| +0x14 | float? | BumpAmp | FUN_004cdd80 | × _DAT_0059e7f8 at load |
| +0x18 | float? | BumpFreq | FUN_004cdd80 | _DAT_0059ed28 / wavelen (min 3.0) |
| +0x1c | float? | Spring | FUN_004cdd80 | Spring rate |
| +0x20 | float? | Damper | FUN_004cdd80 | Damper rate |
| +0x24 | float? | CollFrict | FUN_004cdd80 | Collision friction |
| +0x28 | int? | Sparks | FUN_004cdd80 | Sparks texture/effect |
| +0x2c | bool? | Scraping | FUN_004cdd80 | Bool — scraping sound on collision |
| +0x30–0x38 | int[3]? | SoundIDs | FUN_004cdd80 | 3 sound indices |
| +0x60 | bool? | LegalFlag | FUN_004cdd80 | Bool — is material legal track surface |

Note: Types are inferred from field semantics (float for physics values, int/bool for flags). No explicit type casts documented in source. Struct size ~0x60+.

---



--- Section 43: AudioChannelInitStruct (inferred) (17 offsets) ---
## AudioChannelInitStruct (inferred)

Based on 2+ function observations. Confidence: medium.

Audio channel/voice initialization struct used by audio system init.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x130 | int | PitchScale1 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x131 | int | PitchScale2 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x132 | int | PitchScale3 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x133 | int | PitchScale4 | FUN_0044ff50 | Division rate for pitch scaling |
| +0x13a | int | SourceHandle1 | FUN_0044ff50 | Audio source handle |
| +0x13c | int | SourceHandle2 | FUN_0044ff50 | Audio source handle |
| +0x13d | int | SourceHandle3 | FUN_0044ff50 | Audio source handle |
| +0x13e | int | Direction1 | FUN_0044ff50 | Direction flag |
| +0x140 | int | Direction2 | FUN_0044ff50 | Direction flag |
| +0x141 | int | Direction3 | FUN_0044ff50 | Direction flag |
| +0x142 | int | ChannelOffset1 | FUN_0044ff50 | Channel offset |
| +0x144 | int | ChannelOffset2 | FUN_0044ff50 | Channel offset |
| +0x145 | int | ChannelOffset3 | FUN_0044ff50 | Channel offset |
| +0x146 | int | SampleCount1 | FUN_0044ff50 | 8 samples per source |
| +0x147 | int | SampleCount2 | FUN_0044ff50 | 8 samples per source |
| +0xfef | void* | FnPtrTable | FUN_0045d530 | Function pointer table |
| +0xff6 | int | ChannelType | FUN_0045d530 | Set to 8 |

**Notes:**
- Three audio sources per surface: left engine, right engine, exhaust
- 10 control surface slots (cases 0–8) with sample IDs, volume, pan, gain curves
- +0x6ddb–0x6de3 are 8 slots (unclear stride)

---



--- Section 44: Struct 4: Driver Data Entry (stride 0x20 = 32 bytes = 8 ints) (3 offsets) ---
## Struct 4: Driver Data Entry (stride 0x20 = 32 bytes = 8 ints)

Based on FUN_00418560 and FUN_00418a60. Array at param_1+0x864, 20 entries max.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | Time/RankKey | FUN_00418560 | Sorted entry; compared against reference |
| +0x14 | int | SortKey | FUN_00418560 | Max entry index by this key |
| +0x00–+0x1c | int[8] | EntryData | FUN_00418a60 | Full 8-field entry |

---



--- Section 45: WeatherState (inferred) (36 offsets) ---
## WeatherState (inferred)

Weather state struct passed as `param_1` to weather system functions. Used by weather loader, file reader, file writer, and initializer. Contains wetness values, temperatures, fog/sun params, and a linked list of per-minute weather changes.

Based on 3 function observations. Confidence: **high** (consistent across all 3 functions).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | float | unknown_flag | FUN_004fcaa0 | init to 1.0 |
| +0x10 | int | unknown_id | FUN_004fcaa0 | init to -1 (0xFFFFFFFF) |
| +0x18 | float | unknown_val | FUN_004fcaa0 | init to -1.0 |
| +0x20 | float | unknown_zero | FUN_004fe350 | init to 0; only in FUN_004fe350 |
| +0x24 | float | unknown_zero2 | FUN_004fe350 | init to 0; only in FUN_004fe350 |
| +0x28 | float | OnPathWetness | FUN_004fe350, FUN_004fe820 | track grip on racing line; range ~[0,1]; default 0.0 |
| +0x2c | float | OffPathWetness | FUN_004fe350, FUN_004fe820 | track grip off racing line; clamped >= OnPathWetness; default 0.0 |
| +0x30 | float | AmbientTemp | FUN_004fe350, FUN_004fe820 | ambient temp in °C; default 20.0 |
| +0x34 | float | TrackTemp | FUN_004fe350, FUN_004fe820 | track temp in °C; default 22.0 (ambient + 2°C) |
| +0x38 | pointer | WeatherChangeTail | FUN_004fe350, FUN_004fe820 | linked list tail/current node of per-minute weather changes |
| +0x3c | pointer | WeatherChangeHead | FUN_004fe350, FUN_004fe820 | linked list head of per-minute weather changes |
| +0xa4 | float | unknown_neg1 | FUN_004fcaa0 | init to -1.0 |
| +0xa8 | float | sun_elevation | FUN_004fcaa0 | read for fog computation |
| +0xb4 | float | sun_pos_x | FUN_004fcaa0 | sun/light position X (trackPos.x * _DAT_0059e460) |
| +0xb8 | float | sun_pos_y | FUN_004fcaa0 | sun/light position Y |
| +0xbc | float | sun_pos_z | FUN_004fcaa0 | sun/light position Z |
| +0xc0 | float | fog_color_r | FUN_004fcaa0 | init to 0.75 |
| +0xc4 | float | fog_color_g | FUN_004fcaa0 | init to 0.75 |
| +0xc8 | float | fog_color_b | FUN_004fcaa0 | init to 0.75 |
| +0xcc | float | fog_param1 | FUN_004fcaa0 | init to 0.5; probably fog density/start |
| +0xd0 | float | fog_param2 | FUN_004fcaa0 | init to 0.5 |
| +0xd4 | float | fog_param3 | FUN_004fcaa0 | init to 0.5 |
| +0xd8 | float | sun_angle_cos | FUN_004fcaa0 | out param from FUN_00543a30 (sun angle computation) |
| +0xdc | float | sun_angle_sin | FUN_004fcaa0 | out param from FUN_00543a30 |
| +0xe0 | float | sun_angle_result | FUN_004fcaa0 | in/out param from FUN_00543a60 (sun vector magnitude?) |
| +0xe4 | float | unknown_175 | FUN_004fcaa0 | init to 175.0 |
| +0xe8 | float | unknown_700 | FUN_004fcaa0 | init to 700.0 |
| +0xec | float | fog_derived | FUN_004fcaa0 | derived from sun elevation and angle result |
| +0xf0 | int | unknown_zero3 | FUN_004fcaa0 | init to 0 |
| +0xf4 | float | unknown_150 | FUN_004fcaa0 | init to 150.0 |
| +0xf8 | float | unknown_001 | FUN_004fcaa0 | init to 0.01 |
| +0x1c4 | byte | unknown_flag | FUN_004fcaa0 | init to 0 |

**WeatherChangeNode** (linked list node, stride 0x10):
| Offset | Type | Field | Observed in | Notes |
|--------|------|-------|-------------|-------|
| +0x00 | float | time_minutes | FUN_004fe350, FUN_004fe820 | minutes since session start for this weather change |
| +0x04 | float | ambient_temp | FUN_004fe350, FUN_004fe820 | temperature at this time point |
| +0x08 | float | conditions | FUN_004fe350, FUN_004fe820 | wetness/grip multiplier at this time point |
| +0x0c | pointer | next | FUN_004fe350, FUN_004fe820 | next node in linked list (null = end) |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_C.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
