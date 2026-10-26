## AudioBufferSizeCalc_0051868c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalDispatchWithGuard (00511b5c), sub_511B7C (00511b7c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x68 | RW | 0 | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0xD0 | RW | — | [LLM] |
| this | 0xD8 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0x10A | R | — | [LLM] |
| this | 0x113 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x117 | R | — | [LLM] |
| this | 0x119 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0xD0: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]
- this 0xDC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005afaa0 | dword_5AFAA0 | R | CodecBlockSizeTable [DERIVED] |
| 005afabc | dword_5AFABC | R | Zlib_StrideTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051378b | TextureImageColorTransform | [LLM] |
| 00517e92 | sub_517E92 | [LLM] |
| 00517f04 | MemsetWithByteFill | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10A | != | 0 | [LLM] |
| this | 0x117 | < | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
