## SuspensionDataCopyToPhysicsEngine_004389b0 — Suspension data copy to physics engine bodies

**Summary:** Copies suspension geometry data (rotation matrix, inertia tensor) to physics engine body structs. Handles both active and inactive suspension paths. Part of vehicle physics initialization/data transfer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsSubObjectFree (00441450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | R | — | Rotation angle for Euler-to-matrix conversion |
| this | 0xBC | R | — | Scale factor for inertia tensor transform |
| this | 0x15C | R | — | Pointer to first physics body struct |
| this | 0x160 | R | — | Pointer to second physics body struct |
| this | 0x1C4 | R | — | Boolean flag: active suspension path selector |
| this | 0x1C5 | R | — | Boolean flag: sub-function call selector |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005692a0 | F_3x3InertiaTensorTransform | Transforms inertia tensor to body frame |
| 00569410 | InertiaTensorWorldSpaceTransform | Transforms inertia tensor to world space |
| 0056bd40 | EulerAnglesTo33RotationMatrix | Converts Euler angles to 3x3 rotation matrix |
| 0056bde0 | sub_56BDE0 | Computes rotation matrix for suspension geometry |
| 0056c2d0 | F_33RotationMatrixAroundXAxis | Builds 3x3 rotation matrix around X axis |

**Guard conditions:** If this[0x1C4] (active flag) is zero, uses alternative path without memset zeroing. No early-return guard.
