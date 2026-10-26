## VehiclePhysicsIntegrationStep_00441650 — VehiclePhysicsIntegrationStep

**Summary:** Per-frame vehicle physics integration driver — runs sub-stepped RK2 (midpoint) integration loop, accumulates forces per wheel, detects collision damage, and transforms inertia tensors for physics sub-objects.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsModeDispatcher (004e4930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x15F0) | 0x4 | R | — | inertia tensor row0 col1 (m01) |
| *(this+0x15F0) | 0xC | R | — | inertia tensor row1 col0 (m10) |
| *(this+0x15F0) | 0x14 | R | — | inertia tensor row1 col1 (m11) |
| *(this+0x15F0) | 0x1C | R | — | inertia tensor row1 col2 (m12) |
| *(this+0x15F0) | 0x24 | R | — | inertia tensor row2 col0 (m20) |
| *(this+0x15F0) | 0x2C | R | — | inertia tensor row2 col1 (m21) |
| *(this+0x15F0) | 0x34 | R | — | inertia tensor row2 col2 (m22) |
| *(this+0x15F0) | 0x3C | R | — | inertia tensor row0 col0 (m00) |
| *(this+0x15F0) | 0x44 | R | — | inertia tensor row0 col1 (m01) |
| *(this+0x15F0) | 0x4C | R | — | inertia tensor row0 col2 (m02) |
| *(this+0x15F0) | 0x54 | R | — | inertia tensor row1 col0 (m10) |
| *(this+0x15F0) | 0x5C | R | — | inertia tensor row1 col1 (m11) |
| *(this+0x3EC) | 0x1C | R | — | front collision body velocity X |
| *(this+0x3EC) | 0x34 | R | — | front collision body velocity Y |
| *(this+0x3EC) | 0x4C | R | — | front collision body velocity Z |
| this | 0x60 | RW | — | accumulated sub-step time accumulator |
| this | 0x68 | R | — | physics timestep delta (dt) |
| this | 0x310 | R | — | wheel[0] data base pointer |
| this | 0x318 | R | — | wheel[0] data + 8 (sub-object flag/test pointer) |
| this | 0x338 | RW | — | wheel[0] physics active flag (set non-zero after inertia transform) |
| this | 0x3E0 | R | — | collision body offset (front collision body data base) |
| this | 0x3EC | R | — | front collision body object pointer |
| this | 0x450 | R | — | wheel[0] disabled flag (320 = suspension disable byte) |
| this | 0x844 | R | — | collision body position element (used in distance accumulation) |
| this | 0x850 | R | — | collision body config pointer (second collision body) |
| this | 0xCB4 | R | — | rear collision body object pointer (fallback) |
| this | 0x1118 | R | — | rear collision body object pointer (primary) |
| this | 0x141C | R | — | third collision body object pointer (optional) |
| this | 0x15F0 | R | — | inertia tensor world-space matrix (3x3 or 4x4) |
| this | 0x1658 | RW | — | accumulated total travel distance |

**Written-by note (persistence):**
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x338: recalc every frame — external poke does NOT persist
- this 0x1658: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e830 | dbl_59E830 | R | TempWarningThreshold [DERIVED] (also: ` — dot product comparison threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ed28 | dbl_59ED28 | R | PhysicsMinDeltaThreshold [DERIVED] |
| 0059ed30 | dbl_59ED30 | R | MinVelocityThreshold [DERIVED] |
| 0059ed38 | dbl_59ED38 | R | SpeedSmoothingGain [DERIVED] (also: ` — sub-step stability multiplier) |
| 005d6d70 | dbl_5D6D70 | R | EngineBrakeTorqueFactor [DERIVED] (also: ` — integration enabled flag (shared timestep variable) |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00438130 | VehicleDynamicsForceAccumulatorIntegration | compute and accumulate forces/torques for one wheel |
| 00438690 | PhysicsCollisionDamageDNFDetection | detect collision damage and DNF conditions for a collision body |
| 0043ef20 | EngineStressSimulation | simulate engine stress effects (torque, wear, damage) |
| 00441360 | StateAccumulateDelta | accumulate state deltas at sub-step boundaries |
| 00441450 | PhysicsSubObjectFree | free/release a physics sub-object after inertia transform |
| 004414d0 | WheelDataCopy | copy wheel state data at half-step midpoint |
| 00441600 | PhysicsStepFrame | advance physics frame by a sub-step delta |
| 00441d60 | PhysicsIntegrationStep | perform single physics integration step (forces → acceleration → velocity → position) |
| 004441f0 | VehicleMainPhysicsUpdate | top-level vehicle physics state update before sub-step loop |
| 00567740 | FPUControlWordMaskExtract | save current FPU control word for precision management |
| 00567780 | EmptyStub_7780 | restore FPU control word (no-op stub) |
| 005692a0 | F_3x3InertiaTensorTransform | transform 3x3 inertia tensor to body-local frame |
| 00569410 | InertiaTensorWorldSpaceTransform | transform inertia tensor to world space |
| 0056bde0 | sub_56BDE0 | reset/clear a physics sub-object state |
| 0058957a | InterruptDispatch | yield/interrupt dispatch for cooperative multitasking |

**Guard conditions:** 
- BLOCKED: `dbl_5D6D70 != 1.0 AND byte_7CE254 != 0` — early return, entire physics step skipped (integration disabled AND HUD enabled)
- PASSES: `dbl_5D6D70 == 1.0 OR byte_7CE254 == 0` — physics runs normally
- Sub-step loop: iterates while `v29 > v19` (timestep remaining > delta used), subdividing timestep
- Inertia tensor transform: skips wheel if `*(v10+220) == 0` (no sub-object), or `*(v10+320) != 0` (wheel disabled), or dot product `v13 < 0.5` or `|v33| > 0.7` (stability check)
- TireModelMode: if `dword_7CE958 != 0` and timestep changed, rescales accumulated time
- Minimum sub-step: clamped to `0.000003814697265625` (~1/262144)
