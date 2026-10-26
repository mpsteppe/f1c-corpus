## RotateMatrixAndExtractAngles_005674c0 — rotate 3x3 matrix and extract Euler angles

**Summary:** Rotates a 3x3 matrix by angle a2 using sin/cos. Updates all 9 elements. Then extracts Euler angles (yaw, pitch, roll) into output at a3. Handles gimbal lock when center element this[5] is ±1. Camera/3D math subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraModeViewportUpdate (00409a00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | matrix element [0][0] (rotated) |
| this | 0x4 | RW | — | matrix element [0][1] (rotated) |
| this | 0x8 | R | — | matrix element [0][2] (used in angle extraction) |
| this | 0xC | RW | — | matrix element [1][0] (rotated) |
| this | 0x10 | RW | — | matrix element [1][1] (rotated) |
| this | 0x14 | R | — | matrix element [1][2] (used before rotation, saved to output pitch) |
| this | 0x18 | RW | — | matrix element [2][0] (rotated) |
| this | 0x1C | RW | — | matrix element [2][1] (rotated) |
| this | 0x20 | R | — | matrix element [2][2] (used in angle extraction) |

**Written-by note (persistence):**
- this 0x0: overwritten each call; external poke does not survive
- this 0x4: overwritten each call; external poke does not survive
- this 0xC: overwritten each call; external poke does not survive
- this 0x10: overwritten each call; external poke does not survive
- this 0x18: overwritten each call; external poke does not survive
- this 0x1C: overwritten each call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | constant 1.0 (compared against center element for gimbal lock) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | float conversion / normalization after rotation |

**Guard conditions:** If fabs(this[5]) == 1.0 (center element ±1, gimbal lock) → pitch=0, yaw=atan2(-this[6], this[0]). Else → pitch=atan2(this[2], this[8]), yaw=atan2(this[3], this[4]). Roll saved from pre-rotation this[5] (negated).
