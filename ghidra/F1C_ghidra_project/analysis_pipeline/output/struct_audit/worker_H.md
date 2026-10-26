=== AUDIT RESULTS ===

## Section 105: ChecksumCompute (checksum/hash context)

Overall: 3 MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5c | int | BlockSize/OutputElementCount | HIGH | FUN_0051e6ec:23, FUN_0051e5d7:19 | none |
| +0x64 | int | EntryCount/TableCount | HIGH | FUN_0051e6ec:21, FUN_0051e5d7:20 | none |
| +0x1a4 | ptr | TableBase/TableArrayPtr | HIGH | FUN_0051e6ec:22,29, FUN_0051e5d7:18 | none |

---

## Section 106: PauseStringTable (inferred — FUN_004541d0)

Overall: 1 MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xc88 | int | EntryCount | HIGH | FUN_004541d0:15 (uint) | none (int vs uint, 4-byte either way) |
| +0xc8c | int | CurrentID | LOW | FUN_004541d0:17 (byte) | CONFLICT: actual type is byte (1-byte), not int (4-byte). Values 0x81, 0x5a, 0xD7 all fit in byte. |

---

## Section 107: ConstraintSolverParamStruct (from FUN_00434860)

Overall: all MATCH or COMPATIBLE. Note: "2 function observations" is inaccurate — only 1 unique function (FUN_00434860) + 1 thunk (FUN_00434450).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | byte | Flag0 | HIGH | FUN_00434860:9 (*param_1=0) | none |
| +0x01 | byte | Enabled | HIGH | FUN_00434860:10 (param_1[1]=1) | none |
| +0x02 | byte | Flag2 | HIGH | FUN_00434860:16 (param_1[2]=0) | none |
| +0x03 | (missing) | _pad0 | — | padding (unwritten) | GAP: +0x03 is not documented |
| +0x04 | int | ParamI0 | MEDIUM | FUN_00434860:11 (undefined4=0) | none (int compatible) |
| +0x08 | int | ParamI1 | MEDIUM | FUN_00434860:20 (undefined4=0) | none |
| +0x0c | int | ParamI2 | MEDIUM | FUN_00434860:21 (undefined4=0) | none |
| +0x10 | float | AngleLimit1 | HIGH | FUN_00434860:22 (0x42b40000=90.0f) | none |
| +0x14 | float | AngleLimit2 | HIGH | FUN_00434860:23 (0x42960000=75.0f) | none |
| +0x18 | int | Sentinel | HIGH | FUN_00434860:12 (0xffffffff=-1) | none |
| +0x1c | int | ParamI3 | MEDIUM | FUN_00434860:13 (undefined4=0) | none |
| +0x20 | int | ParamI4 | MEDIUM | FUN_00434860:14 (undefined4=0) | none |
| +0x24 | float | MaxForce | HIGH | FUN_00434860:15 (0x40000000=2.0f) | none |
| +0x28 | int | ParamI5 | MEDIUM | FUN_00434860:17 (undefined4=0) | none |
| +0x2c | int | ParamI6 | MEDIUM | FUN_00434860:18 (undefined4=0) | none |
| +0x30 | float | FrictionCoeff | HIGH | FUN_00434860:19 (0x40500000=3.25f) | none |
| +0x34 | int | ParamI7 | MEDIUM | FUN_00434860:24 (undefined4=0) | none |

---

## Section 108: ConstraintEnforceStruct

Overall: 4 MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1e8 | double | DispX | HIGH | FUN_004380b0:12 (double*) write | none |
| +0x1f0 | double | DispY | HIGH | FUN_004380b0:13 (double*) write | none |
| +0x1f8 | double | RestPosX | HIGH | FUN_004380b0:11 (double*) read | none |
| +0x204 | double | Distance | MEDIUM | FUN_004380b0:15 (double*) via extraout_ECX | none (pointer ambiguity noted) |



## Section 104: Texture/VertexDecoder (param_1 — texture context)

