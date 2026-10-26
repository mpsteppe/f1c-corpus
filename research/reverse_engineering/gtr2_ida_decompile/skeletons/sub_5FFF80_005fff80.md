## sub_5FFF80_005fff80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5E6A50 (005e6a50), sub_6004D0 (006004d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA4) | 0xC | RW | — | [LLM] |
| *(this+0xA4) | 0x4C | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x98 | RW | 0 | [LLM] |
| this | 0x9C | RW | — | [LLM] |
| this | 0xA0 | RW | 0 | [LLM] |
| this | 0xA4 | RW | 0 | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xA4) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x9C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072d54c | aErrorCreatingV_3 | R | [LLM] |
| 0072d6a0 | aCouldNotExpand | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00473b70 | sub_473B70 | [LLM] |
| 004eda30 | nullsub_7 | [LLM] |
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005f5900 | sub_5F5900 | [LLM] |
| 005f5a20 | sub_5F5A20 | [LLM] |
| 005fea10 | sub_5FEA10 | [LLM] |
| 005ff6f0 | sub_5FF6F0 | [LLM] |
| 0060adf0 | ConditionalRenderCall [structural] | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x98 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Could not expand projector vertex cache`
