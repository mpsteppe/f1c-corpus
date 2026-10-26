## ConstructorWithInit_0050b20c — TextureConstructorClass8_V4

**Summary:** Calls DirectX texture creation with mipmap chain (size 8, flag 1), then sets vtable pointer to off_5ADCDC. Returns initialized object.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer, set to off_5ADCDC |

**Written-by note (persistence):**
- this 0x0: written once during construction; vtable pointer persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005adcdc | off_5ADCDC | R | VTable_FUN_0050b20c [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes base DirectX texture object with mipmap chain |

**Guard conditions:** none — unconditional construction, no early return.
