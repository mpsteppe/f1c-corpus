## ClampedSpringIntegrator_0043e980 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsForceScaleDispatch (0043ebd0), RandomWeightedAudioMix (0043ec00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1808 | RW | — | [LLM] |
| this | 0x1818 | RW | — | [LLM] |
| this | 0x1C18 | R | — | [LLM] |
| this | 0x1C20 | R | — | [LLM] |
| this | 0x1C28 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1808: recalc every frame — external poke does NOT persist
- this 0x1818: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059eb28 | dbl_59EB28 | R | Damper2MaxAdd [DERIVED] (also: ` — damper 2 max add (range limit) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059eb58 | dbl_59EB58 | R | Damper2RateCoefficient [DERIVED] |
| 0059ec78 | dbl_59EC78 | R | Damper1RateCoeff [DERIVED] (also: ` — damper 1 rate coefficient) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043bbd0 | SpringDamperCompute | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
