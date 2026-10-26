=== AUDIT RESULTS ===

## Section 118: SceneNode / DrawableList (param_1 — scene graph node)

Confidence: LOW — significant function-to-offset mismatches.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | ActiveFlag | **LOW** | FUN_00545d00 does NOT use +0x00. FUN_00512322 uses +0x60, +0x117 (not +0x00). FUN_0040f130 uses `*param_1` when param_1 is int* (byte offset 0x00). **Only FUN_0040f130 confirms +0x00.** | Assigned to wrong functions |
| +0x04 | uint | CullFlags | **MEDIUM** | FUN_0054a0a0 uses `*(uint *)(param_1 + 4)` — confirmed. FUN_00549fb0 also uses `param_1 + 4` as uint. Both read/write bitmask (1=inside, 2=outside, 4=partial). 2 functions agree. | None |
| +0x0c | int | param_1[3] | **HIGH** | FUN_0040f130: `param_1 + 3` (int* index 3 = byte 0x0c). Parameter passed to FUN_00459830. | None |
| +0x10 | int | Count | **LOW** | FUN_00545d00 does NOT use +0x10. No function found using +0x10 with uint type for count. | Claimed FUN_00545d00 but actual offsets differ |
| +0x14 | uint | Flags / CullFlags | **MEDIUM** | FUN_0054d030 uses `param_1 + 0x14`. FUN_0054d910 uses `param_1 + 0x14`. 2 functions agree on bitfield semantics. | None |
| +0x18 | float | NearPlaneDist | **MEDIUM** | FUN_00549fb0 uses `*(float *)(param_1 + 0x18)` as distance threshold (used in SQRT comparison). 1 function confirms. | None |
| +0x1c | int | param_1[7] | **HIGH** | FUN_0040f130: `param_1[7]` (int* index 7 = byte 0x1c). Switch selector (cases 0-5). | None |
| +0x20 | int | TypeTag | **LOW** | FUN_00545d00 does NOT use +0x20. Not confirmed by any function. | Claimed FUN_00545d00 — not found |
| +0x24–0x2c | float[3] | BoxVertices / SphereOffset | **MEDIUM** | FUN_0054a0a0: `(float *)(param_1 + 0x24)` as 3-float vectors for AABB test. 1 function confirms usage. | None |
| +0x3c | int | SomeFlag | **MEDIUM** | FUN_0054b770 uses `*(uint *)(param_1 + 0x3c)` with bit 0 test. Not used by FUN_00545d00 as claimed. | Wrong function attribution |
| +0x40 | ptr | ParentPtr | **HIGH** | FUN_0054b770: `*(int *)(param_1 + 0x40) == 0` null check. Confirmed as parent pointer. | None |
| +0x50 | int | TypeTag | **LOW** | No function found using +0x50 with TypeTag semantics. FUN_004fc2f0 uses +0x50 for string copy (different struct). | No evidence for SceneNode |
| +0x7c–0x84 | float[3] | FrustumPosition | **HIGH** | FUN_00549fb0: uses +0x7c, +0x80, +0x84 as 3 float position elements. Added to param_2's box vertices for frustum test. | None |
| +0x94 | ptr | AltTransformDest | **HIGH** | FUN_0054b770: uses `*(int *)(param_1 + 0x94)` with bit 0 flag check. Confirmed. | None |
| +0xd4 | float[16] | LocalMatrix | **HIGH** | FUN_0054b770: uses `(float *)(param_1 + 0xd4)` as 4×4 matrix source for computations. | None |
| +0xfc | int | ElementCount | **MEDIUM** | FUN_0054d910 uses `param_1 + 0xfc` as count for element test loop. 1 function. | None |
| +0x100 | ptr | NodeChainHead / HeadPtr | **HIGH** | FUN_00545d00: `*(int *)(param_1 + 0x100)` as linked list head. FUN_0054a2d0, FUN_005453a0 also use it. 3+ functions. | None |
| +0x104 | float[4]×6 | FrustumPlanes | **LOW** | Listed as FUN_00549fb0 but that function uses param_2 (not param_1) for plane data. No param_1 + 0x104 found. | Claimed on wrong param |
| +0x108 | ptr | DefaultNode | **MEDIUM** | FUN_00545d00: `*(int *)(param_1 + 0x108)` null check. FUN_005453a0 also uses it. 2 functions. | None |
| +0x114 | float[16] | WorldMatrix | **HIGH** | FUN_0054b770: uses `(float *)(param_1 + 0x114)` as computed 4×4 world matrix. | None |
| +0x118 | int | ChildCount / RecordCount | **HIGH** | FUN_0054d030, FUN_0054e100, FUN_0054e120, FUN_00519986 all use +0x118 as count. 4+ functions. | None |
| +0x11c | ptr | ChildArrayPtr / RecordArrayPtr | **HIGH** | FUN_0054d030, FUN_0054e100, FUN_0054e120 use +0x11c as array pointer. 3 functions. | None |
| +0x120 | int | FrameCount / ObjectCount | **HIGH** | FUN_00519986, FUN_0054e080 use +0x120 as count. 2 functions. | None |
| +0x124 | ptr | FrameArray / ObjectArrayPtr | **HIGH** | FUN_00519986, FUN_0054e080 use +0x124 as array pointer. 2 functions. | None |
| +0x194 | float | ScaleX | **HIGH** | FUN_0054b770: multiplier applied to row 0 of LocalMatrix. | None |
| +0x198 | float | ScaleY | **HIGH** | FUN_0054b770: multiplier applied to row 1 of LocalMatrix. | None |
| +0x19C | float | ScaleZ | **HIGH** | FUN_0054b770: multiplier applied to row 2 of LocalMatrix. | None |
| +0x1A0 | float[16] | OutputMatrix | **HIGH** | FUN_0054b770: writes result matrix at +0x1a0. | None |
| +0x204 | ptr | AnimNodeListHead / ListHead | **MEDIUM** | FUN_0054bf60, FUN_0054ac30, FUN_0054abe0 all access +0x204 as list pointer. 3 functions. | None |

