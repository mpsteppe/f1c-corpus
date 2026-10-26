## RenderBufferVertexAllocator_0050a7e1 — RenderBufferAndVertexArrayAllocator

**Summary:** Allocates and initializes a render buffer with vertex array: computes vertex count rounded up to even, allocates 16-byte stride array via OperatorNewNhMallocWrapper, initializes elements with sub_5008C2, and conditionally configures for FourCC 'GEQY' format, under DirectX render system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithSingleInit (0050b879), RenderObjectConstructor_b891 (0050b891)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | FourCC format identifier checked against 1498831189 ('GEQY') |
| this | 0x8 | R | — | pointer to format descriptor/parent config |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor/initializer for vertex array |
| 0059c578 | loc_59C578 | R | address of vertex buffer allocation result |
| 005adbb8 | off_5ADBB8 | R | VTable_VideoDecoder [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | initialize array of elements (construct each with sub_5007EC) |
| 00507496 | DirectXTextureCreationWithMipmapChain | base initialization with size=0, count=1 |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory for vertex array (16 bytes * vertex count) |
| 0058a5d8 | SEHHandlerInit | initialize SEH handler for exception safety |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x8) | 0x4 | == | 1498831189 | FourCC identifier 'GEQY' |

**Guard interpretation:** If the FourCC at *(this+0x8)+4 matches 1498831189 ('GEQY'), sets v3[1061]=8 and v3[1062]=0.0 (GEQY format config). Otherwise, sets v3[1061]=0.0 and v3[1062]=8 (alternative format config). Both paths execute, no early return.
