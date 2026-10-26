## SingleFieldFree_0053ab70 — Buffer pointer free

**Summary:** Frees the buffer pointer at this[3] (offset 0xC) via FreeWrapper_7bcf. Destructor helper for sound buffer object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TwoListCleanup (00547420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | allocated buffer pointer to free (this[3]) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free memory wrapper (heap deallocation) |

**Guard conditions:** No branches. Always frees this[3] unconditionally.
