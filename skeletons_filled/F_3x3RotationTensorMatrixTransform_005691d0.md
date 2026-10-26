## F_3x3RotationTensorMatrixTransform_005691d0 — ComputeInertiaTimesAngularVelocity

**Summary:** Converts Euler angles (a2) to rotation matrix, transforms inertia tensor to world space via F_3x3InertiaTensorTransform, then computes three dot products of transformed inertia rows with angular velocity vector, storing result as torque/force at offsets 0x7C, 0x84, 0x8C.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsStateVectorConversion (0040ef70), sub_438F00 (00438f00), VehiclePhysicsInitializer (00439210), sub_43C250 (0043c250), FloatDoubleCoordinateTransform (00459830), VehiclePhysicsJointSystemLoader (0056d930), sub_56F100 (0056f100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | RW | — | output torque/force X component (dot product result) |
| this | 0x84 | RW | — | output torque/force Y component (dot product result) |
| this | 0x8C | RW | — | output torque/force Z component (dot product result) |
| this | 0x94 | R | — | angular velocity X component (input) |
| this | 0x9C | R | — | angular velocity Y component (input) |
| this | 0xA4 | R | — | angular velocity Z component (input) |
| this | 0xEC | R | — | transformed inertia row 0 col 0 |
| this | 0xF4 | R | — | transformed inertia row 0 col 1 |
| this | 0xFC | R | — | transformed inertia row 0 col 2 |
| this | 0x104 | R | — | transformed inertia row 1 col 0 |
| this | 0x10C | R | — | transformed inertia row 1 col 1 |
| this | 0x114 | R | — | transformed inertia row 1 col 2 |
| this | 0x11C | R | — | transformed inertia row 2 col 0 |
| this | 0x124 | R | — | transformed inertia row 2 col 1 |
| this | 0x12C | R | — | transformed inertia row 2 col 2 |

**Written-by note (persistence):**
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005692a0 | F_3x3InertiaTensorTransform | transforms inertia tensor by rotation matrix (world-space conversion) |
| 0056bd40 | EulerAnglesTo33RotationMatrix | converts Euler angles (a2) to 3x3 row-major rotation matrix |

**Guard conditions:** None — unconditional operations, no branches or early returns.
