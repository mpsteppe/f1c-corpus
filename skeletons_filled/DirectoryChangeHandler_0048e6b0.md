## DirectoryChangeHandler_0048e6b0 — DirectoryPathChangeComparer

**Summary:** Compares current directory path at offset 0xB8 against stored path at offset 0xE0. If they differ, updates the path buffer and fires a virtual change notification callback at vtable+172. Always invokes refresh virtual method at vtable+44 with argument 1. Appends to a linked list on entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | virtual method offset for refresh/update |
| obj | 0xAC | R | — | virtual method offset for directory change callback |
| this | 0x0 | R | — | vtable pointer |
| this | 0xB8 | R | — | current/new directory path string pointer |
| this | 0xE0 | R | — | stored/previous directory path string pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00496750 | DoublyLinkedListAppend_6750 | append this struct to a linked list |
| 00566650 | StringCopyWithBufferRealloc | copy new directory path string |

**Guard conditions:**
- If this[56] (offset 0xE0) is null → substitute default path byte_5EA438
- If this[46] (offset 0xB8) is null → substitute default path byte_5EA438
- PASS: strcmp(v3, v2) != 0 (paths differ) → update path, fire change callback
- BLOCKED: strcmp(v3, v2) == 0 (paths same) → skip path update and callback
- Always falls through to virtual method at vtable+44 with arg 1
