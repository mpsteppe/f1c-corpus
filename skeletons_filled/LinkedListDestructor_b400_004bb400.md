## LinkedListDestructor_b400_004bb400 — List destructor (flag at offset 0xC)

**Summary:** Walks a linked list freeing each node and optionally freeing attached data if the flag at node+0xC is set. Zeroes all list bookkeeping fields after destruction.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x4) | 0x4 | R | — | Next node's next pointer (traversal chain) |
| obj | 0x0 | R | — | Node data pointer (freed conditionally) |
| obj | 0xC | R | — | Node free-data flag (non-zero = free data at offset 0) |
| this | 0x0 | RW | 0 | List head pointer (zeroed after destruction) |
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
| 00587bcf | FreeWrapper_7bcf | Memory deallocation (node and conditional data) |

**Guard conditions:** If head is null, loop is skipped but list fields are still zeroed. Per-node: data freed only if node+0xC flag is non-zero.
