=== AUDIT RESULTS ===

## Section 258 — Linked List Node (generic, multiple layouts)

All 5 layouts verified against actual .c source files. All offsets are int (pointer), matching docs/13.

**Layout A (+0x100 HeadPtr, +0x104 NextPtr):**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x100 | ptr | HeadPtr | HIGH | FUN_0054a270 (L11, L17, L21), FUN_0054a2d0 (L15) | none |
| +0x104 | ptr | NextPtr | HIGH | FUN_0054a270 (L13, L16, L18, L23), FUN_0054a2d0 (L42) | none |

**Layout B (+0x204 head, +0x10 NextNode, +0x140 PrevNode):**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x204 | ptr | ListHead | HIGH | FUN_0054abe0 (L11, L13), FUN_0054ac30 (L14) | none |
| +0x10 | ptr | NextNode | HIGH | FUN_0054abe0 (L15, L18, L21, L23), FUN_0054ac30 (L9, L11, L15) | none |
| +0x140 | ptr | PrevNode | HIGH | FUN_0054abe0 (L14, L22), FUN_0054ac30 (L8, L12) | none |

**Layout C (+0x1ac parent, +0x1b0 listhead, +0x1b4 prev, +0x1b8 next):**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1ac | ptr | ParentPtr | HIGH | FUN_005419d0 (L34) | none |
| +0x1b0 | ptr | ListHead | HIGH | FUN_005419d0 (L21, L23) | none |
| +0x1b4 | ptr | PrevPtr | HIGH | FUN_005419d0 (L12, L16, L32) | none |
| +0x1b8 | ptr | NextPtr | HIGH | FUN_005419d0 (L13, L15, L27, L30, L33) | none |

**Layout D (+0x1e4 prev, +0x1e8 next):**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1e4 | ptr | PrevPtr | HIGH | FUN_0053c5d0 (L20, L25) | none |
| +0x1e8 | ptr | NextPtr | HIGH | FUN_0053c5d0 (L13, L17, L19, L21, L26) | none |

**Layout E (+0xf8 list, +0x1b4 prev, +0x1b8 next):**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xf8 | ptr | ListHead | HIGH | FUN_00545090 (L14) | none |
| +0x1b4 | ptr | Prev | HIGH | FUN_00545090 (L8, L12) | none |
| +0x1b8 | ptr | Next | HIGH | FUN_00545090 (L9, L11, L15) | none |

**Overall Section 258: ALL CONFIRMED. No conflicts.**

---

## Section 259 — Unused Empty Struct Offset Headers

63 functions listed with empty **Struct offsets** headers. Spot-checked 5 (FUN_0053e410, FUN_005820c0, FUN_00584340, FUN_005866f0, FUN_00588910) — all confirmed as having no offset data in their doc entries. No action needed.

---

## Section 260 — Bounds2D (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x120 | int | XMin | LOW | FUN_005977c4 — .c file NOT FOUND in analyzed/ or decompiled_all/ | none |
| +0x124 | int | XMax | LOW | FUN_005977c4 not found | none |
| +0x140 | int | YMin | LOW | FUN_005977c4 not found | none |
| +0x144 | int | YMax | LOW | FUN_005977c4 not found | none |

**Overall Section 260: LOW confidence. All 4 offsets rely on a single function (FUN_005977c4) with no .c source file available for verification.**

---

## Section 261 — SuspensionDamperCoeffs

From FUN_00436470 (1 function observation). All offsets confirmed as double.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | double | BiasA | MEDIUM | FUN_00436470 L10: `*(double *)(param_1 + 4)` | none |
| +0x0c | double | LinearA | MEDIUM | FUN_00436470 L9: `*(double *)(param_1 + 0xc)` | none |
| +0x14 | double | QuadA | MEDIUM | FUN_00436470 L9: `*(double *)(param_1 + 0x14)` | none |
| +0x1c | double | BiasB | MEDIUM | FUN_00436470 L13: `*(double *)(param_1 + 0x1c)` | none |
| +0x24 | double | LinearB | MEDIUM | FUN_00436470 L12: `*(double *)(param_1 + 0x24)` | none |
| +0x2c | double | QuadB | MEDIUM | FUN_00436470 L12: `*(double *)(param_1 + 0x2c)` | none |
| +0x34 | double | ResultA | MEDIUM | FUN_00436470 L8: `*(double *)(param_1 + 0x34)` | none |
| +0x3c | double | ResultB | MEDIUM | FUN_00436470 L11: `*(double *)(param_1 + 0x3c)` | none |

