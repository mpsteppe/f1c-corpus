## PerformanceCounterTimerWithScaling_00556510 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F8F50 (004f8f50), sub_556730 (00556730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005564b0 | QueryPerformanceCounterWrapperWithModeDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
