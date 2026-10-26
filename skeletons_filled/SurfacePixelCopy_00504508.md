## SurfacePixelCopy_00504508 — Surface-to-surface pixel row copy

**Summary:** Copies pixel data between two validated compatible surfaces, checking format, dimensions, and palette match. Routes compressed formats to DXTCompressedTextureBlockCopy; for uncompressed formats, performs row-by-row qmemcpy with configurable strides.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | dest pixel format ID (compared with source) |
| obj | 0x10 | R | — | dest flag field (must be 0) |
| obj | 0x18 | R | — | dest pointer to pixel data |
| obj | 0x1050 | R | — | dest row stride in bytes |
| obj | 0x1054 | R | — | dest vertical stride |
| obj | 0x1058 | R | — | dest width in pixels |
| obj | 0x105C | R | — | dest height in pixels |
| obj | 0x1060 | R | — | dest depth/level count |
| this | 0x0 | R | — | pointer to source surface object |
| this | 0x4 | R | — | pointer to dest surface object |
| this | 0x8 | R | — | unknown field |
| this | 0x10 | R | — | source flag field (must be 0) |
| this | 0x18 | R | — | source pointer to pixel data |
| this | 0x1C | R | — | unknown field |
| this | 0x1054 | R | — | source vertical stride |
| this | 0x1058 | R | — | source width in pixels |
| this | 0x105C | R | — | source height in pixels |
| this | 0x1060 | R | — | source depth/level count |
| this | 0x1064 | R | — | bytes per row to copy (row pitch) |
| this | 0x1068 | R | — | unknown |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005033a5 | DXTCompressedTextureBlockCopy | handles copy when surface is compressed format |

**Guard conditions:** If dest format != source format → returns -2147467259. If source flag field != 0 → returns -2147467259. If dest width != source width → returns -2147467259. If dest height != source height → returns -2147467259. If dest depth != source depth → returns -2147467259. If dest is compressed (v2[3]==0) → routes to DXTCompressedTextureBlockCopy. If dest has palette (v2[5]) and palette addresses differ and memcmp of palettes != 0 → returns -2147467259. PASS: all checks pass → row-by-row qmemcpy loop.
