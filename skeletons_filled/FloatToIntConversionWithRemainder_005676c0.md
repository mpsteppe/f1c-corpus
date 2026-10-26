## FloatToIntConversionWithRemainder_005676c0 — convert seconds to minutes with remainder

**Summary:** Converts float seconds to integer minutes and float seconds remainder. Multiplies input by 1/60 (0.016666668), truncates via CRTFtol, stores integer minutes at a1, remainder (input - minutes*60) at a2. Timing/time display subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D24D0 (004d24d0), FloatToIntTruncateWithRemainder (00567700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | integer minutes output |

**Written-by note (persistence):**
- this 0x0: unconditionally overwritten each call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9c0 | flt_59E9C0 | R | 0.016666668 constant (1/60 conversion factor) |
| 0059f118 | flt_59F118 | R | 60.0 constant (seconds-per-minute multiplier) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | C runtime float-to-int truncation (ftol equivalent) |

**Guard conditions:** None — unconditional conversion.
