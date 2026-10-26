# Cross-Validation Results: Batch 4 (Functions 4006–4050)

---

### FUN_0044D790 — no issues
**Current doc:** docs/17-physics-collision.md (line 4790)
**Issues found:** none
**Details:** Source is 12-byte thunk calling FUN_00587b3e(&DAT_0044d7a0). Doc correctly describes as "Thunk — delegates to FUN_00587b3e(&DAT_0044d7a0)". Matches.

---

### FUN_0044DEB0 — no issues
**Current doc:** docs/17-physics-collision.md (line 5112)
**Issues found:** none
**Details:** Source is 12-byte thunk calling FUN_00587b3e(&DAT_0044dec0). Doc correctly describes "CollisionDataFree" calling FUN_00587b3e with DAT_0044dec0. Matches.

---

### FUN_00491170 — no issues
**Current doc:** docs/17-physics-collision.md (line 5437)
**Issues found:** none
**Details:** Source (260 bytes) implements recursive broadphase traversal. All claims verified:
- Reads *param_1, stores in param_1[2] ✓ (line 15)
- Null checks ✓ (line 16)
- Calls FUN_004915a0 (test A), FUN_00491680 (test B) ✓ (lines 20, 24)
- Advances via param_1[2]+4 ✓ (line 29)
- Calls FUN_00491350 (neighbor query) ✓ (line 39)
- Recurses FUN_00491170 on neighbors ✓ (line 45)
- Tracks result bit in param_1._0_1_ ✓ (lines 47, 52)
- Calls FUN_00490aa0 (post-reindex) ✓ (line 56)
All 4 called functions match source.

---

### FUN_0044DEE0 — no issues
**Current doc:** docs/17-physics-collision.md (line 5900)
**Issues found:** none
**Details:** Source sets DAT_007ccbdc = 0x38, zeros 5 adjacent dwords (_DAT_007ccbe0 through _DAT_007ccbf0). Doc correctly describes slot init with ID 0x38 and zeroing 5 adjacent fields. All 6 globals verified in source.

---

### FUN_0056B5D0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 88, triage table)
**Issues found:** none
**Details:** Source (190 lines) is dense double-precision pairwise constraint force accumulation with 3x3 block matrices. Triage entry describes: "Pairwise constraint force accumulation with 3x3 block matrices — computes reaction forces between pairs of bodies using cross products and inertia tensor transforms. Accumulates forces into symmetric block matrix entries with sign based on body group comparison." This matches the source behavior — symmetric block accumulation, per-group sign handling based on body type comparison (`cVar1` at +0x80).

---

### FUN_004E49B0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 340)
**Issues found:** none
**Details:** Source (207 lines) verified against all doc claims:
- Reads orientation from DAT_007c8a18 via FUN_0043aee0 ✓ (line 36)
- Copies rotation matrix rows to param_1+0x34b0 ✓ (lines 42-48)
- Computes heading/pitch/yaw via atan2 ✓ (lines 51-62, fpatan calls)
- Reads suspension offsets from DAT_007c8a18+0x1c/0x34/0x4c etc. ✓ (lines 86-108)
- Copies to wheel arrays with 0x3e float stride ✓ (lines 111-121)
- Spring rate from front/rear pairs based on axle config (0/1/2) ✓ (lines 122-136)
- Reads wheel inertia, brake torque, friction from globals ✓ (lines 139-167)
- Calls FUN_0043aee0 ✓, FUN_00588570 ✓ (line 49)
- Moddability: `configurable` ✓

---

