=== AUDIT RESULTS ===

## Section 160: TireForceQuadraticModel (param_1 — per-tire force model)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1ec | char | TireActive | HIGH | FUN_004f68b0 (char check) | none |
| +0x1f8 | double | ForceConst1 | HIGH | FUN_004f68b0, FUN_004380b0 (both double) | none |
| +0x200 | double | ForceLinCoeff | HIGH | FUN_004f68b0 (double) | none |
| +0x208 | double | ForceQuadCoeff | HIGH | FUN_004f68b0 (double) | none |
| +0x210 | double | ForceConst2 | HIGH | FUN_004f68b0 (double) | none |
| +0x218 | double | TorqueLinCoeff | HIGH | FUN_004f68b0 (double) | none |
| +0x220 | double | TorqueQuadCoeff | HIGH | FUN_004f68b0 (double) | none |
| +0x228 | double | TorqueCamberCoeff | HIGH | FUN_004f68b0 (double) | none |
| +0x250 | double | LatForcePeak | HIGH | FUN_004f68b0 (double) | none |
| +0x288 | double | LongForcePeak | HIGH | FUN_004f68b0 (double) | none |
| +0x2e8 | double | CamberAngle | HIGH | FUN_004f68b0 (double) | none |
| +0x2f8 | byte | ModelEnabledFlag | HIGH | FUN_004f6950 (char check) | none |
| +0x2fc | double | QuadraticC | HIGH | FUN_004f6950 (double) | none |
| +0x304 | double | QuadraticA | HIGH | FUN_004f6950 (double) | none |
| +0x30c | double | QuadraticB | HIGH | FUN_004f6950 (double) | none |
| +0x314 | double | OutputQuadC | HIGH | FUN_004f6950 (double) | none |
| +0x31c | double | OutputQuadA | HIGH | FUN_004f6950 (double) | none |
| +0x324 | double | OutputQuadB | HIGH | FUN_004f6950 (double) | none |
| +0x34c | double | AbsOutput1 | HIGH | FUN_004f6950 (double at +0x34c) | none |
| +0x384 | double | AbsOutput2 | HIGH | FUN_004f6950 (double at 900=0x384) | none |

**Verdict: HIGH confidence. All 20 offsets confirmed. No conflicts.**

Note: These offsets (+0x1ec through +0x384) are reused in OTHER structs at different types. Offsets +0x1ec read as int in FUN_0054a770/FUN_00561940, and as double in FUN_00569de0 — but these are different struct types sharing the same offsets. Within the TireForceQuadraticModel context, all types are consistent.

---

## Section 161: PlayerOptionsFailureRates (FailureRate slots)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5c8 | {0x24,7} | FailureRate[0..6] | LOW | No .c file found for FUN_004aa270 | N/A |

**Verdict: LOW confidence. FUN_004aa270 not found in analyzed/ or decompiled_all/. Cannot verify.**

---

## Section 162: DoublyLinkedList (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1c/+0x2c | ptr | PrevPtr | HIGH | FUN_0055c2e0 (+0x1c), FUN_005519e0 (+0x2c) | Varies by container — correctly noted |
| +0x20/+0x30 | ptr | NextPtr | HIGH | FUN_0055c2e0 (+0x20), FUN_005519e0 (+0x30) | Varies by container — correctly noted |
| +0x118/+0x1518 | ptr | ListHead | HIGH | FUN_005519e0 (+0x118), FUN_0055c2e0 (+0x1518) | Varies by container — correctly noted |

**Verdict: HIGH confidence. Clean doubly-linked list operations verified in both functions. The "offset varies by container" note is accurate.**

---

