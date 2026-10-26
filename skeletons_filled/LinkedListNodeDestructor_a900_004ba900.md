## LinkedListNodeDestructor_a900_004ba900 — Node destructor with conditional data free

**Summary:** Frees a linked list node's attached data (both primary and secondary pointers) if the free-flag at this+0xC is set. Optionally frees the node itself if a2 bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Secondary data pointer in the node's data block (freed if non-null) |
| this | 0x0 | R | — | Primary data pointer (freed if non-null and flag set) |
| this | 0xC | R | — | Free-data enable flag; if non-zero, data pointers are freed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** Data is freed only if this+0xC flag is non-zero. Node self-free only if a2 bit 0 is set.