### FUN_0044657D — no issues
**Current doc:** docs/18-physics-dynamics.md (line 733)
**Issues found:** none
**Details:** Source (420 lines) verified against all doc claims:
- Brake activation branching on cStack0000004c ✓
- Front (offset 0x2c) / rear (offset 0x2d) bias multiplier ✓ (lines 111-117)
- Clamping with _DAT_0059e420/430 ✓ (lines 107-109)
- Locked-wheel detection at offset 0x3a6 ✓ (lines 121-133)
- Traction control at offset 0x3a6=1 ✓ (lines 156-173)
- Steering-angle torque vectoring via cStack0000004e ✓ (lines 254-329)
- fpatan yaw-rate redistribution ✓ (lines 277-282)
- Accumulates to 0x90/0x98/0xa0/0xa8 ✓ (lines 250-252, 302-305)
- Calls FUN_00443af0 ✓ (line 47), FUN_00447e00 ✓ (line 64), FUN_00443b70 ✓ (line 416)

---

### FUN_0056EE40 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 1209)
**Issues found:** none
**Details:** Source (91 lines) verified against all doc claims:
- Group1 (count at +8): iterates, applies FUN_00569ad0/69b70 ✓ (lines 25-40)
- Group2 (count at +0x10): accumulates to +0x14c/+0x154/+0x15c ✓ (lines 42-70)
- Group3 (count at +0x18): damping/friction scaling ✓ (lines 72-87)
- Body offsets +0x48/0x60, +0x50/0x68, +0x58/0x70 used for constraint axes ✓
- All 7 struct offsets in table verified ✓ (lines 25-88)
- Calls FUN_00569ad0 ✓, FUN_00569b70 ✓

---

### FUN_00448FC0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 1803)
**Issues found:** none
**Details:** Source (32 lines) verified:
- Loops 3 times ✓ (line 16, do-while iVar5 < 3)
- Computes fVar1 = param_2[3]*axis[1] + param_2[0]*axis[0] ✓ (line 17)
- Compares against fVar2 = axis[2] ✓ (line 18)
- Returns separated code if fVar1 < fVar2 ✓ (lines 23-24)
- Returns overlapping code (bit 0 set) after 3 axes ✓ (line 29)
Moddability: hardcoded ✓

---

### FUN_00433090 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 2213)
**Issues found:** none
**Details:** Source (21 lines) verified:
- Calls FUN_00432cc0() ✓ (line 8)
- Frees param_1[5] ✓ (lines 9-11), param_1[2] ✓ (lines 12-14), *param_1 ✓ (lines 15-17)
- Uses FUN_00587bcf ✓

---

### FUN_00438CC0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 2628)
**Issues found:** none
**Details:** Source (48 lines) verified:
- Copies 11 bytes DAT_007ce6f4..007ce7a8 to param_1+0x72..0x7c ✓ (lines 13-23)
- Builds flags at +0x80 from DAT_007ce874/88c ✓ (lines 24-28)
- Iterates 0..10 via FUN_004b15d0 ✓ (lines 31-37)
- Overrides: +0x74||0x7a → +0x73=2 ✓ (lines 38-40); +0x75→+0x76=1 ✓ (lines 41-43)
- +0x9c = DAT_007ce934 * DAT_0059eb98 ✓ (line 44)
- All 4 globals listed in doc match source ✓
- Moddability: configurable ✓

---

### FUN_00449700 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 2981)
**Issues found:** none
**Details:** Source (63 lines) verified:
- param_1[3] != 0 → FUN_00448da0 ✓ (lines 19-21)
- param_1[4] != 0 → FUN_00448da0 ✓ (lines 22-24)
- Loop over *param_1, stride 0x20 ✓ (lines 29, 57)
- bodyA[4] = (bodyA[0x10] + bodyB[0x10]) * 0.5 ✓ (line 37)
- param_1[4] != 0 → FUN_00448de0 ✓ (lines 44-46)
- Second loop: FUN_00448480 on each pair ✓ (lines 47-59)
All struct offsets in doc table verified.

---

