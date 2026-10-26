## TimedAudioEventPlayback_004b9510 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9B80 (004b9b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x71C)+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(*(this+0x71C)+0x8)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x714)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x714)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x714)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0x71C)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x71C)+0x8) | 0x0 | R | — | [LLM] |
| *(this+0x714) | 0x0 | R | — | [LLM] |
| *(this+0x718) | 0x0 | R | — | [LLM] |
| *(this+0x71C) | 0x0 | R | — | [LLM] |
| *(this+0x71C) | 0x4 | R | — | [LLM] |
| *(this+0x71C) | 0x8 | R | — | [LLM] |
| this | 0x714 | R | — | [LLM] |
| this | 0x718 | R | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0xF30 | R | — | [LLM] |
| this | 0xF34 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x71C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd68 | flt_5ACD68 | R | UIScrollRange [DERIVED] |
| 0083ee60 | dword_83EE60 | RW | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008aae64 | dword_8AAE64 | RW | RingBufferWritePtr [DERIVED] (also: ` -- ring buffer offset) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |
| 004b4360 | StreamReadWithScale | [LLM] |
| 004b4450 | WrapperPassThrough | [LLM] |
| 004b44a0 | sub_4B44A0 | [LLM] |
| 00566db0 | sub_566DB0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
