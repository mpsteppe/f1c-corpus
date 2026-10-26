## sub_56BDE0_0056bde0 — AngleAxisToRotationMatrix

**Summary:** Converts angle-axis rotation vector (a2) to a 3x3 rotation matrix using Rodrigues' rotation formula. Optionally extracts Euler angles from resulting matrix when a3 is non-null. Part of vehicle physics orientation math.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionDataCopyToPhysicsEngine (004389b0), VehiclePhysicsInitializer (00439210), VehiclePhysicsIntegrationStep (00441650), sub_447780 (00447780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | rotation matrix row 0 col 0 (read for Euler extraction) |
| this | 0x8 | R | — | rotation matrix row 0 col 1 |
| this | 0x10 | R | — | rotation matrix row 0 col 2 |
| this | 0x18 | R | — | rotation matrix row 1 col 0 |
| this | 0x20 | R | — | rotation matrix row 1 col 1 |
| this | 0x28 | R | — | rotation matrix row 1 col 2 |
| this | 0x30 | R | — | rotation matrix row 2 col 0 |
| this | 0x40 | R | — | rotation matrix row 2 col 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | convert double to float or handle floating-point value |

**Guard conditions:** If angle-axis vector norm-squared > 0.0: compute axis, angle, apply Rodrigues rotation. If ≤ 0: skip matrix update (leave unchanged). If a3 non-null: extract Euler angles from result matrix — two paths: gimbal lock (fabs(sin_y)==1) uses atan2(-m[2][0], m[0][0]), normal path uses atan2(m[2][0], m[2][2]) and atan2(m[0][1], m[1][1]).
