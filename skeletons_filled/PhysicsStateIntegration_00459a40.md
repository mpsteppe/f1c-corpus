## PhysicsStateIntegration_00459a40 — PhysicsStateIntegration

**Summary:** Integrates body-state velocity (scaled by a factor) into position/displacement accumulator (three doubles at offsets 0xD8-0xE8). Outputs integrated displacement as floats and forwards to ThreeFieldSetterWithSubCall. Part of physics integration system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UICameraModeDispatchWithVehicleDataRead (0040f550), VehiclePhysicsVelocityAngularVelocityIntegrator (00459ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD8 | R | — | Position/displacement accumulator X (double, this[27]) |
| this | 0xE0 | R | — | Position/displacement accumulator Y (double, this[28]) |
| this | 0xE8 | R | — | Position/displacement accumulator Z (double, this[29]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054b3b0 | ThreeFieldSetterWithSubCall | Forward three output field values for further processing |

**Guard conditions:** No guard conditions — unconditionally integrates and stores, no early return.
