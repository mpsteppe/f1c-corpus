## PlaybackBufferAlloc_0051bf23 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| *(this+0x4) | 0x10 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x4A | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x188 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x188: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051be7d | SoundEffectStateCallback | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515927 | AlignUp | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
