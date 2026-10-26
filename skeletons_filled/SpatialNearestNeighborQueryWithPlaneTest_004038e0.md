## SpatialNearestNeighborQueryWithPlaneTest_004038e0 — Nearest-strut query with plane rejection

**Summary:** Scans all active suspension struts to find the one nearest to a query point, with optional strut-type filtering. After locating the closest strut, applies a plane-normal / height test to decide whether to return the strut pointer itself or redirect to its linked collision child node.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SpatialTreeNearestNeighborSearch (00403aa0), SurfaceHeightfieldCollisionCallback (00404250), MemoryAllocation (004046b0), sub_426430 (00426430), Steward_Init (004d38f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | number of struts to iterate during nearest-neighbor scan |
| this | 0x134 | R | — | base pointer to strut data array |
| this | 0x1C8 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x1CC | R | — | unknown — not directly referenced in decompiled C |
| this | 0x1D0 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x1D8 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x1E0 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x244 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x260 | R | — | unknown — not directly referenced in decompiled C |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:** none

**Guard conditions:** (1) If `this->count (0x130)` > 0, PASS — strut scanning loop executes; if <= 0, BLOCKED — returns 0 immediately. (2) Per-strut filter: distance from query point to strut position must be < current best squared distance AND parameter `a3` must be either -1 (no filter) or match strut field at offset 0x12C (strut type ID). (3) Plane test on result: if closest strut is found AND `plane_normal_z * (strut_pos_z - query_z) + plane_normal_x * (strut_pos_x - query_x) < 0`, return the linked child node at strut+0x110 instead of the strut pointer itself.
