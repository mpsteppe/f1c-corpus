# Cross-Validation Results: docs/18-physics-dynamics.md + docs/19-renderer.md

Generated: 2026-07-15
Validator: Architect (Claude)

---

## docs/18-physics-dynamics.md

### 1. FUN_005670D0 — 3×3 Rotation Matrix from Euler Angles — PASS

**Source:** `analysis_pipeline\analyzed\0x005670d0__FUN_005670d0.c`

**Verification:**
- Doc: Builds 3×3 column-major rotation matrix from yaw (param_2) and pitch (param_3)
- Source: param_1[0..8] matches exactly:
  - `param_1[0] = cos(pitch)*cos(yaw)` ✓
  - `param_1[1] = -sin(pitch)*cos(yaw)` ✓
  - `param_1[2] = sin(yaw)` ✓
  - `param_1[3] = sin(pitch)` ✓
  - `param_1[4] = cos(pitch)` ✓
  - `param_1[5] = 0.0` ✓
  - `param_1[6] = -cos(pitch)*sin(yaw)` ✓
  - `param_1[7] = sin(pitch)*sin(yaw)` ✓
  - `param_1[8] = cos(yaw)` ✓
- Calls fsin, fcos ✓
- All claims verified against decompiled source

---

### 2. FUN_00432810 — Vehicle Field Accessor (Offset +0x2C) — PASS

**Source:** `analysis_pipeline\analyzed\0x00432810__FUN_00432810.c`

**Verification:**
- Doc: `return *(int*)(*param_1 + 0x2C)`
- Source: `return *(undefined4 *)(*param_1 + 0x2c);` ✓
- 6-byte function, single dereference
- Note: `__fastcall` not `__thiscall` — trivial calling-convention difference

---

### 3. FUN_004484C0 — Vec3Subtract (3-component float vector subtraction) — PASS

**Source:** `analysis_pipeline\analyzed\0x004484c0__FUN_004484c0.c`

**Verification:**
- Doc: `*param_1 = *param_2 - *param_3` (x component) ✓
- Doc: `*(double*)(param_1+1) = *(double*)(param_2+1) - *(double*)(param_3+1)` (y+z as double) ✓
- Doc: `param_1[3] = param_2[3] - param_3[3]` (w/extra) ✓
- Doc notes 8-byte aligned double access pattern for components 1-2 — accurate
- Pure math, no calls ✓

---

### 4. FUN_0043E230 — WheelDynamicsInit — PASS

**Source:** `analysis_pipeline\analyzed\0x0043e230__FUN_0043e230.c`

**Verification:**
- Calls FUN_00431a50 with param_1[0x753] (wheel RPM/velocity) ✓
- Loop 4 wheels, stride 0x464: ✓
  - FUN_00431930 (slip ratio) per wheel ✓
  - FUN_004319c0 (slip angle) per wheel ✓
  - FUN_00431a70 ×3 (force/moment components) per wheel ✓
- Calls FUN_004d5840 ✓, FUN_004358f0 ✓
- Sets param_1[0x7c0] = 0 ✓
- Calls FUN_0056e970 ✓
- Frees param_1[0x73f] and param_1[0x58b] if non-null ✓
- Zeroes 0x7ce×4 = 0x1f38 bytes ✓
- Loop 4 wheels stride 0x119×4 = 0x464: wheel ID, double init (0x8f5c28f6, 0x40767dc2) ✓
- All called functions present in source

---

### 5. FUN_0056C2D0 — 3×3 Rotation Matrix Around X-Axis — PASS

**Source:** `analysis_pipeline\analyzed\0x0056c2d0__FUN_0056c2d0.c`

**Verification:**
- Computes sin(param_2), cos(param_2) via fsin/fcos ✓
- Rotates Y-Z plane columns (param_1[1..8]): ✓
  - `param_1[1] = Z·sin + Y·cos` ✓
  - `param_1[2] = Z·cos - Y·sin` ✓
  - Same pattern for all 3 row pairs (col Y, col Z) ✓
