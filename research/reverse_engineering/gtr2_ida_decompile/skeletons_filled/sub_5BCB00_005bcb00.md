## sub_5BCB00_005bcb00 — Accumulate transformed child vertices into AABB (alt table)

**Summary:** Twin of sub_5BC9C0: builds an output AABB (a2) from the children (count 0x1BC, array 0x1C4), but resolves the per-child data object through the table at child+0x140 (instead of +0x128), then transforms each vertex of that object by the child's 4x4 matrix (child+0x44) and merges the transformed points into the AABB.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | number of children in the list |
| this | 0x1C4 | R | — | pointer to child object pointer array (4-byte entries) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bc480 | sub_5BC480 | expand the output AABB (a2) by one transformed vertex |

**Guard conditions:** child count (this[111]) > 0 → iterate; per child, pointer at child+0x140+8*a3+4 must be non-null → virtual call vtable+12; result non-null and vertex count (obj+40) > 0 → per-vertex transform+merge. Count <= 0 → only the ±FLT_MAX initializers written to a2, returns count.
