## MutexCallbackDispatch_0057e3a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57E280 (0057e280)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC8) | 0x0 | R | — | [LLM] |
| *(this+0xAD4) | 0x0 | R | — | [LLM] |
| this | 0xAC8 | R | — | [LLM] |
| this | 0xAD0 | RW | — | [LLM] |
| this | 0xAD4 | R | — | [LLM] |
| this | 0xAD8 | R | — | [LLM] |
| this | 0xADC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAD0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587230 | CounterIncrementDecrementByFlag | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
