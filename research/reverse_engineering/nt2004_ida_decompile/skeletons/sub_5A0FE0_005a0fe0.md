## sub_5A0FE0_005a0fe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_45C1B0 (0045c1b0), sub_511500 (00511500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | 0 | [LLM] |
| *(this+0x1E8) | 0x4 | RW | — | [LLM] |
| *(this+0x1E8) | 0x8 | RW | — | [LLM] |
| *(this+0x1E8) | 0xC | RW | — | [LLM] |
| *(this+0x1E8) | 0x1C | RW | — | [LLM] |
| *(this+0x1E8) | 0x20 | RW | — | [LLM] |
| *(this+0x1E8) | 0x24 | RW | — | [LLM] |
| this | 0x1E0 | RW | 0 | [LLM] |
| this | 0x1E8 | RW | — | [LLM] |
| this | 0x204 | R | — | [LLM] |
| this | 0x2E0 | R | — | [LLM] |
| this | 0x2E4 | R | — | [LLM] |
| this | 0x2E8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x1E8) 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041bf10 | sub_41BF10 | [LLM] |
| 005a02f0 | ShortComputation_eaf0 [exact] | [LLM] |
| 005a1200 | LinkedNodeDestruction [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
