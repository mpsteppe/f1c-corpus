## ProtocolStateHandler_0051a4b7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0xC | RW | — | [LLM] |
| *(this+0x184) | 0x10 | R | — | [LLM] |
| this | 0x49 | R | — | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0x184 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x184) 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00519d51 | DrawableObjectBatchProcessor | R | [LLM] |
| 00519f9a | AudioSubbandSynthesisFilterbank | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519eb7 | RenderStateCopyWithValidation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
