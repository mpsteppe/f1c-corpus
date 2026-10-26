=== AUDIT RESULTS ===

## Section 90: VibrationEffectController (21 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | int | activeFlag | LOW | NOT in FUN_00545d00.c | FUN_00545d00 is NOT a vibration controller |
| +0x14 | int | state | LOW | NOT in FUN_00545d00.c | FUN_00545d00 uses scene node offsets |
| +0x16 | int | active | LOW | NOT in FUN_00545d00.c | — |
| +0x19 | byte | mode | LOW | NOT in FUN_00545d00.c | — |
| +0x1d | byte | subState | LOW | NOT in FUN_00545d00.c | — |
| +0x20 | int | ModeA | HIGH | FUN_005169ac: `*(int *)(param_2 + 0x20)` checked for 3 | none |
| +0x24 | int | ModeB | HIGH | FUN_005169ac: `*(int *)(param_2 + 0x24)` checked for 3 | none |
| +0x28 | int | ModeC | HIGH | FUN_005169ac: `*(int *)(param_2 + 0x28)` checked for 2 | none |
| +0x32 | byte | altMode | LOW | NOT in FUN_00545d00.c | — |
| +0x41 | byte | processingFlag | LOW | NOT in FUN_00545d00.c | — |
| +0x46 | byte | durationMultiplier | LOW | NOT in FUN_00545d00.c | — |
| +0x48 | byte | FlagA | HIGH | FUN_005169ac: `*(char *)(param_2 + 0x48)` checked for 0 | none |
| +0x4a | byte | globalEnable | LOW | NOT in FUN_00545d00.c | — |
| +0x59 | byte | flagRight | LOW | NOT in FUN_00545d00.c | — |
| +0x5a | byte | flagLeft | LOW | NOT in FUN_00545d00.c | — |
| +0x64 | int | ModeD | HIGH | FUN_005169ac: `*(int *)(param_2 + 100)` checked for 3 | none |
| +0x69 | byte | intensity | LOW | NOT in FUN_00545d00.c | — |
| +0xc4 | ptr | SubStructPtr | HIGH | FUN_005169ac: `*(int *)(param_2 + 0xc4)` dereferenced as ptr | none |
| +0xc9 | byte | extendedFlag | LOW | NOT in FUN_00545d00.c | — |
| +0x108 | byte | FlagB | HIGH | FUN_005169ac: `*(char *)(param_2 + 0x108)` checked for 0 | none |
| +0x114 | int | MatchID | HIGH | FUN_005169ac: `*(int *)(param_2 + 0x114)` cross-checked | none |

**MAJOR CONFLICT:** FUN_00545d00 is a **scene node / drawable list traversal** function, NOT a vibration controller. It accesses offsets (+0xec, +0x100, +0x108, +0x110, +0x24, +0x9c, +0xc0, +0x1b0–+0x1d0) that match the SceneNode/DrawableList struct, not VibrationEffectController. NONE of the 13 claimed VibrationEffectController offsets from FUN_00545d00 appear in the actual .c file.

**Recommendation:** Remove FUN_00545d00 from the "Observed in" column. The VibrationEffectController struct should be based on FUN_005169ac only. The remaining 8 offsets from FUN_005169ac (0x20, 0x24, 0x28, 0x48, 0x64, 0x108, 0xc4, 0x114) are HIGH confidence.

---

## Section 91: UIListComboBox (4 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x20 | int | ItemCount | HIGH | FUN_0051a4f2: `(int *)(param_1 + 0x20)` read as loop bound; FUN_0051bc88: `*(int *)(param_1 + 0x20)` as upper bound | none |
| +0xc4 | ptr[] | ItemArray | HIGH | FUN_0051a4f2: `(int *)(param_1 + 0xc4)` dereferenced as int**; FUN_0051bc88: `*(int *)(param_1 + 0xc4) + 0x50` as ptr | none |
| +0x184 | ptr | ListDataPtr | HIGH | FUN_0051a4f2: `(param_1 + 0x184)` stores allocation result | none |
| +0x198 | ptr | ListDataPtr | HIGH | FUN_0051bc88: `(param_1 + 0x198)` stores allocation result | none |

