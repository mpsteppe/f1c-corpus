## AccumulatorClamp_004ed0f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatParameterForwarder (004ed1c0), ForceApplicationRouter (004ed1f0), PhysicsTimeStep (004ed220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3A6C | RW | — | [LLM] |
| this | 0x3A70 | RW | — | [LLM] |
| this | 0x3A78 | R | — | [LLM] |
| this | 0x3A80 | R | — | [LLM] |
| this | 0x3D60 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x3A6C: recalc every frame — external poke does NOT persist
- this 0x3A70: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 005acee8 | flt_5ACEE8 | R | FrontRearDistributionWeight [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
