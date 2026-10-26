## ShortComputation_f070_0049f070 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004082b0 | FloatClampWithEventDispatch | [LLM] |
| 0045bc00 | ThunkToFUN0045b840 | [LLM] |
| 00461d20 | YouHaveBeenBootedHandler | [LLM] |
| 0049d070 | SteeringWheelAnimation | [LLM] |
| 0049f790 | ModeBasedDispatch | [LLM] |
| 0049f870 | sub_49F870 | [LLM] |
| 004d8450 | sub_4D8450 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