Overall confidence: **high**. 20 MATCH, 4 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | int | PostProcessFlag | HIGH | FUN_00509e85:26, FUN_0050a34b:25, FUN_00509644:25, FUN_00509de6:25, +2 more | none |
| +0x18 | int | PixelDataStart/BaseIndex | HIGH | FUN_00509e85:14, FUN_0050a34b:16, FUN_00509644:16, FUN_005086dd:21, +4 more | none |
| +0x2c | ptr | ColorTableBase/PaletteArrayPtr | HIGH | FUN_00508c22:24, FUN_0050930b:21, +8 more | none |
| +0x38 | float[4]×256 | ReferenceVerts/ReferenceArray | HIGH | FUN_005086dd:29, FUN_005085c5:32 | MINOR: actual base at +0x30 (pfVar starts at +0x38, but first access is pfVar[-2]) |
| +0x60 | uint | RenderFlags | HIGH | FUN_0051378b:18,34 | none |
| +0x104 | ptr | PixelDataPtr | HIGH | FUN_0051378b:23,52 | none |
| +0x108 | ushort | PixelCount | HIGH | FUN_0051378b:21,48 | none |
| +0x116 | byte | ColorDepthMode | HIGH | FUN_0051378b:17 (char) | none (char vs byte same storage) |
| +0x138 | int | ColorOffset | HIGH | FUN_0051378b:25,26,27 | none |
| +0x150 | byte | ShiftR | HIGH | FUN_0051378b:36 | none |
| +0x151 | byte | ShiftG | HIGH | FUN_0051378b:37 | none |
| +0x152 | byte | ShiftB | HIGH | FUN_0051378b:38 | none |
| +0x1034 | int | OffsetA | HIGH | FUN_0050aeae:14 | none |
| +0x1040 | int | OffsetB | HIGH | FUN_0050aeae:14 | none |
| +0x1048 | int | TransformFlag | HIGH | FUN_00508c22:21, FUN_0050930b:18, +10 more | none |
| +0x1050 | int | TexStrideX | HIGH | FUN_00509e85:14, FUN_0050a34b:15, +7 more | none |
| +0x1054 | int | TexStrideY | HIGH | Same as +0x1050 | none |
| +0x1058 | int | PixelCount/VertexCount | HIGH | All 18 listed functions | none |
| +0x106c | float[8] | InputVertexArray/DestBuffer | LOW | FUN_0050a92d:24 (ptr), FUN_0050aeae:19 (ptr), FUN_0050b27c:16-17 (float scalar), FUN_0050ab51:45 (ptr) | CONFLICT: claimed float[8] but 3/4 functions use as ptr (pointer to external float array) |
| +0x1070 | int | CurrentIndex/RowPitch/Scale | HIGH | FUN_0050a92d:19 (uint), FUN_0050aeae:18 (int), FUN_0050b27c:17 (float), FUN_0050ab51:44 (uint) | none (float is benign reinterpretation) |
| +0x1078 | int | VertexCount | HIGH | FUN_0050a92d:25,69, FUN_0050ab51:49,135 | none |
| +0x1080 | int | OutputRowStride | MEDIUM | FUN_0050a92d:21, FUN_0050ab51:31,38 | SEMANTIC: a92d uses as stride, ab51 uses as minColumnIndex |
| +0x108c | ptr/int | InputBuffer/CopyCompleteFlag | LOW | FUN_0050a92d:18,71 (int flag), FUN_0050aeae:30 (int flag) | CONFLICT (minor): never used as ptr, always int/boolean flag |
| +0x1090 | ptr | OutputBuffer | HIGH | FUN_0050a92d:18, FUN_0050ab51:26 | none |
| +0x1094 | int | ChannelBitShift0 | MEDIUM | FUN_0050a92d:64 (undefined4), FUN_0050ab51:51 (ushort) | CONFLICT: FUN_0050ab51 reads as ushort (2-byte) |
| +0x1098 | int | ChannelBitShift1 | MEDIUM | FUN_0050a92d:65 (undefined4), FUN_0050ab51:53 (ushort) | CONFLICT: FUN_0050ab51 reads as ushort (2-byte) |

---

## Section 109: SetupParamArrayEntry (inferred)

