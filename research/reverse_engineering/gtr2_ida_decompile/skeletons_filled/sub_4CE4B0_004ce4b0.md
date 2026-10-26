## sub_4CE4B0_004ce4b0 — Get indexed list-node name

**Summary:** Walks a singly-linked list indexed by a2 — starting from the head pointer stored at this[0x90], it follows the next-link at node+0x8C a2 times and returns the CHAR* name stored at the resulting node+0x114. Falls back to the WindowName global for out-of-range indices or NULL entries.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | Next-node link followed while walking the list toward the requested index |
| *(this+0x11C) | 0x114 | R | — | CHAR* string (entry name) of the indexed node, returned to caller |
| this | 0x90 | R | — | Head pointer of the linked list (first node) |
| this | 0x94 | R | — | List length / element count used to validate the index |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Default/fallback CHAR* returned when the index is invalid or no name is present |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Index a2 must satisfy `a2 >= 0` and `a2 < this[37]` (count at offset 0x94) — otherwise the list is not walked and WindowName is returned. While walking, if the next-link (node+0x8C) becomes NULL before a2 steps are reached, the walk aborts and WindowName is returned; if the reached node's name field (node+0x114) is NULL, WindowName is returned instead.
