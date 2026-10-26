## LinkedListVirtualDispatch_00499520 — Linked-list virtual dispatch at offset 0xA4

**Summary:** Iterates linked list starting at this+0x44, calling virtual method at vtable offset 0xA4 on each node. Advances via next pointer at node offset 0x8C. Part of render/update dispatch chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xD0) | 0xA4 | R | — | vtable slot 0xA4 — virtual dispatch target per list node |
| this | 0x44 | R | — | linked list head pointer (first node) |
| this | 0xD0 | R | — | pointer providing type info for vtable dispatch at 0xA4 |
| this | 0x15C | R | — | unknown — field read but not visible in decompiled body |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — loops unconditionally until null terminator; returns 0
