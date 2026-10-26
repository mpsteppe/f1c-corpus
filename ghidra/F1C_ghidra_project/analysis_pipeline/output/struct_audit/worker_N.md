=== AUDIT RESULTS ===

## AnimationNode / BoneGroup — Section 188

Current confidence in docs/13: **medium**

### AnimationNode (node struct within linked list at parent+0x204)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | ptr | NextNode | HIGH | 0x54bf60 L14: `*(int *)(iVar1 + 0x10)` | none |
| +0x118 | int | BoneGroupCount | HIGH | 0x54bf60 L16: `*(int *)(iVar1 + 0x118)` | none |
| +0x11c | ptr | BoneGroupArray | HIGH | 0x54bf60 L17: `*(int *)(iVar1 + 0x11c)` | none |

Note: ListHead at parent+0x204 NOT part of anim node struct. The parent container's linked list head is at +0x204.

### BoneGroup (stride 0x40, piVar3 starts at base+8)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | GroupID | **LOW** | 0x54bf60 L19: GroupID = piVar3[-1] = *(base+4) | **Doc off by 4**: code shows +0x04 |
| +0x04 | int | BoneCount | **LOW** | 0x54bf60 L22/L29: BoneCount = *piVar3 = *(base+8) | **Doc off by 4**: code shows +0x08 |
| +0x08 | ptr | BoneDataArray | **LOW** | 0x54bf60 L23: BoneDataArray = piVar3[1] = *(base+12) | **Doc off by 4**: code shows +0x0C |
| +0x30 | int | DirtyFlags | **LOW** | 0x54bf60 L41: DirtyFlags = piVar3[0xC] = *(base+0x38) | **Doc off by 8**: code shows +0x38 |

**CONFLICT (Systematic):** All 4 BoneGroup offsets are wrong. The doc lists +0x00/0x04/0x08/0x30, but code shows +0x04/0x08/0x0C/0x38. Likely cause: doc reported offsets relative to piVar3 base (which starts at base+8) instead of absolute offset from group struct base. **SYSTEMATIC +4/+8 ERROR.**

### Animation State

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x340 | byte | AnimFlag1 | HIGH | 0x4be9e0 L10, 0x4be700 L8 | none |
| +0x341 | byte | AnimFlag2 | HIGH | 0x4be9e0 L11, 0x4be700 L9 | none |
| +0x342 | byte | FlagC | HIGH | 0x4be700 L10 | none |
| +0x344 | int/float | MultiplierA/AnimValue1 | HIGH | 0x4be9e0 L12, 0x4be700 L11 (0x3f800000=1.0f) | none |
| +0x348 | float | MultiplierB | HIGH | 0x4be700 L12 (0x3f800000=1.0f) | none |
| +0x34C | float | ThresholdRef | HIGH | 0x4be700 L13 (DAT_005acdac) | none |
| +0x350 | float | FloatLimit/AnimValue2 | HIGH | 0x4be9e0 L13, 0x4be700 L14 (0x41200000=10.0f) | none |
| +0x35C | int | IterationCount | HIGH | 0x4be700 L17 (10) | none |
| +0x360 | int | SubIterationCount | HIGH | 0x4be700 L18 (5) | none |

### New offsets found in Animation State

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| AnimationState | +0x354 | undefined4 | 0x4be700 L15 | Zero-initialized |
| AnimationState | +0x358 | undefined4 | 0x4be700 L16 | Zero-initialized |

---

## 14. AnimationList (inferred) — Section 190

Current confidence in docs/13: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x204 | ptr | ListHead | **UNVERIFIABLE** | FUN_004f2e90: no .c file exists | Missing source |
| +0x10 (node) | ptr | NextPtr | MEDIUM | 0x54bf60 L14: linked list next pattern, same offsets | Not confirmed to be AnimationList container |
| +0x118 (node) | int | ElementCount | MEDIUM | 0x54bf60 L16: BoneGroupCount | Same value used as BoneGroup count |
| +0x11c (node) | ptr | ElementBase | MEDIUM | 0x54bf60 L17: BoneGroupArray | Same value used as BoneGroup ptr |

**Assessment:** These offsets appear in FUN_0054bf60 which is AnimationNode/BoneGroup traversal — NOT an AnimationList. The ListHead at +0x204 and node fields +0x10/+0x118/+0x11c are AnimationNode fields, not a separate "AnimationList" struct. The AnimationList struct appears to **duplicate AnimationNode**. FUN_00585bf0 (cited source) has vtable dispatch, no +0x204 access.

