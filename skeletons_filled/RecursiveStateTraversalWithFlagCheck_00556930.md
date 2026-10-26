## RecursiveStateTraversalWithFlagCheck_00556930 — SceneNodeVisibilityCulledTraverse

**Summary:** Traverses a scene graph sibling-linked list rooted at `this`. For each node, checks a visibility mask against the global render visibility mask; if visible, dispatches animation and optionally recurses into children. Part of scene graph render/animation traversal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneRenderTransform (00548c20), sub_556E70 (00556e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | node visibility/state mask for culling against global render mask |
| this | 0x40 | R | — | sibling continuation flag; zero means end of sibling chain |
| this | 0x44 | R | — | children flag; non-zero triggers recursive traversal |
| this | 0x4C | R | — | next sibling pointer (linked list continuation) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8e34 | dword_8B8E34 | R | global renderer visibility/active-state mask used for node culling |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556930 | RecursiveStateTraversalWithFlagCheck | self: recursive traversal into child nodes |
| 00556980 | AnimationDispatchWithSkipFlag | dispatch animation updates with skip-flag check |

**Guard conditions:** 
1. `result = this[14]` (offset 0x38) is non-zero AND `(global_mask & node_mask & param_mask) != node_mask` → break loop (skip this node and its subtree)
   PASSES: node mask is zero (no restriction) OR visibility test passes → dispatch animation + recurse
   BLOCKED: visibility test fails → break out of traversal loop
2. `this[16]` (offset 0x40) is zero → break loop (no more siblings)
3. Next sibling pointer `this[19]` (offset 0x4C) is null → loop ends