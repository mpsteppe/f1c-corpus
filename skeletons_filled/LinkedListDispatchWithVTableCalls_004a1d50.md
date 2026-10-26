## LinkedListDispatchWithVTableCalls_004a1d50 — LinkedListDispatchWithVTableCalls

**Summary:** Walks a linked list and calls each node's first vtable function (vtable[0]) with a parameter. Optionally performs resource lookup with dual path before traversal. Tracks current position in iterator field (this+0x8).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B0770 (004b0770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x0)+0x0) | 0x0 | R | — | next node pointer (linked list chain) |
| *(obj+0x0) | 0x0 | R | — | first node pointed to by list head |
| *(this+0xC) | 0x0 | R | — | vtable pointer (first entry is call target) |
| *(this+0xC) | 0x4 | R | — | second vtable entry (unused in this function) |
| obj | 0x0 | R | — | node's own next pointer field |
| this | 0x0 | R | — | head of linked list |
| this | 0x8 | RW | — | current iterator position during walk |

**Written-by note (persistence):**
- this 0x8: written each iteration during walk; updated externally before walk begins

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cf0 | ResourceLookupWithDualPath | Performs resource lookup with dual path if a3 is provided |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | head of linked list |

**Guard interpretation:** If list head (this[0]) is NULL, skips traversal entirely. Otherwise walks all nodes, calling vtable[0] on each with parameter a2. Stops when next-node pointer is NULL.
