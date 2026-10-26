## ObjectReleaseArrayIterator_004034d0 — SubObjectArrayRelease

**Summary:** Releases an array of sub-objects at this[77] (pointer to 316-byte stride array with count at offset -4). Iterates backward through all entries calling EmptyStub_0170 on each, then frees the allocation via FreeWrapper_7bcf. Zeroes this[76] (count) and this[77] (pointer) on completion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_402690 (00402690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | RW | 0 | element count (this[76]) — zeroed on release |
| this | 0x134 | RW | 0 | pointer to sub-object array (this[77]) — freed and zeroed on release |

**Written-by note (persistence):**
- this 0x130: written once on release — persists until next allocation
- this 0x134: written once on release — persists until next allocation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | called on each sub-object entry during release (likely virtual destructor/dispose) |
| 00587bcf | FreeWrapper_7bcf | frees the sub-object array allocation |

**Guard conditions:** If this[77] (pointer) is non-null, reads count from offset -4, iterates backward calling EmptyStub_0170 on each element, then frees the allocation. If this[77] is null, just zeroes count and pointer. PASSES: array released, both fields zeroed.
