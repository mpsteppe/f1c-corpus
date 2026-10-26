## WheelSuspensionTireStateInit_004e2540 — WheelSuspensionTireStateInit

**Summary:** Initializes wheel suspension and tire state for a given wheel index — computes wheel offset from chassis origin, stores camber/toe/caster parameters, and builds rotation matrix from Euler angles. Part of vehicle suspension system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | R | — | Chassis local origin X |
| this | 0x4C | R | — | Chassis local origin Y |
| this | 0x50 | R | — | Chassis local origin Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005670d0 | F_33RotationMatrixFromEulerAngles | Builds 3x3 rotation matrix from suspension toe/caster angles |
| 00567340 | RotationMatrixYAxisRotationEulerExtraction | Extracts Y-axis rotation Euler angle for steering orientation |

**Guard conditions:** None — always computes wheel offset and builds rotation matrix.
