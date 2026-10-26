## NamePathFormatterWithLengthCheck_004b02b0 — NamePathFormatterWithLengthCheck

**Summary:** Formats a file path with ".bch" extension. Validates buffer size, prepends directory path from object field (or default), strips existing extension (before '.'), then appends ".bch". Returns 0 on success, -1 if buffer too small or inputs invalid.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_5StepInit (004b0720), SettingsFileInit (004b0930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F9C | R | — | directory path string (or null to use default) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d1fe8 | dword_5D1FE8 | R | FilePath_MaxLen [DERIVED] |
| 005d1fec | byte_5D1FEC | R | PathConcatBuffer [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0220 | PathTruncationUtility | truncates input path to fit within buffer limit |

**Guard conditions:** Multiple:
1. If a2 (output buffer) is NULL or a3 (buffer size) is 0 → goto fail (set output[0]=0, return -1).
2. If buffer size <= strlen(a2) + strlen(dirpath) → goto fail (too small to append directory).
3. After appending directory, if buffer size <= strlen(a2) + 5 → goto fail (too small to append ".bch").
Passes only when buffer is large enough for directory + ".bch" suffix.
