## sub_6AA7D5_006aa7d5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x218 | RW | 0 | [LLM] |
| this | 0x21C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x218: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00742710 | aPixelShaderMus | R | [LLM] |
| 00742750 | aDepthMustBeASc | R | [LLM] |
| 00744244 | aRelativeAddres_3 | R | [LLM] |

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

- `pixel shader must minimally write all four components of COLOR0`
- `DEPTH must be a scalar`
- `relative addressing not supported in ps_1_x`
