## PackedArrayTotalSize_0054e100 — Packed array total size accumulation

**Summary:** Sums a size/count field at offset +8 from each element in a packed array with 64-byte stride. Returns total.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), AudioPhysicsMixWithLerp (0040e2b0), LightFrustumClosestPoint (0040e480), ParticleCollisionSpawn (004c9fb0), BoundingBoxComputation (004dd550), sub_4DD7C0 (004dd7c0), MaxSquaredMagnitudeSearch (004dd8f0), sub_4DE610 (004de610), ColorAlphaUpdateFlagSet (004e21d0), PhysicsAudioVectorUpdate (004e2ad0), VertexClusteringLODGrouping (004e2d00), F_3DCollisionDetectionWithAABBTestAndContactResp (004ea040), CameraViewportRenderSetup (004fbd70), RenderColorUpdate (004fc170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x118 | R | — | Element count (number of array entries) |
| this | 0x11C | R | — | Base pointer to packed array |
| this | 0x124 | R | — | Element stride (64 bytes between entries) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x118]` (element count) ≤ 0 → return 0. Passes when count > 0.
