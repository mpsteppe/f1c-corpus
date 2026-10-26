## PixelDataConvolutionViaLookupTable_0051e8d6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1E8) | 0x0 | RW | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x11C | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x1F8 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1E8) 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1F8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1F8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
