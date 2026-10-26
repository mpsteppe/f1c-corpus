## SpatialNodeInit_0044c680 — SpatialNodeDefaultsInit

**Summary:** Initializes four global spatial node parameters: element count to 2, radius sentinel to -1.0f, and two float thresholds to 0.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cca44 | dword_7CCA44 | W | NodeElementCount [DERIVED] (also: ` — node element count (2) |
| 007cca48 | flt_7CCA48 | W | RenderFloat_A [DERIVED] |
| 007cca4c | dword_7CCA4C | W | CollisionRadiusSentinel [DERIVED] (also: ` — radius or sentinel value (-1.0f) |
| 007cca50 | flt_7CCA50 | W | UISliderMinThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
