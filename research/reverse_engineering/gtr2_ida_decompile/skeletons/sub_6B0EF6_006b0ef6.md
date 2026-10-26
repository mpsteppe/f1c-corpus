## sub_6B0EF6_006b0ef6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x54 | R | — | [LLM] |
| obj | 0x58 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00742768 | aVertexShaderMu | R | [LLM] |
| 007427ac | aPsizeMustBeASc | R | [LLM] |
| 007448bc | aFogMustBeAScal | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `vertex shader must minimally write all four components of POSITION`
- `PSIZE must be a scalar`
- `FOG must be a scalar`
