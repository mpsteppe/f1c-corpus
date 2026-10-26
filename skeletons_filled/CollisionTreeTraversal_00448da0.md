## CollisionTreeTraversal_00448da0 — Collision tree traversal with shadow extrusion and child recursion

**Summary:** Recursively traverses a collision tree node hierarchy. For each node, extrudes shadow volume geometry, then recurses into up to 4 child nodes and follows a sibling link to continue the traversal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionContactResponse (00449700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | Pointer to first child collision node (child[0]) |
| this | 0x5C | R | — | Pointer to sibling/next node in tree (linked-list chain) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448730 | ShadowVolumeExtrusion | Builds shadow volume geometry for current collision node |
| 00448da0 | CollisionTreeTraversal | Recursive self-call to process each non-null child node |

**Guard conditions:** Node children (this[0x4C] through this[0x58]) are skipped if null (field == 0 → skip). Sibling link this[0x5C] == 0 terminates the outer loop (break). Non-null sibling causes loop to continue with next node.