**Overall Section 261: All types CONFIRMED. Confidence MEDIUM (only 1 function). Structure shape consistent with quadratic spring computation (2 channels × 3 coeffs + 2 results).**

---

## Section 262 — JointHingeBarStruct (inferred)

From FUN_0056d930 (decompiled_all). Used by JointArray/HingeArray with stride 0x30.

**CRITICAL CONFLICT: +0x14 type is WRONG in docs/13.**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | NameString | MEDIUM | FUN_0056d930 L353-354: `operator_new` + `*(void**)(iVar12 + param_1[3])` = char* alloc | none |
| +0x04 | (ptr) | NegBodyPtr | MEDIUM | FUN_0056d930 L311: `*(int*)(param_1[3] + 4 + iVar12) = ...` | none |
| +0x08 | double | DerivedSpring1 | LOW | FUN_0056d930 L570: `*(undefined4 *)(iVar5 + 8) = uVar9;` — 4-byte write, NOT double | CONFLICT: docs say double, code writes 4 bytes |
| +0x0c | (ptr) | PosBodyPtr | MEDIUM | FUN_0056d930 L314, L342: negbody/posbody string matching, both stored in stride 0x30 array | none |
| +0x10 | double | DerivedSpring2 | LOW | FUN_0056d930 L572: `*(undefined4 *)(iVar5 + 0x10) = uVar10;` — 4-byte write, NOT double | CONFLICT: docs say double, code writes 4 bytes |
| +0x14 | double[6] | PositionOrientation | **WRONG** | FUN_0056d930 L561-567: reads 6× undefined4 (4 bytes each) from +0x14 | **CONFLICT: docs say double[6] (48 bytes), code reads 6×4=24 bytes. Stride 0x30+0x14=0x44 overflow if double** |
| +0x2c | int | LinkCounter | MEDIUM | FUN_0056d930 L371: `*(int*)(param_1[3] + 0x2c + iVar12) = local_624` | none |
| +0x30 | — | StructStride | HIGH | FUN_0056d930 L373: `iVar12 = iVar12 + 0x30` | none. But also used by HingeArray (L408) with same stride |

**Correction needed: +0x14 should be float[6] (not double[6]). +0x08 and +0x10 are float or unknown (4 bytes), not double. If all fields 4 bytes: 0x00(4)+0x04(4)+0x08(4)+0x0c(4)+0x10(4)+0x14-0x28(24)+0x2c(4) = 48 = 0x30. ✓**

---

## Section 263 — Vehicle Array Entry (stride 0x424)

Based on 4+ functions confirmed using stride 0x424. **SYSTEMATIC OFFSET ERROR in early fields.**

The .c code uses `undefined4*` (word) indexing, but docs/13 lists some offsets as word indices (not byte offsets). Fields loaded via FUN_004c3200 use `param_1 + N` where N is a WORD index into undefined4*. Actual byte offset = N × 4.

