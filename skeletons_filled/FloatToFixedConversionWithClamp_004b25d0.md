## FloatToFixedConversionWithClamp_004b25d0 — Float to fixed-point conversion with clamping

**Summary:** Converts three floats from a2 array into fixed-point representation: a2[0] clamped ±6.35 ×20 → byte at +0x24; a2[1] clamped ±65.534 ×500 → short at +0x26; a2[2] clamped ±6.35 ×20 → byte at +0x25. All clamped to signed min/max sentinel values on overflow.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | Encoded byte from a2[0] (signed, clamped ±127) |
| this | 0x25 | RW | 127 | Encoded byte from a2[2] (signed, clamped ±127) |
| this | 0x26 | RW | — | Encoded short from a2[1] (signed, clamped ±32767) |

**Written-by note (persistence):**
- this 0x24: written unconditionally; overwrites any previous value
- this 0x25: written unconditionally; init 127 is overwritten by this function
- this 0x26: written unconditionally; overwrites any previous value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 005acca0 | flt_5ACCA0 | R | ClampLowerBound [DERIVED] (also: clamp bounds) |
| 005acca4 | flt_5ACCA4 | R | ClampUpper_ColorB [DERIVED] |
| 005acca8 | flt_5ACCA8 | R | NormalClampLower [DERIVED] |
| 005accac | flt_5ACCAC | R | NormalClampUpper [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each float is independently guarded by two-sided range check. If within [-6.35, 6.35] -> multiply by 20, truncate to byte. If below -6.35 -> clamp to -127. If above 6.35 -> clamp to 127. Same pattern for a2[1] with range [-65.534, 65.534] ×500 to short, and a2[2] with same range as a2[0].
