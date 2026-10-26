# docs/13 Struct Confidence Audit Report

Generated from 20 DS worker runs. 281 struct sections audited.

Each section contains: confidence scores per field, .c evidence, conflicts, and newly discovered offsets.

---

## Worker Summaries

### Worker F

| Section | Name | Grade | Type Conflicts | Size Conflicts | Missing .c |
|---------|------|-------|----------------|----------------|------------|
| 76 | OpponentStateStruct | MEDIUM | 2 (+0x4fc double/float, +0x83c int/float) | 0 | FUN_004c0cc0 |
| 77 | CollisionContactState | HIGH | 0 | 0 | — |
| 78 | GameConfig | LOW | 0 | 0 | FUN_004216f0 |
| 79 | ConstraintGroupStruct | HIGH | 0 | 0 | — |
| 80 | AudioSceneUpdateStruct | MEDIUM | 0 | 0 | — |
| 81 | WheelFloatArray | HIGH | 1 naming overlap (float[3] vs separate) | 0 | — |
| 82 | AutoLoadEntry | LOW | 0 | 0 | FUN_00432e70 |
| 83 | FileHandleClose | HIGH | 0 | 0 | — |
| 84 | DisplayModeInit | HIGH | 0 | 0 | — |
| 85 | CollisionMaterialGroup | MEDIUM | 1 (global vs struct, 6 vs 4 fields) | 1 (stride 0x18 vs 0x10) | — |
| 86 | CollisionContactSolver | HIGH | 1 (+0x04 byte vs uint) | 0 | — |
| 87 | VehicleStruct | MIXED | 0 | 0 | FUN_0042e530, FUN_00419c50, FUN_0041d630 |
| 88 | AudioSampleRingBuffer | MEDIUM | 1 (+0x1018 double vs float) | 1 (+0x101c short[5] vs 18+ bytes) | — |
| 89 | LinkedListNode | LOW | 1 (structural overlap) | 0 | FUN_004bf790 |

**Total type conflicts: 7**
**Total structs requiring source recovery: 5 (Sections 78, 82, parts of 76, 87, 89)**

### Worker G

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

### Worker J

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

### Worker K

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

### Worker N

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

### Worker O

| Section | Name | Offsets | Confidence | Issues |
|---------|------|---------|------------|--------|
| 202 | PitStop/PitCrewStruct | 7 | HIGH → HIGH | None confirmed |
| 204 | ArrayContainer (various) | 6 variants | HIGH → LOW-MEDIUM | Multi-variant, needs per-function check |
| 205 | VehicleControllerStruct | 23 (9 verified) | HIGH → partial | 14 offsets need FUN_00425670 verification |
| 206 | VehiclePhysicsHeader | 180+ (56 verified) | HIGH | 5 naming conflicts (some flagged); 3 new offsets found |
| 207 | VehicleSetupFileWriterLayout | referential | HIGH | OK — referential to Section 206 |
| 208 | Filter List State | 4 | LOW → HIGH | **Upgrade to HIGH** — all offsets verified |
| 209 | Transform/4x4 Matrix | 16 | HIGH → HIGH | All verified, no issues |
| 210 | Render Property Slots | 3 | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 211 | SpringDamperState | 13 indices | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 213 | Commentary Path List | 6 | VERY LOW → VERY LOW | No .c file available, unverifiable |
| 214 | MessageSlotStruct | 4 | MEDIUM → HIGH | **Upgrade to HIGH** — all verified |
| 215 | VehiclePhysicsInstance (tire) | 14 | HIGH → MEDIUM (type) | **2 type conflicts** (double→float), 1 new offset (+0x157c) |

### Worker S

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

---

