## sub_6CBC69_006cbc69 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A1C41 (006a1c41), sub_6ACF7B (006acf7b), sub_6B0326 (006b0326)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x108) | 0x0 | R | — | [LLM] |
| *(this+0x110) | 0x0 | R | — | [LLM] |
| obj | 0x60 | R | — | [LLM] |
| obj | 0x64 | R | — | [LLM] |
| obj | 0x7C | R | — | [LLM] |
| obj | 0x88 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x6E | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00747708 | aInternalErrorU_11 | R | [LLM] |
| 00747c0c | aClipCannotBePe | R | [LLM] |
| 00747c40 | aClipMustBePerf_0 | R | [LLM] |
| 00747c80 | aCannotClipFrom | R | [LLM] |
| 00747ca4 | aClipMustBePerf | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |
| 006c64e6 | sub_6C64E6 | [LLM] |
| 006cb0ce | sub_6CB0CE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x104 | != | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: unexpected input register type`
- `clip cannot be performed from a constant or literal`
- `clip must be performed from a float4 vector for ps_2_0 models`
- `cannot clip from a swizzled vector`
- `clip must be performed from a float3 vector for ps_1_x models`
