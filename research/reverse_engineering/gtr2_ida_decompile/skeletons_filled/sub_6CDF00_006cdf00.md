## sub_6CDF00_006cdf00 — Expand per-record data into region A/B buffers

**Summary:** For each of `this+0x24` records (stride 84 bytes at this+0xDC) recomputes the element count `count = f1*f2 / this+0x140` from the record's +0xC and +0x24 fields, then rewrites the record's destination buffers: copies `count*(divisor+2)` dwords from the per-record source buffer (+0x1B4) into both the region A buffer (+0x1E4) and region B buffer (+0x1E8), cross-copies two `2*count`-sized halves between regions of B and the source, and fills the `count` dwords in front of region A with region A's first element.

**Called by:** sub_6CE380 (006ce380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | — | the pointed-to region B buffer content: read and rewritten in place by the copy/swap loops |
| this | 0x24 | R | — | record count (loop bound) |
| this | 0xDC | R | — | record array base (stride 21 dwords = 84 bytes) |
| this | 0xE8 | R | — | record field at record+0xC: first factor of the element count |
| this | 0x100 | R | — | record field at record+0x24: second factor of the element count |
| this | 0x140 | R | — | divisor applied to the product of the two count factors |
| this | 0x1AC | R | — | pointer to the data object holding the per-record pointer arrays |
| this | 0x1B4 | R | — | per-record source buffer pointer array; the source data is read from here |
| this | 0x1E4 | R | — | per-record region A buffer pointer array; values are written through these pointers |
| this | 0x1E8 | R | — | per-record region B buffer pointer array; used to derive the region B cursor and as write target |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: region B content is recalculated in place for every record on every call — an external poke is overwritten the next time this pass runs.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** the record loop is entered only when `this+0x24` (record count) is > 0 and runs while the decrementing counter is non-zero. Inside, three sub-loops are individually gated: the copy loop runs only when `count*(divisor+2) > 0`; the swap loop only when `2*count > 0`; the header fill only when `count > 0`. All three are skipped when the computed count is zero. The function returns the last computed loop counter/pointer value (decompiler artifact of the loop structure).
