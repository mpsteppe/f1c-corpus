## InertialTensorVectorTransform_0056a240 — PreConstraintVelocityUpdate

**Summary:** Computes gyroscopic torque (ω × L), subtracts from applied torque, transforms result through inverse inertia to get angular velocity delta, computes linear velocity from momentum, then invokes constraint preparation sub-functions and stiffness matrix assembly.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_56ECF0 (0056ecf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | R | — | angular velocity ω x (gyroscopic torque input) |
| this | 0x84 | R | — | angular velocity ω y |
| this | 0x8C | R | — | angular velocity ω z |
| this | 0x94 | R | — | angular momentum L x |
| this | 0x9C | R | — | angular momentum L y |
| this | 0xA4 | R | — | angular momentum L z |
| this | 0xB4 | R | — | inverse mass (1/m) for linear velocity computation |
| this | 0xEC | R | — | world-space inverse inertia row 0 col 0 |
| this | 0xF4 | R | — | world-space inverse inertia row 0 col 1 |
| this | 0xFC | R | — | world-space inverse inertia row 0 col 2 |
| this | 0x104 | R | — | world-space inverse inertia row 1 col 0 |
| this | 0x10C | R | — | world-space inverse inertia row 1 col 1 |
| this | 0x114 | R | — | world-space inverse inertia row 1 col 2 |
| this | 0x11C | R | — | world-space inverse inertia row 2 col 0 |
| this | 0x124 | R | — | world-space inverse inertia row 2 col 1 |
| this | 0x12C | R | — | world-space inverse inertia row 2 col 2 |
| this | 0x134 | R | — | linear momentum x |
| this | 0x13C | R | — | linear momentum y |
| this | 0x144 | R | — | linear momentum z |
| this | 0x14C | R | — | applied torque x (before gyroscopic subtraction) |
| this | 0x154 | R | — | applied torque y |
| this | 0x15C | R | — | applied torque z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056a390 | sub_56A390 | combine angular delta and linear velocity into constraint-space vectors |
| 0056a5d0 | sub_56A5D0 | process/transform constraint velocity vectors |
| 0056a840 | sub_56A840 | build constraint-space velocity deltas |
| 0056aa60 | sub_56AA60 | compute body-local constraint data |
| 0056b5d0 | sub_56B5D0 | prepare joint constraint parameters |
| 0056baf0 | ConstraintStiffnessMatrixAssembly | assemble constraint stiffness matrix from prepared data |

**Guard conditions:** No guard — always executes fully with no early-return branches.
