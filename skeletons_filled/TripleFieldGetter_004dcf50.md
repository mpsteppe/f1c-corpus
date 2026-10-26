## TripleFieldGetter_004dcf50 — Three-field getter (X, Y, Z/size)

**Summary:** Returns three object fields at offsets +0x08 (X), +0x0C (Y), and +0x10 (Z/size) via output pointers a2, a3, a4 if non-null; returns a4 as the function result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICursorSelectionRectangleRenderWithInterpolatio (0045b660), TextRenderDispatcher (004dd030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | X position (this[2]) — copied to *a2 |
| this | 0xC | R | — | Y position (this[3]) — copied to *a3 |
| this | 0x10 | R | — | Z/size value (this[4]) — copied to *a4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks each output pointer independently: if `a2` is null, skip field 0x08; if `a3` is null, skip field 0x0C; if `a4` is null, skip field 0x10.
