## CollisionMaterialCoefficientsSet5_0044c860 — CollisionMaterialDefaultsInit

**Summary:** Initializes four collision material coefficient globals: default material type to 7, two float thresholds to 0.0, and restitution coefficient to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccbb0 | dword_7CCBB0 | W | CollisionMaterialDefault [DERIVED] |
| 007ccbb4 | flt_7CCBB4 | W | VehicleRideHeightRear [DERIVED] |
| 007ccbb8 | flt_7CCBB8 | W | RendererClampThreshold [DERIVED] |
| 007ccbbc | dword_7CCBBC | W | MaterialRestCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
