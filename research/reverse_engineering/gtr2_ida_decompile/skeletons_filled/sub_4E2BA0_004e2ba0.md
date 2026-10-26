## sub_4E2BA0_004e2ba0 — 2D point-in-rectangle bounds test

**Summary:** Returns TRUE only when both coordinates fall inside the axis-aligned rectangle stored in the object: a2 must lie within [this[3], this[4]] and a3 within [this[1], this[2]] (inclusive on both ends). Pure comparison helper, no side effects.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Rectangle bound (minimum for the a3 axis); lower range limit compared against a3 |
| this | 0x8 | R | — | Rectangle bound (maximum for the a3 axis); upper range limit compared against a3 |
| this | 0xC | R | — | Rectangle bound (minimum for the a2 axis); lower range limit compared against a2 |
| this | 0x10 | R | — | Rectangle bound (maximum for the a2 axis); upper range limit compared against a2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Four range checks combined with `&&`, inclusive bounds: `a2 >= this[3]` and `a2 <= this[4]` (a2 axis), `a3 >= this[1]` and `a3 <= this[2]` (a3 axis). PASSES (returns TRUE) only if a2 and a3 both fall within their inclusive ranges; BLOCKED (returns FALSE) as soon as any single bound fails.
