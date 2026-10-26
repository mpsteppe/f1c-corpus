# WORKER P — F1C Struct Confidence Audit

You are auditing struct field definitions in docs/13-struct-offsets.md against
actual Ghidra decompilation source files.
Worker P of 20.

## STEP 1 — LOAD REFERENCES
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md` — audit target
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md` — named globals
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\analyzed\` — source .c files

## OUTPUT FILE
Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_P.md

## YOUR STRUCT SECTIONS (14)

--- Section 216: Session/Rankings ScoringGate (9 offsets) ---
## Session/Rankings ScoringGate

Based on FUN_00411440. Confidence: **medium**.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x48 | int | EntryCount | FUN_00411440 | Race entries |
| +0x4c | ptr | EntryRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x50 | byte[] | EntryArray | FUN_00411440 | Stride 0xca |
| +0x54 | int | QualiCount | FUN_00411440 | |
| +0x58 | ptr | QualiRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x5c | byte[] | QualiArray | FUN_00411440 | Stride 0xc6 |
| +0x60 | int | PracticeCount | FUN_00411440 | |
| +0x64 | ptr | PracticeRosterPtr | FUN_00411440 | Stride 0x24 |
| +0x68 | byte[] | PracticeArray | FUN_00411440 | Stride 0xc6 |

---



--- Section 217: Multi-Function Struct Groups (Cross-Function Confirmation) (47 offsets) ---
## Multi-Function Struct Groups (Cross-Function Confirmation)

These structs have 2+ functions confirming the same offset layout, providing higher confidence.

### Buffer Descriptor (param_2 / param_1)

Functions: FUN_0052a5d7, FUN_005698e0, FUN_0058d78e
Confidence: medium (offset ranges differ — may be different buffer types)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | CurrentPtr | int32* | Current write position in buffer | FUN_0058d78e |
| +0x04 | RemainingCount | int32 | Bytes left before flush needed | FUN_0058d78e |
| +0x18 | MatrixA | float[12] | 3x4 matrix (via FUN_0056c3a0) | FUN_005698e0 |
| +0x28 | BufferStart | ? | Start of buffer (wrap target) | FUN_0052a5d7 |
| +0x2c | BufferEnd | ? | End of buffer (wrap limit) | FUN_0052a5d7 |
| +0x30 | ReadPtr | ? | Current read position | FUN_0052a5d7 |
| +0x34 | EndPtr | ? | Buffer end pointer | FUN_0052a5d7 |
| +0x38 | Callback | ? | Optional callback function | FUN_0052a5d7 |
| +0x3c | CallbackCtx | ? | Callback context | FUN_0052a5d7 |
| +0x78 | ExtraInt1 | int | Written from param_5 | FUN_005698e0 |
| +0x7c | ExtraInt2 | int | Written from param_3 | FUN_005698e0 |
| +0x80 | ExtraByte | byte | Written from param_4 | FUN_005698e0 |

### Simple Buffer Descriptor (param_2)

Functions: FUN_0052a5d7, FUN_0058d78e
Confidence: medium (partial overlap)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | CurrentPtr | int32* | Write position | FUN_0058d78e |
| +0x04 | RemainingCount | int32 | Bytes remaining | FUN_0058d78e |
| +0x28 | BufferStart | ? | Wrap target | FUN_0052a5d7 |
| +0x2c | BufferEnd | ? | Wrap limit | FUN_0052a5d7 |
| +0x30 | ReadPtr | ? | Read position | FUN_0052a5d7 |
| +0x34 | EndPtr | ? | Buffer end | FUN_0052a5d7 |
| +0x38 | Callback | ? | Optional callback | FUN_0052a5d7 |
| +0x3c | CallbackCtx | ? | Callback context | FUN_0052a5d7 |

### Timer/Performance State Struct (param_1)

Functions: FUN_00568be0, FUN_00569da0
Confidence: high (identical offset layout)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | FrequencyLowPart | uint | QPC frequency low DWORD | FUN_00568be0 |
| +0x08 | InvFrequencyScaled | double | scaling_constant / freq | FUN_00568be0 |
| +0x10–+0x14 | AccLow/AccHigh | uint | Zeroed accumulators | FUN_00568be0 |
| +0x18–+0x1c | CounterLow/CounterHigh | uint | QPC init sample | FUN_00568be0 |
| +0x20–+0x24 | LastSampleLow/High | uint | Copy of init sample | FUN_00568be0 |
| +0x28–+0x2c | Acc/Overflow | uint | Zeroed | FUN_00568be0 |
| +0x48 | Mode | uint | Timer mode flags | FUN_00568be0 |
| +0x00 | StartTime | double | QPC start time | FUN_00569da0 |
| +0x08 | Frequency | double | QPC frequency | FUN_00569da0 |
| +0x10 | ElapsedS | double | Elapsed seconds | FUN_00569da0 |
| +0x18 | ElapsedMS | double | Elapsed ms | FUN_00569da0 |

### Dynamic Array Container (param_1)

Functions: FUN_00457cf0, FUN_004bd900
Confidence: medium (different field layouts)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x0c | Capacity | ? | Current capacity (elements) | FUN_004bd900 |
| +0x10 | Count | ? | Current element count | FUN_004bd900 |
| +0x14 | Data | ? | Array data pointer | FUN_004bd900 |
| [0] (+0x00) | HeapPtr | int* | Heap pointer, freed via FUN_00587bcf | FUN_00457cf0 |
| [1]–[6] (+0x04–+0x18) | DataFields | int | Zeroed unconditionally | FUN_00457cf0 |

### Linked List Node Layout

Functions: FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005bf450, FUN_005e3b60
Confidence: high (consistent pattern)

| Offset | Field | Type | Notes | Observed in |
|--------|-------|------|-------|-------------|
| +0x00 | Key / ID | int32 | Match key or pointer | FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005e3b60 |
| +0x04 | NextPtr | int32* | Next node in list | FUN_00407c90, FUN_0050b6f0, FUN_00512a20, FUN_005e3b60 |
| +0x08 | Flags/Data
[...1367 chars truncated]

--- Section 218: 16. InputDevice (inferred) (4 offsets) ---
## 16. InputDevice (inferred)

Input device binding struct and controller array.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x13E8 | int | BindingValueA | FUN_0040be70 | Read when state 0x10 |
| +0x13EC | int | InputDeviceHandle | FUN_0040be70 | Handle/ptr |
| +0x1544 | int | ControlID | FUN_0040be70 sibling |  |
| +0x1f98 | ptr | ControllerArray | FUN_00455da0 | Stride 0xb, max 0x21 entries |



--- Section 219: VehicleGearShiftStruct (9 offsets) ---
## VehicleGearShiftStruct

From FUN_00426330. Confidence: medium.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x37cc | float | LeftWheelSpeed | Left wheel speed |
| +0x38c4 | float | RightWheelSpeed | Right wheel speed |
| +0x39a0 | float | EngineRPM | Engine RPM |
| +0x39fc | int | ShiftTimer | Gear shift state / timer |
| +0x3a04 | int | NextGearThreshold | Next gear shift threshold |
| +0x3a10 | float | EngineSpeed | Engine speed (vs zero threshold) |
| +0x3a18 | float | RPMShiftThreshold | RPM shift threshold |
| +0x3d6c | int | DrivingMode | Driving mode (2=specifiic) |
| +0x4510 | int | CurrentGear | Current gear (6=highest) |

---



--- Section 220: PhysicsBody (inferred) (6 offsets) ---
## PhysicsBody (inferred)

Based on 1 function observation (FUN_00439210). Confidence: medium.

Rigid body struct referenced by pointers in VehiclePhysicsHeader (at +0x1d4, +0x15f0, +0x141c).

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | unknown | (vtable/type) | FUN_00439210 | |
| +0x04 | double[3] | Position | FUN_00439210 | x, y, z world position |
| +0x1c | double[3×3] | OrientationMatrix | FUN_00439210 | 3×3 rotation matrix (9 doubles, 0x1c-0x5c) |
| +0xac | double | Mass | FUN_00439210 | Body mass |
| +0xb4 | double | InvMass | FUN_00439210 | 1.0 / mass |
| +0xbc | double[3] | InertiaDiagonal | FUN_00439210 | Principal inertia terms |

---



--- Section 221: Conflicting Offset Observations (5 offsets) ---
## Conflicting Offset Observations

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x1d4 | (ptr) FuelTankBodyPtr vs low offset | FUN_00439210 (+0x1d4 as ptr), FUN_00439210 also +0x1d4 listed | Same struct — low absolute offset relative to vehicle base, consistent as pointer field |
| +0x15c4 | SteeringBarCount vs EngineMapSetting | FUN_00439210 (bar count), FUN_0042fd00 (engine map) | Likely different struct regions or same field repurposed. Majority: FUN_00439210 more authoritative for physics layout |
| +0x1884 | GearCount vs NumPitstopsSetting | FUN_0042f470 (gear count), FUN_0042fd00 (pitstops) | Same offset, different usage context. May be union or function-specific interpretation |
| +0x3d64 | EngineFailureTime[4] vs TireWearAccumulator | FUN_004ee150 (4 floats for engine failure), FUN_004efae0 (single float tire wear) | Different structs or union. Engine failure uses param_2, tire wear uses param_1 directly |
| +0x1db4 | double vs docs/13 EffectiveLifetime | docs/13 (double) | Consistent |

---



--- Section 222: File Buffer State Struct (2 offsets) ---
## File Buffer State Struct

Based on 2 function observations (FUN_00587ca0, FUN_00589898). Confidence: high — identical offsets in both functions.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | byte* | buffer_ptr | FUN_00587ca0, FUN_00589898 | current read/write position |
| +0x04 | int | remaining | FUN_00587ca0, FUN_00589898 | remaining bytes in buffer |

---



--- Section 223: Texture/Surface Format Struct (inferred) (22 offsets) ---
## Texture/Surface Format Struct (inferred)

Used by FUN_0050ab51, FUN_00518248, FUN_00586d70, FUN_00558d80,
FUN_00558d10, FUN_00558dc0. Holds surface dimensions, pitch, pixel format,
and buffer pointers.

Based on 6+ function observations. Confidence: medium.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | width | FUN_00518248, FUN_00552f20 | Surface width (updated on stretch) |
| +0x04 | int | height | FUN_00552f20 | Surface height |
| +0x0b | byte | bpp | FUN_00518248 | Bits per pixel (1/2/4/8+) |
| +0x14 | ptr | bitmapData | FUN_00586d70 | Raw bitmap data ptr |
| +0x1c | ptr | bitmapHeader | FUN_00586d70 | Bitmap header struct |
| +0x20 | int | flags | FUN_00558d80, FUN_00558dc0 | Bit 0x100 = locked, sign bit for render mode |
| +0x34 | ptr | rowLookup | FUN_00558dc0 | Row lookup table |
| +0x38 | int | regionStride | FUN_00586d70 | Scan offset into bitmap |
| +0x4c | int | renderMode | FUN_00558dc0 | Render mode flag (gated: ==1) |
| +0x50 | ptr | surfaceArray | FUN_00558d80, FUN_00558dc0 | Surface slot array base, pixel buffer |
| +0x1050 | int | yPitch | FUN_0050ab51, FUN_00503920 | Y plane pitch in bytes |
| +0x1054 | int | uvPitch | FUN_0050ab51 | UV plane pitch |
| +0x106c | ptr | outputBuffer | FUN_0050ab51 | Output float RGBA buffer |
| +0x1070 | int | outputStride | FUN_0050ab51 | Output stride in pixels |
| +0x1074 | int | dirtyLeft | FUN_0050ab51 | Dirty rect left |
| +0x1078 | int | dirtyRight | FUN_0050ab51 | Dirty rect right |
| +0x107c | int | dirtyTop | FUN_0050ab51 | Dirty rect top |
| +0x1080 | int | dirtyBottom | FUN_0050ab51 | Dirty rect bottom |
| +0x1084 | int | width | FUN_0050ab51 | Surface width |
| +0x1090 | int | bufferReady | FUN_0050ab51 | Flag (non-zero = ready) |
| +0x1094 | int | bitDepth | FUN_0050ab51 | Bits per channel |
| +0x1098 | int | bitShift | FUN_0050ab51 | Bit shift amount |



--- Section 224: Texture/Blit Render Struct (inferred) (8 offsets) ---
## Texture/Blit Render Struct (inferred)

Used by FUN_0048E4B0. Stores path strings, render enable flag,
dirty flag, and rect dimensions.

Based on 1 function observation. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0xb0 | ptr | pathStringA | FUN_0048E4B0 | Path string or null |
| +0xfc | ptr | pathStringB | FUN_0048E4B0 | Path string or null |
| +0xe4 | int | renderEnable | FUN_0048E4B0 | Non-zero enables render |
| +0xf8 | byte | dirtyFlag | FUN_0048E4B0 | Cleared after render |
| +0xe8 | int | rectX | FUN_0048E4B0 | Clear/render X |
| +0xec | int | rectY | FUN_0048E4B0 | Clear/render Y |
| +0xf0 | int | rectW | FUN_0048E4B0 | Clear/render W |
| +0xf4 | int | rectH | FUN_0048E4B0 | Clear/render H |

---



--- Section 225: SensorState (inferred — param_1 in FUN_00464a40) (3 offsets) ---
## SensorState (inferred — param_1 in FUN_00464a40)

Based on FUN_00464a40. Confidence: **low** (single function).

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x068 | int | SensorTimeout | Sensor timeout value |
| +0x06C | byte | SensorState | Sensor state flag |
| +0x071 | undefined4 | SensorValue | Sensor reading (float?) |

---



--- Section 226: Source: docs/03-engine-wear-damage.md (0 offsets) ---
## Source: docs/03-engine-wear-damage.md

Source: `docs/03-engine-wear-damage.md` (7 entries, 93+ offset observations)

---



--- Section 227: 14. UI Dialog Struct (inferred) (5 offsets) ---
## 14. UI Dialog Struct (inferred)

Based on observations from FUN_0046b0c0, FUN_00470300. Confidence: low.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x1fc | int | State | FUN_0046b0c0 | State machine (0=idle, 1=init, 2=await input, 3=confirm) |
| +0x200 | int | RawInputData | FUN_0046b0c0 | Raw input key/button data |
| +0x204 | int | InputType | FUN_0046b0c0 | Input device type |
| +0x2e8 | int | ResetField | FUN_00470300 | Reset counter/state |
| +0x304 | int | ControlID | FUN_00470300 | Dialog control ID |

Note: +0x1fc (500 in decimal) is documented as "500" in FUN_0046b0c0 for DeviceIndex — likely not a struct offset but an array index relative to param_1.

---



--- Section 228: Minor Structs (1 observation each) (21 offsets) ---
## Minor Structs (1 observation each)

### AudioStreamInitStruct (FUN_0057a3f0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x00 | int | Active | =1 |
| +0x04 | int | Field1 | =0 |
| +0x08 | uint16 | SampleRate | =0xd45 (3397 — sample rate/format ID) |
| +0x0a | uint16 | BufferSize | =0x1d8 (472) |
| +0x0c | int | Field3 | =0 |
| +0x10–0x2c | int[8] | Reserved | Zeroed |

### VehicleSoundStruct (FUN_004f12e0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x7a4 | float | SlipAngle | >0 triggers skid sounds |
| +0x32bc | int | SuspensionType | Engine/road noise selector |
| +0x34ec | float | WheelVelX | Wheel velocity component |
| +0x34f0 | float | WheelVelY | Wheel velocity component |
| +0x34f4 | float | WheelVelZ | Wheel velocity component |
| +0x3668 | void*[4] | WheelPtrs | 4 wheel pointers, stride 0x3e |

### VehicleEngineSoundStruct (FUN_004f88a0)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x39a0 | float | RPMNumerator | RPM ratio numerator |
| +0x39a4 | float | RPMDenominator | RPM ratio denominator |

### AudioBufferFormatStruct (FUN_0051868c)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x60 | uint16 | FormatFlags | Audio format flags |
| +0xb8 | int | SampleRate | Sample rate in Hz |
| +0xbc | int | Channels | Channel count |
| +0x10a | short | Interleave | Interleave size, doubles buffer size |
| +0x116 | byte | FormatType | Format-specific override (0/2/3) |
| +0x119 | byte | BitsPerPixel | Bit depth |

### AudioWaveTableStruct (FUN_0051e3e7)
| Offset | Type | Field Name | Notes |
|--------|------|------------|-------|
| +0x64 | int | ChannelCount | param_1+100, per-channel divisor |

---



--- Section 229: Struct 2: TireBrandManager (2 offsets) ---
## Struct 2: TireBrandManager

Based on 1 function observation (FUN_004d7660).
Confidence: **medium** — only one function accesses this struct.

| Offset | Type | Field Name | Observed in | Notes |
|--------|------|------------|-------------|-------|
| +0x00 | int | brandCount | FUN_004d7660 | number of tire brands loaded |
| +0x04 | ptr | brandArray | FUN_004d7660 | array of TireBrandEntry (stride 0x24) |

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
0. NEVER modify any files except %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\struct_audit\worker_P.md.
1. Process ALL sections. For every offset in each section, run the grep.
2. Flag EVERY conflict — do not silently pick a winner.
3. New offsets: only report if seen in 2+ .c files.
4. Write to disk after each struct section.