## Section 163: QuadFunctionCoeffs (spring/damper quadratic)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x17a8 | double | CoeffSetA[0] | HIGH | FUN_0043bb30, FUN_0043e890 (double) | none |
| +0x17b0 | double | CoeffSetA[1] | HIGH | FUN_0043bb30 (double) | none |
| +0x17b8 | double | CoeffSetA[2] | HIGH | FUN_0043bb30 (double) | none |
| +0x17c0 | double | CoeffSetB[0] | HIGH | FUN_0043bb30, FUN_0043e890 (double) | none |
| +0x17c8 | double | CoeffSetB[1] | HIGH | FUN_0043bb30 (double) | none |
| +0x17d0 | double | CoeffSetB[2] | HIGH | FUN_0043bb30 (double) | none |
| +0x17d8 | double | ConstTerm0 | HIGH | FUN_0043bb80 (double) | none |
| +0x17e0 | double | LinearTerm0 | HIGH | FUN_0043bb80 (double) | none |
| +0x17e8 | double | QuadTerm0 | HIGH | FUN_0043bb80 (double) | none |
| +0x17f0 | double | ConstTerm1 | HIGH | FUN_0043bb80 (double) | none |
| +0x17f8 | double | LinearTerm1 | HIGH | FUN_0043bb80 (double) | none |
| +0x1800 | double | QuadTerm1 | HIGH | FUN_0043bb80 (double) | none |
| +0x1808 | double | RestForceX | HIGH | FUN_0043bbd0, FUN_0043e980 (double) | none |
| +0x1810 | double | StiffnessX | HIGH | FUN_0043bbd0 (double) | none |
| +0x1818 | double | RestForceY | HIGH | FUN_0043bbd0, FUN_0043e980 (double) | none |
| +0x1820 | double | StiffnessY | HIGH | FUN_0043bbd0 (double) | none |
| +0x1828 | double | RestForceZ | HIGH | FUN_0043bbd0 (double) | none |
| +0x1830 | double | StiffnessZ | HIGH | FUN_0043bbd0 (double) | none |
| +0x1930 | double | ResultA | HIGH | FUN_0043bb30 (double) | none |
| +0x19e8 | double | ResultB | HIGH | FUN_0043bb30 (double) | none |
| +0x1a0c | double | Result0 | HIGH | FUN_0043bb80 (double) | none |
| +0x1abc | double | Result1 | HIGH | FUN_0043bb80 (double) | none |
| +0x1adc | double | ForceY | HIGH | FUN_0043bbd0 (double) | none |
| +0x1b94 | double | ForceX | HIGH | FUN_0043bbd0 (double) | none |
| +0x1d9c | double | ForceZ | HIGH | FUN_0043bbd0 (double) | none |

**Verdict: HIGH confidence. All 25 offsets confirmed. No type conflicts.**

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| QuadFunctionCoeffs | +0x1c00 | double | FUN_0043bb30, FUN_0043e890 | Input parameter storage — not in table |
| QuadFunctionCoeffs | +0x1c08 | double | FUN_0043e890 | Clamp bound A0 — not in table |
| QuadFunctionCoeffs | +0x1c10 | double | FUN_0043e890 | Clamp bound A1 — not in table |
| QuadFunctionCoeffs | +0x1c18 | double | FUN_0043bbd0, FUN_0043e980 | Input parameter storage (spring) — not in table |
| QuadFunctionCoeffs | +0x1c20 | double | FUN_0043e980 | Clamp bound spring X — not in table |
| QuadFunctionCoeffs | +0x1c28 | double | FUN_0043e980 | Clamp bound spring Y — not in table |
| QuadFunctionCoeffs | +0x1c38 | double | FUN_0043bb80 | Input parameter storage (coeff set B) — not in table |

---

## Section 164: VectorPositionStruct (0x20 stride, interpolation points)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | SrcX | HIGH | FUN_004e3090 (*pfVar13 = srcX) | none |
| +0x04 | float | SrcY | HIGH | FUN_004e3090 (pfVar13[1] = srcY) | none |
| +0x08 | float | SrcZ | HIGH | FUN_004e3090 (pfVar13[2] = srcZ) | none |
| +0x0c | float | TgtX | HIGH | FUN_004e3090 (pfVar13[3] = tgtX) | none |
| +0x10 | float | TgtY | HIGH | FUN_004e3090 (pfVar13[4] = tgtY) | none |
| +0x14 | float | TgtZ | HIGH | FUN_004e3090 (pfVar13[5] = tgtZ) | none |
| +0x18 | float | Factor | HIGH | FUN_004e3090 (pfVar13[6] = factor) | none |
| +0x1c | float* | OutputPtr | HIGH | FUN_004e3090 (pfVar13[7] = output ptr) | none |

