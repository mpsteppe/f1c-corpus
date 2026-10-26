## sub_57ACB0_0057acb0 — ModuleListFindAndRemoveNode

**Summary:** Calls method on a1's sub-object, then searches global module init list for node whose data pointer matches a1. Unlinks node from doubly-linked list. If flag at node+12 set, destroys data object via vtable destructor and frees it. Frees node. Decrements pool alloc counter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PointerCheckWithFallback (0057ab20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | a1 parameter — data pointer to match against list nodes |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3bfc | dword_8D3BFC | RW | ModuleInitListHead [DERIVED] — list head, updated if removing first node |
| 008d3c00 | dword_8D3C00 | RW | GenericList_Tail [DERIVED] — tail, updated if removing last node |
| 008d3c04 | dword_8D3C04 | RW | TaskListTail [DERIVED] — updated if removing task tail |
| 008d3c08 | dword_8D3C08 | RW | PoolAllocCounter [DERIVED] — decremented on removal |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | no-op stub |
| 0057a4c0 | VTableDestructorThenNullPointer | destroys data object via vtable |
| 00585cc0 | FieldGetter_5cc0 | retrieves sub-object from a1, calls vtable method at offset 4 on it |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory (data object and node) |

**Guard conditions:** dword_8D3BFC (list head) null → return 1 (empty list). Linear scan fails to find match (v2 becomes null) → return 1 (not found).

