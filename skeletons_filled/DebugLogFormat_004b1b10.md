## DebugLogFormat_004b1b10 — Debug log entry formatter

**Summary:** Writes a formatted debug log entry to output buffer. Copies a labeled string from this+0x14 into temp buffer, writes key-value separator, appends optional comment string (from this+0x0C or default path), then writes a config-substring token suffix.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | String pointer for optional comment field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005cd13c | aSS_6 | R | FmtKeyValue [DERIVED] |
| 005d23a8 | aS_8 | R | FormatString_Comment [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1a60 | FormattedStringCopy | Copy formatted string from source into temp buffer |
| 00566c30 | BufferWriteWithStringLengthCheck | Write string to output buffer with length validation |

**Guard conditions:** this+0x0C == NULL -> uses byte_5EA438 as default comment string. strlen(comment)==0 -> skips writing comment format. If both conditions pass (non-NULL, non-empty), writes comment string with format aS_8.
