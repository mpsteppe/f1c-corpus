## BoundingVolumeHierarchyTraversalFilter_00443af0 — BvhTraversalFilter

**Summary:** Filters bounding volume hierarchy traversal by checking distance thresholds against an input parameter. Returns TRUE if any relevant bounding volume extends beyond the test distance, FALSE if all checked volumes are within it. Three mode-dependent filter paths based on BVH mode state. Part of collision detection pruning.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3D0 | R | — | first bounding volume threshold |
| this | 0x834 | R | — | second bounding volume threshold |
| this | 0xC98 | R | — | third bounding volume threshold (default path) |
| this | 0x10FC | R | — | fourth bounding volume threshold (default path) |
| this | 0x1E14 | R | — | BVH traversal mode selector (1, 2, or other) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1E14 | != | 2 | BVH mode not 2 — use default filter path |
| this | 0x1E14 | == | 1 | BVH mode 1 — use first/second threshold pair |

**Guard interpretation:**
- Mode 1 (this+0x1E14 == 1): if threshold at +0x3D0 <= a2 OR threshold at +0x834 <= a2, return FALSE (BLOCKED — no volume extends beyond test distance). Otherwise fall through to LABEL_7.
- Mode 2 (this+0x1E14 == 2): if threshold at +0x3D0 <= a2, return FALSE. Otherwise return threshold at +0x834 > a2 (PASS if second volume extends beyond).
- Other modes (default): if threshold at +0xC98 <= a2, return FALSE. Otherwise return threshold at +0x10FC > a2 (PASS if fourth volume extends beyond).
