## sub_5F0DD0_005f0dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4E1950 (004e1950), StringFormatAndRender [structural] (004e6210), sub_4E6AA0 (004e6aa0), sub_4E6E80 (004e6e80), sub_562B70 (00562b70), sub_562C80 (00562c80), sub_5F10F0 (005f10f0), sub_5F1150 (005f1150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xA4) | 0xC | RW | — | [LLM] |
| *(this+0xA4) | 0x4C | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0xA0 | RW | 0 | [LLM] |
| this | 0xA4 | RW | 0 | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xA4) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006eca5b | SEH_5F0DD0 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051d670 | sub_51D670 | [LLM] |
| 005e5050 | sub_5E5050 | [LLM] |
| 005e53e0 | sub_5E53E0 | [LLM] |
| 005e54e0 | sub_5E54E0 | [LLM] |
| 005e55e0 | sub_5E55E0 | [LLM] |
| 005e57e0 | sub_5E57E0 | [LLM] |
| 005e7120 | sub_5E7120 | [LLM] |
| 005e7150 | sub_5E7150 | [LLM] |
| 005effc0 | sub_5EFFC0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
