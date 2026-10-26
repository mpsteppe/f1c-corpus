## sub_6BBB22_006bbb22 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B3A58 (006b3a58), sub_6CA50D (006ca50d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x4 | R | — | [LLM] |
| *(this+0x10) | 0x8 | R | — | [LLM] |
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0x60 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006bb047 | sub_6BB047 | R | [LLM] |
| 007471d0 | aMaximumIterato_0 | R | [LLM] |
| 00747230 | aMaximumBoolean | R | [LLM] |
| 00747288 | aMaximumConstan | R | [LLM] |
| 007472e0 | aMaximumInputRe | R | [LLM] |
| 00747308 | aMaximumIterato | R | [LLM] |
| 00747350 | aMaximumSampler | R | [LLM] |
| 00747378 | aInvalidRegiste_3 | R | [LLM] |
| 007473ec | aOverlappingReg | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00631abd | j__atol | [LLM] |
| 00633887 | StringComparisonWithConstantDispatch [structural] | [LLM] |
| 00635155 | sub_635155 | [LLM] |
| 00682274 | sub_682274 | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006bba7b | sub_6BBA7B | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 0 | [LLM] |
| this | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `maximum iterator register index exceeded - Try reducing number of loops and depth of loops`
- `maximum boolean register index exceeded - Try reducing number of constant branches`
- `maximum constant register index exceeded - Try reducing number of constants referenced`
- `maximum input register index exceeded`
- `maximum iterator register index exceeded - Try reducing number of loops`
- `maximum sampler register index exceeded`
- `maximum sampler register index exceeded`
- `invalid register semantic '%s', or variable must be bound to multiple register banks (%c register binding required)`
- `overlapping register semantics not yet implemented '%c%u'`