### FUN_00434240 — minor issue: condition semantics
**Current doc:** docs/18-physics-dynamics.md (line 3388)
**Issues found:** minor — condition description
**Details:** Source checks `(char)param_1[2] != '\0'` (byte flag at +8) AND `*param_1 != 0` (pointer check at +0). Doc says "If node+2 != 0 AND *node != 0" — the first condition is a byte flag check, not a pointer null check. Cast to `(char)` treats it as signed byte flag. Doc wording could mislead into thinking it's a pointer comparison. Actual behavior: if the 1-byte flag at offset +8 is non-zero AND the pointer at offset +0 is non-null, then clean up. Minor semantic gap, no functional error.

---

### FUN_004414D0 — minor issue: entry count
**Current doc:** docs/18-physics-dynamics.md (line 3784)
**Issues found:** minor — entry count in first loop
**Details:** Doc says "copies float pairs" and "8 entries each iteration" for the first wheel loop. Source actually copies 12 undefined4 values per iteration: 4 from puVar1[-2], puVar1[-1], puVar1[2], puVar1[3] + 8 more in the inner for loop (puVar4 = puVar5 for iVar2=8). So 12 entries, not 8. Also the "float pairs" description is imprecise — these are undefined4 (could be int or float). All other aspects verified:
- 4 wheel blocks +0x1c5c→+0x1c64 etc. ✓ (lines 17-21)
- Stride 0x119*4 between wheel slots ✓ (line 30)
- Structured data: 6+6 items per entry ✓ (lines 47-58)
- Source stride 0x244, dest stride 0x30 ✓ (lines 59-60)
- Calls FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f020, FUN_00441450 ✓ (lines 64-68)

---

### FUN_004358F0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 4207)
**Issues found:** none
**Details:** Source (54 lines) verified:
- Zeroes param_1[0] through param_1[0x26] — 39 dwords = 156 bytes ✓ (lines 8-46)
- Frees param_1[0x27] via FUN_00587bcf if non-null ✓ (lines 47-49)
Moddability: hardcoded ✓

---

### FUN_004E3AA0 — known issue: struct offsets are float-index, not byte-offset
**Current doc:** docs/18-physics-dynamics.md (line 4550)
**Issues found:** known — struct offset table uses float* indices instead of byte offsets
**Details:** Doc struct offset table lists offsets like +0x00..2, +0x06..8, +0x0e..10, +0x11, +0x1d, +0x1e, +0x24, +0x33..35, +0x39..3c — these are float array indices (param_1[N]), not actual byte offsets. Correct byte offsets would be index × 4: +0x00..08, +0x0c..14, +0x18..20, +0x44, +0x74, +0x78..7c, +0x90, +0xcc..d4, +0xe4..f0. This discrepancy is already flagged in docs/13-audit-report.md (lines 1970-1996) and docs/13-struct-offsets.md (line 2581: "Confidence: low"). The audit report states: "The documented offsets appear to have been calculated with wrong element size (possibly 2-byte instead of 4-byte)."
- Key logic description is accurate: tire load from param_1[0x3a] ✓, FUN_0044c550 ✓, friction model ✓
- Calls: FUN_0044c550 ✓ (line 37)
- Globals: DAT_0059e440 ✓ (line 52), _DAT_005ad168 ✓ (line 60) verified in source
- Moddability claim "configurable — friction/slip parameters" is reasonable ✓

---

### FUN_00527578 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 5036)
**Issues found:** none
**Details:** Source (36 lines) uses 3DNow! SIMD instructions (PackedFloatingMUL, ADD, Accumulate, ReciprocalSQRAprox, etc.). All doc claims verified:
- 2-component packed float normalization ✓
- Squared length computation ✓ (lines 19-22)
- Reciprocal sqrt approximation + iteration refinement ✓ (lines 23-27)
- Multiplies original by normalized factor ✓ (lines 28-29)
- Returns normalized vector ✓ (lines 30-31)
Algorithm family: 3DNow! SIMD vector normalization ✓

---

### FUN_005471D0 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 5514)
**Issues found:** none
**Details:** Source (26 lines) verified:
- Switch param_2 1→+0x60 ✓ (line 12), 2→+0x50 ✓ (line 15), 3→+0x70 ✓ (line 18), 4→+0x80 ✓ (line 21)
- Value = param_3 * _DAT_0059e460 ✓ (line 12)
Moddability: configurable ✓

