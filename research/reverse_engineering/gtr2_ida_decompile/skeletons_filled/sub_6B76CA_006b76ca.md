## sub_6B76CA_006b76ca — Pack plane rows from linear source buffer

**Summary:** Converts a rectangular region of a source buffer into the object's packed pixel format for one plane: for 1/2/4-bpp pixel depths it bit-packs pixels into bytes, for the default depth it copies whole rows via memcpy. On success it writes the computed row count and packed row byte size back into the object.

**Called by:** sub_67A175 (0067a175)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Input: region width (pixel count bound); Output: number of source rows covered (computed from plane pitch/offset) |
| this | 0x4 | RW | — | Output: packed row size in bytes = (rows * bpp + 7) >> 3 |
| this | 0xB | R | — | Pixel depth selector: 1 → 1 bit/pixel, 2 → 2 bpp, 4 → 4 bpp, anything else → byte-copy path |

**Written-by note (persistence):**
- this 0x0: recomputed at the end of each call (row count from plane pitch/offset and old width); external poke overwritten on next call
- this 0x4: recomputed at the end of each call from the new row count and bpp; external poke overwritten on next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00744fc0 | dword_744FC0 | R | Per-plane lookup table: starting linear offset into the source buffer, indexed by plane index a3 |
| 00744fdc | dword_744FDC | R | Per-plane lookup table: source row pitch (stride), indexed by plane index a3 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Outer gate: only runs when `a3 < 6` (valid plane index); for a3 >= 6 the body is skipped entirely and a3 is returned unchanged. Inside each depth case the packing loop runs only while the running source offset `dword_744FC0[a3] + n*pitch` is < this->0x0 (width); if the start offset is already >= width the loop is skipped (straight to the result computation). After a packed loop, if the partial byte accumulator is not empty (`v35 != 7` / `v34 != 6` / `v33 != 4`) the remaining bits are flushed with a final store. Result (row count) and packed row size are written only when a3 < 6.
