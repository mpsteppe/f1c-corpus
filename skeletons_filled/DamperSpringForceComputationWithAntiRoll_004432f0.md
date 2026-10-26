## DamperSpringForceComputationWithAntiRoll_004432f0 — ComputeDamperSpringAndAntiRollForces

**Summary:** Computes per-corner damper/spring forces from suspension travel, helper-spring abutment forces, and anti-roll bar coupling torques; accumulates resulting angular momentum into the chassis rigid-body for the physics integration step.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x1C | R | — | chassis orientation matrix element [0,0] (row 0, col 0) |
| *(this+0x15F0) | 0x24 | R | — | chassis orientation matrix element [0,1] |
| *(this+0x15F0) | 0x2C | R | — | chassis orientation matrix element [0,2] |
| *(this+0x15F0) | 0x34 | R | — | chassis orientation matrix element [1,0] |
| *(this+0x15F0) | 0x3C | R | — | chassis orientation matrix element [1,1] |
| *(this+0x15F0) | 0x44 | R | — | chassis orientation matrix element [1,2] |
| *(this+0x15F0) | 0x4C | R | — | chassis orientation matrix element [2,0] |
| *(this+0x15F0) | 0x54 | R | — | chassis orientation matrix element [2,1] |
| *(this+0x15F0) | 0x5C | R | — | chassis orientation matrix element [2,2] |
| *(this+0x15F0) | 0x64 | R | — | suspension attachment arm vector X (body-frame) |
| *(this+0x15F0) | 0x6C | R | — | suspension attachment arm vector Y |
| *(this+0x15F0) | 0x74 | R | — | suspension attachment arm vector Z |
| *(this+0x15F0) | 0x7C | R | — | direction / lever-arm vector X (for anti-roll bar couple) |
| *(this+0x15F0) | 0x84 | R | — | direction / lever-arm vector Y |
| *(this+0x15F0) | 0x8C | R | — | direction / lever-arm vector Z |
| *(this+0x15F0) | 0x14C | RW | — | accumulated angular momentum X (torque integral, written each frame) |
| *(this+0x15F0) | 0x154 | RW | — | accumulated angular momentum Y |
| *(this+0x15F0) | 0x15C | RW | — | accumulated angular momentum Z |
| *(this+0x1F00) | 0xCD4 | R | — | pointer to front-axle anti-roll bar link/suspension state struct (checked for null and flag at +0x40) |
| *(this+0x1F00) | 0xD14 | R | — | unknown (additional suspension/ARB state reference) |
| *(this+0x1F00) | 0xD18 | R | — | pointer to rear-axle anti-roll bar link/suspension state struct (checked for null and flag at +0x40) |
| *(this+0x1F00) | 0xD58 | R | — | unknown (additional vehicle state field) |
| *(this+0x1F00) | 0x3A64 | R | — | wheel contact point X (float, world-space) |
| *(this+0x1F00) | 0x3A68 | R | — | wheel contact point Y (float, world-space) |
| *(this+0x1F00) | 0x3A6C | R | — | wheel contact point Z (float, world-space) |
| this | 0x15F0 | R | — | pointer to chassis rigid-body sub-struct (3x3 orientation + position vectors + torque accumulator) |
| this | 0x16F0 | R | — | front-left suspension travel (double) |
| this | 0x16F8 | R | — | front-right suspension travel (double) |
| this | 0x1700 | R | — | rear-left suspension travel (double) |
| this | 0x1708 | R | — | rear-right suspension travel (double) |
| this | 0x1900 | R | — | first anti-roll bar enabled flag (byte) |
| this | 0x1908 | RW | 0 | first anti-roll bar displacement angle (double, clamped to [0, max]) |
| this | 0x190C | RW | 0 | upper 32 bits of first ARB displacement |
| this | 0x1910 | R | — | first anti-roll bar maximum displacement limit (double) |
| this | 0x1914 | R | — | upper 32 bits of first ARB max limit |
| this | 0x1918 | R | — | first anti-roll bar attachment/lever vector X (body-frame) |
| this | 0x1920 | R | — | first anti-roll bar attachment vector Y |
| this | 0x1928 | R | — | first anti-roll bar attachment vector Z |
| this | 0x1930 | R | — | first anti-roll bar constant term (base force) |
| this | 0x1938 | R | — | first anti-roll bar linear rate coefficient |
| this | 0x1940 | R | — | first anti-roll bar lateral-force reduction coefficient (cos-squared falloff) |
| this | 0x19E0 | RW | — | computed first anti-roll bar coupling force (double, written each frame) |
| this | 0x1A08 | R | — | second anti-roll bar enabled flag (byte) |
| this | 0x1A0C | R | — | second anti-roll bar constant term |
| this | 0x1A14 | R | — | second anti-roll bar lateral-force reduction coefficient |
| this | 0x1AB4 | RW | — | computed second anti-roll bar coupling force (double, written each frame) |
| this | 0x1ADC | R | — | damper force intercept (constant term) |
| this | 0x1AE4 | R | — | damper spring-rate coefficient (stiffness) |
| this | 0x1AEC | R | — | damper damping-coefficient (velocity-dependent) |
| this | 0x1AF4 | R | — | maximum suspension travel clamp limit (double) |
| this | 0x1AF8 | R | — | upper 32 bits of travel clamp limit |
| this | 0x1B9C | RW | — | computed total damper force (written each frame) |
| this | 0x1BBC | R | — | helper-spring enabled flag (byte) |
| this | 0x1BC0 | R | — | helper-spring constant term |
| this | 0x1BC8 | R | — | helper-spring rate term (quadratic-in-travel coefficient) |
| this | 0x1BD0 | R | — | helper-spring rate term 2 |
| this | 0x1BD8 | R | — | helper-spring rate term 3 |
| this | 0x1BE0 | R | — | helper-spring lateral-force reduction coefficient |
| this | 0x1F00 | R | — | pointer to vehicle global/shared state sub-struct (wheel contacts, suspension links) |

