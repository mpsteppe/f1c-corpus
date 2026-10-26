=== AUDIT RESULTS ===

## Section 244: AudioSoundInstance (param_1 — sound instance)

Source: FUN_00541810 (analyzed). param_1 is `undefined4*` (int-indexed).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | undefined4 | AudioResult | HIGH | `*param_1 = uVar1` — sound op result storage | none |
| +0x13D8 | int | SoundSystemPtr | HIGH | `param_1[0x4f6]` null guard (0x4f6×4=0x13D8) | none |
| +0x1100 | int | SoundSystemVtable | HIGH | `param_1[0x440]` dereferenced as vtable (0x440×4=0x1100) | none |
| +0x155C | int | InstanceCount | HIGH | `param_1[0x557]` counter (0x557×4=0x155C) | none |
| +0x1560 | int[] | InstanceIDs | HIGH | `param_1 + 0x558` iterated as ID array (0x558×4=0x1560) | none |

**Grade: HIGH** — all offsets verified from single function. Doc correctly notes `×4` int-index scaling.

---

## Section 245: Vehicle/AI Struct Offsets (High Offset Ranges)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1000 | short | ReadCursor | HIGH | 2 files: `*(short *)(param_1+0x1000)` (FUN_0057b530, FUN_0057b630) | none |
| +0x1002 | ushort | AvailableData | HIGH | 2 files: `*(ushort *)(param_1+0x1002)` (FUN_0057b530, FUN_0057b630) | none |
| +0x1040 | float | Scale | MEDIUM | 1 file: `*(float *)(param_1+0x1040)` (FUN_004c73f0). Doc says FUN_00530b50 — does NOT exist. | Wrong function attribution |
| +0x105c | int | ObjectIndex | LOW | 3 files use `param_1[0x105c]` (int-indexed, byte offset = 0x105c×4=0x4170 if pointer-typed). Functions: 0x00423e80, 0x00424790, 0x00424e70. | Indexing ambiguity; wrong function |
| +0x1b79c | int | (net flag) | MEDIUM | 4 files: `*(int *)(*param_1+0x1b79c)` (0x00461ed0, 0x00461f70, 0x00461f90, 0x00461fc0) — NetComm flag check | Wrong function attribution |
| +0x32d0 | int | (field) | HIGH | 1 file: `*(undefined4 *)(param_1+0x32d0)` (FUN_00424060). Doc says FUN_004A3570 — wrong. | Wrong function attribution |
| +0x3e18 | int[] | (data array) | HIGH | 5 files: `param_1+0x3e18` as int array base (0x0045e5f0, 0x0045f4a0, 0x0045f710, 0x00460c30, 0x00460c60) | Wrong function attribution |
| +0x3fc4 | int | SessionState | HIGH | 4 files: values 1/2/3 (0x0045f390, 0x0045f4a0, 0x0045f710, 0x00460710) | Wrong function attribution |
| +0x4034 | int | (unknown) | **NONE** | 0 files found. **DOC CLAIM UNSUPPORTED.** | No evidence |
| +0x4038 | int | (field) | HIGH | 2 files: FUN_00424060, 0x004d1b50. Doc says FUN_004A3570 — wrong. | Wrong function attribution |
| +0x4354 | int | AIStateFlags | MEDIUM | 2 files: used as both int and pointer-to-AI-substruct (0x00425670, 0x00425920) | Wrong function attribution |

**Major issues:**
1. **+0x4034: NO EVIDENCE** — remove or mark unconfirmed.
2. **+0x105c**: Source uses `param_1[0x105c]` (int-indexed). If param_1 truly is `int*`, byte offset = 0x4170, not 0x105c. If decompiler artifact, byte offset = 0x105c. Needs clarification.
3. **All function attributions are wrong** — none of the listed functions (FUN_00530b50, FUN_005a7320, FUN_004A3570, FUN_005a0d00, FUN_004AB040, FUN_004AB230, FUN_0052bbe8) exist in analyzed/. Actual functions using these offsets differ.

---