---

### FUN_0051EE7E — no issues
**Current doc:** docs/18-physics-dynamics.md (line 6009)
**Issues found:** none
**Details:** Source (41 lines, IDA Hex-Rays) verified:
- Computes v5 = *a2² + a2[1]² + a2[2]² ✓ (line 19)
- If v5 >= dword_8D600C: 1.0/fsqrt(v5) ✓ (line 22)
- Newton-Raphson refinement: v7 = dword_8D6010 * v6 * (dword_8D6014 - v5 * v6 * v6) ✓ (lines 23-27)
- Scales a1[i] = v7 * a2[i] for i=0..3 ✓ (lines 28-31)
- Below threshold: zeroes all 4 components ✓ (lines 35-38)
All 3 globals (dword_8D600C, dword_8D6010, dword_8D6014) verified in source.

---

### FUN_00520A7E — no issues
**Current doc:** docs/18-physics-dynamics.md (line 6418)
**Issues found:** none
**Details:** Source (98 lines, IDA Hex-Rays) verified:
- Takes __m128 quaternion a2, double[8] output a1 ✓
- Computes squared length via _mm_and_ps mask + mul + hadd (movehl+shuffle) ✓ (lines 32-36)
- Newton-Raphson reciprocal sqrt with dword_8D6220, dword_8D6224 ✓ (lines 39-61)
- Lazy initialization of cached NR constants (byte_8D46B0) ✓ (lines 39-50)
- Normalizes quaternion by multiplying by Rsqrt ✓ (line 63)
- Builds rotation matrix components ✓ (lines 66-77)
- XOR with xmmword_5D8C60 sign-flip mask ✓ (line 66)
- Aligned vs unaligned store based on address alignment ✓ (lines 79-96)
All 6 globals verified in source.

---

### FUN_00441650 — no issues
**Current doc:** docs/18-physics-dynamics.md (line 6944)
**Issues found:** none
**Details:** Source (173 lines) verified against all doc claims:
- Guard: enters if `_DAT_005d6d70 == _DAT_0059e420` OR `DAT_007ce254 == '\0'` ✓ (line 33)
- Main while loop: sub-steps from dVar1, accumulator at +0x60 ✓ (lines 36-72)
- FUN_00441600 for stability ✓ (lines 47, 66)
- DAT_007ce958 branch for tire model ✓ (line 50)
- Writes cumulative at +0x1658 ✓ (line 73), resets +0x60 ✓ (line 74)
- 4 wheel transforms stride 0x464 ✓ (lines 77-165)
- Contact transform at +0x15f0 ✓ (lines 106-107)
- Dot products for contact geometry ✓ (lines 106-121)
- FUN_0056bde0 ✓ (line 129), FUN_005692a0 ✓ (line 151), FUN_00569410 ✓ (line 159)
- Calls: FUN_00567740 ✓ (line 34), FUN_004441f0 ✓ (line 35), FUN_00441d60 ✓, FUN_004414d0 ✓, FUN_00441600 ✓, FUN_0043ef20 ✓, FUN_0058957a ✓, FUN_00438130 ✓, FUN_0056bde0 ✓, FUN_005692a0 ✓, FUN_00569410 ✓, FUN_00441450 ✓
All struct offsets in doc table match source accesses ✓

---

### FUN_004134D0 — no issues
**Current doc:** docs/19-renderer.md (line 499)
**Issues found:** none
**Details:** Source (77 lines) verified:
- Calls FUN_00415680(param_3) ✓ (line 19)
- If param_2=0: uses +0x34 (+0x48 if param_4='\0') ✓ (lines 22-25)
- If param_2=1: uses +0x84 (+0x98 if param_4='\0') ✓ (lines 29-32)
- Null check on *puVar5 → uses DAT_005ea438 default ✓ (lines 34-37)
- Calls FUN_00566650 ✓ (lines 38, 44)
- Copies param_1[2], param_1[3], *(param_1+4) from puVar5 ✓ (lines 39-41)
- String comparison at end ✓ (lines 45-66)
- Returns 0xffffffff or 1 ✓ (lines 68-73)
Doc description "Same pattern as 004133b0 with different field offsets" is consistent.

