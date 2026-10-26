## RotationMatrixYAxisRotationEulerExtraction_00567340 — ApplyXRotationThenExtractEuler

**Summary:** Rotates a 3x3 row-major matrix (this) around the X axis by angle a2 (right-multiply by Rx(-a2)), then extracts Euler angles to output buffer a3. Handles gimbal lock singularity in Euler extraction.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraModeViewportUpdate (00409a00), SuspensionParamUpdate (004e24a0), WheelSuspensionTireStateInit (004e2540)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | matrix row 0 col 0, read for Euler extraction |
| this | 0x4 | RW | — | matrix row 0 col 1, rotated |
| this | 0x8 | RW | — | matrix row 0 col 2, rotated |
| this | 0xC | R | — | matrix row 1 col 0, read for Euler extraction |
| this | 0x10 | RW | — | matrix row 1 col 1, rotated |
| this | 0x14 | RW | — | matrix row 1 col 2, rotated and extracted for x-angle |
| this | 0x18 | R | — | matrix row 2 col 0, read for Euler extraction |
| this | 0x1C | RW | — | matrix row 2 col 1, rotated |
| this | 0x20 | RW | — | matrix row 2 col 2, rotated and extracted for y-angle |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | converts float value, called before Euler extraction |

**Guard conditions:** Checks fabs(this[5]) == 1.0 for gimbal lock in Euler extraction. If true: singularity path — reads y-angle from this[6] and this[0], sets z-angle to 0. If false: normal path — reads y-angle from this[2], this[8] and z-angle from this[3], this[4].
