## TwinFieldGetter_cf30_004dcf30 — Two-field getter (width and height)

**Summary:** Returns two object fields at offsets +0x14 (this[5]) and +0x18 (this[6]) via output pointers a2 and a3 if non-null; returns a3 as the function result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICursorSelectionRectangleRenderWithInterpolatio (0045b660), CollisionDamageDecayProcessor (0045b840), TextRenderDispatcher (004dd030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Width field (this[5]) — copied to *a2 |
| this | 0x18 | R | — | Height field (this[6]) — copied to *a3 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks both output pointers individually: if `a2` is null, skip writing field 0x14. If `a3` is null, skip writing field 0x18. Both guards are per-pointer (independent).
