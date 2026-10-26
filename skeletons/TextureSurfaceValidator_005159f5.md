## TextureSurfaceValidator_005159f5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenStateMachine (00515df2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x10 | RW | 0 | [LLM] |
| *(this+0xC4) | 0xC | R | — | [LLM] |
| *(this+0xC4) | 0x1C | RW | — | [LLM] |
| *(this+0xC4) | 0x20 | RW | — | [LLM] |
| *(this+0xC4) | 0x24 | RW | 8 | [LLM] |
| *(this+0xC4) | 0x28 | RW | — | [LLM] |
| *(this+0xC4) | 0x2C | RW | — | [LLM] |
| *(this+0xC4) | 0x30 | RW | 1 | [LLM] |
| *(this+0xC4) | 0x4C | RW | 0 | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 16 | [LLM] |
| obj | 0x18 | RW | 65500 | [LLM] |
| obj | 0x1C | RW | 10 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x10C | RW | 1 | [LLM] |
| this | 0x110 | RW | 1 | [LLM] |
| this | 0x114 | RW | 8 | [LLM] |
| this | 0x118 | RW | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x18C) 0x10: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x1C: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x20: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x24: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x28: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x2C: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x30: [LLM: once/conditional? does external poke survive?]
- *(this+0xC4) 0x4C: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- obj 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x10C: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]

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
| *(this+0xC4) | 0xC | <= | 0 | [LLM] |
| *(this+0xC4) | 0xC | > | 4 | [LLM] |
| this | 0x18 | > | 65500 | [LLM] |
| this | 0x1C | > | 65500 | [LLM] |
| this | 0x20 | <= | 0 | [LLM] |
| this | 0x20 | > | 10 | [LLM] |
| this | 0xC0 | != | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
