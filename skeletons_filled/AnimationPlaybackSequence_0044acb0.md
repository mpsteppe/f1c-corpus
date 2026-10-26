## AnimationPlaybackSequence_0044acb0 — AnimationDrivenCollisionMeshUpdater

**Summary:** Iterates audio network node hierarchy and scene graph to find animation-matched meshes, then generates collision geometry via recursive triangle edge subdivision for triangles passing normal and area checks.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionGeometryOperationSelector (0044bb60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044aae0 | RecursiveTriangleEdgeSubdivisionForCollision | Performs recursive edge subdivision on triangle for collision mesh generation |
| 004ce860 | StringListLookup | Looks up string in list, returns index/cached identifier |
| 004ce8d0 | IndexedArrayAccess | Accesses array entry by string-list index to retrieve animation metadata |
| 004dd9f0 | TriangleNormalComputation | Computes triangle normal from vertex transform data |
| 005452f0 | AudioNetworkNodeCount | Returns count of nodes in audio/animation network |
| 00545340 | LinkedListNodeFinder | Retrieves node from linked list by index |
| 00547370 | ArithmeticComparison_7370 | Computes arithmetic comparison on float data in v37 buffer |
| 0054c210 | SceneGraphChildCount | Returns child count for a scene graph node |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses scene graph child by index from linked list |
| 0054e190 | CameraDistanceGetter | Returns count of camera-distance entries (LOD steps or view-dependent indices) |
| 0054e1a0 | IndexedTransformRead | Reads transformation matrix/vertex data by camera-distance index |
| 0054e240 | ArrayIndexRead | Reads array index value by position |

**Guard conditions:** 
1. `AudioNetworkNodeCount(a2) > 0` — PASS: at least one node to iterate; BLOCKED: zero nodes, skip entire function.
2. `SceneGraphChildCount(v24) > 0` — PASS: node has children to process; BLOCKED: no children, skip node.
3. `*(v6 + 20) & 0x100 == 0x100` — PASS: child has flag 0x100 set (animation/collision-relevant); BLOCKED: flag not set, skip child entirely.
4. `CameraDistanceGetter(v6) > 0` — PASS: at least one camera-distance entry; BLOCKED: none, skip child.
5. `v9 != NULL` (IndexedArrayAccess result) — PASS: valid animation data entry found; BLOCKED: null, skip triangle subdivision.
6. `*(float*)(v9+8) != 0.0` — PASS: animation playback speed/value at offset 8 is non-zero; BLOCKED: zero, skip.
7. `!TriangleNormalComputation(v30, v31) && v32 >= 0.001` — PASS: normal computation returns 0 AND triangle area/dot-product >= 0.001; BLOCKED: normal returned non-zero OR value < 0.001.
