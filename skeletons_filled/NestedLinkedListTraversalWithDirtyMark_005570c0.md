## NestedLinkedListTraversalWithDirtyMark_005570c0 — NestedSceneNodeDirtyMarkTraversal

**Summary:** Iterates two levels of linked lists rooted at `this+0x100` and `this+0x108`, calling D3DMarkDirty on each node. First traverses parent nodes with nested child lists (at offset 0xEC), then a flat sibling list. Used to mark scene graph resources as dirty for D3D re-upload.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x204)+0xEC) | 0x98 | R | — | field at offset 0x98 within child node structure (unused directly in this function) |
| *(this+0x204) | 0xEC | R | — | child node list head pointer within parent node (from linked list rooted at this+0x100) |
| *(this+0x204) | 0x104 | R | — | next sibling pointer within parent linked list (offset 0x104 from node) |
| this | 0x100 | R | — | linked list head for parent nodes (first level of traversal) |
| this | 0x108 | R | — | linked list head for flat sibling nodes (second traversal loop) |
| this | 0x1A0 | R | — | additional field (unused directly in this function) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556cd0 | D3DMarkDirty | mark a D3D resource/buffer as dirty for re-upload |

**Guard conditions:** 
1. Outer loop: `this[64]` (offset 0x100) null → skip nested traversal entirely
   Inner loop: child list `*(i + 0xEC)` null → skip inner loop for this parent
   Child next pointer `j[19]` (offset 0x4C) null → end inner loop
   Parent next pointer at offset 0x104 null → end outer loop
2. Second loop: `this[66]` (offset 0x108) null → skip flat list traversal
   Node next pointer `k[19]` (offset 0x4C) null → end loop