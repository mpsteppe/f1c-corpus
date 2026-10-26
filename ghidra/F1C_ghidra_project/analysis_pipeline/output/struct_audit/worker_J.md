=== AUDIT RESULTS ===

## Section 132: AudioStreamBuffer (param_1 — audio stream)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x030 | byte | ReadyFlag | HIGH | FUN_00519720 (+0x30 char* + 0x30 undefined1* write), FUN_005196b8 (+0x30 char*) | none |
| +0x034 | uint | Position | HIGH | FUN_00519720 (+0x34 uint* read/write, puVar1), FUN_005196b8 (+0x34 uint*) | none |
| +0x038 | ptr | SourcePointer | HIGH | FUN_00519720 (base of pointer array at +0x38, indexed by BufferIndex*4) | none |
| +0x040 | uint | BufferIndex | HIGH | FUN_00519720 (+0x40 int* read, xor 1 toggle), FUN_00519986 (NOT accessed as audio buffer field) | none |
| +0x044 | int | FillState | HIGH | FUN_00519720 (+0x44 int* read/write, compared to 0/1/2) | none |
| +0x048 | uint | BufferSize | HIGH | FUN_00519720 (+0x48 uint* read, compared to Position) | none |
| +0x04c | int | BufferCounter | HIGH | FUN_00519720 (+0x4c int* read/write, increment) | none |
| +0x114 | int | BufferSizeBase | HIGH | FUN_00519720 (+0x114 int* read, param_1), FUN_005196b8 (+0x114 uint* read, param_1) | none |
| +0x118 | int | TotalBuffers | HIGH | FUN_00519720 (+0x118 int* read, param_1), FUN_00519986 (+0x118 uint* read, param_1) | none |
| +0x180 | ptr | StreamPtr | HIGH | FUN_00519720 (+0x180 int* read = iVar2 base), FUN_005196b8 (+0x180 int* read) | none |
| +0x184 | ptr | VtableDecoder | HIGH | FUN_00519720 (+0x184, method +0xc called), FUN_005196b8 (+0x184), FUN_00519986 (+0x184 = iVar1), FUN_00515db8 (+0x184 method call) | none |
| +0x188 | ptr | VtableFiller / BufferObj | HIGH | FUN_00519720 (+0x188, method +4 called), FUN_005196b8 (+0x188), FUN_0051bd61 (+0x188), FUN_0051bcfc (+0x188), FUN_0051bdf1 (+0x188) | none |
| +0x19c | ptr | PlayCallback / WriteVtable | HIGH | FUN_0051bd61 (+0x19c, method +4 called), FUN_0051bcfc (+0x19c, method +4) | none |
| +0x1a4 | ptr | FlushCallback / FlushVtable | HIGH | FUN_0051bd61 (+0x1a4, method +4 called), FUN_0051bcfc (+0x1a4, method +4), FUN_0051bdf1 (+0x1a4, method +4) | none |

**ISSUES:**

1. **MIXED STRUCT LEVELS**: Offsets +0x030 through +0x04c are NOT on param_1 directly. They are accessed through iVar2 = *(int *)(param_1 + 0x180) — a sub-object pointed to by StreamPtr. The struct table presents all offsets as if belonging to the same struct level, which is misleading.

2. **BufferObj sub-fields undocumented at +0x188 target**: The VtableFiller/BufferObj (loaded from param_1+0x188) has sub-fields at +0x8, +0xc, +0x10, +0x14, +0x18 that are used across FUN_0051bd61, FUN_0051bcfc, and FUN_0051bdf1. These should be documented as a separate sub-struct or clarified.

3. **Undocumented param_1 fields**: FUN_00519986 reads param_1+0x80 (uint), +0x120 (int), +0x124 (ptr). FUN_0051bdf1 reads param_1+0x4 (vtable ptr with method at +0x1c), +0x60 (int). None are in the struct table.

4. All TYPES are correct for documented offsets.

---

## Section 133: GeometryProximityTest (per-element wheel collision)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x828 | int[4] | ElementFlags | MEDIUM | FUN_004ed420 (piVar6 = int* @ +0x828, stride 0x4a*4=0x128, 4 elements) | none |
| +0x3594 | float[4] | ElementArray | MEDIUM | FUN_004ed420 (pfVar3 = float* @ +0x3594, stride 0x3e*4=0xf8, 4 elements) | none |

**Additional offsets found in FUN_004ed420 (not in struct table):**
- +0x34b0..+0x34d0: 3x3 rotation matrix (9 floats at +0x34b0, +0x34b4, +0x34b8, +0x34bc, +0x34c0, +0x34c4, +0x34c8, +0x34cc, +0x34d0) — row stride 12 bytes (3 floats). These appear in only 1 function, not added as new offsets.

