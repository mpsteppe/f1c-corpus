## BVHTreeLinearize_004486e0 — BVH tree flatten/linearize

**Summary:** Recursively flattens a BVH tree into a contiguous array. Stores node pointer at `out[a3]`, writes current output index to `this[18]` (0x48), then recurses through up to 5 child pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44BC50 (0044bc50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | RW | — | output index: written with current position `a3`, survives as record of where this node was placed |
| this | 0x4C | R | — | child pointer 0 (null = no child) |
| this | 0x5C | R | — | extra child pointer (5th child), checked separately after the main 4 |

**Written-by note (persistence):**
- this 0x48: written once per call (stores the output index `a3`); will be overwritten if linearize runs again on same node

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004486e0 | BVHTreeLinearize | recursive call — linearizes child subtree into remaining output slots |

**Guard conditions:** Loop guards 4 children at offsets 0x4C, 0x50, 0x54, 0x58: if `*v5` (child pointer) is non-null, recurse; null child is skipped (not recursed). Final guard at `this[23]` (offset 0x5C): if non-null, recurse once more; if null, skip.
