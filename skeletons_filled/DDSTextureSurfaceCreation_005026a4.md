## DDSTextureSurfaceCreation_005026a4 — DDSTextureSurfaceHierarchyBuild

**Summary:** Parses DDS data and builds a linked-list surface hierarchy for mip-mapped/cubemap textures. Creates one surface sub-object per mip level per face, each with format, dimensions, stride, data pointer, and mip chain linking. Validates DDS magic, format table lookup, and buffer size.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXSurfaceFormatNegotiation (00502a15)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | DDS pixel format ID (fourCC code like DXT1, DXT3, etc.) |
| this | 0x4 | RW | — | Pointer to surface pixel data within DDS buffer |
| this | 0x8 | RW | — | Off-screen/extra surface pointer (for mip chain linking) |
| this | 0xC | RW | — | Width of current mip level |
| this | 0x10 | RW | — | Height of current mip level |
| this | 0x14 | RW | 1 | Depth parameter (mip count / layer count for current level) |
| this | 0x30 | RW | — | Row stride in bytes |
| this | 0x34 | RW | — | Total surface data size in bytes |
| this | 0x38 | RW | 0 | Data ownership flag (0 = points into source buffer) |
| this | 0x3C | RW | 0 | Surface/mip flags |
| this | 0x44 | RW | 4 | Surface type info (3=2D, 4=compressed, 5=cubemap face) |

**Written-by note (persistence):**
- this 0x0: Written once per surface to format ID
- this 0x4: Written once per surface to DDS data pointer
- this 0x8: Written once per surface to link pointer
- this 0xC: Written once per mip level to width
- this 0x10: Written once per mip level to height
- this 0x14: Written once per mip level to depth/layer count
- this 0x30: Written once per mip level to computed stride
- this 0x34: Written once per mip level to total size
- this 0x38: Written once per surface to 0 (external data)
- this 0x3C: Written once per surface to 0
- this 0x44: Written once per call to surface type (3/4/5)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d71f8 | dword_5D71F8 | R | D3DFormatTable [DERIVED] — format lookup table (9-DWORD entries per format) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00500680 | IDToStructTableLookup | Look up format properties from format ID table |
| 00500f3c | F_7FieldInitializer | Initialize a new 84-byte surface sub-object (sets defaults) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new surface sub-object |

**Guard conditions:** If a3 < 4 → return error. If DDS magic != 0x44445320 ("DDS ") → return error. If remaining size < 0x7C → return error. If pixel format flags (a2+112) != 0 and != 0xFC00 → return error. If format table entry not found → return error. If remaining buffer insufficient for mip data → return error.
