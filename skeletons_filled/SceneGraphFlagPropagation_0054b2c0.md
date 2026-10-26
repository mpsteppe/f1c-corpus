## SceneGraphFlagPropagation_0054b2c0 — Propagate flags through scene graph hierarchy

**Summary:** Propagates flag bits through a scene graph tree: sets flag a2 on current node (this+0x3C), sets flag a3 on all children in linked list (child list at this+0x204, next at node+0x10, flag field at node+0x14). Recursively propagates to siblings if this+0x44 is non-null. Walks up to parent (this+0x4C) when a4=1. Used during buffer clear/reset operations to propagate dirty/visible flags through hierarchy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ClearBuffersLoop (00545850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x214)+0x10) | 0x10 | R | — | Children linked list next pointer |
| *(*(this+0x214)+0x10) | 0x14 | RW | — | Child node flag field; a3 flags OR-ed in |
| this | 0x3C | RW | — | Current node flag field; a2 flags OR-ed in |
| this | 0x44 | R | — | Non-null triggers recursive sibling propagation |
| this | 0x4C | R | — | Parent pointer; used for upward traversal when a4=1 |
| this | 0x204 | R | — | Head of children linked list |
| this | 0x214 | R | — | Pointer to child list structure |
| this | 0x218 | RW | — | Child or traversal state field |

**Written-by note (persistence):**
- *(*(this+0x214)+0x10) 0x14: written once per call (flags OR-ed into each child node); cumulative — bits survive external pokes
- this 0x3C: OR-ed with a2 each call; cumulative flag field
- this 0x218: written during traversal; cumulative flag state

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b2c0 | SceneGraphFlagPropagation | Recursive call for sibling propagation when this+0x44 is non-null |

**Guard conditions:** If a3 is non-zero: children iteration BLOCKED if `this[0x204]` (head) is null. Child walk continues via node+0x10 next pointer until null. Recursive sibling call BLOCKED if `this+0x44` is zero. Parent walk (when a4=1) BLOCKED if `this[0x4C]` (parent) is null.