All 4 offsets confirmed. Types match. No conflicts.

---

## Section 92: UIObjectList (7 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x44 (0x11) | ptr | ItemListHead | HIGH | FUN_0047e960: `param_1[0x11]` (int-index) → byte 0x44, set to 0 | none |
| +0x48 (0x12) | ptr | ItemListTail | HIGH | FUN_0047e960: `param_1[0x12]` → byte 0x48, set to 0 | none |
| +0x4c (0x13) | ptr | CurrentItem | HIGH | FUN_0047e960: `param_1[0x13]` → byte 0x4c, set to 0 | none |
| +0x50 (0x14) | int | ItemCount | HIGH | FUN_0047e960: `param_1[0x14]` → byte 0x50, set to 0 | none |
| +0xec (0x3b) | int | InitField | HIGH | FUN_0047e960: `param_1[0x3b]` → byte 0xec, set to 0 | none |
| +0xf0 (0x3c) | int | EndMarker | HIGH | FUN_0047e960: `param_1[0x3c]` → byte 0xf0, set to -1 | none |
| +0xf4 (0x3d) | int | OptionID | HIGH | FUN_0047e960: `param_1[0x3d]` → byte 0xf4, set to param_2 | none |

All 7 offsets confirmed. Note: access is via int-indexed `param_1[idx]` where byte offset = idx × 4. The doc lists byte offsets correctly. Confidence: high. No conflicts.

---

## Section 93: ConstraintEntryStruct (stride 0x48) (4 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | int | BodyA_ID | HIGH | FUN_0043ba20: `*(int *)(iVar3 + 4)` compared to target A | none |
| +0x08 | int* | ForcePtrA | MEDIUM | FUN_0043ba20: `*(double **)(iVar3 + 8)` — actual type is **double*** | **TYPE:** doc says int*, source shows double* |
| +0x0c | int | BodyB_ID | HIGH | FUN_0043ba20: `*(int *)(iVar3 + 0xc)` compared to target B | none |
| +0x10 | int* | ForcePtrB | MEDIUM | FUN_0043ba20: `*(double **)(iVar3 + 0x10)` — actual type is **double*** | **TYPE:** doc says int*, source shows double* |

Stride 0x48 confirmed: `iVar3 = iVar3 + 0x48` at line 46.

**Note:** The +0x08 and +0x10 fields are swapped between `ForcePtrA` and `ForcePtrB` depending on the branch (lines 19-43). Both are used as `double*` pointers, not `int*`. On x86 the pointer size is the same, but the dereference type is double. Minor type mismatch — suggest changing to `double*` or `ptr`.

---

## Section 94: ForceIntegratorStruct (FUN_00438130 + FUN_00438100 overlap) (5 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x364 | double | FactorA | HIGH | FUN_00438100: `*(double *)(param_1 + 0x364)` read; FUN_00438130: write | none |
| +0x36c | double | FactorB | HIGH | FUN_00438100: `*(double *)(param_1 + 0x36c)` read; FUN_00438130: modified | none |
| +0x374 | double | Product | HIGH | FUN_00438100: `*(double *)(param_1 + 0x374)` = FactorA×FactorB; FUN_00438130: read | none |
| +0x38c | double | Multiplier | HIGH | FUN_00438100: `*(double *)(param_1 + 0x38c)` read; FUN_00438130: not directly referenced | none |
| +0x384 | double | BiasTerm | HIGH | FUN_00438100: `*(double *)(param_1 + 900)` read = +0x384; FUN_00438130: read+write | none |

All 5 offsets confirmed as double. FUN_00438100 logic verified: `Product = FactorB * FactorA; output = Product * Multiplier + BiasTerm`. No conflicts. (Table ordering is non-sequential but functionally correct.)

---

