## ConstructorSize0x30_0050b743 — DirectX Surface Constructor (size 0x30)

**Summary:** DirectX texture/surface sub-constructor variant (size 0x30). Calls DirectXTextureCreationWithMipmapChain to initialize base object, then installs DX surface vtable off_5ADDAC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADDAC) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005addac | off_5ADDAC | R | DXSurfaceVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507496 | DirectXTextureCreationWithMipmapChain | Initializes DirectX texture base object with mipmap chain (size 0x30, param a2) |

**Guard conditions:** unconditional — no branches, no early return.
