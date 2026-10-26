## sub_5FBB60_005fbb60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FBCC0 (005fbcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x214)+0x0)+0x1DC) | 0x0 | R | — | [LLM] |
| *(*(*(this+0x214)+0x0)+0x1DC) | 0x10 | R | — | [LLM] |
| *(*(this+0x214)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x214)+0x0) | 0x1DC | R | — | [LLM] |
| *(*(this+0x21C)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x214) | 0x0 | R | — | [LLM] |
| *(this+0x21C) | 0x4 | R | — | [LLM] |
| *(this+0x26C) | 0x300 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x21C | RW | — | [LLM] |
| this | 0x26C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7980 | F_3DSquaredDistance [exact] | [LLM] |
| 005daf80 | sub_5DAF80 | [LLM] |
| 00600940 | sub_600940 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x26C) | 0x300 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
