# WORKER Q — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker Q of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_Q.md

## YOUR STRUCT SECTIONS (14)

--- Section 230: SpriteOverlayList (param_1 — display list) (6 offsets) ---
## SpriteOverlayList (param_1 — display list)

Based on FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480. Confidence: **high**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x6c0 | ptr | ListHead | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | Linked list head |
| +0x6c4 | ptr | ListTail | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | |
| +0x6c8 | ptr | ListCursor | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | |
| +0x6cc | int | ListCount | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480 | |
| +0x6d0 | byte | DirtyFlag/CleanupFlag | FUN_004b81a0, FUN_004b8360, FUN_004b8480 | |
| +0xf38 | float | ScoreValue/Threshold | FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360 | Sort key |

---



--- Section 231: Single-Function Struct Observations (37 offsets) ---
## Single-Function Struct Observations

These ~163 observations represent unique struct layouts used by a single function each. 
Listed below by functional category.

### Linked List Controller (param_1)

**FUN_00407c90 — List Controller:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x18 | Head | int32* | Linked list head |
| +0x1c | Tail | int32* | Linked list tail |
| +0x20 | Current | int32* | Current iterator |
| +0x24 | Count | int32 | Number of nodes |

**FUN_0050b6f0 — List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Head | int32* | First node |
| +0x04 | NodeCount | int32 | Total node count |

**FUN_00512a20 — Resource List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x08 | Head | int32* | List head |
| +0x0c | TailOrCount | int32* | Tail or count |
| +0x10 | NodeCount | int32 | Number of nodes |
| +0x14 | DataPtr | void* | Associated data |
| +0x18 | AllocFunc | func* | Allocation function |
| +0x1c | FreeFunc | func* | Deallocation function |

**FUN_00565f20 — List Container:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | HeadPtr | int* | Current list head |
| *(headPtr)+0x08 | NextPtr | int* | Next entry in list |

### Stream Object (param_1)

**FUN_005e3b60:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | StreamPtr | byte* | Data stream pointer |
| +0x04 | StreamEnd | byte* | End of stream marker |

### Ring Buffer (param_1)

**FUN_00569da0:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | Buffer | byte* | Data buffer |
| +0x04 | Capacity | int | Max capacity |
| +0x08 | HeadIdx | int | Write index |
| +0x0c | TailIdx | int | Read index |
| +0x10 | WrapFlag | int | Overflow flag |
| +0x14 | ElementSize | int | Per-element size |

### Processing State Machine (param_1)

**FUN_00404460 — Multi-Phase Processing:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x130 | Cap | int32 | Max iteration count per phase |
| +0x16c | Phase | int32 | 0, 1, 2 — state machine |
| +0x170 | FloatVal | float | Computed threshold value |
| +0x174 | IterIdx | int32 | Current iteration index |

### Per-Element Struct (param_1 — per element)

**FUN_0053c790 — Per-Element Data:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | OwnerPtr | void* | Container pointer |
| +0x04 | Index | int | Element index |
| +0x14 | Val1 | float | First float value |
| +0x18 | Val2 | float | Second float value |
| +0x1c | Flag1 | int | Flag |
| +0x20 | Val3 | float | Third float value |
| +0x24 | Dim | byte | Dimension/count |

### FILE* Stream (MSVC CRT)

**FUN_00587d33 — FILE struct internals:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x0c | _flag | int | CRT FILE flag field |
| +0x10 | _file | int | OS file descriptor |
| +0x1c | _tmpfname | char* | Temporary filename |

### VTable Object Header

**FUN_00408520 — VTable Swap:**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | vtable | pointer | Initial→final vtable swap |
| +0x10–+0x30 | SubObj[4..12] | pointer[] | 9 sub-object slots |

---



--- Section 232: 17. NetworkMessage (inferred) (7 offsets) ---
## 17. NetworkMessage (inferred)

