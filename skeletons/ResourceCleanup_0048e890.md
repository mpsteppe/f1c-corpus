## ResourceCleanup_0048e890 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateResetWithZero (004662e0), Destructor_e670 (0048e670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE8 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005461b0 | MutexSemaphoreCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
