## TemporaryStateWrapper_00507779 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x1048 | RW | 1 | [LLM] |
| this | 0x104C | RW | — | [LLM] |
| this | 0x1058 | RW | 1 | [LLM] |
| this | 0x1064 | RW | — | [LLM] |
| this | 0x1068 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x1048: [LLM: once/conditional? does external poke survive?]
- this 0x104C: [LLM: once/conditional? does external poke survive?]
- this 0x1058: [LLM: once/conditional? does external poke survive?]
- this 0x1064: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d76c8 | unk_5D76C8 | R | TextureTempDataPointer [DERIVED] (also: ` — constant data pointer for temporary state) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506ce2 | DirectXVertexBufferFormatConversion | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
