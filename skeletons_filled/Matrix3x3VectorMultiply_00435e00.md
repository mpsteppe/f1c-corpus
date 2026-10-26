## Matrix3x3VectorMultiply_00435e00 — 3x3 matrix times 3-vector multiply

**Summary:** Computes matrix-vector product result = M * v for a 3x3 matrix stored as 9 doubles and a 3-element vector. Used for coordinate transformations in the physics engine.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RigidBodyConstraintJointSolver (004359a0), VehiclePhysicsInitializer (00439210), RigidBodyTorqueAccumulation (00441bb0), SteeringGeometryUpdate (00442060), sub_4423B0 (004423b0), sub_442C90 (00442c90), WheelContactForceSolver (00443150), DamperSpringForceComputationWithAntiRoll (004432f0), sub_56A5D0 (0056a5d0), ConstraintStiffnessMatrixAssembly (0056baf0), F_3x3MatrixInverseCoordinateTransform (0056d020), sub_56D2D0 (0056d2d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Matrix row 0, column 0 |
| this | 0x8 | R | — | Matrix row 0, column 1 |
| this | 0x10 | R | — | Matrix row 0, column 2 |
| this | 0x18 | R | — | Matrix row 1, column 0 |
| this | 0x20 | R | — | Matrix row 1, column 1 |
| this | 0x28 | R | — | Matrix row 1, column 2 |
| this | 0x30 | R | — | Matrix row 2, column 0 |
| this | 0x38 | R | — | Matrix row 2, column 1 |
| this | 0x40 | R | — | Matrix row 2, column 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes, no conditional branches.
