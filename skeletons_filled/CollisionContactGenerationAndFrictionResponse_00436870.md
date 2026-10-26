## CollisionContactGenerationAndFrictionResponse_00436870 — TireContactAndFrictionSolver

**Summary:** Solves tire-ground contact and friction: generates 3 or 5 contact points from suspension geometry, queries terrain height via spatial grid, computes friction forces using Pacejka-like curves, and applies impulse with torque to the rigid body.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4423B0 (004423b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x264)+0x54) | 0x8 | R | — | terrain friction coefficient from contact point spatial data |
| *(*(this+0x264)+0x54) | 0xC | R | — | terrain slip angle factor from contact point |
| *(*(this+0x264)+0x54) | 0x10 | R | — | terrain stiffness from contact point |
| *(this+0x15C) | 0x4 | R | — | body position X (from suspension state struct) |
| *(this+0x15C) | 0xC | R | — | body position Y |
| *(this+0x15C) | 0x14 | R | — | body position Z |
| *(this+0x15C) | 0x1C | R | — | body forward direction X |
| *(this+0x15C) | 0x2C | R | — | body forward direction Y |
| *(this+0x15C) | 0x34 | R | — | body up direction X |
| *(this+0x15C) | 0x44 | R | — | body up direction Y |
| *(this+0x15C) | 0x4C | R | — | body up direction Z |
| *(this+0x15C) | 0x5C | R | — | body right direction X |
| *(this+0x15C) | 0x64 | R | — | body right direction Y |
| *(this+0x15C) | 0x6C | R | — | body right direction Z |
| *(this+0x15C) | 0x74 | R | — | body inertia tensor element |
| *(this+0x15C) | 0x7C | R | — | accumulated force X |
| *(this+0x15C) | 0x84 | R | — | accumulated force Y |
| *(this+0x15C) | 0x8C | R | — | accumulated force Z |
| *(this+0x15C) | 0x134 | RW | — | accumulated torque X |
| *(this+0x15C) | 0x13C | RW | — | accumulated torque Y |
| *(this+0x15C) | 0x144 | RW | — | accumulated torque Z |
| *(this+0x15C) | 0x14C | RW | — | impulse response X |
| *(this+0x15C) | 0x154 | RW | — | impulse response Y |
| *(this+0x15C) | 0x15C | RW | — | impulse response Z |
| *(this+0x264) | 0x54 | R | — | pointer to spatial grid contact data (terrain properties) |
| this | 0xBC | R | — | vehicle longitudinal speed |
| this | 0xE4 | RW | — | accumulated friction displacement X |
| this | 0xEC | RW | — | accumulated friction displacement Y |
| this | 0xF4 | RW | — | accumulated friction displacement Z |
| this | 0xFC | RW | 18446744073709551615 | contact state sentinel (-1 = no prior contact) |
| this | 0x100 | RW | 18446744073708503039 | secondary contact sentinel (0xFFEFFFFF = fresh contact) |
| this | 0x124 | R | — | friction force threshold for static/dynamic transition |
| this | 0x12C | R | — | friction scale factor |
| this | 0x134 | RW | 0 | lateral friction X component |
| this | 0x138 | RW | 0 | lateral friction Y component |
| this | 0x13C | RW | 0 | normal force magnitude |
| this | 0x140 | RW | 0 | normal force high dword |
| this | 0x144 | RW | 0 | combined friction force (sqrt of components) |
| this | 0x148 | RW | 1072693248 → 1.875f | friction force limit |
| this | 0x14C | RW | 0 | friction coefficient (sqrt of friction force) |
| this | 0x150 | RW | 0 | friction coefficient high dword |
| this | 0x154 | RW | 0 | final impulse X |
| this | 0x158 | RW | 0 | final impulse Y |
| this | 0x15C | R | — | pointer to suspension body state struct |
| this | 0x1C4 | R | — | suspension active flag (byte; if set, return early) |
| this | 0x20C | R | — | body half-extent X |
| this | 0x214 | R | — | body half-extent Y |
| this | 0x21C | R | — | body half-length |
| this | 0x224 | R | — | tire contact patch width X |
| this | 0x228 | R | — | tire contact patch width Y |
| this | 0x22C | R | — | tire vertical stiffness |
| this | 0x234 | R | — | tire vertical damping |
| this | 0x23C | R | — | stiffness polynomial coefficient a (cubic term) |
| this | 0x244 | R | — | stiffness polynomial coefficient b (quadratic term) |
| this | 0x24C | R | — | stiffness polynomial coefficient c (linear term) |
| this | 0x254 | R | — | stiffness polynomial coefficient d (constant) |
| this | 0x25C | R | — | maximum penetration depth clamp |
| this | 0x264 | RW | 0 | nearest contact point spatial data pointer |
| this | 0x268 | RW | 0 | friction damping result |
| this | 0x26C | RW | 1072693248 → 1.875f | friction response limit |
| this | 0x270 | R | — | tire slip angle factor |
| this | 0x278 | R | — | tire lateral force base |
| this | 0x280 | R | — | tire lateral force slope |
| this | 0x288 | R | — | tire longitudinal force base |
| this | 0x290 | R | — | tire longitudinal force slope |
| this | 0x298 | R | — | friction curve min value |
| this | 0x2A0 | R | — | friction curve amplitude |
| this | 0x2A8 | R | — | friction curve penetration threshold |
| this | 0x2B0 | R | — | friction curve frequency |
| this | 0x2B8 | R | — | secondary friction curve min |
| this | 0x2C0 | R | — | secondary friction curve amplitude |
| this | 0x2C8 | R | — | secondary friction curve threshold |
| this | 0x2D0 | R | — | secondary friction curve frequency |
| this | 0x2E4 | R | — | final force output scale |
| this | 0x2EC | R | — | friction torque output scale |
| this | 0x2F4 | R | — | slip angle threshold for friction blend |
| this | 0x2FC | R | — | slip angle damping factor |
| this | 0x304 | R | — | slip angle oscillation frequency |
| this | 0x30C | R | — | slip angle blend transition factor |
| this | 0x314 | RW | — | tire yaw/slip angle (computed from contact plane) |
| this | 0x31C | RW | 0 | contact penetration depth (computed) |
| this | 0x320 | RW | 0 | penetration depth high dword |
| this | 0x324 | RW | 0 | penetration result for stiffness polynomial |
| this | 0x328 | RW | 0 | penetration result high dword |
| this | 0x32C | R | — | tire stiffness from terrain data |
| this | 0x39C | R | — | combined friction scale factor |

