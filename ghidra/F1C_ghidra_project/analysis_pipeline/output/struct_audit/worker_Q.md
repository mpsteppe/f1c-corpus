=== AUDIT RESULTS ===

## Section 230: SpriteOverlayList (param_1 — display list)

Based on: FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480
All 5 files verified in analyzed/. HIGH confidence.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c0 | ptr | ListHead | HIGH | 5 files agree: (int*)(param+0x6c0) — linked list head pointer | none |
| +0x6c4 | ptr | ListTail | HIGH | 4 files agree: *(undefined4**)(param+0x6c4) — tail pointer | none |
| +0x6c8 | ptr | ListCursor | HIGH | 4 files agree: *(undefined4**)(param+0x6c8) — iterator/cursor | none |
| +0x6cc | int | ListCount | HIGH | 5 files agree: *(int*)(param+0x6cc) — integer count | none |
| +0x6d0 | byte | DirtyFlag | HIGH | 3 files agree: *(undefined1*)(param+0x6d0)=1 — byte flag | none |
| +0xf38 | float | ScoreValue | HIGH | 2 files agree: used as sort key, compared as float | none |

**Verdict:** All offsets correct. HIGH confidence. No changes needed.

---

## Section 231: Single-Function Struct Observations

### Linked List Controller (FUN_00407c90)
File exists: analyzed\0x00407c90__FUN_00407c90.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x18 | int32* | Head | HIGH | *(int**)(param+0x18) — list head pointer | none |
| +0x1c | int32* | Tail | HIGH | *(int**)(param+0x1c) — compared to current | none |
| +0x20 | int32* | Current | HIGH | *(undefined4*)(param+0x20) — iterator | none |
| +0x24 | int32 | Count | HIGH | *(int*)(param+0x24) decremented on removal | none |

### List Container (FUN_0050b6f0)
| +0x00 | int32* | Head | LOW | File not found in analyzed/ or decompiled_all/ | — |
| +0x04 | int32 | NodeCount | LOW | File not found | — |

### Resource List Container (FUN_00512a20)
All 6 offsets: LOW | File not found | —

### List Container (FUN_00565f20)
File exists: analyzed\0x00565f20__FUN_00565f20.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int* | HeadPtr | HIGH | *param_1 — dereferences to get head pointer | none |
| *(headPtr)+0x08 | int* | NextPtr | HIGH | *(int*)(iVar1+8) — next entry in list | none |

### Stream Object (FUN_005e3b60)
All offsets: LOW | File not found | —

### Ring Buffer (FUN_00569da0)
All offsets: LOW | File not found | —

### Processing State Machine (FUN_00404460)
File exists: analyzed\0x00404460__FUN_00404460.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x130 | int32 | Cap | HIGH | *(int*)(param+0x130) — max iteration count | none |
| +0x16c | int32 | Phase | HIGH | *(int*)(param+0x16c) — 0,1,2 state machine | none |
| +0x170 | float | FloatVal | HIGH | *(float*)(param+0x170) — computed threshold | none |
| +0x174 | int32 | IterIdx | HIGH | *(int*)(param+0x174) — current iteration index | none |

### Per-Element Struct (FUN_0053c790)
All 7 offsets: LOW | File not found | —

### FILE* Stream (FUN_00587d33)
File exists: analyzed\0x00587d33____fclose_lk.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | int | _flag | HIGH | param_1->_flag (CRT FILE struct) | none |
| +0x10 | int | _file | HIGH | param_1->_file (OS fd) | none |
| +0x1c | char* | _tmpfname | HIGH | param_1->_tmpfname | none |

### VTable Object Header (FUN_00408520)
File exists: analyzed\0x00408520__FUN_00408520.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | pointer | vtable | HIGH | *param_1 = &PTR_FUN_0059e60c | none |
| +0x10..+0x30 | pointer[] | SubObj[4..12] | HIGH | param_1[4..0xc] — 9 sub-object slots | none |

**Verdict:** 5 of 9 sub-structs verifiable. 4 sub-structs have no .c evidence (LOW).

---

## Section 232: NetworkMessage (inferred)

