## TexturePathParsingAndDimensionCalculation_00552f20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_552470 (00552470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x64) | 0x1C | R | — | [LLM] |
| *(this+0x64) | 0x20 | R | — | [LLM] |
| *(this+0x64) | 0x30 | R | — | [LLM] |
| *(this+0x64) | 0x34 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x64) 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00552fac | jpt_552F31 | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00552ba0 | sub_552BA0 | [LLM] |
| 00552d70 | sub_552D70 | [LLM] |
| 0058b050 | CRTStrrchr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
