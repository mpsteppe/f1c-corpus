## CollisionStateInit_0044c620 — CollisionStateDefaultsInit

**Summary:** Initializes four global collision state parameters to their default values: cell init count to 1, two float thresholds to 0.0, and cell scale to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca490 | dword_7CA490 | W | CollisionCellInitCount [DERIVED] (also: ` — collision cell initial count (1) |
| 007ca494 | flt_7CA494 | W | AudioEngine_MinVolume [DERIVED] |
| 007ca498 | flt_7CA498 | W | RenderStateMinThreshold_498 [DERIVED] |
| 007ca49c | dword_7CA49C | W | CollisionCellScale [DERIVED] (also: ` — collision cell scale (1.0f) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
