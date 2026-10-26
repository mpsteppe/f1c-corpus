# Cross-Validation Audit: worker_C batch 433-446

Audit date: 2026-07-15
Source: docs/18-physics-dynamics.md
Files: analysis_pipeline/analyzed/

---

## FUN_0056a390 — FAIL

Source: docs/18-physics-dynamics.md (line 247)

**Errors:**
- [INCOMPLETE] Entry is a stub — only a code block with one-line comment. No Globals section, no Calls section, no Struct offsets section, no Moddability, no target comment.
- [MISSING] Globals used: `DAT_005e5238`, `DAT_005e523c`, `_DAT_005e5240` (cross-product/force computation constants) not documented.
- [MISSING] Struct offsets: param_1+0x22c (count), +0x230 (array base, stride 0x38), +0x224 (force output array, stride 8), +0x7c/84/8c (body-space vectors), char at +0x34 (sign flag) — not documented.
- [MISSING] No calls listed (function is leaf, calls none — but this should be stated).

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0056a390 — Constraint Impulse Force Accumulation

Source: constraint_solver.cpp. Accumulates body-space impulse forces from multiple contact constraints across a body.

**Key logic:**
- Iterates over `count = *(int *)(param_1 + 0x22c)` items at `param_1 + 0x230` with stride 0x38 (contact point array)
- For each contact: computes 3D cross-product contributions using body-space vectors at +0x7c/+0x84/+0x8c (torque arms) and contact position offsets at +0x18/+0x20/+0x28 relative to contact base
- Scales by double constants `_DAT_005e5240`, `CONCAT44(DAT_005e523c, DAT_005e5238)` as force mixing factors
- Reads external force contributions from param_2, param_3 arrays (additional impulse inputs)
- Accumulates results into double array at `param_1 + 0x224` with stride 8 bytes per entry
- Sign flag at char `param_8 + 0x34`: if '\0' → adds forces; else → subtracts forces (bidirectional constraint)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x22c | ContactCount | int, number of active contacts |
| +0x230 | ContactArray | int*, pointer to contact data array, stride 0x38 |
| +0x224 | ForceAccumArray | double*, accumulator array, stride 8 |
| +0x7c | BodySpaceVec0 | double, body-space vector component |
| +0x84 | BodySpaceVec1 | double |
| +0x8c | BodySpaceVec2 | double |
| +0x4/0xc/0x14 | Position | double, body position for offset computation |
| +0x100 | ExtForceOffset | double, offset in position computation |

**Contact struct (stride 0x38):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x18/+0x20/+0x28 | PositionOffset | double[3], contact position offset from body |
| +0x30 | ForceIdx | int, index into force accumulator array |
| +0x34 | SignFlag | char, 0=add / non-zero=subtract |

**Globals:**
- `DAT_005e5238` / `DAT_005e523c` — double constant pair (force mixing factor, upper/lower 32 bits)
- `_DAT_005e5240` — double constant (force mixing factor)

**Calls:** none (pure math leaf function)

**Moddability:** hardcoded

---

## FUN_004ee2d0 — FAIL

Source: docs/18-physics-dynamics.md (line 592)

**Errors:**
- [FALSE_GLOBAL] Claims `_DAT_0059e8d0` as a suspension physics constant. This global does not appear anywhere in the source file. Remove it from the globals list.
- [MISSING_GLOBALS] Source also uses `_DAT_008afeec`, `_DAT_008afee8` (frame-timing comparison at top, lines 73-74) — not documented.

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004ee2d0 — Wheel Suspension Contact Force

Source: unknown (no assert strings). Computes suspension contact forces and wheel-terrain interaction for all 4 wheels.

**Key logic:**
- Switch on param_1+0x32bc (mode 0/1/2/3 — different suspension types)
- Mode 0: simple contact — copies+transforms wheel position into world space, checks contact threshold against _DAT_0059e430
- Mode 1: detailed per-wheel suspension — iterates 4 wheels (stride 0x3e), computes spring force from deflection, bump-stop limiting, damper rate from velocity
- Modes 2/3: deformable terrain/3D surface contact — reads surface normals from param_1+0x101c-0x102c, converts per-wheel, computes contact normal and friction
- Calls FUN_004ce3e0 (apply contact force at position) and FUN_004ce930 (apply contact constraint)

