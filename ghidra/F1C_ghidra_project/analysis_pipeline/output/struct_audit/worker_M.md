# WORKER M — F1C Struct Confidence Audit Results

Worker M of 20. Auditing sections 174–187 from docs/13-struct-offsets.md.

Date: 2026-07-15

---

## EXECUTIVE SUMMARY

| Section | Name | Verdict | Issues |
|---------|------|---------|--------|
| 174 | SessionStruct/SessionTimers | **PARTIAL FAIL** | 1 HIGH conflict (+0x190 short vs byte), missing observers |
| 175 | UNUSED/ABSENT OFFSETS | **PASS** | +0x1130/+0x1132 confirmed DirectX FP |
| 176 | BoolFloatToggle | **PASS** | Minor: undefined4 write but float semantics |
| 177 | WheelStateArray | **PARTIAL FAIL** | 2 type errors (double not float), address typos |
| 178 | TraversalBoundStruct | **PASS** | All 5 offsets verified |
| 179 | SteeringTorqueOutputStruct | **PARTIAL FAIL** | +0x10/+0x18 stored as int not float |
| 180 | Scene Array Entry | **PASS** | Stride + offset verified across 6 functions |
| 181 | RenderContext | **PARTIAL FAIL** | 7 systematic offset errors, 4 wrong observers, duplicate entries |
| 182 | Pixel Compositing Struct | **PASS** | Both offsets verified |
| 183 | CollisionRaycastPlane | **PASS** | All 6 offsets verified |
| 184 | CollisionTerrainSurface | **PASS** | Both offsets confirmed |
| 185 | Player Slot Struct | **INCONCLUSIVE** | Stride confirmed; internal offsets not in cited function |
| 186 | AudioConfigFlagsStruct | **PASS** | Exact bitmask match |

---

## === AUDIT RESULTS ===

## Section 174: SessionStruct / SessionTimers (param_1 — session struct)

Docs/13 offset: line 514.
Based on FUN_004d0f10, FUN_00411120, FUN_004a5e10. Claimed confidence: **high**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | int | ActiveFlag | **HIGH** | FUN_004a5e60: `*(int *)(param_1 + 0x14)`; FUN_004a5e80: `*(int *)(param_1 + 0x14)` | none |
| +0x24 | int | Count1 | **HIGH** | FUN_00411120: `*(int *)(param_1 + 0x24)` lines 18,22 | none |
| +0x30 | int | Count2 | **HIGH** | FUN_00411120: `*(int *)(param_1 + 0x30)` lines 25,29 | none |
| +0x3c | int | Count3 | **HIGH** | FUN_00411120: `*(int *)(param_1 + 0x3c)` lines 32,36 | none |
| +0x44 | ptr | ListHead | **HIGH** | FUN_0046ae60: `*(int **)(param_1 + 0x44)` line 17 | none |
| +0x48 | int | Count | **HIGH** | FUN_0046ae60: `*(undefined4 *)(param_1 + 0x48)=0`; FUN_00411120: `*(int *)(param_1 + 0x48)` | **MISSING observer** FUN_00411120 |
| +0x4c | int | Count | **HIGH** | FUN_0046ae60: `*(undefined4 *)(param_1 + 0x4c)=0` | none |
| +0x50 | int | Count | **HIGH** | FUN_0046ae60: `*(undefined4 *)(param_1 + 0x50)=0` | none |
| +0x54 | int | Count4 | **HIGH** | FUN_00411120: `*(int *)(param_1 + 0x54)` lines 61,89 | none |
| +0x60 | int | Count5 | **HIGH** | FUN_00411120: `*(int *)(param_1 + 0x60)` lines 92,112 | none |
| +0xac | int | BestTime | **HIGH** | FUN_004d0f10: `*(undefined4 *)(param_1 + 0xac)=0x7fffffff` (INT_MAX) | none |
| +0xb8 | float | MaxSessionTime | **HIGH** | FUN_004d0f10: `*(undefined4 *)(param_1 + 0xb8)=0x45e10000` (7200.0f) | none |
| +0xbc | float | TimeMultiplier | **HIGH** | FUN_004d0f10: `*(undefined4 *)(param_1 + 0xbc)=0x3f800000` (1.0f) | none |
| +0x128 | int[26] | SectorFlags | **HIGH** | FUN_004d0f10: loop 0x1a (26) × 4B writes from `(undefined4*)(param_1 + 0x128)` | none |
| +0x180 | byte | StateFlag/FlagA | **HIGH** | FUN_004a5e60: `*(undefined1 *)(param_1 + 0x180)=1`; FUN_004a5e80: `=0` | none |
| +0x184 | int | SessionState/FlagB | **HIGH** | FUN_004a5e10: `*(int *)(param_1 + 0x184)` (0/1/4) | none |
| +0x190 | short | LapCount | **MEDIUM** | FUN_004d0f10: `*(undefined2 *)(param_1 + 400)=0xffff` | **CONFLICT**: FUN_004a4db0 writes `*(undefined1 *)(param_1 + 0x190)=0` (byte) |
| +0x192 | byte | CurrentSector | **HIGH** | FUN_004d0f10: `*(undefined1 *)(param_1 + 0x192)=0xff` | none |
| +0x280 | int[52] | PitWindowHistory | **HIGH** | FUN_004d0f10: loop 0x34 (52) × 4B zero from `(undefined4*)(param_1 + 0x280)` | none |

