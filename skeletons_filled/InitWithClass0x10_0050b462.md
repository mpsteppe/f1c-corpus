## InitWithClass0x10_0050b462 — DirectX Texture Constructor with VTable alt

**Summary:** DirectX texture sub-constructor variant. Calls DirectXTextureCreationWithMipmapChain to allocate/init base object, then writes alternative vtable pointer (off_5ADD8C) at offset 0x0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADD8C) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005add8c | off_5ADD8C | R | VtablePtr_5ADD8C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes the DirectX texture base object with mipmap chain support (size 0x10, param a2) |

**Guard conditions:** unconditional — no branches, no early return.