**Globals:**
- `_DAT_0059e430` — zero threshold
- `_DAT_0059e43c` — physics constant (~1.0)
- `DAT_0059e440` — physics zero threshold (~0.0f)
- `_DAT_005ad228` — bump-stop threshold
- `_DAT_005ad224` — secondary bump-stop threshold
- `_DAT_005ad220` — bump-stop gradient
- `_DAT_005ad21c` — damper force threshold
- `_DAT_005ad218` — damper saturation threshold
- `_DAT_005ad214` — damper gradient
- `_DAT_005ad210` — angle/position scale constant
- `_DAT_0059e98c` — terrain property scale
- `_DAT_005ac108` — contact surface property scale
- `_DAT_0059e778` — position/angle conversion factor
- `_DAT_008aceb8` — debris/particle emission threshold
- `_DAT_008afeec` / `_DAT_008afee8` — frame-timing globals (delta-time comparison)

**Calls:** FUN_004472b0 (suspension), FUN_004e16f0 (deformation), FUN_004ce380/FUN_004ce3e0 (contact force), FUN_004ce8f0/FUN_004ce930 (contact constraint), FUN_004ed750 (wheel hub pos), FUN_0044c4c0 (segment collision), FUN_004cce90 (particle/debris), FUN_004ee230 (unknown)

**Moddability:** hardcoded (physics constants)

---

## FUN_004e5ae0 — PASS

Source: docs/18-physics-dynamics.md (line 992)

All claims verified against source:
- Function signature and purpose match
- Wheel velocity transform through rotation matrix (0x34b0..0x34d0) ✓
- Angular velocity accumulation with damping factor (0x34a8) ✓
- Wheel rotation matrix update (0x34ec/0x34f0/0x34f4) ✓
- Torque vector transform (0x34f8/0x34fc/0x3500) ✓
- Call to FUN_00567120 ✓
- Call to FUN_004e43d0 ×4 ✓
- Brake force selection at 0x39b4 (0=front, 1=all/2, 2=rear) ✓
- Brake torque inversion at 0x3964 with 0x39c8 ✓
- Clamping between 0x399c (min) and 0x3998 (max) ✓
- Mode 0/1 at 0x39f0 ✓
- Zeroing when below DAT_0059e440 ✓

No false claims detected. Minor note: globals used (`_DAT_0059e450`, `_DAT_0059e7f8`, `DAT_0059e440`) are not explicitly listed in a Globals section, but no false claims are made about them.

---

## FUN_0043ec80 — PASS

Source: docs/18-physics-dynamics.md (line 1518)

All claims verified against source:
- Capping double values with upper bounds at offsets 0x17a8/0x17c0/0x17d8/0x17f0 vs 0x1c08/0x1c10/0x1c40/0x1c48 ✓
- Adding damping constants (_DAT_0059ec60, _DAT_0059ec90, _DAT_0059eb50) to values at 0x1808/0x1818/0x1bc0 ✓
- Calls FUN_0043bb30, FUN_0043bbd0, FUN_0043bb80 ✓

Minor: doc says "min clamp" but operations include both min-clamp and max-clamp depending on comparison direction. This is descriptive enough for the intended purpose.

---

## FUN_00438c10 — PASS

Source: docs/18-physics-dynamics.md (line 2043)

All claims verified against source:
- Calls FUN_004353f0, FUN_0042e1c0, FUN_0056d3e0, FUN_004363d0 (×2) ✓ (lines 11-15)
- Zeros 0x7CE dwords starting at param_1 ✓ (line 17)
- Initializes 4 sets at param_1+0x176, stride 0x119 (0x464 bytes apart) ✓ (lines 22-32)
- Each set stores two undefined4 values (0x8f5c28f6, 0x40767dc2) repeated across 6 slots ✓ (lines 24-30)
- Calls FUN_0043e230 (post-init) ✓ (line 33)

Minor: 0x8f5c28f6 as float is ~2.126e-9, not 0.01f as doc suggests with "(0.01f?)". The value interpretation is uncertain and doc correctly uses "?".

---

## FUN_00567030 — PASS

Source: docs/18-physics-dynamics.md (line 2453)

All claims verified against source:
- Multiplies each Euler angle by _DAT_0059e450 ✓ (lines 19, 21, 23)
- Computes fcos/fsin for yaw (fVar2/fVar3), pitch (fVar4/fVar5), roll (fVar6/fVar7) ✓ (lines 19-24)
- Computes 4 quaternion components into param_2[0..3] ✓ (lines 25-32)
- Globals: _DAT_0059e450 — DEG_TO_RAD factor ✓

---

## FUN_00434d40 — PASS

Source: docs/18-physics-dynamics.md (line 2880)

All claims verified against source:
- Checks if *(param_1 + 0xc) != null ✓ (line 8)
- If non-null: calls vtable method(1), sets pointer to null ✓ (lines 9-10)
- Returns 0 ✓ (line 12)

---

## FUN_004484f0 — PASS

Source: docs/18-physics-dynamics.md (line 3242)