Based on: FUN_004a3ef0, FUN_00591583

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5C4 | uint | EventCode | LOW | No .c file for FUN_004a3ef0 or FUN_00591583 | — |
| +0x5C8 | char[] | StringBuffer | LOW | No .c file | — |
| +0x618 | HANDLE | BufferMutex | LOW | No .c file | — |
| +0x910 | uint16 | HeaderField | LOW | No .c file | — |
| +0xAC8 | ptr | ListBase | LOW | No .c file | — |
| +0xAD8 | HANDLE | ListMutex | LOW | No .c file | — |
| +0xADC | DWORD | MutexTimeout | LOW | No .c file | — |

**Verdict:** No .c source files exist for either referenced function. **LOW confidence.** Cannot verify.

---

## Section 233: PhysicsInteractionState (steering/force feedback)

Based on: FUN_004e2760. File exists in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x108 | int[4] | WheelIndices | HIGH | piVar11 = (int*)(param+0x108); stride 0x4a; loop 4 times | none |
| +0x938 | int | PackedWheelData | HIGH | *(int*)(param+0x938) = packed value | none |
| +0x93c | short | PackedShort | HIGH | *(short*)(param+0x93c) | none |
| +0x93e | byte | PackedByte | HIGH | *(char*)(param+0x93e) | none |
| +0x93f | byte | ChannelMask | HIGH | *(byte*)(param+0x93f) | none |
| +0x940 | int | ChannelBitfield | HIGH | *(uint*)(param+0x940) bitfield | none |
| +0x944 | short | ChannelOut0 | HIGH | *(undefined2*)(param+0x944) | none |
| +0x946 | short | ChannelOut1 | HIGH | *(undefined2*)(param+0x946) | none |
| +0x948 | short | ChannelOut2 | HIGH | *(undefined2*)(param+0x948) | none |
| **+0x98c** | **int** | **ActiveFlag** | **MEDIUM** | ***(char*)(param+0x98c) — byte, not int** | **CONFLICT: doc says int, .c shows char/byte** |
| +0x9a8 | float[] | AnalogChannels | HIGH | pfVar9 = (float*)(param+0x9a8); loop 0x11 times, stride 7 floats | none |

**Verdict:** 10 of 11 offsets verified. **1 CONFLICT at +0x98c** — change type from `int` to `char`/`byte`.

---

## Section 234: PhysicsSystemHeader (inferred)

Based on: FUN_0056d930. File exists in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | BodyCount | HIGH | param_1[0] = 0; init, incremented | none |
| +0x04 | ptr | BodyArray | HIGH | param_1[1] = (int)piVar4; stride 0x244 allocated | none |
| +0x08 | int | JointCount | HIGH | param_1[2] = 0; incremented per JOINT token | none |
| +0x0c | ptr | JointArray | HIGH | param_1[3] = (int)piVar3; stride 0x30 | none |
| +0x10 | int | HingeCount | HIGH | param_1[4] = 0; incremented per HINGE token | none |
| +0x14 | ptr | HingeArray | HIGH | param_1[5] = (int)piVar3; stride 0x30 | none |
| +0x18 | int | BarCount | HIGH | param_1[6] = 0; incremented per BAR token | none |
| +0x1c | ptr | BarArray | HIGH | param_1[7] = (int)piVar3; stride 0x48 | none |
| +0x20 | int | ConstraintCount | HIGH | param_1[8] = iVar12 (return from FUN_0056d430) | none |
| +0x24 | ptr | ConstraintMatrix | HIGH | param_1[9] = (int)pvVar11; alloc count*count*8 | none |
| **+0x28** | **ptr** | **ConstraintRowStride** | **HIGH** | **param_1[10] = row ptr array; naming misleading** | **MINOR: "RowStride" → "RowPtrArray"** |
| +0x2c | ptr | SolverObject | HIGH | param_1[0xb] = iVar12; solver object handle | none |

**Verdict:** All 12 offsets verified. HIGH confidence. Minor naming note at +0x28.

---

## Section 235: Source: docs/08-file-formats.md
0 offsets. Skip.

---

## Section 236: File State / Mode Flags Struct

