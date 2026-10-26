## FloatParameterForwarder_004ed1c0 — float parameter accumulator dispatcher

**Summary:** Forwards float input to AccumulatorClamp, conditionally dispatches to PhysicsForceScaleDispatch when mode flag is zero. Part of physics parameter routing system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CollisionSparkParticleEffects (004ec1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | mode flag (0 → dispatch force scale, non-zero → block) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043ebd0 | PhysicsForceScaleDispatch | dispatches physics force scaling with accumulated delta |
| 004ed0f0 | AccumulatorClamp | accumulates and clamps the float input |

**Guard conditions:** this[3247] (0x32BC) == 0 → PASS (dispatch PhysicsForceScaleDispatch). Non-zero → BLOCKED (skip force dispatch).