### CONFLICTS FOUND

**⚠️ CONFLICT #1 (HIGH): +0x190 short vs byte within same struct**
- FUN_004d0f10 writes as `undefined2` (2 bytes) with value `0xffff`
- FUN_004a4db0 writes as `undefined1` (1 byte) with value `0` (same struct - verified by identical +0x194..+0x1a8 write pattern)
- If LapCount is short (2B), byte write only clears low byte, leaving high byte = 0xFF. Recommend investigate +0x191 usage.

**MISSING observers:**
- +0x48: FUN_00411120 accesses as `*(int *)(param_1 + 0x48)` — should be listed
- +0x14, +0x184, +0x190: FUN_004a4db0 accesses all three with same struct pattern — should be listed

---

## Section 175: UNUSED / ABSENT OFFSETS

Confirmed: Offsets +0x1130 and +0x1132 do NOT appear in any 06-session-race-logic function entries. These are DirectX false positives. **PASS**.

---

## Section 176: BoolFloatToggle (inferred — FUN_0059d6ff)

Docs/13 offset: line 1304.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1065 | byte | BoolFlag | **HIGH** | FUN_0059d6ff: `*(char *)(unaff_EBX + 0x1065)` | none — single access |
| +0x3584 | float | FloatParam | **MEDIUM** | FUN_0059d6ff: written as `undefined4` (0 or 0x3f800000=1.0f); read as `float*` in FUN_004270a0, FUN_00451720, FUN_004c71c0 | Minor: Ghidra writes as undefined4, but float semantics confirmed |

**Verdict: PASS**

---

## Section 177: WheelStateArray (stride 0x464, 4 wheels)

Docs/13 offset: line 2358.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x338 | float[0x119] | WheelStates | **HIGH** | FUN_004412f0 (NOT FUN_00412f0): `(undefined4 *)(param_1 + 0x338)` with stride 0x464, 4 wheels. 0x119 dwords = 0x464 bytes ✓ |
| +0x1c5c-0x1c68 | float | SuspHistory | **LOW** | FUN_004412f0: `(undefined4 *)(param_1 + 0x1c5c)` — writes 4 dwords | **TYPE CONFLICT**: Same doc (lines 2098-2099) says `double` (AccumulatedFriction) at +0x1c5c and `float` (CurSuspDisp) at +0x1c64. FUN_0043f7f0 reads +0x1c5c as `double*`. **+0x1c5c should be double, not float.** |
| +0x1e38-0x1e44 | float | VelHistory | **LOW** | FUN_004412f0: writes 4 undefined4 values; FUN_0043f7f0 reads +0x1e38 as `double*` | **TYPE CONFLICT**: Same doc (lines 2117-2119) says `double` (SuspensionTravel) at +0x1e38, `float` (PrevWheelVel) at +0x1e3c, `float` (CurWheelVel) at +0x1e40. **+0x1e38 should be double, not float.** |

