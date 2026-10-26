## UITextFormatHelper_00489970 — Path suffix extractor

**Summary:** Reads text via UIScreenTextAccessor, extracts path suffix after skipping a2 path-delimiter-separated components, stores result at this[0xE1] buffer, returns pointer to it. Like dirname/basename extraction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIListManagementHandler (0048a3c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE1 | RW | 0 | output buffer for extracted path suffix (77 bytes max) |

**Written-by note (persistence):**
- this 0xE1: written once per call with result of path extraction; conditional on UIScreenTextAccessor succeeding

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c692c | word_5C692C | R | PathDelimiterChar [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489920 | UIScreenTextAccessor | gets text string from screen/UI widget |
| 005897ca | sub_5897CA | finds path delimiter character in string (strrchr-style) |

**Guard conditions:** If UIScreenTextAccessor returns null, returns 0 immediately. After skipping path delimiters, if no delimiter found returns 0. a2 (number of path components to skip) must be >= 0.
