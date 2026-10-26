## DynamicsNodeCountRecursive_004486a0 — Recursive tree node count

**Summary:** Recursively counts nodes in a spatial tree (BVH/kd-tree). Starts at 1 (self), then recurses into 4 child pointers (array at this+0x4C) if non-null, plus the equal-bucket child at this+0x5C. Returns total node count.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44BC50 (0044bc50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | child pointer 0 in 4-element child array |
| this | 0x5C | R | — | equal-bucket child pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004486a0 | DynamicsNodeCountRecursive | recursive call to count child subtree nodes |

**Guard conditions:** Each child pointer guarded individually: recursed only if non-null.
