## ShortComputation_29f0_004b29f0 — Bitfield 5-bit extract and scale (inverse of insert)

**Summary:** Extracts bits 12-16 from bitfield dword at offset 0x2C, shifts right 12, masks to 5 bits, and scales by 0.032258064 (1/31). Inverse of BitfieldInsert. Returns double.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VectorToShort3Conversion (004b2c80), VehiclePhysicsTimeStep (004c73f0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Bitfield dword (bits 12-16 = 5-bit packed value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: ` — Float scale factor for 5/6-bit channel decoding) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — reads directly.