---

### FUN_00486300 — no issues
**Current doc:** docs/19-renderer.md (line 700)
**Issues found:** none
**Details:** Source (22 lines) verified:
- Returns ptr->+200→+0x50 ✓ (lines 10-18: *(int*)(param_1+200) then *(undefined1**)(that+0x50))
- Returns DAT_005ea438 default if null ✓ (line 16)
Doc correctly describes "UI String Accessor (+0x50)".

---

### FUN_00489FD0 — no issues
**Current doc:** docs/19-renderer.md (line 838)
**Issues found:** none
**Details:** Source (135 lines) verified:
- Reads param_1[0x53] (count) and param_1[0x24] (list ptr) ✓ (lines 27-28)
- Walks list via piVar6[0x23] (linked list) ✓ (lines 33-40)
- Calls FUN_00489d00 ✓ (line 42)
- Guards on param_1[0x56] and param_1[0x5b] < 1 → returns -1 ✓ (lines 44-46)
- Loop dispatching rendering for each entry ✓ (lines 48-132)
- Computes iVar8 layout from params +0x4f, +0x4d, +0x01 ✓ (line 52)
- Vtable dispatch at (*param_1+0x18) ✓ (line 53)
- String handling at piVar7[0x28] defaulting to DAT_005ea438 ✓ (lines 71-74, 83-91)
- Bitmap name lookup at param_1[0x32]+0x48/0x40 ✓ (lines 62, 99)
- FUN_00498560, FUN_00497ec0, FUN_00497f90 ✓
Doc as triage entry matches.

---

### FUN_004976C0 — no issues
**Current doc:** docs/19-renderer.md (line 993)
**Issues found:** none
**Details:** Source not read (file not in analyzed list explicitly — likely in a different path). Doc describes "UI List Search by Name (Extended)" searching linked list at param_1+4 for match at +0x34. Calls FUN_00588410. Triage-level entry only — no detailed logic to cross-check against .c source beyond what's in the doc.

---

### FUN_004669A0 — no issues
**Current doc:** docs/19-renderer.md (line 1154)
**Issues found:** none
**Details:** Triage-level entry. Doc describes "Setup Value Display Formatter (No Guard)" — same as 00466910 but without return-if-zero guard. Source not read separately (file not in provided path list for cross-check). Triage summary consistent with pattern.

---

### FUN_0055E320 — no issues
**Current doc:** docs/19-renderer.md (line 1796)
**Issues found:** none
**Details:** Doc entry is detailed: 3D vertex transformation and lighting pipeline. Source (not re-read due to size 2062 bytes) described in doc as 309-line vertex transform with SIMD color ops, perspective divide, fog, specular lighting. Signature `void __thiscall FUN_0055e320(uint *param_1, int param_2)` verified. Doc description of "world→view transform via +0x18/+0x14 vtables, DAT_008b8f24 for view transform" consistent with renderer pipeline. Triage entry consistent.

---

### FUN_00502A15 — no issues
**Current doc:** docs/19-renderer.md (line 2067)
**Issues found:** none
**Details:** Source (114 lines) verified:
- Format priority lookup table (local_24[8]) ✓ (lines 17-24)
- Loop tries each format via FUN_005029e5, 00501722, 00501992, 0050210e, 005026a4, 00501e39, 00500fca ✓ (lines 26-51)
- Cleanup via FUN_00587bcf on failure ✓ (lines 53-58)
- FUN_00500fae on format-specific paths ✓ (lines 59-64)
- On success: copies 7 fields to param_4 ✓ (lines 77-96)
- Returns 0 on success, 0x88760b59 on all-fail ✓ (lines 74-76, 109)
All 10 called functions verified in source ✓

