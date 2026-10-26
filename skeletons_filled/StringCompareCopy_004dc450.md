## StringCompareCopy_004dc450 — Compare and conditionally copy file path with extension handling

**Summary:** Compares a source file path against a global path buffer (byte_5EA438) by extracting filename portions, checks extension match via sub_546AA0; optionally copies the filename with extension stripping if a4 flag is set, then registers and matches the result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureAdjuster (004dc770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Global path buffer for file path comparison/registration |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c800 | StringRegistry | Register/compare string in global string table |
| 0053c900 | StringMatchWithFlagSet | Match string against flag-based criteria |
| 00546aa0 | sub_546AA0 | Check filename/extension match against criteria parameter a2 |
| 005472b0 | RelativeStringCopy | Copy relative path string |
| 00566650 | StringCopyWithBufferRealloc | Copy string with automatic buffer reallocation |
| 00587bcf | FreeWrapper_7bcf | Free memory wrapper |
| 00589901 | sub_589901 | Process/modify path string (extension strip context) |

**Guard conditions:** Checks `a1` (pointer) and `a3` (source string) for non-null. PASSES (processes strings) when both are non-null. BLOCKED (returns 1) if either is null. Inside the main path, `sub_546AA0(a2, v7)` check: if match fails (returns 0) and `a4` is non-zero, additional copy/extension-strip path runs.
