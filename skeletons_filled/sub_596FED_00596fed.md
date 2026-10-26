## sub_596FED_00596fed — CodePageResolver

**Summary:** Resolves special code page identifiers (0xFFFFFFFE=OEM, 0xFFFFFFFD=ANSI, 0xFFFFFFFC=default) to actual system code pages via GetOEMCP/GetACP. Sets global auto-flag for caller.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_596E40 (00596e40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e088 | GetOEMCP | R | Return OEM code page for identifier 0xFFFFFFFE |
| 0059e08c | GetACP | R | Return ANSI code page for identifier 0xFFFFFFFD |
| 008d3f48 | CodePage | R | DefaultCodePage [DERIVED] — default code page for identifier 0xFFFFFFFC |
| 008d41d4 | dword_8D41D4 | W | CodePageAutoFlag [DERIVED] — set to 1 when special identifier is resolved |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No error guards. Non-matching code page identifiers pass through unchanged with auto-flag left at 0.
