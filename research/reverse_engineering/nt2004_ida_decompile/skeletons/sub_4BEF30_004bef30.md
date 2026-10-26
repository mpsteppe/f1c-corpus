## sub_4BEF30_004bef30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C21B0 (004c21b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC4) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0076782c | dword_76782C | R | [LLM] |
| 007d6b78 | byte_7D6B78 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd140 | sub_4BD140 | [LLM] |
| 004beca0 | sub_4BECA0 | [LLM] |
| 004f0320 | sub_4F0320 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
