## PathDirectoryExtractionAndComparison_00433290 — PathDirectoryExtractionAndComparison

**Summary:** Extracts directory path from module callback table, copies it to output buffer. Strips file extension from input path string. If input becomes empty after stripping, concatenates with dot-extension string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PathStringModifier (00433370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to output string buffer (defaults to byte_5EA438 if null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c4068 | asc_5C4068 | R | DotExtension [DERIVED] — dot extension string for concatenation |
| 005ea438 | byte_5EA438 | R | default application directory path |
| 007c73e0 | dword_7C73E0 | R | ModuleCallbackTable [DERIVED] — module callback table for path access |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004328e0 | PathAccessor_28e0 | get module directory path from callback table |
| 00568910 | sub_568910 | unknown operation on max length parameter |
| 00587dd0 | sub_587DD0 | concatenate string with dot extension |
| 00588640 | sub_588640 | copy module path string into output buffer |

**Guard conditions:** If `*a1` (output buffer) is null at entry, defaults to `&byte_5EA438`. After finding last backslash, if `PathAccessor_28e0` returns null, skips path copy. Extension stripping: scans from end of `a2` backward for '.'; if none found before start, skips stripping. After stripping, if `*a2` is null (empty result), concatenates with `asc_5C4068`.
