## MilesSoundSystemSampleAllocator_004072e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GenericObjectConstructorWithVTable (00406ab0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x90 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e3dc | _AIL_init_sample@4 | R | [LLM] |
| 0059e3ec | _AIL_allocate_sample_handle@4 | R | [LLM] |
| 0059e3f0 | _AIL_release_sample_handle@4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
