## AudioSystemShutdown_00406e50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ComplexDestructorWith4LinkedLists (00406ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x8)+0x0) | 0x18 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x4 | R | — | [LLM] |
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x2C) | 0x4 | R | — | [LLM] |
| *(this+0x3C) | 0x4 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| obj | 0x34 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | RW | 0 | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | 0 | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x90: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e394 | __imp__AIL_shutdown@0 | R | [LLM] |
| 0059e3a4 | _AIL_waveOutClose@4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405410 | MultiStageCleanupWithFree | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
