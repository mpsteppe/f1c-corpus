## PhysicsIntegrationStateMachine_004e4e60 — PhysicsIntegrationStateMachine

**Summary:** Selects integration sub-step size based on wheel speed squared vs threshold, then runs v4 iterations of suspension/tire physics (spring-damper reset, force computation, torque integration). Stores step value in 4 wheel slots (62-DWORD stride). Part of vehicle physics time integration.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3498 | R | — | Integration sub-step count from config |
| this | 0x349C | R | — | Speed^2 threshold for step size selection |
| this | 0x34A0 | R | — | pitTime[0] [CONFIRMED] — small step size |
| this | 0x34A4 | R | — | Larger step size for high speed |
| this | 0x34A8 | RW | — | Selected step value for current sub-iteration |
| this | 0x34AC | RW | — | Session/race time stored after integration |
| this | 0x3508 | R | — | Wheel speed used for step size selection |
| this | 0x35F0 | RW | — | Base of 4 wheel step arrays (62-DWORD stride) |

**Written-by note (persistence):**
- this 0x34A8: recalc every frame — external poke does NOT persist
- this 0x34AC: recalc every frame — external poke does NOT persist
- this 0x35F0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e4f40 | SuspensionSpringDampingRateReset | Resets spring/damper forces and recomputes damping rates |
| 004e51a0 | sub_4E51A0 | Computes suspension displacement and force |
| 004e5470 | WheelForceCalculationSpringDamperTorque | Calculates wheel contact forces and spring/damper torques |
| 004e58d0 | sub_4E58D0 | Updates suspension geometry and kinematics |
| 004e5ae0 | sub_4E5AE0 | Integrates wheel angular velocity and updates rotation |

**Guard conditions:** Checks this+0x3508 (wheel speed) squared > this+0x349C (threshold) to select large vs small step size. Checks this+0x3498 (step count) <= 0 to skip physics iteration loop entirely. PASSES: step count > 0 -> run v4 sub-iterations. BLOCKED: step count <= 0 -> skip physics.
