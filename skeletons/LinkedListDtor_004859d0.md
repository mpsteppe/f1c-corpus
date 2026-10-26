## LinkedListDtor_004859d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x164)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x164) | 0x0 | R | — | [LLM] |
| *(this+0x164) | 0x8 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x164 | RW | 0 | [LLM] |
| this | 0x168 | RW | 0 | [LLM] |
| this | 0x16C | RW | 0 | [LLM] |
| this | 0x170 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x164: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]
- this 0x16C: [LLM: once/conditional? does external poke survive?]
- this 0x170: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00485eb0 | sub_485EB0 | [LLM] |
| 00499b50 | ConditionalDualCleanup | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x164) | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
