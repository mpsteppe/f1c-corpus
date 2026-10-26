## sub_5EFD80_005efd80 — Tile-atlas UV record builder

**Summary:** Reads a tile-ID matrix through the buffer object at this+0xAC, determines the tile repeat period (columns/rows per tile) by scanning for a sentinel tile ID, then fills an array of 24-byte records at this+0xB8 with tile indices and normalized UV rectangles for a texture atlas; finally zeroes sentinel-valued elements and marks the buffer dirty. Texture-page/atlas support code.

**Called by:** sub_5F0670 (005f0670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC) | 0x0 | RW | — | Buffer object state/flags dword; passed to the buffer access helpers and ORed with 0x200 to mark the data modified/dirty |
| *(this+0xAC) | 0x4 | R | — | Matrix dimension (element count along one axis; used for tile-column count and UV scale denominator) |
| *(this+0xAC) | 0x8 | R | — | Matrix dimension (other axis, row count; used for tile-row count and UV scale denominator) |
| *(this+0xAC) | 0x10 | R | — | Byte stride of one matrix row (>>2 gives dwords per row; used for row-stepping index math) |
| this | 0x10 | R | — | Flags byte; bit 0 selects the texture-dimension adjustment path (dword_FB27A4 vtable call) |
| this | 0x58 | RW | — | First sentinel tile ID read from the end of a matrix row; repeat marker for the column scan |
| this | 0x5C | RW | 18446744073692774400 | Second sentinel tile ID from the row tail; overwritten with 0xFF000000 (-16777216) at the end |
| this | 0x60 | RW | — | Third sentinel tile ID from the row tail; compared during the final zeroing sweep |
| this | 0x64 | RW | — | Columns per tile (scan result: index where the tile pattern repeats) |
| this | 0x68 | RW | — | Rows per tile (scan result: row where the pattern repeats) |
| this | 0x74 | RW | — | Number of tile columns = P[1]/(columns per tile) |
| this | 0x78 | RW | — | Number of tile rows = P[2]/(rows per tile) |
| this | 0x7C | RW | — | Total tile slot count plus 32 — capacity of the 24-byte record array |
| this | 0xAC | R | — | Pointer to the tile matrix/buffer object descriptor (fields 0x0/0x4/0x8/0x10 above) |
| this | 0xBD | RW | — | Byte at record offset +5 of the current 24-byte tile record (records start at this+0xB8); written with rows-per-tile-1 |

**Written-by note (persistence):**
- *(this+0xAC) 0x0: read as input each call; bit 0x200 ORed in during the final sweep. An external poke of other bits survives until a sweep that finds sentinel-valued elements.
- this 0x58: recalculated each successful call from the matrix; an external poke survives only until the next call of this routine.
- this 0x5C: written twice per successful call (matrix value, then hardcoded 0xFF000000 on exit); an external poke never survives a call.
- this 0x60: recalculated each successful call; poke survives only until the next call.
- this 0x64: recalculated each successful call (scan result); poke survives only until the next call.
- this 0x68: recalculated each successful call (scan result); poke survives only until the next call.
- this 0x74: recalculated each successful call; poke survives only until the next call.
- this 0x78: recalculated each successful call; poke survives only until the next call.
- this 0x7C: recalculated each successful call; poke survives only until the next call.
- this 0xBD: rewritten for every tile record each successful call; poke survives only until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | Global singleton; its vtable slot +280 is invoked to adjust the two texture dimensions before UV computation (only when this+0x10 bit 0 is set) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e6e70 | sub_5E6E70 | Buffer access helper — called with (object, flags/state, 0, 2); returns pointer to the tile element array |
| 005e6ea0 | sub_5E6EA0 | Buffer release/flush helper — called with the same arguments after the records are built |

**Guard conditions:** `if (result)`: if the buffer access helper returns 0, the entire body is skipped and 0 is returned (BLOCKED). `(*(this+16) & 1)`: if bit 0 SET, both dimension values are passed through dword_FB27A4 vtable+280 before use; if clear, the raw values are used. `if (v16 > 0)`: the 24-byte record-building loop runs only when the computed tile slot count is positive (skipped otherwise). `if (P[1] * P[2] > 0)`: the final sweep that zeroes sentinel-valued elements and sets flag 0x200 runs only when the matrix has elements. The two ID scans (`for (i...)` and the `do..while`) rely on hitting the sentinel value — no explicit bounds check.