Overall: 2 MATCH, 1 PARTIAL MATCH, 3 CONFLICTS, 1 MISSING. Confidence should be lowered.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | double | BaseValue | HIGH | FUN_0042f470:27,72,76,98,170,184,192,203,226,237,254,262,267 | none |
| +0x08 | double | Multiplier | HIGH | FUN_0042f470:72,76,98,170,184,192,203,226,237,254,262,267 | none |
| +0x10 | int | ParamCount | LOW | NOT ACCESSED in any observed function | CONFLICT: phantom field — zero references |
| +0x14 | int | CurrentValue | MEDIUM | FUN_0042f470:45,72,76,98,170,184,192,203,226,237,248,254,262,267,277,307 | PARTIAL MATCH — int in most contexts, but also used as pointer/key in some branches |
| +0x18 | char* | FormatName | LOW | NOT ACCESSED in any observed function | CONFLICT: phantom field — no string pointer read from this offset |
| +0x1c | int | Flags | MEDIUM | FUN_0042f470:306 (char/byte read, `!= '\0'` check) | CONFLICT: actual access is char (1-byte), not int (4-byte) |
| +0x1e | (missing) | FormatBuffer | — | FUN_0042f470:39,73,139,143,171,174,188,194,197,225,269,291,295,312,316,336 | MISSING: char[34] buffer passed to sprintf-like function |
| +0x20 | (padding) | (padding) | LOW | — | MISLEADING: buffer starts at +0x1e, not +0x20 |

---

## Section 110: Game State / Session Config Struct

Overall: 11 MATCH, 1 PARTIAL MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb110 | int | filter base start | HIGH | FUN_004c0db0:34 (int*) | none |
| +0xb114 | int | filter base repeat | HIGH | FUN_004c0db0:35 (int*) | none |
| +0xb118 | int | filter count | HIGH | FUN_004c0db0:36 (undefined4=0) | none |
| +0xb11c | bool | filter active flag | HIGH | FUN_004c0db0:37 (undefined1=1) | none |
| +0xb130 | int | QualifyLaps | HIGH | FUN_004c11e0:25,30 (undefined4) | none |
| +0xb134 | int | QualifyTime | HIGH | FUN_004c11e0:34,39 (undefined4) | none |
| +0xb138 | int | RaceLaps | HIGH | FUN_004c11e0:43,48 (undefined4) | none |
| +0xb13c | int | RaceTime | HIGH | FUN_004c11e0:52,57 (undefined4) | none |
| +0xb140 | void* | Current track data ptr | MEDIUM | FUN_004c11e0:60 (undefined4 copy) | PARTIAL MATCH — semantic void*, actual cast is undefined4 |
| +0xb144 | int | session filter type (=2) | LOW | FUN_004c0db0:18 (undefined4=2) vs FUN_004c0b70:38 (int** — stores pointer) | CONFLICT: FUN_004c0b70 writes int* (pointer), not int. Union/overloaded field. |
| +0xb148 | int | CURRENTRACE | HIGH | FUN_004c0db0:19, FUN_004c11e0:59, FUN_004c0b70:35 | none |
| +0xb14c | int | RACESESSION | MEDIUM | FUN_004c0b70:30 (address passed to INI parser) | none (inferred, no counter-evidence) |
| +0xb150 | bool | RACEOVER | HIGH | FUN_004c0b70:33 (bool*) | none |

---

## Section 111: Buffer Flush/Write I/O Struct (FUN_0058a05a)

Overall: 5 COMPATIBLE/MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | WritePos | MEDIUM | FUN_0058a05a:14,29 (int arithmetic via param_1[0]) | none — decompiler uses int* for arithmetic on pointer values |
| +0x04 | void* | StartPos | MEDIUM | FUN_0058a05a:28 (param_1[1]=0) | none |
| +0x08 | void* | BufferStart | MEDIUM | FUN_0058a05a:14,16,29 (int arithmetic) | none |
| +0x0c | uint | Flags | HIGH | FUN_0058a05a:13,18,19,23 (bitwise ops) | none |
| +0x10 | int | IOHandle | HIGH | FUN_0058a05a:16 (passed as uint to callee) | none |

---

## Section 112: List Container (doubly-linked) (inferred)

