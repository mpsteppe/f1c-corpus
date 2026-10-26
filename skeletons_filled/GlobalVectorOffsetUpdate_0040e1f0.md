## GlobalVectorOffsetUpdate_0040e1f0 — GlobalVectorOffsetUpdate

**Summary:** Iterates scene graph children and packed array vertices, subtracts a 3-component offset vector from each vertex, recomputes bounding boxes, and clears flags. Part of scene graph / mesh transform system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioPhysicsMixWithLerp (0040e2b0), VehicleSceneLoadAndPositionTires (004681b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Offset vector X component subtracted from each vertex |
| this | 0x4 | R | — | Offset vector Y component subtracted from each vertex |
| this | 0x8 | R | — | Offset vector Z component subtracted from each vertex |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054c210 | SceneGraphChildCount | Returns number of children in scene graph |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses linked list node by index |
| 0054d080 | sub_54D080 | Unknown post-processing after bounding box update |
| 0054d520 | F_3DBoundingBoxExtentsComputation | Computes 3D bounding box extents |
| 0054e100 | PackedArrayTotalSize | Returns total element count in packed array |
| 0054e120 | PackedArrayIndexLookup | Retrieves packed array element by index |
| 0054e270 | BoundingBoxComputationFromVertexData | Recomputes bounding box from vertex data |

**Guard conditions:** Scene graph must have at least one child → loop. Each child's packed array must have at least one element → inner loop. Both loops iterate from 0 to count-1.
