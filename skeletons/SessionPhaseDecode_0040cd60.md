## SessionPhaseDecode_0040cd60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomStateMachineWithTimerAndTrigger (0040c070), SessionPhaseDispatchWithCascadeChecks (0040d1b0), ShortComputation_d3c0 (0040d3c0), ShortComputation_d410 (0040d410), sub_49F870 (0049f870), sub_4B9890 (004b9890), AudioSoundEffectController (004e0ed0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | RW | 5 | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040cdbc | jpt_40CD70 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
