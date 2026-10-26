## QuaternionTransformComputation_004d5c70 — QuaternionCubicInterpolationTransform

**Summary:** Computes a quaternion/rotation transform using cubic interpolation parameterized by a2 (negated if positive), a3 (clamped [0,1]), and a4. Builds four 4x4 transform matrices from these parameters, calls sub_5677B0 to combine them, then stores result as 8 doubles in `this`. On failure, zeros the output and sets the last element to identity (1.0).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_430750 (00430750), BrakeTemperatureFadeModel (00430a50), TireCompoundPerWheelPhysicsApplication (0043da10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | output quaternion/transform component 0 |
| this | 0x4 | RW | 0 | output quaternion/transform component 1 |
| this | 0x8 | RW | 0 | output quaternion/transform component 2 |
| this | 0xC | RW | 0 | output quaternion/transform component 3 |
| this | 0x10 | RW | 0 | output quaternion/transform component 4 |
| this | 0x14 | RW | 0 | output quaternion/transform component 5 |
| this | 0x18 | RW | 0 | output quaternion/transform component 6 |
| this | 0x1C | RW | 1072693248 → 1.875f | output quaternion/transform component 7 (identity when reset) |
| this | 0x20 | RW | — | stores input parameter a4 (used in interpolation) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005677b0 | sub_5677B0 | combines four 4x4 transform matrices into final result |

**Guard conditions:** If a2 > 0, negates it (forces negative). If a3 < 0, clamps to 0. If a3 > 1, clamps to 1. If sub_5677B0 returns non-zero (failure), zeros all 8 output doubles and sets last to identity (1.0).