**Recommendation:** Either merge with AnimationNode or verify FUN_004f2e90 source exists.

---

## VehicleWheelDataStruct (stride 0x3e/0x4a) — Section 191

Current confidence in docs/13: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x32bc | int | PhysicsMode | HIGH | 0x4ee2d0 L95: `*(int *)(param_1 + 0x32bc)` switch 0/1/2/3 | none |
| +0x34ac | float | RotationAngle | HIGH | 0x4ee2d0 L88: `*(float *)(param_1 + 0x34ac)` | none |
| +0x34b0-0x34e0 | float[9] | RotationMatrix | **MEDIUM** | 0x4ee2d0: 0x34b0..0x34dc = **12 floats (0x30 bytes)**, not 9 | **Range wrong**: actual 0x34b0-0x34dc (12 floats) |
| +0x34d4-0x34dc | float[3] | PositionOffset | HIGH | 0x4ee2d0 L78-80: +0x34d4, +0x34d8, +0x34dc | none |
| +0x34ec-0x34f4 | float[3] | LocalPosition | HIGH | 0x4ee2d0 L85-87: +0x34ec, +0x34f0, +0x34f4 | none |
| +0x34f8-0x3500 | float[3] | LocalOffset | HIGH | 0x4ee2d0 L307-309: +0x34f8, +0x34fc, +0x3500 | none |
| +0x3590 | float[] | WheelData[4] | HIGH | 0x4ee2d0 L125: pfVar12 = param_1+0x3590, stride 0x3e, 4 iters | none |
| +0x3668 | int | ContactCount | HIGH | 0x4ee2d0 L101: `*(int *)(param_1 + 0x3668)` | none |
| +0x36c4 | float | ContactActive | HIGH | 0x4ee2d0 L116: `*(float *)(param_1 + 0x36c4)` | none |
| +0x3760 | int | WheelCount | HIGH | 0x4ee2d0 L206: `*(int *)(param_1 + 0x3760)` | none |
| +0x3be8-0x3bf0 | float[3] | SurfaceNormal | HIGH | 0x4ee2d0 L103-105: +0x3be8, +0x3bec, +0x3bf0 | none |
| +0x3d54-0x3d5c | float[3] | ContactPos | HIGH | 0x4ee2d0 L222-224: +0x3d54, +0x3d58, +0x3d5c | none |
| +0x6e4 | ? | SuspensionData | HIGH | 0x4ee2d0 L97: passed to FUN_004472b0(param_1+0x6e4) | type unknown |
| +0x77c | ? | TireDataStart | HIGH | 0x4ee2d0 L220: Tire ptr, L383-385: float writes at +0x77c, +0x790, +0x7a4 | type = float sub-struct |
| +0x7d4 | float[] | BrakeData[4] | HIGH | 0x4ee2d0 L124: pfVar8 = param_1+0x7d4, stride 0x4a, 4 iters | none |
| +0x8cc-0xc44 | float[4] | TireWearChannels | HIGH | 0x4ee2d0 L387-390: +0x8cc, +0x9f4, +0xb1c, +0xc44 (stride 0x128) | not contiguous |
| +0x1070 | byte | ActiveFlag | HIGH | 0x4ee2d0 L98/L239: `*(char *)(param_1 + 0x1070)` | none |

**RotationMatrix range mismatch:** Doc says 9 floats at 0x34b0-0x34e0, code accesses 12 floats at 0x34b0-0x34dc. The 4th column (+0x34d4-0x34dc) is separately called PositionOffset, so the matrix is likely 3x4 (12 floats, column-major) with PositionOffset being the 4th column of a 4x4 matrix.

---

## WheelSuspensionInitStruct (inferred) — Section 193

