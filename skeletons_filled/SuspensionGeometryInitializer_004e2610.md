## SuspensionGeometryInitializer_004e2610 — SuspensionGeometryInitializer

**Summary:** Initializes suspension geometry for a wheel — computes wheel offset from chassis origin, copies two rotation matrices (suspension orientation + upright orientation), and extracts Euler angles from both. Part of vehicle suspension initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | R | — | Chassis local origin X |
| this | 0x4C | R | — | Chassis local origin Y |
| this | 0x50 | R | — | Chassis local origin Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588570 | FloatConvertWrapper | Floating-point conversion helper for Euler angle extraction |

**Guard conditions:** Checks if fabs of rotation matrix element (sin of angle) == 1.0 to detect gimbal lock. If true, uses alternate atan2 formula (X-Z axes only, Y=0). If false, uses standard formula for both Y and X Euler angles.
