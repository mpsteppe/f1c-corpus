## sub_5ECBC0_005ecbc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5ED650 (005ed650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1D0) | 0x0 | RW | 16 | [LLM] |
| *(this+0x1D0) | 0x18 | R | — | [LLM] |
| *(this+0x1D0) | 0x28 | R | — | [LLM] |
| *(this+0x1D0) | 0x2C | R | — | [LLM] |
| *(this+0x1D0) | 0x30 | R | — | [LLM] |
| *(this+0x1D0) | 0x34 | RW | — | [LLM] |
| *(this+0x1D0) | 0x38 | RW | — | [LLM] |
| *(this+0x1D0) | 0x3C | RW | — | [LLM] |
| *(this+0x1D0) | 0x40 | RW | — | [LLM] |
| *(this+0x1D0) | 0x44 | RW | — | [LLM] |
| *(this+0x1D0) | 0x48 | RW | — | [LLM] |
| *(this+0x1D0) | 0x4C | RW | — | [LLM] |
| *(this+0x1D0) | 0x50 | RW | — | [LLM] |
| *(this+0x1D0) | 0x58 | RW | — | [LLM] |
| *(this+0x1D0) | 0x5C | RW | — | [LLM] |
| *(this+0x1D0) | 0x60 | RW | — | [LLM] |
| *(this+0x1D0) | 0x64 | RW | — | [LLM] |
| *(this+0x1D0) | 0x68 | RW | — | [LLM] |
| *(this+0x1D0) | 0x6C | RW | — | [LLM] |
| *(this+0x1D0) | 0x70 | RW | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |
| this | 0x1D0 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x220 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1D0) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1D0) 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f4958 | dbl_6F4958 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d77b0 | sub_5D77B0 | [LLM] |
| 005d7810 | sub_5D7810 | [LLM] |
| 005d7920 | sub_5D7920 | [LLM] |
| 005ec7b0 | sub_5EC7B0 | [LLM] |
| 005fdfa0 | sub_5FDFA0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x220 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