## Section 246: FreeableMultiPtr (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c..+0x24 | void*[7] | FreeablePtrs | HIGH | FUN_0058f8eb: 7 pointers freed at +0x0c,+0x10,+0x14,+0x18,+0x1c,+0x20,+0x24. Sentinel at +0x0c: `&DAT_008d41cc`. | none |
| +0x224..+0x240 | ptr*3+int*3 | SubBuffers | LOW | FUN_005913d0 NOT FOUND in analyzed/. | Unverifiable |
| +0x0c/+0x1c/+0x20 | ptr*3 | ResourcePtrs | LOW | FUN_0059a17b NOT FOUND in analyzed/. | Unverifiable |

**Note:** First row confirmed (7 sequential pointer slots). Rows 2-3 unverifiable — source files absent.

---

## Section 247: EntityGridManagerStruct

Sources: FUN_00465460 and FUN_00464c10 (both analyzed).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c | int* | ListHead | HIGH | 2 files: traversal start at `*(*param_1+0x6c)` | none |
| +0x74 | int* | ListCurrent | HIGH | 2 files: traversal cursor | none |
| +0x7c | int* | AltListHead | HIGH | 2 files: secondary list head | none |
| +0x84 | int* | AltListCur | HIGH | 2 files: secondary cursor | none |
| +0x2b4 | short | BudgetRemaining | HIGH | Stride 0x230 per-vehicle. `*(ushort *)(base+0x2b4+idx*0x230)` | none |
| +0x2b6 | byte | EntityTypeFilter | HIGH | Per-vehicle at stride 0x230 | none |
| +0x2b8 | int* | EntityPtrs | HIGH | Per-vehicle entity pointer at stride 0x230 | none |
| +0xe410 | int[32] | EntityTypeMap | HIGH | Initialized 0x68 slots at +0xe410, stride 4 | none |
| +0xe5b0 | int* | ActiveListHead | HIGH | 2 files: active processing list | none |
| +0xe5b4 | int* | ActiveListTail | HIGH | 2 files | none |
| +0xe5b8 | int* | ActiveListIter | HIGH | 2 files | none |
| +0xe5bc | int | ActiveListCount | HIGH | 2 files | none |
| +0xe5c0 | int* | WorkListHead | HIGH | 2 files: pending-entity work list | none |
| +0xe5c4 | int* | WorkListTail | HIGH | 2 files | none |
| +0xe5c8 | int* | WorkListIter | HIGH | 2 files | none |
| +0xe5cc | int | WorkListCount | HIGH | 2 files | none |

**Grade: HIGH** for all 16 offsets. Most solidly documented struct in this batch.

**Note:** Access pattern is `*(type *)(*param_1 + offset)` — double indirection (param_1 is ptr-to-struct-ptr).

---

## Section 248: PhysicsBody (solver system) (inferred)

Source: FUN_0056d930 does NOT exist in analyzed/. BodyArray stride 0x244 confirmed by 7+ other files.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| All 13 offsets | various | various | **NONE** | FUN_0056d930 NOT FOUND. Cannot verify. | Unverifiable |

**Partial validation:** FUN_00436870 line 531 accesses `*(double *)(param_1 + 0x23c)` and `*(double *)(param_1 + 0x244)`. Doc says `int` at +0x23c (BarRefCount) but source shows **double**. **CONFLICT: +0x23c is double, not int.**

---

## Section 249: Vehicle Struct (int-indexed from .veh file parser)

Source: FUN_004c3200 (decompiled_all/). param_1 is `undefined4*` — uses INT-INDEX notation.

All 26 offsets verified from source:
- +0x00..+0x08: string pointers (filename, HDVehicle, HeadPhysics, Sounds, Graphics)
- +0x0a: GenString
- +0x0e–+0x1c: float×3 groups (Eyepoint, CameraTarget, MirrorPos, MirrorNorm, SteeringWheelAxis)
- +0x1d–+0x6f: string pointers (Number, Driver, Description, Engine, Manufacturer, Classes)
- +0xaf–+0xef: team info string pointers (FullTeamName, TeamFounded, etc.)
- +0xf5: TrackLivery linked list header

