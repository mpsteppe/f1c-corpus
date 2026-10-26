## F_4ElementDeterminant_0052266c — 3DNow! 4-element matrix determinant (cofactor expansion)

**Summary:** Computes a determinant from a packed matrix/struct a1 via 3DNow! cofactor expansion: computes three 2x2 sub-determinants (v3, v4, v5) using pfsub/pfmul of shuffled elements, then accumulates them weighted by matrix row elements into v6. Returns pfacc(v6, v6) as a single float (cast to double).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Matrix element row 0 col 0 (float) |
| this | 0x8 | R | — | Matrix element row 0 col 1 / row 0 col 2 (__m64 pair) |
| this | 0x10 | R | — | Matrix element row 0 col 3 (float) |
| this | 0x14 | R | — | Matrix element row 1 col 0 (float) |
| this | 0x18 | R | — | Matrix element row 1 col 1 / row 1 col 2 (__m64 pair) |
| this | 0x20 | R | — | Matrix element row 1 col 3 (float) |
| this | 0x24 | R | — | Matrix element row 2 col 0 (float) |
| this | 0x28 | R | — | Matrix element row 2 col 1 / row 2 col 2 (__m64 pair) |
| this | 0x30 | R | — | Matrix element row 2 col 3 (float) |
| this | 0x34 | R | — | Matrix element row 3 col 0 (float) |
| this | 0x38 | R | — | Matrix element row 3 col 1 / row 3 col 2 (__m64 pair) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full determinant computation.
