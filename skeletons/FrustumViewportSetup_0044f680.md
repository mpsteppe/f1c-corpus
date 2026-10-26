## FrustumViewportSetup_0044f680 — Set viewport rectangle and projection factors

**Summary:** Configures a viewport rectangle from top, left, bottom, right coordinates: stores bounds, computes center point, and pre-calculates reciprocal half-width and half-height for projection transformations. Called during cursor initialization and input restart.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44F4E0 (0044f4e0), HWInput_Restart (00455da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Viewport top (Y min) |
| this | 0x4 | RW | — | Viewport bottom (Y max) |
| this | 0x8 | RW | — | Viewport left (X min) |
| this | 0xC | RW | — | Viewport right (X max) |
| this | 0x10 | RW | — | Center X ((left+right)/2) |
| this | 0x14 | RW | — | Center Y ((top+bottom)/2) |
| this | 0x18 | RW | — | Reciprocal half-width (1.0 / ((right-left)*0.5)) |
| this | 0x1C | RW | — | Reciprocal half-height (1.0 / ((bottom-top)*0.5)) |

**Written-by note (persistence):**
- this 0x0–0x1C: all 8 fields written unconditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no conditional checks; always writes all fields