## Section 95: WheelSuspensionForceStruct (stride 0x13c) (13 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x70 | float | LateralForce | HIGH | FUN_00401340: `*(undefined4 *)(iVar9 + 0x70) = 0` then assigned computed lateral force | none |
| +0x74 | float | LongitudinalForce | HIGH | FUN_00401340: `*(undefined4 *)(iVar9 + 0x74) = 0` then assigned computed long force | none |
| +0x78 | float | SpringForce0 | HIGH | FUN_00401340: `*(float *)(iVar9 + 0x78) = local_2c` (0.0f); later overwritten | none |
| +0x7c | float | SpringForce1 | HIGH | FUN_00401340: `*(float *)(iVar9 + 0x7c) = local_28` (-9.4f); later overwritten | none |
| +0x80 | float | SpringForce2 | HIGH | FUN_00401340: `*(undefined4 *)(iVar9 + 0x80) = local_24` (0); later overwritten | none |
| +0x94 | float | BodyAttachX | HIGH | FUN_00401340: `*(float *)(iVar9 + 0x94)` read as body attachment point X | none |
| +0x98 | float | BodyAttachY | HIGH | FUN_00401340: `*(float *)(iVar9 + 0x98)` read as body attachment point Y | none |
| +0x9c | float | BodyAttachZ | HIGH | FUN_00401340: `*(float *)(iVar9 + 0x9c)` read as body attachment point Z | none |
| +0x10c | ptr | SuspGeomPtr | HIGH | FUN_00401340: `*(int *)(iVar9 + 0x10c)` dereferenced as geometry pointer | none |
| +0x110 | ptr | ContactPtr | HIGH | FUN_00401340: `*(int *)(iVar9 + 0x110)` used as contact surface pointer | none |
| +0x130 | int | NumWheels | HIGH | FUN_00401340: `*(int *)(param_1 + 0x130)` — on parent struct, loop bound | none |
| +0x134 | ptr | WheelArrayPtr | HIGH | FUN_00401340: `*(int *)(param_1 + 0x134)` base pointer for wheel array | none |
| +0x13c | — | StructStride | HIGH | FUN_00401340: `local_88 += 0x13c` confirmed stride | none |

All offsets confirmed. Stride 0x13c confirmed (lines 80-81, 189). Per-wheel entry base is iVar9, parent struct access at param_1. No type conflicts. Recommend upgrading confidence to HIGH.

---

## Section 96: AutoLoadEntry List Head Struct (5 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1c | void* | head | HIGH | FUN_00432e70: `*(int **)(param_1 + 0x1c)` read, write, linked list head | none |
| +0x20 | void* | tail | HIGH | FUN_00432e70: `*(undefined4 *)(param_1 + 0x20) = 0` nulled; stores new nodes | none |
| +0x24 | void* | iterator | HIGH | FUN_00432e70: `*(undefined4 *)(param_1 + 0x24) = 0` nulled; used as current during traversal | none |
| +0x28 | int | count | HIGH | FUN_00432e70: `*(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 1` incremented | none |
| +0x18 | int (byte) | loaded flag | MEDIUM | FUN_00432e70: `*(undefined1 *)(param_1 + 0x18) = 1` — **byte write, not int** | **TYPE:** doc says int, actual is byte |

All 5 offsets confirmed. Minor type mismatch at +0x18: doc says int, actual is byte (`undefined1`). The value is 0/1 so it works functionally, but suggest changing to `byte` for accuracy.

---

## Section 97: Season Database Struct (FUN_0047f440) (2 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x191c | void** | entryArray[508] | HIGH | FUN_0047f440: `*(undefined4 **)(param_1 + 0x191c + iVar1 * 4)` with iVar1 up to 0x1fb (508 entries) | none |
| +0x1fe8 | void* | specialPtr | HIGH | FUN_0047f440: `*(undefined4 **)(param_1 + 0x1fe8)` for index 0x1b4 case | none |

Both confirmed. Note: +0x1fe8 overlaps with entryArray[0x1b3] (since 0x191c + 0x1b3×4 = 0x1fe8). The code handles param_2=0x1b4 as a special case before the array access, so the overlap is intentional (specialPtr occupies the same slot as entryArray[0x1b3]).

---