**ISSUES:**
- Low confidence (single function observation only).
- All types match the code.

---

## Section 134: DynamicBuffer (inferred — FUN_00564930)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | int | AccumSize | HIGH | FUN_00564930 (+0x04 int* read/write, accumulated with Addend) | none |
| +0x08 | int | ElemSize | HIGH | FUN_00564930 (+0x08 int* read, multiplied with AccumSize for realloc) | none |
| +0x0c | int | Addend | HIGH | FUN_00564930 (+0x0c int* read, added to AccumSize) | none |
| +0x14 | ptr | Buffer | HIGH | FUN_00564930 (+0x14 ptr* read, passed to FUN_0058b5d4 realloc) | none |

All confirmed. No issues. Confidence: HIGH (single function but all types match).

---

## Section 135: ContactPairStruct (stride 0x20)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | ContactType | LOW | FUN_00449700: used as ptr* (piVar1 = (int*)(array+iVar7)), CONTACT: field is PTR not INT |
| +0x04 | int | BodyA | LOW | FUN_00449700: used as ptr* (piVar3 = (int*)(array+4+iVar7)), CONTACT: field is PTR not INT |
| +0x08 | int | BodyB | HIGH | FUN_00449700: used as ptr* (piVar2 = (int*)(array+8+iVar7)), param_1[2] used as array base. CONTACT: field is PTR not INT |
| +0x0c | int | BodyC | HIGH | FUN_00449700: param_1[3] as int (null check `!= 0`) | none |
| +0x10 | int | BodyVelocity | HIGH | FUN_00449700: param_1[4] as int (null check `!= 0`) | none |
| +0x14 | int | BodyVelocityB | LOW | Not directly accessed in FUN_00449700 or FUN_004496d0 | none [unconfirmed] |
| +0x18 | int | Reserved | LOW | Not directly accessed in these functions | none [unconfirmed] |
| +0x1c | int | NextPtr | MEDIUM | FUN_004496d0 (+0x1c used as ptr* for linked list next, `*(int *)(iVar1 + 0x1c + param_1[2])`). CONTACT: field is PTR not INT |

**STRUCTURE CLARIFICATION:**
- param_1 is NOT the ContactPairStruct itself. It's a **ContactList header** with:
  - param_1[0] (+0x00): count (int)
  - param_1[2] (+0x08): array base ptr (int* / ptr)
  - param_1[3] (+0x0c): flag (int)
  - param_1[4] (+0x10): flag (int)
- Individual ContactPair entries at the array base have stride 0x20:
  - +0x00: ptr (not int)
  - +0x04: ptr (not int)
  - +0x08: ptr (not int)
  - +0x1c: ptr (next linked-list pointer)

**TYPE CONFLICTS:** +0x00, +0x04, +0x08, +0x1c are PTR not INT. The struct table lists them as int.

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| (not adding — single function observations) | | | | |

---

## Section 136: SuspensionCopyStruct (FUN_0043bc20 setup copy)

