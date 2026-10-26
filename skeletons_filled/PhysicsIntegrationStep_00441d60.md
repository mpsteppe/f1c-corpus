## PhysicsIntegrationStep_00441d60 — physics integration step (gravity, constraint solving, velocity accumulation)

**Summary:** Performs a physics integration substep: applies gravity to body array, computes damper/spring forces with anti-roll, solves rigid-body constraints, then accumulates linear and angular velocities into the current body state.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x134 | RW | — | integrated linear position/velocity X (3D vector component 0) |
| *(this+0x15F0) | 0x13C | RW | — | integrated linear position/velocity Y (3D vector component 1) |
| *(this+0x15F0) | 0x144 | RW | — | integrated linear position/velocity Z (3D vector component 2) |
| *(this+0x15F0) | 0x14C | RW | — | integrated angular position/velocity X (3D vector component 0) |
| *(this+0x15F0) | 0x154 | RW | — | integrated angular position/velocity Y (3D vector component 1) |
| *(this+0x15F0) | 0x15C | RW | — | integrated angular position/velocity Z (3D vector component 2) |
| this | 0x60 | R | — | constraint solver param (body count/index) |
| this | 0x64 | R | — | constraint solver param (body count/index) |
| this | 0xEC | R | — | linear velocity delta X to accumulate |
| this | 0xF4 | R | — | linear velocity delta Y to accumulate |
| this | 0xFC | R | — | linear velocity delta Z to accumulate |
| this | 0x104 | R | — | angular velocity delta X to accumulate |
| this | 0x10C | R | — | angular velocity delta Y to accumulate |
| this | 0x114 | R | — | angular velocity delta Z to accumulate |
| this | 0x19C | R | — | flag: when zero, triggers velocity damping from speed error |
| this | 0x15AC | R | — | count of rigid bodies/particles in array |
| this | 0x15B0 | R | — | pointer to array of physics bodies (stride 0x244 bytes) |
| this | 0x15F0 | R | — | pointer to current body state (position/velocity accumulator) |
| this | 0x1F04 | R | — | external linear velocity X to accumulate |
| this | 0x1F0C | R | — | external linear velocity Y to accumulate |
| this | 0x1F14 | R | — | external linear velocity Z to accumulate |
| this | 0x1F1C | R | — | external angular velocity X to accumulate |
| this | 0x1F24 | R | — | external angular velocity Y to accumulate |
| this | 0x1F2C | R | — | external angular velocity Z to accumulate |

**Written-by note (persistence):**
- *(this+0x15F0) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x144: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0x15C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059ed50 | dbl_59ED50 | R | VelocityDampingFactor [DERIVED] (also: ` — anti-roll rate scale) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004359a0 | RigidBodyConstraintJointSolver | solves rigid body constraints (joints/contacts) on the body array |
| 00441ad0 | VelocityDampingFromSpeedError | computes and applies velocity damping correction from speed error |
| 00441bb0 | RigidBodyTorqueAccumulation | accumulates torque contributions onto rigid bodies |
| 004423b0 | sub_4423B0 | pre-integration physics state update / force preparation |
| 00442c90 | sub_442C90 | pre-integration physics state update / external force application |
| 004432f0 | DamperSpringForceComputationWithAntiRoll | computes damper/spring forces with anti-roll bar coupling |
| 0056eb90 | sub_56EB90 | prepares/inits physics body array for integration loop |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15AC | > | 0 | rigid body count — guards gravity/state-copy loop |

**Guard interpretation:** When body count at offset 0x15AC is > 0, the integration loop executes (applying gravity * -9.81 per element and copying state DWORDs for each body). When count is ≤ 0, the loop is skipped entirely and only constraint solving + velocity accumulation from this-frame deltas proceed.