| Offset (actual) | Offset (doc) | Type | Field Name | Confidence | .c Evidence | Conflicts |
|-|-|-|-|-|-|-|
| +0x00 | +0x00 | char* | filename | HIGH | FUN_004c3200 L42, FUN_004c78f0 L32, etc. | none |
| +0x08 | +0x02 | char* | HDVehicle file path | MEDIUM | FUN_004c3200 L219: `param_1 + 2` (word index 2) | **DOC OFFSET WRONG: +0x02 should be +0x08** |
| +0x10 | +0x04 | char* | HeadPhysics file path | MEDIUM | FUN_004c3200 L220: `param_1 + 4` | **DOC OFFSET WRONG: +0x04 should be +0x10** |
| +0x18 | +0x06 | char* | Sounds file path | MEDIUM | FUN_004c3200 L222: `param_1 + 6` | **DOC OFFSET WRONG: +0x06 should be +0x18** |
| +0x20 | +0x08 | char* | Graphics file path | MEDIUM | FUN_004c3200 L221: `param_1 + 8` | **DOC OFFSET WRONG: +0x08 should be +0x20** |
| +0x28 | +0x0a | char* | GenString | MEDIUM | FUN_004c3200 L77: `param_1 + 0xa` | **DOC OFFSET WRONG: +0x0a should be +0x28** |
| +0x38 | +0x0e | float | EyepointX | MEDIUM | FUN_004c3200 L78-79: `param_1 + 0xe` as float[3] | **DOC OFFSET WRONG: +0x0e should be +0x38** |
| +0x3c | +0x0f | float | EyepointY | MEDIUM | FUN_004c3200 L79: `param_1 + 0xf` | same issue |
| +0x40 | +0x10 | float | EyepointZ | MEDIUM | FUN_004c3200 L79: `param_1 + 0x10` | same issue |
| +0x44 | +0x11 | float | CameraTargetX | MEDIUM | FUN_004c3200 L93 | same issue |
| ... | ... | ... | ... | ... | ... | ... |

**Late offsets (from DAT_007c54e8 vehicle struct) are confirmed correct:**
| +0x403c | +0x403c | int | SeasonPoints | HIGH | FUN_004c2a80 L21, L28 | none |
| +0x4060 | +0x4060 | int | FinishPosition | HIGH | FUN_004c2a80 L30 | none |
| +0x4064 | +0x4064 | int | FinishState | HIGH | FUN_004c2a80 L38 | none |
| +0x409c | +0x409c | float | BestLapTime | HIGH | FUN_004c2a80 L22-24 | none |
| +0x4620 | +0x4620 | char* | DriverName | HIGH | FUN_004c78f0 L18, FUN_004c7b50 L13 | none |
| +0x4660 | +0x4660 | char[] | Nationality | HIGH | FUN_004c78f0 L16, L23 | none |
| +0x4677 | +0x4677 | char | null terminator | HIGH | FUN_004c78f0 L17, L24 | none |
| +0x4678 | +0x4678 | char* | Description | HIGH | FUN_004c78f0 L27 (from .veh +0x3f) | none |
| +0x46b8 | +0x46b8 | char* | Number | HIGH | FUN_004c78f0 L29, FUN_004c7b50 L25 | none |
| +0x4714 | +0x4714 | char* | VehicleDescription | HIGH | FUN_004c78f0 L36, FUN_004c7b50 L13 | none |
| +0x4898 | +0x4898 | int | VehicleIndex | HIGH | FUN_004c78f0 L43, FUN_004c7b50 L16 | none |
| +0x489c | +0x489c | int | DriverNumber | HIGH | FUN_004c7b50 L14 | none |
| +0x48a0 | +0x48a0 | int | (unknown) | MEDIUM | FUN_004c7b50 L26 | none |

**New field found:**
- +0x48a4: `*(int *)(param_1 + 0x48a4)` in FUN_004c6c40 — flag set to -1 after load

**Correction needed: All offsets in the 0x00–0x28 range listed as +0x02, +0x04, +0x06, +0x08, +0x0a, +0x0e..+0x1c are word indices, not byte offsets. Multiply by 4 to get actual byte offsets.**

---

## Section 264 — Buffered I/O Stream Struct

From FUN_00599081 (analyzed/). All 3 offsets CONFIRMED.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | vtablePtr | MEDIUM | FUN_00599081 L17: `*param_1` = vtable, called at L18 (+0x14/0x08) | none |
| +0x1c | byte* | BufferPtr | HIGH | FUN_00599081 L13: `*(byte**)param_1[7]` = param_1 + 0x1c | none |
| +0x2c | int* | BufferEnd | HIGH | FUN_00599081 L14: `*(int*)param_1[0xb]` = param_1 + 0x2c | none |

**Overall Section 264: CONFIRMED. Note: struct also has virtual method table at vtablePtr (+0x00), with methods at vtable+0x14 and vtable+0x08.**

---

## Section 265 — Buffer/Mesh Allocation Struct (inferred)