**Verdict: HIGH confidence. Array at param_2+0x120, stride 0x20 confirmed. All 8 fields verified.**

---

## Section 165: InitFloatConstantsStruct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | float | Zero | MEDIUM | FUN_004594d0 (writes 0 as undefined4) | none |
| +0x1c | float | MaxBound1 | MEDIUM | FUN_004594d0 (0x7f7fffff = FLT_MAX) | none |
| +0x20 | float | MaxBound2 | MEDIUM | FUN_004594d0 (0x7f7fffff) | none |
| +0x24 | float | Cleared1 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0x28 | float | Cleared2 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0x2c | float | PhysicsParam1 | MEDIUM | FUN_004594d0 (0x40700000 = 3.75f) | none |
| +0x30 | float | Cleared3 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0x34 | float | PhysicsParam2 | MEDIUM | FUN_004594d0 (0x40500000 = 3.25f) | none |
| +0x38 | float | Cleared4 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0x3c | float | PhysicsParam3 | MEDIUM | FUN_004594d0 (0x3fe00000 = 1.75f) | none |
| +0x40 | float | LargeNeg1 | MEDIUM | FUN_004594d0 (0xd2f1a9fc = -4.19e8) | none |
| +0x44 | float | Coeff1 | MEDIUM | FUN_004594d0 (0x3f50624d = 0.813f) | none |
| +0x48 | float | LargeNeg2 | MEDIUM | FUN_004594d0 (0xd2f1a9fc) | none |
| +0x4c | float | Coeff2 | MEDIUM | FUN_004594d0 (0x3f40624d = 0.752f) | none |
| +0x50 | float | Cleared5 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0xc0 | float | Cleared6 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0xc4 | float | Cleared7 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0xc8 | float | Cleared8 | MEDIUM | FUN_004594d0 (writes 0, line: param_1 + 200) | none |
| +0xcc | float | Cleared9 | MEDIUM | FUN_004594d0 (writes 0) | none |
| +0xd0 | float | Cleared10 | MEDIUM | FUN_004594d0 (writes 0) | none |

**Verdict: MEDIUM confidence. Single function observation. All hex values match float representation. Code writes undefined4, interpreted as float — correct.**

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| InitFloatConstantsStruct | +0x08..+0x18 | float | FUN_004594d0 | 5 intermediate zero fields not in docs table (0x08, 0x0c, 0x10, 0x14, 0x18) |

---

## Section 166: Terrain Validation Flags Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| ALL (7 offsets +0x1b754..+0x1b76e) | byte | terrain flags | LOW | FUN_00460a10 NOT FOUND in analyzed/ or decompiled_full/ | N/A |

**Verdict: LOW confidence. Referenced function (FUN_00460a10) does not exist as a .c file. Cannot verify.**

---

## Section 167: Source: docs/19-renderer.md

Cross-reference section. 0 offsets to audit. Section is a processing note, not a struct definition.

**Verdict: N/A — no offsets to verify.**

---

## Section 168: Render Object / VTable Wrapper (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | vtable | HIGH | FUN_0052e170 (line 11: *param_1 = &PTR_LAB_005b4810) | none |
| +0x90 | ptr | observerList | LOW | FUN_0052e170 does NOT reference +0x90 | Unverified — may be set by parent constructor FUN_0052d9f0() |

**Verdict: +0x00 confirmed. +0x90 is NOT directly referenced in the sole .c file — assumed set by parent constructor. Confidence is LOW for +0x90.**

