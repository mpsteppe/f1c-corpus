## ContactManifoldCleanup_00507845 — ContactZMatchZero

**Summary:** Iterates contact manifold array, zeros out any contact whose position matches a reference contact position stored in the owning struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureByteToFloatConverter (00509644), TextureRGBAByteToFloatConversion (005096d0), TextureUnpackRGB (00509776), VertexTextureDecoderRGB565 (00509812), TextureDecode16BitRGB565Format (005098b7), RGB5551ToFloatTextureDecompress (00509959), TextureDecodeRGBA4 (00509a09), VertexTextureDecoderRGBA1010102 (00509ab8), TextureDecode32BitRGLuminanceAlphaFormat (00509b8e), RGB332ToFloatTextureDecompress (00509c20), TextureDecode8BitAlphaOnlyFormat (00509cc2), TextureDecodeRGB565 (00509d34), F_4BitPackedColorDecoder (00509de6), F_8BitVertexColorDecoder (00509e85), TexturePixelPaletteLookup (00509f0c), F_8BitGrayscaleToRGBATextureConverter (00509f70), TextureGrayscaleConversion (00509fde), TextureUnpackNibbles (0050a067), F_8BitVertexPositionDecompression (0050a0f0), RGB565TextureDecompression (0050a172), VertexUnpackRGBA (0050a223), VertexByteDecompress (0050a2b4), VertexBufferGeneration (0050a34b), VertexTextureDecoder1010102 (0050a3ce), TextureDecode32BitRGB10A2Format (0050a488), F_16BitGrayscaleToRGBATextureConverter (0050a55b), F_16BitToFloatTextureDecompress (0050a5cb), F_16BitVertexPositionDecompression (0050a659), TextureDecodeRGB16 (0050a6e5), InputDeviceDataRead (0050af57)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Reference contact X position (float) |
| this | 0x20 | R | — | Reference contact Y position (float) |
| this | 0x24 | R | — | Reference contact Z position (float) |
| this | 0x28 | R | — | Reference contact W/extra component (float) |
| this | 0x1058 | R | — | Contact count limit (int) — number of valid contacts in manifold |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks a2 < a2 + 16 * *(this+0x1058) — if contact count is zero, loop skipped entirely. Each 16-byte contact element: if all 4 floats match the reference (this+0x1C through this+0x28), the contact is zeroed (all 4 floats set to 0.0). Contacts that don't match pass through unchanged.
