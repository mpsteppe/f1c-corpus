## RigidBodyTransformUpdate_0043e6a0 — RigidBodyPositionAndOrientationUpdate

**Summary:** Updates a rigid body's position by adding a delta vector, computes Euler angle extraction from its rotation matrix/quaternion (atan2-based), and calls the transform update function. Part of vehicle rigid-body physics integration.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleTelemetryPositionAccumulator (004ec080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15F0 | R | — | pointer to rigid body state struct |
| this | 0x15F4 | R | — | rigid body state field (accessed via callee) |
| this | 0x15FC | R | — | rigid body state field (accessed via callee) |
| this | 0x1604 | R | — | rigid body state field (accessed via callee) |
| this | 0x160C | R | — | rigid body state field (accessed via callee) |
| this | 0x161C | R | — | rigid body state field (accessed via callee) |
| this | 0x1624 | R | — | rigid body state field (accessed via callee) |
| this | 0x162C | R | — | rigid body state field (accessed via callee) |
| this | 0x1634 | R | — | rigid body state field (accessed via callee) |
| this | 0x163C | R | — | rigid body state field (accessed via callee) |
| this | 0x164C | R | — | rigid body state field (accessed via callee) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567740 | FPUControlWordMaskExtract | save/restore FPU control word precision mask |
| 00567780 | EmptyStub_7780 | empty stub (no-op) |
| 0056f100 | sub_56F100 | applies position/rotation update to rigid body |
| 00588570 | FloatConvertWrapper | float conversion helper for FPU state management |

**Guard conditions:** branch on `fabs(v4+0x44) == 1.0` (rotation matrix w-component) — determines Euler angle extraction path: quaternion path (atan2 of negated values) vs rotation matrix path (atan2 of matrix elements)
