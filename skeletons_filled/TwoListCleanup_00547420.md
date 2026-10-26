## TwoListCleanup_00547420 — Clean up two linked lists with per-node cleanup

**Summary:** Walks and frees two separate linked lists rooted at this+0x24 and this+0x2C. First list (from this+0x24 via this+0x40): traverses via node[48], calls ArrayCleanupWithDualFree on node[47]+0xBC? and frees node[47]. Second list (from this+0x2C): traverses via node[5] (offset 0x14), calls SingleFieldFree on node[4] (offset 0x10) and frees node. Resource manager bulk cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53CAF0 (0053caf0), sub_54AC70 (0054ac70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x10 | R | — | first-list node next pointer (offset 0x40 -> 0x10? actually node+0xC0 = node[48]) |
| this | 0x24 | R | — | root pointer for first linked list |
| this | 0x2C | R | — | root pointer for second linked list |
| this | 0x40 | R | — | pointer used to access first list nodes |
| this | 0xE4 | R | — | unknown field read |
| this | 0x1A0 | RW | 0 | written to 0 at end |

**Written-by note (persistence):**
- this 0x1A0: zeroed unconditionally at end

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ab70 | SingleFieldFree | free single-field allocation |
| 00546370 | ArrayCleanupWithDualFree | free array with dual per-element cleanup |
| 00557470 | EmptyStub_7470 | stub cleanup callback |
| 00587bcf | FreeWrapper_7bcf | memory deallocation |

**Guard conditions:** (1) If this+0x24 (first list root) is non-null: walk linked list via node[48], freeing each node. (2) If this+0x2C (second list root) is non-null: walk linked list via node[5], freeing each node. Both lists cleaned independently.
