## ConstructorWithInit_b7e3_0050b7e3 — DirectX Texture2D Constructor (VTable_D3DTex2)

**Summary:** DirectX D3D texture2D sub-constructor. Calls DirectXTextureSurfaceFormatInitialization to set up surface format, then installs D3D texture2D vtable (off_5ADDEC).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADDEC) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005addec | off_5ADDEC | R | VTable_D3DTex2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050afe2 | DirectXTextureSurfaceFormatInitialization | Initializes DirectX surface format data (pixel format, stride, etc.) |

**Guard conditions:** unconditional — no branches, no early return.
