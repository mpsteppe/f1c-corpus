## FontResourceLoader_0048e3a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0xC | R | — | [LLM] |
| *(this+0xE4) | 0x10 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xE4 | RW | 0 | [LLM] |
| this | 0xE8 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0xF0 | RW | — | [LLM] |
| this | 0xF4 | RW | — | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3f0 | dword_5EC3F0 | R | ExtraDirPath [DERIVED] (also: ` — font directory path) |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551eb0 | sub_551EB0 | [LLM] |
| 00551f10 | ObjectCreationWithRollbackOnFailure | [LLM] |
| 00551f80 | ConditionalFreeWithBinkClose | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE4 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
