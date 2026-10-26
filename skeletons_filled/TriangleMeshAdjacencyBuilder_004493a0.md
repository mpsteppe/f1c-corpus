## TriangleMeshAdjacencyBuilder_004493a0 — Triangle mesh adjacency builder with BVH spatial insertion

**Summary:** Builds adjacency data for a triangle mesh collision shape. Allocates/reallocates triangle body buffer, inserts vertices into spatial (BVH) trees, discovers shared edges between adjacent triangles, and stores edge adjacency pointers. Handles weighted edge midpoint interpolation and optionally copies edge flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RecursiveTriangleEdgeSubdivisionForCollision (0044aae0), BezierPatchTessellation (0044b370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of triangle entries currently stored in buffer |
| this | 0x4 | RW | — | Capacity/end pointer of allocated triangle buffer |
| this | 0x8 | RW | — | Pointer to triangle body array (AABB collision bodies) |
| this | 0xC | RW | — | First BVH tree root pointer (lazy-allocated) |
| this | 0x10 | RW | — | Second BVH tree root pointer (lazy-allocated) |

**Written-by note (persistence):**
- this 0x4: Written on reallocation (incremented by 0x2000)
- this 0x8: Written on reallocation (updated to new buffer address)
- this 0xC: Written once on first use (allocated and initialized via QuaternionRotationStructureInitialize)
- this 0x10: Written once on first use (allocated and initialized)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448480 | WeightedAverageInterpolation | Computes edge midpoint via weighted average for triangle edge subdivision |
| 00448510 | QuaternionRotationStructureInitialize | Initializes a quaternion rotation structure with given vertices |
| 004485d0 | SpatialTreeInsertion | Inserts a vertex into the spatial (BVH) tree for collision queries |
| 00448e50 | DynamicsBVHNodeRecursiveTraversal | Traverses and cleans up BVH tree nodes during reallocation |
| 00448e90 | AABBCollisionBodyInitializer | Initializes each AABB body slot during buffer reallocation |
| 00448ec0 | SmallStructCopy | Copies 3-byte type+handle pair into collision body entry |
| 00587bcf | FreeWrapper_7bcf | Frees old triangle buffer during reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | Heap allocation for triangle body array and BVH tree nodes |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Count of stored triangles — reallocation copy loop guard |

**Guard interpretation:** this[0] (count) > 0 → old entries are copied to new buffer during reallocation. this[0] >= this[1] (capacity) → triggers full buffer reallocation (grow by 0x2000 slots). Null checks on this[3] and this[4] trigger lazy allocation of BVH trees.
