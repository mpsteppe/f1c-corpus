## DestructorWithResourceCleanup_0045b400 — RenderUIObjectDestructor

**Summary:** Destructor for RenderUIObject. Sets vtable to RenderUIObject table (off_59F080), cleans up sub-object at offset 4, frees heap allocation at offset 0x2C if non-null, then performs resource cleanup. Returns cleanup result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_b3e0 (0045b3e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, restored to RenderUIObject vtable before cleanup |
| this | 0x2C | R | — | heap allocation pointer; conditionally freed if non-null |

**Written-by note (persistence):**
- this 0x0: written to RenderUIObject vtable every call. External poke overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f080 | off_59F080 | R | Vtable_RenderUIObject [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd000 | ShortComputation_d000 | cleanup sub-object at this+4 (offset 4) |
| 00587bcf | FreeWrapper_7bcf | free heap memory pointed to by field at offset 0x2C |
| 0045bcd0 | ResourceCleanup_cd10 | release remaining resources, return cleanup result |

**Guard conditions:** If field at offset 0x2C (heap allocation pointer) is non-null → free it via FreeWrapper_7bcf. If null → skip free.
