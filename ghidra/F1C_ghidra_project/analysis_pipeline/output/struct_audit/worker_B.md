# STRUCT AUDIT RESULTS — Worker B

Generated: 2026-07-15

Audit of struct offset confidence in docs/13-struct-offsets.md.
Struct sections 16-30 assigned to Worker B.

---

## Section 16: Source: docs/06-session-race-logic.md

0 offsets — skipped.

---

## Section 17: ViewportStruct (param_1 — viewport/render target)

Confidence in docs: **medium**.
Audit verdict: **UPGRADE to HIGH** — all offsets verified.

| Offset | Docs Type | Actual Type | Verdict | Notes |
|--------|-----------|-------------|---------|-------|
| +0x54 | int Width | int | **VERIFIED** | FUN_005425a0: `*(int *)(param_1 + 0x54)` |
| +0x58 | int Height | int | **VERIFIED** | FUN_005425a0: `*(int *)(param_1 + 0x58)` |
| +0x68 | int XOffset | int | **VERIFIED** | FUN_005425a0: `*(int *)(param_1 + 0x68)` |
| +0x15c | ptr LocalData | ptr | **VERIFIED** | FUN_005425a0: `param_1 + 0x15c` passed as pointer arg |
| +0x234 | int RenderTarget1 | int (undefined4) | **VERIFIED** | FUN_0054c110: `*(undefined4 *)(param_1 + 0x234)` |
| +0x238 | int RenderTarget2 | int (undefined4) | **VERIFIED** | FUN_0054c110: `*(undefined4 *)(param_1 + 0x238)` |
| +0x03c | uint DirtyFlags | uint | **VERIFIED** | FUN_0054c110: `*(uint *)(param_1 + 0x3c)` bitmask ops |

**New offset discovered:**
| Offset | Type | Name | Found In | Notes |
|--------|------|------|----------|-------|
| +0x64 | int | YOffset | FUN_005425a0 | Used as Y boundary clamp, parallel to +0x68 (XOffset). `*(int *)(param_1 + 100)` — 100 decimal = 0x64. |

All 7 documented offsets verified. All types match. ViewportStruct confidence should be **HIGH** (was medium).

---

## Section 18: LinkedList (inferred)

Confidence in docs: medium (no explicit grade).
Audit verdict: **CONFLICTS FOUND — field names/meanings wrong.**

| Offset | Docs Type/Name | Actual Type | Verdict |
|--------|----------------|-------------|---------|
| +0x00 | ptr HeadPtr | ptr | **VERIFIED** | `*param_1` in FUN_005819c0, FUN_00586000 |
| +0x04 | ptr TailPtr | ptr | **VERIFIED** | `param_1[1]` in FUN_005819c0, FUN_00586000 |
| +0x08 | int Count | **ptr** | **CONFLICT** | FUN_00586000 writes `param_1[2] = (int)piVar3` (node address). Cannot be int Count — receives pointer value. Probably a 2nd tail/iterator pointer. |
| +0x0c | int Capacity | **int (counter)** | **REASSIGN** | FUN_00586000: `param_1[3] = iVar1 + 1` — incremented on each insert. Acts as **Count**, not fixed Capacity. |

**Corrections needed:**
- +0x08: Change type to `ptr`, rename to `LastAccessedPtr` or `IteratorPtr`
- +0x0c: Change name from `Capacity` to `Count` (incremented, not pre-allocated)

---

## Section 19: RigidBodyState (inferred)

Confidence in docs: **high**.
Audit verdict: **OVERLAP/BUGS FOUND — 3 critical issues, 1 duplicate.**

### Overlap 1: +0x000 Pad/Mass? overlaps with +0x004 PosX
FUN_00448e90 zeros 6 ints (24 bytes) from +0x00. A double at +0x000 would span bytes 0-7 while double at +0x004 spans bytes 4-11 — overlapping at bytes 4-7. Since +0x004 is confirmed as double PosX by 6+ functions, +0x000 cannot be a separate double.

**Fix:** Change +0x000 from `double Pad/Mass?` to `int[6] Reserved/Unused` or padding.

