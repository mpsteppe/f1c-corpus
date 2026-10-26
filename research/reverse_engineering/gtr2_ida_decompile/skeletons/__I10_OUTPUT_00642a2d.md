## _$I10_OUTPUT_00642a2d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** UIWidgetPropagateState [structural] (00640b22)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00735f64 | a1Qnan | R | [LLM] |
| 00735f6c | a1Inf | R | [LLM] |
| 00735f74 | a1Ind | R | [LLM] |
| 00735f7c | a1Snan | R | [LLM] |
| 00912b08 | dword_912B08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006349bb | sub_6349BB | [LLM] |
| 00636a70 | _strcpy | [LLM] |
| 00642896 | CRTAdd12 [structural] | [LLM] |
| 006428f4 | F_96BitLeftShiftBy1 [structural] | [LLM] |
| 00642922 | F_96BitRightShift [structural] | [LLM] |
| 00642fa3 | ___ld12mul | [LLM] |
| 006431d5 | ___multtenpow12 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `1#QNAN`
- `1#INF`
- `1#IND`
- `1#SNAN`
