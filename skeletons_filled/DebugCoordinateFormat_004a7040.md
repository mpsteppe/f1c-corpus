## DebugCoordinateFormat_004a7040 — DebugCoordinateFormat

**Summary:** Writes two constant debug strings ("%s %d %d" format and a config substring token) to a buffer via BufferWriteWithStringLengthCheck. Likely formats debug coordinate or position output for logging.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005cd6b0 | aSDD | R | String_SDD [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566c30 | BufferWriteWithStringLengthCheck | writes a string to the output buffer with length checking |

**Guard conditions:** No guards. Always writes both strings unconditionally.
