## RigidBodyTorqueAccumulation_00441bb0 — RigidBodyTorqueForceAccumulator

**Summary:** Transforms a local-space force vector to world-space via rotation matrix, computes torque from cross product of lever arm and force, applies damping/spring factors (stiffness and damping coefficient), and accumulates the result into the target body's force buffer. Part of vehicle rigid body dynamics.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStep (00441d60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | source body position X |
| *(this+0x15F0) | 0xC | R | — | source body position Y |
| *(this+0x15F0) | 0x14 | R | — | source body position Z |
| *(this+0x15F0) | 0x64 | R | — | source body rotation matrix row 1 |
| *(this+0x15F0) | 0x6C | R | — | source body rotation matrix row 2 |
| *(this+0x15F0) | 0x74 | R | — | source body rotation matrix row 3 |
| *(this+0x15F0) | 0x7C | R | — | source body force accumulator X |
| *(this+0x15F0) | 0x84 | R | — | source body force accumulator Y |
| *(this+0x15F0) | 0x8C | R | — | source body force accumulator Z |
| *(this+0x1D4) | 0x4 | R | — | target body position X |
| *(this+0x1D4) | 0xC | R | — | target body position Y |
| *(this+0x1D4) | 0x14 | R | — | target body position Z |
| *(this+0x1D4) | 0x64 | R | — | target body rotation matrix row 1 |
| *(this+0x1D4) | 0x6C | R | — | target body rotation matrix row 2 |
| *(this+0x1D4) | 0x74 | R | — | target body rotation matrix row 3 |
| *(this+0x1D4) | 0xAC | R | — | target body stiffness/damping parameter |
| *(this+0x1D4) | 0x134 | RW | — | target body accumulated force X |
| *(this+0x1D4) | 0x13C | RW | — | target body accumulated force Y |
| *(this+0x1D4) | 0x144 | RW | — | target body accumulated force Z |
| this | 0x1D4 | R | — | pointer to target body struct |
| this | 0x1D8 | R | — | target body field (accessed via callee) |
| this | 0x1E0 | R | — | target body field (accessed via callee) |
| this | 0x15F0 | R | — | pointer to source body struct |

**Written-by note (persistence):**
- *(this+0x1D4) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0x144: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | multiplies 3x3 matrix by 3D vector |
| 00569b70 | F_3DVectorSubtractWithCrossProduct | subtracts vectors and computes cross product |

**Guard conditions:** no branches — always executes full accumulation path (computed stiffness*damping factor may be zero, resulting in no effective force added)
