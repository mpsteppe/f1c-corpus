## RectangleClipping_00491350 — RectDifferenceClipping

**Summary:** Clips one rectangle (subject, from this[0..3]) against a boundary rectangle (a2..a5). Returns a linked list of rectangles representing the area of the subject that lies outside the boundary. Uses 3×3 spatial subdivision.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_490D00 (00490d00), CollisionBroadphaseBuilder (00490ee0), CollisionBroadphaseTraversal (00491170)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Subject rectangle x1 |
| this | 0x2 | R | — | Subject rectangle y1 |
| this | 0x4 | R | — | Subject rectangle width (x2 - x1) |
| this | 0x6 | R | — | Subject rectangle height (y2 - y1) |
| this | 0x8 | R | — | Metadata value stored at offset +8 of each output node |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490940 | ResourcePoolNodeAllocDealloc | Allocate pool node for each clipped output rectangle |

**Guard conditions:** None — the 3×3 grid loops always execute. Output list may be empty (return 0) if subject rect is entirely inside boundary (no cells pass the inside-subject AND outside-boundary test).
