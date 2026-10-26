## DoublyLinkedListUnlink_0053c630 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010), MutexSemaphoreCleanup (005461b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E4) | 0x1E8 | RW | — | [LLM] |
| *(this+0x1E8) | 0x1E4 | RW | — | [LLM] |
| this | 0x1E4 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E4) 0x1E8: [LLM: once/conditional? does external poke survive?]
- *(this+0x1E8) 0x1E4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | RW | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
