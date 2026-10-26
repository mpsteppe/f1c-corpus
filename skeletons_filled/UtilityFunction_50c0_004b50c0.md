## UtilityFunction_50c0_004b50c0 — Bounds check with sentinel values

**Summary:** Checks if float parameter is within range [lower, upper] where -1.0e32 sentinel value means the respective bound is inactive (unbounded). Supports open-ended or fully bounded range checks.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LinkedListTraversalWithFilter (004b72a0), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x84 | R | — | Lower bound (-1.0e32 sentinel = no lower bound) |
| this | 0x88 | R | — | Upper bound (-1.0e32 sentinel = no upper bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd10 | flt_5ACD10 | R | EntityActiveDefault [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — sentinel values (-1.0e32) bypass respective bound check.
