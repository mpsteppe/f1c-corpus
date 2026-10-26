## sub_4C1BA0_004c1ba0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C1830 (004c1830), sub_4C2E00 (004c2e00), sub_4FA450 (004fa450), sub_4FBD60 (004fbd60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x519C | R | — | [LLM] |
| obj | 0x522A | R | — | [LLM] |
| obj | 0x527C | RW | 0 | [LLM] |
| obj | 0x62D4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x338 | RW | 0 | [LLM] |
| this | 0x3AC | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x527C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x338: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3AC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629328 | flt_629328 | R | [LLM] |
| 00766220 | unk_766220 | R | [LLM] |
| 00766238 | dword_766238 | R | [LLM] |
| 007d7540 | dword_7D7540 | R | [LLM] |
| 007d758c | byte_7D758C | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b400 | sub_41B400 | [LLM] |
| 004bbf50 | sub_4BBF50 | [LLM] |
| 004bec30 | sub_4BEC30 | [LLM] |
| 004c0a80 | sub_4C0A80 | [LLM] |
| 004c1790 | sub_4C1790 | [LLM] |
| 004c1970 | sub_4C1970 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 004f7f20 | sub_4F7F20 | [LLM] |
| 0051c900 | sub_51C900 | [LLM] |
| 0051f3d0 | sub_51F3D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
