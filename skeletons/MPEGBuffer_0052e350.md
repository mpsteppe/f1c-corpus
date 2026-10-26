## MPEGBuffer_0052e350 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GuardedFunctionCall (0052d970)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x248C | R | — | [LLM] |
| this | 0x249C | R | — | [LLM] |
| this | 0x24B4 | RW | — | [LLM] |
| this | 0x24E4 | RW | — | [LLM] |
| this | 0x24E8 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x24B4: [LLM: once/conditional? does external poke survive?]
- this 0x24E4: [LLM: once/conditional? does external poke survive?]
- this 0x24E8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da6f0 | aMpegFail2D | R | MPEG_Fail2Format [DERIVED] |
| 005da700 | aMpegFail1D | R | MpegFailString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052df10 | sub_52DF10 | [LLM] |
| 00588821 | FileOpWithGlobalBuffer | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
