## sub_4CDE30_004cde30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_48BD20 (0048bd20), sub_4CDF40 (004cdf40), sub_4CDFB0 (004cdfb0), sub_4CED00 (004ced00), sub_4CEE20 (004cee20), sub_4CEED0 (004ceed0), sub_4CEF60 (004cef60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0xA0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10C | >= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
