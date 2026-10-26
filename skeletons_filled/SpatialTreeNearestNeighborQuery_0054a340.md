## SpatialTreeNearestNeighborQuery_0054a340 — Find nearest visible object to query point

**Summary:** Finds the nearest spatial object to a 3D query point that passes a 6-plane frustum visibility test. First attempts tree walk from spatial index (this+0x2A0), iterating child nodes via +0x10 child pointer and +0x14 sibling next. Falls back to linear walk of linked list (head at this+0x100, next at node+0x104) if tree unavailable. Computes squared distance from query point to each candidate's bounding sphere; if within radius and better than current best, tests against 6 frustum planes. Stores best result at this+0x1A4. Part of scene/audio spatial culling.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_556E70 (00556e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2A0)+0x10) | 0x7C | R | — | Tree child object bounding sphere center X |
| *(*(this+0x2A0)+0x10) | 0x80 | R | — | Tree child object bounding sphere center Y |
| *(*(this+0x2A0)+0x10) | 0x84 | R | — | Tree child object bounding sphere center Z |
| *(*(this+0x2A0)+0x10) | 0x8C | R | — | Tree child object frustum plane data start |
| *(*(this+0x2A0)+0x10) | 0x90 | R | — | Tree child object frustum plane data |
| *(*(this+0x2A0)+0x10) | 0x94 | R | — | Tree child object frustum plane data |
| *(this+0x2A0) | 0x10 | R | — | Pointer to tree child list head |
| *(this+0x2A0) | 0x14 | R | — | Next sibling pointer in tree child chain |
| *(this+0x204) | 0x104 | R | — | Next pointer in fallback linear list |
| this | 0x100 | R | — | Head of fallback linear linked list |
| this | 0x104 | R | — | Node next pointer in linked list walk |
| this | 0x118 | R | — | First inline node sphere radius (node at this+0x100) |
| this | 0x17C | R | — | First inline node sphere center X |
| this | 0x180 | R | — | First inline node sphere center Y |
| this | 0x184 | R | — | First inline node sphere center Z |
| this | 0x18C | R | — | First inline node frustum plane data start |
| this | 0x190 | R | — | First inline node frustum plane data |
| this | 0x194 | R | — | First inline node frustum plane data |
| this | 0x1A4 | RW | — | Tree root pointer / cached nearest neighbor result |
| this | 0x2A0 | R | — | Pointer to spatial index tree root structure |

**Written-by note (persistence):**
- this 0x1A4: written each call with best result (nearest visible node pointer) or 0 if none found

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[0x1A4]` (tree root / cached result) is null → skip tree walk and fall back to linear list. Tree walk child iteration: checks each child's bounding sphere distance against query point. Linear walk: skips nodes where flag at node+0x4 & 0x40 is set (bit 6 = hidden/disabled). Both paths: candidate PASSES if squared distance < sphere radius squared AND < current best, AND all 6 frustum planes pass (`dot(plane, sphere_center) >= 0` for each plane).
