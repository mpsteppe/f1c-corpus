## CollisionContactResponse_00449700 — Collision contact pair processing with mass blending

**Summary:** Processes collision contact pairs after broad-phase detection. Traverses both collision trees (shadow volume extrusion), blends mass properties between contact pairs via weighted averaging, and propagates the blended mass through the physics tree. Calls weighted interpolation on each contact's vertex pairs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BezierPatchTessellation (0044b370), CollisionGeometryOperationSelector (0044bb60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of active contact pairs to process |
| this | 0x8 | R | — | Pointer to contact pair array (32-byte stride, 3 node pointers per pair) |
| this | 0xC | R | — | First collision tree root pointer |
| this | 0x10 | R | — | Second collision tree root pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) — 0.5 blend factor for mass lerp |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00448480 | WeightedAverageInterpolation | Computes weighted edge midpoint for contact pair vertices |
| 00448da0 | CollisionTreeTraversal | Traverses collision tree with shadow volume extrusion |
| 00448de0 | PhysicsTreeMassPropagation | Propagates blended mass values through physics tree |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Contact pair count — loops over pairs only when positive |

**Guard interpretation:** *this (count) > 0 → process all contact pair entries in the array. If this[3] (first tree) or this[4] (second tree) is null, skip traversal. If this[4] is non-null, propagate mass after processing.
