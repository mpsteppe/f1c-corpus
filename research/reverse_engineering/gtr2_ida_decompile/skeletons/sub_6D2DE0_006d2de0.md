## sub_6D2DE0_006d2de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B4A10 (006b4a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xDC) | 0x84 | RW | 0 | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 27 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x78 | RW | 3 | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0x1CC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xDC) 0x84: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00606bd0 | pfnAPC | R | [LLM] |
| 006d2150 | sub_6D2150 | R | [LLM] |
| 006d2270 | sub_6D2270 | R | [LLM] |
| 006d23b0 | sub_6D23B0 | R | [LLM] |
| 006d2440 | sub_6D2440 | R | [LLM] |
| 006d2470 | sub_6D2470 | R | [LLM] |
| 006d24d0 | sub_6D24D0 | R | [LLM] |
| 006d2a30 | sub_6D2A30 | R | [LLM] |
| 006d2be0 | sub_6D2BE0 | R | [LLM] |
| 006d2fa0 | jpt_6D2E0B | R | [LLM] |
| 016c94d0 | off_16C94D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d2070 | sub_6D2070 | [LLM] |
| 006d2610 | sub_6D2610 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | != | 1 | [LLM] |
| this | 0x24 | != | 3 | [LLM] |
| this | 0x24 | != | 4 | [LLM] |
| this | 0x24 | < | 1 | [LLM] |
| this | 0x24 | <= | 1 | [LLM] |
| this | 0x2C | != | 2 | [LLM] |
| this | 0x2C | == | 4 | [LLM] |
| this | 0x2C | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
