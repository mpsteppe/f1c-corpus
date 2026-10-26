## CollisionGlobalInit_d0a0_0044d0a0 — CollisionGlobalDefaultsInit_d0a0

**Summary:** Initializes four collision globals: target/type field to 106, two float thresholds to 0.0, and a state field to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ccf90 | dword_7CCF90 | W | VehicleSetup_Target_7CCF90 [DERIVED] |
| 007ccf94 | flt_7CCF94 | W | UIStatThreshold [DERIVED] |
| 007ccf98 | flt_7CCF98 | W | VehicleSetupFloat_7CCF98 [DERIVED] |
| 007ccf9c | dword_7CCF9C | W | RenderState_OneFloat [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
