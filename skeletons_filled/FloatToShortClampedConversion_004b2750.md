## FloatToShortClampedConversion_004b2750 — Float to short conversion with clamping

**Summary:** Converts two floats from a2 array (a2[0] and a2[2]) to signed short fixed-point: multiply by 512 after clamping input to ±64. Stores at this+0x28 and this+0x2A. Clamps to ±32767 on overflow.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | — | Encoded short from a2[0] (signed, clamped ±32767) |
| this | 0x2A | RW | 32767 | Encoded short from a2[2] (signed, clamped ±32767) |

**Written-by note (persistence):**
- this 0x28: written unconditionally from a2[0]; overwrites previous
- this 0x2A: written unconditionally from a2[2]; init 32767 overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accb4 | flt_5ACCB4 | R | RGB10A2QuantScale [DERIVED] (also: — Scale factor for RGB10A2 encoding) |
| 005accb8 | flt_5ACCB8 | R | ShortConversionClampLow [DERIVED] |
| 005accbc | flt_5ACCBC | R | FloatQuantizeUpperBound [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each float independently guarded by two-sided range check. If within [-63.998, 63.998] -> multiply by 512, truncate to short. If below -63.998 -> clamp to -32767. If above 63.998 -> clamp to 32767 (0x7FFF). a2[1] is not processed.
