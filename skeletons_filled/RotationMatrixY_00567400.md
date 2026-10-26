## RotationMatrixY_00567400 — ApplyYRotationThenExtractEuler

**Summary:** Rotates a 3x3 row-major matrix (this) around the Y axis by angle a2 (right-multiply by Ry(a2): replaces columns 0 and 2 using sin/cos), then extracts Euler angles to output buffer a3. Handles gimbal lock singularity.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraModeViewportUpdate (00409a00), sub_4A3320 (004a3320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | matrix row 0 col 0, rotated |
| this | 0x8 | RW | — | matrix row 0 col 2, rotated |
| this | 0xC | RW | — | matrix row 1 col 0, rotated |
| this | 0x10 | R | — | matrix row 1 col 1, read for Euler extraction |
| this | 0x14 | RW | — | matrix row 1 col 2, rotated and extracted for x-angle |
| this | 0x18 | RW | — | matrix row 2 col 0, rotated |
| this | 0x20 | RW | — | matrix row 2 col 2, rotated |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | converts float value, called before Euler extraction |

**Guard conditions:** Checks fabs(this[5]) == 1.0 for gimbal lock in Euler extraction. If true: singularity path — sets z-angle from combined this[6], this[0], z-angle = 0. If false: normal path — individual y-angle and z-angle computation from matrix elements.