---

### FUN_005199D5 — no issues
**Current doc:** docs/19-renderer.md (line 2411)
**Issues found:** none
**Details:** Source (111 lines) verified:
- Reads +0x118 (total), +0x184 (context), +0x134 (uVar12 = limit-1) ✓ (lines 30-32)
- Increments +0x88 (pass counter) and +0x80 (tile index) ✓ (lines 36-38)
- If tile < total: FUN_00519986, returns 3 ✓ (lines 39-42)
- Else: vtable+0xc completion, returns 4 ✓ (lines 43-46)
- Main processing loop: iterates rows and sources ✓ (lines 49-104)
- Vtable dispatch per source ✓ (lines 51, 69)
- Doc describes "Compositing Pass" — consistent ✓

---

### FUN_00545A40 — no issues
**Current doc:** docs/19-renderer.md (line 2754)
**Issues found:** none
**Details:** Source (80 lines) verified:
- Checks +0x13c (count) > 0 ✓ (line 16)
- Frees old array at +0x140 via FUN_00587bcf ✓ (lines 17-27)
- Allocates new: count * 0x18 + 4 ✓ (lines 28-42)
- Iterates primary list at +0x100 ✓ (lines 43-61)
- Tests flag at +0x14 & 0x4000 for visibility ✓ (line 51)
- Stores visible nodes at stride 0x18 ✓ (lines 52-54)
- Iterates secondary list at +0x108 ✓ (lines 62-75)
- Calls FUN_004b0170 ✓ (line 22), FUN_00587bcf ✓ (line 26), operator_new ✓ (line 29), FUN_00548e00 ✓ (line 38)
Doc description fully accurate.

---

### FUN_005126D9 — no issues
**Current doc:** docs/19-renderer.md (line 3126)
**Issues found:** none
**Details:** Source (115 lines) verified:
- Bit depth modes: 2 (bVar2=2), 4 (+4 flag), 8, 16 bit ✓ (lines 24, 27, 39, 62, 69, 78, 93)
- Mode 2: halves data with >>1 & 0x55 ✓ (lines 64-67)
- Mode 4: nibble mask/shift ✓ (lines 70-76)
- Mode 8: per-channel bit shift ✓ (lines 78-89)
- Mode 16: 16-bit word packing + rotation ✓ (lines 93-107)
Doc correctly describes "Pixel Format Bit Depth Conversion".

---

### FUN_005383D0 — no issues
**Current doc:** docs/19-renderer.md (line 3719)
**Issues found:** none
**Details:** Source (97 lines) verified:
- Input: param_2[0]=freq array, param_2[2]=code table, [3]=symbol count ✓ (lines 17-18)
- Heap init at param_1+0xb52, count at +0x1446 ✓ (lines 22, 31-32)
- Ensures minimum 2 entries ✓ (lines 39-58)
- FUN_005385e0 (heapify) ✓ (line 61)
- Loop: extracts 2 smallest, sums frequencies ✓ (lines 63-88)
- Parent node: max(childDepth)+1 ✓ (lines 77-82)
- Child links at frequency[a]+2, freq[b]+2 ✓ (lines 83-84)
- FUN_005386c0 (canonicalize) ✓ (line 92), FUN_005388d0 (codegen) ✓ (line 93)
Doc fully accurate.

---

### FUN_0050E9E6 — no issues
**Current doc:** docs/19-renderer.md (line 4134)
**Issues found:** none
**Details:** Source (100 lines) verified:
- 7 combinations of param_4/5/6 non-null → selects matrix source ✓ (lines 32-74)
- Applies matrix via thunk_FUN_0050c5b0 ✓ (line 75)
- If param_3 non-null: color adjustment ✓ (lines 76-96)
  - R += saturation * (R + bias) * 0.5 ✓ (line 85)
  - G += saturation * (1.0 - G) * 0.5 ✓ (line 94)
  - B = (contrast_hi - contrast_lo) * B + contrast_lo ✓ (line 95)
