## ClampedFloatSetter_00456fb0 — FloatClampedSetter_0xAC

**Summary:** Writes a float value to offset 0xAC, clamped between bounds at offsets 0x80 (min) and 0x84 (max).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraPositionDefinitions (00408870), CollisionCoefficientApplication (00456f70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | R | — | minimum clamp bound |
| this | 0x84 | R | — | maximum clamp bound |
| this | 0xAC | RW | — | target field written with clamped value |

**Written-by note (persistence):**
- this 0xAC: always written (clamped). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if input < min → set to min. if input > max → set to max. Values within [min, max] pass through unchanged.
