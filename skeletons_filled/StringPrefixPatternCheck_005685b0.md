## StringPrefixPatternCheck_005685b0 — CheckPlusTildePrefixPattern

**Summary:** Checks if string matches prefix pattern: starts with '+' (0x2B = 43), '~' (0x7E = 126), followed by two characters passing sub_589BC6 validation. Requires minimum 4 characters.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ReplaceSpecialCharsWithUnderscoreHyphen (00568560), sub_568620 (00568620)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first character of prefix (must be '+' = 43) |
| this | 0x1 | R | — | second character of prefix (must be '~' = 126) |
| this | 0x2 | R | — | third character, validated by sub_589BC6 |
| this | 0x3 | R | — | fourth character, validated by sub_589BC6 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00589bc6 | sub_589BC6 | validates individual character (likely alphanumeric or character class check) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 43 | first character must be '+' (0x2B) |
| this | 0x1 | == | 126 | second character must be '~' (0x7E) |

**Guard interpretation:** Length >= 4 is checked first. Then byte 0 == '+' AND byte 1 == '~' AND byte 2,3 pass sub_589BC6. All conditions must hold — if any fails (wrong prefix chars, invalid chars in positions 2-3, or strlen < 4), returns 0 (BLOCKED). Only when all pass does the function return 1 (PASS).
