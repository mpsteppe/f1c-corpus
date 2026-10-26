## AABBOverlapTest_004915a0 — AABBContainmentCheck

**Summary:** Tests if the `this` AABB (x1, y1, width, height) is fully contained within boundary AABB (a2, a3, a4, a5). Requires top-left corner inside boundary AND bottom-right corner not exceeding boundary edges.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_490D00 (00490d00), CollisionBroadphaseTraversal (00491170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | AABB x1 (tested: >= a2 && < a2+a4) |
| this | 0x2 | R | — | AABB y1 (tested: >= a3 && < a3+a5) |
| this | 0x4 | R | — | AABB width (used to compute x2 = x1 + w, tested: <= a2+a4) |
| this | 0x6 | R | — | AABB height (used to compute y2 = y1 + h, tested: <= a3+a5) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `*this` (x1) is NOT >= a2 OR NOT < a2+a4 → return 0 (no containment). If `this[1]` (y1) passes x-check but fails y-check (NOT >= a3 OR NOT < a3+a5) → return 0. Final check: x1+width <= a2+a4 AND y1+height <= a3+a5.
