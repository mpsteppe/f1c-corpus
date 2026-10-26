## MultiListDestructorWithCleanup_00486080 — MultiListDestructorWithCleanup

**Summary:** Frees multiple linked lists of heterogeneous nodes: four lists of DualConditionalFree-managed nodes, one singly-linked list of vtable-based objects called with Release/Shutdown, and one list of owned-data nodes. Zeros all freed list heads.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485EB0 (00485eb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x0 | R | — | data pointer of node in list at this+0x54 |
| *(this+0x58) | 0x4 | R | — | next pointer of node in list at this+0x54 |
| *(this+0x90) | 0x0 | R | — | first vtable entry of object in list at this+0x90 |
| this | 0x54 | RW | 0 | head of linked list 5 (owned-data nodes, zeroed after walk) |
| this | 0x58 | RW | 0 | next pointer field within list-5 node structure |
| this | 0x5C | RW | 0 | third field within list-5 node structure |
| this | 0x60 | RW | 0 | fourth field within list-5 node structure |
| this | 0x90 | RW | 0 | head of singly-linked vtable-object list (zeroed after walk) |
| this | 0xCC | R | — | head of linked list 1 (DualConditionalFree nodes) |
| this | 0xD0 | R | — | head of linked list 2 (DualConditionalFree nodes) |
| this | 0xD4 | R | — | head of linked list 3 (DualConditionalFree nodes) |
| this | 0xD8 | R | — | head of linked list 4 (DualConditionalFree nodes) |
| this | 0xFC | R | — | node next pointer for list 1 (node[6]) |
| this | 0x100 | R | — | node next pointer for list 2 (node[6]) |
| this | 0x104 | R | — | node next pointer for list 3 (node[6]) |
| this | 0x108 | R | — | node next pointer for list 4 (node[6]) |

**Written-by note (persistence):**
- this 0x54: zeroed after list freed; external writes before destructor survive until destructor
- this 0x58: zeroed after list freed; external writes before destructor survive
- this 0x5C: zeroed after list freed; external writes before destructor survive
- this 0x60: zeroed after list freed; external writes before destructor survive
- this 0x90: zeroed after list freed; external writes before destructor survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | retrieve next pointer from vtable-object list node |
| 0049a5a0 | DualConditionalFree | conditionally free sub-resources inside a node |
| 00587bcf | FreeWrapper_7bcf | free/deallocate memory via internal allocator |

**Guard conditions:** four DualConditionalFree lists (this[51..54]) — traverse while current node non-null; null node ends traversal. Vtable-object list (this[36]) — traverses while current node non-null; StructFieldAccessor retrieves next before calling vtable Release. Owned-data list (this[21]) — traverses while current node non-null; per-node flag at node+8 determines whether to process data pointer; if data pointer itself is non-null, further dereferences and conditionally frees inner pointer.
