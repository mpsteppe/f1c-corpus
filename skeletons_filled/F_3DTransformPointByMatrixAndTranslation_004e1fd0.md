## F_3DTransformPointByMatrixAndTranslation_004e1fd0 — PointTransformByMatrixWithTranslation

**Summary:** Transforms 3D point by rotation matrix (rotation at this+0x14, component scale at this[572]) and adds translation (at this+0x8E8). Outputs transformed point to a2 and copies rotation quaternion to a3. Camera/view space coordinate transform.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00), CameraTransformComputation (0040b710), SteeringInterpolationCameraFollow (00434d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | rotation matrix row 0 element 0 |
| this | 0x18 | R | — | rotation matrix row 0 element 1 |
| this | 0x1C | R | — | rotation matrix row 0 element 2 |
| this | 0x20 | R | — | rotation matrix row 1 element 0 |
| this | 0x24 | R | — | rotation matrix row 1 element 1 |
| this | 0x28 | R | — | rotation matrix row 1 element 2 |
| this | 0x2C | R | — | rotation matrix row 2 element 0 |
| this | 0x30 | R | — | rotation matrix row 2 element 1 |
| this | 0x34 | R | — | rotation matrix row 2 element 2 |
| this | 0x38 | R | — | rotation quaternion x |
| this | 0x3C | R | — | rotation quaternion y |
| this | 0x40 | R | — | rotation quaternion z |
| this | 0x8E8 | R | — | translation/position offset X |
| this | 0x8EC | R | — | translation/position offset Y |
| this | 0x8F0 | R | — | translation/position offset Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always applies full transform.
