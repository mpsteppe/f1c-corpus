## DoubleAccumulatorClamp_0043ea70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomWeightedAudioMix (0043ec00), PhysicsDampingScaleApplication (0043ec50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC0 | RW | — | [LLM] |
| this | 0x1C30 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1BC0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ec80 | dbl_59EC80 | R | InputOffsetBias [DERIVED] |
| 0059ec88 | dbl_59EC88 | R | FuelConsumptionRate [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
