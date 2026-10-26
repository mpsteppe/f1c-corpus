## sub_5C6FB0_005c6fb0 — Scalar deleting destructor for ios_base object

**Summary:** MSVC scalar deleting destructor for a std::ios_base-derived object: runs the ios_base destructor (??1ios_base@std@@UAE@XZ) and, when the flag a2 has bit 0 set, frees the memory with j__free; returns the object pointer.

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
| 005c6fd0 | ??1ios_base@std@@UAE@XZ_6 | std::ios_base destructor run before the optional deallocation |
| 006308d3 | j__free | MSVC free() thunk releasing the object memory when a2 bit 0 is set |

**Guard conditions:** a2 (delete flag) bit 0: set → j__free(Block) after the ios_base destructor; clear → no deallocation, destructor only. The pointer is always returned.