## Section 98: UI Control Struct (common) (29 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | vtable | HIGH | Multiple: `*param_1 = &PTR_...` | none |
| +0x08 | ushort | renderMode | MEDIUM | FUN_0040eb30: `*(undefined2 *)(param_1 + 8)` | only 1 function |
| +0x0c | int | width | MEDIUM | FUN_0048fdb0: `*(int *)(param_1 + 0xc) = width` | only 1 function |
| +0x10 | int | height | MEDIUM | FUN_0048fdb0: `*(int *)(param_1 + 0x10) = height+1` | only 1 function |
| +0x18 | ptr | nextNode | MEDIUM | FUN_00486540: linked list next at `*(int *)(param_1 + 0xd8)` = **+0xd8 not +0x18** | **OFFSET CONFLICT** |
| +0x1c | int | typeID | MEDIUM | FUN_0040eb30: `*(undefined4 *)(param_1 + 0x1c) = 3` | only 1 function |
| +0x20 | ptr/uint | reference/resource | MEDIUM | FUN_0040eb30: `*(undefined4 *)(param_1 + 0x20) = param_3` | only 1 function |
| +0x24-0x28 | ptr[3] | resourcePtrs | LOW | Claimed from FUN_004c9310 — needs verification | — |
| +0x38 | char | visibility | **VERIFY** | FUN_0048bbe0: `param_1[0x38]` (int index) = byte **0xe0**, not 0x38 | **INT-INDEX vs BYTE-OFFSET** |
| +0x3c | ptr | elementList | **VERIFY** | FUN_0048f640: `param_1[0x3c]` (int index) = byte **0xf0**, not 0x3c | **INT-INDEX vs BYTE-OFFSET** |
| +0x3e | ptr | currentElement | **VERIFY** | FUN_0048f640: `param_1[0x3e]` (int index) = byte **0xf8**, not 0x3e | **INT-INDEX vs BYTE-OFFSET** |
| +0x40 | int | layoutMode | **VERIFY** | FUN_0048f640: `param_1[0x40]` (int index) = byte **0x100**, not 0x40 | **INT-INDEX vs BYTE-OFFSET** |
| +0x45 | byte | activeFlag | **VERIFY** | FUN_00488180: `*(undefined1 *)(param_1 + 0x45)` with undefined4* param_1 | ambiguous scaling |
| +0x48 | int | headerWidth | **VERIFY** | FUN_0048f640: `param_1[0x48]` (int index) = byte **0x120**, not 0x48 | **INT-INDEX vs BYTE-OFFSET** |
| +0x49 | int | contentWidth | **VERIFY** | FUN_0048f640: `param_1[0x49]` (int index) = byte **0x124**, not 0x49 | **INT-INDEX vs BYTE-OFFSET** |
| +0x50 | int | headerHeight | **VERIFY** | FUN_0048f640: `param_1[0x50]` (int index) = byte **0x140**, not 0x50 | **INT-INDEX vs BYTE-OFFSET** |
| +0x51 | int | contentHeight | **VERIFY** | FUN_0048f640: `param_1[0x51]` (int index) = byte **0x144**, not 0x51 | **INT-INDEX vs BYTE-OFFSET** |
| +0x54 | int | maxElementWidth | **VERIFY** | FUN_0048f640: `param_1[0x54]` (int index) = byte **0x150**, not 0x54 | **INT-INDEX vs BYTE-OFFSET** |
| +0x55 | int | maxElementHeight | **VERIFY** | FUN_0048f640: `param_1[0x55]` (int index) = byte **0x154**, not 0x55 | **INT-INDEX vs BYTE-OFFSET** |
| +0x56 | int | columnCount | **VERIFY** | FUN_0048f640: `param_1[0x56]` (int index) = byte **0x158**, not 0x56 | **INT-INDEX vs BYTE-OFFSET** |
| +0x57 | int | rowCount | **VERIFY** | FUN_0048f640: `param_1[0x57]` (int index) = byte **0x15c**, not 0x57 | **INT-INDEX vs BYTE-OFFSET** |
| +0x58 | int | viewWidth | **VERIFY** | FUN_0048f640: `param_1[0x58]` (int index) = byte **0x160**, not 0x58 | **INT-INDEX vs BYTE-OFFSET** |
| +0x59 | int | viewHeight | **VERIFY** | FUN_0048f640: `param_1[0x59]` (int index) = byte **0x164**, not 0x59 | **INT-INDEX vs BYTE-OFFSET** |
| +0x5b | int | scrollRange | **VERIFY** | FUN_0048f640: `param_1[0x5b]` (int index) = byte **0x16c**, not 0x5b | **INT-INDEX vs BYTE-OFFSET** |
| +0xe1 | char | secondaryFlag | MEDIUM | FUN_0048bbe0: `*(char *)((int)param_1 + 0xe1)` explicit byte offset | only 1 function |
| +0xe8 | int | guardFlag | HIGH | FUN_0048e860: `param_1[0x3a]` (int index) = byte 0xe8 ✅ | none |
| +0x118 | ptr | ptrSlot1 | HIGH | FUN_004a70e0: `param_1[0x46]` (int index) = byte 0x118 ✅ | none |
| +0x130 | ptr | ptrSlot2 | HIGH | FUN_004a70e0: `param_1[0x4c]` (int index) = byte 0x130 ✅ | none |
| +0x14c | int | navigationPos | HIGH | FUN_00489530: `param_1[0x53]` (int index) = byte 0x14c ✅ | none |

