## sub_5BACC0_005bacc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BA970 (005ba970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xB0 | RW | 18446744073709551615 | [LLM] |
| this | 0xD4 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005baf34 | jpt_5BADBA | R | [LLM] |
| 00624a10 | off_624A10 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005baf50 | sub_5BAF50 | [LLM] |
| 005baf70 | UtilityFunction_5750 [structural] | [LLM] |
| 005bb260 | sub_5BB260 | [LLM] |
| 005bb5d0 | sub_5BB5D0 | [LLM] |
| 005bb7f0 | sub_5BB7F0 | [LLM] |
| 005bb890 | sub_5BB890 | [LLM] |
| 005d26e6 | sendto [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xB0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
