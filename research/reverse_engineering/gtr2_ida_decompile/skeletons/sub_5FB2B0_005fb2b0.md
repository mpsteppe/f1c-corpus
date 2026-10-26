## sub_5FB2B0_005fb2b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FB420 (005fb420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x128) | 0x8 | R | — | [LLM] |
| *(this+0x128) | 0xC | R | — | [LLM] |
| *(this+0x128) | 0x14 | R | — | [LLM] |
| *(this+0x128) | 0x18 | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x128 | RW | — | [LLM] |
| this | 0x12C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x128: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072d35c | aErrorSettingDX | R | [LLM] |
| 00fb2780 | dword_FB2780 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |
| 005fb180 | sub_5FB180 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Error setting %d x %d x %d video mode`
