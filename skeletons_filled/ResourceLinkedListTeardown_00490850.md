## ResourceLinkedListTeardown_00490850 — PoolAllocTeardown

**Summary:** Tears down the custom memory pool allocator system. Frees allocator handle, walks used and free linked lists to release resources with conditional cleanup routines, zeroes list fields, then frees the pool descriptor itself.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

(None — operates on heap-allocated pool descriptor and globals)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd9cc | dword_7CD9CC | R | PoolDescriptorPtr — pointer to pool struct being torn down |
| 007cd9d0 | dword_7CD9D0 | R | AllocatorHandle — handle object to destroy and free |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00491740 | ConditionalDestructor_1740 | Conditional destructor for allocator handle |
| 00491e60 | ShortComputation_1e60 | Cleanup/notification for used list nodes |
| 00491e80 | UtilityFunction_1e80 | Cleanup utility for free list node resources |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation |

**Guard conditions:** Checks `dword_7CD9D0` — PASSES (calls destructor and frees) when non-null. Checks `dword_7CD9CC` — BLOCKED (returns) when null. Within pool: walks used linked list from pool+16, frees each node (with conditional ShortComputation_1e60 call if flag at node+8 is non-zero and vtable exists). Then walks free linked list from pool start, frees each node (with conditional UtilityFunction_1e80 call if flag at node+8 is non-zero and pointer exists). Finally frees pool descriptor itself.