### Overlap 2: +0x014 double PosZ overlaps with +0x018 ActiveFlag et al
`*(double *)(param_1 + 0x14)` reads 8 bytes (+0x14 to +0x1b). But init writes byte metadata at +0x18 (ActiveFlag=1), +0x19 (BVType=0), +0x1a-1b (CollisionGroupID=0xFFFF). These 4 bytes are INSIDE the claimed double range.

**Fix:** PosZ might be `float` at +0x014 (4 bytes), with Ghidra misreading float-to-double promotion. Or there's a 4-byte gap. Needs assembly inspection. **Mark LOW confidence on PosZ.**

### Issue 3: Wrong field names +0x064/0x06c/0x074
FUN_00441ad0 computes: `SQRT(*(double*)(iVar2+0x74)² + *(double*)(iVar2+0x6c)² + *(double*)(iVar2+100)²)` — this is velocity magnitude. But 100-decimal = 0x64, not +0x074.

Wait, let me re-check. Line 18-20 of FUN_00441ad0:
`*(double *)(iVar2 + 0x74)` 
`*(double *)(iVar2 + 0x6c)`
`*(double *)(iVar2 + 100)` — 100 decimal = 0x64

So the velocity vector is at:
- +0x6c: VelocityX? No — the docs say +0x6c = ForceAccumZ0/VelocityX, and +0x64 = ForceAccumY0
- +0x64 = VelocityX component (used in SQRT as vx)
- +0x6c = VelocityY component
- +0x74 = VelocityZ component

So the velocity vector is at +0x64, +0x6c, +0x74 (not at +0x060 as doc suggests).

**Fix:** Rename:
- +0x060: keep as ForceAccumX0 (separate from velocity, confirmed in FUN_00441d60)
- +0x064: Rename from `ForceAccumY0` to `VelocityX`
- +0x06c: Rename from `ForceAccumZ0/VelocityX?` to `VelocityY`  
- +0x074: Rename from `VelocityY?` to `VelocityZ`

### Issue 4: Duplicate field at +0x22c
Both `RingBufferIndex` and `EntityCount` documented at same offset +0x22c. FUN_00569860 uses as write index (increments after write). FUN_0056a390 uses as loop limit. Same field — after N writes, index == count.

**Fix:** Merge into single entry: `RingBufferIndex/EntityCount`.

### Verified offsets (no changes needed):
| Offset | Field | Evidence |
|--------|-------|----------|
| +0x004 | double PosX | 6+ functions agree |
| +0x00c | double PosY | 6+ functions agree |
| +0x014 | double PosZ | **LOW CONFIDENCE** — overlaps with +0x18 metadata |
| +0x018 | byte ActiveFlag | FUN_00448e90: byte=1 |
| +0x019 | byte BVType/Flags | FUN_00448e90: byte=0 |
| +0x01a | short CollisionGroupID | FUN_00448e90: short=0xFFFF |
| +0x01c–+0x05c | double RotMatrix[3][3] | 9 entries, 5+ functions agree |
| +0x0b4 | double ScaleFactor | FUN_00569670, FUN_00569410 |
| +0x0bc/+0x0c4/+0x0cc | double DiagonalScale[0-2] | FUN_00569410, FUN_00438130 |
| +0x0ec–+0x12c | double InertiaTensor[3][3] | FUN_00569670, FUN_005691d0 |
| +0x134/+0x13c/+0x144 | double LinearMomentumAccum XYZ | 5+ functions agree |
| +0x14c/+0x154/+0x15c | double AngularMomentumAccum XYZ | 7+ functions agree |
| +0x07c/+0x084/+0x08c | double TransformResult XYZ | FUN_005691d0, FUN_00435e00, FUN_004359a0 |
| +0x094/+0x09c/+0x0a4 | double InputVector XYZ | FUN_005691d0, FUN_00569670 |
| +0x224 | double* AccumulatorArray | FUN_0056a390 |
| +0x22c | int RingBufferIndex/EntityCount | merge duplicates |
| +0x230 | double* RingBufferBase | FUN_00569860 |