**MAJOR ISSUE:** FUN_00545d00 is claimed for offsets +0x00, +0x0c, +0x10, +0x20, +0x3c but NONE of these offsets appear in the actual function. FUN_00545d00 actually uses offsets in 0xec–0x1d0 range. The function-to-offset mapping for this function is entirely wrong.

**FIX:** Remove FUN_00545d00 from all SceneNode offsets it doesn't use (+0x00, +0x0c, +0x10, +0x20, +0x3c). The +0x00 and +0x0c claims should be attributed only to FUN_0040f130 (where param_1 is int*, giving correct array-indexed offsets).

---

## Section 119: AudioRingBuffer (buffer manager)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c000 | various | RingBuffer base | **LOW** | Base address not directly accessed as param_1 + 0x6c000. The buffer content is at relative offsets 0x6c004–0x6c00c. | Base offset may be structural |
| +0x6c004 | ptr | EndPtr | **HIGH** | FUN_004b3af0: `*(int *)(param_1 + 0x6c004)`. Read for ring buffer wrap check. | None |
| +0x6c008 | ptr | StartPtr / SourceValue | **HIGH** | FUN_004b3af0 and FUN_004b3b30 both access +0x6c008. Read in copy loop. 2 functions. | Name could be SourcePtr |
| +0x6c00c | ptr | CurrentPtr / DestValue | **HIGH** | FUN_004b3af0 and FUN_004b3b30 both access +0x6c00c. Written in copy loop. 2 functions. | Name could be DestPtr |

**Verdict:** Core offsets confirmed. +0x6c000 base may just be struct start. Confidence upgraded to MEDIUM.

---

## Section 120: RaceModeBackup

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | byte | InitFlag | **HIGH** | FUN_00404890, FUN_004049d0 both write byte at +0x14. 2 functions agree. | None |
| +0x15 | byte | InitFlag2 | **MEDIUM** | FUN_00404890 writes byte at +0x15. Only 1 function. | Only in FUN_00404890 |
| +0x20 | byte | StateCondition | **HIGH** | FUN_00404890, FUN_004049d0 both check byte at +0x20 == 1. 2 functions. | None |
| +0x50 | int | SavedSessionType | **HIGH** | FUN_00404890, FUN_004049d0 both use int at +0x50 as backup of DAT_007d2e44. 2 functions. | None |
| +0x54 | int | SavedRaceMode | **HIGH** | FUN_00404890, FUN_004049d0 both use int at +0x54 as backup of DAT_007d0410. 2 functions. | None |

**Verdict:** All offsets confirmed. Confidence: HIGH.

---

