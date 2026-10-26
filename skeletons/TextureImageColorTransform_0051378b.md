## TextureImageColorTransform_0051378b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioBufferSizeCalc (0051868c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x104) | 0x2 | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x151 | R | — | [LLM] |
| this | 0x152 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x104) 0x2: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00602000 | unk_602000 | R | VEH[4].0x3628 [LLM: field purpose] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513482 | EngineSoundWaveTableGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