Overall: 4 MATCH (on FUN_004967d0). **"Used by FUN_004b9000, FUN_00486540" is INCORRECT** — those functions use different list containers at different offsets.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x18cc | ptr | head | HIGH | FUN_004967d0:21,22 (int** store, int* read) | none — but only in FUN_004967d0, not in claimed FUN_004b9000/FUN_00486540 |
| +0x18d0 | ptr | tailWrite | HIGH | FUN_004967d0:26,27,29 | none — same scope limitation |
| +0x18d4 | ptr | tailAlt | HIGH | FUN_004967d0:23 | none — same scope limitation |
| +0x18d8 | int | elementCount | HIGH | FUN_004967d0:30 (RMW +1) | none — same scope limitation |

**CORRECTION:** Section header claims "Used by FUN_004967d0, FUN_004b9000, FUN_00486540" but FUN_004b9000 uses list at +0x714/+0x718/+0x71c (renderer) and FUN_00486540 uses list at +0xd8 (different container). Only FUN_004967d0 uses these specific offsets. Change "Based on 3 function observations" to "Based on 1 function observation (FUN_004967d0)."

---

## Section 113: CollisionDeformationMesh (inferred — param_1 in FUN_004DF110)

Overall: 5 MATCH, 1 MAJOR CONFLICT (+0x1C), 1 undocumented gap.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | MaxValue | HIGH | FUN_004DF110:56,62,75,81,109 | none |
| +0x04 | (missing) | (unknown) | — | Not referenced | GAP: 4 bytes between MaxValue and GroupCount |
| +0x08 | int | GroupCount | HIGH | FUN_004DF110:59,85,104,127,166,228,255,258,277,286,295,298,356 | none (accessed via (int)param_1[2]) |
| +0x0C | int* | GroupArray | HIGH | FUN_004DF110:88,90,93,130,132,231,233,262,289,301 | none |
| +0x10 | int | EntityCount | MEDIUM | FUN_004DF110:169,223 (only 2 refs) | none |
| +0x14 | int* | EntityArray | MEDIUM | FUN_004DF110:172,174 | none (pointer to mixed float/int struct) |
| +0x18 | int | EntryCount | HIGH | FUN_004DF110:59,65,70,78,110,282 | none |
| +0x1C | float* | EntryArray | LOW | FUN_004DF110:115,117,226,258 (read as float via pfVar15[-7]) | CONFLICT: claimed float* (ptr) but actual is float (sentinel/mode value 0=relax, 1=stiff, 2=snap). Entries are inline at +0x20, not behind pointer. |

---

## Section 114: Tire/vehicle struct (partial from FUN_004a6b80 comments)

Overall: 2 MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x344C | int | ActiveFlag | LOW | FUN_004a6b80:40 (char), FUN_004c73f0:117 (byte). 18 refs across 15 functions, all byte/char | CONFLICT: actual type is byte/char (1-byte boolean), not int |
| +0x34E0 | float[3] | Position | HIGH | FUN_004a6b80:44-47, FUN_004e49b0:50-54. 29 matches all float | none |
| +0x34F8 | float[3] | Direction | HIGH | FUN_004a6b80:41-42, FUN_004e49b0:74-85. 31 matches all float | none |

---

## Section 115: Camera Manager Struct (inferred)

