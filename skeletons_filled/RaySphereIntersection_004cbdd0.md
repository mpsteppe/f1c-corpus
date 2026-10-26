## RaySphereIntersection_004cbdd0 — RaySphereIntersectionSliding

**Summary:** Performs a 3D ray-sphere intersection test with sliding collision response. Adjusts sphere position by restitution coefficient, checks distance threshold, and if intersection found, slides the ray origin (a1) to the contact point. Used by wheel and particle collision systems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WheelRenderObjectPerFrameUpdate (004cb860), ParticleInstanceUpdate (004cc1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Ray origin X coordinate (updated to intersection point X on hit) |
| this | 0x4 | RW | — | Ray origin Y coordinate (updated to intersection point Y on hit) |
| this | 0x8 | RW | — | Ray origin Z coordinate (updated to intersection point Z on hit) |

**Written-by note (persistence):**
- this 0x0: Updated to intersection X when collision detected. Otherwise unchanged.
- this 0x4: Updated to intersection Y when collision detected. Otherwise unchanged.
- this 0x8: Updated to intersection Z when collision detected. Otherwise unchanged.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005d3488 | dword_5D3488 | R | Collision_RestitutionCoeff [DERIVED] |
| 005d348c | flt_5D348C | R | CollisionPenetrationThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared distance from ray endpoint to adjusted sphere center against CollisionPenetrationThreshold — if exceeded, no intersection check. Checks discriminant > 0 for sphere intersection. Checks t-parameter > 0 for forward intersection.
