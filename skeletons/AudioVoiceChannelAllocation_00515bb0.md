## AudioVoiceChannelAllocation_00515bb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VtableDelegateDispatch (00515db8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x8 | R | — | [LLM] |
| *(this+0x124) | 0xC | R | — | [LLM] |
| *(this+0x124) | 0x1C | R | — | [LLM] |
| *(this+0x124) | 0x20 | R | — | [LLM] |
| *(this+0x124) | 0x24 | R | — | [LLM] |
| *(this+0x124) | 0x34 | RW | — | [LLM] |
| *(this+0x124) | 0x38 | RW | — | [LLM] |
| *(this+0x124) | 0x3C | RW | — | [LLM] |
| *(this+0x124) | 0x40 | RW | — | [LLM] |
| *(this+0x124) | 0x44 | RW | — | [LLM] |
| *(this+0x124) | 0x48 | RW | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 11 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| obj | 0x1C | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x134 | RW | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x13C | RW | 0 | [LLM] |
| this | 0x140 | RW | 0 | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x158 | RW | 1 | [LLM] |
| this | 0x15C | RW | 1 | [LLM] |
| this | 0x160 | RW | 1 | [LLM] |
| this | 0x164 | RW | — | [LLM] |
| this | 0x168 | RW | 1 | [LLM] |
| this | 0x16C | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x124) 0x34: [LLM: once/conditional? does external poke survive?]
- *(this+0x124) 0x38: [LLM: once/conditional? does external poke survive?]
- *(this+0x124) 0x3C: [LLM: once/conditional? does external poke survive?]
- *(this+0x124) 0x40: [LLM: once/conditional? does external poke survive?]
- *(this+0x124) 0x44: [LLM: once/conditional? does external poke survive?]
- *(this+0x124) 0x48: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- obj 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x134: [LLM: once/conditional? does external poke survive?]
- this 0x138: [LLM: once/conditional? does external poke survive?]
- this 0x13C: [LLM: once/conditional? does external poke survive?]
- this 0x140: [LLM: once/conditional? does external poke survive?]
- this 0x158: [LLM: once/conditional? does external poke survive?]
- this 0x15C: [LLM: once/conditional? does external poke survive?]
- this 0x160: [LLM: once/conditional? does external poke survive?]
- this 0x164: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]
- this 0x16C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515917 | CeilingDivision | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
