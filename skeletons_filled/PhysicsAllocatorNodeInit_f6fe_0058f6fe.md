## PhysicsAllocatorNodeInit_f6fe_0058f6fe — AllocatorNodeInitWithLocaleData

**Summary:** Initializes an allocator node with locale data. If dword_8D3F3C (MemPool_AllocFlag) is set, allocates 48-byte block, calls sub_58F7C9 to populate locale fields, stores in off_5E9AC0, replaces ListManagerHead (dword_8D3F68). If flag is zero, copies off_5E9AC0 pointers to static sentinel (off_5E9A90/94/98) and clears the list manager.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9a90 | off_5E9A90 | RW | LinkedList_Sentinel [DERIVED] — static sentinel for locale list when dynamic mode disabled |
| 005e9a94 | off_5E9A94 | W | AllocLinkedListPtr [DERIVED] — second field of static sentinel structure |
| 005e9a98 | off_5E9A98 | W | CRT_AllocChainPtr [DERIVED] — third field of static sentinel structure |
| 005e9ac0 | off_5E9AC0 | RW | PTR_AudioStreamBuffer [DERIVED] — locale data pointer array (3 fields), replaced with new or sentinel |
| 008d3f3c | dword_8D3F3C | R | MemPool_AllocFlag [DERIVED] — nonzero = allocate dynamic node, zero = use static sentinel |
| 008d3f68 | dword_8D3F68 | RW | ListManagerHead [DERIVED] — old list manager head, freed and replaced |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058aa6f | sub_58AA6F | Free old list manager head or failed allocation |
| 0058ab58 | sub_58AB58 | Allocate zero-initialized 48-byte block for new node |
| 0058f7c9 | sub_58F7C9 | Initialize locale data fields in the allocated block (query system locale) |
| 0058f8eb | MultiFieldFree_f8eb | Free the 7 locale buffer pointers inside the list manager head structure |

**Guard conditions:**
- `dword_8D3F3C` (MemPool_AllocFlag) nonzero → allocate new node, init locale, replace off_5E9AC0 and dword_8D3F68
- `dword_8D3F3C` zero → use static sentinel globals, free old manager, set to NULL
- `sub_58AB58(1, 48)` returns NULL → return 1 (allocation failure)
- `sub_58F7C9(v0)` returns nonzero (init failed) → free block, return 1
- Success → return 0
