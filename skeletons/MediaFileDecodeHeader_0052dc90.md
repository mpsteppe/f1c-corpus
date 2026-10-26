## MediaFileDecodeHeader_0052dc90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x2D34)+0x0) | 0x8 | R | — | [LLM] |
| *(this+0x2D34) | 0x0 | R | — | [LLM] |
| this | 0x2498 | R | — | [LLM] |
| this | 0x24A4 | R | — | [LLM] |
| this | 0x24A8 | RW | 0 | [LLM] |
| this | 0x2D34 | R | — | [LLM] |
| this | 0x2D3C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: once/conditional? does external poke survive?]
- this 0x2D3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da5fc | aCmpegfileplaye | R | CMpegFilePlayerHeaderString [DERIVED] |
| 005da65c | aWaitingForCdAc | R | WaitingForCDStr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da30 | CMpegBase_ProcessHeader | [LLM] |
| 00588821 | FileOpWithGlobalBuffer | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
