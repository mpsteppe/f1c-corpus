## SteeringGeometryUpdate_00442060 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x141C | R | — | [LLM] |
| this | 0x1438 | R | — | [LLM] |
| this | 0x1440 | R | — | [LLM] |
| this | 0x1448 | R | — | [LLM] |
| this | 0x1450 | R | — | [LLM] |
| this | 0x1458 | R | — | [LLM] |
| this | 0x1460 | R | — | [LLM] |
| this | 0x1468 | R | — | [LLM] |
| this | 0x1470 | R | — | [LLM] |
| this | 0x1478 | R | — | [LLM] |
| this | 0x15BC | R | — | [LLM] |
| this | 0x15C0 | R | — | [LLM] |
| this | 0x1F00 | R | — | [LLM] |
| this | 0x5F68 | RW | 4 | [LLM] |

**Written-by note (persistence):**
- this 0x5F68: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059ed60 | dbl_59ED60 | R | TireWearWobbleDouble [DERIVED] |
| 0059ed68 | dbl_59ED68 | R | LifetimeClampUpperBound [DERIVED] |
| 0059ed70 | dbl_59ED70 | R | Double_SteeringClampMax [DERIVED] |
| 0059ed78 | dbl_59ED78 | R | RandomOffsetScale [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | [LLM] |
| 004388d0 | Mat3x3MulVec | [LLM] |
| 00441450 | PhysicsSubObjectFree | [LLM] |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15BC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