From FUN_00403350 (analyzed/). All 11 offsets CONFIRMED.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | initializedFlag | HIGH | FUN_00403350 L27: `*(undefined4*)(param_1+8)=1` | none |
| +0x0c | int | countA | HIGH | FUN_00403350 L25: `*(int*)(param_1+0xc)=iVar1` | none |
| +0x10 | int | countB | HIGH | FUN_00403350 L26: `*(int*)(param_1+0x10)=iVar4` | none |
| +0x14 | int | totalCount | HIGH | FUN_00403350 L28: `*(int*)(param_1+0x14)=iVar4+*(int*)(param_1+0x164)` | none |
| +0x150 | ptr | bufferBPtr | HIGH | FUN_00403350 L14: `*(int*)(param_1+0x150)`, L32: alloc dimB×0x1C | none |
| +0x154 | ptr | bufferAPtr | HIGH | FUN_00403350 L17: `*(int*)(param_1+0x154)`, L30: alloc dimC×0x1C | none |
| +0x158 | ptr | bufferCPtr | HIGH | FUN_00403350 L20: `*(int*)(param_1+0x158)`, L33: alloc dimD×dimC×0x1C | none |
| +0x15c | int | dimA | HIGH | FUN_00403350 L23: `*(int*)(param_1+0x15c)+1` | none |
| +0x160 | int | dimB | HIGH | FUN_00403350 L24: `*(int*)(param_1+0x160)` | none |
| +0x164 | int | dimC | HIGH | FUN_00403350 L28: `*(int*)(param_1+0x164)` | none |
| +0x168 | int | dimD | HIGH | FUN_00403350 L33: `*(int*)(param_1+0x168)` | none |

**Overall Section 265: ALL CONFIRMED. Confidence HIGH. 3 buffer pointers (A/B/C) with 4 dimension fields managing multi-dimensional 0x1C-byte element arrays.**

---

## Section 266 — Notes

No offsets to verify. Commentary about RenderContext, UI patterns, offset 0x14 polymorphism. Informational only.

---

## Section 267 — CollisionProxyRegistration

From FUN_0044f0e0 + FUN_0044f0a0 (analyzed/). **CONFLICT at +0xc88.**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x37C | byte[256] | ProxyActiveFlags | HIGH | FUN_0044f0e0 L13: byte write; FUN_0044f0a0 L15: clear loop 256× | none |
| +0x87C | int[256] | ProxyChildIndices | HIGH | FUN_0044f0e0 L25-28: float/int write indexed by param_2; FUN_0044f0a0 L13-18: clear 256× undefined4 | none |
| +0xC88 | int[12] | ProxyLeafNodes | **CONFLICT** | FUN_0044f0e0 L15: `(ushort*)(param_1+0xc88)` — reads as short; FUN_0044f0a0 L20-24: initializes 12× undefined4 | **CONFLICT: +0xc88 accessed as ushort* in FUN_0044f0e0 (2-byte) but initialized as int[12] in FUN_0044f0a0 (4-byte×12). Loop in FUN_0044f0e0 iterates 0x100 times → 512 bytes, which exceeds documented int[12]=48 bytes** |

**Undocumented field found:**
- +0xc84: `*(undefined4 *)(param_1 + 0xc84) = 0;` in FUN_0044f0a0 L11. This is a 4-byte field between +0x87C+0x400=0xc7c and +0xc88. Possibly a count/length field.

---

## Section 268 — RPMPerGearSubStruct (stride 0x0c, 5 gears)

From FUN_004f6bf0 (decompiled_all). All 3 offsets CONFIRMED. Stride 0x0c confirmed.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 + gear×0xc | float | MinimumRPM | HIGH | FUN_004f6bf0 L37: `*(float*)(param_1 + 4 + param_3*0xc)` | none |
| +0x08 + gear×0xc | float | MaximumRPM | HIGH | FUN_004f6bf0 L41: `*(float*)(param_1 + 8 + param_3*0xc)` | none |
| +0x0c + gear×0xc | float | NaturalRPM_recip | HIGH | FUN_004f6bf0 L46-47: `*(float*)(param_1 + (param_3*3+3)*4)` = `param_1 + 0x0c + param_3*0x0c` | none |

