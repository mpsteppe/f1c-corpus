## ComplexDestructorWith4LinkedLists_00406ba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDestructor (00406b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x8)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x4 | R | — | [LLM] |
| *(this+0x2C) | 0x4 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
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

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
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

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e530 | off_59E530 | R | VTable_StreamObject [DERIVED] |
| 0059e598 | off_59E598 | R | VTable_FUN_00406ba0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | [LLM] |
| 00406e50 | AudioSystemShutdown | [LLM] |
| 004081e0 | UtilityFunction | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | [LLM] |
| this | 0x20 | == | 0 | [LLM] |
| this | 0x30 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
