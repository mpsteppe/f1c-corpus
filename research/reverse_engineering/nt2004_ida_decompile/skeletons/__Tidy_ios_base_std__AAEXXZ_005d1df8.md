## ?_Tidy@ios_base@std@@AAEXXZ_005d1df8 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ??1ios_base@std@@UAE@XZ (005d1ce4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005be8ae | sub_5BE8AE | [LLM] |
| 005d1d50 | CallbackChainIteration [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
