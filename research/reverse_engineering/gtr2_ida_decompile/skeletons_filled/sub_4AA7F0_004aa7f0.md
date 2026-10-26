## sub_4AA7F0_004aa7f0 — ScalarDeletingDestructor

**Summary:** Standard scalar deleting destructor variant: runs the base cleanup sub_4A7290 and frees the object block with j__free only when the low bit of flag a2 is set; returns the block pointer.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a7290 | sub_4A7290 | Base cleanup/destruction invoked before the optional free. |
| 006308d3 | j__free | Frees the object block when the deleting flag is set. |

**Guard conditions:** j__free(Block) is called only when (a2 & 1) != 0 (deleting-destructor flag); with the low bit clear only the cleanup runs.