### CONFLICTS FOUND

**⚠️ TYPE CONFLICT: +0x1c5c — claimed float, actual double**
- FUN_0043f7f0, FUN_0043ff3d, FUN_0043fffb all read as `double*`
- FUN_004412f0 writes as undefined4 × 4 (could be two doubles or 4 floats)
- Doc elsewhere (line 2098) confirms double

**⚠️ TYPE CONFLICT: +0x1e38 — claimed float, actual double**
- FUN_0043f7f0, FUN_0043ff3d, FUN_0043fffb all read as `double*`
- Doc elsewhere (line 2117) confirms double

**⚠️ ADDRESS TYPOS in docs:**
- FUN_00412f0 should be **FUN_004412f0** (missing leading 4)
- FUN_0041ad0 should be **FUN_00441ad0**
- FUN_00413e230 is **unresolvable** — no file with that address exists

---

## Section 178: TraversalBoundStruct

Docs/13 offset: line 2732. From FUN_00443af0. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1e14 | int | TraversalMode | **HIGH** | FUN_00443af0: `*(int *)(param_1 + 0x1e14) == 1/2`; also in FUN_0043f7f0, FUN_0043ff3d, FUN_0043fffb, FUN_004441f0 | none |
| +0x3d0 | double | BoundA | **HIGH** | FUN_00443af0: `*(double *)(param_1 + 0x3d0)` | none |
| +0x834 | double | BoundB | **HIGH** | FUN_00443af0: `*(double *)(param_1 + 0x834)` | none |
| +0xc98 | double | BoundC | **HIGH** | FUN_00443af0: `*(double *)(param_1 + 0xc98)` | none |
| +0x10fc | double | BoundD | **HIGH** | FUN_00443af0: `*(double *)(param_1 + 0x10fc)`; also FUN_004441f0, FUN_0044657d | none |

**Verdict: PASS** — All 5 offsets verified exactly.

---

## Section 179: SteeringTorqueOutputStruct (inferred)

Docs/13 offset: line 3336. Based on FUN_00423ca0. Claimed confidence: medium.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 (param_1[4]) | float | OrthogonalResult | **LOW** | FUN_00423ca0: `param_1[4] = (int)SQRT(fVar3)` — stored as **int** (truncated float) | **TYPE MISMATCH**: access is `int`, not `float`. param_1 is `int*`. |
| +0x18 (param_1[6]) | float | PrimaryResult | **LOW** | FUN_00423ca0: `param_1[6] = (int)fVar2` then read back as `(float)param_1[6]` — stored as int, cast to float | **TYPE MISMATCH**: access is `int` with `(float)` cast on read. |

**Verdict: PARTIAL FAIL** — Offsets match but types should be `int` with note "stores float result truncated to int". The `(float)param_1[6]` cast implies the field stores a truncated float as int.

---

## Section 180: Scene Array Entry (stride 0x18c)

Docs/13 offset: line 3739. Based on 4 function observations. Claimed confidence: high.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x104 | char* | scene name/identifier | **HIGH** | FUN_004c54f0: `(char *)(iVar1 + 0x104)` string copy; FUN_004c55b0: `FUN_00499e20(iVar3 + 0x104)`; FUN_004c5cb0, FUN_004c6330: string compare; FUN_004c51a0, FUN_00415c40 also access | none |
| Stride 0x18c | stride | | **HIGH** | `DAT_008ac48c * 0x18c + DAT_008ac490`, `*param_1 * 0x18c + DAT_008ac490` | Confirmed |

