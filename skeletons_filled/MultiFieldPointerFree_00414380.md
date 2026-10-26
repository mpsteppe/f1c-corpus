## MultiFieldPointerFree_00414380 — MultiFieldPointerFree

**Summary:** Frees multiple pointer fields in a struct (main pointer at offset 0, and four groups of 2 pointers at stride 5) using FreeWrapper_7bcf, preceded by a TextFormatStructInitializer_4d70 reset call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GlobalListTripleCleanupWithTimerRemoval (00414210), DrawableResourceCleanup (004150c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Main pointer field at base of struct, freed after sub-field cleanup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414d70 | TextFormatStructInitializer_4d70 | Resets/initializes the text format struct before freeing its pointer fields |
| 00587bcf | FreeWrapper_7bcf | Wrapper around free() for releasing individual pointer fields |

**Guard conditions:** Each pointer field is checked for non-null before freeing. Main pointer (this+0) freed last only if non-null. Four loops each free 2 pointers at stride 5 (offsets 8, 3, -2, -7, etc., relative to loop start positions this+43, this+33, this+23, this+13).
