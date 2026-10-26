## sub_50B3ED_0050b3ed — TextureConstructorSize32_Flag2_V2

**Summary:** Calls DirectX texture creation with mipmap chain (size 0x20, flag 2), then sets vtable pointer to off_5ADD4C. Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, set to off_5ADD4C |

**Written-by note (persistence):**
- this 0x0: written once during construction; vtable pointer persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005add4c | off_5ADD4C | R | Unknown_VTable_5ADD4C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes base DirectX texture object with mipmap chain |

**Guard conditions:** none — unconditional construction, no early return.