- If param_3 non-null: computes Euler angles via fpatan, handles gimbal lock ✓
  - `*param_3 = -FUN_00588570()` (negative sign/norm) ✓
  - Non-gimbal: param_3[1] = atan2(Z, Mzz), param_3[2] = atan2(Mzy, Myy) ✓
  - Gimbal: param_3[2]=0, param_3[1] = atan2(-Mzx, Mxx) ✓
- Calls FUN_00588570 ✓

---

### 6. FUN_004B1DE0 — Clamped Float Setter — PASS

**Source:** `analysis_pipeline\analyzed\0x004b1de0__FUN_004b1de0.c`

**Verification:**
- Writes param_2 to param_1 + 0x14 ✓
- Clamps to [param_1+0x1c (min), param_1+0x20 (max)] ✓
  - If value < min → value = min ✓
  - If value > max → value = max ✓
- Simple clamp utility, no calls ✓

---

### 7. FUN_00583790 — Physics Query Getter with Ready Flag — PASS

**Source:** `analysis_pipeline\analyzed\0x00583790__FUN_00583790.c`

**Verification:**
- Ready flag at param_1+0xc: check returns 0 if '\0' ✓
- Sets ready flag to 0 ✓
- `*param_2 = (param_5 - param_1+0x10) + param_1+0x18` ✓
- `*param_4 = *(undefined4*)(param_1+0x120)` — data count ✓
- If 0 < param_1+0x120: *param_3 = param_1+0x20 (buffer ptr), return 1 ✓
- Else: *param_3 = 0, return 1 ✓
- Struct offset table accurate: +0x0C, +0x10, +0x18, +0x20, +0x120 ✓
- No calls ✓

---

### 8. FUN_004FD7E0 — 1D Table Lookup with Lerp — PASS

**Source:** `analysis_pipeline\analyzed\0x004fd7e0__FUN_004fd7e0.c`

**Verification:**
- If param_2 >= DAT_005ad2d0: returns param_1+0xa0 (saturation) ✓
- Else: param_2 × DAT_0059e46c, truncate to int index via __ftol ✓
- Lerp: `frac * (table[i+1] - table[i]) + table[i]` ✓
  - table[i] at param_1 + 0x64 + i×4 ✓
  - table[i+1] at param_1 + 0x68 + i×4 = param_1 + 0x64 + (i+1)×4 ✓
- Calls FUN_005895a2 and __ftol ✓
- Moddability: `configurable` — DAT_ globals are thresholds — correct assessment

---

### 9. FUN_00578F76 — InitPhysicsTransformIdentity — PASS

**Source:** `analysis_pipeline\analyzed\0x00578f76__FUN_00578f76.c`

**Verification:**
- 34 switch cases (0-33) ✓
- Cases 0-2: sparse pattern, sets 10-14 elements, one to 1.0, rest to 0.0 ✓
- Cases 3-9: memset N bytes (24-72) then set identity element to 1.0 ✓
- Cases 10-12: sparse pattern at different base addresses ✓
- Cases 13-14: memset 24-32 then identity ✓
- Cases 15-17: memset 80 then identity ✓
- Cases 18-20: sparse 3-row blocks ✓
- Cases 21-23: combined memset 80+24, 24, 24 ✓
- Cases 24-26: memset 64 then identity ✓
- Cases 27-28: combined 64+24, 64+32 then identity ✓
- Cases 29-33: memset 112-144 (step +8/case) then identity ✓
- Calls sub_58BB10 (memset) ✓
- Operates on 0x8D0000-0x8D9000 physics region ✓
- **NOTE:** Duplicate entry at lines 5824 and 5852 — content nearly identical. Should be deduplicated.

---

### 10. FUN_005986CB — PhysicsSolverInitStub — PASS

**Source:** `analysis_pipeline\analyzed\0x005986cb__sub_5986CB.c`

