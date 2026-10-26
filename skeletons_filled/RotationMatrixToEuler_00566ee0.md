## RotationMatrixToEuler_00566ee0 — RotationMatrixToEulerAngles

**Summary:** Extracts 3 Euler angles (x, y, z) from a 3x3 row-major rotation matrix. Handles gimbal lock singularity by setting z-angle to 0 and computing y-angle from the combined rotation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_567010 (00567010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output Euler x-angle (pitch) |
| this | 0x4 | RW | — | output Euler y-angle (yaw) |
| this | 0x8 | RW | 0 | output Euler z-angle (roll), set to 0 on singularity |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8968 | flt_5B8968 | R | EulerSingularityThreshold [DERIVED] (also: ` -- singularity threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks FPU status word (v2 & 0x4100) after x-angle computation. If flag set (singularity / domain error from sqrt of near-zero cos-angle): sets z-angle = 0, computes y-angle from a1[6], a1[0] combined rotation. If flag clear (normal): computes y-angle from a1[2], a1[8] and z-angle from a1[3], a1[4] separately.
