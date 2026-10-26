# WORKER P — Struct Confidence Audit Results

---

## Section 216: Session/Rankings ScoringGate

Based on FUN_00411440, confirmed by FUN_00410bc0, FUN_00410f60, FUN_00410890, FUN_00411330.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x48 | int | EntryCount | HIGH | 4+ files: FUN_00411440, FUN_00410bc0, FUN_00410f60, FUN_00410890 all access as int | none |
| +0x4c | ptr | EntryRosterPtr | HIGH | FUN_00411440, FUN_00410bc0, FUN_00411330 all use as ptr with stride 0x24 | none |
| +0x50 | byte[] | EntryArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x50)` — pointer to array, not inline array | TYPE: doc says byte[], code shows `ptr` |
| +0x54 | int | QualiCount | HIGH | 4+ files: all access as int | none |
| +0x58 | ptr | QualiRosterPtr | HIGH | FUN_00411440, FUN_00410bc0, FUN_00411330 use as ptr with stride 0x24 | none |
| +0x5c | byte[] | QualiArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x5c)` — pointer to array | TYPE: doc says byte[], code shows `ptr` |
| +0x60 | int | PracticeCount | HIGH | 4+ files: all access as int | none |
| +0x64 | ptr | PracticeRosterPtr | HIGH | FUN_00411440 (as `param_1+100`=0x64), FUN_00410bc0 (line 130), FUN_00411330 (line 35) | none |
| +0x68 | byte[] | PracticeArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x68)` — pointer to array | TYPE: doc says byte[], code shows `ptr` |

**Summary:** Good struct definition. 3 type corrections needed: +0x50, +0x5c, +0x68 should be `ptr` not `byte[]` — .c files double-dereference these (read ptr at offset, then offset into pointed-to data).

---

## Section 217: Multi-Function Struct Groups (Cross-Function Confirmation)

### Buffer Descriptor — ACTUALLY 3 DIFFERENT STRUCTS conflated

The prompt groups these as one struct, but analysis shows **3 distinct struct layouts**:

**Struct A: Circular Buffer (param_1 of FUN_0052a5d7)**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x28 | ptr | BufferStart | HIGH | FUN_0052a5d7 line 55: `*(undefined4**)(param_1+0x28)` | none |
| +0x2c | ptr | BufferEnd | HIGH | FUN_0052a5d7 line 23: `*(undefined4**)(param_1+0x2c)` | none |
| +0x30 | ptr | ReadPtr | HIGH | FUN_0052a5d7 line 19: `*(undefined4**)(param_1+0x30)` | none |
| +0x34 | ptr | EndPtr | HIGH | FUN_0052a5d7 line 21: `*(undefined4**)(param_1+0x34)` | none |
| +0x38 | ptr | Callback | HIGH | FUN_0052a5d7 line 35: `*(code**)(param_1+0x38)` — function pointer | none |
| +0x3c | ptr | CallbackCtx | HIGH | FUN_0052a5d7 line 36: `*(undefined4*)(param_1+0x3c)` | none |

**Struct B: Stream Descriptor (param_2 of FUN_0052a5d7)**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | ptr | DestPtr | MEDIUM | FUN_0052a5d7 line 20: `*(undefined4**)(param_2+0xc)` | not in doc |
| +0x10 | uint | RemainingCount | MEDIUM | FUN_0052a5d7 line 25: `*(uint*)(param_2+0x10)` | not in doc |
| +0x14 | int | TotalWritten | MEDIUM | FUN_0052a5d7 line 33: `*(int*)(param_2+0x14)` | not in doc |
| +0x30 | ptr | OutputPtr | MEDIUM | FUN_0052a5d7 line 38: `*(undefined4*)(param_2+0x30)` | not in doc |

**Struct C: Simple Buffer (param_2 of FUN_0058d78e, also FUN_00589898)**
| +0x00 | byte* | CurrentPtr | HIGH | FUN_0058d78e line 17, FUN_00589898 line 19-20 | none |
| +0x04 | int | RemainingCount | HIGH | FUN_0058d78e line 11, FUN_00589898 line 13 | none |

**FUN_005698e0 sub-struct (queue element at iVar1, stride 0x84) — DIFFERENT**
| +0x78 | int | ExtraInt1 | LOW | on array element, not param_1 struct | not param_1 |
| +0x7c | int | ExtraInt2 | LOW | same | not param_1 |
| +0x80 | byte | ExtraByte | LOW | same | not param_1 |

**Summary:** Doc conflates 3-4 struct layouts. Struct C (Simple Buffer)+0x00/+0x04 is confirmed HIGH across 2 functions. Struct A (Circular Buffer) is HIGH in FUN_0052a5d7 alone. Doc incorrectly lists +0x28-+0x3c under "Simple Buffer Descriptor" — they belong to Circular Buffer (Struct A). FUN_005698e0 accesses are on queue element, not param_1 directly.

### Timer/Performance State Struct

Functions: FUN_00568be0 exists; FUN_00569da0 has NO .c file.

FUN_00568be0 analysis (param_1 = `uint*`, int-indexed):

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | uint | FrequencyLowPart | HIGH | line 21: `*param_1 = local_8.s.LowPart` | none |
| +0x08 | double | InvFrequencyScaled | HIGH | line 32: `*(double*)(param_1+2)` at int-index 2 = byte 8 | none |
| +0x10 | uint | AccLow | HIGH | line 30: `param_1[4] = 0` | none |
| +0x14 | uint | AccHigh | HIGH | line 31: `param_1[5] = 0` | none |
| +0x18 | uint | CounterLow | HIGH | line 19: `param_1[6]` | none |
| +0x1c | uint | CounterHigh | HIGH | line 20: `param_1[7]` | none |
| +0x20 | uint | LastSampleLow | HIGH | line 24: `param_1[8]` | none |
| +0x24 | uint | LastSampleHigh | HIGH | line 29: `param_1[9]` | none |
| +0x28 | uint | Acc | HIGH | line 26: `param_1[10] = 0` | none |
| +0x2c | uint | Overflow | HIGH | line 27: `param_1[0xb] = 0` | none |
| +0x48 | uint | Mode | HIGH | line 25: `param_1[0x12] = param_2` | none |

**Doc mismatch:** Doc shows `double StartTime` at +0x00, `double Frequency` at +0x08, `double ElapsedS` at +0x10, `double ElapsedMS` at +0x18 (from FUN_00569da0 which has no .c). Could be same struct at different lifecycle stage — after init, raw uint counters reinterpreted as doubles. Cannot verify without FUN_00569da0 source.

### Dynamic Array Container

Functions: FUN_00457cf0 (NO .c file), FUN_004bd900.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | int | Capacity | HIGH | FUN_004bd900 lines 11-12: capacity check, `+8` growth | none |
| +0x10 | int | Count | HIGH | FUN_004bd900 lines 11,16,21,28,29 | none |
| +0x14 | ptr | Data | HIGH | FUN_004bd900 lines 19,24,26,28 | none |

FUN_00457cf0 not available. Doc claim of +0x00 HeapPtr, +0x04-+0x18 DataFields unverifiable.

### Linked List Node Layout

Functions: FUN_00407c90 (exists). Others (FUN_0050b6f0, FUN_00512a20, FUN_005bf450, FUN_005e3b60) NO .c files.

FUN_00407c90 shows a LIST CONTAINER struct on param_1:

| +0x18 | ptr | HeadPtr | MEDIUM | line 13,30,44 | not in node doc |
| +0x1c | ptr | TailPtr | MEDIUM | line 49-50 | not in node doc |
| +0x20 | ptr | Iterator | MEDIUM | line 14,17-18,23 | not in node doc |
| +0x24 | int | Count | MEDIUM | line 52 | not in node doc |

Node layout (from pointer arithmetic):
| +0x00 | int | Key/ID | HIGH | lines 15,32,40-41,53-54 | none |
| +0x04 | ptr | NextPtr | HIGH | line 18,35 | none |
| +0x08 | byte | Flags | MEDIUM | line 53: `(char)piVar4[2]` byte access | doc says int32, code shows byte |

**CONFLICT:** Doc says +0x08 is `int32 Flags/Data` but FUN_00407c90 accesses as `(char)piVar4[2]` — byte access (bit flags).

---

## Section 218: InputDevice (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x13E8 | int | BindingValueA | **ZERO** | NOT in FUN_0040be70. Uses +0x08,+0x18,+0x24,+0x2c only. | Function mismatch |
| +0x13EC | int | InputDeviceHandle | **ZERO** | NOT in FUN_0040be70 | Function mismatch |
| +0x1544 | int | ControlID | **ZERO** | NOT in FUN_0040be70 | Function mismatch |
| +0x1f98 | ptr | ControllerArray | **ZERO** | FUN_00455da0 has NO .c file | No source |

**Summary:** FUN_0040be70 (referenced as source) does NOT use offsets +0x13E8,+0x13EC,+0x1544 — it uses completely different offsets. FUN_00455da0 (for +0x1f98) has no .c file. **Claimed offsets are unverifiable.** Recommend removing or reassigning to correct function.

---

## Section 219: VehicleGearShiftStruct

Based on FUN_00426330.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x37cc | float | LeftWheelSpeed | HIGH | line 33 | none |
| +0x38c4 | float | RightWheelSpeed | HIGH | line 36 | none |
| +0x39a0 | float | EngineRPM | HIGH | line 26 | none |
| +0x39fc | int | ShiftTimer | HIGH | lines 13,40 | none |
| +0x3a04 | int | NextGearThreshold | HIGH | line 40 | none |
| +0x3a10 | float | EngineSpeed | HIGH | line 12 | none |
| +0x3a18 | float | RPMShiftThreshold | HIGH | line 26 | none |
| +0x3d6c | int | DrivingMode | HIGH | line 21 | none |
| +0x4510 | int | CurrentGear | HIGH | line 14 | none |

**Summary:** All 9 offsets confirmed HIGH. Single function but consistent with vehicle physics struct.

---

## Section 220: PhysicsBody (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x00 | unknown | (vtable/type) | **NO VERIFICATION** | FUN_00439210 has NO .c file |
| +0x04 | double[3] | Position | **NO VERIFICATION** | no source |
| +0x1c | double[3x3] | OrientationMatrix | **NO VERIFICATION** | no source |
| +0xac | double | Mass | **NO VERIFICATION** | no source |
| +0xb4 | double | InvMass | **NO VERIFICATION** | no source |
| +0xbc | double[3] | InertiaDiagonal | **NO VERIFICATION** | no source |

**Summary:** Cannot verify — FUN_00439210 not found in analyzed/ or decompiled_all/. **Confidence: UNVERIFIABLE.**

---

## Section 221: Conflicting Offset Observations

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x1d4 | FuelTankBodyPtr | FUN_00439210 (no file) | Cannot verify |
| +0x15c4 | SteeringBarCount vs EngineMapSetting | FUN_00439210 (no file), FUN_0042fd00 | Cannot cross-verify |
| +0x1884 | GearCount vs NumPitstopsSetting | FUN_0042f470 (no file), FUN_0042fd00 (no file) | Cannot verify |
| +0x3d64 | EngineFailureTime[4] vs TireWearAccumulator | FUN_004ee150, FUN_004efae0 | **RESOLVED: No conflict.** FUN_004ee150 writes +0x3d64 as float[4] (engine failure timers). FUN_004efae0 reads +0x3d64 as float[0] threshold check. Same field, consistent usage. "TireWearAccumulator" label is misinterpretation — it is EngineFailureTime[0]. |
| +0x1db4 | double vs docs/13 EffectiveLifetime | docs/13 | Consistent per doc |

---

## Section 222: File Buffer State Struct

Based on FUN_00587ca0, FUN_00589898. Confidence: HIGH.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | byte* | buffer_ptr | HIGH | FUN_00587ca0 line 27: `*(byte*)*param_3`; FUN_00589898 line 19: `*(undefined1*)*param_2` | none |
| +0x04 | int | remaining | HIGH | FUN_00587ca0 line 22: `*piVar1 = *piVar1 + -1`; FUN_00589898 line 13: same pattern | none |

**Summary:** Confirmed across 2 functions with identical access pattern. Both use int*-indexed access (param[0], param[1]).

---

## Section 223: Texture/Surface Format Struct (inferred)

Based on 6+ functions. Confidence: **medium** (different offset ranges may indicate sub-structs).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | width | HIGH | FUN_00518248 line 24: `*param_1` as width counter | none |
| +0x04 | int | height | MEDIUM | FUN_00518248 line 177: `param_1[1]` set as stride | name uncertain — may be stride/pitch |
| +0x0b | byte | bpp | HIGH | FUN_00518248 line 26: `*(byte*)(param_1+0xb)` values 1,2,4 | none |
| +0x14 | ptr | bitmapData | MEDIUM | FUN_00586d70 line 21: `*(int*)(param_1+0x14)` | single function source |
| +0x1c | ptr | bitmapHeader | HIGH | FUN_00586d70 line 13: `*(int*)(param_1+0x1c)` | also used in pixel calc FUN_0050ab51 line 48 |
| +0x20 | int | flags | HIGH | FUN_00558d80 line 8-9; FUN_00558dc0 line 10; FUN_00558d10 line 15 | bit 0x100 = locked |
| +0x24 | int | height | MEDIUM | FUN_00558dc0 line 15: used in row lookup indexing | doc says +0x04 is height; +0x24 may be extended height |
| +0x34 | ptr | rowLookup | MEDIUM | FUN_00558dc0 line 15 | single function source |
| +0x38 | int | regionStride | MEDIUM | FUN_00586d70 line 13 | single function source |
| +0x4c | int | renderMode | HIGH | FUN_00558dc0 line 10: `== 1` | none |
| +0x50 | ptr | surfaceArray | HIGH | FUN_00558d80 line 10; FUN_00558dc0 line 12; FUN_00558d10 line 20 | confirmed across 3 functions |
| +0x1050 | int | yPitch | HIGH | FUN_0050ab51 line 47 | none |
| +0x1054 | int | uvPitch | HIGH | FUN_0050ab51 line 47 | none |
| +0x106c | ptr | outputBuffer | HIGH | FUN_0050ab51 line 45: `*(float**)(param_1+0x106c)` | none |
| +0x1070 | int | outputStride | HIGH | FUN_0050ab51 line 44 | none |
| +0x1074 | int | dirtyLeft | HIGH | FUN_0050ab51 lines 30,37 | none |
| +0x1078 | int | dirtyRight | HIGH | FUN_0050ab51 lines 49,135 | none |
| +0x107c | int | dirtyTop | HIGH | FUN_0050ab51 lines 31,36 | none |
| +0x1080 | int | dirtyBottom | HIGH | FUN_0050ab51 lines 31,38 | none |
| +0x1084 | int | width | HIGH | FUN_0050ab51 line 31 | CONFLICT: +0x00 also called "width" — may be different resolution/scaled |
| +0x1090 | int | bufferReady | HIGH | FUN_0050ab51 line 26 | none |
| +0x1094 | int | bitDepth | MEDIUM | FUN_0050ab51 line 51: accessed as `undefined2` NOT int | TYPE: doc says int, code shows uint16 |
| +0x1098 | int | bitShift | MEDIUM | FUN_0050ab51 line 53: accessed as `undefined2` NOT int | TYPE: doc says int, code shows uint16 |

**Summary:** 22 offsets tracked. Most confirmed HIGH. Minor type issues (+0x1094, +0x1098 should be uint16), and +0x1084 "width" conflicts with +0x00 "width" (different scale — +0x00 = logical width, +0x1084 = dirty rect width?). +0x2c used in FUN_00558d10 line 27 (not in doc — new offset discovered). No DirectX API calls detected; these are game-side surface management structs.

---

## Section 224: Texture/Blit Render Struct (inferred)

Based on FUN_0048e4b0. Confidence: **low** (single function).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb0 | ptr | pathStringA | MEDIUM | line 17: `param_1[0x2c]` (int-indexed) | none |
| +0xfc | ptr | pathStringB | MEDIUM | line 21: `param_1[0x3f]` | none |
| +0xe4 | int | renderEnable | MEDIUM | line 30: `param_1[0x39]` | none |
| +0xf8 | byte | dirtyFlag | MEDIUM | line 41: `*(undefined1*)(param_1+0x3e)` — byte access via int-index | none |
| +0xe8 | int | rectX | MEDIUM | line 31: `param_1[0x3a]` | none |
| +0xec | int | rectY | MEDIUM | line 31: `param_1[0x3b]` | none |
| +0xf0 | int | rectW | MEDIUM | line 33: `param_1[0x3c]` | none |
| +0xf4 | int | rectH | MEDIUM | line 32: `param_1[0x3d]` | none |

**Summary:** All offsets confirmed. param_1 is `int*` so all access is int-indexed (offset = index * 4). Single function, LOW confidence overall. No DirectX calls, appears to be UI render path management.

---

## Section 225: SensorState (inferred — param_1 in FUN_00464a40)

Based on FUN_00464a40. Confidence: **low** (single function, 18 bytes, init-only).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x068 | int | SensorTimeout | LOW | line 12: `*(undefined4*)(param_1+0x68) = 0` | init only, type uncertain |
| +0x06C | byte | SensorState | LOW | line 11: `*(undefined1*)(param_1+0x6c) = 0` | init only |
| +0x071 | undefined4 | SensorValue | LOW | line 10: `*(undefined4*)(param_1+0x71) = _DAT_0059f130` | offset unaligned (0x71) |

**Summary:** All 3 offsets confirmed as written. Init-only function means types are tentative. +0x71 is unusual (not 4-byte aligned), suggesting a packed struct. Confidence remains LOW.

---

## Section 226: Source: docs/03-engine-wear-damage.md

No offsets claimed in this section — it references existing docs/03 entries. **No audit needed.**

---

## Section 227: 14. UI Dialog Struct (inferred)

Functions: FUN_0046b0c0 (NO .c file), FUN_00470300 (NO .c file).

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x1fc | int | State | **NO VERIFICATION** | No .c files available |
| +0x200 | int | RawInputData | **NO VERIFICATION** | No .c files available |
| +0x204 | int | InputType | **NO VERIFICATION** | No .c files available |
| +0x2e8 | int | ResetField | **NO VERIFICATION** | No .c files available |
| +0x304 | int | ControlID | **NO VERIFICATION** | No .c files available |

**Summary:** Neither function has a .c file. **UNVERIFIABLE.**

---

## Section 228: Minor Structs (1 observation each)

### AudioStreamInitStruct (FUN_0057a3f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Active | HIGH | line 11: `*param_1 = 1` | none |
| +0x04 | int | Field1 | HIGH | line 12: `param_1[1] = 0` | none |
| +0x08 | uint16 | SampleRate | HIGH | line 13: `*(undefined2*)(param_1+2) = 0xd45` (param_1 is `undefined4*`, so index 2 = byte 8) | none |
| +0x0a | uint16 | BufferSize | HIGH | line 14: `*(undefined2*)((int)param_1+10) = 0x1d8` | none |
| +0x0c | int | Field3 | HIGH | line 15: `param_1[3] = 0` | none |
| +0x10-0x2c | int[8] | Reserved | HIGH | lines 16-20: `param_1+4` through `param_1+11` zeroed | none |

**Summary:** All offsets confirmed. Init function sets fixed values. HIGH confidence for init pattern.

### VehicleSoundStruct (FUN_004f12e0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x7a4 | float | SlipAngle | HIGH | line 88: `*(float*)(param_1+0x7a4) <= float_const` | none |
| +0x32bc | int | SuspensionType | HIGH | line 94: `*(int*)(param_1+0x32bc) == 0/1` | none |
| +0x34ec | float | WheelVelX | HIGH | line 59 | none |
| +0x34f0 | float | WheelVelY | HIGH | line 58 | none |
| +0x34f4 | float | WheelVelZ | HIGH | line 57 | none |
| +0x3668 | void*[4] | WheelPtrs | HIGH | line 25: ptr array, stride 0x3e (line 53) | none |

**Summary:** All 6 offsets confirmed HIGH. Also references +0x5fc (skid sound flag, not in doc), +0x39b8,+0x39c4 (engine RPM thresholds, not in doc), +0x3a58,+0x3a5c,+0x3a60 (vehicle velocity, not in doc).

### VehicleEngineSoundStruct (FUN_004f88a0)

**NOTE:** These offsets are on `*param_1`, NOT on `param_1` directly. param_1 is `int*` and is dereferenced first.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x39a0 | float | RPMNumerator | HIGH | line 22: `*(float*)(*param_1+0x39a0)` — on **dereferenced** ptr | none |
| +0x39a4 | float | RPMDenominator | HIGH | line 22: `*(float*)(*param_1+0x39a4)` — on **dereferenced** ptr | none |

**Summary:** Offsets confirmed. But they belong to the struct pointed to by param_1[0], NOT param_1 itself. The containing struct is the vehicle physics struct (same range as Section 219).

### AudioBufferFormatStruct (FUN_0051868c)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x60 | uint16 | FormatFlags | MEDIUM | line 25: byte access `& 2`; line 37: uint access `& 4` | TYPE: doc says uint16, code shows byte and uint |
| +0xb8 | int | SampleRate | HIGH | line 19: `*(int*)(param_1+0xb8)` | none |
| +0xbc | int | Channels | HIGH | line 17: `*(uint*)(param_1+0xbc)` | none |
| +0x10a | short | Interleave | HIGH | line 44: `*(short*)(param_1+0x10a)` | none |
| +0x116 | byte | FormatType | HIGH | line 42: `*(char*)(param_1+0x116)` | none |
| +0x119 | byte | BitsPerPixel | HIGH | line 36: `*(byte*)(param_1+0x119)` | none |

**Summary:** Confirmed. Also discovered (not in doc): +0x68 (line 15), +0x5c (line 76), +0xc0 (line 20), +0xcc (line 22), +0xd0 (line 21), +0xd8 (line 74), +0xdc (line 72), +0x113 (line 18), +0x114 (line 30), +0x117 (line 38).

### AudioWaveTableStruct (FUN_0051e3e7)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x64 | int | ChannelCount | HIGH | line 38: `*(int*)(param_1+100)` (100 = 0x64) as loop bound | none |

**Summary:** Confirmed. Also accesses +0x4c (line 25, mode check), +0x1a4 (line 24, sub-struct pointer), and extensive sub-struct fields at offsets from pointer at +0x1a4 (not documented).

---

## Section 229: TireBrandManager

Based on FUN_004d7660. Confidence: **medium** (single function). NO .c file available.

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x00 | int | brandCount | **NO VERIFICATION** | FUN_004d7660 has NO .c file |
| +0x04 | ptr | brandArray | **NO VERIFICATION** | FUN_004d7660 has NO .c file |

**Summary:** **UNVERIFIABLE** — no .c file exists.

---

## NEW OFFSETS DISCOVERED

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| Timer/Perf State | +0x00 | uint | FUN_00568be0 | FrequencyLowPart — doc says double StartTime (conflict) |
| Timer/Perf State | +0x08 | double | FUN_00568be0 | InvFrequencyScaled — doc says double Frequency |
| Timer/Perf State | +0x10 | uint | FUN_00568be0 | AccLow — doc says double ElapsedS |
| Timer/Perf State | +0x18 | uint | FUN_00568be0 | CounterLow — doc says double ElapsedMS |
| Timer/Perf State | +0x48 | uint | FUN_00568be0 | Mode — not in doc |
| Stream Descriptor | +0x0c | ptr | FUN_0052a5d7 | DestPtr — not in doc |
| Stream Descriptor | +0x10 | uint | FUN_0052a5d7 | RemainingCount — not in doc |
| Stream Descriptor | +0x14 | int | FUN_0052a5d7 | TotalWritten — not in doc |
| Stream Descriptor | +0x30 | ptr | FUN_0052a5d7 | OutputPtr — not in doc |
| Linked List Container | +0x18 | ptr | FUN_00407c90 | HeadPtr — not in doc |
| Linked List Container | +0x1c | ptr | FUN_00407c90 | TailPtr — not in doc |
| Linked List Container | +0x20 | ptr | FUN_00407c90 | Iterator — not in doc |
| Linked List Container | +0x24 | int | FUN_00407c90 | Count — not in doc |
| Texture/Surface | +0x2c | int | FUN_00558d10 | Index multiplier — not in doc |
| AudioBufferFormat | +0x5c | uint | FUN_0051868c | Flags2 — not in doc |
| AudioBufferFormat | +0x68 | int | FUN_0051868c | Field — not in doc |
| AudioBufferFormat | +0xc0 | uint | FUN_0051868c | Computed channels — not in doc |
| AudioBufferFormat | +0xcc | uint | FUN_0051868c | Alloc size — not in doc |
| AudioBufferFormat | +0xd0 | int | FUN_0051868c | Stride — not in doc |
| AudioBufferFormat | +0xd8 | ptr | FUN_0051868c | Buffer — not in doc |
| AudioBufferFormat | +0xdc | ptr | FUN_0051868c | Buffer2 — not in doc |
| VehicleSound | +0x5fc | byte | FUN_004f12e0 | SkidSoundFlag — not in doc |
| VehicleSound | +0x3a58 | float | FUN_004f12e0 | VelX2 — not in doc |
| VehicleSound | +0x3a5c | float | FUN_004f12e0 | VelY2 — not in doc |
| VehicleSound | +0x3a60 | float | FUN_004f12e0 | VelZ2 — not in doc |
| AudioWaveTable | +0x4c | int | FUN_0051e3e7 | Mode — not in doc |
| AudioWaveTable | +0x1a4 | ptr | FUN_0051e3e7 | SubStruct — not in doc |
