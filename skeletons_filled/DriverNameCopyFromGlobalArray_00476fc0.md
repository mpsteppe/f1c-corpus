## DriverNameCopyFromGlobalArray_00476fc0 — DriverHotFilePathBuilder

**Summary:** Builds a file path by copying a driver name from a global array (indexed by `a2`), then conditionally appending a `.HOT` extension and an additional path segment from offset 0x188.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x188 | R | — | additional path segment appended after .HOT extension |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d0d5c | dword_7D0D5C | R | TeamNamePtrArray [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | copies string into buffer with length limit (strncpy-like) |

**Guard conditions:** calculated total length (base driver name + extra path + 1) >= `a4` (buffer size) → skip append, return required length; fits → write `.HOT` extension and append extra path, return 0