**Grade: HIGH** for all offsets.

**Critical: Doc uses INT-INDEX notation, not byte offsets.** Each `+0xNN` = `param_1[N]` = byte offset N×4. This must be clarified to avoid confusion with byte-offset conventions elsewhere in docs/13.

---

## Section 250: Stream Object Struct

Source: FUN_0059a3a9 (analyzed).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | uint | status/flags | HIGH | `*(uint *)(param_1+4)` OR'd with 4 | none |
| +0x28 | void* | stored reference | HIGH | `*(void**)(param_1+0x28) = param_2` | none |
| +0x2c | void* | zeroed | HIGH | `*(void**)(param_1+0x2c) = 0` | none |
| +0x30 | ushort | buffer/chunk size | HIGH | `*(ushort *)(param_1+0x30)` from FUN_0059b208(0x20) | none |

**Grade: HIGH.** Single function, unambiguous.

---

## Section 251: Animation State Struct (inferred)

Sources: FUN_00486730 and FUN_00403cd0 (both analyzed).

**CRITICAL: This section conflates TWO different structs.**

**Struct A — AnimationDefinition** (returned by FUN_00486460, referenced as `uVar3`):
| Offset | Type | Field | Confidence | Issue |
|--------|------|-------|------------|-------|
| +0x10 | int | maxFrames | LOW | Belongs to uVar3 struct, NOT param_1 |
| +0x18 | float | duration | LOW | Belongs to uVar3. Source uses `float`, doc says `int` |
| +0x1c | int | loopMode | LOW | Belongs to uVar3. Values: 0=wrap, non-0=modulo |
| +0x28 | int | active | LOW | Belongs to uVar3 |

**Struct B — AnimationState** (param_1):
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x80 | float | accumulator | HIGH | `*(float *)(param_1+0x80)` read/written | none |
| +0x84 | int | stateID | HIGH | `*(int *)(param_1+0x84)` passed to FUN_00486460 | none |
| +0x88 | int | frameIndex | HIGH | `*(int *)(param_1+0x88)` incremented | none |
| +0xdc | int | repeatCount | HIGH | `*(int *)(param_1+0xdc)` decremented | none |
| +0x150 | float* | keyframeArray | MEDIUM | `*(float **)(param_1+0x150)` — **pointer**, NOT inline array. Doc says `float[7]` but field is `float*`. | Type mismatch: pointer vs array |

**Corrections needed:**
1. Split into AnimationDefinition (+0x10, +0x18, +0x1c, +0x28) and AnimationState (+0x80, +0x84, +0x88, +0xdc, +0x150).
2. +0x18 is float (not int).
3. +0x150 is float* pointer (not float[7]).

---

## Section 252: Offset conflicts

| Offset | Doc Claim | .c Evidence | Resolution |
|--------|-----------|-------------|------------|
| +0x14 | int flags | **FUN_0054ca00**: `*(uint *)(param+0x14) & 0x8000000` (clip). **FUN_0054d9f0**: `*(uint *)(param+0x14) & 0x400000` (LOD). **FUN_004e2d00**: NO +0x14 usage found. | Same renderer struct (bitfield flags). Remove FUN_004e2d00 reference. |
| +0x20 | different usage | **FUN_0040eb30**: stored param. **FUN_00558d80**: flags (`& 0x100`). **FUN_00558dc0**: byte flag. **FUN_00586d70**: no +0x20 found. | Valid conflict — different struct types. |
| +0x50 | surface ptr | **FUN_00558d80**: `*(int*)(param+0x50)` → surface array. **FUN_00558dc0**: same pattern. **FUN_00558d10**: pixel buffer base. | **SAME** texture manager struct. Correctly identified. |

**Corrections:**
1. +0x14: Remove FUN_004e2d00 reference.
2. +0x20: Remove FUN_00586d70 reference (no +0x20 usage found).

---

## Section 253: OscillatoryCollisionState (FUN_0045c7e0 / FUN_0045c8f0)