**Written-by note (persistence):**
- *(this+0x15C) 0x134: recalc every frame — external poke does NOT persist
- *(this+0x15C) 0x13C: recalc every frame — external poke does NOT persist
- *(this+0x15C) 0x144: recalc every frame — external poke does NOT persist
- *(this+0x15C) 0x14C: recalc every frame — external poke does NOT persist
- *(this+0x15C) 0x154: recalc every frame — external poke does NOT persist
- *(this+0x15C) 0x15C: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist
- this 0xEC: recalc every frame — external poke does NOT persist
- this 0xF4: recalc every frame — external poke does NOT persist
- this 0xFC: recalc every frame — external poke does NOT persist
- this 0x100: recalc every frame — external poke does NOT persist
- this 0x134: recalc every frame — external poke does NOT persist
- this 0x138: recalc every frame — external poke does NOT persist
- this 0x13C: recalc every frame — external poke does NOT persist
- this 0x140: recalc every frame — external poke does NOT persist
- this 0x144: recalc every frame — external poke does NOT persist
- this 0x148: recalc every frame — external poke does NOT persist
- this 0x14C: recalc every frame — external poke does NOT persist
- this 0x150: recalc every frame — external poke does NOT persist
- this 0x154: recalc every frame — external poke does NOT persist
- this 0x158: recalc every frame — external poke does NOT persist
- this 0x264: recalc every frame — external poke does NOT persist
- this 0x268: recalc every frame — external poke does NOT persist
- this 0x26C: recalc every frame — external poke does NOT persist
- this 0x314: recalc every frame — external poke does NOT persist
- this 0x31C: recalc every frame — external poke does NOT persist
- this 0x320: recalc every frame — external poke does NOT persist
- this 0x324: recalc every frame — external poke does NOT persist
- this 0x328: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e898 | dbl_59E898 | R | CamberAngleLimitDeg [DERIVED] (also: ` = 90.0 (camber angle limit, degrees) |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059eaf0 | dbl_59EAF0 | R | Trans_SetupDouble_01 [DERIVED] |
| 0059eaf8 | dbl_59EAF8 | R | Physics_DoubleThreshold_59EAF8 [DERIVED] |
| 0059eb00 | dbl_59EB00 | R | EngineTempDamageThreshold [DERIVED] |
| 0059eb08 | dbl_59EB08 | R | DoublePi [DERIVED] |
| 0059eb10 | dbl_59EB10 | R | ThermalModelConst [DERIVED] |
| 0059eb18 | dbl_59EB18 | R | EngineThermalConstant [DERIVED] |
| 0059eb20 | dbl_59EB20 | R | TireTerrainDoubleThreshold [DERIVED] |
| 0059eb28 | dbl_59EB28 | R | Damper2MaxAdd [DERIVED] (also: ` — damper 2 max add (range limit) |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 007ce994 | byte_7CE994 | R | FiveContactPointMode [DERIVED] (also: ` — enables 5-contact-point mode (vs default 3) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004366e0 | BestFitPlaneFitting | compute best-fit contact plane from 3+ contact points |
| 0044c4c0 | SpatialGridQuery | query terrain height and properties at a 3D position |
| 004d6830 | CubicHermiteInterpolation | cubic Hermite interpolation for friction curve blending |
| 00569a20 | ApplyImpulseToRigidBodyWithTorque | apply force impulse and torque to the rigid body at contact point |
| 0056c640 | sub_56C640 | compute contact plane normal from collision geometry |
| 00588570 | FloatConvertWrapper | convert float/double value with clamping |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 18446744073709551615 | contact state sentinel (-1): no prior contact, BLOCKS friction history accumulation |
| this | 0x100 | != | 18446744073708503039 | secondary sentinel (0xFFEFFFFF): if NOT equal, contact was active last frame, PASSES friction history |
| this | 0x100 | == | 18446744073708503039 | secondary sentinel set: fresh/recovered contact, BLOCKS friction history (uses direct force) |

**Guard interpretation:** 
- this+0xFC == -1 (all bits set): Contact just started or was lost. Friction history accumulation BLOCKED — contact position is reset to current point, sentinel at 0x100 is checked for recovery logic.
- this+0x100 != 0xFFEFFFFF (-1048577): Prior contact exists and is active. PASSES friction history accumulation (computes displacement from last position, adds to accumulated friction force, checks if force exceeds static friction limit).
- this+0x100 == 0xFFEFFFFF: Fresh contact (just recovered from no-contact state). BLOCKS history — sets current position as starting point, computes direct friction force without accumulated displacement.
