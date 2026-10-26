## RigidBodyConstraintJointSolver_004359a0 — Rigid body constraint joint solver loop

**Summary:** Iterates over joint constraints between two rigid bodies, computes position and angular error, and applies corrective impulses via angular momentum accumulation. Part of the physics constraint solver system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Body position X |
| obj | 0xC | R | — | Body position Y |
| obj | 0x14 | R | — | Body position Z |
| obj | 0x64 | R | — | Body angular velocity / momentum X |
| obj | 0x6C | R | — | Body angular velocity / momentum Y |
| obj | 0x74 | R | — | Body angular velocity / momentum Z |
| obj | 0x7C | R | — | Body inverse inertia / mass diagonal X |
| obj | 0x84 | R | — | Body inverse inertia / mass diagonal Y |
| obj | 0x8C | R | — | Body inverse inertia / mass diagonal Z |
| this | 0x0 | R | — | Pointer to rigid body struct |
| this | 0x98 | R | — | Number of constraints to process |
| this | 0x9C | R | — | Base offset for constraint data array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | Transforms constraint direction vectors from local to world frame |
| 00569ad0 | AccumulateAngularMomentum | Applies computed constraint impulse to body angular momentum |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x98 | <= | 0 | Number of constraints |

**Guard interpretation:** If this->constraintCount <= 0, skip entire solver (no constraints to process). Also returns 0 if *this (body pointer) is null.
