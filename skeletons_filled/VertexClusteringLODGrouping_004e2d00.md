## VertexClusteringLODGrouping_004e2d00 — VertexLODClusteringUpdate

**Summary:** Groups scene-graph vertices into 4 LOD clusters by spatial proximity to 4 reference positions. Finds nearest cluster center per vertex, allocates per-cluster arrays, stores vertex positions with normals and LOD distance weights. Scene LOD/culling preparation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x150 | R | — | 4 reference cluster positions (stride 296 = 74 floats) |
| this | 0x1F4 | RW | 0 | per-cluster vertex count, zeroed at start |
| this | 0x1F8 | RW | — | per-cluster array pointer, set during init |
| this | 0x890 | R | — | scene graph node pointer, checked for non-null |
| this | 0x8E4 | RW | 0 | found child node pointer, set if vertex count matches |

**Written-by note (persistence):**
- this 0x1F4: zeroed each call; external poke survives
- this 0x1F8: written per call with new allocation; external poke overwritten
- this 0x8E4: set each call; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ad15c | flt_5AD15C | R | WheelOffsetThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c210 | SceneGraphChildCount | get number of child nodes |
| 0054c230 | LinkedListIndexedAccessor_c230 | retrieve child node by index |
| 0054e100 | PackedArrayTotalSize | get total element count in packed vertex array |
| 0054e120 | PackedArrayIndexLookup | retrieve vertex element by index |
| 00587c03 | OperatorNewNhMallocWrapper | allocate per-cluster memory arrays |

**Guard conditions:** If this[548] (offset 0x890, scene graph ptr) is non-null, process children to find matching vertex node. If this[569] (offset 0x8E4, found node) is non-null, process vertex clustering.
