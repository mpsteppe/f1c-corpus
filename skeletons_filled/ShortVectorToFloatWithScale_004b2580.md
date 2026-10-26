## ShortVectorToFloatWithScale_004b2580 — Int16 vector to float unpack (scale 0.02)

**Summary:** Converts 3 int16 values to float by multiplying by 0.02 (1/50). Unpacks compact vertex/vector data back to floating point. Inverse of UtilityFunction_2480.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VectorToShort3Conversion (004b2c80), VehiclePhysicsTimeStep (004c73f0), VehicleContactForceAccumulation (004ebc60), AudioParameterInterpolation (004ff680), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1E | R | — | Int16 value 0 (converted to float * 0.02) |
| this | 0x20 | R | — | Int16 value 1 (converted to float * 0.02) |
| this | 0x22 | R | — | Int16 value 2 (converted to float * 0.02) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6ec | flt_59E6EC | R | ShortIntToWorldScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all fields read directly.
