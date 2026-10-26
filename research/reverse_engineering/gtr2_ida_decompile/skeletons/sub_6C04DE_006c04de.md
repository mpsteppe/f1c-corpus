## sub_6C04DE_006c04de — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A14B5 (006a14b5), sub_6ADF60 (006adf60), sub_6B1163 (006b1163)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x108 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b0 | dbl_6F16B0 | R | [LLM] |
| 007460f0 | dword_7460F0 | R | [LLM] |
| 00746150 | unk_746150 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006bb35b | sub_6BB35B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
