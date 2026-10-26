## CollisionGridRaycast32x32_0044ba40 — CollisionGrid32x32QueryBuilder

**Summary:** Subdivides collision grid into 32×32 cells, computes each cell's world-space bounding box from grid center and scale parameters, queries collision data per cell via sub_44A880, and stores the returned pointers in a flat 1024-element output array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTrackFileLoader (0044c0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Pointer to collision grid data for sub_44A880 queries; null-checked for early return |
| this | 0x8 | R | — | Center X coordinate of grid (double) used to offset cell bounding boxes |
| this | 0x10 | R | — | Scale factor X (double) — inverse of half-extent; used to compute reciprocal cell size |
| this | 0x18 | R | — | Center Z coordinate of grid (double) used to offset cell bounding boxes |
| this | 0x20 | R | — | Scale factor Z (double) — inverse of half-extent; used to compute reciprocal cell size |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044a880 | sub_44A880 | Queries collision grid for data within a float bounding box (4 floats: x1, x2, z1, z2); returns result pointer |

**Guard conditions:** 
1. `*(this+4) != NULL` — PASS: valid grid pointer, iterate all 32×32 cells. BLOCKED: null, return immediately.
2. `*(this+16) == 0.0` (scale X) — PASS: zero scale, use zero cell stride for X. BLOCKED: compute reciprocal stride as 1.0/scaleX.
3. `*(this+32) == 0.0` (scale Z) — PASS: zero scale, use zero cell stride for Z. BLOCKED: compute reciprocal stride as 1.0/scaleZ.
