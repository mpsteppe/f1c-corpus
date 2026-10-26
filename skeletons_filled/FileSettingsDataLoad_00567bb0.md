## FileSettingsDataLoad_00567bb0 — ConfigFileSectionParser

**Summary:** Parses a settings/config data structure line by line. Handles nested sections delimited by {} braces, splits keys at '.' delimiter, and dispatches key-value pairs to FileDataProcessor for storage.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | base directory path for file loading (fallback to byte_5EA438) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30ac | asc_5C30AC | R | StrDelimiter_Period [DERIVED] (also: ` — first lookup key string or identifier) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cc0 | ConditionalDispatchBasedOnFlag | reads next line of input into buffer |
| 00567b10 | sub_567B10 | sanitizes/trims input line |
| 00567bb0 | FileSettingsDataLoad | recursive call for nested {} section |
| 00567fb0 | FileDataProcessor | processes parsed key-value pair |
| 00587c20 | sub_587C20 | finds '.' delimiter in key string |

**Guard conditions:** if trimmed line starts with '{' (0x7B), enters nested section via recursion; if starts with '}' (0x7D), returns immediately (exits current section). Only non-empty trimmed lines after trimming/truncation proceed to parsing.