Note: FUN_0052e170 writes to param_1[0xb4d] (byte offset 0x2D34) and param_1[0xb4e] (byte offset 0x2D38) — these are undocumented fields well beyond +0x90.

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| RenderObject | +0x2D34 | undefined4 | FUN_0052e170 | Constructor parameter 2 |
| RenderObject | +0x2D38 | undefined4 | FUN_0052e170 | Constructor parameter 3 |

---

## Section 169: ViewportRect (inferred — param_1 in FUN_0044f680)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| [0] (byte +0x00) | int | left | HIGH | FUN_0044f680: *param_1 = param_3 | CONFLICT: naming |
| [1] (byte +0x04) | int | top | HIGH | FUN_0044f680: param_1[1] = param_5 | CONFLICT: naming (docs say top, code shows right) |
| [2] (byte +0x08) | int | right | HIGH | FUN_0044f680: param_1[2] = param_2 | CONFLICT: naming (docs say right, code shows top) |
| [3] (byte +0x0c) | int | bottom | HIGH | FUN_0044f680: param_1[3] = param_4 | CONFLICT: naming |
| [4] (byte +0x10) | int | center_x | HIGH | FUN_0044f680: param_1[4] = (param_2+param_4)>>1 | CONFLICT: naming (docs say center_x, code shows center_y) |
| [5] (byte +0x14) | int | center_y | HIGH | FUN_0044f680: param_1[5] = (param_3+param_5)>>1 | CONFLICT: naming (docs say center_y, code shows center_x) |
| [6] (byte +0x18) | int | scale_x | HIGH | FUN_0044f680: param_1[6] = 2/(param_4-param_2) | CONFLICT: naming (docs say scale_x, code shows vertical scale) |
| [7] (byte +0x1c) | int | scale_y | HIGH | FUN_0044f680: param_1[7] = 2/(param_5-param_3) | CONFLICT: naming (docs say scale_y, code shows horizontal scale) |

**Verdict: All 8 int fields confirmed. But field NAMES are swapped:**

CORRECT mapping (verified from code):
| Index | Computed From | Element Name |
|-------|--------------|-------------|
| [0] | param_3 | left |
| [1] | param_5 | right (NOT top) |
| [2] | param_2 | top (NOT right) |
| [3] | param_4 | bottom |
| [4] | (top+bottom)>>1 | center_y (NOT center_x) |
| [5] | (left+right)>>1 | center_x (NOT center_y) |
| [6] | 2/(bottom-top) | scale_y (NOT scale_x) |
| [7] | 2/(right-left) | scale_x (NOT scale_y) |

**CONFLICT: Field [1]↔[2], [4]↔[5], [6]↔[7] naming is swapped. Function param order: (int *param_1, int right_param2, int left_param3, int bottom_param4, int top_param5)**

---

## Section 170: GridCellIndex (inferred — entry in FUN_0051d247)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| [0] | int | minX | LOW | unaff_ESI[0] = X loop lower bound | none |
| [1] | int | maxX | LOW | unaff_ESI[1] = X loop upper bound | none |
| [2] | int | minZ | LOW | unaff_ESI[2] = Z row lower bound | none |
| [3] | int | maxZ | LOW | unaff_ESI[3] = Z row upper bound | none |
| [4] | int | minY | LOW | unaff_ESI[4] = Y inner lower bound | none |
| [5] | int | maxY | LOW | unaff_ESI[5] = Y inner upper bound | none |
| [6] | int | contactDistanceSq | LOW | unaff_ESI[6] = weighted squared sum | none |
| [7] | int | nonZeroCellCount | LOW | unaff_ESI[7] = count of occupied cells | none |

**Verdict: LOW confidence (stack-based temporary, not persistent struct). All 8 int fields and naming consistent with code. No type conflicts.**

---

