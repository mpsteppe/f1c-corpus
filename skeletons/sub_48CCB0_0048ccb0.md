## sub_48CCB0_0048ccb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x324)+0x4)+0xC) | 0x1C | R | — | [LLM] |
| *(*(this+0x324)+0x4) | 0xC | R | — | [LLM] |
| *(this+0x324) | 0x4 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0x10 | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| obj | 0x18 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| obj | 0x20 | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x31C | R | — | [LLM] |
| this | 0x324 | RW | 0 | [LLM] |
| this | 0x328 | R | — | [LLM] |
| this | 0x32C | R | — | [LLM] |
| this | 0x334 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x324: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | [LLM] |
| 00486830 | sub_486830 | [LLM] |
| 00494a30 | F_10ParamForwarder | [LLM] |
| 00495150 | GlobalAccessor_5150 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | != | 18446744073709551615 | [LLM] |
| this | 0x18 | != | 18446744073709551615 | [LLM] |
| this | 0x1C | != | 18446744073709551615 | [LLM] |
| this | 0x20 | != | 18446744073709551615 | [LLM] |
| this | 0x328 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
