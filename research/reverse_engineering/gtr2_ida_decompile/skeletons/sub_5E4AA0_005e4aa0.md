## sub_5E4AA0_005e4aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E6040 (005e6040), sub_5E6500 (005e6500), sub_5E95C0 (005e95c0), sub_5FF950 (005ff950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xDC) | 0x6C | R | — | [LLM] |
| *(this+0xDC) | 0xD4 | R | — | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0xDC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e2b00 | j_j_nullsub_7 | R | [LLM] |
| 00fb2d78 | dword_FB2D78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d9a40 | sub_5D9A40 | [LLM] |
| 005e6dd0 | sub_5E6DD0 | [LLM] |
| 006308d3 | j__free | [LLM] |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | [LLM] |
| 00630fe0 | sub_630FE0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xDC) | 0xD4 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
