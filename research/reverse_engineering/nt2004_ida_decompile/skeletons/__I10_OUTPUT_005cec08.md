## _$I10_OUTPUT_005cec08 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** __fltout2 (005ccb41)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f74d4 | a1Qnan | R | [LLM] |
| 005f74dc | a1Inf | R | [LLM] |
| 005f74e4 | a1Ind | R | [LLM] |
| 005f74ec | a1Snan | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c6f50 | _strcpy | [LLM] |
| 005cea88 | CRTAdd12 [structural] | [LLM] |
| 005ceae6 | F_96BitLeftShiftBy1 [structural] | [LLM] |
| 005ceb14 | F_96BitRightShift [structural] | [LLM] |
| 005cefc0 | ___ld12mul | [LLM] |
| 005cf1e0 | BitPackedDataDecodeViaLookupTable [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `1#QNAN`
- `1#INF`
- `1#IND`
- `1#SNAN`