**Verification:**
- Source: `return sub_598E39(&unk_8D4370);` ✓
- Doc: "Calls sub_598E39 with physics constraint workspace at unk_8D4370" ✓
- 10-byte thin wrapper ✓
- Globals: DAT_008d4370 (unk_8D4370) ✓
- IDA Hex-Rays source (Ghidra gap function) ✓

---

### 11. FUN_0050CDFF — 4x4 Matrix Transpose (Float) — PASS

**Source:** `analysis_pipeline\analyzed\0x0050cdff__sub_50CDFF.c`

**Verification:**
- Swaps elements across 4x4 diagonal (float indices → byte offsets):
  - (1↔4) → swap(a1+4, a1+16) ✓
  - (2↔8) → swap(a1+8, a1+32) ✓
  - (3↔12) → swap(a1+12, a1+48) ✓
  - (6↔9) → swap(a1+24, a1+36) ✓
  - (7↔13) → swap(a1+28, a1+52) ✓
  - (11↔14) → swap(a1+44, a1+56) ✓
- If a1 != a2: copies diagonal (a1+0, a1+20, a1+40, a1+60) ✓
- IDA Hex-Rays source ✓

---

## docs/19-renderer.md

### 12. FUN_004CB620 — ParticleCollisionSpark — PASS

**Source:** `analysis_pipeline\analyzed\0x004cb620__FUN_004cb620.c`

**Verification:**
- Returns if velocity magnitude < _DAT_0059e43c (threshold ≈1.0) or count (param_1+0x58) ≤ 0 ✓
- Allocates particle via FUN_004cb540 ✓
- Sets lifetime: `param_2 + existing` ✓
- Pseudo-random intensity from DAT_008aae70/8aae74 ✓
- If velocity < param_1+0x48: scales intensity by velocity/threshold ✓
- Computes position = direction × scale + offset ✓
- Projects to camera via FUN_0044c550 ✓
- Sets velocity = direction × _DAT_0059e84c ✓
- Calls FUN_00558c60, FUN_00558cb0, FUN_00558cf0 for render setup ✓
- Globals: DAT_008aae70, DAT_008aae74 ✓
- Moddability assessment reasonable ✓

---

### 13. FUN_00455560 — Array Indexed Accessor (44-entry) — PASS

**Source:** `analysis_pipeline\analyzed\0x00455560__FUN_00455560.c`

**Verification:**
- Bound check: param_2 < 0x2c (44) ✓
- Array at param_1 + 0x22b0, stride 8 ✓
- Returns null-terminated string pointer ✓
- Default fallback to DAT_005ea438 (empty string) when null ✓

---

### 14. FUN_00489920 — UI Screen Text Accessor (+0xb0) — PASS

**Source:** `analysis_pipeline\analyzed\0x00489920__FUN_00489920.c`

**Verification:**
- Calls FUN_00489450 ✓
- Returns text at iVar1 + 0xb0 ✓
- Null fallback to DAT_005ea438 ✓
- Doc calls: FUN_00489450 ✓ (minor: doc omits null-handling detail but core behavior correct)

---

### 15. FUN_0048EBD0 — UI Dimension Capture — FAIL

**Source:** `analysis_pipeline\analyzed\0x0048ebd0__FUN_0048ebd0.c`

**Issues found:**
1. **Missing significant post-processing logic** — doc says "Captures 8 screen dimensions via FUN_00487060 and 8 via FUN_004870e0. Stores at param_1[0x44] through [0x53]." This is accurate for the first 16 stores (lines 10-41) but the function does much more:
   - Conditional fallback for negative values at param_1[0x50], param_1[0x48], param_1[0x51], param_1[0x49] (lines 42-53)
   - `param_1[0x5d] = 0` (line 54)
   - Vtable call at `*param_1 + 0x40` (line 55)
   - Three FUN_00486460 calls for UI params at indices 6, 7, 5 (lines 56-67)
   - FUN_0048f9f0() call (line 68) — **not listed in doc's Calls**
   - FUN_00566650() call (line 69) — **not listed in doc's Calls**
   - `param_1[0x5a] = 0` (line 70)