All claims verified against source:
- Function body is empty (just `return;`) ✓
- No parameters, no locals, no operations ✓

---

## FUN_00431a50 — PASS

Source: docs/18-physics-dynamics.md (line 3614)

All claims verified against source:
- Stores param_2 at param_1 + 0x1cbc ✓ (line 8)
- Sets byte at param_1 + 0x1cb8 = 1 ✓ (line 9)

---

## FUN_00436610 — PASS

Source: docs/18-physics-dynamics.md (line 4011)

All claims verified against source:
- Compares param_3 against _DAT_0059e430 and param_1[3], param_1[7] thresholds ✓ (lines 16-17)
- Region 1 (param_3 <= 0): uses param_1[6] or param_1[5]+param_1[8] depending on param_1[7] ✓ (lines 17-22)
- Region 2 (param_3 <= param_1[3]): uses param_1[2] × param_3 ✓ (line 25)
- Region 3 (else): uses param_1[1] × param_3 + param_1[4] ✓ (line 28)
- Adds param_2 × param_1[0] (base linear term) ✓ (line 30)
- Distance adjustment using param_1[0xd]/param_1[0xe] (indices 13/14) with sign based on param_2 ✓ (lines 31-52)
- Globals: _DAT_0059e430 (zero threshold) ✓

---

## FUN_0056d1c0 — PASS

Source: docs/18-physics-dynamics.md (line 4430)

All claims verified against source:
- Reads two body pointers from param_1+0x4, param_1+0xc ✓ (lines 16, 19)
- Reads two position pointers from param_1+0x8, param_1+0x10 ✓ (lines 17-18)
- Computes 3D separating vector per axis using rotation matrix rows + position offsets ✓ (lines 20-37)
  - X: body1[+0x1c/24/2c]*pos1 + body1[+0x4] - body2[...] ✓
  - Y: body1[+0x34/3c/44]*pos1 + body1[+0xc] - body2[...] ✓
  - Z: body1[+0x4c/54/5c]*pos1 + body1[+0x14] - body2[...] ✓
- Computes magnitude: SQRT(dVar7² + dVar5² + dVar6²) ✓ (line 38)
- Stores at pdVar2[7] and *(param_1+0x10)+0x38 ✓ (lines 39-40)
- Struct offsets table matches source exactly ✓

---

## FUN_004e3aa0 — PASS

Source: docs/18-physics-dynamics.md (line 4762)

All claims verified against source:
- Reads tire load from param_1[0x3a] (suspension deflection) ✓ (line 29)
- Converts to doubles, calls FUN_0044c550 ✓ (line 37)
- Computes force direction in contact frame (param_1[0xe/0xf/0x10]) via 3×3 matrix multiply ✓ (lines 48-50)
- Computes contact load param_1[0x1d] = param_1[0x24] - local_50 ✓ (lines 51-53)
- Friction/slip model branches on _DAT_005ad168 threshold ✓ (line 60)
- Computes slip force param_1[0x11] with damping ✓ (line 81)
- Struct offsets: +0x00..2 (Position), +0x06..8 (Velocity), +0x0e..10 (ForceDir), +0x11 (SlipForce), +0x1d (ContactLoad), +0x1e..1f (FrictionParams), +0x24 (SuspensionDefl), +0x33..35 (ContactForce), +0x39..3c (SuspensionParams) — all verified ✓
- Globals: DAT_0059e440 (zero threshold), _DAT_005ad168 (slip threshold) — both present ✓

---

## FUN_005000e0 — PASS

Source: docs/18-physics-dynamics.md (line 5244)

All claims verified against source:
- Reads 3 floats from param_1+8, +0xc, +0x10 into doubles ✓ (lines 22-24)
- Sets up double constants ✓ (lines 25-28)
- Calls FUN_0044c4c0 ✓ (line 30)
- Compares param_2 with stored value at +0xc ✓ (lines 33-38)
- If param_2 >= stored (not equal): updates field +0xc, returns 1 ✓ (lines 38-40)
- Returns 0 otherwise ✓ (line 31, 43)

---

## FUN_004efb20 — PASS

Source: docs/18-physics-dynamics.md (line 5722)

All claims verified against source:
- Calls FUN_004ef680 to initialize vec3 local_c/8/4 ✓ (line 13)
- Transforms through 3x3 rotation matrix (+0x34b0..+0x34d0) ✓ (lines 14-22)
- Adds translation (+0x34d4/+0x34d8/+0x34dc) ✓ (lines 23-25)
- Outputs additional vec3 from +0x34e0/+0x34e4/+0x34e8 to param_2 ✓ (lines 26-28)
- Moddability: hardcoded ✓