**Written-by note (persistence):**
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist
- this 0x1908: recalc every frame — external poke does NOT persist
- this 0x190C: recalc every frame — external poke does NOT persist
- this 0x19E0: recalc every frame — external poke does NOT persist
- this 0x1AB4: recalc every frame — external poke does NOT persist
- this 0x1B9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | multiply 3x3 matrix by 3-vector (transform direction from body to world frame) |
| 00436230 | QuadraticForm6x6 | compute quadratic form with a 6x6 stiffness/Jacobian matrix for force-coupling solve |
| 004388d0 | Mat3x3MulVec | multiply 3x3 matrix by 3-vector (local-to-world or world-to-local transform) |
| 00443150 | WheelContactForceSolver | solve wheel-ground contact forces for one corner (front or rear) |
| 00569ad0 | AccumulateAngularMomentum | accumulate torque contribution (force × lever-arm cross) into chassis angular momentum |

**Guard conditions:**
- Suspension travel averages (v41, v40) clamped to [0.0, *(this+0x1AF4)]; negative → set to 0.0, above max → cap at max.
- `if (*(_BYTE *)(this + 0x1BBC) && v39 < 0.0)` → helper-spring force computed only when flag set AND vertical displacement is negative (compression). BLOCKED if flag unset or v39 >= 0.
- `if (*(_BYTE *)(this + 0x1900))` → first anti-roll bar section entered only if enabled flag is non-zero. BLOCKED (skipped) if flag is zero.
- Within first ARB: `if (!v15 || *(_BYTE *)(v16 + 0x40))` → force computed if link pointer is null OR linked-object flag at +0x40 is set. PASSES when either condition true (likely means "no linked car" or "linked car ready").
- `if (*(double *)(this + 0x1908) >= 0.0)` and `if ( > *(this+0x1910))` → displacement clamped to [0, max]. Below 0 → set to 0; above max → set to max.
- `if (*(_BYTE *)(this + 0x1A08))` → second anti-roll bar section entered only if second enabled flag non-zero.
- Within second ARB: `if (!v25 || *(_BYTE *)(v26 + 0x40))` → same null/flag guard pattern as first ARB.
