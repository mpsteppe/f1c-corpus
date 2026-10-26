## CollisionProxyListBuilder_00491ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_496E90 (00496e90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x2C)+0x0) | 0x0 | R | — | [LLM] |
| *(*(obj+0x2C)+0x0) | 0x2 | R | — | [LLM] |
| *(*(obj+0x2C)+0x0) | 0x4 | R | — | [LLM] |
| *(*(obj+0x2C)+0x0) | 0x6 | R | — | [LLM] |
| *(*(obj+0x34)+0x4) | 0x0 | R | — | [LLM] |
| *(obj+0x2C) | 0x0 | R | — | [LLM] |
| *(obj+0x34) | 0x4 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| obj | 0x1C | RW | — | [LLM] |
| obj | 0x20 | RW | — | [LLM] |
| obj | 0x24 | RW | — | [LLM] |
| obj | 0x28 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x34 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x1C: [LLM: once/conditional? does external poke survive?]
- obj 0x20: [LLM: once/conditional? does external poke survive?]
- obj 0x24: [LLM: once/conditional? does external poke survive?]
- obj 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490940 | ResourcePoolNodeAllocDealloc | [LLM] |
| 00490d00 | sub_490D00 | [LLM] |
| 004910d0 | ListIteratorFullDestruction | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x2C | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
