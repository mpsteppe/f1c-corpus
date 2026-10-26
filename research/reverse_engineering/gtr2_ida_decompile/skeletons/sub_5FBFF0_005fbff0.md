## sub_5FBFF0_005fbff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FBFF0 (005fbff0), sub_5FC390 (005fc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2FC)+0x25C) | 0x0 | R | — | [LLM] |
| *(*(this+0x2FC)+0x25C) | 0x4 | R | — | [LLM] |
| *(*(this+0x2FC)+0x26C) | 0x0 | R | — | [LLM] |
| *(*(this+0x2FC)+0x26C) | 0x4 | R | — | [LLM] |
| *(*(this+0x328)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x2FC) | 0x0 | R | — | [LLM] |
| *(this+0x2FC) | 0x5C | RW | 0 | [LLM] |
| *(this+0x2FC) | 0x70 | RW | 0 | [LLM] |
| *(this+0x2FC) | 0x84 | RW | 0 | [LLM] |
| *(this+0x2FC) | 0x98 | RW | 0 | [LLM] |
| *(this+0x2FC) | 0xAC | RW | 0 | [LLM] |
| *(this+0x2FC) | 0xC0 | RW | 0 | [LLM] |
| *(this+0x2FC) | 0x104 | RW | 0 | [LLM] |
| *(this+0x2FC) | 0x254 | R | — | [LLM] |
| *(this+0x2FC) | 0x25C | RW | — | [LLM] |
| *(this+0x2FC) | 0x264 | R | — | [LLM] |
| *(this+0x2FC) | 0x26C | RW | — | [LLM] |
| *(this+0x2FC) | 0x2E8 | R | — | [LLM] |
| *(this+0x2FC) | 0x33C | R | — | [LLM] |
| *(this+0x320) | 0x0 | R | — | [LLM] |
| *(this+0x328) | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x2FC | R | — | [LLM] |
| this | 0x30C | R | — | [LLM] |
| this | 0x310 | R | — | [LLM] |
| this | 0x314 | R | — | [LLM] |
| this | 0x318 | R | — | [LLM] |
| this | 0x320 | R | — | [LLM] |
| this | 0x328 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x2FC) 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x84: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x25C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2FC) 0x26C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x328: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb2804 | dword_FB2804 | RW | [LLM] |
| 016c9808 | off_16C9808 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e5050 | sub_5E5050 | [LLM] |
| 005e6840 | sub_5E6840 | [LLM] |
| 005f7d00 | sub_5F7D00 | [LLM] |
| 005fbcc0 | sub_5FBCC0 | [LLM] |
| 005fbdc0 | sub_5FBDC0 | [LLM] |
| 005fbff0 | sub_5FBFF0 | [LLM] |
| 00608270 | sub_608270 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