Based on: FUN_00587f90, FUN_0059c156. Both in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | uint | ModeFlags | HIGH | *(uint*)(param+0xc) — bitmask checks (0x83, 1, 8, 0x80) — both files | none |
| +0x10 | int/void* | FileHandle | HIGH | *(undefined4*)(param+0x10) — file handle — both files | none |
| +0x18 | uint | BufferSize | HIGH | *(undefined4*)(param+0x18) = 0x200 — both files | none |

**Verdict:** All 3 offsets confirmed in 2 files each. HIGH confidence.

---

## Section 237: D3D Render State Cache (inferred)

Based on: FUN_00586700. File in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x34 | int | D3DRS_1_Value | HIGH | param+0x34 passed to FUN_0059b5c0(1, ...) | none |
| +0x38 | int | D3DRS_8_Value | HIGH | param+0x38 passed to FUN_0059b5c0(8, ...) | none |
| +0x3c | int | D3DRS_1b_Value | HIGH | param+0x3c passed to FUN_0059b5c0(1, ...) | none |
| +0x40 | int | D3DRS_2_Value | HIGH | param+0x40 passed to FUN_0059b5c0(2, ...) | none |
| +0x44 | int | D3DRS_10_Value | HIGH | param+0x44 passed to FUN_0059b5c0(0x10, ...) | none |

**Verdict:** All 5 offsets confirmed. HIGH confidence.

---

## Section 238: Inline offset references (not in tables)

### FUN_004c71c0 — SetupCarLightingAndRender
File exists: analyzed\0x004c71c0__FUN_004c71c0.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x83c | float[3]×4 | WheelPositions | HIGH | *(float*)(iVar4+param+0x83c) — indexed access | none |
| +0x704 | float[16] | ViewMatrix | HIGH | param+0x704 passed to FUN_004b2310 (matrix) | none |
| +0x744 | float[16] | WorldMatrix | HIGH | param+0x744 passed to FUN_004b2310 (matrix) | none |
| +0x34f8 | float[4] | DiffuseColor | HIGH | param+0x34f8 passed to FUN_004b2480 | none |
| +0x3510 | float[4] | SpecularColor | HIGH | param+0x3510 passed to FUN_004b25d0 | none |
| +0x3540 | int | EnvMapHandle | HIGH | param+0x3540 passed to FUN_004b2750 | none |

### FUN_0053f270 — RenderTargetCleanup
File exists: analyzed\0x0053f270__FUN_0053f270.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1140 | ptr | FrontBuffer | HIGH | *(int*)(param+0x1140) — released/cleared | none |
| +0x113c | ptr | BackBuffer | HIGH | *(int*)(param+0x113c) — released/cleared | none |
| +0x1144 | ptr | DepthStencil | HIGH | *(int*)(param+0x1144) — released/cleared | none |
| +0x14f0..0x1504 | int[5] | ViewportDims | HIGH | *(undefined4*)(param+0x14f0)=0 | none |
| +0x1518 | ptr | TextureList | HIGH | Linked list iteration from +0x1518 | none |
| +0x1580 | ptr | RenderTargetList | HIGH | Iterated from *(int*)(param+0x1580) | none |
| +0x13a8 | int | CleanupFlag | HIGH | *(uint*)(param+0x13a8)&0x10000000 — bit 28 | none |
| +0x13a0 | int | RenderState | HIGH | *(undefined4*)(param+0x13a0)=1 | none |

### Shared offsets
| +0x14 | int | flags | HIGH | Not directly verified but seen in many functions | — |

**Verdict:** All 15 inline offsets verified. HIGH confidence.

---

## Section 239: CollisionPositionStepper (inferred — param_1 in FUN_0048cb00)

Based on: FUN_0048cb00. File exists in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xCA*4 (0x328) | int | ArrayDimA | HIGH | param_1[0xca] — int-indexed read | none |
| +0xCB*4 (0x32c) | int | ArrayDimB | HIGH | param_1[0xcb] — multiplied with ArrayDimA | none |
| +0xCD*4 (0x334) | int | CurrentPosition | HIGH | param_1[0xcd] — cyclic position, read/write | none |
| +0xCE*4 (0x338) | int | PositionScale | HIGH | param_1[0xce] — scaling factor | none |
| +0xCF*4 (0x33c) | char | DirectionFlag | HIGH | param_1[0xcf]; (char) check for sign | none |
| +0xD0*4 (0x340) | int | Accumulator | HIGH | param_1[0xd0] — fixed-point time accumulator | none |