## Section 121: BVH/TreeNode (0x60 bytes)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | SplitX | **HIGH** | FUN_004485d0: `*param_2` / `*pfVar4` as float. Used in 4-way comparison for tree traversal. | None |
| +0x04 | byte[8] | Pad1 | **LOW** | **WRONG.** FUN_004485d0 treats +0x04 as `double` (via `*(double *)(param_2 + 1)` where param_2 is float*). FUN_00448de0 treats +0x04 as `double` (via `*(double *)(param_1 + 4)`). **Not padding.** | **CONFLICT:** Two rows claim +0x04 (Pad1 byte[8] vs LocalValue double). Also used as DoubleKey by FUN_004485d0 |
| +0x04 | double | LocalValue | **HIGH** | FUN_00448de0: `*(double *)(param_1 + 4)` — read and accumulated. Confirmed. | See above — same as DoubleKey? |
| +0x0c | float | SplitY | **MEDIUM** | FUN_004485d0: `pfVar4[3]` (index 3 of float* = byte offset 0x0c). Used in comparison. | None |
| +0x10 | double | DoubleKey | **HIGH** | FUN_00448de0: `*(double *)(param_1 + 0x10)` — read, accumulated, written. Used as accumulator. | None |
| +0x48 | int | LinearIndex | **MEDIUM** | FUN_004486e0 uses `param_1 + 0x48` as DFS-assigned index. 1 function. | None |
| +0x4c | int* | Child[0] | **HIGH** | FUN_004485d0: `pfVar4[iVar5 + 0x13]` (i=0 → index 0x13 → offset 0x4c). FUN_00448de0, FUN_004486e0, FUN_00448da0, FUN_00448e50, FUN_004486a0 all confirm. 6+ functions. | None |
| +0x50 | int* | Child[1] | **HIGH** | FUN_004485d0: index 0x14 → offset 0x50. Confirmed by 6+ functions. | None |
| +0x54 | int* | Child[2] | **HIGH** | FUN_004485d0: index 0x15 → offset 0x54. Confirmed by 6+ functions. | None |
| +0x58 | int* | Child[3] | **HIGH** | FUN_004485d0: index 0x16 → offset 0x58. Confirmed by 6+ functions. | None |
| +0x5c | int* | NextSibling | **HIGH** | FUN_004485d0: index 0x17 → offset 0x5c. FUN_00448de0, FUN_004486e0, FUN_00448da0, FUN_00448e50, FUN_004486a0 all confirm. 6+ functions. | None |

**FIX NEEDED:** Remove Pad1 row at +0x04. Rename to clarify that +0x04 is a double (either LocalValue or DoubleKey depending on context). The two rows at +0x04 should be merged: it's a `double` field. FUN_004485d0 uses it as tree-sort DoubleKey, FUN_00448de0 uses it as LocalValue accumulator. These could be the same field in different tree operations.

---

## Section 122: EnergyAccumulationStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x138 | double[4] | WheelEnergy | **HIGH** | FUN_004390a0: `pdVar3 = (double *)(param_1 + 0x138)`, stride 0x58 for 4 wheels. Iterated in loop. Confirmed. | Stride 0x58 implies interleaved per-wheel data, not contiguous double[4] |
| +0xdf0 | double[3] | FrontEnergyParams | **MEDIUM** | FUN_004390a0: Reads +0xdf0 (double) and +0xdf8 (double). But third element is `*(int *)(param_1 + 0xe04)` — **int, not double**. | **TYPE CONFLICT:** Third element is int (4 bytes), not double (8 bytes). Between +0xdf8 (8B) and +0xe04 (4B) there's a 4-byte gap at +0xe00. |
| +0xe30 | double[3] | RearEnergyParams | **MEDIUM** | FUN_004390a0: Reads +0xe30 (double) and +0xe38 (double). Third element is `*(int *)(param_1 + 0xe44)` — **int**. | Same type issue as FrontEnergyParams |
| +0x1270 | double[3] | ChassisEnergyParams | **MEDIUM** | FUN_004390a0: Reads +0x1270 (double) and +0x1278 (double). Third element is `*(int *)(param_1 + 0x1284)` — **int**. | Same type issue |
| +0x12b0 | double[3] | SecondaryEnergyParams | **MEDIUM** | FUN_004390a0: Reads +0x12b0 (double) and +0x12b8 (double). Third element is `*(int *)(param_1 + 0x12c4)` — **int**. | Same type issue |
| +0x12f0 | double[3] | FrontCombinedParams | **MEDIUM** | FUN_004390a0: Reads +0x12f0 (double) and +0x12f8 (double). Third element is `*(int *)(param_1 + 0x1304)` — **int**. | Same type issue |
| +0x1330 | double[3] | RearCombinedParams | **MEDIUM** | FUN_004390a0: Reads +0x1330 (double) and +0x1338 (double). Third element is `*(int *)(param_1 + 0x1344)` — **int**. Also note: +0x1330 overlaps with LifetimeAvg field from docs/13 vehicle struct. | **TYPE CONFLICT:** Same issue. Also potential struct overlap at +0x1330. |

