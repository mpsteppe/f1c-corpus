## JPEGHuffmanDecoder_00518032 — BitStreamPixelUnpacker

**Summary:** Unpacks packed pixel data from a source buffer into individual pixel slots, handling 1/2/4/8+ bits per pixel formats. Reads from a source data pointer (+1 offset) and expands into output buffer based on bit depth.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_511B7C (00511b7c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xDC) | 0x1 | R | — | source data bytes (offset 1 skips some header byte) |
| this | 0xB8 | R | — | pixel count or output width |
| this | 0xDC | R | — | source data buffer pointer |
| this | 0xFB | R | — | bits per pixel (1, 2, 4, or 8+) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a3==255, copies entire block as 8bpp (full byte copy). Otherwise switches on bits-per-pixel field at 0xFB: case 1 (1bpp), case 2 (2bpp), case 4 (4bpp), default (8+ bpp using byte copies). Each case bit-unpacks source pixels and re-packs them into the output buffer, with a stencil/mask in a3 controlling which bits are written.
