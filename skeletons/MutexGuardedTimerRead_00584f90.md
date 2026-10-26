## MutexGuardedTimerRead_00584f90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationTimingUpdateWithParamSet (0057a5a0), AnimationValueFetchWithTiming (0057a610), sub_57CB50 (0057cb50), VtableCallFormatDispatchTimerDispatchChain (0057dbb0), sub_57DC10 (0057dc10), sub_57E0A0 (0057e0a0), sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4 | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