**FIX:** Change type from `double[3]` to `struct { double a; double b; int c; }` for each params block. Each block is 12 bytes (8+4) with a 4-byte gap after the first double pair.

---

## Section 123: VehicleSceneNodeMap (inferred)

Based on FUN_004dfce0 (in decompiled_all/). Uses `param_1` as `int*` (array-indexed).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x144 (idx 0x51) | int | LFTIRE_idx | **HIGH** | `param_1[0x51]` stores scene node handle for "LFTIRE". Confirmed. | None |
| +0x188 (idx 0x62) | int | LFSPINDLE_idx | **HIGH** | `param_1[0x62]` for "LFSPINDLE". Confirmed. | None |
| +0x26c (idx 0x9b) | int | RFTIRE_idx | **HIGH** | `param_1[0x9b]` for "RFTIRE". Confirmed. | None |
| +0x2b0 (idx 0xac) | int | RFSPINDLE_idx | **HIGH** | `param_1[0xac]` for "RFSPINDLE". Confirmed. | None |
| +0x394 (idx 0xe5) | int | LRTIRE_idx | **HIGH** | `param_1[0xe5]` for "LRTIRE". Confirmed. | None |
| +0x3d8 (idx 0xf6) | int | LRSPINDLE_idx | **HIGH** | `param_1[0xf6]` for "LRSPINDLE". Confirmed. | None |
| +0x4bc (idx 0x12f) | int | RRTIRE_idx | **HIGH** | `param_1[0x12f]` for "RRTIRE". Confirmed. | None |
| +0x500 (idx 0x140) | int | RRSPINDLE_idx | **HIGH** | `param_1[0x140]` for "RRSPINDLE". Confirmed. | None |
| +0x5e4 (idx 0x179) | int | FWING_idx | **HIGH** | `param_1[0x179]` for "FWING". Confirmed. | None |
| +0x628 (idx 0x18a) | int | RWING_idx | **HIGH** | `param_1[0x18a]` for "RWING". Confirmed. | None |
| +0x66c–0x91c | int[8] | DEBRIS0–7_idx | **HIGH** | `param_1[0x19b]` loop with stride 0x11 (17 ints) for 8 debris items. Each stores "DEBRIS_d" scene node handle. | Stride 0x11 between debris entries |
| +0x88c (idx 0x223) | int | COCKPIT_idx | **HIGH** | `param_1[0x223]` for "COCKPIT". Confirmed. | None |
| +0x890 (idx 0x224) | int | SUSPENSION_idx | **HIGH** | `param_1[0x224]` for "SUSPENSION". Confirmed. | None |
| +0x894 (idx 0x225) | int | HELMET_idx | **HIGH** | `param_1[0x225]` for "HELMET". Confirmed. | None |
| +0x898 (idx 0x226) | int | (unnamed) | **HIGH** | `param_1[0x226]` for DAT_005c674c. Confirmed. | Name needed |
| +0x89c (idx 0x227) | int | (unnamed) | **HIGH** | `param_1[0x227]` for DAT_005d4d64. Confirmed. | Name needed |
| +0x8a0 (idx 0x228) | int | WHEEL_idx | **HIGH** | `param_1[0x228]` for "WHEEL". Confirmed. | None |
| +0x8a4 (idx 0x229) | int | RAINLIGHT_idx | **HIGH** | `param_1[0x229]` for "RAINLIGHT". Confirmed. | None |
| +0x8a8 (idx 0x22a) | int | BRAKELIGHT_idx | **HIGH** | `param_1[0x22a]` for "BRAKELIGHT". Confirmed. | None |
| +0x8ac (idx 0x22b) | int | HEADLIGHT_idx | **HIGH** | `param_1[0x22b]` for "HEADLIGHT". Confirmed. | None |
| +0x8b0 (idx 0x22c) | int | BACKFIRE_idx | **HIGH** | `param_1[0x22c]` for "BACKFIRE". Confirmed. | None |