Network message/packet struct with event code and string buffer.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x5C4 | uint | EventCode | FUN_004a3ef0 |  |
| +0x5C8 | char[] | StringBuffer | FUN_004a3ef0 |  |
| +0x618 | HANDLE | BufferMutex | FUN_004a3ef0 |  |
| +0x910 | uint16 | HeaderField | FUN_00591583 |  |
| +0xAC8 | ptr | ListBase | FUN_00591583 |  |
| +0xAD8 | HANDLE | ListMutex | FUN_00591583 |  |
| +0xADC | DWORD | MutexTimeout | FUN_00591583 |  |



--- Section 233: PhysicsInteractionState (steering/force feedback) (11 offsets) ---
## PhysicsInteractionState (steering/force feedback)

From FUN_004e2760. Confidence: low.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x108 | int[4] | WheelIndices | Stride 0x4a (74 bytes) |
| +0x938 | int | PackedWheelData | Base-256 packed |
| +0x93c | short | PackedShort | Base-16 packed |
| +0x93e | byte | PackedByte | Base-8/base-4 packed |
| +0x93f | byte | ChannelMask | Active channel bitmask |
| +0x940 | int | ChannelBitfield | Active channels |
| +0x944 | short | ChannelOut0 | 16-bit output channel 0 |
| +0x946 | short | ChannelOut1 | 16-bit output channel 1 |
| +0x948 | short | ChannelOut2 | 16-bit output channel 2 |
| +0x98c | int | ActiveFlag | Zero = clear all outputs |
| +0x9a8 | float[] | AnalogChannels | Up to 17 channels, stride 7 floats |

---



--- Section 234: PhysicsSystemHeader (inferred) (12 offsets) ---
## PhysicsSystemHeader (inferred)

Based on 1 function observation (FUN_0056d930). Confidence: high.

Top-level physics system/joint struct managed by solver. Contains counts and arrays for bodies, joints, hinges, bars.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | BodyCount | FUN_0056d930 | |
| +0x04 | (ptr) | BodyArray | FUN_0056d930 | Stride 0x244 |
| +0x08 | int | JointCount | FUN_0056d930 | |
| +0x0c | (ptr) | JointArray | FUN_0056d930 | Stride 0x30 |
| +0x10 | int | HingeCount | FUN_0056d930 | |
| +0x14 | (ptr) | HingeArray | FUN_0056d930 | Stride 0x30 |
| +0x18 | int | BarCount | FUN_0056d930 | |
| +0x1c | (ptr) | BarArray | FUN_0056d930 | Stride 0x48 |
| +0x20 | int | ConstraintCount | FUN_0056d930 | |
| +0x24 | (ptr) | ConstraintMatrix | FUN_0056d930 | |
| +0x28 | (ptr) | ConstraintRowStride | FUN_0056d930 | |
| +0x2c | (ptr) | SolverObject | FUN_0056d930 | |

---



--- Section 235: Source: docs/08-file-formats.md (0 offsets) ---
## Source: docs/08-file-formats.md

Source: docs/08-file-formats.md (279 entries, ~204 offset observations)

---



--- Section 236: File State / Mode Flags Struct (3 offsets) ---
## File State / Mode Flags Struct

Based on 2 function observations (FUN_00587f90, FUN_0059c156). Confidence: high — consistent offsets.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x0c | uint | ModeFlags | FUN_00587f90, FUN_0059c156 | bitmask: 0x1=read, 0x2=write, 0x80=EOF |
| +0x10 | int/void* | FileHandle/Buffer | FUN_00587f90, FUN_0059c156 | file handle or buffer pointer |
| +0x18 | uint | BufferSize | FUN_00587f90, FUN_0059c156 | I/O buffer size (0x200) |

---



--- Section 237: D3D Render State Cache (inferred) (5 offsets) ---
## D3D Render State Cache (inferred)

Used by FUN_00586700. Stores per-D3DRS cached values for incremental
state updates.

