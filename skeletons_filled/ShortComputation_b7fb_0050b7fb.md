## ShortComputation_b7fb_0050b7fb — DirectX Surface Format Constructor (VTable_5ADDFC)

**Summary:** DirectX surface sub-constructor variant. Calls DirectXTextureSurfaceFormatInitialization to set up format data, then installs vtable off_5ADDFC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADDFC) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005addfc | off_5ADDFC | R | Vtable_5ADDFC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050afe2 | DirectXTextureSurfaceFormatInitialization | Initializes DirectX surface format data (pixel format, stride, etc.) |

**Guard conditions:** unconditional — no branches, no early return.
