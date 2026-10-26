## sub_4F7EC0_004f7ec0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4FA6A0 (004fa6a0), sub_4FA940 (004fa940), sub_4FBE60 (004fbe60), sub_4FEFE0 (004fefe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00757c1c | dword_757C1C | R | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b640c8 | dword_B640C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f7c90 | sub_4F7C90 | [LLM] |
| 004f7dd0 | sub_4F7DD0 | [LLM] |
| 005da8c0 | sub_5DA8C0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
