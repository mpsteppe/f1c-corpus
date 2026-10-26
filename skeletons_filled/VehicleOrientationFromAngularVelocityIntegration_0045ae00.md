## VehicleOrientationFromAngularVelocityIntegration_0045ae00 — VehicleOrientationFromAngularVelocityIntegration

**Summary:** Integrates angular velocity over time delta to update vehicle orientation. Reads angular velocity components, computes incremental rotation, extracts Euler angles from rotation matrix, and forwards result for body-state update. Part of vehicle physics integration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ModeDispatchedRenderPhysicsCall (0040f300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Previous angular velocity timestamp (float) |
| this | 0xD0 | R | — | Pointer/flag check; if zero, skip integration |
| this | 0xD8 | R | — | Angular velocity X component (double) |
| this | 0xE0 | R | — | Angular velocity Y component (double) |
| this | 0xE8 | R | — | Angular velocity Z component (double) |
| this | 0x138 | R | — | Angular velocity scale/axis input X (double at offset 312) |
| this | 0x140 | R | — | Angular velocity scale/axis input Y (double at offset 320) |
| this | 0x148 | R | — | Angular velocity scale/axis input Z (double at offset 328) |
| this | 0x150 | R | — | Angular velocity scale/axis input W (double at offset 336) |
| this | 0x158 | R | — | Angular velocity scale/axis input V (double at offset 344) |
| this | 0x160 | R | — | Angular velocity scale/axis input U (double at offset 352) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b4d0 | sub_54B4D0 | Forward computed orientation (Euler angles + integrated position) for physics state update |
| 0056c020 | sub_56C020 | Perform quaternion/rotation matrix update from angular velocity delta |
| 00588570 | FloatConvertWrapper | Convert double to float for Euler angle computation |

**Guard conditions:** Guard at this+0xD0: if zero, skip integration and return immediately (inactive state). Otherwise, compute time delta from this+0x24, scale by angular velocity inputs, integrate orientation, extract Euler angles, and forward result.
