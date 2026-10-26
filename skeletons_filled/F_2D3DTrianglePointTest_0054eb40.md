## F_2D3DTrianglePointTest_0054eb40 — 2D/3D triangle point-in-triangle test

**Summary:** Tests whether a 3D point lies inside a triangle projected onto a 2D plane. Supports 6 projection modes (selector 0-5) choosing coordinate pair and winding direction, using cross-product edge tests.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_54EED0 (0054eed0), CollisionContactDetection (0054f2f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Triangle vertex 0 pointer (float3) |
| obj | 0x4 | R | — | Triangle vertex 1 pointer (float3) |
| obj | 0x8 | R | — | Triangle vertex 2 pointer (float3) |
| this | 0x0 | R | — | Test point X coordinate |
| this | 0x4 | R | — | Test point Y coordinate |
| this | 0x8 | R | — | Test point Z coordinate |
| this | 0xC | R | — | Reserved / unused in test |
| this | 0x10 | R | — | Reserved / unused in test |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0054ee74 | jpt_54EB4D | R | Jump table for selector dispatch (cases 0-5) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054ee90 | F_2DCrossProduct | 2D cross product helper for cases 4 and 5 |

**Guard conditions:** Return 0 (outside) immediately when any edge cross product has wrong sign for the selected projection. Return 1 (inside) only when all three edge tests pass. Default case (unhandled selector) returns 1 (inside).
