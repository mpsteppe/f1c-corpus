## ShadowVolumeExtrusion_00448730 — shadow volume extrusion computation

**Summary:** Computes shadow volume extrusion offset for collision geometry. Reads triangle faces from an array at this+0x1C, detects silhouette edges relative to light, accumulates extrusion factor, writes clamped result to this+0x10.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionTreeTraversal (00448da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x0 | R | — | triangle vertex 0 pointer |
| *(*(this+0x1C)+0x0) | 0x8 | R | — | triangle vertex 0 coordinate element |
| *(*(this+0x1C)+0x0) | 0xC | R | — | triangle vertex 0 Z coordinate |
| *(this+0x1C) | 0x0 | R | — | triangle entry: vertex 0 pointer |
| *(this+0x1C) | 0x4 | R | — | triangle entry: vertex 1 pointer |
| *(this+0x1C) | 0x8 | R | — | triangle entry: vertex 2 pointer |
| *(this+0x1C) | 0xC | R | — | triangle entry: face normal or edge data |
| *(this+0x1C) | 0x10 | R | — | triangle entry: edge/adjacency data |
| *(this+0x1C) | 0x14 | R | — | triangle entry: additional vertex/edge reference |
| *(this+0x1C) | 0x18 | R | — | triangle entry: flags or index |
| *(this+0x1C) | 0x19 | R | — | triangle entry: per-face flag (0xFF sentinel used) |
| *(this+0x1C) | 0x1A | R | — | triangle entry: per-face small field |
| *(this+0x1C) | 0x1C | R | — | triangle entry: 16-bit value accessed as unsigned short at offset 13 |
| this | 0x0 | R | — | base position X (float) |
| this | 0x4 | R | — | base position Y (treated as double in subtraction) |
| this | 0xC | R | — | base position Z (float) |
| this | 0x10 | RW | — | extrusion offset: written with computed clamped value |
| this | 0x18 | R | — | element count / type selector: must be 2..11 inclusive |
| this | 0x1C | R | — | pointer to array of triangle entries |

**Written-by note (persistence):**
- this 0x10: written once per call (computed extrusion); may be overwritten by subsequent calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00448d80 | jpt_44890C | R | jump table for switch on triangle edge index |
| 0059e420 | dbl_59E420 | R | 1.0 constant for vector normalization divisor |
| 0059e430 | dbl_59E430 | R | ~0.0 zero sentinel for comparison |
| 0059e830 | dbl_59E830 | R | dot product comparison threshold (0.7) |
| 0059e880 | dbl_59E880 | R | lower threshold constant |
| 0059ec60 | dbl_59EC60 | R | suspension travel offset |
| 0059ef18 | dbl_59EF18 | R | transform math constant |
| 0059ef20 | dbl_59EF20 | R | vertex transform constant |
| 0059ef28 | dbl_59EF28 | R | vehicle dynamics double constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Early return if this[0x18] (type/count) is not in {2..11}. Inner guard: silhouette edge test passes only if face normal component ratio >= 0.7. Extrusion accumulation guard: only when the two test vectors have opposite sign (one >0, one <0). Final clamp: if accumulated extrusion exceeds 0.025, write 0.025 fixed value; if below -0.025, clamp to -0.025.