Key observations from FUN_0043bc20:

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1900 | double | FlagType | **CONFLICT** | Line 28: `*(undefined1 *)(param_1 + 0x1900)` — **byte**, NOT double | **TYPE MISMATCH**: table says double, code uses byte |
| +0x1910 | float | SetupValue1 | HIGH | Lines 30,76: `undefined4` write | none |
| +0x1914 | float | SetupValue2 | HIGH | Lines 31,77: `undefined4` write (from param_3+500=0x1f4) | none |
| +0x1938 | float | SetupValue3 | HIGH | Lines 32,78: `undefined4` write | none |
| +0x193c | float | SetupValue4 | HIGH | Lines 33,79: `undefined4` write | none |
| +0x1940 | float | SetupValue5 | HIGH | Lines 34,80: `undefined4` write | none |
| +0x1944 | float | SetupValue6 | HIGH | Lines 35,82: `undefined4` write | none |
| +0x1960 | float[36] | SpringDamperMatrix | HIGH | Lines 37-51: 6×6 loop copying dwords (36 dwords = 144 bytes) | none |
| +0x19f0 | float[6] | BiasVector | HIGH | Lines 53-58, 96-102: 6 dword copy loop | none |
| +0x17a8 | float[6*4] | HubPositions | **PARTIAL** | Lines 59-64: only **6 dwords** copied (not 6*4=24). Table overstates size. Actual: float[6] |
| +0x17c0 | float[6*4] | PatchPositions | **PARTIAL** | Lines 65-70: only **6 dwords** copied. Same issue: float[6], not float[24] |
| +0x1c08-0x1c14 | float[6*4] | MirroredPositions | **PARTIAL** | Lines 71-74: only **4 dwords** copied (2 from HubPositions + 2 from PatchPositions), mirror only first 2 elements |
| +0x1a08 | flag | DampingFlag | HIGH | Line 107: `*(undefined1 *)` byte copy | none |
| +0x1a14/0x1a18 | float | BumpRebound | HIGH | Lines 108-109: `undefined4` copy | none |
| +0x1a34 | float[36] | DampingMatrix | HIGH | Lines 110-124: 6×6 loop | none |
| +0x1ac4 | float[6] | DampingBias | HIGH | Lines 125-131: 6 dword loop | none |
| +0x17d8-0x1804 | float[12] | TravelLimits | HIGH | Lines 132-143: 12 dword copies | none |
| +0x1828-0x1834 | float[6] | WheelMassInertia | **PARTIAL** | Lines 152-155: only **4 dwords** copied (+0x1828, +0x182c, +0x1830, +0x1834). Table says 6 but only 4 confirmed |
| +0x1ae4-0x1af8 | float[6] | InertiaMatrix | HIGH | Lines 156-161: 6 dword loop | none |
| +0x1b14-0x1ba4 | float[36] | ComplianceMatrix | HIGH | Lines 162-176: 6×6 loop | none |
| +0x1808 | float | SpringPreloadToe | **CONFLICT** | Line 186: `*(double *)(param_1 + 0x1808)` — **double**, NOT float | **TYPE MISMATCH**: table says float, code uses double |
| +0x1810/0x1814 | float | CamberToe | HIGH | Lines 188-189: `undefined4` copy | none |
| +0x1818 | float | ScaledCaster | **CONFLICT** | Line 190: `*(double *)(param_1 + 0x1818)` — **double**, NOT float | **TYPE MISMATCH**: table says float, code uses double |
| +0x1820/0x1824 | float | CasterAngles | HIGH | Lines 191-192: `undefined4` copy | none |
| +0x1bbc-0x1be4 | float[8] | AntiRollBarParams | **CONFLICT** | Lines 199-210: mixture of byte(+0x1bbc), double(+0x1bc0), and 8 dwords(+0x1bc8..+0x1be4). **NOT float[8]** | **STRUCTURE MISMATCH**: layout is byte(1) + double(8) + dword[8](32) = 41 bytes, not 32 |

**TYPE CONFLICTS SUMMARY:**
1. +0x1900: byte in code, double in table ❌
2. +0x1808: double in code, float in table ❌
3. +0x1818: double in code, float in table ❌
4. +0x1bbc-0x1be4: not float[8]; actual layout: byte + double + 8×dword ❌
5. +0x17a8: float[6] (not float[6*4])
6. +0x17c0: float[6] (not float[6*4])
7. +0x1c08-0x1c14: float[4] (not float[6*4])
8. +0x1828-0x1834: float[4] confirmed (table says float[6])

---

## Section 137: CameraStruct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | unknown | (start) | NONE | Not accessed in FUN_0040b850 | Placeholder only |
| +0x04 | int | CameraCount | MEDIUM | FUN_0040b850: `extraout_ECX+4` set from FUN_00544f50 return | none |
| +0x0c | ptr | CameraArrayPtr | MEDIUM | FUN_0040b850: `extraout_ECX+0xc` set to piVar3 (array after count header) | none |
| +0x10 | int | CameraCount2 | MEDIUM | FUN_0040b850: `extraout_ECX+0x10` set to iVar5 | none |
| +0x14 | int | CurrentIndex | MEDIUM | FUN_0040b850: `extraout_ECX+0x14` set to 0 | none |
| +0xd0 | — | CameraStructSize | MEDIUM | Stride from `operator_new(iVar5 * 0xd0 + 4)` — array element stride 0xd0 | none |

**ISSUES:**
- Function FUN_0040b850 is `void` (no parameters) — uses `extraout_ECX` calling convention artifact. The struct is actually a class with `this` pointer. Struct table should clarify it's a class layout, not a function parameter.
- +0x08 (between +0x04 and +0x0c): not accessed, may be padding or separate field.

---

## Section 138: Per-Vehicle Filter State Struct (stride 0x1b4)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x194 | int | filter index start | MEDIUM | FUN_004c0db0 line 63: `*(int *)(param_1 + 0x194) = iVar5` | none |
| +0x198 | int | filter index end | MEDIUM | FUN_004c0db0 line 64: `*(int *)(param_1 + 0x198) = iVar5` | none |
| +0x19c | int | filter flags | MEDIUM | FUN_004c0db0 line 65: `*(undefined4 *)(param_1 + 0x19c) = 1` | none |
| +0x1a0 | bool | filter active flag | MEDIUM | FUN_004c0db0 line 66: `*(undefined1 *)(param_1 + 0x1a0) = 1` | none |
| Stride 0x1b4 | — | per-vehicle stride | HIGH | FUN_004c0db0 line 68: `param_1 = param_1 + 0x1b4` | none |

