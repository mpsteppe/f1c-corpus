## RecursiveTreeNodeTraversal_00561620 — TransformTreeNodeTraverse

**Summary:** Recursively traverse a tree of transform/position nodes. Visits child (offset 0x44) first, then sibling via offset 0x40 (if child at 0x4C exists), then calls sub_561660 to process the current node. Skips if flag at offset 0x3C bit 1 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5613E0 (005613e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C | R | — | Flags byte (bit 1 = skip processing) |
| this | 0x40 | R | — | Pointer to next sibling node |
| this | 0x44 | R | — | Pointer to child node |
| this | 0x4C | R | — | Pointer to sibling's child / extra link |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00561620 | RecursiveTreeNodeTraversal | Recurse into child/sibling nodes |
| 00561660 | sub_561660 | Process current node transform |

**Guard conditions:** *(a1 + 60) bit 1 (offset 0x3C) — if set, skip entire traversal and return early. If child at offset 0x44 is non-zero, recurse into it first. If offset 0x40 is non-zero AND offset 0x4C is non-zero, recurse into the 0x4C pointer.
