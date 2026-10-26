## NetworkPacketQueueReader_005805c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8C) | 0x48 | RW | — | [LLM] |
| this | 0xB58 | R | — | [LLM] |
| this | 0xB60 | RW | 0 | [LLM] |
| this | 0xB68 | RW | 0 | [LLM] |
| this | 0xB6C | R | — | [LLM] |
| this | 0xB8C | R | — | [LLM] |
| this | 0xB94 | RW | 0 | [LLM] |
| this | 0xB98 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xB8C) 0x48: [LLM: once/conditional? does external poke survive?]
- this 0xB60: [LLM: once/conditional? does external poke survive?]
- this 0xB68: [LLM: once/conditional? does external poke survive?]
- this 0xB94: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | [LLM] |
| 0059e1a4 | ReleaseMutex | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ba780 | ShortComputation_a780 | [LLM] |
| 005823c0 | sub_5823C0 | [LLM] |
| 00582780 | sub_582780 | [LLM] |
| 00582b10 | LinkedListElementRemovalWithCleanup | [LLM] |
| 005832e0 | sub_5832E0 | [LLM] |
| 00583430 | sub_583430 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
