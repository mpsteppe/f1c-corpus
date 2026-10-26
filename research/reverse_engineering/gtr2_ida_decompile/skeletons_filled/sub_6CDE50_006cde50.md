## sub_6CDE50_006cde50 — Allocate per-record two-region data buffers

**Summary:** Builds the per-record buffer tables of the object at this+0x1AC: allocates one block holding the two pointer arrays (+0x38 and +0x3C) and, for each of the `this+0x24` records (stride 84 bytes at this+0xDC), allocates a combined buffer whose region A pointer goes into +0x38[i] and region B pointer into +0x3C[i]. Sizes are derived from the record's +0xC and +0x24 count fields divided by this+0x140, with region B placed one stride (divisor+4 dwords) past region A.

**Called by:** sub_6CE3F0 (006ce3f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1AC) | 0x38 | RW | — | base of the per-record pointer array for region A (allocated here) |
| *(this+0x1AC) | 0x3C | RW | — | base of the per-record pointer array for region B (allocated here, immediately after array A) |
| *(this+0x4) | 0x0 | R | — | allocator callback invoked as (this, 1, byte_size) for every buffer |
| *(this+0xDC) | 0xC | R | — | record field used as the first factor of the element count |
| *(this+0xDC) | 0x24 | R | — | record field used as the second factor of the element count |
| this | 0x4 | R | — | pointer to the allocation callback (called indirectly) |
| this | 0x24 | R | — | record count (loop bound; also returned) |
| this | 0xDC | R | — | record array base (stride 21 dwords = 84 bytes) |
| this | 0x140 | R | — | divisor applied to the product of the two record count fields |
| this | 0x1AC | R | — | target object receiving the two pointer arrays |

**Written-by note (persistence):**
- *(this+0x1AC) 0x38: written (reallocated) on every call of this setup function — each call replaces the pointer array with fresh allocations, so an external poke survives only until the next call.
- *(this+0x1AC) 0x3C: same — rewritten on every call; an external poke survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** no early returns; only the per-record allocation loop is guarded by `*(this+0x24) > 0` — with a count of zero (or negative) the loop body is skipped, the two pointer-array bases are still written, and the function returns the (non-positive) count. The function returns `*(this+0x24)` in all cases.
