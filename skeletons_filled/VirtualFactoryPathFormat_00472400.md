## VirtualFactoryPathFormat_00472400 — VirtualFactoryPathFormat

**Summary:** Formats and displays a factory/virtual path string. Queries game command dispatch for an object by ID 19, compares names, then formats dword_7D09D8 as an integer into the edit buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_2340 (00472340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007d09d8 | dword_7D09D8 | R | Integer value formatted into the factory path string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477280 | ObjectNameComparison | Compare object name against this component's name |
| 0048b810 | EditBufferStringUpdate | Format buffer and update UI string display |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting with overflow check |

**Guard conditions:** Guard on query result: if game command dispatch returns non-null for ID 19, calls ObjectNameComparison; if null, skips name comparison. Always formats and updates display regardless.
