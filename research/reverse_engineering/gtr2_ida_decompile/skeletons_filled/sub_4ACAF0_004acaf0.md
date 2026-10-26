## sub_4ACAF0_004acaf0 — Scalar deleting destructor (thunk)

**Summary:** Destructor thunk: runs the object cleanup routine (sub_4993A0) and, when the low bit of the flag argument is set, frees the object memory via j__free. Returns the object pointer. Compiler-generated deleting-destructor pattern.

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
| 004993a0 | sub_4993A0 | Object cleanup/destructor body for this object |
| 006308d3 | j__free | Frees the heap block when the delete flag is set |

**Guard conditions:** (a2 & 1) != 0 → after cleanup, j__free(Block) is called (full delete). When the bit is clear, only sub_4993A0 runs and the memory is left allocated; the object pointer is returned either way.
