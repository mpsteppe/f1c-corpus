## SoundEffectStateCallback_0051be7d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x188) | 0x4 | RW | — | [LLM] |
| *(this+0x188) | 0x8 | R | — | [LLM] |
| *(this+0x188) | 0xC | RW | — | [LLM] |
| *(this+0x188) | 0x10 | R | — | [LLM] |
| *(this+0x188) | 0x14 | RW | 0 | [LLM] |
| *(this+0x188) | 0x18 | RW | 0 | [LLM] |
| *(this+0x19C) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x1C | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x4A | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x188) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x188) 0xC: [LLM: once/conditional? does external poke survive?]
- *(this+0x188) 0x14: [LLM: once/conditional? does external poke survive?]
- *(this+0x188) 0x18: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051bcfc | RenderCommandDispatch | R | [LLM] |
| 0051bd61 | AudioRingBufferManager | R | [LLM] |
| 0051bdf1 | BufferedDataReader | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x188) | 0xC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
