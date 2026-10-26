## LinkedListEntrySearchByName_004155d0 — LinkedListEntrySearchByName

**Summary:** Searches a linked list (head at this[8], count at this[11]) by comparing node strings with a2 using sub_588410. Returns matching index or -1 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0x0 | R | — | String pointer dereferenced from list node data for comparison |
| *(this+0x24) | 0x4 | R | — | Next pointer in linked list node for traversal |
| this | 0x20 | R | — | Head pointer of the linked list (this[8]) |
| this | 0x2C | R | — | Count of entries in the list (this[11]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default string fallback when list node string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions:** If a2 is null, returns -1 immediately. If this[11] (count) <= 0, returns -1. PASSES: sub_588410 returns 0 (string match) — returns node index. BLOCKED: no match found, returns -1.