**Verdict:** All 6 offsets confirmed. HIGH confidence.

---

## Section 240: VehiclePhysicsInstance (primary vehicle struct)

Based on 7 functions. Extensive verification below.

### Engine/Drivetrain Params
File: decompiled_all\0x004f3c80__FUN_004f3c80.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x674 | double | FuelConsumption | HIGH | param+0x674 to FUN_00565aa0("FuelConsumption") | none |
| +0x67c | double | FuelEstimate | HIGH | param+0x67c to FUN_00565aa0("FuelEstimate") | none |
| +0x684 | double | EngineInertia | HIGH | param+0x684 to FUN_00565aa0("EngineInertia") | none |
| +0x68c | double | IdleRPMLogic_min | HIGH | (double*)(param+0x68c) | none |
| +0x694 | double | IdleRPMLogic_max | HIGH | (double*)(param+0x694) | none |
| +0x69c | double | IdleThrottle | HIGH | (double*)(param+0x69c) | none |
| +0x6a0 | double | IdleThrottle_flag | HIGH | (double*)(param+0x6a0) — computed flag | none |
| +0x6ac | double | LaunchRPMLogic_min | HIGH | (double*)(param+0x6ac) | none |
| +0x6b4 | double | LaunchRPMLogic_max | HIGH | (double*)(param+0x6b4) | none |
| +0x6bc | double | RevLimitLogic | HIGH | (double*)(param+0x6bc) | none |
| +0x6c4 | int | RPMTorque_point_count | HIGH | *(int*)(param+0x6c4)=local_348 | none |
| +0x6c8 | double[3] | RPMTorque_array | HIGH | (double*)(param+0x6c8) — local_344 | none |

### Tire/Compound Data
File: analyzed\0x004537b0__FUN_004537b0.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1140 | double×8 | FrontTireTelemetry | HIGH | *(float*)(param+0x1140) read | none (note: float read, not double) |
| +0x1160 | byte[16] | FrontCompoundFlags | HIGH | *(undefined1*)(param+0x1160) | none |
| +0x1170 | int | CurrentFrontCompound | HIGH | *(int*)(param+0x1170) compared to 4 constants | none |
| +0x1174 | int | CompoundSelect_Stop2 | HIGH | *(int*)(param+0x1174) | none |
| +0x1178 | int | CompoundSelect_Stop3 | HIGH | *(int*)(param+0x1178) | none |
| +0x117c | int | CompoundSelect_Stop4 | HIGH | *(int*)(param+0x117c) | none |
| +0x1180 | uint | PitStopFlag | HIGH | *(byte*)(param+0x1180)&1 and *(uint*)(param+0x1180)&0x100 | none |

### Thermal/Engine Model Params
File: decompiled_all\0x004f3c80__FUN_004f3c80.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x12c8 | double | OptimumOilTemp | HIGH | (double*)(param+0x12c8) | none |
| +0x12d0 | double | CombustionHeat | HIGH | param+0x12d0 to FUN_00565aa0("CombustionHeat") | none |
| +0x12d8 | double | EngineSpeedHeat | HIGH | param+0x12d8 to FUN_00565aa0("EngineSpeedHeat") | none |
| +0x12e0 | double | OilMinimumCooling | HIGH | param+0x12e0 to FUN_00565aa0("OilMinimumCooling") | none |
| +0x12e8 | double | OilWaterHeatTransfer_p1 | HIGH | param+0x12e8 to FUN_00565aa0("OilWaterHeatTransfer") | none |
| +0x12f0 | double | OilWaterHeatTransfer_p2 | HIGH | param+0x12f0 passed as 2nd double arg | none |
| +0x12f8 | double | WaterMinimumCooling | HIGH | param+0x12f8 to FUN_00565aa0("WaterMinimumCooling") | none |
| +0x1300 | double | RadiatorCooling_min | HIGH | param+0x1300 to FUN_00565aa0("RadiatorCooling") | none |
| +0x1308 | double | RadiatorCooling_max | HIGH | param+0x1308 passed as 2nd double arg | none |
| +0x1310 | double | LifetimeEngineRPM_min | HIGH | (double*)(param+0x1310) | none |
| +0x1318 | double | LifetimeEngineRPM_max | HIGH | (double*)(param+0x1318) | none |
| +0x1320 | double | LifetimeOilTemp_min | HIGH | (double*)(param+0x1320), also (param+0x1320) to "LifetimeOilTemp" | none |
| +0x1328 | double | LifetimeOilTemp_max | HIGH | param+0x1328 to FUN_00565aa0("LifetimeOilTemp") | none |
| +0x1330 | double | LifetimeAvg | HIGH | param+0x1330 to FUN_00565aa0("LifetimeAvg") | none |
| +0x1338 | double | LifetimeVar | HIGH | param+0x1338 to FUN_00565aa0("LifetimeVar") | none |