Based on 1 function observation. Confidence: high.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x34 | int | D3DRS_1_Value | FUN_00586700 | Render state value for D3DRS 1 |
| +0x38 | int | D3DRS_8_Value | FUN_00586700 | Render state value for D3DRS 8 |
| +0x3c | int | D3DRS_1b_Value | FUN_00586700 | Render state D3DRS 0x1b |
| +0x40 | int | D3DRS_2_Value | FUN_00586700 | Render state value for D3DRS 2 |
| +0x44 | int | D3DRS_10_Value | FUN_00586700 | Render state D3DRS 0x10 |



--- Section 238: Inline offset references (not in tables) (16 offsets) ---
## Inline offset references (not in tables)

These offsets appear in function descriptions but not in structured tables.

### FUN_004c71c0 — SetupCarLightingAndRender
| +0x83c | float[3]×4 | WheelPositions | stride 0x128 between wheels |
| +0x704 | float[16] | ViewMatrix | |
| +0x744 | float[16] | WorldMatrix | |
| +0x34f8 | float[4] | DiffuseColor | |
| +0x3510 | float[4] | SpecularColor | |
| +0x3540 | int | EnvMapHandle | |

### FUN_0053f270 — RenderTargetCleanup
| +0x1140 | ptr | FrontBuffer | |
| +0x113c | ptr | BackBuffer | |
| +0x1144 | ptr | DepthStencil | |
| +0x14f0..0x1504 | int[5] | ViewportDims | |
| +0x1518 | ptr | TextureList | Linked list |
| +0x1580 | ptr | RenderTargetList | |
| +0x13a8 | int | CleanupFlag | Bit 28 |
| +0x13a0 | int | RenderState | Set to 1 |

### FUN_003f270 / FUN_003ead0 shared
| +0x152c | ptr | ExtraTexture | |

### Inline from many functions
| +0x14 | int | flags | 0x800000(clip), 0x8000000(alpha), 0x4000(visible), etc. |



--- Section 239: CollisionPositionStepper (inferred — param_1 in FUN_0048cb00) (6 offsets) ---
## CollisionPositionStepper (inferred — param_1 in FUN_0048cb00)

Based on FUN_0048cb00. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0xCA*4 | int | ArrayDimA | Array dimension A |
| +0xCB*4 | int | ArrayDimB | Array dimension B |
| +0xCD*4 | int | CurrentPosition | Cyclic position index |
| +0xCE*4 | int | PositionScale | Position scaling factor |
| +0xCF*4 | char | DirectionFlag | Direction sign (0 = negate) |
| +0xD0*4 | int | Accumulator | Fixed-point time accumulator |

Note: Offsets are int-indexed (multiply by 4 for byte offset).

---



--- Section 240: VehiclePhysicsInstance (primary vehicle struct) (62 offsets) ---
## VehiclePhysicsInstance (primary vehicle struct)

Based on 7 function observations. Confidence: **high**.

This is the main per-vehicle physics instance struct (~0x48C0 bytes). Observed as `param_1` in engine parser (FUN_004f3c80), session init (FUN_0043c250), engine stress sim (FUN_0043ef20), fuel/wear (FUN_004ed960), tire compound broadcast (FUN_004537b0/54350), and engine physics updater (FUN_004e6d93).

