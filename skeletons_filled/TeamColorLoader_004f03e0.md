## TeamColorLoader_004f03e0 — TeamColorLoader

**Summary:** Loads team color data via utility function and applies it to vehicle physics time step. Part of vehicle appearance/team customization system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | Team color parameter/index loaded by utility function |
| this | 0x0 | R | — | Object identifier passed to VehiclePhysicsTimeStep |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00463d50 | UtilityFunction_3d50 | Resolves/loads team color data into buffer |
| 004c73f0 | VehiclePhysicsTimeStep | Steps vehicle physics with loaded color/team data |

**Guard conditions:** Calls UtilityFunction_3d50 with team color parameter; only proceeds to VehiclePhysicsTimeStep if it returns nonzero (success). BLOCKED from physics step if color data cannot be resolved.
