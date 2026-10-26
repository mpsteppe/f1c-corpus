## ExtendedPrecisionDivisionWithOverflowFixup_005908b0 — ExtendedPrecisionDivWithOverflowCorrection

**Summary:** Performs extended-precision (80-bit _TBYTE) division with overflow fixup using table-guided scaling to avoid precision loss.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DoubleArithmeticWrapper (005910a1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e74e0 | byte_5E74E0 | R | MathLookupTable [DERIVED] |
| 005e74f0 | flt_5E74F0 | R | Float5E74F0 [DERIVED] |
| 005e74f4 | flt_5E74F4 | R | Unknown_Float_FPU2 [DERIVED] |
| 005e74f8 | flt_5E74F8 | R | MathLibConst_5E74F8 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** While carry flag not set on high dword add: if a1 is zero or exponent non-zero, returns a2/a1 directly (PASS: normal division). If a1 exponent is 0x7FFF (infinity/NaN), returns a2/a1. If a2 exponent is 0 (denormal) and no carry on add, skips to check table lookup; if exponent is 1, scales by flt_5E74F4. If carry on add, checks exponent range via lookup table; if table entry is 0 or exponent is zero/0x7FFF, returns a2/a1 (BLOCKED: out-of-range or invalid).