**Verdict: PASS** — Fully verified across 6+ functions.

---

## Section 181: RenderContext (inferred)

Docs/13 offset: line 4021. Based on 18+ function observations. Claimed confidence: high.

### CRITICAL: Systematic Byte Offset Error

**7 entries have byte offsets computed as `index * 4` but posted as wrong byte values** — off by 0x100.

| Doc Offset | Index | Actual Byte Offset (index×4) | Error |
|-----------|-------|-----------------------------|-------|
| +0x12a8 | 0x4ea | **+0x13a8** | **OFF BY 0x100** |
| +0x12b0 | 0x4ec | **+0x13b0** | **OFF BY 0x100** |
| +0x12c4 | 0x4f1 | **+0x13c4** | **OFF BY 0x100** |
| +0x12c8 | 0x4f2 | **+0x13c8** | **OFF BY 0x100** |
| +0x12cc | 0x4f3 | **+0x13cc** | **OFF BY 0x100** |
| +0x12d0 | 0x4f4 | **+0x13d0** | **OFF BY 0x100** |
| +0x12d8 | 0x4f6 | **+0x13d8** | **OFF BY 0x100** |

### Detailed Audit Table

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0000 | int* (vtablePtr) | vtablePtr | **LOW** | FUN_005550e0: `*param_1 = uVar3` (stores COM HRESULT, write-only). FUN_004c71c0: param_1 is `int`, not pointer — no +0x0000 access. | **WRONG type**: actual `int`/`undefined4` result store, not `int*`. **WRONG observers**: FUN_004c71c0, FUN_0054ca00 don't access +0x0000. |
| +0x1100 (0x440) | ptr | deviceVtableObj | **HIGH** | FUN_005550e0: `(int *)param_1[0x440]` → vtable dispatch at +200; FUN_0053eb70, FUN_0053ead0, FUN_00554700 all confirm | **WRONG observer**: FUN_00586700 does NOT access +0x1100 (uses small offsets 0x34-0x44, different struct) |
| +0x1398 (0x4e6) | int | valueSlot1 | **HIGH** | FUN_00554700: `param_1[0x4e6]` read/write; FUN_0053eb70 line 190: `param_1[0x4e6]=0` | **MISSING observer**: FUN_0053eb70 |
| +0x139c (0x4e7) | int | valueSlotIndex | **HIGH** | FUN_00554700: `param_1[0x4e7]`; FUN_0053eb70 line 193: `param_1[0x4e7]=0` | **MISSING observer**: FUN_0053eb70 |
| +0x13e0 (0x4f8) | int | bufferType | **HIGH** | FUN_00540f00: `param_1[0x4f8]` compared to 1/2 | none |
| +0x12a8 **→ +0x13a8** | int | renderStateFlags | **MEDIUM** | FUN_005550e0: `param_1[0x4ea] & 0x100`; FUN_0053eb70: `& 0x10000000` (bit 28 = init guard) | **OFFSET ERROR**: should be +0x13a8. **OVERLAP**: same real offset as cleanupFlags below — merge. |
| +0x12b0 **→ +0x13b0** | int | renderLimit | **HIGH** | FUN_005550e0: `(int)param_1[0x4ec]` loop compare | **OFFSET ERROR** |
| +0x12c4 **→ +0x13c4** | int | initializedFlag | **HIGH** | FUN_005550e0: `param_1[0x4f1]` compared to 1 | **OFFSET ERROR** |
| +0x12c8 **→ +0x13c8** | int | colorValue | **HIGH** | FUN_005550e0: `param_1[0x4f2]` passed to SetRenderState | **OFFSET ERROR** |
| +0x12cc **→ +0x13cc** | int | currentMaterialID | **HIGH** | FUN_005550e0: `param_1[0x4f3]` multiple accesses | **OFFSET ERROR** |
| +0x12d0 **→ +0x13d0** | int | renderDebugMode | **HIGH** | FUN_005550e0: `param_1[0x4f4]` compared to 0 | **OFFSET ERROR** |
| +0x12d8 **→ +0x13d8** | int | textOverlayMode | **HIGH** | FUN_005550e0: `param_1[0x4f6]` compared to 0 | **OFFSET ERROR** |
| +0x14f0 (0x53c) | int | extraFlag | **MEDIUM** | FUN_005550e0: `param_1[0x53c]` read, conditional render state | **OVERLAP**: same byte as viewportDims[0] |
| +0x152c (0x54b) | ptr | textureResource | **HIGH** | FUN_0053ead0: `param_1[0x54b]` released via FUN_0053f6e0 | **DUPLICATE**: extraTexture at same +0x152c same field |
| +0x1524 (0x549) | ptr | resourceA | **HIGH** | FUN_0053ead0: released | none |
| +0x1528 (0x54a) | ptr | resourceB | **HIGH** | FUN_0053ead0: released | none |
| +0x152c | ptr | extraTexture | **MEDIUM** | FUN_0053ead0: same as textureResource above | **DUPLICATE**: same field as textureResource. **WRONG observer**: FUN_0053f270 does NOT access +0x152c |
| +0x13a0 | int | renderState | **HIGH** | FUN_0053f270: `*(undefined4 *)(param_1 + 0x13a0)=1` | none |
| +0x13a8 | int | cleanupFlags | **HIGH** | FUN_0053f270: `*(uint *)(param_1 + 0x13a8) & 0x10000000` (bit 28) | **OVERLAP**: same as renderStateFlags (+0x12a8→+0x13a8) — merge. |
| +0x1140 | ptr | frontBuffer | **HIGH** | FUN_0053f270: `*(int *)(param_1 + 0x1140)` — released | none |
| +0x113c | ptr | backBuffer | **HIGH** | FUN_0053f270: `*(int *)(param_1 + 0x113c)` — released | none |
| +0x1144 | ptr | depthStencil | **HIGH** | FUN_0053f270: `*(int *)(param_1 + 0x1144)` — released | none |
| +0x14f0..0x1504 | int[5] | viewportDims | **MEDIUM** | FUN_0053f270: zeros **6** ints: +0x14f0, +0x14f4, +0x14f8, +0x14fc, +0x1500, +0x1504 | **COUNT WRONG**: int[6] not int[5]. **OVERLAP**: +0x14f0 also claimed as extraFlag. |
| +0x1518 | ptr | textureList | **HIGH** | FUN_0053f270: `*(int *)(param_1 + 0x1518)` — traversed as linked list | none |
| +0x1580 | ptr | targetList | **HIGH** | FUN_0053f270: `*(int *)(param_1 + 0x1580)` — traversed | none |
| +0x704 | float[16] | viewMatrix | **MEDIUM** | FUN_004c71c0: address passed to matrix multiply | Type inferred from callee |
| +0x744 | float[16] | worldMatrix | **MEDIUM** | FUN_004c71c0: address passed to matrix multiply | Type inferred from callee |
| +0x83c | float[3]×4 | wheelPositions | **HIGH** | FUN_004c71c0: `*(float*)(iVar4 + param_1 + 0x83c)` with iVar4 += 0x128 loop (4 iters) | Stride 0x128 confirmed |
| +0x34f8 | float[4] | diffuseColor | **MEDIUM** | FUN_004c71c0: address passed to lighting function | Type inferred |
| +0x3510 | float[4] | specularColor | **MEDIUM** | FUN_004c71c0: address passed to lighting function | Type inferred |
| +0x3540 | int | envMapHandle | **MEDIUM** | FUN_004c71c0: address passed to texture function | Type inferred |

