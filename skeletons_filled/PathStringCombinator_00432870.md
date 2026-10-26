## PathStringCombinator_00432870 — PathStringArrayComposer

**Summary:** Processes an array of three path strings: copies the first via StringCopyWithBufferRealloc, processes the third via a path utility function, and returns the fifth entry (or default application directory if null). Defaults any null string to the application directory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PathBuilderWithBackslash (0046e600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First path string (copied via StringCopyWithBufferRealloc) |
| obj | 0x8 | R | — | Third path string (processed via sub_5665B0) |
| obj | 0x10 | R | — | Fifth path string (returned as result) |
| this | 0x0 | R | — | Pointer to string array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005665b0 | sub_5665B0 | Path processing utility (normalize/transform) |
| 00566650 | StringCopyWithBufferRealloc | Copies string with automatic buffer reallocation |

**Guard conditions:** Each of the three string pointers (offsets 0x0, 0x8, 0x10 within the array) is checked for null. If null, defaults to byte_5EA438 (default application directory). Always returns a valid string pointer (either the fifth string or default).
