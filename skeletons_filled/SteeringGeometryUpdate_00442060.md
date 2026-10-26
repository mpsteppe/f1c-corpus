## SteeringGeometryUpdate_00442060 — SteeringGeometryUpdate

**Summary:** Updates per-wheel steering geometry: computes steering angle from input, applies noise perturbation via trig table lookup, clamps to ±10 degrees, transforms wheel contact geometry through coordinate frames of matching contact bodies, and accumulates steering angle. If accumulated angle exceeds threshold, triggers a state change. Part of vehicle steering system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x141C | R | — | shared suspension ID selector |
| this | 0x1438 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1440 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1448 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1450 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1458 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1460 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1468 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1470 | R | — | suspension data pointer (accessed via callee) |
| this | 0x1478 | R | — | suspension data pointer (accessed via callee) |
| this | 0x15BC | R | — | wheel-body contact count |
| this | 0x15C0 | R | — | pointer to wheel-body contact array |
| this | 0x1F00 | R | — | pointer to secondary state struct |
| this | 0x5F68 | RW | 4 | steering state/flag (set to 4 when threshold exceeded) |

**Written-by note (persistence):**
- this 0x5F68: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` — yaw error tolerance (radians) |
| 0059ed60 | dbl_59ED60 | R | TireWearWobbleDouble [DERIVED] |
| 0059ed68 | dbl_59ED68 | R | LifetimeClampUpperBound [DERIVED] |
| 0059ed70 | dbl_59ED70 | R | Double_SteeringClampMax [DERIVED] |
| 0059ed78 | dbl_59ED78 | R | RandomOffsetScale [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | multiplies 3x3 matrix by 3D vector |
| 004388d0 | Mat3x3MulVec | multiplies matrix by vector in-place |
| 00441450 | PhysicsSubObjectFree | copies suspension data to physics sub-objects |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | inverse coordinate transform for contact geometry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15BC | > | 0 | wheel-body contact count |

**Guard interpretation:** If wheel-body contact count (this+0x15BC) > 0, iterate contact entries matching wheel ID and transform steering contact geometry. If <= 0, skip geometry transformation loop. Also per-wheel sub-guards: steering angles clamped to ±0.1745329251994329 rad (±10°).
