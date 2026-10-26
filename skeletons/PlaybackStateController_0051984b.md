## PlaybackStateController_0051984b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |
| this | 0x184 | RW | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1B0 | RW | 0 | [LLM] |
| this | 0x1B4 | RW | 0 | [LLM] |
| this | 0x1C0 | RW | 0 | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x184: [LLM: once/conditional? does external poke survive?]
- this 0x1B0: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]
- this 0x1CC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005196b8 | BufferedDataStreamWrite | R | [LLM] |
| 00519720 | AudioStreamBufferFill | R | [LLM] |
| 00519828 | RendererVtableDispatchWrapper | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051941d | TextureRowCopy | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
