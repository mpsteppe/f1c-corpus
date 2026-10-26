## PixelBlenderCompositor_00503e36 — 8-bit 2x2 pixel averaging blend

**Summary:** Performs 2x2 block pixel averaging for 8-bit RGB surfaces, reading 4 source pixels per block and blending channels (masks 0xE3 and 0x1C for RGB 332 format) into one output byte per block. Iterates over source rows with double-stride advancement.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** COMInterfaceVectorProcessingMethod (00504b37)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x18) | 0x0 | R | — | source pixel value (first of 4 in 2x2 block) |
| *(obj+0x18) | 0x1 | R | — | source pixel value (second of 4 in 2x2 block) |
| obj | 0x18 | R | — | pointer to source pixel data base |
| obj | 0x1050 | R | — | source row stride in bytes |
| obj | 0x1058 | R | — | source block width in pixels (loop bound) |
| obj | 0x105C | R | — | source blocks per row count |
| this | 0x0 | R | — | pointer to source surface object |
| this | 0x4 | R | — | pointer to destination surface object |
| this | 0x1C | R | — | unknown field |
| this | 0x1054 | R | — | destination row stride |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Inner loop runs while source pixel pointer < row-end bound from block width. Outer loop advances source by 2× row stride and destination by 1× row stride. No early-return guards — always returns 0.
