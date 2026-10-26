## ResourcePathBuilder_00493e20 — Build resource file path with directory prefix

**Summary:** Constructs a resource file path by prepending directory traversal prefix ("..\\" or ".HOT\\") based on parser nesting depth, then appends the filename. Outputs to write stream if write mode is enabled.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160), sub_492460 (00492460), sub_492710 (00492710), sub_492A40 (00492a40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Write stream handle (this[1]) |
| this | 0x194 | R | — | Parser nesting depth (this[101]), controls prefix count |
| this | 0x19A | R | — | Write mode flag byte (offset 410) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c406c | word_5C406C | R | InitStringConstant [DERIVED] (also: global string constant used for initialization) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005887b1 | StringFormatWithNestedIO | Writes formatted string to output stream |

**Guard conditions:** Returns -1 if a2 (filename) is null or empty. Prefix count is 4 * this[101]; if <= 0, no prefix is prepended. If byte at this+410 is non-zero and write stream exists, the built path string is written to the stream.
