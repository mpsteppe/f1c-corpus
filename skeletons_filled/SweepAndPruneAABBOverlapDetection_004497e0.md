## SweepAndPruneAABBOverlapDetection_004497e0 — Sweep-and-prune AABB broad phase with SAT narrow phase

**Summary:** Broad-phase collision detection using sweep-and-prune on AABB projections. Computes min/max axis-aligned projections for each triangle, sorts them by left bound, sweeps for overlapping pairs, and validates each overlap with SATEdgeSeparationTest. Marks overlapping pairs at field offset 0x18.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionGeometryOperationSelector (0044bb60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of triangles in the collision batch |
| this | 0x8 | R | — | Pointer to triangle array (32-byte stride, 3 vertex pointers per triangle) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00448440 | sub_448440 | R | Comparator callback for sort — compares AABB left bound values |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004491c0 | SATEdgeSeparationTest | Narrow-phase SAT test for overlapping triangle pairs |
| 00587bcf | FreeWrapper_7bcf | Frees the temporary sort buffer after sweep completes |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates sort buffer (20 bytes per triangle for AABB projections) |
| 005890aa | sub_5890AA | Sort routine — sorts AABB projection array by left bound (offset 0) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Triangle count — skip allocation and sweep if zero |

**Guard interpretation:** this[0] (count) <= 0 → skip entire detection, return. Sort buffer allocation always performed if count > 0. During sweep: AABB right bound of current entry vs left bound of candidate — if right <= left, break inner loop (no further overlap possible due to sort order).
