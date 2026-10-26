## ObjectInitWithVTable_b77b_0050b77b — DirectX Texture Constructor (size 0x40)

**Summary:** DirectX texture sub-constructor variant (size 0x40). Calls DirectXTextureCreationWithMipmapChain to initialize base object, then installs vtable off_5ADDBC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADDBC) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005addbc | off_5ADDBC | R | VTablePtr11 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes DirectX texture base object with mipmap chain (size 0x40, param a2) |

**Guard conditions:** unconditional — no branches, no early return.
