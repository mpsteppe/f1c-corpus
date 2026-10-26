=== AUDIT RESULTS ===

## CameraStruct (param_1 — camera/projection)

Based on FUN_00541b70, FUN_00545670, FUN_0054e190. Confidence: **HIGH**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x004 | float | NearPlane | HIGH | FUN_00541b70: `*(float *)(param_1 + 4)` | none |
| +0x008 | float | FarPlane | HIGH | FUN_00541b70: `*(float *)(param_1 + 8)` | none |
| +0x01c | float | FocalX | HIGH | FUN_00541b70: `*(float *)(param_1 + 0x1c)` | none |
| +0x020 | float | FocalY | HIGH | FUN_00541b70: `*(float *)(param_1 + 0x20)` | none |
| +0x080 | byte | Flags | HIGH | FUN_00541b70: `*(byte *)(param_1 + 0x80)` & bit 0x10 check | none |
| +0x11c | float | CameraPosX | HIGH | FUN_00545670: `*(undefined4 *)(param_1 + 0x11c)` | none |
| +0x120 | float | CameraDistance | HIGH | FUN_0054e190: returns `*(undefined4 *)(param_1 + 0x120)` | none |
| +0x124 | float | CameraPosY | HIGH | FUN_00545670: `*(undefined4 *)(param_1 + 0x124)` | none |
| +0x15c | float[16] | ViewMatrix | HIGH | FUN_00541b70: passed as matrix `param_1 + 0x15c` to FUN_0055ca40 | none |
| +0x18c | ptr | CameraObjPtr | HIGH | FUN_00515ecd: `*(undefined4 **)(param_1 + 0x18c) = puVar1` (pointer store) | none |

**Summary:** All 10 offsets verified. No conflicts. Confidence upgraded to HIGH (3 functions, consistent patterns). CameraPosX/Y read as uint but semantically float. NEW: FUN_00545670 also reads `*(undefined4 *)(param_1 + 300)` = offset +0x12c (undocumented field, likely CameraPosZ).

---

## GridCellIterate (grid counter)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x934 | int | CellCounter / RenderCounter | HIGH | FUN_004be340: read as `*(int *)(param_1 + 0x934)`, incremented, stored back. FUN_004be4e0: same pattern. | none |

**Summary:** Single offset confirmed in 2 near-identical functions. Type and behavior match. Confidence: HIGH.

---

## SceneExtents (inferred — FUN_004bdc10)

Source: decompiled_all (searchgrid.cpp).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x924 | float | MinX | HIGH | FUN_004bdc10: `*(float *)(param_1 + 0x924) = local_30` | none |
| +0x928 | float | ScaleX | HIGH | FUN_004bdc10: `*(float *)(param_1 + 0x928) = fVar1` (computed as DAT_0059e4dc/(maxX-minX)) | none |
| +0x92c | float | MinZ | HIGH | FUN_004bdc10: `*(float *)(param_1 + 0x92c) = local_28` | none |
| +0x930 | float | ScaleZ | HIGH | FUN_004bdc10: `*(float *)(param_1 + 0x930) = DAT_0059e4dc/(local_1c - local_28)` | none |

**Summary:** All 4 offsets confirmed from single function. Types match. Scale constants use global DAT_0059e4dc (likely render width). Confidence: HIGH (was medium).

---

## CollisionContactBufferStruct

Based on FUN_004492d0. Confidence: **MEDIUM**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | ElementCount | LOW | Not explicitly set in FUN_004492d0 (likely zeroed by allocator or set in separate function) | none |
| +0x04 | int | AllocatedCount | HIGH | FUN_004492d0: `*(int *)(param_1 + 4) = param_2` (capacity) | none |
| +0x08 | void* | BufferPtr | HIGH | FUN_004492d0: `*(int **)(param_1 + 8) = piVar1 + 1` (pointer to first element) | none |

**Summary:** +0x04 and +0x08 confirmed. +0x00 not explicitly written in constructor — confidence LOW for that field. ElementCount may be initialized to 0 by default or in a separate zero-init function. Confidence overall: MEDIUM.

---

## CollisionShapeStruct (0x20 bytes)

