## GlobalStateInitializer_0044c6e0 — GlobalStateDefaultsInit_c6e0

**Summary:** Initializes four global parameters: audio engine type to 3, two float thresholds to 0.0, and collision Z scale to 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca3e8 | dword_7CA3E8 | W | AudioEngineDefaultType [DERIVED] |
| 007ca3ec | flt_7CA3EC | W | FrontBrakeBalance [DERIVED] |
| 007ca3f0 | flt_7CA3F0 | W | SteeringWheelRange [DERIVED] |
| 007ca3f4 | dword_7CA3F4 | W | CollisionScaleZ [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional writes to all four globals.
