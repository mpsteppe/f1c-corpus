## sub_5F4CF0_005f4cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E2E00 (005e2e00), sub_5E3450 (005e3450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f4ee0 | jpt_5F4D4B | R | [LLM] |
| 006f15cc | _BinkWait@4 | R | [LLM] |
| 006f15d0 | _BinkDoFrame@4 | R | [LLM] |
| 006f15d4 | _BinkNextFrame@4 | R | [LLM] |
| 006f15d8 | _BinkGetRects@8 | R | [LLM] |
| 006f15dc | _BinkCopyToBufferRect@44 | R | [LLM] |
| 006f15e0 | _BinkCopyToBuffer@28 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e6e70 | sub_5E6E70 | [LLM] |
| 005e6ea0 | sub_5E6EA0 | [LLM] |
| 005e7150 | sub_5E7150 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB8 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
