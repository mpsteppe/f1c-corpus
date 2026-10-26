## sub_5A0AD0_005a0ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** SceneBatchRenderCheck [structural] (005a0d70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | 1 | [LLM] |
| *(this+0x1E8) | 0x18 | R | — | [LLM] |
| *(this+0x1E8) | 0x28 | R | — | [LLM] |
| *(this+0x1E8) | 0x2C | R | — | [LLM] |
| *(this+0x1E8) | 0x30 | R | — | [LLM] |
| *(this+0x1E8) | 0x34 | RW | — | [LLM] |
| *(this+0x1E8) | 0x38 | RW | 0 | [LLM] |
| *(this+0x1E8) | 0x3C | RW | — | [LLM] |
| *(this+0x1E8) | 0x40 | RW | — | [LLM] |
| *(this+0x1E8) | 0x44 | RW | — | [LLM] |
| *(this+0x1E8) | 0x48 | RW | — | [LLM] |
| *(this+0x1E8) | 0x4C | RW | — | [LLM] |
| *(this+0x1E8) | 0x50 | RW | 0 | [LLM] |
| *(this+0x1E8) | 0x58 | RW | — | [LLM] |
| *(this+0x1E8) | 0x5C | RW | — | [LLM] |
| *(this+0x1E8) | 0x60 | RW | — | [LLM] |
| *(this+0x1E8) | 0x64 | RW | — | [LLM] |
| *(this+0x1E8) | 0x68 | RW | — | [LLM] |
| *(this+0x1E8) | 0x6C | RW | — | [LLM] |
| *(this+0x1E8) | 0x70 | RW | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |
| this | 0x1E4 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007e8e58 | dword_7E8E58 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a0320 | sub_5A0320 | [LLM] |
| 005b19d0 | sub_5B19D0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1E4 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
