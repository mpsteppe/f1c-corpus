## StringPathExtensionManipulation_0040dc00 — StringPathExtensionManipulation

**Summary:** Builds a path string from CurrentTrackPath (or default directory), concatenates with a dot-extension string, finds and truncates at the last '.' to strip existing extension, then appends path separator word and extension bytes. Passes result to FunctionCallWrapper_dbe0 and frees the temp buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005beb4c | off_5BEB4C | R | DotExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040dbe0 | FunctionCallWrapper_dbe0 | invoke function with constructed path string |
| 00587bcf | FreeWrapper_7bcf | free temp allocated path buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for concatenated path |
| 00587dd0 | sub_587DD0 | string concatenation (strcat-like) |

**Guard conditions:** dword_7CE5D0 null → fall back to byte_5EA438 default path; path buffer allocation fails → return 0 early
