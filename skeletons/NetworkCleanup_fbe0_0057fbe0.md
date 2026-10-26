## NetworkCleanup_fbe0_0057fbe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BCE0 (0057bce0), AudioStreamingThreadShutdown (0057fde0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x30 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xA74 | RW | 0 | [LLM] |
| this | 0xAD8 | R | — | [LLM] |
| this | 0xADC | R | — | [LLM] |
| this | 0xAF4 | R | — | [LLM] |
| this | 0xAF8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA74: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |
| 0059e318 | __imp_WSACleanup | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057e570 | sub_57E570 | [LLM] |
| 0057e6e0 | ThreadSafeLinkedListDestructionWithMutex | [LLM] |
| 0057e760 | MutexProtectedLinkedListFlushDestroy | [LLM] |
| 0057e7e0 | MutexProtectedLinkedListDestruction | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
