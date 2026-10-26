## BVHNearestNeighborQuery_004039c0 — BVH chain nearest-neighbor traversal

**Summary:** Traverses a linked chain of physics nodes (BVH-style) to find the closest node to a query position. Computes squared distances between query point and each node position, accumulates path length along the chain, and terminates early when child distance exceeds current best (spatial culling) or cumulative path exceeds 200 units.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteering (004270a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | query position X component |
| this | 0x4 | R | — | query position Y component |
| this | 0x8 | R | — | query position Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e470 | flt_59E470 | R | TrackNodeSearchRadiusSq [DERIVED] |

**Functions called:** none

**Guard conditions:** (1) `a2` (start node) must be non-null — null BLOCKED (return null). (2) Node at offset 0x110 must have a linked child — null BLOCKED (return start node). (3) Cumulative path length `v16` (sum of `node+0x3C` values along chain) > 200.0 → BLOCKED (stop traversal). (4) Child squared distance >= current best squared distance → BLOCKED (BVH early-out, return current node). (5) If child has no further children at offset 0x110, return child immediately.
