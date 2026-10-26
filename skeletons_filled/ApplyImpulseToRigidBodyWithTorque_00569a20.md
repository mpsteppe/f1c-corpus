## ApplyImpulseToRigidBodyWithTorque_00569a20 — ApplyLinearAndAngularImpulse

**Summary:** Applies impulse vector to rigid body at a world-space point: accumulates impulse into linear momentum, computes torque via cross product (lever arm × impulse), accumulates into angular momentum. Part of collision response constraint solver.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionContactGenerationAndFrictionResponse (00436870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | body position x, used to compute lever arm |
| this | 0xC | R | — | body position y |
| this | 0x14 | R | — | body position z |
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