---

## Section 20: PhysicsQueryStruct

Confidence in docs: **medium**.
Audit verdict: **UPGRADE to HIGH** — all offsets verified, no conflicts.

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x0c | byte ReadyFlag | byte | **VERIFIED** | `*(char *)(param_1 + 0xc)`, compared to '\0' |
| +0x10 | double ReferenceValue | double | **VERIFIED** | `*(double *)(param_1 + 0x10)` |
| +0x18 | double DeltaValue | double | **VERIFIED** | `*(double *)(param_1 + 0x18)` |
| +0x20 | byte[] DataBuffer | byte[] | **VERIFIED** | `param_1 + 0x20` returned as data base |
| +0x120 | int DataCount | int | **VERIFIED** | `*(int *)(param_1 + 0x120)` |

All types and positions correct. No undocumented offsets found.

---

## Section 21: PerWheelTireCompound (inferred)

Confidence in docs: **high**.
Audit verdict: **DOWNGRADE to MEDIUM** — 11+ type conflicts, many undocumented offsets.

### Type conflicts (docs=float, code=double):
| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x21c | float CamberFactor1 | double | **CONFLICT** — 8-byte write |
| +0x224 | float CamberFactor2 | double | **CONFLICT** — 8-byte write |
| +0x22c | float LoadSensitivity | double | **CONFLICT** — 8-byte write |
| +0x280 | float TireWidth | double | **CONFLICT** — 8-byte write |
| +0x290 | float TireWidth2 | double | **CONFLICT** — 8-byte write |
| +0x2e4 | float LoadNormalization | double | **CONFLICT** — 8-byte write |
| +0x2f4 | float OptimumCamber | double | **CONFLICT** — 8-byte write |
| +0x2fc | float CamberSensitivity | double | **CONFLICT** — 8-byte write |
| +0x30c | float CamberSlope | double | **CONFLICT** — 8-byte write |
| +0x334 | float OptimumTemp | double | **CONFLICT** — 8-byte write |
| +0x3cc | float WearRate | double | **CONFLICT** — 8-byte write |

### Same-offset duplicate:
| Offset | Issue |
|--------|-------|
| +0x08 | Claimed as BOTH `compound[1]` (unknown) AND `TireRadiusMax` (float). Neither confirmed — no writes to +0x08. TireRadiusMax SOURCE data (pdVar15[1]) goes to +0x288, not +0x08. |

### Conditional double-overlap warnings (DAT_007ce958 path):
- +0x234/+0x238: GripMultiplier/GripMultiplier2 — treated as double in racing mode
- +0x384/+0x388: BaseGrip/GripFactor — treated as double in racing mode
- +0x38c/+0x390: SensFactor/SensFactor2 — treated as double in racing mode

### Verified offsets (type OK):
+0x20c, +0x210, +0x214, +0x218 (GripParam1-4, float agrees), +0x234, +0x238 (GripMultiplier), +0x2d8/2dc/2e0 (ptr SlipCurves), +0x304 (CamberFactorMain), +0x34c (CamberSensitivityTable), +0x384-0x398 (BaseGrip through WearInit1)

### Key new offsets discovered:
| Offset | Type | Notes |
|--------|------|-------|
| +0x27c | float | Upper 4 bytes of TireRadiusMin |
| +0x28c | float | Upper 4 bytes of TireRadiusMax |
| +0x124-+0x12c | float[3] | Grip normalization workspace |
| +0x44c-+0x460 | float[6] | Duplicate copy of compound/spring data |
| +0x36c | double | Overlaps CamberSensitivityTable[8][9] |
| +0x32c-0x3c8 | various | pdVar15 sourced data for wear/grip |

---

## Section 22: Standings / Scoring Struct (int-indexed)