Based on FUN_00448e90. FUN_00492b0 referenced in docs but source file not found in any directory. Confidence: **HIGH** from single verified function.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Field0 | HIGH | FUN_00448e90: zeroed (loop 6 ints). FUN_00433090: freed as `param_1[0]` (ptr!) | **TYPE CONFLICT**: docs say int, FUN_00433090 treats as pointer |
| +0x04 | int | Field1 | HIGH | FUN_00448e90: zeroed in loop | none |
| +0x08 | int | Field2 | HIGH | FUN_00448e90: zeroed. FUN_00433090: freed as `param_1[2]` (ptr!) | **TYPE CONFLICT**: docs say int, FUN_00433090 treats as pointer |
| +0x0c | int | Field3 | HIGH | FUN_00448e90: zeroed in loop | none |
| +0x10 | int | Field4 | HIGH | FUN_00448e90: zeroed in loop | none |
| +0x14 | int | Field5 | MEDIUM | FUN_00448e90: zeroed in loop. FUN_00433090: freed as `param_1[5]` (ptr!) | **TYPE CONFLICT**: docs say int, FUN_00433090 treats as pointer |
| +0x18 | byte | ActiveFlag | HIGH | FUN_00448e90: `*(undefined1 *)(param_1 + 6) = 1` (int-indexed byte at +0x18) | none |
| +0x19 | byte | BVType | HIGH | FUN_00448e90: `*(undefined1 *)((int)param_1 + 0x19) = 0` | none |
| +0x1a | short | CollisionGroup | HIGH | FUN_00448e90: `*(undefined2 *)((int)param_1 + 0x1a) = 0xffff` | none |

**Findings:**
1. **3 TYPE CONFLICTS**: Field0 (+0x00), Field2 (+0x08), Field5 (+0x14) are used as pointers in FUN_00433090 (freed via FUN_00587bcf). Should be `ptr` not `int`.
2. FUN_00492b0 referenced in docs does not exist in any source directory.
3. NEW OFFSET: FUN_00448e90 zeroes `param_1[7]` = offset +0x1c (int, undocumented). Suggests struct extends to at least 0x20 bytes.

---

## PositionDeltaStruct (inferred)

Based on FUN_004faec0. Confidence: **HIGH**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float[3] | CurrentPosition | HIGH | FUN_004faec0: `param_1[0..2]` as float[3] (x,y,z) | none |
| +0x0c | float[3] | ComputedDelta | HIGH | FUN_004faec0: `param_1[3..5]` as float[3] (dx,dy,dz) | none |
| +0x10c | ptr | RefPtr | HIGH | FUN_004faec0: `param_1[0x43]` cast to float* (reference position pointer) | none |
| +0x110 | ptr | TargetPtr | HIGH | FUN_004faec0: `param_1[0x44]` cast to float* (target position pointer) | none |

**Summary:** All 4 offsets confirmed. Function uses float-indexed access on `float *param_1`. Individual float components at +0x00, +0x04, +0x08 (implicit in float[3]) and +0x0c, +0x10, +0x14 (implicit in float[3]). No conflicts.

---

## Track Database Struct (int-indexed)

Based on FUN_00460a10. Confidence: **MEDIUM** (single source, but all offsets verified).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | expected terrain type | LOW | `*(short *)(param_2 + 8)` — read as **short** (2 bytes), not int | **TYPE CONFLICT**: docs say int, code says **short** |
| +0x0c | int | expected surface type hash | HIGH | `*(int *)(param_2 + 0xc)` | none |
| +0x10 | int | expected terrain.ini CRC | HIGH | `*(int *)(param_2 + 0x10)` | none |
| +0x14 | int | expected track name hash | HIGH | `*(int *)(param_2 + 0x14)` | none |
| +0x18 | int | expected full path hash | HIGH | `*(int *)(param_2 + 0x18)` | none |

**Summary:** 4 of 5 offsets match. +0x08 type conflict: docs say `int` (4 bytes) but code reads `*(short *)` (2 bytes). Should be `short` or `int16`. Otherwise verified. Note: param_1 (terrain validation flags) accessed at very high offsets (+0x1b76a–e), not related to this struct.

---

## Render Args Struct (inferred)

Based on FUN_0058a40a, FUN_0058a4e5. Confidence: **HIGH**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | arg1 | HIGH | FUN_0058a40a: `*(undefined4 *)(param_2 + 8)`. FUN_0058a4e5: same. | none |
| +0x0c | int | arg2 | HIGH | FUN_0058a40a: `*(undefined4 *)(param_2 + 0xc)`. FUN_0058a4e5: same. | none |
| +0x10 | int | arg3 | HIGH | FUN_0058a40a: `*(undefined4 *)(param_2 + 0x10)`. FUN_0058a4e5: same. | none |
| +0x14 | int | arg4 | HIGH | FUN_0058a4e5: `*(undefined4 *)(param_2 + 0x14)` | none |
| +0x18 | ptr | dispatchFn | HIGH | FUN_0058a4e5: `(**(code **)(param_2 + 0x18))()` — called as function pointer | none |
| +0x24 | int | stateFlag | HIGH | FUN_0058a4e5: read as `*(int *)(param_2 + 0x24)`, also set to 1 | none |