### Engine/Drivetrain Params (loaded from .svm ENGINE section)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x674 | double | FuelConsumption | FUN_004f3c80 | raw from .svm |
| +0x67c | double | FuelEstimate | FUN_004f3c80 | raw from .svm |
| +0x684 | double | EngineInertia | FUN_004f3c80 | raw from .svm |
| +0x68c | double | IdleRPMLogic_min | FUN_004f3c80 | × RPM_TO_RAD (DAT_005ad258) |
| +0x694 | double | IdleRPMLogic_max | FUN_004f3c80 | × RPM_TO_RAD |
| +0x69c | double | IdleThrottle | FUN_004f3c80 | range-checked → flag at +0x6a0 |
| +0x6a0 | double | IdleThrottle_flag | FUN_004f3c80 | computed (0 or 1.0) |
| +0x6ac | double | LaunchRPMLogic_min | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6b4 | double | LaunchRPMLogic_max | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6bc | double | RevLimitLogic | FUN_004f3c80 | × RPM_TO_RAD |
| +0x6c4 | int | RPMTorque_point_count | FUN_004f3c80 | max 126 |
| +0x6c8 | double[3] | RPMTorque_array | FUN_004f3c80 | each 3 doubles: rpm, torque_throttle, torque_brake; rpm × RPM_TO_RAD |

### Tire/Compound Data

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1140–+0x115c | double×8 | FrontTireTelemetry | FUN_004537b0, FUN_00454350 | contiguous 8 doubles |
| +0x1160 | byte[16] | FrontCompoundFlags | FUN_004537b0, FUN_00454350 | compound/state flag array |
| +0x1170 | int | CurrentFrontCompound | FUN_004537b0 | index compared to 4 constants |
| +0x1174 | int | CompoundSelect_Stop2 | FUN_004537b0 | compound selection for pitstop 2 |
| +0x1178 | int | CompoundSelect_Stop3 | FUN_004537b0 | |
| +0x117c | int | CompoundSelect_Stop4 | FUN_004537b0 | |
| +0x1180 | uint | PitStopFlag | FUN_004537b0 | bitmask: bit0=stop1 valid, 0x100=stop2, 0x200=stop3, 0x400=stop4 |
| +0x153c–+0x1558 | double×8 | RearTireTelemetry | FUN_004537b0, FUN_00454350 | contiguous 8 doubles |
| +0x155c | byte[16] | RearCompoundFlags | FUN_004537b0 | compound/state flag array |

### Thermal/Engine Model Params (loaded from .svm ENGINE section)

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x12c8 | double | OptimumOilTemp | FUN_004f3c80 | + 273.15 K offset (DAT_0059eac8) |
| +0x12d0 | double | CombustionHeat | FUN_004f3c80 | raw |
| +0x12d8 | double | EngineSpeedHeat | FUN_004f3c80 | raw |
| +0x12e0 | double | OilMinimumCooling | FUN_004f3c80 | raw |
| +0x12e8 | double | OilWaterHeatTransfer_p1 | FUN_004f3c80 | raw |
| +0x12f0 | double | OilWaterHeatTransfer_p2 | FUN_004f3c80 | raw |
| +0x12f8 | double | WaterMinimumCooling | FUN_004f3c80 | raw |
| +0x1300 | double | RadiatorCooling_min | FUN_004f3c80 | raw |
| +0x1308 | double | RadiatorCooling_max | FUN_004f3c80 | raw |
| +0x1310 | double | LifetimeEngineRPM_min | FUN_004f3c80, FUN_0043c250 | × RPM_TO_RAD at load; stored raw at +0x1dbc in runtime |
| +0x1318 | double | LifetimeEngineRPM_max | FUN_004f3c80, FUN_0043c250 | × RPM_TO_RAD at load; 1/max stored at +0x1dc4 in runtime |
| +0x1320 | double | LifetimeOilTemp_min | FUN_004f3c80, FUN_0043c250 | + 273.15 K at load; stored at +0x1dcc in runtime |
| +0x1328 | double | LifetimeOilTemp_max | FUN_004f3c80, FUN_0043c250 | **type conflict**: FUN_004f3c80 says raw (no offset), FUN_0043c250 stores 1/max at +0x1dd4 |
| +0x1330 | double | LifetimeAvg | FUN_004f3c80, FUN_004e6d93, FUN_0043c250, FUN_0043bc20 | raw from .svm; used in lifetime formula |
| +0x1338 | double | LifetimeVar | FUN_004f3c80, FUN_004e6d93, FUN_0043c250, FUN_0043bc20 | raw from .svm; us
[...3094 chars truncated]

