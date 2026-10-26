## PhysicsForceScaleDispatch_0043ebd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatParameterForwarder (004ed1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e890 | SuspensionDamperForceAccumulation | [LLM] |
| 0043e980 | ClampedSpringIntegrator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