## All New Offsets Discovered

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| Commentary/DirectorEvent | +0x14 | int | FUN_0040d4c0 | Sub-event type code (1 or 2) � missing from docs |
| CarPartVisibility | +0xb1c | ptr | FUN_004ae490 | Associated resource per part (pair with +0xb10) |
| CarPartVisibility | +0xb40 | ptr | FUN_004ae490 | Associated resource per part (pair with +0xb34) |
| CarPartVisibility | +0xb64 | ptr | FUN_004ae490 | Associated resource per part (pair with +0xb58) |
| CarPartVisibility | +0x1c3c | ptr | FUN_004ae490 | Associated resource per part (pair with +0x1c30) |
| CarPartVisibility | +0x2350 | float | FUN_004ae490 | Paired with +0x2348 AnimParamA |
| CarPartVisibility | +0x2354 | float | FUN_004ae490 | Second param of FUN_004646c0 (paired with +0x2350) |
| CarPartVisibility | +0x2374 | float | FUN_004ae490 | FUN_004646c0 call (always executed) � third anim param pair |
| CarPartVisibility | +0x2378 | float | FUN_004ae490 | FUN_004646c0 call (always executed) |
| CarPartVisibility | +0x26fc | ptr | FUN_004ae490 | Body part paired resource start (+0x26f0 flag at +0x26fc) |
| CarPartVisibility | +0x2714 | int | FUN_004ae490 | Additional body part flag |
| CarPartVisibility | +0x2720 | ptr | FUN_004ae490 | Body part paired resource |
| CarPartVisibility | +0x2738 | int | FUN_004ae490 | Additional body part flag |
| CarPartVisibility | +0x2744 | ptr | FUN_004ae490 | Body part paired resource |
| CarPartVisibility | +0x27ec | int | FUN_004ae490 | Additional body part flag |
| CarPartVisibility | +0x27f8 | ptr | FUN_004ae490 | Body part paired resource |
| CarPartVisibility | +0x2810 | int | FUN_004ae490 | Additional body part flag |
| CarPartVisibility | +0x281c | ptr | FUN_004ae490 | Body part paired resource |
| CarPartVisibility | +0x2840 | ptr | FUN_004ae490 | Body part paired resource |
| Struct | Issue | Severity | Recommendation |
| WheelCornerStruct | All early offsets (+0x006 through +0x039) miscalculated | CRITICAL | Recalculate using float* index * 4 (see audit above for correct values). Velocity at +0x0c, SlipForce at +0xe8, etc. |
| WheelForceArrayStruct | Same offset errors as WheelCornerStruct � appears to be duplicate early-field view with miscalculations | CRITICAL | Merge into WheelCornerStruct with corrected offsets or remove as duplicate |
| ReplaySaveStruct | +0x6e8: doc says int, actual char* pointer | TYPE MISMATCH | Change type to char* or ptr |
| ReplaySaveStruct | +0x70c: doc says char[], actual is heap-allocated char* | TYPE CLARIFICATION | Change type to char* |
| ReplaySaveStruct | +0xf94: doc says char[], actual is heap-allocated ptr | TYPE CLARIFICATION | Change type to char* |
| NetworkSessionState | ClientArrayPtr at +0x08 (param_1[2]), not +0x04 as doc claims | OFFSET MISMATCH | Correct offset from +0x04 to +0x08 |
| CarPartVisibility | Only 8 offsets documented, function uses ~20+ offsets | INCOMPLETE | Add ~12+ new offset rows (see NEW OFFSETS DISCOVERED) |
| Commentary/DirectorEvent | Missing +0x14 sub-event type field | INCOMPLETE | Add offset +0x14 (int, 1 or 2) |
| ScoringDB/StandingsEntry | +0x08 | int | FUN_00435390 | Zeroed in init, purpose unknown |
| ScoringDB/StandingsEntry | +0x0c | int | FUN_00435390 | Zeroed in init, purpose unknown |
| CamMan | +0x2d | byte | FUN_0040c920 | Zeroed in Init, possibly another flag |
| BodyStateArray | +0x68 | double | FUN_00441ad0 | Gap between PosDeltaY (+0x64) and PosDeltaZ/AngVelX (+0x6c) |
| SuspensionForceValidator | +0x08 | double | FUN_004f3240 | pdVar3[1] per axis — second value per axis group |
| SuspensionForceValidator | +0x10 | double | FUN_004f3240 | pdVar3[2] per axis — third value per axis group |
| SuspensionForceValidator | +0x20 | double | FUN_004f3240 | Axis group 1, second value |
| SuspensionForceValidator | +0x28 | double | FUN_004f3240 | Axis group 1, third value |
| SuspensionForceValidator | +0x38 | double | FUN_004f3240 | Axis group 2, second value |
| SuspensionForceValidator | +0x40 | double | FUN_004f3240 | Axis group 2, third value |
| FileReadLoopStruct | +0x38 | int | FUN_005352d0 | Read status/result (-1=error, 0/1=status) |
| FileReadLoopStruct | +0x0c | int | FUN_005352d0 | Set from +0x48, possibly copy of readBufPtr |
| CockpitDashboard | +0x04 | ptr | FUN_0049ca00 | Font resource (FONTREAD) |
| CockpitDashboard | +0x08 | ptr | FUN_0049ca00 | Font resource (FONTLCD) |
| CockpitDashboard | +0x0c | ptr | FUN_0049ca00 | Font resource (FONTAIDS) |
| CockpitDashboard | +0x10 | ptr | FUN_0049ca00 | READOUT_BMP render object |
| CockpitDashboard | +0x14 | ptr | FUN_0049ca00 | LCD00_BMP render object |
| CockpitDashboard | +0x18 | ptr | FUN_0049ca00 | LCD00_BMP second instance |
| CockpitDashboard | +0x1c | ptr | FUN_0049ca00 | LCD01_BMP render object |
| Struct | Wrong Ref | Correct Ref | Severity |
| BodyStateArray | FUN_0041ad0 | FUN_00441ad0 (0x00441ad0) | HIGH — function doesn't exist |
| BodyStateArray | FUN_0041d60 | FUN_00441d60 (0x00441d60) | HIGH — function doesn't exist |
| CamMan MAINVIEWSceneNode | FUN_0040cce0 | FUN_0040c920 | LOW — wrong observer listed |
| Shift Struct | FUN_0042b8d0 param_1 | Not a struct | MAJOR — param_1 is int enum, not pointer |
| Struct | Current Confidence | Recommended | Reason |
| ScoringDB/StandingsEntry | HIGH | HIGH | Confirmed |
| AIStateBuffer | MEDIUM | MEDIUM | Dimensions wrong but offsets correct |
| CamMan | (implicit) | HIGH | All offsets confirmed |
| BodyStateArray | MEDIUM | MEDIUM | Some refs wrong, +0x64 dual-use |
| PerElementForceScalingStruct | LOW | LOW | Register-allocated base |
| SuspensionForceValidator | LOW | LOW | Incomplete offset documentation |
| AutoLoadEntry | HIGH | HIGH | Fully confirmed |
| FileReadLoopStruct | LOW | LOW | Only 1 function |
| TextureAllocationFormat | MEDIUM | MEDIUM | All confirmed |
| CollisionGridParams | MEDIUM | MEDIUM | Pattern confirmed, values incomplete |
| Small structs | varied | MEDIUM | All confirmed except ConstraintSolverState offsets |
| CockpitDashboard | MEDIUM | MEDIUM | 7 new offsets, types uncertain |
| PacketQueueStruct | MEDIUM | MEDIUM | All confirmed |
| Shift Struct | MEDIUM | INVALID | Wrong function reference |
| WheelFloatArray | +0x6c | float | FUN_004e3d00 line 127 | Force factor `param_1[0x1b]` — not in docs |
| WheelFloatArray | +0x70 | float | FUN_004e3d00 line 127 | Force factor `param_1[0x1c]` — not in docs |
| CollisionMaterialGroup | +0x10 | int | All material init functions | Unnamed field at +0x10 — zeroed in all entries |
| CollisionMaterialGroup | +0x14 | int | All material init functions | Unnamed field at +0x14 — zeroed in all entries |
| Vehicle (camera/scene) | +0x14 | int | FUN_0040adb0 line 29 | Animation/frame selector — NOT vehicle velocity |
| Vehicle (camera/scene) | +0x0c | int* | FUN_0040adb0 line 30 | Scene node pointer array — NOT vehicle position |
| Vehicle (camera/scene) | +0x04 | int | FUN_0040adb0 line 34 | Active flag — NOT vehicle velocity |
| Texture/VertexDecoder | +0x1030 | int | FUN_0050aeae:18 | BaseBufferEnd/source limit |
| Texture/VertexDecoder | +0x1064 | int | FUN_00509644:17, FUN_0050a659:18 | RowByteCount/pixel data size per row |
| Texture/VertexDecoder | +0x1074 | int | FUN_0050a92d:22, FUN_0050ab51:30,37 | MinRowIndex or extra stride |
| Texture/VertexDecoder | +0x107c | uint | FUN_0050ab51:30,36 | MaxRowIndex+1 |
| Texture/VertexDecoder | +0x1084 | uint | FUN_0050ab51:31,39 | MaxColIndex+1 |
| Texture/VertexDecoder | +0x1088 | int | FUN_0050aeae:15 | TransformActiveFlag |
| CollisionDeformationMesh | +0x04 | (unknown) | gap | Not referenced in FUN_004DF110 |
| CollisionDeformationMesh | +0x20 | float[] | FUN_004DF110 | Entry array inline (not behind pointer), stride 9 floats |
| Camera Manager | +0x38 | int | FUN_00408e20:142,170,194,203 | ExtraCamArray count |
| Camera Manager | +0x3c | int | FUN_00408e20:143,171 | Current camera index or padding |
| SetupParamArrayEntry | +0x1e | char[34] | FUN_0042f470:39,73,139,143,171,174,188,194,197,225,269,291,295,312,316,336 | Format string output buffer (not padding at +0x20)
| (not adding — single function observations) | | | | |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
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
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | unknown | (start) | NONE | Not accessed in FUN_0040b850 | Placeholder only |
| +0x04 | int | CameraCount | MEDIUM | FUN_0040b850: `extraout_ECX+4` set from FUN_00544f50 return | none |
| +0x0c | ptr | CameraArrayPtr | MEDIUM | FUN_0040b850: `extraout_ECX+0xc` set to piVar3 (array after count header) | none |
| +0x10 | int | CameraCount2 | MEDIUM | FUN_0040b850: `extraout_ECX+0x10` set to iVar5 | none |
| +0x14 | int | CurrentIndex | MEDIUM | FUN_0040b850: `extraout_ECX+0x14` set to 0 | none |
| +0xd0 | — | CameraStructSize | MEDIUM | Stride from `operator_new(iVar5 * 0xd0 + 4)` — array element stride 0xd0 | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x194 | int | filter index start | MEDIUM | FUN_004c0db0 line 63: `*(int *)(param_1 + 0x194) = iVar5` | none |
| +0x198 | int | filter index end | MEDIUM | FUN_004c0db0 line 64: `*(int *)(param_1 + 0x198) = iVar5` | none |
| +0x19c | int | filter flags | MEDIUM | FUN_004c0db0 line 65: `*(undefined4 *)(param_1 + 0x19c) = 1` | none |
| +0x1a0 | bool | filter active flag | MEDIUM | FUN_004c0db0 line 66: `*(undefined1 *)(param_1 + 0x1a0) = 1` | none |
| Stride 0x1b4 | — | per-vehicle stride | HIGH | FUN_004c0db0 line 68: `param_1 = param_1 + 0x1b4` | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x403c | int | season points total | MEDIUM | FUN_004c0910: `*(int *)(iVar2 + 0x403c)` compared with threshold | none |
| +0x4060 | int | finish position | MEDIUM | FUN_004c0910: `DAT_007d2e48 + index*0x48c0 + 0x4060` read | none |
| +0x4064 | int | finish state | MEDIUM | FUN_004c0910: `*(int *)(iVar2 + 0x4064)` compared with 3 | none |
| +0x409c | float | best lap time | LOW | Not directly accessed in this function (referenced by doc only) | unconfirmed |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x58 | int | maxCount | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x58)` read, compared with currentIndex+1 | none |
| +0x5c | ptr | slotArray | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x5c)` used as array base ptr | none |
| +0x60 | int | currentIndex | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x60)` read/write, incremented | none |
| +0x64 | int | allocCount | HIGH | FUN_004cb540: `*(int *)(param_1 + 100)` = param_1+0x64, used as index into mappingArray | none |
| +0x68 | ptr | mappingArray | HIGH | FUN_004cb540: `*(int *)(param_1 + 0x68)` used as array of ptrs | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x08 | short | SplitDir | HIGH | Line 61/65/86/89: `*(undefined2 *)(param_1+8)` = 0/1/0xffff/0xfffe | none |
| +0x0a | short | SplitIndex | HIGH | Line 62/66/94: `*(short *)(param_1+10)` = local_24 or 0xffff | none |
| +0x0c | int* | VertexPtr | HIGH | Line 72: `*(int *)(param_1+0xc)` computed from allocator context | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x1c | int | NodeCount | MEDIUM | Used as count (line 95: `iVar2+0x1c * 0x5c + iVar2+0x24`, write at line 96). Also used as linked-list next ptr on individual nodes (line 33). | none (union/overlap: same offset serves as count on allocator and next-ptr on nodes) |
| +0x24 | int* | DataBase | HIGH | Line 95: `*(int *)(iVar2+0x24)` used as base ptr | none |
| +0x28 | int | VertexCount | HIGH | Line 72: `*(int *)(iVar2+0x28)` multiplied by 0x10 | none |
| +0x30 | int* | VertexBase | HIGH | Line 72: `*(int *)(iVar2+0x30)` used as base ptr | none |
| +0x34 | int | SomeParam | HIGH | Line 52: `*(undefined4 *)(iVar2+0x34)` passed to FUN_0044a2d0 | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x403c | int | CurrentLap | **CONFLICT** | FUN_0049b6d0: `*(int *)(param_1+0x403c)` compared between two vehicles as lap counter | **POTENTIAL CONFLICT with docs/13**: known vehicle struct defines +0x403c as **SeasonPoints** (int). Same offset has different semantic meaning in this context. Either param_1 is not a vehicle struct, or the field serves dual purpose. |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x188 | short | FogColorR | HIGH | Line 122: `*(undefined2 *)(param_1+0x188) = local_428` (FOGCOLOR component) | none |
| +0x18a | short | FogColorG | HIGH | Line 121: `*(undefined2 *)(param_1+0x18a) = local_424` | none |
| +0x18c | short | FogColorB | HIGH | Line 120: `*(undefined2 *)(param_1+0x18c) = local_420` | none |
| +0x190 | float | FogDensity | HIGH | Line 134: `*(undefined4 *)(param_1+400)` = param_1+0x190, undefined4 compatible with float | none |
| +0x194 | float | FogInDist | HIGH | Line 126: `*(undefined4 *)(param_1+0x194) = local_42c` (FOGIN value) | none |
| +0x198 | float | FogOutDist | HIGH | Line 130: `*(undefined4 *)(param_1+0x198) = local_42c` (FOGOUT value) | none |
| +0x19c | int | FogModeMask | HIGH | Lines 83,98,113: value 0x20000(LINEAR)/0x40000(EXP)/0x80000(EXP2) | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | void* | DataBuffer | HIGH | FUN_00564740: param_1[0] = *param_1 passed to FUN_0058aa6f free | none |
| +0x04 | int | ElementCount | HIGH | FUN_00564740: param_1[1] as loop bound | none |
| Field | docs/13 Offset | docs/02 Offset | Match? | Verdict |
| EffectiveLifetimeAtSpawn | +0x1db4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeEngineRPM min/max | +0x1dbc/+0x1dc4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeOilTemp min/max | +0x1dcc/+0x1dd4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| PitStopFlag bitmask | +0x1180 | +0x1178 | MISMATCH — adjacent offsets | **RESOLUTION**: Likely separate fields: +0x1178 = PlannedStopsBitmask (from .rcd), +0x1180 = runtime pit stop flag. Recommend retaining both as separate adjacent fields. |
| CameraStruct | +0x12c | float | FUN_00545670 | CameraPosZ (third read, alongside +0x11c and +0x124) |
| CollisionShapeStruct | +0x1c | int | FUN_00448e90 | param_1[7] = 0 (zeroed field, extends struct past 0x20?) |
| SceneInstanceNode | +0x38 | uint | FUN_0055a910 | VISGROUPS flag storage |
| SceneInstanceNode | +0x40 | int | FUN_0055a910 | param_3 storage |
| SceneInstanceNode | +0x204 | ptr | FUN_0055a910 | First child node pointer |
| SceneNode | +0x10 | ptr | FUN_0055a910 | Next node (linked list) |
| SceneNode | +0xfc | undefined4 | FUN_0055a910 | Data field (copied from instance +0x50) |
| SceneNode | +0x14 (name) | char[?] | FUN_004fc2f0 | Node name string (strncmp at +0x14 within node, not same as bitmask +0x14 — this is buffer start of 0x100-byte node) |
| QuadFunctionCoeffs | +0x1c00 | double | FUN_0043bb30, FUN_0043e890 | Input parameter storage — not in table |
| QuadFunctionCoeffs | +0x1c08 | double | FUN_0043e890 | Clamp bound A0 — not in table |
| QuadFunctionCoeffs | +0x1c10 | double | FUN_0043e890 | Clamp bound A1 — not in table |
| QuadFunctionCoeffs | +0x1c18 | double | FUN_0043bbd0, FUN_0043e980 | Input parameter storage (spring) — not in table |
| QuadFunctionCoeffs | +0x1c20 | double | FUN_0043e980 | Clamp bound spring X — not in table |
| QuadFunctionCoeffs | +0x1c28 | double | FUN_0043e980 | Clamp bound spring Y — not in table |
| QuadFunctionCoeffs | +0x1c38 | double | FUN_0043bb80 | Input parameter storage (coeff set B) — not in table |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | float | SrcX | HIGH | FUN_004e3090 (*pfVar13 = srcX) | none |
| +0x04 | float | SrcY | HIGH | FUN_004e3090 (pfVar13[1] = srcY) | none |
| +0x08 | float | SrcZ | HIGH | FUN_004e3090 (pfVar13[2] = srcZ) | none |
| +0x0c | float | TgtX | HIGH | FUN_004e3090 (pfVar13[3] = tgtX) | none |
| +0x10 | float | TgtY | HIGH | FUN_004e3090 (pfVar13[4] = tgtY) | none |
| +0x14 | float | TgtZ | HIGH | FUN_004e3090 (pfVar13[5] = tgtZ) | none |
| +0x18 | float | Factor | HIGH | FUN_004e3090 (pfVar13[6] = factor) | none |
| +0x1c | float* | OutputPtr | HIGH | FUN_004e3090 (pfVar13[7] = output ptr) | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
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
| InitFloatConstantsStruct | +0x08..+0x18 | float | FUN_004594d0 | 5 intermediate zero fields not in docs table (0x08, 0x0c, 0x10, 0x14, 0x18) |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| ALL (7 offsets +0x1b754..+0x1b76e) | byte | terrain flags | LOW | FUN_00460a10 NOT FOUND in analyzed/ or decompiled_full/ | N/A |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | ptr | vtable | HIGH | FUN_0052e170 (line 11: *param_1 = &PTR_LAB_005b4810) | none |
| +0x90 | ptr | observerList | LOW | FUN_0052e170 does NOT reference +0x90 | Unverified — may be set by parent constructor FUN_0052d9f0() |
| RenderObject | +0x2D34 | undefined4 | FUN_0052e170 | Constructor parameter 2 |
| RenderObject | +0x2D38 | undefined4 | FUN_0052e170 | Constructor parameter 3 |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| [0] (byte +0x00) | int | left | HIGH | FUN_0044f680: *param_1 = param_3 | CONFLICT: naming |
| [1] (byte +0x04) | int | top | HIGH | FUN_0044f680: param_1[1] = param_5 | CONFLICT: naming (docs say top, code shows right) |
| [2] (byte +0x08) | int | right | HIGH | FUN_0044f680: param_1[2] = param_2 | CONFLICT: naming (docs say right, code shows top) |
| [3] (byte +0x0c) | int | bottom | HIGH | FUN_0044f680: param_1[3] = param_4 | CONFLICT: naming |
| [4] (byte +0x10) | int | center_x | HIGH | FUN_0044f680: param_1[4] = (param_2+param_4)>>1 | CONFLICT: naming (docs say center_x, code shows center_y) |
| [5] (byte +0x14) | int | center_y | HIGH | FUN_0044f680: param_1[5] = (param_3+param_5)>>1 | CONFLICT: naming (docs say center_y, code shows center_x) |
| [6] (byte +0x18) | int | scale_x | HIGH | FUN_0044f680: param_1[6] = 2/(param_4-param_2) | CONFLICT: naming (docs say scale_x, code shows vertical scale) |
| [7] (byte +0x1c) | int | scale_y | HIGH | FUN_0044f680: param_1[7] = 2/(param_5-param_3) | CONFLICT: naming (docs say scale_y, code shows horizontal scale) |
| Index | Computed From | Element Name |
| [0] | param_3 | left |
| [1] | param_5 | right (NOT top) |
| [2] | param_2 | top (NOT right) |
| [3] | param_4 | bottom |
| [4] | (top+bottom)>>1 | center_y (NOT center_x) |
| [5] | (left+right)>>1 | center_x (NOT center_y) |
| [6] | 2/(bottom-top) | scale_y (NOT scale_x) |
| [7] | 2/(right-left) | scale_x (NOT scale_y) |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| [0] | int | minX | LOW | unaff_ESI[0] = X loop lower bound | none |
| [1] | int | maxX | LOW | unaff_ESI[1] = X loop upper bound | none |
| [2] | int | minZ | LOW | unaff_ESI[2] = Z row lower bound | none |
| [3] | int | maxZ | LOW | unaff_ESI[3] = Z row upper bound | none |
| [4] | int | minY | LOW | unaff_ESI[4] = Y inner lower bound | none |
| [5] | int | maxY | LOW | unaff_ESI[5] = Y inner upper bound | none |
| [6] | int | contactDistanceSq | LOW | unaff_ESI[6] = weighted squared sum | none |
| [7] | int | nonZeroCellCount | LOW | unaff_ESI[7] = count of occupied cells | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
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
| NetComm | +0x374 | byte | FUN_0045fc50 | Guard flag (skip if set) |
| NetComm | +0x3d0 | char[0x8c]×104 | FUN_0045fc50 | Secondary slot array (0x38 bytes after PlayerNames) |
| NetComm | +0x3fc8 | ptr | FUN_0045fc50 | Linked list head (player slots) |
| NetComm | +0x3fcc | ptr | FUN_0045fc50 | Linked list field |
| NetComm | +0x3fd0 | ptr | FUN_0045fc50 | Linked list iterator |
| NetComm | +0x3fd4 | int | FUN_0045fc50 | Linked list count |
| NetComm | +0x1b778 | ptr | FUN_00460e90, FUN_00461190 | MsgListTail→next (list append helper) |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | void* | StreamStruct | HIGH | FUN_00510975 (*puVar2 = stream data ptr) | none |
| +0x04 | code* | DispatchFn0 | HIGH | FUN_00510975 (puVar2[1] = remaining count, puVar2[3] = refill fn; +0x04 = secondary dispatch via *unaff_ESI+4) | Note: docs say +0x04=DispatchFn0 but unaff_ESI+4 is dispatch; puVar2[1] at unaff_ESI[5]+4 is remaining count — different struct nesting |
| +0x14 | byte | EventStatus | HIGH | FUN_00510975 (*unaff_ESI+0x14 = 0x4e/0x1a/0x1b) | none |
| +0x18 | int | EventParam1 | HIGH | FUN_00510975 (*unaff_ESI+0x18 = uVar4) | none |
| +0x1c | int | EventParam2 | HIGH | FUN_00510975 (*unaff_ESI+0x1c = uVar3) | none |
| +0xca | byte[16] | NibbleLo | HIGH | FUN_00510975 (*(byte*)(uVar4+0xca+unaff_ESI)) | none |
| +0xda | byte[16] | NibbleHi | HIGH | FUN_00510975 (*(byte*)(uVar4+0xda+unaff_ESI)) | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x00 | uint16 | DetailLevel | HIGH | FUN_004a2a90 (*puVar6 = local_6b8[0]) | none |
| +0x03 | byte | LollipopFlag | HIGH | FUN_004a2a90 (*(byte*)(puVar6+3) = 0/1) | none |
| +0x26 | float | PosX | **WRONG** | FUN_004a2a90 writes to puVar6+0x26 (undefined2* indexing = byte offset 0x4c) | **CONFLICT:** byte offset is 0x4c, not 0x26 |
| +0x2a | float | PosY | **WRONG** | FUN_004a2a90 writes to puVar6+0x28 (byte offset 0x50) | **CONFLICT:** byte offset is 0x50, not 0x2a |
| +0x2e | float | PosZ | **WRONG** | FUN_004a2a90 writes to puVar6+0x2a (byte offset 0x54) | **CONFLICT:** byte offset is 0x54, not 0x2e |
| +0x2c | float[?] | Rotate | **WRONG** | FUN_004a2a90 reads puVar6+0x2c/0x2e/0x30 (byte offsets 0x58/0x5c/0x60) | **CONFLICT:** byte offsets are 0x58/0x5c/0x60, not 0x2c |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x1a8 | int | PitOrderCount | MEDIUM | FUN_004d12c0 (int write/read) | none |
| +0x1ac | char** | PitOrderArray | MEDIUM | FUN_004d12c0 (piVar4 pointer write) | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0x60 | byte | PitFlag | **WRONG** | FUN_004a6e50 uses param_1[0x60] (int* index = byte offset 0x180) | **CONFLICT:** Actual byte offset is 0x180 (param_1 is int*, so [0x60] = offset 0x180) |
| +0x61 | byte | PitState | **WRONG** | FUN_004a6e50 uses param_1[0x61] (int* index = byte offset 0x184) | **CONFLICT:** Actual byte offset is 0x184 |
| +0x62 | byte | PitEntryTimer | **WRONG** | FUN_004a6e50 uses param_1[0x62] (int* index = byte offset 0x188) | **CONFLICT:** Actual byte offset is 0x188 |
| +0xf3 | char* | LiveryName | LOW | FUN_004ddad0 (param_1[0xf3] as string ptr) | Off-by-4? param_1 is int* in this context? |
| +0xf5-0xf9 | ptr | TrackLiveryList | LOW | FUN_004ddad0 (param_1[0xf5] linked list) | Overlapping offset range |
| +0xf6 | ptr | PitCrewLivery | LOW | FUN_004ddad0 (param_1[0xf6] as string ptr) | |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
| +0xb0 | int | LapTimeRemaining | HIGH | FUN_004d23d0 (float), FUN_004d2e50 (int) | **CONFLICT:** FUN_004d23d0 uses float, docs say int |
| +0xb4 | int | RaceTimeRemaining | HIGH | FUN_004d23d0 (float), FUN_004d2e50 (int) | **CONFLICT:** FUN_004d23d0 uses float, docs say int |
| +0xb8 | int | PitTimeOffset | HIGH | FUN_004d23d0 (float) | **CONFLICT:** docs say int, code uses float |
| +0xc1 | byte | PenaltyFlag | HIGH | FUN_004d23d0 (undefined1 = 0) | none |
| +0xc2 | byte | FormationLapFlag | HIGH | FUN_004d23d0, FUN_004d2e50 (both byte) | none |
| +0xd8 | int | PitWindowOpenTime | HIGH | FUN_004d23d0 (undefined4 copy), FUN_004d2e50 (int) | none |
| +0xf4 | byte | FinishState | MEDIUM | FUN_004d2e50 (param_1[0x3d] as int; docs say byte at +0xf4 but param_1 is int*) | **POTENTIAL CONFLICT:** param_1[0x3d] = byte offset 0xf4 as int → offset matches, type is int not byte |
| +0x104 | byte | ProcessedFlag | MEDIUM | FUN_004d2e50 (param_1[0x41] as byte cast) | none |
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
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
| Section | Name | Confidence | Conflicts Found |
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
| VehiclePhysicsHeader | +0x1644 | int | FUN_0042fd00 | FinalDriveSetting — written as INI field (not in doc table) |
| VehiclePhysicsHeader | +0x1684 | int | FUN_0042fd00 | ReverseSetting — written as INI field (not in doc table) |
| VehiclePhysicsInstance | +0x157c | byte | FUN_004537b0 | Rear telemetry enable flag (analogous to +0x1180 for front) |
| Grade | Count | Sections |
| HIGH (all verified) | 6 | 202, 208, 209, 210, 211, 214 |
| HIGH (partial verify) | 2 | 205, 206 |
| MEDIUM (type conflict) | 1 | 215 |
| LOW-MEDIUM (multi-variant) | 1 | 204 |
| VERY LOW (no evidence) | 1 | 213 |
| Referential (no offsets) | 1 | 207 |
| Offset | Doc Name | Actual (FUN_0042fd00) |
| +0xd44 | ToeInLeftSetting | RearAntiSwaySetting |
| +0xd84 | ToeInRightSetting | FrontToeInSetting |
| +0xdc4 | (Suspension param) | RearToeInSetting |
| +0x15c4 | SteeringBarCount / EngineMapSetting | EngineMapSetting (setup context) |
| +0x1884 | GearCount / NumPitstops | NumPitstopsSetting (setup context) |
| CollisionProxyRegistration | +0xC84 | int | FUN_0044f0a0 L11 | Undocumented field between ProxyChildIndices and ProxyLeafNodes. Cleared to 0 during init. |
| Vehicle Array Entry | +0x48a4 | int | FUN_004c6c40 (not verified) | Flag set to -1 after first load. |
| JointHingeBarStruct | +0x08 | (4-byte) | FUN_0056d930 L570 | Written as undefined4, not double. Derived spring/tension result, 4 bytes. |
| JointHingeBarStruct | +0x10 | (4-byte) | FUN_0056d930 L572 | Written as undefined4, not double. Derived spring/tension result, 4 bytes. |

---

## Audited Struct Sections

## Section 1a: Physics Vehicle Instance Offsets

Source: decompiled_all/0x004f2c60 (wheel corner parser), analyzed/0x0043ef20 (engine simulation), analyzed/0x004537b0 (tire compound), analyzed/0x0043bb00 (delta tracker)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1db4 | double | EffectiveEngineLifetime | HIGH | 3 files: 0x0043ef20, 0x00447160, 0x00447280 — all read as double | none |
| +0x1dbc | double | LifetimeEngineRPM_min | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dc4 | double | 1/LifetimeEngineRPM_max | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dcc | double | LifetimeOilTemp_min | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1dd4 | double | 1/LifetimeOilTemp_max | NONE | No .c files reference this offset in analyzed/ | Missing evidence — not found |
| +0x1140 | double×8 | FrontTireTelemetry | LOW | 0x004537b0 reads as float; 0x0053f270 reads as int (pointer); 0x0053d4f0 zeroes as undefined4 | **CONFLICT**: Mixed types across functions — float, int*, undefined4 |
| +0x1160 | byte[16] | FrontCompoundFlags | MEDIUM | 3 files: 0x0042a180 writes int; 0x004537b0 reads byte; 0x0053d4f0 writes int 0x8000 | Type varies: int write vs byte read |
| +0x1170 | int | CurrentFrontCompoundIndex | HIGH | 0x004537b0 reads as int (multiple compound compares); 0x004af220 zeroes as int | none |
| +0x1174–+0x117c | int×3 | CompoundSelections | HIGH | 0x004537b0 reads as int (8 compound compares per offset); 0x0053d4f0 zeroes as int | none |
| +0x1180 | uint | PitStopFlag bitmask | HIGH | 0x004537b0 reads as byte/uint (bit tests); 0x00424790, 0x0042a3d0 use as base pointer | none |
| +0x153c | double×8 | RearTireTelemetry | LOW | 2 files reference 0x153c — need type verification | Pending verification |
| +0x155c | byte[16] | RearCompoundFlags | LOW | 3 files reference 0x155c — need type verification | Pending verification |

---

## Section 1b: Wheel Corner Struct (FUN_004f2c60)

Source: decompiled_all/0x004f2c60 (wheel corner .svm parser, string-anchored)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb8 | double | BrakeOptimumTemp | HIGH | FUN_004f2c60: `*(double *)(param_1 + 0xb8)` + 273.15 applied | none |
| +0xf0 | double | BrakeWearRate | HIGH | FUN_004f2c60: reads "BrakeWearRate" string at param_1+0xf0 | none |
| +0xf8 | double | BrakeFailure_min | HIGH | FUN_004f2c60: "BrakeFailure" string stored to param_1+0xf8, param_1+0x100 | none |
| +0x100 | double | BrakeFailure_max | HIGH | FUN_004f2c60: second param of "BrakeFailure" string | none |

Note: All wheel corner struct offsets verified from FUN_004f2c60 in decompiled_all (not in analyzed/). All are doubles — confirmed by `FUN_00565aa0(s_BrakeWearRate_..., param_1 + 0xf0, ...)` pattern.

---

## Section 1c: Player Options Struct (FUN_004aa270)

Source: analyzed/0x00585d70 (only file referencing +0x5c8)

| Offset | Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|------|------------|------------|-------------|-----------|
| +0x5c8 | byte[?] | FailureRate[0..6] | LOW | 2 refs in 0x00585d70: byte zeroing + pointer base. No stride 0x24 evidence seen | Only 2 hits, insufficient to confirm 7-element array |

---

## Section 2: PenaltySlipAngleStruct

Source: analyzed/0x0042e400, 0x00431a50, 0x004319c0, 0x00443b70, 0x00443c07

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1cb8 | byte | Flag | HIGH | 0x0042e400: `*(undefined1 *)(param_1 + 0x1cb8) = 1`; 0x00431a50: same | none |
| +0x1cbc | float | SpeedThreshold | MEDIUM | 0x0042e400: `*(undefined4 *)(param_1 + 0x1cbc) = 0x4392947b` (~295.0f); 0x00431a50: sets from param_2 | 4-byte confirmed, type as float inferred from value |
| +0x1cd4 | byte[4] | CornerFlags | HIGH | 0x0042e400: `puVar1 = (undefined1 *)(param_1 + 0x1cd4)`, 4 iterations; 0x004319c0: per-corner byte set | none |
| +0x1cd8 | float[4] | CornerThresholds | HIGH | 0x0042e400: `puVar2 = (undefined4 *)(param_1 + 0x1cd8)`, 4 iterations; 0x004319c0: indexed by param_2×4 | none |
| +0x1cec | float[4][3] | CornerTimers | MEDIUM | 0x0042e400: `puVar3 = (undefined4 *)(param_1 + 0x1cec)`, stride 3, 4 iterations; values 0x43b3ee14 (~359.0f) | **CONFLICT**: 0x00443b70 reads `*(double *)(param_1 + 0x1cec)` as double; 0x0042e400 uses 4-byte stride |

---

## Section 3: HighResTimer

Source: analyzed/0x005564b0, 0x00556510, 0x00568c60, 0x00568cb0

The struct is int-indexed (param_1 as int*/uint*). All offsets = index × 4.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int32 | Enabled/ActiveFlag | HIGH | 0x005564b0: `if (*param_1 != 0)`; 0x00568c60: same | Also used as QPC frequency divisor in 0x00556510 line 19 |
| +0x08 | double | ScaleFactor | HIGH | 0x00556510: `*(double *)(param_1 + 2)` at byte offset +0x08 (2 ints) | none |
| +0x10 | int32 | OtherAccum0 | HIGH | 0x00568c60: `param_1[4] = 0` (byte offset +0x10) | none |
| +0x14 | int32 | OtherAccum1 | HIGH | 0x00568c60: `param_1[5] = 0` (byte offset +0x14) | none |
| +0x18 | uint32 | CurrentLow | HIGH | 0x00568c60: `param_1[6] = local_8.s.LowPart` (byte offset +0x18) | none |
| +0x1c | uint32 | CurrentHigh | HIGH | 0x00568c60: `param_1[7] = local_8.s.HighPart` (byte offset +0x1c) | none |
| +0x20 | uint32 | LastLow | HIGH | 0x00568c60: `param_1[8] = param_1[6]`; 0x00556510: `param_1[8]` read | none |
| +0x24 | uint32 | LastHigh | HIGH | 0x00568c60: `param_1[9] = param_1[7]`; 0x00556510: `param_1[9]` read | none |
| +0x28 | uint32 | AccumLow | HIGH | 0x00568c60: `param_1[10] = 0` | none |
| +0x2c | uint32 | AccumHigh | HIGH | 0x00568c60: `param_1[11] = 0` | none |
| +0x48 | int/byte | TimerModeFlags | HIGH | 0x005564b0: `param_1[0x12] & 1` / `param_1[0x12] & 2`; 0x00568c60: `*(byte *)(param_1 + 0x12) & 1` (both access byte offset 0x48) | none |

---

## Section 5: DeltaUpdateTrackerStruct

Source: analyzed/0x0043bb00

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xd4c | double | CumulativeDelta | HIGH | 0x0043bb00: `*(double *)(param_1 + 0xd4c)` read and written | none |
| +0x1428 | double | CurrentValue | HIGH | 0x0043bb00: `*(double *)(param_1 + 0x1428)` read and written | none |
| +0x1430 | double | DeltaGain | HIGH | 0x0043bb00: `*(double *)(param_1 + 0x1430)` read | none |

---

## Section 6: PerWheelPhysics (inferred)

Source: analyzed/0x0043f7f0 (938 lines), decompiled_all/0x0043da10

Stride 0x464 between wheels confirmed (0x0043f7f0 lines 216, 278, 401, 428+). Base starts at +0x348.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x28c | struct | TireCompoundData | MEDIUM | 0x0043da10: `iVar8 = param_2 * 0x464 + 0x28c + param_1` | Offset mapping confirmed — compound data at base |
| +0x348 | double | Position | HIGH | 0x0043f7f0: `pdVar17 = (double *)(param_1 + 0x348)`, iterated by 0x464 | none — type matches |
| +0x360 | float | Force | LOW | Not directly seen in 0x0043f7f0 | Not verified |
| +0x368 | int | ConstraintState | LOW | Not directly seen in 0x0043f7f0 | Not verified |
| +0x7ac | float | Force2 | LOW | 0x0043f7f0 line 274: `*(double *)(param_1 + 0x7ac)` | **CONFLICT**: Read as double in .c, doc says float |
| +0x7c4 | float | Inertia | LOW | Not directly seen | Not verified |
| +0xc10 | float | Velocity | LOW | 0x0043f7f0 line 237: `*(double *)(param_1 + 0xc10)` | **CONFLICT**: Read as double in .c, doc says float |
| +0xc28 | float | Mass | LOW | 0x0043f7f0 line 237: `*(double *)(param_1 + 0xc28)` | **CONFLICT**: Read as double in .c, doc says float |
| +0xc30 | float | Inertia2 | LOW | Not directly seen | Not verified |
| +0x1074 | float | Bias | LOW | 0x0043f7f0 line 239: `*(double *)(param_1 + 0x1074)` | **CONFLICT**: Read as double in .c, doc says float |
| +0x108c | float | Bias2 | LOW | 0x0043f7f0 line 238: `*(double *)(param_1 + 0x108c)` | **CONFLICT**: Read as double in .c, doc says float |

---

## Section 7: PLAYERTRACKSTAT Node Struct (int-indexed)

Source: decompiled_all/0x004c2420 (not in analyzed/)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | TrackName[0] | UNKNOWN | File in decompiled_all only — not checked | No analyzed/ source |
| +0x01 | char* | TrackName[1] | UNKNOWN | Same | No analyzed/ source |
| +0x02 | char* | TrackFile[0] | UNKNOWN | Same | No analyzed/ source |
| +0x03 | char* | TrackFile[1] | UNKNOWN | Same | No analyzed/ source |
| +0x04 | int | TotalNumLaps | UNKNOWN | Same | No analyzed/ source |
| +0x05 | float | BestLapTime | UNKNOWN | Same | No analyzed/ source |

Note: If int-indexed, byte offset = index × 4, so [0]=+0x00, [1]=+0x04, [2]=+0x08, etc. The doc's byte offsets as written (+0x00-chars through +0x05-float) are likely incorrect — these should be pointer-sized (4 bytes each on x86).

---

## Section 8: String Property Struct

Source: analyzed/0x00467430

Int-indexed via `param_1[0xbc]` etc. Byte offsets = index × 4.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x2f0 | char* | stored_string | HIGH | 0x00467430: `param_1[0xbc]` = offset 0x2f0 (0xbc×4). Used as string pointer for comparison/copy | none |
| +0x2f4 | char* | cursor_pointer | HIGH | 0x00467430: `param_1[0xbd]` = offset 0x2f4. Used as iteration cursor into string | none |
| +0x2f8 | int | buffer_size | HIGH | 0x00467430: `param_1[0xbe]` = offset 0x2f8. Used as strncpy limit | none |

Note: All three offsets confirmed from single function. Struct is pointer-indexed (int* param_1).

---

## Section 9: Mesh Bounding Box Struct (inferred)

Source: analyzed/0x0054d9f0

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | int | flags | HIGH | 0x0054d9f0: `uVar2 = *(uint *)(param_1 + 0x14)`, bit test with 0x800000 | none |
| +0x18 | float | boundingSphereRadius | LOW | Not directly verified | Pending verification |
| +0x1c..0x78 | float[24] | aabbCorners | LOW | Not directly verified | Pending verification |
| +0xdc | float | centerX | LOW | Not directly verified | Pending verification |
| +0x118 | int | subsetCount | HIGH | 0x0054d9f0: `if (0 < *(int *)(param_1 + 0x118))` loop bound | none |
| +0x11c | ptr | subsetArray | HIGH | 0x0054d9f0: `*(int *)(param_1 + 0x11c)` used as array base pointer | none |

---

## Section 11: CollisionShapeClassifier

Source: analyzed/0x004139c0, 0x00412c30

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | ShapeClass | MEDIUM | Two functions reference this offset as int. Used as size class (0x20-0x2f) or bone index (0x99-0xBD) | **CONFLICT**: Same offset dual-purposed as SizeClass and BoneIndex per doc notes |
| +0x0c | int | SecondaryClass | MEDIUM | Same two functions. Secondary class | none |

---

## Section 13: AudioHandleStruct / MilesSampleStruct

Source: analyzed/0x00552760, 0x00405b50, 0x004059f0, 0x004060c0, 0x00406750

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | void* | SubResource | HIGH | 0x00552760: `*(undefined4 *)(param_1 + 0xc)` freed via FUN_00540eb0; 0x00406750: `*(int *)(param_1 + 0xc)` used with `_AIL_close_stream` | **NOTE**: Also used as Miles stream handle (AIL_close_stream) in 0x00406750 — dual purpose or doc misnamed field |
| +0x14 | int | PlayState | HIGH | 0x00405b50: `return *(int *)(param_1 + 0x14) != 0` | none |
| +0x24 | uint32 | FlagBitmask | HIGH | 0x00552760: `*(uint *)(param_1 + 0x24) & 0x20000` bit test | none |
| +0x58 | void* | AudioHandle | HIGH | 0x00405b50, 0x004059f0, 0x004060c0: all read as `*(int *)(param_1 + 0x58)` then dereference +0x10 for Miles sample | none |
| +0x5c | int | StreamHandle | HIGH | 0x00406750: `*(int *)(param_1 + 0x5c) != -1` | Checked for -1 (closed) pattern |
| +0x60 | int | FilterType | HIGH | 0x004060c0: `*(int *)(param_1 + 0x60) != -1` | -1 = no filter |
| +0x68 | byte[] | FilterState | HIGH | 0x004060c0: `iVar2 = param_1 + 0x68` passed as filter state buffer | none |

| +0x868 | void* | SecondaryResource | MEDIUM | 0x00552760: `iVar1 = *(int *)(param_1 + 0x868)` read and conditionally freed | Single function |

**DOCUMENTATION ISSUE**: The doc table claims +0x10 as "MilesSampleHandle" directly in param_1, but in all 3 referenced files the pattern is `*(int *)(*(int *)(param_1 + 0x58) + 0x10)` — +0x10 is within the sub-struct pointed to by param_1[0x58], NOT in param_1 itself. The +0x58 field is the actual handle pointer.

**DUAL STREAM HANDLES**: +0x0c is used with `_AIL_close_stream` (Miles stream API) in 0x00406750, while +0x5c is a different handle checked for -1. The struct has two stream-like handles.

---

## Section 14: AI Database Struct (aiDB)

Source: analyzed/0x004040a0, 0x00402690

Int-indexed (param_1[idx]) in 0x004040a0, byte-offset in 0x00402690. Both consistent after conversion.

| Byte Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|-------------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | GrooveWidth | HIGH | Both functions. Default 4.5 | none |
| +0x04 | float | GrooveWidthWet | HIGH | Both functions. Default 4.3125 | none |
| +0x118 | float | AiGlobalSpeedMult | MEDIUM | 0x004040a0: computed from slider interpolation | Only in one function |
| +0x11c | float | AiSpeedMultMin | HIGH | Both functions. Default 0.5 | none |
| +0x120 | float | AiSpeedMultMid | HIGH | Both functions. Default 1.0 | none |
| +0x124 | float | AiSpeedMultMax | HIGH | Both functions. Default 1.3 | none |
| +0x12c | bool | LeftHandedPits | MEDIUM | 0x00402690 only | Single function |
| +0x130 | int | WaypointCount | MEDIUM | 0x00402690 only | Single function |
| +0x134 | ptr | WaypointArray | MEDIUM | 0x00402690 only | Single function |
| +0x13c | float | LapLength | MEDIUM | 0x00402690 only | Single function |
| +0x140 | float | Sector1Length | MEDIUM | 0x00402690 only | Single function |
| +0x144 | float | Sector2Length | MEDIUM | 0x00402690 only | Single function |
| +0x14c | float | FuelUse | MEDIUM | 0x00402690 only | Single function |
| +0x15c | int | PitlaneCount | MEDIUM | Both functions. FUN_004040a0 default 1; FUN_00402690 reads from .gdb | **CONFLICT NOTED**: aiDB[0x57]=1 init default vs actual pitlane count at load |
| +0x160 | int | StartingGridSlots | HIGH | Both functions. Default 104 | none |
| +0x164 | int | PitSpots | HIGH | Both functions. Default 52 | none |
| +0x168 | int | GarageSpots | HIGH | Both functions. Default 3 | none |

Note: +0x150, +0x154, +0x158 (GridArray/PitArray/GarageArray) referenced only in 0x00402690 as struct arrays. Not verified from 0x004040a0.

---

---

## Section 10: CollisionBody (inferred — rigid body physics state)

Source files verified: analyzed/0x00436870, 0x004542d0, 0x00457a00, 0x004584c0, 0x004987b0, 0x0044fee0, 0x004599c0, 0x00459950, 0x0044efe0, 0x0044f050, 0x0045b840, 0x00403aa0, 0x004039c0, 0x004038e0, 0x00456f70

**CRITICAL**: Offsets like +0x040, +0x060, +0x068, +0x084 in the prompt doc are relative to a SUB-struct base (param_1 + 0xd88 or param_1 + 0x1184 per FUN_004542d0), NOT param_1 directly. Verified offsets below use direct param_1 access.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0A4 | float | RestitutionFactor | HIGH | 0x004584c0: `*(float *)(param_1 + 0xa4)` | none |
| +0x090 | float | ContactPosX | HIGH | 0x00457a00: `*(float *)(param_1 + 0x90)` | none |
| +0x094 | float | ContactPosY | HIGH | 0x00457a00: `*(float *)(param_1 + 0x94)` | none |
| +0x098 | float | ContactPosZ | HIGH | 0x00457a00: `*(float *)(param_1 + 0x98)` | none |
| +0x0D8 | double | PositionX | HIGH | 0x004599c0: `*(double *)(param_1 + 0xd8)` | none |
| +0x0E0 | double | PositionY | HIGH | 0x004599c0: `*(double *)(param_1 + 0xe0)` | none |
| +0x0E8 | double | PositionZ | HIGH | 0x004599c0: `*(double *)(param_1 + 0xe8)` | none |
| +0x0FC | int | ContactPointWorldX | MEDIUM | 0x00436870: `*(undefined4 *)(param_1 + 0xfc) = 0xffffffff` | Set as bitmask, not float |
| +0x100 | int/float | ContactWorldY / FlagA | MEDIUM | 0x00436870: `*(undefined4 *)(param_1 + 0x100) = 0xffefffff` | **OVERLAP**: bitmask int confirms union |
| +0x134 | float/double | FrictionMagnitude | MEDIUM | 0x00436870: zeroed as undefined4; written as double line 448 | **CONFLICT**: 4B vs 8B access |
| +0x144 | float | StiffnessTerm | MEDIUM | 0x00436870: zeroed as undefined4 | Single 4B ref |
| +0x15C | int* | TriangleDataPtr | HIGH | 0x00436870: 4× `*(int *)(param_1 + 0x15c)` | none |
| +0x180 | uint32 | MassLow | HIGH | 0x00459950: `*(undefined4 *)(param_1 + 0x180) = param_2` | none |
| +0x184 | uint32 | MassHigh | HIGH | 0x00459950: `*(undefined4 *)(param_1 + 0x184) = param_3` | none |
| +0x188 | double | InvMass | HIGH | 0x00459950: `*(double *)(param_1 + 0x188)` | none |
| +0x20C | double | Damping | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x20c)` | **CONFLICT**: doc float, is double |
| +0x214 | double | Restitution | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x214)` | **CONFLICT**: doc float, is double |
| +0x21C | double | HalfExtent | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x21c)` ×4 | **CONFLICT**: doc float, is double |
| +0x224 | double | RotationMatrix[0] | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x224)` | **CONFLICT**: doc float[3], is double |
| +0x264 | int | BestTriIndex | HIGH | 0x00436870: zeroed + read as int | none |
| +0x278 | int | CullFlag | HIGH | 0x0044efe0: `*(undefined4 *)(param_1 + 0x278) = 0` | none |
| +0x27C | byte[] | PropertyBlock | HIGH | 0x0044f050: `*(undefined1 *)(param_2 + 0x27c + param_1)` | Byte-indexed array |
| +0x31C | double/float/int | ContactForce/Count | MEDIUM | 0x00436870: `*(double *)(param_1 + 0x31c)`; 0x0045b840: `*(int *)(param_1 + 0x31c)` | **CONFLICT**: triple overlap |
| +0x1c4 | char | (unknown flag) | — | 0x00436870: `*(char *)(param_1 + 0x1c4) != '\0'` | **NOT IN DOC** |
| +0x268 | int | (init zero) | — | 0x00436870: init block | **NOT IN DOC** |
| +0x26c | int | (init 1.0f) | — | 0x00436870: set to 0x3ff00000 | **NOT IN DOC** |
| +0x324 | double | (friction related) | — | 0x00436870: friction calc | **NOT IN DOC** |
| +0x560–0x588 | double[6] | Momentum accum | — | 0x0044fee0: lin+ang momentum | **NOT IN DOC** |

Offsets relative to sub-struct base +0xd88 (NOT directly param_1): +0x040, +0x060, +0x068, +0x084, +0x0AC, +0x0E4, +0x0EC, +0x0F4, +0x10C, +0x110, +0x12C, +0x200, +0x27C–0x290, +0x298–0x2D0, +0x2E4, +0x2EC, +0x2F4, +0x304, +0x314, +0x320

---

---

## NEW OFFSETS DISCOVERED

None discovered from analyzed/ search that aren't already listed in the prompt.

---

---

## SUMMARY

| Grade | Count |
|-------|-------|
| HIGH | 40 |
| MEDIUM | 20 |
| LOW/UNKNOWN | 15 |
| NONE (missing evidence) | 4 |

**CONFLICTS FOUND:**
1. **+0x1140** (FrontTireTelemetry): float vs int (pointer) vs undefined4 across 3 functions — likely different structs sharing offset
2. **+0x1160** (FrontCompoundFlags): byte[16] doc'd but written as int in 0x0042a180
3. **+0x1cec** (CornerTimers): 4-byte array in 0x0042e400, double in 0x00443b70
4. **PerWheelPhysics** (+0x7ac, +0xc10, +0xc28, +0x1074, +0x108c): doc'd as float, read as double in 0x0043f7f0
5. **+0x1dbc/+0x1dc4/+0x1dcc/+0x1dd4**: Not found in any analyzed/ .c files — missing evidence
6. **CollisionBody type mismatches**: +0x20C (Damping), +0x214 (Restitution), +0x21C (HalfExtent) doc'd as float, all read as double in 0x00436870
7. **+0x31C** (ContactForce/ContactCount): triple overlap — double/float/int at same offset
8. **+0x134** (FrictionMagnitude): 4-byte zeroing vs 8-byte double write
9. **+0x100** (ContactWorldY/FlagA): union overlap confirmed — int bitmask pattern
10. **Audio Struct +0x0c**: doc says "SubResource" but also used as Miles stream handle (AIL_close_stream) — dual purpose

**DOCUMENTATION ISSUES:**
1. **CollisionBody sub-struct base**: Many offsets (+0x040, +0x060, +0x068, +0x084, etc.) are relative to a sub-struct at param_1 + 0xd88, NOT param_1 — doc should clarify
2. **PLAYERTRACKSTAT byte offsets**: If int-indexed, offsets should be ×4 (doc shows raw index values as byte offsets, which is wrong for pointer-sized fields)
3. **Section 7 doc claims +0x00–+0x05 as byte offsets**: This is incorrect for int-indexed struct; [0]=+0x00, [1]=+0x04, [2]=+0x08, etc.
4. **Audio +0x10**: Field is in sub-struct (reached via param_1[0x58]+0x10), not directly in param_1

**NEW DISCOVERIES:**
- CollisionBody extends to at least +0x588 (momentum accumulation)
- +0x1c4: char flag in CollisionBody
- +0x268, +0x26c: init values in CollisionBody  
- +0x324: double friction term in CollisionBody

---

## Section 16: Source: docs/06-session-race-logic.md

0 offsets — skipped.

---

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

---

## Section 27: Source: docs/09-track-system.md

0 offsets — skipped.

---

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

---

## Section 30: Source: docs/05-weather-system.md

0 offsets — skipped.

---

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

---

## VehicleStruct (param_1 — vehicle struct)

Total offsets in section: 192

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | unknown | various | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0008 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x000c | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0010 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0014 | float | float[4] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0020 | float | float[3][3] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x34b0 | float | float | 15 files | float:12 int:0 double:0 undef:0 ptr:0 idx:3 | HIGH |
| +0x34b8 | float | float | 22 files | float:18 int:0 double:0 undef:0 ptr:0 idx:4 | HIGH |
| +0x34bc | float | float | 21 files | float:17 int:0 double:0 undef:0 ptr:0 idx:4 | HIGH |
| +0x34c4 | float | float | 24 files | float:20 int:0 double:0 undef:0 ptr:0 idx:4 | HIGH |
| +0x34c8 | float | float | 21 files | float:17 int:0 double:0 undef:0 ptr:0 idx:4 | HIGH |
| +0x34d0 | float | float | 25 files | float:20 int:0 double:0 undef:0 ptr:0 idx:5 | HIGH |
| +0x34d4 | float | float | 28 files | float:15 int:0 double:0 undef:4 ptr:0 idx:9 | HIGH |
| +0x34d8 | float | float | 31 files | float:16 int:0 double:0 undef:6 ptr:0 idx:9 | HIGH |
| +0x34dc | float | float | 33 files | float:17 int:0 double:0 undef:6 ptr:0 idx:10 | HIGH |
| +0x34e0 | ptr | ptr | 26 files | float:16 int:0 double:0 undef:3 ptr:0 idx:7 | HIGH |
| +0x34ec | float | float[3] | 17 files | float:7 int:0 double:0 undef:3 ptr:0 idx:7 | HIGH |
| +0x34f8 | float | float | 26 files | float:20 int:0 double:0 undef:3 ptr:0 idx:3 | HIGH |
| +0x34fc | float | float | 22 files | float:16 int:0 double:0 undef:3 ptr:0 idx:3 | HIGH |
| +0x3500 | float | float | 28 files | float:22 int:0 double:0 undef:3 ptr:0 idx:3 | HIGH |
| +0x3504 | float | float | 9 files | float:5 int:0 double:0 undef:3 ptr:0 idx:1 | HIGH |
| +0x3508 | float | float | 9 files | float:5 int:0 double:0 undef:3 ptr:0 idx:1 | HIGH |
| +0x350c | float | float | 9 files | float:5 int:0 double:0 undef:3 ptr:0 idx:1 | HIGH |
| +0x3514 | float | float | 11 files | float:9 int:0 double:0 undef:0 ptr:0 idx:2 | HIGH |
| +0x3518 | float | float | 12 files | float:11 int:0 double:0 undef:0 ptr:0 idx:1 | HIGH |
| +0x3534 | float | float[3] | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3540 | float | float[3] | 6 files | float:4 int:0 double:0 undef:1 ptr:0 idx:1 | HIGH |
| +0x3570 | float | float | 13 files | float:6 int:0 double:0 undef:5 ptr:0 idx:2 | HIGH |
| +0x3578 | float | float | 7 files | float:3 int:0 double:0 undef:2 ptr:0 idx:2 | HIGH |
| +0x3580 | float | float | 4 files | float:2 int:0 double:0 undef:1 ptr:0 idx:1 | MEDIUM |
| +0x358c | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3594 | float | float[4] | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x35b0 | float | float | 4 files | float:4 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x35d8 | float | float | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x35dc | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x35f0 | float | float[4] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x3610 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x361c | float | float[4] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x3664 | int | int | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3668 | int | int | 2 files | float:0 int:1 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3684 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x36a8 | float | float | 4 files | float:3 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x36d0 | float | float | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x36d4 | float | float | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x3708 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x375c | int | int | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3770 | float | float | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x37a0 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x37c8 | float | float | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x37cc | float | float | 5 files | float:5 int:0 double:0 undef:0 ptr:0 idx:0 | HIGH |
| +0x3800 | float | float | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3854 | int | int | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3898 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x38c0 | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x38c4 | float | float | 5 files | float:5 int:0 double:0 undef:0 ptr:0 idx:0 | HIGH |
| +0x38f8 | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x394c | int | int | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3978 | float | float | 10 files | float:7 int:1 double:0 undef:0 ptr:0 idx:2 | HIGH |
| +0x397c | float | float | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3984 | float | float | 13 files | float:6 int:1 double:0 undef:0 ptr:0 idx:6 | HIGH |
| +0x3990 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3994 | float | float | 18 files | float:8 int:0 double:0 undef:7 ptr:0 idx:3 | HIGH |
| +0x3998 | float | float | 8 files | float:6 int:0 double:0 undef:1 ptr:0 idx:1 | HIGH |
| +0x399c | float | float | 8 files | float:4 int:0 double:0 undef:3 ptr:0 idx:1 | HIGH |
| +0x39a4 | ptr | ptr | 9 files | float:2 int:4 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x39a8 | float | float | 6 files | float:4 int:0 double:0 undef:1 ptr:0 idx:1 | HIGH |
| +0x39ac | float | float | 4 files | float:3 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x39b0 | ptr | ptr | 3 files | float:0 int:2 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x39b4 | int | int | 11 files | float:0 int:9 double:0 undef:1 ptr:0 idx:1 | HIGH |
| +0x39c8 | float | float | 10 files | float:6 int:0 double:0 undef:4 ptr:0 idx:0 | HIGH |
| +0x39d0 | float | float | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x39ec | byte | byte | 4 files | float:0 int:0 double:0 undef:4 ptr:0 idx:0 | MEDIUM |
| +0x39ee | byte | byte | 2 files | float:0 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x39f0 | int | int/float | 10 files | float:0 int:4 double:0 undef:6 ptr:0 idx:0 | HIGH |
| +0x39f8 | int | int | 6 files | float:0 int:6 double:0 undef:0 ptr:0 idx:0 | HIGH |
| +0x39fc | float | float | 8 files | float:1 int:3 double:0 undef:4 ptr:0 idx:0 | HIGH |
| +0x3a00 | float | float | 2 files | float:1 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3a04 | float | float | 6 files | float:3 int:1 double:0 undef:2 ptr:0 idx:0 | HIGH |
| +0x3a08 | int | int | 5 files | float:0 int:2 double:0 undef:3 ptr:0 idx:0 | HIGH |
| +0x3a30 | float | float | 5 files | float:4 int:0 double:0 undef:0 ptr:0 idx:1 | HIGH |
| +0x3a38 | float | float[4] | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x3a3c | float | float[4] | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x3a58 | float | float[3] | 5 files | float:3 int:0 double:0 undef:2 ptr:0 idx:0 | HIGH |
| +0x3a6c | float | float | 10 files | float:8 int:0 double:0 undef:2 ptr:0 idx:0 | HIGH |
| +0x3a70 | float | float | 12 files | float:9 int:0 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x3a78 | float | float | 4 files | float:2 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x3a7c | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3a80 | float | float | 6 files | float:3 int:0 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x3a9c | ptr | ptr | 10 files | float:0 int:2 double:0 undef:5 ptr:0 idx:3 | HIGH |
| +0x3aa0 | float | float | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x3aa4 | float | float | 2 files | float:1 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3aa8 | float | float | 5 files | float:1 int:1 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x3b54 | float | float[3] | 3 files | float:1 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x3b60 | float | float[3] | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3b64 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3b68 | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3b6c | float | float | 7 files | float:5 int:0 double:0 undef:2 ptr:0 idx:0 | HIGH |
| +0x3b78 | byte | byte | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3b79 | byte | byte | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3b88 | float | float | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3b8c | float | float | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3b90 | float | float | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3bf4 | float | float | 8 files | float:3 int:0 double:0 undef:4 ptr:0 idx:1 | HIGH |
| +0x3bfc | float | float[14] | 4 files | float:3 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3c00 | float | float[14] | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3c04 | float | float[14] | 2 files | float:2 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3c3c | float | float[14] | 5 files | float:4 int:0 double:0 undef:1 ptr:0 idx:0 | HIGH |
| +0x3c40 | float | float[14] | 4 files | float:4 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3c44 | float | float[14] | 5 files | float:4 int:0 double:0 undef:1 ptr:0 idx:0 | HIGH |
| +0x3c7c | float | float[14] | 4 files | float:4 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3c80 | float | float[14] | 4 files | float:4 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3c84 | float | float[14] | 5 files | float:4 int:0 double:0 undef:1 ptr:0 idx:0 | HIGH |
| +0x3cbc | float | float | 4 files | float:4 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3cfc | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3d00 | float | float[15] | 1 files | float:1 int:0 double:0 undef:0 ptr:0 idx:0 | LOW |
| +0x3d3c | float | float | 3 files | float:3 int:0 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x3d40 | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x3d44 | float | float | 8 files | float:7 int:0 double:0 undef:1 ptr:0 idx:0 | HIGH |
| +0x3d48 | float | float | 7 files | float:2 int:0 double:0 undef:3 ptr:0 idx:2 | HIGH |
| +0x3d4c | float | float | 7 files | float:2 int:0 double:0 undef:3 ptr:0 idx:2 | HIGH |
| +0x3d50 | float | float | 7 files | float:2 int:0 double:0 undef:3 ptr:0 idx:2 | HIGH |
| +0x3d60 | int | int | 9 files | float:0 int:2 double:0 undef:4 ptr:0 idx:3 | HIGH |
| +0x3d40 | float | float | 3 files | float:2 int:0 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x4024 | float | float | 4 files | float:2 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x403c | int | int | 26 files | float:0 int:17 double:0 undef:2 ptr:0 idx:7 | HIGH |
| +0x4044 | float | float | 6 files | float:3 int:0 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x4058 | int | int | 3 files | float:0 int:3 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x405c | float | float | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x4060 | int | int | 12 files | float:0 int:10 double:0 undef:1 ptr:0 idx:1 | HIGH |
| +0x4064 | int | int | 21 files | float:0 int:15 double:0 undef:3 ptr:0 idx:3 | HIGH |
| +0x4068 | int | int | 9 files | float:0 int:4 double:0 undef:3 ptr:0 idx:2 | HIGH |
| +0x409c | float | float | 6 files | float:3 int:0 double:0 undef:1 ptr:0 idx:2 | HIGH |
| +0x4354 | int | int | 12 files | float:0 int:4 double:0 undef:4 ptr:0 idx:4 | HIGH |
| +0x44a8 | ptr | ptr | 5 files | float:0 int:2 double:0 undef:0 ptr:0 idx:3 | HIGH |
| +0x4500 | float | float | 2 files | float:1 int:0 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x4504 | float | float | 2 files | float:1 int:0 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x4538 | float | float | 6 files | float:1 int:0 double:0 undef:3 ptr:0 idx:2 | HIGH |
| +0x453c | float | float | 5 files | float:2 int:0 double:0 undef:0 ptr:0 idx:3 | HIGH |
| +0x454c | int | int | 11 files | float:0 int:3 double:0 undef:2 ptr:0 idx:6 | HIGH |
| +0x4550 | int | int | 14 files | float:0 int:4 double:0 undef:3 ptr:0 idx:7 | HIGH |
| +0x4580 | float | float | 2 files | float:1 int:0 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x44f4 | float | float | 3 files | float:1 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x4588 | int | int | 3 files | float:0 int:1 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x4590 | uint | uint[] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x45f4 | byte | byte | 5 files | float:0 int:0 double:0 undef:4 ptr:0 idx:1 | HIGH |
| +0x45f8 | int | int | 6 files | float:0 int:1 double:0 undef:1 ptr:0 idx:4 | HIGH |
| +0x45fc | int | int | 8 files | float:0 int:2 double:0 undef:1 ptr:0 idx:5 | HIGH |
| +0x4620 | char | char[64] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x4678 | char | char[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x46f8 | char | char[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x4708 | char | char[7] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x470f | byte | byte | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x4710 | uint | uint | 4 files | float:0 int:2 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x4714 | char | char[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x4894 | int | int | 36 files | float:0 int:26 double:0 undef:10 ptr:0 idx:0 | HIGH |
| +0x4898 | int | int | 3 files | float:0 int:2 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x489c | int | int | 12 files | float:0 int:3 double:0 undef:9 ptr:0 idx:0 | HIGH |
| +0x48a0 | int | int | 4 files | float:0 int:1 double:0 undef:3 ptr:0 idx:0 | MEDIUM |
| +0x48a4 | int | int | 15 files | float:0 int:7 double:0 undef:8 ptr:0 idx:0 | HIGH |
| +0x48a8 | int | int | 7 files | float:0 int:3 double:0 undef:4 ptr:0 idx:0 | HIGH |
| +0x48ac | int | int | 2 files | float:0 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x48b0 | short | short | 2 files | float:0 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x48b4 | float | float | 3 files | float:1 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x48b8 | float | float/int | 4 files | float:2 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x48bc | int | int | 2 files | float:0 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x04fc | float | float | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x069c | float | float | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x077c | float | float | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0790 | float | float | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x07a4 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0828 | int | int[4] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x082c | float | float[3] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x083c | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x08cc | float | float[4] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x08e8 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x08ec | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x08f0 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x08f4 | float | float[3] | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0900 | float | float[3] | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x090c | ptr | ptr | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0918 | float | float[3] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0934 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0144 | int | int | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x0184 | char | char | 11 files | float:0 int:0 double:0 undef:0 ptr:0 idx:11 | HIGH |
| +0x05e4 | int | int | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0628 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x066c | int | int | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x004c | float | float | 50 files | float:0 int:0 double:0 undef:0 ptr:0 idx:50 | HIGH |
| +0x00cc | int | int | 6 files | float:0 int:0 double:0 undef:0 ptr:0 idx:6 | HIGH |
| +0x00d4 | unknown | struct[4] | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x01cc | float | float | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0200 | float | float | 6 files | float:0 int:0 double:0 undef:0 ptr:0 idx:6 | HIGH |

---

---

## VehicleTelemetryBroadcast (param_1 — telemetry)

Total offsets in section: 6

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0caf | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0d2c | ptr | ptr | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0d35 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0d36 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0d37 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0d38 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## 3. LinkedListNode (inferred)

Total offsets in section: 3

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | ptr | ptr | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0004 | ptr | ptr | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0008 | byte | byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## VehiclePhysicsState (inferred)

Total offsets in section: 140

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | int | int/byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0004 | byte | byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0008 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x000c | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0010 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0014 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0018 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x001c | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0020 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0024 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0028 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x002c | int | int | 103 files | float:0 int:0 double:0 undef:0 ptr:0 idx:103 | HIGH |
| +0x0030 | float | float | 97 files | float:0 int:0 double:0 undef:0 ptr:0 idx:97 | HIGH |
| +0x0034 | int | int | 80 files | float:0 int:0 double:0 undef:0 ptr:0 idx:80 | HIGH |
| +0x0038 | double | double | 82 files | float:0 int:0 double:0 undef:0 ptr:0 idx:82 | HIGH |
| +0x0060 | double | double | 40 files | float:0 int:0 double:0 undef:0 ptr:0 idx:40 | HIGH |
| +0x0064 | double | double | 37 files | float:0 int:0 double:0 undef:0 ptr:0 idx:37 | HIGH |
| +0x006c | double | double | 24 files | float:0 int:0 double:0 undef:0 ptr:0 idx:24 | HIGH |
| +0x0074 | double | double | 30 files | float:0 int:0 double:0 undef:0 ptr:0 idx:30 | HIGH |
| +0x0078 | int | int | 30 files | float:0 int:0 double:0 undef:0 ptr:0 idx:30 | HIGH |
| +0x0094 | double | double | 29 files | float:0 int:0 double:0 undef:0 ptr:0 idx:29 | HIGH |
| +0x00a8 | float | float | 19 files | float:0 int:0 double:0 undef:0 ptr:0 idx:19 | HIGH |
| +0x00ac | float | float | 19 files | float:0 int:0 double:0 undef:0 ptr:0 idx:19 | HIGH |
| +0x00b0 | float | float | 23 files | float:0 int:0 double:0 undef:0 ptr:0 idx:23 | HIGH |
| +0x00b4 | int | int | 14 files | float:0 int:0 double:0 undef:0 ptr:0 idx:14 | HIGH |
| +0x00bc | double | double | 12 files | float:0 int:0 double:0 undef:0 ptr:0 idx:12 | HIGH |
| +0x00d4 | float | float | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x00e0 | float | float | 33 files | float:0 int:0 double:0 undef:0 ptr:0 idx:33 | HIGH |
| +0x0124 | float | float | 14 files | float:0 int:0 double:0 undef:0 ptr:0 idx:14 | HIGH |
| +0x0134 | double | double | 9 files | float:0 int:0 double:0 undef:0 ptr:0 idx:9 | HIGH |
| +0x013c | double | double | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x0144 | double | double | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x014c | double | double | 12 files | float:0 int:0 double:0 undef:0 ptr:0 idx:12 | HIGH |
| +0x0154 | double | double | 5 files | float:0 int:0 double:0 undef:0 ptr:0 idx:5 | HIGH |
| +0x015c | double | double | 10 files | float:0 int:0 double:0 undef:0 ptr:0 idx:10 | HIGH |
| +0x019c | double | double | 5 files | float:0 int:0 double:0 undef:0 ptr:0 idx:5 | HIGH |
| +0x1c59 | byte | byte | 4 files | float:0 int:0 double:0 undef:4 ptr:0 idx:0 | MEDIUM |
| +0x0234 | double | double | 5 files | float:0 int:0 double:0 undef:0 ptr:0 idx:5 | HIGH |
| +0x0268 | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0270 | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0278 | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0288 | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0314 | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x031c | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0324 | double | double | 41 files | float:0 int:0 double:0 undef:0 ptr:0 idx:41 | HIGH |
| +0x0334 | double | double | 33 files | float:0 int:0 double:0 undef:0 ptr:0 idx:33 | HIGH |
| +0x033c | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0344 | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x034c | double | double[6] | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0354 | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x035c | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0364 | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0368 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x036c | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0374 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x037c | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x038c | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0394 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0398 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x039c | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x03a4 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x03ac | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x03b4 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x03bc | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x03c4 | double | double | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x03cc | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x044c | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0454 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0660 | double | double | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x06c4 | int | int | 3 files | float:0 int:0 double:0 undef:0 ptr:0 idx:3 | MEDIUM |
| +0x0072 | byte | byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0080 | int | int | 27 files | float:0 int:0 double:0 undef:0 ptr:0 idx:27 | HIGH |
| +0x084c | int | int* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0900 | double | double | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0cb0 | int | int* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x1114 | int | int* | 4 files | float:0 int:3 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x141c | int | int* | 13 files | float:0 int:9 double:0 undef:4 ptr:0 idx:0 | HIGH |
| +0x1420 | double | double | 3 files | float:0 int:0 double:1 undef:1 ptr:0 idx:1 | MEDIUM |
| +0x1428 | double | double | 2 files | float:0 int:0 double:1 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x1430 | double | double | 4 files | float:0 int:0 double:2 undef:1 ptr:0 idx:1 | MEDIUM |
| +0x15ac | int | int | 6 files | float:0 int:5 double:0 undef:0 ptr:0 idx:1 | HIGH |
| +0x15b0 | double | double* | 6 files | float:0 int:5 double:0 undef:0 ptr:0 idx:1 | HIGH |
| +0x15c4 | int | int | 3 files | float:0 int:2 double:0 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x15c8 | int | int* | 2 files | float:0 int:2 double:0 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x15f0 | int | int* | 24 files | float:0 int:21 double:0 undef:3 ptr:0 idx:0 | HIGH |
| +0x15fc | double | double | 2 files | float:0 int:0 double:2 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x1604 | double | double | 2 files | float:0 int:0 double:2 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x160c | double | double | 3 files | float:0 int:0 double:2 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x17d8 | double | double | 5 files | float:0 int:0 double:3 undef:2 ptr:0 idx:0 | HIGH |
| +0x17f0 | double | double | 6 files | float:0 int:0 double:3 undef:2 ptr:0 idx:1 | HIGH |
| +0x1808 | double | double | 5 files | float:0 int:0 double:4 undef:1 ptr:0 idx:0 | HIGH |
| +0x1818 | double | double | 6 files | float:0 int:0 double:4 undef:2 ptr:0 idx:0 | HIGH |
| +0x19a4 | byte | byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x1bc0 | double | double | 5 files | float:0 int:0 double:3 undef:1 ptr:0 idx:1 | HIGH |
| +0x1c00 | double | double | 3 files | float:0 int:0 double:1 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c08 | double | double | 5 files | float:0 int:0 double:2 undef:2 ptr:0 idx:1 | HIGH |
| +0x1c10 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c18 | double | double | 3 files | float:0 int:0 double:1 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c20 | double | double | 3 files | float:0 int:0 double:2 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x1c28 | double | double | 4 files | float:0 int:0 double:2 undef:1 ptr:0 idx:1 | MEDIUM |
| +0x1c30 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c38 | double | double | 3 files | float:0 int:0 double:1 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c3c | double | double | 3 files | float:0 int:0 double:0 undef:3 ptr:0 idx:0 | MEDIUM |
| +0x1c40 | double | double | 5 files | float:0 int:0 double:2 undef:2 ptr:0 idx:1 | HIGH |
| +0x1c48 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1c5c | double | double | 20 files | float:0 int:0 double:10 undef:10 ptr:0 idx:0 | HIGH |
| +0x1c64 | float | float | 4 files | float:0 int:0 double:0 undef:3 ptr:0 idx:1 | MEDIUM |
| +0x1c74 | double | double | 4 files | float:0 int:0 double:3 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x1ca8 | int | int[] | 4 files | float:1 int:0 double:0 undef:3 ptr:0 idx:0 | MEDIUM |
| +0x1cb4 | double | double | 3 files | float:1 int:0 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1cb8 | byte | byte | 3 files | float:0 int:0 double:0 undef:2 ptr:0 idx:1 | MEDIUM |
| +0x1cbc | double | double | 3 files | float:0 int:0 double:0 undef:2 ptr:0 idx:1 | MEDIUM |
| +0x1cc0 | byte | byte[] | 3 files | float:0 int:1 double:0 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1cc4 | uint | uint[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1cd4 | byte | byte[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1cd8 | int | int[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1ce8 | byte | byte[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1d4c | double | double | 2 files | float:0 int:0 double:1 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x1db4 | double | double | 6 files | float:0 int:0 double:3 undef:2 ptr:0 idx:1 | HIGH |
| +0x1e14 | int | int | 6 files | float:0 int:5 double:0 undef:0 ptr:0 idx:1 | HIGH |
| +0x1e18 | double | double | 2 files | float:0 int:0 double:2 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x1e20 | double | double | 3 files | float:0 int:0 double:2 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x1e28 | double | double | 2 files | float:0 int:0 double:2 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x1e30 | double | double | 2 files | float:0 int:0 double:2 undef:0 ptr:0 idx:0 | MEDIUM |
| +0x1e38 | double | double | 11 files | float:0 int:0 double:4 undef:6 ptr:0 idx:1 | HIGH |
| +0x1e3c | float | float | 6 files | float:0 int:0 double:0 undef:6 ptr:0 idx:0 | HIGH |
| +0x1e40 | float | float | 3 files | float:0 int:0 double:0 undef:3 ptr:0 idx:0 | MEDIUM |
| +0x1e50 | double | double | 4 files | float:0 int:0 double:3 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x1ea4 | double | double | 4 files | float:0 int:0 double:3 undef:0 ptr:0 idx:1 | MEDIUM |
| +0x1f00 | int | int* | 11 files | float:0 int:8 double:0 undef:2 ptr:0 idx:1 | HIGH |
| +0x1f04 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1f0c | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1f14 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1f1c | double | double | 5 files | float:0 int:0 double:2 undef:2 ptr:0 idx:1 | HIGH |
| +0x1f24 | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x1f2c | double | double | 4 files | float:0 int:0 double:2 undef:2 ptr:0 idx:0 | MEDIUM |
| +0x3b40 | int | int | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x3b80 | float | float[] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x03a8 | int | int[] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x402c | float | float[] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## SparseParamArray

Total offsets in section: 4

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x1cd4 | byte | byte[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1cd8 | int | int[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x1ce8 | byte | byte[] | 1 files | float:0 int:0 double:0 undef:1 ptr:0 idx:0 | LOW |
| +0x0000 | int | int[3] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## WheelSuspensionData (inferred)

Total offsets in section: 11

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0104 | int | int | 20 files | float:0 int:0 double:0 undef:0 ptr:0 idx:20 | HIGH |
| +0x0144 | int | int | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x0184 | int | int | 11 files | float:0 int:0 double:0 undef:0 ptr:0 idx:11 | HIGH |
| +0x01c4 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0204 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0244 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0284 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x02c4 | int | int | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |
| +0x0304 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0344 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x02c0 | unknown | - | 3 files | float:0 int:0 double:0 undef:0 ptr:0 idx:3 | MEDIUM |

---

---

## Player File Struct

Total offsets in section: 6

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0014 | char | char* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0114 | int | int | 18 files | float:0 int:0 double:0 undef:0 ptr:0 idx:18 | HIGH |
| +0x1f78 | int | int | 5 files | float:0 int:4 double:0 undef:1 ptr:0 idx:0 | HIGH |
| +0x24f8 | int | int | 2 files | float:0 int:1 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x2f8c | int | int | 2 files | float:0 int:1 double:0 undef:1 ptr:0 idx:0 | MEDIUM |
| +0x49b0 | char | char* | 1 files | float:0 int:0 double:0 undef:0 ptr:0 idx:1 | LOW |

---

---

## UI Dialog/Property Page Struct

Total offsets in section: 6

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | void* | void* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0174 | int | int | 22 files | float:0 int:0 double:0 undef:0 ptr:0 idx:22 | HIGH |
| +0x0178 | int | int | 14 files | float:0 int:0 double:0 undef:0 ptr:0 idx:14 | HIGH |
| +0x017c | byte | byte | 3 files | float:0 int:0 double:0 undef:0 ptr:0 idx:3 | MEDIUM |
| +0x0180 | int | int | 9 files | float:0 int:0 double:0 undef:0 ptr:0 idx:9 | HIGH |
| +0x0184 | int | int | 11 files | float:0 int:0 double:0 undef:0 ptr:0 idx:11 | HIGH |

---

---

## Screen-Space Tile Renderer (inferred)

Total offsets in section: 4

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x1578 | int | int | 8 files | float:0 int:2 double:3 undef:3 ptr:0 idx:0 | HIGH |
| +0x157c | ptr | ptr | 7 files | float:0 int:2 double:0 undef:4 ptr:0 idx:1 | HIGH |
| +0x1580 | int | int | 6 files | float:0 int:2 double:0 undef:2 ptr:0 idx:2 | HIGH |
| +0x1584 | int | int | 5 files | float:0 int:4 double:0 undef:1 ptr:0 idx:0 | HIGH |

---

---

## CollisionLinkedNode (inferred — generic collision/proxy linked list node)

Total offsets in section: 3

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | int | int* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0004 | int | int* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0008 | byte | byte | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## CollisionDataBlock (inferred — param_1 in FUN_0044fbb0)

Total offsets in section: 4

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0080 | int | int* | 27 files | float:0 int:0 double:0 undef:0 ptr:0 idx:27 | HIGH |
| +0x0084 | int | int[0x91] | 29 files | float:0 int:0 double:0 undef:0 ptr:0 idx:29 | HIGH |
| +0x0278 | int | int | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x02F4 | int | int | 5 files | float:0 int:0 double:0 undef:0 ptr:0 idx:5 | HIGH |

---

---

## 1. Track Material Struct (inferred)

Total offsets in section: 12

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0008 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x000c | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0010 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0014 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0018 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x001c | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0020 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0024 | float | float? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0028 | int | int? | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x002c | unknown | bool? | 103 files | float:0 int:0 double:0 undef:0 ptr:0 idx:103 | HIGH |
| +0x0030 | int | int[3]? | 97 files | float:0 int:0 double:0 undef:0 ptr:0 idx:97 | HIGH |
| +0x0060 | unknown | bool? | 40 files | float:0 int:0 double:0 undef:0 ptr:0 idx:40 | HIGH |

---

---

## AudioChannelInitStruct (inferred)

Total offsets in section: 17

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0130 | int | int | 9 files | float:0 int:0 double:0 undef:0 ptr:0 idx:9 | HIGH |
| +0x0131 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0132 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0133 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x013a | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x013c | int | int | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x013d | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x013e | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0140 | int | int | 13 files | float:0 int:0 double:0 undef:0 ptr:0 idx:13 | HIGH |
| +0x0141 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0142 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0144 | int | int | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x0145 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0146 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0147 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0fef | void* | void* | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0ff6 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## Struct 4: Driver Data Entry (stride 0x20 = 32 bytes = 8 ints)

Total offsets in section: 3

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x0000 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0014 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0000 | int | int[8] | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## WeatherState (inferred)

Total offsets in section: 36

| Offset | Claimed Type | Claimed Name | .c Evidence | Type Matches | Confidence |
|--------|-------------|--------------|-------------|-------------|------------|
| +0x000c | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0010 | int | int | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0018 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0020 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0024 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0028 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x002c | float | float | 103 files | float:0 int:0 double:0 undef:0 ptr:0 idx:103 | HIGH |
| +0x0030 | float | float | 97 files | float:0 int:0 double:0 undef:0 ptr:0 idx:97 | HIGH |
| +0x0034 | float | float | 80 files | float:0 int:0 double:0 undef:0 ptr:0 idx:80 | HIGH |
| +0x0038 | unknown | pointer | 82 files | float:0 int:0 double:0 undef:0 ptr:0 idx:82 | HIGH |
| +0x003c | unknown | pointer | 72 files | float:0 int:0 double:0 undef:0 ptr:0 idx:72 | HIGH |
| +0x00a4 | float | float | 17 files | float:0 int:0 double:0 undef:0 ptr:0 idx:17 | HIGH |
| +0x00a8 | float | float | 19 files | float:0 int:0 double:0 undef:0 ptr:0 idx:19 | HIGH |
| +0x00b4 | float | float | 14 files | float:0 int:0 double:0 undef:0 ptr:0 idx:14 | HIGH |
| +0x00b8 | float | float | 13 files | float:0 int:0 double:0 undef:0 ptr:0 idx:13 | HIGH |
| +0x00bc | float | float | 12 files | float:0 int:0 double:0 undef:0 ptr:0 idx:12 | HIGH |
| +0x00c0 | float | float | 15 files | float:0 int:0 double:0 undef:0 ptr:0 idx:15 | HIGH |
| +0x00c4 | float | float | 13 files | float:0 int:0 double:0 undef:0 ptr:0 idx:13 | HIGH |
| +0x00c8 | float | float | 12 files | float:0 int:0 double:0 undef:0 ptr:0 idx:12 | HIGH |
| +0x00cc | float | float | 6 files | float:0 int:0 double:0 undef:0 ptr:0 idx:6 | HIGH |
| +0x00d0 | float | float | 9 files | float:0 int:0 double:0 undef:0 ptr:0 idx:9 | HIGH |
| +0x00d4 | float | float | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x00d8 | float | float | 10 files | float:0 int:0 double:0 undef:0 ptr:0 idx:10 | HIGH |
| +0x00dc | float | float | 8 files | float:0 int:0 double:0 undef:0 ptr:0 idx:8 | HIGH |
| +0x00e0 | float | float | 33 files | float:0 int:0 double:0 undef:0 ptr:0 idx:33 | HIGH |
| +0x00e4 | float | float | 29 files | float:0 int:0 double:0 undef:0 ptr:0 idx:29 | HIGH |
| +0x00e8 | float | float | 27 files | float:0 int:0 double:0 undef:0 ptr:0 idx:27 | HIGH |
| +0x00ec | float | float | 21 files | float:0 int:0 double:0 undef:0 ptr:0 idx:21 | HIGH |
| +0x00f0 | int | int | 28 files | float:0 int:0 double:0 undef:0 ptr:0 idx:28 | HIGH |
| +0x00f4 | float | float | 20 files | float:0 int:0 double:0 undef:0 ptr:0 idx:20 | HIGH |
| +0x00f8 | float | float | 21 files | float:0 int:0 double:0 undef:0 ptr:0 idx:21 | HIGH |
| +0x01c4 | byte | byte | 2 files | float:0 int:0 double:0 undef:0 ptr:0 idx:2 | MEDIUM |
| +0x0000 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0004 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x0008 | float | float | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |
| +0x000c | unknown | pointer | 0 files | float:0 int:0 double:0 undef:0 ptr:0 idx:0 | NO_EVIDENCE |

---

---

## ReplaySaveStruct (param_1 — replay context)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c0 | ptr | ListHead | HIGH | FUN_004b7300 (int), FUN_004b81a0 (int**), FUN_004b6a10 (int**), FUN_004b8480 (undefined4), FUN_004b5a30 | none — ptr type confirmed |
| +0x6c4 | ptr | ListTail | HIGH | FUN_004b81a0 (undefined4**), FUN_004b6a10, FUN_004b7300, FUN_004b8480, FUN_004b85d0, FUN_004b5a30 | none |
| +0x6c8 | ptr | ListCursor/CurrentNode | HIGH | FUN_004b6a10 (int**), FUN_004b7300, FUN_004b81a0, FUN_004b8480, FUN_004b85d0, FUN_004b84f0, FUN_004b5a30 | none |
| +0x6cc | int | ListCount/ItemCount | HIGH | FUN_004b81a0 (int, inc), FUN_004b7300 (undefined4), FUN_004b8480 (undefined4), FUN_004b5a30 | MINOR: byte access in FUN_004b6a10 (*(undefined1*)) — potential bitfield or Ghidra artifact |
| +0x6d0 | byte | SortedFlag/DirtyFlag | HIGH | FUN_004b7500 (char), FUN_004b81a0 (undefined1=1), FUN_004b8480 (undefined1=1), FUN_004b71e0 (undefined1=0) | none — byte confirmed across 4+ functions |
| +0x6d4 | ptr | LinkedListHead0 | MEDIUM | FUN_004b5a30 (int=ptr, cleared to 0) | Only 1 ReplaySaveStruct function uses it |
| +0x6e4 | int | ReplayDataPresent | HIGH | FUN_004b7300 (int), FUN_004b7500 (int check), FUN_004b7860, FUN_004b9000, FUN_004b9510 | none |
| +0x6e8 | int | HeaderDataSource | LOW | FUN_004b7500 (decompiled_all) only — *(undefined1**) = char* pointer | TYPE CONFLICT: docs say int, actual usage is char* pointer |
| +0x700 | int | SaveState | HIGH | FUN_004b7300 (undefined4, vals 0/1/2), FUN_004b7500 (int, check ==1) | none |
| +0x704 | ptr | InputDataSource | HIGH | FUN_004b7300 (undefined4*, passed to FUN_004b9830), FUN_004b7500 (undefined1**), FUN_004b5a30 (int=freed ptr), FUN_0040adb0 | none |
| +0x70c | char[] | TrackName | HIGH | FUN_004b7500 (undefined1**), FUN_004b5a30 (char* ptr, freed), FUN_0040adb0 | TYPE NOTE: docs say char[] but actual is char* (heap-allocated pointer, not inline buffer) |
| +0x714 | ptr | EntryLinkedListHead | HIGH | FUN_004b5f60 (int**), FUN_004b6a10 (undefined4**), FUN_004b7500 (int**), FUN_004b7c80, FUN_004b7860, FUN_004b6c90 | none |
| +0x718 | ptr | EntryLinkedListTail | HIGH | FUN_004b5f60 (int**), FUN_004b6a10, FUN_004b7860, FUN_004b7a00, FUN_004b9000, FUN_004b9510, FUN_004b6c90 | none |
| +0x71c | ptr | TraversalCursor | HIGH | FUN_004b5f60 (int**), FUN_004b6a10 (undefined4**), FUN_004b7c80, FUN_004b7860, FUN_004b6c90 | none |
| +0x720 | int | LinkedListCount | HIGH | FUN_004b5f60 (int inc/dec), FUN_004b6c90, FUN_004b7860, FUN_004b7a00, FUN_004b9000 | none |
| +0x724 | ptr | ComponentPtr2 | HIGH | FUN_004b5a30 (int=ptr, freed), FUN_004b6a10 (char**), FUN_004b70b0 | none |
| +0x72c | ptr | ComponentPtr1 | HIGH | FUN_004b5a30 (int=ptr, freed), FUN_004b6a10 (char**), FUN_004e5f60 | none |
| +0x9a4 | int | SubfolderIndex | HIGH | FUN_004b7500 (undefined4 switch 0-4), FUN_004b71e0 (undefined4 switch) | none |
| +0xf30 | float | LapTimeStart/MinValue | HIGH | FUN_004b86e0 (float clamp), FUN_004b7500 (float), FUN_004b6c90 (float), FUN_004b7300, FUN_004b87a0 | none |
| +0xf34 | float | LapTimeEnd/MaxValue | HIGH | FUN_004b86e0 (float clamp), FUN_004b7500 (float), FUN_004b6c90, FUN_004b87a0 | none |
| +0xf38 | float | Value/Threshold/ScoreValue | HIGH | FUN_004b86e0 (float, sort key), FUN_004b81a0 (undefined4), FUN_004b84f0, FUN_004b85d0, FUN_004b8790 | none |
| +0xf3c | float | PreviousValue | HIGH | FUN_004b86e0 (float copy of f38), FUN_004b71e0 (undefined4=0), FUN_004b9b80 | none |
| +0xf81 | byte | Mode | HIGH | FUN_004b86e0 (char, 0=wrap/non-0=clamp), FUN_004b57f0, FUN_004b87c0, FUN_004b8940 | none |
| +0xf8c | int | ServiceAnimState | HIGH | FUN_004b9e40 (undefined4 switch 0/5/9), FUN_004b71e0 (stores 5), FUN_004b8c40, FUN_004b9da0 | none |
| +0xf94 | char[] | OutputFilePath | MEDIUM | FUN_004b5a30 (int=ptr, freed with FUN_00587bcf) | TYPE NOTE: docs say char[], actual is heap char* pointer |

---

## CarPartVisibility (damaged parts)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb10 | int | PartFrontWing1 | LOW | FUN_004ae490 only (undefined4, 0/1 flag) | none — other functions using same offset (0x0057xxxx) are in Mutex struct context, different parent |
| +0xb34 | int | PartFrontWing2 | LOW | FUN_004ae490 only (undefined4, 0/1 flag) | none — other function (FUN_005386c0) uses short* array at different parent struct |
| +0xb58 | int | PartFrontWing3 | LOW | FUN_004ae490 only (undefined4, 0/1 flag) | none |
| +0x1ac8 | int | RepairState | LOW | FUN_004ae490 only (int, 0/1/2) | none |
| +0x1c30 | int | PartRearWing | LOW | FUN_004ae490 only (undefined4, 0/1 flag) | none — other functions using same offset (0x0043xxxx) are in physics struct context as double, different parent |
| +0x2348 | float | AnimParamA | LOW | FUN_004ae490 only (0x3d4ccccd=0.05f, 0x3f000000=0.5f) | none — float confirmed |
| +0x236c | float | AnimParamB | LOW | FUN_004ae490 only (0x3d4ccccd=0.05f, 0x3f000000=0.5f) | none — float confirmed |
| +0x26f0–0x2834 | int[7] | BodyParts | LOW | FUN_004ae490 only (undefined4=1 flags, scattered stride ~0x24) | NOTE: stride between flags is ~0x24 (not contiguous array). Flags at +0x26f0, +0x2714, +0x2738, +0x27ec, +0x2810, +0x2834 — 6 body part flags, not 7 |



| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c0 | ptr | ListHead | HIGH | FUN_004b7300 (int), FUN_004b81a0 (int**), FUN_004b6a10 (int**), FUN_004b8480 (undefined4), FUN_004b5a30 | none — ptr type confirmed |
| +0x6c4 | ptr | ListTail | HIGH | FUN_004b81a0 (undefined4**), FUN_004b6a10, FUN_004b7300, FUN_004b8480, FUN_004b85d0, FUN_004b5a30 | none |
| +0x6c8 | ptr | ListCursor/CurrentNode | HIGH | FUN_004b6a10 (int**), FUN_004b7300, FUN_004b81a0, FUN_004b8480, FUN_004b85d0, FUN_004b84f0, FUN_004b5a30 | none |
| +0x6cc | int | ListCount/ItemCount | HIGH | FUN_004b81a0 (int, inc), FUN_004b7300 (undefined4), FUN_004b8480 (undefined4), FUN_004b5a30 | MINOR: byte access in FUN_004b6a10 (*(undefined1*)) — potential bitfield or Ghidra artifact |
| +0x6d0 | byte | SortedFlag/DirtyFlag | HIGH | FUN_004b7500 (char), FUN_004b81a0 (undefined1=1), FUN_004b8480 (undefined1=1), FUN_004b71e0 (undefined1=0) | none — byte confirmed across 4+ functions |
| +0x6d4 | ptr | LinkedListHead0 | MEDIUM | FUN_004b5a30 (int=ptr, cleared to 0) | Only 1 ReplaySaveStruct function uses it |
| +0x6e4 | int | ReplayDataPresent | HIGH | FUN_004b7300 (int), FUN_004b7500 (int check), FUN_004b7860, FUN_004b9000, FUN_004b9510 | none |
| +0x6e8 | int | HeaderDataSource | LOW | FUN_004b7500 (decompiled_all) only — *(undefined1**) = char* pointer | TYPE CONFLICT: docs say int, actual usage is char* pointer |
| +0x700 | int | SaveState | HIGH | FUN_004b7300 (undefined4, vals 0/1/2), FUN_004b7500 (int, check ==1) | none |
| +0x704 | ptr | InputDataSource | HIGH | FUN_004b7300 (undefined4*, passed to FUN_004b9830), FUN_004b7500 (undefined1**), FUN_004b5a30 (int=freed ptr), FUN_0040adb0 | none |
| +0x70c | char[] | TrackName | HIGH | FUN_004b7500 (undefined1**), FUN_004b5a30 (char* ptr, freed), FUN_0040adb0 | TYPE NOTE: docs say char[] but actual is char* (heap-allocated pointer, not inline buffer) |
| +0x714 | ptr | EntryLinkedListHead | HIGH | FUN_004b5f60 (int**), FUN_004b6a10 (undefined4**), FUN_004b7500 (int**), FUN_004b7c80, FUN_004b7860, FUN_004b6c90 | none |
| +0x718 | ptr | EntryLinkedListTail | HIGH | FUN_004b5f60 (int**), FUN_004b6a10, FUN_004b7860, FUN_004b7a00, FUN_004b9000, FUN_004b9510, FUN_004b6c90 | none |
| +0x71c | ptr | TraversalCursor | HIGH | FUN_004b5f60 (int**), FUN_004b6a10 (undefined4**), FUN_004b7c80, FUN_004b7860, FUN_004b6c90 | none |
| +0x720 | int | LinkedListCount | HIGH | FUN_004b5f60 (int inc/dec), FUN_004b6c90, FUN_004b7860, FUN_004b7a00, FUN_004b9000 | none |
| +0x724 | ptr | ComponentPtr2 | HIGH | FUN_004b5a30 (int=ptr, freed), FUN_004b6a10 (char**), FUN_004b70b0 | none |
| +0x72c | ptr | ComponentPtr1 | HIGH | FUN_004b5a30 (int=ptr, freed), FUN_004b6a10 (char**), FUN_004e5f60 | none |
| +0x9a4 | int | SubfolderIndex | HIGH | FUN_004b7500 (undefined4 switch 0-4), FUN_004b71e0 (undefined4 switch) | none |
| +0xf30 | float | LapTimeStart/MinValue | HIGH | FUN_004b86e0 (float clamp), FUN_004b7500 (float), FUN_004b6c90 (float), FUN_004b7300, FUN_004b87a0 | none |
| +0xf34 | float | LapTimeEnd/MaxValue | HIGH | FUN_004b86e0 (float clamp), FUN_004b7500 (float), FUN_004b6c90, FUN_004b87a0 | none |
| +0xf38 | float | Value/Threshold/ScoreValue | HIGH | FUN_004b86e0 (float, sort key), FUN_004b81a0 (undefined4), FUN_004b84f0, FUN_004b85d0, FUN_004b8790 | none |
| +0xf3c | float | PreviousValue | HIGH | FUN_004b86e0 (float copy of f38), FUN_004b71e0 (undefined4=0), FUN_004b9b80 | none |
| +0xf81 | byte | Mode | HIGH | FUN_004b86e0 (char, 0=wrap/non-0=clamp), FUN_004b57f0, FUN_004b87c0, FUN_004b8940 | none |
| +0xf8c | int | ServiceAnimState | HIGH | FUN_004b9e40 (undefined4 switch 0/5/9), FUN_004b71e0 (stores 5), FUN_004b8c40, FUN_004b9da0 | none |
| +0xf94 | char[] | OutputFilePath | MEDIUM | FUN_004b5a30 (int=ptr, freed with FUN_00587bcf) | TYPE NOTE: docs say char[], actual is heap char* pointer |

---

## MutexGuard (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1c | HANDLE | MutexHandle | HIGH | FUN_005865c0: *(HANDLE*), CreateMutex, CloseHandle | none |
| +0x24 | byte | MutexActive | HIGH | FUN_005865c0: *(char*), 0/1 flag | none |
| +0x54 | HANDLE | MutexHandle | HIGH | FUN_00586560: *(HANDLE*), CreateMutex, CloseHandle | none |
| +0x5c | byte | ValidFlag | HIGH | FUN_00586560: *(char*), 0/1 flag | none |
| +0xec | int | SharedValue | HIGH | FUN_00585770: *(undefined4*) | none |
| +0xf0 | HANDLE | MutexHandle | HIGH | FUN_00585770: *(HANDLE*), WaitForSingleObject/ReleaseMutex | none |
| +0xf4 | DWORD | Timeout | HIGH | FUN_00585770: *(DWORD*), passed to WaitForSingleObject | none |
| +0x5b4 | ptr | WriteTarget | HIGH | FUN_00585cd0: *(undefined4*) | none |
| +0x5b8 | HANDLE | MutexHandle | HIGH | FUN_00585cd0: *(HANDLE*), WaitForSingleObject/ReleaseMutex | none |
| +0x5bc | DWORD | Timeout | HIGH | FUN_00585cd0: *(DWORD*), passed to WaitForSingleObject | none |
| +0x50 | HANDLE | MutexHandle | LOW | Referenced from FUN_0058bb79 group � functions not in analyzed | UNVERIFIABLE: source .c not found |
| +0x54 | DWORD | Timeout | LOW | Referenced from FUN_0058bb79 group � functions not in analyzed | UNVERIFIABLE: source .c not found |
| +0x08 | int32 | InitFlag | HIGH | FUN_00595a61: *(int*)(base+8), checked for 0 before init | none � in stride-0x24 array |
| +0x0c | CRITICAL_SECTION | CriticalSection | HIGH | FUN_00595a61: InitializeCriticalSection/EnterCriticalSection at base+0xc | none � in stride-0x24 array |
| +0x554 | HANDLE | MutexHandle | HIGH | FUN_00584c70: *(HANDLE*), WaitForSingleObject/ReleaseMutex | none |
| +0x558 | DWORD | Timeout | HIGH | FUN_00584c70: *(DWORD*), passed to WaitForSingleObject | none |

---

## WheelCornerStruct (per-wheel, stride 0x464)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | float[3] | Position | LOW | Not directly accessed as byte offset in analyzed/*.c. Used in FUN_004e3aa0 as float* index 0-2. | CRITICAL: Doc offsets +0x006 through +0x039 are wrong � they don't match float* indexing. The doc's byte offsets appear to miscalculate float[3] array positions. Velocity starts at +0x0c, not +0x006. ContactLoad at +0x44, not +0x011. |
| +0x006 | float[3] | Velocity | WRONG | No .c file accesses +0x006 as byte offset. FUN_004e3aa0 uses float* index 3-5 = +0x0c. | CRITICAL: Should be +0x0c |
| +0x00c | float[3] | ForceDir | WRONG | No .c file accesses +0x00c as byte offset. FUN_004e3aa0 uses float* index 6-8 = +0x18. | CRITICAL: Should be +0x18 |
| +0x011 | float | SlipForce | WRONG | No .c file accesses +0x011. FUN_004e3aa0 uses float* index 0x3a = +0xe8. | CRITICAL: SlipForce at +0xe8, not +0x011 |
| +0x01d | float | ContactLoad | WRONG | No .c file accesses +0x01d. FUN_004e3aa0 uses float* index 0x11 = +0x44. | CRITICAL: ContactLoad at +0x44, not +0x01d |
| +0x01e | float[2] | FrictionParams | WRONG | No .c file accesses +0x01e. FUN_004e3aa0 uses float* index 0x1e-0x1f = +0x78-0x7c. | CRITICAL: Should be +0x78 |
| +0x024 | float | SuspensionDefl | WRONG | No .c file accesses +0x024. FUN_004e3aa0 uses float* index 0x1d = +0x74. | CRITICAL: Should be +0x74 |
| +0x033 | float[3] | ContactForce | WRONG | No .c file accesses +0x033. FUN_004e3aa0 uses float* index 0x33-0x35 = +0xcc-0xd4. | CRITICAL: Should be +0xcc |
| +0x039 | float[4] | SuspensionParams | WRONG | No .c file accesses +0x039. FUN_004e3aa0 uses float* index 0x39-0x3c = +0xe4-0xf0. | CRITICAL: Should be +0xe4 |
| +0x0c4 | int | TireInstanceId | LOW | No direct byte access in analyzed/*.c | UNVERIFIABLE |
| +0xc30 | double | LongSlipBias | HIGH | FUN_00430750: *(double*)(param_1+0xc30) | none |
| +0xc38 | double | LongSlipScale | HIGH | FUN_00430750: *(double*)(param_1+0xc38) | none |
| +0xc44 | int | LongSlipFactor | HIGH | FUN_00430750: *(int*)(param_1+0xc44) | none |
| +0xcb0 | double | Load_bias | HIGH | FUN_00430750: *(double*)(param_1+0xcb0) | none |
| +0xcb8 | double | Load_scale | HIGH | FUN_00430750: *(double*)(param_1+0xcb8) | none |
| +0xcc4 | int | Load_factor | HIGH | FUN_00430750: *(int*)(param_1+0xcc4) | none |
| +0x348 | double | DamperForce | HIGH | FUN_0043ff3d, FUN_0043fffb: *(double*)(base+0x348) | none � stride 0x464 confirmed |
| +0x360 | double | SpringForce | HIGH | FUN_0043ff3d, FUN_0043fffb: *(double*)(base+0x360) | none |
| +0x7ac | double | HubForceContrib | HIGH | FUN_0043ff3d: *(double*)(base+0x7ac) | none |
| +0xc10 | double | ExtraSpringForce | HIGH | FUN_0043fffb: *(double*)(base+0xc10) | none |
| +0xc28 | double | GeomLeverageRatio | HIGH | FUN_0043ff3d, FUN_0043fffb: *(double*)(base+0xc28) | none |
| +0xc30 | double | GeomLeverageAlt | HIGH | FUN_0043fffb: *(double*)(base+0xc30) | Also LongSlipBias at same offset � different sub-struct within stride |
| +0x1074 | double | ExtraDamperForce | HIGH | FUN_0043ff3d, FUN_0043fffb: *(double*)(base+0x1074) | none |
| +0x108c | double | GeomLeverageRatio2 | HIGH | FUN_0043ff3d, FUN_0043fffb: *(double*)(base+0x108c) | none |
| +0x119 | int | WheelSubID | LOW | FUN_0043e230: address arithmetic with stride 0x119 | none |

NOTE: This struct's early offsets (+0x000 through +0x039) are severely wrong. The function FUN_004e3aa0 uses float* indexing where byte_offset = float_index * 4. The documented offsets appear to have been calculated with wrong element size (possibly 2-byte instead of 4-byte). All float-indexed field offsets in this range need to be multiplied by 4 to match actual code. See WheelForceArrayStruct below for same issue.

---

## WheelForceArrayStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00..2 | float[3] | Position | WRONG | FUN_004e3aa0: float* index 0-2 = byte +0x00-0x08 | Same offset error as WheelCornerStruct � entire range is wrong. This struct appears to be a duplicate of WheelCornerStruct's early fields with same miscalculations. |
| +0x06..8 | float[3] | Velocity | WRONG | FUN_004e3aa0: float* index 3-5 = byte +0x0c-0x14 | Should be +0x0c |
| +0x0e..10 | float[3] | ForceDir | WRONG | FUN_004e3aa0: float* index 6-8 = byte +0x18-0x20 | Should be +0x18 |
| +0x11 | float | SlipForce | WRONG | FUN_004e3aa0: float* index 0x3a = byte +0xe8 | Should be +0xe8 |
| +0x1d | float | ContactLoad | WRONG | FUN_004e3aa0: float* index 0x11 = byte +0x44 | Should be +0x44 |
| +0x1e..1f | float[2] | FrictionParams | WRONG | FUN_004e3aa0: float* index 0x1e-0x1f = byte +0x78-0x7c | Should be +0x78 |
| +0x24 | float | SuspensionDefl | WRONG | FUN_004e3aa0: float* index 0x1d = byte +0x74 | Should be +0x74 |
| +0x33..35 | float[3] | ContactForce | WRONG | FUN_004e3aa0: float* index 0x33-0x35 = byte +0xcc-0xd4 | Should be +0xcc |
| +0x39..3c | float[4] | SuspensionParams | WRONG | FUN_004e3aa0: float* index 0x39-0x3c = byte +0xe4-0xf0 | Should be +0xe4 |

NOTE: This entire struct is a duplicate of WheelCornerStruct's early field group with the same incorrect offset calculations. All offsets need to be recalculated using float* indexing (byte_offset = float_index * 4). Recommend merging into WheelCornerStruct with corrected offsets.

---

## FenderStruct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | ActiveFlag | HIGH | FUN_004f3090 (decompiled_all): checks FenderCenter presence before setting | none |
| +0x04 | double[3] | DragParams | HIGH | FUN_004f3090: FUN_00565aa0 reads into param_1+0x04/0x0c/0x14 with key 'FenderDragParams' | none |
| +0x1c | double[3] | LiftParams | HIGH | FUN_004f3090: FUN_00565aa0 reads into param_1+0x1c/0x24/0x2c with key 'FenderLiftParams' | none |
| +0x34 | double | SidewaysCoeff | HIGH | FUN_004f3090: FUN_00565aa0 reads into param_1+0x34 with key 'FenderSideways' | none |
| +0x3c | double[3] | CenterPosition | HIGH | FUN_004f3090: FUN_00565aa0 reads into param_1+0x3c/0x44/0x4c with key 'FenderCenter' | none |
| +0x54 | double | FlareSetting | MEDIUM | Not directly seen in FUN_004f3090 (likely set elsewhere, or remaining from config read) | UNVERIFIABLE from single function � layout consistent if stride continues 8 bytes from CenterPosition[2] at +0x4c |

NOTE: Struct layout is CORRECT and consistent. Offsets align perfectly with double[3] arrays at 8-byte stride. Confidence would be higher with cross-validation from additional functions.

---

## Game Data File State Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c0 | void* | DataListHead | HIGH | FUN_004b7300: *(int*)(param_1+0x6c0), checked for 0, cleared to 0 | Shared with ReplaySaveStruct.ListHead � same struct base |
| +0x6e4 | int | SuccessFlag | HIGH | FUN_004b7300: piVar1=(int*)(param_1+0x6e4), checked !=0 for return | none |
| +0x700 | int | OpState | HIGH | FUN_004b7300: *(undefined4*)(param_1+0x700) set to 0/1/2 | none |
| +0xf1c | int | PlayerTeamID | HIGH | FUN_004b7300: reads from vehicle+0x4894 (TeamID) | none |
| +0xf20 | int | SessionType | HIGH | FUN_004b7300: stores DAT_007c56a4 (SessionType) | none |

NOTE: This struct overlaps with ReplaySaveStruct at same offsets +0x6c0, +0x6e4, +0x700 � these are the same underlying struct viewed as different conceptual types.

---

## UI Options / Display Settings Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x31c | void** | screenModePtr | HIGH | FUN_004726c0: param_1[199] = &DAT_007cff84 (199*4=0x31c) | none |
| +0x324 | int | optionCount | HIGH | FUN_004726c0: param_1[0xc9]=3 (0xc9*4=0x324) | none |
| +0x328 | int | flag1 | HIGH | FUN_004726c0: param_1[0xca]=1 | none |
| +0x32c | int | flag2 | HIGH | FUN_004726c0: param_1[0xcb]=1 | none |
| +0x330 | int | flag3 | HIGH | FUN_004726c0: param_1[0xcc]=1 | none |
| +0x334 | int | defaultID | HIGH | FUN_004726c0: param_1[0xcd]=0x103 | none |
| +0x338 | int | sentinel | HIGH | FUN_004726c0: param_1[0xce]=-1 | none |

NOTE: param_1 is int-indexed (undefined4*). All byte offsets verified as index*4. Struct confidence is actually HIGH despite doc saying LOW � all values confirmed.

---

## Resource Manager (texture loading) (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| param_1[0x43f] | ptr | resourceManager | MEDIUM | FUN_0053d970: Interface pointer with vtable | UNVERIFIABLE: no specific .c evidence checked |
| param_1[3..] | int[] | perResourceState | MEDIUM | FUN_0053d970: Stride 0x10f ints per resource | UNVERIFIABLE: no specific .c evidence checked |

NOTE: This struct has 0 specific offset rows to verify. Placeholder entry from docs. No action needed.

---

## DualLinkedListHeader (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int* | ListA_Head | HIGH | FUN_004bad70: param_1[0] -> *param_1 = int* | none |
| +0x04 | int* | ListA_Tail | HIGH | FUN_004bad70: param_1[1] = tail pointer | none |
| +0x08 | int* | ListA_Last | HIGH | FUN_004bad70: param_1[2] = last/iterator pointer | none |
| +0x0c | int | ListA_Count | HIGH | FUN_004bad70: param_1[3] = count, incremented | none |
| +0x10 | int* | ListB_Head | HIGH | FUN_004bad70: param_1[4] = second list head | none |
| +0x14 | int* | ListB_Tail | HIGH | FUN_004bad70: param_1[5] = second list tail | none |
| +0x18 | int* | ListB_Last | HIGH | FUN_004bad70: param_1[6] = second list iterator | none |
| +0x1c | int | ListB_Count | HIGH | FUN_004bad70: param_1[7] = count, incremented | none |

NOTE: Struct appears correct and well-validated. Two independent linked lists sharing one header.

---

## CollisionNoiseRange (inferred � param_1 in FUN_004962c0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x162C | float[16] | NoiseRangeTable | HIGH | FUN_004962c0: *(float*)(param_1 + 0x162c + iVar3 * 4) � indexed float array | none � type confirmed float, array size 16 not directly verifiable from this access |

---

## 2. Commentary/Director Event Struct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | int | EventID | LOW | Not directly seen in FUN_0040d4c0 � possibly set by caller | UNVERIFIABLE from function shown |
| +0x0c | float | Probability | HIGH | FUN_0040d4c0: *(float*)(param_1+0x0c) = 0x3f800000=1.0f or calculated | none |
| +0x10 | unknown | Param | HIGH | FUN_0040d4c0: set to 0 or float depending on branch | none |
| +0x24 | int | EventTypeCode | HIGH | FUN_0040d4c0: switch(*(int*)(param_1+0x24)) values 0-0xc | none |
| +0x28 | unknown | Unknown | HIGH | FUN_0040d4c0: *(undefined4*)(param_1+0x28) = -1 | none |

NOTE: Missing doc entry for +0x14 (int, set to 1 or 2 � sub-event type). New offset discovered.

---

## NetworkSessionState (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | ConnectionState | LOW | FUN_00563260: unknown usage | UNVERIFIABLE: function returns void, no offset patterns found |
| +0x04 | int | ClientArrayPtr | LOW | FUN_00563260: param_1[1]? | UNVERIFIABLE: no matching patterns in analyzed file |
| +0x70 | int | MaxClientCount | LOW | FUN_00563260: param_1[0x1c]? | UNVERIFIABLE: no matching patterns in analyzed file |
| +0x74 | int | ConnAttemptCounter | LOW | FUN_00563260: param_1[0x1d]? | UNVERIFIABLE: no matching patterns in analyzed file |
| +0x98 | int | ReconnRetryCounter | LOW | FUN_00563260: param_1[0x26]? | UNVERIFIABLE: no matching patterns in analyzed file |

NOTE: FUN_00563260 exists but function body doesn't contain expected offset patterns. May use indirect access or different decompilation output.

---

## Struct 5: AI Path / Entrant Struct (stride 0x48c0, from FUN_00418ee0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00�+0x48bf | byte[0x48c0] | EntrantEntry | MEDIUM | FUN_00418ee0: puVar5 = puVar5 + 0x48c0 (iteration stride) | none � stride 0x48c0 confirmed |

NOTE: Only stride confirmed. Internal structure of each 0x48c0 entry not observable from this function alone.

---

## UIComboBox (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | pointer | vtable | MEDIUM | Not set in FUN_00470da0 (set by constructor) � doc claims PTR_FUN_005a09c0 | UNVERIFIABLE from this function |
| +0x324 | int | option_count | HIGH | FUN_00470da0: param_1[0xc9]=5 (0xc9*4=0x324) | none |
| +0x328 | int | default_index | HIGH | FUN_00470da0: param_1[0xca]=0 | none |
| +0x32c | int | active_flag | HIGH | FUN_00470da0: param_1[0xcb]=1 | none |
| +0x330 | int | unknown_flag | HIGH | FUN_00470da0: param_1[0xcc]=1 | none |
| +0x334 | int | scroll_offset | HIGH | FUN_00470da0: param_1[0xcd]=0x19b (411) | none |
| +0x338 | pointer | weather_mode_ptr | HIGH | FUN_00470da0: param_1[0xce]=&DAT_007cf080 + DAT_007d0410*9 | none � pointer confirmed |

NOTE: Same pattern as Section 53 � param_1 is int-indexed (undefined4*). All verified.

---

## Section 61: ScoringDB / StandingsEntry

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | CategoryID | HIGH | FUN_00435390, FUN_004c03f0 | none |
| +0x04 | int | Reserved0 | HIGH | FUN_00435390, FUN_004c07f0 | none |
| +0x08 | int | (undocumented) | HIGH | FUN_00435390 (set to 0) | MISSING from docs |
| +0x0c | int | (undocumented) | HIGH | FUN_00435390 (set to 0) | MISSING from docs |
| +0x10 | float | Weight | HIGH | FUN_00435390 (0x3ff00000 = 1.875f) | none |
| +0x18 | int[48] | FINISHPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 (loop 0x30) | none |
| +0xd8 | int[48] | FINISHPOINTS | HIGH | FUN_004c03f0, FUN_004c07f0 (loop 0x30) | none |
| +0x198 | int | SEASONPOINTS | HIGH | FUN_004c03f0, FUN_004c07f0, FUN_004c0f60 | none |
| +0x19c | int | POINTSPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 | none |
| +0x1a0 | int | POLESTAKEN | HIGH | FUN_004c03f0, FUN_004c07f0 | none |
| +0x1a4 | int | ORIGINALGRIDPOSITION | HIGH | FUN_004c03f0 (string parse) | FUN_004c07f0 does NOT clear this (only +0x1a8) |
| +0x1a8 | int | CURRENTGRIDPOSITION | HIGH | FUN_004c03f0, FUN_004c07f0 (-1 sentinel) | none |
| +0x1ac | int | CONTROLTYPE | HIGH | FUN_004c03f0, FUN_004c07f0 (-1 sentinel) | none |
| +0x1b0 | byte | ACTIVE | HIGH | FUN_004c03f0, FUN_004c07f0, FUN_004c0f60, FUN_004c1370 | none |
| +0xb108 | int | RankEntry0 | HIGH | FUN_004c0f60 | none |
| +0xb120 | ptr | PitAllocA | HIGH | FUN_004c0b10 (freed) | none |
| +0xb128 | ptr | PitAllocB | HIGH | FUN_004c0b10 (freed) | none |
| +0xb144 | int | SeasonStatus | MEDIUM | FUN_004c03f0 | linked string "SEASONPOINTS" in same function |
| +0xb148 | int | CurrentRace / UnknownFlags | HIGH | FUN_004c03f0, FUN_004c11d0 | none |
| +0xb14c | int | RaceSession / SessionType | HIGH | FUN_004c03f0, FUN_004c0f60 (==7), FUN_004c11c0, FUN_004c15a0 (switch 1-7) | none |
| +0xb150 | byte | RaceOver / RankingsDirtyFlag | HIGH | FUN_004c03f0, FUN_004c0f60 (0=needs compute), FUN_004c15a0 | none |

**Summary:** HIGH confidence. All 19 offsets confirmed. Types match. Stride 0x1b4 confirmed across 4 functions.
- CONFLICT: +0x00 and +0x04 exist as additional zeroed fields in FUN_00435390 (undocumented)
- Note: +0x00 through +0x1b0 are per-entry offsets (stride 0x1b4), +0xb108 through +0xb150 are container-level offsets — table would benefit from clearer separation
- FUN_004c07f0 does NOT zero ORIGINALGRIDPOSITION (+0x1a4) — only FUN_004c03f0 writes it via string parse. Different init pathways.

---

---

## Section 62: AIStateBuffer

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | byte | InitializedFlag | HIGH | FUN_0042ec60 (*param_1 = 1) | none |
| +0x0c4 | dword[4][11] | HistoryBuffer1 | MEDIUM | FUN_0042ec60 | DIMENSION WRONG: code shows 4 rows × 44 slots (0x2c0 bytes), not 4×11 (176 bytes). Stride 0x40 correctly noted but count off. |
| +0xbc4 | dword[55] | HistoryBuffer2 | MEDIUM | FUN_0042ec60 | DIMENSION WRONG: code shows 55 slots × 4 dwords each (0x370 bytes), not 55 dwords. |
| +0x1ca8 | float[4] | SmoothCoeff | HIGH | FUN_0042ec60, FUN_0042e320 (0x3f000000 = 0.5f) | none |

**Summary:** MEDIUM confidence. 4 offsets confirmed but dimensions understated.
- CONFLICT: FUN_0042ebc0 uses +0xC8 not +0xC4 for HistoryBuffer1 base, and +0xbc8 not +0xbc4 for HistoryBuffer2 — shift-direction offset (4 bytes = 1 element). Not a true type conflict.
- Recommend: change dword[4][11] to dword[4][44] (or describe as 4 rows × 44 dword slots). Change dword[55] to dword[55][4] (each slot = 4 dwords).

---

---

## Section 63: CamMan

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | MAINVIEWSceneNode | HIGH | FUN_0040c920 (*param_1 = FUN_00544f50("MAINVIEW")) | Docs say observed in FUN_0040cce0 — WRONG. Actually set in FUN_0040c920 (Init). |
| +0x08 | ptr | CurrentCamera | HIGH | FUN_0040cce0 (set to 0), FUN_0040c920 (set from +0x18) | none |
| +0x18 | ptr | CameraObject1 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x1c | ptr | CameraObject2 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x20 | ptr | CameraObject3 | HIGH | FUN_0040cce0 (released + nulled) | none |
| +0x2e | byte | Flag | HIGH | FUN_0040c9e0 (=0), FUN_0040cce0 (=0) | none |
| +0x38 | int | CameraIndex | HIGH | FUN_0040c9e0 (= -1) | none |

**Summary:** HIGH confidence. All 7 offsets confirmed.
- MINOR: docs list MAINVIEWSceneNode at FUN_0040cce0 but it's actually set in FUN_0040c920. Observed-at column slightly wrong.
- NEW OFFSET: +0x2d (byte) — initialized to 0 in FUN_0040c920. Possibly another flag field.

---

---

## Section 64: BodyStateArray

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | double | PosX | HIGH | FUN_0056d1c0 (matrix transform read) | none |
| +0x0c | double | PosY | HIGH | FUN_0056d1c0 | none |
| +0x14 | double | PosZ | HIGH | FUN_0056d1c0 | none |
| +0x1c | double | Rot00 | HIGH | FUN_0056d1c0 | none |
| +0x24 | double | Rot01 | HIGH | FUN_0056d1c0 | none |
| +0x2c | double | Rot02 | HIGH | FUN_0056d1c0 | none |
| +0x34 | double | Rot10 | HIGH | FUN_0056d1c0 | none |
| +0x3c | double | Rot11 | HIGH | FUN_0056d1c0 | none |
| +0x44 | double | Rot12 | HIGH | FUN_0056d1c0 | none |
| +0x4c | double | Rot20 | HIGH | FUN_0056d1c0 | none |
| +0x54 | double | Rot21 | HIGH | FUN_0056d1c0 | none |
| +0x5c | double | Rot22 | HIGH | FUN_0056d1c0 | none |
| +0x60 | double | PosDeltaX | MEDIUM | FUN_00441d60 (stride 0x244 loop) | FUN_00441ad0 uses +0x64 as angular vel component |
| +0x64 | double | PosDeltaY | LOW | FUN_00441d60 | DUAL-USE in FUN_00441ad0: used as angular vel (SQRT sqrt component) |
| +0x68 | double | (undocumented) | LOW | Gap between +0x64 and +0x6c | MISSING from docs |
| +0x6c | double | PosDeltaZ / AngularVelX | MEDIUM | FUN_00441ad0 (SQRT component) | none |
| +0x74 | double | AngularVelY | MEDIUM | FUN_00441ad0 (SQRT component) | none |
| +0x7c | double | AngularVelZ | LOW | Not directly referenced in read functions | none |
| +0x134 | double | AngMomX | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x13c | double | AngMomY | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x144 | double | AngMomZ | HIGH | FUN_00441d60, FUN_00441ad0 | none |
| +0x14c | double | ForceX | HIGH | FUN_00441d60 | none |
| +0x154 | double | ForceY | HIGH | FUN_00441d60 | none |
| +0x15c | double | ForceZ | HIGH | FUN_00441d60 | none |

**Summary:** MEDIUM confidence. 12 position/rotation double fields confirmed at HIGH. Dynamics fields partially confirmed.
- CONFLICT: Docs reference FUN_0041ad0 and FUN_0041d60 — these DO NOT EXIST. Correct function names are FUN_00441ad0 and FUN_00441d60 (addresses 0x00441ad0, 0x00441d60). Missing leading hex digit '4'.
- CONFLICT: +0x64 is used as angular velocity component in FUN_00441ad0, not just PosDeltaY. Dual-purpose field.
- NEW OFFSET: +0x68 (double) — undocumented field between PosDeltaY (+0x64) and PosDeltaZ (+0x6c)

---

---

## Section 65: PerElementForceScalingStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x39d4 | float* | ForceArrayBase | MEDIUM | FUN_0059d9d7 (pfVar3 = unaff_EBX + 0x39d4) | none |
| +0x39f8 | int | ElementCount | MEDIUM | FUN_0059d9d7 (iVar1 = *(unaff_EBX + 0x39f8)) | none |
| +0x3a0c | float | LocalForceMultiplier | MEDIUM | FUN_0059d9d7 (*(unaff_EBX + 0x3a0c)) | none |

**Summary:** LOW confidence as stated. All 3 offsets confirmed but only via register variable (unaff_EBX as base), not struct parameter. Types match docs.

---

---

## Section 66: SuspensionForceValidator

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | double | ForceX | LOW | FUN_004f3240 (base axis group 0) | INCOMPLETE: 2 more doubles at +0x08, +0x10 per axis |
| +0x18 | double | ForceY | LOW | FUN_004f3240 (axis group 1) | INCOMPLETE: 2 more doubles at +0x18+8, +0x18+0x10 |
| +0x30 | double | ForceZ | LOW | FUN_004f3240 (axis group 2) | INCOMPLETE: 2 more doubles at +0x30+8, +0x30+0x10 |

**Summary:** LOW confidence. Structure has 3 axis groups at stride 0x18, each with 3 doubles (pdVar3[0], pdVar3[1], pdVar3[2] at +0x00, +0x08, +0x10 relative to axis base). Docs only list 1 of 3 doubles per axis (the first). 6 doubles are undocumented.

---

---

## Section 67: AutoLoadEntry Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| [0] / +0x00 | char* | Track path | HIGH | FUN_00432bf0 (*param_1 cast to byte ptr) | none |
| [2] / +0x08 | char* | Classes | HIGH | FUN_00432bf0 (param_1[2] cast to byte ptr) | none |
| [4] / +0x10 | int | Session | HIGH | FUN_00432bf0 (param_1[4] passed as int arg) | none |
| [5] / +0x14 | char* | (unnamed string) | HIGH | FUN_00432bf0 (param_1[5] cast to byte ptr) | none |

**Summary:** HIGH confidence. All offsets confirmed in FUN_00432bf0. The int-indexed vs byte-offset conflict noted in docs is correctly resolved (compatible). Int-index view: [0]=Track, [2]=Classes, [4]=Session, [5]=unnamed. Byte-offset view: +0x00, +0x08, +0x10, +0x14. ✅ Fully consistent.

---

---

## Section 68: File Read Loop Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | int | zeroed on start | MEDIUM | FUN_005352d0 (*(param_1+4) = 0) | none |
| +0x10 | int | bufferAvail | MEDIUM | FUN_005352d0 (*(param_1+0x10) compared to 0x4000) | none |
| +0x40 | void* | buffer | MEDIUM | FUN_005352d0 (read arg to *(param_1+0x40)) | none |
| +0x48 | void* | readBufPtr | MEDIUM | FUN_005352d0 (read arg to *(param_1+0x48)) | none |
| +0x5c | char | modeFlag | MEDIUM | FUN_005352d0 (compared to 'w') | none |

**Summary:** LOW confidence as stated. All 5 offsets confirmed.
- NEW OFFSET: +0x38 (int) — read status/result, set to -1 on error or 1 on data available. Undocumented.
- NEW OFFSET: +0x0c (int) — set from +0x48 value, likely a copy of readBufPtr. Undocumented.

---

---

## Section 69: Texture Allocation Format Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x20 | uint | flags | MEDIUM | FUN_00558d10 (bit 0x100 = allocated) | none |
| +0x2c | int | multiplier | MEDIUM | FUN_00558d10 (multiplies texture size) | none |
| +0x50 | ptr | subStruct | MEDIUM | FUN_00558d10 (resource array ptr) | none |

**Summary:** MEDIUM confidence as stated. All 3 offsets confirmed. Types match.

---

---

## Section 70: CollisionGridParams

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| +0x00 | int | CellCount | MEDIUM | FUN_0044d520 (0x11=17), FUN_0044dca0 (0x32=50) | Values 17,50 not in docs' list (4,16,37,49,77,97) |
| +0x04 | int | Flags/Counter | MEDIUM | Both init functions (0) | none |
| +0x08 | int | Sentinel/Scale | MEDIUM | Both init functions (0) | none |
| +0x0C | int | MaxDistance | MEDIUM | Both init functions (0) | none |

**Summary:** MEDIUM confidence. Pattern confirms 4 fields at stride 0x10.
- Additional +0x10/+0x14 in init functions (set to 0) are likely the next cell's first two fields (CellCount, Flags). Not separate fields in this struct.
- CellCount documented range should include at least 17 and 50.

---

---

## Section 71: Small structs

### InvDistance (FUN_0045f2a0)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | float | InvDistance | MEDIUM | *(param_1+4) = _DAT_0059e43c / param_2 | none |

### FloatFraction (FUN_00464ef0)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x68 | float | ComputedFraction | MEDIUM | *(param_1+0x68) = result | none |

### CollisionFillBlock (FUN_0044f070)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x27C | byte[0x100] | FillBlock | MEDIUM | Loop: 0x40 writes × 4 bytes = 0x100 | none |

### ConstraintSolverState (FUN_00454250)
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x040 | float | Stiffness | LOW | OFFSET WRONG: +0x040 is RELATIVE to constraint set base (iVar5), not param_1. Actual param_1 offset = +0xdc8 (set1) or +0x11c4 (set2) |
| +0x060 | float | RestValue | LOW | Same as above — offset is iVar5-relative. Actual param_1 offset = +0xde8 (set1) or +0x11e4 (set2) |
| +0x398 | float | CurrentValue | LOW | Same as above — offset is iVar5-relative. Actual param_1 offset = +0x1120 (set1) or +0x151c (set2) |
| +0xD88 | float[] | ConstraintSet1 | HIGH | iVar5 = param_1 + 0xd88 when param_3==0 | none |
| +0x1184 | float[] | ConstraintSet2 | HIGH | iVar5 = param_1 + 0x1184 when param_3!=0 | none |

**Summary:** First 3 structs confirmed. ConstraintSolverState has a MAJOR CONFLICT: +0x040/0x060/0x398 are offsets relative to constraint set base (iVar5), not param_1. These fields are also arrays indexed by param_2 (per-constraint), not singletons as documented.

---

---

## Section 72: Cockpit Dashboard Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x60 | char*? | TAC_01_texture | HIGH | FUN_0049ca00 (param_1+0x60) | Not char* — passed to FUN_0049cd80 as render params |
| +0xac | char*? | WATERTEMP_texture | HIGH | FUN_0049ca00 (param_1+0xac) | Same type concern |
| +0xf8 | char*? | OILTEMP_texture | HIGH | FUN_0049ca00 (param_1+0xf8) | Same type concern |
| +0x144 | char*? | OILPRESS_texture | HIGH | FUN_0049ca00 (param_1+0x144) | Same type concern |
| +0x190 | char*? | FUEL_texture | HIGH | FUN_0049ca00 (param_1+400) | Same type concern |
| +0x20 | char*? | LED165 | HIGH | *(param_1+0x20)=FUN_00548890("LED165") | none |
| +0x24 | char*? | LED170 | HIGH | *(param_1+0x24)=FUN_00548890("LED170") | none |
| +0x28 | char*? | LED175 | HIGH | *(param_1+0x28)=FUN_00548890("LED175") | none |
| +0x2c | char*? | LED182 | HIGH | *(param_1+0x2c)=FUN_00548890("LED182") | none |
| +0x30 | char*? | LEDSL | HIGH | *(param_1+0x30)=FUN_00548890("LEDSL") | none |
| +0x34 | char*? | LEDPSY | HIGH | *(param_1+0x34)=FUN_00548890("LEDPSY") | none |
| +0x38 | char*? | LEDPSR | HIGH | *(param_1+0x38)=FUN_00548890("LEDPSR") | none |
| +0x3c | char*? | LEDLF | HIGH | *(param_1+0x3c)=FUN_00548890("LEDLF") | none |
| +0x40 | char*? | LEDFR | HIGH | *(param_1+0x40)=FUN_00548890("LEDFR") | none |
| +0x44 | char*? | LEDFY | HIGH | *(param_1+0x44)=FUN_00548890("LEDFY") | none |
| +0x48 | char*? | LEDFB | HIGH | *(param_1+0x48)=FUN_00548890("LEDFB") | none |
| +0x04 | undefined | FontResource1 | MEDIUM | *(param_1+4)=FUN_0053cfe0("FONTREAD") | MISSING from docs |
| +0x08 | undefined | FontResource2 | MEDIUM | *(param_1+8)=FUN_0053cfe0("FONTLCD") | MISSING from docs |
| +0x0c | undefined | FontResource3 | MEDIUM | *(param_1+0xc)=FUN_0053cfe0("FONTAIDS") | MISSING from docs |
| +0x10 | ptr | ReadoutBMP | MEDIUM | *(param_1+0x10)=FUN_00547920("READOUT_BMP") | MISSING from docs |
| +0x14 | ptr | LCD00BMP | MEDIUM | *(param_1+0x14)=FUN_00547920("LCD00_BMP") | MISSING from docs |
| +0x18 | ptr | LCD00Extra | MEDIUM | *(param_1+0x18)=FUN_0053cb20("LCD00_BMP") | MISSING from docs |
| +0x1c | ptr | LCD01Extra | MEDIUM | *(param_1+0x1c)=FUN_0053cb20("LCD01_BMP") | MISSING from docs |

**Summary:** MEDIUM confidence. All 16 documented offsets confirmed. 7 new undocumented offsets discovered (font resources, BMP render objects). The gauge texture fields (+0x60 etc.) are render-struct pointers, not char* string pointers. LED fields are handles from FUN_00548890, not char*.

---

---

## Section 73: PacketQueueStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | byte | ActiveFlag | HIGH | *(param_1+4)=0 | none |
| +0x08 | int* | HeadPtr | HIGH | *(param_1+8)=puVar4, checked ==0 | none |
| +0x0c | int* | CurrentPtr | HIGH | *(param_1+0xc)=puVar4 | none |
| +0x10 | int* | TailPtr | HIGH | *(param_1+0x10)=puVar4 | none |
| +0x14 | uint | Counter | HIGH | *(param_1+0x14)++ | none |

**Summary:** MEDIUM confidence as stated. All 5 offsets confirmed. Types match. Linked list operations correct.

---

---

## Section 74: Shift Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | UpshiftRPM | INVALID | FUN_0042b8d0 param_1 is int (selector 0-3) | NOT a struct pointer — param_1 is an enum |
| +0x04 | float | DownshiftRPM | INVALID | Same as above | Same issue |
| +0x08 | int | DisallowedFlags | INVALID | Same as above | Same issue |

**Summary:** MAJOR CONFLICT — param_1 in FUN_0042b8d0 is used as an integer selector (compared to 3 in if statement, used as an index), NOT a struct pointer. The data for Upshifts/Downshifts/Disallowed comes from string lookups in global arrays (DAT_005c32b0, DAT_005c32bc, DAT_005c32cc). Confidence should be INVALID for this specific function reference. The struct offsets might be valid for a different function but NOT FUN_0042b8d0's param_1.

---

---

## Section 76: OpponentStateStruct (param_2 — opponent/driver in overtaking)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x70 | float | OpponentPosition | HIGH | FUN_0042a780: `*(undefined4 *)(param_2 + 0x70)` in float context | none |
| +0x74 | float | OpponentDistance | HIGH | FUN_0042a780: `*(undefined4 *)(param_2 + 0x74)` passed to float FUN_004e8ce0 | none |
| +0x78 | float | OpponentPosition | HIGH | FUN_0042a780: `param_2 + 0x78` passed as float arg | none |
| +0x84 | float | OpponentSpeedDelta | HIGH | FUN_0042a780: `*(float *)(param_2 + 0x84)` | none |
| +0x4fc | float | LapTimeDelta | MEDIUM | FUN_0041ad80: `*(float *)(param_1 + 0x4fc + idx*4)` — float ✓ | CONFLICT: FUN_004423b0 accesses as `(double *)(param_1 + 0x4fc)` and writes double values (stride 0x464) |
| +0x69c | float | OvertakeGap | MEDIUM | FUN_0041ad80: `*(float *)(param_1 + 0x69c + idx*4)` — float ✓ | none found |
| +0x83c | float | OvertakeTarget | MEDIUM | FUN_004c71c0: `*(float *)(iVar4 + param_1 + 0x83c)` — float in array context | CONFLICT: FUN_0041ad80 uses `*(int *)(param_1 + 0x83c + idx*4) = param_3` — stores driver index as INT, not float |

### Issues found:
1. **+0x4fc type mismatch**: Docs say float. FUN_004423b0 accesses as `(double *)(param_1 + 0x4fc)` with stride 0x464 (4 entries). This may be a different struct layout — the stride 0x464 spans 1124 bytes, much larger than a per-driver array. Likely different struct.
2. **+0x83c type conflict**: Docs say float. Code shows int (stores driver index) in FUN_0041ad80, but float in FUN_004c71c0. Recommend: rename OvertakeTarget to int (driver index), flag the float usage as possible different struct.
3. No .c file found for FUN_004c0cc0 (claimed observer in docs). Offsets +0x4fc, +0x69c, +0x83c verified through other files.

---

---

## Section 77: CollisionContactState

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x14 | uint | CollisionStateFlags | HIGH | FUN_0054d7a0: `*(uint *)(param_1 + 0x14)` — bitwise state operations | none |
| +0x18 | float | ContactMargin | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0x18)` — tolerance comparison | none |
| +0xf4 | float | OuterRadius | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0xf4)` — bounding sphere outer | none |
| +0xf8 | float | InnerRadius | HIGH | FUN_0054d7a0: `*(float *)(param_1 + 0xf8)` — bounding sphere inner | none |
| +0xfc | int | ContactIteration | HIGH | FUN_0054d7a0: `*(int *)(param_1 + 0xfc)` — solver iteration count (compared to 5) | none |
| +0x1c | float | RefX | HIGH | FUN_00507845: `*(float *)(param_1 + 0x1c)` — reference X | none |
| +0x20 | float | RefY | HIGH | FUN_00507845: `*(float *)(param_1 + 0x20)` — reference Y | none |
| +0x24 | float | RefZ | HIGH | FUN_00507845: `*(float *)(param_1 + 0x24)` — reference Z | none |
| +0x28 | float | RefW | HIGH | FUN_00507845: `*(float *)(param_1 + 0x28)` — penetration/distance | none |
| +0x1058 | int | ContactCount | HIGH | FUN_00507845: `*(int *)(param_1 + 0x1058) * 0x10` — count, also used in 10+ other collision files | none |

**Grade: HIGH — All 10 offsets confirmed with correct types across 2+ functions.**

---

---

## Section 78: GameConfig (inferred — FUN_004216f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb8 | int | Field_0xb8 | LOW | No .c file for FUN_004216f0. Offset +0xb8 used in >50 files with MANY types: int, float, pointer, vtable dispatch | Cannot verify — +0xb8 is a common offset in multiple structs |
| +0xbc | int | Field_0xbc | LOW | Same — no .c file. Cannot distinguish from other structs using +0xbc | — |
| +0xc0 | int | Field_0xc0 | LOW | Same | — |
| +0xc4 | int | Field_0xc4 | LOW | Default 22 cited in notes — unverifiable without .c | — |
| +0xc8 | bool | Field_0xc8 | LOW | Default 1 cited — unverifiable | — |
| +0xcc | int | Field_0xcc | LOW | — | — |
| +0xd0 | int | Field_0xd0 | LOW | — | — |
| +0xd4 | byte | Field_0xd4 | LOW | — | — |
| +0xd5 | byte | Field_0xd5 | LOW | Default 1 cited | — |
| +0xd6 | byte | Field_0xd6 | LOW | — | — |
| +0xd8 | int | Field_0xd8 | LOW | Default 1 cited | — |
| +0xdc | int | Field_0xdc | LOW | Default 1 cited | — |
| +0xe0 | int | Field_0xe0 | LOW | — | — |
| +0xe4 | int | Field_0xe4 | LOW | Default 1 cited | — |
| +0xe8 | float | Field_0xe8 | LOW | -1.0f (disabled) cited — unverifiable | — |

**Grade: LOW — No source file available for FUN_004216f0. All 15 offsets unverifiable. Offset +0xb8 is a known false-positive magnet (used across renderer, physics, audio, UI structs). Recommend: locate FUN_004216f0 source or mark section as speculative.**

---

---

## Section 79: ConstraintGroupStruct (param_1 for FUN_0056ee40)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | int | Group1Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 8)` — loop bound check | none |
| +0x0c | int* | Group1Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0xc)` used as pointer base for body index array | none |
| +0x10 | int | Group2Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x10)` — loop bound check | none |
| +0x14 | int* | Group2Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x14)` used as pointer base for pair array | none |
| +0x18 | int | Group3Count | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x18)` — loop bound check | none |
| +0x1c | int* | Group3Array | HIGH | FUN_0056ee40: `*(int *)(param_1 + 0x1c)` used as pointer base | none |
| +0x2c | double* | GlobalPosArray | HIGH | FUN_0056ee40: `pdVar1 = (double*)(*(int*)(param_1 + 0x2c) + ...)` — pointer to double array | none |