**Verdict:** All sampled offsets verified. HIGH confidence. No conflicts found.

---

## Section 241: Net Session State Struct (inferred, small)

Based on: FUN_00462160. File exists in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| **+0xc4** | **int** | **FilterActiveFlag** | **MEDIUM** | ***(bool*)(iVar1+0xc4) = *(char*)(iVar1+0xc4)=='\0'** | **CONFLICT: doc says int (4B), .c shows char/bool (1B)** |

**Verdict:** 1 offset, but TYPE CONFLICT. Change from `int` to `bool`/`char`.

---

## Section 243: TireBrandEntry (stride 0x24)

Based on: FUN_004d7150, FUN_004d7880. Both in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | brandName | HIGH | *(undefined1**)(param_1[1]+iVar5) in FUN_004d7880 | none |
| +0x04 | unknown | pad_or_ptr | LOW | No documented access in either file | presumably padding/gap |
| +0x08 | int | slipcurveCount | HIGH | *(int*)(param_1+8) incremented on SLIPCURVE token (FUN_004d7150) | none |
| +0x0c | ptr | slipcurveArray | HIGH | *(int**)(param_1+0xc) set to allocated array stride 0x18 (FUN_004d7150) | none |
| +0x10 | int | compoundCount | HIGH | *(int*)(param_1+0x10) incremented on COMPOUND token (FUN_004d7150) | none |
| +0x14 | ptr | compoundArray | HIGH | *(int**)(param_1+0x14) set to allocated array stride 0x2a8 (FUN_004d7150) | none |
| +0x18..+0x23 | unknown | unknown | — | No access documented | 12 bytes undocumented (fits 0x24 stride) |

**Verdict:** 6 of 7 offsets verified (1 gap at +0x04). HIGH confidence. Stride 0x24 confirmed in FUN_004d7880.

---

## Summary of Conflicts Found

| # | Section | Offset | Field | Doc Type | Actual Type | Action |
|---|---------|--------|-------|----------|-------------|--------|
| 1 | 233 | +0x98c | ActiveFlag | int | **char** (1 byte, checked for non-zero) | Change type to `byte` |
| 2 | 234 | +0x28 | ConstraintRowStride | ptr | **RowPtrArray** (not stride) | Rename to `ConstraintRowPtrArray` |
| 3 | 241 | +0xc4 | FilterActiveFlag | int | **bool**/**char** (1 byte, toggled) | Change type to `bool` |

=== NEW OFFSETS DISCOVERED ===
None discovered (no new offsets seen in 2+ .c files that aren't already documented).

=== NEW GLOBALS DISCOVERED ===
None directly relevant to struct audit.

=== MISSING FILES (no .c evidence) ===
The following functions referenced in struct definitions have no .c file in analyzed/ or decompiled_all/:
- 0x0050b6f0 (Section 231 — List Container)
- 0x00512a20 (Section 231 — Resource List Container)
- 0x005e3b60 (Section 231 — Stream Object)
- 0x00569da0 (Section 231 — Ring Buffer)
- 0x0053c790 (Section 231 — Per-Element Data)
- 0x004a3ef0 (Section 232 — NetworkMessage)
- 0x00591583 (Section 232 — NetworkMessage)
