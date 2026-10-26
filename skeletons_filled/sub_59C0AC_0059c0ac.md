## sub_59C0AC_0059c0ac — CharToUpper

**Summary:** Converts a character to uppercase: uses ctype lookup tables (byte_8D47E1/byte_8D46E0) for ANSI and locale-aware LCMapString (sub_591FA1) for multibyte characters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59BA1D (0059ba1d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d46bc | dword_8D46BC | R | CRT_Locale [DERIVED] — locale handle for character conversion |
| 008d46e0 | byte_8D46E0 | R | CharUpperTable [DERIVED] — uppercase mapping for 8-bit chars |
| 008d47e1 | byte_8D47E1 | R | CharClassTable_byte [DERIVED] — ctype flags (bit 5 = lowercase, bit 2 = lead byte) |
| 008d48e4 | dword_8D48E4 | R | LocaleCRT [DERIVED] — locale handle for LCMapString |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00591fa1 | sub_591FA1 | Locale-aware character uppercasing (LCMapString wrapper) |

**Guard conditions:** For input <= 0xFF: returns uppercase table lookup if character is lowercase (bit 5 set in ctype), otherwise returns input unchanged. For > 0xFF: returns uppercased result from locale function only if it is a lead byte (bit 2 set); otherwise returns input unchanged.
