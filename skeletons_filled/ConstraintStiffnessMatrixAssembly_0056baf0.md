## ConstraintStiffnessMatrixAssembly_0056baf0 — AssembleContactConstraintMatrix

**Summary:** Builds diagonal and off-diagonal constraint stiffness matrix blocks for contact constraints. Computes cross product of constraint axes, transforms through world-space inverse inertia tensor, scales by inverse mass, accumulates into sparse block matrix. Part of vehicle physics constraint solver.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** InertialTensorVectorTransform (0056a240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB4 | R | — | inverse mass (1/m) |
| this | 0x228 | R | — | constraint matrix base pointer (sparse block storage) |
| this | 0x23C | R | — | contact constraint count (third array) |
| this | 0x240 | R | — | contact constraint entry buffer pointer (third array, stride 88) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | transform vector through 3x3 rotation matrix (inverse inertia) |

**Guard conditions:** PASSES when contact count (this+0x23C) > 0 — iterates all contact constraints computing matrix blocks. BLOCKED when ≤ 0 — skip entirely, return 0.
