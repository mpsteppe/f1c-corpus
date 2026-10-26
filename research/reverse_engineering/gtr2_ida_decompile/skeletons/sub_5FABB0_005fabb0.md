## sub_5FABB0_005fabb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FAD90 (005fad90), sub_5FAE80 (005fae80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x21C)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x21C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x21C)+0x4) | 0x8 | R | — | [LLM] |
| *(*(this+0x22C)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x22C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x22C)+0x4) | 0x8 | R | — | [LLM] |
| *(this+0x21C) | 0x0 | R | — | [LLM] |
| *(this+0x21C) | 0x4 | RW | — | [LLM] |
| *(this+0x22C) | 0x0 | R | — | [LLM] |
| *(this+0x22C) | 0x4 | RW | — | [LLM] |
| *(this+0x2F4) | 0x0 | RW | 0 | [LLM] |
| *(this+0x2F4) | 0x4 | R | — | [LLM] |
| this | 0xCC | RW | 0 | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x14C | RW | 0 | [LLM] |
| this | 0x150 | RW | 0 | [LLM] |
| this | 0x21C | RW | — | [LLM] |
| this | 0x220 | RW | — | [LLM] |
| this | 0x224 | RW | — | [LLM] |
| this | 0x228 | R | — | [LLM] |
| this | 0x22C | RW | — | [LLM] |
| this | 0x230 | RW | — | [LLM] |
| this | 0x234 | RW | — | [LLM] |
| this | 0x238 | R | — | [LLM] |
| this | 0x2F4 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x21C) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x22C) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x2F4) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xCC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x150: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x220: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x224: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x22C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x230: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x234: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005f77c0 | sub_5F77C0 | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