All types match. Note: filter state starts at param_1_base + 0x10 (from line 53: `param_1 = param_1 + 0x10`), with 0x1b4 stride after that.

**Undocumented surrounding fields (not in struct table):**
- param_1 + 0xb110, +0xb114: int (from iVar1 = DAT_007d0a20)
- param_1 + 0xb118: int (set to 0)
- param_1 + 0xb11c: byte (set to 1)
- param_1 + 0xb144: int (set to 2)
- param_1 + 0xb148: int (set to 0)

---

## Section 139: Scoring Database Struct (at DAT_007d2e48 + season_index * 0x48c0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x403c | int | season points total | MEDIUM | FUN_004c0910: `*(int *)(iVar2 + 0x403c)` compared with threshold | none |
| +0x4060 | int | finish position | MEDIUM | FUN_004c0910: `DAT_007d2e48 + index*0x48c0 + 0x4060` read | none |
| +0x4064 | int | finish state | MEDIUM | FUN_004c0910: `*(int *)(iVar2 + 0x4064)` compared with 3 | none |
| +0x409c | float | best lap time | LOW | Not directly accessed in this function (referenced by doc only) | unconfirmed |

All confirmed offset types match. The database stride of 0x48c0 between entries matches vehicle struct sizing.

**NOTE:** These offsets (+0x403c..+0x409c) align with known vehicle struct offsets, suggesting the scoring DB may reuse the vehicle struct layout or a compatible subset.

---

