## LinkedListDestructionWithVTableCall_0048d230 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0), sub_46A2A0 (0046a2a0), ObjectConstructorWithZeroedFields (0048c9f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x31C)+0x0)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x31C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x31C)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x31C) | 0x0 | R | — | [LLM] |
| *(this+0x31C) | 0xC | R | — | [LLM] |
| this | 0x31C | RW | 0 | [LLM] |
| this | 0x320 | RW | 0 | [LLM] |
| this | 0x324 | RW | 0 | [LLM] |
| this | 0x328 | RW | 0 | [LLM] |
| this | 0x32C | RW | 0 | [LLM] |
| this | 0x330 | RW | 0 | [LLM] |
| this | 0x334 | RW | 0 | [LLM] |
| this | 0x338 | RW | 0 | [LLM] |
| this | 0x33C | RW | 1 | [LLM] |
| this | 0x340 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x31C: [LLM: once/conditional? does external poke survive?]
- this 0x320: [LLM: once/conditional? does external poke survive?]
- this 0x324: [LLM: once/conditional? does external poke survive?]
- this 0x328: [LLM: once/conditional? does external poke survive?]
- this 0x32C: [LLM: once/conditional? does external poke survive?]
- this 0x330: [LLM: once/conditional? does external poke survive?]
- this 0x334: [LLM: once/conditional? does external poke survive?]
- this 0x338: [LLM: once/conditional? does external poke survive?]
- this 0x33C: [LLM: once/conditional? does external poke survive?]
- this 0x340: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x31C) | 0xC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