**Verdict:** All 21 offsets confirmed from FUN_004dfce0. Confidence: HIGH.

**Additional offsets found in FUN_004dfce0 (not in docs section):**
- param_1[0x18]/[0x19]/[0x1a] = +0x60/+0x64/+0x68: position copy from [0x1e]/[0x1f]/[0x20]
- param_1[0x1b] = +0x6c: rotation copy from [0x21]
- param_1[0x1c]/[0x1d] = +0x70/+0x74: additional rotation copies from [0x22]/[0x23]
- param_1[0x22d] = +0x8b4: unnamed spare index or capacity count
- param_1[0x22e-0x22f] = +0x8b8-0x8bc: spare scene node indices
- param_1[0x230-0x231] = +0x8c0-0x8c4: CATSTEER indices
- param_1[0x23a-0x24b] = +0x8e8-0x92c: setup-derived vehicle parameters (up to +0x92c)
- param_1[0x24c-0x256] = +0x930-0x958: additional setup/rendering parameters
- param_1[0x254] = +0x950: counter/flag (zeroed)
- param_1[599-600] = +0x95c-0x960: setup parameters from file offset 0x6c/0x70
- param_1[0xaf4] = +0x2bd0: debris array count
- param_1[0xaf5] = +0x2bd4: debris array pointer

---

## Section 124: Vehicle Setup Struct

Based on FUN_004f6300 (in decompiled_all/). Uses unaff_ESI (vehicle struct) and unaff_EBX (setup struct) — not param_1.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xbc0 | void* | Tire brand data ptr | **HIGH** | `*(undefined4 *)(unaff_EBX + 0xbc0) = *(undefined4 *)(iVar9 + 0x10)` — assigned from tire DB lookup. Confirmed. | None |
| +0x13c0 | int | SetupType | **HIGH** | `*(undefined4 *)(unaff_ESI + 0x13c0) = 0/1/2` — set based on string match (Custom/Gearing/Balance/Downforce). Confirmed. | Uses unaff_ESI, not unaff_EBX |
| +0x1988 | bool | Auto-setup enabled | **HIGH** | `*(undefined1 *)(unaff_EBX + 0x1988) = *(undefined1 *)(unaff_ESI + 0x548)` — confirmed. | None |
| +0x1989 | bool | Auto-setup sub-flag | **HIGH** | `*(undefined1 *)(unaff_EBX + 0x1989) = *(undefined1 *)(unaff_ESI + 0x56c)` — confirmed. | None |
| +0x1990 | bool | Auto-setup flag | **HIGH** | `*(undefined4 *)(unaff_EBX + 0x1990) = in_stack_00000044` — confirmed (int, not bool). | Type is int, not bool |
| +0x1994 | float | FuelConsumptionRecip | **HIGH** | `*(double *)(unaff_EBX + 0x1994) = _DAT_0059e420 / dVar2` — but assigned as **double**, not float! Also writes `*(undefined4 *)(unaff_EBX + 0x1994) = 0` and `*(undefined4 *)(unaff_EBX + 0x1998) = 0` for zero case. | **TYPE CONFLICT:** Actual type is double (8 bytes at +0x1994–0x199b), not float (4 bytes). |
| +0x19a4 | bool | Setup bool flag | **HIGH** | `*(bool *)(unaff_EBX + 0x19a4) = in_stack_00000038 != 0` — confirmed as bool. | None |
| +0x19a5 | bool | Setup bool flag 2 | **HIGH** | `*(bool *)(unaff_EBX + 0x19a5) = in_stack_00000034 != 0` — confirmed as bool. | None |

**FIX:** +0x1994 is double, not float. Change type.

---

## Section 125: File Close Wrapper Struct (FUN_00599495)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x50 | int | FileHandle | **HIGH** | FUN_00599495: `*(int *)(param_1 + 0x50)` used as handle argument to FUN_005990f0 (file close). Confirmed. | None |

**Verdict:** Single offset, confirmed. Confidence: MEDIUM (single function).