**Summary:** All 6 offsets confirmed across 2 functions. No conflicts. StateFlag checked for early-out and set to 1 on failure condition.

---

## CollisionDamageContactStore (inferred — FUN_0045b840)

Based on FUN_0045b840. Confidence: **MEDIUM**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x31C | int | ContactCount | HIGH | `*(int *)(param_1 + 0x31c)` — read contact count for loop | none |
| +0x320 | float | ContactEnergy | MEDIUM | Per-contact at stride 0x5c, offset 0x90 within contact: `*(float *)(iVar1 + 0x90)` | **STRIDE CONFLICT**: docs say stride 0x90, actual stride is **0x5c** |
| +0x3C (per contact) | float[3] | ContactPosition | HIGH | `iVar1 + 0x3c` passed to FUN_004dd030 as position | none |
| +800 (0x320) | byte | DecayDoneFlag | HIGH | `*(undefined1 *)(param_1 + 800)` set to 0, then conditionally set to 1 | none |

**Detailed analysis:**
- Contact stride is **0x5c**, not 0x90 as documented.
- ContactEnergy per-contact offset is 0x90 within each 0x5c-byte contact block (iVar1 = param_1 + i * 0x5c).
- The absolute offset +0x320 in docs for ContactEnergy is misleading — it only equals contact[5] energy by coincidence (5 × 0x5c + 0x90 = 0x25C, not 0x320). Actually no contact index lands at absolute 0x320.
- DecayDoneFlag at absolute 0x320 is confirmed as a separate field.
- ContactPosition at per-contact +0x3c within stride 0x5c is confirmed.

---

## CollisionMutexState (inferred — from FUN_0045bf90)

Based on FUN_0045bf90. Confidence: **HIGH** (globals, single function).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| DAT_007cd264 | HANDLE | MutexHandle | HIGH | `DAT_007cd264 = CreateMutexA(...)` | none |
| DAT_007cd268 | int | LockState | HIGH | `_DAT_007cd268 = 0xffffffff` (-1 = unlocked) | none |
| DAT_007cd26C | int | InitFlag | HIGH | `DAT_007cd26c = 0` initially, `= 1` after CreateMutexA succeeds | none |

**Summary:** All 3 globals confirmed. Note: no struct offsets — these are standalone globals, not fields in a struct. Should be in docs/12-globals, not docs/13-struct-offsets. Function uses Win32 CreateMutexA for collision thread synchronization.

---

## Scene Instance/Node Struct (inferred)

Based on FUN_0055a910, FUN_004fc2f0. Confidence: **HIGH** (all offsets verified).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x3c | int | InstanceFlags | HIGH | FUN_0055a910: `*(uint *)(iVar2 + 0x3c)` — bitfield manipulated extensively | **BIT VALUES WRONG** (see below) |
| +0x50 | unknown | ClipPlaneData | HIGH | FUN_0055a910: `*(undefined4 *)(iVar2 + 0x50) = local_338` (PLANES keyword) | none |
| +0x118 | int | NodeCount | HIGH | FUN_004fc2f0: `*(int *)(param_2 + 0x118)` — loop limit | none |
| +0x128 | ptr | NodeList | HIGH | FUN_004fc2f0: `*(int *)(param_2 + 0x128)` — pointer, stride 0x100 | none |
| +0x13c | int | ShadowRecvCount | HIGH | FUN_0055a910: `*(int *)(param_1 + 0x13c)++` (incremented per SHADOWRECEIVER) | none |
| +0x174 | int | ReflectorCount | HIGH | FUN_0055a910: `*(int *)(param_1 + 0x174)++` (incremented per REFLECTOR) | none |

**Node flags (+0x14 bitmask):** — these are on a CHILD NODE struct (iVar6 from linked list at +0x204), NOT the instance struct.

