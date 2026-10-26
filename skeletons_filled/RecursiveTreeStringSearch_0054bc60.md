## RecursiveTreeStringSearch_0054bc60 — Recursive depth-first tree string search

**Summary:** Recursively searches a tree structure for a node whose base address string matches input a2. First traverses subtree at this+0x44, then subtree at this+0x4C, then compares this node's string via strcmp. Uses a3 as found-flag (int *): skips string comparison if *a3 already set (short-circuit). Stores found node pointer in *a3. Part of scene node property evaluation system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EvaluateSceneNodeProperty (005453a0), ArithmeticComparison_9170 (00549170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | Pointer to first subtree (child/sibling) for recursive search |
| this | 0x4C | R | — | Pointer to second subtree (child/sibling) for recursive search |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054bc60 | RecursiveTreeStringSearch | Recursive call for subtree traversal |

**Guard conditions:** First recursion BLOCKED if `this+0x44` is null. Second recursion BLOCKED if `this+0x4C` is null. String comparison (strcmp) BLOCKED if `*a3` is already non-zero (node already found in earlier traversal). String match PASSES: stores this node pointer in `*a3` and returns (further comparisons skipped by found-flag).
