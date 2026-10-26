## sub_5BC9C0_005bc9c0 — Accumulate transformed child vertices into AABB

**Summary:** Builds an output AABB (a2) by iterating the child list (count 0x1BC, array 0x1C4), resolving a per-child data object through an 8-byte-stride table at child+0x128 indexed by a3, then transforming the object's vertex array (count at +40, data at +16) by the child's 4x4 matrix (copied from child+0x44) and expanding the AABB with every transformed point.

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

**Guard conditions:** child count (this[111]) > 0 → iterate; per child, pointer at child+0x128+8*a3+4 must be non-null → virtual call vtable+12; result non-null and vertex count (obj+40) > 0 → per-vertex transform+merge loop. If count <= 0, the routine only writes the ±FLT_MAX initializers to a2 and returns the count (0).
