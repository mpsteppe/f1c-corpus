## QuadraticSurfaceCollisionTest_0044a070 — QuadraticSurfaceCollisionTest

**Summary:** Tests a ray/query against a quadratic surface defined by six double coefficients (conic equation). Performs 3-axis slab culling test, evaluates surface equation at intersection point, and updates query with nearest hit if closer than previous. Part of collision detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** BVHTreeTraversal (0044aa30), SpatialGridQuery (0044c4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Quadratic coefficient A (x*x term) |
| this | 0x8 | R | — | Quadratic coefficient B (x*z term) |
| this | 0x10 | R | — | Quadratic coefficient C (z*z term) |
| this | 0x18 | R | — | Linear coefficient D (x term) |
| this | 0x20 | R | — | Linear coefficient E (z term) |
| this | 0x28 | R | — | Constant term F |
| this | 0x34 | R | — | Slab min bound for axis 2 |
| this | 0x38 | R | — | Slab max bound for axis 2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Three sequential slab axis tests: if (ray.x * slab.normal.x + ray.z * slab.normal.z) < slab.min for any axis, return 0 (no hit). Then: if residual > query.max_dist, return 0; if |residual| >= query.min_dist, return 0. PASSES only if all slab tests pass AND residual magnitude is within [min_dist, max_dist].
