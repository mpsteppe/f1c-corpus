## RandomStateMachineWithTimerAndTrigger_0040c070 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MainCameraDirectorUpdate (0040ca30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040c128 | jpt_40C0BD | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c780 | ScoringGateConditionCheck | [LLM] |
| 0040cd60 | SessionPhaseDecode | [LLM] |
| 0040cde0 | GameActionStateMachine | [LLM] |
| 0040d290 | CameraTargetRaceLeader | [LLM] |
| 0040d360 | ShortComputation_d360 | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
