## LinkedListDestructorWithVTableNotification_004902c0 — LinkedListDtorNotify

**Summary:** Destructor for a linked list of widget nodes. Iterates the list, conditionally dispatches vtable notification on each node before freeing it, then zeroes list fields and calls base destructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalFree (004902a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xE0)+0x0)+0x0) | 0x0 | R | — | Vtable pointer of node's sub-object |
| *(*(this+0xE0)+0x0) | 0x0 | R | — | Vtable pointer of list node |
| *(*(this+0xE0)+0x4) | 0x4 | R | — | Next node pointer in linked list |
| *(this+0xE0) | 0x0 | R | — | Vtable pointer of first node (for notification) |
| *(this+0xE0) | 0xC | R | — | Node flag byte (tested for zero) |
| this | 0x0 | RW | — | VTable pointer (set before cleanup) |
| this | 0xE0 | RW | 0 | Linked list head pointer |
| this | 0xE4 | RW | 0 | First node pointer or count |
| this | 0xE8 | RW | 0 | Linked list field |
| this | 0xEC | RW | 0 | Linked list field |

**Written-by note (persistence):**
- this 0x0: Once — set to vtable; persists.
- this 0xE0-0xEC: Zeroed during destruction; persists as zero after destructor.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac760 | off_5AC760 | R | VTable_WidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation for each node |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xE0) | 0xC | == | 0 | Node destruction flag (byte) |

**Guard interpretation:** Iterates list from `this+0xE0`. For each node: checks byte at node+0xC — if non-zero AND node's vtable pointer is non-null, dispatches vtable method 0 with arg 1 (notification before free). Always frees the node via FreeWrapper_7bcf. Loop terminates when node pointer is null.
