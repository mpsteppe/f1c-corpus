## CollisionPositionTransform_00446fd0 — CollisionPositionTransform

**Summary:** Transforms a collision contact position from body-local coordinates to world space using the body rotation matrix, subtracts the vehicle's world-space position, then applies two consecutive 3x3 matrix coordinate transformations. Part of collision detection geometry processing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15F0 | R | — | pointer to rigid body state struct |
| this | 0x15FC | R | — | rigid body state field (accessed via callee) |
| this | 0x1604 | R | — | rigid body state field (accessed via callee) |
| this | 0x160C | R | — | vehicle position X (this+5628) after subtraction |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | transforms 3D vector by 3x3 rotation matrix |
| 0056c740 | F_33MatrixMultiply | multiplies two 3x3 matrices |

**Guard conditions:** no branches — always executes full transform chain
