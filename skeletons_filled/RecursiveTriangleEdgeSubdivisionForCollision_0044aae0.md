## RecursiveTriangleEdgeSubdivisionForCollision_0044aae0 — Recursive triangle edge subdivision for collision mesh

**Summary:** Recursively subdivides a triangle whose edges exceed a squared-length threshold (22500.0). Identifies the longest edge, splits it at the midpoint via WeightedAverageInterpolation, and recurses on the two resulting triangles. Terminates when all edges are short enough, emitting the triangle via TriangleMeshAdjacencyBuilder.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationPlaybackSequence (0044acb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ef38 | dbl_59EF38 | R | TriangleSubdivisionThreshold [DERIVED] (also: ` — double, subdivision threshold (max edge length) — 22500.0 squared-length threshold for edge subdivision |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448480 | WeightedAverageInterpolation | Computes edge midpoint for subdivision |
| 004484c0 | Vec3Subtract | Subtracts two 3D vectors to compute edge vector |
| 004484f0 | EmptyFunction | Computes squared magnitude of edge vector (used as edge-length-squared test) |
| 004493a0 | TriangleMeshAdjacencyBuilder | Emits final triangle after all edges are below threshold |
| 0044aae0 | RecursiveTriangleEdgeSubdivisionForCollision | Recursive self-call for subdivided triangle halves |

**Guard conditions:** Edge squared length < 22500.0 → no split on that edge. Longest edge determines split axis: only the longest edge exceeding threshold triggers subdivision.
