## ValueBarDisplayFormatter_00479600 — ValueBarDisplayFormatter

**Summary:** Formats current value as percentage string for display bar: reads value via vtable+180 callback, computes percentage = (value - min) * 100 / (max - min) using fields at 0xF4 (min) and 0xF8 (max), writes "%d%%" formatted string to output buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | value read from object returned by vtable+180 callback |
| this | 0x0 | R | — | vtable pointer (method at +180 called) |
| this | 0xF4 | R | — | minimum range value for percentage calculation |
| this | 0xF8 | R | — | maximum range value for percentage calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |
| 005c37cc | aD | R | FormatSpecifierD [DERIVED] — "%d" format specifier |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | copies formatted percentage string to output buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string formatting with "%d%%" pattern |

**Guard conditions:** vtable+180 callback must return non-null pointer (skip formatting if null).