## Section 171: NetComm Session Struct (inferred) — large, multi-field

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | float | RefillTimeout | HIGH | FUN_0045f950 (read at line 62, copied to +0x10) | none |
| +0x10 | float | ClientTimeout | HIGH | FUN_0045f950, FUN_00464290 (both float read/write) | none |
| +0x14 | int | ClientFlag | MEDIUM | FUN_00464290 (byte write=1), FUN_0045f950 (byte check) | **CONFLICT:** code uses byte, docs say int |
| +0x1c | float | GridTimer | HIGH | FUN_00460380 (float read/decrement) | none |
| +0x1c | ptr? | NodeIDArray | **WRONG** | FUN_00460cb0 uses +0x1d4, NOT +0x1c | **DOCUMENTATION ERROR:** second row reusing +0x1c is incorrect; NodeIDList is at +0x1d4 |
| +0x20 | int | SceneLoadedFlag | HIGH | FUN_00460380 (byte check/write) | **CONFLICT:** code uses byte, docs say int |
| +0x28 | int | InitFlag | HIGH | FUN_00464290 (byte check/write) | **CONFLICT:** code uses byte, docs say int |
| +0x29 | byte | OpeningFlag | HIGH | FUN_00460e90 (byte=1), FUN_00461190 (byte=0) | none |
| +0x2c | float | OpenTimer | HIGH | FUN_00461190 (-1.0f or DAT), FUN_004612e0 | none |
| +0x30 | int | BootedFlag | MEDIUM | FUN_00461d20 (char check/write) | **CONFLICT:** code uses byte, docs say int |
| +0x380 | float | ResetTimer | HIGH | FUN_00464290 (=0), FUN_00461d20 (float decrement) | none |
| +0x388 | int | ResetFlag | MEDIUM | FUN_00464290 (=0 via undefined4) | none |
| +0x38c | float | KeepAliveAccum | HIGH | FUN_0045f950 (float accumulation) | none |
| +0x390 | float | SyncTimeout | MEDIUM | FUN_00464290 (=DAT), FUN_0045d890 | none |
| +0x398 | char[0x8c]×104 | PlayerNames | HIGH | FUN_0045eb50 (return iVar2*0x8c+0x398+param_1) | none |
| +0x3c74 | int[104] | SlotNodeIDs | HIGH | FUN_00460cb0, FUN_0045eb50 (0x68 iterations) | none |
| +0x3e14 | int | SlotCount | HIGH | FUN_00460cb0, FUN_0045eb50, FUN_0045fc50 | none |
| +0x3fc4 | int | Connected | HIGH | FUN_0045f950, FUN_00464290, FUN_0045fc50 | none |
| +0x1b770 | ptr | MsgListHead | HIGH | FUN_00460e90, FUN_00461190 | none |
| +0x1b774 | ptr | MsgListTail | HIGH | FUN_00460e90, FUN_00461190 | none |
| +0x1b77c | int | MsgListCount | HIGH | FUN_00460e90, FUN_00461190 (++count) | none |
| +0x1b79c | int | NetworkActive | HIGH | FUN_00461de0 (!=0 check) | none |
| +0x1d4 | int[104] | NodeIDList | HIGH | FUN_00460cb0 (104× int at param_1+0x1d4) | none |

**Verdict: HIGH confidence for most fields. Multiple CONFLICTS found:**

1. **+0x14 (ClientFlag):** docs say `int`, code uses `byte` in ALL functions (char check in FUN_0045f950, undefined1 write in FUN_00464290)
2. **+0x1c (NodeIDArray):** This row references +0x1c but FUN_00460cb0 uses +0x1d4 for NodeIDList. The docs' CONFLICT note flags this correctly.
3. **+0x20 (SceneLoadedFlag):** docs say `int`, code uses `byte` (char check/undefined1 write)
4. **+0x28 (InitFlag):** docs say `int`, code uses `byte` (char check/undefined1 write)
5. **+0x30 (BootedFlag):** docs say `int`, code uses `byte` (char check/undefined1 write)

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| NetComm | +0x374 | byte | FUN_0045fc50 | Guard flag (skip if set) |
| NetComm | +0x3d0 | char[0x8c]×104 | FUN_0045fc50 | Secondary slot array (0x38 bytes after PlayerNames) |
| NetComm | +0x3fc8 | ptr | FUN_0045fc50 | Linked list head (player slots) |
| NetComm | +0x3fcc | ptr | FUN_0045fc50 | Linked list field |
| NetComm | +0x3fd0 | ptr | FUN_0045fc50 | Linked list iterator |
| NetComm | +0x3fd4 | int | FUN_0045fc50 | Linked list count |
| NetComm | +0x1b778 | ptr | FUN_00460e90, FUN_00461190 | MsgListTail→next (list append helper) |

