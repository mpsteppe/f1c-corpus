## ConstructorWithVTableSubInit_b446_0050b446 — DirectX Texture Constructor with VTable

**Summary:** DirectX texture sub-constructor. Calls DirectXTextureCreationWithMipmapChain to allocate/init base object, then writes a vtable pointer at offset 0x0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADD7C) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005add7c | off_5ADD7C | R | VTablePtr_5ADD7C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes the DirectX texture base object with mipmap chain support (size 0x10, param a2) |

**Guard conditions:** unconditional — no branches, no early return.
