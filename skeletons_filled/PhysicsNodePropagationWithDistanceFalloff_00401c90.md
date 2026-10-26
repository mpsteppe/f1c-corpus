## PhysicsNodePropagationWithDistanceFalloff_00401c90 — Force propagation with distance falloff

**Summary:** Propagates suspension and tire forces through linked collision geometry chains with distance-based falloff. Calls SweptSuspensionCollisionDetection, applies TireForceSolver/TireForce/TireGripLateralForceCalculation per strut, computes contact force attenuation as a function of distance between strut center and collision feature, and records the maximum propagated force.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionWrapperWithLock (004e4910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | number of suspension struts to process (iteration count) |
| this | 0x134 | R | — | base pointer/offset to suspension strut data array |
| this | 0x148 | RW | — | maximum propagated contact force across all struts |

**Written-by note (persistence):**
- this 0x148: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401340 | VehicleSuspensionForceCalculation | computes suspension contact forces between wheel and ground |
| 00401910 | SweptSuspensionCollisionDetection | performs swept collision detection for suspension struts |
| 004e8ce0 | TireForceSolver | solves tire contact force from suspension input |
| 004e9100 | TireForce | applies tire force magnitude at a given strut position |
| 004e9300 | TireGripLateralForceCalculation | computes lateral grip force component for tire |
| 004faf60 | sub_4FAF60 | unknown — per-strut physics processing called after force propagation |
| 004fb260 | sub_4FB260 | unknown — applies grip-based multiplier per strut |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | > | 0 | strut count — number of active suspension struts |

**Guard interpretation:** If `this->count (0x130)` > 0, PASS — all six processing loops execute (force propagation, grip propagation, init, final falloff, sub_4FB260, sub_4FAF60). If count <= 0, BLOCKED — each loop is skipped entirely.