---

## Section 172: StreamEventDecompressor (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | StreamStruct | HIGH | FUN_00510975 (*puVar2 = stream data ptr) | none |
| +0x04 | code* | DispatchFn0 | HIGH | FUN_00510975 (puVar2[1] = remaining count, puVar2[3] = refill fn; +0x04 = secondary dispatch via *unaff_ESI+4) | Note: docs say +0x04=DispatchFn0 but unaff_ESI+4 is dispatch; puVar2[1] at unaff_ESI[5]+4 is remaining count — different struct nesting |
| +0x14 | byte | EventStatus | HIGH | FUN_00510975 (*unaff_ESI+0x14 = 0x4e/0x1a/0x1b) | none |
| +0x18 | int | EventParam1 | HIGH | FUN_00510975 (*unaff_ESI+0x18 = uVar4) | none |
| +0x1c | int | EventParam2 | HIGH | FUN_00510975 (*unaff_ESI+0x1c = uVar3) | none |
| +0xca | byte[16] | NibbleLo | HIGH | FUN_00510975 (*(byte*)(uVar4+0xca+unaff_ESI)) | none |
| +0xda | byte[16] | NibbleHi | HIGH | FUN_00510975 (*(byte*)(uVar4+0xda+unaff_ESI)) | none |

**Verdict: HIGH confidence. All offsets verified against single .c file. The struct has two levels: unaff_ESI[5] points to a stream struct ({dataPtr, remaining, ?, refillFn}), and *unaff_ESI is the main event struct with the listed offsets.**

---

## Section 173: Pooled Struct Groupings

### Struct 1: Pit Crew Actor (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | uint16 | DetailLevel | HIGH | FUN_004a2a90 (*puVar6 = local_6b8[0]) | none |
| +0x03 | byte | LollipopFlag | HIGH | FUN_004a2a90 (*(byte*)(puVar6+3) = 0/1) | none |
| +0x26 | float | PosX | **WRONG** | FUN_004a2a90 writes to puVar6+0x26 (undefined2* indexing = byte offset 0x4c) | **CONFLICT:** byte offset is 0x4c, not 0x26 |
| +0x2a | float | PosY | **WRONG** | FUN_004a2a90 writes to puVar6+0x28 (byte offset 0x50) | **CONFLICT:** byte offset is 0x50, not 0x2a |
| +0x2e | float | PosZ | **WRONG** | FUN_004a2a90 writes to puVar6+0x2a (byte offset 0x54) | **CONFLICT:** byte offset is 0x54, not 0x2e |
| +0x2c | float[?] | Rotate | **WRONG** | FUN_004a2a90 reads puVar6+0x2c/0x2e/0x30 (byte offsets 0x58/0x5c/0x60) | **CONFLICT:** byte offsets are 0x58/0x5c/0x60, not 0x2c |

**Verdict: Stride 0x78 confirmed. DetailLevel (+0x00) and LollipopFlag (+0x03) correct. However POSITION/ROTATE offsets are WRONG** — the docs use raw index values from the undefined2* pointer without multiplying by sizeof(undefined2)=2. Correct byte offsets: PosX=+0x4c, PosY=+0x50, PosZ=+0x54, Rotate=+0x58..+0x60.

### Struct 2: Pit Order Config (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1a8 | int | PitOrderCount | MEDIUM | FUN_004d12c0 (int write/read) | none |
| +0x1ac | char** | PitOrderArray | MEDIUM | FUN_004d12c0 (piVar4 pointer write) | none |