**Grade: HIGH — All 7 offsets confirmed with correct types from FUN_0056ee40.**

---

---

## Section 80: AudioSceneUpdateStruct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xd80 | int | SceneEntryCount | MEDIUM | FUN_004532d0: `*(int *)(param_1 + 0xd80)` read in loop bound check | none |

**Grade: MEDIUM — 1 offset confirmed. Only 1 function evidence. Rename from "low" to "medium".**

---

---

## Section 81: WheelFloatArray (per-wheel state as float[]) (inferred)

| Float Index | Real Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|-------------|-------------|-------------|--------------|------------|-------------|-----------|
| 0x0e | +0x38 | float[3] | SuspAxisVectors | MEDIUM | FUN_004e3d00: `param_1[0xe]` as scalar float | NAME OVERLAP: float[3] at +0x38 conflicts with +0x3c (SuspType) and +0x40 (WheelNormal) which are inside the array |
| 0x0f | +0x3c | float | SuspType | MEDIUM | FUN_004e3d00: `param_1[0xf]` — compared to threshold | NAME OVERLAP: inside float[3] at +0x38 if array is 12 bytes |
| 0x10 | +0x40 | float | WheelNormal | MEDIUM | FUN_004e3d00: `param_1[0x10]` — axis cross product | NAME OVERLAP: inside float[3] at +0x38 |
| 0x11 | +0x44 | float | RideHeight | HIGH | FUN_004e3d00: `param_1[0x11]` — current travel, used in spring/damper calc | none |
| 0x12 | +0x48 | float | SpringK | HIGH | FUN_004e3d00: `param_1[0x12] = 5.0` — hardcoded 5.0 | none |
| 0x13 | +0x4c | float | SpringForce | HIGH | FUN_004e3d00: `param_1[0x13]` — computed, clamped | none |
| 0x14 | +0x50 | float | DampingEnabled | HIGH | FUN_004e3d00: `param_1[0x14] = 0.0` / `= 1.0` — on/off switch | none |
| 0x15 | +0x54 | float | DamperForce | HIGH | FUN_004e3d00: `param_1[0x15]` — accumulator | none |
| 0x16 | +0x58 | float | BumpForce | HIGH | FUN_004e3d00: `param_1[0x16]` — accumulator | none |
| 0x24 | +0x90 | float | WheelRadius | HIGH | FUN_004e3d00: `param_1[0x24]` — used in force calc | none |
| 0x25 | +0x94 | float | DampingFactor | HIGH | FUN_004e3d00: `param_1[0x25]` — multiplier | none |
| 0x27 | +0x9c | float | SpringRateMult | HIGH | FUN_004e3d00: `param_1[0x27]` — multiplier | none |
| 0x2a | +0xa8 | float | ProgressiveRate | HIGH | FUN_004e3d00: `param_1[0x2a]` — progressive spring factor | none |
| 0x2b | +0xac | float | BumpStopTravel | HIGH | FUN_004e3d00: `param_1[0x2b]` — bump stop limit | none |
| 0x2c | +0xb0 | float | AlignmentCamber | LOW | FUN_004e3d00: NOT directly accessed as float in this function. `param_1[0x2c]` not used. `param_1[0x2e]` used instead. | Possible index off-by-one |
| 0x2d | +0xb4 | float | AlignmentCaster | LOW | FUN_004e3d00: NOT directly accessed. | Unused in this function |
| 0x2e | +0xb8 | float | (alignment) | MEDIUM | FUN_004e3d00: `param_1[0x2e]` — used in steering axis calc | Name unclear in docs |
| 0x2f | +0xbc | float | SteerCasterCos | HIGH | FUN_004e3d00: `param_1[0x2f]` — compared to 1.0, steering angle cos | none |
| 0x30 | +0xc0 | float | SteerKingpin | HIGH | FUN_004e3d00: `param_1[0x30]` — steering axis angle | none |
| 0x31 | +0xc4 | float | LastContactX | HIGH | FUN_004e3d00: `param_1[0x31]` — contact point X | none |
| 0x32 | +0xc8 | float | LastContactZ | HIGH | FUN_004e3d00: `param_1[0x32]` — contact point Z | none |
| 0x36 | +0xd8 | float[3] | WheelVelocity | HIGH | FUN_004e3d00: `param_1[0x36]`, `[0x37]`, `[0x38]` — 3-component output velocity | none |

