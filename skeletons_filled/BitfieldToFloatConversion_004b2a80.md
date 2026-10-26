## BitfieldToFloatConversion_004b2a80 — Bitfield 7-bit biased extract and scale

**Summary:** Extracts low 7 bits from bitfield at offset 0x2C, subtracts bias 64, and multiplies by 0.015873 (1/63). Inverse of FloatToBitfieldEncoder. Converts biased 7-bit signed value back to float.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Bitfield dword (bits 0-6 = 7-bit biased signed value) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — reads directly.
