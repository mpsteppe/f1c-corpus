## IndexRemappingWithStride_00403540 — SubObjectGraphLinkRemap

**Summary:** Iterates over all sub-object entries in the array at this[77] (316-byte stride) and remaps three pointer fields (+272 parent, +268 child, +276 sibling) from absolute array-index references to direct pointers into the sub-object array. Invalid or out-of-range indices (-1 or >= count) are zeroed and reset to -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | element count (this[76]) — number of sub-objects |
| this | 0x134 | R | — | pointer to sub-object array (this[77]) base address |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[76] (count) > 0, iterates each sub-object. For each of three index fields (+292 parent, +288 child, +296 sibling): if index is -1 or >= count, zeroes the corresponding pointer field and resets index to -1; otherwise computes pointer as `base + 316 * index`. PASSES: all sub-object links remapped. If count <= 0, does nothing.
