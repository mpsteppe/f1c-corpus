## BezierPatchTessellation_0044b370 — BezierPatchCollisionTessellator

**Summary:** Tessellates Bezier patch control points into collision triangle mesh adjacency; computes surface-fit coefficients, determines axis permutation from proximity tests, and builds final collision output with permuted/transformed vertex coordinates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionGeometryOperationSelector (0044bb60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0044b8f4 | jpt_44B6EC | R | Jump table for switch(permutation_index) dispatching axis permutation cases 0-4 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448ee0 | RGBColorPacking | Packs patch index/color identifier for adjacency builder indexing |
| 004492b0 | CollisionShapeInit | Initializes collision shape structure for tessellation pipeline |
| 004492d0 | CollisionContactBufferAllocator | Allocates contact/adjacency buffer with given element count |
| 00449340 | PhysicsBufferFree | Frees physics pipeline buffer memory |
| 004493a0 | TriangleMeshAdjacencyBuilder | Builds triangle mesh adjacency data for collision pipeline (takes vertex data and color) |
| 00449700 | CollisionContactResponse | Computes collision contact response from adjacency data |
| 00449a80 | HATPolygonSurfaceFit | Fits surface coefficients (HAT = height above terrain) for a polygon patch |
| 0044af20 | CollisionFaceVerticesGather | Extracts six coordinate values from three triangle vertex sources |
| 0044af60 | AxisPermutationMatrixRead | Reads/constructs axis permutation matrix for indexed edge direction |
| 0044b040 | CollisionCapsuleShapeCopyToPipeline | Copies capsule collision shape data into pipeline processing buffer |
| 0044b110 | sub_44B110 | Selects axis permutation index based on triangle edge proximity tests against capsule shape |
| 00587bcf | FreeWrapper_7bcf | Wrapper around memory deallocation (free) |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation wrapper around new/malloc |

**Guard conditions:** 
1. `v64 > 0` (patch count) — PASS: at least one patch, enter first build loop. BLOCKED: no patches, skip.
2. `v3 > 0` (result count) — PASS: process surface fit and axis selection. BLOCKED: skip second phase.
3. `v64 > 0` (patches remain) — PASS: enter vertex adjustment phase. BLOCKED: skip.
4. `*v20 != 0` (permutation index non-zero) — PASS: process vertex position adjustments for this patch. BLOCKED: zero, skip patch.
5. `*v20 != v24 + 1` (edge index not equal to permutation) — PASS: adjust vertex at this edge. BLOCKED: edge matches permutation, skip.
6. `v3 > 0` (output patches) — PASS: enter final adjacency builder loop. BLOCKED: skip.
7. Switch on `*v30` (permutation index): 0→standard builder, 1-3→axis permuted builder, 4→direct face gather builder, default→do nothing.
