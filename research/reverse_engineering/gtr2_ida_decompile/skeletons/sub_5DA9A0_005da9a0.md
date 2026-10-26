## sub_5DA9A0_005da9a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AC8B0 (004ac8b0), sub_4E8C30 (004e8c30), sub_51FBF0 (0051fbf0), sub_549500 (00549500), sub_54CD40 (0054cd40), sub_54D5C0 (0054d5c0), sub_54E880 (0054e880), sub_552680 (00552680), sub_597140 (00597140), sub_5DA9A0 (005da9a0), sub_5E0490 (005e0490), AVIPlayerCleanup [structural] (006072a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1C4)+0x0)+0x274) | 0x0 | R | — | [LLM] |
| *(*(this+0x1BC)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x1C4)+0x0) | 0x274 | R | — | [LLM] |
| *(*(this+0x1C4)+0x0) | 0x27C | RW | — | [LLM] |
| *(*(this+0x1D0)+0x274) | 0x0 | R | — | [LLM] |
| *(this+0x1B4) | 0x0 | R | — | [LLM] |
| *(this+0x1BC) | 0x4 | R | — | [LLM] |
| *(this+0x1C4) | 0x0 | R | — | [LLM] |
| *(this+0x1D0) | 0x274 | R | — | [LLM] |
| *(this+0x1D0) | 0x27C | RW | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1BC | RW | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1CC | RW | — | [LLM] |
| this | 0x1D0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x1C4)+0x0) 0x27C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x27C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1BC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005da9a0 | sub_5DA9A0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B4 | == | 0 | [LLM] |
| this | 0x1C4 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
