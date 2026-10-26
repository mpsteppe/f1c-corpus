## ObjectAllocator_0045bb90 — UIRenderObjectAllocator

**Summary:** Allocates 812-byte UI render object from heap. On success, calls ShortComputation_bb40 to initialize allocated block and stores pointer in this[0]. On allocation failure, stores 0 in this[0]. Returns this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | pointer to allocated and initialized UI render object (or 0 on failure) |

**Written-by note (persistence):**
- this 0x0: written every call (either valid pointer or 0). External poke overwritten each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bb40 | ShortComputation_bb40 | initialize allocated 812-byte block as UI render object |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 812 bytes from heap |

**Guard conditions:** If heap allocation returns NULL → store 0 in this[0], skip initialization. If allocation succeeds → call ShortComputation_bb40 to initialize, store result in this[0].
