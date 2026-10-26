## BoundingBoxComputation_004dd550 — SceneGraphBoundingBoxComputer

**Summary:** Computes 3D axis-aligned bounding box (min/max X,Y,Z) of a scene graph node. Initializes min to +FLT_MAX and max to -FLT_MAX, iterates scene graph children, filters by LOD level, extracts vertex data via PackedArray, and records extents. Returns child count.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioPhysicsMixWithLerp (0040e2b0), LightFrustumClosestPoint (0040e480), sub_40EA30 (0040ea30), sub_40ED10 (0040ed10), CameraViewSetupFromVehiclePosition (0045af50), Camera (004a3b50), SceneExtentComputation (004bdc10), ParticleCollisionSpawn (004c9fb0), sub_4D0110 (004d0110), BoundingBoxUpdate (004dd6a0), VehicleGraphicsSceneLoader (004dfce0), PhysicsAudioVectorUpdate (004e2ad0), sub_4FBA10 (004fba10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output min X coordinate of bounding box |
| this | 0x4 | RW | — | output min Y coordinate of bounding box |
| this | 0x8 | RW | — | output min Z coordinate of bounding box |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd4e0 | sub_4DD4E0 | computes LOD level threshold for the scene graph node |
| 0054c210 | SceneGraphChildCount | returns number of child nodes in the scene graph |
| 0054c230 | LinkedListIndexedAccessor_c230 | indexed access into scene graph child linked list |
| 0054e100 | PackedArrayTotalSize | returns total vertex count in packed array |
| 0054e120 | PackedArrayIndexLookup | retrieves vertex data by index from packed array |

**Guard conditions:** If LOD level (v10) < threshold (v13), skips that child's vertices. For each vertex, tracks running min/max across X, Y, Z.