Overall: 9 MATCH (offsets +0x10 to +0x30), 1 MISSING field (+0x38), 1 MISSING field (+0x3c), 2 CONFLICTS (offsets +0x40/+0x44 belong to Camera struct, not CameraManager).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | Camera* | NoseCam | HIGH | FUN_00408e20:124,134 | none |
| +0x14 | Camera* | CockpitCam | HIGH | FUN_00408e20:96,106 | none |
| +0x18 | Camera* | TVCockpitCam | HIGH | FUN_00408e20:110,120 | none |
| +0x1c | Camera* | SwingmanCam | HIGH | FUN_00408e20:82,92 | none |
| +0x20 | Camera* | ExtraCamArray | HIGH | FUN_00408e20:138,161,198 (int** — array base ptr) | none |
| +0x24 | Camera* | PitCam | HIGH | FUN_00408e20:206, FUN_00408870:11,21 | none |
| +0x28 | Camera* | Unused1 | HIGH | FUN_00408e20:210, FUN_00408870:65,75 | RENAME: string "3SEATER" → call ThreeSeaterCam, not "Unused1" |
| +0x2c | Camera* | Unused2 | HIGH | FUN_00408e20:214, FUN_00408870:119,129 | RENAME: string "LEFT_OF_PITS" → call LeftPitsCam, not "Unused2" |
| +0x30 | Camera* | Unused3 | HIGH | FUN_00408e20:218, FUN_00408870:172,182 | RENAME: string "RIGHT_OF_PITS" → call RightPitsCam, not "Unused3" |
| +0x38 | (missing) | ExtraCamCount | — | FUN_00408e20:142,170,194,203 (int) | MISSING: count of cameras in ExtraCamArray |
| +0x3c | (missing) | CurrentIndex/pad | — | FUN_00408e20:143,171 (undefined4=0) | MISSING: current camera index or padding |
| +0x40 | int/str? | CameraName | — | FUN_00408e20:179,183,187,191,199,207,211,215,219 | CONFLICT: +0x40 belongs to Camera struct (200B each), NOT CameraManager. Remove from Section 6. |
| +0x44 | int | CameraCount | — | FUN_00408e20:180,184,188,193,201,208,212,216,220 | CONFLICT: +0x44 belongs to Camera struct (200B each), NOT CameraManager. Remove from Section 6. |

---

## Section 116: AudioMixerValueStruct (inferred)

Overall: 1 MATCH (+0x78 code*), 2 MINOR CONFLICTS (undefined4 vs int — low severity, Ghidra default typing).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Value | MEDIUM | FUN_00562fe0:8 (undefined4 copy from param_2) | MINOR: decompiler shows undefined4 not int |
| +0x78 | code* | vtable_fn | HIGH | FUN_00562fe0:9 (explicit (code*) cast) | none |
| +0x7c | int | ChannelId | MEDIUM | FUN_00562fe0:9 (undefined4, passed as 3rd arg) | MINOR: decompiler shows undefined4 not int |

---

## Section 117: Struct 9: Race Mode State Struct (FUN_004ae9f0 / FUN_004af220)

Overall: 2 PARTIAL CONFLICTS (minor — undefined4 vs int due to switch dispatch).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1b10 | int | DifficultyMode | MEDIUM | FUN_004ae9f0:10 (undefined4* switch), 152 (int*) | PARTIAL: switch access uses undefined4*; comparison uses int* |
| +0x1b34 | int | ModeSelector | MEDIUM | FUN_004af220:8 (undefined4* switch, only access) | PARTIAL: sole access is undefined4* for switch dispatch |

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| Texture/VertexDecoder | +0x1030 | int | FUN_0050aeae:18 | BaseBufferEnd/source limit |
| Texture/VertexDecoder | +0x1064 | int | FUN_00509644:17, FUN_0050a659:18 | RowByteCount/pixel data size per row |
| Texture/VertexDecoder | +0x1074 | int | FUN_0050a92d:22, FUN_0050ab51:30,37 | MinRowIndex or extra stride |
| Texture/VertexDecoder | +0x107c | uint | FUN_0050ab51:30,36 | MaxRowIndex+1 |
| Texture/VertexDecoder | +0x1084 | uint | FUN_0050ab51:31,39 | MaxColIndex+1 |
| Texture/VertexDecoder | +0x1088 | int | FUN_0050aeae:15 | TransformActiveFlag |
| CollisionDeformationMesh | +0x04 | (unknown) | gap | Not referenced in FUN_004DF110 |
| CollisionDeformationMesh | +0x20 | float[] | FUN_004DF110 | Entry array inline (not behind pointer), stride 9 floats |
| Camera Manager | +0x38 | int | FUN_00408e20:142,170,194,203 | ExtraCamArray count |
| Camera Manager | +0x3c | int | FUN_00408e20:143,171 | Current camera index or padding |
| SetupParamArrayEntry | +0x1e | char[34] | FUN_0042f470:39,73,139,143,171,174,188,194,197,225,269,291,295,312,316,336 | Format string output buffer (not padding at +0x20)

