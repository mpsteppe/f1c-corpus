## PhysicsAudioVectorUpdate_004e2ad0 — PhysicsAudioCenterUpdate

**Summary:** Centers physics/audio vertex data around bounding box midpoint. Computes bounding box for objects a1 and a2, derives center, adjusts all child vertex positions by subtracting center offset, recalculates bounding boxes, and updates audio position references. Audio-physics geometry integration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleGraphicsSceneLoader (004dfce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | compute min/max bounding box from object |
| 0054b3b0 | ThreeFieldSetterWithSubCall | set three float fields and call subsidiary function |
| 0054b420 | TripleFieldQuery | query three float values (position offset) |
| 0054c210 | SceneGraphChildCount | get number of child nodes in scene graph |
| 0054c230 | LinkedListIndexedAccessor_c230 | retrieve child node by index |
| 0054d080 | sub_54D080 | unknown — post-process after bounding box recompute |
| 0054d520 | F_3DBoundingBoxExtentsComputation | compute 3D bounding box extents |
| 0054e100 | PackedArrayTotalSize | get total element count in packed vertex array |
| 0054e120 | PackedArrayIndexLookup | retrieve vertex element by index |
| 0054e270 | BoundingBoxComputationFromVertexData | recompute bounding box from raw vertex positions |

**Guard conditions:** If a1 is non-null, process; if null, skip entirely.
