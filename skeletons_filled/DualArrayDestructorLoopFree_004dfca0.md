## DualArrayDestructorLoopFree_004dfca0 — LoopDualArrayDestructAndFree

**Summary:** Walks backward through array of 11 structures (each 748 bytes), calling DualArrayDestructor on each, then conditionally frees a pointer at offset 0x90 if non-null. Cleanup/destructor for array of sub-systems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_4570 (004e4570)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | R | — | pointer to free, freed if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ded20 | DualArrayDestructor | destroy internal dual-array structure |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory block |

**Guard conditions:** If this[36] (offset 0x90) is non-null, free the pointer; otherwise skip free.