**MAJOR STRUCTURAL ISSUE:** This section mixes INT-INDEX access (where byte offset = index × 4) with direct byte-offset access without consistent conversion.

**Evidence of int-index access (with scaling factor 4):**
- FUN_0040eb30 uses direct byte offsets (param_1 is `int` type): +0x08, +0x1c, +0x20
- FUN_00486540 uses byte offsets: +0xd8 (param_1 is `int` type, NOT +0x18 as doc claims)
- FUN_0048bbe0 uses `param_1[0x38]` (int*) = byte 0xe0, AND `(int)param_1 + 0xe1` = byte 0xe1 → proves scaling
- FUN_0048e860 uses `param_1[0x3a]` (int*) = byte 0xe8 → **doc shows +0xe8 (correct)**
- FUN_0048f640 uses `param_1[idx]` (int*) where doc includes many entries at wrong byte offset
- FUN_00489530 uses `param_1[0x53]` (int*) = byte 0x14c → **doc shows +0x14c (correct)**
- FUN_004a70e0 uses `param_1[0x46]` = byte 0x118, `param_1[0x4c]` = byte 0x130 → **doc shows +0x118, +0x130 (correct)**

**Inconsistency pattern:** Many offsets from FUN_0048f640 were recorded as int indices (0x3c, 0x3e, 0x40, 0x48, 0x49, 0x50, 0x51, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5b) instead of byte offsets (0xf0, 0xf8, 0x100, 0x120, 0x124, 0x140, 0x144, 0x150, 0x154, 0x158, 0x15c, 0x160, 0x164, 0x16c). Offsets from FUN_0040eb30, FUN_0048e860, FUN_00489530, FUN_004a70e0 were correctly converted.

**Conflict at +0x18:** Doc says FUN_00486540 has +0x18 as nextNode, but source at 0x00486540.c uses byte offsets +0xd8 for list operations. This suggests the +0x18 entry is from a different function reference or was incorrectly extracted.

**Recommendation:** Re-extract all offsets from int-indexed functions by multiplying the index by sizeof(int) (=4). Indices and byte offsets should be normalized to byte offsets throughout.

---

## Section 99: WheelContactState (4 offsets)

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| +0x828 | int[4] | WheelActiveFlags | HIGH | FUN_004e96c0: `*(int *)(param_1 + 0x828)` checked per wheel, stride 0x4a×4 | none |
| +0x34D4 | float[3] | VehiclePos | HIGH | FUN_004e96c0: `*(float *)(param_1 + 0x34d4)` read as X | none |
| +0x3AAC | float[3] | TargetPos | HIGH | FUN_004e96c0: `*(float *)(param_1 + 0x3aac)` read as target X | none |
| +0x3B6C | float | SuspensionTravel | HIGH | FUN_004e96c0: `*(float *)(param_1 + 0x3b6c)` read as travel bound | none |

