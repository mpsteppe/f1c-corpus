## F_4ElementDotProduct_0053bde0 — FourElementReverseDotProduct

**Summary:** Computes a dot product between a reversed-order integer vector (with zero first component) and a float vector using SSE shuffle-add. Returns scalar float result. Used in physics constraint evaluation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Integer component W (a1[0]) |
| this | 0x4 | R | — | Integer component Z (a1[1]) |
| this | 0x8 | R | — | Integer component Y (a1[2]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — all pointers assumed valid, no null checks.