Confidence in docs: **medium**.
Audit verdict: **UPGRADE to HIGH** — all offsets verified.

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x18 + i*4 | int FINISHPOSITION[48] | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |
| +0xd8 + i*4 | int FINISHPOINTS[48] | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |
| +0x198 | int SEASONPOINTS | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |
| +0x1a0 | int POLESTAKEN | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |
| +0x1a4 | int ORIGINALGRIDPOSITION | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |
| +0x1a8 | int CURRENTGRIDPOSITION | int | **VERIFIED** | FUN_004c0910, FUN_004c03f0 |

**New offsets discovered:**
| Offset | Type | Name | Found In |
|--------|------|------|----------|
| +0x19c | int | POINTSPOSITION | FUN_004c03f0 |
| +0x1ac | int | CONTROLTYPE | FUN_004c03f0 |
| +0x1b0 | bool | ACTIVE | FUN_004c03f0 |

---

## Section 23: UI State Struct

Confidence in docs: **low**.
Audit verdict: **UPGRADE to MEDIUM** — both offsets verified.

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0xf4 | byte flag | byte | **VERIFIED** | `*(undefined1 *)(param_1 + 0xf4) = 0` |
| +0xf5 | byte flag | byte | **VERIFIED** | `*(undefined1 *)(param_1 + 0xf5) = 0` |

Both zeroed on reset. Single function observation — remains low confidence for general struct definition.

---

## Section 24: D3D Vertex Buffer Object (inferred)

Confidence in docs: **medium**.
Audit verdict: **UPGRADE to HIGH** — all offsets verified from FUN_0054ca00.

| Offset | Docs Type | Actual Type | Verdict | Notes |
|--------|-----------|-------------|---------|-------|
| +0x14 | int flags | uint | **VERIFIED** | Bitmask: 0x8000000=clip, 0x800000=alpha |
| +0x118 | int numBlocks | int | **VERIFIED** | Used as loop bound for block processing |
| +0x11c | ptr blockArray | ptr (int*) | **VERIFIED** | Dereferenced as array + 0x38 stride |
| +0x138 | ptr devicePtr | ptr (int*) | **VERIFIED** | Dereferenced as device struct + 0x3c |

All types, positions, and field semantics confirmed from source. No new offsets found.

---

## Section 25: BVH/SpatialTreeNode (inferred)

Confidence in docs: **high**.
Audit verdict: **CONFIRMED HIGH** — all 12 offsets verified, 1 new offset discovered.

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x08 | short NodeIdx | short | **VERIFIED** | Negative=leaf, 0=axis test |
| +0x0A | short AxisIdx | short | **VERIFIED** | Axis selector for comparison |
| +0x0C | int* ChildPtr | int*/float* | **VERIFIED** | Child/sibling node pointer |
| +0x3C | float Stride | float | **VERIFIED** | Element stride |
| +0x94 | float PosX | float | **VERIFIED** | 3 functions agree |
| +0x98 | float PosY | float | **VERIFIED** | 3 functions agree |
| +0x9C | float PosZ | float | **VERIFIED** | 3 functions agree |
| +0xA4 | float NormalX | float | **VERIFIED** | Split plane normal |
| +0xAC | float NormalZ | float | **VERIFIED** | Split plane normal |
| +0x10C | int* NextPrimary | int* | **VERIFIED** | Primary child link |
| +0x110 | int* NextSecondary | int* | **VERIFIED** | Sibling/alternate link |
| +0x12C | int CategoryTag | int | **VERIFIED** | Match filter/type field |

**New offset discovered:**
| Offset | Type | Name | Found In | Notes |
|--------|------|------|----------|-------|
| +0x114 | int* | TagRedirect | FUN_00403aa0 | Alternative node pointer when CategoryTag doesn't match; redirects search to tagged sibling |

---

## Section 26: ImpulseAccumulator (inferred — param_1 in FUN_0044fee0)