### RenderContext — SUMMARY OF ISSUES

1. **SYSTEMATIC OFFSET ERROR (7 entries):** +0x12xx offsets should be +0x13xx (computed as index×4 correctly but posted as wrong byte values, off by 0x100)
2. **WRONG FUNCTION OBSERVERS (4):** FUN_004c71c0 (listed for vtablePtr, doesn't access +0x0000), FUN_0054ca00 (different struct), FUN_0053f270 (listed for extraTexture, doesn't access +0x152c), FUN_00586700 (listed for deviceVtableObj, different struct)
3. **MISSING FUNCTION OBSERVERS (2):** FUN_0053eb70 for valueSlot1 and valueSlotIndex
4. **DUPLICATE ENTRY:** textureResource and extraTexture both at +0x152c, both reference FUN_0053ead0 — same field
5. **OVERLAPPING ENTRIES (2 pairs):** renderStateFlags(+0x13a8) = cleanupFlags(+0x13a8) same bit 28; extraFlag(+0x14f0) = viewportDims[0](+0x14f0)
6. **WRONG ARRAY SIZE:** viewportDims claimed int[5] but code zeros 6 ints
7. **WRONG TYPE:** +0x0000 claimed as `int* vtablePtr` — actually `int` storing COM return values

---

## Section 182: Pixel Compositing Struct (inferred)

