## MaxSquaredMagnitudeSearch_004dd8f0 — FindMaxSquaredMagnitude

**Summary:** Iterates scene graph children, computes squared magnitude of 3D vectors from packed array, returns maximum value found. Part of LOD/geometry culling system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_40ED10 (0040ed10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd4e0 | sub_4DD4E0 | Gets minimum LOD/detail-level threshold from current object |
| 0054c210 | SceneGraphChildCount | Returns number of scene graph child nodes |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses a child node by index from linked list |
| 0054e100 | PackedArrayTotalSize | Returns element count of packed data array |
| 0054e120 | PackedArrayIndexLookup | Returns pointer to element at index in packed array |

**Guard conditions:** Checks `*(float *)(v3 + 244)` (lodDistance/nearFade). If 0.0, reads flags at offset 20; if bit 0x2000000 set, detail = 2 - ((bit 0x40)!=0); else detail = 4 - ((bit 0x40)!=0). If non-zero, detail = 0. Then checks detail >= threshold from sub_4DD4E0 — if false, skips child entirely. BLOCKED: children whose detail level < threshold.
