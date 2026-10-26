## MediaAudioDecodeDispatch_0051c3e2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| *(this+0xC4) | 0x24 | R | — | [LLM] |
| *(this+0xC4) | 0x28 | R | — | [LLM] |
| *(this+0xC4) | 0x30 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 37 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x19C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051bfa6 | VehicleStructFieldCopy | R | [LLM] |
| 0051bfc0 | AudioBufferMixing | R | [LLM] |
| 0051c086 | SetterReturnA4 | R | [LLM] |
| 0051c091 | PtrInitZero | R | [LLM] |
| 0051c099 | TrackMapPixelFill | R | [LLM] |
| 0051c176 | MonochromeBufferByteDuplicateCopy | R | [LLM] |
| 0051c1cd | BufferInterleaveCopy | R | [LLM] |
| 0051c237 | PixelBlendFilterHorizontal | R | [LLM] |
| 0051c2db | ImageResampleFilter | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC4) | 0x28 | > | 2 | [LLM] |
| this | 0x20 | > | 0 | [LLM] |
| this | 0x114 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
