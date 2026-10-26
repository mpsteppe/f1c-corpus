## TextureAllocationWithFormatSizeFlags_00558d10 — TextureBufferAllocation

**Summary:** Allocates a texture buffer via BufferLockAllocate, selecting entry size (96 or 32 bytes) based on format flag bit 7, and stores the allocated handle.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_558A30 (00558a30), sub_558B30 (00558b30), PixelAttributeWriteToTexture (00558dc0), PixelWriteToTextureBuffer (00558e10), sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | flags (sets bit 8 to mark allocation done) |
| this | 0x2C | R | — | element count for total size calculation |
| this | 0x50 | R | — | format descriptor pointer (this[20], contains buffer params) |

**Written-by note (persistence):**
- this 0x20: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540f00 | BufferLockAllocate | allocates a locked buffer for texture data |

**Guard conditions:** If flag bit 8 is already set → skip allocation, return existing result (BLOCKED: already allocated). PASSES: bit 8 not set → set bit 8, determine entry size (96 or 32 bytes) from flag bit 7, call BufferLockAllocate, store handle.
