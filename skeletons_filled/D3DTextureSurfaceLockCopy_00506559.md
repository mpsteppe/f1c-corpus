## D3DTextureSurfaceLockCopy_00506559 — Lock D3D surface rectangle and copy pixel data

**Summary:** Tears down existing resources, then locks a rectangular region of a D3D surface, creates a compatible child surface, copies pixel data between surfaces handling compressed (DXT) format alignment, and fills a descriptor structure with surface info (pitch, format, dimensions). Supports partial rect copies and various copy flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), SurfaceBlitOperation (0050099c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x24 | R | — | vtable offset 36 (LockRect) on destination surface |
| *(*(this+0xC)+0x0) | 0x6C | R | — | vtable offset 108 (CreateCompatibleSurface or similar) on source surface |
| *(*(this+0xC)+0x0) | 0x70 | R | — | vtable offset 112 (CopyRects) on source surface |
| *(this+0x8) | 0x0 | R | — | dest surface vtable pointer |
| *(this+0xC) | 0x0 | R | — | source surface vtable pointer |
| this | 0x0 | RW | — | flags / control DWORD (stores a7 parameter) |
| this | 0x4 | RW | — | stores a3 input surface pointer |
| this | 0x8 | R | — | dest surface pointer (used for LockRect) |
| this | 0xC | R | — | source surface pointer (used for CreateCompatibleSurface) |

**Written-by note (persistence):**
- this 0x0: once — overwritten with a7 flags; external poke does NOT survive
- this 0x4: once — overwritten with a3 surface pointer; external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad4c0 | unk_5AD4C0 | R | Unknown_Struct_5AD4C0 [DERIVED] — used for surface capability query (GetDesc + custom check) |
| 005ad4d0 | unk_5AD4D0 | R | D3DSurfaceDesc [DERIVED] — surface descriptor for GetDesc call |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00500eac | sub_500EAC | disables/enables rendering state (arg 0=disable, 1=enable) around surface description queries |
| 005064cf | RenderResourceTeardown | releases existing surface/device resources before creating new surface |

**Guard conditions:** If a5 (rect) provided and bounds invalid (x<0, x2>w, x1>x2, y<0, y2>h, y1>y2) → returns -2005530516 (D3DERR_INVALIDCALL). If no render-to-system-mem conversion needed (v27 or v26&0x200) AND v44 flag not set → jumps to LABEL_39 (skip surface creation). For DXT formats (FourCC 0x31545844-0x35545844), aligns dimensions to 4. If v43 (full-surface copy) is true or CopyRects succeeds → proceeds to LockRect. PASS: LockRect succeeds → fills a2 descriptor with pitch, format, size, stride info and returns 0.
