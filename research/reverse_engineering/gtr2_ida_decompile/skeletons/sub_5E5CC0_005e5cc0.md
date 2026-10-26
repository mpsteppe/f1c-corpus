## sub_5E5CC0_005e5cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5DB470 (005db470), sub_5E5CC0 (005e5cc0), sub_5E6C20 (005e6c20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x200)+0x40) | 0x4 | R | — | [LLM] |
| *(*(this+0x200)+0x40) | 0x50 | R | — | [LLM] |
| *(this+0x1B8) | 0x0 | R | — | [LLM] |
| *(this+0x1B8) | 0x270 | R | — | [LLM] |
| *(this+0x200) | 0x40 | R | — | [LLM] |
| *(this+0x50) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x118 | RW | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x150 | RW | 1022739087 → 0.03f | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x200 | RW | — | [LLM] |
| this | 0x29C | R | — | [LLM] |
| this | 0x2AC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x118: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x150: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x200: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ec78b | loc_6EC78B | R | [LLM] |
| 0072be70 | aErrorCreatingP | R | [LLM] |
| 0072bea0 | aL1shadowdraw | R | [LLM] |
| 0072beb0 | aL1shadowdrawte | R | [LLM] |
| 0072bec0 | aL0shadowdraw | R | [LLM] |
| 0072bed0 | aL0shadowdrawte | R | [LLM] |
| 0072bee0 | aInvalidScenePa | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005da7a0 | sub_5DA7A0 | [LLM] |
| 005dce20 | sub_5DCE20 | [LLM] |
| 005e5cc0 | sub_5E5CC0 | [LLM] |
| 005eb310 | sub_5EB310 | [LLM] |
| 005ffaf0 | sub_5FFAF0 | [LLM] |
| 006002c0 | sub_6002C0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `L1SHADOWDRAW`
- `L1SHADOWDRAWTEX`
- `L0SHADOWDRAW`
- `L0SHADOWDRAWTEX`
- `Invalid scene parameter.`
