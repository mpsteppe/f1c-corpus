## TimeFormatStringForDebugDisplay_004319da — TimeValueDebugFormatter

**Summary:** Formats a time value into a display string with unit suffix for debug HUD. Scales raw time by display multiplier, selects 2 or 3 decimal precision based on flag and value magnitude.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea18 | dbl_59EA18 | R | TimeDisplayMultMs [DERIVED] |
| 0059ea20 | dbl_59EA20 | R | QREpsilonThreshold [DERIVED] |
| 005c3780 | a3fS | R | FormatStr3fS [DERIVED] |
| 005c3820 | a2fS | R | sFormat_2fS [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with overflow protection |

**Guard conditions:** Computes value from register args; if high bit (0x80) of result is set, loads alternate time value from a lookup table and scales by dbl_59EA20. Within that branch, if field at _ECX+4 equals 1, formats with "%.2f %s" (2 decimal places). Otherwise (high bit clear or field != 1), scales by dbl_59EA18 and formats with "%.3f %s" (3 decimal places).
