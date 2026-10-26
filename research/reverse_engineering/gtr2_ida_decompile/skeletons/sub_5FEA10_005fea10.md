## sub_5FEA10_005fea10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FF750 (005ff750), sub_5FFF80 (005fff80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA4) | 0xC | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA4 | RW | 0 | [LLM] |
| this | 0xB0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xB0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072d54c | aErrorCreatingV_3 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | [LLM] |
| 005d8c80 | sub_5D8C80 | [LLM] |
| 0060adf0 | ConditionalRenderCall [structural] | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