Sources: Both functions analyzed.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | Accum0 | HIGH | `*param_1` in FUN_0045c7e0 | none |
| +0x04 | float | Accum1 | HIGH | `param_1[1]` in FUN_0045c7e0 | none |
| +0x08 | float | Accum2 | HIGH | `param_1[2]` in FUN_0045c7e0 | none |
| +0x0C | float | OverflowScaled | MEDIUM | `param_1[3]` stores float (truncated through int cast). Doc says int; source stores float. | Type mismatch |
| +0x10 | float | Accum3 | HIGH | `param_1[4]` in FUN_0045c7e0 | none |
| +0x14 | float | Accum4 | HIGH | `*(float *)(param_1+0x14+idx*4)` in FUN_0045c8f0 | none |
| +0x68 | float | ContactTimer[i] | HIGH | Loop counter (0x68=104) updating float pairs | none |
| +0x1B4 | float | ContactThreshold[i] | HIGH | `*(float *)(param_1+0x1b4+idx*4)` compared vs global | none |
| +0x354 | byte | ContactActive[i] | HIGH | `*(byte *)(param_1+0x354+idx)` incremented, <0x10 check | none |
| +0x3BC | byte | ContactPosIdx[i] | HIGH | `*(byte *)(param_1+0x3bc+idx)` masked &0xf, modulo 16 | none |
| +0x1124 | float | ContactOutput[i] | HIGH | `*(float *)(param_1+0x1124+idx*4) = -1.0f` (0xbf800000) | none |

**Grade: HIGH** for all offsets. Minor: +0x0C is float in source (doc says int).

---

## Section 254: DamageModelSubStruct (PHYSICAL section)

Source: FUN_004f24f0 (decompiled_all/). File parser for .svm/.hdv PHYSICAL section.

**Single-value fields (+0x00 to +0x84): ALL HIGH — verified from source.**

| Offset | Field | Verification |
|--------|-------|-------------|
| +0x00 | RadiusAdd | `FUN_00565870(s_RadiusAdd, param_1)` |
| +0x04 | RadiusMult | `FUN_00565870(s_RadiusMult, param_1+4)` |
| +0x08 | RadiusMax | `FUN_00565870(s_RadiusMax, param_1+8)` |
| +0x0c | EngineCollision | `FUN_00565870(s_Engine, param_1+0xc)` |
| +0x10 | AeroDiv | `FUN_00565870(s_AeroDiv, param_1+0x10)` |
| +0x14 | AeroMin | `FUN_00565870(s_AeroMin, param_1+0x14)` |
| +0x18 | VertMult | `FUN_00565870(s_VertMult, param_1+0x18)` |
| +0x1c | FrontWingDetach | `FUN_00565870(s_FrontWingDetach, param_1+0x1c)` |
| +0x20 | FrontWingRandom | `FUN_00565870(s_FrontWingRandom, param_1+0x20)` |
| +0x24,+0x28,+0x2c | FrontWingPos | `FUN_00565870(s_FrontWingPos, ...)` 3 floats |
| +0x30,+0x34,+0x38,+0x3c | FrontWingMassInertia | 4 floats |
| +0x40,+0x44,+0x48 | FrontWingCollParams | 3 floats |
| +0x4c | RearWingDetach | single float |
| +0x50 | RearWingRandom | single float |
| +0x54,+0x58,+0x5c | RearWingPos | 3 floats |
| +0x60,+0x64,+0x68,+0x6c | RearWingMassInertia | 4 floats |
| +0x70,+0x74,+0x78 | RearWingCollParams | 3 floats |
| +0x7c | WheelBend | single float |
| +0x80 | WheelDetach | single float |
| +0x84 | WheelRandom | single float |

**Wheel loop** (4 wheels, stride 0x1c, iVar2 starts at param_1+0x90):
- Wheel 0: MassInertia +0x88..+0x94, CollParams +0x98..+0xA0
- Wheel 1: MassInertia +0xA4..+0xB0, CollParams +0xB4..+0xBC
- Wheel 2: MassInertia +0xC0..+0xCC, CollParams +0xD0..+0xD8
- Wheel 3: MassInertia +0xDC..+0xE8, CollParams +0xEC..+0xF4
- **Actual span: +0x88 to +0xF4** (doc says +0x88–+0xfc — minor off-by-8)

