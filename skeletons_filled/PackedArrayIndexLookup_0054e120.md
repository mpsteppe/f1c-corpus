## PackedArrayIndexLookup_0054e120 — Packed array index-to-pointer lookup

**Summary:** Walks packed array elements (64-byte stride), accumulating per-element size fields to locate which element contains global index `a2`. Returns pointer to the sub-element at that index within the found element.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), AudioPhysicsMixWithLerp (0040e2b0), LightFrustumClosestPoint (0040e480), ParticleCollisionSpawn (004c9fb0), BoundingBoxComputation (004dd550), sub_4DD7C0 (004dd7c0), MaxSquaredMagnitudeSearch (004dd8f0), sub_4DE610 (004de610), ColorAlphaUpdateFlagSet (004e21d0), PhysicsAudioVectorUpdate (004e2ad0), VertexClusteringLODGrouping (004e2d00), F_3DCollisionDetectionWithAABBTestAndContactResp (004ea040), CameraViewportRenderSetup (004fbd70), RenderColorUpdate (004fc170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x118 | R | — | Element count (number of packed array entries) |
| this | 0x11C | R | — | Base pointer to packed array (stride 64 bytes) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x118]` (element count) ≤ 0 → return 0. If index `a2` not found within any element's cumulative range → return 0.