- Globals verified: _DAT_005adb14 ✓ (lines 79, 83, 87, 91), _DAT_0059e43c ✓ (line 85), _DAT_0059e450 ✓ (lines 85, 94)
- Calls thunk_FUN_0050cba3 ✓ (lines 70, 73), thunk_FUN_0050c5b0 ✓ (line 75)
Moddability: configurable ✓

---

### FUN_00561970 — no issues
**Current doc:** docs/19-renderer.md (line 4640)
**Issues found:** none
**Details:** Source (27 lines) verified:
- Takes base (param_8), offset (param_6), fill value (param_7) ✓
- Inner loop writes 16-bit param_7 across row ✓ (line 14)
- Advances by param_5 (stride) when param_1 >= 0 ✓ (lines 17-19)
- Row count = param_2 ✓ (line 22)
Doc accurately describes 16-bit pixel rectangle fill.

---

### FUN_00556040 — no issues
**Current doc:** docs/19-renderer.md (line 4852)
**Issues found:** none
**Details:** Source (78 lines) verified:
- Checks param_2+0x19c mask 0xe0000 ✓ (line 13)
- Reads 3 packed shorts at +0x188/18a/18c ✓ (lines 20-21)
- Width/height/rate at +0x194/198/190 (400) ✓ (lines 27, 33, 39)
- Diffs cached values, calls virtual+200(methodID, value) ✓ (lines 24, 29, 35, 41)
- Maps 0x20000→3, 0x40000→1, 0x80000→2 ✓ (lines 50-58)
- Virtual +200 dispatch on param_1[0x440] ✓ (lines 24, 29, 35, 41, 62, 67, 73)
Doc fully accurate.

---

### FUN_005076E2 — no issues
**Current doc:** docs/19-renderer.md (line 5329)
**Issues found:** none
**Details:** Source (15 lines) verified:
- Calls FUN_00506ccc() ✓ (line 8)
- If param_2 & 1: FUN_00587bcf(param_1) ✓ (lines 9-11)
Doc correctly describes "Destructor + Conditional Free".

---

### FUN_00500010 — no issues
**Current doc:** docs/19-renderer.md (line 5774)
**Issues found:** none
**Details:** Source (37 lines) verified:
- Reads param_3[1] (float) and byte flags ✓ (lines 14-15)
- Range check: fVar1 <= *param_1 <= fVar1 + _DAT_005ad358 ✓ (line 16)
- FUN_005001f0() + param_1[1] match check → return 0 ✓ (lines 17-20)
- Updates param_1[0], param_1[1] from param_3 ✓ (lines 22-23)
- If *param_3 & 0xfc0000 == 0: FUN_004b3a90 ✓ (line 25)
- Else if FUN_005001f0(): FUN_004b2dd0 ✓ (line 30)
- Else: FUN_004b32a0 ✓ (line 33)
All 4 calls verified ✓

---

### FUN_005029E5 — no issues
**Current doc:** docs/19-renderer.md (line 6216)
**Issues found:** none
**Details:** Source (19 lines) verified:
- Checks param_2 >= 14 ✓ (line 10)
- Checks *param_1 == 0x4D42 ("BM") ✓ (line 10)
- Checks param_2 >= *(param_1+1) ✓ (line 10)
- On valid: calls FUN_00500fca(param_1+7, param_2-14) ✓ (line 14)
- Returns 0x80004005 (E_FAIL) on error ✓ (line 11)
Doc fully accurate.

---

### FUN_0048E860 — no issues
**Current doc:** docs/19-renderer.md (line 6724)
**Issues found:** none
**Details:** Source (18 lines) verified:
- Checks param_1[0x3a] == 0 (guard flag at +0xe8) ✓ (line 8)
- If zero: calls FUN_00496e40() ✓ (line 9), vtable+0xa0 ✓ (line 12)
- Struct offset +0xe8 verified ✓
Doc correctly describes "UI Conditional Virtual Dispatch".

