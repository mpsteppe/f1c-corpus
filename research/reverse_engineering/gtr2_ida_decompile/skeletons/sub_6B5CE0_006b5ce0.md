## sub_6B5CE0_006b5ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** TwoIterationCleanup [structural] (006b5de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x28 | RW | 0 | [LLM] |
| *(this+0x74) | 0x2C | R | — | [LLM] |
| *(this+0x74) | 0x38 | R | — | [LLM] |
| *(this+0x78) | 0x28 | RW | 0 | [LLM] |
| *(this+0x78) | 0x2C | R | — | [LLM] |
| *(this+0x78) | 0x38 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 14 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x74) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x78) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d3b30 | sub_6D3B30 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
