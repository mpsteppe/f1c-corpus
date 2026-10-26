## sub_5F5BC0_005f5bc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5F1500 (005f1500), sub_5F2860 (005f2860), sub_60F3B0 (0060f3b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b0 | dbl_6F16B0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005f5760 | sub_5F5760 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