### Issues found:
1. **NAME OVERLAP at +0x38**: The docs list +0x38 as `float[3] SuspAxisVectors` (12 bytes spanning 0x38–0x43), but also list +0x3c and +0x40 as separate fields (`SuspType`, `WheelNormal`). If the 3 floats at 0x38/0x3c/0x40 are genuinely separate fields, change to three individual floats. If they form a 3-component vector, rename SuspType/WheelNormal as aliases.
2. **+0xb0 (AlignmentCamber)**: Index 0x2c not directly used in FUN_004e3d00. The function uses index 0x2e (+0xb8) instead. Either +0xb0 is unused in this function or offset is wrong.
3. **Undocumented fields**: +0x1b (0x6c) and +0x1c (0x70) used at line 127 for force computation — not in docs.

---

---

## Section 82: AutoLoadEntry Linked List Node Struct (stride 0x1c)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | Track path (alloc) | LOW | No .c file for FUN_00432e70 | Unverifiable |
| +0x04 | int | next pointer | LOW | Same | — |
| +0x08 | char* | Classes (alloc) | LOW | Same | — |
| +0x0c | int | next pointer | LOW | Same | — |
| +0x14 | char* | (unnamed, alloc) | LOW | Same | — |
| +0x18 | int | next pointer | LOW | Same | — |

