## sub_5FEB60_005feb60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FFAF0 (005ffaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x1E8 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e2ac0 | sub_5E2AC0 | R | [LLM] |
| 005e2b00 | j_j_nullsub_7 | R | [LLM] |
| 006ecdeb | SEH_5FEB60 | R | [LLM] |
| 0072d57c | aErrorAllocatin | R | [LLM] |
| 0072d5ac | aProj3dtex | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb2d78 | dword_FB2D78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005e2e00 | sub_5E2E00 | [LLM] |
| 005e2e70 | sub_5E2E70 | [LLM] |
| 005e3a10 | sub_5E3A10 | [LLM] |
| 005e55e0 | sub_5E55E0 | [LLM] |
| 005e6f50 | BitfieldManager [structural] | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | [LLM] |
| 00630a11 | sub_630A11 | [LLM] |
| 00631761 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Error allocating shadow caster target surface`
- `PROJ%.3dTEX`