2. **Incomplete Calls list**:
   - Missing: `FUN_00486460` (called 3×)
   - Missing: `FUN_0048f9f0`
   - Missing: `FUN_00566650`
   - Missing: vtable call at +0x40

---

### 16. FUN_004986A0 — Render State Reset — PASS

**Source:** `analysis_pipeline\analyzed\0x004986a0__FUN_004986a0.c`

**Verification:**
- Calls FUN_00566650 ✓
- Zeroes param_1 + 0x1560 ✓
- Zeroes param_1 + 0x1564 ✓
- Zeroes param_1 + 0x1568 ✓
- Doc calls: FUN_00566650 ✓
- Accurate summary of a small function

---

### 17. FUN_0055DA50 — 3D→Screen-Space Vertex Transform & Lighting — PASS (triage entry)

**Source:** `analysis_pipeline\analyzed\0x0055da50__FUN_0055da50.c`

**Verification:**
- Size matches: 2247 bytes / 314 lines ✓
- D3D device calls via DAT_008b8f24 vtable ✓
- Matrix transforms using D3D functions ✓
- Saturated color arithmetic (paddsw at line 252) ✓
- Per-vertex lighting with distance checks ✓
- SQRT for distance computations ✓
- Complexity rating "Very high — 80+ local variables" matches source (extensive stack frame) ✓
- **Note:** This is a triage-style entry, not full `## FUN_` entry. Level of detail appropriate for triage.

---

### 18. FUN_0054E270 — Bounding-Box Computation from Vertex Data — PASS

**Source:** `analysis_pipeline\analyzed\0x0054e270__FUN_0054e270.c`

**Verification:**
- Iterates vertex arrays from param_1+0x118 (group count) ✓
- Computes covariance matrix (sum X², Y², Z², XY, XZ, YZ, X, Y, Z) ✓
- Flag 0x800000 at +0x14 controls transformed vs untransformed vertices ✓
- Eigen decomposition via FUN_0053b6f0 (3×3 covariance → OBB axes) ✓
- Builds 4×4 OBB-to-world matrix from eigenvectors ✓
- D3D device (DAT_008b8f24 vtable +4) transforms 8 OBB corners ✓
- Tracks min/max extents per axis ✓
- Computes final OBB extent radius at param_1+0x18 ✓
- Calls: FUN_0053b6f0, DAT_008b8f24 vtable +4 ✓
- Full detailed description matches the 283-line source

---

### 19. FUN_00448730 — Shadow Volume Extrusion — FAIL

**Source:** `analysis_pipeline\analyzed\0x00448730__FUN_00448730.c`

**Issues found:**
1. **Claimed calls not present in source:**
   - Doc lists calls: `FUN_00448480, FUN_00448510, FUN_004485d0, FUN_00448e90`
   - **None of these function calls appear in the decompiled source.** No FUN_00448xxx calls found at all.
   - These functions (quaternion init, rotation struct init, etc.) may have been inlined by the Ghidra decompiler, or the doc author wrote them from a different decompilation pass.
   - The source shows only SQRT, fpatan, and _DAT_ constants — all inline computation.

2. **Core logic is correct** (verified separately):
   - Guard: param_1[6] in range (2,11) ✓
   - Triangle iteration via linked list at param_1+7 ✓
   - Switch 0-5 for adjacent triangles ✓
   - Cross-product edge computation ✓
   - _DAT_0059e830 facing check ✓
   - Extrusion constants _DAT_0059e430, _DAT_0059ef18, _DAT_0059ef20 ✓
   - fpatan angle interpolation ✓
   - Writes to param_1[4] and param_1[1] ✓

**Recommendation:** Update Calls list to remove the four FUN_00448xxx functions, or add note about possible inlining.

