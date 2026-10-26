## DirectXTextureSurfaceBlitWithColorSpaceConversio_0050b47e — DirectX Texture Surface Blit with Color Space Conversion

**Summary:** Performs DirectX texture surface blit with color space conversion (e.g., DXT-compressed to ARGB). Allocates intermediate conversion buffer on first call, processes scanlines, applies channel decode scaling (R5/G6/B5/A4), and conditionally clears pixels whose decoded values match a reference color.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | RW | — | Pixel R component (or first color channel) |
| *(this+0x10) | 0x4 | RW | — | Pixel G component (or second color channel) |
| *(this+0x10) | 0x8 | R | — | Pixel B component (or third color channel) |
| *(this+0x10) | 0xC | R | — | Pixel A component (or fourth color channel) |
| this | 0x8 | RW | — | Accumulated X offset / position tracking |
| this | 0xC | RW | — | Accumulated Y offset / position tracking |
| this | 0x10 | RW | — | Pointer to surface pixel data (source/dest) |

**Written-by note (persistence):**
- *(this+0x10) 0x0: written conditionally per-pixel inside loops; external poke will not survive if overwritten in next iteration
- *(this+0x10) 0x4: same as above — written conditionally per-pixel
- this 0x8: written conditionally when surface dimensions change
- this 0xC: written conditionally when surface dimensions change
- this 0x10: pointer value set externally; not modified here

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | Callback used for intermediate buffer initialization |
| 0059c58c | loc_59C58C | R | Code label (used as address reference) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005accd0 | flt_5ACCD0 | R | RGBChannelScaleR [DERIVED] (also: R channel scale factor for 5-bit decode) |
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: Float scale factor for 5/6-bit channel decoding) |
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: G channel scale factor for 6-bit decode) |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: A channel scale factor for 4-bit decode) |
| 008b009c | dword_8B009C | R | Conversion state flag read after transform loop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | Initializes allocated conversion buffer with callback-based fill pattern |
| 00507473 | UtilityFunction_7473 | Retrieves or advances output pointer position for format conversion |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation for intermediate conversion buffer |
| 0058a5d8 | SEHHandlerInit | Structured exception handler registration for this frame |

**Guard conditions:** 
- if `*(v4+4280)` (conversion buffer pointer) is NULL: allocate new buffer (size = `*(v4+4260) << 8`, 16 rows). Fail if allocation returns 0 → return early.
- if `width` (aligned) != cached `*(v4+4272)` OR `height` != cached `*(v4+4276)`: re-compute surface layout, flush pixels to conversion buffer via row-callback loop.
- if `*(v4+16)` (some format flag) is zero: skip the color-space conversion/conditional-clear loop.
- Inside conversion loop: if decoded RGBA components all match reference values at `v21[7..10]`, zero-fill the output pixel (color-key / chroma-key discard).
