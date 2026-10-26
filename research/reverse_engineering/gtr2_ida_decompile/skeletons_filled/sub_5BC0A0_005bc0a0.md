## sub_5BC0A0_005bc0a0 — scale 3-float vector by a scalar

**Summary:** Copies a 3-component float vector (`a2`) to the output `a1` scaled by scalar `a3`: `a1[i] = a2[i] * a3`. Arithmetic goes through x87 doubles (`st7`/`st6`) before being stored as floats. Returns `a1`.

**Called by:** sub_5C6530 (005c6530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | x component of the vector used by this scale-copy routine (source `a2[0]`, destination `a1[0]`). |
| this | 0x4 | R | — | y component of the vector (source `a2[1]`, destination `a1[1]`). |
| this | 0x8 | R | — | z component of the vector (source `a2[2]`, destination `a1[2]`). |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — the three multiplies and stores execute unconditionally; no values checked, nothing blocked.