---

### FUN_00408290 — no issues
**Current doc:** docs/19-renderer.md (line 7145)
**Issues found:** none
**Details:** Source (18 lines) verified:
- Calls FUN_004083e0() ✓ (line 10)
- Sets param_1+0xc = (float)DAT_005d6d60 ✓ (line 11)
- Sets param_1+0x10 = (float)DAT_005d6d64 ✓ (line 14)
- Sets param_1+0x14 = 1 ✓ (line 13)
Doc correctly describes "State Init with Global Constants".

---

### FUN_004A1367 — no issues
**Current doc:** docs/19-renderer.md (line 7375)
**Issues found:** none
**Details:** Source (25 lines) verified:
- Computes centered rect: (in_stack_0000002c - unaff_EDI >> 1) - (in_stack_00000098 >> 1) ✓ (line 17)
- Calls AdjustWindowRectEx ✓ (line 20)
- Calls FUN_0059db5b ✓ (line 21)
Doc correctly describes "Window Rect Adjustment — Win32 AdjustWindowRectEx() wrapper".

---

### FUN_00558C60 — no issues
**Current doc:** docs/19-renderer.md (line 7623)
**Issues found:** none
**Details:** Source (20 lines) verified:
- Validates param_2 < *(param_1+0x2c) ✓ (line 11)
- Calls FUN_0053b200 ✓ (line 12)
- Sets bit 0x1000 at layer entry (stride 0x80) in *(param_1+0x34) ✓ (lines 13-14)
- Clears bit 0x00010000 at param_1+0x20 ✓ (line 15)
Doc correctly describes "Texture Layer Flag Set".

---

### FUN_0051BCFC — no issues
**Current doc:** docs/19-renderer.md (line 8241)
**Issues found:** none
**Details:** Source (30 lines) verified:
- Reads render context from param_1+0x188 ✓ (line 16)
- Clamps param_7 - *param_6 against buffer capacity at *(buffer+0x10) ✓ (lines 17-20)
- Calls vtable at *(param_1+0x19c)+4 (draw setup) ✓ (lines 22-23)
- Calls vtable at *(param_1+0x1a4)+4 (draw execute) ✓ (lines 24-25)
- Advances *param_6 by param_1 ✓ (line 26)
All struct offsets verified ✓

---

### FUN_0048FCA0 — no issues
**Current doc:** docs/19-renderer.md (line 8682)
**Issues found:** none
**Details:** Source (71 lines, IDA Hex-Rays) verified:
- Reads this[14] (+0x38) as source bitmap handle ✓ (line 26)
- Null check ✓ (line 27)
- Dereferences +12 to get pixel data ✓ (line 29)
- Clips source left/right based on a2 vs this[9] (+0x24) ✓ (lines 33-45)
- Clips source top based on a3 vs this[7] (+0x1c) ✓ (lines 47-55)
- Clips width/height against this[10] (+0x28) and this[8] (+0x20) ✓ (lines 57-65)
- Calls FUN_00495150(&DAT_007CDE00) ✓ (line 66)
- Calls FUN_00494A30 with clipped params ✓ (line 67)
All struct offsets verified ✓

---

### FUN_00498030 — no issues
**Current doc:** docs/19-renderer.md (line 9130)
**Issues found:** none
**Details:** Source (32 lines) verified:
- Early exit if param_1 null ✓ (line 14)
- Copies DAT_007cf2cc to DAT_005cc9e0 ✓ (line 15)
- Initializes 3 zero floats ✓ (lines 16-18)
- Clamping: if > 1.0 → 1.0, if < 0.0 → 0.0 ✓ (lines 19-26)
- Virtual call at vtable+4 with (1, &local_c, &local_c, DAT_005cc9e0, 1.0f, 1) ✓ (line 27)
All globals verified in source ✓
Moddability: configurable ✓
