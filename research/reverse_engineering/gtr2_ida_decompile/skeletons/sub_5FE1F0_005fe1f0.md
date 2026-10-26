## sub_5FE1F0_005fe1f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FE2C0 (005fe2c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2CC) | 0x14 | R | — | [LLM] |
| *(this+0x2CC) | 0x18 | R | — | [LLM] |
| this | 0x2C4 | R | — | [LLM] |
| this | 0x2CC | RW | — | [LLM] |
| this | 0x2D0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x2CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ecdcb | SEH_5FE1F0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d9010 | GlobalZeroInit_c2a0 [exact] | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
