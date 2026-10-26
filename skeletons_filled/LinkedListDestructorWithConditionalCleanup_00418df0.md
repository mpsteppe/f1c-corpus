## LinkedListDestructorWithConditionalCleanup_00418df0 — LinkedListWithFlaggedDataCleanup

**Summary:** Destructor for linked list with per-node data cleanup flag. Calls pre-cleanup sub_4190C0, then iterates nodes: if node's byte flag at +8 is non-zero, frees attached data pointer before freeing node. Zeros all four list management fields (head/next/counts) after traversal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x4 | R | — | Node field at offset +4: contains next pointer (linked list traversal) |
| this | 0x1A0 | RW | 0 | Linked list head pointer (this[104]); iterated by for loop, zeroed after |
| this | 0x1A4 | RW | 0 | Node pointer / tail iterator (this[105]); zeroed after |
| this | 0x1A8 | RW | 0 | List count/size (this[106]); zeroed after |
| this | 0x1AC | RW | 0 | Auxiliary list field (this[107]); zeroed after |

**Written-by note (persistence):**
- this 0x1A0: zeroed unconditionally after list traversal
- this 0x1A4: zeroed unconditionally after list traversal
- this 0x1A8: zeroed unconditionally after list traversal
- this 0x1AC: zeroed unconditionally after list traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004190c0 | sub_4190C0 | Pre-cleanup helper called before list node traversal |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper (for nodes and their data) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1A8 | == | 0 | List count/size field |

**Guard interpretation:** When this+0x1A8 (list count) is 0, the linked list is empty — for-loop condition (`i = this[104]`) yields null and traversal is BLOCKED. When non-zero, list has entries and iteration proceeds — each node's data pointer freed if node flag at offset +8 is non-zero.
