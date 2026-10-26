## SuspensionParamUpdate_004e24a0 — SuspensionParamUpdate

**Summary:** Updates wheel suspension parameters — ride height offset, damper angle, and steering angle for a given wheel index. Rebuilds rotation matrix on angle change. Part of vehicle suspension system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | Suspension rest height / chassis reference position |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005670d0 | F_33RotationMatrixFromEulerAngles | Builds 3x3 rotation matrix from damper Euler angles when angle changes |
| 00567340 | RotationMatrixYAxisRotationEulerExtraction | Extracts Y-axis rotation Euler angle for steering orientation |

**Guard conditions:** Checks if new damper angle (a5 + this[74*a2+115]) equals old angle (this[74*a2+103]). If equal (v9 == true), skips rotation matrix rebuild.