**Verdict: MEDIUM confidence. Both offsets confirmed in single function. Types match.**

### Struct 3: Vehicle Struct — Livery/Pit Section (low offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x60 | byte | PitFlag | **WRONG** | FUN_004a6e50 uses param_1[0x60] (int* index = byte offset 0x180) | **CONFLICT:** Actual byte offset is 0x180 (param_1 is int*, so [0x60] = offset 0x180) |
| +0x61 | byte | PitState | **WRONG** | FUN_004a6e50 uses param_1[0x61] (int* index = byte offset 0x184) | **CONFLICT:** Actual byte offset is 0x184 |
| +0x62 | byte | PitEntryTimer | **WRONG** | FUN_004a6e50 uses param_1[0x62] (int* index = byte offset 0x188) | **CONFLICT:** Actual byte offset is 0x188 |
| +0xf3 | char* | LiveryName | LOW | FUN_004ddad0 (param_1[0xf3] as string ptr) | Off-by-4? param_1 is int* in this context? |
| +0xf5-0xf9 | ptr | TrackLiveryList | LOW | FUN_004ddad0 (param_1[0xf5] linked list) | Overlapping offset range |
| +0xf6 | ptr | PitCrewLivery | LOW | FUN_004ddad0 (param_1[0xf6] as string ptr) | |

**Verdict: LOW-MEDIUM. FUN_004a6e50 uses int* param_1, so offsets +0x60/+0x61/+0x62 are actually byte offsets 0x180/0x184/0x188. FUN_004ddad0 uses undefined4* param_1, so [0xf3] = byte offset 0x3CC — unclear if referencing same struct.**

### Struct 4: Vehicle Struct — Session/Pit Timer Section

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb0 | int | LapTimeRemaining | HIGH | FUN_004d23d0 (float), FUN_004d2e50 (int) | **CONFLICT:** FUN_004d23d0 uses float, docs say int |
| +0xb4 | int | RaceTimeRemaining | HIGH | FUN_004d23d0 (float), FUN_004d2e50 (int) | **CONFLICT:** FUN_004d23d0 uses float, docs say int |
| +0xb8 | int | PitTimeOffset | HIGH | FUN_004d23d0 (float) | **CONFLICT:** docs say int, code uses float |
| +0xc1 | byte | PenaltyFlag | HIGH | FUN_004d23d0 (undefined1 = 0) | none |
| +0xc2 | byte | FormationLapFlag | HIGH | FUN_004d23d0, FUN_004d2e50 (both byte) | none |
| +0xd8 | int | PitWindowOpenTime | HIGH | FUN_004d23d0 (undefined4 copy), FUN_004d2e50 (int) | none |
| +0xf4 | byte | FinishState | MEDIUM | FUN_004d2e50 (param_1[0x3d] as int; docs say byte at +0xf4 but param_1 is int*) | **POTENTIAL CONFLICT:** param_1[0x3d] = byte offset 0xf4 as int → offset matches, type is int not byte |
| +0x104 | byte | ProcessedFlag | MEDIUM | FUN_004d2e50 (param_1[0x41] as byte cast) | none |

**Verdict: MEDIUM-HIGH. Offsets are correct. But type CONFLICTS:**
- +0xb0, +0xb4, +0xb8: docs say `int`, code uses `float` in FUN_004d23d0 (reads/writes as float)
- +0xf4: docs say `byte`, FUN_004d2e50 uses `param_1[0x3d]` (int access, then cast to float for comparison, not byte)

### Struct 5: Part Repair/Status

