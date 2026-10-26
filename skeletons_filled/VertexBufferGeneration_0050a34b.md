## VertexBufferGeneration_0050a34b — Short2DToFloatRGBAVertexDecoder

**Summary:** Decompresses signed 16-bit vertex position data (two int16 values packed in 4 bytes per vertex) to 32-bit float RGBA format (XY positions, Z=0.0, alpha=1.0), under DirectX vertex/texture system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | flag to enable post-processing step |
| this | 0x18 | R | — | pointer to source vertex data |
| this | 0x1050 | R | — | source row pitch (bytes per row) |
| this | 0x1054 | R | — | source slice stride (rows per image) |
| this | 0x1058 | R | — | number of vertices/elements to decode |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e780 | flt_59E780 | R | VertexScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00507845 | ContactManifoldCleanup | post-process decoded float RGBA buffer (likely alpha blend or edge fix) |

**Guard conditions:** If this[4] (offset +0x10 flag) is non-zero, calls ContactManifoldCleanup on the decoded output; if zero, skips post-processing.
