## LinkedListDestructionWithSEHAllocCleanup_00586240 — DestroySimpleLinkedList

**Summary:** Frees all nodes in a single linked list rooted at offset 0x0. For each node, if flag byte at node+8 is set and data pointer at node+0 is non-null, calls EmptyStub_0170 then frees the data pointer. Frees the node itself. Clears all list head/tail fields (offsets 0x0-0xC) to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Data pointer stored in linked list node |
| obj | 0x8 | R | — | Flag byte in node: if non-zero, node data pointer is valid |
| this | 0x0 | RW | 0 | Linked list head pointer |
| this | 0x4 | RW | 0 | Linked list tail pointer |
| this | 0x8 | RW | 0 | Auxiliary/current pointer |
| this | 0xC | RW | 0 | List node count |

**Written-by note (persistence):**
- this 0x0: set to 0 at end; survives as external write until destruct
- this 0x4: set to 0 at end
- this 0x8: set to 0 at end
- this 0xC: set to 0 at end

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d138 | SEH_586240 | R | SEH handler registration for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op stub called before freeing each node's data pointer |
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated node and node data pointer |

**Guard conditions:** Iterates list from this[0]; processes node only if node flag at +8 is non-zero AND node data pointer at +0 is non-null. If list head is NULL, function returns immediately.
