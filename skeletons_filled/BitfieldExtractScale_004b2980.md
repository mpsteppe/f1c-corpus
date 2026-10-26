## BitfieldExtractScale_004b2980 — Bitfield extract and scale (inverse of pack)

**Summary:** Extracts bits 17-31 from bitfield dword at offset 0x2C, shifts right 17, and multiplies by 0.1 (1/10). Inverse of FloatToBitfieldPack. Returns double.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VectorToShort3Conversion (004b2c80), VehiclePhysicsTimeStep (004c73f0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Bitfield dword (bits 17-31 = packed 15-bit unsigned value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — reads directly.