---

### 20. FUN_0048F870 — UI Tile Grid — PASS

**Source:** `analysis_pipeline\analyzed\0x0048f870__FUN_0048f870.c`

**Verification:**
- Reads viewport via FUN_00498880 ✓
- Computes tile spacing from layout params (+0x48/+0x49 spacing, +0x54/+0x58 size) ✓
- Iterates rows (param_1[0x56]) × columns (param_1[0x57]) ✓
- Computes each tile's screen position with clamping ✓
- Renders each tile via FUN_0048ea20 ✓
- Vtable call at offset +0x2c ✓
- Calls: FUN_00498880, FUN_0048ea20, vtable+0x2c ✓
- Alignment logic with param_1[0x38], [0x40], [0x5a] (center/offset) ✓

---

### 21. FUN_0052804A — Fixed-Point IDCT / Color Transform — PASS

**Source:** `analysis_pipeline\analyzed\0x0052804a__FUN_0052804a.c`

**Verification:**
- 8-element 1D transform (first loop, param_1=8) ✓
- Fixed-point multiplication by constants: 0x3b21, 0x187e, 0x2e75, 0x21f9, 0x6c2, 0x4587, 0x1ccd, 0x133e, 0x1050, 0x5203 ✓
- Arithmetic shifts: >> 0xc (12) and >> 0x13 (19) ✓
- Second pass: 4 output elements (second loop, 4 iterations) ✓
- Output addressing: `*(param_4 + param_1×4) + param_5` with `>>5 & 0x3ff` lookup ✓
- Zero-skip optimization: if all 6 input channels zero → replicates single output value ✓
- No calls (pure math) ✓

---

## Summary

| # | Function | Result |
|---|----------|--------|
| 1 | FUN_005670D0 | **PASS** |
| 2 | FUN_00432810 | **PASS** |
| 3 | FUN_004484C0 | **PASS** |
| 4 | FUN_0043E230 | **PASS** |
| 5 | FUN_0056C2D0 | **PASS** |
| 6 | FUN_004B1DE0 | **PASS** |
| 7 | FUN_00583790 | **PASS** |
| 8 | FUN_004FD7E0 | **PASS** |
| 9 | FUN_00578F76 | **PASS** (duplicate entry noted) |
| 10 | FUN_005986CB | **PASS** |
| 11 | FUN_0050CDFF | **PASS** |
| 12 | FUN_004CB620 | **PASS** |
| 13 | FUN_00455560 | **PASS** |
| 14 | FUN_00489920 | **PASS** |
| 15 | FUN_0048EBD0 | **FAIL** — missing Calls (FUN_00486460, FUN_0048f9f0, FUN_00566650, vtable+0x40) and post-processing logic |
| 16 | FUN_004986A0 | **PASS** |
| 17 | FUN_0055DA50 | **PASS** (triage entry) |
| 18 | FUN_0054E270 | **PASS** |
| 19 | FUN_00448730 | **FAIL** — claimed Calls (FUN_00448480, FUN_00448510, FUN_004485d0, FUN_00448e90) absent from source |
| 20 | FUN_0048F870 | **PASS** |
| 21 | FUN_0052804A | **PASS** |

**Overall: 19/21 PASS, 2/21 FAIL**

**Action items for CHANGELOG:**
- `[CORRECTION] FUN_0048EBD0: doc missing FUN_00486460 (×3), FUN_0048f9f0, FUN_00566650, vtable+0x40 calls; missing post-processing logic (negative clamping, param_1[0x5d], param_1[0x5a])`
- `[CORRECTION] FUN_00448730: claimed calls FUN_00448480/FUN_00448510/FUN_004485d0/FUN_00448e90 not found in .c source — likely inlined by decompiler. Update Calls section.`
- `[CLEANUP] FUN_00578F76: duplicate entry at lines 5824 and 5852 — merge or remove duplicate.`
