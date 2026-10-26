## AudioParameterInterpolation_004ff680 — Audio parameter state interpolation

**Summary:** Interpolates audio/physics parameter state between frames: clamps delta, unpacks short vectors and bitfields, applies rotation via Euler angles, copies interpolated packed state to output. Audio/parameter blending system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PassthroughWrapper_00c0 (005000c0), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059ed50 | dbl_59ED50 | R | VelocityDampingFactor [DERIVED] (also: ` — anti-roll rate scale) |
| 0059f0c0 | flt_59F0C0 | R | HUDLayoutOffsetX [DERIVED] |
| 005accb0 | flt_5ACCB0 | R | ClutchCatchSpeedScale [DERIVED] |
| 005ad350 | flt_5AD350 | R | ThrottleBrakeInputClamp [DERIVED] |
| 005ad354 | flt_5AD354 | R | SteerFFBClamp [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2580 | ShortVectorToFloatWithScale | Convert packed short[3] vector to float[3] with scale factor |
| 004b2800 | ShortToFloatVectorUnpack | Unpack short integers to floats for interpolation |
| 00566e40 | EulerToRotationMatrix | Convert Euler angles (float[3]) to 3x3 rotation matrix |
| 00567120 | sub_567120 | Apply rotation/acceleration to vector (physics transform) |
| 00587bdc | CRTFtol | Float-to-integer truncation for quantized output |

**Guard conditions:** Delta `(a1 - *(a2+4))` clamped to `[-1.25, 1.25]`. Scaled delta `v19 = v28 * 0.33399999` clamped to `[-0.075, 0.075]`. Always passes through to full interpolation.