Confidence in docs: **medium**.
Audit verdict: **UPGRADE to HIGH** — all 6 offsets verified.

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x560 | double LinearImpulseX | double | **VERIFIED** | `*(double *)(param_1 + 0x560) += param_2[0]` |
| +0x568 | double LinearImpulseY | double | **VERIFIED** | `param_2[1] + *(double *)(param_1 + 0x568)` |
| +0x570 | double LinearImpulseZ | double | **VERIFIED** | `param_2[2] + *(double *)(param_1 + 0x570)` |
| +0x578 | double AngularImpulseX | double | **VERIFIED** | `*(double *)(param_1 + 0x578) += param_3[0]` |
| +0x580 | double AngularImpulseY | double | **VERIFIED** | `param_3[1] + *(double *)(param_1 + 0x580)` |
| +0x588 | double AngularImpulseZ | double | **VERIFIED** | `param_3[2] + *(double *)(param_1 + 0x588)` |

All types and positions confirmed. No new offsets.

---

## Section 27: Source: docs/09-track-system.md

0 offsets — skipped.

---

## Section 28: AudioStreamStruct (inferred)

Confidence in docs: **medium**.
Audit verdict: **1 CONFLICT found.**

| Offset | Docs Type | Actual Type | Verdict |
|--------|-----------|-------------|---------|
| +0x24a4 | void* InputBufferPtr | void* | **VERIFIED** | Stored as int, null-checked as pointer |
| +0x24a8 | int BitPosition | int | **VERIFIED** | Bitstream read position |
| +0x24bc | int RingBufIndex | **byte** | **CONFLICT** | Code: `*(byte *)(param_1 + 0x24bc)` — all accesses are byte (4-bit ring index, masked & 0xf) |
| +0x24cc | int EntryCount | int | **VERIFIED** | Compared as `== 2` (stereo) |
| +0x24d0 | int OutputStride | int | **VERIFIED** | Output byte stride per channel |

**Correction needed:** Change +0x24bc type from `int` to `byte`.

---

## Section 29: Struct 3: Waypoint Struct (stride 0x13c = 316 bytes)

Confidence in docs: **medium**.
Audit verdict: **MAJOR ISSUE — offsets appear to be int-indexed, not byte offsets.**

### Critical finding:
All documented offsets use param_1[N] (int-indexed) in FUN_00402690, where `piVar5` is `int*`. 
**Real byte offset = documented_offset × 4.** The docs show values as if they were byte offsets, but they're actually word indices.

### Corrected offsets:
| Docs Offset (wrong) | Real Byte Offset | Type | Name | Verdict |
|---------------------|-------------------|------|------|---------|
| +0x00 | +0x00 | float[3] | Position | **OK type** — piVar5[0..2] |
| +0x08 | +0x20 | float[3] | PerpVector | **OK type** — piVar5[8..10] |
| +0x0b | +0x2c | float[4] | Width | **OK type** — piVar5[0xb..0xe] |
| +0x12 | +0x48 | int/float | Score | **OK** — piVar5[0x12] |
| +0x16 | +0x58 | float[4] | DWidth | **OK type** — piVar5[0x16..0x19] |
| +0x21 | +0x84 | int (not byte[2]) | Event | **CONFLICT** — docs byte[2], code shows int |
| +0x25 | +0x94 | float[3] | PosBackup | **OK type** — piVar5[0x25..0x27] |
| +0x46 | +0x118 | int (not byte) | GAlpha | **CONFLICT** — docs byte, code shows int |
| +0x47 | +0x11c | int (not byte) | GrooveLat | **CONFLICT** — docs byte, code shows int |
| +0x48 | +0x120 | ptr[3] | NextPtrs | **OK type** — piVar5[0x48..0x4a] |
| +0x4b | +0x12c | int (not byte) | BranchID | **CONFLICT** — docs byte, code shows int |
| +0x4c | +0x130 | int (not byte) | Bitfields | **CONFLICT** — docs byte, code shows int |
| +0x4d | +0x134 | int[2] (not byte[2]) | Wpse | **CONFLICT** — docs byte[2], code shows int[2] |
| +0x110 | — | ptr | NextWpPtr | **NOT VERIFIED** — not found in FUN_00402690 |

### Overlap concern resolution:
The overlap concerns in docs are **ARTIFACTS** of treating int-indices as byte offsets. Real byte layout (after ×4 conversion) has NO overlaps.