(Source file FUN_004a58b0 found in decompiled_all/ but prompt section was truncated. Checking available offsets:)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| param_1[0x1b] | int | (parts count?) | LOW | FUN_004a58b0 (iVar6 = param_1[0x1b]) | Need full context from docs |
| param_1[0x18] | double | (repair cost base?) | LOW | FUN_004a58b0 (dVar1 = *(double*)(param_1+0x18)) | int* index 0x18 = byte offset 0x60 |
| param_1[0x16] | double | (repair cost coeff?) | LOW | FUN_004a58b0 (dVar2 = *(double*)(param_1+0x16)) | int* index 0x16 = byte offset 0x58 |
| param_1[0x5f] | float | (repair flag?) | LOW | FUN_004a58b0 ((float)param_1[0x5f]) | |
| param_1+0x76 | char[] | (status string) | LOW | FUN_004a58b0 (sprintf target) | |
| param_1[0x2b] | int | (part index?) | LOW | FUN_004a58b0 (FUN_004a5820 call) | |
| param_1[0x3b] | int | (current?) | LOW | FUN_004a58b0 (iVar6 = param_1[0x3b]) | |
| param_1[0x3c] | int | (max?) | LOW | FUN_004a58b0 (iVar7 = param_1[0x3c]) | |
| param_1+0xf6 | char[] | (count string) | LOW | FUN_004a58b0 (sprintf target) | |
| param_1[0x4a] | int | (repair type?) | LOW | FUN_004a58b0 (==1 check) | |
| param_1[0x4b] | int | (repair flag?) | LOW | FUN_004a58b0 (==0 = Do Not Repair) | |
| param_1+0x136 | char[] | (repair status string) | LOW | FUN_004a58b0 (sprintf target) | |
| param_1+0x36 | char[] | (cost string) | LOW | FUN_004a58b0 (sprintf target) | |
| param_1[10] | int | (unknown flag) | LOW | FUN_004a58b0 (!=1 check) | |
| param_1[0xb] | int | (repair string selector) | LOW | FUN_004a58b0 (==0 selects different string) | |
| *param_1+0x4074 | int | (cost value) | LOW | FUN_004a58b0 (uVar4 = *(undefined4*)(*param_1+0x4074)) | Double-indirection |

**Verdict: LOW confidence — prompt section was truncated, cannot fully verify against original docs table. Partial offsets checked from code.**

---

## SUMMARY

| Section | Name | Confidence | Conflicts Found |
|---------|------|------------|-----------------|
| 160 | TireForceQuadraticModel | **HIGH** | 0 |
| 161 | PlayerOptionsFailureRates | **LOW** | Source not found |
| 162 | DoublyLinkedList | **HIGH** | 0 (variances correctly noted) |
| 163 | QuadFunctionCoeffs | **HIGH** | 0 (7 new offsets discovered) |
| 164 | VectorPositionStruct | **HIGH** | 0 |
| 165 | InitFloatConstantsStruct | **MEDIUM** | 0 (5 intermediate zero fields undocumented) |
| 166 | Terrain Validation Flags | **LOW** | Source not found |
| 167 | docs/19-renderer.md ref | N/A | No offsets to audit |
| 168 | Render Object/VTable Wrapper | **LOW** | +0x90 unverified; 2 new offsets discovered |
| 169 | ViewportRect | **HIGH** | **3 naming swaps** — docs have [1]↔[2], [4]↔[5], [6]↔[7] swapped |
| 170 | GridCellIndex | **LOW** | 0 (stack-based temp, types correct) |
| 171 | NetComm Session Struct | **HIGH** | **5 type conflicts** (byte vs int), +0x1c row error, 7 new offsets |
| 172 | StreamEventDecompressor | **HIGH** | 0 |
| 173.1 | Pit Crew Actor | **HIGH** | **4 offset errors** — POSITION/ROTATE offsets off by 2× |
| 173.2 | Pit Order Config | **MEDIUM** | 0 |
| 173.3 | Vehicle Livery/Pit | **LOW** | **3 offset errors** (int* vs byte* confusion) |
| 173.4 | Vehicle Session Timer | **MEDIUM** | **3 type conflicts** (float vs int) |
| 173.5 | Part Repair/Status | **LOW** | Truncated input, partial verification |

**Total conflicts flagged: 20**
**New offsets discovered: 7 (QuadFunctionCoeffs) + 5 (InitFloatConstants) + 2 (RenderObject) + 7 (NetComm) = 21**
