## AudioBufferFormatSetup_00541120 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553070 (00553070), sub_553700 (00553700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x94 | R | — | [LLM] |
| *(this+0x1100) | 0xC8 | R | — | [LLM] |
| *(this+0x1100) | 0x118 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | R | — | [LLM] |
| this | 0x1170 | RW | 2304 | [LLM] |
| this | 0x13B8 | R | — | [LLM] |
| this | 0x13CC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1170: [LLM: once/conditional? does external poke survive?]
- this 0x13CC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553db0 | StructInitWithDefaultValues | [LLM] |
| 00553fa0 | StateFieldSetWithChainedInit | [LLM] |
| 005546a0 | MultiFieldSetterDispatchingTo7SubSetters | [LLM] |
| 00554700 | PropertyValueSetterWithRefreshOnChange | [LLM] |
| 00554790 | sub_554790 | [LLM] |
| 00554f80 | sub_554F80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
