## RecursiveTreeFree_004c9d30 — RecursiveTreeFree

**Summary:** Recursively frees a tree of nodes by following the child pointer at this+0x24. Each node is freed with FreeWrapper_7bcf after its subtree is freed. Called during SpecialFX_Init cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Pointer to child/sub-node; triggers recursive free if non-null |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9d30 | RecursiveTreeFree | Recursive self-call to free child's subtree before freeing current node |
| 00587bcf | FreeWrapper_7bcf | Frees the current node's memory after child subtree is freed |

**Guard conditions:** Checks `this[9]` (this+0x24) for non-null child pointer. If null, returns without action (leaf node reached).
