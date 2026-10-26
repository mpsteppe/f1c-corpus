## sub_56ECF0_0056ecf0 — PhysicsConstraintSolverStep

**Summary:** Executes the physics constraint solver step: zeroes the constraint matrix, transforms wheel/suspension/constraint data, computes inertia tensor transforms, and reinitializes identity matrices for active bodies flagged by bit 0 of byte at offset +44 or +68.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelDataCopy (004414d0), PhysicsStepFrame (00441600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x30) | 0x14 | R | — | Vtable offset 20 — virtual method for final solve |
| *(this+0x30) | 0x1C | R | — | Vtable offset 28 — virtual method for matrix clear |
| this | 0x0 | R | — | Count of wheel bodies (joint array) |
| this | 0x4 | R | — | Pointer to wheel body array (stride 580) |
| this | 0x8 | R | — | Count of bodies in first batch (this[2]) |
| this | 0xC | R | — | Pointer to first batch array (stride 48) |
| this | 0x10 | R | — | Count of bodies in second batch (this[4]) |
| this | 0x14 | R | — | Pointer to second batch array (stride 48) |
| this | 0x18 | R | — | Count of constraints (this[6]) |
| this | 0x1C | R | — | Pointer to constraint array (stride 72) |
| this | 0x20 | R | — | Matrix dimension (this[8]) |
| this | 0x28 | R | — | Column pointer array (this[10]) |
| this | 0x2C | R | — | Row pointer array (this[11]) |
| this | 0x30 | R | — | Vtable pointer (this[12]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056a240 | InertialTensorVectorTransform | Transform inertia tensor vector for wheel body |
| 0056cd70 | sub_56CD70 | Finalize constraint matrix solve (non-virtual path) |
| 0056ec00 | BatchProcessingLoop3Passes | Run 3-pass matrix transforms on batch data |
| 0056ec70 | MatrixIdentityInitialization | Init identity matrix for a row/column |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Wheel body count |
| this | 0x8 | > | 0 | First batch body count (this[2]) |
| this | 0x10 | > | 0 | Second batch body count (this[4]) |
| this | 0x18 | > | 0 | Constraint count (this[6]) |

**Guard interpretation:** PASSES when count > 0 for each group — processes bodies/constraints. BLOCKED for each group independently when its count <= 0 (skips that group). Also checks this[12] (vtable) for virtual vs non-virtual matrix clear and finalize paths.
