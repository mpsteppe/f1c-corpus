## sub_49BBB0_0049bbb0 — elapsed-time string formatter with fallback

**Summary:** Computes elapsed session time from postProcessInput, formats it as " MM:SS.FFF" into the output buffer, or writes a default string if conditions (grid cell, negative time, flag) are not met.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualTextDisplay (0049e410), MultiLayerTextStringRenderer (004dbc90), DoubleRenderPass (004dc1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ccc0c | flt_5CCC0C | R | Unknown_Float_5CCC0C [DERIVED] |
| 005cce18 | asc_5CCE18 | R | Unknown_String5CCE18 [DERIVED] |
| 005cce24 | a2d063f_1 | R | Unknown_String5CCE24 [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b630 | SpatialGridCell | convert time value into minutes/seconds components for formatting |
| 004bc2a0 | ArithmeticComparison_c2a0 | perform arithmetic comparison on a decremented value |
| 0058815f | StringFormatWithBufferOverflowCheck | safe sprintf-style formatting with buffer bounds check |

**Guard conditions:** Three-tier guard:
1. `elapsed < flt_5CCC0C` AND `*(dword_7C54E0+16444) > 0` — enters A/C path; if `ArithmeticComparison_c2a0(v4-1) > 0.0`, formats elapsed time and returns early. If <= 0, falls through to final guard.
2. Falls through: `*(v2+16532) != 2` OR `elapsed < 0.0` OR `*(v2+16484)` — if ANY true, writes default string `asc_5CCE18` and returns.
3. If ALL false (state==2, elapsed>=0, flag clear): formats elapsed time as " MM:SS.FFF".