Current confidence in docs/13: **medium**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x48 | float | PosX | HIGH | 0x4e2540 L19: `*(float *)(param_1 + 0x48)` | none |
| +0x4c | float | PosY | HIGH | 0x4e2540 L20: `*(float *)(param_1 + 0x4c)` | none |
| +0x50 | float | PosZ | HIGH | 0x4e2540 L21: `*(float *)(param_1 + 0x50)` | none |
| +0x74 | float | VelocityStore1 | HIGH | 0x4e2540 L22: `*(float *)(iVar1 + 0x74)` = fVar2 | none |
| +0x8c | int[9] | CoeffCopySource | HIGH | 0x4e2540 L35-39: copy loop from +0xd0 to +0x8c | none |
| +0xb8 | float | VelocityStore2 | HIGH | 0x4e2540 L25: `*(float *)(iVar1 + 0xb8)` = fVar2 | none |
| +0xc4 | float | ParamStore1 | HIGH | 0x4e2540 L31: `*(undefined4 *)(iVar1 + 0xc4)` = 0 | none |
| +0xcc | float | ParamStore2 | HIGH | 0x4e2540 L32: `*(undefined4 *)(iVar1 + 0xcc)` = param_6 | none |
| +0xd0 | int[9] | CoeffCopyTarget | HIGH | 0x4e2540 L34-38: source for 9-int copy | none |
| +0xf8 | float | ParamStore3 | HIGH | 0x4e2540 L29: `*(undefined4 *)(iVar1 + 0xf8)` = param_5 | none |
| +0xfc | float | ParamStore4 | HIGH | 0x4e2540 L28: `*(undefined4 *)(iVar1 + 0xfc)` = param_4 | none |

### New offsets in WheelSuspensionInitStruct

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| WheelSuspensionInit | +0x78 (per-wheel) | float | 0x4e2540 L23 | Velocity component 2 |
| WheelSuspensionInit | +0x7c (per-wheel) | float | 0x4e2540 L24 | Velocity component 3 |
| WheelSuspensionInit | +0xbc (per-wheel) | float | 0x4e2540 L26 | Velocity component 2 (duplicate store at +0xb8) |
| WheelSuspensionInit | +0xc0 (per-wheel) | float | 0x4e2540 L27 | Velocity component 3 (duplicate store at +0x78?) |
| WheelSuspensionInit | +0x80 (per-wheel) | ptr/undefined4 | 0x4e2540 L41 | Passed to FUN_00567340 |
| WheelSuspensionInit | +0xC8 (per-wheel) | undefined4 | 0x4e2540 L30 | Also = param_5 (duplicate of +0xf8) |

**Note:** iVar1 = param_2 * 0x128 + 0xd4 + param_1. Struct per-wheel offset starts at +0xd4 from param_1 base, stride 0x128.

---

## Filter Node Linked List (stride 0xc) — Section 194

Current confidence in docs/13: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | scene index | HIGH | 0x4c5e50 L56: `*piVar6 = iVar3` | none |
| +0x04 | void* | next pointer | HIGH | 0x4c5e50 L57: `piVar6[1] = 0` | none |
| +0x08 | bool | active flag | HIGH | 0x4c5e50 L58: `*(undefined1 *)(piVar6 + 2) = 1` | type is byte/undefined1, not bool |

Container struct (Filter List State, also in docs/13) confirmed:
| +0x08 | ptr | list head | HIGH | 0x4c5e50 L60-61 | |
| +0x0c | ptr | list tail | HIGH | 0x4c5e50 L67 | |
| +0x10 | ptr | iterator | HIGH | 0x4c5e50 L62 | |
| +0x14 | int | node count | HIGH | 0x4c5e50 L69 | |

**Assessment:** Node struct confirmed correct. Container struct also verified.

---

## Camera/Projection Struct (inferred) — Section 195

Current confidence in docs/13: **high**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | float | nearClipZ | HIGH | 0x542050 L47: read at +0x04 via +0xe8 copy, 0x4c7f30 L86: used in clamp | none |
| +0x08 | float | farClipZ | HIGH | 0x542050 L43: read as f32, 0x4c7f30 L85-89: compared/modified | none |
| +0x0c | float | projScaleX | HIGH | 0x542050 L38, 0x542200 L64-65 | none |
| +0x10 | float | projScaleY | HIGH | 0x542050 L39, 0x542200 L66-67 | none |
| +0x14 | float | widthFloat | HIGH | 0x542200 L58: `*(float *)(param_1 + 0x14)` | none |
| +0x18 | float | heightFloat | HIGH | 0x542200 L62: `*(float *)(param_1 + 0x18)` | none |
| +0x1c | float | tanHalfFovX | HIGH | 0x542050 L30, 0x542200 L64 | none |
| +0x20 | float | tanHalfFovY | HIGH | 0x542050 L33, 0x542200 L67 | none |
| +0x54 | int | screenWidth | HIGH | 0x542050 L38, 0x542200 L29/L39 | none |
| +0x58 | int | screenHeight | HIGH | 0x542050 L39, 0x542200 L46/L51 | none |
| +0x5c | int | centerX | HIGH | 0x542200 L57 | none |
| +0x60 | int | centerY | HIGH | 0x542200 L61 | none |
| +0x6c | float | fov | HIGH | 0x542050 L19, 0x4c7f30 | none |
| +0x70 | float | pitch | HIGH | 0x542050 L27 | none |
| +0x74 | float | aspectRatio | HIGH | 0x542200 L68 | none |
| +0x78 | float | farDiagonal | HIGH | 0x542050 L68 | none |
| +0x80 | int | flags | HIGH | 0x542050 L69, 0x542200 L69: bit 4 checked | none |
| +0x9c..0xd8 | float[15] | viewMatrix | HIGH | 0x542050 L48-62: 0x9c..0xd8 = 15 floats, 3x5 matrix | name: orientation matrix |
| +0xec..0xf8 | float[3] | translation | HIGH | 0x542050 L40-42: zeroed + farClipZ relation | none |
| +0xdc..0xe8 | float[3] | forwardZ | HIGH | 0x542050 L44-46: (0,0,1.0, farClipZ copy) | none |
| +0x19c | ptr | chainTexture | **LOW** | **NOT in FUN_00495dc0** | **NO EVIDENCE: FUN_00495dc0 accesses 0x1578-0x1584, not 0x19c** |