## Section 140: Circular Buffer Slot Allocator (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x58 | int | maxCount | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x58)` read, compared with currentIndex+1 | none |
| +0x5c | ptr | slotArray | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x5c)` used as array base ptr | none |
| +0x60 | int | currentIndex | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x60)` read/write, incremented | none |
| +0x64 | int | allocCount | HIGH | FUN_004cb540: `*(int *)(param_1 + 100)` = param_1+0x64, used as index into mappingArray | none |
| +0x68 | ptr | mappingArray | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x68)` used as array of ptrs | none |

All types confirmed. No conflicts. ✓

**Additional observation:** Sub-field at slotArray[i]+4 is checked for `< 0` (line 19, negative sentinel meaning free slot), then written with allocCount when allocated.

---

## Section 141: BSPTreeNode (inferred — param_1/param_2 in FUN_0044a4b0)

**Node output (param_1):**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | short | SplitDir | HIGH | Line 61/65/86/89: `*(undefined2 *)(param_1+8)` = 0/1/0xffff/0xfffe | none |
| +0x0a | short | SplitIndex | HIGH | Line 62/66/94: `*(short *)(param_1+10)` = local_24 or 0xffff | none |
| +0x0c | int* | VertexPtr | HIGH | Line 72: `*(int *)(param_1+0xc)` computed from allocator context | none |

**Allocator context (param_2):**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1c | int | NodeCount | MEDIUM | Used as count (line 95: `iVar2+0x1c * 0x5c + iVar2+0x24`, write at line 96). Also used as linked-list next ptr on individual nodes (line 33). | none (union/overlap: same offset serves as count on allocator and next-ptr on nodes) |
| +0x24 | int* | DataBase | HIGH | Line 95: `*(int *)(iVar2+0x24)` used as base ptr | none |
| +0x28 | int | VertexCount | HIGH | Line 72: `*(int *)(iVar2+0x28)` multiplied by 0x10 | none |
| +0x30 | int* | VertexBase | HIGH | Line 72: `*(int *)(iVar2+0x30)` used as base ptr | none |
| +0x34 | int | SomeParam | HIGH | Line 52: `*(undefined4 *)(iVar2+0x34)` passed to FUN_0044a2d0 | none |

All confirmed. The +0x1c overlap (NodeCount vs nextPtr) is correctly flagged in the struct table as a potential union/overlap. ✓

---

## Section 142: VehicleLapTime (inferred — from FUN_0049b6d0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x403c | int | CurrentLap | **CONFLICT** | FUN_0049b6d0: `*(int *)(param_1+0x403c)` compared between two vehicles as lap counter | **POTENTIAL CONFLICT with docs/13**: known vehicle struct defines +0x403c as **SeasonPoints** (int). Same offset has different semantic meaning in this context. Either param_1 is not a vehicle struct, or the field serves dual purpose. |

**VERDICT:** FUN_0049b6d0 treats +0x403c as a monotonically increasing counter compared between entities, with time-delta computation based on equality/inequality. This could be lap count (for scoring) OR season points (for position comparison). The function logic is ambiguous — flag as `[NEEDS RESOLUTION]`.

---

## Section 143: Scene File Struct (param_1, fog parameters)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x188 | short | FogColorR | HIGH | Line 122: `*(undefined2 *)(param_1+0x188) = local_428` (FOGCOLOR component) | none |
| +0x18a | short | FogColorG | HIGH | Line 121: `*(undefined2 *)(param_1+0x18a) = local_424` | none |
| +0x18c | short | FogColorB | HIGH | Line 120: `*(undefined2 *)(param_1+0x18c) = local_420` | none |
| +0x190 | float | FogDensity | HIGH | Line 134: `*(undefined4 *)(param_1+400)` = param_1+0x190, undefined4 compatible with float | none |
| +0x194 | float | FogInDist | HIGH | Line 126: `*(undefined4 *)(param_1+0x194) = local_42c` (FOGIN value) | none |
| +0x198 | float | FogOutDist | HIGH | Line 130: `*(undefined4 *)(param_1+0x198) = local_42c` (FOGOUT value) | none |
| +0x19c | int | FogModeMask | HIGH | Lines 83,98,113: value 0x20000(LINEAR)/0x40000(EXP)/0x80000(EXP2) | none |

All confirmed. Types match. NOTE: the color component ordering in code is B(+0x188) then G(+0x18a) then R(+0x18c), consistent with DirectX BGR convention. The current struct table names them FogColorR at +0x188 and FogColorB at +0x18c, which is **swapped** relative to the code. The code stores `local_428` (first param to FOGCOLOR parser) at +0x188 and `local_420` (third param) at +0x18c. If the parser returns B,G,R order (DirectX convention), then +0x188=B, +0x18a=G, +0x18c=R. The struct table has R at +0x188 and B at +0x18c — likely needs **field name swap**.

---

## Section 144: AudioArrayContainer (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | DataBuffer | HIGH | FUN_00564740: param_1[0] = *param_1 passed to FUN_0058aa6f free | none |
| +0x04 | int | ElementCount | HIGH | FUN_00564740: param_1[1] as loop bound | none |

All confirmed. Simple container with data ptr + count. ✓

---

## Section 145: Cross-reference: fields already in docs/13-struct-offsets.md

| Field | docs/13 Offset | docs/02 Offset | Match? | Verdict |
|-------|---------------|----------------|--------|---------|
| EffectiveLifetimeAtSpawn | +0x1db4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeEngineRPM min/max | +0x1dbc/+0x1dc4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeOilTemp min/max | +0x1dcc/+0x1dd4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| PitStopFlag bitmask | +0x1180 | +0x1178 | MISMATCH — adjacent offsets | **RESOLUTION**: Likely separate fields: +0x1178 = PlannedStopsBitmask (from .rcd), +0x1180 = runtime pit stop flag. Recommend retaining both as separate adjacent fields. |

=== NEW OFFSETS DISCOVERED ===

No new offsets added (all undocumented offsets found are single-function observations; rule requires 2+ .c files for addition).

=== SUMMARY OF CONFLICTS ===

| Section | Offset | Issue | Severity |
|---------|--------|-------|----------|
| 132 | +0x030..+0x04c | Mixed struct levels — on sub-object, not param_1 | MEDIUM |
| 135 | +0x00 | Type mismatch: int→ptr | HIGH |
| 135 | +0x04 | Type mismatch: int→ptr | HIGH |
| 135 | +0x08 | Type mismatch: int→ptr | HIGH |
| 135 | +0x1c | Type mismatch: int→ptr | HIGH |
| 136 | +0x1900 | Type mismatch: double→byte | HIGH |
| 136 | +0x1808 | Type mismatch: float→double | HIGH |
| 136 | +0x1818 | Type mismatch: float→double | HIGH |
| 136 | +0x1bbc-0x1be4 | Structure mismatch: not float[8] | HIGH |
| 136 | +0x17a8 | Array size: float[6*4]→float[6] | MEDIUM |
| 136 | +0x17c0 | Array size: float[6*4]→float[6] | MEDIUM |
| 136 | +0x1828-0x1834 | Array size: float[6]→float[4] | MEDIUM |
| 142 | +0x403c | Semantic conflict: CurrentLap vs SeasonPoints | MEDIUM |
| 143 | +0x188/0x18c | Field names swapped: R↔B color components | LOW |
