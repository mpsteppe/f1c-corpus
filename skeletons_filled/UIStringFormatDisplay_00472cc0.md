## UIStringFormatDisplay_00472cc0 — UIListValueToStringDisplay

**Summary:** Reads an index pointer from this+0x31C, dereferences it to get a list index, retrieves the corresponding value from a UI list via indexed accessor, formats it as a string into a local buffer with overflow check, and updates the edit/display buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x31C | R | — | pointer to index value for UI list access |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | retrieve value from UI list at given index |
| 0048b810 | EditBufferStringUpdate | update edit/display buffer with formatted string |
| 0058815f | StringFormatWithBufferOverflowCheck | format integer to string with overflow protection |

**Guard conditions:** none — straight-line, no branches.
