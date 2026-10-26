## VehicleSuspensionForceCalculation_00401340 — Wheel-ground suspension solver

**Summary:** Computes suspension contact forces between wheel collision geometry and ground surface using ray-sphere intersection tests. Iterates over suspension struts, queries spatial grid for collision features, and calculates response force components along contact normal with gravity compensation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SweptSuspensionCollisionDetection (00401910), PhysicsNodePropagationWithDistanceFalloff (00401c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | number of suspension struts to process (iterations count) |
| this | 0x134 | R | — | base index offset for indexed strut data access |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e438 | flt_59E438 | R | NormalizationHalf (~0.5f) [DERIVED] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401180 | RaySphereQuadraticIntersectionTest | computes ray-sphere penetration depth along suspension travel axis |
| 0044c4c0 | SpatialGridQuery | queries collision spatial grid for contact features near wheel position |
| 0044c550 | CollisionNormalFromFeature | extracts collision surface normal vector from contact feature data |

**Guard conditions:** Multiple nested checks control iteration and per-strut processing. (1) If `a2 != 0`, loop count = 1 (single-strut mode); if `a2 == 0`, loop count = `this[0x130/4]` (all struts) — values <= 0 skip entirely. (2) Pointer at strut+0x110 (v52) must be non-null — null BLOCKED (skip strut). (3) Pointer at strut+0x10C (v6) must be non-null — null BLOCKED. (4) SpatialGridQuery must return non-zero — zero BLOCKED (no contact found). (5) CollisionNormalFromFeature must return non-zero — zero BLOCKED. (6) Second SpatialGridQuery must return non-zero — zero BLOCKED. (7) Distance delta sqrt(...) != 0.0 — zero BLOCKED (no displacement). (8) Cross-product magnitude sqrt(...) != 0.0 — zero BLOCKED (degenerate contact normal).
