## UIElementBitfieldStateSetter_0054bdc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FBA10 (004fba10), RecursiveTraversal (0054bcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x228 | R | — | [LLM] |
| this | 0x32C | R | — | [LLM] |
| this | 0x330 | RW | — | [LLM] |
| this | 0x338 | R | — | [LLM] |
| this | 0x350 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x330: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] (also: ` — unknown context/state pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e0e0 | SingleCallWrapper_e0e0 | [LLM] |
| 0054e0f0 | Wrapper_e0f0 | [LLM] |
| 0055d900 | sub_55D900 | [LLM] |
| 0055da50 | sub_55DA50 | [LLM] |
| 0055e320 | sub_55E320 | [LLM] |
| 0055eb30 | sub_55EB30 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C | > | 0 | [LLM] |
| this | 0x338 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