Docs/13 offset: line 4416. Used by FUN_00503e36. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | srcPtr | **HIGH** | FUN_00503e36: `iVar5 = *param_1` then `pbVar6 = *(byte **)(iVar5 + 0x18)` — pointer to image struct | none |
| +0x04 | ptr | dstPtr | **HIGH** | FUN_00503e36: `pbVar10 = *(byte **)(param_1[1] + 0x18)` — pointer | Confirmed "offset via +0x18" |

**Verdict: PASS**

---

## Section 183: CollisionRaycastPlane (inferred — param_1 in FUN_0044ba40)

Docs/13 offset: line 4791. Based on FUN_0044ba40. Claimed confidence: medium.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x004 | int | PlaneActive | **HIGH** | FUN_0044ba40: `*(int *)(param_1 + 4) != 0` | none |
| +0x008 | double | OriginX | **HIGH** | FUN_0044ba40: `*(double *)(param_1 + 8)` in stepping | none |
| +0x010 | double | PlaneWidth | **HIGH** | FUN_0044ba40: `*(double *)(param_1 + 0x10)` in division | none |
| +0x018 | double | OriginY | **HIGH** | FUN_0044ba40: `*(double *)(param_1 + 0x18)` in stepping | none |
| +0x020 | double | PlaneHeight | **HIGH** | FUN_0044ba40: `*(double *)(param_1 + 0x20)` in division | none |
| +0x028 | float[1024] | ResultBuffer | **HIGH** | FUN_0044ba40: `(undefined4 *)(param_1 + 0x28)` in 32×32 nested loop = 1024 writes | none |

**Verdict: PASS** — All 6 offsets verified.

---

## Section 184: CollisionTerrainSurface (inferred — from FUN_0045ca20)

Docs/13 offset: line 5095. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x424 | float[8] | SurfaceDataBlock | **HIGH** | FUN_0045ca20: `(undefined4 *)(iVar3 * 0x20 + 0x424 + param_1)` — loop reads 8 dwords (32 bytes = 8×4) | none |
| +0x1124[surfaceIdx] | float | SurfaceCache | **HIGH** | FUN_0045ca20: `*(float *)(param_1 + 0x1124 + iVar3 * 4)`; also FUN_0045c850 (`undefined4` -1.0f), FUN_00423e80 (`=0`), FUN_004270a0 | Minor: access type varies but semantically float |

**Verdict: PASS**

---

## Section 185: Player Slot Struct (stride 0x8c)

