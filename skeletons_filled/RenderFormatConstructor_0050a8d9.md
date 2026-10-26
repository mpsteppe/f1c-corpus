## RenderFormatConstructor_0050a8d9 — TextureObject32ByteConstructor

**Summary:** Constructor that initializes a DirectX texture surface object with 0x20-byte (32-byte) allocation via DirectXTextureCreationWithMipmapChain and sets vtable to off_5ADBC8, under DirectX texture system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5ADBC8 after base init |

**Written-by note (persistence):**
- this 0x0: written once during construction (vtable assignment). Stable unless externally corrupted.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005adbc8 | off_5ADBC8 | R | VTablePtr9 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | base initialization with size=0x20, count=1 |

**Guard conditions:** None — unconditional constructor, no guard branches.
