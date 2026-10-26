## sub_4E9BB0_004e9bb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EB1C0 (004eb1c0), sub_4EB6C0 (004eb6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x34) | 0xC | R | — | [LLM] |
| *(this+0x34) | 0x28 | RW | 0 | [LLM] |
| *(this+0x44) | 0xC | R | — | [LLM] |
| *(this+0x44) | 0x28 | RW | 0 | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x8C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0x34) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x44) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |
| 007d6b74 | dword_7D6B74 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ec010 | sub_4EC010 | [LLM] |
| 004ec230 | sub_4EC230 | [LLM] |
| 004ed8c0 | sub_4ED8C0 | [LLM] |
| 005922a0 | sub_5922A0 | [LLM] |
| 00592310 | DestroyFree [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
