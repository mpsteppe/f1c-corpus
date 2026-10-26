## DXTCompressedTextureBlockCopy_005033a5 — DXT block blit with alignment and format validation

**Summary:** Copies DXT-compressed texture blocks from source to destination surface, validating 4-byte alignment and DXT1/2/3/4/5 pixel format, then iterating over rows and columns of blocks with qmemcpy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SurfacePixelCopy (00504508)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | pointer to source pixel data base address |
| obj | 0x1030 | R | — | source texture width in pixels |
| obj | 0x1034 | R | — | source texture height in pixels |
| obj | 0x1038 | R | — | source row pitch (bytes) |
| obj | 0x103C | R | — | source slice pitch (bytes) |
| obj | 0x1040 | R | — | additional row offset for multi-level surfaces |
| obj | 0x1050 | R | — | source row stride (bytes between rows of blocks) |
| obj | 0x1054 | R | — | source vertical block count or offset stride |
| this | 0x0 | R | — | pointer to source surface object |
| this | 0x4 | R | — | pointer to destination surface object |
| this | 0x8 | R | — | unknown field |
| this | 0x1C | R | — | unknown field |
| this | 0x1034 | R | — | dest texture height in pixels |
| this | 0x1038 | R | — | dest row pitch (bytes) |
| this | 0x103C | R | — | dest slice pitch (bytes) |
| this | 0x1040 | R | — | dest additional row offset |
| this | 0x1044 | R | — | unknown |
| this | 0x1054 | R | — | dest vertical block count or offset stride |
| this | 0x1058 | R | — | dest block width in pixels (>> 2 = blocks per row) |
| this | 0x105C | R | — | number of blocks per row (loop count) |
| this | 0x1060 | R | — | number of block rows (loop count) |
| this | 0x1064 | R | — | unknown |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks source and dest surface alignment: if low 2 bits of height, width, row pitch, or slice pitch are nonzero → returns -2147467259 (E_FAIL). Checks dest pixel format magic: must be DXT1 (0x31545844) → block size 8, or DXT2/3/4/5 (0x32545844/0x33545844/0x34545844/0x35545844) → block size 16; otherwise returns -2147467259.
