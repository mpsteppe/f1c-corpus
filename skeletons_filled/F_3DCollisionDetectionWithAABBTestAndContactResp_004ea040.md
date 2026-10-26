## F_3DCollisionDetectionWithAABBTestAndContactResp_004ea040 — VehicleCollisionDetectionAABBAndContactResponse

**Summary:** Per-vehicle 3D collision detection: transforms contact point to vehicle-local space, performs AABB overlap test against vehicle bounds, iterates collision geometry vertices to find closest penetrating point, computes contact normal and penetration depth, and outputs collision response data (contact point, normal, force direction).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SwitchBasedStateHandler (0040f380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x72C | R | — | vehicle AABB minimum X bound (body collision box) |
| this | 0x730 | R | — | vehicle AABB minimum Y bound |
| this | 0x734 | R | — | vehicle AABB minimum Z bound |
| this | 0x744 | R | — | coordinatesInTrack.x (replay) [CONFIRMED] |
| this | 0x748 | R | — | vehicle AABB maximum X bound |
| this | 0x74C | R | — | coordinatesInTrack.y (replay) [CONFIRMED] |
| this | 0x750 | R | — | vehicle AABB maximum Y bound |
| this | 0x754 | R | — | vehicle AABB maximum Z bound |
| this | 0x758 | R | — | vehicle AABB center / offset reference |
| this | 0x34B0 | R | — | vehicle orientation matrix [0][0] (X-axis world X component) |
| this | 0x34B4 | R | — | vehicle orientation matrix [0][1] (X-axis world Y component) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | vehicle orientation matrix [1][0] (Y-axis world X component) |
| this | 0x34C0 | R | — | vehicle orientation matrix [1][1] (Y-axis world Y component) |
| this | 0x34C4 | R | — | vehicle orientation matrix [1][2] (Y-axis world Z component) |
| this | 0x34C8 | R | — | vehicle orientation matrix [2][0] (Z-axis world X component) |
| this | 0x34CC | R | — | vehicle orientation matrix [2][1] (Z-axis world Y component) |
| this | 0x34D0 | R | — | vehicle orientation matrix [2][2] (Z-axis world Z component) |
| this | 0x34D4 | R | — | vehicle world position X |
| this | 0x34D8 | R | — | vehicle world position Y |
| this | 0x34DC | R | — | vehicle world position Z |
| this | 0x3B70 | R | — | collision penetration depth threshold / cushion radius |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ea010 | ArithmeticComparison_a010 | allocate and initialize a collision response / contact data struct |
| 004ea930 | sub_4EA930 | fetch vehicle projected collision geometry vertex position |
| 004ed420 | VehicleGeometryProximityTest | compute closest approach distance between two geometry surfaces |
| 0054c230 | LinkedListIndexedAccessor_c230 | access linked list of collision geometry data by index |
| 0054e100 | PackedArrayTotalSize | get total count of entries in packed collision geometry array |
| 0054e120 | PackedArrayIndexLookup | retrieve collision geometry vertex by index from packed array |
| 005694e0 | VehicleProjectedPosition | project a 3D position onto collision plane from origin and normal |

**Guard conditions:** none — function body is a single AABB overlap check branching into vertex-level penetration test; no early-return guards based on fixed field values.