All 4 offsets confirmed. Types match. No conflicts. Note: +0x34D4, +0x34D8, +0x34DC are read individually (x,y,z). The stride for wheel active flags at +0x828 is `piVar11 + 0x4a` (0x4a ints = 0x128 bytes per wheel). Confidence: HIGH.

---

## Section 100: AnimationFrameTimer (2 offsets)

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| [0x5D] | float | FrameTimer | HIGH | FUN_00469dd0: `param_1[0x5d]` int-indexed, accumulated frame time as int-cast float | none |
| [0x5E] | int | FrameIndex | HIGH | FUN_00469dd0: `param_1[0x5e]` int-indexed, incremented by 2, wraps at DAT_007d2dcc | none |

Both confirmed. Note: `param_1[0x5d]` stores a float value as int (via `(int)(float)(fVar3 + fVar1)` at line 16). The doc correctly lists these as int indices (not byte offsets). The byte offsets would be 0x174 (0x5D×4) and 0x178 (0x5E×4). No type conflicts.

---

## Section 101: SpecialFX Struct (inferred) (10 offsets)

| Offset | Current Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|------------|------------|-------------|-----------|
| +0x00 | int | LPTreeCount | **INT INDEX** | FUN_004cf070: `param_1[0]` increments for each "LPTREE" scene node | **INT-INDEX ISSUE** |
| +0x01 | ptr? | LPTreeArray | **INT INDEX** | FUN_004cf070: `param_1[1]` stores allocated array (stride 0x3c) | **INT-INDEX ISSUE** |
| +0x02 | int | FeedbackCount | **INT INDEX** | FUN_004cf070: `param_1[2]` = param_1[2] + 1 counts feedback entries | **INT-INDEX ISSUE** |
| +0x03 | ptr? | FeedbackArray | **INT INDEX** | FUN_004cf070: `param_1[3]` stores FEEDBACK grouped entries, stride 0x6c | **INT-INDEX ISSUE** |
| +0x04 | int | LooseMatCount | **INT INDEX** | FUN_004cf070: `param_1[4]` incremented per loose material found | **INT-INDEX ISSUE** |
| +0x05 | ptr? | LooseMatArray | **INT INDEX** | FUN_004cf070: `param_1[5]` stores array, stride 0x6c per entry | **INT-INDEX ISSUE** |
| +0x06–0x0a | ptr[5] | SpecialMaterials | **INT INDEX** | FUN_004cf070: `param_1[6-10]` store pointers for types 0xc, 0xd, 1, 3, 4 | **INT-INDEX ISSUE** |
| +0x0b | unknown | SceneExtents | **INT INDEX** | FUN_004cf070: `param_1[0xb]` stores scene extents pointer → **int index, not byte** | **INT-INDEX ISSUE** |
| +0x0c | float | AIDryGrip | **INT INDEX** | FUN_004cf070: `param_1[0xc]` stores AIDryGrip from config line | **INT-INDEX ISSUE** |
| +0x0d | float | AIWetGrip | **INT INDEX** | FUN_004cf070: `param_1[0xd]` stores AIWetGrip from config line | **INT-INDEX ISSUE** |

**MAJOR INT-INDEX ISSUE:** All offsets in this section are INT INDICES (0, 1, 2, ...) from `param_1[N]` access, NOT byte offsets. The doc even warns about this itself: "Offsets +0x00 through +0x0d are suspiciously small (not DWORD-aligned)."

**Correct byte offsets would be:**
| +0x00 | int | LPTreeCount | HIGH | confirmed |
| +0x04 | ptr | LPTreeArray | HIGH | stride 0x3c |
| +0x08 | int | FeedbackCount | HIGH | confirmed |
| +0x0c | ptr | FeedbackArray | HIGH | stride 0x6c |
| +0x10 | int | LooseMatCount | HIGH | confirmed |
| +0x14 | ptr | LooseMatArray | HIGH | stride 0x6c |
| +0x18 | ptr | SpecialMatC (0xc) | HIGH | param_1[6] |
| +0x1c | ptr | SpecialMatD (0xd) | HIGH | param_1[7] |
| +0x20 | ptr | SpecialMat1 | HIGH | param_1[8] |
| +0x24 | ptr | SpecialMat3 | HIGH | param_1[9] |
| +0x28 | ptr | SpecialMat4 | HIGH | param_1[10] |
| +0x2c | ptr | SceneExtents | MEDIUM | param_1[0xb] — computed, then never read |
| +0x30 | int | AIDryGrip | MEDIUM | param_1[0xc] — stored as int (float cast) from config |
| +0x34 | int | AIWetGrip | MEDIUM | param_1[0xd] — stored as int (float cast) from config |

