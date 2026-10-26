## StringCapitalizer_00432650 — TitleCaseConverter

**Summary:** Converts a string to title case in-place: capitalizes the first letter of each word (letters following non-letter characters) and lowercases all other letters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsCopySetupFileCopy (00432220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First character of string; capitalized if lowercase |
| this | 0x1 | RW | — | Subsequent characters; capitalized after non-letters, lowercased after letters |

**Written-by note (persistence):**
- this 0x0: written once if lowercase letter. External poke survives until next call.
- this 0x1: written during loop for each character that needs case change. External poke survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | >= | 97 | ASCII 'a' — first char is lowercase letter |
| this | 0x1 | < | 97 | Previous char is NOT lowercase letter (non-letter or uppercase) |
| this | 0x1 | < | 65 | Previous char is NOT any letter (below 'A') |

**Guard interpretation:** First character: if >= 97 and <= 122 (lowercase), subtract 32 to capitalize. Loop: for each subsequent char, if previous char is a non-letter (outside a-z or A-Z) and current is lowercase, then capitalize (make uppercase). If previous char is a letter and current is uppercase, then decapitalize (make lowercase). Other chars pass through unchanged.