---

## Section 126: Linked List Node (inferred)

**ISSUE:** The section claims this is a generic node with data/next/prev at +0x00/+0x04/+0x08. But FUN_00486540 does NOT use these offsets.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | data | **NONE** | FUN_00486540 does NOT access +0x00, +0x04, or +0x08 on the node struct. | **ENTIRELY WRONG.** Function uses +0xd8 for head pointer and +0x18 for next pointer. |
| +0x04 | ptr | next | **NONE** | Not found. | See above |
| +0x08 | ptr | prev | **NONE** | Not found. | See above |

**CORRECT offsets for this linked list implementation:**
- Container (param_1): +0xd8 = head pointer
- Node: +0x18 = next pointer

The function appends a node (`param_2`) to the end of a singly-linked list. It traverses using +0x18 as next, and stores the new node at the found tail's +0x18 or at container's +0xd8 if list is empty.

This is NOT a classic doubly-linked list with data/next/prev. It's a singly-linked list with +0x18 as next pointer and container head at +0xd8.

**Verdict: COMPLETELY WRONG.** Must be rewritten.

---

## Section 127: CollisionResponseState (inferred)

**IMPORTANT:** Functions use `*param_1` (double indirection), meaning the struct is pointed to by param_1, not at param_1 itself.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | int | CollisionThreshold | **HIGH** | FUN_00462ce0: `*(undefined4 *)(*param_1 + 0x10) = _DAT_0059f0a0` — confirmed as assigned from global threshold. | None |
| +0x29 | byte | ActiveFlag | **HIGH** | FUN_00462ce0: `*(undefined1 *)(*param_1 + 0x29) = 1` — confirmed. | None |
| +0x374 | int | ResponseFlag | **MEDIUM** | FUN_00463cd0: `param_1 + 0x374` accessed. 1 function. | Only in FUN_00463cd0 |
| +0x388 | float | SpeedParam | **MEDIUM** | FUN_004636a0: `param_1 + 0x388` accessed. 1 function. | Only in FUN_004636a0 |
| +0x3FC4 | int | CollisionType | **HIGH** | FUN_00462ce0: writes 4. FUN_00463cd0, FUN_00462940, FUN_0045f390 all access +0x3fc4. 4+ functions. | None |

**Verdict:** +0x10, +0x29, +0x3fc4 are HIGH confidence. +0x374, +0x388 are MEDIUM. No conflicts. Note the double-indirection pattern: offsets are on `*param_1`, not `param_1`.

---

## Section 128: ConstraintForceState (inferred — param_1 in FUN_00454250)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x040 | float | Stiffness | **NONE** | FUN_00454250 does NOT use +0x040, +0x060, or +0x398. | **NOT FOUND.** |
| +0x060 | float | RestValue | **NONE** | Not found in FUN_00454250. | Not confirmed. |
| +0x398 | float | CurrentValue | **NONE** | Not found in FUN_00454250. | Not confirmed. |
| +0xD88 | float[] | ConstraintSetPrimary | **HIGH** | FUN_00454250: uses `param_1 + 0xd88` in constraint setup. Confirmed. | None |
| +0x1184 | float[] | ConstraintSetSecondary | **HIGH** | FUN_00454250: uses `param_1 + 0x1184` in constraint setup. Confirmed. | None |

**Verdict:** +0xD88 and +0x1184 are HIGH confidence. +0x040, +0x060, +0x398 are **NOT FOUND** in FUN_00454250 — they should be removed or attributed to a different function/file.

---

## Section 129: Camera Struct (200 bytes, stride 200)

