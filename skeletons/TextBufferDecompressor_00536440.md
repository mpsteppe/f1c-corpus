## TextBufferDecompressor_00536440 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecompressionBufferFlush (00536300), ZlibInflateDecompressionCore (005365d0), InflateDecompressionLoop (00536a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x22 | R | — | [LLM] |
| this | 0x2E | R | — | [LLM] |
| this | 0x32 | R | — | [LLM] |
| this | 0x36 | R | — | [LLM] |
| this | 0x3A | R | — | [LLM] |
| this | 0x3E | RW | — | [LLM] |
| this | 0x42 | R | — | [LLM] |
| this | 0x4A | R | — | [LLM] |
| this | 0x4E | R | — | [LLM] |
| this | 0x52 | RW | — | [LLM] |
| this | 0x62 | RW | — | [LLM] |
| this | 0x66 | RW | — | [LLM] |
| this | 0x6A | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3E: [LLM: once/conditional? does external poke survive?]
- this 0x52: [LLM: once/conditional? does external poke survive?]
- this 0x62: [LLM: once/conditional? does external poke survive?]
- this 0x66: [LLM: once/conditional? does external poke survive?]
- this 0x6A: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00536560 | DecompressionStreamRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
