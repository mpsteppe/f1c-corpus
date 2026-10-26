## FloatToInt16SaturationPack_004b31a0 — Float3ToInt16SaturationPack

**Summary:** Converts three float values to int16 with saturation at ±15.999512 and 2048.0 scale factor. Stores results at offsets 0xC, 0xE, 0x10 of the struct. Returns the third converted value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Packed int16 component 0 (float * 2048, sat) |
| this | 0xE | RW | — | Packed int16 component 1 (float * 2048, sat) |
| this | 0x10 | RW | 32767 | Packed int16 component 2 (float * 2048, sat) |

**Written-by note (persistence):**
- this 0xC: overwritten each call with clamped scaled value; external poke overwritten
- this 0xE: overwritten each call with clamped scaled value; external poke overwritten
- this 0x10: overwritten each call with clamped scaled value; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 005acc90 | flt_5ACC90 | R | ShortNormMin [DERIVED] |
| 005acc94 | flt_5ACC94 | R | VertexShortClampMax [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Per-component: value > 15.999512 → BLOCKED from linear scale, clamps to 0x7FFF. Value < -15.999512 → clamps to -32767. In-range values PASS: multiply by 2048.0, truncate to int16.
