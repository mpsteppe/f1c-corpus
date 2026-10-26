## ThreadResumeWithMutexWait_00585680 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkSocketInitializationAndListen (005804a0), ThreadTerminationWithWaitCleanup (00585550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | [LLM] |
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e1f8 | ResumeThread | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00583660 | FloatSetWithTimingCall | [LLM] |
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
