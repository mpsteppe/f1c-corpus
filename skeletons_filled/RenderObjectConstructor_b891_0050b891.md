## RenderObjectConstructor_b891_0050b891 — Shader Object Constructor

**Summary:** DirectX shader sub-constructor. Calls RenderBufferVertexAllocator to allocate render buffer/vertex data, then installs shader vtable (off_5ADE2C).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceFactoryDispatchingFourCCCod (0050b8a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5ADE2C) |

**Written-by note (persistence):**
- this 0x0: written unconditionally at end of function; external poke not expected after construction.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ade2c | off_5ADE2C | R | ShaderVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050a7e1 | RenderBufferVertexAllocator | Allocates render buffer/vertex data for shader object |

**Guard conditions:** unconditional — no branches, no early return.
