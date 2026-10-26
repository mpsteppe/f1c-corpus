## GetBodyMotionState_00447100 — GetBodyForceAndTorqueState

**Summary:** Computes suspension spring-damper force and torque for a body via SuspensionSpringDamperForceComputationWithClampi, then returns the results through two output float arrays (force and torque vectors). Part of vehicle suspension query interface.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4F0430 (004f0430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15F0 | R | — | pointer to rigid body state (passed to force computation) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e60 | SuspensionSpringDamperForceComputationWithClampi | computes suspension spring-damper force and torque for body |

**Guard conditions:** no branches — always computes and returns force/torque
