## AudioSampleCrossFadeInterpolation_004ff8f0 — Audio sample cross-fade with position/rotation/blend

**Summary:** Cross-fades between two audio sample states `a3`/`a4`: computes blend factor from time, interpolates position via Hermite spline, rotation via quaternion slerp, and packed bitfields. Audio sample playback system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioSamplePlaybackWithPitchModulationAndStereoP (00500210), CollisionTestWithThreshold (00500560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 0059e77c | flt_59E77C | R | ShortVertexScale [DERIVED] (also: ` — short-to-float scale/conversion factor) |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 005ad35c | flt_5AD35C | R | BlendThresholdFloat [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b2580 | ShortVectorToFloatWithScale | Convert packed short[3] to float[3] with scale |
| 004b2930 | FloatToBitfieldPack | Pack float into bitfield representation |
| 004b2980 | BitfieldExtractScale | Extract scaled value from bitfield |
| 004b29b0 | BitfieldInsert | Insert value into bitfield |
| 004b29f0 | ShortComputation_29f0 | Compute short value from bitfield data |
| 004b2a30 | BitfieldExtract | Extract raw bitfield value |
| 004b2a40 | FloatToBitfieldEncoder | Encode float as bitfield for output |
| 004b2a80 | BitfieldToFloatConversion | Convert bitfield to float |
| 004b33b0 | ProgressBarEventEncode | Encode a progress/status bar event (audio position) |
| 004ff3a0 | F_3DHermiteSplineInterpolation | Hermite spline interpolation of 3D position |
| 005001d0 | FieldCompareConstant | Check field against sentinel (large negative) |
| 00567010 | sub_567010 | Convert quaternion back to Euler angles |
| 00567030 | QuaternionFromEulerAngles | Convert Euler angles to quaternion |
| 00567580 | sub_567580 | Quaternion slerp/interpolation between two quaternions |
| 00587bdc | CRTFtol | Float-to-integer truncation for quantized output |

**Guard conditions:** Time `a2` clamped to range `[a3+4, a4+4]`. If range `v43 > 5.0` AND `FieldCompareConstant(this)` returns true, blend factors set to `(0.0, 1.0)` (use source A fully). If `v43 > 5.0` AND `FieldCompareConstant` false, use `(1.0, 0.0)` (source B fully). If squared distance delta >= 14981.386, use source B. Normal blend otherwise. When `v36 <= 0`, block bitfield blending (copy source A directly).
