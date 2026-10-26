## sub_6DAAC0_006daac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B8F20 (006b8f20), sub_6B9044 (006b9044), sub_6B92EA (006b92ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x16B0 | RW | — | [LLM] |
| this | 0x16B1 | R | — | [LLM] |
| this | 0x16B4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x16B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x16B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00748118 | unk_748118 | R | [LLM] |
| 00748598 | unk_748598 | R | [LLM] |
| 016c9470 | off_16C9470 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d95b2 | sub_6D95B2 | [LLM] |
| 006d9dd5 | sub_6D9DD5 | [LLM] |
| 006da010 | sub_6DA010 | [LLM] |
| 006da3c4 | sub_6DA3C4 | [LLM] |
| 006da486 | sub_6DA486 | [LLM] |
| 006da62e | sub_6DA62E | [LLM] |
| 006da811 | sub_6DA811 | [LLM] |
| 006da86b | sub_6DA86B | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1C | == | 2 | [LLM] |
| this | 0x7C | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