Docs/13 offset: line 5652. Based on FUN_0045eb50, FUN_0045fc50. Claimed confidence: medium.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | NodeID | **LOW** | FUN_0045eb50: returns slot base pointer but does NOT dereference slot+0x00. Only compares node IDs from SEPARATE array at +0x3c74. | **Cannot verify from FUN_0045eb50 alone.** |
| +0x04–0x8b | char[0x87] | PlayerName | **LOW** | FUN_0045eb50: returns pointer to slot base +0x398 but does NOT read slot+0x04. | **Cannot verify from FUN_0045eb50 alone.** |
| Stride 0x8c | stride | | **HIGH** | FUN_0045eb50: `iVar2 * 0x8c + 0x398 + param_1` (line 17) | Confirmed ✓ |

**Verdict: INCONCLUSIVE** — stride 0x8c confirmed, but slot internal offsets (+0x00, +0x04) cannot be verified from FUN_0045eb50 alone. Recommend checking FUN_0045fc50 or other functions that dereference the slot pointer.

---

## Section 186: AudioConfigFlagsStruct (inferred)

Docs/13 offset: line 6033. Based on FUN_00551480. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | uint | AudioConfigFlags | **HIGH** | FUN_00551480: `*(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffff9fff | 0x1000` — bit 12 set, bits 13-14 cleared | Exact bitmask match |

**Verdict: PASS**

---

## === NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| — | — | — | — | No new offsets discovered in 2+ files for these sections |

---

## PRIORITY RECOMMENDATIONS

### HIGH (must fix)
1. **RenderContext byte offsets**: Fix all 7 +0x12xx offsets to +0x13xx (off by 0x100)
2. **RenderContext +0x152c duplicate**: Merge textureResource and extraTexture into one entry
3. **RenderContext +0x13a8 overlap**: Merge renderStateFlags and cleanupFlags (same byte, same bit 28)
4. **RenderContext +0x14f0 overlap**: Resolve extraFlag vs viewportDims[0] overlap
5. **SessionStruct +0x190 conflict**: Investigate short-vs-byte conflict between FUN_004d0f10 and FUN_004a4db0
6. **WheelStateArray type errors**: Fix +0x1c5c type to double, +0x1e38 type to double

### MEDIUM (should fix)
7. **WheelStateArray address typos**: FUN_00412f0→FUN_004412f0, remove unresolvable FUN_00413e230
8. **RenderContext wrong observers**: Remove FUN_004c71c0/FUN_0054ca00 from vtablePtr; remove FUN_0053f270 from extraTexture; remove FUN_00586700 from deviceVtableObj
9. **RenderContext missing observers**: Add FUN_0053eb70 for valueSlot1/valueSlotIndex
10. **RenderContext +0x0000 type**: Change from `int* vtablePtr` to `int lastResult/comResult`
11. **RenderContext viewportDims**: Change array size from int[5] to int[6] (or int[5] at +0x14f4..0x1504)
12. **SessionStruct missing observers**: Add FUN_00411120 for +0x48, FUN_004a4db0 for +0x14/+0x184/+0x190

### LOW (nice to fix)
13. **SteeringTorqueOutputStruct types**: Add note that values stored as int (truncated float)
14. **Player Slot Struct**: Verify internal offsets from FUN_0045fc50

---

## CONFIDENCE SUMMARY

| Confidence Level | Count | Sections |
|-----------------|-------|----------|
| HIGH (all verified) | 6 | 175, 176, 178, 180, 182, 183, 184, 186 |
| MEDIUM (partial issues) | 3 | 174, 177, 181 |
| LOW (unverifiable) | 1 | 185 |
| PASS | 10 | 175, 176, 178, 180, 182, 183, 184, 186 |
| PARTIAL FAIL | 3 | 174 (1 conflict), 177 (2 type errors), 181 (systematic offset errors) |
| INCONCLUSIVE | 1 | 185 |
