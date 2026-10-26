## ObjectArrayLinkedListWalk_00406f90 — ObjectArrayAndLinkedListWalkDispatch

**Summary:** Walks both an array of 20-byte object entries and a linked list of objects, dispatching virtual method calls on each (vtable+8 for array entries, vtable+12 for linked list nodes). Used for iterating all active objects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0xC | R | — | vtable method index used by linked list nodes (vtable+12 dispatch) |
| *(this+0x18) | 0x0 | R | — | first linked list node pointer |
| this | 0x18 | R | — | linked list head pointer |
| this | 0x20 | RW | — | linked list iterator (current node, set during traversal) |
| this | 0x24 | R | — | unknown (not directly referenced in decompiled code) |
| this | 0x28 | R | — | unknown (not directly referenced in decompiled code) |
| this | 0x48 | R | — | pointer to array of 20-byte object entries |
| this | 0x4C | R | — | count of entries in the array |

**Written-by note (persistence):**
- this 0x20: written during walk — set to each linked list node as iteration progresses, ends at last node

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | > | 0 | array entry count must be > 0 to iterate the array |

**Guard interpretation:** Array walk: checks this[18] (offset 0x48) != NULL for valid array pointer, then checks this[19] (offset 0x4C) > 0 for non-zero count. If count <= 0, skips array entirely. Linked list walk: checks this[6] (offset 0x18) != NULL for valid head pointer.