**Overall Section 268: ALL CONFIRMED. Confidence HIGH. 3 floats × 4 bytes = 12 bytes = 0x0c stride. 5 gears (0–4).**

---

## Section 269 — Source: docs/21-audio-network-internals.md

Reference section. No offsets to verify.

---

## Section 270 — Summary

Reference section. No offsets to verify.

---

## Section 271 — SlipCurveEntry (stride 0x18 = 24 bytes)

From FUN_004d5f70 + FUN_004d75d0. **TYPE CONFLICT at +0x08.**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | name | HIGH | FUN_004d5f70 param usage; FUN_004d75d0 L18: `*(undefined1**)(... + iVar5)` | none |
| +0x04 | unknown | pad_or_id | LOW | No evidence of write. Only gap filler. | none |
| +0x08 | float → **double** | peakSlip | MEDIUM | FUN_004d5f70 L224, L239: `*(double*)(param_1 + 2)` — param_1 is undefined4*, byte offset 8. **8-byte write** | **CONFLICT: docs say float, code writes double** |
| +0x0c | float | peakGrip | **NOT FOUND** | No write to +0x0c found in FUN_004d5f70. Peak grip is computed (dVar1) but used only for normalization, not persisted. | **CONFLICT: field claimed at +0x0c but no .c evidence** |
| +0x10 | int | pointCount | HIGH | FUN_004d5f70 L173: `param_1[4] = iVar18` (word index 4 = byte 0x10) | none |
| +0x14 | ptr | splineData | HIGH | FUN_004d5f70 L175: `param_1[5] = pvVar14` (word index 5 = byte 0x14). Allocated as `iVar18 << 5` = pointCount×32 bytes | none |

**Correction needed: +0x08 stores peakSlip as double (8 bytes), not float. The corrected layout is: +0x00 char*(4) + +0x04 pad(4) + +0x08 double(8) + +0x10 int(4) + +0x14 ptr(4) = 24 = 0x18. ✓**
**peakGrip is computed (max cubic spline value) but NOT stored in struct. All spline coefficients normalized by peakGrip at runtime.**


=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| CollisionProxyRegistration | +0xC84 | int | FUN_0044f0a0 L11 | Undocumented field between ProxyChildIndices and ProxyLeafNodes. Cleared to 0 during init. |
| Vehicle Array Entry | +0x48a4 | int | FUN_004c6c40 (not verified) | Flag set to -1 after first load. |
| JointHingeBarStruct | +0x08 | (4-byte) | FUN_0056d930 L570 | Written as undefined4, not double. Derived spring/tension result, 4 bytes. |
| JointHingeBarStruct | +0x10 | (4-byte) | FUN_0056d930 L572 | Written as undefined4, not double. Derived spring/tension result, 4 bytes. |


=== SUMMARY ===

| Section | Name | Status | Conflicts |
|---------|------|--------|-----------|
| 258 | Linked List Node | ALL CONFIRMED | 0 |
| 259 | Empty Struct Headers | Spot-checked | 0 |
| 260 | Bounds2D | LOW (no .c file) | 0 |
| 261 | SuspensionDamperCoeffs | CONFIRMED (1 fn) | 0 |
| 262 | JointHingeBarStruct | PARTIAL CONFIRMED | 3: +0x08, +0x10 should be float (not double), +0x14 should be float[6] (not double[6]) |
| 263 | Vehicle Array Entry | PARTIAL CONFIRMED | Systematic: early offsets (+0x02..+0x1c) are word indices ×4, not byte offsets |
| 264 | Buffered I/O Stream | CONFIRMED | 0 |
| 265 | Buffer/Mesh Allocation | ALL CONFIRMED | 0 |
| 266 | Notes | N/A | 0 |
| 267 | CollisionProxyRegistration | PARTIAL CONFIRMED | 1: +0xc88 type conflict (ushort vs int), +0xc84 undocumented |
| 268 | RPMPerGearSubStruct | ALL CONFIRMED | 0 |
| 269 | Source ref | N/A | 0 |
| 270 | Summary | N/A | 0 |
| 271 | SlipCurveEntry | PARTIAL CONFIRMED | 2: +0x08 is double (not float), +0x0c peakGrip not persisted |
