## SceneRenderTransform_00548c20 — SceneOrientationAndTransformUpdate

**Summary:** Computes orientation offsets from a dual matrix transform, updates rotation matrices (orientation and random Euler), then processes wheel forces, camera projection (param 14), and recursive state traversal for an audio/scene node. Returns result from sub_5550E0 or the count field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioNodeIterator (00548dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Base pointer to scene/audio node object (passed as *this to subroutines) |
| this | 0x8 | R | — | Dual matrix pointer/flag — if non-null triggers DualMatrixTransformMultiply |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult (reverse gear throttle multiplier constant) |
| 008b78a0 | dword_8B78A0 | R | SoundManager (global sound manager pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541a70 | TransformWheelForcesToChassis | Transforms wheel force vectors into chassis coordinate frame |
| 00541b70 | CameraProjectionUpdate | Updates camera projection with parameter value 14 |
| 00541d10 | OrientationRotationMatrixUpdate | Updates orientation rotation matrix from negated position vector |
| 00541db0 | RandomRotationMatrixFromEulerAngles | Applies π/2 (1.5707964) rotation around computed axis via Euler angles |
| 0054b530 | DualMatrixTransformMultiply | Computes dual matrix transform into local float variables |
| 005550e0 | sub_5550E0 | Final processing step for the audio/scene node |
| 00556930 | RecursiveStateTraversalWithFlagCheck | Recursively traverses/updates child states with flag check |
| 005572b0 | sub_5572B0 | Prepares or updates state on a2 before wheel/camera processing |

**Guard conditions:** this[0x8] (dual matrix pointer) — if non-null, DualMatrixTransformMultiply is called to compute transform vectors. `*(a2+372)` must be > 0 to enter the wheel-force, camera-update, state-traversal, and sub_5550E0 code path; otherwise returns the count value directly.
