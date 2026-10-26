## TreeWalkerVirtualCallRecurse_00495930 — TreeWalkRecurseVirtual

**Summary:** Recursively walks a tree structure invoking a virtual callback (vtable slot 40) on each node, then recursing into the child subtree (offset 0x90), and iterating to the sibling node (offset 0x118). Returns 0 on successful full traversal, -1 on NULL input. Part of a UI or scene-graph tree walker.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_58d0 (004958d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | unknown field (possibly accessed during virtual callback) |
| this | 0x0 | R | — | Vtable pointer; slot 40 (offset 160) called as per-node visitor |
| this | 0x90 | R | — | Child subtree pointer — recursed into via TreeWalkerVirtualCallRecurse |
| this | 0x118 | R | — | Sibling/next node pointer — loop iteration continuation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00495930 | TreeWalkerVirtualCallRecurse | Recursive self-call to process child subtree at offset 0x90 |

**Guard conditions:** NULL input → return -1 (BLOCKED). Non-NULL → traverse entire tree until sibling chain at offset 0x118 terminates in NULL.
