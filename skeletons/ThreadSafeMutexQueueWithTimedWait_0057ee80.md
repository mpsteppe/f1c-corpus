## ThreadSafeMutexQueueWithTimedWait_0057ee80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57D6C0 (0057d6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAD0)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xAC8) | 0x0 | R | — | [LLM] |
| *(this+0xAD0) | 0x4 | R | — | [LLM] |
| this | 0xAC8 | R | — | [LLM] |
| this | 0xAD0 | RW | — | [LLM] |
| this | 0xAD8 | R | — | [LLM] |

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
| 0057b840 | NetworkMessageEventComparisonWithShortMasking | [LLM] |
| 005871f0 | ReadFieldAtOffset0x14 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
