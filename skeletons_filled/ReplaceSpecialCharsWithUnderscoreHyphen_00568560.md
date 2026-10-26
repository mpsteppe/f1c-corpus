## ReplaceSpecialCharsWithUnderscoreHyphen_00568560 — FilenameCharSanitizer

**Summary:** Replaces path separator characters ('.', '/', '\\') with underscore '_', and characters matching StringPrefixPatternCheck with hyphen '-'. Used to sanitize strings for use as file/directory names.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50), PathBuilderWithBackslash (0046e600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 45 | first byte of input string; checked/replaced during iteration |

**Written-by note (persistence):**
- this 0x0: modified in-place if character meets replacement criteria; survives as caller's buffer is modified directly

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005685b0 | StringPrefixPatternCheck | checks if character at current position matches replacement pattern for hyphen |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | >= | 46 | first byte of string during character iteration |

**Guard interpretation:** chars >= 46 (ASCII '.' and above) pass to the inner condition check for path separator chars ('.'=46, '/'=47, '\\'=92) → replaced with '_'. Chars < 46 are never replaced. Second loop: chars where StringPrefixPatternCheck returns true replaced with '-'.
