## CollisionStateInitAlpha_0044c7a0 — CollisionStateAlphaInit

**Summary:** Initializes four globals for collision state: default collision type to 5, two float thresholds to 0.0, and a render/alpha field to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd198 | dword_7CD198 | W | DefaultCollisionState [DERIVED] (also: ` — collision state (type=5, alpha=1.0) |
| 007cd19c | flt_7CD19C | W | VehicleHeatDisplayTread [DERIVED] |
| 007cd1a0 | flt_7CD1A0 | W | AudioMixThreshold [DERIVED] |
| 007cd1a4 | dword_7CD1A4 | W | Flt_Unknown_Render [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