**Part loop** (8 parts) — **DOC RANGES ARE INCORRECT**:

| Field | Doc Claim | Actual Range | Correction |
|-------|-----------|-------------|------------|
| PartDetach[0..7] | +0x118–+0x158 | **+0xF8 to +0x114** (stride 4) | Off by 0x20 |
| PartRandom[0..7] | NOT DOCUMENTED | **+0x118 to +0x134** (stride 4) | Add to doc |
| PartPos[0..7] | +0x13c–+0x178 | **+0x138 to +0x1F4** (stride 0xc) | Start off by 4, end off by 0x7C |
| PartMassInertia[0..7] | +0x1a0–+0x250 | **+0x198 to +0x2D0** (stride 0x1c) | Start off by 8, end off by 0x80 |
| PartCollParams[0..7] | NOT DOCUMENTED | **+0x1A8 to +0x2DC** (stride 0x1c) | Add to doc |

**Derivation:** `local_3b8 = param_1+0x118` (PartRandom base). `iVar2 = param_1+0x1a0` (MassInertia base). `iVar3 = param_1+0x13c` (Pos base). PartDetach at `local_3b8-0x20` = param_1+0xF8 (not 0x118!). PartRandom at `local_3b8` = param_1+0x118. PartPos at iVar3-4,iVar3,iVar3+4. MassInertia at iVar2-8,-4,0,+4. CollParams at iVar2+8,+0xc,+0x10.

---

## Section 255: Summary

Summary table references 15 structs. All structs in this batch are covered by individual sections above. No new audit findings beyond what's detailed per section.

---

## Section 256: Source: docs/02-ai-system.md (0 offsets)

No offsets to audit.

---

## Section 257: TireCompoundEntry (stride 0x2a8 = 680 bytes)

Sources: FUN_004d6b00 and FUN_004d7570 (both decompiled_all/).

**Stride confirmation:** FUN_004d7570 line 11: `return param_2 * 0x2a8 + *(int *)(param_1 + 0x14)`. Stride 0x2a8 **CONFIRMED.**

**Type confirmation:** FUN_004d6b00 uses `double *pdVar1` casts when accessing fields via FUN_00565aa0. All 5 documented fields are **double**.

**Offset reference:** The doc offsets are relative to the front/rear sub-struct base (iVar3), not absolute to TireCompoundEntry base.
- Front compound base: param_1 + 0x18
- Rear compound base: param_1 + 0x160
- Fields accessed as `iVar3 + offset` where offset is the doc value.

| Offset (rel) | Type | Field Name | Confidence | .c Evidence | Conflicts |
|-------------|------|------------|------------|-------------|-----------|
| +0x0e0 | double | wearRate | HIGH | `FUN_00565aa0(s_WearRate, iVar3+0xe0)` | none |
| +0x0f0 | double | aiSensitivityMin | HIGH | `FUN_00565aa0(s_AISens, iVar3+0xf0, iVar3+0xf8, ...)` | none |
| +0x0f8 | double | aiSensitivityMax | HIGH | Same call, second param | none |
| +0x100 | double | aiGripMult | HIGH | `FUN_00565aa0(s_AIGripMult, iVar3+0x100)` | none |
| +0x110 | double | aiWearMult | HIGH | `FUN_00565aa0(s_AIWear, iVar3+0x110)` | none |

**Grade: HIGH** for all 5 fields. Type confirmed as double (not "likely double"). Moddability confirmed (.tbc file parameters).

**Clarification needed:** These offsets are RELATIVE to front/rear compound sub-struct (base at param_1+0x18 or param_1+0x160). Absolute offsets within TireCompoundEntry differ for front vs rear.

---

## Section 255-256: Summary / Source docs/02-ai-system.md

No additional findings. All structs covered.
