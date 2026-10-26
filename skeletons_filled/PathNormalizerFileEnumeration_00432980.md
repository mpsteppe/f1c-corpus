## PathNormalizerFileEnumeration_00432980 — PathNormalizerAndFileEnumerator

**Summary:** Normalizes a path string (ensuring it ends with a backslash) and then enumerates files in that directory. Reads the path from offset 0x8 of an array, defaults to application directory if null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerNameSetup (004326e0), PollingLoopWithBranch (0046e7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Path string from array (used as directory for enumeration) |
| this | 0x0 | R | — | First string in array (passed to DirectoryFileEnumerator) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00431db0 | DirectoryFileEnumerator | Enumerates files in a given directory |
| 005665b0 | sub_5665B0 | Path normalization/string processing utility |
| 00568620 | sub_568620 | Buffer initialization utility |

**Guard conditions:** Path string at array offset 0x8 checked for null; if null, defaults to byte_5EA438. If path length > 0 and last character is not backslash (0x5C), appends backslash via sub_5665B0. Always returns 1.
