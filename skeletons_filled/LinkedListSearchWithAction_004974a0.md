## LinkedListSearchWithAction_004974a0 — SearchLinkedListAndDispatchAction

**Summary:** Traverses a singly-linked list starting from head pointer at this+0x4, searching for a node whose data matches parameter `a2`. On match, calls SimpleSetter_fc40(1), FieldGetter_8e30, and SetterVirtualCall. Always sets byte field at this+0x25 to 1 via ShortComputation_7250 before returning 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x4) | 0x0 | R | — | Next node's first field (item pointer) |
| *(this+0x4) | 0x0 | R | — | Head node's first field (initial item pointer) |
| *(this+0xC) | 0x4 | R | — | Current node's second field (next node pointer) |
| this | 0x4 | R | — | Linked list head pointer |
| this | 0xC | RW | — | Current node pointer during traversal |

**Written-by note (persistence):**
- this 0xC: Written each call (head on entry, next node each iteration). External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00497250 | ShortComputation_7250 | Sets byte field at this+0x25 to 1 (always at end) |
| 00498e30 | FieldGetter_8e30 | Gets a field from matched node for SetterVirtualCall |
| 00498f40 | SetterVirtualCall | Performs virtual setter on matched node's field |
| 0054fc40 | SimpleSetter_fc40 | Sets a flag to 1 on match |

**Guard conditions:** Three-entry guard: (1) head pointer at this+0x4 must be non-null, (2) head node's data field must be non-null (*v3 != 0), (3) search parameter a2 must be non-null. During traversal, current node at this+0xC and next node pointer are checked for null — null causes loop break.
