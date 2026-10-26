## CoordinateTransformWithOffset_004ef6c0 — CoordinateTransformWithOffset

**Summary:** Transforms a coordinate vector from one space to another using Euler angle rotation matrix, ride height delta, and position offsets. Part of vehicle physics coordinate transformation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), AIRacingLinePathFollowing (004e9ca0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34D4 | R | — | Position offset X component |
| this | 0x34D8 | R | — | Position offset Y component |
| this | 0x34DC | R | — | Position offset Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ef680 | RideHeightDelta | Computes ride height delta 3-vector for pitch compensation |
| 00566e40 | EulerToRotationMatrix | Converts Euler angles to 3x3 rotation matrix |

**Guard conditions:** None — always executes full transform.
