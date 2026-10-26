## SpatialGridQuery_0044c4c0 — SpatialGridQuery

**Summary:** Queries a 2D spatial grid (32x32 cells) for collision surfaces at a given position. Tests cached surface first, then maps world position to grid cell, looks up BVH tree for that cell, and traverses it. Part of collision detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleSuspensionForceCalculation (00401340), sub_402220 (00402220), CollisionContactGenerationAndFrictionResponse (00436870), sub_4423B0 (004423b0), CollisionNormalFromFeature (0044c550), Camera (004a3b50), SpecialFX_Init (004cf070), sub_4D0110 (004d0110), sub_4EE2D0 (004ee2d0), PhysicsFloatUpdateWithCompare (005000e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Grid origin X coordinate (double, at this[1]) |
| this | 0x10 | R | — | Inverse of grid cell size X (double, at this[2]) |
| this | 0x18 | R | — | Grid origin Z coordinate (double, at this[3]) |
| this | 0x20 | R | — | Inverse of grid cell size Z (double, at this[4]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044a070 | QuadraticSurfaceCollisionTest | Test cached surface at query position |
| 0044aa30 | BVHTreeTraversal | Traverse BVH tree from grid cell to find closest surface |

**Guard conditions:** Early return (no-op) if a2+48 holds a valid surface pointer that passes QuadraticSurfaceCollisionTest (hit already cached). Otherwise: compute grid cell indices (v9, v8) from world pos; BLOCK if either index >= 32 (out of grid bounds); BLOCK if no BVH pointer stored at grid cell (v6 == NULL). PASS only when grid cell is in range and has BVH data to traverse.
