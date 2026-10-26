## D3DSurfaceCopyBlit_00500bc8 — D3DSurfaceCopyBlit

**Summary:** Copies D3D texture surface data across mip levels and cubemap faces. Validates surface type (3=2D texture, 4=3D volume, 5=cubemap), auto-selects mip format flags, iterates per-face/mip calling SurfaceBlitOperation or Direct3DTextureVertexBufferInit. Manages surface lock/unlock lifecycle.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXDeviceSurfaceCreationWithFormatCapability (0053fd40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Vtable entry offset 40 (GetSurfaceType / surface dimension query) |
| obj | 0x28 | R | — | Vtable entry offset 56 (LockRect / retrieve surface descriptor) |
| obj | 0x34 | R | — | Vtable entry offset 60 (LockSurface for 2D/volume texture faces) |
| obj | 0x38 | R | — | Alternative LockSurface path (face+mip for cubemap textures) |
| obj | 0x3C | R | — | Vtable entry offset 52 (GetMipMapCount / surface count) |
| this | 0x0 | R | — | Vtable pointer for D3D texture surface object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050099c | SurfaceBlitOperation | Blit source surface to destination surface |
| 00500b42 | Direct3DTextureVertexBufferInit | Initialize vertex buffer from surface data (alternative path) |

**Guard conditions:** If a1 NULL → return -2005530516. Surface type must be 3, 4, or 5; otherwise return -2005530516. If a4 == -1 (auto mip): for type 3, check power-of-2 dimensions → set a4=5 (auto-generate mips) or a4=0. For type 4, check power-of-2 width/height and depth. For type 5, check power-of-2 width/height. If auto fails, a4=524292 (D3DX_FILTER_LINEAR | D3DX_FILTER_DITHER). If a3 (mip level) >= surface count → return -2005530516.
