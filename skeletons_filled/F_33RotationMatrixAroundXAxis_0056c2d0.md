## F_33RotationMatrixAroundXAxis_0056c2d0 — RotateMatrixAroundXAxis

**Summary:** Applies X-axis rotation to columns 1 and 2 of a 3x3 matrix using sin/cos of angle a2. Column 0 (X direction) is unchanged. Optionally extracts Euler angles if a3 is non-null. Part of vehicle physics suspension orientation setup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionDataCopyToPhysicsEngine (004389b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | matrix col 0 row 0 (unchanged by rotation, read for Euler extraction) |
| this | 0x8 | RW | — | matrix col 0 row 1 (rotated around X) |
| this | 0x10 | RW | — | matrix col 0 row 2 (rotated around X) |
| this | 0x18 | R | — | matrix col 1 row 0 (unchanged by rotation) |
| this | 0x20 | RW | — | matrix col 1 row 1 (rotated around X) |
| this | 0x28 | RW | — | matrix col 1 row 2 (rotated around X) |
| this | 0x30 | R | — | matrix col 2 row 0 (unchanged by rotation) |
| this | 0x38 | RW | — | matrix col 2 row 1 (rotated around X) |
| this | 0x40 | RW | — | matrix col 2 row 2 (rotated around X) |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | convert double to float or handle floating-point value |

**Guard conditions:** If a3 non-null: extract Euler angles. Two paths: gimbal lock (fabs(matrix[1][1]) == 1.0) → atan2(-matrix[2][0], matrix[0][0]); normal → atan2(matrix[0][2], matrix[2][2]) and atan2(matrix[0][1], matrix[1][1]).