**CONFLICT:** `+0x19c | ptr | chainTexture | FUN_00495dc0` — FUN_00495dc0 does NOT access offset +0x19c. It accesses +0x1578, +0x157c, +0x1580, +0x1584 for texture chain operations. This offset claim in FUN_00495dc0 is **FALSE**.

**No new offsets found.**

---

## Lazy Init Struct (inferred) — Section 196

Current confidence in docs/13: **high**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xaf0 | byte | initFlag | HIGH | 0x4184f0 L10: `*(char *)(param_1 + 0xaf0)` | none |
| +0xaf4 | int | resourceHandle | HIGH | 0x4184f0 L13: `*(int *)(param_1 + 0xaf4)` | none |

**Assessment:** Both offsets verified. Confidence HIGH confirmed.

---

## ProximitySphere (inferred — entry in FUN_004bda20) — Section 197

Current confidence in docs/13: **high**

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| +0x04 | int | Tag | HIGH | 0x4bda20 L24: `*(int *)(iVar1 + 4)` compared with param_2 | none |
| +0x0C | float | CenterX | HIGH | 0x4bda20 L19: `*(float *)(iVar1 + 0xc)` | none |
| +0x10 | float | CenterY | HIGH | 0x4bda20 L20: `*(float *)(iVar1 + 0x10)` | none |
| +0x14 | float | CenterZ | HIGH | 0x4bda20 L21: `*(float *)(iVar1 + 0x14)` | none |
| +0x18 | float | Radius | HIGH | 0x4bda20 L22: `*(float *)(iVar1 + 0x18)` + param_5 | none |
| +0x20 | int | ExcludeTag | HIGH | 0x4bda20 L24: `*(int *)(iVar1 + 0x20)` compared with param_3 | none |

**Assessment:** All 6 offsets verified. Confidence HIGH confirmed.

---

## CollisionProxyFlagSetter (inferred — from FUN_004ba140) — Section 198

Current confidence in docs/13: **low**

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| param_1+0x08 | int* | EntityPtr | HIGH | 0x4ba140 L8: `*(int *)(param_1 + 8)` dereferenced | none |
| EntityPtr+0xF78 | byte | FlagField | HIGH | 0x4ba140 L8: `*(undefined1 *)(entity + 0xf78) = param_2` | none |

**Assessment:** Both offsets verified. The struct is minimal (2-field bridge accessor). Confidence should be HIGH, not LOW.

---

## 12. Environment/Track Struct (inferred) — Section 199

Current confidence in docs/13: **low**

| Offset | Current Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|------------|------------|-------------|-----------|
| +0x1aec | int | EnvMode | HIGH | 0x4ade20 L11: `*(undefined4 *)(param_1 + 0x1aec) = 1` | none |
| +0x1b10 | int | CameraCount | HIGH | 0x4ade20 L24/L29-34: read, clamp, modify | none |
| +0x1b18 | int | CameraMin | HIGH | 0x4ade20 L30: `*(int *)(param_1 + 0x1b18)` used as clamp lower bound | none |
| +0x1b1c | int | CameraMax | HIGH | 0x4ade20 L33: `*(int *)(param_1 + 0x1b1c)` used as clamp upper bound | none |

**Assessment:** All 4 offsets verified in single function. Confidence should be raised to MEDIUM.

---

## StreamBufferReadStruct (inferred) — Section 200

