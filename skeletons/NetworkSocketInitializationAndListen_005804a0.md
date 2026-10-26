## NetworkSocketInitializationAndListen_005804a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48 | R | — | [LLM] |
| obj | 0x90 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x910 | R | — | [LLM] |
| this | 0x938 | R | — | [LLM] |
| this | 0x93C | R | — | [LLM] |
| this | 0x967 | RW | 0 | [LLM] |
| this | 0x968 | RW | 1 | [LLM] |
| this | 0x96A | RW | 1 | [LLM] |
| this | 0x96B | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x967: [LLM: once/conditional? does external poke survive?]
- this 0x968: [LLM: once/conditional? does external poke survive?]
- this 0x96A: [LLM: once/conditional? does external poke survive?]
- this 0x96B: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ca8b | SEH_5804A0 | R | [LLM] |
| 0059e330 | listen | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057c7b0 | SocketBindPortScan | [LLM] |
| 00585680 | ThreadResumeWithMutexWait | [LLM] |
| 005857c0 | MutexProtectedFieldWrite | [LLM] |
| 00585cd0 | ThreadSafeWriteWithMutex | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