**CRITICAL ISSUE:** The section mixes at least 2 different structs: CameraManager (camera array container) and CameraDefinition (individual camera params).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | char*? | NodeName | **LOW** | Claimed from FUN_004fc2f0. But FUN_004fc2f0 uses param_1 + 0x50 for name copy (s_CLOUDS/s_CLOUDR), NOT +0x14. The function is likely a cloud/weather node, not a camera. | **WRONG attribution.** |
| +0x18 | int*? | Interface1 | **MEDIUM** | FUN_0040c890 uses param_1 + 0x18 as interface pointer (vtable dispatch). But this is on CameraManager struct, not CameraDefinition. | May be on different struct |
| +0x1c | int*? | Interface2 | **MEDIUM** | FUN_0040c890 uses param_1 + 0x1c as interface pointer. | Same ambiguity |
| +0x20 | int*? | Interface3 | **MEDIUM** | FUN_0040c890 uses param_1 + 0x20 as interface pointer. | Same ambiguity |
| +0x30 | float | Param1 / FOV | **HIGH** | FUN_00408870: writes 0x42700000 = 60.0 to camera instance + 0x30. Confirmed for CameraDefinition. | None |
| +0x34 | float | Param2 / FOV | **HIGH** | FUN_00408870: writes 0x42340000 = 45.0 to camera instance + 0x34. Confirmed. | None |
| +0x38 | float | NearClip | **HIGH** | FUN_00408870: writes 0x42700000 = 60.0 to +0x38. | None |
| +0x3c | float | FarClip | **HIGH** | FUN_00408870: writes 0x42340000 = 45.0 to +0x3c. | None |
| +0x40 | int | NameID | **CONFLICT** | FUN_00408870: writes 0x3e800000 = 0.25f to +0x40 (looks like a FOV/zoom parameter). FUN_00408e20: writes `unaff_retaddr` (camera count/id) to +0x40. | **CONFLICT:** Same offset used as float zoom param (0.25) in one context and camera index in another. |
| +0x44 | int | SlotCount / Range | **CONFLICT** | FUN_00408870: writes 0x43fa0000 = 500.0f to +0x44 (range). FUN_00408e20: writes `param_1` (camera count) to +0x44. | **CONFLICT:** float (500.0) vs int (camera count). |
| +0x48 | float | ScaleX | **HIGH** | FUN_00408870: writes 0x3f800000 = 1.0f to +0x48. Confirmed. | None |
| +0x4c | float | ScaleY | **HIGH** | FUN_00408870: writes 0x3f800000 = 1.0f to +0x4c. Confirmed. | None |
| +0x50 | float | ScaleZ | **HIGH** | FUN_00408870: writes 0x3f800000 = 1.0f to +0x50. Confirmed. | None |
| +0x54 | float | AspectClipX | **HIGH** | FUN_00408870: writes 0x3f000000 = 0.5f to +0x54. Confirmed. | None |
| +0x58 | float | AspectClipY | **HIGH** | FUN_00408870: writes 0x3f000000 = 0.5f to +0x58. Confirmed. | None |
| +0x60 | int | ActiveFlag | **HIGH** | FUN_00408870: writes byte 1 to +0x60. Confirmed. | None |
| +0x64–0x78 | byte[0x14] | Padding | **MEDIUM** | FUN_00408870: writes 0 to +0x64 through +0x78 (6 dwords + 2 zero + 3 more). Likely padding. | None |
| +0x80 | float | BaseOffsetX | **HIGH** | FUN_00408870: writes various values to +0x80 (0 for 2seater/3seater, 0 for pits). Confirmed. | None |
| +0x84 | float | BaseOffsetY | **HIGH** | FUN_00408870: writes various values to +0x84 (0 for 2seater/3seater, 5.0f for pits). Confirmed. | None |
| +0x88–0x90 | float[3]? | PositionRot | **HIGH** | FUN_00408870: writes to +0x88 (360.0), +0x8c (360.0), +0x90 (360.0) for 2seater/3seater; different positions for pit cams. Confirmed. | +0x8c also used by FUN_0040db00 as OriginalTarget ptr. |
| +0x8c | Camera* | OriginalTarget | **HIGH** | FUN_0040db00: returns `*(undefined4 *)(param_1 + 0x8c)`. Confirmed as camera pointer. | **OVERLAP CONFLICT** with PositionRot float[3]. |
| +0x90 | Camera* | LastTarget | **HIGH** | FUN_0040db00: returns `*(undefined4 *)(param_1 + 0x90)`. Confirmed. | **OVERLAP CONFLICT** with PositionRot. |
| +0x94–0xa8 | float[4]? | LookAtQuat | **HIGH** | FUN_00408870: writes quaternion values to +0x94–0xa8 for camera aim direction. Confirmed. | None |
| +0xa0 | float | ExtraOffsetX | **LOW** | Listed as separate field but actually within LookAtQuat range (+0x94–0xa8). This is the 4th quaternion component. | **WRONG** — likely same as quat[3] |
| +0xa4 | float | ExtraOffsetY | **LOW** | Within LookAtQuat range. May be incorrect field boundary. | See above |
| +0xa8 | float | ExtraOffsetZ | **LOW** | Within LookAtQuat range. May be incorrect field boundary. | See above |