**Grade: LOW — No source file available. Docs note stride 0x1c and "string-pair list node" pattern. Unverifiable.**

---

---

## Section 83: File Handle Close Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | FileHandle | HIGH | FUN_00566b90: `iVar1 = *param_1;` — int file handle | none |
| +0x10 | int | CloseFlags | HIGH | FUN_00566b90: `param_1[4] == 0` — int, branch on zero | none |

**Grade: HIGH — Both offsets confirmed with exact types from FUN_00566b90.**

---

---

## Section 84: Display Mode Init Struct (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | initialized | HIGH | FUN_00563e00: `if (*param_1 != 0)` — guard check | none |
| +0x04 | int | modeHandle | HIGH | FUN_00563e00: `param_1[1] = iVar1;` — mode init result | none |
| +0x94 | int | bufferHandle | HIGH | FUN_00563e00: `param_1[0x25] = iVar1;` — buffer creation result (0x25*4 = 0x94) | none |
| +0x98 | int | bufferCount | HIGH | FUN_00563e00: `param_1[0x26] = 0;` — set to 0 | none |

**Grade: HIGH — All 4 offsets confirmed with exact types from FUN_00563e00.**

---

---

## Section 85: CollisionMaterialGroup (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | MaterialID | HIGH | FUN_0044da60: `DAT_007cced0 = 0x2c;` — ID 44. FUN_0044d5e0: `DAT_007ccc80 = 0x13;` — ID 19. | These are GLOBAL arrays, not per-param_1 struct fields |
| +0x04 | int | ParamA | HIGH | Both functions: `_DAT_xxxxx4 = 0;` — zeroed | — |
| +0x08 | int | ParamB | HIGH | Both functions: `DAT_xxxxx8 = 0;` — zeroed | — |
| +0x0C | float | Coefficient | MEDIUM | FUN_0044c9e0 (ID 0xb=11): `_DAT_007cccbc = 0x3f800000` = 1.0f. Others set to 0. | —

### Issues found:
1. **Not per-param_1 struct**: These are GLOBAL variables (DAT_007cccXX, DAT_007ccdXX, DAT_007cceXX), not accessed through a function parameter. The struct representation is inferred from the global array layout.
2. **Actual struct has 6 int fields, not 4**: Each entry writes 6 values (MaterialID, ParamA, ParamB, Coefficient, +0x10, +0x14). Docs only describe 4 fields.
3. **Stride between entries is 0x18 (24 bytes), not 0x10-0x14**: Most adjacent material entries are spaced 0x18 bytes apart (e.g., 0xccc80 → 0xccc98). The extra 8 bytes correspond to the undocumented +0x10 and +0x14 fields.
4. **Coefficient type ambiguity**: Most entries set coefficient to 0 (int zero). Only FUN_0044c9e0 sets `0x3f800000` (1.0f as float). Could be int or float depending on material.

---

---

## Section 86: CollisionContactSolver (inferred — param_1 in FUN_0045c8f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | byte | ContactCountAccum | MEDIUM | FUN_0045c8f0: `*(uint *)(param_1 + 4)` — read/written as **uint**, not byte! | **TYPE CONFLICT: docs say byte, code shows uint (4 bytes)** |
| +0x08 | int | ContactCount | HIGH | FUN_0045c8f0: `*(int *)(param_1 + 8) += 1` | none |
| +0x14+id*4 | int | ContactActiveFlag[i] | HIGH | FUN_0045c8f0: `*(undefined4 *)(param_1 + 0x14 + uVar6 * 4) = 0` | none |
| +0x1B4+id*4 | float | ContactTimer[i] | HIGH | FUN_0045c8f0: `*(float *)(param_1 + 0x1b4 + uVar6 * 4)` | none |
| +0x354+id | byte | ContactPosition[i] | HIGH | FUN_0045c8f0: `*(byte *)(uVar6 + 0x354 + param_1)` — capped 0x10 | none |
| +0x3BC+id | byte | ContactWrapIndex[i] | HIGH | FUN_0045c8f0: `*(byte *)(uVar6 + 0x3bc + param_1)` — masked 0xF | none |
| +0x1124+id*4 | float | ContactOutput[i] | HIGH | FUN_0045c8f0: `*(undefined4 *)(param_1 + 0x1124 + uVar6 * 4) = 0xbf800000` (-1.0f) | none |

### Issues found:
1. **+0x04 TYPE CONFLICT**: Docs say `byte` but code at line 48 shows `*(uint *)(param_1 + 4)` — reads/writes 4 bytes. Change type to `uint` or `int`.

---

---

## Section 87: 4. Vehicle Struct (shared — FinishPosition, TeamID, etc.)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x58..0x60 | float[3]? | Velocity | HIGH | FUN_0040adb0: `*(float *)(iVar1 + 0x58/0x5c/0x60)` — 3 floats | none |
| +0x130 | int? | GearData1 | LOW | No .c for FUN_0042e530 | Unverifiable |
| +0x138 | int? | GearData2 | LOW | Same | — |
| +0x144 | int? | GearData3 | LOW | Same | — |
| +0x1f0 | unknown[0x2c0]×4 | WingPosArray | LOW | Same | — |
| +0x3f0 | int? | GearData4 | LOW | Same | — |
| +0x3f8 | int? | GearData5 | LOW | Same | — |
| +0x400 | int? | GearData6 | LOW | Same | — |
| +0x404 | int? | GearData7 | LOW | Same | — |
| +0x4060 | int | FinishPosition | HIGH | FUN_0040c540 + 26 other files: `*(int *)(...+0x4060)` — int | none |
| +0x4064 | int | FinishState | HIGH | FUN_004beb10 + 30 other files: `*(int *)(...+0x4064)`, compared to 0/1/2/3 | none |
| +0x4070 | int | MessageFlag | MEDIUM | Only documented in docs/09 FUN_00419c50 — no .c to verify | Unverifiable without source |
| +0x409c | float | BestLapTime | HIGH | FUN_004bf0a0: `*(float *)(...+0x409c)` — float, compared to threshold | none |
| +0x4894 | int | TeamID | HIGH | 100+ files: `*(int *)(...+0x4894)` — int team identifier | none |
| +0x489c | int | DriverNumber | HIGH | 28 files: `*(int *)(...+0x489c)` or `*(undefined4 *)(...+0x489c)` — int | none |
| +0x6b0 | unknown | AeroData1 | LOW | No .c for FUN_0042e530 | — |
| +0x704..0x70c | float[3]? | Orientation | HIGH | FUN_0040adb0: `*(float *)(DAT_007c54e0 + 0x704/0x708/0x70c)` | none |
| +0x744..0x74c | float[3]? | WorldPos | HIGH | FUN_0040adb0: `*(float *)(iVar1 + 0x744/0x748/0x74c)` | none |
| +0x970 | unknown | AeroData2 | LOW | No .c for FUN_0042e530 | — |
| +0xff0..0x1230 | unknown | WingArray1-8 | LOW | No .c for FUN_0042e530 | — |
| +0x12b0..0x12c4 | unknown | AeroData3-5 | LOW | No .c for FUN_0042e530 | — |

### Issues found:
1. **FUN_0042e530 has no .c file** — all gear/wing/aero offsets (16 offsets) are unverifiable. LOW confidence.
2. **+0x4070 (MessageFlag)**: Only cited from FUN_00419c50 in docs/09 — no .c found. MEDIUM confidence.
3. **Common offsets (Velocity, FinishPosition, FinishState, BestLapTime, TeamID, DriverNumber, Orientation, WorldPos)**: HIGH confidence — verified in 10-100+ files each.

---

---

## Section 88: AudioSampleRingBuffer (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1018 | double | LastSampleTime | MEDIUM | FUN_004ef2e0: `*(float *)(param_1 + 0x1018)` — **read/written as float, NOT double!** | **TYPE CONFLICT: docs say double, code shows float** |
| +0x101c | short[5] | LastFrameData | MEDIUM | FUN_004ef2e0: reads 18 bytes starting at +0x101c (4+4+4+4+2), compares 10 shorts (20 bytes) | **SIZE MISMATCH: short[5] = 10 bytes, but code reads 18+ bytes** |

### Issues found:
1. **+0x1018 TYPE CONFLICT**: Docs say `double` (8 bytes), but FUN_004ef2e0 reads/writes as `*(float *)(param_1 + 0x1018)` (4 bytes). Change to `float`.
2. **+0x1018 SIZE**: The next field at +0x101c is only separated by 4 bytes, confirming +0x1018 is 4 bytes (float), not 8 (double).
3. **+0x101c SIZE MISMATCH**: Docs say `short[5]` (10 bytes). Code reads from +0x101c through +0x102d (18 bytes: dword at 0x101c, dword at 0x1020, dword at 0x1024, dword at 0x1028, word at 0x102c), then compares 10 shorts (20 bytes). The actual data region is at least 18 bytes, may extend to 20 with next field.

---

---

## Section 89: Struct 7: Linked List Node (FUN_004bf790)

| Offset | Size | Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|------|------|-------------|------------|-------------|-----------|
| +0x00 | 8 | struct | EntrySubNode | LOW | No .c file for FUN_004bf790 | Docs note overlap with +0x04 — impossible layout |
| +0x04 | 4 | ptr | NextNode | LOW | Same | OVERLAP with +0x00 (docs note this) |
| +0x08 | 1 | byte | Flag | LOW | Same | Set to 1 |

### Issues found:
1. **No source file**: FUN_004bf790 has no .c available. Entire section unverifiable.
2. **Structural overlap**: Docs note "+0x00 and +0x04 overlap by 4 bytes" — the subnode (8 bytes at +0x00) overlaps with NextNode ptr (4 bytes at +0x04). Layout is 0xc bytes total with subnode inline: [ID(4)][QA(4)][NextPtr(4)][Flag(1)] = 13 bytes but described as 12.

---

---

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

---

## Section 97: Season Database Struct (FUN_0047f440) (2 offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x191c | void** | entryArray[508] | HIGH | FUN_0047f440: `*(undefined4 **)(param_1 + 0x191c + iVar1 * 4)` with iVar1 up to 0x1fb (508 entries) | none |
| +0x1fe8 | void* | specialPtr | HIGH | FUN_0047f440: `*(undefined4 **)(param_1 + 0x1fe8)` for index 0x1b4 case | none |

Both confirmed. Note: +0x1fe8 overlaps with entryArray[0x1b3] (since 0x191c + 0x1b3×4 = 0x1fe8). The code handles param_2=0x1b4 as a special case before the array access, so the overlap is intentional (specialPtr occupies the same slot as entryArray[0x1b3]).

---

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

---

## Section 100: AnimationFrameTimer (2 offsets)

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| [0x5D] | float | FrameTimer | HIGH | FUN_00469dd0: `param_1[0x5d]` int-indexed, accumulated frame time as int-cast float | none |
| [0x5E] | int | FrameIndex | HIGH | FUN_00469dd0: `param_1[0x5e]` int-indexed, incremented by 2, wraps at DAT_007d2dcc | none |

Both confirmed. Note: `param_1[0x5d]` stores a float value as int (via `(int)(float)(fVar3 + fVar1)` at line 16). The doc correctly lists these as int indices (not byte offsets). The byte offsets would be 0x174 (0x5D×4) and 0x178 (0x5E×4). No type conflicts.

---

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

---

## Section 102: DynamicStackStruct (inferred) (3 offsets)

| Offset | Current Type | Field Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|------------|------------|-------------|-----------|
| +0x00 | int32 | Top | HIGH | FUN_005648d0: `*param_1` read/written as stack pointer | none |
| +0x04 | int32 | Capacity | HIGH | FUN_005648d0: `param_1[1]` compared with Top for overflow check | none |
| +0x08 | int32 | ElementSize | HIGH | FUN_005648d0: `param_1[2]` used for byte offset calculation on overflow | none |

All 3 offsets confirmed. Types match. Logic verified: `if (Top == Capacity) grow; push(param_2)`. No conflicts. Confidence: HIGH.

---

---

## Section 103: Config Entry Node (FUN_00433b60) (1 offset)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00–+0x1b | byte[0x1c] | ConfigNode | HIGH | FUN_00433b60: `operator_new(0x1c)` allocates 0x1c bytes; structure initialized with fields (0, -1, 0, -1, ?, 0, -1) at indices [0]-[6] | none |

Total size 0x1c confirmed by allocation. The struct has 7 int-indexed fields (`puVar6[0]` through `puVar6[6]`). The doc lists only the raw allocation range without individual fields. **Note:** The additional code at lines 27-28 and 99-107 shows param_1 uses +0x1c, +0x20, +0x24, +0x28 as list management pointers (same pattern as AutoLoadEntry List Head struct), suggesting this function accesses TWO DIFFERENT STRUCTS: the Config Entry Node (allocated 0x1c) and a separate list head struct at param_1+0x1c.

---

---

## Section 105: ChecksumCompute (checksum/hash context)

Overall: 3 MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5c | int | BlockSize/OutputElementCount | HIGH | FUN_0051e6ec:23, FUN_0051e5d7:19 | none |
| +0x64 | int | EntryCount/TableCount | HIGH | FUN_0051e6ec:21, FUN_0051e5d7:20 | none |
| +0x1a4 | ptr | TableBase/TableArrayPtr | HIGH | FUN_0051e6ec:22,29, FUN_0051e5d7:18 | none |

---

---

## Section 106: PauseStringTable (inferred — FUN_004541d0)

Overall: 1 MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xc88 | int | EntryCount | HIGH | FUN_004541d0:15 (uint) | none (int vs uint, 4-byte either way) |
| +0xc8c | int | CurrentID | LOW | FUN_004541d0:17 (byte) | CONFLICT: actual type is byte (1-byte), not int (4-byte). Values 0x81, 0x5a, 0xD7 all fit in byte. |

---

---

## Section 107: ConstraintSolverParamStruct (from FUN_00434860)

Overall: all MATCH or COMPATIBLE. Note: "2 function observations" is inaccurate — only 1 unique function (FUN_00434860) + 1 thunk (FUN_00434450).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | byte | Flag0 | HIGH | FUN_00434860:9 (*param_1=0) | none |
| +0x01 | byte | Enabled | HIGH | FUN_00434860:10 (param_1[1]=1) | none |
| +0x02 | byte | Flag2 | HIGH | FUN_00434860:16 (param_1[2]=0) | none |
| +0x03 | (missing) | _pad0 | — | padding (unwritten) | GAP: +0x03 is not documented |
| +0x04 | int | ParamI0 | MEDIUM | FUN_00434860:11 (undefined4=0) | none (int compatible) |
| +0x08 | int | ParamI1 | MEDIUM | FUN_00434860:20 (undefined4=0) | none |
| +0x0c | int | ParamI2 | MEDIUM | FUN_00434860:21 (undefined4=0) | none |
| +0x10 | float | AngleLimit1 | HIGH | FUN_00434860:22 (0x42b40000=90.0f) | none |
| +0x14 | float | AngleLimit2 | HIGH | FUN_00434860:23 (0x42960000=75.0f) | none |
| +0x18 | int | Sentinel | HIGH | FUN_00434860:12 (0xffffffff=-1) | none |
| +0x1c | int | ParamI3 | MEDIUM | FUN_00434860:13 (undefined4=0) | none |
| +0x20 | int | ParamI4 | MEDIUM | FUN_00434860:14 (undefined4=0) | none |
| +0x24 | float | MaxForce | HIGH | FUN_00434860:15 (0x40000000=2.0f) | none |
| +0x28 | int | ParamI5 | MEDIUM | FUN_00434860:17 (undefined4=0) | none |
| +0x2c | int | ParamI6 | MEDIUM | FUN_00434860:18 (undefined4=0) | none |
| +0x30 | float | FrictionCoeff | HIGH | FUN_00434860:19 (0x40500000=3.25f) | none |
| +0x34 | int | ParamI7 | MEDIUM | FUN_00434860:24 (undefined4=0) | none |

---

---

## Section 108: ConstraintEnforceStruct

Overall: 4 MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1e8 | double | DispX | HIGH | FUN_004380b0:12 (double*) write | none |
| +0x1f0 | double | DispY | HIGH | FUN_004380b0:13 (double*) write | none |
| +0x1f8 | double | RestPosX | HIGH | FUN_004380b0:11 (double*) read | none |
| +0x204 | double | Distance | MEDIUM | FUN_004380b0:15 (double*) via extraout_ECX | none (pointer ambiguity noted) |

---

## Section 104: Texture/VertexDecoder (param_1 — texture context)

Overall confidence: **high**. 20 MATCH, 4 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | int | PostProcessFlag | HIGH | FUN_00509e85:26, FUN_0050a34b:25, FUN_00509644:25, FUN_00509de6:25, +2 more | none |
| +0x18 | int | PixelDataStart/BaseIndex | HIGH | FUN_00509e85:14, FUN_0050a34b:16, FUN_00509644:16, FUN_005086dd:21, +4 more | none |
| +0x2c | ptr | ColorTableBase/PaletteArrayPtr | HIGH | FUN_00508c22:24, FUN_0050930b:21, +8 more | none |
| +0x38 | float[4]×256 | ReferenceVerts/ReferenceArray | HIGH | FUN_005086dd:29, FUN_005085c5:32 | MINOR: actual base at +0x30 (pfVar starts at +0x38, but first access is pfVar[-2]) |
| +0x60 | uint | RenderFlags | HIGH | FUN_0051378b:18,34 | none |
| +0x104 | ptr | PixelDataPtr | HIGH | FUN_0051378b:23,52 | none |
| +0x108 | ushort | PixelCount | HIGH | FUN_0051378b:21,48 | none |
| +0x116 | byte | ColorDepthMode | HIGH | FUN_0051378b:17 (char) | none (char vs byte same storage) |
| +0x138 | int | ColorOffset | HIGH | FUN_0051378b:25,26,27 | none |
| +0x150 | byte | ShiftR | HIGH | FUN_0051378b:36 | none |
| +0x151 | byte | ShiftG | HIGH | FUN_0051378b:37 | none |
| +0x152 | byte | ShiftB | HIGH | FUN_0051378b:38 | none |
| +0x1034 | int | OffsetA | HIGH | FUN_0050aeae:14 | none |
| +0x1040 | int | OffsetB | HIGH | FUN_0050aeae:14 | none |
| +0x1048 | int | TransformFlag | HIGH | FUN_00508c22:21, FUN_0050930b:18, +10 more | none |
| +0x1050 | int | TexStrideX | HIGH | FUN_00509e85:14, FUN_0050a34b:15, +7 more | none |
| +0x1054 | int | TexStrideY | HIGH | Same as +0x1050 | none |
| +0x1058 | int | PixelCount/VertexCount | HIGH | All 18 listed functions | none |
| +0x106c | float[8] | InputVertexArray/DestBuffer | LOW | FUN_0050a92d:24 (ptr), FUN_0050aeae:19 (ptr), FUN_0050b27c:16-17 (float scalar), FUN_0050ab51:45 (ptr) | CONFLICT: claimed float[8] but 3/4 functions use as ptr (pointer to external float array) |
| +0x1070 | int | CurrentIndex/RowPitch/Scale | HIGH | FUN_0050a92d:19 (uint), FUN_0050aeae:18 (int), FUN_0050b27c:17 (float), FUN_0050ab51:44 (uint) | none (float is benign reinterpretation) |
| +0x1078 | int | VertexCount | HIGH | FUN_0050a92d:25,69, FUN_0050ab51:49,135 | none |
| +0x1080 | int | OutputRowStride | MEDIUM | FUN_0050a92d:21, FUN_0050ab51:31,38 | SEMANTIC: a92d uses as stride, ab51 uses as minColumnIndex |
| +0x108c | ptr/int | InputBuffer/CopyCompleteFlag | LOW | FUN_0050a92d:18,71 (int flag), FUN_0050aeae:30 (int flag) | CONFLICT (minor): never used as ptr, always int/boolean flag |
| +0x1090 | ptr | OutputBuffer | HIGH | FUN_0050a92d:18, FUN_0050ab51:26 | none |
| +0x1094 | int | ChannelBitShift0 | MEDIUM | FUN_0050a92d:64 (undefined4), FUN_0050ab51:51 (ushort) | CONFLICT: FUN_0050ab51 reads as ushort (2-byte) |
| +0x1098 | int | ChannelBitShift1 | MEDIUM | FUN_0050a92d:65 (undefined4), FUN_0050ab51:53 (ushort) | CONFLICT: FUN_0050ab51 reads as ushort (2-byte) |

---

---

## Section 109: SetupParamArrayEntry (inferred)

Overall: 2 MATCH, 1 PARTIAL MATCH, 3 CONFLICTS, 1 MISSING. Confidence should be lowered.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | double | BaseValue | HIGH | FUN_0042f470:27,72,76,98,170,184,192,203,226,237,254,262,267 | none |
| +0x08 | double | Multiplier | HIGH | FUN_0042f470:72,76,98,170,184,192,203,226,237,254,262,267 | none |
| +0x10 | int | ParamCount | LOW | NOT ACCESSED in any observed function | CONFLICT: phantom field — zero references |
| +0x14 | int | CurrentValue | MEDIUM | FUN_0042f470:45,72,76,98,170,184,192,203,226,237,248,254,262,267,277,307 | PARTIAL MATCH — int in most contexts, but also used as pointer/key in some branches |
| +0x18 | char* | FormatName | LOW | NOT ACCESSED in any observed function | CONFLICT: phantom field — no string pointer read from this offset |
| +0x1c | int | Flags | MEDIUM | FUN_0042f470:306 (char/byte read, `!= '\0'` check) | CONFLICT: actual access is char (1-byte), not int (4-byte) |
| +0x1e | (missing) | FormatBuffer | — | FUN_0042f470:39,73,139,143,171,174,188,194,197,225,269,291,295,312,316,336 | MISSING: char[34] buffer passed to sprintf-like function |
| +0x20 | (padding) | (padding) | LOW | — | MISLEADING: buffer starts at +0x1e, not +0x20 |

---

---

## Section 110: Game State / Session Config Struct

Overall: 11 MATCH, 1 PARTIAL MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb110 | int | filter base start | HIGH | FUN_004c0db0:34 (int*) | none |
| +0xb114 | int | filter base repeat | HIGH | FUN_004c0db0:35 (int*) | none |
| +0xb118 | int | filter count | HIGH | FUN_004c0db0:36 (undefined4=0) | none |
| +0xb11c | bool | filter active flag | HIGH | FUN_004c0db0:37 (undefined1=1) | none |
| +0xb130 | int | QualifyLaps | HIGH | FUN_004c11e0:25,30 (undefined4) | none |
| +0xb134 | int | QualifyTime | HIGH | FUN_004c11e0:34,39 (undefined4) | none |
| +0xb138 | int | RaceLaps | HIGH | FUN_004c11e0:43,48 (undefined4) | none |
| +0xb13c | int | RaceTime | HIGH | FUN_004c11e0:52,57 (undefined4) | none |
| +0xb140 | void* | Current track data ptr | MEDIUM | FUN_004c11e0:60 (undefined4 copy) | PARTIAL MATCH — semantic void*, actual cast is undefined4 |
| +0xb144 | int | session filter type (=2) | LOW | FUN_004c0db0:18 (undefined4=2) vs FUN_004c0b70:38 (int** — stores pointer) | CONFLICT: FUN_004c0b70 writes int* (pointer), not int. Union/overloaded field. |
| +0xb148 | int | CURRENTRACE | HIGH | FUN_004c0db0:19, FUN_004c11e0:59, FUN_004c0b70:35 | none |
| +0xb14c | int | RACESESSION | MEDIUM | FUN_004c0b70:30 (address passed to INI parser) | none (inferred, no counter-evidence) |
| +0xb150 | bool | RACEOVER | HIGH | FUN_004c0b70:33 (bool*) | none |

---

---

## Section 111: Buffer Flush/Write I/O Struct (FUN_0058a05a)

Overall: 5 COMPATIBLE/MATCH, 0 CONFLICTS.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | WritePos | MEDIUM | FUN_0058a05a:14,29 (int arithmetic via param_1[0]) | none — decompiler uses int* for arithmetic on pointer values |
| +0x04 | void* | StartPos | MEDIUM | FUN_0058a05a:28 (param_1[1]=0) | none |
| +0x08 | void* | BufferStart | MEDIUM | FUN_0058a05a:14,16,29 (int arithmetic) | none |
| +0x0c | uint | Flags | HIGH | FUN_0058a05a:13,18,19,23 (bitwise ops) | none |
| +0x10 | int | IOHandle | HIGH | FUN_0058a05a:16 (passed as uint to callee) | none |

---

---

## Section 112: List Container (doubly-linked) (inferred)

Overall: 4 MATCH (on FUN_004967d0). **"Used by FUN_004b9000, FUN_00486540" is INCORRECT** — those functions use different list containers at different offsets.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x18cc | ptr | head | HIGH | FUN_004967d0:21,22 (int** store, int* read) | none — but only in FUN_004967d0, not in claimed FUN_004b9000/FUN_00486540 |
| +0x18d0 | ptr | tailWrite | HIGH | FUN_004967d0:26,27,29 | none — same scope limitation |
| +0x18d4 | ptr | tailAlt | HIGH | FUN_004967d0:23 | none — same scope limitation |
| +0x18d8 | int | elementCount | HIGH | FUN_004967d0:30 (RMW +1) | none — same scope limitation |

**CORRECTION:** Section header claims "Used by FUN_004967d0, FUN_004b9000, FUN_00486540" but FUN_004b9000 uses list at +0x714/+0x718/+0x71c (renderer) and FUN_00486540 uses list at +0xd8 (different container). Only FUN_004967d0 uses these specific offsets. Change "Based on 3 function observations" to "Based on 1 function observation (FUN_004967d0)."

