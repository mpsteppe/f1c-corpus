## ListFullDestruction_004bb650 — List destructor with two-level data free

**Summary:** Walks linked list freeing nodes. For flagged nodes with data, frees both the inner allocation (data[0]) and the outer data block. Zeroes all list fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Inner allocation pointer (data[0], freed separately) |
| *(obj+0x4) | 0x4 | R | — | Next node's inner data pointer (traversal chain) |
| obj | 0x0 | R | — | Outer data pointer (freed if flag set and non-null) |
| obj | 0x8 | R | — | Node free-data flag (non-zero = free data) |
| this | 0x0 | RW | 0 | List head pointer (zeroed after) |
| this | 0x4 | RW | 0 | List tail pointer (zeroed after) |
| this | 0x8 | RW | 0 | List current pointer (zeroed after) |
| this | 0xC | RW | 0 | List node count (zeroed after) |

**Written-by note (persistence):**
- this 0x0-0xC: all zeroed after destruction; list becomes empty

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation (inner ptr, outer data, node) |

**Guard conditions:** Inner data freed only if node+0x8 flag is set AND outer data pointer is non-null.
