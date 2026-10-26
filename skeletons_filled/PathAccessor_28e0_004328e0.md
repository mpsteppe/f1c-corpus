## PathAccessor_28e0_004328e0 — FirstStringInArrayGetter

**Summary:** Returns the first string from the array pointed to by `this`. If the string pointer is null, returns the default application directory instead.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PathDirectoryExtractionAndComparison (00433290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First string in the array |
| this | 0x0 | R | — | Pointer to the string array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If the dereferenced string pointer (this[0][0]) is null, returns byte_5EA438 (default application directory).
