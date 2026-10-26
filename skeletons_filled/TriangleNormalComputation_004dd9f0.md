## TriangleNormalComputation_004dd9f0 — ComputeTriangleNormal

**Summary:** Computes normalized face normal from three triangle vertices via cross product. Returns 0 on success, -1 for degenerate (zero-area) triangle. Used in collision/geometry processing.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AnimationPlaybackSequence (0044acb0), sub_4DE610 (004de610), sub_4DF110 (004df110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First vertex X component |
| this | 0x4 | R | — | First vertex Y component |
| this | 0x8 | R | — | First vertex Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks squared length of cross product (v6*v6 + v16*v16 + v5*v5) <= 0.0. If true (degenerate triangle), returns -1 and writes (1.0, 0.0, 0.0) as normal. If false (valid triangle), normalizes cross product and returns 0.
