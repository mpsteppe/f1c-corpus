## sub_5EFFC0_005effc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5F0DD0 (005f0dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA8) | 0x0 | RW | — | [LLM] |
| *(this+0xA8) | 0x4 | RW | — | [LLM] |
| *(this+0xA8) | 0x8 | RW | 0 | [LLM] |
| *(this+0xA8) | 0xC | RW | 1065353216 → 1.0f | [LLM] |
| *(this+0xA8) | 0x10 | RW | — | [LLM] |
| *(this+0xA8) | 0x14 | RW | — | [LLM] |
| *(this+0xA8) | 0x18 | RW | — | [LLM] |
| *(this+0xA8) | 0x1C | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0xAC | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xA8) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0xA8) 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x84: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16c8 | flt_6F16C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005e7540 | sub_5E7540 | [LLM] |
| 0063099c | __ftol2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
