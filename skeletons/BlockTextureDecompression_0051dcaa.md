## BlockTextureDecompression_0051dcaa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C4) | 0x0 | RW | — | [LLM] |
| *(this+0x1C4) | 0x2 | RW | — | [LLM] |
| *(this+0x1C4) | 0x4 | RW | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C8 | RW | 1 | [LLM] |
| this | 0x1CC | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1C4) 0x0: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C4) 0x2: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C4) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x1C8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051db31 | BitstreamTextureBlockCopy | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