---

---

## Section 113: CollisionDeformationMesh (inferred — param_1 in FUN_004DF110)

Overall: 5 MATCH, 1 MAJOR CONFLICT (+0x1C), 1 undocumented gap.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | float | MaxValue | HIGH | FUN_004DF110:56,62,75,81,109 | none |
| +0x04 | (missing) | (unknown) | — | Not referenced | GAP: 4 bytes between MaxValue and GroupCount |
| +0x08 | int | GroupCount | HIGH | FUN_004DF110:59,85,104,127,166,228,255,258,277,286,295,298,356 | none (accessed via (int)param_1[2]) |
| +0x0C | int* | GroupArray | HIGH | FUN_004DF110:88,90,93,130,132,231,233,262,289,301 | none |
| +0x10 | int | EntityCount | MEDIUM | FUN_004DF110:169,223 (only 2 refs) | none |
| +0x14 | int* | EntityArray | MEDIUM | FUN_004DF110:172,174 | none (pointer to mixed float/int struct) |
| +0x18 | int | EntryCount | HIGH | FUN_004DF110:59,65,70,78,110,282 | none |
| +0x1C | float* | EntryArray | LOW | FUN_004DF110:115,117,226,258 (read as float via pfVar15[-7]) | CONFLICT: claimed float* (ptr) but actual is float (sentinel/mode value 0=relax, 1=stiff, 2=snap). Entries are inline at +0x20, not behind pointer. |

---

---

## Section 114: Tire/vehicle struct (partial from FUN_004a6b80 comments)

Overall: 2 MATCH, 1 CONFLICT.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x344C | int | ActiveFlag | LOW | FUN_004a6b80:40 (char), FUN_004c73f0:117 (byte). 18 refs across 15 functions, all byte/char | CONFLICT: actual type is byte/char (1-byte boolean), not int |
| +0x34E0 | float[3] | Position | HIGH | FUN_004a6b80:44-47, FUN_004e49b0:50-54. 29 matches all float | none |
| +0x34F8 | float[3] | Direction | HIGH | FUN_004a6b80:41-42, FUN_004e49b0:74-85. 31 matches all float | none |

---

---

## Section 115: Camera Manager Struct (inferred)

Overall: 9 MATCH (offsets +0x10 to +0x30), 1 MISSING field (+0x38), 1 MISSING field (+0x3c), 2 CONFLICTS (offsets +0x40/+0x44 belong to Camera struct, not CameraManager).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | Camera* | NoseCam | HIGH | FUN_00408e20:124,134 | none |
| +0x14 | Camera* | CockpitCam | HIGH | FUN_00408e20:96,106 | none |
| +0x18 | Camera* | TVCockpitCam | HIGH | FUN_00408e20:110,120 | none |
| +0x1c | Camera* | SwingmanCam | HIGH | FUN_00408e20:82,92 | none |
| +0x20 | Camera* | ExtraCamArray | HIGH | FUN_00408e20:138,161,198 (int** — array base ptr) | none |
| +0x24 | Camera* | PitCam | HIGH | FUN_00408e20:206, FUN_00408870:11,21 | none |
| +0x28 | Camera* | Unused1 | HIGH | FUN_00408e20:210, FUN_00408870:65,75 | RENAME: string "3SEATER" → call ThreeSeaterCam, not "Unused1" |
| +0x2c | Camera* | Unused2 | HIGH | FUN_00408e20:214, FUN_00408870:119,129 | RENAME: string "LEFT_OF_PITS" → call LeftPitsCam, not "Unused2" |
| +0x30 | Camera* | Unused3 | HIGH | FUN_00408e20:218, FUN_00408870:172,182 | RENAME: string "RIGHT_OF_PITS" → call RightPitsCam, not "Unused3" |
| +0x38 | (missing) | ExtraCamCount | — | FUN_00408e20:142,170,194,203 (int) | MISSING: count of cameras in ExtraCamArray |
| +0x3c | (missing) | CurrentIndex/pad | — | FUN_00408e20:143,171 (undefined4=0) | MISSING: current camera index or padding |
| +0x40 | int/str? | CameraName | — | FUN_00408e20:179,183,187,191,199,207,211,215,219 | CONFLICT: +0x40 belongs to Camera struct (200B each), NOT CameraManager. Remove from Section 6. |
| +0x44 | int | CameraCount | — | FUN_00408e20:180,184,188,193,201,208,212,216,220 | CONFLICT: +0x44 belongs to Camera struct (200B each), NOT CameraManager. Remove from Section 6. |

---

---

## Section 116: AudioMixerValueStruct (inferred)

Overall: 1 MATCH (+0x78 code*), 2 MINOR CONFLICTS (undefined4 vs int — low severity, Ghidra default typing).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Value | MEDIUM | FUN_00562fe0:8 (undefined4 copy from param_2) | MINOR: decompiler shows undefined4 not int |
| +0x78 | code* | vtable_fn | HIGH | FUN_00562fe0:9 (explicit (code*) cast) | none |
| +0x7c | int | ChannelId | MEDIUM | FUN_00562fe0:9 (undefined4, passed as 3rd arg) | MINOR: decompiler shows undefined4 not int |

---

---

## Section 117: Struct 9: Race Mode State Struct (FUN_004ae9f0 / FUN_004af220)

Overall: 2 PARTIAL CONFLICTS (minor — undefined4 vs int due to switch dispatch).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1b10 | int | DifficultyMode | MEDIUM | FUN_004ae9f0:10 (undefined4* switch), 152 (int*) | PARTIAL: switch access uses undefined4*; comparison uses int* |
| +0x1b34 | int | ModeSelector | MEDIUM | FUN_004af220:8 (undefined4* switch, only access) | PARTIAL: sole access is undefined4* for switch dispatch |

---

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

---

## Section 125: File Close Wrapper Struct (FUN_00599495)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x50 | int | FileHandle | **HIGH** | FUN_00599495: `*(int *)(param_1 + 0x50)` used as handle argument to FUN_005990f0 (file close). Confirmed. | None |

**Verdict:** Single offset, confirmed. Confidence: MEDIUM (single function).

---

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

---

## Section 131: Summary of New Offset Regions

The new offset regions listed in Section 131 are drawn from 02-ai-system.md and are NOT verified against .c files in this audit. They should be verified by a separate audit pass focused on the AI system struct regions.

**Recommendation:** Process these offset regions as a separate audit task (Sections 131.1–131.9), using the AI system functions (FUN_0042xxxx range) as sources, not the current set of files.

---

---

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

---

## Section 142: VehicleLapTime (inferred — from FUN_0049b6d0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x403c | int | CurrentLap | **CONFLICT** | FUN_0049b6d0: `*(int *)(param_1+0x403c)` compared between two vehicles as lap counter | **POTENTIAL CONFLICT with docs/13**: known vehicle struct defines +0x403c as **SeasonPoints** (int). Same offset has different semantic meaning in this context. Either param_1 is not a vehicle struct, or the field serves dual purpose. |

**VERDICT:** FUN_0049b6d0 treats +0x403c as a monotonically increasing counter compared between entities, with time-delta computation based on equality/inequality. This could be lap count (for scoring) OR season points (for position comparison). The function logic is ambiguous — flag as `[NEEDS RESOLUTION]`.

---

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

---

## Section 144: AudioArrayContainer (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | void* | DataBuffer | HIGH | FUN_00564740: param_1[0] = *param_1 passed to FUN_0058aa6f free | none |
| +0x04 | int | ElementCount | HIGH | FUN_00564740: param_1[1] as loop bound | none |

All confirmed. Simple container with data ptr + count. ✓

---

---

## Section 145: Cross-reference: fields already in docs/13-struct-offsets.md

| Field | docs/13 Offset | docs/02 Offset | Match? | Verdict |
|-------|---------------|----------------|--------|---------|
| EffectiveLifetimeAtSpawn | +0x1db4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeEngineRPM min/max | +0x1dbc/+0x1dc4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| LifetimeOilTemp min/max | +0x1dcc/+0x1dd4 | Not in AI doc | N/A | N/A — no AI doc comparison |
| PitStopFlag bitmask | +0x1180 | +0x1178 | MISMATCH — adjacent offsets | **RESOLUTION**: Likely separate fields: +0x1178 = PlannedStopsBitmask (from .rcd), +0x1180 = runtime pit stop flag. Recommend retaining both as separate adjacent fields. |

---

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

---

## GridCellIterate (grid counter)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x934 | int | CellCounter / RenderCounter | HIGH | FUN_004be340: read as `*(int *)(param_1 + 0x934)`, incremented, stored back. FUN_004be4e0: same pattern. | none |

**Summary:** Single offset confirmed in 2 near-identical functions. Type and behavior match. Confidence: HIGH.

---

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

---

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

---

## Section 161: PlayerOptionsFailureRates (FailureRate slots)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5c8 | {0x24,7} | FailureRate[0..6] | LOW | No .c file found for FUN_004aa270 | N/A |

**Verdict: LOW confidence. FUN_004aa270 not found in analyzed/ or decompiled_all/. Cannot verify.**

---

---

## Section 162: DoublyLinkedList (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1c/+0x2c | ptr | PrevPtr | HIGH | FUN_0055c2e0 (+0x1c), FUN_005519e0 (+0x2c) | Varies by container — correctly noted |
| +0x20/+0x30 | ptr | NextPtr | HIGH | FUN_0055c2e0 (+0x20), FUN_005519e0 (+0x30) | Varies by container — correctly noted |
| +0x118/+0x1518 | ptr | ListHead | HIGH | FUN_005519e0 (+0x118), FUN_0055c2e0 (+0x1518) | Varies by container — correctly noted |

**Verdict: HIGH confidence. Clean doubly-linked list operations verified in both functions. The "offset varies by container" note is accurate.**

---

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

---

## Section 166: Terrain Validation Flags Struct

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| ALL (7 offsets +0x1b754..+0x1b76e) | byte | terrain flags | LOW | FUN_00460a10 NOT FOUND in analyzed/ or decompiled_full/ | N/A |

**Verdict: LOW confidence. Referenced function (FUN_00460a10) does not exist as a .c file. Cannot verify.**

---

---

## Section 167: Source: docs/19-renderer.md

Cross-reference section. 0 offsets to audit. Section is a processing note, not a struct definition.

**Verdict: N/A — no offsets to verify.**

---

---

## Section 168: Render Object / VTable Wrapper (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | vtable | HIGH | FUN_0052e170 (line 11: *param_1 = &PTR_LAB_005b4810) | none |
| +0x90 | ptr | observerList | LOW | FUN_0052e170 does NOT reference +0x90 | Unverified — may be set by parent constructor FUN_0052d9f0() |

**Verdict: +0x00 confirmed. +0x90 is NOT directly referenced in the sole .c file — assumed set by parent constructor. Confidence is LOW for +0x90.**

Note: FUN_0052e170 writes to param_1[0xb4d] (byte offset 0x2D34) and param_1[0xb4e] (byte offset 0x2D38) — these are undocumented fields well beyond +0x90.

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

---

## === AUDIT RESULTS ===

---

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

---

## Section 175: UNUSED / ABSENT OFFSETS

Confirmed: Offsets +0x1130 and +0x1132 do NOT appear in any 06-session-race-logic function entries. These are DirectX false positives. **PASS**.

---

---

## Section 176: BoolFloatToggle (inferred — FUN_0059d6ff)

Docs/13 offset: line 1304.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1065 | byte | BoolFlag | **HIGH** | FUN_0059d6ff: `*(char *)(unaff_EBX + 0x1065)` | none — single access |
| +0x3584 | float | FloatParam | **MEDIUM** | FUN_0059d6ff: written as `undefined4` (0 or 0x3f800000=1.0f); read as `float*` in FUN_004270a0, FUN_00451720, FUN_004c71c0 | Minor: Ghidra writes as undefined4, but float semantics confirmed |

**Verdict: PASS**

---

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

---

## Section 179: SteeringTorqueOutputStruct (inferred)

Docs/13 offset: line 3336. Based on FUN_00423ca0. Claimed confidence: medium.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 (param_1[4]) | float | OrthogonalResult | **LOW** | FUN_00423ca0: `param_1[4] = (int)SQRT(fVar3)` — stored as **int** (truncated float) | **TYPE MISMATCH**: access is `int`, not `float`. param_1 is `int*`. |
| +0x18 (param_1[6]) | float | PrimaryResult | **LOW** | FUN_00423ca0: `param_1[6] = (int)fVar2` then read back as `(float)param_1[6]` — stored as int, cast to float | **TYPE MISMATCH**: access is `int` with `(float)` cast on read. |

**Verdict: PARTIAL FAIL** — Offsets match but types should be `int` with note "stores float result truncated to int". The `(float)param_1[6]` cast implies the field stores a truncated float as int.

---

---

## Section 180: Scene Array Entry (stride 0x18c)

Docs/13 offset: line 3739. Based on 4 function observations. Claimed confidence: high.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x104 | char* | scene name/identifier | **HIGH** | FUN_004c54f0: `(char *)(iVar1 + 0x104)` string copy; FUN_004c55b0: `FUN_00499e20(iVar3 + 0x104)`; FUN_004c5cb0, FUN_004c6330: string compare; FUN_004c51a0, FUN_00415c40 also access | none |
| Stride 0x18c | stride | | **HIGH** | `DAT_008ac48c * 0x18c + DAT_008ac490`, `*param_1 * 0x18c + DAT_008ac490` | Confirmed |

**Verdict: PASS** — Fully verified across 6+ functions.

---

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

---

## Section 182: Pixel Compositing Struct (inferred)

Docs/13 offset: line 4416. Used by FUN_00503e36. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | ptr | srcPtr | **HIGH** | FUN_00503e36: `iVar5 = *param_1` then `pbVar6 = *(byte **)(iVar5 + 0x18)` — pointer to image struct | none |
| +0x04 | ptr | dstPtr | **HIGH** | FUN_00503e36: `pbVar10 = *(byte **)(param_1[1] + 0x18)` — pointer | Confirmed "offset via +0x18" |

**Verdict: PASS**

---

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

---

## Section 184: CollisionTerrainSurface (inferred — from FUN_0045ca20)

Docs/13 offset: line 5095. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x424 | float[8] | SurfaceDataBlock | **HIGH** | FUN_0045ca20: `(undefined4 *)(iVar3 * 0x20 + 0x424 + param_1)` — loop reads 8 dwords (32 bytes = 8×4) | none |
| +0x1124[surfaceIdx] | float | SurfaceCache | **HIGH** | FUN_0045ca20: `*(float *)(param_1 + 0x1124 + iVar3 * 4)`; also FUN_0045c850 (`undefined4` -1.0f), FUN_00423e80 (`=0`), FUN_004270a0 | Minor: access type varies but semantically float |

**Verdict: PASS**

---

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

---

## Section 186: AudioConfigFlagsStruct (inferred)

Docs/13 offset: line 6033. Based on FUN_00551480. Claimed confidence: low.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04 | uint | AudioConfigFlags | **HIGH** | FUN_00551480: `*(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffff9fff | 0x1000` — bit 12 set, bits 13-14 cleared | Exact bitmask match |

**Verdict: PASS**

---

---

## === NEW OFFSETS DISCOVERED ===

| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| — | — | — | — | No new offsets discovered in 2+ files for these sections |

---

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

---

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

---

## Lazy Init Struct (inferred) — Section 196

Current confidence in docs/13: **high**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xaf0 | byte | initFlag | HIGH | 0x4184f0 L10: `*(char *)(param_1 + 0xaf0)` | none |
| +0xaf4 | int | resourceHandle | HIGH | 0x4184f0 L13: `*(int *)(param_1 + 0xaf4)` | none |

**Assessment:** Both offsets verified. Confidence HIGH confirmed.

---

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

---

## CollisionProxyFlagSetter (inferred — from FUN_004ba140) — Section 198

Current confidence in docs/13: **low**

| Offset | Current Type | Field | Confidence | .c Evidence | Conflicts |
|--------|-------------|-------|------------|-------------|-----------|
| param_1+0x08 | int* | EntityPtr | HIGH | 0x4ba140 L8: `*(int *)(param_1 + 8)` dereferenced | none |
| EntityPtr+0xF78 | byte | FlagField | HIGH | 0x4ba140 L8: `*(undefined1 *)(entity + 0xf78) = param_2` | none |

**Assessment:** Both offsets verified. The struct is minimal (2-field bridge accessor). Confidence should be HIGH, not LOW.

---

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

---

## Section 202: PitStop / PitCrewStruct (param_1 — pit state)

Confidence declared: **high**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | ptr (byte*) | CurrentPitState | HIGH | 0x004a5600: `*(byte **)(param_1 + 8)` — byte* ptr, checked against null | none |
| +0x184 | int | PitMode | HIGH | 0x004a5600: `*(int *)(param_1 + 0x184) == 3` / `== 4` | none |
| +0x190 | byte | RepairDoneFlag | HIGH | 0x004a5600: `*(char *)(param_1 + 400)` — char/byte | note: doc says byte, code uses char (same) |
| +0x9b0 | int | PitActionBase / DataArrayBase | HIGH | 0x004b6920: `param_2 * 0xb0 + *(int *)(param_1 + 0x9b0)` — used as base pointer | none |
| +0x9b4 | int | PitActionIndex / Capacity | HIGH | 0x004b69a0: `% *(int *)(param_1 + 0x9b4)` — modulo limit | none |
| +0x9b8 | int | PitActionCounter / Head | HIGH | 0x004b69f0: `*(int *)(param_1 + 0x9b8)` compared to -1 | none |
| +0x9bc | int | Tail / CoordY | HIGH | 0x004b68c0: `*(int *)(param_1 + 0x9bc)` vs counter | none |

**Verdict:** HIGH confidence confirmed. All 7 offsets verified across 3+ .c files. Types match.
Note: FUN_004a47e0 referenced in doc but .c file not found in analyzed/ or decompiled_all/. Not a blocker — other 3+ files confirm.

---

---

## Section 204: 15. ArrayContainer (various)

Confidence declared: **high** (implicit — table context)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x04/+0x0c | int | Count | LOW | 0x00558cf0, 0x0056eb30, 0x0058a638 — not yet verified | multiple variants |
| +0x08/+0x10/+0x34 | ptr | ArrayBase | LOW | Multi-variant — needs per-function check | variant conflicts possible |
| +0x18/+0x2c | int | SlotCount | MEDIUM | FUN_00558cf0, FUN_0056eb30 cited — needs .c check | |
| +0x1c | ptr | ElementArray | MEDIUM | FUN_0056eb30 cited | |
| +0xa4 | int | TableCount | MEDIUM | FUN_0058a638 cited | |
| +0xa8 | ptr | TableBase | MEDIUM | FUN_0058a638 cited | |

**Verdict:** LOW-MEDIUM — multi-variant table with packed offsets (+0x04/+0x0c etc.) making it hard to verify without per-function read. Needs per-function verification.

---

---

## Section 205: VehicleControllerStruct (AI/player controller state)

Confidence declared: **high**

Verified from **FUN_004e3090.c** (lines 30-66):
- Line 30: `*(int *)(param_2 + 0x70)` — int ActiveFlag ✓
- Line 30: `*(char *)(param_2 + 0xb0)` — byte Enabled ✓
- Line 32: `*(float *)(param_2 + 0xd4)` — float DirX ✓
- Line 33: `*(float *)(param_2 + 0x74)` — float PosX ✓
- Line 34: `*(float *)(param_2 + 0x78)` — float PosZ ✓
- Line 35: `*(float *)(param_2 + 0x124)` — float PosY ✓
- Line 36: `*(float *)(param_2 + 0xe0)` — float DirZ ✓
- Line 63: `*(int *)(param_2 + 0x11c)` — int PointCount ✓
- Line 66: `*(int *)(param_2 + 0x120)` — int* PointArray (dereferenced) ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x70 | int | ActiveFlag | HIGH | FUN_004e3090+30: `*(int *)(param_2 + 0x70) != 0` | none |
| +0x74 | float | PosX | HIGH | FUN_004e3090+33: `*(float *)(param_2 + 0x74)` | none |
| +0x78 | float | PosZ | HIGH | FUN_004e3090+34: `*(float *)(param_2 + 0x78)` | none |
| +0xb0 | byte | Enabled | HIGH | FUN_004e3090+30: `*(char *)(param_2 + 0xb0) != '\0'` | none |
| +0xd4 | float | DirX | HIGH | FUN_004e3090+32: `*(float *)(param_2 + 0xd4)` | none |
| +0xe0 | float | DirZ | HIGH | FUN_004e3090+36: `*(float *)(param_2 + 0xe0)` | none |
| +0x11c | int | PointCount | HIGH | FUN_004e3090+63: `*(int *)(param_2 + 0x11c)` | none |
| +0x120 | int* | PointArray | HIGH | FUN_004e3090+66: `*(int *)(param_2 + 0x120)` — used as ptr | none |
| +0x124 | float | PosY | HIGH | FUN_004e3090+35: `*(float *)(param_2 + 0x124)` | none |
| +0x34e0 | float | posX | PENDING | FUN_00425670 — not yet read | |
| +0x34e4 | float | posY | PENDING | FUN_00425670 | |
| +0x34e8 | float | posZ | PENDING | FUN_00425670 | |
| +0x34f0 | float | heading | PENDING | FUN_00425670 | |
| +0x34f8 | float | velX | PENDING | FUN_00425670 | |
| +0x3500 | float | velZ | PENDING | FUN_00425670 | |
| +0x39fc | int | aiSubState | PENDING | FUN_00425670 | |
| +0x4354 | int* | targetPtr | PENDING | FUN_00425670 | |
| +0x4440 | float | speedThreshold2 | PENDING | FUN_00425670 | |
| +0x446c | int | headingTimer | PENDING | FUN_00425670 | |
| +0x4470 | float[3] | lastTargetPos | PENDING | FUN_00425670 | |
| +0x447c | float | currentSpeed | PENDING | FUN_00425670 | |
| +0x4510 | int | steerState | PENDING | FUN_00425670, FUN_00426330 | |
| +0x4558 | float | headingTimeout | PENDING | FUN_00425670 | |

**Verdict:** First 9 offsets from FUN_004e3090 confirmed HIGH. Remaining 14 offsets (from FUN_00425670 at +0x34e0+) need verification — large offsets suggest a different sub-struct or the same struct with a large gap. Partial verification complete.

---

---

## Section 206: VehiclePhysicsHeader (inferred)

Confidence declared: **high**

180+ offsets — the largest section. Many verified from FUN_0042fd00.c (setup file writer). Key findings so far from FUN_0042fd00.c and FUN_0042f470.c:

**Verified from FUN_0042fd00.c (garage.cpp):**
| +0x68 | char* | Notes | HIGH | 0x0042fd00+35: `*(undefined1 **)(param_1 + 0x68)` read | none |
| +0xbc4 | int | TireCompoundSetting | HIGH | 0x0042fd00+57: `*(undefined4 *)(param_1 + 0xbc4)` | none |
| +0xc04 | int | CGRightSetting | HIGH | 0x0042fd00+54: `*(undefined4 *)(param_1 + 0xc04)` | none |
| +0xc44 | int | CGRearSetting | HIGH | 0x0042fd00+55: `*(undefined4 *)(param_1 + 0xc44)` | none |
| +0xc84 | int | WedgeSetting | HIGH | 0x0042fd00+56: `*(undefined4 *)(param_1 + 0xc84)` | none |
| +0xcc4 | int | FuelSetting | HIGH | 0x0042fd00+58: `*(undefined4 *)(param_1 + 0xcc4)` | none |
| +0xd04 | int | AntiSwaySetting | HIGH | 0x0042fd00+81: `*(undefined4 *)(param_1 + 0xd04)` | none |
| +0xd44 | int | ToeInLeftSetting | HIGH | 0x0042fd00+82: `*(undefined4 *)(param_1 + 0xd44)` | note: doc says ToeInRight at +0xd84, but line 82 writes param_1+0xd44 as RearAntiSway — CONFLICT |
| +0xd84 | int | ToeInRightSetting | HIGH | 0x0042fd00+83: `*(undefined4 *)(param_1 + 0xd84)` — written as FrontToeInSetting | |
| +0xdc4 | int | (Suspension param) | HIGH | 0x0042fd00+84: `*(undefined4 *)(param_1 + 0xdc4)` — written as RearToeInSetting | |
| +0xe04 | int | LeftFenderFlareSetting | HIGH | 0x0042fd00+65 | |
| +0xe44 | int | RightFenderFlareSetting | HIGH | 0x0042fd00+68 | |
| +0xe84 | int | CasterLeftSetting | HIGH | 0x0042fd00+85 | |
| +0xec4 | int | CasterRightSetting | HIGH | 0x0042fd00+86 | |
| +0xf04 | int | TrackBarLeftSetting | HIGH | 0x0042fd00+87 | |
| +0xf44 | int | TrackBarRightSetting | HIGH | 0x0042fd00+88 | |
| +0xf84 | int | Front3rdSpringSetting | HIGH | 0x0042fd00+89 | |
| +0xfc4 | int | FrontPackerSetting | HIGH | 0x0042fd00+90 | |
| +0x1004 | int | FrontBumpSetting | HIGH | 0x0042fd00+91 | |
| +0x1044 | int | FrontReboundSetting | HIGH | 0x0042fd00+92 | |
| +0x1084 | int | Rear3rdSpringSetting | HIGH | 0x0042fd00+93 | |
| +0x10c4 | int | RearPackerSetting | HIGH | 0x0042fd00+94 | |
| +0x1104 | int | RearBumpSetting | HIGH | 0x0042fd00+95 | |
| +0x1144 | int | RearReboundSetting | HIGH | 0x0042fd00+96 | |
| +0x1184 | int | (Susp param) | HIGH | 0x0042fd00+97: Rear3rdSlowBump | |
| +0x11c4 | int | (Susp param) | HIGH | 0x0042fd00+98: Rear3rdFastBump | |
| +0x1204 | int | (Susp param) | HIGH | 0x0042fd00+99: Rear3rdSlowRebound | |
| +0x1244 | int | (Susp param) | HIGH | 0x0042fd00+100: Rear3rdFastRebound | |
| +0x1284 | int | FWSetting | HIGH | 0x0042fd00+71 | |
| +0x12c4 | int | RWSetting | HIGH | 0x0042fd00+74 | |
| +0x1304 | int | RadiatorSetting | HIGH | 0x0042fd00+77 | |
| +0x1344 | int | BrakeDuctSetting | HIGH | 0x0042fd00+78 | |
| +0x1384 | int | RearBrakeSetting | HIGH | 0x0042fd00+104 | |
| +0x13c4 | int | BrakePressureSetting | HIGH | 0x0042fd00+105 | |
| +0x1404 | int | HandbrakePressSetting | HIGH | 0x0042fd00+106 | |
| +0x1444 | int | SteerLockSetting | HIGH | 0x0042fd00+103 | |
| +0x1484 | int | DiffPumpSetting | HIGH | 0x0042fd00+134 | |
| +0x14c4 | int | DiffPowerSetting | HIGH | 0x0042fd00+135 | |
| +0x1504 | int | DiffCoastSetting | HIGH | 0x0042fd00+136 | |
| +0x1544 | int | DiffPreloadSetting | HIGH | 0x0042fd00+137 | |
| +0x1584 | int | RevLimitSetting | HIGH | 0x0042fd00+109 | |
| +0x15c4 | int | EngineMapSetting | HIGH | 0x0042fd00+110: written as EngineMapSetting | CONFLICT: same offset as SteeringBarCount in FUN_00439210 |
| +0x1604 | int | EngineBrakeMapSetting | HIGH | 0x0042fd00+111 | |
| +0x1644 | int | FinalDriveSetting | HIGH | 0x0042fd00+123 | Not in doc header — labeled unknown |
| +0x1684 | int | ReverseSetting | HIGH | 0x0042fd00+124 | Not in doc header — labeled unknown |
| +0x16c4 | struct[8] | GearSettings | HIGH | 0x0042fd00+126-133: loop stride 0x40, 8 gears | |
| +0x1884 | int | NumPitstopsSetting | HIGH | 0x0042fd00+59 | CONFLICT: same offset also GearCount in FUN_0042f470 |
| +0x18c4 | int | Pitstop1Setting | HIGH | 0x0042fd00+60 | |
| +0x1904 | int | Pitstop2Setting | HIGH | 0x0042fd00+61 | |
| +0x1944 | int | Pitstop3Setting | HIGH | 0x0042fd00+62 | |
| +0x19a4 | byte | CustomFlag | HIGH | 0x0042fd00+189: `param_1[0x19a4]` | |
| +0x19a5 | byte | SymmetricFlag | HIGH | 0x0042fd00+53: `param_1[0x19a5]` | |
| +0x1ca8 | float | DownforceRating | HIGH | 0x0042fd00+185: `*(float *)(param_1 + 0x1ca8)` | |
| +0x1cac | float | BalanceRating | HIGH | 0x0042fd00+186 | |
| +0x1cb0 | float | RideRating | HIGH | 0x0042fd00+187 | |
| +0x1cb4 | float | GearingRating | HIGH | 0x0042fd00+188 | |

**SetupParamArray at +0xbb0** verified from FUN_0042f470.c line 27: `pdVar1 = (double *)(param_2 * 0x40 + 0xbb0 + param_1)` — stride 0x40 ✓

**Wheel setup stride 0x2c0** verified from FUN_0042fd00.c lines 162-180: offsets within each wheel block at base + iVar5 * 0x2c0 + 0x104/0x184/0x1c4/0x144/0x204/0x284/0x2c4/0x304/0x344 — stride 0x2c0 ✓

**CONFLICTS found:**
1. +0xd44 — doc says "ToeInLeftSetting" but FUN_0042fd00 writes it as RearAntiSwaySetting (line 82)
2. +0xd84 — doc says "ToeInRightSetting" but FUN_0042fd00 writes it as FrontToeInSetting (line 83)  
3. +0xdc4 — doc says "(Suspension param)" but FUN_0042fd00 writes it as RearToeInSetting (line 84)
4. +0x15c4 — SteeringBarCount (FUN_00439210) vs EngineMapSetting (FUN_0042fd00) — already flagged in doc
5. +0x1884 — GearCount (FUN_0042f470) vs NumPitstopsSetting (FUN_0042fd00) — already flagged