| Bit position | Field | .c Evidence | Match |
|-------------|-------|-------------|-------|
| 6 (0x40) | COLLTARGET | `0x40` bit set/cleared | ✓ |
| 7 (0x80) | SPHERETARGET | `0x80` bit set/cleared | ✓ |
| 8 (0x100) | HATTARGET | `0x100` bit set/cleared | ✓ |
| 13 (0x2000) | ZBUFFER_DISABLE | `0x2000` bit set/cleared | ✓ |
| 14 (0x4000) | SHADOW_RECEIVER | `0x4000` bit set/cleared | ✓ |
| 17 (0x20000) | REFLECTOR | `0x20000` bit set/cleared | ✓ |
| 21 (0x200000) | MORPH_TARGET | `0x200000` bit set/cleared | ✓ |
| 25 (0x2000000) | SHADOW_CASTER | `0x2000000` bit set/cleared | ✓ |

**InstanceFlags (+0x3c) bit value CORRECTIONS:**

| Doc Claim | Actual Bit Mask | Actual Bit Pos | Doc Bit | Status |
|-----------|----------------|----------------|---------|--------|
| MOVEABLE(0x1) | **0x10** | 4 | bit 0 | ✗ WRONG |
| RENDERdis(0x4) | **0x4** | 2 | bit 2 | ✓ CORRECT |
| CHANGEdis(0x8) | **0x200** | 9 | bit 3 | ✗ WRONG |
| STAMP(0x10) | **0x100** | 8 | bit 4 | ✗ WRONG |
| BILLBOARD(0x9) | **0x2000** | 13 | bit 3/bit 1 | ✗ WRONG |

**Additional offsets discovered:**
- Instance +0x38: uint VISGROUPS flag (FUN_0055a910: `*(uint *)(iVar2 + 0x38) = local_304`)
- Instance +0x40: int field (set to param_3)
- Instance +0x204: ptr to first child node (linked list via +0x10)
- Node +0x10: ptr next node (linked list)
- Node +0xfc: data field (receives copy of instance +0x50)

---

## AllocStruct18 (inferred, 0x18 bytes)

Based on FUN_00564810. Confidence: **HIGH**.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Zeroed | HIGH | `*puVar1 = 0` | none |
| +0x04 | int | ElementSize | HIGH | `puVar1[1] = param_2` (default 8) | none |
| +0x08 | int | Capacity | HIGH | `puVar1[2] = param_1` | none |
| +0x0c | int | Count | HIGH | `puVar1[3] = param_2` BUT set to ElementSize, not 0 | **SEMANTIC NOTE**: named Count but initialized to ElementSize |
| +0x10 | int | UserData | HIGH | `puVar1[4] = param_3` | none |
| +0x14 | void* | DataBuffer | HIGH | `puVar1[5] = _malloc(param_1 * param_2)` | none |

**Summary:** All 6 offsets confirmed. Allocation size verified as 0x18 (24 bytes). Note: +0x0c initialized to ElementSize (param_2) not 0 — field may be "element stride" or "bytes per element" rather than "count". Internal data buffer = Capacity × ElementSize bytes.

---

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| CameraStruct | +0x12c | float | FUN_00545670 | CameraPosZ (third read, alongside +0x11c and +0x124) |
| CollisionShapeStruct | +0x1c | int | FUN_00448e90 | param_1[7] = 0 (zeroed field, extends struct past 0x20?) |
| SceneInstanceNode | +0x38 | uint | FUN_0055a910 | VISGROUPS flag storage |
| SceneInstanceNode | +0x40 | int | FUN_0055a910 | param_3 storage |
| SceneInstanceNode | +0x204 | ptr | FUN_0055a910 | First child node pointer |
| SceneNode | +0x10 | ptr | FUN_0055a910 | Next node (linked list) |
| SceneNode | +0xfc | undefined4 | FUN_0055a910 | Data field (copied from instance +0x50) |
| SceneNode | +0x14 (name) | char[?] | FUN_004fc2f0 | Node name string (strncmp at +0x14 within node, not same as bitmask +0x14 — this is buffer start of 0x100-byte node) |

=== SUMMARY ===

**Sections audited:** 14 (all sections 146–159)
**Offsets verified:** 68
**Offsets with CONFLICTS:** 6
  - CollisionShapeStruct: +0x00, +0x08, +0x14 type (int→ptr)
  - TrackDB: +0x08 type (int→short)
  - SceneInstanceFlags: bit values all wrong
  - CollisionDamageContactStore: stride 0x5c not 0x90
**New offsets discovered:** 8
**Confidence upgrades:** 5 (CameraStruct→HIGH, GridCellIterate→HIGH, SceneExtents→HIGH, CollisionShapeStruct→HIGH, SceneInstance→HIGH)
**Functions not found:** FUN_00492b0 (referenced in CollisionShapeStruct)
**Globals documented as struct offsets:** CollisionMutexState (DAT_007cd264/268/26C are globals, not struct fields)
