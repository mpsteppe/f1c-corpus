## ModeDispatchWithSwitch_0040f4b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ParticleEffectUpdateDispatch (004eb430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040f52c | jpt_40F4BB | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040f0d0 | ShortComputation_f0d0 | [LLM] |
| 004599c0 | CollisionContactImpulse | [LLM] |
| 004ebc60 | VehicleContactForceAccumulation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
