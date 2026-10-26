## AccumulateAngularMomentum_00569ad0 — ApplyImpulseAtLocalOffset

**Summary:** Accumulates impulse (a3) into linear momentum and cross product (lever arm a2 × impulse) into angular momentum. Same physics as ApplyImpulseToRigidBodyWithTorque but takes pre-computed lever arm vector as a2 parameter instead of computing it from world position.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RigidBodyConstraintJointSolver (004359a0), sub_4423B0 (004423b0), sub_442C90 (00442c90), WheelContactForceSolver (00443150), DamperSpringForceComputationWithAntiRoll (004432f0), VehiclePhysicsVelocityAngularVelocityIntegrator (00459ae0), sub_56EE40 (0056ee40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x134 | RW | — | linear momentum (accumulated impulse) x |
| this | 0x13C | RW | — | linear momentum (accumulated impulse) y |
| this | 0x144 | RW | — | linear momentum (accumulated impulse) z |
| this | 0x14C | RW | — | angular momentum (accumulated torque) x |
| this | 0x154 | RW | — | angular momentum (accumulated torque) y |
| this | 0x15C | RW | — | angular momentum (accumulated torque) z |

**Written-by note (persistence):**
- this 0x134: recalc every frame — external poke does NOT persist
- this 0x13C: recalc every frame — external poke does NOT persist
- this 0x144: recalc every frame — external poke does NOT persist
- this 0x14C: recalc every frame — external poke does NOT persist
- this 0x154: recalc every frame — external poke does NOT persist
- this 0x15C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always executes fully with no early-return branches.
