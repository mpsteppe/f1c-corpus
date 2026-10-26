## sub_4DD7C0_004dd7c0 — SceneGraphMaxDotProductFinder

**Summary:** Computes the vertex in a scene graph with maximum dot product against direction vector a2. Iterates children, filters by LOD level, extracts vertices via PackedArray, evaluates dot product of each vertex with the direction, and returns the coordinates of the extreme point in a3.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | input direction vector X component |
| this | 0x4 | R | — | input direction vector Y component |
| this | 0x8 | R | — | input direction vector Z component |

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

**Guard conditions:** If LOD level (v9) < threshold (v17), skips that child's vertices. Output a3 initialized to (0,0,0); only updated when dot product exceeds current best.
