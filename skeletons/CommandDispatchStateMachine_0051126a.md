## CommandDispatchStateMachine_0051126a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 84 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x178 | RW | 0 | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1E0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x178: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050ff84 | sub_50FF84 | [LLM] |
| 00510012 | ImageFormatStreamDecoder | [LLM] |
| 0051030d | sub_51030D | [LLM] |
| 00510975 | sub_510975 | [LLM] |
| 00510acc | sub_510ACC | [LLM] |
| 00510d60 | MP3HuffmanDecoder | [LLM] |
| 00510f89 | StreamRead2ByteTokenParser | [LLM] |
| 00511060 | StreamingDataReader | [LLM] |
| 005110fc | BitstreamTokenReader | [LLM] |
| 005111d3 | JPEGMarkerReader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
