## F_2DLineSegmentIntersection_00449000 — 2D line segment intersection test with endpoint tolerance

**Summary:** Tests whether two 2D line segments (defined by four points with 12-byte stride) intersect. Validates intersection parameters are strictly between 0 and 1 for both segments, and that contact is not at segment endpoints (within 0.001 skin thickness). Returns true on valid intersection.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SATEdgeSeparationTest (004491c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | X coordinate of vertex (stride 12 bytes = 3 floats) |
| this | 0xC | R | — | Y coordinate of vertex (3 floats after X) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) — constant 1.0 for normalization |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) — constant 0.0 for degenerate check |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) — 0.001 endpoint rejection threshold |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Segments sharing both endpoints → return false (reject). Vertical first segment (a1.x == a2.x) with vertical second segment (a3.x == a4.x) → return false (parallel vertical). After swap/assign: v12 == 0.0 (parallel) → return false. Intersection t-parameter v18 <= 0.0 or >= 1.0 → return false (no valid intersection along segment). Second segment u-parameter v14 <= 0.0 or >= 1.0 → return false. Contact distance from endpoint <= 0.001 or >= (segment_length - 0.001) → return false. Final check: v18 * v16 must be > 0.001 and < v16 - 0.001.
