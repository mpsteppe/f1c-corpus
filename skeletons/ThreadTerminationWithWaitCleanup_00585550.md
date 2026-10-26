## ThreadTerminationWithWaitCleanup_00585550 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioStreamingThreadShutdown (0057fde0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 1 | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | [LLM] |
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e1a8 | CloseHandle | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00585680 | ThreadResumeWithMutexWait | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