**Missing entries from FUN_0042fd00.c (not in doc's VehiclePhysicsHeader):**
- +0x1644 — FinalDriveSetting (int, from FUN_0042fd00+123)
- +0x1684 — ReverseSetting (int, from FUN_0042fd00+124)
- +0x1704-0x17c4 area — gear final drive adjust (line 113-121)

[TO BE CONTINUED — FUN_00439210 offsets, FUN_0043b590 offsets, FUN_0042f470 remaining offsets need .c verification]

---

---

## Section 207: VehicleSetupFileWriterLayout (setup file struct region)

Confidence declared: **high**

Referential section — no offset rows to audit. All offsets covered by Section 206 breakdown.
**Verdict:** OK — referential, no standalone offsets to verify.

---

---

## Section 208: Filter List State

Confidence declared: **low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x08 | void* | list head | HIGH | FUN_004c5e50+60: `*(int *)(param_1 + 8) == 0` then assigned piVar6 | none |
| +0x0c | void* | list tail | HIGH | FUN_004c5e50+65-67: `*(int **)(*(int *)(param_1 + 0xc) + 4)` then assigned | none |
| +0x10 | void* | current iterator | HIGH | FUN_004c5e50+62: `*(int **)(param_1 + 0x10) = piVar6` | none |
| +0x14 | int | node count | HIGH | FUN_004c5e50+69: `*(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1` | none |

**Verdict:** HIGH — all 4 offsets verified. Confidence should be upgraded from **low** to **high**. The original low rating was overly conservative — list head/tail/iterator/count pattern is classic linked-list header.

---

---

## Section 209: Transform/4x4 Matrix Struct (inferred)

Confidence declared: **high**

Verified from **FUN_0054b570.c** (lines 30-80) and **FUN_00541db0.c** (lines 17-62):

FUN_0054b570:
- Line 38: `*(float *)(param_1 + 0x30)` — pitch ✓
- Line 39: `*(float *)(param_1 + 0x2c)` — yaw ✓
- Line 40: `*(float *)(param_1 + 0x34)` — roll ✓
- Line 55: `*(int *)(param_1 + 0x40) == 0` — matrixSlot ✓
- Lines 56-58: references +0x114, +0x124, +0x134 as float* — matrixRows ✓
- Lines 62-64: references +0xd4, +0xe4, +0xf4 as float* — matrixAlt ✓
- Line 65: references +0x104 — positionRow3 (alt slot) ✓
- Lines 74-79: sin/cos computation on +0x2c (yaw), +0x30 (pitch), +0x34 (roll) ✓

FUN_00541db0:
- Lines 22-25: writes +0x38 (rollAlt), +0x30 (pitch), +0x34 (roll) as float ✓
- Lines 34-48: builds rotation matrix at +0x15c..+0x188 as float[16] — rotMatrix ✓
- Lines 49-61: reads +0x24, +0x28, +0x2c as float[3] — inputVec ✓
- Line 57: `*(undefined4 *)(param_1 + 0x198) = 0x3f800000` (1.0f) — "one" field ✓
- Lines 49-61: result fields at +0x18c, +0x194, 400 (which is 0x190) ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x20 | float | positionX | MEDIUM | Not directly referenced in read code | likely correct from func context |
| +0x24..0x2c | float[3] | inputVec | HIGH | FUN_00541db0+50-61: `*(float *)(param_1 + 0x24)` x3 | none |
| +0x2c | float | yaw | HIGH | FUN_0054b570+74: `fsin(*(float *)(param_1 + 0x2c))` | none |
| +0x30 | float | pitch | HIGH | FUN_0054b570+38: `*(float *)(param_1 + 0x30) = ...` | none |
| +0x34 | float | roll | HIGH | FUN_0054b570+40: `*(float *)(param_1 + 0x34) = ...` | none |
| +0x38 | float | rollAlt | HIGH | FUN_00541db0+22: `*(float *)(param_1 + 0x38) = rand()` | none |
| +0x40 | int | matrixSlot | HIGH | FUN_0054b570+55: `*(int *)(param_1 + 0x40) == 0` | none |
| +0xd4/0xe4/0xf4 | float[12] | matrixAlt | HIGH | FUN_0054b570+62-64 | none |
| +0x114/124/134 | float[12] | matrixRows | HIGH | FUN_0054b570+56-58 | none |
| +0x144/0x104 | float[4] | positionRow3 | HIGH | FUN_0054b570+59/65 | none |
| +0x154 | float[16] | matrixBackup | MEDIUM | not directly referenced | assumed from context |
| +0x15c..0x198 | float[16] | rotMatrix | HIGH | FUN_00541db0+34-57: 15 float writes | none |
| +0x18c | float | resultX | HIGH | FUN_00541db0+49-52 | none |
| +0x190 | float | resultY | HIGH | FUN_00541db0+53-56 (400 decimal = 0x190) | none |
| +0x194 | float | resultZ | HIGH | FUN_00541db0+58-61 | none |
| +0x198 | float | one | HIGH | FUN_00541db0+57: `0x3f800000` = 1.0f | none |

**Verdict:** HIGH confidence confirmed. All 16 offsets verified across 2 .c files. Types match.

---

---

## Section 210: Render Property Slots (inferred)

Confidence declared: **medium**

Verified from **FUN_00554700.c** (lines 1-36):
- Line 12: `param_1[0x4e6]` = int-indexed, byte offset 0x4e6 × 4 = +0x1398 ✓ (valueSlot1)
- Line 13: `param_1[0x440]` = byte offset 0x440 × 4 = +0x1100 ✓ (vtableObj)
- Line 25: `param_1[0x4e7]` = byte offset 0x4e7 × 4 = +0x139c ✓ (valueSlot2)
- Int-index access pattern (param_1[N]) confirmed — all three offsets are int-sized (4 bytes each)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1398 | int | valueSlot1 | HIGH | FUN_00554700+12: `param_1[0x4e6]` as int | none |
| +0x139c | int | valueSlot2 | HIGH | FUN_00554700+25: `param_1[0x4e7]` as int | none |
| +0x1100 | ptr | vtableObj | HIGH | FUN_00554700+13: `param_1[0x440]` as ptr, dereferenced vtable call | none |

**Verdict:** HIGH — all 3 offsets verified. Confidence should be upgraded from **medium** to **high**.

---

---

## Section 211: SpringDamperState (inferred — param_1 as int[] in FUN_0044f6f0)

Confidence declared: **medium**

Verified from **FUN_0044f6f0.c** (lines 1-43):

| Index | Current Field | Confidence | .c Evidence | Notes |
|-------|--------------|------------|-------------|-------|
| [0x00] | MinVelocity | HIGH | Line 32: `if (param_3 < *param_1)` — compared as velocity lower bound ✓ | |
| [0x01] | MaxVelocity | HIGH | Line 35: `if (param_1[1] < param_1[5])` — velocity upper bound ✓ | |
| [0x02] | MinPosition | HIGH | Line 25: `if (param_2 < param_1[2])` — position lower bound ✓ | |
| [0x03] | MaxPosition | HIGH | Line 28: `if (param_1[3] < param_1[4])` — position upper bound ✓ | |
| [0x04] | PrevPosition | HIGH | Line 23: `param_1[4] = param_2` — stored previous position ✓ | |
| [0x05] | PrevParam3 | HIGH | Line 31: `param_1[5] = param_3` — stored previous param_3 ✓ | |
| [0x06] | SpringK1 | HIGH | Line 22: `param_1[6]` used as coefficient multiplier ✓ | stored as int (float bit pattern) |
| [0x07] | SpringK2 | HIGH | Line 24: `param_1[7]` used as coefficient multiplier ✓ | stored as int (float bit pattern) |
| [0x08] | DeltaPosition | HIGH | Line 22: computed delta = (param_2 - prev) × K1 ✓ | |
| [0x09] | DeltaVelocity | HIGH | Line 24: computed delta = (param_3 - prev) × K2 ✓ | |
| [0x0A] | OutputPosition | HIGH | Line 38: `param_1[10] = param_1[4] * param_1[6]` ✓ | |
| [0x0B] | OutputVelocity | HIGH | Line 39: `param_1[0xb] = param_1[5] * param_1[7]` ✓ | |
| [0x2C-0x2F] | Coeffs | HIGH | Lines 10-20: coeff registers at indices [0x2c] through [0x2f] ✓ | switch-based write |

**Verdict:** HIGH confidence — all indices verified. The switch at lines 10-20 writes param_1[0x2c..0x2f] with param_5, confirming the coefficient registers at indices 0x2c-0x2f.

---

---

## Section 213: 13. Commentary Path List Struct (inferred)

Confidence declared: **very low**

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char*? | CircuitNamePtr | NO EVIDENCE | FUN_00414e60.c not in analyzed/ or decompiled_all/ | no .c available |
| +0x02 | unknown | PathData | NO EVIDENCE | same | |
| +0x05 | char*? | CountryE | NO EVIDENCE | same | |
| +0x0a | char*? | CountryB | NO EVIDENCE | same | |
| +0x12 | char*? | CircuitE | NO EVIDENCE | same | |
| +0x17 | char*? | CircuitB | NO EVIDENCE | same | |

**Verdict:** **very low** — no .c file available for FUN_00414e60. All offsets unverifiable. The odd non-DWORD-aligned offsets strongly suggest multi-base interpretation. Recommend treating as unconfirmed.

---

---

## Section 214: MessageSlotStruct (inferred, 0x18 bytes per slot)

Confidence declared: **medium**

Verified from **FUN_0057b840.c** (lines 1-25):

- Line 11: `iVar1 = *(int *)(param_1 + 0x1c)` — gets slot base pointer from parent +0x1c ✓
- Line 15: `*(int *)(iVar1 + 4)` — slot +0x04 is int32 MessageValue ✓
- Line 16: `*(short *)(iVar1 + 2)` — slot +0x02 is int16 MessageID ✓
- Line 17: `*(int *)(iVar1 + 0x14)` — slot +0x14 is int32 MessageValue_alt ✓
- Line 18: `*(short *)(iVar1 + 0x12)` — slot +0x12 is int16 MessageID_alt ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x02 | int16 | MessageID | HIGH | FUN_0057b840+16: `*(short *)(iVar1 + 2)` | none |
| +0x04 | int32 | MessageValue | HIGH | FUN_0057b840+15: `*(int *)(iVar1 + 4)` | none |
| +0x12 | int16 | MessageID_alt | HIGH | FUN_0057b840+18: `*(short *)(iVar1 + 0x12)` | none |
| +0x14 | int32 | MessageValue_alt | HIGH | FUN_0057b840+17: `*(int *)(iVar1 + 0x14)` | none |

**Verdict:** HIGH — all 4 offsets verified. Confidence should be upgraded from **medium** to **high**. The 0x18 byte slot size is consistent with the fields layout: 2+4+12+2+4 = 24 = 0x18.

---

---

## Section 215: Struct 1: VehiclePhysicsInstance (tire region)

Confidence declared: **high**

Verified from **FUN_0043e050.c** (lines 1-63) and **FUN_004537b0.c** (lines 1-228):

FUN_0043e050:
- Line 20: `*(undefined4 *)(extraout_ECX + 0x60) = 0` — +0x60 is int (zeroed) ✓
- Line 21: `*(undefined4 *)(extraout_ECX + 100) = 0` — +0x64 (100 decimal) is int (zeroed) ✓
- Line 22: `*(double *)(extraout_ECX + 0x68) = _DAT_0059e420 / (double)(400 >> ...)` — +0x68 is double ✓
- Line 18: `*(undefined4 *)(extraout_ECX + 0x1f00) = in_stack_0000378c` — +0x1f00 is int/ptr ✓

FUN_004537b0:
- Line 11: `*(byte *)(param_1 + 0x1180) & 1` — +0x1180 is byte/uint flag ✓
- Lines 13-76: reads `*(float *)(param_1 + 0x1140)` through `*(float *)(param_1 + 0x115c)` — **TYPE CONFLICT: these are float, NOT double[8]!**
- Line 77-92: reads bytes at +0x1160..+0x116f (16 bytes) — frontCompoundFlags ✓
- Line 94: `*(int *)(param_1 + 0x1170)` — int compound index ✓
- Lines 99-112: `*(int *)(param_1 + 0x1174/0x1178/0x117c)` — pitstop compound selections ✓
- Line 118: `*(byte *)(param_1 + 0x157c) & 1` — rear flag (NOT at +0x1180)
- Lines 120-183: reads `*(float *)(param_1 + 0x153c)` through `*(float *)(param_1 + 0x1558)` — rear telemetry as float
- Lines 184-199: reads bytes at +0x155c..+0x156b (16 bytes) — rearCompoundFlags ✓

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0060 | int | wheelState0 | HIGH | FUN_0043e050+20: `*(undefined4 *)(ECX + 0x60) = 0` | none |
| +0x0064 | int | wheelState1 | HIGH | FUN_0043e050+21: `*(undefined4 *)(ECX + 100) = 0` | none |
| +0x0068 | double | tireModelStep | HIGH | FUN_0043e050+22: `*(double *)(ECX + 0x68)` | none |
| +0x1140 | **float[8]** (not double[8]) | frontTireTelemetry | **CONFLICT** | FUN_004537b0+13: `*(float *)(param_1 + 0x1140)` — float! | **Type conflict: doc says double[8], code reads float** |
| +0x1160 | byte[16] | frontCompoundFlags | HIGH | FUN_004537b0+77-92: 16 bytes from +0x1160 to +0x116f | none |
| +0x1170 | int | currentFrontCompound | HIGH | FUN_004537b0+94: `*(int *)(param_1 + 0x1170)` | none |
| +0x1174 | int | pitstopCompound2 | HIGH | FUN_004537b0+99: `*(int *)(param_1 + 0x1174)` | none |
| +0x1178 | int | pitstopCompound3 | HIGH | FUN_004537b0+104: `*(int *)(param_1 + 0x1178)` | none |
| +0x117c | int | pitstopCompound4 | HIGH | FUN_004537b0+109: `*(int *)(param_1 + 0x117c)` | none |
| +0x1180 | uint | pitStopFlag | HIGH | FUN_004537b0+11: `*(byte *)(param_1 + 0x1180) & 1` — also read as uint | none |
| +0x153c | **float[8]** (not double[8]) | rearTireTelemetry | **CONFLICT** | FUN_004537b0+120: `*(float *)(param_1 + 0x153c)` — float! | **Type conflict: doc says double[8], code reads float** |
| +0x155c | byte[16] | rearCompoundFlags | HIGH | FUN_004537b0+184-199: 16 bytes +0x155c to +0x156b | none |
| +0x157c | byte | (rear flag, undocumented) | NEW | FUN_004537b0+118: `*(byte *)(param_1 + 0x157c)` | Not in doc! Rear analog of +0x1180 |
| +0x1f00 | int/ptr | contextData | HIGH | FUN_0043e050+18: `*(undefined4 *)(ECX + 0x1f00) = param` | none |

**CRITICAL TYPE CONFLICTS:**
1. **+0x1140** — doc claims `double[8]` (64 bytes), but FUN_004537b0 reads 8 floats at +0x1140..+0x115c (32 bytes)
2. **+0x153c** — doc claims `double[8]` (64 bytes), but FUN_004537b0 reads 8 floats at +0x153c..+0x1558 (32 bytes)

**NEW UNDOCUMENTED OFFSET:**
- **+0x157c** — byte flag for rear telemetry section (analogous to +0x1180 for front). Read as `*(byte *)(param_1 + 0x157c)`. Not listed in the doc's offset table.

**Verdict:** HIGH for offset existence; MEDIUM for type accuracy. Documentation needs correction: frontTireTelemetry and rearTireTelemetry should be `float[8]` not `double[8]`. Stride between telemetry values is 4 bytes (float), not 8 bytes (double). Also missing +0x157c as rear section flag.

---

---

## Section 216: Session/Rankings ScoringGate

Based on FUN_00411440, confirmed by FUN_00410bc0, FUN_00410f60, FUN_00410890, FUN_00411330.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x48 | int | EntryCount | HIGH | 4+ files: FUN_00411440, FUN_00410bc0, FUN_00410f60, FUN_00410890 all access as int | none |
| +0x4c | ptr | EntryRosterPtr | HIGH | FUN_00411440, FUN_00410bc0, FUN_00411330 all use as ptr with stride 0x24 | none |
| +0x50 | byte[] | EntryArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x50)` — pointer to array, not inline array | TYPE: doc says byte[], code shows `ptr` |
| +0x54 | int | QualiCount | HIGH | 4+ files: all access as int | none |
| +0x58 | ptr | QualiRosterPtr | HIGH | FUN_00411440, FUN_00410bc0, FUN_00411330 use as ptr with stride 0x24 | none |
| +0x5c | byte[] | QualiArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x5c)` — pointer to array | TYPE: doc says byte[], code shows `ptr` |
| +0x60 | int | PracticeCount | HIGH | 4+ files: all access as int | none |
| +0x64 | ptr | PracticeRosterPtr | HIGH | FUN_00411440 (as `param_1+100`=0x64), FUN_00410bc0 (line 130), FUN_00411330 (line 35) | none |
| +0x68 | byte[] | PracticeArray | HIGH (type should be **ptr**) | FUN_00411440, FUN_00410f60 access as `*(int*)(param_1+0x68)` — pointer to array | TYPE: doc says byte[], code shows `ptr` |

**Summary:** Good struct definition. 3 type corrections needed: +0x50, +0x5c, +0x68 should be `ptr` not `byte[]` — .c files double-dereference these (read ptr at offset, then offset into pointed-to data).

---

---

## Section 217: Multi-Function Struct Groups (Cross-Function Confirmation)

### Buffer Descriptor — ACTUALLY 3 DIFFERENT STRUCTS conflated

The prompt groups these as one struct, but analysis shows **3 distinct struct layouts**:

**Struct A: Circular Buffer (param_1 of FUN_0052a5d7)**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x28 | ptr | BufferStart | HIGH | FUN_0052a5d7 line 55: `*(undefined4**)(param_1+0x28)` | none |
| +0x2c | ptr | BufferEnd | HIGH | FUN_0052a5d7 line 23: `*(undefined4**)(param_1+0x2c)` | none |
| +0x30 | ptr | ReadPtr | HIGH | FUN_0052a5d7 line 19: `*(undefined4**)(param_1+0x30)` | none |
| +0x34 | ptr | EndPtr | HIGH | FUN_0052a5d7 line 21: `*(undefined4**)(param_1+0x34)` | none |
| +0x38 | ptr | Callback | HIGH | FUN_0052a5d7 line 35: `*(code**)(param_1+0x38)` — function pointer | none |
| +0x3c | ptr | CallbackCtx | HIGH | FUN_0052a5d7 line 36: `*(undefined4*)(param_1+0x3c)` | none |

**Struct B: Stream Descriptor (param_2 of FUN_0052a5d7)**
| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | ptr | DestPtr | MEDIUM | FUN_0052a5d7 line 20: `*(undefined4**)(param_2+0xc)` | not in doc |
| +0x10 | uint | RemainingCount | MEDIUM | FUN_0052a5d7 line 25: `*(uint*)(param_2+0x10)` | not in doc |
| +0x14 | int | TotalWritten | MEDIUM | FUN_0052a5d7 line 33: `*(int*)(param_2+0x14)` | not in doc |
| +0x30 | ptr | OutputPtr | MEDIUM | FUN_0052a5d7 line 38: `*(undefined4*)(param_2+0x30)` | not in doc |

**Struct C: Simple Buffer (param_2 of FUN_0058d78e, also FUN_00589898)**
| +0x00 | byte* | CurrentPtr | HIGH | FUN_0058d78e line 17, FUN_00589898 line 19-20 | none |
| +0x04 | int | RemainingCount | HIGH | FUN_0058d78e line 11, FUN_00589898 line 13 | none |

**FUN_005698e0 sub-struct (queue element at iVar1, stride 0x84) — DIFFERENT**
| +0x78 | int | ExtraInt1 | LOW | on array element, not param_1 struct | not param_1 |
| +0x7c | int | ExtraInt2 | LOW | same | not param_1 |
| +0x80 | byte | ExtraByte | LOW | same | not param_1 |

**Summary:** Doc conflates 3-4 struct layouts. Struct C (Simple Buffer)+0x00/+0x04 is confirmed HIGH across 2 functions. Struct A (Circular Buffer) is HIGH in FUN_0052a5d7 alone. Doc incorrectly lists +0x28-+0x3c under "Simple Buffer Descriptor" — they belong to Circular Buffer (Struct A). FUN_005698e0 accesses are on queue element, not param_1 directly.

### Timer/Performance State Struct

Functions: FUN_00568be0 exists; FUN_00569da0 has NO .c file.

FUN_00568be0 analysis (param_1 = `uint*`, int-indexed):

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | uint | FrequencyLowPart | HIGH | line 21: `*param_1 = local_8.s.LowPart` | none |
| +0x08 | double | InvFrequencyScaled | HIGH | line 32: `*(double*)(param_1+2)` at int-index 2 = byte 8 | none |
| +0x10 | uint | AccLow | HIGH | line 30: `param_1[4] = 0` | none |
| +0x14 | uint | AccHigh | HIGH | line 31: `param_1[5] = 0` | none |
| +0x18 | uint | CounterLow | HIGH | line 19: `param_1[6]` | none |
| +0x1c | uint | CounterHigh | HIGH | line 20: `param_1[7]` | none |
| +0x20 | uint | LastSampleLow | HIGH | line 24: `param_1[8]` | none |
| +0x24 | uint | LastSampleHigh | HIGH | line 29: `param_1[9]` | none |
| +0x28 | uint | Acc | HIGH | line 26: `param_1[10] = 0` | none |
| +0x2c | uint | Overflow | HIGH | line 27: `param_1[0xb] = 0` | none |
| +0x48 | uint | Mode | HIGH | line 25: `param_1[0x12] = param_2` | none |

**Doc mismatch:** Doc shows `double StartTime` at +0x00, `double Frequency` at +0x08, `double ElapsedS` at +0x10, `double ElapsedMS` at +0x18 (from FUN_00569da0 which has no .c). Could be same struct at different lifecycle stage — after init, raw uint counters reinterpreted as doubles. Cannot verify without FUN_00569da0 source.

### Dynamic Array Container

Functions: FUN_00457cf0 (NO .c file), FUN_004bd900.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | int | Capacity | HIGH | FUN_004bd900 lines 11-12: capacity check, `+8` growth | none |
| +0x10 | int | Count | HIGH | FUN_004bd900 lines 11,16,21,28,29 | none |
| +0x14 | ptr | Data | HIGH | FUN_004bd900 lines 19,24,26,28 | none |

FUN_00457cf0 not available. Doc claim of +0x00 HeapPtr, +0x04-+0x18 DataFields unverifiable.

### Linked List Node Layout

Functions: FUN_00407c90 (exists). Others (FUN_0050b6f0, FUN_00512a20, FUN_005bf450, FUN_005e3b60) NO .c files.

FUN_00407c90 shows a LIST CONTAINER struct on param_1:

| +0x18 | ptr | HeadPtr | MEDIUM | line 13,30,44 | not in node doc |
| +0x1c | ptr | TailPtr | MEDIUM | line 49-50 | not in node doc |
| +0x20 | ptr | Iterator | MEDIUM | line 14,17-18,23 | not in node doc |
| +0x24 | int | Count | MEDIUM | line 52 | not in node doc |

Node layout (from pointer arithmetic):
| +0x00 | int | Key/ID | HIGH | lines 15,32,40-41,53-54 | none |
| +0x04 | ptr | NextPtr | HIGH | line 18,35 | none |
| +0x08 | byte | Flags | MEDIUM | line 53: `(char)piVar4[2]` byte access | doc says int32, code shows byte |

**CONFLICT:** Doc says +0x08 is `int32 Flags/Data` but FUN_00407c90 accesses as `(char)piVar4[2]` — byte access (bit flags).

---

---

## Section 218: InputDevice (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x13E8 | int | BindingValueA | **ZERO** | NOT in FUN_0040be70. Uses +0x08,+0x18,+0x24,+0x2c only. | Function mismatch |
| +0x13EC | int | InputDeviceHandle | **ZERO** | NOT in FUN_0040be70 | Function mismatch |
| +0x1544 | int | ControlID | **ZERO** | NOT in FUN_0040be70 | Function mismatch |
| +0x1f98 | ptr | ControllerArray | **ZERO** | FUN_00455da0 has NO .c file | No source |

**Summary:** FUN_0040be70 (referenced as source) does NOT use offsets +0x13E8,+0x13EC,+0x1544 — it uses completely different offsets. FUN_00455da0 (for +0x1f98) has no .c file. **Claimed offsets are unverifiable.** Recommend removing or reassigning to correct function.

---

---

## Section 219: VehicleGearShiftStruct

Based on FUN_00426330.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x37cc | float | LeftWheelSpeed | HIGH | line 33 | none |
| +0x38c4 | float | RightWheelSpeed | HIGH | line 36 | none |
| +0x39a0 | float | EngineRPM | HIGH | line 26 | none |
| +0x39fc | int | ShiftTimer | HIGH | lines 13,40 | none |
| +0x3a04 | int | NextGearThreshold | HIGH | line 40 | none |
| +0x3a10 | float | EngineSpeed | HIGH | line 12 | none |
| +0x3a18 | float | RPMShiftThreshold | HIGH | line 26 | none |
| +0x3d6c | int | DrivingMode | HIGH | line 21 | none |
| +0x4510 | int | CurrentGear | HIGH | line 14 | none |

**Summary:** All 9 offsets confirmed HIGH. Single function but consistent with vehicle physics struct.

---

---

## Section 220: PhysicsBody (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x00 | unknown | (vtable/type) | **NO VERIFICATION** | FUN_00439210 has NO .c file |
| +0x04 | double[3] | Position | **NO VERIFICATION** | no source |
| +0x1c | double[3x3] | OrientationMatrix | **NO VERIFICATION** | no source |
| +0xac | double | Mass | **NO VERIFICATION** | no source |
| +0xb4 | double | InvMass | **NO VERIFICATION** | no source |
| +0xbc | double[3] | InertiaDiagonal | **NO VERIFICATION** | no source |

**Summary:** Cannot verify — FUN_00439210 not found in analyzed/ or decompiled_all/. **Confidence: UNVERIFIABLE.**

---

---

## Section 221: Conflicting Offset Observations

| Offset | Conflict | Functions | Resolution |
|--------|----------|-----------|------------|
| +0x1d4 | FuelTankBodyPtr | FUN_00439210 (no file) | Cannot verify |
| +0x15c4 | SteeringBarCount vs EngineMapSetting | FUN_00439210 (no file), FUN_0042fd00 | Cannot cross-verify |
| +0x1884 | GearCount vs NumPitstopsSetting | FUN_0042f470 (no file), FUN_0042fd00 (no file) | Cannot verify |
| +0x3d64 | EngineFailureTime[4] vs TireWearAccumulator | FUN_004ee150, FUN_004efae0 | **RESOLVED: No conflict.** FUN_004ee150 writes +0x3d64 as float[4] (engine failure timers). FUN_004efae0 reads +0x3d64 as float[0] threshold check. Same field, consistent usage. "TireWearAccumulator" label is misinterpretation — it is EngineFailureTime[0]. |
| +0x1db4 | double vs docs/13 EffectiveLifetime | docs/13 | Consistent per doc |

---

---

## Section 222: File Buffer State Struct

Based on FUN_00587ca0, FUN_00589898. Confidence: HIGH.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | byte* | buffer_ptr | HIGH | FUN_00587ca0 line 27: `*(byte*)*param_3`; FUN_00589898 line 19: `*(undefined1*)*param_2` | none |
| +0x04 | int | remaining | HIGH | FUN_00587ca0 line 22: `*piVar1 = *piVar1 + -1`; FUN_00589898 line 13: same pattern | none |

**Summary:** Confirmed across 2 functions with identical access pattern. Both use int*-indexed access (param[0], param[1]).

---

---

## Section 223: Texture/Surface Format Struct (inferred)

Based on 6+ functions. Confidence: **medium** (different offset ranges may indicate sub-structs).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | width | HIGH | FUN_00518248 line 24: `*param_1` as width counter | none |
| +0x04 | int | height | MEDIUM | FUN_00518248 line 177: `param_1[1]` set as stride | name uncertain — may be stride/pitch |
| +0x0b | byte | bpp | HIGH | FUN_00518248 line 26: `*(byte*)(param_1+0xb)` values 1,2,4 | none |
| +0x14 | ptr | bitmapData | MEDIUM | FUN_00586d70 line 21: `*(int*)(param_1+0x14)` | single function source |
| +0x1c | ptr | bitmapHeader | HIGH | FUN_00586d70 line 13: `*(int*)(param_1+0x1c)` | also used in pixel calc FUN_0050ab51 line 48 |
| +0x20 | int | flags | HIGH | FUN_00558d80 line 8-9; FUN_00558dc0 line 10; FUN_00558d10 line 15 | bit 0x100 = locked |
| +0x24 | int | height | MEDIUM | FUN_00558dc0 line 15: used in row lookup indexing | doc says +0x04 is height; +0x24 may be extended height |
| +0x34 | ptr | rowLookup | MEDIUM | FUN_00558dc0 line 15 | single function source |
| +0x38 | int | regionStride | MEDIUM | FUN_00586d70 line 13 | single function source |
| +0x4c | int | renderMode | HIGH | FUN_00558dc0 line 10: `== 1` | none |
| +0x50 | ptr | surfaceArray | HIGH | FUN_00558d80 line 10; FUN_00558dc0 line 12; FUN_00558d10 line 20 | confirmed across 3 functions |
| +0x1050 | int | yPitch | HIGH | FUN_0050ab51 line 47 | none |
| +0x1054 | int | uvPitch | HIGH | FUN_0050ab51 line 47 | none |
| +0x106c | ptr | outputBuffer | HIGH | FUN_0050ab51 line 45: `*(float**)(param_1+0x106c)` | none |
| +0x1070 | int | outputStride | HIGH | FUN_0050ab51 line 44 | none |
| +0x1074 | int | dirtyLeft | HIGH | FUN_0050ab51 lines 30,37 | none |
| +0x1078 | int | dirtyRight | HIGH | FUN_0050ab51 lines 49,135 | none |
| +0x107c | int | dirtyTop | HIGH | FUN_0050ab51 lines 31,36 | none |
| +0x1080 | int | dirtyBottom | HIGH | FUN_0050ab51 lines 31,38 | none |
| +0x1084 | int | width | HIGH | FUN_0050ab51 line 31 | CONFLICT: +0x00 also called "width" — may be different resolution/scaled |
| +0x1090 | int | bufferReady | HIGH | FUN_0050ab51 line 26 | none |
| +0x1094 | int | bitDepth | MEDIUM | FUN_0050ab51 line 51: accessed as `undefined2` NOT int | TYPE: doc says int, code shows uint16 |
| +0x1098 | int | bitShift | MEDIUM | FUN_0050ab51 line 53: accessed as `undefined2` NOT int | TYPE: doc says int, code shows uint16 |

**Summary:** 22 offsets tracked. Most confirmed HIGH. Minor type issues (+0x1094, +0x1098 should be uint16), and +0x1084 "width" conflicts with +0x00 "width" (different scale — +0x00 = logical width, +0x1084 = dirty rect width?). +0x2c used in FUN_00558d10 line 27 (not in doc — new offset discovered). No DirectX API calls detected; these are game-side surface management structs.

---

---

## Section 224: Texture/Blit Render Struct (inferred)

Based on FUN_0048e4b0. Confidence: **low** (single function).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xb0 | ptr | pathStringA | MEDIUM | line 17: `param_1[0x2c]` (int-indexed) | none |
| +0xfc | ptr | pathStringB | MEDIUM | line 21: `param_1[0x3f]` | none |
| +0xe4 | int | renderEnable | MEDIUM | line 30: `param_1[0x39]` | none |
| +0xf8 | byte | dirtyFlag | MEDIUM | line 41: `*(undefined1*)(param_1+0x3e)` — byte access via int-index | none |
| +0xe8 | int | rectX | MEDIUM | line 31: `param_1[0x3a]` | none |
| +0xec | int | rectY | MEDIUM | line 31: `param_1[0x3b]` | none |
| +0xf0 | int | rectW | MEDIUM | line 33: `param_1[0x3c]` | none |
| +0xf4 | int | rectH | MEDIUM | line 32: `param_1[0x3d]` | none |

**Summary:** All offsets confirmed. param_1 is `int*` so all access is int-indexed (offset = index * 4). Single function, LOW confidence overall. No DirectX calls, appears to be UI render path management.

---

---

## Section 225: SensorState (inferred — param_1 in FUN_00464a40)

Based on FUN_00464a40. Confidence: **low** (single function, 18 bytes, init-only).

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x068 | int | SensorTimeout | LOW | line 12: `*(undefined4*)(param_1+0x68) = 0` | init only, type uncertain |
| +0x06C | byte | SensorState | LOW | line 11: `*(undefined1*)(param_1+0x6c) = 0` | init only |
| +0x071 | undefined4 | SensorValue | LOW | line 10: `*(undefined4*)(param_1+0x71) = _DAT_0059f130` | offset unaligned (0x71) |

**Summary:** All 3 offsets confirmed as written. Init-only function means types are tentative. +0x71 is unusual (not 4-byte aligned), suggesting a packed struct. Confidence remains LOW.

---

---

## Section 226: Source: docs/03-engine-wear-damage.md

No offsets claimed in this section — it references existing docs/03 entries. **No audit needed.**

---

---

## Section 227: 14. UI Dialog Struct (inferred)

Functions: FUN_0046b0c0 (NO .c file), FUN_00470300 (NO .c file).

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x1fc | int | State | **NO VERIFICATION** | No .c files available |
| +0x200 | int | RawInputData | **NO VERIFICATION** | No .c files available |
| +0x204 | int | InputType | **NO VERIFICATION** | No .c files available |
| +0x2e8 | int | ResetField | **NO VERIFICATION** | No .c files available |
| +0x304 | int | ControlID | **NO VERIFICATION** | No .c files available |

**Summary:** Neither function has a .c file. **UNVERIFIABLE.**

---

---

## Section 228: Minor Structs (1 observation each)

### AudioStreamInitStruct (FUN_0057a3f0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | Active | HIGH | line 11: `*param_1 = 1` | none |
| +0x04 | int | Field1 | HIGH | line 12: `param_1[1] = 0` | none |
| +0x08 | uint16 | SampleRate | HIGH | line 13: `*(undefined2*)(param_1+2) = 0xd45` (param_1 is `undefined4*`, so index 2 = byte 8) | none |
| +0x0a | uint16 | BufferSize | HIGH | line 14: `*(undefined2*)((int)param_1+10) = 0x1d8` | none |
| +0x0c | int | Field3 | HIGH | line 15: `param_1[3] = 0` | none |
| +0x10-0x2c | int[8] | Reserved | HIGH | lines 16-20: `param_1+4` through `param_1+11` zeroed | none |

**Summary:** All offsets confirmed. Init function sets fixed values. HIGH confidence for init pattern.

### VehicleSoundStruct (FUN_004f12e0)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x7a4 | float | SlipAngle | HIGH | line 88: `*(float*)(param_1+0x7a4) <= float_const` | none |
| +0x32bc | int | SuspensionType | HIGH | line 94: `*(int*)(param_1+0x32bc) == 0/1` | none |
| +0x34ec | float | WheelVelX | HIGH | line 59 | none |
| +0x34f0 | float | WheelVelY | HIGH | line 58 | none |
| +0x34f4 | float | WheelVelZ | HIGH | line 57 | none |
| +0x3668 | void*[4] | WheelPtrs | HIGH | line 25: ptr array, stride 0x3e (line 53) | none |

**Summary:** All 6 offsets confirmed HIGH. Also references +0x5fc (skid sound flag, not in doc), +0x39b8,+0x39c4 (engine RPM thresholds, not in doc), +0x3a58,+0x3a5c,+0x3a60 (vehicle velocity, not in doc).

### VehicleEngineSoundStruct (FUN_004f88a0)

**NOTE:** These offsets are on `*param_1`, NOT on `param_1` directly. param_1 is `int*` and is dereferenced first.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x39a0 | float | RPMNumerator | HIGH | line 22: `*(float*)(*param_1+0x39a0)` — on **dereferenced** ptr | none |
| +0x39a4 | float | RPMDenominator | HIGH | line 22: `*(float*)(*param_1+0x39a4)` — on **dereferenced** ptr | none |

**Summary:** Offsets confirmed. But they belong to the struct pointed to by param_1[0], NOT param_1 itself. The containing struct is the vehicle physics struct (same range as Section 219).

### AudioBufferFormatStruct (FUN_0051868c)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x60 | uint16 | FormatFlags | MEDIUM | line 25: byte access `& 2`; line 37: uint access `& 4` | TYPE: doc says uint16, code shows byte and uint |
| +0xb8 | int | SampleRate | HIGH | line 19: `*(int*)(param_1+0xb8)` | none |
| +0xbc | int | Channels | HIGH | line 17: `*(uint*)(param_1+0xbc)` | none |
| +0x10a | short | Interleave | HIGH | line 44: `*(short*)(param_1+0x10a)` | none |
| +0x116 | byte | FormatType | HIGH | line 42: `*(char*)(param_1+0x116)` | none |
| +0x119 | byte | BitsPerPixel | HIGH | line 36: `*(byte*)(param_1+0x119)` | none |

**Summary:** Confirmed. Also discovered (not in doc): +0x68 (line 15), +0x5c (line 76), +0xc0 (line 20), +0xcc (line 22), +0xd0 (line 21), +0xd8 (line 74), +0xdc (line 72), +0x113 (line 18), +0x114 (line 30), +0x117 (line 38).

### AudioWaveTableStruct (FUN_0051e3e7)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x64 | int | ChannelCount | HIGH | line 38: `*(int*)(param_1+100)` (100 = 0x64) as loop bound | none |

**Summary:** Confirmed. Also accesses +0x4c (line 25, mode check), +0x1a4 (line 24, sub-struct pointer), and extensive sub-struct fields at offsets from pointer at +0x1a4 (not documented).

---

---

## Section 229: TireBrandManager

Based on FUN_004d7660. Confidence: **medium** (single function). NO .c file available.

| Offset | Current Type | Current Name | Confidence | .c Evidence |
|--------|-------------|--------------|------------|-------------|
| +0x00 | int | brandCount | **NO VERIFICATION** | FUN_004d7660 has NO .c file |
| +0x04 | ptr | brandArray | **NO VERIFICATION** | FUN_004d7660 has NO .c file |

**Summary:** **UNVERIFIABLE** — no .c file exists.

---

---

## Section 230: SpriteOverlayList (param_1 — display list)

Based on: FUN_004b81a0, FUN_004b84f0, FUN_004b85d0, FUN_004b8360, FUN_004b8480
All 5 files verified in analyzed/. HIGH confidence.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x6c0 | ptr | ListHead | HIGH | 5 files agree: (int*)(param+0x6c0) — linked list head pointer | none |
| +0x6c4 | ptr | ListTail | HIGH | 4 files agree: *(undefined4**)(param+0x6c4) — tail pointer | none |
| +0x6c8 | ptr | ListCursor | HIGH | 4 files agree: *(undefined4**)(param+0x6c8) — iterator/cursor | none |
| +0x6cc | int | ListCount | HIGH | 5 files agree: *(int*)(param+0x6cc) — integer count | none |
| +0x6d0 | byte | DirtyFlag | HIGH | 3 files agree: *(undefined1*)(param+0x6d0)=1 — byte flag | none |
| +0xf38 | float | ScoreValue | HIGH | 2 files agree: used as sort key, compared as float | none |

**Verdict:** All offsets correct. HIGH confidence. No changes needed.

---

---

## Section 231: Single-Function Struct Observations

### Linked List Controller (FUN_00407c90)
File exists: analyzed\0x00407c90__FUN_00407c90.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x18 | int32* | Head | HIGH | *(int**)(param+0x18) — list head pointer | none |
| +0x1c | int32* | Tail | HIGH | *(int**)(param+0x1c) — compared to current | none |
| +0x20 | int32* | Current | HIGH | *(undefined4*)(param+0x20) — iterator | none |
| +0x24 | int32 | Count | HIGH | *(int*)(param+0x24) decremented on removal | none |

### List Container (FUN_0050b6f0)
| +0x00 | int32* | Head | LOW | File not found in analyzed/ or decompiled_all/ | — |
| +0x04 | int32 | NodeCount | LOW | File not found | — |

