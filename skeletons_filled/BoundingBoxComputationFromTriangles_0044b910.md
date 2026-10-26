## BoundingBoxComputationFromTriangles_0044b910 — TriangleBoundingBoxCompute

**Summary:** Scans triangle vertex data to compute 2D axis-aligned bounding box (XZ plane), then stores center coordinates and inverse-half-extent scale factors for use in collision spatial subdivision/indexing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTrackFileLoader (0044c0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Center X coordinate of bounding box in XZ plane (midpoint of X range) |
| this | 0x10 | RW | 0 | Lower 32 bits of X scale factor (inverse of half-extent), zero if X range is zero |
| this | 0x14 | RW | 0 | Upper 32 bits of X scale factor (inverse of half-extent), zero if X range is zero |
| this | 0x18 | RW | — | Center Z coordinate of bounding box in XZ plane (midpoint of Z range) |
| this | 0x20 | RW | 0 | Lower 32 bits of Z scale factor (inverse of half-extent), zero if Z range is zero |
| this | 0x24 | RW | 0 | Upper 32 bits of Z scale factor (inverse of half-extent), zero if Z range is zero |

**Written-by note (persistence):**
- this 0x8: computed from vertex data every call — no persistence
- this 0x10: computed every call (either zero or reciprocal) — no persistence
- this 0x14: computed every call — no persistence
- this 0x18: computed from vertex data every call — no persistence
- this 0x20: computed every call — no persistence
- this 0x24: computed every call — no persistence

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ef30 | flt_59EF30 | R | MinusFLT_MAX [DERIVED] (also: ` — -FLT_MAX) |
| 0059ef48 | dbl_59EF48 | R | BoundingBoxExtentScale [DERIVED] (also: ` — extent scale factor) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
1. `*a2 > 0` (triangle count) — PASS: at least one triangle, scan all vertices for min/max. BLOCKED: zero triangles, skip scan (center set to 0, scale set to 0).
2. `(max_x - min_x) * 0.03125 == 0.0` (X extent zero) — PASS: write zero double at offsets 0x10-0x17. BLOCKED: write reciprocal at offsets 0x10-0x17.
3. `(max_z - min_z) * 0.03125 == 0.0` (Z extent zero) — PASS: write zero double at offsets 0x20-0x27. BLOCKED: write reciprocal at offsets 0x20-0x27.