Current confidence in docs/13: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | uint | vtable | HIGH | 0x50fab7 L11: `param_1[0]` = `*param_1`, L12: `*param_1 + 0x14` | none |
| +0x08 | uint | IOCallback | HIGH | 0x50fab7 L17-19: `piVar1[2]` has vtable dispatch | type: ptr-to-vtable-obj, not uint |
| +0x10 | int | MagicCheck | HIGH | 0x50fab7 L11: `param_1[4]` must be 0xcd | none |
| +0x60 | uint | CompletionCallback | **LOW** | 0x50fab7 L16: `piVar1[0x18]` used as **size/boundary** for read cursor | **WRONG ROLE**: +0x60 is TotalSize/BufferLimit, not a callback |
| +0x78 | uint | ReadCursor | HIGH | 0x50fab7 L16/L24: `piVar1[0x1e]` compared and incremented | none |

**CONFLICT (documented):** +0x60 is listed as both CompletionCallback and TotalSize. Code confirms it IS TotalSize/BufferLimit — used in `piVar1[0x1e] < piVar1[0x18]` comparison (read cursor < limit).

### New offsets discovered

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| StreamBufferRead | +0x180 | ptr | 0x50fab7 L23 | `piVar1[0x60]` = object ptr with vtable+4 = read method. **This is the actual I/O handler.** |
| StreamBufferRead | +0x08 (vtable) | ptr (field within IOCallback obj) | 0x50fab7 L18 | `*(int *)(piVar1[2] + 4)` = IOCallback object method |

**+0x60 role correction:** The size/limit at +0x60 determines how many bytes remain in the buffer. The actual I/O completion handler is at +0x180 (`piVar1[0x60]`), which has a vtable-based dispatch at +4.

=== NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| AnimationState | +0x354 | undefined4 | 0x4be700 L15 | Zero-initialized (padding?) |
| AnimationState | +0x358 | undefined4 | 0x4be700 L16 | Zero-initialized (padding?) |
| WheelSuspensionInit | +0x78 (per-wheel) | float | 0x4e2540 L23 | Velocity Y component |
| WheelSuspensionInit | +0x7c (per-wheel) | float | 0x4e2540 L24 | Velocity Z component |
| WheelSuspensionInit | +0xbc (per-wheel) | float | 0x4e2540 L26 | Velocity Y duplicate |
| WheelSuspensionInit | +0xc0 (per-wheel) | float | 0x4e2540 L27 | Velocity Z duplicate |
| WheelSuspensionInit | +0x80 (per-wheel) | ptr/undefined4 | 0x4e2540 L41 | Passed to FUN_00567340 |
| WheelSuspensionInit | +0xC8 (per-wheel) | undefined4 | 0x4e2540 L30 | Also = param_5 (dup of +0xf8) |
| StreamBufferRead | +0x180 | ptr | 0x50fab7 L23 | Actual I/O handler object with vtable |
| Environment/Track | +0x1aec param_1 | int | 0x4ade20 | Struct base extends beyond these 4 fields |

=== SUMMARY ===

| Struct | Verdict |
|--------|---------|
| **AnimationNode** (node) | ✓ Correct |
| **BoneGroup** | **✗ SYSTEMATIC ERROR**: All 4 offsets off by +4/+8. Doc describes offsets relative to wrong base. |
| **AnimationState** | ✓ Correct. 2 new zeroed fields at +0x354/+0x358. |
| **AnimationList** | ⚠ No source for FUN_004f2e90. Appears to duplicate AnimationNode. |
| **VehicleWheelDataStruct** | ✓ Mostly correct. RotationMatrix range wrong (12 floats not 9). |
| **WheelSuspensionInitStruct** | ✓ Correct. 6 minor new offsets found. |
| **Filter Node Linked List** | ✓ Correct. Container struct also verified. |
| **Camera/Projection Struct** | ✓ Mostly correct. **✗ +0x19c chainTexture FALSE**: FUN_00495dc0 has no such offset. |
| **Lazy Init Struct** | ✓ Verified. Confidence HIGH confirmed. |
| **ProximitySphere** | ✓ All 6 offsets verified. |
| **CollisionProxyFlagSetter** | ✓ Verified. Should be HIGH not LOW confidence. |
| **Environment/Track Struct** | ✓ Verified. Should be MEDIUM not LOW. |
| **StreamBufferReadStruct** | ⚠ +0x60 is TotalSize/Limit, NOT CompletionCallback. Actual handler at +0x180. |
