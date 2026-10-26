## UIViewportLayoutCalculator_0048f640 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectNameComparison (00477280), GameFilterSetup (00477830), ProfileBitmapBrowser (00477cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0xC | R | — | [LLM] |
| *(this+0xF0) | 0x10 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x40 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF8 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x104 | RW | 0 | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |
| this | 0x158 | RW | 0 | [LLM] |
| this | 0x15C | RW | 0 | [LLM] |
| this | 0x160 | RW | 0 | [LLM] |
| this | 0x164 | RW | 0 | [LLM] |
| this | 0x16C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x158: [LLM: once/conditional? does external poke survive?]
- this 0x15C: [LLM: once/conditional? does external poke survive?]
- this 0x160: [LLM: once/conditional? does external poke survive?]
- this 0x164: [LLM: once/conditional? does external poke survive?]
- this 0x16C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048f870 | UITileGrid | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x16C | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
