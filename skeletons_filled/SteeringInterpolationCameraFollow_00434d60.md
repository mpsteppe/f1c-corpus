## SteeringInterpolationCameraFollow_00434d60 — Interpolated Steering Camera Follow

**Summary:** Computes interpolated camera position and steering angle to smoothly follow a vehicle, handling both normal chase-cam and special fixed-camera (mode 5) paths. Part of the camera/rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460), sub_4348B0 (004348b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x18 | R | — | Target object active/validity flag (must be non-zero to proceed) |
| *(this+0xC) | 0x0 | R | — | Pointer to camera target/vehicle state object |
| *(this+0xC) | 0x38 | RW | — | Computed camera steering angle (output written by this function) |
| *(this+0xC) | 0x3C | RW | — | Complementary camera orientation angle (paired with 0x38) |
| *(this+0xC) | 0xA8 | RW | 0 | One-shot operation gate flag (cleared then restored around virtual call) |
| *(this+0xC) | 0xB0 | R | — | Target-enable flag (must be non-zero; guard at function entry) |
| *(this+0xC) | 0xBC | R | — | Current raw state value read before calling GuardedFunctionWithFlagSet |
| this | 0x1 | RW | 0 | One-shot "set initial camera target" byte flag (cleared after first use) |
| this | 0x4 | R | — | Camera mode selector (5 = special fixed-camera mode, bypasses interpolation) |
| this | 0xC | R | — | Pointer to camera target/vehicle state object (indirection target) |
| this | 0x10 | R | — | Minimum camera follow threshold (lower clamp for steering value) |
| this | 0x14 | R | — | Maximum camera follow threshold (upper clamp) |
| this | 0x18 | R | — | Vehicle index (guarded: must be >= 0 and < VehicleCount to enter normal path) |
| this | 0x1C | R | — | Secondary player/vehicle index (guarded >= 0) |
| this | 0x2C | R | — | Current waypoint/stride index into vehicle path array |
| this | 0x30 | R | — | Maximum steering angle / interpolation range cap |

**Written-by note (persistence):**
- *(this+0xC) 0x38: overwritten every call while target is valid — external changes lost
- *(this+0xC) 0x3C: overwritten every call while target is valid — external changes lost
- *(this+0xC) 0xA8: saved, zeroed, virtual-called, then restored — survives within call only
- this 0x1: set to 0 unconditionally when flag is non-zero, then read as zero thereafter — one-shot self-clearing

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403cd0 | sub_403CD0 | Gets camera/vehicle position from scene setup data into output vector |
| 00456060 | DualFieldGetter | Reads two related float fields (likely steering + offset) from vehicle state |
| 004582a0 | StridedArrayElementPointer | Returns pointer to element in vehicle path/state strided array by index |
| 004582c0 | GuardedFunctionWithFlagSet | Applies a computed value to a guarded field with conditional logic |
| 004e1fd0 | F_3DTransformPointByMatrixAndTranslation | Transforms a 3D point by a matrix and translation (camera-space conversion) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 5 | Camera mode: 5 = special fixed-camera path (bypasses normal interpolation) |
| this | 0x18 | < | 0 | Vehicle index: negative = invalid, falls through to backup camera logic |

**Guard interpretation:** When camera mode is 5 (fixed special camera), or when vehicle indices are out of range (this+0x18 < 0, this+0x1C < 0, or this+0x18 >= VehicleCount), the normal interpolated chase-camera path is BLOCKED. Instead, a fallback path computes a static camera position either from a known reference point or from the scene setup. When all guards PASS, the function interpolates between two reference positions weighted by progress and writes steering angles to the target object.