**CRITICAL OVERLAP:** +0x8c is documented as BOTH PositionRot[1] (float) AND OriginalTarget (Camera*). Since these are different types and sizes, one is wrong. FUN_00408870 initializes +0x8c to 360.0f (float), while FUN_0040db00 reads +0x8c as a Camera*. These are likely **different structs** or the field repurposes after initialization.

**FIX:** Split into two structs: CameraDefinition (200B, initialized by FUN_00408870) and CameraManager (contains pointer array + interface ptrs). Move FUN_0040c890 offsets to the manager struct. Remove +0x14 from FUN_004fc2f0 attribution (that function handles cloud nodes, not cameras).

---

## Section 130: AudioResourceStruct (inferred)

Based on FUN_00552760.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | uint32 | SubResourcePtr | **HIGH** | `param_1 + 0x0c` freed and zeroed under +0x24 bit 0x20000 gate. Confirmed. | None |
| +0x24 | uint32 | FlagBitmask | **HIGH** | `param_1 + 0x24` checked for bit 0x20000. Confirmed. | None |
| +0x64 | uint32 | ResourceHandle | **HIGH** | `param_1 + 0x64` released via FUN_0053cb90. Confirmed. | None |
| +0x868 | uint32 | SecondaryResource | **HIGH** | `param_1 + 0x868` conditionally freed. Confirmed. | None |

**Verdict:** All 4 offsets confirmed. Confidence: HIGH.

---

## Section 131: Summary of New Offset Regions

The new offset regions listed in Section 131 are drawn from 02-ai-system.md and are NOT verified against .c files in this audit. They should be verified by a separate audit pass focused on the AI system struct regions.

**Recommendation:** Process these offset regions as a separate audit task (Sections 131.1–131.9), using the AI system functions (FUN_0042xxxx range) as sources, not the current set of files.

---

## NEW OFFSETS DISCOVERED

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| SceneNode | +0xec | uint | FUN_00545d00 | Flag bits, OR with 0x800 |
| SceneNode | +0x1b0 | int | FUN_00545d00 | Zeroed on flag condition |
| SceneNode | +0x1b4–0x1d0 | ptr+count pairs | FUN_00545d00 | 4 groups of sub-node lists, stride 8 per group |
| VehicleSceneNodeMap | ~30+ offsets | int[] | FUN_004dfce0 | Indices 0x18–0x24 (copy), 0x22d–0x256, 599-600, 0xaf4–0xaf5 |
| Linked List Container | +0xd8 | ptr | FUN_00486540 | Container head pointer (not node struct) |
| Linked List Node | +0x18 | ptr | FUN_00486540 | Next pointer (not +0x04 as docs claim) |
| EnergyAccumulation | +0xe00–0xe03 | hole | FUN_004390a0 | 4-byte gap between each params block's double pair and int |
| FUN_00454250 constraint | +0xd88 | float[] | FUN_00454250 | ConstraintSetPrimary (confirmed) |
| FUN_00454250 constraint | +0x1184 | float[] | FUN_00454250 | ConstraintSetSecondary (confirmed) |

## SUMMARY

**Sections with major issues (need rewrite):**
- Section 118 (SceneNode): Wrong FUN_00545d00 attribution for multiple offsets
- Section 121 (BVH): Duplicate +0x04 row, Pad1 should be double
- Section 126 (Linked List Node): Completely wrong offsets
- Section 128 (ConstraintForceState): 3 of 5 offsets not found
- Section 129 (Camera): Struct mixing, overlap conflicts, wrong FUN_004fc2f0 attribution

**Sections with minor issues:**
- Section 122 (EnergyAccumulation): Types should be {double, double, int} not double[3]
- Section 124 (Vehicle Setup): +0x1994 should be double not float
- Section 127 (CollisionResponseState): Note double-indirection pattern

**Sections fully correct:**
- Section 119 (AudioRingBuffer): Minor naming, offsets correct
- Section 120 (RaceModeBackup): All 5 offsets confirmed
- Section 123 (VehicleSceneNodeMap): All 21 offsets confirmed
- Section 125 (File Close Wrapper): 1 offset confirmed
- Section 130 (AudioResourceStruct): All 4 offsets confirmed
