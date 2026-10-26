## UIListNodeManager_0054bb40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x238)+0x24) | 0x24 | RW | — | [LLM] |
| this | 0x214 | RW | 0 | [LLM] |
| this | 0x218 | R | — | [LLM] |
| this | 0x238 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x238)+0x24) 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x214: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 005510f0 | sub_5510F0 | [LLM] |
| 00551440 | EntityFlagSetSubInitChain | [LLM] |
| 00557350 | sub_557350 | [LLM] |
| 00559200 | sub_559200 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
