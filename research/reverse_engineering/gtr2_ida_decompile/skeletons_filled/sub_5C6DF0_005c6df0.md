## sub_5C6DF0_005c6df0 — Scalar deleting destructor (destroy + optional free)

**Summary:** MSVC scalar deleting destructor: runs the destructor body (sub_5C6E10) and, when the flag a2 has bit 0 set, frees the object memory with j__free; returns the object pointer.

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
| 005c6e10 | sub_5C6E10 | destructor body executed before the optional deallocation |
| 006308d3 | j__free | MSVC free() thunk releasing the object memory when a2 bit 0 is set |

**Guard conditions:** a2 (delete flag) bit 0: set → j__free(Block) is called after the destructor body; clear → memory is left allocated and only the destructor body runs. The object pointer is always returned.
