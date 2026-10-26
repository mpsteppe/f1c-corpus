## RectangleClampConstraint_00491600 — RectClampToBounds

**Summary:** Clamps a short[4] rect (x1, y1, width, height) in-place to fit within boundary (a2, a3, a2+a4, a3+a5). Adjusts width/height when position shifts. Used for render/viewport clipping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderDispatchWithIteration (004993d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | x1 — clamped to >= a2 |
| this | 0x2 | RW | — | y1 — clamped to >= a3 |
| this | 0x4 | RW | — | width — reduced when x1 adjusted or right edge exceeds a2+a4 |
| this | 0x6 | RW | — | height — reduced when y1 adjusted or bottom edge exceeds a3+a5 |

**Written-by note (persistence):**
- this 0x0: conditionally written if x1 < a2; set to a2
- this 0x2: conditionally written if y1 < a3; set to a3
- this 0x4: conditionally reduced if x1 adjusted or right edge exceeds bound
- this 0x6: conditionally reduced if y1 adjusted or bottom edge exceeds bound

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[1]` (y1) < a3 (min y) → adjust height down by (a3 - y1), set y1 = a3. If `*this` (x1) < a2 (min x) → adjust width down by (a2 - x1), set x1 = a2. If `x1 + width + 1` > `a2 + a4 + 1` (right edge exceeds bound) → clamp width. If `y1 + height` > `a3 + a5` (bottom edge exceeds bound) → clamp height.