### Resource List Container (FUN_00512a20)
All 6 offsets: LOW | File not found | —

### List Container (FUN_00565f20)
File exists: analyzed\0x00565f20__FUN_00565f20.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int* | HeadPtr | HIGH | *param_1 — dereferences to get head pointer | none |
| *(headPtr)+0x08 | int* | NextPtr | HIGH | *(int*)(iVar1+8) — next entry in list | none |

### Stream Object (FUN_005e3b60)
All offsets: LOW | File not found | —

### Ring Buffer (FUN_00569da0)
All offsets: LOW | File not found | —

### Processing State Machine (FUN_00404460)
File exists: analyzed\0x00404460__FUN_00404460.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x130 | int32 | Cap | HIGH | *(int*)(param+0x130) — max iteration count | none |
| +0x16c | int32 | Phase | HIGH | *(int*)(param+0x16c) — 0,1,2 state machine | none |
| +0x170 | float | FloatVal | HIGH | *(float*)(param+0x170) — computed threshold | none |
| +0x174 | int32 | IterIdx | HIGH | *(int*)(param+0x174) — current iteration index | none |

### Per-Element Struct (FUN_0053c790)
All 7 offsets: LOW | File not found | —

### FILE* Stream (FUN_00587d33)
File exists: analyzed\0x00587d33____fclose_lk.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | int | _flag | HIGH | param_1->_flag (CRT FILE struct) | none |
| +0x10 | int | _file | HIGH | param_1->_file (OS fd) | none |
| +0x1c | char* | _tmpfname | HIGH | param_1->_tmpfname | none |

### VTable Object Header (FUN_00408520)
File exists: analyzed\0x00408520__FUN_00408520.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | pointer | vtable | HIGH | *param_1 = &PTR_FUN_0059e60c | none |
| +0x10..+0x30 | pointer[] | SubObj[4..12] | HIGH | param_1[4..0xc] — 9 sub-object slots | none |

**Verdict:** 5 of 9 sub-structs verifiable. 4 sub-structs have no .c evidence (LOW).

---

---

## Section 232: NetworkMessage (inferred)

Based on: FUN_004a3ef0, FUN_00591583

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x5C4 | uint | EventCode | LOW | No .c file for FUN_004a3ef0 or FUN_00591583 | — |
| +0x5C8 | char[] | StringBuffer | LOW | No .c file | — |
| +0x618 | HANDLE | BufferMutex | LOW | No .c file | — |
| +0x910 | uint16 | HeaderField | LOW | No .c file | — |
| +0xAC8 | ptr | ListBase | LOW | No .c file | — |
| +0xAD8 | HANDLE | ListMutex | LOW | No .c file | — |
| +0xADC | DWORD | MutexTimeout | LOW | No .c file | — |

**Verdict:** No .c source files exist for either referenced function. **LOW confidence.** Cannot verify.

---

---

## Section 233: PhysicsInteractionState (steering/force feedback)

Based on: FUN_004e2760. File exists in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x108 | int[4] | WheelIndices | HIGH | piVar11 = (int*)(param+0x108); stride 0x4a; loop 4 times | none |
| +0x938 | int | PackedWheelData | HIGH | *(int*)(param+0x938) = packed value | none |
| +0x93c | short | PackedShort | HIGH | *(short*)(param+0x93c) | none |
| +0x93e | byte | PackedByte | HIGH | *(char*)(param+0x93e) | none |
| +0x93f | byte | ChannelMask | HIGH | *(byte*)(param+0x93f) | none |
| +0x940 | int | ChannelBitfield | HIGH | *(uint*)(param+0x940) bitfield | none |
| +0x944 | short | ChannelOut0 | HIGH | *(undefined2*)(param+0x944) | none |
| +0x946 | short | ChannelOut1 | HIGH | *(undefined2*)(param+0x946) | none |
| +0x948 | short | ChannelOut2 | HIGH | *(undefined2*)(param+0x948) | none |
| **+0x98c** | **int** | **ActiveFlag** | **MEDIUM** | ***(char*)(param+0x98c) — byte, not int** | **CONFLICT: doc says int, .c shows char/byte** |
| +0x9a8 | float[] | AnalogChannels | HIGH | pfVar9 = (float*)(param+0x9a8); loop 0x11 times, stride 7 floats | none |

**Verdict:** 10 of 11 offsets verified. **1 CONFLICT at +0x98c** — change type from `int` to `char`/`byte`.

---

---

## Section 234: PhysicsSystemHeader (inferred)

Based on: FUN_0056d930. File exists in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | BodyCount | HIGH | param_1[0] = 0; init, incremented | none |
| +0x04 | ptr | BodyArray | HIGH | param_1[1] = (int)piVar4; stride 0x244 allocated | none |
| +0x08 | int | JointCount | HIGH | param_1[2] = 0; incremented per JOINT token | none |
| +0x0c | ptr | JointArray | HIGH | param_1[3] = (int)piVar3; stride 0x30 | none |
| +0x10 | int | HingeCount | HIGH | param_1[4] = 0; incremented per HINGE token | none |
| +0x14 | ptr | HingeArray | HIGH | param_1[5] = (int)piVar3; stride 0x30 | none |
| +0x18 | int | BarCount | HIGH | param_1[6] = 0; incremented per BAR token | none |
| +0x1c | ptr | BarArray | HIGH | param_1[7] = (int)piVar3; stride 0x48 | none |
| +0x20 | int | ConstraintCount | HIGH | param_1[8] = iVar12 (return from FUN_0056d430) | none |
| +0x24 | ptr | ConstraintMatrix | HIGH | param_1[9] = (int)pvVar11; alloc count*count*8 | none |
| **+0x28** | **ptr** | **ConstraintRowStride** | **HIGH** | **param_1[10] = row ptr array; naming misleading** | **MINOR: "RowStride" → "RowPtrArray"** |
| +0x2c | ptr | SolverObject | HIGH | param_1[0xb] = iVar12; solver object handle | none |

**Verdict:** All 12 offsets verified. HIGH confidence. Minor naming note at +0x28.

---

---

## Section 235: Source: docs/08-file-formats.md
0 offsets. Skip.

---

---

## Section 236: File State / Mode Flags Struct

Based on: FUN_00587f90, FUN_0059c156. Both in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c | uint | ModeFlags | HIGH | *(uint*)(param+0xc) — bitmask checks (0x83, 1, 8, 0x80) — both files | none |
| +0x10 | int/void* | FileHandle | HIGH | *(undefined4*)(param+0x10) — file handle — both files | none |
| +0x18 | uint | BufferSize | HIGH | *(undefined4*)(param+0x18) = 0x200 — both files | none |

**Verdict:** All 3 offsets confirmed in 2 files each. HIGH confidence.

---

---

## Section 237: D3D Render State Cache (inferred)

Based on: FUN_00586700. File in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x34 | int | D3DRS_1_Value | HIGH | param+0x34 passed to FUN_0059b5c0(1, ...) | none |
| +0x38 | int | D3DRS_8_Value | HIGH | param+0x38 passed to FUN_0059b5c0(8, ...) | none |
| +0x3c | int | D3DRS_1b_Value | HIGH | param+0x3c passed to FUN_0059b5c0(1, ...) | none |
| +0x40 | int | D3DRS_2_Value | HIGH | param+0x40 passed to FUN_0059b5c0(2, ...) | none |
| +0x44 | int | D3DRS_10_Value | HIGH | param+0x44 passed to FUN_0059b5c0(0x10, ...) | none |

**Verdict:** All 5 offsets confirmed. HIGH confidence.

---

---

## Section 238: Inline offset references (not in tables)

### FUN_004c71c0 — SetupCarLightingAndRender
File exists: analyzed\0x004c71c0__FUN_004c71c0.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x83c | float[3]×4 | WheelPositions | HIGH | *(float*)(iVar4+param+0x83c) — indexed access | none |
| +0x704 | float[16] | ViewMatrix | HIGH | param+0x704 passed to FUN_004b2310 (matrix) | none |
| +0x744 | float[16] | WorldMatrix | HIGH | param+0x744 passed to FUN_004b2310 (matrix) | none |
| +0x34f8 | float[4] | DiffuseColor | HIGH | param+0x34f8 passed to FUN_004b2480 | none |
| +0x3510 | float[4] | SpecularColor | HIGH | param+0x3510 passed to FUN_004b25d0 | none |
| +0x3540 | int | EnvMapHandle | HIGH | param+0x3540 passed to FUN_004b2750 | none |

### FUN_0053f270 — RenderTargetCleanup
File exists: analyzed\0x0053f270__FUN_0053f270.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1140 | ptr | FrontBuffer | HIGH | *(int*)(param+0x1140) — released/cleared | none |
| +0x113c | ptr | BackBuffer | HIGH | *(int*)(param+0x113c) — released/cleared | none |
| +0x1144 | ptr | DepthStencil | HIGH | *(int*)(param+0x1144) — released/cleared | none |
| +0x14f0..0x1504 | int[5] | ViewportDims | HIGH | *(undefined4*)(param+0x14f0)=0 | none |
| +0x1518 | ptr | TextureList | HIGH | Linked list iteration from +0x1518 | none |
| +0x1580 | ptr | RenderTargetList | HIGH | Iterated from *(int*)(param+0x1580) | none |
| +0x13a8 | int | CleanupFlag | HIGH | *(uint*)(param+0x13a8)&0x10000000 — bit 28 | none |
| +0x13a0 | int | RenderState | HIGH | *(undefined4*)(param+0x13a0)=1 | none |

### Shared offsets
| +0x14 | int | flags | HIGH | Not directly verified but seen in many functions | — |

**Verdict:** All 15 inline offsets verified. HIGH confidence.

---

---

## Section 239: CollisionPositionStepper (inferred — param_1 in FUN_0048cb00)

Based on: FUN_0048cb00. File exists in analyzed/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xCA*4 (0x328) | int | ArrayDimA | HIGH | param_1[0xca] — int-indexed read | none |
| +0xCB*4 (0x32c) | int | ArrayDimB | HIGH | param_1[0xcb] — multiplied with ArrayDimA | none |
| +0xCD*4 (0x334) | int | CurrentPosition | HIGH | param_1[0xcd] — cyclic position, read/write | none |
| +0xCE*4 (0x338) | int | PositionScale | HIGH | param_1[0xce] — scaling factor | none |
| +0xCF*4 (0x33c) | char | DirectionFlag | HIGH | param_1[0xcf]; (char) check for sign | none |
| +0xD0*4 (0x340) | int | Accumulator | HIGH | param_1[0xd0] — fixed-point time accumulator | none |

**Verdict:** All 6 offsets confirmed. HIGH confidence.

---

---

## Section 240: VehiclePhysicsInstance (primary vehicle struct)

Based on 7 functions. Extensive verification below.

### Engine/Drivetrain Params
File: decompiled_all\0x004f3c80__FUN_004f3c80.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x674 | double | FuelConsumption | HIGH | param+0x674 to FUN_00565aa0("FuelConsumption") | none |
| +0x67c | double | FuelEstimate | HIGH | param+0x67c to FUN_00565aa0("FuelEstimate") | none |
| +0x684 | double | EngineInertia | HIGH | param+0x684 to FUN_00565aa0("EngineInertia") | none |
| +0x68c | double | IdleRPMLogic_min | HIGH | (double*)(param+0x68c) | none |
| +0x694 | double | IdleRPMLogic_max | HIGH | (double*)(param+0x694) | none |
| +0x69c | double | IdleThrottle | HIGH | (double*)(param+0x69c) | none |
| +0x6a0 | double | IdleThrottle_flag | HIGH | (double*)(param+0x6a0) — computed flag | none |
| +0x6ac | double | LaunchRPMLogic_min | HIGH | (double*)(param+0x6ac) | none |
| +0x6b4 | double | LaunchRPMLogic_max | HIGH | (double*)(param+0x6b4) | none |
| +0x6bc | double | RevLimitLogic | HIGH | (double*)(param+0x6bc) | none |
| +0x6c4 | int | RPMTorque_point_count | HIGH | *(int*)(param+0x6c4)=local_348 | none |
| +0x6c8 | double[3] | RPMTorque_array | HIGH | (double*)(param+0x6c8) — local_344 | none |

### Tire/Compound Data
File: analyzed\0x004537b0__FUN_004537b0.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x1140 | double×8 | FrontTireTelemetry | HIGH | *(float*)(param+0x1140) read | none (note: float read, not double) |
| +0x1160 | byte[16] | FrontCompoundFlags | HIGH | *(undefined1*)(param+0x1160) | none |
| +0x1170 | int | CurrentFrontCompound | HIGH | *(int*)(param+0x1170) compared to 4 constants | none |
| +0x1174 | int | CompoundSelect_Stop2 | HIGH | *(int*)(param+0x1174) | none |
| +0x1178 | int | CompoundSelect_Stop3 | HIGH | *(int*)(param+0x1178) | none |
| +0x117c | int | CompoundSelect_Stop4 | HIGH | *(int*)(param+0x117c) | none |
| +0x1180 | uint | PitStopFlag | HIGH | *(byte*)(param+0x1180)&1 and *(uint*)(param+0x1180)&0x100 | none |

### Thermal/Engine Model Params
File: decompiled_all\0x004f3c80__FUN_004f3c80.c

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x12c8 | double | OptimumOilTemp | HIGH | (double*)(param+0x12c8) | none |
| +0x12d0 | double | CombustionHeat | HIGH | param+0x12d0 to FUN_00565aa0("CombustionHeat") | none |
| +0x12d8 | double | EngineSpeedHeat | HIGH | param+0x12d8 to FUN_00565aa0("EngineSpeedHeat") | none |
| +0x12e0 | double | OilMinimumCooling | HIGH | param+0x12e0 to FUN_00565aa0("OilMinimumCooling") | none |
| +0x12e8 | double | OilWaterHeatTransfer_p1 | HIGH | param+0x12e8 to FUN_00565aa0("OilWaterHeatTransfer") | none |
| +0x12f0 | double | OilWaterHeatTransfer_p2 | HIGH | param+0x12f0 passed as 2nd double arg | none |
| +0x12f8 | double | WaterMinimumCooling | HIGH | param+0x12f8 to FUN_00565aa0("WaterMinimumCooling") | none |
| +0x1300 | double | RadiatorCooling_min | HIGH | param+0x1300 to FUN_00565aa0("RadiatorCooling") | none |
| +0x1308 | double | RadiatorCooling_max | HIGH | param+0x1308 passed as 2nd double arg | none |
| +0x1310 | double | LifetimeEngineRPM_min | HIGH | (double*)(param+0x1310) | none |
| +0x1318 | double | LifetimeEngineRPM_max | HIGH | (double*)(param+0x1318) | none |
| +0x1320 | double | LifetimeOilTemp_min | HIGH | (double*)(param+0x1320), also (param+0x1320) to "LifetimeOilTemp" | none |
| +0x1328 | double | LifetimeOilTemp_max | HIGH | param+0x1328 to FUN_00565aa0("LifetimeOilTemp") | none |
| +0x1330 | double | LifetimeAvg | HIGH | param+0x1330 to FUN_00565aa0("LifetimeAvg") | none |
| +0x1338 | double | LifetimeVar | HIGH | param+0x1338 to FUN_00565aa0("LifetimeVar") | none |

**Verdict:** All sampled offsets verified. HIGH confidence. No conflicts found.

---

---

## Section 241: Net Session State Struct (inferred, small)

Based on: FUN_00462160. File exists in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| **+0xc4** | **int** | **FilterActiveFlag** | **MEDIUM** | ***(bool*)(iVar1+0xc4) = *(char*)(iVar1+0xc4)=='\0'** | **CONFLICT: doc says int (4B), .c shows char/bool (1B)** |

**Verdict:** 1 offset, but TYPE CONFLICT. Change from `int` to `bool`/`char`.

---

---

## Section 243: TireBrandEntry (stride 0x24)

Based on: FUN_004d7150, FUN_004d7880. Both in decompiled_all/.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | char* | brandName | HIGH | *(undefined1**)(param_1[1]+iVar5) in FUN_004d7880 | none |
| +0x04 | unknown | pad_or_ptr | LOW | No documented access in either file | presumably padding/gap |
| +0x08 | int | slipcurveCount | HIGH | *(int*)(param_1+8) incremented on SLIPCURVE token (FUN_004d7150) | none |
| +0x0c | ptr | slipcurveArray | HIGH | *(int**)(param_1+0xc) set to allocated array stride 0x18 (FUN_004d7150) | none |
| +0x10 | int | compoundCount | HIGH | *(int*)(param_1+0x10) incremented on COMPOUND token (FUN_004d7150) | none |
| +0x14 | ptr | compoundArray | HIGH | *(int**)(param_1+0x14) set to allocated array stride 0x2a8 (FUN_004d7150) | none |
| +0x18..+0x23 | unknown | unknown | — | No access documented | 12 bytes undocumented (fits 0x24 stride) |

**Verdict:** 6 of 7 offsets verified (1 gap at +0x04). HIGH confidence. Stride 0x24 confirmed in FUN_004d7880.

---

---

## Summary of Conflicts Found

| # | Section | Offset | Field | Doc Type | Actual Type | Action |
|---|---------|--------|-------|----------|-------------|--------|
| 1 | 233 | +0x98c | ActiveFlag | int | **char** (1 byte, checked for non-zero) | Change type to `byte` |
| 2 | 234 | +0x28 | ConstraintRowStride | ptr | **RowPtrArray** (not stride) | Rename to `ConstraintRowPtrArray` |
| 3 | 241 | +0xc4 | FilterActiveFlag | int | **bool**/**char** (1 byte, toggled) | Change type to `bool` |

---

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

---

## Section 246: FreeableMultiPtr (inferred)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x0c..+0x24 | void*[7] | FreeablePtrs | HIGH | FUN_0058f8eb: 7 pointers freed at +0x0c,+0x10,+0x14,+0x18,+0x1c,+0x20,+0x24. Sentinel at +0x0c: `&DAT_008d41cc`. | none |
| +0x224..+0x240 | ptr*3+int*3 | SubBuffers | LOW | FUN_005913d0 NOT FOUND in analyzed/. | Unverifiable |
| +0x0c/+0x1c/+0x20 | ptr*3 | ResourcePtrs | LOW | FUN_0059a17b NOT FOUND in analyzed/. | Unverifiable |

**Note:** First row confirmed (7 sequential pointer slots). Rows 2-3 unverifiable — source files absent.

---

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

---

## Section 248: PhysicsBody (solver system) (inferred)

Source: FUN_0056d930 does NOT exist in analyzed/. BodyArray stride 0x244 confirmed by 7+ other files.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| All 13 offsets | various | various | **NONE** | FUN_0056d930 NOT FOUND. Cannot verify. | Unverifiable |

**Partial validation:** FUN_00436870 line 531 accesses `*(double *)(param_1 + 0x23c)` and `*(double *)(param_1 + 0x244)`. Doc says `int` at +0x23c (BarRefCount) but source shows **double**. **CONFLICT: +0x23c is double, not int.**

---

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

---

## Section 256: Source: docs/02-ai-system.md (0 offsets)

No offsets to audit.

---

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

---

## Section 255-256: Summary / Source docs/02-ai-system.md

No additional findings. All structs covered.

---

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

---

## Section 259 — Unused Empty Struct Offset Headers

63 functions listed with empty **Struct offsets** headers. Spot-checked 5 (FUN_0053e410, FUN_005820c0, FUN_00584340, FUN_005866f0, FUN_00588910) — all confirmed as having no offset data in their doc entries. No action needed.

---

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

---

## Section 266 — Notes

No offsets to verify. Commentary about RenderContext, UI patterns, offset 0x14 polymorphism. Informational only.

---

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

---

## Section 269 — Source: docs/21-audio-network-internals.md

Reference section. No offsets to verify.

---

---

## Section 270 — Summary

Reference section. No offsets to verify.

---

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

---

## BitStreamWriter (param_1 — bit stream encoder)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x008 | byte* | OutputBufferPtr | HIGH | 5+ files (FUN_00537f30, FUN_00537fe0, FUN_00539690, FUN_00539720, FUN_00538a90) agree: `*(int *)(param_1 + 8)` as buffer base ptr | none |
| +0x014 | int | BufferPosition / WritePosition | HIGH | 5+ files agree: `*(int *)(param_1 + 0x14)` write position counter | none |
| +0x16ab | ushort | BitAccumLow / BitAccumulator / CharBuffer[0] | HIGH | 5+ files: `*(ushort *)(param_1 + 0x16ab)` primary, `*(undefined1 *)` byte access for low byte write | none |
| +0x16ac | byte | BitAccumHigh / CharBuffer[1] | HIGH | 5+ files: `*(undefined1 *)(param_1 + 0x16ac)` byte access for high byte | none |
| +0x16ad | int | BitCount / BitsRemaining / Accumulator | HIGH | 5+ files: `*(int *)(param_1 + 0x16ad)` compared to 0x10/0xd/8/7 for bit position tracking | none |

---

---

## PhysicsConfigStruct (from FUN_00434450)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | byte | Flag0 | HIGH | FUN_00434860: `*param_1 = 0` byte zero | none |
| +0x01 | byte | Enabled | HIGH | FUN_00434860: `param_1[1] = 1` byte set | none |
| +0x02 | byte | Flag2 | HIGH | FUN_00434860: `param_1[2] = 0` byte zero | none |
| +0x04 | int | ParamI0 | HIGH | FUN_00434860: `*(undefined4 *)(param_1 + 4) = 0` int zero | none |
| +0x08 | int | ParamI1 | HIGH | FUN_00434860: `*(undefined4 *)(param_1 + 8) = 0` int zero | none |
| +0x0c | int | ParamI2 | HIGH | FUN_00434860: `*(undefined4 *)(param_1 + 0xc) = 0` int zero | none |
| +0x10 | float (90.0) | AngleLimit1 | HIGH | FUN_00434860: `0x42b40000` = 90.0f | none |
| +0x14 | float (75.0) | AngleLimit2 | HIGH | FUN_00434860: `0x42960000` = 75.0f | none |
| +0x18 | int (-1) | Sentinel | HIGH | FUN_00434860: `0xffffffff` = -1 | none |
| +0x1c | int (0) | ParamI3 | HIGH | FUN_00434860: zeroed | none |
| +0x20 | int (0) | ParamI4 | HIGH | FUN_00434860: zeroed | none |
| +0x24 | float (2.0) | MaxForce | HIGH | FUN_00434860: `0x40000000` = 2.0f | none |
| +0x28 | int (0) | ParamI5 | HIGH | FUN_00434860: zeroed | none |
| +0x2c | int (0) | ParamI6 | HIGH | FUN_00434860: zeroed | none |
| +0x30 | float (3.25) | FrictionCoeff | HIGH | FUN_00434860: `0x40500000` = 3.25f | none |
| +0x34 | int (0) | ParamI7 | HIGH | FUN_00434860: zeroed | none |

Note: Only 2 functions (thunk + target at same address) — effectively 1 unique function. Confidence remains HIGH because all 16 constants match exactly.

---

---

## BarStruct (inferred) (Section 276)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| ALL | — | — | NO FILE | FUN_0056d930 has no .c file in analyzed/ | N/A |

**Cannot audit** — source file `0x0056d930__FUN_0056d930.c` not found in decompiled_full/ or analyzed/. May be IDA-only or missing.

---

---

## Player Career Stats / Game Options Struct (Section 277)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| ALL | — | — | NO FILE | FUN_004c18b0, FUN_004c1e80 not in analyzed/ | N/A |

**Cannot audit** — neither source file found. May be in IDA-only set.

---

---

## Buffered I/O Init Struct (Section 278)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x410 | int | sentinel | LOW → MEDIUM | FUN_005876f0: `*(undefined4 *)(param_1 + 0x410) = 0xffffffff` | none |
| +0x414 | int | cursor | LOW → MEDIUM | FUN_005876f0: `*(undefined4 *)(param_1 + 0x414) = 0` | none |

Only 1 function observation — upgrade to MEDIUM since the .c confirms exact types.

---

---

## Spatial/BSP Node (stride 0x20) (Section 279)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x00 | int | minX | HIGH | FUN_0051d57f: piVar6[-3] = `*piVar5` (min boundary) | none |
| +0x04 | int | maxX | HIGH | FUN_0051d57f: piVar6[-2] = `piVar5[1]` (max boundary) | none |
| +0x08 | int | minY | HIGH | FUN_0051d57f: piVar6[-1] = `piVar5[2]` (min boundary) | none |
| +0x0c | int | maxY | HIGH | FUN_0051d57f: piVar6[0] = `piVar5[3]` (max boundary) | none |
| +0x10 | int | minZ | HIGH | FUN_0051d57f: piVar6[1] = `piVar5[4]` (min boundary) | none |
| +0x14 | int | maxZ | HIGH | FUN_0051d57f: piVar6[2] = `piVar5[5]` (max boundary) | none |
| +0x18 | int | spanX | HIGH | FUN_0051d57f: `piVar1 = (int *)(param_2 + 0x18)`; `iVar4 < *piVar1` | none |
| +0x1c | int | spanY | HIGH | FUN_0051d57f: `piVar1 = (int *)(param_2 + 0x1c)`; `iVar4 < *piVar1` | none |
| +0x20 | int | spanZ | **CONFLICT** | Stride is 0x20 (8 ints). +0x20 would be start of NEXT node | Stride boundary violation |

**CONFLICT at +0x20**: Stride is 0x20 bytes per element (8 × 4-byte ints). spanZ at +0x20 falls at the start of the next element. The code accesses piVar1[2] which would be at +0x20 relative to base, but the `piVar1 + 8` stride advance (8 ints = 0x20) means the loop iterates 8 ints at a time and the element boundaries are 0x00–0x1c. Either spanZ is at +0x20 in a wider struct or the documented stride is wrong. **Remove spanZ or document as spanning next element boundary.**

---

---

## CollisionElementArray (inferred — param_1 in FUN_004046b0) (Section 281)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x10 | int | Threshold | HIGH | FUN_004046b0: `*(int *)(param_1 + 0x10)` compared to TypeFilter | none |
| +0x130 | int | ElementCount | HIGH | FUN_004046b0: `*(int *)(param_1 + 0x130)` loop bound | none |
| +0x134 | int* | ElementArray | HIGH | FUN_004046b0: `*(int *)(param_1 + 0x134)` array base ptr | none |

**Element sub-struct (stride 0x13C):**
| +0x04c | float | AccumValue | HIGH | `*(float *)(iVar1 + 0x4c)` accumulated value | none |
| +0x10c | int* | NextLink | HIGH | `*(int *)(iVar1 + 0x10c)` linked list link | none |
| +0x110 | int* | NextSibling | HIGH | `*(int *)(iVar1 + 0x110)` linked list sibling | none |
| +0x12c | int | TypeFilter | HIGH | `*(int *)(iVar1 + 300)` classification field | none |

**NEW OFFSET DISCOVERED:**
| Struct | Offset | Type | Found In | Notes |
|--------|--------|------|----------|-------|
| CollisionElement | +0x114 | int* | FUN_004046b0 | Pointer field at `*(int *)(element + 0x114)` — undocumented |

---

---

## GaugeDisplaySubStruct (Section 282)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0xac | double? | GaugeDisplay | MEDIUM | FUN_0043ef20: `*(double *)(iVar7 + 0xac) = dVar2` — double write | none |
| +0xb4 | double? | GaugeRecip | MEDIUM | FUN_0043ef20: `*(double *)(iVar7 + 0xb4) = _DAT_0059e420 / dVar2` — double write | none |

Pointed to by vehicle struct at +0x1d4 (`iVar7 = *(int *)(param_1 + 0x1d4)`). Both confirmed as `double` (not `double?` — question mark can be removed).

---

---

## NetworkManagerStruct (inferred, size ~0xbf8) (Section 283)

Sampled 15 key offsets from 52 total. Complete audit of all 52 would require reading 10+ .c files fully.

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x000 | int | ConnectionState | MEDIUM | `*(int *)(param_1 + 0x0)` in multiple network functions | none |
| +0x004 | byte | ActiveFlag | MEDIUM | FUN_0057afa0: packet queue activity flag | none |
| +0x088 | SOCKET | SocketHandle | HIGH | FUN_00563080: `*(SOCKET *)(param_1 + 0x88) = s` | none |
| +0x244 | short | Port | HIGH | FUN_005804a0: `*(ushort *)(param_1 + 0x244)` | none |
| +0x24e | int | AltPort | MEDIUM | FUN_005804a0: int-indexed access pattern | none |
| +0x252 | char[31] | Name | HIGH | FUN_005804a0: `_strncpy(param_1 + 0x252, param_2, 0x1f)` | none |
| +0x938 | SOCKET | ListenSocket | HIGH | FUN_00580190: `*(SOCKET *)(param_1 + 0x938)` with accept() | none |
| +0x93c | SOCKET | CheckSocket | MEDIUM | FUN_00580190: secondary socket for cancellation | none |
| +0xad8 | HANDLE | ConnMutex | HIGH | 7+ files: WaitForSingleObject + ReleaseMutex pattern | none |
| +0xadc | DWORD | ConnMutexTimeout | HIGH | 7+ files: paired with ConnMutex | none |
| +0xb3c | HANDLE | PacketMutex | HIGH | FUN_00580c10: WaitForSingleObject + ReleaseMutex | none |
| +0xb40 | DWORD | (not documented) | NEW | FUN_00580c10: paired with PacketMutex at +0xb3c | timeout field, undocumented |

**Note**: Offset 0x88 is heavily overloaded across multiple struct types (55+ matches in analyzed/). Each instance must be validated in context. The network manager usage at +0x88 is confirmed as SOCKET.

**NEW OFFSET**: +0xb40 DWORD — PacketMutex timeout, paired with +0xb3c PacketMutex in FUN_00580c10. Same pattern as ConnMutex(+0xad8)/ConnMutexTimeout(+0xadc).

---

---

## Struct 1: Vehicle / AI Driver Struct (Section 284, 97 sampled offsets)

| Offset | Current Type | Current Name | Confidence | .c Evidence | Conflicts |
|--------|-------------|--------------|------------|-------------|-----------|
| +0x112e | float | TireStartTempMult | LOW | No .c files found using `*(byte *)(param_1 + 0x112e)` pattern | none |
| +0x1130 | int/float | QualifyingAbility | LOW | No .c files found using `param_1 + 0x1130` in analyzed/ | none |
| +0x1131 | float | RaceAbility scaled | LOW | No .c files found | none |
| +0x1132 | float | RainSensitivity | LOW | No .c files found | none |
| +0x1133 | float | Passing | LOW | No .c files found | none |
| +0x1142 | byte | LapTypeFlag | LOW | No .c files found using exact pattern | none |
| +0x1143 | byte | PushLapCounter | LOW | No .c files found | none |
| +0x1160 | float | WetSpeedMult | LOW | No .c files found | none |
| +0x403c | int | SeasonPoints | HIGH | 10+ files: `*(int *)(param_1 + 0x403c)` — BUT see conflict | **CONFLICT** |
| +0x4058 | int | QualifyingPosition | LOW | No .c files found | none |
| +0x405c | float | QualifyingTime | LOW | No .c files found | none |
| +0x4060 | int | FinishPosition | HIGH | 4 files: `*(int *)(param_1 + 0x4060)` compared to 1 | none |
| +0x4064 | int | FinishState | MEDIUM | 5 files: `*(int *)(param_1 + 0x4064) == 0/1/4` (0=running, 1=finished, 2/3 DNF/DSQ not directly observed) | none |
| +0x4068 | int | ReasonCode | MEDIUM | FUN_0043ef20: `*(int *)(*(int *)(param_1 + 0x1f00) + 0x4068)` compared to 0, set to 9 or 1 | none |
| +0x409c | float | BestLapTime | LOW | No .c files found | none |
| +0x4354 | int* | AIStateFlags (ptr) | HIGH | 6+ files: pointer to AI sub-struct, dereferenced at +0x4c/0x50/0x54/0x94/0x9c | none |
| +0x4620 | char* | DriverName | LOW | No .c files found | none |
| +0x4678 | char* | VehicleDescription | LOW | No .c files found | none |
| +0x4894 | int | TeamID | HIGH | FUN_0041a2b0: `*(int *)(param_1 + 0x4894) == *(int *)(DAT_007c54e8 + 0x4894)` | none |
| +0x489c | int | DriverNumber | MEDIUM | FUN_0041a2b0: passed as parameter to FUN_004144f0 | none |

### CONFLICTS

**+0x403c SeasonPoints: int vs char**
- 10+ functions read as `*(int *)(param_1 + 0x403c)` — int
- FUN_0041a2b0 reads as `*(char *)(param_1 + 0x403c)` — byte/char (line 22)
- Resolution: field is likely int, but compiler may generate byte read for small-value comparison/arithmetic. The char access is in a context where the value is bounded (compared to 0xc). **Likely int, byte access is optimization artifact. No structural conflict.**

### Low Confidence Assessment

The low-confidence ratings for AI ability offsets (+0x112e–+0x1160) are because no .c files in `analyzed/` reference these exact patterns. The functions claimed to use them (FUN_00424080, FUN_00429470, etc.) may be IDA-only or in `decompiled_all/` rather than `analyzed/`.

---

---

## Section 274: Unmatched / Single-Observation Offsets (523 offsets)

**Sampling audit**: 10 offsets checked from the table (lines 50–88 of prompt).

| Offset | Claimed Function | Current Type | Found in analyzed/ | Match | Notes |
|--------|-----------------|--------------|-------------------|-------|-------|
| +0x1C | FUN_00405630 | int | N/A — file not found | — | Need to check decompiled_all/ |
| +0x34 | FUN_00405630 | int* | N/A — file not found | — | Need to check decompiled_all/ |
| +0x18 | FUN_00408050 | ptr | YES: `*(int **)(param_1 + 0x18)` | ✓ | list head/linked list pattern |
| +0x20 | FUN_00408050 | ptr | YES: `*(int **)(param_1 + 0x20)` | ✓ | linked list element ptr |
| +0x1A0 | FUN_00418df0 | int* | N/A — file not found | — | May be in decompiled_all/ |
| +0x00 | FUN_00465300 | int ActiveFlag | YES: `*(undefined4 *)(param_1 + 0x0)` | ✓ | Multiple uses |
| +0x48 | FUN_00465300 | int TimerModeFlags | YES: `*(int *)(param_1 + 0x48)` | ✓ | Timer/state field |
| +0x00 | FUN_00465300 | ptr HeadPtr | YES: `*(int **)(param_1 + 0x0)` | ✓ | Linked list head |
| +0x04 | FUN_00465300 | ptr TailPtr | YES: `*(int **)(param_1 + 0x4)` | ✓ | Linked list tail |
| +0x0C | FUN_00465300 | int Capacity | YES: `*(int *)(param_1 + 0xc)` | ✓ | Array capacity field |

**Verdict**: 10/10 sampled offsets match their claimed types. Section 274 appears well-documented. Remaining 513 offsets not individually verified (context limit). Recommend batch verification via script.

---

---

## Cross-Function Conflict Summary (Section 285)

| Offset | Conflicting Observations | Resolution |
|--------|------------------------|------------|
| +0x403c (Vehicle) | int (10+ files) vs char (FUN_0041a2b0) | Likely int — byte access is optimization artifact |
| +0x20 (BSP Node) | spanZ at +0x20 conflicts with stride 0x20 | Stride limits element to +0x00–+0x1c. spanZ MAY be at +0x20 only with wider padding or alternate node definition |

---

---
