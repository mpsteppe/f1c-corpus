## RayPlaneIntersect_0050e491 — Ray-plane intersection test

**Summary:** Computes intersection point between a ray (defined by origin `a3` and target point `a4`) and plane `a2` (normal + negated distance). Returns output point in `a1` if intersection is valid, or NULL if ray is parallel or t-value fails validation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Intersection point X |
| this | 0x4 | RW | — | Intersection point Y |
| this | 0x8 | RW | — | Intersection point Z |

**Written-by note (persistence):**
- this 0x0: conditional write (only on valid intersection) — external poke survives if no intersection
- this 0x4: conditional write (only on valid intersection) — external poke survives if no intersection
- this 0x8: conditional write (only on valid intersection) — external poke survives if no intersection

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a88f | ArithmeticComparison_a88f | Validates computed t-value (likely range check 0..1 or near-zero) |

**Guard conditions:** If `n·O - n·P == 0.0` (ray is parallel to plane, denominator zero), return NULL (no intersection). If `ArithmeticComparison_a88f` returns false for the computed t-value `v7` (out of valid range, e.g. not in [0,1] for segment), return NULL. Otherwise write intersection point `O + t*(P-O)` to `a1`.
