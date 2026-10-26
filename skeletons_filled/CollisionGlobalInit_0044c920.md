## CollisionGlobalInit_0044c920 — CollisionGlobalDefaultsInit_920

**Summary:** Initializes four collision global parameters: state type to 9, two float thresholds to 0.0, and a float init field to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cca6c | dword_7CCA6C | W | RenderStateInt_9 [DERIVED] |
| 007cca70 | flt_7CCA70 | W | VehicleSetup_BrakeBalance [DERIVED] |
| 007cca74 | flt_7CCA74 | W | DriverStatThreshold [DERIVED] |
| 007cca78 | dword_7CCA78 | W | FloatInit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
