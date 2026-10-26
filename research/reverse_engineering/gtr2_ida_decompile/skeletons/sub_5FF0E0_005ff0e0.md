## sub_5FF0E0_005ff0e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FF6F0 (005ff6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB4 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x20C | R | — | [LLM] |
| this | 0x210 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b0 | dbl_6F16B0 | R | [LLM] |
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7810 | sub_5D7810 | [LLM] |
| 005d7920 | sub_5D7920 | [LLM] |
| 005d82b0 | sub_5D82B0 | [LLM] |
| 005e4d90 | sub_5E4D90 | [LLM] |
| 005ec2a0 | sub_5EC2A0 | [LLM] |
| 005ec450 | sub_5EC450 | [LLM] |
| 005fe610 | sub_5FE610 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
