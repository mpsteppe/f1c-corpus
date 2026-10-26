## PathBuilderWithBackslash_0046e600 — Path builder with backslash

**Summary:** Builds file path string: combines base directory path from module callback table (or default directory), ensures trailing backslash, sanitizes object name (special chars → underscore/hyphen), appends ".svm" extension and additional parameter. Allocates temp buffer and frees it on completion. Part of file path construction utility system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitWithStackBuffer (0046e5c0), ClearBufferAndInit (0046f490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | backslash character ('\\') for path separator |
| 005c403c | aSvm | R | ".svm" file extension string |
| 005ea438 | byte_5EA438 | R | default application directory path (fallback) |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable — provides combined path string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00432870 | PathStringCombinator | combines/constructs path string from module callback table |
| 005665b0 | sub_5665B0 | appends string to buffer (used for backslash, name, extension) |
| 00566650 | StringCopyWithBufferRealloc | copies string with buffer reallocation |
| 00568560 | ReplaceSpecialCharsWithUnderscoreHyphen | replaces special characters with underscore/hyphen in string |
| 00568620 | sub_568620 | appends additional parameter string to path |
| 00587bcf | FreeWrapper_7bcf | frees heap-allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 128-byte temp buffer |
| 00587dd0 | sub_587DD0 | copies object name string into buffer (max 127 chars) |

**Guard conditions:** No entry guard. If v8 (allocated buffer) is null, falls back to byte_5EA438 (default directory) for path base. If last character of path is already backslash (0x5C), skips appending backslash. If v8 was allocated, frees it via FreeWrapper_7bcf at end.
