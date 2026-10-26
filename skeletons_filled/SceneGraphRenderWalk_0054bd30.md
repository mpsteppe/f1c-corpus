## SceneGraphRenderWalk_0054bd30 — Walk scene graph and collect visible nodes for render

**Summary:** Walks scene graph tree via sibling chain (this+0x4C) and recursively via child pointer (this+0x44). For each node, checks children linked list (head at this+0x204, next at node+0x10) searching for any child with visibility flag bit 0x80000 at node+0x14. If found, registers current node into global render list at dword_8B8F28+336 (indexed by counter at dword_8B8F28+332). Collects nodes whose children have visible flag set for render submission.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VertexBufferResourceAllocation (00543fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x214) | 0x10 | R | — | Children linked list next pointer |
| *(this+0x214) | 0x14 | R | — | Child node flag field; bit 0x80000 checked for visibility |
| this | 0x44 | R | — | Non-null triggers recursive SceneGraphRenderWalk call |
| this | 0x4C | R | — | Sibling/next pointer for tree walk loop |
| this | 0x204 | R | — | Head of children linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] — UI root context; offsets +332 (render list counter) and +336 (render list buffer) used for registration |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054bd30 | SceneGraphRenderWalk | Recursive call for subtree traversal when this+0x44 is non-null |

**Guard conditions:** If `this[0x204]` (children head) is null → skip children search, go to recursion check. Children walk: tests each child's flag at node+0x14 for bit 0x80000; if not set, follows node+0x10 next pointer — walk stops at first child WITH bit set, or exhausts list. No child with flag set → node not registered in render list. Recursion BLOCKED if `this[0x44]` is null. Sibling loop continues while `this[0x4C]` is non-null.
