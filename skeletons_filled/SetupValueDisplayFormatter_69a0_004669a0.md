## SetupValueDisplayFormatter_69a0_004669a0 — FormatNormalizedValueAsPercent

**Summary:** Retrieves a value via virtual call (vtable+180), normalizes by dividing by (this[62]-this[61]), converts to percentage, and formats as "%d%%" string. Checks flag at this+0xF0 to choose signed vs unsigned division.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | vtable pointer for virtual method dispatch (+180) |
| this | 0xF0 | R | — | flag: if set, treat value as signed; else unsigned |
| this | 0xF4 | R | — | field 61 — lower bound of range (denominator component) |
| this | 0xF8 | R | — | field 62 — upper bound of range (denominator component) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | store formatted string to persistent buffer |
| 00587bdc | CRTFtol | convert float to integer (truncate) |
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf with "%d%%" format |

**Guard conditions:** None — unconditional.
