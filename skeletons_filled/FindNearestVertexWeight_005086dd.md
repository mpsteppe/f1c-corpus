## FindNearestVertexWeight_005086dd — NearestNeighborWeightSearch

**Summary:** For each input vertex, searches a 256-entry 4-component weight table (squared Euclidean distance) and writes the nearest match index as a byte.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Output buffer stride — byte stride for output index buffer |
| this | 0x38 | R | — | Weight table base pointer — 256 entries of 4 floats each (starting at this+14 float offset) |
| this | 0x3C | R | — | Unknown — part of weight table area or adjacent field |
| this | 0x1048 | R | — | Format conversion flag — if non-zero, calls DirectXVertexBufferFormatConversion |
| this | 0x1050 | R | — | Stride for a2 dimension — byte stride for output indexing |
| this | 0x1054 | R | — | Stride for a3 dimension — byte stride for output indexing |
| this | 0x1058 | R | — | Vertex count — number of vertices to process (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | Transforms input vertex buffer format for compatibility |

**Guard conditions:** checks this[1042] (0x1048) — if non-zero, calls DirectXVertexBufferFormatConversion and uses the result as input buffer; otherwise uses original a4. If vertex count (this[1046]) is zero, outer loop body skipped entirely, returns vertex count (0).
