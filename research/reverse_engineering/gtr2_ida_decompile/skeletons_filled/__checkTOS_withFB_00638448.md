## __checkTOS_withFB_00638448 — Check x87 TOS value with fallback (exponent-field extractor)

**Summary:** Floating-point runtime helper called by the inverse-trig routines: extracts the exponent field from the high 32-bit word of a double value and returns the full word when all exponent bits are set (NaN/Inf special case).

**Called by:** __CIasin (00631ad0), __CIacos (00632ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Computes `result = a2 & 0x7FF00000` (exponent field of the double's high word). If the masked value equals 0x7FF00000 (all exponent bits set → Inf/NaN marker) → returns the raw a2 unchanged. Otherwise → returns the masked exponent bits, discarding the sign bit and mantissa bits.
