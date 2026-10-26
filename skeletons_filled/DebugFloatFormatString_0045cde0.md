## DebugFloatFormatString_0045cde0 — Format debug float value to string

**Summary:** Formats hardcoded float value 1.026 as "%1.3f" into a local buffer via StringFormatWithBufferOverflowCheck, then processes the output buffer through ShortComputation_ce30 (backslash-to-underscore replacement) before and after formatting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f090 | flt_59F090 | R | FloatParam_59F090 [DERIVED] |
| 005c5b68 | off_5C5B68 | R | Configuration/reference pointer |
| 005c5bc4 | aGamever | R | GameverString [DERIVED] |
| 005c5bcc | a13f | R | FormatString_1_3f [DERIVED] |
| 005c5bd4 | aGamename_0 | R | GameNameString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ce30 | ShortComputation_ce30 | String processing (backslash-to-underscore replacement) on output buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe snprintf-style formatting with overflow check |

**Guard conditions:** none — unconditional formatting and string processing
