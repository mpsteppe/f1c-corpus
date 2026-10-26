## sub_69FE7E_0069fe7e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_672E89 (00672e89)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x40 | RW | 1 | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 1 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |
| this | 0x58 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fbaa30 | dword_FBAA30 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0065a004 | sub_65A004 | [LLM] |
| 0065d529 | sub_65D529 | [LLM] |
| 00694cc7 | sub_694CC7 | [LLM] |
| 0069eb7f | sub_69EB7F | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
