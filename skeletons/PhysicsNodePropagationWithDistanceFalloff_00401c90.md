## PhysicsNodePropagationWithDistanceFalloff_00401c90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionWrapperWithLock (004e4910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x148 | RW | — | [LLM] |

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
| 00401340 | VehicleSuspensionForceCalculation | [LLM] |
| 00401910 | SweptSuspensionCollisionDetection | [LLM] |
| 004e8ce0 | TireForceSolver | [LLM] |
| 004e9100 | TireForce | [LLM] |
| 004e9300 | TireGripLateralForceCalculation | [LLM] |
| 004faf60 | sub_4FAF60 | [LLM] |
| 004fb260 | sub_4FB260 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x130 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
