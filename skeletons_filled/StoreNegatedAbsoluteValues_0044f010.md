## StoreNegatedAbsoluteValues_0044f010 — StoreNegatedAbsValues

**Summary:** Computes absolute values of two floats (a2, a3), negates them, and stores results at this[799] (offset 0xC7C) and this[800] (offset 0xC80). Updates surface constants previously initialized as -0.5f and -0.1f.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC7C | RW | — | Surface constant: -abs(a2), previously -0.5f |
| this | 0xC80 | RW | — | Surface constant: -abs(a3), previously -0.1f |

**Written-by note (persistence):**
- this 0xC7C: Overwritten each call with -abs(a2). Overrides D3DWindowSurfaceCreation init -0.5f.
- this 0xC80: Overwritten each call with -abs(a3). Overrides D3DWindowSurfaceCreation init -0.1f.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional store, no branches. Absolute value computed inline for each input (negate if negative).