**Recommendation:** Rewrite the offset column as byte offsets (×4). Note that AIDryGrip and AIWetGrip are stored as `int` (cast from float), not as native float type.

---

## Section 102: DynamicStackStruct (inferred) (3 offsets)

| Offset | Current Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|------------|------------|-------------|-----------|
| +0x00 | int32 | Top | HIGH | FUN_005648d0: `*param_1` read/written as stack pointer | none |
| +0x04 | int32 | Capacity | HIGH | FUN_005648d0: `param_1[1]` compared with Top for overflow check | none |
| +0x08 | int32 | ElementSize | HIGH | FUN_005648d0: `param_1[2]` used for byte offset calculation on overflow | none |

All 3 offsets confirmed. Types match. Logic verified: `if (Top == Capacity) grow; push(param_2)`. No conflicts. Confidence: HIGH.

---

## Section 103: Config Entry Node (FUN_00433b60) (1 offset)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00–+0x1b | byte[0x1c] | ConfigNode | HIGH | FUN_00433b60: `operator_new(0x1c)` allocates 0x1c bytes; structure initialized with fields (0, -1, 0, -1, ?, 0, -1) at indices [0]-[6] | none |

Total size 0x1c confirmed by allocation. The struct has 7 int-indexed fields (`puVar6[0]` through `puVar6[6]`). The doc lists only the raw allocation range without individual fields. **Note:** The additional code at lines 27-28 and 99-107 shows param_1 uses +0x1c, +0x20, +0x24, +0x28 as list management pointers (same pattern as AutoLoadEntry List Head struct), suggesting this function accesses TWO DIFFERENT STRUCTS: the Config Entry Node (allocated 0x1c) and a separate list head struct at param_1+0x1c.

---

=== NEW OFFSETS DISCOVERED ===

None discovered — all offsets in the 14 sections were previously documented. However, several corrections to existing offsets are needed.

=== SUMMARY OF ISSUES ===

**High-severity (structural):**

1. **Section 90 — VibrationEffectController:** FUN_00545d00 is misidentified. The function is a scene node traversal, not a vibration controller. Remove from "Observed in" column. Keep only FUN_005169ac entries.

2. **Section 98 — UI Control Struct:** Widespread int-index vs byte-offset confusion. ~15 of 29 offsets appear to be int indices mistakenly recorded as byte offsets. The pattern is inconsistent — some indices were correctly multiplied by 4 (e.g., +0xe8, +0x118, +0x130, +0x14c) but others were not (e.g., +0x38 should be +0xe0, +0x3c should be +0xf0). Suggest complete re-extraction.

3. **Section 101 — SpecialFX Struct:** ALL 10 offsets are int indices, not byte offsets. All should be multiplied by 4. The doc itself flags this as suspicious.

**Medium-severity (type mismatches):**

4. **Section 93 — ConstraintEntryStruct:** +0x08 and +0x10 typed as `int*` but source reads as `double*`. Same 4-byte pointer size on x86 but dereference type differs.

5. **Section 96 — AutoLoadEntry List Head Struct:** +0x18 typed as `int` but source writes as `byte` (`undefined1`).

**Low-severity:**

6. **Section 95 — WheelSuspensionForceStruct:** Confidence can be upgraded from LOW to HIGH — all 13 offsets confirmed from single function FUN_00401340 with stride 0x13c verified.

7. **Section 98 — UI Control Struct:** FUN_00486540 is claimed for +0x18 nextNode but the source shows +0xd8 byte offset — either the wrong function or wrong offset.

8. **Section 101 — SpecialFX Struct:** AIDryGrip and AIWetGrip stored as `int` (cast from float), not native `float` type. Minor.