--- Section 241: 15. Net Session State Struct (inferred, small) (1 offsets) ---
## 15. Net Session State Struct (inferred, small)

Based on observations from FUN_00462160. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xc4 | int | FilterActiveFlag | FUN_00462160 | Sort/filter active flag, toggle by param_3 |

---



--- Section 242: Summary (0 offsets) ---
## Summary

| # | Struct Name | Estimated Size | Functions | Observations |
|---|-------------|---------------|-----------|-------------|
| 1 | NetworkManagerStruct | ~0xbf8 (3064) | 10+ | 50+ |
| 2 | AudioHandleStruct | ~0x870 | 5 | 10 |
| 3 | AudioStreamStruct | ~0x24d4+ | 2 | 5 |
| 4 | AudioChannelInitStruct | ~0xff6+ | 2 | 16 |
| 5 | NetworkSessionState | ~0x98 | 1 | 5 |
| 6 | PacketQueueStruct | ~0x18 | 1 | 5 |
| 7 | AudioSampleRingBuffer | ~0x102c | 1 | 2 |
| 8 | DynamicStackStruct | ~0x0c | 1 | 3 |
| 9 | AudioMixerValueStruct | ~0x80 | 1 | 3 |
| 10 | AudioResourceStruct | ~0x868 | 1 | 4 |
| 11 | AudioArrayContainer | ~0x08 | 1 | 2 |
| 12 | AllocStruct18 | 0x18 | 1 | 6 |
| 13 | StreamEventDecompressor | ~0xea | 1 | 7 |
| 14 | AudioConfigFlagsStruct | ~0x08 | 1 | 1 |
| 15 | StreamBufferReadStruct | ~0x78+ | 1 | 4+1 conflict |
| 16 | MessageSlotStruct | ~0x18 | 1 | 4 |
| 17 | AudioStreamInitStruct | ~0x2c | 1 | 5 |
| 18 | VehicleSoundStruct | ~0x3668+ | 1 | 6 |
| 19 | VehicleEngineSoundStruct | ~0x39a4+ | 1 | 2 |
| 20 | AudioBufferFormatStruct | ~0x11a | 1 | 6 |
| 21 | AudioWaveTableStruct | ~0x68 | 1 | 1 |

**Flags for docs/13 integration:**
- NetworkManagerStruct is the most cross-referenced — strong candidate for a canonical definition
- VehicleSoundStruct offsets (0x7a4, 0x32bc, 0x34ec, 0x3668) may overlap with vehicle physics struct — verify against docs/10-vehicle-physics.md
- AudioHandleStruct +0x58 pattern matches Miles Sound System wrapper idiom
- AudioStreamStruct offsets (0x24xx range) are in a different region vs other audio structs — likely a separate large codec struct

---



--- Section 243: Struct 3: TireBrandEntry (stride 0x24) (7 offsets) ---
## Struct 3: TireBrandEntry (stride 0x24)

Based on 2 function observations (FUN_004d7150, FUN_004d7880).
Confidence: **medium** — two functions access this struct; stride confirmed.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | char* | brandName | FUN_004d7880 (inferred) | name pointer, searched by linear comparison |
| +0x04 | unknown | pad_or_ptr | — | 4 bytes gap, no documented access |
| +0x08 | int | slipcurveCount | FUN_004d7150 | number of slip curves for this brand |
| +0x0c | ptr | slipcurveArray | FUN_004d7150 | array of SlipCurveEntry (stride 0x18) |
| +0x10 | int | compoundCount | FUN_004d7150 | number of tire compounds for this brand |
| +0x14 | ptr | compoundArray | FUN_004d7150 | array of TireCompoundEntry (stride 0x2a8) |
| +0x18–+0x23 | unknown | unknown | — | 12 bytes undocumented (rest of 0x24 stride) |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_Q.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
