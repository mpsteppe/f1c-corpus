## MinimumDistanceSearch_0040acd0 — Minimum Distance Search

**Summary:** Searches a stride-160 array at this+0xC for the entry whose float at offset +140 is closest to EmptyStub(a2). Returns the index and minimum delta via output parameters a3 and a4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Base pointer of stride-160 array (entries each contain a float at +140) |
| this | 0x10 | R | — | Entry count of the array (loop bound, must be > 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004579c0 | EmptyStub | Returns a float referencing value from argument a2 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | > | 0 | Array entry count |

**Guard interpretation:** this[4] (offset 0x10) must be > 0 for loop to execute. If 0 or negative, skips search and outputs index -1 with initial max-float delta.