### Missing fields:
| Real Offset | Type | Name | Found In |
|-------------|------|------|----------|
| +0x18-0x1f | int[2] | wp_path | piVar5[6..7], accessed via string "wp_path" |
| +0x44 | int | (adjacent to Score) | piVar5[0x11], integer conversion from score |

### Total accounted:
128 bytes verified out of 0x13c (316 bytes) stride. 188 bytes unaccounted.

---

## Section 30: Source: docs/05-weather-system.md

0 offsets — skipped.

---

## MASTER CORRECTIONS SUMMARY

### Critical corrections needed:

| Section | Offset | Issue | Fix |
|---------|--------|-------|-----|
| 18 (LinkedList) | +0x08 | Docs=int Count, actual=ptr | Change type to ptr, rename |
| 18 (LinkedList) | +0x0c | Docs=Capacity, actual=Count (counter) | Rename to Count |
| 19 (RigidBodyState) | +0x000 | double Pad/Mass overlaps with +0x004 | Change to int[6] Reserved |
| 19 (RigidBodyState) | +0x014 | double PosZ overlaps +0x18 metadata | Mark LOW confidence, possibly float |
| 19 (RigidBodyState) | +0x064/0x06c/0x074 | Wrong field names (ForceAccum → Velocity) | Rename to VelocityX/Y/Z |
| 19 (RigidBodyState) | +0x22c | Duplicate: RingBufferIndex & EntityCount | Merge to single entry |
| 21 (PerWheelTire) | +0x08 | Duplicate + wrong | Remove both entries, TireRadiusMax at +0x288 |
| 21 (PerWheelTire) | 11 offsets | Docs=float, actual=double | Change type to double |
| 28 (AudioStream) | +0x24bc | Docs=int, actual=byte | Change type to byte |
| 29 (Waypoint) | ALL | Offsets are int-indices, not byte | Multiply all by 4, fix types |

### Verdict confidence adjustments:

| Section | Previous | New | Reason |
|---------|----------|-----|--------|
| 17 ViewportStruct | medium | **HIGH** | All 7 offsets verified |
| 19 RigidBodyState | high | **MEDIUM** | 3 significant issues found |
| 20 PhysicsQueryStruct | medium | **HIGH** | All 5 offsets verified, clean |
| 21 PerWheelTireCompound | high | **LOW** | 11+ type conflicts, 0x08 duplicate |
| 22 Standings | medium | **HIGH** | All 6 offsets verified |
| 24 D3D Vertex Buffer | medium | **HIGH** | All 4 offsets verified |
| 25 BVH/SpatialTree | high | **HIGH** | All 12 verified, 1 new found |
| 26 ImpulseAccumulator | medium | **HIGH** | All 6 offsets verified |
| 28 AudioStream | medium | **MEDIUM** | 1 conflict (+0x24bc type) |
| 29 Waypoint | medium | **LOW** | Systematic offset misalignment |

---

## NEW OFFSETS DISCOVERED

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| ViewportStruct | +0x64 | int YOffset | FUN_005425a0 | Y boundary clamp |
| BVH/SpatialTree | +0x114 | int* TagRedirect | FUN_00403aa0 | Category tag redirect |
| Standings | +0x19c | int POINTSPOSITION | FUN_004c03f0 | |
| Standings | +0x1ac | int CONTROLTYPE | FUN_004c03f0 | |
| Standings | +0x1b0 | bool ACTIVE | FUN_004c03f0 | |
| PerWheelTire | +0x27c | float | FUN_0043da10 | Upper half TireRadiusMin |
| PerWheelTire | +0x28c | float | FUN_0043da10 | Upper half TireRadiusMax |
| PerWheelTire | +0x124-0x12c | float[3] | FUN_0043da10 | Grip normalization workspace |
| AudioStream | +0x24b9 | — | FUN_0052e6f0 | Byte between InputBufferPtr and BitPosition |
| Waypoint | +0x18-0x1f | int[2] wp_path | FUN_00402690 | piVar5[6..7] |
| Waypoint | +0x44 | int | FUN_00402690 | piVar5[0x11], adj to Score |
