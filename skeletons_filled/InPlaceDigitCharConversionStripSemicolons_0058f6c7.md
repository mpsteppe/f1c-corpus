## InPlaceDigitCharConversionStripSemicolons_0058f6c7 — DigitCharToNibbleAndStripSemicolons

**Summary:** Converts a locale digit string in-place: ASCII '0'-'9' chars are converted to their nibble values (subtract 48), semicolons (';' = 59) are removed by left-shifting remaining characters, other characters are left unchanged. Used to parse locale digit grouping/format strings like "3;2;1" into binary array [3, 2, 1].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioCodecBufferAllocation (0058f4f2), sub_58F7C9 (0058f7c9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First character of input string — converted from ASCII to nibble or shifted left |
| this | 0x1 | R | — | Second character of input string — read during shift-over-semicolon removal |

**Written-by note (persistence):**
- this 0x0: overwritten once per iteration — either converted to nibble (if digit) or overwritten by semicolon-removal shift
- External poke survives partially: the string is modified in-place but always null-terminated

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `result < 48 || result > 57` (not a digit) AND `result != 59` (not semicolon) → skip, advance pointer
- `result >= 48 && result <= 57` (digit '0'-'9') → convert to nibble (result - 48), store, advance
- `result == 59` (semicolon) → left-shift remaining chars to delete it, continue without advancing (next iteration checks shifted char)
- Loop ends when `*v1` (current char) is null terminator
