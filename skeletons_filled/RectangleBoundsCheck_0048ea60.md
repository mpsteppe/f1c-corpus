## RectangleBoundsCheck_0048ea60 — PointInRectHitTest

**Summary:** Hit-test: checks if point (a2, a3) lies within the axis-aligned rectangle defined by left (offset 0x14), top (offset 0x18), width (offset 0xC), and height (offset 0x10). Returns 1 if inside, 0 otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BoundsCheckWithPositionQuery (004773a0), UIWidgetProcessChildren (00490450), PanelMouseInteractionHandler (00490550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | rectangle width |
| this | 0x10 | R | — | rectangle height |
| this | 0x14 | R | — | rectangle left edge (x origin) |
| this | 0x18 | R | — | rectangle top edge (y origin) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- PASS: a2 > this[5] (offset 0x14) AND a2 < this[5] + this[3] (0x14 + 0xC) → x within bounds
- BLOCKED: x not within bounds → return 0
- PASS: a3 > this[6] (offset 0x18) AND a3 < this[6] + this[4] (0x18 + 0x10) → y within bounds
- BLOCKED: y not within bounds → return 0
- Both PASS → return 1
