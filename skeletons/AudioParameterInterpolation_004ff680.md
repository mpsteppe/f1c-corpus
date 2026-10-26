## AudioParameterInterpolation_004ff680 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 004b2580 | ShortVectorToFloatWithScale | [LLM] |
| 004b2800 | ShortToFloatVectorUnpack | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |
| 00567120 | sub_567120 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
