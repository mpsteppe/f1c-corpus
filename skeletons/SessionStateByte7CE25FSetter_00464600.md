## SessionStateByte7CE25FSetter_00464600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC5 | R | — | [LLM] |
| obj | 0xC6 | R | — | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| obj | 0x3FC4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce260 | byte_7CE260 | R | InitGuard_45d500 [DERIVED] (also: ` -- init guard flag) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045d500 | GuardedInitCall | [LLM] |
| 00463140 | ShortComputation_3140 | [LLM] |
| 004b16b0 | TrackConfigurationNameBuilder | [LLM] |
| 0057a910 | SingleFunctionCallWrapper_a910 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
