## sub_5EFB30_005efb30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5F0670 (005f0670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC) | 0x0 | RW | — | [LLM] |
| *(this+0xAC) | 0x4 | R | — | [LLM] |
| *(this+0xAC) | 0x8 | R | — | [LLM] |
| *(this+0xAC) | 0x10 | R | — | [LLM] |
| *(this+0xAC) | 0x18 | R | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0xBA | RW | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0xBD | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xAC) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBA: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBD: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e6e70 | sub_5E6E70 | [LLM] |
| 005e6ea0 | sub_5E6EA0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xAC) | 0x18 | != | 5 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
