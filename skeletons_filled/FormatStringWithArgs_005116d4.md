## FormatStringWithArgs_005116d4 — Select format string and call vsnprintf equivalent

**Summary:** Selects a format string from a table (primary or alternate range) by index; resolves default string on out-of-range; detects "%s" format to switch between varargs and va_list calling convention; delegates to string formatting function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x70) | 0x0 | R | — | first format string in primary table (fallback default) |
| obj | 0x14 | R | — | current format string index |
| obj | 0x18 | RW | — | format argument 0 (written when fallback to default string) |
| obj | 0x1C | R | — | format argument 1 |
| obj | 0x20 | R | — | format argument 2 |
| obj | 0x24 | R | — | format argument 3 |
| obj | 0x28 | R | — | format argument 4 |
| obj | 0x2C | R | — | format argument 5 |
| obj | 0x30 | R | — | format argument 6 |
| obj | 0x34 | R | — | format argument 7 |
| obj | 0x70 | R | — | pointer to primary format string table (array of char*) |
| obj | 0x74 | R | — | primary table element count |
| obj | 0x78 | R | — | pointer to alternate format string table (or null) |
| obj | 0x7C | R | — | alternate table start index |
| obj | 0x80 | R | — | alternate table end index |
| this | 0x0 | R | — | pointer to format state structure |

**Written-by note (persistence):**
- obj 0x18: written once on fallback path when index is out of range; survives as the overridden format argument 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Performs safe string formatting with buffer bounds check |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x70) | 0x0 | != | 115 | first char of resolved format string is not 's' (i.e. format is not "%s") |

**Guard interpretation:** After scanning to first '%' in resolved format string, checks if the format specifier is "%s". If the character AFTER '%' is NOT 's' (value 115), falls through to the variadic call path passing all 8 format arguments individually. If it IS "%s", takes the compact path passing a pointer to the argument array (va_list-style). The guard BLOCKS the va_list path when format is not a simple "%s".
