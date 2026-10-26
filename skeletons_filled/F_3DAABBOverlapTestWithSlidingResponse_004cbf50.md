## F_3DAABBOverlapTestWithSlidingResponse_004cbf50 — OBBOverlapSlidingResponse

**Summary:** Tests line segment (a1→a2) against an oriented bounding box (a3) for overlap. Transforms both endpoints into the box's local coordinate frame using its orientation matrix, checks AABB interval overlap on all three axes, and slides the target point (a2) to the box surface on collision. Used by particle physics collision.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParticleEffectPhysics (004ccb30), ParticleSystemUpdateWithWindAndDamping (004cd220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Source point X (a1[0]) — read for local-space transform, NOT updated |
| this | 0x4 | R | — | Source point Y (a1[1]) — read for local-space transform, NOT updated |
| this | 0x8 | R | — | Source point Z (a1[2]) — read for local-space transform, NOT updated |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks all three axes for interval overlap between transformed local positions and the box's min/max extents. Only proceeds to adjust target if overlap exists on every axis (full intersection).
