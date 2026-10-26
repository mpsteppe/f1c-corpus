## VertexBufferSurfaceInit_005527c0 — VertexBufferSurfaceInit

**Summary:** Initializes a vertex buffer for rendering a texture (only when flag bit 0x20000 at offset 0x24 is set). Allocates a 36-byte vertex buffer descriptor, configures primitive type (34 = D3DPT_TRIANGLESTRIP?), vertex stride (dword_8CEF78), and vertex count (768). Allocates the actual vertex buffer via BufferLockAllocate with 96-byte elements, then zeroes two fields per vertex (offset 0x8 = 0, offset 0xC = 1.0f) and calls ArithmeticComparison_0f90 to finalize.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70), sub_552470 (00552470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x8 | RW | 0 | Per-vertex field (e.g., color or UV coordinate) zeroed each iteration |
| *(this+0x10) | 0xC | RW | 1065353216 → 1.0f | Per-vertex field (e.g., alpha/rhw) set to 1.0 |
| *(this+0xC) | 0x0 | RW | 34 | Vertex buffer primitive type (D3DPT_TRIANGLESTRIP = 34?) |
| *(this+0xC) | 0x4 | RW | — | Vertex stride (from global dword_8CEF78) |
| *(this+0xC) | 0x8 | RW | 28 | Some offset/size parameter (28 = 0x1C) |
| *(this+0xC) | 0xC | RW | 768 | Vertex/element count (max iterations for init loop) |
| this | 0xC | RW | — | Pointer to 36-byte vertex buffer descriptor struct (allocated if null) |
| this | 0x10 | RW | — | Vertex buffer pointer (returned by BufferLockAllocate) |
| this | 0x24 | R | — | Flags (bit 0x20000 = texture mode gate; entire init skipped if clear) |

**Written-by note (persistence):**
- *(this+0x10) 0x8: written on init; survives external poke (initialized to 0)
- *(this+0x10) 0xC: written on init; survives external poke (initialized to 1.0f)
- *(this+0xC) 0x0: written on init; survives external poke (set to 34)
- *(this+0xC) 0x4: written on init; survives external poke (set to global stride)
- *(this+0xC) 0x8: written on init; survives external poke (set to 28)
- *(this+0xC) 0xC: written on init; survives external poke (set to 768)
- this 0xC: written on init (allocation); survives external poke
- this 0x10: written on init (buffer allocation); survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager global — used for D3D operations (sub_540DF0, BufferLockAllocate, ArithmeticComparison_0f90) |
| 008cef78 | dword_8CEF78 | R | Vertex buffer stride value (vertex size in bytes) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540df0 | sub_540DF0 | Validates/creates a D3D vertex buffer description |
| 00540f00 | BufferLockAllocate | Allocates and locks vertex buffer memory |
| 00540f90 | ArithmeticComparison_0f90 | Finalizes/completes buffer setup (arithmetic compare operation) |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation wrapper |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0xC | > | 0 | Vertex count: loop advances through all vertices until counter reaches count |

**Guard interpretation:** BLOCKED: entire function skipped if bit 0x20000 at offset 0x24 is NOT set (non-texture mode returns 0 immediately). PASSED: allocates and initializes vertex buffer with 768 vertices, each initialized with 0 and 1.0f at offsets 0x8 and 0xC.
