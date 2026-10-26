## LinkedListDtor_004859d0 — ListAndBufferDtor

**Summary:** Destructor iterating a linked list at offset 0x164: frees node data if node flag at +8 is set, frees each node, clears list fields, frees a standalone buffer at offset 0x15C if non-null, calls ConditionalDualCleanup on sub-objects at offsets 224 and 284, then chains to base destructor sub_485EB0 and optionally frees self.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x164)+0x4) | 0x4 | R | — | next pointer in list node; traversed during iteration |
| *(this+0x164) | 0x0 | R | — | first list node pointer; iterated in while loop |
| *(this+0x164) | 0x8 | R | — | flag byte in list node; if non-zero, node data is freed |
| this | 0x15C | R | — | standalone buffer pointer freed if non-null |
| this | 0x164 | RW | 0 | list head pointer; cleared after traversal |
| this | 0x168 | RW | 0 | list tail pointer or count; cleared after traversal |
| this | 0x16C | RW | 0 | list state field; cleared after traversal |
| this | 0x170 | RW | 0 | list state field; cleared after traversal |

**Written-by note (persistence):**
- this 0x164: cleared to 0 after list traversal
- this 0x168: cleared to 0 after list traversal
- this 0x16C: cleared to 0 after list traversal
- this 0x170: cleared to 0 after list traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | chains to base class destructor |
| 00499b50 | ConditionalDualCleanup | cleans up a two-field sub-object (conditionally freeing embedded pointers) |
| 00587bcf | FreeWrapper_7bcf | memory deallocation wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x164) | 0x8 | == | 0 | flag byte in list node: 0 = skip freeing node data, non-zero = free data pointer |

**Guard interpretation:** When node flag byte at offset +8 is 0, the node's data pointer is NOT freed (only the node itself is freed). When flag is non-zero, both data pointer and node are freed.
